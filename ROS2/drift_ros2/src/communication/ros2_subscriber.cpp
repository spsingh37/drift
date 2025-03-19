#include "communication/ros2_subscriber.h"
// #include <memory>
// #include <iostream>
// #include <Eigen/Dense>

namespace ros_wrapper {

ROSSubscriber::ROSSubscriber(rclcpp::Node::SharedPtr node)
    : rclcpp::Node("ros2_subscriber"), node_(node), thread_started_(false) {}

ROSSubscriber::~ROSSubscriber() {
    if (thread_started_) {
        subscribing_thread_.join();
    }
    subscriber_list_.clear();
    imu_queue_list_.clear();
}

IMUQueuePair ROSSubscriber::AddIMUSubscriber(const std::string &topic_name) {
    std::cout << "Subscribing to IMU topic: " << topic_name << std::endl;
    auto imu_queue_ptr = std::make_shared<IMUQueue>();
    auto mutex = std::make_shared<std::mutex>();

    auto callback = [this, mutex, imu_queue_ptr](const sensor_msgs::msg::Imu::SharedPtr msg) {
        IMUCallback(msg, mutex, imu_queue_ptr);
    };

    subscriber_list_.push_back(node_->create_subscription<sensor_msgs::msg::Imu>(
        topic_name, 10, callback));

    imu_queue_list_.push_back(imu_queue_ptr);
    return {imu_queue_ptr, mutex};
}

PositionQueuePair ROSSubscriber::AddOdom2PositionSubscriber(
    const std::string &topic_name,
    const std::vector<double> &translation_odomsrc2body,
    const std::vector<double> &rotation_odomsrc2body) {
    std::cout << "Subscribing to odometry topic: " << topic_name << std::endl;
    auto position_queue_ptr = std::make_shared<OdomQueue>();
    auto mutex = std::make_shared<std::mutex>();

    Eigen::Quaternion<double> orientation_quat(rotation_odomsrc2body[0], rotation_odomsrc2body[1],
                                               rotation_odomsrc2body[2], rotation_odomsrc2body[3]);
    odom_src_to_body_ = Eigen::Matrix4d::Identity();
    odom_src_to_body_.block<3, 3>(0, 0) = orientation_quat.toRotationMatrix();
    odom_src_to_body_.block<3, 1>(0, 3) = Eigen::Vector3d(translation_odomsrc2body.data());

    auto callback = [this, mutex, position_queue_ptr](const nav_msgs::msg::Odometry::SharedPtr msg) {
        Odom2PositionCallback(msg, mutex, position_queue_ptr);
    };

    subscriber_list_.push_back(node_->create_subscription<nav_msgs::msg::Odometry>(
        topic_name, 10, callback));

    position_queue_list_.push_back(position_queue_ptr);
    return {position_queue_ptr, mutex};
}

PositionQueuePair ROSSubscriber::AddGPS2PositionSubscriber(
    const std::string &topic_name,
    const std::vector<double> &translation_gpssrc2body,
    const std::vector<double> &rotation_gpssrc2body,
    const Eigen::Vector3d &reference_position) {
    std::cout << "Subscribing to GPS topic: " << topic_name << std::endl;
    auto position_queue_ptr = std::make_shared<OdomQueue>();
    auto mutex = std::make_shared<std::mutex>();

    Eigen::Quaternion<double> orientation_quat(rotation_gpssrc2body[0], rotation_gpssrc2body[1],
                                               rotation_gpssrc2body[2], rotation_gpssrc2body[3]);
    gps_src_to_body_ = Eigen::Matrix4d::Identity();
    gps_src_to_body_.block<3, 3>(0, 0) = orientation_quat.toRotationMatrix();
    gps_src_to_body_.block<3, 1>(0, 3) = Eigen::Vector3d(translation_gpssrc2body.data());

    auto callback = [this, mutex, position_queue_ptr, reference_position](const sensor_msgs::msg::NavSatFix::SharedPtr msg) {
        GPS2PositionCallback(msg, mutex, position_queue_ptr, reference_position);
    };

    subscriber_list_.push_back(node_->create_subscription<sensor_msgs::msg::NavSatFix>(
        topic_name, 10, callback));

    position_queue_list_.push_back(position_queue_ptr);
    return {position_queue_ptr, mutex};
}

void ROSSubscriber::StartSubscribingThread() {
    subscribing_thread_ = std::thread([this] { rclcpp::spin(node_); });
    thread_started_ = true;
}

// void ROSSubscriber::StartSubscribingThread() {
//     subscribing_thread_ = std::thread([this] { this->RosSpin(); });
//     thread_started_ = true;
// }

// void ROSSubscriber::StartSubscribingThread(std::shared_ptr<ROSSubscriber> node_ptr) {
//     subscribing_thread_ = std::thread([node_ptr] { node_ptr->RosSpin(); });
// }

// void ROS2Subscriber::IMUCallback(
//     const sensor_msgs::msg::Imu::SharedPtr msg,
//     const std::shared_ptr<std::mutex> &mutex,
//     IMUQueuePtr &imu_queue) {
void ROSSubscriber::IMUCallback(
    const sensor_msgs::msg::Imu::SharedPtr imu_msg,
    const std::shared_ptr<std::mutex>& mutex, const IMUQueuePtr& imu_queue) {
    auto imu_measurement = std::make_shared<ImuMeasurement<double>>();
    // imu_measurement->set_header(msg->header.stamp.sec + msg->header.stamp.nanosec / 1e9, msg->header.frame_id);
    imu_measurement->set_header(imu_msg->header.stamp.sec, 
        imu_msg->header.stamp.sec + imu_msg->header.stamp.nanosec / 1e9, 
        imu_msg->header.frame_id);
    imu_measurement->set_angular_velocity(imu_msg->angular_velocity.x, imu_msg->angular_velocity.y, imu_msg->angular_velocity.z);
    imu_measurement->set_lin_acc(imu_msg->linear_acceleration.x, imu_msg->linear_acceleration.y, imu_msg->linear_acceleration.z);

    if (Eigen::Vector4d({imu_msg->orientation.w, imu_msg->orientation.x, imu_msg->orientation.y, imu_msg->orientation.z}).norm() != 0) {
        imu_measurement->set_quaternion(imu_msg->orientation.w, imu_msg->orientation.x, imu_msg->orientation.y, imu_msg->orientation.z);
    }
    std::cout << "imu x_linear_acccel: " << imu_msg->linear_acceleration.x << std::endl;
    std::cout << "imu y_linear_acccel: " << imu_msg->linear_acceleration.y << std::endl;
    std::cout << "imu z_linear_acccel: " << imu_msg->linear_acceleration.z << std::endl;
    // std::lock_guard<std::mutex> lock(*mutex);
    mutex.get()->lock();
    imu_queue->push(imu_measurement);
    mutex.get()->unlock();
    RCLCPP_INFO(this->get_logger(), "IMU measurement added to queue. Queue size: %lu", imu_queue->size());
}

// void ROS2Subscriber::Odom2PositionCallback(
//     const nav_msgs::msg::Odometry::SharedPtr msg,
//     const std::shared_ptr<std::mutex> &mutex,
//     OdomQueuePtr &position_queue) {
void ROSSubscriber::Odom2PositionCallback(
    const nav_msgs::msg::Odometry::SharedPtr odom_msg,
    const std::shared_ptr<std::mutex>& position_mutex, const OdomQueuePtr& position_queue) {
    auto position_measurement = std::make_shared<OdomMeasurement>();
    Eigen::Vector3d translation(odom_msg->pose.pose.position.x, odom_msg->pose.pose.position.y, odom_msg->pose.pose.position.z);
    std::cout << "pose x before transform: " << odom_msg->pose.pose.position.x << std::endl;
    std::cout << "pose y before transform: " << odom_msg->pose.pose.position.y << std::endl;
    std::cout << "pose z before transform: " << odom_msg->pose.pose.position.z << std::endl;
    Eigen::Matrix4d curr_transformation = Eigen::Matrix4d::Identity();
    curr_transformation.block<3, 1>(0, 3) = translation;
    Eigen::Matrix4d transformed_pose = odom_src_to_body_.inverse() * curr_transformation;
    Eigen::Vector3d transformed_translation = transformed_pose.block<3, 1>(0, 3);
    if (!transformed_translation.allFinite()) {
        RCLCPP_WARN(this->get_logger(), "Invalid transformation detected!");
        return;
    }

    // position_measurement->set_header(msg->header.stamp.sec + msg->header.stamp.nanosec / 1e9, msg->header.frame_id);
    position_measurement->set_header(odom_msg->header.stamp.sec, 
        odom_msg->header.stamp.sec + odom_msg->header.stamp.nanosec / 1e9, 
        odom_msg->header.frame_id);
    position_measurement->set_translation(transformed_translation);
    std::cout << "pose after transform: " << transformed_translation << std::endl;
    // std::lock_guard<std::mutex> lock(*mutex);
    position_mutex.get()->lock();
    position_queue->push(position_measurement);
    position_mutex.get()->unlock();
    RCLCPP_INFO(this->get_logger(), "Odom measurement added to queue. Queue size: %lu", position_queue->size());
}

// void ROS2Subscriber::GPS2PositionCallback(
//     const sensor_msgs::msg::NavSatFix::SharedPtr msg,
//     const std::shared_ptr<std::mutex> &mutex,
//     OdomQueuePtr &position_queue,
//     const Eigen::Vector3d &reference_position) {
// void ROS2Subscriber::GPS2PositionCallback(
//     const sensor_msgs::msg::NavSatFix::SharedPtr msg,
//     const std::shared_ptr<std::mutex>& mutex, const OdomQueuePtr& position_queue, const Eigen::Vector3d& reference_position) {
//     auto position_measurement = std::make_shared<OdomMeasurement>();
//     Eigen::Vector3d enu_translation = ConvertGPSToENU(msg, reference_position);
//     position_measurement->set_translation(enu_translation);
    
//     std::lock_guard<std::mutex> lock(*mutex);
//     position_queue->push(position_measurement);
// }
void ROSSubscriber::GPS2PositionCallback(
    const sensor_msgs::msg::NavSatFix::SharedPtr gps_msg,
    const std::shared_ptr<std::mutex>& position_mutex,
    const OdomQueuePtr& position_queue, 
    const Eigen::Vector3d& reference_position) {

    std::shared_ptr<OdomMeasurement> position_measurement = std::make_shared<OdomMeasurement>();

    double lat0 = reference_position(0);
    double lon0 = reference_position(1);
    double alt0 = reference_position(2);

    // Convert GPS coordinates to ENU coordinates
    measurement::NavSatMeasurement<double> navsat_measurement;
    navsat_measurement.set_navsatfix(gps_msg->latitude, gps_msg->longitude, gps_msg->altitude);

    // Obtain ENU coordinates relative to the reference lat/lon/alt
    Eigen::Matrix<double, 3, 1> enu_translation = navsat_measurement.get_enu(lat0, lon0, alt0);

    // Set up transformation matrix for ENU translation (no rotation as GPS lacks orientation data)
    Eigen::Matrix4d enu_transformation = Eigen::Matrix4d::Identity();
    enu_transformation.block<3, 1>(0, 3) = enu_translation;

    Eigen::Matrix4d transformed_pose = gps_src_to_body_.inverse() * enu_transformation;

    // Extract transformed translation
    Eigen::Vector3d transformed_translation = transformed_pose.block<3, 1>(0, 3);

    // Set headers and timestamps using ROS2 format
    position_measurement->set_header(
        gps_msg->header.stamp.sec,  // Sequence number (ROS2 does not use `seq`)
        rclcpp::Time(gps_msg->header.stamp).seconds(),  // Convert to double timestamp
        gps_msg->header.frame_id);

    position_measurement->set_translation(transformed_translation);
    position_measurement->set_transformation();

    // Use lock_guard for RAII-based thread safety
    // std::lock_guard<std::mutex> lock(*mutex);
    position_mutex.get()->lock();
    position_queue->push(position_measurement);
    position_mutex.get()->unlock();
}

// void RosSpin() {
//     rclcpp::executors::MultiThreadedExecutor executor;
//     executor.add_node(shared_from_this());  // Add the node to the executor
//     executor.spin();  // Spins using multiple threads
// }

// void RosSpin(std::shared_ptr<ROSSubscriber> node_ptr) {
//     rclcpp::executors::MultiThreadedExecutor executor;
//     executor.add_node(node_ptr);
//     executor.spin();
// }

} // namespace ros_wrapper

