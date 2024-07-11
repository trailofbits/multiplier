// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <gap/coro/generator.hpp>
#include <optional>
#include <memory>
#include <string_view>

#include "OperationKind.h"
#include "Value.h"

#include "../Types.h"

namespace mlir {
class Operation;
class OpOperand;
namespace detail {
class OpResultImpl;
}  // namespace detail
}  // namespace mlir
namespace mx {
class Decl;
class Fragment;
class Index;
class Stmt;

enum class DeclKind : unsigned char;
enum class StmtKind : unsigned char;

namespace ir {
class Attribute;
class Block;
class Argument;
class Label;
class Region;
class Result;
class Operand;
class SourceIRImpl;
class Symbol;
class Value;

// An operation is like an 'instruction', but can contain arbitrary
// complexity in the form or one or more regions, each of which can
// embed their own control-flow graphs of blocks containing operations.
class MX_EXPORT Operation {
 private:
  friend class Attribute;
  friend class Block;
  friend class Label;
  friend class Operand;
  friend class Region;
  friend class Result;
  friend class SourceIRImpl;
  friend class Symbol;
  friend class Value;

  friend class ::mx::Decl;
  friend class ::mx::Fragment;
  friend class ::mx::Index;
  friend class ::mx::Stmt;

  Operation(void) = delete;

 protected:
  std::shared_ptr<const SourceIRImpl> module_;
  mlir::Operation *op_;
  OperationKind kind_;

 public:
  Operation(std::shared_ptr<const SourceIRImpl> module,
            mlir::Operation *opaque,
            OperationKind kind);

  inline Operation(std::shared_ptr<const SourceIRImpl> module,
                   mlir::Operation *opaque)
      : Operation(std::move(module), opaque, classify(opaque)) {}

  inline Operation(std::shared_ptr<const SourceIRImpl> module, void *opaque)
      : Operation(std::move(module),
                  reinterpret_cast<mlir::Operation *>(opaque)) {}

  inline mlir::Operation *underlying_operation(void) const noexcept {
    return op_;
  }

  // Classify an MLIR operation, by raw pointer or by operation name.
  static OperationKind classify(mlir::Operation *);
  static OperationKind classify(std::string_view);

  // The name of this operation.
  std::string_view kind_name(void) const noexcept;

  // Return the ID of this operation.
  EntityId id(void) const noexcept;

  // Kind of this operation. If the kind is from a dialect that isn't recognized
  // by multiplier, then `OperationKind::UNKNOWN` is returned.
  inline OperationKind kind(void) const noexcept {
    return kind_;
  }

  // Results (a kind of value) are always produced by operations.
  inline static Operation producing(const Result &val);

  // Some values are produced by operations. 
  static std::optional<Operation> producing(const Value &val);

  // Regions and blocks are always contained inside of an operation.
  static Operation containing(const Region &);
  static Operation containing(const Block &);

  static std::optional<Operation> first_from(const ::mx::Decl &that);
  static std::optional<Operation> first_from(const ::mx::Decl &that, OperationKind);
  static gap::generator<Operation> all_from(const ::mx::Decl &that);

  static std::optional<Operation> first_from(const ::mx::Stmt &that);
  static std::optional<Operation> first_from(const ::mx::Stmt &that, OperationKind);
  static gap::generator<Operation> all_from(const ::mx::Stmt &that);

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

  // Return the previous and next operations in the current `Block`.
  std::optional<Operation> previous(void) const noexcept;
  std::optional<Operation> next(void) const noexcept;

  // Returns `true` whether or not this operation is a terminator.
  bool is_terminator(void) const noexcept;

  // Return the symbol defined by this operation, if any.
  std::optional<Symbol> defined_symbol(void) const noexcept;

  // Return the operation defining a symbol.
  static Operation defining(const Symbol &symbol);

  bool operator==(const Operation &that) const noexcept;
  bool operator!=(const Operation &that) const noexcept = default;
};

// A value produced as a result of an operation.
class Result final : public Value {
 private:
  friend class Value;
  friend class Operation;

 public:

  inline static constexpr ValueKind static_kind(void) noexcept {
    return ValueKind::OPERATION_RESULT;
  }

  inline Result(std::shared_ptr<const SourceIRImpl> module,
                void *res)
      : Value(std::move(module),
              reinterpret_cast<mlir::detail::OpResultImpl *>(res)) {}

  // If an operation has only one result, then return it.
  static std::optional<Result> of(const Operation &);

  // Try to down-cast a `Value` to a `Result`.
  static std::optional<Result> from(const Value &);

  // Return the operation producing this result.
  Operation operation(void) const noexcept;

  // Index of this result in its operation's result list.
  unsigned index(void) const noexcept;

  bool operator==(const Result &that) const noexcept;
  bool operator!=(const Result &that) const noexcept = default;
};

static_assert(sizeof(Result) == sizeof(Value));

inline Operation Operation::producing(const Result &res) {
  return res.operation();
}

// A use of a value by a specific operation.
class MX_EXPORT Operand {
 private:
  friend class Block;
  friend class Label;
  friend class Operation;
  friend class Value;

  std::shared_ptr<const SourceIRImpl> module_;
  mlir::OpOperand *op_;

 public:

  inline Operand(std::shared_ptr<const SourceIRImpl> module, void *op)
      : module_(std::move(module)),
        op_(reinterpret_cast<mlir::OpOperand *>(op)) {}

  inline mlir::OpOperand *underlying_operand(void) const noexcept {
    return op_;
  }

  // The operation containing this operand.
  Operation operation(void) const noexcept;

  // The index of this operand within its owner operation's operand list.
  unsigned index(void) const noexcept;

  // Value associated with this operand. This could be a block argument, or
  // the result of another operation.
  Value value(void) const noexcept;

  bool operator==(const Operand &that) const noexcept;
  bool operator!=(const Operand &that) const noexcept = default;
};

// API for symbols defined by operations.
class MX_EXPORT Symbol {
 private:
  friend class Block;
  friend class Label;
  friend class Operation;
  friend class Value;

  std::shared_ptr<const SourceIRImpl> module_;
  mlir::Operation *op_;
  OperationKind kind_;

 public:

  inline Symbol(std::shared_ptr<const SourceIRImpl> module,
                mlir::Operation *opaque,
                OperationKind kind)
      : module_(std::move(module)),
        op_(opaque),
        kind_(kind) {}

  inline mlir::Operation *underlying_operation(void) const noexcept {
    return op_;
  }

  // If an operation defines a symbol then return it.
  static std::optional<Symbol> from(const Operation &);

  // The operation defining this symbol.
  Operation operation(void) const noexcept;

  // Name of this symbol.
  std::string_view name(void) const noexcept;

  // References to this symbol.
  gap::generator<Operation> references(void) const & noexcept;

  bool operator==(const Symbol &that) const noexcept;
  bool operator!=(const Symbol &that) const noexcept = default;
};

}  // namespace ir
}  // namespace mx
