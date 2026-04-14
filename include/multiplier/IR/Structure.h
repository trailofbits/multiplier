// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../Compiler.h"
#include "../Types.h"
#include "StructureKind.h"
#include <memory>
#include <optional>
#include <gap/coro/generator.hpp>

namespace mx {

class IRBlock;
class IRFunction;
class IRObject;
class IRStructureImpl;
class Stmt;
using IRStructureImplPtr = std::shared_ptr<const IRStructureImpl>;

class MX_EXPORT IRStructure {
 protected:
  friend class EntityProvider;
  friend class Index;
  friend class IRBlock;
  friend class IRFunction;
  IRStructureImplPtr impl;

  // For derived structure classes.
  friend class IRScopeStructure;
  friend class IRIfStructure;
  friend class IRIfThenStructure;
  friend class IRIfElseStructure;
  friend class IRForStructure;
  friend class IRWhileStructure;
  friend class IRDoWhileStructure;
  friend class IRSwitchStructure;
  friend class IRSwitchCaseStructure;
  friend class IRExpressionScopeStructure;
  IRStructureImplPtr impl_ptr(void) const { return impl; }

 public:
  IRStructure(void) = default;
  explicit IRStructure(IRStructureImplPtr impl_)
      : impl(std::move(impl_)) {}

  EntityId id(void) const;
  ir::StructureKind kind(void) const;

  // AST provenance: the CompoundStmt, IfStmt, ForStmt, etc.
  std::optional<Stmt> source_statement(void) const;

  // Parent: another structure or function.
  std::optional<IRStructure> parent_structure(void) const;
  std::optional<IRFunction> parent_function(void) const;

  // Children (structures and blocks in source order).
  gap::generator<IRStructure> child_structures(void) const &;
  gap::generator<IRBlock> child_blocks(void) const &;

  // Scope-specific: objects (ALLOCAs) declared in this scope.
  // Only meaningful for FUNCTION_SCOPE and SCOPE kinds.
  gap::generator<IRObject> objects(void) const &;

  // Convenience: scope-kind check.
  bool is_scope(void) const;
};

}  // namespace mx
