// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/OMPLoopDirective.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class OMPExecutableDirective;
class OMPForDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPForDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPForDirective> in(const Index &index);
  static gap::generator<OMPForDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPForDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPForDirective> in(const Fragment &frag);
  static gap::generator<OMPForDirective> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_FOR_DIRECTIVE;
  }

  static gap::generator<OMPForDirective> containing(const Decl &decl);
  static gap::generator<OMPForDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPForDirective> containing(const Stmt &stmt);
  static gap::generator<OMPForDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPForDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPForDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPForDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPForDirective> from(const Reference &r);
  static std::optional<OMPForDirective> from(const VariantEntity &e);
  static std::optional<OMPForDirective> from(const TokenContext &t);

  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

static_assert(sizeof(OMPForDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
