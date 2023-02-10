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
  for (RawEntityId raw_id : impl->ep->Redeclarations(impl->ep, id().Pack())) {
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
  const EntityProvider::Ptr &ep = impl->ep;
  for (RawEntityId raw_id : ep->Redeclarations(ep, id().Pack())) {
    if (DeclImplPtr redecl = ep->DeclFor(ep, raw_id)) {
      return Decl(std::move(redecl));
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

gap::generator<Decl> Decl::in_internal(const Fragment &fragment) {
  FragmentId fid(fragment.impl->fragment_id);
  const EntityProvider::Ptr &ep = fragment.impl->ep;
  for (DeclImplPtr reader : ep->DeclsFor(ep, fid)) {
    co_yield Decl(std::move(reader));
  }
}

// Grab all call expressions of this FunctionDecl
gap::generator<CallExpr> FunctionDecl::callers() const {
  for (Reference ref : references()) {
    auto reference = ref.as_statement();
    for (CallExpr call : CallExpr::containing(reference)) {
      if (auto decl = call.direct_callee()) {
        const FunctionDecl &orig_func_decl = *decl;
        auto eq = orig_func_decl <=> *this;
        if (eq == 0) {
          co_yield CallExpr(std::move(call));
          break;
        }
      }
    }
  }
}

}  // namespace mx
