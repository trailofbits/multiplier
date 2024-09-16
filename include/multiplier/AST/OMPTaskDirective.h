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
class OMPTaskDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPTaskDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPTaskDirective> in(const Index &index);
  static gap::generator<OMPTaskDirective> in(const Fragment &frag);
  static gap::generator<OMPTaskDirective> in(const File &file);
  static gap::generator<OMPTaskDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<OMPTaskDirective> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPTaskDirective, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TASK_DIRECTIVE;
  }

  static gap::generator<OMPTaskDirective> containing(const Decl &decl);
  static gap::generator<OMPTaskDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPTaskDirective> containing(const Stmt &stmt);
  static gap::generator<OMPTaskDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTaskDirective> by_id(const Index &, EntityId);

  static std::optional<OMPTaskDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPTaskDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPTaskDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPTaskDirective> from(const Reference &r);
  static std::optional<OMPTaskDirective> from(const VariantEntity &e);
  static std::optional<OMPTaskDirective> from(const TokenContext &t);

  bool has_cancel(void) const;
};

static_assert(sizeof(OMPTaskDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
