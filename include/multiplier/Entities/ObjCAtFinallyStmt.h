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

#include "Stmt.h"

namespace mx {
class Decl;
class ObjCAtFinallyStmt;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCAtFinallyStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<ObjCAtFinallyStmt> in(const Fragment &frag);
  static gap::generator<ObjCAtFinallyStmt> in(const File &file);
  static gap::generator<ObjCAtFinallyStmt> in(const Index &index);
  static gap::generator<ObjCAtFinallyStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCAtFinallyStmt> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_AT_FINALLY_STMT;
  }

  static gap::generator<ObjCAtFinallyStmt> containing(const Decl &decl);
  static gap::generator<ObjCAtFinallyStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCAtFinallyStmt> containing(const Stmt &stmt);
  static gap::generator<ObjCAtFinallyStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCAtFinallyStmt> from(const Stmt &parent);

  inline static std::optional<ObjCAtFinallyStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCAtFinallyStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCAtFinallyStmt> from(const Reference &r) {
    return ObjCAtFinallyStmt::from(r.as_statement());
  }

  inline static std::optional<ObjCAtFinallyStmt> from(const TokenContext &t) {
    return ObjCAtFinallyStmt::from(t.as_statement());
  }

  Token at_finally_token(void) const;
  Stmt finally_body(void) const;
};

static_assert(sizeof(ObjCAtFinallyStmt) == sizeof(Stmt));

#endif
} // namespace mx
