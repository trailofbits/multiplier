// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/NodeKind.h>
#include <unordered_map>

namespace mx {

struct SyntexGrammarNode;

//
// One set of grammar leaves
//
using SyntexGrammarLeaves = std::unordered_map<SyntexNodeKind, SyntexGrammarNode>;

//
// Node in the grammar tree
//

struct SyntexGrammarNode {
  // Does this node correspond to the head of a production
  bool is_production;
  // Further leaves
  SyntexGrammarLeaves leaves;
};

}  // namespace mx