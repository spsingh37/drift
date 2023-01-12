/* ----------------------------------------------------------------------------
 * Copyright 2022, CURLY Lab, University of Michigan
 * All Rights Reserved
 * See LICENSE for the license information
 * -------------------------------------------------------------------------- */

/**
 *  @file   ros_subsriber.h
 *  @author Tzu-Yuan Lin
 *  @brief  Header file for ROS subscriber class
 *  @date   December 6, 2022
 **/

#ifndef ROS_COMMUNICATION_ROS_SUBSCRIBER_H
#define ROS_COMMUNICATION_ROS_SUBSCRIBER_H

#include <memory>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>

#include "boost/bind.hpp"
#include "geometry_msgs/Twist.h"
#include "ros/ros.h"
#include "sensor_msgs/Contact.h"
#include "sensor_msgs/Imu.h"
#include "sensor_msgs/JointState.h"

#include "measurement/contact.h"
#include "measurement/imu.h"
#include "measurement/joint_state.h"
#include "measurement/legged_kinematics.h"
#include "measurement/velocity.h"

typedef std::queue<std::shared_ptr<ImuMeasurement<double>>> IMUQueue;
typedef std::shared_ptr<IMUQueue> IMUQueuePtr;
typedef std::pair<IMUQueuePtr, std::shared_ptr<std::mutex>> IMUQueuePair;

typedef std::queue<std::shared_ptr<VelocityMeasurement<double>>> VelocityQueue;
typedef std::shared_ptr<VelocityQueue> VelocityQueuePtr;
typedef std::pair<VelocityQueuePtr, std::shared_ptr<std::mutex>>
    VelocityQueuePair;
/*
typedef std::queue<std::shared_ptr<ContactMeasurement>> ContactQueue;
typedef std::shared_ptr<ContactQueue> ContactQueuePtr;
typedef std::pair<ContactQueuePtr, std::shared_ptr<std::mutex>>
    ContactQueuePair;

typedef std::queue<std::shared_ptr<JointStateMeasurement<double>>>
    JointStateQueue;
typedef std::shared_ptr<JointStateQueue> JointStateQueuePtr;
typedef std::pair<JointStateQueuePtr, std::shared_ptr<std::mutex>>
    JointStateQueuePair;
*/
typedef std::queue<std::shared_ptr<LeggedKinematics>> KINQueue;
typedef std::shared_ptr<KINQueue> KINQueuePtr;
typedef std::pair<KINQueuePtr, std::shared_ptr<std::mutex>> KINQueuePair;

namespace ros_wrapper {
class ROSSubscriber {
 public:
  ROSSubscriber(ros::NodeHandle* nh);
  ~ROSSubscriber();

  IMUQueuePair add_imu_subscriber(const std::string topic_name);
  VelocityQueuePair add_velocity_subscriber(const std::string topic_name);
  VelocityQueuePair add_differential_drive_velocity_subscriber(
      const std::string topic_name);
  KINQueuePair add_kinematics_subscriber(const std::string contact_topic_name,
                                         const std::string encoder_topic_name);
  void start_subscribing_thread();

 private:
  void imu_call_back(const boost::shared_ptr<const sensor_msgs::Imu>& imu_msg,
                     const std::shared_ptr<std::mutex>& mutex,
                     IMUQueuePtr& imu_queue);
  void velocity_call_back(
      const boost::shared_ptr<const geometry_msgs::Twist>& vel_msg,
      const std::shared_ptr<std::mutex>& mutex, VelocityQueuePtr& vel_queue);
  void differential_encoder2velocity_call_back(
      const boost::shared_ptr<const sensor_msgs::JointState>& encoder_msg,
      const std::shared_ptr<std::mutex>& mutex, VelocityQueuePtr& vel_queue);
  void kin_call_back(
      const boost::shared_ptr<const sensor_msgs::Contact>& contact_msg,
      const boost::shared_ptr<const sensor_msgs::JointState>& encoder_msg,
      const std::shared_ptr<std::mutex>& mutex, KINQueuePtr& kin_queue);
  void ros_spin();

  ros::NodeHandle* nh_;
  std::vector<ros::Subscriber> subscriber_list_;

  // measurement queue list
  std::vector<IMUQueuePtr> imu_queue_list_;
  std::vector<VelocityQueuePtr> vel_queue_list_;
  std::vector<KINQueuePtr> kin_queue_list_;
  std::vector<std::shared_ptr<std::mutex>> mutex_list_;

  bool thread_started_;
  std::thread subscribing_thread_;

  ros::MultiThreadedSpinner spinner_;
};

}    // namespace ros_wrapper

#endif