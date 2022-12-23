// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <iosfwd>
#include <memory>
#include <optional>

namespace pasta {
class DefineMacroDirective;
class FileToken;
class MacroArgument;
class MacroDirective;
class MacroExpansion;
class MacroToken;
class Token;
}  // namespace pasta
namespace mx {
enum class MacroKind : unsigned char;
}  // namespace mx
namespace indexer {

class Substitution;
class SubstitutionNodeList;
class TokenTree;
class TokenTreeImpl;
class TokenTreeNodeIterator;

class TokenTreeNode {
 private:
  friend class TokenTree;
  friend class TokenTreeNodeIterator;
  friend class TokenTreeNodeRange;

  std::shared_ptr<const SubstitutionNodeList> impl;
  unsigned offset{0u};

  TokenTreeNode(std::shared_ptr<const SubstitutionNodeList> impl_)
      : impl(std::move(impl_)) {}

 public:
  std::optional<pasta::FileToken> FileToken(void) const noexcept;
  std::optional<pasta::MacroToken> MacroToken(void) const noexcept;
  std::optional<pasta::Token> Token(void) const noexcept;
  std::optional<TokenTree> SubTree(void) const noexcept;
  const void *RawNode(void) const noexcept;
};

class TokenTreeNodeIteratorEnd {};

// Iterator over interior nodes of the token tree.
class TokenTreeNodeIterator {
 private:
  friend class TokenTree;
  friend class TokenTreeNodeRange;

  TokenTreeNode node;

  TokenTreeNodeIterator(std::shared_ptr<const SubstitutionNodeList> impl_)
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

class TokenTreeNodeRange {
 private:
  friend class TokenTree;

  TokenTreeNodeIterator begin_;

  TokenTreeNodeRange(std::shared_ptr<const SubstitutionNodeList> impl_)
      : begin_(std::move(impl_)) {}

 public:

  inline TokenTreeNodeIterator begin(void) const & noexcept {
    return begin_;
  }

  inline TokenTreeNodeIterator begin(void) && noexcept {
    return std::move(begin_);
  }

  inline TokenTreeNodeIteratorEnd end(void) const noexcept {
    return {};
  }

  unsigned Size(void) const noexcept;

  inline unsigned size(void) const noexcept {
    return Size();
  }
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
  static std::optional<TokenTreeNodeRange>
  Create(pasta::TokenRange range, uint64_t begin_index, uint64_t end_index,
         std::ostream &err);

  mx::MacroKind Kind(void) const noexcept;

  std::optional<pasta::Macro> Macro(void) const noexcept;

  // Specializations of `TokenTree::Macro`.
  std::optional<pasta::MacroDirective> MacroDirective(void) const noexcept;
  std::optional<pasta::DefineMacroDirective> MacroDefinition(void) const noexcept;
  std::optional<pasta::MacroExpansion> MacroExpansion(void) const noexcept;
  std::optional<pasta::MacroArgument> MacroArgument(void) const noexcept;

  TokenTreeNodeRange Children(void) const noexcept;
  TokenTreeNodeRange ReplacementChildren(void) const noexcept;

  bool HasExpansion(void) const noexcept;

  // Return the number of children in this tree.
  unsigned NumChildren(void) const noexcept;

  // Return the number of replacement children in this tree.
  unsigned NumReplacementChildren(void) const noexcept;

  inline const void *RawNode(void) const noexcept {
    return impl.get();
  }
};

}  // namespace indexer
