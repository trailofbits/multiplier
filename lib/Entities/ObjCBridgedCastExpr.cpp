// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCBridgedCastExpr.h>

#include <multiplier/Entities/CastExpr.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/ExplicitCastExpr.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCBridgedCastExpr> ObjCBridgedCastExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCBridgedCastExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCBridgedCastExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCBridgedCastExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCBridgedCastExpr> ObjCBridgedCastExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCBridgedCastExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCBridgedCastExpr> ObjCBridgedCastExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCBridgedCastExpr> ObjCBridgedCastExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCBridgedCastExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCBridgedCastExpr> ObjCBridgedCastExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCBridgedCastExpr::contains(const Decl &decl) {
  for (auto &parent : ObjCBridgedCastExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ObjCBridgedCastExpr::contains(const Stmt &stmt) {
  for (auto &parent : ObjCBridgedCastExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<ObjCBridgedCastExpr> ObjCBridgedCastExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ObjCBridgedCastExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kObjCBridgedCastExprDerivedKinds[] = {
    ObjCBridgedCastExpr::static_kind(),
};

std::optional<ObjCBridgedCastExpr> ObjCBridgedCastExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCBridgedCastExpr::static_kind():
      return reinterpret_cast<const ObjCBridgedCastExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCBridgedCastExpr> ObjCBridgedCastExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kObjCBridgedCastExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCBridgedCastExpr> e = ObjCBridgedCastExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCBridgedCastExpr> ObjCBridgedCastExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCBridgedCastExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCBridgedCastExpr> e = ObjCBridgedCastExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCBridgedCastExpr> ObjCBridgedCastExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCBridgedCastExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCBridgedCastExpr> e = ObjCBridgedCastExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Token ObjCBridgedCastExpr::bridge_keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal43());
}

ObjCBridgeCastKind ObjCBridgedCastExpr::bridge_kind(void) const {
  return static_cast<ObjCBridgeCastKind>(impl->reader.getVal95());
}

std::string_view ObjCBridgedCastExpr::bridge_kind_name(void) const {
  capnp::Text::Reader data = impl->reader.getVal65();
  return std::string_view(data.cStr(), data.size());
}

Token ObjCBridgedCastExpr::l_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal44());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
