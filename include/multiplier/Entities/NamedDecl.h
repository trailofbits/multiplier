// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Decl.h"
#include "Linkage.h"
#include "ObjCStringFormatFamily.h"
#include "Visibility.h"

namespace mx {
class EntityProvider;
class Index;
class BindingDecl;
class BuiltinTemplateDecl;
class CXXConstructorDecl;
class CXXConversionDecl;
class CXXDeductionGuideDecl;
class CXXDestructorDecl;
class CXXMethodDecl;
class CXXRecordDecl;
class ClassTemplateDecl;
class ClassTemplatePartialSpecializationDecl;
class ClassTemplateSpecializationDecl;
class ConceptDecl;
class ConstructorUsingShadowDecl;
class Decl;
class DecompositionDecl;
class EnumConstantDecl;
class EnumDecl;
class FieldDecl;
class FunctionDecl;
class FunctionTemplateDecl;
class HLSLBufferDecl;
class ImplicitParamDecl;
class IndirectFieldDecl;
class LabelDecl;
class MSGuidDecl;
class MSPropertyDecl;
class NamedDecl;
class NamespaceAliasDecl;
class NamespaceDecl;
class NonTypeTemplateParmDecl;
class OMPCapturedExprDecl;
class OMPDeclareMapperDecl;
class OMPDeclareReductionDecl;
class ObjCAtDefsFieldDecl;
class ObjCCategoryDecl;
class ObjCCategoryImplDecl;
class ObjCCompatibleAliasDecl;
class ObjCImplementationDecl;
class ObjCInterfaceDecl;
class ObjCIvarDecl;
class ObjCMethodDecl;
class ObjCPropertyDecl;
class ObjCProtocolDecl;
class ObjCTypeParamDecl;
class ParmVarDecl;
class RecordDecl;
class Stmt;
class TemplateParamObjectDecl;
class TemplateTemplateParmDecl;
class TemplateTypeParmDecl;
class Token;
class TypeAliasDecl;
class TypeAliasTemplateDecl;
class TypedefDecl;
class UnnamedGlobalConstantDecl;
class UnresolvedUsingIfExistsDecl;
class UnresolvedUsingTypenameDecl;
class UnresolvedUsingValueDecl;
class UsingDecl;
class UsingDirectiveDecl;
class UsingEnumDecl;
class UsingPackDecl;
class UsingShadowDecl;
class VarDecl;
class VarTemplateDecl;
class VarTemplatePartialSpecializationDecl;
class VarTemplateSpecializationDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NamedDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<NamedDecl> in(const Fragment &frag);
  static gap::generator<NamedDecl> in(const File &file);
  static gap::generator<NamedDecl> in(const Index &index);
  static gap::generator<NamedDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NamedDecl> by_id(const Index &, EntityId);

  static gap::generator<NamedDecl> containing(const Decl &decl);
  static gap::generator<NamedDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<NamedDecl> containing(const Stmt &stmt);
  static gap::generator<NamedDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<NamedDecl> redeclarations(void) const &;
  static std::optional<NamedDecl> from(const Decl &parent);

  inline static std::optional<NamedDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return NamedDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NamedDecl> from(const Reference &r);
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
