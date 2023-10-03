// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "OMPExecutableDirective.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class OMPExecutableDirective;
class OMPScopeDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPScopeDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPScopeDirective> in(const Index &index);
  static gap::generator<OMPScopeDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPScopeDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPScopeDirective> in(const Fragment &frag);
  static gap::generator<OMPScopeDirective> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_SCOPE_DIRECTIVE;
  }

  static gap::generator<OMPScopeDirective> containing(const Decl &decl);
  static gap::generator<OMPScopeDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPScopeDirective> containing(const Stmt &stmt);
  static gap::generator<OMPScopeDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPScopeDirective> from(const Stmt &parent);

  inline static std::optional<OMPScopeDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPScopeDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPScopeDirective> from(const Reference &r);
  static std::optional<OMPScopeDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPScopeDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
