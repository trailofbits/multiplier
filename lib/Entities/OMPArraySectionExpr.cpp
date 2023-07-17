// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPArraySectionExpr.h>

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

gap::generator<OMPArraySectionExpr> OMPArraySectionExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPArraySectionExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPArraySectionExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPArraySectionExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPArraySectionExpr> OMPArraySectionExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPArraySectionExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPArraySectionExpr> OMPArraySectionExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPArraySectionExpr> OMPArraySectionExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPArraySectionExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPArraySectionExpr> OMPArraySectionExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPArraySectionExpr::contains(const Decl &decl) {
  for (auto &parent : OMPArraySectionExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPArraySectionExpr::contains(const Stmt &stmt) {
  for (auto &parent : OMPArraySectionExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<OMPArraySectionExpr> OMPArraySectionExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return OMPArraySectionExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kOMPArraySectionExprDerivedKinds[] = {
    OMPArraySectionExpr::static_kind(),
};

std::optional<OMPArraySectionExpr> OMPArraySectionExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPArraySectionExpr::static_kind():
      return reinterpret_cast<const OMPArraySectionExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPArraySectionExpr> OMPArraySectionExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kOMPArraySectionExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPArraySectionExpr> e = OMPArraySectionExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPArraySectionExpr> OMPArraySectionExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPArraySectionExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPArraySectionExpr> e = OMPArraySectionExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPArraySectionExpr> OMPArraySectionExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPArraySectionExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPArraySectionExpr> e = OMPArraySectionExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPArraySectionExpr> OMPArraySectionExpr::from(const Reference &r) {
  return OMPArraySectionExpr::from(r.as_statement());
}

std::optional<OMPArraySectionExpr> OMPArraySectionExpr::from(const TokenContext &t) {
  return OMPArraySectionExpr::from(t.as_statement());
}

Expr OMPArraySectionExpr::base(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token OMPArraySectionExpr::first_colon_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

Token OMPArraySectionExpr::second_colon_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

Expr OMPArraySectionExpr::length(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr OMPArraySectionExpr::lower_bound(void) const {
  RawEntityId eid = impl->reader.getVal42();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token OMPArraySectionExpr::r_bracket_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal43());
}

Expr OMPArraySectionExpr::stride(void) const {
  RawEntityId eid = impl->reader.getVal44();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
