// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXUnresolvedConstructExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXUnresolvedConstructExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXUnresolvedConstructExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXUnresolvedConstructExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXUnresolvedConstructExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXUnresolvedConstructExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXUnresolvedConstructExpr::contains(const Decl &decl) {
  for (auto &parent : CXXUnresolvedConstructExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool CXXUnresolvedConstructExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXUnresolvedConstructExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CXXUnresolvedConstructExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCXXUnresolvedConstructExprDerivedKinds[] = {
    CXXUnresolvedConstructExpr::static_kind(),
};

std::optional<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXUnresolvedConstructExpr::static_kind():
      return reinterpret_cast<const CXXUnresolvedConstructExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kCXXUnresolvedConstructExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXUnresolvedConstructExpr> e = CXXUnresolvedConstructExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXUnresolvedConstructExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXUnresolvedConstructExpr> e = CXXUnresolvedConstructExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXUnresolvedConstructExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXUnresolvedConstructExpr> e = CXXUnresolvedConstructExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<Expr> CXXUnresolvedConstructExpr::nth_argument(unsigned n) const {
  auto list = impl->reader.getVal15();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from(Stmt(std::move(e)));
}

gap::generator<Expr> CXXUnresolvedConstructExpr::arguments(void) const & {
  auto list = impl->reader.getVal15();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from(Stmt(std::move(d15)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

Token CXXUnresolvedConstructExpr::l_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

Token CXXUnresolvedConstructExpr::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

Type CXXUnresolvedConstructExpr::type_as_written(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool CXXUnresolvedConstructExpr::is_list_initialization(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
