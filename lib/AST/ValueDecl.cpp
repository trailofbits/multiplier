// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ValueDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/VarDecl.h>
#include <multiplier/AST/BindingDecl.h>
#include <multiplier/AST/CXXConstructorDecl.h>
#include <multiplier/AST/CXXConversionDecl.h>
#include <multiplier/AST/CXXDeductionGuideDecl.h>
#include <multiplier/AST/CXXDestructorDecl.h>
#include <multiplier/AST/CXXMethodDecl.h>
#include <multiplier/AST/DecompositionDecl.h>
#include <multiplier/AST/EnumConstantDecl.h>
#include <multiplier/AST/FieldDecl.h>
#include <multiplier/AST/FunctionDecl.h>
#include <multiplier/AST/ImplicitParamDecl.h>
#include <multiplier/AST/IndirectFieldDecl.h>
#include <multiplier/AST/MSGuidDecl.h>
#include <multiplier/AST/MSPropertyDecl.h>
#include <multiplier/AST/NonTypeTemplateParmDecl.h>
#include <multiplier/AST/OMPCapturedExprDecl.h>
#include <multiplier/AST/OMPDeclareMapperDecl.h>
#include <multiplier/AST/OMPDeclareReductionDecl.h>
#include <multiplier/AST/ObjCAtDefsFieldDecl.h>
#include <multiplier/AST/ObjCIvarDecl.h>
#include <multiplier/AST/ParmVarDecl.h>
#include <multiplier/AST/TemplateParamObjectDecl.h>
#include <multiplier/AST/UnnamedGlobalConstantDecl.h>
#include <multiplier/AST/UnresolvedUsingValueDecl.h>
#include <multiplier/AST/VarDecl.h>
#include <multiplier/AST/VarTemplatePartialSpecializationDecl.h>
#include <multiplier/AST/VarTemplateSpecializationDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
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
}  // namespace

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

std::optional<ValueDecl> ValueDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<ValueDecl, ir::Operation>> ValueDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kValueDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<ValueDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ValueDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ValueDecl> ValueDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<ValueDecl> ValueDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ValueDecl> dr = from_base(r)) {
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
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<ValueDecl> ValueDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ValueDecl> ValueDecl::from_base(const Decl &parent) {
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
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kValueDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ValueDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ValueDecl> ValueDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kValueDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ValueDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ValueDecl> ValueDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kValueDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ValueDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ValueDecl> ValueDecl::from(const Reference &r) {
  return ValueDecl::from(r.as_declaration());
}

std::optional<ValueDecl> ValueDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<ValueDecl> ValueDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<VarDecl> ValueDecl::potentially_decomposed_variable_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal55();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return VarDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

Type ValueDecl::type(void) const {
  RawEntityId eid = impl->reader.getVal56();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool ValueDecl::is_initializer_capture(void) const {
  return impl->reader.getVal74();
}

bool ValueDecl::is_weak(void) const {
  return impl->reader.getVal75();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
