// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Macro.h>

#include "API.h"

namespace mx {

struct BeforeTag {};
struct AfterTag {};

class MacroSubstitutionListImpl {
 public:
  const std::shared_ptr<const FragmentImpl> fragment;
  const NodeReader nodes;

  MacroSubstitutionListImpl(void) = delete;

  MacroSubstitutionListImpl(std::shared_ptr<const FragmentImpl> fragment_,
                            unsigned offset, BeforeTag);

  MacroSubstitutionListImpl(std::shared_ptr<const FragmentImpl> fragment_,
                            unsigned offset, AfterTag);
};

}  // namespace mx
