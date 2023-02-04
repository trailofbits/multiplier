// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Macro.h"

#include <multiplier/Index.h>

#include "Fragment.h"
#include "Types.h"

namespace mx {
namespace {

static thread_local RawEntityIdList tIgnoredRedecls;

}  // namespace

MacroImpl::MacroImpl(std::shared_ptr<EntityProvider> ep_,
                     kj::Array<capnp::word> data_,
                     RawEntityId id_)
    : EntityImpl<ast::Macro>(std::move(ep_), kj::mv(data_)),
      fragment_id(FragmentIdFromEntityId(id_).value()),
      offset(FragmentOffsetFromEntityId(id_).value()) {}

SpecificEntityId<MacroId> Macro::id(void) const {
  MacroId eid;
  eid.fragment_id = impl->fragment_id.Unpack().fragment_id;
  eid.kind = kind();
  eid.offset = impl->offset;
  return eid;
}

gap::generator<Macro> Macro::in_internal(const Fragment &fragment) {
  FragmentId fid(fragment.impl->fragment_id);
  auto &ep = fragment.impl->ep;
  for (MacroImplPtr reader : ep->MacrosFor(ep, fid)) {
    co_yield Macro(std::move(reader));
  }
}

gap::generator<Macro> Macro::containing_internal(const Token &token) {
  auto frag = token.impl->OwningFragment();
  if (!frag) {
    co_return;
  }

  EntityId eid = token.impl->NthContainingMacroId(token.offset);
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
    co_return;

  } else if (!std::holds_alternative<MacroId>(vid)) {
    assert(false);
    co_return;
  }

  MacroId mid = std::get<MacroId>(vid);
  MacroImplPtr eptr = frag->ep->MacroFor(frag->ep, mid);
  if (!eptr || mid.fragment_id != frag->fragment_id) {
    assert(false);
    co_return;
  }

  std::optional<Macro> macro;
  for (macro.emplace(std::move(eptr)); macro; macro = macro->parent()) {
    co_yield *macro;
  }
}

// References to this macro definition.
gap::generator<Reference> Macro::references(void) const {
  // TODO!!!
  co_return;
//  const EntityProvider::Ptr &ep = impl->ep;
//  RawEntityIdList references_ids;
//
//  tIgnoredRedecls.clear();
//  ep->FillReferences(ep, id().Pack(), tIgnoredRedecls, references_ids);
//  assert(tIgnoredRedecls.empty());
//
//  for (RawEntityId raw_macro_id : references_ids) {
//    VariantId vid = EntityId(raw_macro_id).Unpack();
//    if (!std::holds_alternative<MacroId>(vid)) {
//      assert(false);
//      continue;
//    }
//
//    if (auto eptr = ep->MacroFor(ep, raw_macro_id)) {
//      co_yield Macro(std::move(eptr));
//    }
//  }
}

}  // namespace mx
