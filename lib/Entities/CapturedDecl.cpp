// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CapturedDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/ImplicitParamDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CapturedDecl> CapturedDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CapturedDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CapturedDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CapturedDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CapturedDecl> CapturedDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = CapturedDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CapturedDecl> CapturedDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CapturedDecl> CapturedDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = CapturedDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CapturedDecl> CapturedDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CapturedDecl::contains(const Decl &decl) {
  for (auto &parent : CapturedDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CapturedDecl::contains(const Stmt &stmt) {
  for (auto &parent : CapturedDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

CapturedDecl CapturedDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (CapturedDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<CapturedDecl> CapturedDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<CapturedDecl> CapturedDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<CapturedDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<CapturedDecl> CapturedDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<CapturedDecl> CapturedDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const DeclKind kCapturedDeclDerivedKinds[] = {
    CapturedDecl::static_kind(),
};

}  // namespace

std::optional<CapturedDecl> CapturedDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case CapturedDecl::static_kind():
      return reinterpret_cast<const CapturedDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CapturedDecl> CapturedDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kCapturedDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<CapturedDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CapturedDecl> CapturedDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kCapturedDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<CapturedDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CapturedDecl> CapturedDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kCapturedDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<CapturedDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CapturedDecl> CapturedDecl::from(const Reference &r) {
  return CapturedDecl::from(r.as_declaration());
}

std::optional<CapturedDecl> CapturedDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<CapturedDecl> CapturedDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

ImplicitParamDecl CapturedDecl::context_parameter(void) const {
  RawEntityId eid = impl->reader.getVal49();
  return ImplicitParamDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

bool CapturedDecl::is_nothrow(void) const {
  return impl->reader.getVal50();
}

unsigned CapturedDecl::num_parameters(void) const {
  return impl->reader.getVal51().size();
}

std::optional<ImplicitParamDecl> CapturedDecl::nth_parameter(unsigned n) const {
  auto list = impl->reader.getVal51();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ImplicitParamDecl::from_base(std::move(e));
}

gap::generator<ImplicitParamDecl> CapturedDecl::parameters(void) const & {
  auto list = impl->reader.getVal51();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d51 = ep->DeclFor(ep, v)) {
      if (auto e = ImplicitParamDecl::from_base(std::move(d51))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

gap::generator<Decl> CapturedDecl::declarations_in_context(void) const & {
  EntityProviderPtr ep = impl->ep;
  auto list = impl->reader.getVal52();
  for (auto v : list) {
    if (auto eptr = ep->DeclFor(ep, v)) {
      co_yield std::move(eptr);
    }
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
