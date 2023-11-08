// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gap/core/generator.hpp>
#include <multiplier/Index.h>

namespace mx {

enum class CastKind {
  SIGN_CHANGE,
  TYPE_DOWNCAST,
  TYPE_UPCAST,
};

typedef struct {
  int before;
  int after;

  CastKind kind;
} TCast;

using TypeCastChain = std::list<TypecastChainNode>;

class TypecastAnalysis final {
private:

  TypecastAnalysis(void) = delete;

public:
  TypecastAnalysis(const Index &);

  // Traverse the AST tree of a starting statement to recover all casting instances.
  void cast_instances(const Stmt &);

  // Traverse the AST tree of a starting declaration to recover all casting instances.
  void cast_instances(const Expr &);

  // At each use of an entity, generate a TypecastChain
  void cast_chain(const EntityId &);

};
} // namespace mx