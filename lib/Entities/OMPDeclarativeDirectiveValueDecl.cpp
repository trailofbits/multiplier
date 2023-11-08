// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPDeclarativeDirectiveValueDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/OMPDeclareMapperDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueDecl.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPDeclarativeDirectiveValueDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPDeclarativeDirectiveValueDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPDeclarativeDirectiveValueDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = OMPDeclarativeDirectiveValueDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = OMPDeclarativeDirectiveValueDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPDeclarativeDirectiveValueDecl::contains(const Decl &decl) {
  for (auto &parent : OMPDeclarativeDirectiveValueDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPDeclarativeDirectiveValueDecl::contains(const Stmt &stmt) {
  for (auto &parent : OMPDeclarativeDirectiveValueDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

OMPDeclarativeDirectiveValueDecl OMPDeclarativeDirectiveValueDecl::canonical_declaration(void) const {
  if (auto canon = OMPDeclarativeDirectiveValueDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (OMPDeclarativeDirectiveValueDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::definition(void) const {
  return OMPDeclarativeDirectiveValueDecl::from(this->Decl::definition());
}

gap::generator<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<OMPDeclarativeDirectiveValueDecl> dr = OMPDeclarativeDirectiveValueDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return OMPDeclarativeDirectiveValueDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kOMPDeclarativeDirectiveValueDeclDerivedKinds[] = {
    OMPDeclareMapperDecl::static_kind(),
};

std::optional<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case OMPDeclareMapperDecl::static_kind():
      return reinterpret_cast<const OMPDeclarativeDirectiveValueDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kOMPDeclarativeDirectiveValueDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<OMPDeclarativeDirectiveValueDecl> e = OMPDeclarativeDirectiveValueDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kOMPDeclarativeDirectiveValueDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<OMPDeclarativeDirectiveValueDecl> e = OMPDeclarativeDirectiveValueDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kOMPDeclarativeDirectiveValueDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<OMPDeclarativeDirectiveValueDecl> e = OMPDeclarativeDirectiveValueDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::from(const Reference &r) {
  return OMPDeclarativeDirectiveValueDecl::from(r.as_declaration());
}

std::optional<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::from(const TokenContext &t) {
  return OMPDeclarativeDirectiveValueDecl::from(t.as_declaration());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
