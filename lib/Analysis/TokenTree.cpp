// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Analysis/TokenTree.h>

#include <algorithm>
#include <functional>
#include <iterator>
#include <multiplier/Entities/MacroParameterSubstitution.h>
#include <multiplier/Entities/MacroParameter.h>
#include <type_traits>
#include <unordered_map>
#include <vector>

#include "../File.h"
#include "../Fragment.h"
#include "../Token.h"

//#define D(...) __VA_ARGS__
#ifndef D
# define D(...)
#endif
#if D(1 +) 0
#include <iostream>
#endif

namespace mx {
namespace {

static const std::hash<std::string> kHasher;

#define FILL_MACRO_CHILREN(generator, children_name, file_tokens_name) \
  std::vector<MacroOrToken> children_name; \
  std::vector<Token> file_tokens_name; \
  for (MacroOrToken mt : generator) { \
    if (std::holds_alternative<Token>(mt)) { \
      file_tokens_name.emplace_back(std::get<Token>(mt).file_token()); \
    } else { \
      file_tokens_name.emplace_back(LeftCornerOfUse(std::get<Macro>(mt)).file_token()); \
    } \
    children_name.emplace_back(std::move(mt)); \
  }

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


// If the `i`th thing of `before` is a `, ## __VA_ARGS__` then return `true`
// if the `__VA_ARGS__` expands to something, and `false` if it expands to
// nothing. If it's not a paste of `__VA_ARGS__` then return `std::nullopt`.
static std::optional<bool> EndsWithEmptyVAArgs(
    const std::vector<MacroOrToken> &before) {
  auto num_entries = before.size();
  if (3u > num_entries) {
    return std::nullopt;
  }

  const Token *comma = std::get_if<Token>(&(before[num_entries - 3u]));
  const Token *hash_hash = std::get_if<Token>(&(before[num_entries - 2u]));
  const Macro *param_sub = std::get_if<Macro>(&(before[num_entries - 1u]));

  if (!comma || !hash_hash || !param_sub) {
    return std::nullopt;
  }

  if (comma->kind() != TokenKind::COMMA ||
      hash_hash->kind() != TokenKind::HASH_HASH ||
      param_sub->kind() != MacroKind::PARAMETER_SUBSTITUTION) {
    return std::nullopt;
  }

  // Not a `...` or a GNU named variadic argument, e.g. `args...`.
  auto param = MacroParameterSubstitution::from(*param_sub);
  if (!param->parameter().variadic_dots()) {
    return std::nullopt;
  }

  return !LeftCornerOfExpansion(*param_sub);
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

// We want to match the body of a macro, or the intermediate children of a macro
// with the expansion of a macro. To best do this, we need to match the actual
// uses of an expansion themselves, and align on those. This does the flattening
// in a way that maximizes our chances of merging against a macro body or an
// intermediate macro body.
static void FlattenExpansionUses(
    MacroOrToken mt, std::vector<MacroOrToken> &out) {
  if (std::holds_alternative<Token>(mt)) {
    out.emplace_back(std::move(mt));
  } else if (std::holds_alternative<Macro>(mt)) {
    Macro m = std::move(std::get<Macro>(mt));
    switch (m.kind()) {
      case MacroKind::EXPANSION:
      case MacroKind::CONCATENATE:
      case MacroKind::SUBSTITUTION:
      case MacroKind::ARGUMENT:
        for (MacroOrToken sub_mt : m.children()) {
          FlattenExpansionUses(std::move(sub_mt), out);
        }
        break;
      default:
        out.emplace_back(std::move(m));
        break;
    }
  } else {
    assert(false);
  }
}

static std::optional<MacroVAOpt> AsMacroVAOpt(const MacroOrToken &mt) {
  if (!std::holds_alternative<Macro>(mt)) {
    return std::nullopt;
  }
  return MacroVAOpt::from(std::get<Macro>(mt));
}

// Conditionally take the `...` of a `__VA_OPT__(...)` and put it into `out`.
// This will be more likely to match against an expanded macro body.
//
// TODO(pag): Think about whitespace prior to the `__VA_OPT__`. Maybe have a
//            way of "drilling up" to the relevant thing in the logic that
//            injects whitespace?
static void GenerateVAOptChildrenInto(MacroVAOpt va_opt,
                                      std::vector<MacroOrToken> &out) {
  if (va_opt.contents_are_elided()) {
    return;
  }

  int paren_count = 0;
  for (MacroOrToken mt : va_opt.children()) {

    if (std::holds_alternative<Token>(mt)) {
      TokenKind tk = std::get<Token>(mt).kind();
      int test_paren_count = paren_count;
      if (tk == TokenKind::L_PARENTHESIS) {
        ++paren_count;
      } else if (tk == TokenKind::R_PARENTHESIS) {
        --paren_count;
        test_paren_count = paren_count;
      }

      if (test_paren_count) {
        out.emplace_back(std::move(mt));
      }
    } else if (paren_count) {
      out.emplace_back(std::move(mt));

    } else {
      assert(false);  // Found a macro thing outside of the parens?
    }
  }
}


// Tries to figure out if we're in an obscure non-tree trailing macro
// expansion case. This happens with things like:
//
//      #define HEAD TAIL(
//      #define TAIL(x) x
//      ...
//        return HEAD 1);
//
// This can be complicated by recursive use of tail-macros, e.g.:
//
//      #define HEAD DO_TAIL
//      #define DO_TAIL TAIL(
//      #define TAIL(x) x
//      ...
//        return HEAD 1);
static std::optional<MacroExpansion> NonTreeTailExpansion(
    DefineMacroDirective &def_containing_te_use, MacroExpansion &te) {
  // Get the right corner of the macro use for the trailing expansion. We want
  // to identify if the `)` of a function-like macro call isn't from inside
  // `bounds`.
  Token rc_use = RightCornerOfUse(te);
  D( std::cerr << " rc_use " << rc_use.id() << ": " << rc_use.data() << '\n'; )
  if (!rc_use) {
    return std::nullopt;
  }

  // If the right corner of the macro use, which is presumably a `)`, is
  // NOT directly derived from the right corner of the macro defintion, then
  // we're not in a simple expansion.
  Token rc_def = RightCornerOfUse(def_containing_te_use);
  D( std::cerr << " rc_def " << rc_def.id() << ": " << rc_def.data() << '\n'; )
  if (rc_use.derived_token().file_token() != rc_def.file_token()) {
    return te;
  }

  // Need to check the recursive case.
  std::optional<MacroExpansion> next_te = TrailingExpansionInExpansion(te);
  std::optional<DefineMacroDirective> te_def = te.definition();
  if (!next_te || !te_def) {
    return std::nullopt;
  }

  return NonTreeTailExpansion(te_def.value(), next_te.value());
}

struct BodyTokenForChild {
  // The child from the replacement body of a macro substitution.
  MacroOrToken mt;

  // A token from a macro's definition body that we have matched against `mt`.
  // We use this to determine whitespace injection.
  Token definition_token;

  // Tells us if the tokens are from the usage site, i.e. argument tokens.
  bool is_argument;

  BodyTokenForChild(void) = delete;

  inline BodyTokenForChild(MacroOrToken mt_, Token definition_token_,
                           bool is_argument_)
      : mt(std::move(mt_)),
        definition_token(std::move(definition_token_)),
        is_argument(is_argument_) {}
};

}  // namespace

struct TokenTreeImpl::MacroExpansionProcessor {

  std::vector<MacroOrToken> body_children;
  std::vector<MacroOrToken> after_children;
  std::vector<BodyTokenForChild> merged_children;

  void Init(const MacroExpansion &me, const DefineMacroDirective &def);
  bool Run(bool is_non_tree);

  void InitTrailingNonTree(const MacroExpansion &te);

  inline const std::vector<BodyTokenForChild> &ReplacementChildren(void) const {
    return merged_children;
  }
};

void TokenTreeImpl::MacroExpansionProcessor::Init(
    const MacroExpansion &me, const DefineMacroDirective &def) {

  body_children.clear();
  after_children.clear();
  merged_children.clear();

  for (MacroOrToken mt : me.replacement_children()) {
    FlattenExpansionUses(std::move(mt), after_children);
  }

  for (MacroOrToken mt : me.intermediate_children()) {

    // Expand or eliminate a `__VA_OPT__`.
    //
    // TODO(pag): Leading whitespace? Maybe have a new variant that can hold
    //            on to some token for whitespace purposes, or a new vector
    //            for leading whitespace.
    if (std::optional<MacroVAOpt> va_opt = AsMacroVAOpt(mt)) {
      GenerateVAOptChildrenInto(std::move(va_opt.value()), body_children);

      // NOTE(pag): `__VA_OPT__` can contain `, ## __VA_ARGS__`.

    } else {
      body_children.emplace_back(std::move(mt));
    }

    // If the thing has a use of `## , __VA_ARGS__`, then we need to convert
    // this into `, <stuff>` or nothing.
    if (auto is_empty = EndsWithEmptyVAArgs(body_children)) {
      D( std::cerr << "BT(" << (body_children.size() - 3)
                   << ") has `, ## __VA_ARGS__`\n"; )

      mt = std::move(body_children.back());
      body_children.pop_back();
      body_children.pop_back();  // `##`.
      MacroOrToken comma = std::move(body_children.back());
      body_children.pop_back();

      if (!is_empty.value()) {
        body_children.push_back(std::move(comma));
        FlattenExpansionUses(std::move(mt), body_children);
      }

    }
  }

  if (body_children.empty()) {
    for (MacroOrToken mt : def.body()) {
      body_children.emplace_back(std::move(mt));
    }
  }
}

void TokenTreeImpl::MacroExpansionProcessor::InitTrailingNonTree(
    const MacroExpansion &te) {
  after_children.clear();
  merged_children.clear();

  for (MacroOrToken mt : te.children()) {
    after_children.emplace_back(std::move(mt));
  }

  std::reverse(after_children.begin(), after_children.end());
  std::reverse(body_children.begin(), body_children.end());
}

bool TokenTreeImpl::MacroExpansionProcessor::Run(bool is_non_tree) {
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
      assert(std::holds_alternative<Macro>(bt));
      const Macro &bt_macro = std::get<Macro>(bt);
      is_argument = bt_macro.kind() == MacroKind::PARAMETER_SUBSTITUTION;
      bt_lc = LeftCornerOfExpansion(bt_macro);
      bt_tok = &bt_lc;
    }

    if (!at_tok) {
      assert(std::holds_alternative<Macro>(at));
      at_lc = LeftCornerOfUse(std::get<Macro>(at));
      at_tok = &at_lc;
      assert(*at_tok);
    }

    assert(bt_tok && at_tok);

    D( std::cerr << "BT(" << i << "): " << bt_tok->id() << ' ' << bt_tok->data() << '\n'; )
    D( std::cerr << "AT(" << j << "): " << at_tok->id() << ' ' << at_tok->data() << "\n\n"; )

    // A parameter was substituted with nothing.
    if (!bt_lc) {
      ++i;

    } else if (bt_tok->data() == at_tok->data()) {
      merged_children.emplace_back(at, bt_tok->file_token(), is_argument);
      ++i;
      ++j;

    // Skip over stuff in expansions.
    } else {
      merged_children.emplace_back(at, Token(), is_argument);
      ++j;
    }
  }

#if D( 1 + ) 0
  for (auto missing_j = j; missing_j < max_j; ++missing_j) {
    const MacroOrToken &at = after_children[missing_j];
    const Token *at_tok = std::get_if<Token>(&at);
    if (!at_tok) {
      at_lc = LeftCornerOfExpansion(std::get<Macro>(at));
      at_tok = &at_lc;
    }
    std::cerr << "MISSING_AT(" << missing_j << "): "
              << at_tok->id() << ' ' << at_tok->data() << "\n";
  }
#endif

  if (is_non_tree) {
    return j == max_j || i == max_i;
  }

  for (; j < max_j; ++j) {
    merged_children.emplace_back(after_children[j], Token(), false);
  }

#if D( 1 + ) 0
  for (auto missing_i = i; missing_i < max_i; ++missing_i) {
    const MacroOrToken &bt = body_children[missing_i];
    const Token *bt_tok = std::get_if<Token>(&bt);
    if (!bt_tok) {
      bt_lc = LeftCornerOfExpansion(std::get<Macro>(bt));
      bt_tok = &bt_lc;
    }
    std::cerr << "MISSING_BT(" << missing_i << "): "
              << bt_tok->id() << ' ' << bt_tok->data() << "\n";
  }
#endif

  return i == max_i && j == max_j;
}

// NOTE(pag): This will reset `curr_leaf` if `that == curr_leaf` and
//            `curr_leaf` is empty.
template <typename T>
TokenTreeImpl::SequenceNode *TokenTreeImpl::AddToSequence(
    SequenceNode *seq, T *that) {
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

TokenTreeImpl::SequenceNode *TokenTreeImpl::AddTokenToSequence(
    SequenceNode *seq, const Token &tok) {
  return AddTokenToSequence(seq, GetOrCreateIndex(tok));
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::AddTokenToSequence(
    SequenceNode *seq, TokenIndex ti) {
  if (!seq) {
    seq = &(sequences.emplace_back());
  }
  seq->children.push_back(ti);
  return seq;
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::AddNodeToSequence(
    SequenceNode *seq, const Node &node) {
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

// Find the bounds of a top-level macro use.
std::optional<TokenTreeImpl::Bounds> TokenTreeImpl::TopLevelUseBounds(
    const Macro &exp) {
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

TokenTreeImpl::Bounds TokenTreeImpl::FragmentBounds(const TokenRange &tokens) {
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
std::optional<TokenTreeImpl::Bounds> TokenTreeImpl::MacroBodyBounds(
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
TokenTreeImpl::TokenIndex TokenTreeImpl::GetOrCreateIndex(const Token &tok) {
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
TokenTreeImpl::SequenceNode *TokenTreeImpl::AddLeadingTokensInBounds(
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

TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithMacroChild(
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

TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithMacroChildren(
    SequenceNode *seq, const Macro &macro, const Bounds &bounds) {
  FILL_MACRO_CHILREN(macro.children(), mts, fts)
  return ProcessMacroChildren(seq, bounds, std::move(mts), std::move(fts));
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithSimpleExpansion(
    SequenceNode *seq, const MacroExpansion &me,
    const DefineMacroDirective &me_def, const Bounds &user_bounds,
    const Bounds &def_bounds) {

  MacroExpansionProcessor mep;
  mep.Init(me, me_def);
  if (!mep.Run(false)) {
    assert(false);  // Probably a bug.
    return ExtendWithSubstitution(seq, me, user_bounds);
  }

  FILL_MACRO_CHILREN(me.children(), mts, fts)
  SequenceNode *before = ProcessMacroChildren(
      nullptr, user_bounds, std::move(mts), std::move(fts));

  if (!before) {
    return nullptr;
  }

  SequenceNode *after = nullptr;
  for (const BodyTokenForChild &node : mep.ReplacementChildren()) {
    after = AddLeadingTokensInBounds(after, node.definition_token, def_bounds);
    if (node.is_argument) {
      after = ExtendWithMacroChild(after, node.mt, user_bounds);
    } else {
      after = ExtendWithMacroChild(after, node.mt, def_bounds);
    }
  }

  SubstitutionNode *sub = &(substitutions.emplace_back(me));
  sub->before = before;
  if (after) {
    sub->after = after;
  }

  return AddToSequence(seq, sub);
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::ProcessMacroChildren(
    TokenTreeImpl::SequenceNode *seq, const Bounds &bounds,
    std::vector<MacroOrToken> mts, std::vector<Token> fts) {

  size_t num_mts = mts.size();
  for (auto i = 0u; i < num_mts; ++i) {
    const MacroOrToken &mt = mts[i];

    if (std::holds_alternative<Token>(mt)) {
      const Token &tok = std::get<Token>(mt);
      seq = AddLeadingTokensInBounds(seq, fts[i], bounds);
      seq = AddTokenToSequence(seq, tok);
      continue;
    }

    if (!std::holds_alternative<Macro>(mt)) {
      assert(false);
      continue;
    }

    const Macro &m = std::get<Macro>(mt);
    const Token &lc_ft = fts[i];

    // Try to get stricter bounds on the macro use.
    if (!lc_ft) {
      seq = ExtendWithMacro(seq, m, bounds);
      continue;
    }

    TokenIndex lc_index = GetOrCreateIndex(lc_ft);
    Bounds new_bounds = bounds;
    if (new_bounds.reader_index != lc_index.first) {
      seq = ExtendWithMacro(seq, m, bounds);
      continue;
    }

    assert(new_bounds.begin_index <= lc_index.second);
    new_bounds.begin_index = lc_index.second;

    if ((i + 1u) < num_mts) {
      const Token &rc_ft = fts[i + 1u];
      if (rc_ft) {
        TokenIndex rc_index = GetOrCreateIndex(rc_ft);
        if (new_bounds.reader_index == rc_index.first &&
            rc_index.second) {
          assert(new_bounds.begin_index <= rc_index.second);
          assert(rc_index.second <= new_bounds.end_index);
          new_bounds.end_index = rc_index.second - 1u;
        }
      }
    }

    seq = AddLeadingTokensInBounds(seq, lc_ft, bounds);
    seq = ExtendWithMacro(seq, m, new_bounds);
  }

  return seq;
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
TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithNonTreeExpansion(
    SequenceNode *seq,
    const MacroExpansion &me, const Bounds &me_bounds,
    const DefineMacroDirective &def, const Bounds &def_bounds,
    const MacroExpansion &dte) {

  D( std::cerr << "non-tree " << def.name().data() << "\n"; )

  MacroExpansionProcessor mep;
  mep.Init(me, def);
  if (!mep.Run(true)) {
    assert(false);  // Probably not a bug, just something sketchy/odd.
    return ExtendWithSubstitution(seq, me, me_bounds);
  }

  FILL_MACRO_CHILREN(me.children(), mts, fts)
  SequenceNode *before = ProcessMacroChildren(
      nullptr, me_bounds, std::move(mts), std::move(fts));

  if (!before) {
    return seq;
  }

  SequenceNode *after = nullptr;
  for (const BodyTokenForChild &node : mep.ReplacementChildren()) {
    after = AddLeadingTokensInBounds(after, node.definition_token, def_bounds);
    if (node.is_argument) {
      after = ExtendWithMacroChild(after, node.mt, me_bounds);
    } else {
      after = ExtendWithMacroChild(after, node.mt, def_bounds);
    }
  }

  mep.InitTrailingNonTree(dte);

//  // Collect the trailing macro nodes, including argument nodes, that were
//  // out-of-order.
//  auto failed = true;
//
//  if (false && mep.Run(true)) {
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
//  if (failed) {
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

    D( std::cerr << "Trailing token: " << te_tok.data() << '\n'; )

    trailing_toks.emplace_back(std::move(te_tok));
  }

  // TODO(pag): Ideally, we'd be merging in the
  for (const Token &tok : trailing_toks) {
    before = AddLeadingTokensInBounds(before, tok.file_token(), me_bounds);
    before = AddTokenToSequence(before, tok);
  }

//  }

  SubstitutionNode *sub = &(substitutions.emplace_back(me));
  sub->before = before;
  if (after) {
    sub->after = after;
  }

  return AddToSequence(seq, sub);
}

// Extend with a macro expansion. The work here is in figuring out whether or
// not we're in a "non-tree" case.
TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithExpansion(
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

  auto dte = NonTreeTailExpansion(def.value(), te.value());
  if (!dte) {
    return ExtendWithSimpleExpansion(seq, me, def.value(), user_bounds,
                                     def_bounds.value());
  }

  return ExtendWithNonTreeExpansion(
      seq, me, user_bounds, def.value(), def_bounds.value(), dte.value());
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithSubstitution(
    SequenceNode *seq, const MacroSubstitution &macro,
    const Bounds &use_bounds) {

  FILL_MACRO_CHILREN(macro.children(), mts, fts)
  SequenceNode *before = ProcessMacroChildren(
      nullptr, use_bounds, std::move(mts), std::move(fts));

  if (!before) {
    return seq;
  }

  SubstitutionNode *sub = &(substitutions.emplace_back(macro));
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

TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithMacro(
    SequenceNode *seq, const Macro &macro, const Bounds &bounds) {

  if (auto ms = MacroSubstitution::from(macro)) {
    if (auto me = MacroExpansion::from(macro)) {
      seq = ExtendWithExpansion(seq, me.value(), bounds);
    } else {
      seq = ExtendWithSubstitution(seq, ms.value(), bounds);
    }

  } else {
    seq = ExtendWithMacroChildren(seq, macro, bounds);
  }

  return seq;
}

// Create a node for a fragment. If the fragment has file tokens, then the
// returned node will "expand" out to include the file tokens.
TokenTreeImpl::Node TokenTreeImpl::CreateFragmentNode(
    const Fragment &entity, const Bounds &bounds) {

  FILL_MACRO_CHILREN(entity.preprocessed_code(), mts, fts)
  SequenceNode *seq = ProcessMacroChildren(
      nullptr, bounds, std::move(mts), std::move(fts));

  if (!seq) {
    return {};
  }

  return seq;
}

// Create a node for a file. If there are overlapping fragments in this file,
// then this will include them.
TokenTreeImpl::Node TokenTreeImpl::CreateFileNode(const File &entity) {

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

// Choose which fragment to show.
Fragment TokenTreeVisitor::choose(const std::vector<Fragment> &frags) const {
  return frags.front();
}

static const std::shared_ptr<TokenTreeImpl> kInvalidTree =
    std::make_shared<TokenTreeImpl>();

TokenTree::TokenTree(void)
    : TokenTree(kInvalidTree) {}

TokenTree TokenTree::from(const File &file) {
  auto self = file.impl->cached_token_tree.Get();
  if (self) {
    return TokenTree(std::move(self));
  }

  self = std::make_shared<TokenTreeImpl>();
  auto file_tokens = file.tokens();
  self->readers.emplace_back(file_tokens.impl);
  self->root = self->CreateFileNode(file);

  return TokenTree(file.impl->cached_token_tree.Put(std::move(self)));
}

TokenTree TokenTree::from(const Fragment &frag) {
  auto self = frag.impl->cached_token_tree.Get();
  if (self) {
    return TokenTree(std::move(self));
  }

  self = std::make_shared<TokenTreeImpl>();
  self->fragment = frag.impl;

  if (auto opt_file = File::containing(frag)) {
    auto file_tokens = opt_file->tokens();
    self->file = opt_file->impl;
    self->readers.emplace_back(file_tokens.impl);
  } else {
    self->readers.emplace_back(TokenRange().impl);
  }

  TokenTreeImpl::Bounds frag_bounds = self->FragmentBounds(frag.file_tokens());
  self->root = self->CreateFragmentNode(frag, frag_bounds);

  return TokenTree(frag.impl->cached_token_tree.Put(std::move(self)));
}

namespace {

// Used for invalid tokens.
class TokenTreeReader final : public TokenReader {
 public:
  const std::shared_ptr<TokenTreeImpl> impl;
  std::vector<TokenTreeImpl::TokenIndex> tokens;

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

static void CollectTokens(const TokenTreeImpl::Node &node,
                          const TokenTreeVisitor &vis,
                          std::vector<TokenTreeImpl::TokenIndex> &tokens) {
  if (std::holds_alternative<std::monostate>(node)) {
    return;

  } else if (std::holds_alternative<TokenTreeImpl::TokenIndex>(node)) {
    tokens.push_back(std::get<TokenTreeImpl::TokenIndex>(node));

  } else if (std::holds_alternative<TokenTreeImpl::ChoiceNode *>(node)) {
    if (TokenTreeImpl::ChoiceNode *choice =
            std::get<TokenTreeImpl::ChoiceNode *>(node)) {
      PackedFragmentId chosen_frag = vis.choose(choice->fragments).id();
      auto i = 0u;
      for (const Fragment &frag : choice->fragments) {
        if (chosen_frag == frag.id()) {
          const TokenTreeImpl::Node &frag_node = choice->children[i];
          CollectTokens(frag_node, vis, tokens);
        }
        ++i;
      }
    }
  } else if (std::holds_alternative<TokenTreeImpl::SubstitutionNode *>(node)) {
    if (TokenTreeImpl::SubstitutionNode *sub =
            std::get<TokenTreeImpl::SubstitutionNode *>(node)) {
      auto should_expand = false;
      if (std::holds_alternative<MacroSubstitution>(sub->macro)) {
        should_expand = vis.should_expand(
            std::get<MacroSubstitution>(sub->macro));
      } else {
        assert(false);
      }
      if (should_expand) {
        CollectTokens(sub->after, vis, tokens);
      } else {
        CollectTokens(sub->before, vis, tokens);
      }
    }
  } else if (std::holds_alternative<TokenTreeImpl::SequenceNode *>(node)) {
    if (TokenTreeImpl::SequenceNode *seq =
            std::get<TokenTreeImpl::SequenceNode *>(node)) {
      for (const TokenTreeImpl::Node &sub_node : seq->children) {
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

// Return the file containing the token tree.
std::optional<File> File::containing(const TokenTree &tree) {
  if (tree.impl->file) {
    return File(tree.impl->file);
  } else if (tree.impl->fragment) {
    return File::containing(Fragment(tree.impl->fragment));
  } else {
    return std::nullopt;
  }
}

// Return the fragment containing a token tree.
std::optional<Fragment> Fragment::containing(const TokenTree &tree) {
  if (tree.impl->fragment) {
    return Fragment(tree.impl->fragment);
  } else {
    return std::nullopt;
  }
}

}  // namespace mx
