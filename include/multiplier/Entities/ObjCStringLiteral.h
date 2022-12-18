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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class ObjCStringLiteral;
class Stmt;
class StringLiteral;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCStringLiteralRange = DerivedEntityRange<StmtIterator, ObjCStringLiteral>;
using ObjCStringLiteralContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCStringLiteral>;
using ObjCStringLiteralContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCStringLiteral>;

class ObjCStringLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCStringLiteralRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCStringLiteralContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCStringLiteral::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_STRING_LITERAL;
  }

  static ObjCStringLiteralContainingStmtRange containing(const Decl &decl);
  static ObjCStringLiteralContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCStringLiteral> from(const TokenContext &c);
  static std::optional<ObjCStringLiteral> from(const Expr &parent);

  inline static std::optional<ObjCStringLiteral> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ObjCStringLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCStringLiteral> from(const ValueStmt &parent);

  inline static std::optional<ObjCStringLiteral> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ObjCStringLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCStringLiteral> from(const Stmt &parent);

  inline static std::optional<ObjCStringLiteral> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCStringLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token at_token(void) const;
  StringLiteral string(void) const;
};

static_assert(sizeof(ObjCStringLiteral) == sizeof(Expr));

#endif
} // namespace mx
