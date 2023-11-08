// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/EmptyDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<EmptyDecl> EmptyDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = EmptyDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool EmptyDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : EmptyDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<EmptyDecl> EmptyDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = EmptyDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<EmptyDecl> EmptyDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<EmptyDecl> EmptyDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = EmptyDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<EmptyDecl> EmptyDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool EmptyDecl::contains(const Decl &decl) {
  for (auto &parent : EmptyDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool EmptyDecl::contains(const Stmt &stmt) {
  for (auto &parent : EmptyDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

EmptyDecl EmptyDecl::canonical_declaration(void) const {
  if (auto canon = EmptyDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (EmptyDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<EmptyDecl> EmptyDecl::definition(void) const {
  return EmptyDecl::from(this->Decl::definition());
}

gap::generator<EmptyDecl> EmptyDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<EmptyDecl> dr = EmptyDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<EmptyDecl> EmptyDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return EmptyDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kEmptyDeclDerivedKinds[] = {
    EmptyDecl::static_kind(),
};

std::optional<EmptyDecl> EmptyDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case EmptyDecl::static_kind():
      return reinterpret_cast<const EmptyDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<EmptyDecl> EmptyDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kEmptyDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<EmptyDecl> e = EmptyDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<EmptyDecl> EmptyDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kEmptyDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<EmptyDecl> e = EmptyDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<EmptyDecl> EmptyDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kEmptyDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<EmptyDecl> e = EmptyDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<EmptyDecl> EmptyDecl::from(const Reference &r) {
  return EmptyDecl::from(r.as_declaration());
}

std::optional<EmptyDecl> EmptyDecl::from(const TokenContext &t) {
  return EmptyDecl::from(t.as_declaration());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
