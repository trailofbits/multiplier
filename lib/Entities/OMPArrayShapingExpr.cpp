// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPArrayShapingExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OMPArrayShapingExpr> OMPArrayShapingExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPArrayShapingExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPArrayShapingExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPArrayShapingExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPArrayShapingExpr> OMPArrayShapingExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPArrayShapingExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPArrayShapingExpr> OMPArrayShapingExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPArrayShapingExpr> OMPArrayShapingExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPArrayShapingExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPArrayShapingExpr> OMPArrayShapingExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPArrayShapingExpr::contains(const Decl &decl) {
  for (auto &parent : OMPArrayShapingExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool OMPArrayShapingExpr::contains(const Stmt &stmt) {
  for (auto &parent : OMPArrayShapingExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<OMPArrayShapingExpr> OMPArrayShapingExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return OMPArrayShapingExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kOMPArrayShapingExprDerivedKinds[] = {
    OMPArrayShapingExpr::static_kind(),
};

std::optional<OMPArrayShapingExpr> OMPArrayShapingExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPArrayShapingExpr::static_kind():
      return reinterpret_cast<const OMPArrayShapingExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPArrayShapingExpr> OMPArrayShapingExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kOMPArrayShapingExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPArrayShapingExpr> e = OMPArrayShapingExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPArrayShapingExpr> OMPArrayShapingExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPArrayShapingExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPArrayShapingExpr> e = OMPArrayShapingExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPArrayShapingExpr> OMPArrayShapingExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPArrayShapingExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPArrayShapingExpr> e = OMPArrayShapingExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Expr OMPArrayShapingExpr::base(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

unsigned OMPArrayShapingExpr::num_dimensions(void) const {
  return impl->reader.getVal15().size();
}

std::optional<Expr> OMPArrayShapingExpr::nth_dimension(unsigned n) const {
  auto list = impl->reader.getVal15();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from(Stmt(std::move(e)));
}

gap::generator<Expr> OMPArrayShapingExpr::dimensions(void) const & {
  auto list = impl->reader.getVal15();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from(Stmt(std::move(d15)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

Token OMPArrayShapingExpr::l_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

Token OMPArrayShapingExpr::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
