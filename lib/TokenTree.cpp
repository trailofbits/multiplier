// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "TokenTree.h"

#include <algorithm>
#include <functional>
#include <iterator>
#include <multiplier/Entities/MacroParameterSubstitution.h>
#include <multiplier/Entities/MacroParameter.h>
#include <type_traits>
#include <unordered_map>
#include <vector>

#include "File.h"
#include "Fragment.h"

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

class SaveRestoreLastSequence final {
  const TokenTreeImpl::SequenceNode *&last_sequence;
  const TokenTreeImpl::SequenceNode * const old_val;

 public:

  inline SaveRestoreLastSequence(
      const TokenTreeImpl::SequenceNode *&last_sequence_,
      const TokenTreeImpl::SequenceNode *new_val_)
      : last_sequence(last_sequence_),
        old_val(last_sequence) {
    if (new_val_) {
      last_sequence = new_val_;
    }
  }

  inline ~SaveRestoreLastSequence(void) {
    last_sequence = old_val;
  }
};

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
  if (!param) {
    return std::nullopt;
  }

  Token va_args = LeftCornerOfUse(param.value());
  if (va_args.data() != "__VA_ARGS__") {

    // If it's not `__VA_ARGS__`, then it might be a GNU named variadic
    // argument.
    //
    // TODO(pag): Eventually just use this method. Old indexers had issues
    //            serializing parameter references.
    if (!param->parameter().variadic_dots()) {
      return std::nullopt;
    }
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
    MacroOrToken mt, unsigned depth, std::vector<MacroOrToken> &out,
    std::vector<std::optional<MacroOrToken>> &out_orig) {

  if (std::holds_alternative<Token>(mt)) {
    if (!depth) {
      out_orig.emplace_back(mt);

    } else if (out_orig.size() == out.size()) {
      out_orig.emplace_back();
    }

    out.emplace_back(std::move(mt));

  } else if (std::holds_alternative<Macro>(mt)) {
    Macro m = std::move(std::get<Macro>(mt));
    switch (m.kind()) {
      case MacroKind::EXPANSION:
      case MacroKind::CONCATENATE:
      case MacroKind::SUBSTITUTION:
        if (!depth) {
          out_orig.emplace_back(m);

        } else if (out_orig.size() == out.size()) {
          out_orig.emplace_back();
        }
        for (MacroOrToken sub_mt : m.children()) {
          FlattenExpansionUses(std::move(sub_mt), depth + 1u, out, out_orig);
        }
        break;
      case MacroKind::ARGUMENT:
        for (MacroOrToken sub_mt : m.children()) {
          FlattenExpansionUses(std::move(sub_mt), depth, out, out_orig);
        }
        break;
      default:
        if (!depth) {
          out_orig.emplace_back(m);

        } else if (out_orig.size() == out.size()) {
          out_orig.emplace_back();
        }
        out.emplace_back(std::move(m));
        break;
    }
  } else {
    assert(false);
  }

  assert(out_orig.size() == out.size());
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
static void GenerateVAOptChildrenInto(
    MacroVAOpt va_opt, std::vector<MacroOrToken> &out,
    std::vector<std::optional<MacroOrToken>> &out_orig) {

  if (va_opt.contents_are_elided()) {
    return;
  }

  for (MacroOrToken mt : va_opt.children()) {
    if (Macro *m = std::get_if<Macro>(&mt);
        m && m->kind() == MacroKind::VA_OPT_ARGUMENT) {
      out_orig.emplace_back(mt);
      out.emplace_back(std::move(mt));
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
    const DefineMacroDirective &def_containing_te_use,
    const MacroExpansion &exp_containing_te_use,
    const MacroExpansion &te) {

  // Get the right corner of the macro use for the trailing expansion. We want
  // to identify if the `)` of a function-like macro call isn't from inside
  // `bounds`.
  Token rc_use = RightCornerOfUse(te);
  D( std::cerr << " rc_use " << rc_use.id() << ": " << rc_use.data() << '\n'; )
  if (!rc_use) {
    return std::nullopt;
  }

  std::optional<MacroExpansion> next_te = TrailingExpansionInExpansion(te);

  if (!next_te) {
    Token rc_def = RightCornerOfUse(def_containing_te_use);
    D( std::cerr << " rc_def " << rc_def.id() << ": " << rc_def.data() << '\n'; )

    // If this is the deepest macro expansion, and if the right corner of the
    // macro use, which is presumably a `)`, is directly derived from the
    // right corner of the macro definition, then we're in a simple expansion.
    if (rc_use.file_token() == rc_def.file_token()) {
      return std::nullopt;
    }

    // Next, try to figure out if the `)` came from an argument, e.g. in the
    // case of the `_Pragma`s `)` in `MACRO(_Pragma(...))`.
    std::optional<Macro> parent = rc_use.derived_token().containing_macro();
    for (; parent; parent = parent->parent()) {
      if (parent.value() == exp_containing_te_use) {
        return std::nullopt;
      }
    }

    return te;
  }

  // We probably have a trailing expansion. One corner case that gets in the
  // way is `_Pragma`s, which are not subjected to the argument pre-expansion
  // phase, and so their expansions show up in the `.replacement_children()`,
  // not in the `MacroArgument`s.

  // If `te` is a trailing expansion that itself contains a trailing expansion
  // `next_te`, then we can only really do analysis if we can locate elements of
  // `next_te`s use in the defintion of `te`. If we have no such definition,
  // then bail out.
  std::optional<DefineMacroDirective> te_def = te.definition();
  if (!te_def) {
    return std::nullopt;
  }

  D( std::cerr << "Recursing into " << te_def->name().data()
               << "'s trailing expansion\n"; )

  std::optional<MacroExpansion> nte = NonTreeTailExpansion(
      te_def.value(), te, next_te.value());
  if (!nte.has_value()) {
    return std::nullopt;
  }

  D( std::cerr << "Found non-tree trailing " << nte->definition()->name().data()
               << '\n'; )

  // Need to detect the case of a `_Pragma` expansion. We do this by checking if
  // the nested expansion `)` matches the current expansion `)`.
  Token nte_rc_use = RightCornerOfUse(nte.value());
  if (nte_rc_use.derived_token() == rc_use) {
    return std::nullopt;
  }

  return nte;
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

  // Adjusted children from a macro definition body.
  std::vector<MacroOrToken> body_children;

  // Tokens or macros from the expansion of a macro, expanded out in a way that
  // can be compared against `body_children`.
  std::vector<MacroOrToken> after_children;

  // Non-expanded versions of `before_children` and `after_children`, where we
  // need to keep track of the unexpanded forms in order for `merged_children`
  // to be able to represent a complete expansion tree, otherwise
  // `merged_children` will only represent a single level deep of an expansion.
  std::vector<std::optional<MacroOrToken>> body_use;
  std::vector<std::optional<MacroOrToken>> after_use;

  // The result of aligning `body_children` with `after_children`, and then
  // selecting values from `body_children` or `after_use` to form up a proper
  // "view" of what the expanded children should look like.
  std::vector<BodyTokenForChild> merged_children;

  void Init(const MacroExpansion &me, const DefineMacroDirective &def);
  bool Run(bool is_non_tree);

  inline const std::vector<BodyTokenForChild> &ReplacementChildren(void) const {
    return merged_children;
  }
};

void TokenTreeImpl::MacroExpansionProcessor::Init(
    const MacroExpansion &me, const DefineMacroDirective &def) {

  body_children.clear();
  after_children.clear();
  body_use.clear();
  after_use.clear();
  merged_children.clear();

  for (MacroOrToken mt : me.replacement_children()) {
    FlattenExpansionUses(std::move(mt), 0u, after_children, after_use);
  }

  for (MacroOrToken mt : me.intermediate_children()) {

    // Expand or eliminate a `__VA_OPT__`.
    //
    // TODO(pag): Leading whitespace? Maybe have a new variant that can hold
    //            on to some token for whitespace purposes, or a new vector
    //            for leading whitespace.
    if (std::optional<MacroVAOpt> va_opt = AsMacroVAOpt(mt)) {
      GenerateVAOptChildrenInto(std::move(va_opt.value()), body_children,
                                body_use);

      // NOTE(pag): `__VA_OPT__` can contain `, ## __VA_ARGS__`.

    } else {
      body_use.emplace_back(mt);
      body_children.emplace_back(std::move(mt));
    }

    // If the thing has a use of `## , __VA_ARGS__`, then we need to convert
    // this into `, <stuff>` or nothing.
    if (auto is_empty = EndsWithEmptyVAArgs(body_children)) {
      D( std::cerr << "BT(" << (body_children.size() - 3)
                   << ") has `, ## __VA_ARGS__`\n"; )

      assert(body_children.size() == body_use.size());

      mt = std::move(body_children.back());
      body_children.pop_back();
      body_children.pop_back();  // `##`.
      MacroOrToken comma = std::move(body_children.back());
      body_children.pop_back();

      body_use.pop_back();
      body_use.pop_back();
      body_use.pop_back();

      if (!is_empty.value()) {
        body_use.emplace_back(comma);
        body_children.push_back(std::move(comma));

        FlattenExpansionUses(std::move(mt), 0u, body_children, body_use);
      }
    }
  }

  assert(after_children.size() == after_use.size());
  assert(body_children.size() == body_use.size());

  // If `body_children` is empty, then there was probably nothing interesting
  // in the macro body, i.e. no token concatenation, no parameter-to-argument
  // substitution, etc. So, we'll just collect the raw tokens from the macro
  // body.
  if (body_children.empty()) {
    for (MacroOrToken mt : def.body()) {
      body_use.emplace_back(mt);
      body_children.emplace_back(std::move(mt));
    }
  }
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
      MacroKind btk = bt_macro.kind();
      is_argument = btk == MacroKind::PARAMETER_SUBSTITUTION;
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

    if (i == 0 && j == 0 && max_i == 2 && max_j == 1 && bt_tok->data() == "x") {
      asm volatile ("nop;");
    }

    // A parameter was substituted with nothing.
    if (!bt_tok || !*bt_tok) {
      ++i;

    } else if (bt_tok->data() == at_tok->data()) {
      if (auto au = std::move(after_use[j])) {
        assert(au.has_value());
        merged_children.emplace_back(std::move(au.value()),
                                     bt_tok->file_token(), is_argument);
      }
      ++i;
      ++j;

    // Skip over stuff in expansions.
    } else {
      if (auto au = std::move(after_use[j])) {
        assert(au.has_value());
        merged_children.emplace_back(std::move(au.value()), Token(),
                                     is_argument);
      }
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
    if (auto au = std::move(after_use[j])) {
      assert(au.has_value());
      merged_children.emplace_back(std::move(au.value()), Token(), false);
    }
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
    SequenceNode *seq, T *that, const TrailingTokens &trailing_tokens) {
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
      goto end;
    }

  // Try to fold single-item choice nodes.
  } else if constexpr (std::is_same_v<ChoiceNode, T>) {
    if (that->children.size() == 1u) {
      return AddNodeToSequence(seq, that->children.front(), trailing_tokens);
    }
  }

  if (!seq) {
    seq = &(sequences.emplace_back());
  }

  seq->children.emplace_back(that);

end:
  return AddTrailingTokensToSequence(seq, trailing_tokens);
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::AddTokenToSequence(
    SequenceNode *seq, const Token &tok,
    const TrailingTokens &trailing_tokens) {
  return AddTrailingTokensToSequence(
      AddTokenToSequence(seq, GetOrCreateIndex(tok)),
      trailing_tokens);
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
    SequenceNode *seq, const Node &node,
    const TrailingTokens &trailing_tokens) {
  return std::visit<SequenceNode *>(
      [=, &trailing_tokens] (auto &&arg) -> SequenceNode * {
        using arg_t = std::decay_t<decltype(arg)>;
        if constexpr (std::is_pointer_v<arg_t>) {
          return AddToSequence(seq, arg, trailing_tokens);
        } else if constexpr (std::is_same_v<arg_t, TokenIndex>) {
          return AddTrailingTokensToSequence(AddTokenToSequence(seq, arg),
                                             trailing_tokens);
        } else {
          return seq;
        }
      },
      node);
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::AddTrailingTokensToSequence(
    SequenceNode *seq, const TrailingTokens &trailing_tokens) {

  auto prev_depth = depth;
  for (const Token &tok : trailing_tokens.tokens) {
    depth = trailing_tokens.depth;
    seq = AddLeadingTokensInBounds(seq, tok.file_token(), trailing_tokens.bounds);
    seq = AddTokenToSequence(seq, GetOrCreateIndex(tok));
  }

  if (trailing_tokens.next_trailing) {
    seq = AddTrailingTokensToSequence(seq, *(trailing_tokens.next_trailing));
  }

  depth = prev_depth;
  return seq;
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

  for (MacroOrToken mt : def.body()) {
    if (std::holds_alternative<Token>(mt)) {
      if (Token file_tok = std::get<Token>(mt).file_token()) {
        if (!last_tok) {
          TokenIndex ti = GetOrCreateIndex(file_tok);
          ret.reader_index = ti.first;
          ret.begin_index = ti.second;
          ret.end_index = ret.begin_index;
        }
        last_tok = std::move(file_tok);
      }

    } else if (std::holds_alternative<Macro>(mt)) {
      const Macro &m = std::get<Macro>(mt);
      if (Token file_tok = LeftCornerOfUse(m).file_token()) {
        if (!last_tok) {
          TokenIndex ti = GetOrCreateIndex(file_tok);
          ret.reader_index = ti.first;
          ret.begin_index = ti.second;
          ret.end_index = ret.begin_index;
        }

        last_tok = std::move(file_tok);
        if (auto rc_file_tok = RightCornerOfUse(m).file_token()) {
          last_tok = std::move(rc_file_tok);
        }
      }
    }
  }

  if (!last_tok) {
    return std::nullopt;
  }

  TokenIndex ti = GetOrCreateIndex(last_tok);
  assert(ti.first == ret.reader_index);
  assert(ti.second >= ret.begin_index);
  ret.end_index = ti.second;

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

// Get the `TokenIndex` that is the right corner of an existing use.
static std::optional<TokenTreeImpl::TokenIndex> RightCornerOfUse(
    const TokenTreeImpl::Node &node) {
  if (std::holds_alternative<TokenTreeImpl::TokenIndex>(node)) {
    return std::get<TokenTreeImpl::TokenIndex>(node);

  } else if (std::holds_alternative<TokenTreeImpl::ChoiceNode *>(node)) {
    return RightCornerOfUse(
        std::get<TokenTreeImpl::ChoiceNode *>(node)->children.front());

  } else if (std::holds_alternative<TokenTreeImpl::SequenceNode *>(node)) {
    if (auto seq = std::get<TokenTreeImpl::SequenceNode *>(node);
        seq && !seq->children.empty()) {
      return RightCornerOfUse(seq->children.back());
    }
  } else if (std::holds_alternative<TokenTreeImpl::SubstitutionNode *>(node)) {
    if (auto sub = std::get<TokenTreeImpl::SubstitutionNode *>(node)) {
      return RightCornerOfUse(sub->before);
    }
  }
  return std::nullopt;
}

// Counts the number of tokens after `begin` and before `end` that we can
// inject before the token which logically represents `end`.
static EntityOffset CountInjectable(const TokenReader::Ptr &reader,
                                    const TokenTreeImpl::Bounds &bounds,
                                    TokenTreeImpl::TokenIndex upper_bound,
                                    TokenTreeImpl::SequenceNode *seq,
                                    int depth) {
  EntityOffset begin = bounds.begin_index;
  EntityOffset end = upper_bound.second;
  EntityOffset count = 0u;

  // If we're at a file level, then allow us to suck in more tokens.
  if (!depth) {
    if (auto rc = RightCornerOfUse(seq)) {

      // Allow unbounded whitespace/comment injection, but nothing else.
      if (rc->first != upper_bound.first) {
        depth = 1;
        begin = 0;

      // If the previous thing is from the same reader, then allow injection
      // from it.
      } else if (rc->first == upper_bound.first) {
        begin = rc->second + 1u;
      }

      // TODO(pag): Have observed issues where `bounds` and `rc`s reader indices
      //            don't match. This is likely due to subtleties related to the
      //            how `bounds` is simplistically passed down.
    }

    // TODO(pag): We know that the reader index for files will always be zero,
    //            so should be check that here?
  }

  for (auto i = end - 1u; begin <= i; ++count, --i) {
    switch (reader->NthTokenKind(i)) {
      case TokenKind::WHITESPACE:
      case TokenKind::COMMENT:
      case TokenKind::UNKNOWN:
        if (!reader->NthTokenData(i).empty()) {
          D( std::cerr << "Injectable (depth=" << depth << "): "
                       << reader->NthTokenData(i) << '\n'; )
          continue;
        }
        [[clang::fallthrough]];
      default:
        if (depth) {
          D( std::cerr << "Not injectable (depth=" << depth << "): "
                       << reader->NthTokenData(i) << '\n'; )
          return count;
        } else {
          continue;
        }
    }
    if (!i) {
      break;
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
  for (auto num = CountInjectable(fti_reader, bounds, fti, seq, depth);
       num; --num) {
    seq = AddTokenToSequence(seq, TokenIndex(fti.first, fti.second - num));
  }

  return seq;
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithMacroChild(
    SequenceNode *seq, const MacroOrToken &mt, const Bounds &bounds,
    const TrailingTokens &trailing_tokens) {

  if (std::holds_alternative<Token>(mt)) {
    const Token &tok = std::get<Token>(mt);
    seq = AddLeadingTokensInBounds(seq, tok, bounds);
    return AddTokenToSequence(seq, tok, trailing_tokens);

  } else if (std::holds_alternative<Macro>(mt)) {
    return ExtendWithMacro(seq, std::get<Macro>(mt), bounds, trailing_tokens);

  } else {
    assert(false);
    return seq;
  }
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithMacroChildren(
    SequenceNode *seq, const Macro &macro, const Bounds &bounds,
    const TrailingTokens &trailing_toks) {

  FILL_MACRO_CHILREN(macro.children(), mts, fts)
  return ProcessMacroChildren(seq, bounds, std::move(mts), std::move(fts),
                              trailing_toks);
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithSimpleExpansion(
    SequenceNode *seq, const MacroExpansion &me,
    const DefineMacroDirective &me_def, const Bounds &user_bounds,
    const Bounds &def_bounds, const TrailingTokens &trailing_tokens) {

  MacroExpansionProcessor mep;
  mep.Init(me, me_def);
  if (!mep.Run(false)) {
    assert(false);  // Probably a bug.
    return ExtendWithSubstitution(seq, me, user_bounds, trailing_tokens);
  }

  SaveRestoreLastSequence seq_raii(last_sequence, seq);

  FILL_MACRO_CHILREN(me.children(), mts, fts)
  SequenceNode *before = ProcessMacroChildren(
      nullptr, user_bounds, std::move(mts), std::move(fts), trailing_tokens);

  if (!before) {
    assert(trailing_tokens.tokens.empty());
    return nullptr;
  }

  auto prev_depth = depth;
  auto next_depth = depth + 1;

  last_sequence = &dummy_sequence;
  SequenceNode *after = nullptr;
  for (const BodyTokenForChild &node : mep.ReplacementChildren()) {
    depth = next_depth;
    after = AddLeadingTokensInBounds(after, node.definition_token, def_bounds);
    if (node.is_argument) {
      after = ExtendWithMacroChild(after, node.mt, user_bounds,
                                   dummy_trailing_tokens);
    } else {
      after = ExtendWithMacroChild(after, node.mt, def_bounds,
                                   dummy_trailing_tokens);
    }
  }

  SubstitutionNode *sub = &(substitutions.emplace_back(me));
  sub->before = before;
  if (after) {
    sub->after = after;
  }

  depth = prev_depth;
  return AddToSequence(seq, sub, dummy_trailing_tokens);
}

// Process `mts`, a list of children of some kind. There is a one-to-one
// correspondence between `mts` and `fts`. `fts[i]` is the left corner of
// `mts[i]`. The purpose of `fts` is to help us find bounds for injecting
// stuff like whitespace.
TokenTreeImpl::SequenceNode *TokenTreeImpl::ProcessMacroChildren(
    TokenTreeImpl::SequenceNode *seq, const Bounds &bounds,
    std::vector<MacroOrToken> mts, std::vector<Token> fts,
    const TrailingTokens &trailing_tokens) {

  size_t num_mts = mts.size();

  for (auto i = 0u; i < num_mts; ++i) {
    const MacroOrToken &mt = mts[i];
    auto &tt = (i + 1u) == num_mts ? trailing_tokens : dummy_trailing_tokens;

    if (std::holds_alternative<Token>(mt)) {
      const Token &tok = std::get<Token>(mt);
      seq = AddLeadingTokensInBounds(seq, fts[i], bounds);
      seq = AddTokenToSequence(seq, tok, tt);
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
      seq = ExtendWithMacro(seq, m, bounds, tt);
      continue;
    }

    D( std::cerr << "LC token for tighter bounds is " << lc_ft.data() << '\n'; )

    TokenIndex lc_index = GetOrCreateIndex(lc_ft);
    Bounds new_bounds = bounds;
    if (new_bounds.reader_index != lc_index.first ||
        lc_index.second < bounds.begin_index ||
        lc_index.second > bounds.end_index) {

      D( std::cerr << " - Failed to tighten bounds\n"; )
      seq = ExtendWithMacro(seq, m, bounds, tt);
      continue;
    }

    assert(new_bounds.begin_index <= lc_index.second);
    new_bounds.begin_index = lc_index.second;

    // Try to look at the new thing we want to add in order to tighten the
    // upper bounds.
    if ((i + 1u) < num_mts) {
      const Token &rc_ft = fts[i + 1u];
      if (rc_ft) {
        TokenIndex rc_index = GetOrCreateIndex(rc_ft);
        if (new_bounds.reader_index == rc_index.first &&
            rc_index.second >= new_bounds.begin_index &&
            rc_index.second) {
          assert(new_bounds.begin_index <= rc_index.second);
          assert(rc_index.second <= new_bounds.end_index);
          new_bounds.end_index = rc_index.second - 1u;
        }
      }
    }

    seq = AddLeadingTokensInBounds(seq, lc_ft, bounds);
    seq = ExtendWithMacro(seq, m, new_bounds, tt);
  }

  if (!num_mts) {
    seq = AddTrailingTokensToSequence(seq, trailing_tokens);
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
    SequenceNode *seq, const MacroExpansion &me, const Bounds &me_bounds,
    const DefineMacroDirective &def, const Bounds &def_bounds,
    const MacroExpansion &dte, const TrailingTokens &prev_trailing_tokens) {

  D( std::cerr << "Non-tree " << def.name().data() << "\n"; )
  TrailingTokens trailing_tokens;
  trailing_tokens.depth = depth;  // Use this.
  trailing_tokens.bounds = me_bounds;
  trailing_tokens.next_trailing = &prev_trailing_tokens;

  for (Token te_tok : dte.generate_use_tokens()) {
    Token te_file_tok = te_tok.file_token();
    if (!te_file_tok) {
      trailing_tokens.tokens.clear();
      continue;
    }

    TokenIndex ti = GetOrCreateIndex(te_file_tok);
    if (ti.first != me_bounds.reader_index ||
        ti.second < me_bounds.begin_index ||
        ti.second > me_bounds.end_index) {
      trailing_tokens.tokens.clear();
      continue;
    }

    D( std::cerr << " - Trailing token: " << te_tok.data() << '\n'; )
    trailing_tokens.tokens.emplace_back(std::move(te_tok));
  }

  auto prev_depth = depth;
  auto next_depth = depth + 1;

  MacroExpansionProcessor mep;
  mep.Init(me, def);
  if (!mep.Run(true)) {
    assert(false);  // Probably not a bug, just something sketchy/odd.
    return ExtendWithSubstitution(seq, me, me_bounds, trailing_tokens);
  }

  SaveRestoreLastSequence seq_raii(last_sequence, seq);

  FILL_MACRO_CHILREN(me.children(), mts, fts)
  SequenceNode *before = ProcessMacroChildren(
      nullptr, me_bounds, std::move(mts), std::move(fts),
      trailing_tokens);

  assert(depth == prev_depth);

  if (!before) {
    return seq;
  }

  SequenceNode *after = nullptr;
  last_sequence = &dummy_sequence;
  for (const BodyTokenForChild &node : mep.ReplacementChildren()) {
    depth = next_depth;
    after = AddLeadingTokensInBounds(after, node.definition_token, def_bounds);
    if (node.is_argument) {
      after = ExtendWithMacroChild(after, node.mt, me_bounds,
                                   dummy_trailing_tokens);
    } else {
      after = ExtendWithMacroChild(after, node.mt, def_bounds,
                                   dummy_trailing_tokens);
    }
    depth = prev_depth;
  }

  SubstitutionNode *sub = &(substitutions.emplace_back(me));
  sub->before = before;
  if (after) {
    sub->after = after;
  }

  return AddToSequence(seq, sub, dummy_trailing_tokens);
}

// Extend with a macro expansion. The work here is in figuring out whether or
// not we're in a "non-tree" case.
TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithExpansion(
    SequenceNode *seq, const MacroExpansion &me,
    const Bounds &user_bounds, const TrailingTokens &trailing_tokens) {

  std::optional<Bounds> def_bounds;
  std::optional<DefineMacroDirective> def = me.definition();
  if (!def) {
    return ExtendWithSubstitution(seq, me, user_bounds, trailing_tokens);
  }

  def_bounds = MacroBodyBounds(def.value());
  if (!def_bounds) {
    return ExtendWithSubstitution(seq, me, user_bounds, trailing_tokens);
  }

  // If there isn't a trailing expansion, then that is fine.
  std::optional<MacroExpansion> te = TrailingExpansionInExpansion(me);
  if (!te) {
    return ExtendWithSimpleExpansion(seq, me, def.value(), user_bounds,
                                     def_bounds.value(), trailing_tokens);
  }

  auto dte = NonTreeTailExpansion(def.value(), me, te.value());
  if (!dte) {
    return ExtendWithSimpleExpansion(seq, me, def.value(), user_bounds,
                                     def_bounds.value(), trailing_tokens);
  }

  return ExtendWithNonTreeExpansion(
      seq, me, user_bounds, def.value(), def_bounds.value(), dte.value(),
      trailing_tokens);
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithSubstitution(
    SequenceNode *seq, const MacroSubstitution &macro,
    const Bounds &use_bounds, const TrailingTokens &trailing_tokens) {

  auto prev_depth = depth;
  auto next_depth = depth + 1;

  SaveRestoreLastSequence seq_raii(last_sequence, seq);

  FILL_MACRO_CHILREN(macro.children(), mts, fts)
  SequenceNode *before = ProcessMacroChildren(
      nullptr, use_bounds, std::move(mts), std::move(fts), trailing_tokens);

  if (!before) {
    return seq;
  }

  SubstitutionNode *sub = &(substitutions.emplace_back(macro));
  sub->before = before;

  SequenceNode *after = nullptr;
  last_sequence = &dummy_sequence;
  for (MacroOrToken mt : macro.replacement_children()) {
    depth = next_depth;
    after = ExtendWithMacroChild(after, mt, use_bounds, dummy_trailing_tokens);
    depth = prev_depth;
  }

  if (after) {
    sub->after = after;
  }

  return AddToSequence(seq, sub, dummy_trailing_tokens);
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithMacro(
    SequenceNode *seq, const Macro &macro, const Bounds &bounds,
    const TrailingTokens &trailing_tokens) {

  if (auto ms = MacroSubstitution::from(macro)) {
    if (auto me = MacroExpansion::from(macro)) {
      seq = ExtendWithExpansion(seq, me.value(), bounds, trailing_tokens);
    } else {
      seq = ExtendWithSubstitution(seq, ms.value(), bounds, trailing_tokens);
    }

  } else {
    seq = ExtendWithMacroChildren(seq, macro, bounds, trailing_tokens);
  }

  return seq;
}

// Create a node for a fragment. If the fragment has file tokens, then the
// returned node will "expand" out to include the file tokens.
TokenTreeImpl::Node TokenTreeImpl::CreateFragmentNode(
    const Fragment &entity, const Bounds &bounds) {

  FILL_MACRO_CHILREN(entity.preprocessed_code(), mts, fts)
  SequenceNode *seq = ProcessMacroChildren(
      nullptr, bounds, std::move(mts), std::move(fts),
      dummy_trailing_tokens);

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

    RawEntityId first_file_tok_id = file_toks.front().id().Pack();
    RawEntityId last_file_tok_id = file_toks.back().id().Pack();

#ifndef NDEBUG
    VariantId first_file_tok_vid = EntityId(first_file_tok_id).Unpack();
    VariantId last_file_tok_vid = EntityId(last_file_tok_id).Unpack();
    assert(std::holds_alternative<FileTokenId>(first_file_tok_vid));
    assert(std::holds_alternative<FileTokenId>(last_file_tok_vid));
    assert(std::get<FileTokenId>(first_file_tok_vid).file_id ==
           std::get<FileTokenId>(last_file_tok_vid).file_id);
    assert(std::get<FileTokenId>(first_file_tok_vid).offset <=
           std::get<FileTokenId>(last_file_tok_vid).offset);
#endif

    Bounds frag_bounds = FragmentBounds(file_toks);

    depth = 0;
    Node frag_node = CreateFragmentNode(frag, frag_bounds);
    assert(!depth);

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
      assert(!file_frags.count(file_tok_id));
      if (stop_skip_after.value() == file_tok_id) {
        stop_skip_after.reset();
      }
      continue;
    }

    if (auto frag_it = file_frags.find(file_tok_id);
        frag_it != file_frags.end()) {

      ChoiceNode *frag_node = frag_it->second;
      assert(frag_node != nullptr);

      RawEntityId end_file_tok_id = frag_end[file_tok_id];
      if (end_file_tok_id != file_tok_id) {
        stop_skip_after.emplace(end_file_tok_id);
      }
      seq = AddToSequence(seq, frag_node, dummy_trailing_tokens);

      file_frags.erase(file_tok_id);

    } else {
      seq = AddTokenToSequence(seq, file_tok, dummy_trailing_tokens);
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
  self->file = file.impl;
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

  // Capture the sequence of choices made by a token tree visitor.
  std::vector<RawEntityId> visitor_choices;

  virtual ~TokenTreeReader(void) noexcept = default;

  inline TokenTreeReader(std::shared_ptr<TokenTreeImpl> impl_)
      : impl(std::move(impl_)) {}

  const FragmentImpl *OwningFragment(void) const noexcept override {
    return impl->fragment.get();
  }

  const FileImpl *OwningFile(void) const noexcept override {
    return impl->file.get();
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
    if (data_hash != that->data_hash ||
        tokens.size() != that->tokens.size()) {
      return false;
    }

    if (impl != that->impl) {

      // Not configured to look at the same high-level entities.
      if (impl->file != that->impl->file ||
          impl->fragment != that->impl->fragment ||
          impl->readers.size() != that->impl->readers.size()) {
        return false;
      }
    }

    // Compare the choices made by the two visitors.
    return tokens.size() == that->tokens.size() &&
           visitor_choices == that->visitor_choices;
  }
};

static void CollectTokens(const TokenTreeImpl::Node &node,
                          const TokenTreeVisitor &vis,
                          std::vector<RawEntityId> &choices,
                          std::vector<TokenTreeImpl::TokenIndex> &tokens) {
  if (std::holds_alternative<std::monostate>(node)) {
    return;

  } else if (std::holds_alternative<TokenTreeImpl::TokenIndex>(node)) {
    tokens.push_back(std::get<TokenTreeImpl::TokenIndex>(node));

  } else if (std::holds_alternative<TokenTreeImpl::ChoiceNode *>(node)) {
    if (TokenTreeImpl::ChoiceNode *choice =
            std::get<TokenTreeImpl::ChoiceNode *>(node)) {
      PackedFragmentId chosen_frag = vis.choose(choice->fragments).id();
      choices.emplace_back(chosen_frag.Pack());

      auto i = 0u;
      for (const Fragment &frag : choice->fragments) {
        if (chosen_frag == frag.id()) {
          const TokenTreeImpl::Node &frag_node = choice->children[i];
          CollectTokens(frag_node, vis, choices, tokens);
        }
        ++i;
      }
    }
  } else if (std::holds_alternative<TokenTreeImpl::SubstitutionNode *>(node)) {
    if (TokenTreeImpl::SubstitutionNode *sub =
            std::get<TokenTreeImpl::SubstitutionNode *>(node)) {
      auto should_expand = false;
      RawEntityId choice_id = kInvalidEntityId;
      if (std::holds_alternative<MacroSubstitution>(sub->macro)) {
        const MacroSubstitution &msub = std::get<MacroSubstitution>(sub->macro);
        should_expand = vis.should_expand(msub);
        choice_id = msub.id().Pack();
      } else {
        assert(false);
      }

      if (should_expand) {
        choices.emplace_back(choice_id);
      }
      if (should_expand) {
        CollectTokens(sub->after, vis, choices, tokens);
      } else {
        CollectTokens(sub->before, vis, choices, tokens);
      }
    }
  } else if (std::holds_alternative<TokenTreeImpl::SequenceNode *>(node)) {
    if (TokenTreeImpl::SequenceNode *seq =
            std::get<TokenTreeImpl::SequenceNode *>(node)) {
      for (const TokenTreeImpl::Node &sub_node : seq->children) {
        CollectTokens(sub_node, vis, choices, tokens);
      }
    }
  } else {
    assert(false);
  }
}

static void StreamTokData(std::ostream &os, std::string_view tok) {
  for (auto ch : tok) {
    switch (ch) {
      case '<': os << "&lt;"; break;
      case '>': os << "&gt;"; break;
      case '"': os << "&quot;"; break;
      case '\'': os << "&apos;"; break;
      case '\r': os << " "; break;
      case '\n': os << " "; break;
      case '&': os << "&amp;"; break;
      case '\\': os << '|'; break;
      default: os << ch; break;
    }
  }
}

}  // namespace

// Try to get the token tree containing a token range.
std::optional<TokenTree> TokenTree::from(const TokenRange &range) {
  if (auto reader = range.impl.get()) {
    if (auto ttr = dynamic_cast<const TokenTreeReader *>(reader)) {
      return TokenTree(ttr->impl);
    }
  }

  return std::nullopt;
}

// Serialize the token tree into a linear range.
TokenRange TokenTree::serialize(const TokenTreeVisitor &vis) const {
  auto reader = std::make_shared<TokenTreeReader>(impl);
  CollectTokens(impl->root, vis, reader->visitor_choices, reader->tokens);
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

// Dump the token tree into a DOT digraph.
void TokenTree::dump(std::ostream &os) {
  os
      << "digraph {\n"
      << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";

  auto add_link = [] (auto &ss, auto s_id, auto i, auto &node) {
    if (std::holds_alternative<std::monostate>(node)) {
      return;

    } else if (std::holds_alternative<TokenTreeImpl::TokenIndex>(node)) {
      return;

    } else if (std::holds_alternative<TokenTreeImpl::ChoiceNode *>(node)) {
      if (TokenTreeImpl::ChoiceNode *choice =
              std::get<TokenTreeImpl::ChoiceNode *>(node)) {
        auto d_id = reinterpret_cast<uintptr_t>(choice);
        ss << "n" << s_id << ":c" << i << " -> n" << d_id << ";\n";
      }
    } else if (std::holds_alternative<TokenTreeImpl::SubstitutionNode *>(node)) {
      if (TokenTreeImpl::SubstitutionNode *sub =
              std::get<TokenTreeImpl::SubstitutionNode *>(node)) {
        auto d_id = reinterpret_cast<uintptr_t>(sub);
        ss << "n" << s_id << ":c" << i << " -> n" << d_id << ";\n";
      }
    } else if (std::holds_alternative<TokenTreeImpl::SequenceNode *>(node)) {
      if (TokenTreeImpl::SequenceNode *seq =
              std::get<TokenTreeImpl::SequenceNode *>(node)) {
        auto d_id = reinterpret_cast<uintptr_t>(seq);
        ss << "n" << s_id << ":c" << i << " -> n" << d_id << ";\n";
      }
    } else {
      assert(false);
    }
  };

  for (const TokenTreeImpl::SequenceNode &node : impl->sequences) {
    auto id = reinterpret_cast<uintptr_t>(&node);
    os << "n" << id
       << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\" bgcolor=\"goldenrod\"><TR>";

    auto i = 0u;
    for (const TokenTreeImpl::Node &child : node.children) {
      if (std::holds_alternative<TokenTreeImpl::TokenIndex>(child)) {
        auto [ri, to] = std::get<TokenTreeImpl::TokenIndex>(child);
        os << "<TD>";
        StreamTokData(os, impl->readers[ri]->NthTokenData(to));
        os << "</TD>";
      } else {
        os << "<TD port=\"c" << i << "\"> </TD>";
        ++i;
      }
    }
    os << "</TR></TABLE>>];\n";

    i = 0u;
    for (const TokenTreeImpl::Node &child : node.children) {
      if (!std::holds_alternative<TokenTreeImpl::TokenIndex>(child)) {
        add_link(os, id, i++, child);
      }
    }
  }

  for (const TokenTreeImpl::ChoiceNode &node : impl->choices) {
    auto id = reinterpret_cast<uintptr_t>(&node);
    os << "n" << id
       << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\" bgcolor=\"azure2\"><TR>";

    auto i = 0u;
    for (const TokenTreeImpl::Node &child : node.children) {
      (void) child;
      os << "<TD port=\"c" << i << "\">" << node.fragments[i].id().Pack() << "</TD>";
      ++i;
    }
    os << "</TR></TABLE>>];\n";

    i = 0u;
    for (const TokenTreeImpl::Node &child : node.children) {
      add_link(os, id, i++, child);
    }
  }

  for (const TokenTreeImpl::SubstitutionNode &node : impl->substitutions) {
    auto id = reinterpret_cast<uintptr_t>(&node);
    EntityId eid;
    if (std::holds_alternative<MacroSubstitution>(node.macro)) {
      eid = std::get<MacroSubstitution>(node.macro).id();
    } else if (std::holds_alternative<MacroVAOpt>(node.macro)) {
      eid = std::get<MacroVAOpt>(node.macro).id();
    } else {
      assert(false);
    }

    os << "n" << id
       << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\" bgcolor=\"beige\"><TR>"
       << "<TD colspan=\"2\">" << eid.Pack() << "</TD></TR><TR>"
       << "<TD port=\"c0\">before</TD>"
       << "<TD port=\"c1\">after</TD>"
       << "</TR></TABLE>>];\n";

    add_link(os, id, 0, node.before);
    add_link(os, id, 1, node.after);
  }

  os << "}\n";
}

}  // namespace mx
