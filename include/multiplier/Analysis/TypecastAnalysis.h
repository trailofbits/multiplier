// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "multiplier/Entities/CastKind.h"
#include "multiplier/Types.h"
#include <gap/core/generator.hpp>
#include <multiplier/Index.h>

#include <multiplier/Entities/CastExpr.h>

#include <vector>
#include <variant>

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

// Models a single generic typecast operation and different useful properties
// computed from the backing CastExpr.
class CastState final {
private:
  const CastExpr &cast_expr;

public:
  CastState(const CastExpr &);

  // where are we casting from/to?
  EntityId source_entity();
  EntityId destination_entity();

  // what is the type before/after conversion?
  Type type_before_conversion();
  Type type_after_conversion();

  std::optional<bool> is_implicit_cast();
  CastSignChange get_sign_change();
  CastBehavior get_cast_behavior();

};

using CastStateMap = std::unordered_map<PackedStmtId, CastState>;

// Represents all ordered typecast conversions of a single data source
class TypecastChain final {
private:
  std::vector<CastState> cast_state_transitions;
  bool is_forward;

  std::optional<Type> current_resolved_type;

public:
  TypecastChain(bool);

  void add_new_transition(CastState&);
  std::optional<Type> get_current_resolved_type();

  // Does the type at the end of the chain match the one in the beginning?
  bool is_identity_preserving();

  // Prepare a single CastState to represent the resolved type cast
  CastState& resolved_cast_state();

};


class TypecastAnalysis final {
private:
  TypecastAnalysis(void) = delete;

public:
  TypecastAnalysis(const Index &);

  // Traverse the AST tree of a starting fragment to recover all casting instances.
  // Will not resolve a typecast chain for individual data sources.
  // Answers the question: "what are all the typecasts happening in this current fragment?"
  CastStateMap cast_instances(const Fragment &);
  CastStateMap cast_instances(const Stmt &);

  // At a specific entity reference point, resolve a forward or backward typecast chain
  // TODO: MLIR DependencyAnalysis
  TypecastChain forward_cast_chain(const EntityId &);
  TypecastChain backward_cast_chain(const EntityId &);

};
}; // namespace mx