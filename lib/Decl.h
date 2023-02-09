// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <atomic>
#include <multiplier/AST.capnp.h>
#include <multiplier/Entities/Decl.h>

#include "Entity.h"

namespace mx {

// Interface for accessing a declaration.
class DeclImpl final : public EntityImpl<ast::Decl> {
 public:
  const PackedFragmentId fragment_id;
  const EntityOffset offset;

  // Caches for re-used prior computations of the canonical id/def.
  //
  // TODO(pag): These will get out-of-date; consider storing `version_number`.
  //            Alternatively, having some kind of alternate cache of redecls
  //            in-situ, or stored through a `weak_ptr` that the
  //            `CachingEntityProvider` can wipe out in bulk could be nifty.
  mutable std::atomic<RawEntityId> definition_id;
  mutable std::atomic<RawEntityId> canonical_id;

  explicit DeclImpl(std::shared_ptr<EntityProvider> ep_,
                    kj::Array<capnp::word> data_,
                    RawEntityId id_);
};

}  // namespace mx
