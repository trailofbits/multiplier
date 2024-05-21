// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <vector>

#include "Visitor.h"

namespace pasta {
class Attr;
class Decl;
class Macro;
class Stmt;
class Type;
}  // namespace pasta
namespace indexer {

class EntityMapper;
class PendingFragment;

// Initialize the entity labeller for a fragment. This focuses only on the top-
// level entities.
void InitializeEntityLabeller(PendingFragment &pf);

// Label the parsed tokens in this fragment.
void LabelTokensInFragment(PendingFragment &pf);

}  // namespace indexer
