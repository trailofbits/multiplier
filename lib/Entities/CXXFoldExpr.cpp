// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXFoldExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/UnresolvedLookupExpr.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CXXFoldExpr> CXXFoldExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXFoldExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXFoldExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXFoldExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXFoldExpr> CXXFoldExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXFoldExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXFoldExpr> CXXFoldExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXFoldExpr> CXXFoldExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXFoldExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXFoldExpr> CXXFoldExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXFoldExpr::contains(const Decl &decl) {
  for (auto &parent : CXXFoldExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXFoldExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXFoldExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXFoldExpr> CXXFoldExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CXXFoldExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCXXFoldExprDerivedKinds[] = {
    CXXFoldExpr::static_kind(),
};

std::optional<CXXFoldExpr> CXXFoldExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXFoldExpr::static_kind():
      return reinterpret_cast<const CXXFoldExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXFoldExpr> CXXFoldExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kCXXFoldExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXFoldExpr> e = CXXFoldExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXFoldExpr> CXXFoldExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXFoldExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXFoldExpr> e = CXXFoldExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXFoldExpr> CXXFoldExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXFoldExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXFoldExpr> e = CXXFoldExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXFoldExpr> CXXFoldExpr::from(const Reference &r) {
  return CXXFoldExpr::from(r.as_statement());
}

std::optional<CXXFoldExpr> CXXFoldExpr::from(const TokenContext &t) {
  return CXXFoldExpr::from(t.as_statement());
}

UnresolvedLookupExpr CXXFoldExpr::callee(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return UnresolvedLookupExpr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token CXXFoldExpr::ellipsis_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

Expr CXXFoldExpr::initializer(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr CXXFoldExpr::lhs(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token CXXFoldExpr::l_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal42());
}

BinaryOperatorKind CXXFoldExpr::operator_(void) const {
  return static_cast<BinaryOperatorKind>(impl->reader.getVal94());
}

Expr CXXFoldExpr::pattern(void) const {
  RawEntityId eid = impl->reader.getVal43();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr CXXFoldExpr::rhs(void) const {
  RawEntityId eid = impl->reader.getVal44();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token CXXFoldExpr::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal45());
}

bool CXXFoldExpr::is_left_fold(void) const {
  return impl->reader.getVal89();
}

bool CXXFoldExpr::is_right_fold(void) const {
  return impl->reader.getVal90();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
