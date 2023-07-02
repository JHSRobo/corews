// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from core:msg/Float32Arr.idl
// generated code does not contain a copyright notice

#ifndef CORE__MSG__DETAIL__FLOAT32_ARR__STRUCT_HPP_
#define CORE__MSG__DETAIL__FLOAT32_ARR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__core__msg__Float32Arr __attribute__((deprecated))
#else
# define DEPRECATED__core__msg__Float32Arr __declspec(deprecated)
#endif

namespace core
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Float32Arr_
{
  using Type = Float32Arr_<ContainerAllocator>;

  explicit Float32Arr_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Float32Arr_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _array_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _array_type array;

  // setters for named parameter idiom
  Type & set__array(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->array = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    core::msg::Float32Arr_<ContainerAllocator> *;
  using ConstRawPtr =
    const core::msg::Float32Arr_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<core::msg::Float32Arr_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<core::msg::Float32Arr_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      core::msg::Float32Arr_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<core::msg::Float32Arr_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      core::msg::Float32Arr_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<core::msg::Float32Arr_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<core::msg::Float32Arr_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<core::msg::Float32Arr_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__core__msg__Float32Arr
    std::shared_ptr<core::msg::Float32Arr_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__core__msg__Float32Arr
    std::shared_ptr<core::msg::Float32Arr_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Float32Arr_ & other) const
  {
    if (this->array != other.array) {
      return false;
    }
    return true;
  }
  bool operator!=(const Float32Arr_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Float32Arr_

// alias to use template instance with default allocator
using Float32Arr =
  core::msg::Float32Arr_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace core

#endif  // CORE__MSG__DETAIL__FLOAT32_ARR__STRUCT_HPP_
