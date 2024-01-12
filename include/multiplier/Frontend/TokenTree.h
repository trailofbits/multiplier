// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <iosfwd>

#include "../Fragment.h"
#include "MacroSubstitution.h"
#include "MacroVAOpt.h"
#include "Token.h"

namespace mx {

class TokenTreeNode;
class EmptyTokenTreeNode;
class TokenTokenTreeNode;
class ChoiceTokenTreeNode;
class SubstitutionTokenTreeNode;
class SequenceTokenTreeNode;

class MX_EXPORT TokenTreeVisitor {
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
class MX_EXPORT TokenTree {
 private:
  friend class Compilation;
  friend class File;
  friend class Fragment;

  std::shared_ptr<TokenTreeImpl> impl;

  inline TokenTree(std::shared_ptr<TokenTreeImpl> impl_)
      : impl(std::move(impl_)) {}

 public:
  TokenTree(void);

  static TokenTree from(const File &);
  static TokenTree from(const Fragment &);
  static TokenTree from(const TokenRange &);

  // Serialize the token tree into a linear range.
  TokenRange serialize(const TokenTreeVisitor &vis=TokenTreeVisitor()) const;

  // Dump the token tree into a DOT digraph.
  void dump(std::ostream &os);

  // Return the root node of this token tree.
  TokenTreeNode root(void) const noexcept;

  // Returns `false` if this is an empty, default-initialized token tree.
  operator bool(void) const noexcept;
};

enum class TokenTreeNodeKind : int {
  // An empty node.
  EMPTY,

  // A single token node.
  TOKEN,

  // A choice between overlapping fragments.
  CHOICE,

  // A choice between a macro use/expansion.
  SUBSTITUTION,

  // A sequence of nodes.
  SEQUENCE
};

inline static const char *EnumerationName(TokenTreeNodeKind) {
  return "TokenTreeNodeKind";
}

inline static constexpr unsigned NumEnumerators(TokenTreeNodeKind) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(TokenTreeNodeKind);

uintptr_t hash_code(const TokenTreeNode &ttn) noexcept;

// General node kind in a token tree.
class MX_EXPORT TokenTreeNode {
 private:
  friend class TokenTree;
  friend class EmptyTokenTreeNode;
  friend class TokenTokenTreeNode;
  friend class ChoiceTokenTreeNode;
  friend class SubstitutionTokenTreeNode;
  friend class SequenceTokenTreeNode;

  std::shared_ptr<TokenTreeImpl> impl;
  const void *opaque_node;

  TokenTreeNode(void) = delete;

  inline TokenTreeNode(std::shared_ptr<TokenTreeImpl> impl_,
                       const void *opaque_node_)
      : impl(std::move(impl_)),
        opaque_node(opaque_node_) {}

 public:
  ~TokenTreeNode(void);

  // Return the kind of this token tree node.
  TokenTreeNodeKind kind(void) const noexcept;

  // Comparison against nodes.
  inline bool operator==(const TokenTreeNode &that) const noexcept {
    return opaque_node == that.opaque_node;
  }

  friend uintptr_t hash_code(const TokenTreeNode &ttn) noexcept;
};

// An empty token tree node.
class MX_EXPORT EmptyTokenTreeNode final : public TokenTreeNode {
 public:
  inline static constexpr TokenTreeNodeKind static_kind(void) noexcept {
    return TokenTreeNodeKind::EMPTY;
  }

  static std::optional<EmptyTokenTreeNode> from(const TokenTreeNode &);
};

// A token tree node referencing only a single token.
class MX_EXPORT TokenTokenTreeNode final : public TokenTreeNode {
 public:
  inline static constexpr TokenTreeNodeKind static_kind(void) noexcept {
    return TokenTreeNodeKind::TOKEN;
  }

  static std::optional<TokenTokenTreeNode> from(const TokenTreeNode &);

  Token token(void) const noexcept;
};

// A token tree node representing a choice between multiple fragments.
class MX_EXPORT ChoiceTokenTreeNode final : public TokenTreeNode {
 public:
  inline static constexpr TokenTreeNodeKind static_kind(void) noexcept {
    return TokenTreeNodeKind::CHOICE;
  }

  static std::optional<ChoiceTokenTreeNode> from(const TokenTreeNode &);

  gap::generator<std::pair<Fragment, TokenTreeNode>>
      children(void) const & noexcept;
};

// A token tree node representing a substituion of a macro, i.e. the
// before/after of a parameter substitution, or a macro use and its expansion,
// etc.
class MX_EXPORT SubstitutionTokenTreeNode final : public TokenTreeNode {
 public:
  inline static constexpr TokenTreeNodeKind static_kind(void) noexcept {
    return TokenTreeNodeKind::SUBSTITUTION;
  }

  static std::optional<SubstitutionTokenTreeNode> from(const TokenTreeNode &);

  std::variant<MacroSubstitution, MacroVAOpt> macro(void) const noexcept;
  TokenTreeNode before(void) const noexcept;
  TokenTreeNode after(void) const noexcept;
};

// A token tree node representing a sequence of nodes.
class MX_EXPORT SequenceTokenTreeNode final : public TokenTreeNode {
 public:
  inline static constexpr TokenTreeNodeKind static_kind(void) noexcept {
    return TokenTreeNodeKind::SEQUENCE;
  }

  static std::optional<SequenceTokenTreeNode> from(const TokenTreeNode &);

  gap::generator<TokenTreeNode> children(void) const & noexcept;
};

}  // namespace mx
namespace std {
template <>
struct std::hash<mx::TokenTreeNode> {
  inline uintptr_t operator()(const mx::TokenTreeNode &n) const noexcept {
    return ::mx::hash_code(n);
  }
};
}  // namespace std
