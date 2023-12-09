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
class OMPSingleDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPSingleDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPSingleDirective> in(const Index &index);
  static gap::generator<OMPSingleDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPSingleDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPSingleDirective> in(const Fragment &frag);
  static gap::generator<OMPSingleDirective> in(const File &file);

  static std::optional<OMPSingleDirective> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<OMPSingleDirective, ir::hl::Operation>> in(const Compilation &tu);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_SINGLE_DIRECTIVE;
  }

  static gap::generator<OMPSingleDirective> containing(const Decl &decl);
  static gap::generator<OMPSingleDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPSingleDirective> containing(const Stmt &stmt);
  static gap::generator<OMPSingleDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPSingleDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPSingleDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPSingleDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPSingleDirective> from(const Reference &r);
  static std::optional<OMPSingleDirective> from(const VariantEntity &e);
  static std::optional<OMPSingleDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPSingleDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
