// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Attr.h"

#include <multiplier/Index.h>

#include "Fragment.h"
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

gap::generator<Attr> Attr::in_internal(const Fragment &fragment) {
  FragmentId fid(fragment.impl->fragment_id);
  auto &ep = fragment.impl->ep;
  for (AttrImplPtr reader : ep->AttrsFor(ep, fid)) {
    co_yield Attr(std::move(reader));
  }
}

}  // namespace mx
