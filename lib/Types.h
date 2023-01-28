// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Types.h>

namespace mx {

// Return the fragment offset from an entity ID. Returns `~0u` if it's not
// a fragment-specific entity ID.
EntityOffset FragmentOffsetFromEntityId(RawEntityId id);

// Returns the fragment ID corresponding with a fragment-specific entity ID.
RawEntityId FragmentIdFromEntityId(RawEntityId id);

}  // namespace mx
