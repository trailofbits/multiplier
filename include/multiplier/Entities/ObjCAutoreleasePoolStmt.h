// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Stmt.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class ObjCAutoreleasePoolStmt;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCAutoreleasePoolStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<ObjCAutoreleasePoolStmt> in(const Fragment &frag);
  static gap::generator<ObjCAutoreleasePoolStmt> in(const File &file);
  static gap::generator<ObjCAutoreleasePoolStmt> in(const Index &index);
  static gap::generator<ObjCAutoreleasePoolStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCAutoreleasePoolStmt> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_AUTORELEASE_POOL_STMT;
  }

  static gap::generator<ObjCAutoreleasePoolStmt> containing(const Decl &decl);
  static gap::generator<ObjCAutoreleasePoolStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCAutoreleasePoolStmt> containing(const Stmt &stmt);
  static gap::generator<ObjCAutoreleasePoolStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCAutoreleasePoolStmt> from(const Stmt &parent);

  inline static std::optional<ObjCAutoreleasePoolStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCAutoreleasePoolStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCAutoreleasePoolStmt> from(const Reference &r);
  static std::optional<ObjCAutoreleasePoolStmt> from(const TokenContext &t);

  Token at_token(void) const;
  Stmt sub_statement(void) const;
};

static_assert(sizeof(ObjCAutoreleasePoolStmt) == sizeof(Stmt));

#endif
} // namespace mx
