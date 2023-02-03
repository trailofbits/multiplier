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

#include "CapturedRegionKind.h"
#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class CapturedDecl;
class CapturedStmt;
class RecordDecl;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CapturedStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static gap::generator<CapturedStmt> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<CapturedStmt> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : CapturedStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CAPTURED_STMT;
  }

  static gap::generator<CapturedStmt> containing(const Decl &decl);
  static gap::generator<CapturedStmt> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CapturedStmt> from(const TokenContext &c);
  static std::optional<CapturedStmt> from(const Stmt &parent);

  inline static std::optional<CapturedStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CapturedStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  CapturedDecl captured_declaration(void) const;
  RecordDecl captured_record_declaration(void) const;
  CapturedRegionKind captured_region_kind(void) const;
  Stmt captured_statement(void) const;
};

static_assert(sizeof(CapturedStmt) == sizeof(Stmt));

#endif
} // namespace mx
