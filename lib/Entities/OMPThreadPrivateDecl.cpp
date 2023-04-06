// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPThreadPrivateDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/OMPDeclarativeDirectiveDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OMPThreadPrivateDecl> OMPThreadPrivateDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPThreadPrivateDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPThreadPrivateDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPThreadPrivateDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPThreadPrivateDecl> OMPThreadPrivateDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = OMPThreadPrivateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPThreadPrivateDecl> OMPThreadPrivateDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPThreadPrivateDecl> OMPThreadPrivateDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = OMPThreadPrivateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPThreadPrivateDecl> OMPThreadPrivateDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPThreadPrivateDecl::contains(const Decl &decl) {
  for (auto &parent : OMPThreadPrivateDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool OMPThreadPrivateDecl::contains(const Stmt &stmt) {
  for (auto &parent : OMPThreadPrivateDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

OMPThreadPrivateDecl OMPThreadPrivateDecl::canonical_declaration(void) const {
  if (auto canon = OMPThreadPrivateDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (OMPThreadPrivateDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<OMPThreadPrivateDecl> OMPThreadPrivateDecl::definition(void) const {
  return OMPThreadPrivateDecl::from(this->Decl::definition());
}

gap::generator<OMPThreadPrivateDecl> OMPThreadPrivateDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<OMPThreadPrivateDecl> dr = OMPThreadPrivateDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<OMPThreadPrivateDecl> OMPThreadPrivateDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return OMPThreadPrivateDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kOMPThreadPrivateDeclDerivedKinds[] = {
    OMPThreadPrivateDecl::static_kind(),
};

std::optional<OMPThreadPrivateDecl> OMPThreadPrivateDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case OMPThreadPrivateDecl::static_kind():
      return reinterpret_cast<const OMPThreadPrivateDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPThreadPrivateDecl> OMPThreadPrivateDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kOMPThreadPrivateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<OMPThreadPrivateDecl> e = OMPThreadPrivateDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPThreadPrivateDecl> OMPThreadPrivateDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kOMPThreadPrivateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<OMPThreadPrivateDecl> e = OMPThreadPrivateDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPThreadPrivateDecl> OMPThreadPrivateDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kOMPThreadPrivateDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<OMPThreadPrivateDecl> e = OMPThreadPrivateDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPThreadPrivateDecl> OMPThreadPrivateDecl::from(const Reference &r) {
  return OMPThreadPrivateDecl::from(r.as_declaration());
}

std::optional<OMPThreadPrivateDecl> OMPThreadPrivateDecl::from(const TokenContext &t) {
  return OMPThreadPrivateDecl::from(t.as_declaration());
}

unsigned OMPThreadPrivateDecl::num_varlists(void) const {
  return impl->reader.getVal49().size();
}

std::optional<Expr> OMPThreadPrivateDecl::nth_varlist(unsigned n) const {
  auto list = impl->reader.getVal49();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from(Stmt(std::move(e)));
}

gap::generator<Expr> OMPThreadPrivateDecl::varlists(void) const & {
  auto list = impl->reader.getVal49();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d49 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from(Stmt(std::move(d49)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
