// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_sensor_msgs:msg/ContactArray.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT_ARRAY__BUILDER_HPP_
#define CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_sensor_msgs/msg/detail/contact_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_sensor_msgs
{

namespace msg
{

namespace builder
{

class Init_ContactArray_contacts
{
public:
  explicit Init_ContactArray_contacts(::custom_sensor_msgs::msg::ContactArray & msg)
  : msg_(msg)
  {}
  ::custom_sensor_msgs::msg::ContactArray contacts(::custom_sensor_msgs::msg::ContactArray::_contacts_type arg)
  {
    msg_.contacts = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_sensor_msgs::msg::ContactArray msg_;
};

class Init_ContactArray_header
{
public:
  Init_ContactArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ContactArray_contacts header(::custom_sensor_msgs::msg::ContactArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ContactArray_contacts(msg_);
  }

private:
  ::custom_sensor_msgs::msg::ContactArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_sensor_msgs::msg::ContactArray>()
{
  return custom_sensor_msgs::msg::builder::Init_ContactArray_header();
}

}  // namespace custom_sensor_msgs

#endif  // CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT_ARRAY__BUILDER_HPP_
