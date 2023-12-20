// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Linkage.h>
#include <multiplier/AST/ObjCStringFormatFamily.h>
#include <multiplier/AST/Visibility.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class NamedDecl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT NamedDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<NamedDecl> in(const Index &index);
  static gap::generator<NamedDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NamedDecl> by_id(const Index &, EntityId);
  static gap::generator<NamedDecl> in(const Fragment &frag);
  static gap::generator<NamedDecl> in(const File &file);

  static std::optional<NamedDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<NamedDecl, ir::Operation>> in(const Compilation &tu);
  static gap::generator<NamedDecl> containing(const Decl &decl);
  static gap::generator<NamedDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<NamedDecl> containing(const Stmt &stmt);
  static gap::generator<NamedDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  NamedDecl canonical_declaration(void) const;
  std::optional<NamedDecl> definition(void) const;
  gap::generator<NamedDecl> redeclarations(void) const &;
  static std::optional<NamedDecl> from_base(const Decl &parent);
  inline static std::optional<NamedDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<NamedDecl> from(const std::optional<Decl> &parent);
  static std::optional<NamedDecl> from(const Reference &r);
  static std::optional<NamedDecl> from(const VariantEntity &e);
  static std::optional<NamedDecl> from(const TokenContext &t);

  Linkage formal_linkage(void) const;
  std::string_view name(void) const;
  std::optional<ObjCStringFormatFamily> obj_cf_string_formatting_family(void) const;
  std::string_view qualified_name_as_string(void) const;
  NamedDecl underlying_declaration(void) const;
  Visibility visibility(void) const;
  bool has_external_formal_linkage(void) const;
  bool has_linkage(void) const;
  bool has_linkage_been_computed(void) const;
  bool is_cxx_class_member(void) const;
  bool is_cxx_instance_member(void) const;
  bool is_externally_declarable(void) const;
  bool is_externally_visible(void) const;
  bool is_linkage_valid(void) const;
};

static_assert(sizeof(NamedDecl) == sizeof(Decl));

#endif
} // namespace mx
