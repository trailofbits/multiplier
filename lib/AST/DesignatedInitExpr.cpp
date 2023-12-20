// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/DesignatedInitExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Designator.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueStmt.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Fragment.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kDesignatedInitExprDerivedKinds[] = {
    DesignatedInitExpr::static_kind(),
};
}  // namespace

gap::generator<DesignatedInitExpr> DesignatedInitExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DesignatedInitExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DesignatedInitExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DesignatedInitExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<DesignatedInitExpr> DesignatedInitExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<DesignatedInitExpr, ir::Operation>> DesignatedInitExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kDesignatedInitExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<DesignatedInitExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<DesignatedInitExpr> DesignatedInitExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = DesignatedInitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<DesignatedInitExpr> DesignatedInitExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<DesignatedInitExpr> DesignatedInitExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = DesignatedInitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<DesignatedInitExpr> DesignatedInitExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool DesignatedInitExpr::contains(const Decl &decl) {
  for (auto &parent : DesignatedInitExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool DesignatedInitExpr::contains(const Stmt &stmt) {
  for (auto &parent : DesignatedInitExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<DesignatedInitExpr> DesignatedInitExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<DesignatedInitExpr> DesignatedInitExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<DesignatedInitExpr> DesignatedInitExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case DesignatedInitExpr::static_kind():
      return reinterpret_cast<const DesignatedInitExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DesignatedInitExpr> DesignatedInitExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kDesignatedInitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<DesignatedInitExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DesignatedInitExpr> DesignatedInitExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kDesignatedInitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<DesignatedInitExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DesignatedInitExpr> DesignatedInitExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kDesignatedInitExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<DesignatedInitExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<DesignatedInitExpr> DesignatedInitExpr::from(const Reference &r) {
  return DesignatedInitExpr::from(r.as_statement());
}

std::optional<DesignatedInitExpr> DesignatedInitExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<DesignatedInitExpr> DesignatedInitExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

unsigned DesignatedInitExpr::num_designators(void) const {
  return impl->reader.getVal15().size();
}

std::optional<Designator> DesignatedInitExpr::nth_designator(unsigned n) const {
  auto list = impl->reader.getVal15();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DesignatorFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Designator(std::move(e));
}

gap::generator<Designator> DesignatedInitExpr::designators(void) const & {
  auto list = impl->reader.getVal15();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->DesignatorFor(ep, v)) {
      co_yield Designator(std::move(d15));
    }
  }
  co_return;
}

TokenRange DesignatedInitExpr::designators_tokens(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal37(), impl->reader.getVal38());
}

Token DesignatedInitExpr::equal_or_colon_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

Expr DesignatedInitExpr::initializer(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

bool DesignatedInitExpr::is_direct_initializer(void) const {
  return impl->reader.getVal89();
}

bool DesignatedInitExpr::uses_gnu_syntax(void) const {
  return impl->reader.getVal90();
}

unsigned DesignatedInitExpr::num_sub_expressions(void) const {
  return impl->reader.getVal26().size();
}

std::optional<Expr> DesignatedInitExpr::nth_sub_expression(unsigned n) const {
  auto list = impl->reader.getVal26();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from_base(std::move(e));
}

gap::generator<Expr> DesignatedInitExpr::sub_expressions(void) const & {
  auto list = impl->reader.getVal26();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d26 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from_base(std::move(d26))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
