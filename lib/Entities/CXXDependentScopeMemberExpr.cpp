// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXDependentScopeMemberExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXDependentScopeMemberExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXDependentScopeMemberExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXDependentScopeMemberExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXDependentScopeMemberExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXDependentScopeMemberExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXDependentScopeMemberExpr::contains(const Decl &decl) {
  for (auto &parent : CXXDependentScopeMemberExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXDependentScopeMemberExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXDependentScopeMemberExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CXXDependentScopeMemberExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCXXDependentScopeMemberExprDerivedKinds[] = {
    CXXDependentScopeMemberExpr::static_kind(),
};

std::optional<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXDependentScopeMemberExpr::static_kind():
      return reinterpret_cast<const CXXDependentScopeMemberExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXDependentScopeMemberExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXDependentScopeMemberExpr> e = CXXDependentScopeMemberExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXDependentScopeMemberExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXDependentScopeMemberExpr> e = CXXDependentScopeMemberExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXDependentScopeMemberExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXDependentScopeMemberExpr> e = CXXDependentScopeMemberExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::from(const Reference &r) {
  return CXXDependentScopeMemberExpr::from(r.as_statement());
}

std::optional<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::from(const TokenContext &t) {
  return CXXDependentScopeMemberExpr::from(t.as_statement());
}

std::optional<Expr> CXXDependentScopeMemberExpr::base(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal38();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

Type CXXDependentScopeMemberExpr::base_type(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<NamedDecl> CXXDependentScopeMemberExpr::first_qualifier_found_in_scope(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal40();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return NamedDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

Token CXXDependentScopeMemberExpr::l_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal41());
}

Token CXXDependentScopeMemberExpr::member_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal42());
}

Token CXXDependentScopeMemberExpr::operator_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal43());
}

Token CXXDependentScopeMemberExpr::r_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal44());
}

Token CXXDependentScopeMemberExpr::template_keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal45());
}

bool CXXDependentScopeMemberExpr::has_explicit_template_arguments(void) const {
  return impl->reader.getVal89();
}

bool CXXDependentScopeMemberExpr::has_template_keyword(void) const {
  return impl->reader.getVal90();
}

bool CXXDependentScopeMemberExpr::is_arrow(void) const {
  return impl->reader.getVal91();
}

bool CXXDependentScopeMemberExpr::is_implicit_access(void) const {
  return impl->reader.getVal92();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
