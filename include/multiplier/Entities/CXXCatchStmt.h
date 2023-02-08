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
class CXXCatchStmt;
class Stmt;
class Type;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXCatchStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<CXXCatchStmt> in(const Fragment &frag);
  static gap::generator<CXXCatchStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_CATCH_STMT;
  }

  static gap::generator<StmtKind> derived_kinds(void);
  static gap::generator<CXXCatchStmt> containing(const Decl &decl);
  static gap::generator<CXXCatchStmt> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CXXCatchStmt> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CXXCatchStmt> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<CXXCatchStmt> from(const Stmt &parent);

  inline static std::optional<CXXCatchStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXCatchStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token catch_token(void) const;
  Type caught_type(void) const;
  std::optional<VarDecl> exception_declaration(void) const;
  Stmt handler_block(void) const;
};

static_assert(sizeof(CXXCatchStmt) == sizeof(Stmt));

#endif
} // namespace mx
