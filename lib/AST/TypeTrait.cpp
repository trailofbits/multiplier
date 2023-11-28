// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TypeTrait.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TypeTrait e) {
  switch (e) {
    case TypeTrait::IS_INTERFACE_CLASS: return "IS_INTERFACE_CLASS";
    case TypeTrait::IS_SEALED: return "IS_SEALED";
    case TypeTrait::IS_DESTRUCTIBLE: return "IS_DESTRUCTIBLE";
    case TypeTrait::IS_TRIVIALLY_DESTRUCTIBLE: return "IS_TRIVIALLY_DESTRUCTIBLE";
    case TypeTrait::IS_NOTHROW_DESTRUCTIBLE: return "IS_NOTHROW_DESTRUCTIBLE";
    case TypeTrait::HAS_NOTHROW_MOVE_ASSIGN: return "HAS_NOTHROW_MOVE_ASSIGN";
    case TypeTrait::HAS_TRIVIAL_MOVE_ASSIGN: return "HAS_TRIVIAL_MOVE_ASSIGN";
    case TypeTrait::HAS_TRIVIAL_MOVE_CONSTRUCTOR: return "HAS_TRIVIAL_MOVE_CONSTRUCTOR";
    case TypeTrait::HAS_NOTHROW_ASSIGN: return "HAS_NOTHROW_ASSIGN";
    case TypeTrait::HAS_NOTHROW_COPY: return "HAS_NOTHROW_COPY";
    case TypeTrait::HAS_NOTHROW_CONSTRUCTOR: return "HAS_NOTHROW_CONSTRUCTOR";
    case TypeTrait::HAS_TRIVIAL_ASSIGN: return "HAS_TRIVIAL_ASSIGN";
    case TypeTrait::HAS_TRIVIAL_COPY: return "HAS_TRIVIAL_COPY";
    case TypeTrait::HAS_TRIVIAL_DEFAULT_CONSTRUCTOR: return "HAS_TRIVIAL_DEFAULT_CONSTRUCTOR";
    case TypeTrait::HAS_TRIVIAL_DESTRUCTOR: return "HAS_TRIVIAL_DESTRUCTOR";
    case TypeTrait::HAS_VIRTUAL_DESTRUCTOR: return "HAS_VIRTUAL_DESTRUCTOR";
    case TypeTrait::IS_ABSTRACT: return "IS_ABSTRACT";
    case TypeTrait::IS_AGGREGATE: return "IS_AGGREGATE";
    case TypeTrait::IS_CLASS: return "IS_CLASS";
    case TypeTrait::IS_EMPTY: return "IS_EMPTY";
    case TypeTrait::IS_ENUM: return "IS_ENUM";
    case TypeTrait::IS_FINAL: return "IS_FINAL";
    case TypeTrait::IS_LITERAL: return "IS_LITERAL";
    case TypeTrait::IS_POD: return "IS_POD";
    case TypeTrait::IS_POLYMORPHIC: return "IS_POLYMORPHIC";
    case TypeTrait::IS_STANDARD_LAYOUT: return "IS_STANDARD_LAYOUT";
    case TypeTrait::IS_TRIVIAL: return "IS_TRIVIAL";
    case TypeTrait::IS_TRIVIALLY_COPYABLE: return "IS_TRIVIALLY_COPYABLE";
    case TypeTrait::IS_UNION: return "IS_UNION";
    case TypeTrait::HAS_UNIQUE_OBJECT_REPRESENTATIONS: return "HAS_UNIQUE_OBJECT_REPRESENTATIONS";
    case TypeTrait::IS_TRIVIALLY_RELOCATABLE: return "IS_TRIVIALLY_RELOCATABLE";
    case TypeTrait::IS_TRIVIALLY_EQUALITY_COMPARABLE: return "IS_TRIVIALLY_EQUALITY_COMPARABLE";
    case TypeTrait::IS_BOUNDED_ARRAY: return "IS_BOUNDED_ARRAY";
    case TypeTrait::IS_UNBOUNDED_ARRAY: return "IS_UNBOUNDED_ARRAY";
    case TypeTrait::IS_NULL_POINTER: return "IS_NULL_POINTER";
    case TypeTrait::IS_SCOPED_ENUM: return "IS_SCOPED_ENUM";
    case TypeTrait::IS_REFERENCEABLE: return "IS_REFERENCEABLE";
    case TypeTrait::CAN_PASS_IN_REGS: return "CAN_PASS_IN_REGS";
    case TypeTrait::IS_ARITHMETIC: return "IS_ARITHMETIC";
    case TypeTrait::IS_FLOATING_POINT: return "IS_FLOATING_POINT";
    case TypeTrait::IS_INTEGRAL: return "IS_INTEGRAL";
    case TypeTrait::IS_COMPLETE_TYPE: return "IS_COMPLETE_TYPE";
    case TypeTrait::IS_VOID: return "IS_VOID";
    case TypeTrait::IS_ARRAY: return "IS_ARRAY";
    case TypeTrait::IS_FUNCTION: return "IS_FUNCTION";
    case TypeTrait::IS_REFERENCE: return "IS_REFERENCE";
    case TypeTrait::IS_LVALUE_REFERENCE: return "IS_LVALUE_REFERENCE";
    case TypeTrait::IS_RVALUE_REFERENCE: return "IS_RVALUE_REFERENCE";
    case TypeTrait::IS_FUNDAMENTAL: return "IS_FUNDAMENTAL";
    case TypeTrait::IS_OBJECT: return "IS_OBJECT";
    case TypeTrait::IS_SCALAR: return "IS_SCALAR";
    case TypeTrait::IS_COMPOUND: return "IS_COMPOUND";
    case TypeTrait::IS_POINTER: return "IS_POINTER";
    case TypeTrait::IS_MEMBER_OBJECT_POINTER: return "IS_MEMBER_OBJECT_POINTER";
    case TypeTrait::IS_MEMBER_FUNCTION_POINTER: return "IS_MEMBER_FUNCTION_POINTER";
    case TypeTrait::IS_MEMBER_POINTER: return "IS_MEMBER_POINTER";
    case TypeTrait::IS_CONST: return "IS_CONST";
    case TypeTrait::IS_VOLATILE: return "IS_VOLATILE";
    case TypeTrait::IS_SIGNED: return "IS_SIGNED";
    case TypeTrait::IS_UNSIGNED: return "IS_UNSIGNED";
    case TypeTrait::TYPE_COMPATIBLE: return "TYPE_COMPATIBLE";
    case TypeTrait::IS_NOTHROW_ASSIGNABLE: return "IS_NOTHROW_ASSIGNABLE";
    case TypeTrait::IS_ASSIGNABLE: return "IS_ASSIGNABLE";
    case TypeTrait::IS_BASE_OF: return "IS_BASE_OF";
    case TypeTrait::IS_CONVERTIBLE_TO: return "IS_CONVERTIBLE_TO";
    case TypeTrait::IS_TRIVIALLY_ASSIGNABLE: return "IS_TRIVIALLY_ASSIGNABLE";
    case TypeTrait::REFERENCE_BINDS_TO_TEMPORARY: return "REFERENCE_BINDS_TO_TEMPORARY";
    case TypeTrait::IS_SAME: return "IS_SAME";
    case TypeTrait::IS_CONVERTIBLE: return "IS_CONVERTIBLE";
    case TypeTrait::XNU_TYPE_COMPATIBLE: return "XNU_TYPE_COMPATIBLE";
    case TypeTrait::IS_CONSTRUCTIBLE: return "IS_CONSTRUCTIBLE";
    case TypeTrait::IS_NOTHROW_CONSTRUCTIBLE: return "IS_NOTHROW_CONSTRUCTIBLE";
    case TypeTrait::IS_TRIVIALLY_CONSTRUCTIBLE: return "IS_TRIVIALLY_CONSTRUCTIBLE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
