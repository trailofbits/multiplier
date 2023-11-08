// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.
#include <multiplier/Analysis/TypeAnalysis.h>
#include <multiplier/Index.h>

namespace mx {

TypecastAnalysis::TypecastAnalysis(const Index &) {}

void TypecastAnalysis::cast_instances(const Stmt &stmt) {
    for (auto child : stmt.children()) {

    }
}

}