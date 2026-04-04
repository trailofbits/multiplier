// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../Compiler.h"
#include "../Types.h"
#include <memory>
#include <optional>
#include <gap/coro/generator.hpp>

namespace mx {

class IRBlock;
class IRObject;
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

  // The source FunctionDecl.
  std::optional<FunctionDecl> declaration(void) const;

  // Entry block.
  IRBlock entry_block(void) const;

  // Blocks in RPO order.
  gap::generator<IRBlock> blocks(void) const &;

  // Memory objects.
  gap::generator<IRObject> objects(void) const &;

  // Find the IR for a FunctionDecl.
  static std::optional<IRFunction> from(const FunctionDecl &decl);

};

}  // namespace mx
