// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <iosfwd>
#include <memory>
#include <optional>
#include <vector>

#include "../../include/multiplier/Types.h"

namespace pasta {
class Decl;
class DefineMacroDirective;
class FileToken;
class Macro;
class MacroArgument;
class MacroDirective;
class MacroExpansion;
class MacroToken;
class PrintedToken;
class PrintedTokenRange;
class Token;
class TokenRange;
}  // namespace pasta
namespace mx {
enum class MacroKind : unsigned char;
}  // namespace mx
namespace indexer {

class PendingFragment;
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
  std::optional<pasta::PrintedToken> PrintedToken(void) const noexcept;
  std::optional<pasta::MacroToken> MacroToken(void) const noexcept;
  std::optional<pasta::Token> Token(void) const noexcept;
  std::optional<TokenTree> SubTree(void) const noexcept;
  std::optional<mx::RawEntityId> SubFragmentHole(void) const noexcept;

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

  // Dump.
  void Dump(std::ostream &os) const;

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
  Create(const PendingFragment &pf, std::ostream &err);

  // Dump.
  void Dump(std::ostream &os) const;

  mx::MacroKind Kind(void) const noexcept;

  std::optional<pasta::Macro> Macro(void) const noexcept;

  // NOTE(pag): These mirror methods available on various pasta Macro classes.
  //            The bootstrapper is aware of these, and custom-generates the
  //            serialization of pasta macros to call these methods instead of
  //            the corresponding ones on the macro. This is for two reasons:
  //
  //                1.  The TokenTree "compresses" the macro graph, merging
  //                    macro expansions with their argument pre-expansion
  //                    phases, which appear as additional expansions in the
  //                    pasta graph.
  //
  //                2.  To allow for the serialization of an invented
  //                    substitution node for `#include` directives embedded
  //                    inside of fragments with decls/statements, i.e. to
  //                    handle the common pattern of an `enum` using an x-macro
  //                    include pattern to define the enumerators.
  std::optional<TokenTree> Parent(void) const noexcept;
  TokenTreeNodeRange Children(void) const noexcept;
  TokenTreeNodeRange IntermediateChildren(void) const noexcept;
  TokenTreeNodeRange ReplacementChildren(void) const noexcept;
  std::optional<pasta::MacroToken> FirstFullySubstitutedToken(void) const noexcept;
  std::optional<pasta::MacroToken> LastFullySubstitutedToken(void) const noexcept;
  std::optional<pasta::MacroToken> NameOrOperator(void) const noexcept;

  // Return whether or not this node has intermediate children.
  bool HasIntermediateChildren(void) const noexcept;

  // Return whether or not this node has an expansion (i.e. replacement
  // children).
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
