// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/AsTypeExpr.h>

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

gap::generator<AsTypeExpr> AsTypeExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = AsTypeExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool AsTypeExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : AsTypeExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<AsTypeExpr> AsTypeExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = AsTypeExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<AsTypeExpr> AsTypeExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<AsTypeExpr> AsTypeExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = AsTypeExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<AsTypeExpr> AsTypeExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool AsTypeExpr::contains(const Decl &decl) {
  for (auto &parent : AsTypeExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool AsTypeExpr::contains(const Stmt &stmt) {
  for (auto &parent : AsTypeExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<AsTypeExpr> AsTypeExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return AsTypeExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kAsTypeExprDerivedKinds[] = {
    AsTypeExpr::static_kind(),
};

std::optional<AsTypeExpr> AsTypeExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case AsTypeExpr::static_kind():
      return reinterpret_cast<const AsTypeExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<AsTypeExpr> AsTypeExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kAsTypeExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<AsTypeExpr> e = AsTypeExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AsTypeExpr> AsTypeExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kAsTypeExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<AsTypeExpr> e = AsTypeExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AsTypeExpr> AsTypeExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kAsTypeExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<AsTypeExpr> e = AsTypeExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<AsTypeExpr> AsTypeExpr::from(const Reference &r) {
  return AsTypeExpr::from(r.as_statement());
}

std::optional<AsTypeExpr> AsTypeExpr::from(const TokenContext &t) {
  return AsTypeExpr::from(t.as_statement());
}

Token AsTypeExpr::builtin_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

Token AsTypeExpr::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

Expr AsTypeExpr::src_expression(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
