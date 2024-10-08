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
class OMPMaskedDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPMaskedDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPMaskedDirective> in(const Index &index);
  static gap::generator<OMPMaskedDirective> in(const Fragment &frag);
  static gap::generator<OMPMaskedDirective> in(const File &file);
  static gap::generator<OMPMaskedDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<OMPMaskedDirective> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPMaskedDirective, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_MASKED_DIRECTIVE;
  }

  static gap::generator<OMPMaskedDirective> containing(const Decl &decl);
  static gap::generator<OMPMaskedDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPMaskedDirective> containing(const Stmt &stmt);
  static gap::generator<OMPMaskedDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPMaskedDirective> by_id(const Index &, EntityId);

  static std::optional<OMPMaskedDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPMaskedDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPMaskedDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPMaskedDirective> from(const Reference &r);
  static std::optional<OMPMaskedDirective> from(const VariantEntity &e);
  static std::optional<OMPMaskedDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPMaskedDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
