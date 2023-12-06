// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/NamedDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class LabelDecl;
class LabelStmt;
class NamedDecl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT LabelDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<LabelDecl> in(const Index &index);
  static gap::generator<LabelDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<LabelDecl> by_id(const Index &, EntityId);
  static gap::generator<LabelDecl> in(const Fragment &frag);
  static gap::generator<LabelDecl> in(const File &file);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::LABEL;
  }

  static gap::generator<LabelDecl> containing(const Decl &decl);
  static gap::generator<LabelDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<LabelDecl> containing(const Stmt &stmt);
  static gap::generator<LabelDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  LabelDecl canonical_declaration(void) const;
  std::optional<LabelDecl> definition(void) const;
  gap::generator<LabelDecl> redeclarations(void) const &;
  static std::optional<LabelDecl> from_base(const Decl &parent);
  inline static std::optional<LabelDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<LabelDecl> from(const std::optional<Decl> &parent);
  static std::optional<LabelDecl> from(const Reference &r);
  static std::optional<LabelDecl> from(const VariantEntity &e);
  static std::optional<LabelDecl> from(const TokenContext &t);

  std::string_view ms_assembly_label(void) const;
  LabelStmt statement(void) const;
  bool is_gnu_local(void) const;
  bool is_ms_assembly_label(void) const;
  bool is_resolved_ms_assembly_label(void) const;
};

static_assert(sizeof(LabelDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
