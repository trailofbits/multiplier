// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/BindingDecl.h>
#include <multiplier/AST/BuiltinTemplateDecl.h>
#include <multiplier/AST/CXXConstructorDecl.h>
#include <multiplier/AST/CXXConversionDecl.h>
#include <multiplier/AST/CXXDeductionGuideDecl.h>
#include <multiplier/AST/CXXDestructorDecl.h>
#include <multiplier/AST/CXXMethodDecl.h>
#include <multiplier/AST/CXXRecordDecl.h>
#include <multiplier/AST/ClassTemplateDecl.h>
#include <multiplier/AST/ClassTemplatePartialSpecializationDecl.h>
#include <multiplier/AST/ClassTemplateSpecializationDecl.h>
#include <multiplier/AST/ConceptDecl.h>
#include <multiplier/AST/ConstructorUsingShadowDecl.h>
#include <multiplier/AST/DecompositionDecl.h>
#include <multiplier/AST/EnumConstantDecl.h>
#include <multiplier/AST/EnumDecl.h>
#include <multiplier/AST/FieldDecl.h>
#include <multiplier/AST/FunctionDecl.h>
#include <multiplier/AST/FunctionTemplateDecl.h>
#include <multiplier/AST/HLSLBufferDecl.h>
#include <multiplier/AST/ImplicitParamDecl.h>
#include <multiplier/AST/IndirectFieldDecl.h>
#include <multiplier/AST/LabelDecl.h>
#include <multiplier/AST/MSGuidDecl.h>
#include <multiplier/AST/MSPropertyDecl.h>
#include <multiplier/AST/NamespaceAliasDecl.h>
#include <multiplier/AST/NamespaceDecl.h>
#include <multiplier/AST/NonTypeTemplateParmDecl.h>
#include <multiplier/AST/OMPCapturedExprDecl.h>
#include <multiplier/AST/OMPDeclareMapperDecl.h>
#include <multiplier/AST/OMPDeclareReductionDecl.h>
#include <multiplier/AST/ObjCAtDefsFieldDecl.h>
#include <multiplier/AST/ObjCCategoryDecl.h>
#include <multiplier/AST/ObjCCategoryImplDecl.h>
#include <multiplier/AST/ObjCCompatibleAliasDecl.h>
#include <multiplier/AST/ObjCImplementationDecl.h>
#include <multiplier/AST/ObjCInterfaceDecl.h>
#include <multiplier/AST/ObjCIvarDecl.h>
#include <multiplier/AST/ObjCMethodDecl.h>
#include <multiplier/AST/ObjCPropertyDecl.h>
#include <multiplier/AST/ObjCProtocolDecl.h>
#include <multiplier/AST/ObjCTypeParamDecl.h>
#include <multiplier/AST/ParmVarDecl.h>
#include <multiplier/AST/RecordDecl.h>
#include <multiplier/AST/TemplateParamObjectDecl.h>
#include <multiplier/AST/TemplateTemplateParmDecl.h>
#include <multiplier/AST/TemplateTypeParmDecl.h>
#include <multiplier/AST/TypeAliasDecl.h>
#include <multiplier/AST/TypeAliasTemplateDecl.h>
#include <multiplier/AST/TypedefDecl.h>
#include <multiplier/AST/UnnamedGlobalConstantDecl.h>
#include <multiplier/AST/UnresolvedUsingIfExistsDecl.h>
#include <multiplier/AST/UnresolvedUsingTypenameDecl.h>
#include <multiplier/AST/UnresolvedUsingValueDecl.h>
#include <multiplier/AST/UsingDecl.h>
#include <multiplier/AST/UsingDirectiveDecl.h>
#include <multiplier/AST/UsingEnumDecl.h>
#include <multiplier/AST/UsingPackDecl.h>
#include <multiplier/AST/UsingShadowDecl.h>
#include <multiplier/AST/VarDecl.h>
#include <multiplier/AST/VarTemplateDecl.h>
#include <multiplier/AST/VarTemplatePartialSpecializationDecl.h>
#include <multiplier/AST/VarTemplateSpecializationDecl.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<NamedDecl> NamedDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = NamedDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool NamedDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : NamedDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<NamedDecl> NamedDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = NamedDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<NamedDecl> NamedDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<NamedDecl> NamedDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = NamedDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<NamedDecl> NamedDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool NamedDecl::contains(const Decl &decl) {
  for (auto &parent : NamedDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool NamedDecl::contains(const Stmt &stmt) {
  for (auto &parent : NamedDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

NamedDecl NamedDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (NamedDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<NamedDecl> NamedDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<NamedDecl> NamedDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<NamedDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<NamedDecl> NamedDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<NamedDecl> NamedDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const DeclKind kNamedDeclDerivedKinds[] = {
    NamespaceAliasDecl::static_kind(),
    NamespaceDecl::static_kind(),
    ObjCCompatibleAliasDecl::static_kind(),
    ObjCMethodDecl::static_kind(),
    ObjCPropertyDecl::static_kind(),
    UnresolvedUsingIfExistsDecl::static_kind(),
    UsingDirectiveDecl::static_kind(),
    UsingPackDecl::static_kind(),
    UsingShadowDecl::static_kind(),
    HLSLBufferDecl::static_kind(),
    LabelDecl::static_kind(),
    ObjCInterfaceDecl::static_kind(),
    ObjCProtocolDecl::static_kind(),
    ObjCCategoryDecl::static_kind(),
    TemplateTemplateParmDecl::static_kind(),
    BuiltinTemplateDecl::static_kind(),
    ConceptDecl::static_kind(),
    UnresolvedUsingTypenameDecl::static_kind(),
    TemplateTypeParmDecl::static_kind(),
    ConstructorUsingShadowDecl::static_kind(),
    BindingDecl::static_kind(),
    EnumConstantDecl::static_kind(),
    IndirectFieldDecl::static_kind(),
    MSGuidDecl::static_kind(),
    OMPDeclareReductionDecl::static_kind(),
    TemplateParamObjectDecl::static_kind(),
    UnnamedGlobalConstantDecl::static_kind(),
    UnresolvedUsingValueDecl::static_kind(),
    UsingDecl::static_kind(),
    UsingEnumDecl::static_kind(),
    ObjCImplementationDecl::static_kind(),
    ObjCCategoryImplDecl::static_kind(),
    TypeAliasTemplateDecl::static_kind(),
    VarTemplateDecl::static_kind(),
    ClassTemplateDecl::static_kind(),
    FunctionTemplateDecl::static_kind(),
    ObjCTypeParamDecl::static_kind(),
    TypeAliasDecl::static_kind(),
    TypedefDecl::static_kind(),
    EnumDecl::static_kind(),
    RecordDecl::static_kind(),
    OMPDeclareMapperDecl::static_kind(),
    FieldDecl::static_kind(),
    FunctionDecl::static_kind(),
    MSPropertyDecl::static_kind(),
    NonTypeTemplateParmDecl::static_kind(),
    VarDecl::static_kind(),
    CXXRecordDecl::static_kind(),
    ObjCAtDefsFieldDecl::static_kind(),
    ObjCIvarDecl::static_kind(),
    CXXDeductionGuideDecl::static_kind(),
    CXXMethodDecl::static_kind(),
    VarTemplateSpecializationDecl::static_kind(),
    DecompositionDecl::static_kind(),
    ImplicitParamDecl::static_kind(),
    OMPCapturedExprDecl::static_kind(),
    ParmVarDecl::static_kind(),
    ClassTemplateSpecializationDecl::static_kind(),
    CXXConstructorDecl::static_kind(),
    CXXConversionDecl::static_kind(),
    CXXDestructorDecl::static_kind(),
    VarTemplatePartialSpecializationDecl::static_kind(),
    ClassTemplatePartialSpecializationDecl::static_kind(),
};

}  // namespace

std::optional<NamedDecl> NamedDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case NamespaceAliasDecl::static_kind():
    case NamespaceDecl::static_kind():
    case ObjCCompatibleAliasDecl::static_kind():
    case ObjCMethodDecl::static_kind():
    case ObjCPropertyDecl::static_kind():
    case UnresolvedUsingIfExistsDecl::static_kind():
    case UsingDirectiveDecl::static_kind():
    case UsingPackDecl::static_kind():
    case UsingShadowDecl::static_kind():
    case HLSLBufferDecl::static_kind():
    case LabelDecl::static_kind():
    case ObjCInterfaceDecl::static_kind():
    case ObjCProtocolDecl::static_kind():
    case ObjCCategoryDecl::static_kind():
    case TemplateTemplateParmDecl::static_kind():
    case BuiltinTemplateDecl::static_kind():
    case ConceptDecl::static_kind():
    case UnresolvedUsingTypenameDecl::static_kind():
    case TemplateTypeParmDecl::static_kind():
    case ConstructorUsingShadowDecl::static_kind():
    case BindingDecl::static_kind():
    case EnumConstantDecl::static_kind():
    case IndirectFieldDecl::static_kind():
    case MSGuidDecl::static_kind():
    case OMPDeclareReductionDecl::static_kind():
    case TemplateParamObjectDecl::static_kind():
    case UnnamedGlobalConstantDecl::static_kind():
    case UnresolvedUsingValueDecl::static_kind():
    case UsingDecl::static_kind():
    case UsingEnumDecl::static_kind():
    case ObjCImplementationDecl::static_kind():
    case ObjCCategoryImplDecl::static_kind():
    case TypeAliasTemplateDecl::static_kind():
    case VarTemplateDecl::static_kind():
    case ClassTemplateDecl::static_kind():
    case FunctionTemplateDecl::static_kind():
    case ObjCTypeParamDecl::static_kind():
    case TypeAliasDecl::static_kind():
    case TypedefDecl::static_kind():
    case EnumDecl::static_kind():
    case RecordDecl::static_kind():
    case OMPDeclareMapperDecl::static_kind():
    case FieldDecl::static_kind():
    case FunctionDecl::static_kind():
    case MSPropertyDecl::static_kind():
    case NonTypeTemplateParmDecl::static_kind():
    case VarDecl::static_kind():
    case CXXRecordDecl::static_kind():
    case ObjCAtDefsFieldDecl::static_kind():
    case ObjCIvarDecl::static_kind():
    case CXXDeductionGuideDecl::static_kind():
    case CXXMethodDecl::static_kind():
    case VarTemplateSpecializationDecl::static_kind():
    case DecompositionDecl::static_kind():
    case ImplicitParamDecl::static_kind():
    case OMPCapturedExprDecl::static_kind():
    case ParmVarDecl::static_kind():
    case ClassTemplateSpecializationDecl::static_kind():
    case CXXConstructorDecl::static_kind():
    case CXXConversionDecl::static_kind():
    case CXXDestructorDecl::static_kind():
    case VarTemplatePartialSpecializationDecl::static_kind():
    case ClassTemplatePartialSpecializationDecl::static_kind():
      return reinterpret_cast<const NamedDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<NamedDecl> NamedDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kNamedDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<NamedDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<NamedDecl> NamedDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kNamedDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<NamedDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<NamedDecl> NamedDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kNamedDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<NamedDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<NamedDecl> NamedDecl::from(const Reference &r) {
  return NamedDecl::from(r.as_declaration());
}

std::optional<NamedDecl> NamedDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<NamedDecl> NamedDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Linkage NamedDecl::formal_linkage(void) const {
  return static_cast<Linkage>(impl->reader.getVal65());
}

std::string_view NamedDecl::name(void) const {
  capnp::Text::Reader data = impl->reader.getVal63();
  return std::string_view(data.cStr(), data.size());
}

std::optional<ObjCStringFormatFamily> NamedDecl::obj_cf_string_formatting_family(void) const {
  if (!impl->reader.getVal50()) {
    return std::nullopt;
  } else {
    return static_cast<ObjCStringFormatFamily>(impl->reader.getVal69());
  }
  return std::nullopt;
}

std::string_view NamedDecl::qualified_name_as_string(void) const {
  capnp::Text::Reader data = impl->reader.getVal64();
  return std::string_view(data.cStr(), data.size());
}

NamedDecl NamedDecl::underlying_declaration(void) const {
  RawEntityId eid = impl->reader.getVal49();
  return NamedDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Visibility NamedDecl::visibility(void) const {
  return static_cast<Visibility>(impl->reader.getVal70());
}

bool NamedDecl::has_external_formal_linkage(void) const {
  return impl->reader.getVal53();
}

bool NamedDecl::has_linkage(void) const {
  return impl->reader.getVal54();
}

bool NamedDecl::has_linkage_been_computed(void) const {
  return impl->reader.getVal55();
}

bool NamedDecl::is_cxx_class_member(void) const {
  return impl->reader.getVal59();
}

bool NamedDecl::is_cxx_instance_member(void) const {
  return impl->reader.getVal60();
}

bool NamedDecl::is_externally_declarable(void) const {
  return impl->reader.getVal61();
}

bool NamedDecl::is_externally_visible(void) const {
  return impl->reader.getVal71();
}

bool NamedDecl::is_linkage_valid(void) const {
  return impl->reader.getVal72();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
