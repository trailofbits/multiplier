// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <iosfwd>

#include "Token.h"

namespace mx {

class TokenTreeVisitor {
 public:
  virtual ~TokenTreeVisitor(void) = default;

  // Return `true` if the input substitution should be expanded or not.
  virtual bool should_expand(const MacroSubstitution &) const;

  // Choose which fragment to show.
  virtual Fragment choose(const std::vector<Fragment> &) const;
};

// A tree of tokens, which can represent the variability of overlapping
// fragments, macro expansions, etc., allowing one to render the tree down
// into a singular linear range of tokens.
class TokenTree {
 private:
  friend class File;
  friend class Fragment;

  std::shared_ptr<TokenTreeImpl> impl;

  inline TokenTree(std::shared_ptr<TokenTreeImpl> impl_)
      : impl(std::move(impl_)) {}

 public:
  TokenTree(void);

  static TokenTree from(const File &);
  static TokenTree from(const Fragment &);

  // Try to get the token tree containing a token range.
  static std::optional<TokenTree> from(const TokenRange &);

  // Serialize the token tree into a linear range.
  TokenRange serialize(const TokenTreeVisitor &vis=TokenTreeVisitor()) const;

  // Dump the token tree into a DOT digraph.
  void dump(std::ostream &os);
};

}  // namespace mx
