// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/UnresolvedLookupExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/OverloadExpr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<UnresolvedLookupExpr> UnresolvedLookupExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UnresolvedLookupExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UnresolvedLookupExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UnresolvedLookupExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<UnresolvedLookupExpr> UnresolvedLookupExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = UnresolvedLookupExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnresolvedLookupExpr> UnresolvedLookupExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<UnresolvedLookupExpr> UnresolvedLookupExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = UnresolvedLookupExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnresolvedLookupExpr> UnresolvedLookupExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool UnresolvedLookupExpr::contains(const Decl &decl) {
  for (auto &parent : UnresolvedLookupExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool UnresolvedLookupExpr::contains(const Stmt &stmt) {
  for (auto &parent : UnresolvedLookupExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<UnresolvedLookupExpr> UnresolvedLookupExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return UnresolvedLookupExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kUnresolvedLookupExprDerivedKinds[] = {
    UnresolvedLookupExpr::static_kind(),
};

std::optional<UnresolvedLookupExpr> UnresolvedLookupExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case UnresolvedLookupExpr::static_kind():
      return reinterpret_cast<const UnresolvedLookupExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<UnresolvedLookupExpr> UnresolvedLookupExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kUnresolvedLookupExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<UnresolvedLookupExpr> e = UnresolvedLookupExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnresolvedLookupExpr> UnresolvedLookupExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kUnresolvedLookupExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<UnresolvedLookupExpr> e = UnresolvedLookupExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnresolvedLookupExpr> UnresolvedLookupExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kUnresolvedLookupExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<UnresolvedLookupExpr> e = UnresolvedLookupExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

bool UnresolvedLookupExpr::is_overloaded(void) const {
  return impl->reader.getVal91();
}

bool UnresolvedLookupExpr::requires_adl(void) const {
  return impl->reader.getVal92();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
