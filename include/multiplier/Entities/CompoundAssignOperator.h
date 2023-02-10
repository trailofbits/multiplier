// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "BinaryOperator.h"
#include "StmtKind.h"

namespace mx {
class BinaryOperator;
class CompoundAssignOperator;
class Expr;
class Stmt;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CompoundAssignOperator : public BinaryOperator {
 private:
  friend class FragmentImpl;
  friend class BinaryOperator;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CompoundAssignOperator> in(const Fragment &frag);
  static gap::generator<CompoundAssignOperator> in(const File &file);
  static gap::generator<CompoundAssignOperator> in(const Index &index);
  static gap::generator<CompoundAssignOperator> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CompoundAssignOperator> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::COMPOUND_ASSIGN_OPERATOR;
  }

  static gap::generator<CompoundAssignOperator> containing(const Decl &decl);
  static gap::generator<CompoundAssignOperator> containing(const std::optional<Decl> &decl);

  static gap::generator<CompoundAssignOperator> containing(const Stmt &stmt);
  static gap::generator<CompoundAssignOperator> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CompoundAssignOperator> from(const Stmt &parent);

  inline static std::optional<CompoundAssignOperator> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CompoundAssignOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<CompoundAssignOperator> from(const Reference &r) {
    return CompoundAssignOperator::from(r.as_statement());
  }

  inline static std::optional<CompoundAssignOperator> from(const TokenContext &t) {
    return CompoundAssignOperator::from(t.as_statement());
  }

  Type computation_lhs_type(void) const;
  Type computation_result_type(void) const;
};

static_assert(sizeof(CompoundAssignOperator) == sizeof(BinaryOperator));

#endif
} // namespace mx
