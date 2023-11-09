// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "multiplier/Entities/CastKind.h"
#include <gap/core/generator.hpp>
#include <multiplier/Index.h>

#include <multiplier/Entities/CastExpr.h>

#include <vector>

namespace mx {

// TODO: what else?

static constexpr CastKind kCXXObjectCasts[] = {
  CastKind::BASE_TO_DERIVED,
  CastKind::DERIVED_TO_BASE,
  CastKind::UNCHECKED_DERIVED_TO_BASE,
  CastKind::REINTERPRET_MEMBER_POINTER,
  CastKind::BASE_TO_DERIVED_MEMBER_POINTER,
  CastKind::DERIVED_TO_BASE_MEMBER_POINTER,
};

static constexpr CastKind kNoneTypeCasts[] = {
  CastKind::FUNCTION_TO_POINTER_DECAY,
  CastKind::ARRAY_TO_POINTER_DECAY,
  CastKind::INT_TO_OCL_SAMPLER,
  CastKind::NO_OPERATION,
};

enum class CastSignChange {
  C_UNSIGNED_TO_SIGNED,
  C_SIGNED_TO_UNSIGNED,
  NO_SIGN_CHANGE,
};

enum class CastBehavior {
  // e.g. int -> long, long -> int
  C_TYPE_WIDTH_DOWNCAST,
  C_TYPE_WIDTH_UPCAST,

  // e.g. big_t* -> small_t*, small_t* -> big_t*
  C_PTR_TYPE_DOWNCAST,
  C_PTR_TYPE_UPCAST,

  // e.g. Base -> Derived, Derived -> Base
  CXX_OBJ_UPCAST,
  CXX_OBJ_DOWNCAST,

  // e.g. int -> int, ptr_t* -> ptr_t*
  NO_CAST_BEHAVIOR,
};

// Models a single cast operation in the
class CastState final {
private:
  const CastExpr &cast_expr;

  // where are we casting from/to?
  EntityId source_entity;
  EntityId destination_entity;

public:
  CastState(const CastExpr &);

  Type type_before_conversion();
  Type type_after_conversion();

  CastBehavior get_cast_behavior();

  bool is_implicit_cast();
  CastSignChange get_sign_change();
};

class TypecastChain final {
private:
  // 
  Type current_resolved_type;

public:
  TypecastChain();
};


class TypecastAnalysis final {
private:
  TypecastAnalysis(void) = delete;

public:
  TypecastAnalysis(const Index &);

  // Traverse the AST tree of a starting fragment to recover all casting instances.
  void cast_instances(const Fragment &);

  // At each use of an entity, generate a TypecastChain
  TypecastChain cast_chain(const EntityId &);

};
} // namespace mx