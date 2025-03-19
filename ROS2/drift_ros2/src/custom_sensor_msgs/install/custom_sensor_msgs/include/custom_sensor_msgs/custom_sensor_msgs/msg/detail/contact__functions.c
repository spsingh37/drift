// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_sensor_msgs:msg/Contact.idl
// generated code does not contain a copyright notice
#include "custom_sensor_msgs/msg/detail/contact__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
custom_sensor_msgs__msg__Contact__init(custom_sensor_msgs__msg__Contact * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // indicator
  return true;
}

void
custom_sensor_msgs__msg__Contact__fini(custom_sensor_msgs__msg__Contact * msg)
{
  if (!msg) {
    return;
  }
  // id
  // indicator
}

bool
custom_sensor_msgs__msg__Contact__are_equal(const custom_sensor_msgs__msg__Contact * lhs, const custom_sensor_msgs__msg__Contact * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // indicator
  if (lhs->indicator != rhs->indicator) {
    return false;
  }
  return true;
}

bool
custom_sensor_msgs__msg__Contact__copy(
  const custom_sensor_msgs__msg__Contact * input,
  custom_sensor_msgs__msg__Contact * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // indicator
  output->indicator = input->indicator;
  return true;
}

custom_sensor_msgs__msg__Contact *
custom_sensor_msgs__msg__Contact__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_sensor_msgs__msg__Contact * msg = (custom_sensor_msgs__msg__Contact *)allocator.allocate(sizeof(custom_sensor_msgs__msg__Contact), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_sensor_msgs__msg__Contact));
  bool success = custom_sensor_msgs__msg__Contact__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_sensor_msgs__msg__Contact__destroy(custom_sensor_msgs__msg__Contact * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_sensor_msgs__msg__Contact__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_sensor_msgs__msg__Contact__Sequence__init(custom_sensor_msgs__msg__Contact__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_sensor_msgs__msg__Contact * data = NULL;

  if (size) {
    data = (custom_sensor_msgs__msg__Contact *)allocator.zero_allocate(size, sizeof(custom_sensor_msgs__msg__Contact), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_sensor_msgs__msg__Contact__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_sensor_msgs__msg__Contact__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_sensor_msgs__msg__Contact__Sequence__fini(custom_sensor_msgs__msg__Contact__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_sensor_msgs__msg__Contact__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_sensor_msgs__msg__Contact__Sequence *
custom_sensor_msgs__msg__Contact__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_sensor_msgs__msg__Contact__Sequence * array = (custom_sensor_msgs__msg__Contact__Sequence *)allocator.allocate(sizeof(custom_sensor_msgs__msg__Contact__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_sensor_msgs__msg__Contact__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_sensor_msgs__msg__Contact__Sequence__destroy(custom_sensor_msgs__msg__Contact__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_sensor_msgs__msg__Contact__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_sensor_msgs__msg__Contact__Sequence__are_equal(const custom_sensor_msgs__msg__Contact__Sequence * lhs, const custom_sensor_msgs__msg__Contact__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_sensor_msgs__msg__Contact__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_sensor_msgs__msg__Contact__Sequence__copy(
  const custom_sensor_msgs__msg__Contact__Sequence * input,
  custom_sensor_msgs__msg__Contact__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_sensor_msgs__msg__Contact);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_sensor_msgs__msg__Contact * data =
      (custom_sensor_msgs__msg__Contact *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_sensor_msgs__msg__Contact__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_sensor_msgs__msg__Contact__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_sensor_msgs__msg__Contact__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
