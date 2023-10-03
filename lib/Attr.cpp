// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Attr.h"

#include <multiplier/Index.h>

#include "Fragment.h"
#include "Reference.h"
#include "Types.h"

namespace mx {
namespace {

static thread_local RawEntityIdList tIgnoredRedecls;

}  // namespace

AttrImpl::AttrImpl(std::shared_ptr<EntityProvider> ep_,
                   kj::Array<capnp::word> data_,
                   RawEntityId id_)
    : EntityImpl<ast::Attr>(std::move(ep_), kj::mv(data_)),
      fragment_id(FragmentIdFromEntityId(id_).value()),
      offset(FragmentOffsetFromEntityId(id_).value()) {}

SpecificEntityId<AttrId> Attr::id(void) const {
  AttrId eid;
  eid.fragment_id = impl->fragment_id.Unpack().fragment_id;
  eid.kind = kind();
  eid.offset = impl->offset;
  return eid;
}

// Return references to this attribute.
gap::generator<Reference> Attr::references(void) const & {
  const EntityProviderPtr &ep = impl->ep;
  for (auto ref : ep->References(ep, id().Pack())) {
    if (auto [eptr, category] = ReferencedEntity(ep, std::get<0>(ref)); eptr) {
      auto context = std::make_shared<ReferenceContextImpl>(ep, std::get<1>(ref));
      co_yield Reference(std::move(eptr), std::move(context),
                         std::get<0>(ref), category, std::get<2>(ref));
    }
  }
}

}  // namespace mx
