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
  static gap::generator<CXXCatchStmt> in(const File &file);
  static gap::generator<CXXCatchStmt> in(const Index &index);
  static gap::generator<CXXCatchStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXCatchStmt> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_CATCH_STMT;
  }

  static gap::generator<CXXCatchStmt> containing(const Decl &decl);
  static gap::generator<CXXCatchStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXCatchStmt> containing(const Stmt &stmt);
  static gap::generator<CXXCatchStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXCatchStmt> from(const Stmt &parent);

  inline static std::optional<CXXCatchStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXCatchStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<CXXCatchStmt> from(const Reference &r) {
    return CXXCatchStmt::from(r.as_statement());
  }

  inline static std::optional<CXXCatchStmt> from(const TokenContext &t) {
    return CXXCatchStmt::from(t.as_statement());
  }

  Token catch_token(void) const;
  Type caught_type(void) const;
  std::optional<VarDecl> exception_declaration(void) const;
  Stmt handler_block(void) const;
};

static_assert(sizeof(CXXCatchStmt) == sizeof(Stmt));

#endif
} // namespace mx
