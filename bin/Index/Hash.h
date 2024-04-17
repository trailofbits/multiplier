// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <multiplier/Types.h>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

namespace pasta {
class AST;
class Decl;
class File;
class Macro;
class PrintedTokenRange;
class TokenRange;
}  // namespace pasta
namespace indexer {

using Entity = std::variant<std::monostate, pasta::Decl, pasta::Macro>;
class EntityMapper;
class NameMangler;

// Compute a SHA256 hash of some data from a file.
std::string HashFile(std::string_view data);

// Compute a hash of top-level declarations. This will produce a string of
// the form:
//
//    <tokens hash>:<odr hash 0>:...:<odr hash N>
//
// This hash is intentionally location independent. That is, it does not
// consider the file location at all. We integrate file-specific locations into
// fragment deduplication as part of a compound primary key in the
// `fragment_hash` database table.
std::string HashFragment(
    const EntityMapper &em, const NameMangler &nm, const void *parent_entity,
    const std::vector<pasta::Decl> &decls,
    const std::vector<pasta::Macro> &macros,
    const pasta::TokenRange *frag_tok_range,
    const pasta::PrintedTokenRange &decl_tok_range);

// Hash the entire compilation.
std::string HashCompilation(const pasta::AST &ast, const EntityMapper &em);

}  // namespace indexer
