// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Result.h>
#include <pasta/AST/Token.h>
#include <pasta/Util/File.h>
#include <string>

namespace indexer {

class Substitution;
class TokenTree;
class TokenTreeImpl;
class TokenTreeNodeIterator;

class TokenTreeNode {
 private:
  friend class TokenTree;
  friend class TokenTreeNodeIterator;

  std::shared_ptr<const Substitution> impl;
  unsigned offset{0u};

  TokenTreeNode(std::shared_ptr<const Substitution> impl_)
      : impl(std::move(impl_)) {}

 public:
  std::optional<pasta::FileToken> FileToken(void) const noexcept;
  std::optional<pasta::Token> Token(void) const noexcept;
  std::optional<std::pair<TokenTree, TokenTree>> Substitution(void) const noexcept;
};

class TokenTreeNodeIteratorEnd {};

// Iterator over interior nodes of the token tree.
class TokenTreeNodeIterator {
 private:
  friend class TokenTree;

  TokenTreeNode node;

  TokenTreeNodeIterator(std::shared_ptr<const Substitution> impl_)
      : node(std::move(impl_)) {}

 public:
  const TokenTreeNode &operator*(void) const noexcept {
    return node;
  }

  const TokenTreeNode *operator->(void) const noexcept {
    return &node;
  }

  // Pre-increment.
  inline TokenTreeNodeIterator &operator++(void) {
    ++node.offset;
    return *this;
  }

  bool operator==(TokenTreeNodeIteratorEnd) const;
  bool operator!=(TokenTreeNodeIteratorEnd) const;
};

// A token tree contains several overlapping token lists. The aim is to expose
// the tree of pre-/post-macro expansion tokens as a tree, as well as features
// of the parse tree.
class TokenTree {
 private:
  friend class TokenTreeNode;

  std::shared_ptr<const Substitution> impl;

  inline TokenTree(std::shared_ptr<const Substitution> impl_)
      : impl(std::move(impl_)) {}

 public:
  ~TokenTree(void);

  // Return the file associated with the tokens of this substitution.
  ::pasta::File File(void) const;

  // Create a token tree from the tokens in the inclusive range
  // `[begin_index, end_index]` from `range`.
  static mx::Result<TokenTree, std::string>
  Create(pasta::TokenRange range, uint64_t begin_index, uint64_t end_index);

  TokenTreeNodeIterator begin(void) const noexcept;
  inline TokenTreeNodeIteratorEnd end(void) const noexcept {
    return {};
  }
};

}  // namespace indexer
