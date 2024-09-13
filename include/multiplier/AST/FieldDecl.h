// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/DeclaratorDecl.h>
#include <multiplier/AST/InClassInitStyle.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class DeclaratorDecl;
class Expr;
class FieldDecl;
class File;
class NamedDecl;
class Stmt;
class Token;
class ValueDecl;
class VariableArrayType;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT FieldDecl : public DeclaratorDecl {
 private:
  friend class FragmentImpl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<FieldDecl> in(const Index &index);
  static gap::generator<FieldDecl> in(const Fragment &frag);
  static gap::generator<FieldDecl> in(const File &file);
  static gap::generator<FieldDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<FieldDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<FieldDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::FIELD;
  }

  static gap::generator<FieldDecl> containing(const Decl &decl);
  static gap::generator<FieldDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<FieldDecl> containing(const Stmt &stmt);
  static gap::generator<FieldDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  FieldDecl canonical_declaration(void) const;
  std::optional<FieldDecl> definition(void) const;
  gap::generator<FieldDecl> redeclarations(void) const &;
  static std::optional<FieldDecl> by_id(const Index &, EntityId);

  static std::optional<FieldDecl> from_base(const Decl &parent);
  inline static std::optional<FieldDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<FieldDecl> from(const std::optional<Decl> &parent);
  static std::optional<FieldDecl> from(const Reference &r);
  static std::optional<FieldDecl> from(const VariantEntity &e);
  static std::optional<FieldDecl> from(const TokenContext &t);

  std::optional<Expr> bit_width(void) const;
  std::optional<VariableArrayType> captured_vla_type(void) const;
  uint32_t field_index(void) const;
  InClassInitStyle in_class_initializer_style(void) const;
  std::optional<Expr> in_class_initializer(void) const;
  bool has_captured_vla_type(void) const;
  bool has_in_class_initializer(void) const;
  bool has_non_null_in_class_initializer(void) const;
  bool is_anonymous_struct_or_union(void) const;
  bool is_bit_field(void) const;
  bool is_mutable(void) const;
  bool is_potentially_overlapping(void) const;
  bool is_unnamed_bitfield(void) const;
  bool is_zero_length_bit_field(void) const;
  bool is_zero_size(void) const;
  std::optional<uint64_t> offset_in_bits(void) const;
};

static_assert(sizeof(FieldDecl) == sizeof(DeclaratorDecl));

#endif
} // namespace mx
