// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/AST.capnp.h>
#include <multiplier/AST/Designator.h>

#include "FragmentEntity.h"

#pragma GCC visibility push(hidden)
namespace mx {

#define MX_FOR_EACH_PSEUDO(m) \
    m(TemplateArgument) \
    m(TemplateParameterList) \
    m(CXXBaseSpecifier) \
    m(Designator)

#define MX_DEFINE_PSEUDO(name) \
    class name ## Impl final : public FragmentEntityImpl<ast::name> { \
     public: \
      const PackedFragmentId fragment_id; \
      const EntityOffset offset; \
      \
      explicit name ## Impl(FragmentImplPtr frag_, \
                            ast::name::Reader reader_, \
                            RawEntityId id_); \
    };

MX_FOR_EACH_PSEUDO(MX_DEFINE_PSEUDO)
#undef MX_DEFINE_PSEUDO

}  // namespace mx
#pragma GCC visibility pop
