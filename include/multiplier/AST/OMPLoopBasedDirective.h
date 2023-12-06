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
class OMPLoopBasedDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPLoopBasedDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPLoopBasedDirective> in(const Index &index);
  static gap::generator<OMPLoopBasedDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPLoopBasedDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPLoopBasedDirective> in(const Fragment &frag);
  static gap::generator<OMPLoopBasedDirective> in(const File &file);

  static gap::generator<OMPLoopBasedDirective> containing(const Decl &decl);
  static gap::generator<OMPLoopBasedDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPLoopBasedDirective> containing(const Stmt &stmt);
  static gap::generator<OMPLoopBasedDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPLoopBasedDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPLoopBasedDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPLoopBasedDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPLoopBasedDirective> from(const Reference &r);
  static std::optional<OMPLoopBasedDirective> from(const VariantEntity &e);
  static std::optional<OMPLoopBasedDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPLoopBasedDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
