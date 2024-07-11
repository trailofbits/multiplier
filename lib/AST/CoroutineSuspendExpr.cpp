// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CoroutineSuspendExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/OpaqueValueExpr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueStmt.h>
#include <multiplier/AST/CoawaitExpr.h>
#include <multiplier/AST/CoyieldExpr.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kCoroutineSuspendExprDerivedKinds[] = {
    CoyieldExpr::static_kind(),
    CoawaitExpr::static_kind(),
};
}  // namespace

gap::generator<CoroutineSuspendExpr> CoroutineSuspendExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCoroutineSuspendExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CoroutineSuspendExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CoroutineSuspendExpr> CoroutineSuspendExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCoroutineSuspendExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CoroutineSuspendExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<CoroutineSuspendExpr> CoroutineSuspendExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCoroutineSuspendExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CoroutineSuspendExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CoroutineSuspendExpr> CoroutineSuspendExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CoroutineSuspendExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CoroutineSuspendExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CoroutineSuspendExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<CoroutineSuspendExpr> CoroutineSuspendExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<CoroutineSuspendExpr, ir::Operation>> CoroutineSuspendExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kCoroutineSuspendExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<CoroutineSuspendExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<CoroutineSuspendExpr> CoroutineSuspendExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CoroutineSuspendExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CoroutineSuspendExpr> CoroutineSuspendExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CoroutineSuspendExpr> CoroutineSuspendExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CoroutineSuspendExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CoroutineSuspendExpr> CoroutineSuspendExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CoroutineSuspendExpr::contains(const Decl &decl) {
  for (auto &parent : CoroutineSuspendExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CoroutineSuspendExpr::contains(const Stmt &stmt) {
  for (auto &parent : CoroutineSuspendExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CoroutineSuspendExpr> CoroutineSuspendExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<CoroutineSuspendExpr> CoroutineSuspendExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<CoroutineSuspendExpr> CoroutineSuspendExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case CoyieldExpr::static_kind():
    case CoawaitExpr::static_kind():
      return reinterpret_cast<const CoroutineSuspendExpr &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<CoroutineSuspendExpr> CoroutineSuspendExpr::from(const Reference &r) {
  return CoroutineSuspendExpr::from(r.as_statement());
}

std::optional<CoroutineSuspendExpr> CoroutineSuspendExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<CoroutineSuspendExpr> CoroutineSuspendExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Expr CoroutineSuspendExpr::common_expression(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Token CoroutineSuspendExpr::keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

OpaqueValueExpr CoroutineSuspendExpr::opaque_value(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return OpaqueValueExpr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr CoroutineSuspendExpr::operand(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr CoroutineSuspendExpr::ready_expression(void) const {
  RawEntityId eid = impl->reader.getVal42();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr CoroutineSuspendExpr::resume_expression(void) const {
  RawEntityId eid = impl->reader.getVal43();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr CoroutineSuspendExpr::suspend_expression(void) const {
  RawEntityId eid = impl->reader.getVal44();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
