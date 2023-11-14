// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CoyieldExpr.h>

#include <multiplier/Entities/CoroutineSuspendExpr.h>
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

gap::generator<CoyieldExpr> CoyieldExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CoyieldExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CoyieldExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CoyieldExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CoyieldExpr> CoyieldExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CoyieldExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CoyieldExpr> CoyieldExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CoyieldExpr> CoyieldExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CoyieldExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CoyieldExpr> CoyieldExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CoyieldExpr::contains(const Decl &decl) {
  for (auto &parent : CoyieldExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CoyieldExpr::contains(const Stmt &stmt) {
  for (auto &parent : CoyieldExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CoyieldExpr> CoyieldExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<CoyieldExpr> CoyieldExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kCoyieldExprDerivedKinds[] = {
    CoyieldExpr::static_kind(),
};

}  // namespace

std::optional<CoyieldExpr> CoyieldExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case CoyieldExpr::static_kind():
      return reinterpret_cast<const CoyieldExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CoyieldExpr> CoyieldExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCoyieldExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CoyieldExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CoyieldExpr> CoyieldExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCoyieldExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CoyieldExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CoyieldExpr> CoyieldExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCoyieldExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CoyieldExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CoyieldExpr> CoyieldExpr::from(const Reference &r) {
  return CoyieldExpr::from(r.as_statement());
}

std::optional<CoyieldExpr> CoyieldExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<CoyieldExpr> CoyieldExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
