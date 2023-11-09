// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXPseudoDestructorExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
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

gap::generator<CXXPseudoDestructorExpr> CXXPseudoDestructorExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXPseudoDestructorExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXPseudoDestructorExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXPseudoDestructorExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXPseudoDestructorExpr> CXXPseudoDestructorExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXPseudoDestructorExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXPseudoDestructorExpr> CXXPseudoDestructorExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXPseudoDestructorExpr> CXXPseudoDestructorExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXPseudoDestructorExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXPseudoDestructorExpr> CXXPseudoDestructorExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXPseudoDestructorExpr::contains(const Decl &decl) {
  for (auto &parent : CXXPseudoDestructorExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXPseudoDestructorExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXPseudoDestructorExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXPseudoDestructorExpr> CXXPseudoDestructorExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CXXPseudoDestructorExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCXXPseudoDestructorExprDerivedKinds[] = {
    CXXPseudoDestructorExpr::static_kind(),
};

std::optional<CXXPseudoDestructorExpr> CXXPseudoDestructorExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXPseudoDestructorExpr::static_kind():
      return reinterpret_cast<const CXXPseudoDestructorExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXPseudoDestructorExpr> CXXPseudoDestructorExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXPseudoDestructorExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXPseudoDestructorExpr> e = CXXPseudoDestructorExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXPseudoDestructorExpr> CXXPseudoDestructorExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXPseudoDestructorExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXPseudoDestructorExpr> e = CXXPseudoDestructorExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXPseudoDestructorExpr> CXXPseudoDestructorExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXPseudoDestructorExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXPseudoDestructorExpr> e = CXXPseudoDestructorExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXPseudoDestructorExpr> CXXPseudoDestructorExpr::from(const Reference &r) {
  return CXXPseudoDestructorExpr::from(r.as_statement());
}

std::optional<CXXPseudoDestructorExpr> CXXPseudoDestructorExpr::from(const TokenContext &t) {
  return CXXPseudoDestructorExpr::from(t.as_statement());
}

Expr CXXPseudoDestructorExpr::base(void) const {
  RawEntityId eid = impl->reader.getVal37();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token CXXPseudoDestructorExpr::colon_colon_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

Type CXXPseudoDestructorExpr::destroyed_type(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Token CXXPseudoDestructorExpr::destroyed_type_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

Token CXXPseudoDestructorExpr::operator_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal41());
}

std::optional<Type> CXXPseudoDestructorExpr::scope_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal42();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token CXXPseudoDestructorExpr::tilde_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal43());
}

bool CXXPseudoDestructorExpr::has_qualifier(void) const {
  return impl->reader.getVal87();
}

bool CXXPseudoDestructorExpr::is_arrow(void) const {
  return impl->reader.getVal88();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
