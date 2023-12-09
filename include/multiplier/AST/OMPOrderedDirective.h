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
class OMPOrderedDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPOrderedDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPOrderedDirective> in(const Index &index);
  static gap::generator<OMPOrderedDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPOrderedDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPOrderedDirective> in(const Fragment &frag);
  static gap::generator<OMPOrderedDirective> in(const File &file);

  static std::optional<OMPOrderedDirective> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<OMPOrderedDirective, ir::hl::Operation>> in(const Compilation &tu);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_ORDERED_DIRECTIVE;
  }

  static gap::generator<OMPOrderedDirective> containing(const Decl &decl);
  static gap::generator<OMPOrderedDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPOrderedDirective> containing(const Stmt &stmt);
  static gap::generator<OMPOrderedDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPOrderedDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPOrderedDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPOrderedDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPOrderedDirective> from(const Reference &r);
  static std::optional<OMPOrderedDirective> from(const VariantEntity &e);
  static std::optional<OMPOrderedDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPOrderedDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
