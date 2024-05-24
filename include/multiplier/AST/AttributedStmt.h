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
class Attr;
class AttributedStmt;
class Decl;
class File;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT AttributedStmt : public ValueStmt {
 private:
  friend class FragmentImpl;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<AttributedStmt> in(const Index &index);
  static gap::generator<AttributedStmt> in(const Fragment &frag);
  static gap::generator<AttributedStmt> in(const File &file);
  static gap::generator<AttributedStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<AttributedStmt> from(const ir::Operation &op);
  static gap::generator<std::pair<AttributedStmt, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::ATTRIBUTED_STMT;
  }

  static gap::generator<AttributedStmt> containing(const Decl &decl);
  static gap::generator<AttributedStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<AttributedStmt> containing(const Stmt &stmt);
  static gap::generator<AttributedStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<AttributedStmt> by_id(const Index &, EntityId);

  static std::optional<AttributedStmt> from_base(const Stmt &parent);
  inline static std::optional<AttributedStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<AttributedStmt> from(const std::optional<Stmt> &parent);
  static std::optional<AttributedStmt> from(const Reference &r);
  static std::optional<AttributedStmt> from(const VariantEntity &e);
  static std::optional<AttributedStmt> from(const TokenContext &t);

  Token attribute_token(void) const;
  std::optional<Attr> nth_attribute(unsigned n) const;
  unsigned num_attributes(void) const;
  gap::generator<Attr> attributes(void) const &;
  Stmt sub_statement(void) const;
};

static_assert(sizeof(AttributedStmt) == sizeof(ValueStmt));

#endif
} // namespace mx
