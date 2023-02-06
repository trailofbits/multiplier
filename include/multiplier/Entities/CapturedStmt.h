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
#include "../Reference.h"
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
  static gap::generator<CapturedStmt> in(const Fragment &frag);
  static gap::generator<CapturedStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CAPTURED_STMT;
  }

  static gap::generator<CapturedStmt> containing(const Decl &decl);
  static gap::generator<CapturedStmt> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CapturedStmt> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CapturedStmt> from(const TokenContext &t) {
    return from(t.as_statement());
  }

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
