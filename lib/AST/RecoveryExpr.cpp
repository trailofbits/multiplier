// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/RecoveryExpr.h>
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
static const StmtKind kRecoveryExprDerivedKinds[] = {
    RecoveryExpr::static_kind(),
};
}  // namespace

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

std::optional<RecoveryExpr> RecoveryExpr::from(const ir::hl::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<RecoveryExpr, ir::hl::Operation>> RecoveryExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::hl::Operation> res : Stmt::in(tu, kRecoveryExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<RecoveryExpr, ir::hl::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
    if (auto base = index.statement(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<RecoveryExpr> RecoveryExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<RecoveryExpr> RecoveryExpr::from_base(const Stmt &parent) {
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
      if (std::optional<RecoveryExpr> e = from_base(std::move(eptr))) {
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
      if (std::optional<RecoveryExpr> e = from_base(std::move(eptr))) {
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
        if (std::optional<RecoveryExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<RecoveryExpr> RecoveryExpr::from(const Reference &r) {
  return RecoveryExpr::from(r.as_statement());
}

std::optional<RecoveryExpr> RecoveryExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<RecoveryExpr> RecoveryExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

unsigned RecoveryExpr::num_sub_expressions(void) const {
  return impl->reader.getVal15().size();
}

std::optional<Expr> RecoveryExpr::nth_sub_expression(unsigned n) const {
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

gap::generator<Expr> RecoveryExpr::sub_expressions(void) const & {
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

#pragma GCC diagnostic pop
#endif
}  // namespace mx
