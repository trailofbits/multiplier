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
class CapturedStmt;
class OMPExecutableDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPExecutableDirective : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<OMPExecutableDirective> in(const Fragment &frag);
  static gap::generator<OMPExecutableDirective> in(const Index &index);
  static gap::generator<OMPExecutableDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPExecutableDirective> by_id(const Index &, EntityId);

  static gap::generator<OMPExecutableDirective> containing(const Decl &decl);
  static gap::generator<OMPExecutableDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPExecutableDirective> containing(const Stmt &stmt);
  static gap::generator<OMPExecutableDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<OMPExecutableDirective> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<OMPExecutableDirective> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<OMPExecutableDirective> from(const Stmt &parent);

  inline static std::optional<OMPExecutableDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPExecutableDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Stmt associated_statement(void) const;
  CapturedStmt innermost_captured_statement(void) const;
  Stmt raw_statement(void) const;
  Stmt structured_block(void) const;
  bool has_associated_statement(void) const;
  bool is_standalone_directive(void) const;
};

static_assert(sizeof(OMPExecutableDirective) == sizeof(Stmt));

#endif
} // namespace mx
