// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/PseudoObjectExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/Frontend/File.h>
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
static const StmtKind kPseudoObjectExprDerivedKinds[] = {
    PseudoObjectExpr::static_kind(),
};
}  // namespace

gap::generator<PseudoObjectExpr> PseudoObjectExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kPseudoObjectExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<PseudoObjectExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<PseudoObjectExpr> PseudoObjectExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kPseudoObjectExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<PseudoObjectExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<PseudoObjectExpr> PseudoObjectExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kPseudoObjectExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<PseudoObjectExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<PseudoObjectExpr> PseudoObjectExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = PseudoObjectExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool PseudoObjectExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : PseudoObjectExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<PseudoObjectExpr> PseudoObjectExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<PseudoObjectExpr, ir::Operation>> PseudoObjectExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kPseudoObjectExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<PseudoObjectExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<PseudoObjectExpr> PseudoObjectExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = PseudoObjectExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<PseudoObjectExpr> PseudoObjectExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<PseudoObjectExpr> PseudoObjectExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = PseudoObjectExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<PseudoObjectExpr> PseudoObjectExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool PseudoObjectExpr::contains(const Decl &decl) {
  for (auto &parent : PseudoObjectExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool PseudoObjectExpr::contains(const Stmt &stmt) {
  for (auto &parent : PseudoObjectExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<PseudoObjectExpr> PseudoObjectExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<PseudoObjectExpr> PseudoObjectExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<PseudoObjectExpr> PseudoObjectExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case PseudoObjectExpr::static_kind():
      return reinterpret_cast<const PseudoObjectExpr &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<PseudoObjectExpr> PseudoObjectExpr::from(const Reference &r) {
  return PseudoObjectExpr::from(r.as_statement());
}

std::optional<PseudoObjectExpr> PseudoObjectExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<PseudoObjectExpr> PseudoObjectExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Expr PseudoObjectExpr::result_expression(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

uint32_t PseudoObjectExpr::result_expression_index(void) const {
  return impl->reader.getVal26();
}

Expr PseudoObjectExpr::syntactic_form(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

unsigned PseudoObjectExpr::num_semantics(void) const {
  return impl->reader.getVal15().size();
}

std::optional<Expr> PseudoObjectExpr::nth_semantic(unsigned n) const {
  auto list = impl->reader.getVal15();
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

gap::generator<Expr> PseudoObjectExpr::semantics(void) const & {
  auto list = impl->reader.getVal15();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from_base(std::move(d15))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned PseudoObjectExpr::num_semantic_expressions(void) const {
  return impl->reader.getVal27().size();
}

std::optional<Expr> PseudoObjectExpr::nth_semantic_expression(unsigned n) const {
  auto list = impl->reader.getVal27();
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

gap::generator<Expr> PseudoObjectExpr::semantic_expressions(void) const & {
  auto list = impl->reader.getVal27();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d27 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from_base(std::move(d27))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
