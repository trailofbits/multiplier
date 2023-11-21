// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CompoundLiteralExpr.h>

#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/Token.h>
#include <multiplier/AST/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CompoundLiteralExpr> CompoundLiteralExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CompoundLiteralExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CompoundLiteralExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CompoundLiteralExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CompoundLiteralExpr> CompoundLiteralExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CompoundLiteralExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CompoundLiteralExpr> CompoundLiteralExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CompoundLiteralExpr> CompoundLiteralExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CompoundLiteralExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CompoundLiteralExpr> CompoundLiteralExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CompoundLiteralExpr::contains(const Decl &decl) {
  for (auto &parent : CompoundLiteralExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CompoundLiteralExpr::contains(const Stmt &stmt) {
  for (auto &parent : CompoundLiteralExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CompoundLiteralExpr> CompoundLiteralExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<CompoundLiteralExpr> CompoundLiteralExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kCompoundLiteralExprDerivedKinds[] = {
    CompoundLiteralExpr::static_kind(),
};

}  // namespace

std::optional<CompoundLiteralExpr> CompoundLiteralExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case CompoundLiteralExpr::static_kind():
      return reinterpret_cast<const CompoundLiteralExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CompoundLiteralExpr> CompoundLiteralExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCompoundLiteralExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CompoundLiteralExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CompoundLiteralExpr> CompoundLiteralExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCompoundLiteralExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CompoundLiteralExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CompoundLiteralExpr> CompoundLiteralExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCompoundLiteralExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CompoundLiteralExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CompoundLiteralExpr> CompoundLiteralExpr::from(const Reference &r) {
  return CompoundLiteralExpr::from(r.as_statement());
}

std::optional<CompoundLiteralExpr> CompoundLiteralExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<CompoundLiteralExpr> CompoundLiteralExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Expr CompoundLiteralExpr::initializer(void) const {
  RawEntityId eid = impl->reader.getVal37();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Token CompoundLiteralExpr::l_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

bool CompoundLiteralExpr::is_file_scope(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
