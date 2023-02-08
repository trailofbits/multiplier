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
class CompoundStmt;
class Expr;
class ObjCAtSynchronizedStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCAtSynchronizedStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<ObjCAtSynchronizedStmt> in(const Fragment &frag);
  static gap::generator<ObjCAtSynchronizedStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_AT_SYNCHRONIZED_STMT;
  }

  static gap::generator<StmtKind> derived_kinds(void);
  static gap::generator<ObjCAtSynchronizedStmt> containing(const Decl &decl);
  static gap::generator<ObjCAtSynchronizedStmt> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<ObjCAtSynchronizedStmt> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<ObjCAtSynchronizedStmt> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<ObjCAtSynchronizedStmt> from(const Stmt &parent);

  inline static std::optional<ObjCAtSynchronizedStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCAtSynchronizedStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token at_synchronized_token(void) const;
  CompoundStmt synch_body(void) const;
  Expr synch_expression(void) const;
};

static_assert(sizeof(ObjCAtSynchronizedStmt) == sizeof(Stmt));

#endif
} // namespace mx
