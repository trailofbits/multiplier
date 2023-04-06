// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ExternCContextDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ExternCContextDecl> ExternCContextDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ExternCContextDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ExternCContextDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ExternCContextDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ExternCContextDecl> ExternCContextDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ExternCContextDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ExternCContextDecl> ExternCContextDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ExternCContextDecl> ExternCContextDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ExternCContextDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ExternCContextDecl> ExternCContextDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ExternCContextDecl::contains(const Decl &decl) {
  for (auto &parent : ExternCContextDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ExternCContextDecl::contains(const Stmt &stmt) {
  for (auto &parent : ExternCContextDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

ExternCContextDecl ExternCContextDecl::canonical_declaration(void) const {
  if (auto canon = ExternCContextDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ExternCContextDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ExternCContextDecl> ExternCContextDecl::definition(void) const {
  return ExternCContextDecl::from(this->Decl::definition());
}

gap::generator<ExternCContextDecl> ExternCContextDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ExternCContextDecl> dr = ExternCContextDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ExternCContextDecl> ExternCContextDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ExternCContextDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kExternCContextDeclDerivedKinds[] = {
    ExternCContextDecl::static_kind(),
};

std::optional<ExternCContextDecl> ExternCContextDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ExternCContextDecl::static_kind():
      return reinterpret_cast<const ExternCContextDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ExternCContextDecl> ExternCContextDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kExternCContextDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ExternCContextDecl> e = ExternCContextDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ExternCContextDecl> ExternCContextDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kExternCContextDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ExternCContextDecl> e = ExternCContextDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ExternCContextDecl> ExternCContextDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kExternCContextDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ExternCContextDecl> e = ExternCContextDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ExternCContextDecl> ExternCContextDecl::from(const Reference &r) {
  return ExternCContextDecl::from(r.as_declaration());
}

std::optional<ExternCContextDecl> ExternCContextDecl::from(const TokenContext &t) {
  return ExternCContextDecl::from(t.as_declaration());
}

gap::generator<Decl> ExternCContextDecl::declarations_in_context(void) const & {
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
