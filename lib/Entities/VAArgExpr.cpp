// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/VAArgExpr.h>

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

gap::generator<VAArgExpr> VAArgExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = VAArgExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool VAArgExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : VAArgExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<VAArgExpr> VAArgExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = VAArgExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<VAArgExpr> VAArgExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<VAArgExpr> VAArgExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = VAArgExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<VAArgExpr> VAArgExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool VAArgExpr::contains(const Decl &decl) {
  for (auto &parent : VAArgExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool VAArgExpr::contains(const Stmt &stmt) {
  for (auto &parent : VAArgExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<VAArgExpr> VAArgExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return VAArgExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kVAArgExprDerivedKinds[] = {
    VAArgExpr::static_kind(),
};

std::optional<VAArgExpr> VAArgExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case VAArgExpr::static_kind():
      return reinterpret_cast<const VAArgExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<VAArgExpr> VAArgExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kVAArgExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<VAArgExpr> e = VAArgExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VAArgExpr> VAArgExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kVAArgExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<VAArgExpr> e = VAArgExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VAArgExpr> VAArgExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kVAArgExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<VAArgExpr> e = VAArgExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Token VAArgExpr::builtin_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

Token VAArgExpr::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

Expr VAArgExpr::sub_expression(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Type VAArgExpr::written_type(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool VAArgExpr::is_microsoft_abi(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
