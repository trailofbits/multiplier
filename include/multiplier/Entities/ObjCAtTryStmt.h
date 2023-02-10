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
#include "StmtKind.h"

namespace mx {
class ObjCAtCatchStmt;
class ObjCAtFinallyStmt;
class ObjCAtTryStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCAtTryStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<ObjCAtTryStmt> in(const Fragment &frag);
  static gap::generator<ObjCAtTryStmt> in(const File &file);
  static gap::generator<ObjCAtTryStmt> in(const Index &index);
  static gap::generator<ObjCAtTryStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCAtTryStmt> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_AT_TRY_STMT;
  }

  static gap::generator<ObjCAtTryStmt> containing(const Decl &decl);
  static gap::generator<ObjCAtTryStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCAtTryStmt> containing(const Stmt &stmt);
  static gap::generator<ObjCAtTryStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCAtTryStmt> from(const Stmt &parent);

  inline static std::optional<ObjCAtTryStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCAtTryStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCAtTryStmt> from(const Reference &r) {
    return ObjCAtTryStmt::from(r.as_statement());
  }

  inline static std::optional<ObjCAtTryStmt> from(const TokenContext &t) {
    return ObjCAtTryStmt::from(t.as_statement());
  }

  Token at_try_token(void) const;
  ObjCAtFinallyStmt finally_statement(void) const;
  Stmt try_body(void) const;
  std::optional<ObjCAtCatchStmt> nth_catch_statement(unsigned n) const;
  gap::generator<ObjCAtCatchStmt> catch_statements(void) const;
};

static_assert(sizeof(ObjCAtTryStmt) == sizeof(Stmt));

#endif
} // namespace mx
