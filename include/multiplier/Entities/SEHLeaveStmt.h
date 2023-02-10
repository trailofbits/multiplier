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
class SEHLeaveStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SEHLeaveStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<SEHLeaveStmt> in(const Fragment &frag);
  static gap::generator<SEHLeaveStmt> in(const File &file);
  static gap::generator<SEHLeaveStmt> in(const Index &index);
  static gap::generator<SEHLeaveStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SEHLeaveStmt> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::SEH_LEAVE_STMT;
  }

  static gap::generator<SEHLeaveStmt> containing(const Decl &decl);
  static gap::generator<SEHLeaveStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<SEHLeaveStmt> containing(const Stmt &stmt);
  static gap::generator<SEHLeaveStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<SEHLeaveStmt> from(const Stmt &parent);

  inline static std::optional<SEHLeaveStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return SEHLeaveStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<SEHLeaveStmt> from(const Reference &r) {
    return SEHLeaveStmt::from(r.as_statement());
  }

  inline static std::optional<SEHLeaveStmt> from(const TokenContext &t) {
    return SEHLeaveStmt::from(t.as_statement());
  }

  Token leave_token(void) const;
};

static_assert(sizeof(SEHLeaveStmt) == sizeof(Stmt));

#endif
} // namespace mx
