// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/AST.capnp.h>
#include <multiplier/Entities/Designator.h>

#include "Entity.h"

namespace mx {

#define MX_FOR_EACH_PSEUDO(m) \
    m(TemplateArgument) \
    m(TemplateParameterList) \
    m(CXXBaseSpecifier) \
    m(Designator)

#define MX_DEFINE_PSEUDO(name) \
    class name ## Impl final : public EntityImpl<ast::name> { \
     public: \
      const PackedFragmentId fragment_id; \
      const EntityOffset offset; \
      \
      explicit name ## Impl(std::shared_ptr<EntityProvider> ep_, \
                            kj::Array<capnp::word> data_, RawEntityId id_); \
    };

MX_FOR_EACH_PSEUDO(MX_DEFINE_PSEUDO)
#undef MX_DEFINE_PSEUDO

}  // namespace mx
