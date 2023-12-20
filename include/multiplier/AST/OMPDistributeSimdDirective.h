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
class OMPDistributeSimdDirective;
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPDistributeSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPDistributeSimdDirective> in(const Index &index);
  static gap::generator<OMPDistributeSimdDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPDistributeSimdDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPDistributeSimdDirective> in(const Fragment &frag);
  static gap::generator<OMPDistributeSimdDirective> in(const File &file);

  static std::optional<OMPDistributeSimdDirective> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPDistributeSimdDirective, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_DISTRIBUTE_SIMD_DIRECTIVE;
  }

  static gap::generator<OMPDistributeSimdDirective> containing(const Decl &decl);
  static gap::generator<OMPDistributeSimdDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPDistributeSimdDirective> containing(const Stmt &stmt);
  static gap::generator<OMPDistributeSimdDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPDistributeSimdDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPDistributeSimdDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPDistributeSimdDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPDistributeSimdDirective> from(const Reference &r);
  static std::optional<OMPDistributeSimdDirective> from(const VariantEntity &e);
  static std::optional<OMPDistributeSimdDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPDistributeSimdDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
