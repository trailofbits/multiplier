// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Operation.h"

namespace vast::core {
class BinLAndOp;
class BinLOrOp;
class ImplicitReturnOp;
class LazyOp;
class ScopeOp;
class SelectOp;
}  // namespace vast::core
namespace mx::ir::core {

class MX_EXPORT Operation : public ::mx::ir::Operation {
 public:
  static std::optional<Operation> from(const ::mx::ir::Operation &);
};
static_assert(sizeof(Operation) == sizeof(::mx::ir::Operation));

class MX_EXPORT BinLAndOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::CORE_BIN_LAND;
  }

  static std::optional<BinLAndOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinLAndOp> producing(const ::mx::ir::Value &val);

  ::vast::core::BinLAndOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(BinLAndOp) == sizeof(Operation));

class MX_EXPORT BinLOrOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::CORE_BIN_LOR;
  }

  static std::optional<BinLOrOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinLOrOp> producing(const ::mx::ir::Value &val);

  ::vast::core::BinLOrOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(BinLOrOp) == sizeof(Operation));

class MX_EXPORT ImplicitReturnOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::CORE_IMPLICIT_RETURN;
  }

  static std::optional<ImplicitReturnOp> from(const ::mx::ir::Operation &that);
  static std::optional<ImplicitReturnOp> producing(const ::mx::ir::Value &val);

  ::vast::core::ImplicitReturnOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::Operation::operand_range result(void) const;
};
static_assert(sizeof(ImplicitReturnOp) == sizeof(Operation));

class MX_EXPORT LazyOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::CORE_LAZY_OP;
  }

  static std::optional<LazyOp> from(const ::mx::ir::Operation &that);
  static std::optional<LazyOp> producing(const ::mx::ir::Value &val);

  ::vast::core::LazyOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  //::mlir::Region & lazy(void) const;
};
static_assert(sizeof(LazyOp) == sizeof(Operation));

class MX_EXPORT ScopeOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::CORE_SCOPE;
  }

  static std::optional<ScopeOp> from(const ::mx::ir::Operation &that);
  static std::optional<ScopeOp> producing(const ::mx::ir::Value &val);

  ::vast::core::ScopeOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::Region & body(void) const;
};
static_assert(sizeof(ScopeOp) == sizeof(Operation));

class MX_EXPORT SelectOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::CORE_SELECT;
  }

  static std::optional<SelectOp> from(const ::mx::ir::Operation &that);
  static std::optional<SelectOp> producing(const ::mx::ir::Value &val);

  ::vast::core::SelectOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value cond(void) const;
  ::mx::ir::Value then_region(void) const;
  ::mx::ir::Value else_region(void) const;
  //::mlir::Operation::result_range results(void) const;
};
static_assert(sizeof(SelectOp) == sizeof(Operation));

}  // namespace mx::ir::core
