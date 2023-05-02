// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Pseudo.h"

#include "EntityProvider.h"
#include "Reference.h"
#include "Types.h"

namespace mx {

#define MX_DEFINE_PSEUDO(name) \
    name ## Impl::name ## Impl(std::shared_ptr<EntityProvider> ep_, \
                               kj::Array<capnp::word> data_, RawEntityId id_) \
        : EntityImpl<ast::name>(std::move(ep_), kj::mv(data_)), \
          fragment_id(FragmentIdFromEntityId(id_).value()), \
          offset(FragmentOffsetFromEntityId(id_).value()) {} \
    \
    Packed ## name ## Id name::id(void) const { \
      name ## Id id; \
      id.fragment_id = impl->fragment_id.Unpack().fragment_id; \
      id.offset = impl->offset; \
      return id; \
    } \
    \
    gap::generator<Reference> name::references(void) const & { \
      const EntityProviderPtr &ep = impl->ep; \
      for (auto [ref_id, ref_kind] : ep->References(ep, id().Pack())) { \
        if (auto [eptr, category] = ReferencedEntity(ep, ref_id); eptr) { \
          co_yield Reference(std::move(eptr), ref_id, category, ref_kind); \
        } \
      } \
    }

MX_FOR_EACH_PSEUDO(MX_DEFINE_PSEUDO)
#undef MX_DEFINE_PSEUDO



}  // namespace mx
