// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/DeclaratorDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/TemplateParameterList.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueDecl.h>
#include <multiplier/AST/CXXConstructorDecl.h>
#include <multiplier/AST/CXXConversionDecl.h>
#include <multiplier/AST/CXXDeductionGuideDecl.h>
#include <multiplier/AST/CXXDestructorDecl.h>
#include <multiplier/AST/CXXMethodDecl.h>
#include <multiplier/AST/DecompositionDecl.h>
#include <multiplier/AST/FieldDecl.h>
#include <multiplier/AST/FunctionDecl.h>
#include <multiplier/AST/ImplicitParamDecl.h>
#include <multiplier/AST/MSPropertyDecl.h>
#include <multiplier/AST/NonTypeTemplateParmDecl.h>
#include <multiplier/AST/OMPCapturedExprDecl.h>
#include <multiplier/AST/ObjCAtDefsFieldDecl.h>
#include <multiplier/AST/ObjCIvarDecl.h>
#include <multiplier/AST/ParmVarDecl.h>
#include <multiplier/AST/VarDecl.h>
#include <multiplier/AST/VarTemplatePartialSpecializationDecl.h>
#include <multiplier/AST/VarTemplateSpecializationDecl.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<DeclaratorDecl> DeclaratorDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DeclaratorDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DeclaratorDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DeclaratorDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<DeclaratorDecl> DeclaratorDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = DeclaratorDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<DeclaratorDecl> DeclaratorDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<DeclaratorDecl> DeclaratorDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = DeclaratorDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<DeclaratorDecl> DeclaratorDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool DeclaratorDecl::contains(const Decl &decl) {
  for (auto &parent : DeclaratorDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool DeclaratorDecl::contains(const Stmt &stmt) {
  for (auto &parent : DeclaratorDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

DeclaratorDecl DeclaratorDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (DeclaratorDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<DeclaratorDecl> DeclaratorDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<DeclaratorDecl> DeclaratorDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<DeclaratorDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<DeclaratorDecl> DeclaratorDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<DeclaratorDecl> DeclaratorDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const DeclKind kDeclaratorDeclDerivedKinds[] = {
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

std::optional<DeclaratorDecl> DeclaratorDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
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
      return reinterpret_cast<const DeclaratorDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DeclaratorDecl> DeclaratorDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kDeclaratorDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<DeclaratorDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DeclaratorDecl> DeclaratorDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kDeclaratorDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<DeclaratorDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DeclaratorDecl> DeclaratorDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kDeclaratorDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<DeclaratorDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<DeclaratorDecl> DeclaratorDecl::from(const Reference &r) {
  return DeclaratorDecl::from(r.as_declaration());
}

std::optional<DeclaratorDecl> DeclaratorDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<DeclaratorDecl> DeclaratorDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token DeclaratorDecl::first_inner_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal58());
}

Token DeclaratorDecl::first_outer_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal66());
}

std::optional<Expr> DeclaratorDecl::trailing_requires_clause(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal67();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token DeclaratorDecl::type_spec_end_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal68());
}

Token DeclaratorDecl::type_spec_start_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal78());
}

unsigned DeclaratorDecl::num_template_parameter_lists(void) const {
  return impl->reader.getVal51().size();
}

std::optional<TemplateParameterList> DeclaratorDecl::nth_template_parameter_list(unsigned n) const {
  auto list = impl->reader.getVal51();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TemplateParameterListFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return TemplateParameterList(std::move(e));
}

gap::generator<TemplateParameterList> DeclaratorDecl::template_parameter_lists(void) const & {
  auto list = impl->reader.getVal51();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d51 = ep->TemplateParameterListFor(ep, v)) {
      co_yield TemplateParameterList(std::move(d51));
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
