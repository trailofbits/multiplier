// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MaterializeTemporaryExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/LifetimeExtendedTemporaryDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueDecl.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<MaterializeTemporaryExpr> MaterializeTemporaryExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = MaterializeTemporaryExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool MaterializeTemporaryExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : MaterializeTemporaryExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<MaterializeTemporaryExpr> MaterializeTemporaryExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = MaterializeTemporaryExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<MaterializeTemporaryExpr> MaterializeTemporaryExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<MaterializeTemporaryExpr> MaterializeTemporaryExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = MaterializeTemporaryExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<MaterializeTemporaryExpr> MaterializeTemporaryExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool MaterializeTemporaryExpr::contains(const Decl &decl) {
  for (auto &parent : MaterializeTemporaryExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool MaterializeTemporaryExpr::contains(const Stmt &stmt) {
  for (auto &parent : MaterializeTemporaryExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<MaterializeTemporaryExpr> MaterializeTemporaryExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return MaterializeTemporaryExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kMaterializeTemporaryExprDerivedKinds[] = {
    MaterializeTemporaryExpr::static_kind(),
};

std::optional<MaterializeTemporaryExpr> MaterializeTemporaryExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case MaterializeTemporaryExpr::static_kind():
      return reinterpret_cast<const MaterializeTemporaryExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<MaterializeTemporaryExpr> MaterializeTemporaryExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kMaterializeTemporaryExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<MaterializeTemporaryExpr> e = MaterializeTemporaryExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MaterializeTemporaryExpr> MaterializeTemporaryExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kMaterializeTemporaryExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<MaterializeTemporaryExpr> e = MaterializeTemporaryExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MaterializeTemporaryExpr> MaterializeTemporaryExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kMaterializeTemporaryExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<MaterializeTemporaryExpr> e = MaterializeTemporaryExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<MaterializeTemporaryExpr> MaterializeTemporaryExpr::from(const Reference &r) {
  return MaterializeTemporaryExpr::from(r.as_statement());
}

std::optional<MaterializeTemporaryExpr> MaterializeTemporaryExpr::from(const TokenContext &t) {
  return MaterializeTemporaryExpr::from(t.as_statement());
}

std::optional<ValueDecl> MaterializeTemporaryExpr::extending_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal37();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return ValueDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

std::optional<LifetimeExtendedTemporaryDecl> MaterializeTemporaryExpr::lifetime_extended_temporary_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal38();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return LifetimeExtendedTemporaryDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

StorageDuration MaterializeTemporaryExpr::storage_duration(void) const {
  return static_cast<StorageDuration>(impl->reader.getVal94());
}

Expr MaterializeTemporaryExpr::sub_expression(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

bool MaterializeTemporaryExpr::is_bound_to_lvalue_reference(void) const {
  return impl->reader.getVal89();
}

bool MaterializeTemporaryExpr::is_usable_in_constant_expressions(void) const {
  return impl->reader.getVal90();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
