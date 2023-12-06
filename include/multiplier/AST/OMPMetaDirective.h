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
class OMPMetaDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPMetaDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPMetaDirective> in(const Index &index);
  static gap::generator<OMPMetaDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPMetaDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPMetaDirective> in(const Fragment &frag);
  static gap::generator<OMPMetaDirective> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_META_DIRECTIVE;
  }

  static gap::generator<OMPMetaDirective> containing(const Decl &decl);
  static gap::generator<OMPMetaDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPMetaDirective> containing(const Stmt &stmt);
  static gap::generator<OMPMetaDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPMetaDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPMetaDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPMetaDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPMetaDirective> from(const Reference &r);
  static std::optional<OMPMetaDirective> from(const VariantEntity &e);
  static std::optional<OMPMetaDirective> from(const TokenContext &t);

  Stmt if_statement(void) const;
};

static_assert(sizeof(OMPMetaDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
