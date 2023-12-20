// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ExpressionTraitExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueStmt.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kExpressionTraitExprDerivedKinds[] = {
    ExpressionTraitExpr::static_kind(),
};
}  // namespace

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

std::optional<ExpressionTraitExpr> ExpressionTraitExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<ExpressionTraitExpr, ir::Operation>> ExpressionTraitExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kExpressionTraitExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<ExpressionTraitExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
    if (auto base = index.statement(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<ExpressionTraitExpr> ExpressionTraitExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ExpressionTraitExpr> ExpressionTraitExpr::from_base(const Stmt &parent) {
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
      if (std::optional<ExpressionTraitExpr> e = from_base(std::move(eptr))) {
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
      if (std::optional<ExpressionTraitExpr> e = from_base(std::move(eptr))) {
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
        if (std::optional<ExpressionTraitExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ExpressionTraitExpr> ExpressionTraitExpr::from(const Reference &r) {
  return ExpressionTraitExpr::from(r.as_statement());
}

std::optional<ExpressionTraitExpr> ExpressionTraitExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<ExpressionTraitExpr> ExpressionTraitExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Expr ExpressionTraitExpr::queried_expression(void) const {
  RawEntityId eid = impl->reader.getVal37();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

ExpressionTrait ExpressionTraitExpr::trait(void) const {
  return static_cast<ExpressionTrait>(impl->reader.getVal95());
}

bool ExpressionTraitExpr::value(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
