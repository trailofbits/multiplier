// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/PseudoObjectExpr.h>

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

gap::generator<PseudoObjectExpr> PseudoObjectExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = PseudoObjectExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool PseudoObjectExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : PseudoObjectExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<PseudoObjectExpr> PseudoObjectExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = PseudoObjectExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<PseudoObjectExpr> PseudoObjectExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<PseudoObjectExpr> PseudoObjectExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = PseudoObjectExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<PseudoObjectExpr> PseudoObjectExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool PseudoObjectExpr::contains(const Decl &decl) {
  for (auto &parent : PseudoObjectExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool PseudoObjectExpr::contains(const Stmt &stmt) {
  for (auto &parent : PseudoObjectExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<PseudoObjectExpr> PseudoObjectExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return PseudoObjectExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kPseudoObjectExprDerivedKinds[] = {
    PseudoObjectExpr::static_kind(),
};

std::optional<PseudoObjectExpr> PseudoObjectExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case PseudoObjectExpr::static_kind():
      return reinterpret_cast<const PseudoObjectExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<PseudoObjectExpr> PseudoObjectExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kPseudoObjectExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<PseudoObjectExpr> e = PseudoObjectExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<PseudoObjectExpr> PseudoObjectExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kPseudoObjectExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<PseudoObjectExpr> e = PseudoObjectExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<PseudoObjectExpr> PseudoObjectExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kPseudoObjectExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<PseudoObjectExpr> e = PseudoObjectExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<PseudoObjectExpr> PseudoObjectExpr::from(const Reference &r) {
  return PseudoObjectExpr::from(r.as_statement());
}

std::optional<PseudoObjectExpr> PseudoObjectExpr::from(const TokenContext &t) {
  return PseudoObjectExpr::from(t.as_statement());
}

Expr PseudoObjectExpr::result_expression(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr PseudoObjectExpr::syntactic_form(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

unsigned PseudoObjectExpr::num_semantics(void) const {
  return impl->reader.getVal16().size();
}

std::optional<Expr> PseudoObjectExpr::nth_semantic(unsigned n) const {
  auto list = impl->reader.getVal16();
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

gap::generator<Expr> PseudoObjectExpr::semantics(void) const & {
  auto list = impl->reader.getVal16();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d16 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from(Stmt(std::move(d16)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned PseudoObjectExpr::num_semantic_expressions(void) const {
  return impl->reader.getVal27().size();
}

std::optional<Expr> PseudoObjectExpr::nth_semantic_expression(unsigned n) const {
  auto list = impl->reader.getVal27();
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

gap::generator<Expr> PseudoObjectExpr::semantic_expressions(void) const & {
  auto list = impl->reader.getVal27();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d27 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from(Stmt(std::move(d27)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
