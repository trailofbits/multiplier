// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ArraySubscriptExpr.h>

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

gap::generator<ArraySubscriptExpr> ArraySubscriptExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ArraySubscriptExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ArraySubscriptExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ArraySubscriptExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ArraySubscriptExpr> ArraySubscriptExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ArraySubscriptExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ArraySubscriptExpr> ArraySubscriptExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ArraySubscriptExpr> ArraySubscriptExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ArraySubscriptExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ArraySubscriptExpr> ArraySubscriptExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ArraySubscriptExpr::contains(const Decl &decl) {
  for (auto &parent : ArraySubscriptExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ArraySubscriptExpr::contains(const Stmt &stmt) {
  for (auto &parent : ArraySubscriptExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ArraySubscriptExpr> ArraySubscriptExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ArraySubscriptExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kArraySubscriptExprDerivedKinds[] = {
    ArraySubscriptExpr::static_kind(),
};

std::optional<ArraySubscriptExpr> ArraySubscriptExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ArraySubscriptExpr::static_kind():
      return reinterpret_cast<const ArraySubscriptExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ArraySubscriptExpr> ArraySubscriptExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kArraySubscriptExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ArraySubscriptExpr> e = ArraySubscriptExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ArraySubscriptExpr> ArraySubscriptExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kArraySubscriptExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ArraySubscriptExpr> e = ArraySubscriptExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ArraySubscriptExpr> ArraySubscriptExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kArraySubscriptExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ArraySubscriptExpr> e = ArraySubscriptExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ArraySubscriptExpr> ArraySubscriptExpr::from(const Reference &r) {
  return ArraySubscriptExpr::from(r.as_statement());
}

std::optional<ArraySubscriptExpr> ArraySubscriptExpr::from(const TokenContext &t) {
  return ArraySubscriptExpr::from(t.as_statement());
}

Expr ArraySubscriptExpr::base(void) const {
  RawEntityId eid = impl->reader.getVal37();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr ArraySubscriptExpr::index(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr ArraySubscriptExpr::lhs(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token ArraySubscriptExpr::r_bracket_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

Expr ArraySubscriptExpr::rhs(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
