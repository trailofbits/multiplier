// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/UnresolvedMemberExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/OverloadExpr.h>
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

gap::generator<UnresolvedMemberExpr> UnresolvedMemberExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UnresolvedMemberExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UnresolvedMemberExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UnresolvedMemberExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<UnresolvedMemberExpr> UnresolvedMemberExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = UnresolvedMemberExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnresolvedMemberExpr> UnresolvedMemberExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<UnresolvedMemberExpr> UnresolvedMemberExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = UnresolvedMemberExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnresolvedMemberExpr> UnresolvedMemberExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool UnresolvedMemberExpr::contains(const Decl &decl) {
  for (auto &parent : UnresolvedMemberExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool UnresolvedMemberExpr::contains(const Stmt &stmt) {
  for (auto &parent : UnresolvedMemberExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<UnresolvedMemberExpr> UnresolvedMemberExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return UnresolvedMemberExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kUnresolvedMemberExprDerivedKinds[] = {
    UnresolvedMemberExpr::static_kind(),
};

std::optional<UnresolvedMemberExpr> UnresolvedMemberExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case UnresolvedMemberExpr::static_kind():
      return reinterpret_cast<const UnresolvedMemberExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<UnresolvedMemberExpr> UnresolvedMemberExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kUnresolvedMemberExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<UnresolvedMemberExpr> e = UnresolvedMemberExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnresolvedMemberExpr> UnresolvedMemberExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kUnresolvedMemberExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<UnresolvedMemberExpr> e = UnresolvedMemberExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnresolvedMemberExpr> UnresolvedMemberExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kUnresolvedMemberExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<UnresolvedMemberExpr> e = UnresolvedMemberExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Expr UnresolvedMemberExpr::base(void) const {
  RawEntityId eid = impl->reader.getVal43();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Type UnresolvedMemberExpr::base_type(void) const {
  RawEntityId eid = impl->reader.getVal44();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Token UnresolvedMemberExpr::member_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal45());
}

Token UnresolvedMemberExpr::operator_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal46());
}

bool UnresolvedMemberExpr::has_unresolved_using(void) const {
  return impl->reader.getVal90();
}

bool UnresolvedMemberExpr::is_arrow(void) const {
  return impl->reader.getVal91();
}

bool UnresolvedMemberExpr::is_implicit_access(void) const {
  return impl->reader.getVal92();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx