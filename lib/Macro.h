// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/AST.capnp.h>
#include <multiplier/Entities/Macro.h>

#include "Entity.h"

namespace mx {

// Interface for accessing a macro.
class MacroImpl final : public EntityImpl<ast::Macro> {
 public:
  const PackedFragmentId fragment_id;
  const EntityOffset offset;

  explicit MacroImpl(std::shared_ptr<EntityProvider> ep_, std::string data_,
                     RawEntityId id_);
};

}  // namespace mx
