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
class OMPTaskyieldDirective;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPTaskyieldDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPTaskyieldDirective> in(const Fragment &frag);
  static gap::generator<OMPTaskyieldDirective> in(const File &file);
  static gap::generator<OMPTaskyieldDirective> in(const Index &index);
  static gap::generator<OMPTaskyieldDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPTaskyieldDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TASKYIELD_DIRECTIVE;
  }

  static gap::generator<OMPTaskyieldDirective> containing(const Decl &decl);
  static gap::generator<OMPTaskyieldDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPTaskyieldDirective> containing(const Stmt &stmt);
  static gap::generator<OMPTaskyieldDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTaskyieldDirective> from(const Stmt &parent);

  inline static std::optional<OMPTaskyieldDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTaskyieldDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTaskyieldDirective> from(const Reference &r);
  static std::optional<OMPTaskyieldDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPTaskyieldDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
