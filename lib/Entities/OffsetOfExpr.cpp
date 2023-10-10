// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OffsetOfExpr.h>

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

gap::generator<OffsetOfExpr> OffsetOfExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OffsetOfExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OffsetOfExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OffsetOfExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OffsetOfExpr> OffsetOfExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OffsetOfExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OffsetOfExpr> OffsetOfExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OffsetOfExpr> OffsetOfExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OffsetOfExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OffsetOfExpr> OffsetOfExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OffsetOfExpr::contains(const Decl &decl) {
  for (auto &parent : OffsetOfExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OffsetOfExpr::contains(const Stmt &stmt) {
  for (auto &parent : OffsetOfExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<OffsetOfExpr> OffsetOfExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return OffsetOfExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kOffsetOfExprDerivedKinds[] = {
    OffsetOfExpr::static_kind(),
};

std::optional<OffsetOfExpr> OffsetOfExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case OffsetOfExpr::static_kind():
      return reinterpret_cast<const OffsetOfExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OffsetOfExpr> OffsetOfExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kOffsetOfExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OffsetOfExpr> e = OffsetOfExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OffsetOfExpr> OffsetOfExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOffsetOfExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OffsetOfExpr> e = OffsetOfExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OffsetOfExpr> OffsetOfExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOffsetOfExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OffsetOfExpr> e = OffsetOfExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OffsetOfExpr> OffsetOfExpr::from(const Reference &r) {
  return OffsetOfExpr::from(r.as_statement());
}

std::optional<OffsetOfExpr> OffsetOfExpr::from(const TokenContext &t) {
  return OffsetOfExpr::from(t.as_statement());
}

Token OffsetOfExpr::operator_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal37());
}

Token OffsetOfExpr::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
