// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/OMPLoopTransformationDirective.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopTransformationDirective;
class OMPTileDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPTileDirective : public OMPLoopTransformationDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopTransformationDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPTileDirective> in(const Index &index);
  static gap::generator<OMPTileDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPTileDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPTileDirective> in(const Fragment &frag);
  static gap::generator<OMPTileDirective> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TILE_DIRECTIVE;
  }

  static gap::generator<OMPTileDirective> containing(const Decl &decl);
  static gap::generator<OMPTileDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPTileDirective> containing(const Stmt &stmt);
  static gap::generator<OMPTileDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTileDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPTileDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPTileDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPTileDirective> from(const Reference &r);
  static std::optional<OMPTileDirective> from(const VariantEntity &e);
  static std::optional<OMPTileDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPTileDirective) == sizeof(OMPLoopTransformationDirective));

#endif
} // namespace mx
