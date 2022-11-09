// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/NodeKind.h>
#include <unordered_map>

namespace mx {
namespace syntex {

struct GrammarNode;

//
// One set of grammar leaves
//
using GrammarLeaves = std::unordered_map<NodeKind, GrammarNode>;

//
// Node in the grammar tree
//

struct GrammarNode {
  // Does this node correspond to the head of a production
  bool is_production;
  // Further leaves
  GrammarLeaves leaves;
};

}  // namespace syntex
}  // namespace mx