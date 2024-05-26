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
class File;
class OMPExecutableDirective;
class OMPMasterDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPMasterDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPMasterDirective> in(const Index &index);
  static gap::generator<OMPMasterDirective> in(const Fragment &frag);
  static gap::generator<OMPMasterDirective> in(const File &file);
  static gap::generator<OMPMasterDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<OMPMasterDirective> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPMasterDirective, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_MASTER_DIRECTIVE;
  }

  static gap::generator<OMPMasterDirective> containing(const Decl &decl);
  static gap::generator<OMPMasterDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPMasterDirective> containing(const Stmt &stmt);
  static gap::generator<OMPMasterDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPMasterDirective> by_id(const Index &, EntityId);

  static std::optional<OMPMasterDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPMasterDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPMasterDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPMasterDirective> from(const Reference &r);
  static std::optional<OMPMasterDirective> from(const VariantEntity &e);
  static std::optional<OMPMasterDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPMasterDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
