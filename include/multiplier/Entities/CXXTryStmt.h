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
class CXXCatchStmt;
class CXXTryStmt;
class CompoundStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXTryStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<CXXTryStmt> in(const Fragment &frag);
  static gap::generator<CXXTryStmt> in(const Index &index);
  static gap::generator<CXXTryStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXTryStmt> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_TRY_STMT;
  }

  static gap::generator<CXXTryStmt> containing(const Decl &decl);
  static gap::generator<CXXTryStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXTryStmt> containing(const Stmt &stmt);
  static gap::generator<CXXTryStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CXXTryStmt> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CXXTryStmt> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<CXXTryStmt> from(const Stmt &parent);

  inline static std::optional<CXXTryStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXTryStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  CompoundStmt try_block(void) const;
  Token try_token(void) const;
  std::optional<CXXCatchStmt> nth_handler(unsigned n) const;
  gap::generator<CXXCatchStmt> handlers(void) const;
};

static_assert(sizeof(CXXTryStmt) == sizeof(Stmt));

#endif
} // namespace mx
