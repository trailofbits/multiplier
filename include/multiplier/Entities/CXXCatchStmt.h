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
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "DeclUseSelector.h"
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
  inline static gap::generator<CXXCatchStmt> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<CXXCatchStmt> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : CXXCatchStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_CATCH_STMT;
  }

  static gap::generator<CXXCatchStmt> containing(const Decl &decl);
  static gap::generator<CXXCatchStmt> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXCatchStmt> from(const TokenContext &c);
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
