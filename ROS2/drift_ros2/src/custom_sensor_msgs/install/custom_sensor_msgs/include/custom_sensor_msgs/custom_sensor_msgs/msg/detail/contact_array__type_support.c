// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_sensor_msgs:msg/ContactArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_sensor_msgs/msg/detail/contact_array__rosidl_typesupport_introspection_c.h"
#include "custom_sensor_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_sensor_msgs/msg/detail/contact_array__functions.h"
#include "custom_sensor_msgs/msg/detail/contact_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `contacts`
#include "custom_sensor_msgs/msg/contact.h"
// Member `contacts`
#include "custom_sensor_msgs/msg/detail/contact__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__ContactArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_sensor_msgs__msg__ContactArray__init(message_memory);
}

void custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__ContactArray_fini_function(void * message_memory)
{
  custom_sensor_msgs__msg__ContactArray__fini(message_memory);
}

size_t custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__size_function__ContactArray__contacts(
  const void * untyped_member)
{
  const custom_sensor_msgs__msg__Contact__Sequence * member =
    (const custom_sensor_msgs__msg__Contact__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__get_const_function__ContactArray__contacts(
  const void * untyped_member, size_t index)
{
  const custom_sensor_msgs__msg__Contact__Sequence * member =
    (const custom_sensor_msgs__msg__Contact__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__get_function__ContactArray__contacts(
  void * untyped_member, size_t index)
{
  custom_sensor_msgs__msg__Contact__Sequence * member =
    (custom_sensor_msgs__msg__Contact__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__fetch_function__ContactArray__contacts(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const custom_sensor_msgs__msg__Contact * item =
    ((const custom_sensor_msgs__msg__Contact *)
    custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__get_const_function__ContactArray__contacts(untyped_member, index));
  custom_sensor_msgs__msg__Contact * value =
    (custom_sensor_msgs__msg__Contact *)(untyped_value);
  *value = *item;
}

void custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__assign_function__ContactArray__contacts(
  void * untyped_member, size_t index, const void * untyped_value)
{
  custom_sensor_msgs__msg__Contact * item =
    ((custom_sensor_msgs__msg__Contact *)
    custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__get_function__ContactArray__contacts(untyped_member, index));
  const custom_sensor_msgs__msg__Contact * value =
    (const custom_sensor_msgs__msg__Contact *)(untyped_value);
  *item = *value;
}

bool custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__resize_function__ContactArray__contacts(
  void * untyped_member, size_t size)
{
  custom_sensor_msgs__msg__Contact__Sequence * member =
    (custom_sensor_msgs__msg__Contact__Sequence *)(untyped_member);
  custom_sensor_msgs__msg__Contact__Sequence__fini(member);
  return custom_sensor_msgs__msg__Contact__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__ContactArray_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_sensor_msgs__msg__ContactArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "contacts",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_sensor_msgs__msg__ContactArray, contacts),  // bytes offset in struct
    NULL,  // default value
    custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__size_function__ContactArray__contacts,  // size() function pointer
    custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__get_const_function__ContactArray__contacts,  // get_const(index) function pointer
    custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__get_function__ContactArray__contacts,  // get(index) function pointer
    custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__fetch_function__ContactArray__contacts,  // fetch(index, &value) function pointer
    custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__assign_function__ContactArray__contacts,  // assign(index, value) function pointer
    custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__resize_function__ContactArray__contacts  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__ContactArray_message_members = {
  "custom_sensor_msgs__msg",  // message namespace
  "ContactArray",  // message name
  2,  // number of fields
  sizeof(custom_sensor_msgs__msg__ContactArray),
  custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__ContactArray_message_member_array,  // message members
  custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__ContactArray_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__ContactArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__ContactArray_message_type_support_handle = {
  0,
  &custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__ContactArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_sensor_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_sensor_msgs, msg, ContactArray)() {
  custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__ContactArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__ContactArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_sensor_msgs, msg, Contact)();
  if (!custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__ContactArray_message_type_support_handle.typesupport_identifier) {
    custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__ContactArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_sensor_msgs__msg__ContactArray__rosidl_typesupport_introspection_c__ContactArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
