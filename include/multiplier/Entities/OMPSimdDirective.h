// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "OMPLoopDirective.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPSimdDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPSimdDirective> in(const Index &index);
  static gap::generator<OMPSimdDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPSimdDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPSimdDirective> in(const Fragment &frag);
  static gap::generator<OMPSimdDirective> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_SIMD_DIRECTIVE;
  }

  static gap::generator<OMPSimdDirective> containing(const Decl &decl);
  static gap::generator<OMPSimdDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPSimdDirective> containing(const Stmt &stmt);
  static gap::generator<OMPSimdDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPSimdDirective> from(const Stmt &parent);

  inline static std::optional<OMPSimdDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPSimdDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPSimdDirective> from(const Reference &r);
  static std::optional<OMPSimdDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPSimdDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
