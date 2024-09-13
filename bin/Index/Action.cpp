// Copyright (c) 2019-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Action.h"

namespace indexer {

Action::~Action(void) {}

// Return the priority of this action.
unsigned Action::Priority(void) const {
  return 0u;
}

}  // namespace indexer
