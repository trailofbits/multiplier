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
      return References(impl->ep, id().Pack()); \
    }

MX_FOR_EACH_PSEUDO(MX_DEFINE_PSEUDO)
#undef MX_DEFINE_PSEUDO



}  // namespace mx
