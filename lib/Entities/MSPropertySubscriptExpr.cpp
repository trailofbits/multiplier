// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MSPropertySubscriptExpr.h>

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

gap::generator<MSPropertySubscriptExpr> MSPropertySubscriptExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = MSPropertySubscriptExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool MSPropertySubscriptExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : MSPropertySubscriptExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<MSPropertySubscriptExpr> MSPropertySubscriptExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = MSPropertySubscriptExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<MSPropertySubscriptExpr> MSPropertySubscriptExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<MSPropertySubscriptExpr> MSPropertySubscriptExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = MSPropertySubscriptExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<MSPropertySubscriptExpr> MSPropertySubscriptExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool MSPropertySubscriptExpr::contains(const Decl &decl) {
  for (auto &parent : MSPropertySubscriptExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool MSPropertySubscriptExpr::contains(const Stmt &stmt) {
  for (auto &parent : MSPropertySubscriptExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<MSPropertySubscriptExpr> MSPropertySubscriptExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return MSPropertySubscriptExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kMSPropertySubscriptExprDerivedKinds[] = {
    MSPropertySubscriptExpr::static_kind(),
};

std::optional<MSPropertySubscriptExpr> MSPropertySubscriptExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case MSPropertySubscriptExpr::static_kind():
      return reinterpret_cast<const MSPropertySubscriptExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<MSPropertySubscriptExpr> MSPropertySubscriptExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kMSPropertySubscriptExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<MSPropertySubscriptExpr> e = MSPropertySubscriptExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MSPropertySubscriptExpr> MSPropertySubscriptExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kMSPropertySubscriptExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<MSPropertySubscriptExpr> e = MSPropertySubscriptExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MSPropertySubscriptExpr> MSPropertySubscriptExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kMSPropertySubscriptExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<MSPropertySubscriptExpr> e = MSPropertySubscriptExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<MSPropertySubscriptExpr> MSPropertySubscriptExpr::from(const Reference &r) {
  return MSPropertySubscriptExpr::from(r.as_statement());
}

std::optional<MSPropertySubscriptExpr> MSPropertySubscriptExpr::from(const TokenContext &t) {
  return MSPropertySubscriptExpr::from(t.as_statement());
}

Expr MSPropertySubscriptExpr::base(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr MSPropertySubscriptExpr::index(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token MSPropertySubscriptExpr::r_bracket_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
