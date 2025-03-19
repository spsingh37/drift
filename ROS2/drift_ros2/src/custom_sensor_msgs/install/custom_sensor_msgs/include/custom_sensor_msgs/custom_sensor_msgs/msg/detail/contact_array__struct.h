// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_sensor_msgs:msg/ContactArray.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT_ARRAY__STRUCT_H_
#define CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'contacts'
#include "custom_sensor_msgs/msg/detail/contact__struct.h"

/// Struct defined in msg/ContactArray in the package custom_sensor_msgs.
typedef struct custom_sensor_msgs__msg__ContactArray
{
  std_msgs__msg__Header header;
  custom_sensor_msgs__msg__Contact__Sequence contacts;
} custom_sensor_msgs__msg__ContactArray;

// Struct for a sequence of custom_sensor_msgs__msg__ContactArray.
typedef struct custom_sensor_msgs__msg__ContactArray__Sequence
{
  custom_sensor_msgs__msg__ContactArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_sensor_msgs__msg__ContactArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT_ARRAY__STRUCT_H_
