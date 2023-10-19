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
    name ## Impl::name ## Impl(FragmentImplPtr frag_, \
                               ast::name::Reader reader_, \
                               RawEntityId id_) \
        : FragmentEntityImpl<ast::name>(std::move(frag_), kj::mv(reader_)), \
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
      EntityProviderPtr ep = impl->ep; \
      for (auto ref : ep->References(ep, id().Pack())) { \
        if (auto [eptr, category] = ReferencedEntity(ep, std::get<0>(ref)); eptr) { \
          auto context = std::make_shared<ReferenceContextImpl>(ep, std::get<1>(ref)); \
          co_yield Reference(std::move(eptr), std::move(context), \
                             std::get<0>(ref), category, std::get<2>(ref)); \
        } \
      } \
    }

MX_FOR_EACH_PSEUDO(MX_DEFINE_PSEUDO)
#undef MX_DEFINE_PSEUDO



}  // namespace mx
