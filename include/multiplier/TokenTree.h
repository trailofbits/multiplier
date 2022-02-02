// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Token.h"

#include <string>

#include "Result.h"

namespace mx {

class TokenTreeImpl;

// A token tree contains several overlapping token lists. The aim is to expose
// the tree of pre-/post-macro expansion tokens as a tree, as well as features
// of the parse tree.
class TokenTree {
 private:
  std::shared_ptr<TokenTreeImpl> impl;

  inline TokenTree(std::shared_ptr<TokenTreeImpl> impl_)
      : impl(std::move(impl_)) {}

 public:
  ~TokenTree(void);

  // Create a token tree from the tokens in the inclusive range
  // `[begin_index, end_index]` from `range`.
  static Result<TokenTree, std::string>
  Create(pasta::TokenRange range, uint64_t begin_index, uint64_t end_index);
};

}  // namespace mx
