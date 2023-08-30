// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/GenericSelectionExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<GenericSelectionExpr> GenericSelectionExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = GenericSelectionExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool GenericSelectionExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : GenericSelectionExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<GenericSelectionExpr> GenericSelectionExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = GenericSelectionExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<GenericSelectionExpr> GenericSelectionExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<GenericSelectionExpr> GenericSelectionExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = GenericSelectionExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<GenericSelectionExpr> GenericSelectionExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool GenericSelectionExpr::contains(const Decl &decl) {
  for (auto &parent : GenericSelectionExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool GenericSelectionExpr::contains(const Stmt &stmt) {
  for (auto &parent : GenericSelectionExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<GenericSelectionExpr> GenericSelectionExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return GenericSelectionExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kGenericSelectionExprDerivedKinds[] = {
    GenericSelectionExpr::static_kind(),
};

std::optional<GenericSelectionExpr> GenericSelectionExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case GenericSelectionExpr::static_kind():
      return reinterpret_cast<const GenericSelectionExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<GenericSelectionExpr> GenericSelectionExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kGenericSelectionExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<GenericSelectionExpr> e = GenericSelectionExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<GenericSelectionExpr> GenericSelectionExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kGenericSelectionExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<GenericSelectionExpr> e = GenericSelectionExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<GenericSelectionExpr> GenericSelectionExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kGenericSelectionExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<GenericSelectionExpr> e = GenericSelectionExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<GenericSelectionExpr> GenericSelectionExpr::from(const Reference &r) {
  return GenericSelectionExpr::from(r.as_statement());
}

std::optional<GenericSelectionExpr> GenericSelectionExpr::from(const TokenContext &t) {
  return GenericSelectionExpr::from(t.as_statement());
}

unsigned GenericSelectionExpr::num_association_expressions(void) const {
  return impl->reader.getVal15().size();
}

std::optional<Expr> GenericSelectionExpr::nth_association_expression(unsigned n) const {
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
  return Expr::from(Stmt(std::move(e)));
}

gap::generator<Expr> GenericSelectionExpr::association_expressions(void) const & {
  auto list = impl->reader.getVal15();
  EntityProviderPtr ep = impl->ep;
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

Expr GenericSelectionExpr::controlling_expression(void) const {
  RawEntityId eid = impl->reader.getVal37();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token GenericSelectionExpr::default_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

Token GenericSelectionExpr::generic_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

Token GenericSelectionExpr::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

Expr GenericSelectionExpr::result_expression(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

bool GenericSelectionExpr::is_result_dependent(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
