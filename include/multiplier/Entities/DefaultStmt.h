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

#include "StmtKind.h"
#include "SwitchCase.h"

namespace mx {
class DefaultStmt;
class Stmt;
class SwitchCase;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DefaultStmt : public SwitchCase {
 private:
  friend class FragmentImpl;
  friend class SwitchCase;
  friend class Stmt;
 public:
  static gap::generator<DefaultStmt> in(const Fragment &frag);
  static gap::generator<DefaultStmt> in(const Index &index);
  static gap::generator<DefaultStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<DefaultStmt> by(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DEFAULT_STMT;
  }

  static gap::generator<DefaultStmt> containing(const Decl &decl);
  static gap::generator<DefaultStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<DefaultStmt> containing(const Stmt &stmt);
  static gap::generator<DefaultStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<DefaultStmt> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<DefaultStmt> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<DefaultStmt> from(const SwitchCase &parent);

  inline static std::optional<DefaultStmt> from(const std::optional<SwitchCase> &parent) {
    if (parent) {
      return DefaultStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DefaultStmt> from(const Stmt &parent);

  inline static std::optional<DefaultStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return DefaultStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token default_token(void) const;
};

static_assert(sizeof(DefaultStmt) == sizeof(SwitchCase));

#endif
} // namespace mx
