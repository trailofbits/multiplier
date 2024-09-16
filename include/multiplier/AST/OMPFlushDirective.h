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
class OMPFlushDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPFlushDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPFlushDirective> in(const Index &index);
  static gap::generator<OMPFlushDirective> in(const Fragment &frag);
  static gap::generator<OMPFlushDirective> in(const File &file);
  static gap::generator<OMPFlushDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<OMPFlushDirective> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPFlushDirective, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_FLUSH_DIRECTIVE;
  }

  static gap::generator<OMPFlushDirective> containing(const Decl &decl);
  static gap::generator<OMPFlushDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPFlushDirective> containing(const Stmt &stmt);
  static gap::generator<OMPFlushDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPFlushDirective> by_id(const Index &, EntityId);

  static std::optional<OMPFlushDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPFlushDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPFlushDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPFlushDirective> from(const Reference &r);
  static std::optional<OMPFlushDirective> from(const VariantEntity &e);
  static std::optional<OMPFlushDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPFlushDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
