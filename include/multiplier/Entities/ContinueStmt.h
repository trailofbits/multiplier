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
class ContinueStmt;
class Decl;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ContinueStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<ContinueStmt> in(const Fragment &frag);
  static gap::generator<ContinueStmt> in(const File &file);
  static gap::generator<ContinueStmt> in(const Index &index);
  static gap::generator<ContinueStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ContinueStmt> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CONTINUE_STMT;
  }

  static gap::generator<ContinueStmt> containing(const Decl &decl);
  static gap::generator<ContinueStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<ContinueStmt> containing(const Stmt &stmt);
  static gap::generator<ContinueStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ContinueStmt> from(const Stmt &parent);

  inline static std::optional<ContinueStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ContinueStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ContinueStmt> from(const Reference &r) {
    return ContinueStmt::from(r.as_statement());
  }

  inline static std::optional<ContinueStmt> from(const TokenContext &t) {
    return ContinueStmt::from(t.as_statement());
  }

  Token continue_token(void) const;
};

static_assert(sizeof(ContinueStmt) == sizeof(Stmt));

#endif
} // namespace mx
