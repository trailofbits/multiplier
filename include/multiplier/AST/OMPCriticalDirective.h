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
class OMPCriticalDirective;
class OMPExecutableDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPCriticalDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPCriticalDirective> in(const Index &index);
  static gap::generator<OMPCriticalDirective> in(const Fragment &frag);
  static gap::generator<OMPCriticalDirective> in(const File &file);
  static gap::generator<OMPCriticalDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<OMPCriticalDirective> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPCriticalDirective, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_CRITICAL_DIRECTIVE;
  }

  static gap::generator<OMPCriticalDirective> containing(const Decl &decl);
  static gap::generator<OMPCriticalDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPCriticalDirective> containing(const Stmt &stmt);
  static gap::generator<OMPCriticalDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPCriticalDirective> by_id(const Index &, EntityId);

  static std::optional<OMPCriticalDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPCriticalDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPCriticalDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPCriticalDirective> from(const Reference &r);
  static std::optional<OMPCriticalDirective> from(const VariantEntity &e);
  static std::optional<OMPCriticalDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPCriticalDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
