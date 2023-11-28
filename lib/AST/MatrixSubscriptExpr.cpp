// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/MatrixSubscriptExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<MatrixSubscriptExpr> MatrixSubscriptExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = MatrixSubscriptExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool MatrixSubscriptExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : MatrixSubscriptExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<MatrixSubscriptExpr> MatrixSubscriptExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = MatrixSubscriptExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<MatrixSubscriptExpr> MatrixSubscriptExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<MatrixSubscriptExpr> MatrixSubscriptExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = MatrixSubscriptExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<MatrixSubscriptExpr> MatrixSubscriptExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool MatrixSubscriptExpr::contains(const Decl &decl) {
  for (auto &parent : MatrixSubscriptExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool MatrixSubscriptExpr::contains(const Stmt &stmt) {
  for (auto &parent : MatrixSubscriptExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<MatrixSubscriptExpr> MatrixSubscriptExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<MatrixSubscriptExpr> MatrixSubscriptExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kMatrixSubscriptExprDerivedKinds[] = {
    MatrixSubscriptExpr::static_kind(),
};

}  // namespace

std::optional<MatrixSubscriptExpr> MatrixSubscriptExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case MatrixSubscriptExpr::static_kind():
      return reinterpret_cast<const MatrixSubscriptExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<MatrixSubscriptExpr> MatrixSubscriptExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kMatrixSubscriptExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<MatrixSubscriptExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MatrixSubscriptExpr> MatrixSubscriptExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kMatrixSubscriptExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<MatrixSubscriptExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MatrixSubscriptExpr> MatrixSubscriptExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kMatrixSubscriptExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<MatrixSubscriptExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<MatrixSubscriptExpr> MatrixSubscriptExpr::from(const Reference &r) {
  return MatrixSubscriptExpr::from(r.as_statement());
}

std::optional<MatrixSubscriptExpr> MatrixSubscriptExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<MatrixSubscriptExpr> MatrixSubscriptExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Expr MatrixSubscriptExpr::base(void) const {
  RawEntityId eid = impl->reader.getVal37();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr MatrixSubscriptExpr::column_index(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Token MatrixSubscriptExpr::r_bracket_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

Expr MatrixSubscriptExpr::row_index(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

bool MatrixSubscriptExpr::is_incomplete(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
