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

DeclImpl::DeclImpl(FragmentImplPtr frag_,
                   ast::Decl::Reader reader_,
                   RawEntityId id_)
    : FragmentEntityImpl<ast::Decl>(std::move(frag_), kj::mv(reader_)),
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
  const EntityProviderPtr &ep = impl->ep;

  // If we've stored the canonical ID already, then we've also computed the
  // definition ID, if any.
  RawEntityId min_id = impl->canonical_id.load(std::memory_order_acquire);
  if (min_id != kInvalidEntityId) {
    RawEntityId definition_id =
        impl->definition_id.load(std::memory_order_acquire);
    if (DeclImplPtr def = ep->DeclFor(ep, definition_id)) {
      return Decl(std::move(def));
    } else {
      return std::nullopt;
    }
  }

  min_id = std::numeric_limits<RawEntityId>::max();
  RawEntityId definition_id = min_id;
  RawEntityId this_id = id().Pack();
  bool found_def = false;

#ifndef NDEBUG
  bool seen_this_id = false;
#endif

  for (RawEntityId raw_id : ep->Redeclarations(ep, this_id)) {
    VariantId vid = EntityId(raw_id).Unpack();
    if (!std::holds_alternative<DeclId>(vid)) {
      assert(false);
      continue;
    }

    DeclId did = std::get<DeclId>(vid);
    if (did.is_definition) {
      definition_id = std::min(definition_id, raw_id);
      found_def = true;
    }
    min_id = std::min(min_id, raw_id);

#ifndef NDEBUG
    if (raw_id == this_id) {
      seen_this_id = true;
    }
#endif
  }

  assert(seen_this_id);

  if (found_def) {
    if (DeclImplPtr def = ep->DeclFor(ep, definition_id)) {
      impl->canonical_id.store(definition_id, std::memory_order_release);
      impl->definition_id.store(definition_id, std::memory_order_release);
      return Decl(std::move(def));
    }
  }

  min_id = std::min(min_id, this_id);
  impl->canonical_id.store(min_id, std::memory_order_release);
  return std::nullopt;
}

Decl Decl::canonical_declaration(void) const {
  const EntityProviderPtr &ep = impl->ep;

  RawEntityId min_id = impl->canonical_id.load(std::memory_order_acquire);
  if (min_id != kInvalidEntityId) {
    if (DeclImplPtr redecl = ep->DeclFor(ep, min_id)) {
      return Decl(std::move(redecl));
    }
  }

  min_id = std::numeric_limits<RawEntityId>::max();
  RawEntityId definition_id = min_id;
  RawEntityId this_id = id().Pack();
  bool found_def = false;

#ifndef NDEBUG
  bool seen_this_id = false;
#endif

  for (RawEntityId raw_id : ep->Redeclarations(ep, this_id)) {
    VariantId vid = EntityId(raw_id).Unpack();
    if (!std::holds_alternative<DeclId>(vid)) {
      assert(false);
      continue;
    }

    DeclId did = std::get<DeclId>(vid);
    if (did.is_definition) {
      definition_id = std::min(definition_id, raw_id);
      found_def = true;
    }
    min_id = std::min(min_id, raw_id);

#ifndef NDEBUG
    if (raw_id == this_id) {
      seen_this_id = true;
    }
#endif
  }

  assert(seen_this_id);

  if (found_def) {
    if (DeclImplPtr def = ep->DeclFor(ep, definition_id)) {
      impl->canonical_id.store(definition_id, std::memory_order_release);
      impl->definition_id.store(definition_id, std::memory_order_release);
      return Decl(std::move(def));
    }
  }

  min_id = std::min(min_id, this_id);
  if (DeclImplPtr decl = ep->DeclFor(ep, min_id)) {
    impl->canonical_id.store(min_id, std::memory_order_release);
    return Decl(std::move(decl));

  } else {
    assert(false);
    impl->canonical_id.store(this_id, std::memory_order_release);
    return *this;
  }
}

gap::generator<Decl> Decl::redeclarations(void) const & {
  auto any = false;
  EntityProviderPtr ep = impl->ep;
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
gap::generator<Reference> Decl::references(void) const & {
  EntityProviderPtr ep = impl->ep;
  for (auto ref : ep->References(ep, id().Pack())) {
    if (auto [eptr, category] = ReferencedEntity(ep, std::get<0>(ref)); eptr) {
      auto context = std::make_shared<ReferenceContextImpl>(ep, std::get<1>(ref));
      co_yield Reference(std::move(eptr), std::move(context),
                         std::get<0>(ref), category, std::get<2>(ref));
    }
  }
}

// Grab all call expressions of this FunctionDecl
gap::generator<CallExpr> FunctionDecl::callers() const & {
  for (Reference ref : references()) {
    auto reference = ref.as_statement();
    for (CallExpr call : CallExpr::containing(reference)) {
      if (std::optional<FunctionDecl> decl = call.direct_callee()) {
        if (*this == *decl) {
          co_yield CallExpr(std::move(call));
          break;
        }
      }
    }
  }
}

}  // namespace mx
