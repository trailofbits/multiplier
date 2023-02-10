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
class GotoStmt;
class LabelDecl;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class GotoStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<GotoStmt> in(const Fragment &frag);
  static gap::generator<GotoStmt> in(const File &file);
  static gap::generator<GotoStmt> in(const Index &index);
  static gap::generator<GotoStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<GotoStmt> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::GOTO_STMT;
  }

  static gap::generator<GotoStmt> containing(const Decl &decl);
  static gap::generator<GotoStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<GotoStmt> containing(const Stmt &stmt);
  static gap::generator<GotoStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<GotoStmt> from(const Stmt &parent);

  inline static std::optional<GotoStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return GotoStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<GotoStmt> from(const Reference &r) {
    return GotoStmt::from(r.as_statement());
  }

  inline static std::optional<GotoStmt> from(const TokenContext &t) {
    return GotoStmt::from(t.as_statement());
  }

  Token goto_token(void) const;
  LabelDecl label(void) const;
  Token label_token(void) const;
};

static_assert(sizeof(GotoStmt) == sizeof(Stmt));

#endif
} // namespace mx
