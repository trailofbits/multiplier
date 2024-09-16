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
class MX_EXPORT OMPSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPSimdDirective> in(const Index &index);
  static gap::generator<OMPSimdDirective> in(const Fragment &frag);
  static gap::generator<OMPSimdDirective> in(const File &file);
  static gap::generator<OMPSimdDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<OMPSimdDirective> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPSimdDirective, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_SIMD_DIRECTIVE;
  }

  static gap::generator<OMPSimdDirective> containing(const Decl &decl);
  static gap::generator<OMPSimdDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPSimdDirective> containing(const Stmt &stmt);
  static gap::generator<OMPSimdDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPSimdDirective> by_id(const Index &, EntityId);

  static std::optional<OMPSimdDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPSimdDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPSimdDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPSimdDirective> from(const Reference &r);
  static std::optional<OMPSimdDirective> from(const VariantEntity &e);
  static std::optional<OMPSimdDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPSimdDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
