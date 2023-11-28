// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCProtocolExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/ObjCProtocolDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCProtocolExpr> ObjCProtocolExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCProtocolExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCProtocolExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCProtocolExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCProtocolExpr> ObjCProtocolExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCProtocolExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCProtocolExpr> ObjCProtocolExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCProtocolExpr> ObjCProtocolExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCProtocolExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCProtocolExpr> ObjCProtocolExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCProtocolExpr::contains(const Decl &decl) {
  for (auto &parent : ObjCProtocolExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCProtocolExpr::contains(const Stmt &stmt) {
  for (auto &parent : ObjCProtocolExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ObjCProtocolExpr> ObjCProtocolExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<ObjCProtocolExpr> ObjCProtocolExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kObjCProtocolExprDerivedKinds[] = {
    ObjCProtocolExpr::static_kind(),
};

}  // namespace

std::optional<ObjCProtocolExpr> ObjCProtocolExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCProtocolExpr::static_kind():
      return reinterpret_cast<const ObjCProtocolExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCProtocolExpr> ObjCProtocolExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kObjCProtocolExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCProtocolExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCProtocolExpr> ObjCProtocolExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCProtocolExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCProtocolExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCProtocolExpr> ObjCProtocolExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCProtocolExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCProtocolExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCProtocolExpr> ObjCProtocolExpr::from(const Reference &r) {
  return ObjCProtocolExpr::from(r.as_statement());
}

std::optional<ObjCProtocolExpr> ObjCProtocolExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<ObjCProtocolExpr> ObjCProtocolExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token ObjCProtocolExpr::at_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal37());
}

ObjCProtocolDecl ObjCProtocolExpr::protocol(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return ObjCProtocolDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Token ObjCProtocolExpr::protocol_id_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

Token ObjCProtocolExpr::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
