// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXConstructExpr.h>

#include <multiplier/Entities/CXXConstructorDecl.h>
#include <multiplier/Entities/CXXTemporaryObjectExpr.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Fragment.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CXXConstructExpr> CXXConstructExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXConstructExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXConstructExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXConstructExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXConstructExpr> CXXConstructExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXConstructExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXConstructExpr> CXXConstructExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXConstructExpr> CXXConstructExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXConstructExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXConstructExpr> CXXConstructExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXConstructExpr::contains(const Decl &decl) {
  for (auto &parent : CXXConstructExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXConstructExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXConstructExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXConstructExpr> CXXConstructExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    if (auto base = index.statement(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<CXXConstructExpr> CXXConstructExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kCXXConstructExprDerivedKinds[] = {
    CXXConstructExpr::static_kind(),
    CXXTemporaryObjectExpr::static_kind(),
};

}  // namespace

std::optional<CXXConstructExpr> CXXConstructExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXConstructExpr::static_kind():
    case CXXTemporaryObjectExpr::static_kind():
      return reinterpret_cast<const CXXConstructExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXConstructExpr> CXXConstructExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXConstructExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXConstructExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXConstructExpr> CXXConstructExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXConstructExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXConstructExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXConstructExpr> CXXConstructExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXConstructExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXConstructExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXConstructExpr> CXXConstructExpr::from(const Reference &r) {
  return CXXConstructExpr::from(r.as_statement());
}

std::optional<CXXConstructExpr> CXXConstructExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<CXXConstructExpr> CXXConstructExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

unsigned CXXConstructExpr::num_arguments(void) const {
  return impl->reader.getVal15().size();
}

std::optional<Expr> CXXConstructExpr::nth_argument(unsigned n) const {
  auto list = impl->reader.getVal15();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from_base(std::move(e));
}

gap::generator<Expr> CXXConstructExpr::arguments(void) const & {
  auto list = impl->reader.getVal15();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from_base(std::move(d15))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

CXXConstructExprConstructionKind CXXConstructExpr::construction_kind(void) const {
  return static_cast<CXXConstructExprConstructionKind>(impl->reader.getVal95());
}

CXXConstructorDecl CXXConstructExpr::constructor(void) const {
  RawEntityId eid = impl->reader.getVal37();
  return CXXConstructorDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Token CXXConstructExpr::token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

TokenRange CXXConstructExpr::parenthesis_or_brace_range(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal39(), impl->reader.getVal40());
}

bool CXXConstructExpr::had_multiple_candidates(void) const {
  return impl->reader.getVal89();
}

bool CXXConstructExpr::is_elidable(void) const {
  return impl->reader.getVal90();
}

bool CXXConstructExpr::is_immediate_escalating(void) const {
  return impl->reader.getVal91();
}

bool CXXConstructExpr::is_list_initialization(void) const {
  return impl->reader.getVal92();
}

bool CXXConstructExpr::is_std_initializer_list_initialization(void) const {
  return impl->reader.getVal93();
}

bool CXXConstructExpr::requires_zero_initialization(void) const {
  return impl->reader.getVal94();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
