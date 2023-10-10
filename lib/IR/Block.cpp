// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/Block.h>

#include <mlir/IR/Block.h>
#include <mlir/IR/Operation.h>
#include <mlir/IR/OperationSupport.h>
#include <mlir/IR/Region.h>
#include <mlir/IR/Value.h>
#include <multiplier/IR/Operation.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Value.h>

namespace mx::ir {

// Return the block containing a given argument.
Block Block::containing(const Argument &arg_) {
  mlir::BlockArgument arg(arg_.impl_.arg);
  return Block(arg_.module_, arg.getParentBlock());
}

// We almost always have an owning block for an operation. The exception is
// the `mx::ir::builtin::ModuleOp` case.
std::optional<Block> Block::containing(const Operation &op) {
  if (mlir::Block *block = op.op_->getBlock()) {
    return Block(op.module_, block);
  } else {
    return std::nullopt;
  }
}

unsigned Block::num_arguments(void) const noexcept {
  return block_->getNumArguments();
}

std::optional<Argument> Block::nth_argument(unsigned i) const noexcept {
  if (i < block_->getNumArguments()) {
    return Argument(
        module_,
        reinterpret_cast<mlir::detail::BlockArgumentImpl *>(
            block_->getArguments()[i].getAsOpaquePointer()));
  }
  return std::nullopt;
}

// Arguments to the block. Block arguments are like PHI nodes.
gap::generator<Argument> Block::arguments(void) const & noexcept {
  for (mlir::BlockArgument arg : block_->getArguments()) {
    co_yield Argument(module_,
                      reinterpret_cast<mlir::detail::BlockArgumentImpl *>(
                          arg.getAsOpaquePointer()));
  }
}

// Operations within a block. Every block has at least one operation, its
// terminator.
gap::generator<Operation> Block::operations(void) const & noexcept {
  for (mlir::Operation &op : block_->getOperations()) {
    co_yield Operation(module_, &op);
  }
}

// Operations within a block in reverse order.
gap::generator<Operation> Block::reverse_operations(void) const & noexcept {
  mlir::Block::OpListType &ops = block_->getOperations();
  for (auto it = ops.rbegin(), end = ops.rend(); it != end; ++it) {
    co_yield Operation(module_, &*it);
  }
}

// Set of operands that use this block. For example, a block can be an
// operand to a terminator operation.
gap::generator<Label> Block::uses(void) const & noexcept {
  for (mlir::BlockOperand &op : block_->getUses()) {
    co_yield Label(module_, &op);
  }
}

// Return the terminating operation of a block.
Operation Block::terminator(void) const noexcept {
  return Operation(module_, block_->getTerminator());
}

std::optional<Argument> Argument::from(const Value &val) {
  if (mlir::Value(val.impl_.value).isa<mlir::BlockArgument>()) {
    return Argument(val.module_, val.impl_.arg);
  }
  return std::nullopt;
}

// Index of this block argument.
unsigned Argument::index(void) const noexcept {
  return mlir::BlockArgument(impl_.arg).getArgNumber();
}

// The operation containing this label.
Operation Label::operation(void) const noexcept {
  return Operation(module_, op_->getOwner());
}

Block Label::block(void) const noexcept {
  return Block(module_, op_->get());
}

// The index of this label within its owner operation's block operand list.
unsigned Label::index(void) const noexcept {
  return op_->getOperandNumber();
}

}  // namespace mx::ir
