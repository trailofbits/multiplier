// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Expr.h>
#include <multiplier/AST/StringLiteralKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class Stmt;
class StringLiteral;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT StringLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<StringLiteral> in(const Index &index);
  static gap::generator<StringLiteral> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<StringLiteral> by_id(const Index &, EntityId);
  static gap::generator<StringLiteral> in(const Fragment &frag);
  static gap::generator<StringLiteral> in(const File &file);

  static std::optional<StringLiteral> from(const ir::Operation &op);
  static gap::generator<std::pair<StringLiteral, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::STRING_LITERAL;
  }

  static gap::generator<StringLiteral> containing(const Decl &decl);
  static gap::generator<StringLiteral> containing(const std::optional<Decl> &decl);

  static gap::generator<StringLiteral> containing(const Stmt &stmt);
  static gap::generator<StringLiteral> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<StringLiteral> from_base(const Stmt &parent);
  inline static std::optional<StringLiteral> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<StringLiteral> from(const std::optional<Stmt> &parent);
  static std::optional<StringLiteral> from(const Reference &r);
  static std::optional<StringLiteral> from(const VariantEntity &e);
  static std::optional<StringLiteral> from(const TokenContext &t);

  std::optional<bool> contains_non_ascii(void) const;
  std::optional<bool> contains_non_ascii_or_null(void) const;
  std::string_view bytes(void) const;
  StringLiteralKind literal_kind(void) const;
  std::optional<std::string_view> string(void) const;
  bool is_ordinary(void) const;
  bool is_pascal(void) const;
  bool is_utf16(void) const;
  bool is_utf32(void) const;
  bool is_utf8(void) const;
  bool is_unevaluated(void) const;
  bool is_wide(void) const;
};

static_assert(sizeof(StringLiteral) == sizeof(Expr));

#endif
} // namespace mx
