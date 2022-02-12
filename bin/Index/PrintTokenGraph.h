// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdint>
#include <ostream>

namespace pasta {
class TokenRange;
}  // namespace pasta
namespace indexer {

// Print a token context graph (provenance of tokens in the AST) for the
// inclusive range `[begin_index, end_index]` as a DOT digraph to `os`.
void PrintTokenGraph(const pasta::TokenRange &range, uint64_t begin_index,
                     uint64_t end_index, std::ostream &os);

}  // namespace indexer
