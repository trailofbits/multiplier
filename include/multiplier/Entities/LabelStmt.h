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

#include "StmtKind.h"
#include "ValueStmt.h"

namespace mx {
class LabelDecl;
class LabelStmt;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class LabelStmt : public ValueStmt {
 private:
  friend class FragmentImpl;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<LabelStmt> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<LabelStmt> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : LabelStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::LABEL_STMT;
  }

  static gap::generator<LabelStmt> containing(const Decl &decl);
  static gap::generator<LabelStmt> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<LabelStmt> from(const TokenContext &c);
  static std::optional<LabelStmt> from(const ValueStmt &parent);

  inline static std::optional<LabelStmt> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return LabelStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<LabelStmt> from(const Stmt &parent);

  inline static std::optional<LabelStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return LabelStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  LabelDecl declaration(void) const;
  Token identifier_token(void) const;
  std::string_view name(void) const;
  Stmt sub_statement(void) const;
  bool is_side_entry(void) const;
};

static_assert(sizeof(LabelStmt) == sizeof(ValueStmt));

#endif
} // namespace mx
