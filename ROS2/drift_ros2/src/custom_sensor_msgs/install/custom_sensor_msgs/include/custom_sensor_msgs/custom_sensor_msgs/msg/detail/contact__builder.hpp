// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_sensor_msgs:msg/Contact.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT__BUILDER_HPP_
#define CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_sensor_msgs/msg/detail/contact__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_sensor_msgs
{

namespace msg
{

namespace builder
{

class Init_Contact_indicator
{
public:
  explicit Init_Contact_indicator(::custom_sensor_msgs::msg::Contact & msg)
  : msg_(msg)
  {}
  ::custom_sensor_msgs::msg::Contact indicator(::custom_sensor_msgs::msg::Contact::_indicator_type arg)
  {
    msg_.indicator = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_sensor_msgs::msg::Contact msg_;
};

class Init_Contact_id
{
public:
  Init_Contact_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Contact_indicator id(::custom_sensor_msgs::msg::Contact::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Contact_indicator(msg_);
  }

private:
  ::custom_sensor_msgs::msg::Contact msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_sensor_msgs::msg::Contact>()
{
  return custom_sensor_msgs::msg::builder::Init_Contact_id();
}

}  // namespace custom_sensor_msgs

#endif  // CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT__BUILDER_HPP_
