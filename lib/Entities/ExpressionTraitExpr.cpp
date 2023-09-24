// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ExpressionTraitExpr.h>

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

gap::generator<ExpressionTraitExpr> ExpressionTraitExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ExpressionTraitExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ExpressionTraitExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ExpressionTraitExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ExpressionTraitExpr> ExpressionTraitExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ExpressionTraitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ExpressionTraitExpr> ExpressionTraitExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ExpressionTraitExpr> ExpressionTraitExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ExpressionTraitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ExpressionTraitExpr> ExpressionTraitExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ExpressionTraitExpr::contains(const Decl &decl) {
  for (auto &parent : ExpressionTraitExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ExpressionTraitExpr::contains(const Stmt &stmt) {
  for (auto &parent : ExpressionTraitExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ExpressionTraitExpr> ExpressionTraitExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ExpressionTraitExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kExpressionTraitExprDerivedKinds[] = {
    ExpressionTraitExpr::static_kind(),
};

std::optional<ExpressionTraitExpr> ExpressionTraitExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ExpressionTraitExpr::static_kind():
      return reinterpret_cast<const ExpressionTraitExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ExpressionTraitExpr> ExpressionTraitExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kExpressionTraitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ExpressionTraitExpr> e = ExpressionTraitExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ExpressionTraitExpr> ExpressionTraitExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kExpressionTraitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ExpressionTraitExpr> e = ExpressionTraitExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ExpressionTraitExpr> ExpressionTraitExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kExpressionTraitExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ExpressionTraitExpr> e = ExpressionTraitExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ExpressionTraitExpr> ExpressionTraitExpr::from(const Reference &r) {
  return ExpressionTraitExpr::from(r.as_statement());
}

std::optional<ExpressionTraitExpr> ExpressionTraitExpr::from(const TokenContext &t) {
  return ExpressionTraitExpr::from(t.as_statement());
}

Expr ExpressionTraitExpr::queried_expression(void) const {
  RawEntityId eid = impl->reader.getVal37();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

ExpressionTrait ExpressionTraitExpr::trait(void) const {
  return static_cast<ExpressionTrait>(impl->reader.getVal93());
}

bool ExpressionTraitExpr::value(void) const {
  return impl->reader.getVal87();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
