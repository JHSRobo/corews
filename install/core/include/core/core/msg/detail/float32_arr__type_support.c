// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from core:msg/Float32Arr.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "core/msg/detail/float32_arr__rosidl_typesupport_introspection_c.h"
#include "core/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "core/msg/detail/float32_arr__functions.h"
#include "core/msg/detail/float32_arr__struct.h"


// Include directives for member types
// Member `array`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void core__msg__Float32Arr__rosidl_typesupport_introspection_c__Float32Arr_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  core__msg__Float32Arr__init(message_memory);
}

void core__msg__Float32Arr__rosidl_typesupport_introspection_c__Float32Arr_fini_function(void * message_memory)
{
  core__msg__Float32Arr__fini(message_memory);
}

size_t core__msg__Float32Arr__rosidl_typesupport_introspection_c__size_function__Float32Arr__array(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * core__msg__Float32Arr__rosidl_typesupport_introspection_c__get_const_function__Float32Arr__array(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * core__msg__Float32Arr__rosidl_typesupport_introspection_c__get_function__Float32Arr__array(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void core__msg__Float32Arr__rosidl_typesupport_introspection_c__fetch_function__Float32Arr__array(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    core__msg__Float32Arr__rosidl_typesupport_introspection_c__get_const_function__Float32Arr__array(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void core__msg__Float32Arr__rosidl_typesupport_introspection_c__assign_function__Float32Arr__array(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    core__msg__Float32Arr__rosidl_typesupport_introspection_c__get_function__Float32Arr__array(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool core__msg__Float32Arr__rosidl_typesupport_introspection_c__resize_function__Float32Arr__array(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember core__msg__Float32Arr__rosidl_typesupport_introspection_c__Float32Arr_message_member_array[1] = {
  {
    "array",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(core__msg__Float32Arr, array),  // bytes offset in struct
    NULL,  // default value
    core__msg__Float32Arr__rosidl_typesupport_introspection_c__size_function__Float32Arr__array,  // size() function pointer
    core__msg__Float32Arr__rosidl_typesupport_introspection_c__get_const_function__Float32Arr__array,  // get_const(index) function pointer
    core__msg__Float32Arr__rosidl_typesupport_introspection_c__get_function__Float32Arr__array,  // get(index) function pointer
    core__msg__Float32Arr__rosidl_typesupport_introspection_c__fetch_function__Float32Arr__array,  // fetch(index, &value) function pointer
    core__msg__Float32Arr__rosidl_typesupport_introspection_c__assign_function__Float32Arr__array,  // assign(index, value) function pointer
    core__msg__Float32Arr__rosidl_typesupport_introspection_c__resize_function__Float32Arr__array  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers core__msg__Float32Arr__rosidl_typesupport_introspection_c__Float32Arr_message_members = {
  "core__msg",  // message namespace
  "Float32Arr",  // message name
  1,  // number of fields
  sizeof(core__msg__Float32Arr),
  core__msg__Float32Arr__rosidl_typesupport_introspection_c__Float32Arr_message_member_array,  // message members
  core__msg__Float32Arr__rosidl_typesupport_introspection_c__Float32Arr_init_function,  // function to initialize message memory (memory has to be allocated)
  core__msg__Float32Arr__rosidl_typesupport_introspection_c__Float32Arr_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t core__msg__Float32Arr__rosidl_typesupport_introspection_c__Float32Arr_message_type_support_handle = {
  0,
  &core__msg__Float32Arr__rosidl_typesupport_introspection_c__Float32Arr_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_core
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, core, msg, Float32Arr)() {
  if (!core__msg__Float32Arr__rosidl_typesupport_introspection_c__Float32Arr_message_type_support_handle.typesupport_identifier) {
    core__msg__Float32Arr__rosidl_typesupport_introspection_c__Float32Arr_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &core__msg__Float32Arr__rosidl_typesupport_introspection_c__Float32Arr_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
