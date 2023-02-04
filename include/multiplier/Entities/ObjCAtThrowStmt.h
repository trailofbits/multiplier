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
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class ObjCAtThrowStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCAtThrowStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<ObjCAtThrowStmt> in(const Fragment &frag);
  static gap::generator<ObjCAtThrowStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_AT_THROW_STMT;
  }

  static gap::generator<ObjCAtThrowStmt> containing(const Decl &decl);
  static gap::generator<ObjCAtThrowStmt> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<ObjCAtThrowStmt> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<ObjCAtThrowStmt> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<ObjCAtThrowStmt> from(const Stmt &parent);

  inline static std::optional<ObjCAtThrowStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCAtThrowStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr throw_expression(void) const;
  Token throw_token(void) const;
};

static_assert(sizeof(ObjCAtThrowStmt) == sizeof(Stmt));

#endif
} // namespace mx
