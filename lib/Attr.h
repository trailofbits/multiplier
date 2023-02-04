// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/AST.capnp.h>
#include <multiplier/Entities/Attr.h>

#include "Entity.h"

namespace mx {

// Interface for accessing an attribute.
class AttrImpl final : public EntityImpl<ast::Attr> {
 public:
  const PackedFragmentId fragment_id;
  const EntityOffset offset;

  explicit AttrImpl(std::shared_ptr<EntityProvider> ep_,
                    kj::Array<capnp::word> data_,
                    RawEntityId id_);
};

}  // namespace mx
