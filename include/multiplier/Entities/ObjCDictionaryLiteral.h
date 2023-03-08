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

#include "Expr.h"

namespace mx {
class Decl;
class Expr;
class ObjCDictionaryLiteral;
class ObjCMethodDecl;
class Stmt;
class Token;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCDictionaryLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ObjCDictionaryLiteral> in(const Fragment &frag);
  static gap::generator<ObjCDictionaryLiteral> in(const File &file);
  static gap::generator<ObjCDictionaryLiteral> in(const Index &index);
  static gap::generator<ObjCDictionaryLiteral> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCDictionaryLiteral> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_DICTIONARY_LITERAL;
  }

  static gap::generator<ObjCDictionaryLiteral> containing(const Decl &decl);
  static gap::generator<ObjCDictionaryLiteral> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCDictionaryLiteral> containing(const Stmt &stmt);
  static gap::generator<ObjCDictionaryLiteral> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCDictionaryLiteral> from(const Stmt &parent);

  inline static std::optional<ObjCDictionaryLiteral> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCDictionaryLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCDictionaryLiteral> from(const Reference &r) {
    return ObjCDictionaryLiteral::from(r.as_statement());
  }

  inline static std::optional<ObjCDictionaryLiteral> from(const TokenContext &t) {
    return ObjCDictionaryLiteral::from(t.as_statement());
  }

  ObjCMethodDecl dictionary_with_objects_method(void) const;
};

static_assert(sizeof(ObjCDictionaryLiteral) == sizeof(Expr));

#endif
} // namespace mx
