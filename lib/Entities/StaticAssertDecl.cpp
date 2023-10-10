// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/StaticAssertDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<StaticAssertDecl> StaticAssertDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = StaticAssertDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool StaticAssertDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : StaticAssertDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<StaticAssertDecl> StaticAssertDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = StaticAssertDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<StaticAssertDecl> StaticAssertDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<StaticAssertDecl> StaticAssertDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = StaticAssertDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<StaticAssertDecl> StaticAssertDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool StaticAssertDecl::contains(const Decl &decl) {
  for (auto &parent : StaticAssertDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool StaticAssertDecl::contains(const Stmt &stmt) {
  for (auto &parent : StaticAssertDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

StaticAssertDecl StaticAssertDecl::canonical_declaration(void) const {
  if (auto canon = StaticAssertDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (StaticAssertDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<StaticAssertDecl> StaticAssertDecl::definition(void) const {
  return StaticAssertDecl::from(this->Decl::definition());
}

gap::generator<StaticAssertDecl> StaticAssertDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<StaticAssertDecl> dr = StaticAssertDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<StaticAssertDecl> StaticAssertDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return StaticAssertDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kStaticAssertDeclDerivedKinds[] = {
    StaticAssertDecl::static_kind(),
};

std::optional<StaticAssertDecl> StaticAssertDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case StaticAssertDecl::static_kind():
      return reinterpret_cast<const StaticAssertDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<StaticAssertDecl> StaticAssertDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kStaticAssertDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<StaticAssertDecl> e = StaticAssertDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<StaticAssertDecl> StaticAssertDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kStaticAssertDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<StaticAssertDecl> e = StaticAssertDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<StaticAssertDecl> StaticAssertDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kStaticAssertDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<StaticAssertDecl> e = StaticAssertDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<StaticAssertDecl> StaticAssertDecl::from(const Reference &r) {
  return StaticAssertDecl::from(r.as_declaration());
}

std::optional<StaticAssertDecl> StaticAssertDecl::from(const TokenContext &t) {
  return StaticAssertDecl::from(t.as_declaration());
}

Expr StaticAssertDecl::assert_expression(void) const {
  RawEntityId eid = impl->reader.getVal49();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr StaticAssertDecl::message(void) const {
  RawEntityId eid = impl->reader.getVal56();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token StaticAssertDecl::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal57());
}

bool StaticAssertDecl::is_failed(void) const {
  return impl->reader.getVal50();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
