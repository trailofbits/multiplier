// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/MSPropertyDecl.h>

#include <multiplier/AST/Decl.h>
#include <multiplier/AST/DeclaratorDecl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/Token.h>
#include <multiplier/AST/ValueDecl.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<MSPropertyDecl> MSPropertyDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = MSPropertyDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool MSPropertyDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : MSPropertyDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<MSPropertyDecl> MSPropertyDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = MSPropertyDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<MSPropertyDecl> MSPropertyDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<MSPropertyDecl> MSPropertyDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = MSPropertyDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<MSPropertyDecl> MSPropertyDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool MSPropertyDecl::contains(const Decl &decl) {
  for (auto &parent : MSPropertyDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool MSPropertyDecl::contains(const Stmt &stmt) {
  for (auto &parent : MSPropertyDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

MSPropertyDecl MSPropertyDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (MSPropertyDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<MSPropertyDecl> MSPropertyDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<MSPropertyDecl> MSPropertyDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<MSPropertyDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<MSPropertyDecl> MSPropertyDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<MSPropertyDecl> MSPropertyDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const DeclKind kMSPropertyDeclDerivedKinds[] = {
    MSPropertyDecl::static_kind(),
};

}  // namespace

std::optional<MSPropertyDecl> MSPropertyDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case MSPropertyDecl::static_kind():
      return reinterpret_cast<const MSPropertyDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<MSPropertyDecl> MSPropertyDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kMSPropertyDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<MSPropertyDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MSPropertyDecl> MSPropertyDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kMSPropertyDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<MSPropertyDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MSPropertyDecl> MSPropertyDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kMSPropertyDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<MSPropertyDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<MSPropertyDecl> MSPropertyDecl::from(const Reference &r) {
  return MSPropertyDecl::from(r.as_declaration());
}

std::optional<MSPropertyDecl> MSPropertyDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<MSPropertyDecl> MSPropertyDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

bool MSPropertyDecl::has_getter(void) const {
  return impl->reader.getVal76();
}

bool MSPropertyDecl::has_setter(void) const {
  return impl->reader.getVal77();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
