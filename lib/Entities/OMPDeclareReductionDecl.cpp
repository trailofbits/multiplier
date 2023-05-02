// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPDeclareReductionDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueDecl.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OMPDeclareReductionDecl> OMPDeclareReductionDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPDeclareReductionDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPDeclareReductionDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPDeclareReductionDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPDeclareReductionDecl> OMPDeclareReductionDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = OMPDeclareReductionDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPDeclareReductionDecl> OMPDeclareReductionDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPDeclareReductionDecl> OMPDeclareReductionDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = OMPDeclareReductionDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPDeclareReductionDecl> OMPDeclareReductionDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPDeclareReductionDecl::contains(const Decl &decl) {
  for (auto &parent : OMPDeclareReductionDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPDeclareReductionDecl::contains(const Stmt &stmt) {
  for (auto &parent : OMPDeclareReductionDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

OMPDeclareReductionDecl OMPDeclareReductionDecl::canonical_declaration(void) const {
  if (auto canon = OMPDeclareReductionDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (OMPDeclareReductionDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<OMPDeclareReductionDecl> OMPDeclareReductionDecl::definition(void) const {
  return OMPDeclareReductionDecl::from(this->Decl::definition());
}

gap::generator<OMPDeclareReductionDecl> OMPDeclareReductionDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<OMPDeclareReductionDecl> dr = OMPDeclareReductionDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<OMPDeclareReductionDecl> OMPDeclareReductionDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return OMPDeclareReductionDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kOMPDeclareReductionDeclDerivedKinds[] = {
    OMPDeclareReductionDecl::static_kind(),
};

std::optional<OMPDeclareReductionDecl> OMPDeclareReductionDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case OMPDeclareReductionDecl::static_kind():
      return reinterpret_cast<const OMPDeclareReductionDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPDeclareReductionDecl> OMPDeclareReductionDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kOMPDeclareReductionDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<OMPDeclareReductionDecl> e = OMPDeclareReductionDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDeclareReductionDecl> OMPDeclareReductionDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kOMPDeclareReductionDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<OMPDeclareReductionDecl> e = OMPDeclareReductionDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDeclareReductionDecl> OMPDeclareReductionDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kOMPDeclareReductionDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<OMPDeclareReductionDecl> e = OMPDeclareReductionDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPDeclareReductionDecl> OMPDeclareReductionDecl::from(const Reference &r) {
  return OMPDeclareReductionDecl::from(r.as_declaration());
}

std::optional<OMPDeclareReductionDecl> OMPDeclareReductionDecl::from(const TokenContext &t) {
  return OMPDeclareReductionDecl::from(t.as_declaration());
}

Expr OMPDeclareReductionDecl::combiner(void) const {
  RawEntityId eid = impl->reader.getVal56();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr OMPDeclareReductionDecl::combiner_in(void) const {
  RawEntityId eid = impl->reader.getVal64();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr OMPDeclareReductionDecl::combiner_out(void) const {
  RawEntityId eid = impl->reader.getVal65();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr OMPDeclareReductionDecl::initializer_original(void) const {
  RawEntityId eid = impl->reader.getVal66();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr OMPDeclareReductionDecl::initializer_private(void) const {
  RawEntityId eid = impl->reader.getVal76();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr OMPDeclareReductionDecl::initializer(void) const {
  RawEntityId eid = impl->reader.getVal77();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

OMPDeclareReductionDeclInitKind OMPDeclareReductionDecl::initializer_kind(void) const {
  return static_cast<OMPDeclareReductionDeclInitKind>(impl->reader.getVal78());
}

gap::generator<Decl> OMPDeclareReductionDecl::declarations_in_context(void) const & {
  EntityProvider::Ptr ep = impl->ep;
  auto list = impl->reader.getVal49();
  for (auto v : list) {
    if (auto eptr = ep->DeclFor(ep, v)) {
      co_yield std::move(eptr);
    }
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
