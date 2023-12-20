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
class OMPExecutableDirective;
class OMPGenericLoopDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPGenericLoopDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPGenericLoopDirective> in(const Index &index);
  static gap::generator<OMPGenericLoopDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPGenericLoopDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPGenericLoopDirective> in(const Fragment &frag);
  static gap::generator<OMPGenericLoopDirective> in(const File &file);

  static std::optional<OMPGenericLoopDirective> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPGenericLoopDirective, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_GENERIC_LOOP_DIRECTIVE;
  }

  static gap::generator<OMPGenericLoopDirective> containing(const Decl &decl);
  static gap::generator<OMPGenericLoopDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPGenericLoopDirective> containing(const Stmt &stmt);
  static gap::generator<OMPGenericLoopDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPGenericLoopDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPGenericLoopDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPGenericLoopDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPGenericLoopDirective> from(const Reference &r);
  static std::optional<OMPGenericLoopDirective> from(const VariantEntity &e);
  static std::optional<OMPGenericLoopDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPGenericLoopDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
