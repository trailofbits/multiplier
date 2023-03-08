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
class ObjCAutoreleasePoolStmt;
class Stmt;
class Token;
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

  inline static std::optional<ObjCAutoreleasePoolStmt> from(const Reference &r) {
    return ObjCAutoreleasePoolStmt::from(r.as_statement());
  }

  inline static std::optional<ObjCAutoreleasePoolStmt> from(const TokenContext &t) {
    return ObjCAutoreleasePoolStmt::from(t.as_statement());
  }

  Token at_token(void) const;
  Stmt sub_statement(void) const;
};

static_assert(sizeof(ObjCAutoreleasePoolStmt) == sizeof(Stmt));

#endif
} // namespace mx
