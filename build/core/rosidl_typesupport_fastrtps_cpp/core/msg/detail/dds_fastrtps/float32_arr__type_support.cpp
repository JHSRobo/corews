// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from core:msg/Float32Arr.idl
// generated code does not contain a copyright notice
#include "core/msg/detail/float32_arr__rosidl_typesupport_fastrtps_cpp.hpp"
#include "core/msg/detail/float32_arr__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace core
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_core
cdr_serialize(
  const core::msg::Float32Arr & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: array
  {
    cdr << ros_message.array;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_core
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  core::msg::Float32Arr & ros_message)
{
  // Member: array
  {
    cdr >> ros_message.array;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_core
get_serialized_size(
  const core::msg::Float32Arr & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: array
  {
    size_t array_size = ros_message.array.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.array[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_core
max_serialized_size_Float32Arr(
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


  // Member: array
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

static bool _Float32Arr__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const core::msg::Float32Arr *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Float32Arr__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<core::msg::Float32Arr *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Float32Arr__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const core::msg::Float32Arr *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Float32Arr__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Float32Arr(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Float32Arr__callbacks = {
  "core::msg",
  "Float32Arr",
  _Float32Arr__cdr_serialize,
  _Float32Arr__cdr_deserialize,
  _Float32Arr__get_serialized_size,
  _Float32Arr__max_serialized_size
};

static rosidl_message_type_support_t _Float32Arr__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Float32Arr__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace core

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_core
const rosidl_message_type_support_t *
get_message_type_support_handle<core::msg::Float32Arr>()
{
  return &core::msg::typesupport_fastrtps_cpp::_Float32Arr__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, core, msg, Float32Arr)() {
  return &core::msg::typesupport_fastrtps_cpp::_Float32Arr__handle;
}

#ifdef __cplusplus
}
#endif
