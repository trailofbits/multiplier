// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPDeclareMapperDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/OMPDeclarativeDirectiveValueDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueDecl.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OMPDeclareMapperDecl> OMPDeclareMapperDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPDeclareMapperDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPDeclareMapperDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPDeclareMapperDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPDeclareMapperDecl> OMPDeclareMapperDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = OMPDeclareMapperDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPDeclareMapperDecl> OMPDeclareMapperDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPDeclareMapperDecl> OMPDeclareMapperDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = OMPDeclareMapperDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPDeclareMapperDecl> OMPDeclareMapperDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPDeclareMapperDecl::contains(const Decl &decl) {
  for (auto &parent : OMPDeclareMapperDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPDeclareMapperDecl::contains(const Stmt &stmt) {
  for (auto &parent : OMPDeclareMapperDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

OMPDeclareMapperDecl OMPDeclareMapperDecl::canonical_declaration(void) const {
  if (auto canon = OMPDeclareMapperDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (OMPDeclareMapperDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<OMPDeclareMapperDecl> OMPDeclareMapperDecl::definition(void) const {
  return OMPDeclareMapperDecl::from(this->Decl::definition());
}

gap::generator<OMPDeclareMapperDecl> OMPDeclareMapperDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<OMPDeclareMapperDecl> dr = OMPDeclareMapperDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<OMPDeclareMapperDecl> OMPDeclareMapperDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return OMPDeclareMapperDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kOMPDeclareMapperDeclDerivedKinds[] = {
    OMPDeclareMapperDecl::static_kind(),
};

std::optional<OMPDeclareMapperDecl> OMPDeclareMapperDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case OMPDeclareMapperDecl::static_kind():
      return reinterpret_cast<const OMPDeclareMapperDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPDeclareMapperDecl> OMPDeclareMapperDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kOMPDeclareMapperDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<OMPDeclareMapperDecl> e = OMPDeclareMapperDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDeclareMapperDecl> OMPDeclareMapperDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kOMPDeclareMapperDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<OMPDeclareMapperDecl> e = OMPDeclareMapperDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDeclareMapperDecl> OMPDeclareMapperDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kOMPDeclareMapperDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<OMPDeclareMapperDecl> e = OMPDeclareMapperDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPDeclareMapperDecl> OMPDeclareMapperDecl::from(const Reference &r) {
  return OMPDeclareMapperDecl::from(r.as_declaration());
}

std::optional<OMPDeclareMapperDecl> OMPDeclareMapperDecl::from(const TokenContext &t) {
  return OMPDeclareMapperDecl::from(t.as_declaration());
}

Expr OMPDeclareMapperDecl::mapper_variable_reference(void) const {
  RawEntityId eid = impl->reader.getVal56();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

gap::generator<Decl> OMPDeclareMapperDecl::declarations_in_context(void) const & {
  EntityProviderPtr ep = impl->ep;
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
