// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Types.h>

namespace mx {

EntityOffset FragmentOffsetFromEntityId(RawEntityId id);
RawEntityId FragmentIdFromEntityId(RawEntityId id);

}  // namespace mx
