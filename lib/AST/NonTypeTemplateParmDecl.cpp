// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/NonTypeTemplateParmDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/DeclaratorDecl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/ValueDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kNonTypeTemplateParmDeclDerivedKinds[] = {
    NonTypeTemplateParmDecl::static_kind(),
};
}  // namespace

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

std::optional<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<NonTypeTemplateParmDecl, ir::Operation>> NonTypeTemplateParmDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kNonTypeTemplateParmDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<NonTypeTemplateParmDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (NonTypeTemplateParmDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<NonTypeTemplateParmDecl> dr = from_base(r)) {
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
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::from_base(const Decl &parent) {
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
      if (std::optional<NonTypeTemplateParmDecl> e = from_base(std::move(eptr))) {
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
      if (std::optional<NonTypeTemplateParmDecl> e = from_base(std::move(eptr))) {
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
        if (std::optional<NonTypeTemplateParmDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::from(const Reference &r) {
  return NonTypeTemplateParmDecl::from(r.as_declaration());
}

std::optional<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
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
      return Expr::from_base(std::move(eptr));
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
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool NonTypeTemplateParmDecl::has_default_argument(void) const {
  return impl->reader.getVal77();
}

bool NonTypeTemplateParmDecl::has_placeholder_type_constraint(void) const {
  return impl->reader.getVal93();
}

bool NonTypeTemplateParmDecl::is_expanded_parameter_pack(void) const {
  return impl->reader.getVal94();
}

bool NonTypeTemplateParmDecl::is_pack_expansion(void) const {
  return impl->reader.getVal95();
}

unsigned NonTypeTemplateParmDecl::num_expansion_types(void) const {
  return impl->reader.getVal51().size();
}

std::optional<Type> NonTypeTemplateParmDecl::nth_expansion_type(unsigned n) const {
  auto list = impl->reader.getVal51();
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
  auto list = impl->reader.getVal51();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d51 = ep->TypeFor(ep, v)) {
      co_yield Type(std::move(d51));
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
