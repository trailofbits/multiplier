// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MSGuidDecl.h>

#include <multiplier/Entities/Decl.h>
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

gap::generator<MSGuidDecl> MSGuidDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = MSGuidDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool MSGuidDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : MSGuidDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<MSGuidDecl> MSGuidDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = MSGuidDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<MSGuidDecl> MSGuidDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<MSGuidDecl> MSGuidDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = MSGuidDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<MSGuidDecl> MSGuidDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool MSGuidDecl::contains(const Decl &decl) {
  for (auto &parent : MSGuidDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool MSGuidDecl::contains(const Stmt &stmt) {
  for (auto &parent : MSGuidDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

MSGuidDecl MSGuidDecl::canonical_declaration(void) const {
  if (auto canon = MSGuidDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (MSGuidDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<MSGuidDecl> MSGuidDecl::definition(void) const {
  return MSGuidDecl::from(this->Decl::definition());
}

gap::generator<MSGuidDecl> MSGuidDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<MSGuidDecl> dr = MSGuidDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<MSGuidDecl> MSGuidDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return MSGuidDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kMSGuidDeclDerivedKinds[] = {
    MSGuidDecl::static_kind(),
};

std::optional<MSGuidDecl> MSGuidDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case MSGuidDecl::static_kind():
      return reinterpret_cast<const MSGuidDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<MSGuidDecl> MSGuidDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kMSGuidDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<MSGuidDecl> e = MSGuidDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MSGuidDecl> MSGuidDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kMSGuidDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<MSGuidDecl> e = MSGuidDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MSGuidDecl> MSGuidDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kMSGuidDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<MSGuidDecl> e = MSGuidDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<MSGuidDecl> MSGuidDecl::from(const Reference &r) {
  return MSGuidDecl::from(r.as_declaration());
}

std::optional<MSGuidDecl> MSGuidDecl::from(const TokenContext &t) {
  return MSGuidDecl::from(t.as_declaration());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
