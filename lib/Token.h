// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Token.h>

#include <string>
#include <vector>

namespace mx {

class TokenListImpl {
 public:
  std::string data;
  std::vector<TokenKind> token_kinds;
  std::vector<unsigned> data_offsets;

  void AddToken(std::string_view data, TokenKind kind,
                std::vector<uint16_t> &dummy_states,
                std::string &dummy_output);
};

}  // namespace mx
