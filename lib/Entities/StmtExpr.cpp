// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/StmtExpr.h>

#include <multiplier/Entities/CompoundStmt.h>
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

gap::generator<StmtExpr> StmtExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = StmtExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool StmtExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : StmtExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<StmtExpr> StmtExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = StmtExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<StmtExpr> StmtExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<StmtExpr> StmtExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = StmtExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<StmtExpr> StmtExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool StmtExpr::contains(const Decl &decl) {
  for (auto &parent : StmtExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool StmtExpr::contains(const Stmt &stmt) {
  for (auto &parent : StmtExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<StmtExpr> StmtExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return StmtExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kStmtExprDerivedKinds[] = {
    StmtExpr::static_kind(),
};

std::optional<StmtExpr> StmtExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case StmtExpr::static_kind():
      return reinterpret_cast<const StmtExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<StmtExpr> StmtExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kStmtExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<StmtExpr> e = StmtExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<StmtExpr> StmtExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kStmtExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<StmtExpr> e = StmtExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<StmtExpr> StmtExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kStmtExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<StmtExpr> e = StmtExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<StmtExpr> StmtExpr::from(const Reference &r) {
  return StmtExpr::from(r.as_statement());
}

std::optional<StmtExpr> StmtExpr::from(const TokenContext &t) {
  return StmtExpr::from(t.as_statement());
}

Token StmtExpr::l_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

Token StmtExpr::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

CompoundStmt StmtExpr::sub_statement(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return CompoundStmt::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
