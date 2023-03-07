// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ExtVectorElementExpr.h>

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

gap::generator<ExtVectorElementExpr> ExtVectorElementExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ExtVectorElementExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ExtVectorElementExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ExtVectorElementExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ExtVectorElementExpr> ExtVectorElementExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ExtVectorElementExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ExtVectorElementExpr> ExtVectorElementExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ExtVectorElementExpr> ExtVectorElementExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ExtVectorElementExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ExtVectorElementExpr> ExtVectorElementExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ExtVectorElementExpr::contains(const Decl &decl) {
  for (auto &parent : ExtVectorElementExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ExtVectorElementExpr::contains(const Stmt &stmt) {
  for (auto &parent : ExtVectorElementExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<ExtVectorElementExpr> ExtVectorElementExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ExtVectorElementExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kExtVectorElementExprDerivedKinds[] = {
    ExtVectorElementExpr::static_kind(),
};

std::optional<ExtVectorElementExpr> ExtVectorElementExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ExtVectorElementExpr::static_kind():
      return reinterpret_cast<const ExtVectorElementExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ExtVectorElementExpr> ExtVectorElementExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kExtVectorElementExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ExtVectorElementExpr> e = ExtVectorElementExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ExtVectorElementExpr> ExtVectorElementExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kExtVectorElementExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ExtVectorElementExpr> e = ExtVectorElementExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ExtVectorElementExpr> ExtVectorElementExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kExtVectorElementExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ExtVectorElementExpr> e = ExtVectorElementExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

bool ExtVectorElementExpr::contains_duplicate_elements(void) const {
  return impl->reader.getVal88();
}

Token ExtVectorElementExpr::accessor_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

Expr ExtVectorElementExpr::base(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

bool ExtVectorElementExpr::is_arrow(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
