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
class Expr;
class OMPExecutableDirective;
class OMPParallelDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPParallelDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPParallelDirective> in(const Fragment &frag);
  static gap::generator<OMPParallelDirective> in(const File &file);
  static gap::generator<OMPParallelDirective> in(const Index &index);
  static gap::generator<OMPParallelDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPParallelDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_PARALLEL_DIRECTIVE;
  }

  static gap::generator<OMPParallelDirective> containing(const Decl &decl);
  static gap::generator<OMPParallelDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPParallelDirective> containing(const Stmt &stmt);
  static gap::generator<OMPParallelDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPParallelDirective> from(const Stmt &parent);

  inline static std::optional<OMPParallelDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPParallelDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPParallelDirective> from(const Reference &r);
  static std::optional<OMPParallelDirective> from(const TokenContext &t);

  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

static_assert(sizeof(OMPParallelDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
