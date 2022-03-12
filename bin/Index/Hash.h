// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace pasta {
class Decl;
class File;
class TokenRange;
}  // namespace pasta
namespace indexer {

// Compute a SHA256 hash of some data from a file.
std::string FileHash(std::string_view data);

// Compute a hash of top-level declarations. This will produce a string of
// the form:
//
//    <file hash>:<line>:<column>:<tokens hash>:<odr hash 0>:...:<odr hash N>
//
// We use a hash of a file's contents instead of the file path so that we
// can identify the same logical code in different copies of the same file. The
// line and column represent a kind of anchor point within the file. The tokens
// and contents are all hashed together in a way that integrates the actual AST
// structure itself. Finally, the ODR hashes are there to help us to distinguish
// template instantiations, where the tokens and their contexts match, but the
// declarations in the AST do not.
std::string CodeHash(std::unordered_map<pasta::File, std::string> file_hashes,
                     const std::vector<pasta::Decl> &decl_range,
                     const pasta::TokenRange &toks,
                     uint64_t begin_index, uint64_t end_index);

}  // namespace indexer
