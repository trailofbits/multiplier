// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ClassTemplateSpecializationDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Reference;
class CXXRecordDecl;
class ClassTemplatePartialSpecializationDecl;
class ClassTemplateSpecializationDecl;
class Decl;
class NamedDecl;
class RecordDecl;
class Stmt;
class TagDecl;
class TemplateParameterList;
class Token;
class Type;
class TypeDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ClassTemplatePartialSpecializationDecl : public ClassTemplateSpecializationDecl {
 private:
  friend class FragmentImpl;
  friend class ClassTemplateSpecializationDecl;
  friend class CXXRecordDecl;
  friend class RecordDecl;
  friend class TagDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ClassTemplatePartialSpecializationDecl> in(const Index &index);
  static gap::generator<ClassTemplatePartialSpecializationDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ClassTemplatePartialSpecializationDecl> by_id(const Index &, EntityId);
  static gap::generator<ClassTemplatePartialSpecializationDecl> in(const Fragment &frag);
  static gap::generator<ClassTemplatePartialSpecializationDecl> in(const File &file);

  static std::optional<ClassTemplatePartialSpecializationDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<ClassTemplatePartialSpecializationDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION;
  }

  static gap::generator<ClassTemplatePartialSpecializationDecl> containing(const Decl &decl);
  static gap::generator<ClassTemplatePartialSpecializationDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ClassTemplatePartialSpecializationDecl> containing(const Stmt &stmt);
  static gap::generator<ClassTemplatePartialSpecializationDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ClassTemplatePartialSpecializationDecl canonical_declaration(void) const;
  std::optional<ClassTemplatePartialSpecializationDecl> definition(void) const;
  gap::generator<ClassTemplatePartialSpecializationDecl> redeclarations(void) const &;
  static std::optional<ClassTemplatePartialSpecializationDecl> from_base(const Decl &parent);
  inline static std::optional<ClassTemplatePartialSpecializationDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<ClassTemplatePartialSpecializationDecl> from(const std::optional<Decl> &parent);
  static std::optional<ClassTemplatePartialSpecializationDecl> from(const Reference &r);
  static std::optional<ClassTemplatePartialSpecializationDecl> from(const VariantEntity &e);
  static std::optional<ClassTemplatePartialSpecializationDecl> from(const TokenContext &t);

  Type injected_specialization_type(void) const;
  std::optional<ClassTemplatePartialSpecializationDecl> instantiated_from_member(void) const;
  std::optional<ClassTemplatePartialSpecializationDecl> instantiated_from_member_template(void) const;
  TemplateParameterList template_parameters(void) const;
  bool has_associated_constraints(void) const;
};

static_assert(sizeof(ClassTemplatePartialSpecializationDecl) == sizeof(ClassTemplateSpecializationDecl));

#endif
} // namespace mx
