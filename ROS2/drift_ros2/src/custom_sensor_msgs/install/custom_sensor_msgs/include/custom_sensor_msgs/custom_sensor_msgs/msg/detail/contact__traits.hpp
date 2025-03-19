// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_sensor_msgs:msg/Contact.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT__TRAITS_HPP_
#define CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_sensor_msgs/msg/detail/contact__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_sensor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Contact & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: indicator
  {
    out << "indicator: ";
    rosidl_generator_traits::value_to_yaml(msg.indicator, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Contact & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: indicator
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "indicator: ";
    rosidl_generator_traits::value_to_yaml(msg.indicator, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Contact & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_sensor_msgs

namespace rosidl_generator_traits
{

[[deprecated("use custom_sensor_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_sensor_msgs::msg::Contact & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_sensor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_sensor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_sensor_msgs::msg::Contact & msg)
{
  return custom_sensor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_sensor_msgs::msg::Contact>()
{
  return "custom_sensor_msgs::msg::Contact";
}

template<>
inline const char * name<custom_sensor_msgs::msg::Contact>()
{
  return "custom_sensor_msgs/msg/Contact";
}

template<>
struct has_fixed_size<custom_sensor_msgs::msg::Contact>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_sensor_msgs::msg::Contact>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_sensor_msgs::msg::Contact>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT__TRAITS_HPP_
