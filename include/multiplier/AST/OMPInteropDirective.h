// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "OMPExecutableDirective.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class OMPExecutableDirective;
class OMPInteropDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPInteropDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPInteropDirective> in(const Index &index);
  static gap::generator<OMPInteropDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPInteropDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPInteropDirective> in(const Fragment &frag);
  static gap::generator<OMPInteropDirective> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_INTEROP_DIRECTIVE;
  }

  static gap::generator<OMPInteropDirective> containing(const Decl &decl);
  static gap::generator<OMPInteropDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPInteropDirective> containing(const Stmt &stmt);
  static gap::generator<OMPInteropDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPInteropDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPInteropDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPInteropDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPInteropDirective> from(const Reference &r);
  static std::optional<OMPInteropDirective> from(const VariantEntity &e);
  static std::optional<OMPInteropDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPInteropDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
