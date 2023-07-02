// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from core:msg/Float32Arr.idl
// generated code does not contain a copyright notice

#ifndef CORE__MSG__DETAIL__FLOAT32_ARR__BUILDER_HPP_
#define CORE__MSG__DETAIL__FLOAT32_ARR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "core/msg/detail/float32_arr__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace core
{

namespace msg
{

namespace builder
{

class Init_Float32Arr_array
{
public:
  Init_Float32Arr_array()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::core::msg::Float32Arr array(::core::msg::Float32Arr::_array_type arg)
  {
    msg_.array = std::move(arg);
    return std::move(msg_);
  }

private:
  ::core::msg::Float32Arr msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::core::msg::Float32Arr>()
{
  return core::msg::builder::Init_Float32Arr_array();
}

}  // namespace core

#endif  // CORE__MSG__DETAIL__FLOAT32_ARR__BUILDER_HPP_
