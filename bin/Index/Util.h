// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <string_view>

namespace pasta {
class FileToken;
}  // namespace pasta
namespace mx {
enum class TokenKind : unsigned short;
}  // namespace mx
namespace indexer {

// Returns `true` if `data` contains only whitespace or is empty.
bool IsWhitespaceOrEmpty(std::string_view data);

// Return the token kind.
mx::TokenKind TokenKindFromPasta(const pasta::FileToken &entity);

}  // namespace indexer
