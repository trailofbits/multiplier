// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ArrayInitLoopExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/OpaqueValueExpr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ArrayInitLoopExpr> ArrayInitLoopExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ArrayInitLoopExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ArrayInitLoopExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ArrayInitLoopExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ArrayInitLoopExpr> ArrayInitLoopExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ArrayInitLoopExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ArrayInitLoopExpr> ArrayInitLoopExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ArrayInitLoopExpr> ArrayInitLoopExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ArrayInitLoopExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ArrayInitLoopExpr> ArrayInitLoopExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ArrayInitLoopExpr::contains(const Decl &decl) {
  for (auto &parent : ArrayInitLoopExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ArrayInitLoopExpr::contains(const Stmt &stmt) {
  for (auto &parent : ArrayInitLoopExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ArrayInitLoopExpr> ArrayInitLoopExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ArrayInitLoopExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kArrayInitLoopExprDerivedKinds[] = {
    ArrayInitLoopExpr::static_kind(),
};

std::optional<ArrayInitLoopExpr> ArrayInitLoopExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ArrayInitLoopExpr::static_kind():
      return reinterpret_cast<const ArrayInitLoopExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ArrayInitLoopExpr> ArrayInitLoopExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kArrayInitLoopExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ArrayInitLoopExpr> e = ArrayInitLoopExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ArrayInitLoopExpr> ArrayInitLoopExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kArrayInitLoopExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ArrayInitLoopExpr> e = ArrayInitLoopExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ArrayInitLoopExpr> ArrayInitLoopExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kArrayInitLoopExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ArrayInitLoopExpr> e = ArrayInitLoopExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ArrayInitLoopExpr> ArrayInitLoopExpr::from(const Reference &r) {
  return ArrayInitLoopExpr::from(r.as_statement());
}

std::optional<ArrayInitLoopExpr> ArrayInitLoopExpr::from(const TokenContext &t) {
  return ArrayInitLoopExpr::from(t.as_statement());
}

OpaqueValueExpr ArrayInitLoopExpr::common_expression(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return OpaqueValueExpr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr ArrayInitLoopExpr::sub_expression(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
