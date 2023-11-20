// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "multiplier/Types.h"
#include <multiplier/Entities/CallExpr.h>

#include <unordered_set>
#include <stack>

namespace mx {

// a CallGraph is a map between a
using CallGraph = std::unordered_map<PackedStmtId, std::unordered_set<PackedStmtId>>;

class CallAnalysis {
private:
    const Index &index;

public:
    CallAnalysis(Index&);

    std::unordered_set<PackedStmtId> return_value_set(const CallExpr&);

    void call_graph_to(const FunctionDecl&);
    void call_graph_from(const FunctionDecl&);
};

}; // namespace mx