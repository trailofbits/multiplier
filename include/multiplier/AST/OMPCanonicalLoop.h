// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Stmt.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CapturedStmt;
class Decl;
class DeclRefExpr;
class OMPCanonicalLoop;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPCanonicalLoop : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<OMPCanonicalLoop> in(const Index &index);
  static gap::generator<OMPCanonicalLoop> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPCanonicalLoop> by_id(const Index &, EntityId);
  static gap::generator<OMPCanonicalLoop> in(const Fragment &frag);
  static gap::generator<OMPCanonicalLoop> in(const File &file);

  static std::optional<OMPCanonicalLoop> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<OMPCanonicalLoop, ir::hl::Operation>> in(const Compilation &tu);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_CANONICAL_LOOP;
  }

  static gap::generator<OMPCanonicalLoop> containing(const Decl &decl);
  static gap::generator<OMPCanonicalLoop> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPCanonicalLoop> containing(const Stmt &stmt);
  static gap::generator<OMPCanonicalLoop> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPCanonicalLoop> from_base(const Stmt &parent);
  inline static std::optional<OMPCanonicalLoop> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPCanonicalLoop> from(const std::optional<Stmt> &parent);
  static std::optional<OMPCanonicalLoop> from(const Reference &r);
  static std::optional<OMPCanonicalLoop> from(const VariantEntity &e);
  static std::optional<OMPCanonicalLoop> from(const TokenContext &t);

  CapturedStmt distance_func(void) const;
  Stmt loop_statement(void) const;
  CapturedStmt loop_variable_func(void) const;
  DeclRefExpr loop_variable_reference(void) const;
};

static_assert(sizeof(OMPCanonicalLoop) == sizeof(Stmt));

#endif
} // namespace mx
