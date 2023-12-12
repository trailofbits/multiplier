// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ValueStmt.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class LabelDecl;
class LabelStmt;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT LabelStmt : public ValueStmt {
 private:
  friend class FragmentImpl;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<LabelStmt> in(const Index &index);
  static gap::generator<LabelStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<LabelStmt> by_id(const Index &, EntityId);
  static gap::generator<LabelStmt> in(const Fragment &frag);
  static gap::generator<LabelStmt> in(const File &file);

#ifndef MX_DISABLE_VAST
  static std::optional<LabelStmt> from(const ir::Operation &op);
  static gap::generator<std::pair<LabelStmt, ir::Operation>> in(const Compilation &tu);
#endif  // MX_DISABLE_VAST

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::LABEL_STMT;
  }

  static gap::generator<LabelStmt> containing(const Decl &decl);
  static gap::generator<LabelStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<LabelStmt> containing(const Stmt &stmt);
  static gap::generator<LabelStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<LabelStmt> from_base(const Stmt &parent);
  inline static std::optional<LabelStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<LabelStmt> from(const std::optional<Stmt> &parent);
  static std::optional<LabelStmt> from(const Reference &r);
  static std::optional<LabelStmt> from(const VariantEntity &e);
  static std::optional<LabelStmt> from(const TokenContext &t);

  LabelDecl declaration(void) const;
  Token identifier_token(void) const;
  std::string_view name(void) const;
  Stmt sub_statement(void) const;
  bool is_side_entry(void) const;
};

static_assert(sizeof(LabelStmt) == sizeof(ValueStmt));

#endif
} // namespace mx
