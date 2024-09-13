// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Operation.h"

namespace vast::unsup {
class UnsupportedDecl;
class UnsupportedStmt;
}  // namespace vast::unsup
namespace mx::ir::unsup {

class MX_EXPORT Operation : public ::mx::ir::Operation {
 public:
  static std::optional<Operation> from(const ::mx::ir::Operation &);
};
static_assert(sizeof(Operation) == sizeof(::mx::ir::Operation));

class MX_EXPORT UnsupportedDeclOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::UNSUP_DECL;
  }

  static std::optional<UnsupportedDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<UnsupportedDeclOp> producing(const ::mx::ir::Value &val);

  ::vast::unsup::UnsupportedDecl underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(UnsupportedDeclOp) == sizeof(Operation));

class MX_EXPORT UnsupportedStmtOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::UNSUP_STMT;
  }

  static std::optional<UnsupportedStmtOp> from(const ::mx::ir::Operation &that);
  static std::optional<UnsupportedStmtOp> producing(const ::mx::ir::Value &val);

  ::vast::unsup::UnsupportedStmt underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  gap::generator<::mx::ir::Region> children(void) const &;
  std::string_view name(void) const;
};
static_assert(sizeof(UnsupportedStmtOp) == sizeof(Operation));

}  // namespace mx::ir::unsup
