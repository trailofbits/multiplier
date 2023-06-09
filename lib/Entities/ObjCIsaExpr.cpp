// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCIsaExpr.h>

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

gap::generator<ObjCIsaExpr> ObjCIsaExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCIsaExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCIsaExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCIsaExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCIsaExpr> ObjCIsaExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCIsaExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCIsaExpr> ObjCIsaExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCIsaExpr> ObjCIsaExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCIsaExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCIsaExpr> ObjCIsaExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCIsaExpr::contains(const Decl &decl) {
  for (auto &parent : ObjCIsaExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCIsaExpr::contains(const Stmt &stmt) {
  for (auto &parent : ObjCIsaExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ObjCIsaExpr> ObjCIsaExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ObjCIsaExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kObjCIsaExprDerivedKinds[] = {
    ObjCIsaExpr::static_kind(),
};

std::optional<ObjCIsaExpr> ObjCIsaExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCIsaExpr::static_kind():
      return reinterpret_cast<const ObjCIsaExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCIsaExpr> ObjCIsaExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kObjCIsaExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCIsaExpr> e = ObjCIsaExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCIsaExpr> ObjCIsaExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCIsaExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCIsaExpr> e = ObjCIsaExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCIsaExpr> ObjCIsaExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCIsaExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCIsaExpr> e = ObjCIsaExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCIsaExpr> ObjCIsaExpr::from(const Reference &r) {
  return ObjCIsaExpr::from(r.as_statement());
}

std::optional<ObjCIsaExpr> ObjCIsaExpr::from(const TokenContext &t) {
  return ObjCIsaExpr::from(t.as_statement());
}

Expr ObjCIsaExpr::base(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token ObjCIsaExpr::base_token_end(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal42());
}

Token ObjCIsaExpr::isa_member_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal43());
}

Token ObjCIsaExpr::operation_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal44());
}

bool ObjCIsaExpr::is_arrow(void) const {
  return impl->reader.getVal92();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
