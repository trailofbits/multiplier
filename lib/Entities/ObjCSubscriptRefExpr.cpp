// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCSubscriptRefExpr.h>

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

gap::generator<ObjCSubscriptRefExpr> ObjCSubscriptRefExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCSubscriptRefExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCSubscriptRefExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCSubscriptRefExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCSubscriptRefExpr> ObjCSubscriptRefExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCSubscriptRefExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCSubscriptRefExpr> ObjCSubscriptRefExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCSubscriptRefExpr> ObjCSubscriptRefExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCSubscriptRefExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCSubscriptRefExpr> ObjCSubscriptRefExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCSubscriptRefExpr::contains(const Decl &decl) {
  for (auto &parent : ObjCSubscriptRefExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ObjCSubscriptRefExpr::contains(const Stmt &stmt) {
  for (auto &parent : ObjCSubscriptRefExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<ObjCSubscriptRefExpr> ObjCSubscriptRefExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ObjCSubscriptRefExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kObjCSubscriptRefExprDerivedKinds[] = {
    ObjCSubscriptRefExpr::static_kind(),
};

std::optional<ObjCSubscriptRefExpr> ObjCSubscriptRefExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCSubscriptRefExpr::static_kind():
      return reinterpret_cast<const ObjCSubscriptRefExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCSubscriptRefExpr> ObjCSubscriptRefExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kObjCSubscriptRefExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCSubscriptRefExpr> e = ObjCSubscriptRefExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCSubscriptRefExpr> ObjCSubscriptRefExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCSubscriptRefExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCSubscriptRefExpr> e = ObjCSubscriptRefExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCSubscriptRefExpr> ObjCSubscriptRefExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCSubscriptRefExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCSubscriptRefExpr> e = ObjCSubscriptRefExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCSubscriptRefExpr> ObjCSubscriptRefExpr::from(const Reference &r) {
  return ObjCSubscriptRefExpr::from(r.as_statement());
}

std::optional<ObjCSubscriptRefExpr> ObjCSubscriptRefExpr::from(const TokenContext &t) {
  return ObjCSubscriptRefExpr::from(t.as_statement());
}

ObjCMethodDecl ObjCSubscriptRefExpr::at_index_method_declaration(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return ObjCMethodDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Expr ObjCSubscriptRefExpr::base_expression(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr ObjCSubscriptRefExpr::key_expression(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token ObjCSubscriptRefExpr::r_bracket_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal41());
}

bool ObjCSubscriptRefExpr::is_array_subscript_reference_expression(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
