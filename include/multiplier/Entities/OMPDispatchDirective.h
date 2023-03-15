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
class OMPDispatchDirective;
class OMPExecutableDirective;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPDispatchDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPDispatchDirective> in(const Fragment &frag);
  static gap::generator<OMPDispatchDirective> in(const File &file);
  static gap::generator<OMPDispatchDirective> in(const Index &index);
  static gap::generator<OMPDispatchDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPDispatchDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_DISPATCH_DIRECTIVE;
  }

  static gap::generator<OMPDispatchDirective> containing(const Decl &decl);
  static gap::generator<OMPDispatchDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPDispatchDirective> containing(const Stmt &stmt);
  static gap::generator<OMPDispatchDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPDispatchDirective> from(const Stmt &parent);

  inline static std::optional<OMPDispatchDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPDispatchDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPDispatchDirective> from(const Reference &r);
  static std::optional<OMPDispatchDirective> from(const TokenContext &t);

  Token target_call_token(void) const;
};

static_assert(sizeof(OMPDispatchDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
