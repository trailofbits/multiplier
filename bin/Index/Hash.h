// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace pasta {
class Decl;
class TokenRange;
}  // namespace pasta
namespace indexer {

std::string ComputeHash(const std::vector<pasta::Decl> &decl_range,
                        const pasta::TokenRange &toks,
                        uint64_t begin_index, uint64_t end_index);

}  // namespace indexer
