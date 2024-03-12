// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCPropertyRefExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/ObjCInterfaceDecl.h>
#include <multiplier/AST/ObjCMethodDecl.h>
#include <multiplier/AST/ObjCPropertyDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/ValueStmt.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kObjCPropertyRefExprDerivedKinds[] = {
    ObjCPropertyRefExpr::static_kind(),
};
}  // namespace

gap::generator<ObjCPropertyRefExpr> ObjCPropertyRefExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCPropertyRefExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCPropertyRefExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCPropertyRefExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ObjCPropertyRefExpr> ObjCPropertyRefExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<ObjCPropertyRefExpr, ir::Operation>> ObjCPropertyRefExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kObjCPropertyRefExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<ObjCPropertyRefExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<ObjCPropertyRefExpr> ObjCPropertyRefExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCPropertyRefExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCPropertyRefExpr> ObjCPropertyRefExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCPropertyRefExpr> ObjCPropertyRefExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCPropertyRefExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCPropertyRefExpr> ObjCPropertyRefExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCPropertyRefExpr::contains(const Decl &decl) {
  for (auto &parent : ObjCPropertyRefExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCPropertyRefExpr::contains(const Stmt &stmt) {
  for (auto &parent : ObjCPropertyRefExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ObjCPropertyRefExpr> ObjCPropertyRefExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<ObjCPropertyRefExpr> ObjCPropertyRefExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ObjCPropertyRefExpr> ObjCPropertyRefExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCPropertyRefExpr::static_kind():
      return reinterpret_cast<const ObjCPropertyRefExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCPropertyRefExpr> ObjCPropertyRefExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kObjCPropertyRefExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCPropertyRefExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCPropertyRefExpr> ObjCPropertyRefExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCPropertyRefExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCPropertyRefExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCPropertyRefExpr> ObjCPropertyRefExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCPropertyRefExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCPropertyRefExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCPropertyRefExpr> ObjCPropertyRefExpr::from(const Reference &r) {
  return ObjCPropertyRefExpr::from(r.as_statement());
}

std::optional<ObjCPropertyRefExpr> ObjCPropertyRefExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<ObjCPropertyRefExpr> ObjCPropertyRefExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Expr ObjCPropertyRefExpr::base(void) const {
  RawEntityId eid = impl->reader.getVal37();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

ObjCInterfaceDecl ObjCPropertyRefExpr::class_receiver(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return ObjCInterfaceDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

ObjCPropertyDecl ObjCPropertyRefExpr::explicit_property(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return ObjCPropertyDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

ObjCMethodDecl ObjCPropertyRefExpr::implicit_property_getter(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return ObjCMethodDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

ObjCMethodDecl ObjCPropertyRefExpr::implicit_property_setter(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return ObjCMethodDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Token ObjCPropertyRefExpr::token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal42());
}

Token ObjCPropertyRefExpr::receiver_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal43());
}

Type ObjCPropertyRefExpr::receiver_type(void) const {
  RawEntityId eid = impl->reader.getVal44();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type ObjCPropertyRefExpr::super_receiver_type(void) const {
  RawEntityId eid = impl->reader.getVal45();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool ObjCPropertyRefExpr::is_class_receiver(void) const {
  return impl->reader.getVal84();
}

bool ObjCPropertyRefExpr::is_explicit_property(void) const {
  return impl->reader.getVal85();
}

bool ObjCPropertyRefExpr::is_implicit_property(void) const {
  return impl->reader.getVal86();
}

bool ObjCPropertyRefExpr::is_messaging_getter(void) const {
  return impl->reader.getVal87();
}

bool ObjCPropertyRefExpr::is_messaging_setter(void) const {
  return impl->reader.getVal88();
}

bool ObjCPropertyRefExpr::is_object_receiver(void) const {
  return impl->reader.getVal89();
}

bool ObjCPropertyRefExpr::is_super_receiver(void) const {
  return impl->reader.getVal91();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
