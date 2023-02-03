// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/AST.capnp.h>
#include <multiplier/Entities/Stmt.h>

#include "Entity.h"

namespace mx {

// Interface for accessing a statement.
class StmtImpl final : public EntityImpl<ast::Stmt> {
 public:
  const PackedFragmentId fragment_id;
  const EntityOffset offset;

  explicit StmtImpl(std::shared_ptr<EntityProvider> ep_, std::string data_,
                    RawEntityId id_);
};

}  // namespace mx
