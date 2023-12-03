// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/OMPExecutableDirective.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class OMPExecutableDirective;
class OMPTargetDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPTargetDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPTargetDirective> in(const Index &index);
  static gap::generator<OMPTargetDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPTargetDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPTargetDirective> in(const Fragment &frag);
  static gap::generator<OMPTargetDirective> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TARGET_DIRECTIVE;
  }

  static gap::generator<OMPTargetDirective> containing(const Decl &decl);
  static gap::generator<OMPTargetDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPTargetDirective> containing(const Stmt &stmt);
  static gap::generator<OMPTargetDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTargetDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPTargetDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPTargetDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPTargetDirective> from(const Reference &r);
  static std::optional<OMPTargetDirective> from(const VariantEntity &e);
  static std::optional<OMPTargetDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPTargetDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
