// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from core:msg/Float32Arr.idl
// generated code does not contain a copyright notice

#ifndef CORE__MSG__DETAIL__FLOAT32_ARR__TRAITS_HPP_
#define CORE__MSG__DETAIL__FLOAT32_ARR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "core/msg/detail/float32_arr__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace core
{

namespace msg
{

inline void to_flow_style_yaml(
  const Float32Arr & msg,
  std::ostream & out)
{
  out << "{";
  // member: array
  {
    if (msg.array.size() == 0) {
      out << "array: []";
    } else {
      out << "array: [";
      size_t pending_items = msg.array.size();
      for (auto item : msg.array) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Float32Arr & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: array
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.array.size() == 0) {
      out << "array: []\n";
    } else {
      out << "array:\n";
      for (auto item : msg.array) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Float32Arr & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace core

namespace rosidl_generator_traits
{

[[deprecated("use core::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const core::msg::Float32Arr & msg,
  std::ostream & out, size_t indentation = 0)
{
  core::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use core::msg::to_yaml() instead")]]
inline std::string to_yaml(const core::msg::Float32Arr & msg)
{
  return core::msg::to_yaml(msg);
}

template<>
inline const char * data_type<core::msg::Float32Arr>()
{
  return "core::msg::Float32Arr";
}

template<>
inline const char * name<core::msg::Float32Arr>()
{
  return "core/msg/Float32Arr";
}

template<>
struct has_fixed_size<core::msg::Float32Arr>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<core::msg::Float32Arr>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<core::msg::Float32Arr>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CORE__MSG__DETAIL__FLOAT32_ARR__TRAITS_HPP_
