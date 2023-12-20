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
class OMPTargetEnterDataDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPTargetEnterDataDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPTargetEnterDataDirective> in(const Index &index);
  static gap::generator<OMPTargetEnterDataDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPTargetEnterDataDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPTargetEnterDataDirective> in(const Fragment &frag);
  static gap::generator<OMPTargetEnterDataDirective> in(const File &file);

  static std::optional<OMPTargetEnterDataDirective> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPTargetEnterDataDirective, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TARGET_ENTER_DATA_DIRECTIVE;
  }

  static gap::generator<OMPTargetEnterDataDirective> containing(const Decl &decl);
  static gap::generator<OMPTargetEnterDataDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPTargetEnterDataDirective> containing(const Stmt &stmt);
  static gap::generator<OMPTargetEnterDataDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTargetEnterDataDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPTargetEnterDataDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPTargetEnterDataDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPTargetEnterDataDirective> from(const Reference &r);
  static std::optional<OMPTargetEnterDataDirective> from(const VariantEntity &e);
  static std::optional<OMPTargetEnterDataDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPTargetEnterDataDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
