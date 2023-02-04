// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Type.h"

#include <multiplier/Index.h>

#include "Fragment.h"
#include "Types.h"

namespace mx {

TypeImpl::TypeImpl(std::shared_ptr<EntityProvider> ep_,
                   kj::Array<capnp::word> data_,
                   RawEntityId id_)
    : EntityImpl<ast::Type>(std::move(ep_), kj::mv(data_)),
      fragment_id(FragmentIdFromEntityId(id_).value()),
      offset(FragmentOffsetFromEntityId(id_).value()) {}

SpecificEntityId<TypeId> Type::id(void) const {
  TypeId eid;
  eid.fragment_id = impl->fragment_id.Unpack().fragment_id;
  eid.kind = kind();
  eid.offset = impl->offset;
  return eid;
}

gap::generator<Type> Type::in_internal(const Fragment &fragment) {
  FragmentId fid(fragment.impl->fragment_id);
  auto &ep = fragment.impl->ep;
  for (TypeImplPtr reader : ep->TypesFor(ep, fid)) {
    co_yield Type(std::move(reader));
  }
}

}  // namespace mx
