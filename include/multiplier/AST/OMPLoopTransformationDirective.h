// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/OMPLoopBasedDirective.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopTransformationDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPLoopTransformationDirective : public OMPLoopBasedDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPLoopTransformationDirective> in(const Index &index);
  static gap::generator<OMPLoopTransformationDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPLoopTransformationDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPLoopTransformationDirective> in(const Fragment &frag);
  static gap::generator<OMPLoopTransformationDirective> in(const File &file);

  static std::optional<OMPLoopTransformationDirective> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<OMPLoopTransformationDirective, ir::hl::Operation>> in(const Compilation &tu);

  static gap::generator<OMPLoopTransformationDirective> containing(const Decl &decl);
  static gap::generator<OMPLoopTransformationDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPLoopTransformationDirective> containing(const Stmt &stmt);
  static gap::generator<OMPLoopTransformationDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPLoopTransformationDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPLoopTransformationDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPLoopTransformationDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPLoopTransformationDirective> from(const Reference &r);
  static std::optional<OMPLoopTransformationDirective> from(const VariantEntity &e);
  static std::optional<OMPLoopTransformationDirective> from(const TokenContext &t);

  Stmt pre_initializers(void) const;
  Stmt transformed_statement(void) const;
};

static_assert(sizeof(OMPLoopTransformationDirective) == sizeof(OMPLoopBasedDirective));

#endif
} // namespace mx
