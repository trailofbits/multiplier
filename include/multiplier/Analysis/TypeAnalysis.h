// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gap/core/generator.hpp>
#include <multiplier/Index.h>

enum class CastingBehaviorTags {
  SIGN_CHANGE,
  TYPE_DOWNCAST,
  TYPE_UPCAST,
};

namespace mx {

class TypecastAnalysisImpl final {
public:
    Index index;

    inline TypecastAnalysisImpl(const Index &index_)
    : index(index_) {}

};
} // namespace mx