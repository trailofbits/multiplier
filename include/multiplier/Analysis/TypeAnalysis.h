// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gap/core/generator.hpp>
#include <multiplier/Index.h>

#include <multiplier/Entities/CastExpr.h>
#include <multiplier/Entities/ImplicitCastExpr.h>

#include <unordered_set>

namespace mx {

enum class CastWidthChange {
  SIGN_CHANGE,
  TYPE_DOWNCAST,
  TYPE_UPCAST,
};

// Enriched metadata after the CastExpr
class CastState final {

  // what entity was the casting performed on?s
  EntityId referenced_entity;

  Type type_before;
  Type type_after;

  bool type_before_is_builtin;
  bool type_after_is_builtin;

  CastKind cast_kind;
  bool is_implicit;
public:
  CastState()
};

class TypeCastChain final {
private:
  std::unordered_set<CastState> transitions;

public:
  TypeCastChain();
};


class TypecastAnalysis final {
private:

  TypecastAnalysis(void) = delete;

public:
  TypecastAnalysis(const Index &);

  // Traverse the AST tree of a starting fragment to recover all casting instances.
  void cast_instances(const Fragment &);

  // At each use of an entity, generate a TypecastChain
  TypeCastChain cast_chain(const EntityId &);

};
} // namespace mx