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

namespace mx {
class Decl;
class Expr;
class ObjCForCollectionStmt;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCForCollectionStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<ObjCForCollectionStmt> in(const Fragment &frag);
  static gap::generator<ObjCForCollectionStmt> in(const File &file);
  static gap::generator<ObjCForCollectionStmt> in(const Index &index);
  static gap::generator<ObjCForCollectionStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCForCollectionStmt> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_FOR_COLLECTION_STMT;
  }

  static gap::generator<ObjCForCollectionStmt> containing(const Decl &decl);
  static gap::generator<ObjCForCollectionStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCForCollectionStmt> containing(const Stmt &stmt);
  static gap::generator<ObjCForCollectionStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCForCollectionStmt> from(const Stmt &parent);

  inline static std::optional<ObjCForCollectionStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCForCollectionStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCForCollectionStmt> from(const Reference &r) {
    return ObjCForCollectionStmt::from(r.as_statement());
  }

  inline static std::optional<ObjCForCollectionStmt> from(const TokenContext &t) {
    return ObjCForCollectionStmt::from(t.as_statement());
  }

  Stmt body(void) const;
  Expr collection(void) const;
  Stmt element(void) const;
  Token for_token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(ObjCForCollectionStmt) == sizeof(Stmt));

#endif
} // namespace mx
