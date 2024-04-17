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

// Label the parsed tokens and macros of this fragment. This focuses on finding the
// entities that syntactically belong to this fragment, and assigning them
// IDs. Labeling happens first for all fragments, then we run `Build` for
// new fragments that we want to serialize.
void LabelTokensAndMacrosInFragment(PendingFragment &pf);

}  // namespace indexer
