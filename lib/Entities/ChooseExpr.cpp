// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ChooseExpr.h>

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

gap::generator<ChooseExpr> ChooseExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ChooseExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ChooseExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ChooseExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ChooseExpr> ChooseExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ChooseExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ChooseExpr> ChooseExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ChooseExpr> ChooseExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ChooseExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ChooseExpr> ChooseExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ChooseExpr::contains(const Decl &decl) {
  for (auto &parent : ChooseExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ChooseExpr::contains(const Stmt &stmt) {
  for (auto &parent : ChooseExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ChooseExpr> ChooseExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<ChooseExpr> ChooseExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kChooseExprDerivedKinds[] = {
    ChooseExpr::static_kind(),
};

}  // namespace

std::optional<ChooseExpr> ChooseExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case ChooseExpr::static_kind():
      return reinterpret_cast<const ChooseExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ChooseExpr> ChooseExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kChooseExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ChooseExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ChooseExpr> ChooseExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kChooseExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ChooseExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ChooseExpr> ChooseExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kChooseExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ChooseExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ChooseExpr> ChooseExpr::from(const Reference &r) {
  return ChooseExpr::from(r.as_statement());
}

std::optional<ChooseExpr> ChooseExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<ChooseExpr> ChooseExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token ChooseExpr::builtin_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal37());
}

Expr ChooseExpr::chosen_sub_expression(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr ChooseExpr::condition(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr ChooseExpr::lhs(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr ChooseExpr::rhs(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Token ChooseExpr::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal42());
}

bool ChooseExpr::is_condition_dependent(void) const {
  return impl->reader.getVal89();
}

bool ChooseExpr::is_condition_true(void) const {
  return impl->reader.getVal90();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
