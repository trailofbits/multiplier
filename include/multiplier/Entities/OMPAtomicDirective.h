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

#include "OMPExecutableDirective.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class OMPAtomicDirective;
class OMPExecutableDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPAtomicDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPAtomicDirective> in(const Fragment &frag);
  static gap::generator<OMPAtomicDirective> in(const Index &index);
  static gap::generator<OMPAtomicDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<OMPAtomicDirective> by(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_ATOMIC_DIRECTIVE;
  }

  static gap::generator<OMPAtomicDirective> containing(const Decl &decl);
  static gap::generator<OMPAtomicDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPAtomicDirective> containing(const Stmt &stmt);
  static gap::generator<OMPAtomicDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<OMPAtomicDirective> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<OMPAtomicDirective> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<OMPAtomicDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPAtomicDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPAtomicDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPAtomicDirective> from(const Stmt &parent);

  inline static std::optional<OMPAtomicDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPAtomicDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr condition_expression(void) const;
  Expr d(void) const;
  Expr expression(void) const;
  Expr r(void) const;
  Expr update_expression(void) const;
  Expr v(void) const;
  Expr x(void) const;
  bool is_fail_only(void) const;
  bool is_postfix_update(void) const;
  bool is_xlhs_in_rhs_part(void) const;
};

static_assert(sizeof(OMPAtomicDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
