// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from core:msg/Float32Arr.idl
// generated code does not contain a copyright notice
#include "core/msg/detail/float32_arr__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `array`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
core__msg__Float32Arr__init(core__msg__Float32Arr * msg)
{
  if (!msg) {
    return false;
  }
  // array
  if (!rosidl_runtime_c__float__Sequence__init(&msg->array, 0)) {
    core__msg__Float32Arr__fini(msg);
    return false;
  }
  return true;
}

void
core__msg__Float32Arr__fini(core__msg__Float32Arr * msg)
{
  if (!msg) {
    return;
  }
  // array
  rosidl_runtime_c__float__Sequence__fini(&msg->array);
}

bool
core__msg__Float32Arr__are_equal(const core__msg__Float32Arr * lhs, const core__msg__Float32Arr * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // array
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->array), &(rhs->array)))
  {
    return false;
  }
  return true;
}

bool
core__msg__Float32Arr__copy(
  const core__msg__Float32Arr * input,
  core__msg__Float32Arr * output)
{
  if (!input || !output) {
    return false;
  }
  // array
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->array), &(output->array)))
  {
    return false;
  }
  return true;
}

core__msg__Float32Arr *
core__msg__Float32Arr__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  core__msg__Float32Arr * msg = (core__msg__Float32Arr *)allocator.allocate(sizeof(core__msg__Float32Arr), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(core__msg__Float32Arr));
  bool success = core__msg__Float32Arr__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
core__msg__Float32Arr__destroy(core__msg__Float32Arr * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    core__msg__Float32Arr__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
core__msg__Float32Arr__Sequence__init(core__msg__Float32Arr__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  core__msg__Float32Arr * data = NULL;

  if (size) {
    data = (core__msg__Float32Arr *)allocator.zero_allocate(size, sizeof(core__msg__Float32Arr), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = core__msg__Float32Arr__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        core__msg__Float32Arr__fini(&data[i - 1]);
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
core__msg__Float32Arr__Sequence__fini(core__msg__Float32Arr__Sequence * array)
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
      core__msg__Float32Arr__fini(&array->data[i]);
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

core__msg__Float32Arr__Sequence *
core__msg__Float32Arr__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  core__msg__Float32Arr__Sequence * array = (core__msg__Float32Arr__Sequence *)allocator.allocate(sizeof(core__msg__Float32Arr__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = core__msg__Float32Arr__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
core__msg__Float32Arr__Sequence__destroy(core__msg__Float32Arr__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    core__msg__Float32Arr__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
core__msg__Float32Arr__Sequence__are_equal(const core__msg__Float32Arr__Sequence * lhs, const core__msg__Float32Arr__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!core__msg__Float32Arr__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
core__msg__Float32Arr__Sequence__copy(
  const core__msg__Float32Arr__Sequence * input,
  core__msg__Float32Arr__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(core__msg__Float32Arr);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    core__msg__Float32Arr * data =
      (core__msg__Float32Arr *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!core__msg__Float32Arr__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          core__msg__Float32Arr__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!core__msg__Float32Arr__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
