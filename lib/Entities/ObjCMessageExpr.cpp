// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCMessageExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/ObjCInterfaceDecl.h>
#include <multiplier/Entities/ObjCMethodDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Fragment.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCMessageExpr> ObjCMessageExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCMessageExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCMessageExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCMessageExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCMessageExpr> ObjCMessageExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCMessageExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCMessageExpr> ObjCMessageExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCMessageExpr> ObjCMessageExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCMessageExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCMessageExpr> ObjCMessageExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCMessageExpr::contains(const Decl &decl) {
  for (auto &parent : ObjCMessageExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCMessageExpr::contains(const Stmt &stmt) {
  for (auto &parent : ObjCMessageExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ObjCMessageExpr> ObjCMessageExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ObjCMessageExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kObjCMessageExprDerivedKinds[] = {
    ObjCMessageExpr::static_kind(),
};

std::optional<ObjCMessageExpr> ObjCMessageExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCMessageExpr::static_kind():
      return reinterpret_cast<const ObjCMessageExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCMessageExpr> ObjCMessageExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kObjCMessageExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCMessageExpr> e = ObjCMessageExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCMessageExpr> ObjCMessageExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCMessageExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCMessageExpr> e = ObjCMessageExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCMessageExpr> ObjCMessageExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCMessageExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCMessageExpr> e = ObjCMessageExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCMessageExpr> ObjCMessageExpr::from(const Reference &r) {
  return ObjCMessageExpr::from(r.as_statement());
}

std::optional<ObjCMessageExpr> ObjCMessageExpr::from(const TokenContext &t) {
  return ObjCMessageExpr::from(t.as_statement());
}

unsigned ObjCMessageExpr::num_arguments(void) const {
  return impl->reader.getVal18().size();
}

std::optional<Expr> ObjCMessageExpr::nth_argument(unsigned n) const {
  auto list = impl->reader.getVal18();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from(Stmt(std::move(e)));
}

gap::generator<Expr> ObjCMessageExpr::arguments(void) const & {
  auto list = impl->reader.getVal18();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d18 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from(Stmt(std::move(d18)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

Type ObjCMessageExpr::call_return_type(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type ObjCMessageExpr::class_receiver(void) const {
  RawEntityId eid = impl->reader.getVal42();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type ObjCMessageExpr::class_receiver_type(void) const {
  RawEntityId eid = impl->reader.getVal43();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Expr ObjCMessageExpr::instance_receiver(void) const {
  RawEntityId eid = impl->reader.getVal44();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token ObjCMessageExpr::left_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal45());
}

ObjCMethodDecl ObjCMessageExpr::method_declaration(void) const {
  RawEntityId eid = impl->reader.getVal46();
  return ObjCMethodDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

ObjCMethodFamily ObjCMessageExpr::method_family(void) const {
  return static_cast<ObjCMethodFamily>(impl->reader.getVal97());
}

ObjCInterfaceDecl ObjCMessageExpr::receiver_interface(void) const {
  RawEntityId eid = impl->reader.getVal47();
  return ObjCInterfaceDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

ObjCMessageExprReceiverKind ObjCMessageExpr::receiver_kind(void) const {
  return static_cast<ObjCMessageExprReceiverKind>(impl->reader.getVal99());
}

TokenRange ObjCMessageExpr::receiver_range(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal48(), impl->reader.getVal49());
}

Type ObjCMessageExpr::receiver_type(void) const {
  RawEntityId eid = impl->reader.getVal50();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Token ObjCMessageExpr::right_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal51());
}

Token ObjCMessageExpr::selector_start_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal52());
}

Token ObjCMessageExpr::super_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal53());
}

Type ObjCMessageExpr::super_type(void) const {
  RawEntityId eid = impl->reader.getVal54();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool ObjCMessageExpr::is_class_message(void) const {
  return impl->reader.getVal92();
}

bool ObjCMessageExpr::is_delegate_initializer_call(void) const {
  return impl->reader.getVal93();
}

bool ObjCMessageExpr::is_implicit(void) const {
  return impl->reader.getVal94();
}

bool ObjCMessageExpr::is_instance_message(void) const {
  return impl->reader.getVal95();
}

unsigned ObjCMessageExpr::num_selector_tokens(void) const {
  return impl->reader.getVal29().size();
}

std::optional<Token> ObjCMessageExpr::nth_selector_token(unsigned n) const {
  auto list = impl->reader.getVal29();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TokenFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Token(std::move(e));
}

gap::generator<Token> ObjCMessageExpr::selector_tokens(void) const & {
  auto list = impl->reader.getVal29();
  EntityProviderPtr ep = impl->ep;
  auto fragment = ep->FragmentFor(ep, impl->fragment_id);
  if (!fragment) {
    assert(false);
    co_return;
  }
  auto tok_reader = fragment->ParsedTokenReader(fragment);
  for (auto v : list) {
    EntityId id(v);
    if (auto t29 = ep->TokenFor(ep, tok_reader, v)) {
      co_yield t29;
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
