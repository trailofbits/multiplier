// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCAtDefsFieldDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DeclaratorDecl.h>
#include <multiplier/Entities/FieldDecl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueDecl.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCAtDefsFieldDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCAtDefsFieldDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCAtDefsFieldDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCAtDefsFieldDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCAtDefsFieldDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCAtDefsFieldDecl::contains(const Decl &decl) {
  for (auto &parent : ObjCAtDefsFieldDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ObjCAtDefsFieldDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCAtDefsFieldDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

ObjCAtDefsFieldDecl ObjCAtDefsFieldDecl::canonical_declaration(void) const {
  if (auto canon = ObjCAtDefsFieldDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ObjCAtDefsFieldDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::definition(void) const {
  return ObjCAtDefsFieldDecl::from(this->Decl::definition());
}

gap::generator<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCAtDefsFieldDecl> dr = ObjCAtDefsFieldDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ObjCAtDefsFieldDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kObjCAtDefsFieldDeclDerivedKinds[] = {
    ObjCAtDefsFieldDecl::static_kind(),
};

std::optional<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCAtDefsFieldDecl::static_kind():
      return reinterpret_cast<const ObjCAtDefsFieldDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kObjCAtDefsFieldDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCAtDefsFieldDecl> e = ObjCAtDefsFieldDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCAtDefsFieldDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCAtDefsFieldDecl> e = ObjCAtDefsFieldDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCAtDefsFieldDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCAtDefsFieldDecl> e = ObjCAtDefsFieldDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::from(const Reference &r) {
  return ObjCAtDefsFieldDecl::from(r.as_declaration());
}

std::optional<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::from(const TokenContext &t) {
  return ObjCAtDefsFieldDecl::from(t.as_declaration());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
