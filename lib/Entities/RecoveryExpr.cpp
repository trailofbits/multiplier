// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/RecoveryExpr.h>

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

gap::generator<RecoveryExpr> RecoveryExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = RecoveryExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool RecoveryExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : RecoveryExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<RecoveryExpr> RecoveryExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = RecoveryExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<RecoveryExpr> RecoveryExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<RecoveryExpr> RecoveryExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = RecoveryExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<RecoveryExpr> RecoveryExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool RecoveryExpr::contains(const Decl &decl) {
  for (auto &parent : RecoveryExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool RecoveryExpr::contains(const Stmt &stmt) {
  for (auto &parent : RecoveryExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<RecoveryExpr> RecoveryExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return RecoveryExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kRecoveryExprDerivedKinds[] = {
    RecoveryExpr::static_kind(),
};

std::optional<RecoveryExpr> RecoveryExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case RecoveryExpr::static_kind():
      return reinterpret_cast<const RecoveryExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<RecoveryExpr> RecoveryExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kRecoveryExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<RecoveryExpr> e = RecoveryExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<RecoveryExpr> RecoveryExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kRecoveryExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<RecoveryExpr> e = RecoveryExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<RecoveryExpr> RecoveryExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kRecoveryExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<RecoveryExpr> e = RecoveryExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<RecoveryExpr> RecoveryExpr::from(const Reference &r) {
  return RecoveryExpr::from(r.as_statement());
}

std::optional<RecoveryExpr> RecoveryExpr::from(const TokenContext &t) {
  return RecoveryExpr::from(t.as_statement());
}

unsigned RecoveryExpr::num_sub_expressions(void) const {
  return impl->reader.getVal16().size();
}

std::optional<Expr> RecoveryExpr::nth_sub_expression(unsigned n) const {
  auto list = impl->reader.getVal16();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from(Stmt(std::move(e)));
}

gap::generator<Expr> RecoveryExpr::sub_expressions(void) const & {
  auto list = impl->reader.getVal16();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d16 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from(Stmt(std::move(d16)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
