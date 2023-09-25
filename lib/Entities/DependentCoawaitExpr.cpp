// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DependentCoawaitExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/UnresolvedLookupExpr.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<DependentCoawaitExpr> DependentCoawaitExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DependentCoawaitExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DependentCoawaitExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DependentCoawaitExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<DependentCoawaitExpr> DependentCoawaitExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = DependentCoawaitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<DependentCoawaitExpr> DependentCoawaitExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<DependentCoawaitExpr> DependentCoawaitExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = DependentCoawaitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<DependentCoawaitExpr> DependentCoawaitExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool DependentCoawaitExpr::contains(const Decl &decl) {
  for (auto &parent : DependentCoawaitExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool DependentCoawaitExpr::contains(const Stmt &stmt) {
  for (auto &parent : DependentCoawaitExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<DependentCoawaitExpr> DependentCoawaitExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return DependentCoawaitExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kDependentCoawaitExprDerivedKinds[] = {
    DependentCoawaitExpr::static_kind(),
};

std::optional<DependentCoawaitExpr> DependentCoawaitExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case DependentCoawaitExpr::static_kind():
      return reinterpret_cast<const DependentCoawaitExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DependentCoawaitExpr> DependentCoawaitExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kDependentCoawaitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<DependentCoawaitExpr> e = DependentCoawaitExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DependentCoawaitExpr> DependentCoawaitExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kDependentCoawaitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<DependentCoawaitExpr> e = DependentCoawaitExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DependentCoawaitExpr> DependentCoawaitExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kDependentCoawaitExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<DependentCoawaitExpr> e = DependentCoawaitExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<DependentCoawaitExpr> DependentCoawaitExpr::from(const Reference &r) {
  return DependentCoawaitExpr::from(r.as_statement());
}

std::optional<DependentCoawaitExpr> DependentCoawaitExpr::from(const TokenContext &t) {
  return DependentCoawaitExpr::from(t.as_statement());
}

Token DependentCoawaitExpr::keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal37());
}

Expr DependentCoawaitExpr::operand(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

UnresolvedLookupExpr DependentCoawaitExpr::operator_coawait_lookup(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return UnresolvedLookupExpr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
