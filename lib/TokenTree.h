// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/TokenTree.h>

#include "Token.h"

namespace mx {

class TokenTreeImpl {
 public:
  struct MacroExpansionProcessor;

  // The index of a token is the index of a specific reader, followed by the
  // offset of the token within that reader.
  using TokenIndex = std::pair<EntityOffset, EntityOffset>;

  struct ChoiceNode;
  struct SubstitutionNode;
  struct SequenceNode;
  using Node = std::variant<std::monostate, TokenIndex, ChoiceNode *,
                            SubstitutionNode *, SequenceNode *>;

  // Inclusive bounds of something, e.g. the body of a macro.
  struct Bounds {
    EntityOffset reader_index{0u};
    EntityOffset begin_index{0u};
    EntityOffset end_index{0u};
  };

  struct TrailingTokens {
    Bounds bounds;
    int depth{0};
    std::vector<Token> tokens;
    const TrailingTokens *next_trailing{nullptr};
  };

  // A choice among fragments.
  struct ChoiceNode final {
    std::vector<Fragment> fragments;
    std::vector<Node> children;
  };

  // A choice among the different stages of macro expansion.
  struct SubstitutionNode final {
    std::variant<MacroSubstitution, MacroVAOpt> macro;

    Node before;
    Node after;

    inline explicit SubstitutionNode(MacroSubstitution sub_)
        : macro(std::move(sub_)) {}

    inline explicit SubstitutionNode(MacroVAOpt va_opt_)
        : macro(std::move(va_opt_)) {}
  };

  // A sequence of other nodes.
  struct SequenceNode final {
    std::vector<Node> children;

    Node Flatten(void) {
      auto num_children = children.size();
      if (!num_children) {
        return {};
      } else if (num_children == 1u) {
        return children.front();
      } else {
        return this;
      }
    }
  };

  // If this is a token tree for a file then this is the file. If this is the
  // token tree for a fragment, then this is the fragment's file, if any.
  FileImplPtr file;

  // If this is a token tree for a single fragment, then this is the single
  // fragment itself.
  FragmentImplPtr fragment;

  // The list of token readers used in this fragment. There is always one
  // entry in this list. The first entry is always either a file token reader,
  // or an invalid token reader. This is indexed by a `TokenIndex`.
  std::vector<TokenReader::Ptr> readers;

  int depth{0};

  Node root;

  std::deque<ChoiceNode> choices;
  std::deque<SubstitutionNode> substitutions;
  std::deque<SequenceNode> sequences;

  // Never filled.
  const TrailingTokens dummy_trailing_tokens{};

  SequenceNode dummy_sequence{};
  SequenceNode *last_sequence{&dummy_sequence};

  TokenIndex GetOrCreateIndex(const Token &tok);
  SequenceNode *AddLeadingTokensInBounds(
      SequenceNode *seq, const Token &tok, const Bounds &bounds);

  SequenceNode *ExtendWithMacroChild(
      SequenceNode *seq, const MacroOrToken &mt,
      const Bounds &bounds, const TrailingTokens &trailing_tokens);

  SequenceNode *ExtendWithMacroChildren(
      SequenceNode *seq, const Macro &macro,
      const Bounds &bounds, const TrailingTokens &trailing_toks);

  SequenceNode *ExtendWithMacro(
      SequenceNode *seq, const Macro &macro, const Bounds &bounds,
      const TrailingTokens &trailing_toks);

  SequenceNode *ExtendWithSubstitution(
        SequenceNode *seq, const MacroSubstitution &macro,
        const Bounds &bounds, const TrailingTokens &trailing_toks);

  SequenceNode *ExtendWithExpansion(
      SequenceNode *seq, const MacroExpansion &macro,
      const Bounds &user_bounds, const TrailingTokens &trailing_toks);

  SequenceNode *ExtendWithSimpleExpansion(
      SequenceNode *seq, const MacroExpansion &macro,
      const DefineMacroDirective &def, const Bounds &user_bounds,
      const Bounds &def_bounds, const TrailingTokens &trailing_toks);

  SequenceNode *ExtendWithNonTreeExpansion(
      SequenceNode *seq,
      const MacroExpansion &me, const Bounds &me_bounds,
      const DefineMacroDirective &def, const Bounds &def_bounds,
      const MacroExpansion &deepest_te, const TrailingTokens &trailing_toks);

  TokenTreeImpl::SequenceNode *ProcessMacroChildren(
      TokenTreeImpl::SequenceNode *, const Bounds &bounds,
      std::vector<MacroOrToken> mts, std::vector<Token> fts,
      const TrailingTokens &trailing_toks);

  Node CreateFragmentNode(const Fragment &entity, const Bounds &bounds);
  Node CreateFileNode(const File &entity);

  Bounds FragmentBounds(const TokenRange &tokens);
  std::optional<Bounds> MacroBodyBounds(const DefineMacroDirective &def);
  std::optional<Bounds> TopLevelUseBounds(const Macro &macro);

  // Widen bounds to cover leading/trailing comments.
  Bounds WidenBounds(Bounds bounds);

  // NOTE(pag): This will reset `curr_leaf` if `that == curr_leaf` and
  //            `curr_leaf` is empty.
  template <typename T>
  SequenceNode *AddToSequence(SequenceNode *seq, T *that,
                              const TrailingTokens &trailing_tokens);
  SequenceNode *AddTokenToSequence(SequenceNode *seq, const Token &tok,
                                   const TrailingTokens &trailing_tokens);
  SequenceNode *AddTokenToSequence(SequenceNode *seq, TokenIndex ti);
  SequenceNode *AddNodeToSequence(SequenceNode *seq, const Node &node,
                                  const TrailingTokens &trailing_tokens);
  SequenceNode *AddTrailingTokensToSequence(
      SequenceNode *seq, const TrailingTokens &trailing_tokens);
};

class TokenTreeImplCache {
 private:
  mutable std::weak_ptr<TokenTreeImpl> impl;
  mutable std::mutex lock;

 public:
  std::shared_ptr<TokenTreeImpl> Get(void) const;
  std::shared_ptr<TokenTreeImpl> Put(std::shared_ptr<TokenTreeImpl>) const;
};

}  // namespace mx
