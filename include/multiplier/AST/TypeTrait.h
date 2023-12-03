// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class TypeTrait : unsigned char {
  IS_INTERFACE_CLASS,
  IS_SEALED,
  IS_DESTRUCTIBLE,
  IS_TRIVIALLY_DESTRUCTIBLE,
  IS_NOTHROW_DESTRUCTIBLE,
  HAS_NOTHROW_MOVE_ASSIGN,
  HAS_TRIVIAL_MOVE_ASSIGN,
  HAS_TRIVIAL_MOVE_CONSTRUCTOR,
  HAS_NOTHROW_ASSIGN,
  HAS_NOTHROW_COPY,
  HAS_NOTHROW_CONSTRUCTOR,
  HAS_TRIVIAL_ASSIGN,
  HAS_TRIVIAL_COPY,
  HAS_TRIVIAL_DEFAULT_CONSTRUCTOR,
  HAS_TRIVIAL_DESTRUCTOR,
  HAS_VIRTUAL_DESTRUCTOR,
  IS_ABSTRACT,
  IS_AGGREGATE,
  IS_CLASS,
  IS_EMPTY,
  IS_ENUM,
  IS_FINAL,
  IS_LITERAL,
  IS_POD,
  IS_POLYMORPHIC,
  IS_STANDARD_LAYOUT,
  IS_TRIVIAL,
  IS_TRIVIALLY_COPYABLE,
  IS_UNION,
  HAS_UNIQUE_OBJECT_REPRESENTATIONS,
  IS_TRIVIALLY_RELOCATABLE,
  IS_TRIVIALLY_EQUALITY_COMPARABLE,
  IS_BOUNDED_ARRAY,
  IS_UNBOUNDED_ARRAY,
  IS_NULL_POINTER,
  IS_SCOPED_ENUM,
  IS_REFERENCEABLE,
  CAN_PASS_IN_REGS,
  IS_ARITHMETIC,
  IS_FLOATING_POINT,
  IS_INTEGRAL,
  IS_COMPLETE_TYPE,
  IS_VOID,
  IS_ARRAY,
  IS_FUNCTION,
  IS_REFERENCE,
  IS_LVALUE_REFERENCE,
  IS_RVALUE_REFERENCE,
  IS_FUNDAMENTAL,
  IS_OBJECT,
  IS_SCALAR,
  IS_COMPOUND,
  IS_POINTER,
  IS_MEMBER_OBJECT_POINTER,
  IS_MEMBER_FUNCTION_POINTER,
  IS_MEMBER_POINTER,
  IS_CONST,
  IS_VOLATILE,
  IS_SIGNED,
  IS_UNSIGNED,
  TYPE_COMPATIBLE,
  IS_NOTHROW_ASSIGNABLE,
  IS_ASSIGNABLE,
  IS_BASE_OF,
  IS_CONVERTIBLE_TO,
  IS_TRIVIALLY_ASSIGNABLE,
  REFERENCE_BINDS_TO_TEMPORARY,
  IS_SAME,
  IS_CONVERTIBLE,
  XNU_TYPE_COMPATIBLE,
  IS_CONSTRUCTIBLE,
  IS_NOTHROW_CONSTRUCTIBLE,
  IS_TRIVIALLY_CONSTRUCTIBLE,
};

inline static const char *EnumerationName(TypeTrait) {
  return "TypeTrait";
}

inline static constexpr unsigned NumEnumerators(TypeTrait) {
  return 73;
}

MX_EXPORT const char *EnumeratorName(TypeTrait);

} // namespace mx
