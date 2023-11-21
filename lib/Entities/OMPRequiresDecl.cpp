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

#include "../EntityProvider.h"
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
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPRequiresDecl::contains(const Stmt &stmt) {
  for (auto &parent : OMPRequiresDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

OMPRequiresDecl OMPRequiresDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (OMPRequiresDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<OMPRequiresDecl> OMPRequiresDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<OMPRequiresDecl> OMPRequiresDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<OMPRequiresDecl> dr = from_base(r)) {
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
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<OMPRequiresDecl> OMPRequiresDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const DeclKind kOMPRequiresDeclDerivedKinds[] = {
    OMPRequiresDecl::static_kind(),
};

}  // namespace

std::optional<OMPRequiresDecl> OMPRequiresDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case OMPRequiresDecl::static_kind():
      return reinterpret_cast<const OMPRequiresDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPRequiresDecl> OMPRequiresDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kOMPRequiresDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<OMPRequiresDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPRequiresDecl> OMPRequiresDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kOMPRequiresDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<OMPRequiresDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPRequiresDecl> OMPRequiresDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kOMPRequiresDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<OMPRequiresDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPRequiresDecl> OMPRequiresDecl::from(const Reference &r) {
  return OMPRequiresDecl::from(r.as_declaration());
}

std::optional<OMPRequiresDecl> OMPRequiresDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<OMPRequiresDecl> OMPRequiresDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
