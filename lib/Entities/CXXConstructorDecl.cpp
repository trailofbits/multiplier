// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXConstructorDecl.h>

#include <multiplier/Entities/CXXMethodDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DeclaratorDecl.h>
#include <multiplier/Entities/FunctionDecl.h>
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

gap::generator<CXXConstructorDecl> CXXConstructorDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXConstructorDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXConstructorDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXConstructorDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXConstructorDecl> CXXConstructorDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = CXXConstructorDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXConstructorDecl> CXXConstructorDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXConstructorDecl> CXXConstructorDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = CXXConstructorDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXConstructorDecl> CXXConstructorDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXConstructorDecl::contains(const Decl &decl) {
  for (auto &parent : CXXConstructorDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXConstructorDecl::contains(const Stmt &stmt) {
  for (auto &parent : CXXConstructorDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

CXXConstructorDecl CXXConstructorDecl::canonical_declaration(void) const {
  if (auto canon = CXXConstructorDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (CXXConstructorDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::definition(void) const {
  return CXXConstructorDecl::from(this->Decl::definition());
}

gap::generator<CXXConstructorDecl> CXXConstructorDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<CXXConstructorDecl> dr = CXXConstructorDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return CXXConstructorDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kCXXConstructorDeclDerivedKinds[] = {
    CXXConstructorDecl::static_kind(),
};

std::optional<CXXConstructorDecl> CXXConstructorDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case CXXConstructorDecl::static_kind():
      return reinterpret_cast<const CXXConstructorDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXConstructorDecl> CXXConstructorDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kCXXConstructorDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<CXXConstructorDecl> e = CXXConstructorDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXConstructorDecl> CXXConstructorDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kCXXConstructorDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<CXXConstructorDecl> e = CXXConstructorDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXConstructorDecl> CXXConstructorDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kCXXConstructorDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<CXXConstructorDecl> e = CXXConstructorDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::from(const Reference &r) {
  return CXXConstructorDecl::from(r.as_declaration());
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::from(const TokenContext &t) {
  return CXXConstructorDecl::from(t.as_declaration());
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::target_constructor(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal176();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return CXXConstructorDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

bool CXXConstructorDecl::is_default_constructor(void) const {
  return impl->reader.getVal178();
}

bool CXXConstructorDecl::is_delegating_constructor(void) const {
  return impl->reader.getVal179();
}

bool CXXConstructorDecl::is_explicit(void) const {
  return impl->reader.getVal180();
}

bool CXXConstructorDecl::is_inheriting_constructor(void) const {
  return impl->reader.getVal181();
}

bool CXXConstructorDecl::is_specialization_copying_object(void) const {
  return impl->reader.getVal182();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
