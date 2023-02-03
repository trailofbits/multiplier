// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Types.h>

#include <optional>

namespace mx {

// Return the fragment offset from an entity ID. Returns `~0u` if it's not
// a fragment-specific entity ID.
std::optional<EntityOffset> FragmentOffsetFromEntityId(RawEntityId id);

// Returns the fragment ID corresponding with a fragment-specific entity ID.
std::optional<PackedFragmentId> FragmentIdFromEntityId(RawEntityId id);

// Returns the kind of an entity as an undifferentiated integer.
int KindFromEntityId(RawEntityId id);

// Returns the category of entity as an enum.
EntityCategory CategoryFromEntityId(RawEntityId);

}  // namespace mx
