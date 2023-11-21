// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCBridgedCastExpr.h>

#include <multiplier/AST/CastExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/ExplicitCastExpr.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/Token.h>
#include <multiplier/AST/ValueStmt.h>

#include "../EntityProvider.h"
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
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCBridgedCastExpr::contains(const Stmt &stmt) {
  for (auto &parent : ObjCBridgedCastExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ObjCBridgedCastExpr> ObjCBridgedCastExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    if (auto base = index.statement(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<ObjCBridgedCastExpr> ObjCBridgedCastExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kObjCBridgedCastExprDerivedKinds[] = {
    ObjCBridgedCastExpr::static_kind(),
};

}  // namespace

std::optional<ObjCBridgedCastExpr> ObjCBridgedCastExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCBridgedCastExpr::static_kind():
      return reinterpret_cast<const ObjCBridgedCastExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCBridgedCastExpr> ObjCBridgedCastExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kObjCBridgedCastExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCBridgedCastExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCBridgedCastExpr> ObjCBridgedCastExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCBridgedCastExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCBridgedCastExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCBridgedCastExpr> ObjCBridgedCastExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCBridgedCastExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCBridgedCastExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCBridgedCastExpr> ObjCBridgedCastExpr::from(const Reference &r) {
  return ObjCBridgedCastExpr::from(r.as_statement());
}

std::optional<ObjCBridgedCastExpr> ObjCBridgedCastExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<ObjCBridgedCastExpr> ObjCBridgedCastExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token ObjCBridgedCastExpr::bridge_keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal42());
}

ObjCBridgeCastKind ObjCBridgedCastExpr::bridge_kind(void) const {
  return static_cast<ObjCBridgeCastKind>(impl->reader.getVal97());
}

std::string_view ObjCBridgedCastExpr::bridge_kind_name(void) const {
  capnp::Text::Reader data = impl->reader.getVal65();
  return std::string_view(data.cStr(), data.size());
}

Token ObjCBridgedCastExpr::l_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal43());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
