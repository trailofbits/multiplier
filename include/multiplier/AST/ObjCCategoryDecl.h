// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ObjCContainerDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Reference;
class Decl;
class NamedDecl;
class ObjCCategoryDecl;
class ObjCCategoryImplDecl;
class ObjCContainerDecl;
class ObjCInterfaceDecl;
class ObjCIvarDecl;
class ObjCProtocolDecl;
class Stmt;
class Token;
class TokenRange;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCCategoryDecl : public ObjCContainerDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ObjCCategoryDecl> in(const Index &index);
  static gap::generator<ObjCCategoryDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCCategoryDecl> by_id(const Index &, EntityId);
  static gap::generator<ObjCCategoryDecl> in(const Fragment &frag);
  static gap::generator<ObjCCategoryDecl> in(const File &file);

  static std::optional<ObjCCategoryDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<ObjCCategoryDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_CATEGORY;
  }

  static gap::generator<ObjCCategoryDecl> containing(const Decl &decl);
  static gap::generator<ObjCCategoryDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCCategoryDecl> containing(const Stmt &stmt);
  static gap::generator<ObjCCategoryDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ObjCCategoryDecl canonical_declaration(void) const;
  std::optional<ObjCCategoryDecl> definition(void) const;
  gap::generator<ObjCCategoryDecl> redeclarations(void) const &;
  static std::optional<ObjCCategoryDecl> from_base(const Decl &parent);
  inline static std::optional<ObjCCategoryDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCCategoryDecl> from(const std::optional<Decl> &parent);
  static std::optional<ObjCCategoryDecl> from(const Reference &r);
  static std::optional<ObjCCategoryDecl> from(const VariantEntity &e);
  static std::optional<ObjCCategoryDecl> from(const TokenContext &t);

  bool is_class_extension(void) const;
  Token category_name_token(void) const;
  ObjCInterfaceDecl class_interface(void) const;
  ObjCCategoryImplDecl implementation(void) const;
  Token instance_variable_l_brace_token(void) const;
  Token instance_variable_r_brace_token(void) const;
  ObjCCategoryDecl next_class_category(void) const;
  std::optional<ObjCIvarDecl> nth_instance_variable(unsigned n) const;
  unsigned num_instance_variables(void) const;
  gap::generator<ObjCIvarDecl> instance_variables(void) const &;
  std::optional<Token> nth_protocol_token(unsigned n) const;
  unsigned num_protocol_tokens(void) const;
  gap::generator<Token> protocol_tokens(void) const &;
  std::optional<ObjCProtocolDecl> nth_protocol(unsigned n) const;
  unsigned num_protocols(void) const;
  gap::generator<ObjCProtocolDecl> protocols(void) const &;
};

static_assert(sizeof(ObjCCategoryDecl) == sizeof(ObjCContainerDecl));

#endif
} // namespace mx
