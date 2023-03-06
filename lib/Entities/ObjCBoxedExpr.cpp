// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCBoxedExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/ObjCMethodDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCBoxedExpr> ObjCBoxedExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCBoxedExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCBoxedExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCBoxedExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCBoxedExpr> ObjCBoxedExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCBoxedExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCBoxedExpr> ObjCBoxedExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCBoxedExpr> ObjCBoxedExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCBoxedExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCBoxedExpr> ObjCBoxedExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCBoxedExpr::contains(const Decl &decl) {
  for (auto &parent : ObjCBoxedExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ObjCBoxedExpr::contains(const Stmt &stmt) {
  for (auto &parent : ObjCBoxedExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<ObjCBoxedExpr> ObjCBoxedExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ObjCBoxedExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kObjCBoxedExprDerivedKinds[] = {
    ObjCBoxedExpr::static_kind(),
};

std::optional<ObjCBoxedExpr> ObjCBoxedExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCBoxedExpr::static_kind():
      return reinterpret_cast<const ObjCBoxedExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCBoxedExpr> ObjCBoxedExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kObjCBoxedExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCBoxedExpr> e = ObjCBoxedExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCBoxedExpr> ObjCBoxedExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCBoxedExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCBoxedExpr> e = ObjCBoxedExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCBoxedExpr> ObjCBoxedExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCBoxedExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCBoxedExpr> e = ObjCBoxedExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Token ObjCBoxedExpr::at_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

ObjCMethodDecl ObjCBoxedExpr::boxing_method(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return ObjCMethodDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Expr ObjCBoxedExpr::sub_expression(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

bool ObjCBoxedExpr::is_expressible_as_constant_initializer(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
