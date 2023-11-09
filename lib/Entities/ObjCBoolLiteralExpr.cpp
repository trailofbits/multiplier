// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCBoolLiteralExpr.h>

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

gap::generator<ObjCBoolLiteralExpr> ObjCBoolLiteralExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCBoolLiteralExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCBoolLiteralExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCBoolLiteralExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCBoolLiteralExpr> ObjCBoolLiteralExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCBoolLiteralExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCBoolLiteralExpr> ObjCBoolLiteralExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCBoolLiteralExpr> ObjCBoolLiteralExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCBoolLiteralExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCBoolLiteralExpr> ObjCBoolLiteralExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCBoolLiteralExpr::contains(const Decl &decl) {
  for (auto &parent : ObjCBoolLiteralExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCBoolLiteralExpr::contains(const Stmt &stmt) {
  for (auto &parent : ObjCBoolLiteralExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ObjCBoolLiteralExpr> ObjCBoolLiteralExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ObjCBoolLiteralExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kObjCBoolLiteralExprDerivedKinds[] = {
    ObjCBoolLiteralExpr::static_kind(),
};

std::optional<ObjCBoolLiteralExpr> ObjCBoolLiteralExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCBoolLiteralExpr::static_kind():
      return reinterpret_cast<const ObjCBoolLiteralExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCBoolLiteralExpr> ObjCBoolLiteralExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kObjCBoolLiteralExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCBoolLiteralExpr> e = ObjCBoolLiteralExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCBoolLiteralExpr> ObjCBoolLiteralExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCBoolLiteralExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCBoolLiteralExpr> e = ObjCBoolLiteralExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCBoolLiteralExpr> ObjCBoolLiteralExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCBoolLiteralExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCBoolLiteralExpr> e = ObjCBoolLiteralExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCBoolLiteralExpr> ObjCBoolLiteralExpr::from(const Reference &r) {
  return ObjCBoolLiteralExpr::from(r.as_statement());
}

std::optional<ObjCBoolLiteralExpr> ObjCBoolLiteralExpr::from(const TokenContext &t) {
  return ObjCBoolLiteralExpr::from(t.as_statement());
}

Token ObjCBoolLiteralExpr::token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal37());
}

bool ObjCBoolLiteralExpr::value(void) const {
  return impl->reader.getVal87();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
