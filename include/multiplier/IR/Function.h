// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../Compiler.h"
#include "../Types.h"
#include "FunctionKind.h"
#include <memory>
#include <optional>
#include <gap/coro/generator.hpp>

namespace mx {

class Decl;
class IRBlock;
class IRObject;
class IRStructure;
class IRFunctionImpl;
class FunctionDecl;
using IRFunctionImplPtr = std::shared_ptr<const IRFunctionImpl>;

class MX_EXPORT IRFunction {
 private:
  friend class EntityProvider;
  friend class Index;
  IRFunctionImplPtr impl;

 public:
  IRFunction(void) = default;
  explicit IRFunction(IRFunctionImplPtr impl_)
      : impl(std::move(impl_)) {}

  EntityId id(void) const;

  // Function kind (NORMAL, GLOBAL_INITIALIZER, etc.)
  ir::FunctionKind kind(void) const;

  // The source FunctionDecl (nullopt for non-NORMAL kinds).
  std::optional<FunctionDecl> declaration(void) const;

  // The source declaration regardless of kind (FunctionDecl or VarDecl).
  std::optional<Decl> source_declaration(void) const;

  // Entry block.
  IRBlock entry_block(void) const;

  // Blocks in RPO order.
  gap::generator<IRBlock> blocks(void) const &;

  // Memory objects.
  gap::generator<IRObject> objects(void) const &;

  // Root of the structure tree (FUNCTION_SCOPE).
  std::optional<IRStructure> body_scope(void) const;

  // Find the IR for a FunctionDecl.
  static std::optional<IRFunction> from(const FunctionDecl &decl);

};

}  // namespace mx
