// Copyright (c) 2022-present, Trail of Bits, Inc.
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
class File;
class OMPDistributeDirective;
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
class MX_EXPORT OMPDistributeDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPDistributeDirective> in(const Index &index);
  static gap::generator<OMPDistributeDirective> in(const Fragment &frag);
  static gap::generator<OMPDistributeDirective> in(const File &file);
  static gap::generator<OMPDistributeDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<OMPDistributeDirective> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPDistributeDirective, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_DISTRIBUTE_DIRECTIVE;
  }

  static gap::generator<OMPDistributeDirective> containing(const Decl &decl);
  static gap::generator<OMPDistributeDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPDistributeDirective> containing(const Stmt &stmt);
  static gap::generator<OMPDistributeDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPDistributeDirective> by_id(const Index &, EntityId);

  static std::optional<OMPDistributeDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPDistributeDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPDistributeDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPDistributeDirective> from(const Reference &r);
  static std::optional<OMPDistributeDirective> from(const VariantEntity &e);
  static std::optional<OMPDistributeDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPDistributeDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
