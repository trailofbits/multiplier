// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/FullExpr.h>

#include <multiplier/Entities/ConstantExpr.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/ExprWithCleanups.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<FullExpr> FullExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = FullExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool FullExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : FullExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<FullExpr> FullExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = FullExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<FullExpr> FullExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<FullExpr> FullExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = FullExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<FullExpr> FullExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool FullExpr::contains(const Decl &decl) {
  for (auto &parent : FullExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool FullExpr::contains(const Stmt &stmt) {
  for (auto &parent : FullExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<FullExpr> FullExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return FullExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kFullExprDerivedKinds[] = {
    ConstantExpr::static_kind(),
    ExprWithCleanups::static_kind(),
};

std::optional<FullExpr> FullExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ConstantExpr::static_kind():
    case ExprWithCleanups::static_kind():
      return reinterpret_cast<const FullExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<FullExpr> FullExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kFullExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<FullExpr> e = FullExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FullExpr> FullExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kFullExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<FullExpr> e = FullExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FullExpr> FullExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kFullExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<FullExpr> e = FullExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<FullExpr> FullExpr::from(const Reference &r) {
  return FullExpr::from(r.as_statement());
}

std::optional<FullExpr> FullExpr::from(const TokenContext &t) {
  return FullExpr::from(t.as_statement());
}

Expr FullExpr::sub_expression(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
