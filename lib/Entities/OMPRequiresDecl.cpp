// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPRequiresDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/OMPDeclarativeDirectiveDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OMPRequiresDecl> OMPRequiresDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPRequiresDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPRequiresDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPRequiresDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPRequiresDecl> OMPRequiresDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = OMPRequiresDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPRequiresDecl> OMPRequiresDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPRequiresDecl> OMPRequiresDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = OMPRequiresDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPRequiresDecl> OMPRequiresDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPRequiresDecl::contains(const Decl &decl) {
  for (auto &parent : OMPRequiresDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool OMPRequiresDecl::contains(const Stmt &stmt) {
  for (auto &parent : OMPRequiresDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<OMPRequiresDecl> OMPRequiresDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<OMPRequiresDecl> dr = OMPRequiresDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<OMPRequiresDecl> OMPRequiresDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return OMPRequiresDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kOMPRequiresDeclDerivedKinds[] = {
    OMPRequiresDecl::static_kind(),
};

std::optional<OMPRequiresDecl> OMPRequiresDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case OMPRequiresDecl::static_kind():
      return reinterpret_cast<const OMPRequiresDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPRequiresDecl> OMPRequiresDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kOMPRequiresDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<OMPRequiresDecl> e = OMPRequiresDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPRequiresDecl> OMPRequiresDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kOMPRequiresDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<OMPRequiresDecl> e = OMPRequiresDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPRequiresDecl> OMPRequiresDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kOMPRequiresDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<OMPRequiresDecl> e = OMPRequiresDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPRequiresDecl> OMPRequiresDecl::from(const Reference &r) {
  return OMPRequiresDecl::from(r.as_declaration());
}

std::optional<OMPRequiresDecl> OMPRequiresDecl::from(const TokenContext &t) {
  return OMPRequiresDecl::from(t.as_declaration());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
