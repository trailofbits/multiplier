// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <gap/core/generator.hpp>
#include <optional>
#include <memory>
#include <string_view>

#include "OperationKind.h"
#include "Value.h"

namespace mlir {
class Operation;
class OpOperand;
namespace detail {
class OpResultImpl;
}  // namespace detail
}  // namespace mlir
namespace mx {
class Fragment;
namespace ir {
class Attribute;
class Block;
class Argument;
class Label;
class Region;
class Result;
class Operand;
class SourceIRImpl;
class Value;

// An operation is like an 'instruction', but can contain arbitrary
// complexity in the form or one or more regions, each of which can
// embed their own control-flow graphs of blocks containing operations.
class Operation {
 private:
  friend class Attribute;
  friend class Block;
  friend class Label;
  friend class Operand;
  friend class Region;
  friend class Result;
  friend class SourceIRImpl;
  friend class Value;

  friend class ::mx::Fragment;

  Operation(void) = delete;

 protected:
  std::shared_ptr<const SourceIRImpl> module_;
  OperationKind kind_;
  mlir::Operation *op_;

  inline Operation(std::shared_ptr<const SourceIRImpl> module,
                   mlir::Operation *opaque)
      : module_(std::move(module)),
        kind_(classify(opaque)),
        op_(opaque) {}

 public:
  // Classify an MLIR operation, by raw pointer or by operation name.
  static OperationKind classify(mlir::Operation *);
  static OperationKind classify(std::string_view);

  // The name of this operation.
  std::string_view kind_name(void) const noexcept;

  // Kind of this operation. If the kind is from a dialect that isn't recognized
  // by multiplier, then `OperationKind::UNKNOWN` is returned.
  inline OperationKind kind(void) const noexcept {
    return kind_;
  }

  inline static Operation producing(const Result &val);

  static std::optional<Operation> producing(const Value &val);
  static Operation containing(const Region &);
  static Operation containing(const Block &);

  // Operations can have zero or more operands.
  unsigned num_operands(void) const noexcept;
  std::optional<Operand> nth_operand(unsigned) const noexcept;
  gap::generator<Operand> operands(void) const & noexcept;

  // Operations can produce zero or more results.
  unsigned num_results(void) const noexcept;
  std::optional<Result> nth_result(unsigned) const noexcept;
  gap::generator<Result> results(void) const & noexcept;

  // Operations can have zero or more nested regions. Regions allow one to
  // model sequential control-flow and concurrent data-flow graphs of
  // computation.
  unsigned num_regions(void) const noexcept;
  std::optional<Region> nth_region(unsigned) const noexcept;
  gap::generator<Region> regions(void) const & noexcept;

  // If an operation has only one region, the return that region.
  std::optional<Region> only_region(void) const noexcept;

  // If an operation has only one region, then visit those blocks.
  gap::generator<Block> only_region_blocks(void) const & noexcept;

  // An operation can have zero or more uses. A use of an operation is a use of
  // one of the result values of the operations.
  gap::generator<Operand> uses(void) const & noexcept;
};

// A value produced as a result of an operation.
class Result final : public Value {
 private:
  friend class Value;
  friend class Operation;

  inline Result(std::shared_ptr<const SourceIRImpl> module,
                mlir::detail::OpResultImpl *res)
      : Value(std::move(module), res) {}

 public:
  // If an operation has only one result, then return it.
  static std::optional<Result> of(const Operation &);

  // Try to down-cast a `Value` to a `Result`.
  static std::optional<Result> from(const Value &);

  // Return the operation producing this result.
  Operation operation(void) const noexcept;
};

static_assert(sizeof(Result) == sizeof(Value));

inline Operation Operation::producing(const Result &res) {
  return res.operation();
}

// A use of a value by a specific operation.
class Operand {
 private:
  friend class Block;
  friend class Label;
  friend class Operation;
  friend class Value;

  std::shared_ptr<const SourceIRImpl> module_;
  mlir::OpOperand *op_;

  inline Operand(std::shared_ptr<const SourceIRImpl> module,
                 mlir::OpOperand *op)
      : module_(std::move(module)),
        op_(op) {}

 public:
  // The operation containing this operand.
  Operation operation(void) const noexcept;

  // The index of this operand within its owner operation's operand list.
  unsigned index(void) const noexcept;

  // Value associated with this operand. This could be a block argument, or
  // the result of another operation.
  Value value(void) const noexcept;
};

}  // namespace ir
}  // namespace mx
