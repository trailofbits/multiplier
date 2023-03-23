// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/HLSLBufferDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<HLSLBufferDecl> HLSLBufferDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = HLSLBufferDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool HLSLBufferDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : HLSLBufferDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<HLSLBufferDecl> HLSLBufferDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = HLSLBufferDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<HLSLBufferDecl> HLSLBufferDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<HLSLBufferDecl> HLSLBufferDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = HLSLBufferDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<HLSLBufferDecl> HLSLBufferDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool HLSLBufferDecl::contains(const Decl &decl) {
  for (auto &parent : HLSLBufferDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool HLSLBufferDecl::contains(const Stmt &stmt) {
  for (auto &parent : HLSLBufferDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<HLSLBufferDecl> HLSLBufferDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<HLSLBufferDecl> dr = HLSLBufferDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<HLSLBufferDecl> HLSLBufferDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return HLSLBufferDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kHLSLBufferDeclDerivedKinds[] = {
    HLSLBufferDecl::static_kind(),
};

std::optional<HLSLBufferDecl> HLSLBufferDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case HLSLBufferDecl::static_kind():
      return reinterpret_cast<const HLSLBufferDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<HLSLBufferDecl> HLSLBufferDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kHLSLBufferDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<HLSLBufferDecl> e = HLSLBufferDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<HLSLBufferDecl> HLSLBufferDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kHLSLBufferDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<HLSLBufferDecl> e = HLSLBufferDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<HLSLBufferDecl> HLSLBufferDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kHLSLBufferDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<HLSLBufferDecl> e = HLSLBufferDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<HLSLBufferDecl> HLSLBufferDecl::from(const Reference &r) {
  return HLSLBufferDecl::from(r.as_declaration());
}

std::optional<HLSLBufferDecl> HLSLBufferDecl::from(const TokenContext &t) {
  return HLSLBufferDecl::from(t.as_declaration());
}

Token HLSLBufferDecl::l_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal54());
}

Token HLSLBufferDecl::token_start(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal55());
}

Token HLSLBufferDecl::r_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal56());
}

bool HLSLBufferDecl::is_c_buffer(void) const {
  return impl->reader.getVal72();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
