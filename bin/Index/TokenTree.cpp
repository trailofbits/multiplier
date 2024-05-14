// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "TokenTree.h"

#include <cassert>
#include <deque>
#include <glog/logging.h>
#include <map>
#include <multiplier/Frontend/MacroKind.h>
#include <multiplier/Types.h>
#include <mutex>
#include <optional>
#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Forward.h>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Token.h>
#include <pasta/Util/File.h>
#include <sstream>
#include <unordered_map>
#include <vector>

#include <iostream>

#include "EntityMapper.h"
#include "PASTA.h"

// #define D(...) __VA_ARGS__
#ifndef D
# define D(...)
#endif

#define TT_STR_(x) #x
#define TT_STR(x) TT_STR_(x)
#define TT_ASSERT(cond) \
  if (!(cond)) { \
    assert(false); \
    throw "Failed assertion " #cond " at " __FILE__ ":" TT_STR(__LINE__) ; \
  }

namespace indexer {
namespace {

static std::mutex gPrintDOTLock;

}  // namespace

struct TokenInfo {
  std::optional<pasta::Token> parsed_tok;
  std::optional<pasta::PrintedToken> printed_tok;
  std::optional<pasta::MacroToken> macro_tok;
  Substitution *parent{nullptr};
  TokenInfo *next{nullptr};
};

using SubstitutionNode = std::variant<TokenInfo *, Substitution *>;

class SubstitutionNodeList : public std::vector<SubstitutionNode> {
 public:
  // Did we have some kind of error when processing this list of nodes?
  mutable bool has_error{false};
};

// Represents a token substitution. This can be due to a macro expansion, or
// due to an X-macro file inclusion (i.e. where an include is nested inside
// of a declaration, and then the included file expands macros).
class Substitution {
 public:

  using Node = SubstitutionNode;
  using NodeList = SubstitutionNodeList;

  mx::MacroKind kind;

  // This substitution represents a nested fragment.
  std::optional<mx::PackedFragmentId> fragment_id;

  // Number of tokens in this nested fragment.
  unsigned num_parsed_tokens{0u};

  // Offset into the parsed tokens where this nested fragment appears.
  unsigned parsed_token_offset{0u};

  // Associated macro node. If this is non-`nullopt` then the `EntityMapper`
  // uses `macro.RawMacro()` for the entity ID of the token tree.
  std::optional<pasta::Macro> macro;

  // Child nodes, prior to any kind of expansion or substitution.
  NodeList before;

  // Body of the macro.
  NodeList body;

  // Child node, after expansion or substitution. `HasExpansion()` tells us
  // if we should look in here.
  NodeList after;

  Substitution *parent{nullptr};

  bool HasExpansion(void) const noexcept;

  // Is this node dead?
  bool is_dead{false};

  explicit Substitution(mx::MacroKind kind_)
      : kind(kind_) {}

  void Print(std::ostream &os) const;
  void PrintDOT(std::ostream &os, bool first=true) const;
};

class TokenTreeImpl {
 public:
  bool has_error{false};

  // Backing storage for token info. Not necessarily all allocated tokens will
  // be used, but this is an upper bound on them. `deque` for pointer stability.
  std::deque<TokenInfo> tokens_alloc;

  // Backing storage for substitutions.
  std::deque<Substitution> substitutions_alloc;

  // Macro bodies.
  std::unordered_map<const void *, Substitution *> macro_body;

  // Macro tokens that are also final parsed tokens.
  std::unordered_map<const void *, TokenInfo *> final_toks;

  D( std::string indent; )

  // Collect a mapping of substitutions containing parsed tokens, along with
  // those parsed tokens in the order that we see them.
  void FindParsedTokens(
      Substitution *sub,
      std::unordered_map<Substitution *, std::vector<TokenInfo *>> &sub_tokens);

  // Figure out if `node->after` looks like a macro argument pre-expansion of
  // `node`, and if so, return `node->after.before.front()`, i.e. the pre-
  // expansion use.
  Substitution *PreExpansionOf(Substitution *node);

  Substitution *CreateDirectiveFragment(
      const PendingFragment &pf, const pasta::Macro &macro);

  // Build an initial token info list. This contains all of the tokens that were
  // parsed, plus the file tokens that were macro uses. This does not contain
  // file tokens that were elided due to things like conditional macros, e.g.
  // `#if 0`.
  Substitution *BuildFromTokenList(
      const PendingFragment &pf, std::ostream &err);

  Substitution *BuildFromParsedTokenList(
      const PendingFragment &pf, std::ostream &err);

  bool BuildFromMacro(
      const PendingFragment &pf, Substitution *sub,
      Substitution::NodeList &nodes, pasta::Macro macro, std::ostream &err);

  Substitution *GetMacroBody(pasta::DefineMacroDirective def,
                             std::ostream &err);

  Substitution *MergeArguments(Substitution *orig, Substitution *pre_arg,
                               std::ostream &err);

  bool MergeArgPreExpansion(Substitution *sub, Substitution *pre_exp,
                            std::ostream &err);

  bool BuildMacroSubstitution(
      Substitution *sub, Substitution::NodeList &nodes,
      const pasta::MacroToken &node, std::ostream &err);

  bool BuildMacroSubstitution(
      const PendingFragment &pf, Substitution *sub,
      Substitution::NodeList &nodes, const pasta::MacroArgument &node,
      std::ostream &err);

  bool BuildMacroSubstitution(
      const PendingFragment &pf, Substitution *sub,
      Substitution::NodeList &nodes, const pasta::MacroVAOpt &node,
      std::ostream &err);

  bool BuildMacroSubstitution(
      const PendingFragment &pf, Substitution *sub,
      Substitution::NodeList &nodes, const pasta::MacroVAOptArgument &node,
      std::ostream &err);

  bool BuildMacroSubstitution(
      const PendingFragment &pf, Substitution *sub,
      Substitution::NodeList &nodes, const pasta::MacroParameter &node,
      std::ostream &err);

  bool BuildMacroSubstitution(
      const PendingFragment &pf, Substitution *sub,
      Substitution::NodeList &nodes, const pasta::MacroSubstitution &node,
      std::ostream &err);

  bool BuildMacroSubstitution(
      const PendingFragment &pf, Substitution *sub,
      Substitution::NodeList &nodes, const pasta::MacroExpansion &node,
      std::ostream &err);

  bool BuildMacroSubstitution(
      const PendingFragment &pf, Substitution *sub,
      Substitution::NodeList &nodes, const pasta::MacroDirective &node,
      std::ostream &err);

  Substitution *CreateSubstitution(mx::MacroKind kind);
};

namespace {

[[gnu::noinline]]
static std::ostream &Error(void) {
  return std::cerr;
}

static void Die(const TokenTreeImpl *impl) {
  std::unique_lock<std::mutex> locker(gPrintDOTLock);
  Error().flush();
  auto &sub = impl->substitutions_alloc.front();
  Error() << "--------------------------------------------------------\n";
  Error() << "--------------------------------------------------------\n";
  for (const TokenInfo &tok : impl->tokens_alloc) {
    if (tok.parsed_tok) {
      const pasta::Token &ast_tok = tok.parsed_tok.value();
      pasta::AST ast = pasta::AST::From(ast_tok);
      Error() << ast.MainFile().Path().generic_string() << "\n\n";
      break;
    }
  }
  sub.Print(std::cerr);
  Error() << "\n\n";
  sub.PrintDOT(std::cerr);
  Error() << "\n\n";
  Error().flush();
  TT_ASSERT(false);
}

static pasta::TokenKind TokKind(const pasta::MacroToken &mt) {
  return mt.TokenKind();
}

template <typename T>
static pasta::TokenKind TokKind(const T &mt) {
  return mt.Kind();
}

template <typename T>
static std::string TokData(const T &tok) {
  switch (TokKind(tok)) {
    case pasta::TokenKind::kComment:
      return "/* */";
    case pasta::TokenKind::kUnknown:
      return " ";
    case pasta::TokenKind::kCharacterConstant:
    case pasta::TokenKind::kUtf8CharacterConstant:
    case pasta::TokenKind::kUtf16CharacterConstant:
    case pasta::TokenKind::kUtf32CharacterConstant:
    case pasta::TokenKind::kWideCharacterConstant:
    case pasta::TokenKind::kStringLiteral:
    case pasta::TokenKind::kUtf8StringLiteral:
    case pasta::TokenKind::kUtf16StringLiteral:
    case pasta::TokenKind::kUtf32StringLiteral:
    case pasta::TokenKind::kWideStringLiteral:
      return "&lt;str&gt;";
    default:
      break;
  }

  std::stringstream ss;
  for (auto ch : tok.Data()) {
    switch (ch) {
      case '<': ss << "&lt;"; break;
      case '>': ss << "&gt;"; break;
      case '"': ss << "&quot;"; break;
      case '\'': ss << "&apos;"; break;
      case '\n': ss << " "; break;
      case '&': ss << "&amp;"; break;
      case '\\': ss << '|'; break;
      default: ss << ch; break;
    }
  }
  return ss.str();
}

static void FixupNodeParents(Substitution *sub) {
  assert(!sub->parent || sub != sub->parent);

  for (Substitution::Node &node : sub->before) {
    if (std::holds_alternative<Substitution *>(node)) {
      Substitution *child_sub = std::get<Substitution *>(node);
      assert(child_sub != sub);
      child_sub->parent = sub;
    } else if (std::holds_alternative<TokenInfo *>(node)) {
      std::get<TokenInfo *>(node)->parent = sub;
    }
  }

  for (Substitution::Node &node : sub->body) {
    if (std::holds_alternative<Substitution *>(node)) {
      Substitution *child_sub = std::get<Substitution *>(node);
      assert(child_sub != sub);
      child_sub->parent = sub;
    } else if (std::holds_alternative<TokenInfo *>(node)) {
      std::get<TokenInfo *>(node)->parent = sub;
    }
  }

  for (Substitution::Node &node : sub->after) {
    if (std::holds_alternative<Substitution *>(node)) {
      Substitution *child_sub = std::get<Substitution *>(node);
      assert(child_sub != sub);
      child_sub->parent = sub;
    } else if (std::holds_alternative<TokenInfo *>(node)) {
      std::get<TokenInfo *>(node)->parent = sub;
    }
  }
}

static TokenInfo *LeftCornerOfExp(const Substitution::NodeList &nodes);
static TokenInfo *LeftCornerOfExp(const Substitution::Node &node) {
  if (std::holds_alternative<TokenInfo *>(node)) {
    return std::get<TokenInfo *>(node);
  } else if (auto sub = std::get<Substitution *>(node)) {
    return LeftCornerOfExp(sub->after);
  }
  return nullptr;
}

TokenInfo *LeftCornerOfExp(const Substitution::NodeList &nodes) {
  for (const Substitution::Node &node : nodes) {
    if (auto tok = LeftCornerOfExp(node)) {
      return tok;
    }
  }
  return nullptr;
}

static TokenInfo *RightCornerOfExp(const Substitution::NodeList &nodes);
static TokenInfo *RightCornerOfExp(const Substitution::Node &node) {
  if (std::holds_alternative<TokenInfo *>(node)) {
    return std::get<TokenInfo *>(node);
  } else if (auto sub = std::get<Substitution *>(node)) {
    return RightCornerOfExp(sub->after);
  }
  return nullptr;
}

TokenInfo *RightCornerOfExp(const Substitution::NodeList &nodes) {
  auto it = nodes.rbegin();
  auto end = nodes.rend();
  for (; it != end; ++it) {
    const Substitution::Node &node = *it;
    if (auto rc = RightCornerOfExp(node)) {
      return rc;
    }
  }
  return nullptr;
}

static TokenInfo *LeftCornerOfUse(const Substitution::NodeList &nodes);
static TokenInfo *LeftCornerOfUse(const Substitution::Node &node) {
  if (std::holds_alternative<TokenInfo *>(node)) {
    return std::get<TokenInfo *>(node);
  } else if (auto sub = std::get<Substitution *>(node)) {
    return LeftCornerOfUse(sub->before);
  }
  return nullptr;
}

TokenInfo *LeftCornerOfUse(const Substitution::NodeList &nodes) {
  for (const Substitution::Node &node : nodes) {
    if (auto tok = LeftCornerOfUse(node)) {
      return tok;
    }
  }
  return nullptr;
}

static TokenInfo *RightCornerOfUse(const Substitution::NodeList &nodes);
static TokenInfo *RightCornerOfUse(const Substitution::Node &node) {
  if (std::holds_alternative<TokenInfo *>(node)) {
    return std::get<TokenInfo *>(node);
  } else if (auto sub = std::get<Substitution *>(node)) {
    return RightCornerOfUse(sub->before);
  }
  return nullptr;
}

TokenInfo *RightCornerOfUse(const Substitution::NodeList &nodes) {
  auto it = nodes.rbegin();
  auto end = nodes.rend();
  for (; it != end; ++it) {
    if (auto rc = RightCornerOfUse(*it)) {
      return rc;
    }
  }
  return nullptr;
}

static TokenInfo *RightCornerOfExpansionOrUse(
    const Substitution::NodeList &nodes);

static TokenInfo *RightCornerOfExpansionOrUse(const Substitution::Node &node) {
  if (std::holds_alternative<TokenInfo *>(node)) {
    return std::get<TokenInfo *>(node);
  } else if (auto sub = std::get<Substitution *>(node)) {
    if (sub->HasExpansion()) {
      return RightCornerOfExpansionOrUse(sub->after);
    } else {
      return RightCornerOfExpansionOrUse(sub->before);
    }
  }
  return nullptr;
}

static TokenInfo *RightCornerOfExpansionOrUse(const Substitution::NodeList &nodes) {
  auto it = nodes.rbegin();
  auto end = nodes.rend();
  for (; it != end; ++it) {
    if (auto rc = RightCornerOfExpansionOrUse(*it)) {
      return rc;
    }
  }
  return nullptr;
}

static Substitution *MacroArgument(const Substitution::Node &node) {
  if (std::holds_alternative<Substitution *>(node)) {
    auto sub = std::get<Substitution *>(node);
    if (sub->kind == mx::MacroKind::ARGUMENT) {
      return sub;
    }
  }
  return nullptr;
}

#ifndef NDEBUG
static Substitution *MacroDirective(const Substitution::Node &node) {
  if (std::holds_alternative<Substitution *>(node)) {
    auto sub = std::get<Substitution *>(node);
    switch (sub->kind) {
      case mx::MacroKind::OTHER_DIRECTIVE:
      case mx::MacroKind::IF_DIRECTIVE:
      case mx::MacroKind::IF_DEFINED_DIRECTIVE:
      case mx::MacroKind::IF_NOT_DEFINED_DIRECTIVE:
      case mx::MacroKind::ELSE_IF_DIRECTIVE:
      case mx::MacroKind::ELSE_IF_DEFINED_DIRECTIVE:
      case mx::MacroKind::ELSE_IF_NOT_DEFINED_DIRECTIVE:
      case mx::MacroKind::ELSE_DIRECTIVE:
      case mx::MacroKind::END_IF_DIRECTIVE:
      case mx::MacroKind::DEFINE_DIRECTIVE:
      case mx::MacroKind::UNDEFINE_DIRECTIVE:
      case mx::MacroKind::PRAGMA_DIRECTIVE:
      case mx::MacroKind::INCLUDE_DIRECTIVE:
      case mx::MacroKind::INCLUDE_NEXT_DIRECTIVE:
      case mx::MacroKind::INCLUDE_MACROS_DIRECTIVE:
      case mx::MacroKind::IMPORT_DIRECTIVE:
        return sub;
      default:
        break;
    }
  }
  return nullptr;
}
#endif

static pasta::Macro RootNodeFrom(const pasta::Macro &node) {
  if (auto parent = node.Parent()) {
    return RootNodeFrom(parent.value());
  } else {
    return node;
  }
}

static bool HasAnyMacroTokens(const pasta::TokenRange &range) {
  for (pasta::Token tok : range) {
    switch (tok.Role()) {
      case pasta::TokenRole::kBeginOfMacroExpansionMarker:
      case pasta::TokenRole::kEndOfMacroExpansionMarker:
      case pasta::TokenRole::kMacroDirectiveMarker:
      case pasta::TokenRole::kIntermediateMacroExpansionToken:
      case pasta::TokenRole::kInitialMacroUseToken:
      case pasta::TokenRole::kFinalMacroExpansionToken:
        return true;
      default:
        break;
    }
  }
  return false;
}

struct Rebuilder final {
  const PendingFragment &pf;
  const FragmentIdMap &token_to_nested_fragment;
  const bool has_nested_fragments;

  std::map<unsigned, std::vector<TokenInfo *>> parsed_tokens;
  std::vector<int> depth;
  std::deque<Substitution> new_subs_alloc;
  std::deque<TokenInfo> new_tokens_alloc;

  inline Rebuilder(const PendingFragment &pf_)
      : pf(pf_),
        token_to_nested_fragment(pf.token_to_nested_fragment),
        has_nested_fragments(!token_to_nested_fragment.empty()) {}

  Substitution *CreateFragmentNode(mx::PackedFragmentId fid) {
    auto &sub = new_subs_alloc.emplace_back(mx::MacroKind::OTHER_DIRECTIVE);
    sub.fragment_id = fid;
    return &sub;
  }

  TokenInfo *LastInRange(TokenInfo *curr, unsigned lb, unsigned ub,
                         int min_depth, bool &covers_pt);

  // void CollectOriginalLeftCorners(const std::deque<Substitution> &subs_alloc);
  void AllocateTokens(const pasta::PrintedTokenRange &range);
  void BuildBottomUp(std::deque<Substitution> &subs_alloc);
  // void BuildTopDown(Substitution *node);

  void AddTokensToSub(Substitution *new_sub, Substitution::NodeList &nodes,
                      TokenInfo *first, unsigned max_index);

  void ReplicateSurfaceUsesInto(
      Substitution &new_sub, const pasta::Macro &macro);
};

TokenInfo *Rebuilder::LastInRange(
    TokenInfo *curr, unsigned lb, unsigned ub, int min_depth, bool &covers_pt) {

  TokenInfo *prev = nullptr;
  for (; curr; curr = curr->next) {

    // std::cerr << '\t' << curr->printed_tok->Index() << " " << curr->printed_tok->Data() << '\n';
    assert(curr->printed_tok.has_value());

    Substitution *last_parent = nullptr;
    for (auto parent = curr->parent; parent; parent = parent->parent) {
      last_parent = parent;
      covers_pt = true;
    }

    // If this token is already nested inside of something, then jump us to the
    // other end of that thing.
    if (last_parent) {
      curr = RightCornerOfExp(last_parent);
      if (!curr) {
        // std::cerr << "\t\ti)no rc of last_parent, prev=" << (!!prev) << '\n';
        return prev;
      }

      // std::cerr << "\t\t" << curr->printed_tok->Index() << " " << curr->printed_tok->Data() << '\n';
    }

    // We use depth as a heuristic to figure out when we've probably gone too
    // far. This heuristic is based on the idea that most macro uses are
    // probably going to be sane, and as a result, properly nested inside or
    // in-between things.
    if (depth[curr->printed_tok->Index()] < min_depth) {
      // std::cerr << "\t\tii)depth=" << depth[curr->printed_tok->Index()] << " min_depth=" << min_depth << '\n';
      return prev;
    }

    if (curr->parsed_tok.has_value()) {
      auto pti = curr->parsed_tok->Index();
      if (pti < lb || pti > ub) {
        // std::cerr << "\t\tiii) pti=" << pti << " lb=" << lb << " ub=" << ub << '\n';
        return prev;
      }

      // Tell a higher level that we've covered a parsed token. This is a
      // heuristic to tell us whether or not to bother making a macro
      // substitution.
      covers_pt = true;
    }

    // Accept this token into our new substitution, but try not to include
    // trailing whitespace or commas, unless they are contained inside of
    // macro expansions.
    switch (curr->printed_tok->Kind()) {
      case pasta::TokenKind::kUnknown:
      case pasta::TokenKind::kComment:
        if (!curr->parsed_tok || !curr->parsed_tok->MacroLocation()) {
          continue;
        }

        [[fallthrough]];
      default:
        prev = curr;
        break;
    }
  }

  return prev;
}

// Make new token infos for the printed tokens.
void Rebuilder::AllocateTokens(const pasta::PrintedTokenRange &range) {
  TokenInfo *first = nullptr;
  TokenInfo **prev = &first;

  int d = 10;
  auto found_nested = false;

  std::unordered_map<mx::RawEntityId, Substitution *> nested_frags;

  auto i = 0u;
  auto num_parsed_tokens = 0u;
  auto token_to_nested_fragment_end = token_to_nested_fragment.end();

  pasta::TokenKind prev_tk = pasta::TokenKind::kUnknown;
  for (pasta::PrintedToken tok : range) {

    auto &info = new_tokens_alloc.emplace_back();
    auto tk = tok.Kind();
    info.parsed_tok = tok.DerivedLocation();
    info.printed_tok = std::move(tok);

    assert(info.printed_tok->Index() == i++);

    auto raw_tok = RawEntity(tok);
    auto frag_id_it = token_to_nested_fragment.find(raw_tok);

    // Try to find a printed token that is a macro directive marker, and then
    // invent a nested fragment for it (if it is part of a different fragment).
    if (info.parsed_tok.has_value()) {
      info.macro_tok = info.parsed_tok->MacroLocation();
      parsed_tokens[info.parsed_tok->Index()].push_back(&info);

      if (frag_id_it == token_to_nested_fragment_end &&
          info.parsed_tok->Role() == pasta::TokenRole::kMacroDirectiveMarker) {
        continue;
      }
    }

    assert(info.parsed_tok.has_value() ||
           info.printed_tok.has_value() ||
           info.macro_tok.has_value());

    *prev = &info;
    prev = &(info.next);

    // Encode token depth in a way that puts a kind of natural limit on how
    // far we can go with macros even when we don't have parsed tokens. We
    // make depths in the following way:
    //
    //      void      10
    //      foo       10
    //      (         11
    //      int       13
    //      x         13
    //      ,         12
    //      ...       13
    //      )         11
    //      noexcept  10
    //      ;         9
    //
    // The idea with this scheme is that we expect macros to be generally well
    // behaved and nested, and so if there's a macro inside the parameter list
    // then this scheme will help us to prevent it from crossing parameters.
    switch (tk) {
      case pasta::TokenKind::kLBrace:
      case pasta::TokenKind::kLSquare:
      case pasta::TokenKind::kLParenthesis:
      case pasta::TokenKind::kLAngle:
        depth.push_back(++d);
        d += 2;
        break;
      case pasta::TokenKind::kRBrace:
      case pasta::TokenKind::kRSquare:
      case pasta::TokenKind::kRParenthesis:
      case pasta::TokenKind::kRAngle:
        d -= 2;
        depth.push_back(d--);
        break;

      // Try to distinguish the case of a statement-ending semicolon from a
      // class-ending semicolon.
      case pasta::TokenKind::kSemi:
        if (prev_tk == pasta::TokenKind::kRBrace) {
          depth.push_back(d);
          break;
        }
        [[fallthrough]];
      case pasta::TokenKind::kComma:
      case pasta::TokenKind::kColon:
        depth.push_back(d - 1);
        break;
      default:
        depth.push_back(d);
        break;
    }

    if (tk != pasta::TokenKind::kUnknown && tk != pasta::TokenKind::kComment) {
      prev_tk = tk;
    }

    if (!has_nested_fragments) {
      ++num_parsed_tokens;
      continue;
    }

    // Figure out if the token should belong to a sub fragment.
    if (frag_id_it == token_to_nested_fragment_end) {
      continue;
    }

    // Half add it into the fragment substitution. We don't need to attach
    // this token into any node list, because we never want them shown anywhere.
    const mx::PackedFragmentId frag_id = frag_id_it->second;
    auto &nested_frag_sub = nested_frags[frag_id.Pack()];
    if (!nested_frag_sub) {
      nested_frag_sub = CreateFragmentNode(frag_id);
    }

    // Keep track of the sub fragment tokens (for now), so that we can get
    // accurate left/right corners. Later we will clear them out.
    info.parent = nested_frag_sub;
    info.parent->after.emplace_back(&info);
    info.parent->num_parsed_tokens++;
    info.parent->parsed_token_offset = num_parsed_tokens;
    found_nested = true;
  }

  if (!found_nested) {
    return;
  }

  // If we have nested fragments, then place their tokens at a level that
  // allows them to be internalized into macros.
  i = 0u;
  for (auto &info : new_tokens_alloc) {
    if (info.parent) {
      depth[i] += 10;
    }

#if 0
    auto data = info.printed_tok->Data();
    if (data[0] == '\n') {
      data = {};
    }

    std::stringstream pti;
    if (info.parsed_tok) {
      pti << info.parsed_tok->Index();
    }

    std::stringstream fid;
    auto frag_id_it = token_to_nested_fragment.find(RawEntity(info.printed_tok.value()));
    if (frag_id_it != token_to_nested_fragment.end()) {
      fid << frag_id_it->second.Unpack().fragment_id;
    }

    std::cerr << info.printed_tok->Index() << '\t' << pti.str() << '\t' << fid.str() << '\t' << depth[i] << '\t' << data << '\n';
#endif

    ++i;
  }
}

void Rebuilder::AddTokensToSub(
    Substitution *new_sub, Substitution::NodeList &nodes, TokenInfo *first,
    unsigned max_index) {

  for (auto tok = first; tok; tok = tok->next) {
    if (tok->printed_tok->Index() > max_index) {
      break;
    }

    Substitution **parent_pointer = &(tok->parent);
    Substitution *last_parent = nullptr;
    while (*parent_pointer) {
      last_parent = *parent_pointer;
      parent_pointer = &(last_parent->parent);
    }

    // This token is in something that has already been added to `new_sub`.
    if (last_parent == new_sub) {
      continue;
    }

    *parent_pointer = new_sub;
    assert(tok->parent != nullptr);

    if (parent_pointer == &(tok->parent)) {
      nodes.emplace_back(tok);

    } else if (nodes.empty()) {
      nodes.emplace_back(last_parent);

    } else if (Substitution::Node(last_parent) != nodes.back()) {
      nodes.emplace_back(last_parent);
    }
  }
}

void Rebuilder::ReplicateSurfaceUsesInto(
    Substitution &new_sub, const pasta::Macro &macro) {

  if (auto mt = pasta::MacroToken::From(macro)) {
    auto &new_tok = new_tokens_alloc.emplace_back();
    new_tok.macro_tok = std::move(mt);
    new_tok.parent = &new_sub;
    new_sub.before.emplace_back(&new_tok);

  } else {
    for (auto child : macro.Children()) {
      ReplicateSurfaceUsesInto(new_sub, child);
    }
  }
}

void Rebuilder::BuildBottomUp(std::deque<Substitution> &orig_subs_alloc) {

  auto last_frag_sub = new_subs_alloc.size();
  auto last_processed = ~0u;

  for (auto it = orig_subs_alloc.rbegin(); it != orig_subs_alloc.rend(); ++it) {
    Substitution &orig_sub = *it;
    if (orig_sub.is_dead || orig_sub.before.has_error ||
        orig_sub.after.has_error || !orig_sub.parent || !orig_sub.macro) {
      // std::cerr << "1) error/dead/not macro/root kind="
      //           << mx::EnumeratorName(orig_sub.kind) << '\n';
      continue;
    }

    // These never expand to parsed tokens; they only exist in the pre-
    // processor.
    auto &orig_macro = orig_sub.macro.value();
    if (pasta::MacroDirective::From(orig_macro) ||
        pasta::MacroParameterSubstitution::From(orig_macro) ||
        pasta::MacroStringify::From(orig_macro) ||
        pasta::MacroConcatenate::From(orig_macro)) {
      // std::cerr << "2) directive\n";
      continue;
    }

    // TODO(pag): Investigate when `!orig_lc->parsed_tok.has_value()`.
    const TokenInfo *orig_lc = LeftCornerOfExp(&orig_sub);
    if (!orig_lc || !orig_lc->parsed_tok.has_value() ||
        !orig_lc->printed_tok.has_value()) {
      // std::cerr << "3) orig_lc\n";
      continue;
    }

    const TokenInfo *orig_rc = RightCornerOfExp(&orig_sub);
    if (!orig_rc->parsed_tok.has_value()) {
      // std::cerr << "4) orig_rc\n";
      continue;
    }

    auto orig_lc_index = orig_lc->parsed_tok->Index();
    auto orig_rc_index = orig_rc->parsed_tok->Index();
    CHECK_LE(orig_lc_index, orig_rc_index);

    auto lb = parsed_tokens.lower_bound(orig_lc_index);
    if (lb == parsed_tokens.end()) {
      // std::cerr << "5) lc not parsed\n";
      continue;
    }

    // The parsed token appears mutliple times in the printed range.
    // Conservatively ignore it for now.
    //
    // TODO(pag): Eventually do something smarter.
    if (1u < lb->second.size()) {
      // std::cerr << "6) multiple parsed tokens\n";
      continue;
    }

    // This substitution definitely cannot not contain this node. The right
    // corner of the parsed tokens is less than the next known parsed token
    // that is or follows the left corner of the substitution.
    if (orig_rc_index < lb->first) {
      // std::cerr << "7) too far\n";
      continue;
    }

    // The printed token appears out-of-order with respect to the original
    // parsed tokens. We always need to be moving back-to-front in the printed
    // token list.
    TokenInfo *new_lc = lb->second.front();
    auto new_lc_index = new_lc->printed_tok->Index();
    if (new_lc_index > last_processed) {
      // std::cerr << "8) out-of-order\n";
      continue;
    }

    bool covers_pt = false;
    auto new_rc = LastInRange(
        new_lc, orig_lc_index, orig_rc_index,
        depth[orig_lc->printed_tok->Index()], covers_pt);

    if (!new_rc || !covers_pt) {
      // std::cerr << "9) new_lc_index=" << new_lc_index << " orig_lc_index="
      //           << orig_lc->printed_tok->Index()<< " new_rc=" << (!!new_rc)
      //           << " covers_pt=" << covers_pt << '\n';
      continue;
    }

    auto new_rc_index = new_rc->printed_tok->Index();
    DCHECK_LE(new_lc_index, new_rc_index);

    // std::cerr << "new_lc_index=" << new_lc_index << " orig_lc_index="
    //           << orig_lc->printed_tok->Index() << '\n'
    //           << "new_rc_index=" << new_rc_index << "\n";

    last_processed = new_lc_index;

    Substitution &new_sub = new_subs_alloc.emplace_back(orig_sub.kind);
    new_sub.macro = orig_sub.macro;

    AddTokensToSub(&new_sub, new_sub.after, new_lc, new_rc_index);
    assert(!new_sub.parent);

    ReplicateSurfaceUsesInto(new_sub, orig_sub.macro.value());
  }

  Substitution &new_sub = new_subs_alloc.emplace_back(mx::MacroKind::OTHER_DIRECTIVE);

  AddTokensToSub(&new_sub, new_sub.before, &(new_tokens_alloc.front()), ~0u);
  assert(!new_sub.parent);

  // Make sure no macro tokens leak into the top level.
  for (auto &tok : new_tokens_alloc) {
    if (tok.parent == &new_sub) {
      tok.macro_tok.reset();
      assert(tok.printed_tok.has_value());
    }
  }

  // Make sure the fragment substitutions have no tokens.
  for (auto i = 0u; i < last_frag_sub; ++i) {
    auto &sub = new_subs_alloc[i];
    assert(sub.fragment_id.has_value());
    assert(!sub.after.empty());
    sub.after.clear();
  }
}

// void Rebuilder::BuildTopDown(
//     Substitution *node, Substitution::NodeList &old_nodes) {

//   Substitution::NodeList new_nodes;

//   for (auto old_node : old_nodes) {
//     TokenInfo *tok_lc = nullptr;
//     TokenInfo *tok_rc = nullptr;
//     if (std::holds_alternative<Substitution *>(old_node)) {
//       auto old_sub = std::get<Substitution *>(old_node);
//       BuildTopDown(old_sub, old_sub->after);
//       new_nodes.emplace_back(old_sub);

//       tok_lc = LeftCornerOfExp(old_sub);
//       tok_rc = RightCornerOfExp(old_sub);

//     } else if (std::holds_alternative<TokenInfo *>(old_node)) {
//       tok_lc = std::get<TokenInfo *>(old_node);
//       tok_rc = tok_lc;

//     } else {
//       assert(false);
//       continue;
//     }
//   }

//   old_nodes.swap(new_nodes);
// }

}  // namespace

bool Substitution::HasExpansion(void) const noexcept {
  switch (kind) {
    case mx::MacroKind::OTHER_DIRECTIVE:
    case mx::MacroKind::IF_DIRECTIVE:
    case mx::MacroKind::IF_DEFINED_DIRECTIVE:
    case mx::MacroKind::IF_NOT_DEFINED_DIRECTIVE:
    case mx::MacroKind::ELSE_IF_DIRECTIVE:
    case mx::MacroKind::ELSE_IF_DEFINED_DIRECTIVE:
    case mx::MacroKind::ELSE_IF_NOT_DEFINED_DIRECTIVE:
    case mx::MacroKind::ELSE_DIRECTIVE:
    case mx::MacroKind::END_IF_DIRECTIVE:
    case mx::MacroKind::DEFINE_DIRECTIVE:
    case mx::MacroKind::UNDEFINE_DIRECTIVE:
    case mx::MacroKind::PRAGMA_DIRECTIVE:
      return true;  // Empty expansion.

    case mx::MacroKind::INCLUDE_DIRECTIVE:
    case mx::MacroKind::INCLUDE_NEXT_DIRECTIVE:
    case mx::MacroKind::INCLUDE_MACROS_DIRECTIVE:
    case mx::MacroKind::IMPORT_DIRECTIVE:
      return !after.empty();

    case mx::MacroKind::EXPANSION:
    case mx::MacroKind::SUBSTITUTION:
    case mx::MacroKind::STRINGIFY:
    case mx::MacroKind::CONCATENATE:
    case mx::MacroKind::PARAMETER_SUBSTITUTION:
      return true;

    // Macro argument, parameter, etc.
    case mx::MacroKind::ARGUMENT:
    case mx::MacroKind::VA_OPT:
    case mx::MacroKind::VA_OPT_ARGUMENT:
    case mx::MacroKind::PARAMETER:
      return false;
  }

  return false;
}

// Collect a mapping of substitutions containing parsed tokens, along with
// those parsed tokens in the order that we see them.
void TokenTreeImpl::FindParsedTokens(
    Substitution *sub,
    std::unordered_map<Substitution *, std::vector<TokenInfo *>> &sub_tokens) {

  auto &nodes = sub->after.empty() ? sub->before : sub->after;

  for (auto node : nodes) {
    if (std::holds_alternative<TokenInfo *>(node)) {
      auto info = std::get<TokenInfo *>(node);
      if (info->parsed_tok) {
        sub_tokens[sub].push_back(info);
      }
    } else if (std::holds_alternative<Substitution *>(node)) {
      FindParsedTokens(std::get<Substitution *>(node), sub_tokens);
    }
  }
}

// Figure out if `node->after` looks like a macro argument pre-expansion of
// `node`, and if so, return `node->after.before.front()`, i.e. the pre-
// expansion use.
Substitution *TokenTreeImpl::PreExpansionOf(Substitution *node) {
  if (node->kind != mx::MacroKind::EXPANSION) {
    return nullptr;
  }

  auto exp = pasta::MacroExpansion::From(node->macro.value());
  if (!exp->ArgumentPreExpansion()) {
    return nullptr;
  }

  if (node->after.empty() ||
      !std::holds_alternative<Substitution *>(node->after.front())) {
    return nullptr;
  }

  auto sub_exp = std::get<Substitution *>(node->after.front());
  if (sub_exp->kind != mx::MacroKind::EXPANSION) {
    return nullptr;
  }

  exp = pasta::MacroExpansion::From(sub_exp->macro.value());
  if (!exp->IsArgumentPreExpansion()) {
    return nullptr;
  }

  return sub_exp;
}

void Substitution::Print(std::ostream &os) const {
  auto tok_data = [] (TokenInfo *info) -> std::string_view {
    std::string_view a, b, c;
    if (info->parsed_tok) {
      a = info->parsed_tok->Data();
    }
    if (info->macro_tok) {
      b = info->macro_tok->Data();
    }
    if (info->printed_tok) {
      c = info->printed_tok->Data();
    }

    TT_ASSERT((a.empty() || b.empty()) || a == b);
    TT_ASSERT((a.empty() || c.empty()) || a == c);
    TT_ASSERT((b.empty() || c.empty()) || b == c);

    if (!a.empty()) {
      return a;
    } else if (!b.empty()) {
      return b;
    } else if (!c.empty()) {
      return c;
    } else {
      return "\x1b[1;31m???\033[0m";
    }
  };

  for (const Substitution::Node &ent : before) {
    if (std::holds_alternative<TokenInfo *>(ent)) {
      os << tok_data(std::get<TokenInfo *>(ent));
    } else {
      Substitution *child = std::get<Substitution *>(ent);
      assert(child->parent == this);
      child->Print(os);
    }
  }
}

void Substitution::PrintDOT(std::ostream &os, bool first) const {
  const auto self = reinterpret_cast<const void *>(this);

  if (first) {
    os << "digraph {\n"
       << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";
  }

  if (fragment_id) {
    os << "s" << self
       << " [label=<<TABLE cellpadding=\"0\" cellspacing=\"0\" border=\"1\""
       << " bgcolor=\"cadetblue1\"><TR><TD>FRAGMENT</TD></TR><TR><TD>"
       << fragment_id->Pack() << "</TD></TR></TABLE>>];\n";
    return;
  }

  auto has_any = false;
  auto dump_tok = [&](TokenInfo *info) {
    os << "<TD><TABLE cellpadding=\"0\" cellspacing=\"0\" border=\"0\"";
    os << ">";
    if (info->parsed_tok) {
      os << "<TR><TD>PK=" << info->parsed_tok->KindName() << "</TD></TR>";
      os << "<TR><TD>PI=" << info->parsed_tok->Index() << "</TD></TR>";
    }
    if (info->printed_tok) {
      os << "<TR><TD>GI=" << info->printed_tok->Index() << "</TD></TR>";
    }

    if (info->parsed_tok) {
      os << "<TR><TD><B>" << TokData(info->parsed_tok.value())
         << "</B></TD></TR>";
    } else if (info->macro_tok) {
      os << "<TR><TD><B>" << TokData(info->macro_tok.value())
         << "</B></TD></TR>";
    } else if (info->printed_tok) {
      os << "<TR><TD><B>" << TokData(info->printed_tok.value())
         << "</B></TD></TR>";
    } else {
      os << "<TR><TD><FONT COLOR=\"red\">? ? ?</FONT></TD></TR>";
    }
    os << "</TABLE></TD>";
    has_any = true;
  };

  auto dump_toks = [&](const Substitution::NodeList &nodes) {
    for (const Substitution::Node &ent : nodes) {
      if (std::holds_alternative<TokenInfo *>(ent)) {
        dump_tok(std::get<TokenInfo *>(ent));
      } else if (std::holds_alternative<Substitution *>(ent)) {
        Substitution *s = std::get<Substitution *>(ent);
        auto other = reinterpret_cast<const void *>(s);
        os << "<TD port=\"s" << other << "\"> </TD>";
        has_any = true;
      }
    }
  };

  auto link_subs = [&](const Substitution::NodeList &nodes,
                       const char *prefix) {
    for (const Substitution::Node &ent : nodes) {
      if (std::holds_alternative<Substitution *>(ent)) {
        Substitution *s = std::get<Substitution *>(ent);
        assert(s->parent == self || s->is_dead || s->before.has_error ||
               s->after.has_error);
        s->PrintDOT(os, false);
        auto other = reinterpret_cast<const void *>(s);
        os << prefix << self << ":s" << other << " -> s" << other << ";\n";
      }
    }
  };

  if (HasExpansion()) {
    os << "s" << reinterpret_cast<const void *>(this)
       << " [label=<<TABLE cellpadding=\"0\" cellspacing=\"0\" border=\"1\""
       << "><TR><TD colspan=\"" << (2 + int(!body.empty())) << "\">"
       << mx::EnumeratorName(kind) << "</TD></TR><TR><TD port=\"before\">before</TD>";

    if (body.size()) {
      os << "<TD port=\"body\">body</TD>";
    }

    os << "<TD port=\"after\">"
       << "after</TD></TR></TABLE>>];\n";

    if (before.size()) {
      os << "s" << self << ":before -> b" << self << ";\n"
         << "b" << self
         << " [label=<<TABLE cellpadding=\"0\" cellspacing=\"0\" border=\"1\"";
      if (before.has_error) {
        os << " bgcolor=\"red\"";
      }
      os << "><TR>";

      has_any = false;

      dump_toks(before);

      os << "</TR></TABLE>>];\n";

      link_subs(before, "b");
    }

    if (body.size()) {
      os << "s" << self << ":body -> d" << self << ";\n"
         << "d" << self
         << " [label=<<TABLE cellpadding=\"0\" cellspacing=\"0\" border=\"1\"";
      if (body.has_error) {
        os << " bgcolor=\"red\"";
      }
      os << "><TR>";

      has_any = false;

      dump_toks(body);

      os << "</TR></TABLE>>];\n";

      link_subs(body, "d");
    }

    if (after.size()) {
      os << "s" << self << ":after -> a" << self << ";\n"
         << "a" << self
         << " [label=<<TABLE cellpadding=\"0\" cellspacing=\"0\" border=\"1\"";
      if (after.has_error) {
        os << " bgcolor=\"red\"";
      }
      os << "><TR>";

      has_any = false;

      dump_toks(after);

      os << "</TR></TABLE>>];\n";

      link_subs(after, "a");
    }

  // No expansion.
  } else {
    auto num_cols = before.size();

    os << "s" << self
       << " [label=<<TABLE cellpadding=\"0\" cellspacing=\"0\" border=\"1\"";
    if (before.has_error) {
      os << " bgcolor=\"red\"";
    }
    os << "><TR><TD colspan=\"" << num_cols << "\">"
       << mx::EnumeratorName(kind) << "</TD></TR><TR>";

    dump_toks(before);

    if (!has_any && !num_cols) {
      os << "<TD> </TD>";
    }

    os << "</TR></TABLE>>];\n";

    link_subs(before, "s");
  }

  if (first) {
    os << "}\n\n";
  }
}

// Build an initial token info list. This contains all of the tokens that were
// parsed, plus the file tokens that were macro uses. This does not contain
// file tokens that were elided due to things like conditional macros, e.g.
// `#if 0`.
Substitution *TokenTreeImpl::BuildFromTokenList(
    const PendingFragment &pf, std::ostream &err) {

  // std::cerr << "\n-- BUILDING TREE fragment_index="
  //           << pf.fragment_id.Unpack().fragment_id
  //           << " parent_entity=" << (!!pf.raw_parent_entity)
  //           << " parent_eid=" << pf.em.EntityId(pf.raw_parent_entity)
  //           << "\n";
  // std::cerr << pf.parsed_tokens.Data() << "\n";

  Substitution *root_sub = nullptr;

  auto has_any_macros = !pf.top_level_macros.empty();
  if (!has_any_macros && pf.original_tokens) {
    has_any_macros = HasAnyMacroTokens(pf.original_tokens.value());
  }

  // Figure out if we need to rebuild the token tree based on pure printed
  // tokens (e.g. for a template specialization), or to excise nested fragments.
  auto rebuild = !pf.token_to_nested_fragment.empty() ||
                 (has_any_macros && pf.parsed_tokens_are_printed);

  if (!pf.parsed_tokens_are_printed || has_any_macros) {

    if (pf.original_tokens) {
      root_sub = BuildFromParsedTokenList(pf, err);

      // Some dangling tokens, probably from a parent expansion.
      if (!pf.parsed_tokens_are_printed && pf.original_tokens &&
          !final_toks.empty()) {
        rebuild = true;
      }

    } else if (!pf.parsed_tokens) {
      err << "Empty parsed and printed token ranges";
      return nullptr;
    }

    // It's not a specialization of any kind, so we don't need to check if tokens
    // are contiguous or rebuild things.
    if (!rebuild && root_sub) {
      return root_sub;
    }
  }

  // {
  //   std::unique_lock<std::mutex> locker(gPrintDOTLock);
  //   if (root_sub) {
  //     root_sub->PrintDOT(std::cerr);
  //   }
  //   std::cerr
  //       << "\n-- REBUILDING TREE:"
  //       << " parsed_tokens_are_printed=" << pf.parsed_tokens_are_printed
  //       << " has_any_macros=" << has_any_macros
  //       << " original_tokens=" << pf.original_tokens.has_value()
  //       << " root_sub=" << (!!root_sub) << '\n';
  //   std::cerr << pf.top_level_decls.front().Tokens().Data() << '\n';
  //   Dump(pf.top_level_decls.front());
  // }

  Rebuilder rebuilder(pf);
  rebuilder.AllocateTokens(pf.parsed_tokens);
  rebuilder.BuildBottomUp(substitutions_alloc);
  tokens_alloc.swap(rebuilder.new_tokens_alloc);
  substitutions_alloc.swap(rebuilder.new_subs_alloc);

  root_sub = &(substitutions_alloc.back());
  // root_sub->PrintDOT(std::cerr);
  return root_sub;
}

// Try to find the topmost macro whose expansion is contained within this
// fragment, and then include that macro.
static std::optional<pasta::Macro> FindPendingMacro(
    const PendingFragment &pf, std::optional<pasta::Macro> macro) {
  if (!macro) {
    return std::nullopt;
  }

  auto range = pasta::Macro::ExpansionRange(macro.value());
  if (!range) {
    return std::nullopt;
  }

  auto begin_index = range.Front()->Index();
  if (begin_index < pf.first_parsed_token_index) {
    return std::nullopt;
  }

  auto end_index = range.Back()->Index();
  if (end_index > pf.last_parsed_token_index) {
    return std::nullopt;
  }

  if (auto parent = FindPendingMacro(pf, macro->Parent())) {
    return parent;
  }

  return macro;
}

Substitution *TokenTreeImpl::CreateDirectiveFragment(
    const PendingFragment &pf, const pasta::Macro &macro) {

  auto eid = pf.em.EntityId(macro);
  auto mid = mx::EntityId(eid).Extract<mx::MacroId>();
  if (!mid) {
    return nullptr;
  }

  if (mid->fragment_id == pf.fragment_index) {
    return nullptr;
  }

  auto frag_sub = CreateSubstitution(mx::MacroKind::OTHER_DIRECTIVE);
  frag_sub->fragment_id = mx::FragmentId(mid->fragment_id);
  frag_sub->num_parsed_tokens = 1u;
  // TODO(pag): parsed_token_offset.

  return frag_sub;
}

// Most of the time we have parsed tokens and printed tokens, where the printed
// tokens are a subset of the parsed tokens, and should reference them. The
// printed tokens being a subset is due to `pasta::PrintedTokenRange::Adopt` on
// `range`, then the indexer tries to align the adopted range with a 100%
// invented range (generated by pretty printing).
Substitution *TokenTreeImpl::BuildFromParsedTokenList(
    const PendingFragment &pf, std::ostream &err) {

  bool in_macro = false;
  std::optional<pasta::Macro> pending_macro;

  Substitution *root_sub = CreateSubstitution(mx::MacroKind::OTHER_DIRECTIVE);

  std::vector<std::pair<Substitution *, Substitution::NodeList *>> subs;
  subs.emplace_back(root_sub, &(root_sub->before));

  // Figure out a mapping between parsed tokens are printed tokens.
  std::unordered_map<const void *, pasta::PrintedToken> printed_tokens;
  for (auto pt : pf.parsed_tokens) {
    if (auto dt = pt.DerivedLocation()) {
      printed_tokens.emplace(RawEntity(dt.value()), std::move(pt));
    }
  }

  for (pasta::Token tok : pf.original_tokens.value()) {
    TokenInfo *info = nullptr;

    switch (tok.Role()) {

      // These will happen because of token splits in PASTA.
      case pasta::TokenRole::kInvalid:
        continue;

      case pasta::TokenRole::kBeginOfMacroExpansionMarker:
        assert(!in_macro);
        assert(!pending_macro.has_value());
        in_macro = true;
        pending_macro = pasta::Macro::FromMarkerToken(tok);
        if (pending_macro.has_value()) {
          pending_macro = RootNodeFrom(pending_macro.value());
        }
        continue;

      case pasta::TokenRole::kMacroDirectiveMarker: {
        auto directive = pasta::Macro::FromMarkerToken(tok);
        if (!directive) {
          err << "Found directive marker token with no corresponding directive";
          return nullptr;
        }

        // We're in a floating fragment for a `#define` or `#pagma` directive.
        // It contains only the marker token for this directive.
        if (!pending_macro && !in_macro && pf.original_tokens->size() == 1u) {
          if (!BuildFromMacro(pf, subs.back().first, *(subs.back().second),
                              std::move(directive.value()), err)) {
            return nullptr;
          }
        
        } else if (!pending_macro) {
          if (auto dir_sub = CreateDirectiveFragment(pf, directive.value())) {
            subs.back().second->emplace_back(dir_sub);
          }
        }

        continue;
      }

      case pasta::TokenRole::kEndOfMacroExpansionMarker:        
        // If we're building the token tree for a nested fragment, then we
        // might have started part-way through an expansion, so we don't have
        // that macro as part of anything.
        if (!in_macro) {
          assert(!pending_macro.has_value());
          assert(pf.raw_parent_entity != nullptr);
          continue;
        }

        assert(pending_macro.has_value());
        in_macro = false;

        if (!pending_macro.has_value()) {
          assert(false);
          err << "Got to end-of-macro-expansion marker without a macro to process";
          return nullptr;
        }

        if (!BuildFromMacro(pf, subs.back().first, *(subs.back().second),
                            std::move(pending_macro.value()), err)) {
          return nullptr;
        }
        pending_macro.reset();
        continue;

      case pasta::TokenRole::kIntermediateMacroExpansionToken:
      case pasta::TokenRole::kInitialMacroUseToken:
        assert(false);  // Makes no sense to see these tokens in the parsed list.
        assert(in_macro);
        continue;

      // TODO(pag): Maybe a stack of substitutions?
      case pasta::TokenRole::kBeginOfFileMarker: {
        assert(!in_macro);

        if (subs.empty()) {
          assert(false);
          has_error = true;
          err << "Unexpected begin-of-file marker with empty substitution stack";
          return nullptr;
        }

        if (subs.back().second->empty()) {
          assert(false);
          has_error = true;
          err << "Unexpected begin-of-file marker with empty parent node list";
          return nullptr;
        }

        if (!std::holds_alternative<Substitution *>(subs.back().second->back())) {
          assert(false);
          has_error = true;
          err << "Unexpected begin-of-file marker non-substitution on end of parent node list";
          return nullptr;
        }

        auto inc = std::get<Substitution *>(subs.back().second->back());
        switch (inc->kind) {
          case mx::MacroKind::INCLUDE_DIRECTIVE:
          case mx::MacroKind::INCLUDE_MACROS_DIRECTIVE:
          case mx::MacroKind::INCLUDE_NEXT_DIRECTIVE:
          case mx::MacroKind::IMPORT_DIRECTIVE:
            break;

          default:
            has_error = true;
            err << "Last substitution isn't an include directive";
            return nullptr;
        }

        // Create a substitution above the `#include` directive.
        auto inc_sub = CreateSubstitution(mx::MacroKind::SUBSTITUTION);
        inc_sub->before.emplace_back(inc);
        inc->parent = inc_sub;

        inc_sub->parent = subs.back().first;
        subs.back().second->back() = inc_sub;

        // Switch to the "after" of the include directive.
        subs.emplace_back(inc_sub, &(inc_sub->after));
        continue;
      }

      case pasta::TokenRole::kEndOfFileMarker:
        assert(!in_macro);

        if (subs.empty()) {
          assert(false);
          has_error = true;
          err << "Unexpected end-of-file marker with empty substitution stack";
          return nullptr;
        }

        // We're on the other side of an include.
        if (&(subs.back().first->after) == subs.back().second) {
          assert(subs.size() > 1u);
        }

        subs.pop_back();
        
        // We have an entity that crossed from the end of one file back into
        // its including file.
        //
        // This happens in the Linux kernel with `drbd_genl_cmd_to_str` that has
        // an attribute in one file but the rest of the function in another
        // file. This entity is produced by macro expansion of:
        //
        //        CONCAT_(GENL_MAGIC_FAMILY, _genl_cmd_to_str)
        //
        // in the x-macro file `include/linux/genl_magic_func.h`, where the
        // attribute is the last thing in a macro expansion of `GENL_struct` in
        // the same file.
        //
        // What happens is that we end up having unbalanced begin/end file marker
        // tokens and we accumulate into the top-level. In theory we should
        // accumulate an `#include` above `root_sub`, and do a kind of recursive
        // ascent constuction of the tree. In practice, we don't expect to hit
        // this situation, and we try to mitigate the issue of unbalanced `BOF`
        // and `EOF` tokens in `IndexCompileJob.cpp` by identifying when decls
        // include `EOF` markers, and then expanding their ranges to contain the
        // associated `#include` directive.
        //
        // XREF(pag): Issue 258.
        // https://github.com/trailofbits/multiplier/issues/258#issuecomment-1401170794
        if (subs.empty()) {
          subs.emplace_back(root_sub, &(root_sub->before));
        }
        continue;

      // Create token info for each final macro expansion token, but don't
      // actually link them into the substitution. This will happen as-needed
      // when we get to the end of the macro expansion region and visit all
      // of its nodes.
      case pasta::TokenRole::kFinalMacroExpansionToken: {
        info = &(tokens_alloc.emplace_back());
        info->macro_tok = tok.MacroLocation();
        info->parsed_tok = std::move(tok);

        // They should match, but it could also be a split token case, e.g.
        // the parsed token is `>` or `=`, and the macro token is `>=`.
        assert(info->macro_tok->Data().starts_with(info->parsed_tok->Data()) ||
               info->macro_tok->Data().ends_with(info->parsed_tok->Data()));

        assert(info->macro_tok->TokenRole() ==
               pasta::TokenRole::kFinalMacroExpansionToken);

        // If we're building the token tree for a nested fragment, then we
        // might have started part-way through an expansion, so we don't have
        // that macro as part of anything.
        if (!in_macro) {
          assert(pf.raw_parent_entity != nullptr);
          pending_macro = FindPendingMacro(pf, info->macro_tok->Parent());
          if (!pending_macro) {
            subs.back().second->emplace_back(info);
            info->parent = subs.back().first;
            break;
          }

          in_macro = true;
        }

        auto [it, added] = final_toks.emplace(
            info->macro_tok->RawMacro(), info);

        // If we didn't add it in, then we're likely dealing with a split token
        // case, e.g. two parsed tokens (`>` and `>`) derived from one macro
        // token (`>>`).
        if (!added) {
          TokenInfo **next_ptr = nullptr;
          for (auto i = it->second; i; i = *next_ptr) {
            next_ptr = &(i->next);
          }

          // Chain it in at the end.
          *next_ptr = info;
        }
        break;
      }

      case pasta::TokenRole::kFileToken:
        assert(!in_macro);
        assert(!tok.MacroLocation());
        info = &(tokens_alloc.emplace_back());
        info->parsed_tok = std::move(tok);
        info->parent = subs.back().first;
        subs.back().second->emplace_back(info);
        break;
    }

    if (auto it = printed_tokens.find(RawEntity(info->parsed_tok.value()));
        it != printed_tokens.end()) {
      info->printed_tok = it->second;
    }
  }

  if (in_macro) {
    assert(pf.raw_parent_entity != nullptr);

    if (!pending_macro.has_value()) {
      err << "Reached end of token list while still in macro";
      return nullptr;
    }

    if (!BuildFromMacro(pf, subs.back().first, *(subs.back().second),
                        std::move(pending_macro.value()), err)) {
      return nullptr;
    }
  }

  assert(root_sub->after.empty());
  assert(subs.size() == 1u);
  assert(subs.back().first == root_sub);

  return root_sub;
}

bool TokenTreeImpl::BuildFromMacro(
    const PendingFragment &pf, Substitution *sub, Substitution::NodeList &nodes,
    pasta::Macro node, std::ostream &err) {
  switch (node.Kind()) {
    case pasta::MacroKind::kToken:
      return BuildMacroSubstitution(
          sub, nodes, reinterpret_cast<pasta::MacroToken &>(node), err);
    case pasta::MacroKind::kArgument:
      return BuildMacroSubstitution(
          pf, sub, nodes, reinterpret_cast<pasta::MacroArgument &>(node), err);
    case pasta::MacroKind::kParameter:
      return BuildMacroSubstitution(
          pf, sub, nodes, reinterpret_cast<pasta::MacroParameter &>(node), err);
    case pasta::MacroKind::kExpansion:
      return BuildMacroSubstitution(
          pf, sub, nodes, reinterpret_cast<pasta::MacroExpansion &>(node), err);
    case pasta::MacroKind::kVAOpt:
      return BuildMacroSubstitution(
          pf, sub, nodes, reinterpret_cast<pasta::MacroVAOpt &>(node), err);
    case pasta::MacroKind::kVAOptArgument:
      return BuildMacroSubstitution(
          pf, sub, nodes,
          reinterpret_cast<pasta::MacroVAOptArgument &>(node), err);
    case pasta::MacroKind::kSubstitution:
    case pasta::MacroKind::kParameterSubstitution:
    case pasta::MacroKind::kStringify:
    case pasta::MacroKind::kConcatenate:
      return BuildMacroSubstitution(
          pf, sub, nodes,
          reinterpret_cast<pasta::MacroSubstitution &>(node), err);
    case pasta::MacroKind::kOtherDirective:
    case pasta::MacroKind::kIfDirective:
    case pasta::MacroKind::kIfDefinedDirective:
    case pasta::MacroKind::kIfNotDefinedDirective:
    case pasta::MacroKind::kElseIfDirective:
    case pasta::MacroKind::kElseIfDefinedDirective:
    case pasta::MacroKind::kElseIfNotDefinedDirective:
    case pasta::MacroKind::kElseDirective:
    case pasta::MacroKind::kEndIfDirective:
    case pasta::MacroKind::kUndefineDirective:
    case pasta::MacroKind::kPragmaDirective:
    case pasta::MacroKind::kIncludeDirective:
    case pasta::MacroKind::kIncludeNextDirective:
    case pasta::MacroKind::kIncludeMacrosDirective:
    case pasta::MacroKind::kImportDirective:
    case pasta::MacroKind::kDefineDirective:
      return BuildMacroSubstitution(
          pf, sub, nodes,
          reinterpret_cast<pasta::MacroDirective &>(node), err);
  }

  err << "Unexpected/unsupported substitution kind";
  return false;
}

Substitution *TokenTreeImpl::CreateSubstitution(mx::MacroKind kind_) {
  return &(substitutions_alloc.emplace_back(kind_));
}

// Merge an argument `orig` from the main expansion with the argument `pre_exp`
// from the pre argumetn expansion phase. E.g. in the following case:
//
//      macro(
//        "hello"
//        #if anotehr_macro
//        "world"
//        #endif
//        )
//
// Then things like `another_macro` and the `#if` will be present in `orig` but
// not in `pre_exp`.
Substitution *TokenTreeImpl::MergeArguments(
    Substitution *sub, Substitution *pre_exp, std::ostream &err) {

  assert(sub->after.empty());
  assert(pre_exp->after.empty());

  auto orig_arg = pasta::MacroArgument::From(sub->macro.value());
  auto pre_exp_arg = pasta::MacroArgument::From(sub->macro.value());

  if (orig_arg->Index() != pre_exp_arg->Index()) {
    sub->before.has_error = true;
    pre_exp->before.has_error = true;
    Die(this);
    err << "Can't merge arguments with non-matching indices";
    return nullptr;
  }

  D( std::cerr << indent << "Merge pre expansion argument "
               << orig_arg->Index() << '\n'; )

  if (pre_exp->before.empty()) {
    D( std::cerr << indent << "  Trivial merge\n"; )
    return sub;
  }

  // Check if all original argument nodes are tokens.
  bool orig_is_simple = true;
  for (Substitution::Node &orig_node : sub->before) {
    if (!std::holds_alternative<TokenInfo *>(orig_node)) {
      orig_is_simple = false;
      break;
    }
  }

  // If at least one of the original argument nodes is a substitution, then
  // create a before/after substitution.
  if (!orig_is_simple) {

    D( std::cerr << indent << "  Argument isn't simple, using substitution.\n"; )

    Substitution::NodeList new_nodes;

    Substitution *new_arg_sub = CreateSubstitution(mx::MacroKind::SUBSTITUTION);
    new_arg_sub->before = std::move(sub->before);
    new_arg_sub->after = std::move(pre_exp->before);
    new_arg_sub->parent = sub;
    FixupNodeParents(new_arg_sub);

    new_nodes.emplace_back(new_arg_sub);
    sub->before = std::move(new_nodes);

  // Use `pre_exp` because the original is simple, and so the pre-expansion
  // is either simple or not, so whatever it is is more desirable.
  } else {
    sub->before = std::move(pre_exp->before);
    sub->after = std::move(pre_exp->after);
    FixupNodeParents(sub);
  }

  pre_exp->before.clear();
  pre_exp->after.clear();
  pre_exp->macro.reset();
  pre_exp->parent = nullptr;
  pre_exp->is_dead = true;

  return sub;
}

// Tries to unify a macro use with its pre-expansion phase, so that we don't
// doubly count macro uses in the indexer, and so that pre-expansions aren't
// presented in a confusing way.
bool TokenTreeImpl::MergeArgPreExpansion(Substitution *sub,
                                         Substitution *pre_exp,
                                         std::ostream &err) {

  D( std::cerr << indent << "Merge pre expansion";
     if (sub->macro) {
       if (auto bt = sub->macro->BeginToken()) {
         std::cerr << ' ' << bt->Data();
       }
     }
     std::cerr << '\n';)
  D( indent += "  "; )

  // Make sure we calculate the pre-expansion correctly.
  assert(1u <= sub->after.size());
  assert(std::holds_alternative<Substitution *>(sub->after.front()));
  assert(std::get<Substitution *>(sub->after.front()) == pre_exp);
  assert(sub->kind == mx::MacroKind::EXPANSION);
  assert(pre_exp->kind == mx::MacroKind::EXPANSION);

  Substitution::NodeList new_nodes;

  auto orig_i = 0u;
  auto preexp_i = 0u;
  const auto orig_max = sub->before.size();
  const auto preexp_max = pre_exp->before.size();

  auto changed = true;

  TokenInfo *orig_rc = nullptr;
  TokenInfo *preexp_lc = nullptr;
  Substitution *orig_arg = nullptr;
  Substitution *preexp_arg = nullptr;

  while (orig_i < orig_max && preexp_i < preexp_max && changed) {
    changed = false;
    Substitution::Node orig_node = sub->before[orig_i];
    Substitution::Node preexp_node = pre_exp->before[preexp_i];

    const bool orig_is_tok = std::holds_alternative<TokenInfo *>(preexp_node);
    const bool preexp_is_tok = std::holds_alternative<TokenInfo *>(preexp_node);

    orig_rc = RightCornerOfExpansionOrUse(orig_node);
    preexp_lc = LeftCornerOfUse(preexp_node);

    orig_arg = MacroArgument(orig_node);
    preexp_arg = MacroArgument(preexp_node);

    D(
      std::cerr
          << indent << "orig_i=" << orig_i << " preexp_i=" << preexp_i
          << " preexp_is_tok=" << preexp_is_tok
          << " orig_arg=" << (!!orig_arg) << " preexp_arg=" << (!!preexp_arg)
          << " orig_rc=" << (!!orig_rc) << " preexp_lc=" << (!!preexp_lc);

      std::cerr << '\n';
    )

    // If we have two arguments, then try to merge them.
    if (orig_arg && preexp_arg) {
      if (auto new_arg = MergeArguments(orig_arg, preexp_arg, err)) {
        new_nodes.emplace_back(new_arg);
        changed = true;
        ++orig_i;
        ++preexp_i;
        continue;

      } else {
        return false;
      }

    // Move things to align on arguments.
    } else if (orig_arg) {
      new_nodes.push_back(preexp_node);
      ++preexp_i;
      changed = true;
      continue;

    // Move things to align on arguments.
    } else if (preexp_arg) {

      // If this is something that expands to nothing, e.g. a directive.
      if (!orig_rc) {
        new_nodes.push_back(orig_node);

      // Make a substitution that expands to nothing.
      } else {
        Substitution *empty_sub = CreateSubstitution(
            mx::MacroKind::SUBSTITUTION);
        new_nodes.emplace_back(empty_sub);

        empty_sub->parent = sub;
        empty_sub->before.emplace_back(orig_node);
        FixupNodeParents(empty_sub);
      }

      ++orig_i;
      changed = true;
      continue;
    }

    // If we have stuff with what looks like matching token data, then try to
    // merge them.
    if (orig_rc && preexp_lc &&
        orig_rc->macro_tok->Data() == preexp_lc->macro_tok->Data()) {

      // If the pre-expansion is a token, then the original is more interesting,
      // as it'll be a token or a node (that expands to a token), so keep the
      // original.
      if (preexp_is_tok) {
        new_nodes.push_back(orig_node);

      // If the original is a token, then the pre-expansion is more interesting.
      } else if (orig_is_tok) {
        new_nodes.push_back(preexp_node);

      // If the pre-expansion isn't a token, and regardless of what the original
      // is, then we'll want to show some kind of substitution.
      } else {
        Substitution *non_empty_sub = CreateSubstitution(
            mx::MacroKind::SUBSTITUTION);
        non_empty_sub->parent = sub;
        non_empty_sub->before.emplace_back(orig_node);
        non_empty_sub->after.emplace_back(preexp_node);
        FixupNodeParents(non_empty_sub);
        new_nodes.emplace_back(non_empty_sub);
      }

      changed = true;
      ++orig_i;
      ++preexp_i;
      continue;
    }

    // Something that expands to nothing.
    if (!orig_rc) {
      new_nodes.push_back(orig_node);
      changed = true;
      ++orig_i;
      continue;
    }

    // Should be implied by `!orig_rc`.
    assert(!MacroDirective(orig_node));

    // Something that expands to nothing.
    if (!RightCornerOfExpansionOrUse(preexp_node)) {
      new_nodes.push_back(preexp_node);
      changed = true;
      ++preexp_i;
      continue;
    }

    // Should be implied by `!RightCornerOfExpansionOrUse(preexp_node)`.
    assert(!MacroDirective(preexp_node));

    sub->before.has_error = true;
    pre_exp->before.has_error = true;
    Die(this);
    err << "Unable to merge pre-expansion entries at orig_i=" << orig_i
        << " and preexp_i=" << preexp_i;
    return false;
  }

  if (orig_i != orig_max || preexp_i != preexp_max) {
    sub->before.has_error = true;
    pre_exp->before.has_error = true;
    Die(this);
    err << "Failed to merge trailing entries with orig_i=" << orig_i
        << " orig_max=" << orig_max << " preexp_i=" << preexp_i
        << " preexp_max=" << preexp_max;
    return false;
  }

  // Wipe out the intermediate expansion.
  sub->before = std::move(new_nodes);
  sub->after = std::move(pre_exp->after);
  FixupNodeParents(sub);

  pre_exp->parent = nullptr;
  pre_exp->is_dead = true;
  pre_exp->before.clear();

  D( indent.resize(indent.size() - 2u); )
  return true;
}

// Get or create a substitution representing the body of the macro. Really, this
// is to get the beginning/ending tokens.
Substitution *TokenTreeImpl::GetMacroBody(pasta::DefineMacroDirective def,
                                          std::ostream &err) {

  auto maybe_name = def.Name();
  if (!maybe_name) {
    err << "Macro has no name";
    D( std::cerr << indent << "Failed to get body\n"; )
    return nullptr;
  }

  Substitution *&body = macro_body[def.RawMacro()];
  if (body) {
    D( std::cerr << indent << "Already have body for " << maybe_name->Data()
                 << '\n'; )
    return body;
  }

  D( std::cerr << indent << "Getting body for " << maybe_name->Data()
               << '\n'; )
  D( indent += "  "; )

  pasta::MacroToken name = std::move(maybe_name.value());
  body = CreateSubstitution(mx::MacroKind::DEFINE_DIRECTIVE);
  body->macro = def;

  for (pasta::Macro node : def.Body()) {
    std::optional<pasta::MacroToken> tok = pasta::MacroToken::From(node);
    if (!tok) {
      D( std::cerr << indent << "skipping non-token body node: "
                   << node.BeginToken()->Data() << '\n'; )
      continue;
    }

    D( std::cerr << indent << "body token: " << tok->Data() << '\n'; )

    pasta::TokenKind tok_kind = tok->TokenKind();
    TokenInfo &info = tokens_alloc.emplace_back();
    info.macro_tok = tok;

    switch (tok_kind) {
      case pasta::TokenKind::kEndOfFile:
      case pasta::TokenKind::kEndOfDirective:
        continue;
      default:
        info.parent = body;
        body->before.emplace_back(&info);
        break;
    }
  }

  D( indent.resize(indent.size()  - 2u); )
  (void)err;
  return body;
}

bool TokenTreeImpl::BuildMacroSubstitution(
    Substitution *sub, Substitution::NodeList &nodes,
    const pasta::MacroToken &node, std::ostream &err) {

  TokenInfo *info = nullptr;
  auto it = final_toks.find(node.RawMacro());
  if (it != final_toks.end()) {
    assert(node.TokenRole() == pasta::TokenRole::kFinalMacroExpansionToken);
    info = it->second;

    // Shouldn't see the same parsed token twice in a row.
    if (info->parent) {
      assert(false);

      auto new_info = &(tokens_alloc.emplace_back());
      new_info->parsed_tok = info->parsed_tok;
      new_info->macro_tok = info->macro_tok;
      new_info->printed_tok = info->printed_tok;
      info = new_info;
    }

    final_toks.erase(it);

  } else {
    switch (node.TokenRole()) {
      case pasta::TokenRole::kInitialMacroUseToken:
      case pasta::TokenRole::kIntermediateMacroExpansionToken:
        break;
      default:
        assert(false);
        err << "Unexpected token role for macro token";
        nodes.has_error = true;
        return false;
    }
    info = &(tokens_alloc.emplace_back());
    info->macro_tok = node;
  }

  if (!node.Data().empty()) {
    info->parent = sub;
    nodes.emplace_back(info);
  }

  // Fill in the rest of the split tokens.
  while (auto next_info = info->next) {
    info->next = nullptr;
    next_info->parent = sub;
    nodes.emplace_back(next_info);
    info = next_info;
  }

  return true;
}

bool TokenTreeImpl::BuildMacroSubstitution(
    const PendingFragment &pf, Substitution *sub,
    Substitution::NodeList &nodes, const pasta::MacroArgument &node,
    std::ostream &err) {

  assert(!nodes.empty());

  Substitution *arg_sub = CreateSubstitution(mx::FromPasta(node.Kind()));
  arg_sub->parent = sub;
  arg_sub->macro = node;
  nodes.emplace_back(arg_sub);

  for (pasta::Macro arg_node : node.Children()) {
    if (!BuildFromMacro(pf, arg_sub, arg_sub->before, std::move(arg_node), err)) {
      return false;
    }
  }

  return true;
}

bool TokenTreeImpl::BuildMacroSubstitution(
    const PendingFragment &pf, Substitution *sub,
    Substitution::NodeList &nodes, const pasta::MacroVAOpt &node,
    std::ostream &err) {

  Substitution *arg_sub = CreateSubstitution(mx::FromPasta(node.Kind()));
  assert(sub->kind == mx::MacroKind::EXPANSION ||
         sub->kind == mx::MacroKind::STRINGIFY);
  arg_sub->parent = sub;
  arg_sub->macro = node;
  nodes.emplace_back(arg_sub);

  for (pasta::Macro arg_node : node.Children()) {
    if (!BuildFromMacro(pf, arg_sub, arg_sub->before, std::move(arg_node), err)) {
      return false;
    }
  }

  return true;
}

bool TokenTreeImpl::BuildMacroSubstitution(
    const PendingFragment &pf, Substitution *sub, Substitution::NodeList &nodes,
    const pasta::MacroVAOptArgument &node, std::ostream &err) {

  Substitution *arg_sub = CreateSubstitution(mx::FromPasta(node.Kind()));
  assert(sub->kind == mx::MacroKind::VA_OPT);
  arg_sub->parent = sub;
  arg_sub->macro = node;
  nodes.emplace_back(arg_sub);

  for (pasta::Macro arg_node : node.Children()) {
    if (!BuildFromMacro(pf, arg_sub, arg_sub->before, std::move(arg_node), err)) {
      return false;
    }
  }

  return true;
}

bool TokenTreeImpl::BuildMacroSubstitution(
    const PendingFragment &pf, Substitution *sub, Substitution::NodeList &nodes,
    const pasta::MacroParameter &node, std::ostream &err) {

  Substitution *arg_sub = CreateSubstitution(mx::FromPasta(node.Kind()));
  assert(sub->kind == mx::MacroKind::DEFINE_DIRECTIVE);
  arg_sub->parent = sub;
  arg_sub->macro = node;
  nodes.emplace_back(arg_sub);

  for (pasta::Macro arg_node : node.Children()) {
    if (!BuildFromMacro(pf, arg_sub, arg_sub->before, std::move(arg_node), err)) {
      return false;
    }
  }

  return true;
}

bool TokenTreeImpl::BuildMacroSubstitution(
    const PendingFragment &pf, Substitution *sub, Substitution::NodeList &nodes,
    const pasta::MacroSubstitution &node, std::ostream &err) {

  Substitution *exp = CreateSubstitution(mx::FromPasta(node.Kind()));
  exp->parent = sub;
  exp->macro = node;
  nodes.emplace_back(exp);

  for (pasta::Macro use_node : node.Children()) {
    if (!BuildFromMacro(pf, exp, exp->before, std::move(use_node), err)) {
      return false;
    }
  }

  for (pasta::Macro sub_node : node.ReplacementChildren()) {
    if (!BuildFromMacro(pf, exp, exp->after, std::move(sub_node), err)) {
      return false;
    }
  }

  return true;
}

bool TokenTreeImpl::BuildMacroSubstitution(
    const PendingFragment &pf, Substitution *sub, Substitution::NodeList &nodes,
    const pasta::MacroExpansion &node, std::ostream &err) {

  Substitution *exp = CreateSubstitution(mx::FromPasta(node.Kind()));
  assert(exp->kind == mx::MacroKind::EXPANSION);

  exp->parent = sub;
  exp->macro = node;
  nodes.emplace_back(exp);

  for (pasta::Macro use_node : node.Children()) {
    if (!BuildFromMacro(pf, exp, exp->before, std::move(use_node), err)) {
      return false;
    }
  }

  for (pasta::Macro body_node : node.IntermediateChildren()) {
    auto body_node_parent = body_node.Parent();
    if (!body_node_parent || body_node_parent->RawMacro() != node.RawMacro()) {
      break;  // This is from the body of a macro definition.
    }

    if (!BuildFromMacro(pf, exp, exp->body, std::move(body_node), err)) {
      return false;
    }
  }

  for (pasta::Macro sub_node : node.ReplacementChildren()) {
    if (!BuildFromMacro(pf, exp, exp->after, std::move(sub_node), err)) {
      return false;
    }
  }

  std::optional<pasta::DefineMacroDirective> macro_def = node.Definition();
  if (!macro_def) {
    return true;
  }

  // We might have a kind of duplicate of this expansion inside of `after`,
  // as a result of macro argument pre-expansion.
  Substitution *pre_exp = PreExpansionOf(exp);

  // Try to find the real body.
  Substitution *macro_body_sub = GetMacroBody(macro_def.value(), err);
  if (!macro_body_sub) {
    exp->after.has_error = true;
    if (auto macro_name = macro_def->Name()) {
      err << "Unable to find macro body for macro with name '"
          << macro_name->Data() << "'";
    } else {
      assert(false);
      err << "Unable to find macro body for macro that was probably not defined";
    }
    return false;
  }

  // Inherit the `after` bounds from the macro body.
  if (pre_exp) {
    if (!MergeArgPreExpansion(exp, pre_exp, err)) {
      if (auto macro_name = macro_def->Name()) {
        err << "Unable to merge argument pre-expansion with use of macro "
            << macro_name->Data() << "'";
      } else {
        assert(false);
        err << "Unable to merge argument pre-expansion with use of macro "
               "that wasn't defined?";
      }
      return false;
    }

    assert(exp->body.empty());
    exp->body = std::move(pre_exp->body);
    assert(!PreExpansionOf(exp));

    FixupNodeParents(exp);
  }

  return sub;
}

bool TokenTreeImpl::BuildMacroSubstitution(
    const PendingFragment &pf, Substitution *sub, Substitution::NodeList &nodes,
    const pasta::MacroDirective &node, std::ostream &err) {

  Substitution *dir = ShouldGoInFloatingFragment(node) ?
                      CreateDirectiveFragment(pf, node) :
                      nullptr;
  if (!dir) {
    dir = CreateSubstitution(mx::FromPasta(node.Kind()));
    dir->macro = node;

    for (pasta::Macro use_node : node.Children()) {
      if (!BuildFromMacro(pf, dir, dir->before, std::move(use_node), err)) {
        return false;
      }
    }
  }

  dir->parent = sub;
  nodes.emplace_back(dir);

  return true;
}

TokenTree::~TokenTree(void) {}

// Create a token tree from the tokens in the inclusive range
// `[begin_index, end_index]` from `range`.
std::optional<TokenTreeNodeRange> TokenTree::Create(
    const PendingFragment &pf, std::ostream &err) {

  auto impl = std::make_shared<TokenTreeImpl>();

  try {

    // Build and classify the initial list of tokens.
    auto sub = impl->BuildFromTokenList(pf, err);
    if (!sub) {
      return std::nullopt;
    }

    if (impl->has_error) {
      Die(impl.get());
      return std::nullopt;
    }

    // std::cerr << "--------------------------------------------------------\n";
    // sub->Print(std::cerr);
    // std::cerr << "\n\n\n";
    // sub->PrintDOT(std::cerr);
    // std::cerr << "\n\n";

    std::shared_ptr<const SubstitutionNodeList> ret(
        std::move(impl), &(sub->before));
    return TokenTreeNodeRange(std::move(ret));

  } catch (const char *msg) {
    err << msg;
    return std::nullopt;
  }
}

std::optional<TokenTree> TokenTreeNode::Parent(void) const noexcept {
  if (const auto &ent = (*impl)[offset];
      std::holds_alternative<TokenInfo *>(ent)) {
    auto parent = std::get<TokenInfo *>(ent)->parent;
    if (!parent || !parent->parent) {
      return std::nullopt;
    }

    return TokenTree(std::shared_ptr<const Substitution>(impl, parent));
  } else {
    return std::nullopt;
  }
}

std::optional<pasta::PrintedToken> TokenTreeNode::PrintedToken(void) const noexcept {
  if (const auto &ent = (*impl)[offset];
      std::holds_alternative<TokenInfo *>(ent)) {
    return std::get<TokenInfo *>(ent)->printed_tok;
  } else {
    return std::nullopt;
  }
}

std::optional<pasta::MacroToken> TokenTreeNode::MacroToken(void) const noexcept {
  if (const auto &ent = (*impl)[offset];
      std::holds_alternative<TokenInfo *>(ent)) {
    return std::get<TokenInfo *>(ent)->macro_tok;
  } else {
    return std::nullopt;
  }
}

std::optional<pasta::Token> TokenTreeNode::Token(void) const noexcept {
  if (const auto &ent = (*impl)[offset];
      std::holds_alternative<TokenInfo *>(ent)) {
    return std::get<TokenInfo *>(ent)->parsed_tok;
  } else {
    return std::nullopt;
  }
}

const void *TokenTreeNode::RawNode(void) const noexcept {
  const SubstitutionNode &ent = (*impl)[offset];
  return &ent;
}

std::optional<TokenTree> TokenTreeNode::SubTree(void) const noexcept {
  if (const auto &ent = (*impl)[offset];
      std::holds_alternative<Substitution *>(ent)) {
    std::shared_ptr<const Substitution> ptr(
        impl, std::get<Substitution *>(ent));
    return TokenTree(std::move(ptr));
  } else {
    return std::nullopt;
  }
}

bool TokenTreeNodeIterator::operator==(TokenTreeNodeIteratorEnd) const {
  return node.offset >= node.impl->size();
}

bool TokenTreeNodeIterator::operator!=(TokenTreeNodeIteratorEnd) const {
  return node.offset < node.impl->size();
}

// Dump.
void TokenTreeNodeRange::Dump(std::ostream &os) const {
  Substitution *root = nullptr;
  if (!begin_.node.impl) {
    return;
  }

  for (const SubstitutionNode &node : *(begin_.node.impl)) {
    if (!std::holds_alternative<Substitution *>(node)) {
      continue;
    }

    Substitution *sub = std::get<Substitution *>(node);
    while (sub) {
      root = sub;
      sub = sub->parent;
    }

    if (root) {
      break;
    }
  }

  if (root) {
    std::unique_lock<std::mutex> locker(gPrintDOTLock);
    root->PrintDOT(os);
    os.flush();
  }
}

unsigned TokenTreeNodeRange::Size(void) const noexcept {
  return static_cast<unsigned>(begin_.node.impl->size());
}

// Dump.
void TokenTree::Dump(std::ostream &os) const {
  impl->PrintDOT(os, true);
}

mx::MacroKind TokenTree::Kind(void) const noexcept {
  assert(!impl->macro || mx::FromPasta(impl->macro->Kind()) == impl->kind);
  return impl->kind;
}

std::optional<mx::PackedFragmentId>
TokenTree::NestedFragmentId(void) const noexcept {
  return impl->fragment_id; 
}

std::optional<pasta::Macro> TokenTree::Macro(void) const noexcept {
  return impl->macro;
}

std::optional<TokenTree> TokenTree::Parent(void) const noexcept {
  if (!impl->parent) {
    assert(false);  // Should never call expose the root.
    return std::nullopt;
  }

  if (!impl->parent->parent) {
    return std::nullopt; // This is the root node.
  }

  std::shared_ptr<const Substitution> ptr(impl, impl->parent);
  return TokenTree(std::move(ptr));
}

TokenTreeNodeRange TokenTree::Children(void) const noexcept {
  std::shared_ptr<const SubstitutionNodeList> ptr(impl, &(impl->before));
  return TokenTreeNodeRange(std::move(ptr));
}

TokenTreeNodeRange TokenTree::IntermediateChildren(void) const noexcept {
  std::shared_ptr<const SubstitutionNodeList> ptr(impl, &(impl->body));
  return TokenTreeNodeRange(std::move(ptr));
}

TokenTreeNodeRange TokenTree::ReplacementChildren(void) const noexcept {
  std::shared_ptr<const SubstitutionNodeList> ptr(impl, &(impl->after));
  return TokenTreeNodeRange(std::move(ptr));
}

std::optional<pasta::MacroToken>
TokenTree::FirstFullySubstitutedToken(void) const noexcept {
  if (auto lc = LeftCornerOfExp(const_cast<Substitution *>(impl.get()))) {
    if (lc->macro_tok) {
      return lc->macro_tok;
    }
  }
  return std::nullopt;
}

std::optional<pasta::MacroToken>
TokenTree::LastFullySubstitutedToken(void) const noexcept {
  if (auto rc = RightCornerOfExp(const_cast<Substitution *>(impl.get()))) {
    if (rc->macro_tok) {
      return rc->macro_tok;
    }
  }
  return std::nullopt;
}

std::optional<pasta::MacroToken> TokenTree::NameOrOperator(void) const noexcept {
  if (impl->macro) {
    if (auto sub = pasta::MacroSubstitution::From(impl->macro.value())) {
      return sub->NameOrOperator();
    }
  }
  return std::nullopt;
}

// Return whether or not this node has intermediate children.
bool TokenTree::HasIntermediateChildren(void) const noexcept {
  return Kind() == mx::MacroKind::EXPANSION;
}

bool TokenTree::HasExpansion(void) const noexcept {
  return !impl->fragment_id && impl->HasExpansion();
}

// Return the number of nodes in this tree.
unsigned TokenTree::NumChildren(void) const noexcept {
  return static_cast<unsigned>(impl->before.size());
}

// Return the number of replacement nodes in this tree.
unsigned TokenTree::NumReplacementChildren(void) const noexcept {
  return static_cast<unsigned>(impl->after.size());
}

}  // namespace indexer
