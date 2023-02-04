// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Decl.h"

#include <multiplier/Index.h>

#include "Fragment.h"
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
      offset(FragmentOffsetFromEntityId(id_).value()) {}

SpecificEntityId<DeclId> Decl::id(void) const {
  DeclId eid;
  eid.fragment_id = impl->fragment_id.Unpack().fragment_id;
  eid.is_definition = is_definition();
  eid.kind = kind();
  eid.offset = impl->offset;
  return eid;
}

std::optional<Decl> Decl::definition(void) const {
  for (RawEntityId raw_id : impl->ep->Redeclarations(impl->ep, id())) {
    if (DeclImplPtr redecl = impl->ep->DeclFor(impl->ep, raw_id)) {
      Decl decl(std::move(redecl));
      if (decl.is_definition()) {
        return decl;
      }
    }
  }
  return std::nullopt;
}

Decl Decl::canonical_declaration(void) const {
  for (RawEntityId raw_id : impl->ep->Redeclarations(impl->ep, id())) {
    if (DeclImplPtr redecl = impl->ep->DeclFor(impl->ep, raw_id)) {
      return Decl(std::move(redecl));
    }
  }
  assert(false);
  return *this;
}

gap::generator<Decl> Decl::redeclarations(void) const {
  auto any = false;
  for (RawEntityId raw_id : impl->ep->Redeclarations(impl->ep, id())) {
    if (DeclImplPtr redecl = impl->ep->DeclFor(impl->ep, raw_id)) {
      any = true;
      co_yield Decl(std::move(redecl));
    }
  }
  if (!any) {
    assert(false);
    co_yield Decl(impl);
  }
}

gap::generator<Reference> Decl::references(void) const {
  co_return;  // TODO!!!!
//  const EntityProvider::Ptr &ep = impl->ep;
//  RawEntityIdList references_ids;
//
//  tIgnoredRedecls.clear();
//  ep->FillReferences(ep, id().Pack(), tIgnoredRedecls, references_ids);
//  assert(!tIgnoredRedecls.empty());
//
//  for (RawEntityId raw_stmt_id : references_ids) {
//    VariantId vid = EntityId(raw_stmt_id).Unpack();
//    if (!std::holds_alternative<StmtId>(vid)) {
//      assert(false);
//      continue;
//    }
//
//    auto entity_reader = ep->StmtFor(ep, raw_stmt_id);
//    if (entity_reader.has_value()) {
//      co_yield Stmt(std::move(entity_reader.value()));
//    }
//  }
}

gap::generator<Decl> Decl::in_internal(const Fragment &fragment) {
  FragmentId fid(fragment.impl->fragment_id);
  auto &ep = fragment.impl->ep;
  for (DeclImplPtr reader : ep->DeclsFor(ep, fid)) {
    co_yield Decl(std::move(reader));
  }
}

}  // namespace mx
