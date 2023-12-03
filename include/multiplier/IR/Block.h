// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <gap/core/generator.hpp>
#include <memory>

#include "Value.h"

namespace mlir {
class Block;
class BlockArgument;
class BlockOperand;
}  // namespace mlir
namespace mx::ir {

class Argument;
class Label;
class Operation;
class Region;
class SourceIRImpl;

// A region is owned by an operation (not all operations own regions)
// and contain one or more blocks.
class MX_EXPORT Block final {
 private:
  friend class Operation;
  friend class Region;
  friend class Argument;
  friend class Label;

  std::shared_ptr<const SourceIRImpl> module_;
  mlir::Block *block_;

 public:
  inline Block(std::shared_ptr<const SourceIRImpl> module,
               mlir::Block *block)
      : module_(std::move(module)),
        block_(block) {}

  inline Block(std::shared_ptr<const SourceIRImpl> module,
               mlir::Block &block)
      : Block(std::move(module), &block) {}

  // Return the block containing a given argument.
  static Block containing(const Argument &);

  // We almost always have an owning block for an operation. The exception is
  // the `mx::ir::builtin::ModuleOp` case.
  static std::optional<Block> containing(const Operation &);

  unsigned num_arguments(void) const noexcept;

  std::optional<Argument> nth_argument(unsigned) const noexcept;

  // Arguments to the block. Block arguments are like PHI nodes.
  gap::generator<Argument> arguments(void) const & noexcept;

  // Operations within a block. Every block has at least one operation, its
  // terminator.
  gap::generator<Operation> operations(void) const & noexcept;

  // Operations within a block in reverse order.
  gap::generator<Operation> reverse_operations(void) const & noexcept;

  // Set of operands that use this block. For example, a block can be an
  // operand to a terminator operation.
  gap::generator<Label> uses(void) const & noexcept;

  // Return the terminating operation of a block.
  Operation terminator(void) const noexcept;
};

// An parameter to a block is like a PHI node in an SSA IR. It provides a merge
// point for values used by this block (or made available to successors) that
// that come from predecessors.
class MX_EXPORT Argument final : public Value {
 private:
  friend class Block;
  friend class Region;
  friend class Value;

  inline Argument(std::shared_ptr<const SourceIRImpl> module,
                  mlir::detail::BlockArgumentImpl *arg)
      : Value(std::move(module), arg) {}

 public:

  static std::optional<Argument> from(const Value &val);

  // Index of this block argument.
  unsigned index(void) const noexcept;
};

static_assert(sizeof(Argument) == sizeof(Value));

// A use of a block, e.g. in a terminator operation.
class MX_EXPORT Label final {
 private:
  friend class Block;
  friend class Label;
  friend class Operation;
  friend class Value;

  std::shared_ptr<const SourceIRImpl> module_;
  mlir::BlockOperand *op_;

  inline Label(std::shared_ptr<const SourceIRImpl> module,
               mlir::BlockOperand *op)
      : module_(std::move(module)),
        op_(op) {}

 public:
  // The operation containing this operand.
  Operation operation(void) const noexcept;

  // The block referenced by this label.
  Block block(void) const noexcept;

  // The index of this operand within its owner operation's block operand list.
  unsigned index(void) const noexcept;
};

}  // namespace mx::ir
