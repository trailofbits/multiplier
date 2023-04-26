// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ArrayTypeTraitExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ArrayTypeTraitExpr> ArrayTypeTraitExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ArrayTypeTraitExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ArrayTypeTraitExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ArrayTypeTraitExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ArrayTypeTraitExpr> ArrayTypeTraitExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ArrayTypeTraitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ArrayTypeTraitExpr> ArrayTypeTraitExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ArrayTypeTraitExpr> ArrayTypeTraitExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ArrayTypeTraitExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ArrayTypeTraitExpr> ArrayTypeTraitExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ArrayTypeTraitExpr::contains(const Decl &decl) {
  for (auto &parent : ArrayTypeTraitExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ArrayTypeTraitExpr::contains(const Stmt &stmt) {
  for (auto &parent : ArrayTypeTraitExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ArrayTypeTraitExpr> ArrayTypeTraitExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ArrayTypeTraitExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kArrayTypeTraitExprDerivedKinds[] = {
    ArrayTypeTraitExpr::static_kind(),
};

std::optional<ArrayTypeTraitExpr> ArrayTypeTraitExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ArrayTypeTraitExpr::static_kind():
      return reinterpret_cast<const ArrayTypeTraitExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ArrayTypeTraitExpr> ArrayTypeTraitExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kArrayTypeTraitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ArrayTypeTraitExpr> e = ArrayTypeTraitExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ArrayTypeTraitExpr> ArrayTypeTraitExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kArrayTypeTraitExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ArrayTypeTraitExpr> e = ArrayTypeTraitExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ArrayTypeTraitExpr> ArrayTypeTraitExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kArrayTypeTraitExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ArrayTypeTraitExpr> e = ArrayTypeTraitExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ArrayTypeTraitExpr> ArrayTypeTraitExpr::from(const Reference &r) {
  return ArrayTypeTraitExpr::from(r.as_statement());
}

std::optional<ArrayTypeTraitExpr> ArrayTypeTraitExpr::from(const TokenContext &t) {
  return ArrayTypeTraitExpr::from(t.as_statement());
}

Expr ArrayTypeTraitExpr::dimension_expression(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Type ArrayTypeTraitExpr::queried_type(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

ArrayTypeTrait ArrayTypeTraitExpr::trait(void) const {
  return static_cast<ArrayTypeTrait>(impl->reader.getVal94());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
