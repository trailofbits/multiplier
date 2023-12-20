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
class OMPTeamsDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPTeamsDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPTeamsDirective> in(const Index &index);
  static gap::generator<OMPTeamsDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPTeamsDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPTeamsDirective> in(const Fragment &frag);
  static gap::generator<OMPTeamsDirective> in(const File &file);

  static std::optional<OMPTeamsDirective> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPTeamsDirective, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TEAMS_DIRECTIVE;
  }

  static gap::generator<OMPTeamsDirective> containing(const Decl &decl);
  static gap::generator<OMPTeamsDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPTeamsDirective> containing(const Stmt &stmt);
  static gap::generator<OMPTeamsDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTeamsDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPTeamsDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPTeamsDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPTeamsDirective> from(const Reference &r);
  static std::optional<OMPTeamsDirective> from(const VariantEntity &e);
  static std::optional<OMPTeamsDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPTeamsDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
