// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "OMPLoopTransformationDirective.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopTransformationDirective;
class OMPUnrollDirective;
class Stmt;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPUnrollDirective : public OMPLoopTransformationDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopTransformationDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPUnrollDirective> in(const Fragment &frag);
  static gap::generator<OMPUnrollDirective> in(const File &file);
  static gap::generator<OMPUnrollDirective> in(const Index &index);
  static gap::generator<OMPUnrollDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPUnrollDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_UNROLL_DIRECTIVE;
  }

  static gap::generator<OMPUnrollDirective> containing(const Decl &decl);
  static gap::generator<OMPUnrollDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPUnrollDirective> containing(const Stmt &stmt);
  static gap::generator<OMPUnrollDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPUnrollDirective> from(const Stmt &parent);

  inline static std::optional<OMPUnrollDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPUnrollDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPUnrollDirective> from(const Reference &r);
  static std::optional<OMPUnrollDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPUnrollDirective) == sizeof(OMPLoopTransformationDirective));

#endif
} // namespace mx
