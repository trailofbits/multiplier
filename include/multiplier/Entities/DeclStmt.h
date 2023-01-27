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
class Decl;
class DeclStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DeclStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static gap::generator<DeclStmt> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<DeclStmt> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : DeclStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DECL_STMT;
  }

  static gap::generator<DeclStmt> containing(const Decl &decl);
  static gap::generator<DeclStmt> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<DeclStmt> from(const TokenContext &c);
  static std::optional<DeclStmt> from(const Stmt &parent);

  inline static std::optional<DeclStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return DeclStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Decl> nth_declaration(unsigned n) const;
  gap::generator<Decl> declarations(void) const;
  std::optional<Decl> single_declaration(void) const;
  bool is_single_declaration(void) const;
};

static_assert(sizeof(DeclStmt) == sizeof(Stmt));

#endif
} // namespace mx
