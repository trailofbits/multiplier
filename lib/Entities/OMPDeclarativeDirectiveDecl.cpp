// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPDeclarativeDirectiveDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/OMPAllocateDecl.h>
#include <multiplier/Entities/OMPRequiresDecl.h>
#include <multiplier/Entities/OMPThreadPrivateDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OMPDeclarativeDirectiveDecl> OMPDeclarativeDirectiveDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPDeclarativeDirectiveDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPDeclarativeDirectiveDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPDeclarativeDirectiveDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPDeclarativeDirectiveDecl> OMPDeclarativeDirectiveDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = OMPDeclarativeDirectiveDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPDeclarativeDirectiveDecl> OMPDeclarativeDirectiveDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPDeclarativeDirectiveDecl> OMPDeclarativeDirectiveDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = OMPDeclarativeDirectiveDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPDeclarativeDirectiveDecl> OMPDeclarativeDirectiveDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPDeclarativeDirectiveDecl::contains(const Decl &decl) {
  for (auto &parent : OMPDeclarativeDirectiveDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool OMPDeclarativeDirectiveDecl::contains(const Stmt &stmt) {
  for (auto &parent : OMPDeclarativeDirectiveDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

OMPDeclarativeDirectiveDecl OMPDeclarativeDirectiveDecl::canonical_declaration(void) const {
  if (auto canon = OMPDeclarativeDirectiveDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (OMPDeclarativeDirectiveDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<OMPDeclarativeDirectiveDecl> OMPDeclarativeDirectiveDecl::definition(void) const {
  return OMPDeclarativeDirectiveDecl::from(this->Decl::definition());
}

gap::generator<OMPDeclarativeDirectiveDecl> OMPDeclarativeDirectiveDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<OMPDeclarativeDirectiveDecl> dr = OMPDeclarativeDirectiveDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<OMPDeclarativeDirectiveDecl> OMPDeclarativeDirectiveDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return OMPDeclarativeDirectiveDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kOMPDeclarativeDirectiveDeclDerivedKinds[] = {
    OMPAllocateDecl::static_kind(),
    OMPRequiresDecl::static_kind(),
    OMPThreadPrivateDecl::static_kind(),
};

std::optional<OMPDeclarativeDirectiveDecl> OMPDeclarativeDirectiveDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case OMPAllocateDecl::static_kind():
    case OMPRequiresDecl::static_kind():
    case OMPThreadPrivateDecl::static_kind():
      return reinterpret_cast<const OMPDeclarativeDirectiveDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPDeclarativeDirectiveDecl> OMPDeclarativeDirectiveDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kOMPDeclarativeDirectiveDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<OMPDeclarativeDirectiveDecl> e = OMPDeclarativeDirectiveDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDeclarativeDirectiveDecl> OMPDeclarativeDirectiveDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kOMPDeclarativeDirectiveDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<OMPDeclarativeDirectiveDecl> e = OMPDeclarativeDirectiveDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDeclarativeDirectiveDecl> OMPDeclarativeDirectiveDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kOMPDeclarativeDirectiveDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<OMPDeclarativeDirectiveDecl> e = OMPDeclarativeDirectiveDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPDeclarativeDirectiveDecl> OMPDeclarativeDirectiveDecl::from(const Reference &r) {
  return OMPDeclarativeDirectiveDecl::from(r.as_declaration());
}

std::optional<OMPDeclarativeDirectiveDecl> OMPDeclarativeDirectiveDecl::from(const TokenContext &t) {
  return OMPDeclarativeDirectiveDecl::from(t.as_declaration());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
