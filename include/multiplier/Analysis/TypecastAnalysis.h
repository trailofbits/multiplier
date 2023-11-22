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

#include <optional>
#include <vector>
#include <variant>
#include <unordered_set>

namespace mx {

class CastState;

using CastStateMap = std::unordered_map<PackedStmtId, CastState>;

// TODO: what else?
// TODO: interesting: VECTOR_SPLAT, ARRAY_TO_POINTER_DECAY

static constexpr CastKind kCXXObjectCasts[] = {
  // represents most non-ptr object casting
  CastKind::BASE_TO_DERIVED,
  CastKind::DERIVED_TO_BASE,
  CastKind::UNCHECKED_DERIVED_TO_BASE,

  // explicit pointer up/down casting
  CastKind::REINTERPRET_MEMBER_POINTER,
  CastKind::DYNAMIC,

  // implicit pointer up/down casting
  CastKind::BASE_TO_DERIVED_MEMBER_POINTER,
  CastKind::DERIVED_TO_BASE_MEMBER_POINTER,
};

// CastKinds that we are choosing not to be represented as a CastState
static constexpr CastKind kNoneTypeCasts[] = {
  CastKind::FUNCTION_TO_POINTER_DECAY,
  CastKind::BUILTIN_FN_TO_FN_POINTER,
  CastKind::ARRAY_TO_POINTER_DECAY,
  CastKind::VECTOR_SPLAT,
  CastKind::MATRIX_CAST,

  // objc casting
  CastKind::C_POINTER_TO_OBJ_C_POINTER_CAST,
  CastKind::BLOCK_POINTER_TO_OBJ_C_POINTER_CAST,
  CastKind::ANY_POINTER_TO_BLOCK_POINTER_CAST,
  CastKind::OBJ_C_OBJECT_L_VALUE_CAST,
  CastKind::ARC_PRODUCE_OBJECT,
  CastKind::ARC_CONSUME_OBJECT,
  CastKind::ARC_RECLAIM_RETURNED_OBJECT,
  CastKind::ARC_EXTEND_BLOCK_OBJECT,
  CastKind::ATOMIC_TO_NON_ATOMIC,
  CastKind::NON_ATOMIC_TO_ATOMIC,
  CastKind::COPY_AND_AUTORELEASE_BLOCK_OBJECT,
  CastKind::ZERO_TO_OCL_OPAQUE_TYPE,
  CastKind::ADDRESS_SPACE_CONVERSION,
  CastKind::INT_TO_OCL_SAMPLER,
  CastKind::NO_OPERATION,
};

// Represents sign changes for built-in types
enum class CastSignChange {
  C_UNSIGNED_TO_SIGNED,
  C_SIGNED_TO_UNSIGNED,
  NO_SIGN_CHANGE,
};

enum class CastTypeWidth {
  UPCAST,
  DOWNCAST,
  NO_WIDTH_CHANGE,
};

enum class CastCXXObjKind {
  BASE_TO_DERIVED_DOWNCAST,
  DERIVED_TO_BASE_UPCAST,
  NO_CXX_OBJ_CAST,
};

// Models a single generic typecast operation and different useful properties
// computed from the backing CastExpr.
class CastState final {
private:
  CastExpr cast_expr;

  // helpers
  std::optional<CastKind> cxx_object_cast_kind();
  CastTypeWidth determine_width_cast(Type&, Type&);

public:
  CastState(const CastExpr &);

  // Grab a reference to the underlying CastExpr
  // TODO: delete?
  const CastExpr& get_cast_expr();

  // What is the data entity we're casting from?
  VariantEntity source_entity() const;
  EntityId source_entity_id() const;

  // What is the data entity we're casting to?
  // Can return `std::nullopt` if the cast happens during a call or return.
  std::optional<VariantEntity> destination_entity() const;
  std::optional<EntityId> destination_entity_id() const;

  // What is the explicit type alias if any?

  // Is this cast performed as an argument in a CallExpr?
  std::optional<std::pair<PackedStmtId, unsigned>> is_part_of_call_arg();

  // What is the type before/after conversion?
  std::pair<Type, Type> types_before_after_conversion() const;

  // Is this an implicit cast?
  std::optional<bool> is_implicit_cast();

  // Is the source and/or destination type a pointer?
  bool is_pointer_cast();

  // Did the sign change? This applies only to built-in casts.
  CastSignChange sign_change();

  // Is there a down/upcast in the size of the type?
  CastTypeWidth width_cast();

  // Is there a down/upcast in the size of the type after dereferencing
  // any pointers in the source and/or destination type?
  CastTypeWidth deferenced_width_cast();

  // Is there a down/upcast in the C++ class type?
  CastCXXObjKind cxx_obj_cast();
};

// Represents all ordered typecast conversions of a single data source
class TypecastChain final {
private:
  friend CastState;

  bool is_forward;

  // populated after first transition
  Type *root_type;

  // stores final destination types after a leaf transition is added
  std::unordered_set<Type*> last_resolved_types;

  // holds most recent destination type at current transition
  Type* current_resolved_type;

  // maps taint entity IDs to subsequent type cast transitions
  std::map<EntityId, std::vector<CastState>> cast_state_nodes;

public:
  TypecastChain(bool);

  // For a reference entity, add an associated Cast State.
  // Returns a positive number if the transition makes the graph cyclic
  int add_new_transition(EntityId, const CastState&, bool);

  // Get the initial data source's original type
  Type* get_root_type();

  // Resolve the most recent destination type
  Type* get_current_resolved_type();

  // Does the type at the end of the chain match the one in the beginning?
  bool is_identity_preserving();

  // TODO Return lists of every possible typecasting path
  //unsigned int num_chains();
  //gap::generator<std::vector<CastState>> chains();
};

// Main interface for dispatching typecast analyses.
class TypecastAnalysis final {
public:
  TypecastAnalysis(void) = default;

  // Traverse the AST tree of a starting fragment to recover all casting instances and the associated CastExpr's ID.
  // Will not resolve a typecast chain for individual data sources.
  // Answers the question: "what are all the typecasts happening in this current fragment?"
  CastStateMap cast_instances(const Stmt &);
  //  CastStateMap cast_instances(const Reference &);

  // At a specific entity reference point, resolve a forward or backward typecast chain
  TypecastChain cast_chain(const VariantEntity &id, bool backwards);
};
}; // namespace mx