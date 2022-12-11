// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <iosfwd>
#include <optional>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Token.h>
#include <pasta/Util/File.h>
#include <string>
#include <tuple>

namespace mx {
enum class MacroSubstitutionKind : unsigned char;
}  // namespace mx
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
  std::optional<pasta::MacroToken> MacroToken(void) const noexcept;
  std::optional<pasta::Token> Token(void) const noexcept;
  
  std::optional<std::tuple<mx::MacroSubstitutionKind, TokenTree, TokenTree>>
  MaybeSubstitution(void) const noexcept;

  std::optional<std::tuple<mx::MacroSubstitutionKind, TokenTree>>
  MaybeSubTree(void) const noexcept;
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

  // Create a token tree from the tokens in the inclusive range
  // `[begin_index, end_index]` from `range`.
  static std::optional<TokenTree>
  Create(pasta::TokenRange range, uint64_t begin_index, uint64_t end_index,
         std::ostream &err, bool fallback=false);

  TokenTreeNodeIterator begin(void) const noexcept;
  inline TokenTreeNodeIteratorEnd end(void) const noexcept {
    return {};
  }

  std::optional<pasta::MacroDirective> MacroDirective(void) const noexcept;
  std::optional<pasta::DefineMacroDirective> MacroDefinition(void) const noexcept;
  std::optional<pasta::MacroExpansion> MacroExpansion(void) const noexcept;
  std::optional<pasta::MacroExpansionArgument> MacroArgument(void) const noexcept;

  // Return the number of nodes in this tree.
  unsigned NumNodes(void) const noexcept;

  inline const void *RawNode(void) const {
    return impl.get();
  }
};

}  // namespace indexer
