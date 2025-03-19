// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_sensor_msgs:msg/Contact.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT__STRUCT_H_
#define CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Contact in the package custom_sensor_msgs.
typedef struct custom_sensor_msgs__msg__Contact
{
  int32_t id;
  bool indicator;
} custom_sensor_msgs__msg__Contact;

// Struct for a sequence of custom_sensor_msgs__msg__Contact.
typedef struct custom_sensor_msgs__msg__Contact__Sequence
{
  custom_sensor_msgs__msg__Contact * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_sensor_msgs__msg__Contact__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_SENSOR_MSGS__MSG__DETAIL__CONTACT__STRUCT_H_
