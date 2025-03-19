// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_sensor_msgs:msg/ContactArray.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT_ARRAY__TRAITS_HPP_
#define CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_sensor_msgs/msg/detail/contact_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'contacts'
#include "custom_sensor_msgs/msg/detail/contact__traits.hpp"

namespace custom_sensor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ContactArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: contacts
  {
    if (msg.contacts.size() == 0) {
      out << "contacts: []";
    } else {
      out << "contacts: [";
      size_t pending_items = msg.contacts.size();
      for (auto item : msg.contacts) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ContactArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: contacts
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.contacts.size() == 0) {
      out << "contacts: []\n";
    } else {
      out << "contacts:\n";
      for (auto item : msg.contacts) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ContactArray & msg, bool use_flow_style = false)
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
  const custom_sensor_msgs::msg::ContactArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_sensor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_sensor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_sensor_msgs::msg::ContactArray & msg)
{
  return custom_sensor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_sensor_msgs::msg::ContactArray>()
{
  return "custom_sensor_msgs::msg::ContactArray";
}

template<>
inline const char * name<custom_sensor_msgs::msg::ContactArray>()
{
  return "custom_sensor_msgs/msg/ContactArray";
}

template<>
struct has_fixed_size<custom_sensor_msgs::msg::ContactArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_sensor_msgs::msg::ContactArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_sensor_msgs::msg::ContactArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT_ARRAY__TRAITS_HPP_
