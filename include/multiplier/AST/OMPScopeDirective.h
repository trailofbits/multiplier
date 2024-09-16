// Copyright (c) 2022-present, Trail of Bits, Inc.
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
class File;
class OMPExecutableDirective;
class OMPScopeDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPScopeDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPScopeDirective> in(const Index &index);
  static gap::generator<OMPScopeDirective> in(const Fragment &frag);
  static gap::generator<OMPScopeDirective> in(const File &file);
  static gap::generator<OMPScopeDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<OMPScopeDirective> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPScopeDirective, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_SCOPE_DIRECTIVE;
  }

  static gap::generator<OMPScopeDirective> containing(const Decl &decl);
  static gap::generator<OMPScopeDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPScopeDirective> containing(const Stmt &stmt);
  static gap::generator<OMPScopeDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPScopeDirective> by_id(const Index &, EntityId);

  static std::optional<OMPScopeDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPScopeDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPScopeDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPScopeDirective> from(const Reference &r);
  static std::optional<OMPScopeDirective> from(const VariantEntity &e);
  static std::optional<OMPScopeDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPScopeDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
