// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_sensor_msgs:msg/Contact.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT__STRUCT_HPP_
#define CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_sensor_msgs__msg__Contact __attribute__((deprecated))
#else
# define DEPRECATED__custom_sensor_msgs__msg__Contact __declspec(deprecated)
#endif

namespace custom_sensor_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Contact_
{
  using Type = Contact_<ContainerAllocator>;

  explicit Contact_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->indicator = false;
    }
  }

  explicit Contact_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->indicator = false;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _indicator_type =
    bool;
  _indicator_type indicator;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__indicator(
    const bool & _arg)
  {
    this->indicator = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_sensor_msgs::msg::Contact_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_sensor_msgs::msg::Contact_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_sensor_msgs::msg::Contact_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_sensor_msgs::msg::Contact_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_sensor_msgs::msg::Contact_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_sensor_msgs::msg::Contact_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_sensor_msgs::msg::Contact_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_sensor_msgs::msg::Contact_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_sensor_msgs::msg::Contact_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_sensor_msgs::msg::Contact_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_sensor_msgs__msg__Contact
    std::shared_ptr<custom_sensor_msgs::msg::Contact_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_sensor_msgs__msg__Contact
    std::shared_ptr<custom_sensor_msgs::msg::Contact_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Contact_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->indicator != other.indicator) {
      return false;
    }
    return true;
  }
  bool operator!=(const Contact_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Contact_

// alias to use template instance with default allocator
using Contact =
  custom_sensor_msgs::msg::Contact_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_sensor_msgs

#endif  // CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT__STRUCT_HPP_
