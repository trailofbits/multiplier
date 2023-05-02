// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ValueDecl.h>

#include <multiplier/Entities/BindingDecl.h>
#include <multiplier/Entities/CXXConstructorDecl.h>
#include <multiplier/Entities/CXXConversionDecl.h>
#include <multiplier/Entities/CXXDeductionGuideDecl.h>
#include <multiplier/Entities/CXXDestructorDecl.h>
#include <multiplier/Entities/CXXMethodDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DecompositionDecl.h>
#include <multiplier/Entities/EnumConstantDecl.h>
#include <multiplier/Entities/FieldDecl.h>
#include <multiplier/Entities/FunctionDecl.h>
#include <multiplier/Entities/ImplicitParamDecl.h>
#include <multiplier/Entities/IndirectFieldDecl.h>
#include <multiplier/Entities/MSGuidDecl.h>
#include <multiplier/Entities/MSPropertyDecl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/NonTypeTemplateParmDecl.h>
#include <multiplier/Entities/OMPCapturedExprDecl.h>
#include <multiplier/Entities/OMPDeclareMapperDecl.h>
#include <multiplier/Entities/OMPDeclareReductionDecl.h>
#include <multiplier/Entities/ObjCAtDefsFieldDecl.h>
#include <multiplier/Entities/ObjCIvarDecl.h>
#include <multiplier/Entities/ParmVarDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateParamObjectDecl.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/UnnamedGlobalConstantDecl.h>
#include <multiplier/Entities/UnresolvedUsingValueDecl.h>
#include <multiplier/Entities/VarDecl.h>
#include <multiplier/Entities/VarTemplatePartialSpecializationDecl.h>
#include <multiplier/Entities/VarTemplateSpecializationDecl.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ValueDecl> ValueDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ValueDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ValueDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ValueDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ValueDecl> ValueDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ValueDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ValueDecl> ValueDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ValueDecl> ValueDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ValueDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ValueDecl> ValueDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ValueDecl::contains(const Decl &decl) {
  for (auto &parent : ValueDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ValueDecl::contains(const Stmt &stmt) {
  for (auto &parent : ValueDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ValueDecl ValueDecl::canonical_declaration(void) const {
  if (auto canon = ValueDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ValueDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ValueDecl> ValueDecl::definition(void) const {
  return ValueDecl::from(this->Decl::definition());
}

gap::generator<ValueDecl> ValueDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ValueDecl> dr = ValueDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ValueDecl> ValueDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ValueDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kValueDeclDerivedKinds[] = {
    BindingDecl::static_kind(),
    EnumConstantDecl::static_kind(),
    IndirectFieldDecl::static_kind(),
    MSGuidDecl::static_kind(),
    OMPDeclareReductionDecl::static_kind(),
    TemplateParamObjectDecl::static_kind(),
    UnnamedGlobalConstantDecl::static_kind(),
    UnresolvedUsingValueDecl::static_kind(),
    OMPDeclareMapperDecl::static_kind(),
    FieldDecl::static_kind(),
    FunctionDecl::static_kind(),
    MSPropertyDecl::static_kind(),
    NonTypeTemplateParmDecl::static_kind(),
    VarDecl::static_kind(),
    ObjCAtDefsFieldDecl::static_kind(),
    ObjCIvarDecl::static_kind(),
    CXXDeductionGuideDecl::static_kind(),
    CXXMethodDecl::static_kind(),
    VarTemplateSpecializationDecl::static_kind(),
    DecompositionDecl::static_kind(),
    ImplicitParamDecl::static_kind(),
    OMPCapturedExprDecl::static_kind(),
    ParmVarDecl::static_kind(),
    CXXConstructorDecl::static_kind(),
    CXXConversionDecl::static_kind(),
    CXXDestructorDecl::static_kind(),
    VarTemplatePartialSpecializationDecl::static_kind(),
};

std::optional<ValueDecl> ValueDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case BindingDecl::static_kind():
    case EnumConstantDecl::static_kind():
    case IndirectFieldDecl::static_kind():
    case MSGuidDecl::static_kind():
    case OMPDeclareReductionDecl::static_kind():
    case TemplateParamObjectDecl::static_kind():
    case UnnamedGlobalConstantDecl::static_kind():
    case UnresolvedUsingValueDecl::static_kind():
    case OMPDeclareMapperDecl::static_kind():
    case FieldDecl::static_kind():
    case FunctionDecl::static_kind():
    case MSPropertyDecl::static_kind():
    case NonTypeTemplateParmDecl::static_kind():
    case VarDecl::static_kind():
    case ObjCAtDefsFieldDecl::static_kind():
    case ObjCIvarDecl::static_kind():
    case CXXDeductionGuideDecl::static_kind():
    case CXXMethodDecl::static_kind():
    case VarTemplateSpecializationDecl::static_kind():
    case DecompositionDecl::static_kind():
    case ImplicitParamDecl::static_kind():
    case OMPCapturedExprDecl::static_kind():
    case ParmVarDecl::static_kind():
    case CXXConstructorDecl::static_kind():
    case CXXConversionDecl::static_kind():
    case CXXDestructorDecl::static_kind():
    case VarTemplatePartialSpecializationDecl::static_kind():
      return reinterpret_cast<const ValueDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ValueDecl> ValueDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kValueDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ValueDecl> e = ValueDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ValueDecl> ValueDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kValueDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ValueDecl> e = ValueDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ValueDecl> ValueDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kValueDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ValueDecl> e = ValueDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ValueDecl> ValueDecl::from(const Reference &r) {
  return ValueDecl::from(r.as_declaration());
}

std::optional<ValueDecl> ValueDecl::from(const TokenContext &t) {
  return ValueDecl::from(t.as_declaration());
}

std::optional<VarDecl> ValueDecl::potentially_decomposed_variable_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal54();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return VarDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

Type ValueDecl::type(void) const {
  RawEntityId eid = impl->reader.getVal55();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool ValueDecl::is_initializer_capture(void) const {
  return impl->reader.getVal72();
}

bool ValueDecl::is_weak(void) const {
  return impl->reader.getVal73();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
