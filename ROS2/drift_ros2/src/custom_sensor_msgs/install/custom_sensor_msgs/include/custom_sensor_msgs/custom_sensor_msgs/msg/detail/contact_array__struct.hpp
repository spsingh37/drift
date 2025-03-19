// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_sensor_msgs:msg/ContactArray.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT_ARRAY__STRUCT_HPP_
#define CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'contacts'
#include "custom_sensor_msgs/msg/detail/contact__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_sensor_msgs__msg__ContactArray __attribute__((deprecated))
#else
# define DEPRECATED__custom_sensor_msgs__msg__ContactArray __declspec(deprecated)
#endif

namespace custom_sensor_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ContactArray_
{
  using Type = ContactArray_<ContainerAllocator>;

  explicit ContactArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit ContactArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _contacts_type =
    std::vector<custom_sensor_msgs::msg::Contact_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_sensor_msgs::msg::Contact_<ContainerAllocator>>>;
  _contacts_type contacts;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__contacts(
    const std::vector<custom_sensor_msgs::msg::Contact_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_sensor_msgs::msg::Contact_<ContainerAllocator>>> & _arg)
  {
    this->contacts = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_sensor_msgs::msg::ContactArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_sensor_msgs::msg::ContactArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_sensor_msgs::msg::ContactArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_sensor_msgs::msg::ContactArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_sensor_msgs::msg::ContactArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_sensor_msgs::msg::ContactArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_sensor_msgs::msg::ContactArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_sensor_msgs::msg::ContactArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_sensor_msgs::msg::ContactArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_sensor_msgs::msg::ContactArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_sensor_msgs__msg__ContactArray
    std::shared_ptr<custom_sensor_msgs::msg::ContactArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_sensor_msgs__msg__ContactArray
    std::shared_ptr<custom_sensor_msgs::msg::ContactArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ContactArray_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->contacts != other.contacts) {
      return false;
    }
    return true;
  }
  bool operator!=(const ContactArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ContactArray_

// alias to use template instance with default allocator
using ContactArray =
  custom_sensor_msgs::msg::ContactArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_sensor_msgs

#endif  // CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT_ARRAY__STRUCT_HPP_
