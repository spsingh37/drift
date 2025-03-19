/* ----------------------------------------------------------------------------
 * Copyright 2025, CURLY Lab, University of Michigan
 * All Rights Reserved
 * See LICENSE for the license information
 * -------------------------------------------------------------------------- */

/**
 *  @file   wamv_gps_ros2.cpp
 *  @author Surya Singh
 *  @brief  Test file for WAMV robot setup (IMU Propagation +
 *  GPS based Position Correction)
 *  @date   March 1, 2025
 **/

#include <rclcpp/rclcpp.hpp>
#include <filesystem>
#include <iostream>
#include <yaml-cpp/yaml.h>
#include "communication/ros2_publisher.h"
#include "communication/ros2_subscriber.h"
#include "drift/estimator/inekf_estimator.h"

using namespace std;
using namespace state;
using namespace estimator;

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("wamv_gps_ros2");

    RCLCPP_INFO(node->get_logger(), "The subscriber is on!");

    ros_wrapper::ROSSubscriber ros_sub(node);

    std::string file{__FILE__};
    std::string project_dir{file.substr(0, file.rfind("ROS2/drift_ros2/examples/"))};
    RCLCPP_INFO(node->get_logger(), "Project directory: %s", project_dir.c_str());

    std::string ros_config_file = project_dir + "/ROS2/drift_ros2/config/wamv_gps_ros2/ros_comm.yaml";
    YAML::Node config = YAML::LoadFile(ros_config_file);
    
    std::string imu_topic = config["subscribers"]["imu_topic"].as<std::string>();
    std::string gps_topic = config["subscribers"]["gps_topic"].as<std::string>();
    auto translation_gpssrc2body = config["subscribers"]["translation_gps_source_to_body"].as<std::vector<double>>();
    auto rotation_gpssrc2body = config["subscribers"]["rotation_gps_source_to_body"].as<std::vector<double>>();

    Eigen::Vector3d reference_position;
    try {
        const auto& ref_pos_node = config["subscribers"]["reference_position"];
        reference_position = Eigen::Vector3d(ref_pos_node[0].as<double>(), ref_pos_node[1].as<double>(), ref_pos_node[2].as<double>());
    } catch (const YAML::Exception& e) {
        throw std::runtime_error("Error reading reference_position: expected a sequence of 3 doubles.");
    }

    auto [qimu, qimu_mutex] = ros_sub.AddIMUSubscriber(imu_topic);
    auto [qp, qp_mutex] = ros_sub.AddGPS2PositionSubscriber(gps_topic, translation_gpssrc2body, rotation_gpssrc2body, reference_position);

    ros_sub.StartSubscribingThread();

    inekf::ErrorType error_type = RightInvariant;
    InekfEstimator inekf_estimator(error_type, project_dir + "/config/wamv_gps_ros2/inekf_estimator.yaml");

    inekf_estimator.add_imu_propagation(qimu, qimu_mutex, project_dir + "/config/wamv_gps_ros2/imu_propagation.yaml");
    inekf_estimator.add_position_correction(qp, qp_mutex, project_dir + "/config/wamv_gps_ros2/position_correction.yaml");

    auto robot_state_queue_ptr = inekf_estimator.get_robot_state_queue_ptr();
    auto robot_state_queue_mutex_ptr = inekf_estimator.get_robot_state_queue_mutex_ptr();

    ros_wrapper::ROSPublisher ros_pub(node, robot_state_queue_ptr, robot_state_queue_mutex_ptr, ros_config_file);
    ros_pub.StartPublishingThread();

    rclcpp::Rate loop_rate(10);
    while (rclcpp::ok()) {
        if (inekf_estimator.is_enabled()) {
            inekf_estimator.RunOnce();
        } else {
            if (inekf_estimator.BiasInitialized()) {
                inekf_estimator.InitState();
            } else {
                inekf_estimator.InitBias();
            }
        }
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}
