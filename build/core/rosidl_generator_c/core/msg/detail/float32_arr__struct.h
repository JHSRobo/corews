// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from core:msg/Float32Arr.idl
// generated code does not contain a copyright notice

#ifndef CORE__MSG__DETAIL__FLOAT32_ARR__STRUCT_H_
#define CORE__MSG__DETAIL__FLOAT32_ARR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'array'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Float32Arr in the package core.
typedef struct core__msg__Float32Arr
{
  rosidl_runtime_c__float__Sequence array;
} core__msg__Float32Arr;

// Struct for a sequence of core__msg__Float32Arr.
typedef struct core__msg__Float32Arr__Sequence
{
  core__msg__Float32Arr * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} core__msg__Float32Arr__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CORE__MSG__DETAIL__FLOAT32_ARR__STRUCT_H_
