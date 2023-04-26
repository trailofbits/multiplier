// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXDefaultArgExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/ParmVarDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CXXDefaultArgExpr> CXXDefaultArgExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXDefaultArgExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXDefaultArgExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXDefaultArgExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXDefaultArgExpr> CXXDefaultArgExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXDefaultArgExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXDefaultArgExpr> CXXDefaultArgExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXDefaultArgExpr> CXXDefaultArgExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXDefaultArgExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXDefaultArgExpr> CXXDefaultArgExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXDefaultArgExpr::contains(const Decl &decl) {
  for (auto &parent : CXXDefaultArgExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXDefaultArgExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXDefaultArgExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXDefaultArgExpr> CXXDefaultArgExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CXXDefaultArgExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCXXDefaultArgExprDerivedKinds[] = {
    CXXDefaultArgExpr::static_kind(),
};

std::optional<CXXDefaultArgExpr> CXXDefaultArgExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXDefaultArgExpr::static_kind():
      return reinterpret_cast<const CXXDefaultArgExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXDefaultArgExpr> CXXDefaultArgExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kCXXDefaultArgExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXDefaultArgExpr> e = CXXDefaultArgExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXDefaultArgExpr> CXXDefaultArgExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXDefaultArgExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXDefaultArgExpr> e = CXXDefaultArgExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXDefaultArgExpr> CXXDefaultArgExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXDefaultArgExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXDefaultArgExpr> e = CXXDefaultArgExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXDefaultArgExpr> CXXDefaultArgExpr::from(const Reference &r) {
  return CXXDefaultArgExpr::from(r.as_statement());
}

std::optional<CXXDefaultArgExpr> CXXDefaultArgExpr::from(const TokenContext &t) {
  return CXXDefaultArgExpr::from(t.as_statement());
}

Expr CXXDefaultArgExpr::adjusted_rewritten_expression(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr CXXDefaultArgExpr::expression(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

ParmVarDecl CXXDefaultArgExpr::parameter(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return ParmVarDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Expr CXXDefaultArgExpr::rewritten_expression(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token CXXDefaultArgExpr::used_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal42());
}

bool CXXDefaultArgExpr::has_rewritten_initializer(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
