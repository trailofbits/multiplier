// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Decl.h"

#include <multiplier/Index.h>

#include "Fragment.h"
#include "Reference.h"
#include "Types.h"

namespace mx {
namespace {

static thread_local RawEntityIdList tIgnoredRedecls;

}  // namespace

DeclImpl::DeclImpl(std::shared_ptr<EntityProvider> ep_,
                   kj::Array<capnp::word> data_,
                   RawEntityId id_)
    : EntityImpl<ast::Decl>(std::move(ep_), kj::mv(data_)),
      fragment_id(FragmentIdFromEntityId(id_).value()),
      offset(FragmentOffsetFromEntityId(id_).value()),
      definition_id(kInvalidEntityId),
      canonical_id(kInvalidEntityId) {}

SpecificEntityId<DeclId> Decl::id(void) const {
  DeclId eid;
  eid.fragment_id = impl->fragment_id.Unpack().fragment_id;
  eid.is_definition = is_definition();
  eid.kind = kind();
  eid.offset = impl->offset;
  return eid;
}

std::optional<Decl> Decl::definition(void) const {
  const EntityProvider::Ptr &ep = impl->ep;

  RawEntityId cached_id = impl->definition_id.load(std::memory_order_acquire);
  if (cached_id != kInvalidEntityId) {
    if (DeclImplPtr redecl = ep->DeclFor(ep, cached_id)) {
      return Decl(std::move(redecl));
    }
  }

  for (RawEntityId raw_id : ep->Redeclarations(ep, id().Pack())) {
    if (DeclImplPtr redecl = ep->DeclFor(ep, raw_id)) {

      if (impl->canonical_id.load(std::memory_order_relaxed) ==
              kInvalidEntityId) {
        impl->canonical_id.store(raw_id, std::memory_order_release);
      }

      Decl decl(std::move(redecl));
      if (decl.is_definition()) {
        impl->definition_id.store(raw_id, std::memory_order_release);
        return decl;
      }
    }
  }
  return std::nullopt;
}

Decl Decl::canonical_declaration(void) const {
  const EntityProvider::Ptr &ep = impl->ep;

  RawEntityId cached_id = impl->canonical_id.load(std::memory_order_acquire);
  if (cached_id != kInvalidEntityId) {
    if (DeclImplPtr redecl = ep->DeclFor(ep, cached_id)) {
      return Decl(std::move(redecl));
    }
  }

  for (RawEntityId raw_id : ep->Redeclarations(ep, id().Pack())) {
    if (DeclImplPtr redecl = ep->DeclFor(ep, raw_id)) {
      impl->canonical_id.store(raw_id, std::memory_order_release);
      Decl decl(std::move(redecl));
      if (decl.is_definition()) {
        impl->definition_id.store(raw_id, std::memory_order_release);
      }

      return decl;
    }
  }
  assert(false);
  return *this;
}

gap::generator<Decl> Decl::redeclarations(void) const {
  auto any = false;
  const EntityProvider::Ptr &ep = impl->ep;
  for (RawEntityId raw_id : ep->Redeclarations(ep, id().Pack())) {
    if (DeclImplPtr redecl = ep->DeclFor(ep, raw_id)) {
      any = true;
      co_yield Decl(std::move(redecl));
    }
  }
  if (!any) {
    assert(false);
    co_yield Decl(impl);
  }
}

// Return references to this declaration.
gap::generator<Reference> Decl::references(void) const {
  const EntityProvider::Ptr &ep = impl->ep;
  for (auto [ref_id, ref_kind] : ep->References(ep, id().Pack())) {
    if (auto [eptr, category] = ReferencedEntity(ep, ref_id); eptr) {
      co_yield Reference(std::move(eptr), ref_id, category, ref_kind);
    }
  }
}

}  // namespace mx
