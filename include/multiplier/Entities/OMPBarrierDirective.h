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
class OMPBarrierDirective;
class OMPExecutableDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPBarrierDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPBarrierDirective> in(const Index &index);
  static gap::generator<OMPBarrierDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPBarrierDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPBarrierDirective> in(const Fragment &frag);
  static gap::generator<OMPBarrierDirective> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_BARRIER_DIRECTIVE;
  }

  static gap::generator<OMPBarrierDirective> containing(const Decl &decl);
  static gap::generator<OMPBarrierDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPBarrierDirective> containing(const Stmt &stmt);
  static gap::generator<OMPBarrierDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPBarrierDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPBarrierDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPBarrierDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPBarrierDirective> from(const Reference &r);
  static std::optional<OMPBarrierDirective> from(const VariantEntity &e);
  static std::optional<OMPBarrierDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPBarrierDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
