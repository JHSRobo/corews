// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from core:msg/Float32Arr.idl
// generated code does not contain a copyright notice
#include "core/msg/detail/float32_arr__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "core/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "core/msg/detail/float32_arr__struct.h"
#include "core/msg/detail/float32_arr__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // array
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // array

// forward declare type support functions


using _Float32Arr__ros_msg_type = core__msg__Float32Arr;

static bool _Float32Arr__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Float32Arr__ros_msg_type * ros_message = static_cast<const _Float32Arr__ros_msg_type *>(untyped_ros_message);
  // Field name: array
  {
    size_t size = ros_message->array.size;
    auto array_ptr = ros_message->array.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _Float32Arr__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Float32Arr__ros_msg_type * ros_message = static_cast<_Float32Arr__ros_msg_type *>(untyped_ros_message);
  // Field name: array
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->array.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->array);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->array, size)) {
      fprintf(stderr, "failed to create array for field 'array'");
      return false;
    }
    auto array_ptr = ros_message->array.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_core
size_t get_serialized_size_core__msg__Float32Arr(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Float32Arr__ros_msg_type * ros_message = static_cast<const _Float32Arr__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name array
  {
    size_t array_size = ros_message->array.size;
    auto array_ptr = ros_message->array.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Float32Arr__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_core__msg__Float32Arr(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_core
size_t max_serialized_size_core__msg__Float32Arr(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: array
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Float32Arr__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_core__msg__Float32Arr(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Float32Arr = {
  "core::msg",
  "Float32Arr",
  _Float32Arr__cdr_serialize,
  _Float32Arr__cdr_deserialize,
  _Float32Arr__get_serialized_size,
  _Float32Arr__max_serialized_size
};

static rosidl_message_type_support_t _Float32Arr__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Float32Arr,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, core, msg, Float32Arr)() {
  return &_Float32Arr__type_support;
}

#if defined(__cplusplus)
}
#endif
