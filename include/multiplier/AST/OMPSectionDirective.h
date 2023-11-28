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
class OMPSectionDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPSectionDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPSectionDirective> in(const Index &index);
  static gap::generator<OMPSectionDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPSectionDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPSectionDirective> in(const Fragment &frag);
  static gap::generator<OMPSectionDirective> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_SECTION_DIRECTIVE;
  }

  static gap::generator<OMPSectionDirective> containing(const Decl &decl);
  static gap::generator<OMPSectionDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPSectionDirective> containing(const Stmt &stmt);
  static gap::generator<OMPSectionDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPSectionDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPSectionDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPSectionDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPSectionDirective> from(const Reference &r);
  static std::optional<OMPSectionDirective> from(const VariantEntity &e);
  static std::optional<OMPSectionDirective> from(const TokenContext &t);

  bool has_cancel(void) const;
};

static_assert(sizeof(OMPSectionDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
