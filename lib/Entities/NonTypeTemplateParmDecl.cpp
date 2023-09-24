// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/NonTypeTemplateParmDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DeclaratorDecl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/ValueDecl.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = NonTypeTemplateParmDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool NonTypeTemplateParmDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : NonTypeTemplateParmDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = NonTypeTemplateParmDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = NonTypeTemplateParmDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool NonTypeTemplateParmDecl::contains(const Decl &decl) {
  for (auto &parent : NonTypeTemplateParmDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool NonTypeTemplateParmDecl::contains(const Stmt &stmt) {
  for (auto &parent : NonTypeTemplateParmDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

NonTypeTemplateParmDecl NonTypeTemplateParmDecl::canonical_declaration(void) const {
  if (auto canon = NonTypeTemplateParmDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (NonTypeTemplateParmDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::definition(void) const {
  return NonTypeTemplateParmDecl::from(this->Decl::definition());
}

gap::generator<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<NonTypeTemplateParmDecl> dr = NonTypeTemplateParmDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return NonTypeTemplateParmDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kNonTypeTemplateParmDeclDerivedKinds[] = {
    NonTypeTemplateParmDecl::static_kind(),
};

std::optional<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case NonTypeTemplateParmDecl::static_kind():
      return reinterpret_cast<const NonTypeTemplateParmDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kNonTypeTemplateParmDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<NonTypeTemplateParmDecl> e = NonTypeTemplateParmDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kNonTypeTemplateParmDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<NonTypeTemplateParmDecl> e = NonTypeTemplateParmDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kNonTypeTemplateParmDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<NonTypeTemplateParmDecl> e = NonTypeTemplateParmDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::from(const Reference &r) {
  return NonTypeTemplateParmDecl::from(r.as_declaration());
}

std::optional<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::from(const TokenContext &t) {
  return NonTypeTemplateParmDecl::from(t.as_declaration());
}

bool NonTypeTemplateParmDecl::default_argument_was_inherited(void) const {
  return impl->reader.getVal76();
}

std::optional<Expr> NonTypeTemplateParmDecl::default_argument(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal79();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

Token NonTypeTemplateParmDecl::default_argument_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal81());
}

std::optional<Expr> NonTypeTemplateParmDecl::placeholder_type_constraint(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal82();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

bool NonTypeTemplateParmDecl::has_default_argument(void) const {
  return impl->reader.getVal77();
}

bool NonTypeTemplateParmDecl::has_placeholder_type_constraint(void) const {
  return impl->reader.getVal94();
}

bool NonTypeTemplateParmDecl::is_expanded_parameter_pack(void) const {
  return impl->reader.getVal95();
}

bool NonTypeTemplateParmDecl::is_pack_expansion(void) const {
  return impl->reader.getVal96();
}

unsigned NonTypeTemplateParmDecl::num_expansion_types(void) const {
  return impl->reader.getVal52().size();
}

std::optional<Type> NonTypeTemplateParmDecl::nth_expansion_type(unsigned n) const {
  auto list = impl->reader.getVal52();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TypeFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Type(std::move(e));
}

gap::generator<Type> NonTypeTemplateParmDecl::expansion_types(void) const & {
  auto list = impl->reader.getVal52();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d52 = ep->TypeFor(ep, v)) {
      co_yield Type(std::move(d52));
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
