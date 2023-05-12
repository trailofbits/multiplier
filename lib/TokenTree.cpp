// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <algorithm>
#include <deque>
#include <functional>
#include <iterator>
#include <multiplier/Entities/DefineMacroDirective.h>
#include <multiplier/Entities/MacroExpansion.h>
#include <multiplier/Entities/MacroParameterSubstitution.h>
#include <multiplier/Entities/MacroSubstitution.h>
#include <multiplier/Entities/MacroVAOpt.h>
#include <type_traits>
#include <unordered_map>
#include <vector>

#include "File.h"
#include "Fragment.h"
#include "Token.h"

//#define D(...) __VA_ARGS__
#ifndef D
# define D(...)
#endif
#if D(1 +) 0
#include <iostream>
#endif

namespace mx {
namespace {

// The index of a token is the index of a specific reader, followed by the
// offset of the token within that reader.
using TokenIndex = std::pair<EntityOffset, EntityOffset>;

static const std::hash<std::string> kHasher;

struct ChoiceNode;
struct SubstitutionNode;
struct SequenceNode;
using Node = std::variant<std::monostate, TokenIndex, ChoiceNode *,
                          SubstitutionNode *, SequenceNode *>;

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

// Inclusive bounds of something, e.g. the body of a macro.
struct Bounds {
  EntityOffset reader_index;
  EntityOffset begin_index;
  EntityOffset end_index;
};

// Return the leftmost use tokens of a macro.
static Token LeftCornerOfExpansion(const Macro &exp) {
  for (Token tok : exp.generate_expansion_tokens()) {
    return tok;
  }
  return Token();
}

// Return the leftmost use tokens of a macro.
static Token LeftCornerOfUse(const Macro &exp) {
  for (Token tok : exp.generate_use_tokens()) {
    return tok;
  }
  return Token();
}

// Return the rightmost use tokens of a macro.
static Token RightCornerOfUse(const Macro &exp) {
  Token ret;
  for (Token tok : exp.generate_use_tokens()) {
    ret = std::move(tok);
  }
  return ret;
}

// Go look for a macro expansion at the end of another macro expansion. This
// is indicative of a specific corner case with macros, e.g.:
//
//      #define HEAD if (1) TAIL
//      #define TAIL(...) {__VA_ARGS__}
//      ...
//      HEAD(return 1;)
//
// Here, the `(return 1;)` are macro use tokens, but they only appear in the
// expansion of `TAIL`, which itself only appears in the expansion of `HEAD`.
static std::optional<MacroExpansion> TrailingExpansionInExpansion(
    const MacroExpansion &exp) {
  std::optional<MacroExpansion> ret;
  for (MacroOrToken mt : exp.replacement_children()) {
    ret.reset();
    if (std::holds_alternative<Macro>(mt)) {
      ret = MacroExpansion::from(std::get<Macro>(mt));
    }
  }

  return ret;
}

struct BodyTokenForChild {
  // The child from the replacement body of a macro substitution.
  MacroOrToken mt;

  // A token from a macro's definition body that we have matched against `mt`.
  // We use this to determine whitespace injection.
  Token definition_token;

  // Tells us if the tokens are from the usage site, i.e. argument tokens.
  bool is_argument;

  inline BodyTokenForChild(MacroOrToken mt_, Token definition_token_,
                           bool is_argument_)
      : mt(std::move(mt_)),
        definition_token(std::move(definition_token_)),
        is_argument(is_argument_) {}
};

struct MacroExpansionProcessor {

  std::vector<MacroOrToken> body_children;
  std::vector<MacroOrToken> after_children;
  std::vector<BodyTokenForChild> merged_children;

//  // Marker tokens for whitespace injection.
//  std::vector<Token> tokens_for_whitespace;
//  std::vector<Bounds> bounds_for_whitespace;

  void Init(const MacroExpansion &me, const DefineMacroDirective &def);
  bool Run(bool is_non_tree);

  void InitTrailingNonTree(const MacroExpansion &te);

  inline const std::vector<BodyTokenForChild> &ReplacementChildren(void) const {
    return merged_children;
  }
};

void MacroExpansionProcessor::Init(const MacroExpansion &me,
                                   const DefineMacroDirective &def) {

  body_children.clear();
  after_children.clear();
  merged_children.clear();

  for (MacroOrToken mt : me.replacement_children()) {
    after_children.emplace_back(std::move(mt));
  }

  for (MacroOrToken mt : me.intermediate_children()) {
    body_children.emplace_back(std::move(mt));
  }

  if (body_children.empty()) {
    for (MacroOrToken mt : def.body()) {
      body_children.emplace_back(std::move(mt));
    }
  }
}

void MacroExpansionProcessor::InitTrailingNonTree(const MacroExpansion &te) {
  after_children.clear();
  merged_children.clear();

  for (MacroOrToken mt : te.children()) {
    after_children.emplace_back(std::move(mt));
  }

  std::reverse(after_children.begin(), after_children.end());
  std::reverse(body_children.begin(), body_children.end());
}

bool MacroExpansionProcessor::Run(bool is_non_tree) {
  size_t i = 0u;
  size_t j = 0u;

  size_t max_i = body_children.size();
  size_t max_j = after_children.size();

  Token bt_lc;
  Token at_lc;

  D( std::cerr << "max_i = " << max_i << "; max_j = " << max_j << '\n'; )

  while (i < max_i && j < max_j) {
    const MacroOrToken &bt = body_children[i];
    const MacroOrToken &at = after_children[j];

    const Token *bt_tok = std::get_if<Token>(&bt);
    const Token *at_tok = std::get_if<Token>(&at);

    bool is_argument = false;

    if (!bt_tok) {
      const Macro &bt_macro = std::get<Macro>(bt);
      is_argument = bt_macro.kind() == MacroKind::PARAMETER_SUBSTITUTION;
      bt_lc = LeftCornerOfExpansion(bt_macro);
      bt_tok = &bt_lc;
    }

    if (!at_tok) {
      at_lc = LeftCornerOfUse(std::get<Macro>(at));
      at_tok = &at_lc;
    }

    assert(bt_tok && at_tok);

    D( std::cerr << "BT(" << i << "): " << bt_tok->id() << ' ' << bt_tok->data() << '\n'; )
    D( std::cerr << "AT(" << j << "): " << at_tok->id() << ' ' << at_tok->data() << "\n\n"; )

    if (bt_tok->data() == at_tok->data()) {
      merged_children.emplace_back(at, bt_tok->file_token(), is_argument);
      ++i;
      ++j;

    // Skip over stuff in expansions.
    } else {
      merged_children.emplace_back(at, Token(), is_argument);
      ++j;
    }
  }

  if (is_non_tree) {
    return j == max_j;
  }

  for (; j < max_j; ++j) {
    merged_children.emplace_back(after_children[j], Token(), false);
  }

  return i == max_i && j == max_j;
}

}  // namespace

class TokenTreeImpl {
 public:
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

  Node root;

  std::deque<ChoiceNode> choices;
  std::deque<SubstitutionNode> substitutions;
  std::deque<SequenceNode> sequences;

  // Helper to process macro expansions.
  std::unique_ptr<MacroExpansionProcessor> mep;

  TokenIndex GetOrCreateIndex(const Token &tok);
  SequenceNode *AddLeadingTokensInBounds(SequenceNode *seq, const Token &tok,
                                         const Bounds &bounds);
  SequenceNode *ExtendWithMacroChild(SequenceNode *seq, const MacroOrToken &mt,
                                     const Bounds &bounds);
  SequenceNode *ExtendWithMacroChildren(SequenceNode *seq, const Macro &macro,
                                        const Bounds &bounds);
  SequenceNode *ExtendWithMacro(SequenceNode *seq, const Macro &macro,
                                const Bounds &bounds);
  SequenceNode *ExtendWithVAOpt(SequenceNode *seq, const MacroVAOpt &macro,
                                const Bounds &bounds);

  SequenceNode *ExtendWithSubstitution(
        SequenceNode *seq, const MacroSubstitution &macro,
        const Bounds &bounds);

  SequenceNode *ExtendWithExpansion(
      SequenceNode *seq, const MacroExpansion &macro,
      const Bounds &user_bounds);

  SequenceNode *ExtendWithSimpleExpansion(
      SequenceNode *seq, const MacroExpansion &macro,
      const DefineMacroDirective &def, const Bounds &user_bounds,
      const Bounds &def_bounds);

  SequenceNode *ExtendWithNonTreeExpansion(
      SequenceNode *seq,
      const MacroExpansion &me, const Bounds &me_bounds,
      const DefineMacroDirective &def, const Bounds &def_bounds,
      const MacroExpansion &te, const Bounds &te_bounds,
      const MacroExpansion &deepest_te, const Bounds &deepest_te_use_bounds);

//  SequenceNode *MergeAndFormReplacement(
//      SequenceNode *before, const DefineMacroDirective &def,
//      std::vector<MacroOrToken> body, std::vector<MacroOrToken> after);

  Node CreateFragmentNode(const Fragment &entity, const Bounds &bounds);
  Node CreateFileNode(const File &entity);

  Bounds FragmentBounds(const TokenRange &tokens);
  std::optional<Bounds> MacroBodyBounds(const DefineMacroDirective &def);
  std::optional<Bounds> TopLevelUseBounds(const Macro &macro);

  // NOTE(pag): This will reset `curr_leaf` if `that == curr_leaf` and
  //            `curr_leaf` is empty.
  template <typename T>
  SequenceNode *AddToSequence(SequenceNode *seq, T *that) {
    if (!that) {
      return seq;
    }

    if constexpr (std::is_same_v<SequenceNode, T>) {
      if (seq == that) {
        return seq;
      } else if (!seq) {
        return that;
      } else if (seq->children.empty()) {
        return that;
      } else if (that->children.empty()) {
        return seq;
      } else {
        seq->children.insert(seq->children.end(), that->children.begin(),
                             that->children.end());
        return seq;
      }

    // Try to fold single-item choice nodes.
    } else if constexpr (std::is_same_v<ChoiceNode, T>) {
      if (that->children.size() == 1u) {
        return AddNodeToSequence(seq, that->children.front());
      }
    }

    if (!seq) {
      seq = &(sequences.emplace_back());
    }

    seq->children.emplace_back(that);
    return seq;
  }


  SequenceNode *AddTokenToSequence(SequenceNode *seq, const Token &tok) {
    return AddTokenToSequence(seq, GetOrCreateIndex(tok));
  }

  SequenceNode *AddTokenToSequence(SequenceNode *seq, TokenIndex ti) {
    if (!seq) {
      seq = &(sequences.emplace_back());
    }
    seq->children.push_back(ti);
    return seq;
  }

  SequenceNode *AddNodeToSequence(SequenceNode *seq, const Node &node) {
    return std::visit<SequenceNode *>(
        [=] (auto &&arg) -> SequenceNode * {
          using arg_t = std::decay_t<decltype(arg)>;
          if constexpr (std::is_pointer_v<arg_t>) {
            return AddToSequence(seq, arg);
          } else if constexpr (std::is_same_v<arg_t, TokenIndex>) {
            return AddTokenToSequence(seq, arg);
          } else {
            return seq;
          }
        },
        node);
  }
};

// Find the bounds of a top-level macro use.
std::optional<Bounds> TokenTreeImpl::TopLevelUseBounds(const Macro &exp) {
  Bounds ret = {};
  Token last_tok;
  for (Token tok : exp.generate_use_tokens()) {
    if (Token file_tok = tok.file_token()) {
      if (!last_tok) {
        TokenIndex ti = GetOrCreateIndex(file_tok);
        ret.reader_index = ti.first;
        ret.begin_index = ti.second + 1u;
        ret.end_index = ret.begin_index;
      }

      last_tok = std::move(file_tok);
    }
  }

  TokenIndex ti = GetOrCreateIndex(last_tok);
  ret.end_index = ti.second;
  if (ti.first != ret.reader_index) {
    assert(false);
    return std::nullopt;
  }

  if (ret.begin_index > ret.end_index) {
    assert(false);
    return std::nullopt;
  }

  return ret;
}

Bounds TokenTreeImpl::FragmentBounds(const TokenRange &tokens) {
  if (!mep) {
    mep.reset(new MacroExpansionProcessor);
  }

  Bounds ret = {};
  if (!tokens.empty()) {
    auto [ri_begin, ti_begin] = GetOrCreateIndex(tokens.front());
    auto [ri_end, ti_end] = GetOrCreateIndex(tokens.back());
    if (ri_begin != ri_end) {
      assert(false);
      return ret;
    }

    if (ti_begin > ti_end) {
      assert(false);
      return ret;
    }

    ret.reader_index = ri_begin;
    ret.begin_index = ti_begin;
    ret.end_index = ti_end;
  }
  return ret;
}

// Find the bounds of a macro definition body.
std::optional<Bounds> TokenTreeImpl::MacroBodyBounds(
    const DefineMacroDirective &def) {

  Bounds ret = {};
  Token last_tok;
  for (Token tok : def.generate_use_tokens()) {
    if (Token file_tok = tok.file_token()) {
      if (!last_tok) {
        TokenIndex ti = GetOrCreateIndex(file_tok);
        ret.reader_index = ti.first;
        ret.begin_index = ti.second + 1u;
        ret.end_index = ret.begin_index;
      }

      last_tok = std::move(file_tok);
    }
  }

  if (!last_tok) {
    return std::nullopt;
  }

  // Find the end of the parameter list.
  if (def.is_function_like()) {
    for (MacroOrToken mt : def.parameters()) {
      if (std::holds_alternative<Token>(mt)) {
        if (Token file_tok = std::get<Token>(mt).file_token()) {
          TokenIndex ti = GetOrCreateIndex(file_tok);
          if (ti.first != ret.reader_index) {
            assert(false);
            return std::nullopt;
          }
          ret.begin_index = ti.second + 1u;
          ret.end_index = ret.begin_index;
        }
      }
    }
  }

  TokenIndex ti = GetOrCreateIndex(last_tok);
  ret.end_index = ti.second;
  if (ti.first != ret.reader_index) {
    assert(false);
    return std::nullopt;
  }

  if (ret.begin_index > ret.end_index) {
    assert(false);
    return std::nullopt;
  }

  return ret;
}

// Get a `TokenIndex` for `tok`. This will save the reader into the token tree
// if it can't be found, formulating a new token index position for that reader.
TokenIndex TokenTreeImpl::GetOrCreateIndex(const Token &tok) {
  EntityOffset i = 0u;
  for (TokenReader::Ptr &reader : readers) {
    if (reader == tok.impl) {
      return TokenIndex(i, tok.offset);
    }
    ++i;
  }

  readers.emplace_back(tok.impl);
  return TokenIndex(i, tok.offset);
}

// Counts the number of tokens after `begin` and before `end` that we can
// inject before the token which logically represents `end`.
static EntityOffset CountInjectable(const TokenReader::Ptr &reader,
                                    EntityOffset begin, EntityOffset end) {
  EntityOffset count = 0u;
  for (auto i = end - 1u; begin < i; ++count, --i) {
    switch (reader->NthTokenKind(i)) {
      case TokenKind::WHITESPACE:
      case TokenKind::COMMENT:
      case TokenKind::UNKNOWN:
        if (!reader->NthTokenData(i).empty()) {
          continue;
        }
        [[clang::fallthrough]];
      default:
        return count;
    }
  }
  return count;
}

// Try to add leading file tokens into `node` that should logically come from
// before `tok`.
SequenceNode *TokenTreeImpl::AddLeadingTokensInBounds(
    SequenceNode *seq, const Token &tok, const Bounds &bounds) {

  Token file_tok = tok.file_token();
  if (!file_tok) {
    return seq;
  }

  TokenIndex fti = GetOrCreateIndex(file_tok);
  if (fti.first != bounds.reader_index || fti.second <= bounds.begin_index ||
      fti.second > bounds.end_index) {
    return seq;
  }

  // Inject the missing whitespace/comment tokens.
  const TokenReader::Ptr &fti_reader = readers[fti.first];
  for (auto num = CountInjectable(fti_reader, bounds.begin_index, fti.second);
       num; --num) {
    seq = AddTokenToSequence(seq, TokenIndex(fti.first, fti.second - num));
  }

  return seq;
}

SequenceNode *TokenTreeImpl::ExtendWithMacroChild(
    SequenceNode *seq, const MacroOrToken &mt, const Bounds &bounds) {
  if (std::holds_alternative<Token>(mt)) {
    const Token &tok = std::get<Token>(mt);
    seq = AddLeadingTokensInBounds(seq, tok, bounds);
    return AddTokenToSequence(seq, tok);

  } else if (std::holds_alternative<Macro>(mt)) {
    return ExtendWithMacro(seq, std::get<Macro>(mt), bounds);

  } else {
    assert(false);
    return seq;
  }
}

SequenceNode *TokenTreeImpl::ExtendWithMacroChildren(
    SequenceNode *seq, const Macro &macro, const Bounds &bounds) {
  for (MacroOrToken mt : macro.children()) {
    seq = ExtendWithMacroChild(seq, mt, bounds);
  }
  return seq;
}

SequenceNode *TokenTreeImpl::ExtendWithSimpleExpansion(
    SequenceNode *seq, const MacroExpansion &me,
    const DefineMacroDirective &me_def, const Bounds &user_bounds,
    const Bounds &def_bounds) {

  mep->Init(me, me_def);
  if (!mep->Run(false)) {
    assert(false);  // Probably a bug.
    return ExtendWithSubstitution(seq, me, user_bounds);
  }

  SubstitutionNode *sub = &(substitutions.emplace_back(me));
  SequenceNode *before = nullptr;
  for (MacroOrToken mt : me.children()) {
    before = ExtendWithMacroChild(before, mt, user_bounds);
  }

  if (!before) {
    return nullptr;
  }

  SequenceNode *after = nullptr;
  for (const BodyTokenForChild &node : mep->ReplacementChildren()) {
    after = AddLeadingTokensInBounds(after, node.definition_token, def_bounds);
    if (node.is_argument) {
      after = ExtendWithMacroChild(after, node.mt, user_bounds);
    } else {
      after = ExtendWithMacroChild(after, node.mt, def_bounds);
    }
  }

  sub->before = before;

  if (after) {
    sub->after = after;
  }

  return AddToSequence(seq, sub);
}

// Extend with a "non-tree" macro expansion, e.g. something like:
//
//    #define TAIL(...) __VA_ARGS__
//    #define HEAD if (1) TAIL(
//    ...
//    HEAD a, b, c)
//
// In older versions of PASTA, the following also was sometimes a non-tree
// case:
//
//    #define TAIL(...) __VA_ARGS__
//    #define HEAD if (1) TAIL
//    ...
//    HEAD(a, b, c)
//
// Our detection logic in `ExtendWithExpansion` generally works for both. We
// are primarily concerned with meaningfully renderable tokens, and what happens
// in the non-tree cases is that `a, b, c)` in the former example or `(a, b, c)`
// in the latter example end up in the nested macro use of the top-level
// expansion of `HEAD`. This breaks our "meaningfulness" criteria, because
// these tokens are top-level tokens, and so while they should appear in the
// use of the expansion, they should also show up in the use itself.
SequenceNode *TokenTreeImpl::ExtendWithNonTreeExpansion(
    SequenceNode *seq,
    const MacroExpansion &me, const Bounds &me_bounds,
    const DefineMacroDirective &def, const Bounds &def_bounds,
    const MacroExpansion &te, const Bounds &te_bounds,
    const MacroExpansion &dte, const Bounds &dte_bounds) {

  D( std::cerr << "non-tree " << def.name().data() << "\n"; )

  mep->Init(me, def);
  if (!mep->Run(true)) {
    assert(false);  // Probably not a bug, just something sketchy/odd.
    return ExtendWithSubstitution(seq, me, me_bounds);
  }

  SubstitutionNode *sub = &(substitutions.emplace_back(me));
  SequenceNode *before = nullptr;

  for (MacroOrToken mt : me.children()) {
    before = ExtendWithMacroChild(before, mt, me_bounds);
  }

  if (!before) {
    return seq;
  }

  SequenceNode *after = nullptr;
  for (const BodyTokenForChild &node : mep->ReplacementChildren()) {
    after = AddLeadingTokensInBounds(after, node.definition_token, def_bounds);
    if (node.is_argument) {
      after = ExtendWithMacroChild(after, node.mt, me_bounds);
    } else {
      after = ExtendWithMacroChild(after, node.mt, def_bounds);
    }
  }

  mep->InitTrailingNonTree(dte);

//  // Collect the trailing macro nodes, including argument nodes, that were
//  // out-of-order.
  auto failed = true;
  (void) te;
  (void) te_bounds;
  (void) dte_bounds;

//  if (false && mep->Run(true)) {
//    std::vector<BodyTokenForChild> trailing_nodes;
//
//    // NOTE(pag): These are in reverse order, so we start from the end (what
//    //            we want to find) and work our way back toward the beginning.
//    //            We stop at the token that belongs to the macro definition.
//    for (const BodyTokenForChild &node : mep->ReplacementChildren()) {
//      Token tok = node.definition_token;
//      if (!node.definition_token && std::holds_alternative<Macro>(node.mt)) {
//        tok = LeftCornerOfExpansion(std::get<Macro>(node.mt)).file_token();
//      }
//
//      if (tok) {
//        TokenIndex ti = GetOrCreateIndex(tok);
//        if (!(ti.first == me_bounds.reader_index &&
//              ti.second < me_bounds.begin_index &&
//              ti.second > me_bounds.end_index)) {
//          break;
//
//        } else if (ti.first == te_bounds.reader_index &&
//                   ti.second >= te_bounds.begin_index &&
//                   ti.second <= te_bounds.end_index) {
//          break;
//
//        } else if (ti.first == dte_bounds.reader_index &&
//                   ti.second >= dte_bounds.begin_index &&
//                   ti.second <= dte_bounds.end_index) {
//          break;
//        }
//
//        D( std::cerr << "Allowing " << tok.data() << "\n"; )
//      } else {
//        D( std::cerr << "Allowing another node\n"; )
//      }
//
//      trailing_nodes.emplace_back(node);
//    }
//
//    std::reverse(trailing_nodes.begin(), trailing_nodes.end());
//    for (const BodyTokenForChild &node : trailing_nodes) {
//      failed = false;
//      before = AddLeadingTokensInBounds(before, node.definition_token,
//                                        me_bounds);
//      before = ExtendWithMacroChild(before, node.mt, me_bounds);
//    }
//  }

  // If we fail to align things, then collect the trailing tokens that were
  // out-of-order.
  if (failed) {
//    assert(false);

    std::vector<Token> trailing_toks;
    for (Token te_tok : dte.generate_use_tokens()) {
      Token te_file_tok = te_tok.file_token();
      if (!te_file_tok) {
        trailing_toks.clear();
        continue;
      }

      TokenIndex ti = GetOrCreateIndex(te_file_tok);
      if (ti.first != me_bounds.reader_index ||
          ti.second < me_bounds.begin_index ||
          ti.second > me_bounds.end_index) {
        trailing_toks.clear();
        continue;
      }

      trailing_toks.emplace_back(std::move(te_tok));
    }

    // TODO(pag): Ideally, we'd be merging in the
    for (const Token &tok : trailing_toks) {
      before = AddLeadingTokensInBounds(before, tok.file_token(), me_bounds);
      before = AddTokenToSequence(before, tok);
    }
  }

  sub->before = before;
  if (after) {
    sub->after = after;
  }

  return AddToSequence(seq, sub);
}

// Extend with a macro expansion. The work here is in figuring out whether or
// not we're in a "non-tree" case.
SequenceNode *TokenTreeImpl::ExtendWithExpansion(
    SequenceNode *seq, const MacroExpansion &me,
    const Bounds &user_bounds) {

  std::optional<Bounds> def_bounds;
  std::optional<DefineMacroDirective> def = me.definition();
  if (!def) {
    return ExtendWithSubstitution(seq, me, user_bounds);
  }

  def_bounds = MacroBodyBounds(def.value());
  if (!def_bounds) {
    return ExtendWithSubstitution(seq, me, user_bounds);
  }

  // If there isn't a trailing expansion, then that is fine.
  std::optional<MacroExpansion> te = TrailingExpansionInExpansion(me);
  if (!te) {
    return ExtendWithSimpleExpansion(seq, me, def.value(), user_bounds,
                                     def_bounds.value());
  }

  Bounds dte_use_bounds = def_bounds.value();
  std::optional<MacroExpansion> dte = te;
  while (auto nte = TrailingExpansionInExpansion(dte.value())) {
    D( std::cerr << "-- drilling --\n"; )
    if (auto nte_def = nte->definition()) {
      if (auto nte_def_bounds = MacroBodyBounds(nte_def.value())) {
        D( std::cerr << "-- drilled into " << nte_def->name().data() << "--\n"; )
        dte = std::move(nte);  // Drill down through nested trailing expansions.
        dte_use_bounds = nte_def_bounds.value();
        continue;
      }
    }
    break;
  }

  // Get the right corner of the macro use for the trailing expansion. We want
  // to identify if the `)` of a function-like macro call isn't from inside
  // `bounds`.
  Token rc = RightCornerOfUse(dte.value());
  if (!rc) {
    return ExtendWithSimpleExpansion(seq, me, def.value(), user_bounds,
                                     def_bounds.value());
  }

  // If we can't find a file token for the right corner of the use of the
  // nested expansion, which is presumably `)`, then this is probably a macro
  // defined through a command-line option. Assume it won't be crazy, and that
  // PASTA has actually done "rotations" that make it not crazy.
  Token rc_ft = rc.file_token();
  if (!rc_ft) {
    return ExtendWithSimpleExpansion(seq, me, def.value(), user_bounds,
                                     def_bounds.value());
  }

  // The right corner is likely the closing parenthesis of a function-like
  // macro expansion. In the macro-in-tail-position, this can come from the
  // macro use site. We can detect if it's not coming from the use site
  // because it'll be from the body of the macro itself.
  TokenIndex rc_ft_ti = GetOrCreateIndex(rc_ft);
  if (rc_ft_ti.first == dte_use_bounds.reader_index &&
      rc_ft_ti.second >= dte_use_bounds.begin_index &&
      rc_ft_ti.second <= dte_use_bounds.end_index) {
    return ExtendWithSimpleExpansion(seq, me, def.value(), user_bounds,
                                     def_bounds.value());
  }

  return ExtendWithNonTreeExpansion(
      seq, me, user_bounds, def.value(), def_bounds.value(), te.value(),
      def_bounds.value()  /* bounds of top-level TE are the def bounds */,
      dte.value(), dte_use_bounds);
}

SequenceNode *TokenTreeImpl::ExtendWithSubstitution(
    SequenceNode *seq, const MacroSubstitution &macro,
    const Bounds &use_bounds) {
  SubstitutionNode *sub = &(substitutions.emplace_back(macro));
  SequenceNode *before = nullptr;

  for (MacroOrToken mt : macro.children()) {
    before = ExtendWithMacroChild(before, mt, use_bounds);
  }

  if (!before) {
    return seq;
  }

  sub->before = before;

  SequenceNode *after = nullptr;
  for (MacroOrToken mt : macro.replacement_children()) {
    after = ExtendWithMacroChild(after, mt, use_bounds);
  }

  if (after) {
    sub->after = after;
  }

  return AddToSequence(seq, sub);
}

SequenceNode *TokenTreeImpl::ExtendWithVAOpt(
    SequenceNode *seq, const MacroVAOpt &macro, const Bounds &bounds_of_def) {

  SubstitutionNode *sub = &(substitutions.emplace_back(macro));
  seq = AddToSequence(seq, sub);

  SequenceNode *sub_before = ExtendWithMacroChildren(nullptr, macro,
                                                     bounds_of_def);
  assert(sub_before != nullptr);
  sub->before = sub_before->Flatten();

  if (macro.contents_are_elided()) {
    return seq;
  }

  // TODO(pag): Only keep the arguments of the `__VA_OPT__`.
  sub->after = sub->before;

  return seq;
}

SequenceNode *TokenTreeImpl::ExtendWithMacro(
    SequenceNode *seq, const Macro &macro, const Bounds &bounds) {

  if (auto ms = MacroSubstitution::from(macro)) {
    if (auto me = MacroExpansion::from(macro)) {
      seq = ExtendWithExpansion(seq, me.value(), bounds);
    } else {
      seq = ExtendWithSubstitution(seq, ms.value(), bounds);
    }
  } else if (auto vo = MacroVAOpt::from(macro)) {
    seq = ExtendWithVAOpt(seq, vo.value(), bounds);

  } else {
    seq = ExtendWithMacroChildren(seq, macro, bounds);
  }

  return seq;
}

// Create a node for a fragment. If the fragment has file tokens, then the
// returned node will "expand" out to include the file tokens.
Node TokenTreeImpl::CreateFragmentNode(const Fragment &entity,
                                       const Bounds &bounds) {

  SequenceNode *seq = nullptr;

//  std::vector<MacroOrToken> mts;
//  for (MacroOrToken mt : entity.preprocessed_code()) {
//    mts.emplace_back(std::move(mt));
//  }
//
//  size_t num_mts = mts.size();
//  mts.emplace_back(entity.file_tokens().back());
//
//  for (auto i = 0u; i < num_mts; ++i) {
//    const MacroOrToken &mt = mts[i];
//
//    if (std::holds_alternative<Token>(mt)) {
//      const Token &tok = std::get<Token>(mt);
//      seq = AddLeadingTokensInBounds(seq, tok, bounds);
//      seq = AddTokenToSequence(seq, tok);
//
//    } else if (std::holds_alternative<Macro>(mt)) {
//      const Macro &m = std::get<Macro>(mt);
//      Token first = LeftCornerOfExpansion(m).file_token();
//      Token next;
//      if (std::holds_alternative<Macro>(mts[i + 1u])) {
//        next = LeftCornerOfExpansion(std::get<Macro>(mts[i + 1u]));
//      } else {
//        next = std::get<Token>(mts[i + 1u]).file_token();
//      }
//
//      auto first_ti = GetOrCreateIndex(first);
//      auto next_ti = GetOrCreateIndex(next);
//      if (first_ti.first == next_ti.first &&
//          first_ti.first == bounds.reader_index &&
//          first_ti.second <= next_ti.second && false) {
//
//        Bounds exp_bounds;
//        exp_bounds.reader_index = std::max(bounds.begin_index, first_ti.first);
//        exp_bounds.begin_index = std::min(bounds.end_index, first_ti.second);
//        exp_bounds.end_index = next_ti.second;
//
//        seq = AddLeadingTokensInBounds(seq, first, bounds);
//        seq = ExtendWithMacro(seq, m, exp_bounds);
//
//      } else {
//        seq = ExtendWithMacro(seq, m, bounds);
//      }
//    }
//  }

  for (MacroOrToken mt : entity.preprocessed_code()) {
    if (std::holds_alternative<Token>(mt)) {
      const Token &tok = std::get<Token>(mt);
      seq = AddLeadingTokensInBounds(seq, tok, bounds);
      seq = AddTokenToSequence(seq, tok);

    } else if (std::holds_alternative<Macro>(mt)) {
      const Macro &m = std::get<Macro>(mt);
      seq = ExtendWithMacro(seq, m, bounds);
    }
  }

  if (!seq) {
    return {};
  }

  return seq;
}

// Create a node for a file. If there are overlapping fragments in this file,
// then this will include them.
Node TokenTreeImpl::CreateFileNode(const File &entity) {

  // Collect all overlapping fragments into alternations.
  std::unordered_map<RawEntityId, ChoiceNode *> file_frags;
  std::unordered_map<RawEntityId, RawEntityId> frag_end;
  std::unordered_map<RawEntityId, RawEntityId> last_frag;
  for (Fragment frag : entity.fragments()) {
    TokenRange file_toks = frag.file_tokens();
    if (file_toks.empty()) {
      continue;
    }

    Bounds frag_bounds = FragmentBounds(file_toks);
    Node frag_node = CreateFragmentNode(frag, frag_bounds);

    RawEntityId first_file_tok_id = file_toks.front().id().Pack();
    RawEntityId last_file_tok_id = file_toks.back().id().Pack();

    if (auto frag_it = file_frags.find(first_file_tok_id);
        frag_it != file_frags.end()) {

      assert(last_file_tok_id == frag_end[first_file_tok_id]);

      ChoiceNode *alt = frag_it->second;
      alt->fragments.emplace_back(std::move(frag));
      alt->children.emplace_back(std::move(frag_node));

    } else {
      ChoiceNode *alt = &(choices.emplace_back());
      alt->fragments.emplace_back(std::move(frag));
      alt->children.emplace_back(std::move(frag_node));

      frag_end.emplace(first_file_tok_id, last_file_tok_id);
      file_frags.emplace(first_file_tok_id, alt);
    }
  }

  SequenceNode *seq = nullptr;
  std::optional<RawEntityId> stop_skip_after;

  // Combine the file tokens and alternations of the fragment tokens.
  for (Token file_tok : entity.tokens()) {
    RawEntityId file_tok_id = file_tok.id().Pack();
    if (stop_skip_after.has_value()) {
      if (stop_skip_after.value() == file_tok_id) {
        stop_skip_after.reset();
      }
      continue;
    }

    if (auto frag_it = file_frags.find(file_tok_id);
        frag_it != file_frags.end()) {

      ChoiceNode *frag_node = frag_it->second;
      assert(frag_node != nullptr);
      stop_skip_after.emplace(frag_end[file_tok_id]);
      seq = AddToSequence(seq, frag_node);

      file_frags.erase(file_tok_id);

    } else {
      seq = AddTokenToSequence(seq, file_tok);
    }
  }

  assert(file_frags.empty());

  if (!seq) {
    return {};
  }

  return seq;
}

// Return `true` if the input substitution should be expanded or not.
bool TokenTreeVisitor::should_expand(const MacroSubstitution &) const {
  return false;
}

// Return `true` if the input `__VA_OPT__` should be expanded or not.
bool TokenTreeVisitor::should_expand(const MacroVAOpt &) const {
  return false;
}

// Choose which fragment to show.
Fragment TokenTreeVisitor::choose(const std::vector<Fragment> &frags) const {
  return frags.front();
}

TokenTree TokenTree::from(const File &file) {
  auto self = std::make_shared<TokenTreeImpl>();
  auto file_tokens = file.tokens();
  self->readers.emplace_back(file_tokens.impl);
  self->root = self->CreateFileNode(file);
  self->mep.reset();
  return TokenTree(std::move(self));
}

TokenTree TokenTree::from(const Fragment &frag) {
  auto self = std::make_shared<TokenTreeImpl>();
  self->fragment = frag.impl;

  if (auto opt_file = File::containing(frag)) {
    auto file_tokens = opt_file->tokens();
    self->file = opt_file->impl;
    self->readers.emplace_back(file_tokens.impl);
  } else {
    self->readers.emplace_back(TokenRange().impl);
  }

  Bounds frag_bounds = self->FragmentBounds(frag.file_tokens());
  self->root = self->CreateFragmentNode(frag, frag_bounds);
  self->mep.reset();
  return TokenTree(std::move(self));
}

namespace {

// Used for invalid tokens.
class TokenTreeReader final : public TokenReader {
 public:
  const std::shared_ptr<TokenTreeImpl> impl;
  std::vector<TokenIndex> tokens;

  // Offset of the first byte of data from the Nth token. This has one extra
  // element at the end that contains the size of `data`.
  std::vector<EntityOffset> token_offset;

  // A single string representing the serialized token tree token data.
  std::string data;

  std::uint64_t data_hash{0u};

  virtual ~TokenTreeReader(void) noexcept = default;

  inline TokenTreeReader(std::shared_ptr<TokenTreeImpl> impl_)
      : impl(std::move(impl_)) {}

  const FragmentImpl *OwningFragment(void) const noexcept override {
    return impl->fragment.get();
  }

  const FileImpl *OwningFile(void) const noexcept override {
    if (!impl->fragment) {
      return impl->file.get();
    } else {
      return nullptr;
    }
  }

  const FragmentImpl *NthOwningFragment(EntityOffset ti) const noexcept override {
    if (ti >= tokens.size()) {
      return OwningFragment();
    }
    auto [ri, to] = tokens[ti];
    return impl->readers[ri]->NthOwningFragment(to);
  }

  const FileImpl *NthOwningFile(EntityOffset ti) const noexcept override {
    if (ti >= tokens.size()) {
      return OwningFile();
    }
    auto [ri, to] = tokens[ti];
    return impl->readers[ri]->NthOwningFile(to);
  }

  // Return the number of tokens accessible to this reader.
  EntityOffset NumTokens(void) const override {
    return static_cast<EntityOffset>(tokens.size());
  }

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(EntityOffset ti) const override {
    if (ti >= tokens.size()) {
      return TokenKind::UNKNOWN;
    }
    auto [ri, to] = tokens[ti];
    return impl->readers[ri]->NthTokenKind(to);
  }

  // Return the data of the Nth token.
  std::string_view NthTokenData(EntityOffset ti) const override {
    if ((ti + 1u) >= token_offset.size()) {
      return {};
    }
    EntityOffset bo = token_offset[ti];
    EntityOffset eo = token_offset[ti + 1u];
    auto len = eo - bo;
    return std::string_view(data).substr(bo, len);
  }

  // Return the id of the token from which the Nth token is derived.
  EntityId NthDerivedTokenId(EntityOffset ti) const override {
    if (ti >= tokens.size()) {
      return mx::kInvalidEntityId;
    }
    auto [ri, to] = tokens[ti];
    return impl->readers[ri]->NthDerivedTokenId(to);
  }

  // Return the id of the parsed token which is derived from the Nth token.
  EntityId NthParsedTokenId(EntityOffset ti) const override {
    if (ti >= tokens.size()) {
      return mx::kInvalidEntityId;
    }
    auto [ri, to] = tokens[ti];
    return impl->readers[ri]->NthParsedTokenId(to);
  }

  // Return the id of the macro containing the Nth token.
  EntityId NthContainingMacroId(EntityOffset ti) const override {
    if (ti >= tokens.size()) {
      return mx::kInvalidEntityId;
    }
    auto [ri, to] = tokens[ti];
    return impl->readers[ri]->NthContainingMacroId(to);
  }

  // Return an entity id associated with the Nth token.
  EntityId NthRelatedEntityId(EntityOffset ti) const override {
    if (ti >= tokens.size()) {
      return mx::kInvalidEntityId;
    }
    auto [ri, to] = tokens[ti];
    return impl->readers[ri]->NthRelatedEntityId(to);
  }

  // Return the entity associated with the Nth token.
  VariantEntity NthRelatedEntity(EntityOffset ti) const override {
    if (ti >= tokens.size()) {
      return NotAnEntity{};
    }
    auto [ri, to] = tokens[ti];
    return impl->readers[ri]->NthRelatedEntity(to);
  }

  // Return the id of the Nth token.
  EntityId NthTokenId(EntityOffset ti) const override {
    if (ti >= tokens.size()) {
      return mx::kInvalidEntityId;
    }
    auto [ri, to] = tokens[ti];
    return impl->readers[ri]->NthTokenId(to);
  }

  EntityId NthFileTokenId(EntityOffset ti) const override {
    if (ti >= tokens.size()) {
      return mx::kInvalidEntityId;
    }
    auto [ri, to] = tokens[ti];
    return impl->readers[ri]->NthFileTokenId(to);
  }

  // Returns `true` if `this` is logically equivalent to `that`.
  bool Equals(const TokenReader *that_) const override {
    if (this == that_) {
      return true;
    }

    auto that = dynamic_cast<const TokenTreeReader *>(that_);
    if (!that) {
      return false;
    }

    // Different data is being shown, easy to count as different.
    if (data_hash != that->data_hash) {
      return false;
    }

    if (impl != that->impl) {

      // Not configured to look at the same high-level entities.
      if (impl->file != that->impl->file ||
          impl->fragment != that->impl->fragment) {
        return false;
      }

      // Can't compare the readers.
      auto num_readers = impl->readers.size();
      if (num_readers != that->impl->readers.size()) {
        return false;
      }

      // Check that all readers match.
      for (auto i = 0u; i < num_readers; ++i) {
        if (!impl->readers[i]->Equals(that->impl->readers[i].get())) {
          return false;
        }
      }
    }

    // Readers match, make sure the token indices match.
    return tokens == that->tokens;
  }
};

static void CollectTokens(const Node &node, const TokenTreeVisitor &vis,
                          std::vector<TokenIndex> &tokens) {
  if (std::holds_alternative<std::monostate>(node)) {
    return;

  } else if (std::holds_alternative<TokenIndex>(node)) {
    tokens.push_back(std::get<TokenIndex>(node));

  } else if (std::holds_alternative<ChoiceNode *>(node)) {
    if (ChoiceNode *choice = std::get<ChoiceNode *>(node)) {
      PackedFragmentId chosen_frag = vis.choose(choice->fragments).id();
      auto i = 0u;
      for (const Fragment &frag : choice->fragments) {
        if (chosen_frag == frag.id()) {
          const Node &frag_node = choice->children[i];
          CollectTokens(frag_node, vis, tokens);
        }
        ++i;
      }
    }
  } else if (std::holds_alternative<SubstitutionNode *>(node)) {
    if (SubstitutionNode *sub = std::get<SubstitutionNode *>(node)) {
      auto should_expand = false;
      if (std::holds_alternative<MacroSubstitution>(sub->macro)) {
        should_expand = vis.should_expand(
            std::get<MacroSubstitution>(sub->macro));
      } else if (std::holds_alternative<MacroVAOpt>(sub->macro)) {
        should_expand = vis.should_expand(std::get<MacroVAOpt>(sub->macro));
      } else {
        assert(false);
      }
      if (should_expand) {
        CollectTokens(sub->after, vis, tokens);
      } else {
        CollectTokens(sub->before, vis, tokens);
      }
    }
  } else if (std::holds_alternative<SequenceNode *>(node)) {
    if (SequenceNode *seq = std::get<SequenceNode *>(node)) {
      for (const Node &sub_node : seq->children) {
        CollectTokens(sub_node, vis, tokens);
      }
    }
  } else {
    assert(false);
  }
}

}  // namespace

// Serialize the token tree into a linear range.
TokenRange TokenTree::serialize(const TokenTreeVisitor &vis) const {
  auto reader = std::make_shared<TokenTreeReader>(impl);
  CollectTokens(impl->root, vis, reader->tokens);
  EntityOffset num_tokens = static_cast<EntityOffset>(reader->tokens.size());

  // Copy in the token data.
  reader->token_offset.reserve(num_tokens + 1u);
  reader->token_offset.emplace_back(0u);
  for (EntityOffset ti = 0u; ti < num_tokens; ++ti) {
    auto [ri, to] = reader->tokens[ti];
    const TokenReader::Ptr &tok_reader = impl->readers[ri];
    std::string_view tok_data = tok_reader->NthTokenData(to);
    if (!tok_data.empty()) {
      reader->data.insert(reader->data.end(), tok_data.begin(), tok_data.end());
    }

    reader->token_offset.emplace_back(
        static_cast<EntityOffset>(reader->data.size()));
  }

  reader->data_hash = kHasher(reader->data);

  return TokenRange(std::move(reader), 0u, num_tokens);
}

}  // namespace mx
