// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "TokenTree.h"

#include <cassert>
#include <deque>
#include <glog/logging.h>
#include <multiplier/Types.h>
#include <optional>
#include <pasta/AST/Forward.h>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Token.h>
#include <pasta/Util/File.h>
#include <sstream>
#include <unordered_map>
#include <vector>

#include <iostream>

//#define D(...) __VA_ARGS__
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
  enum Category : unsigned char {
    // A token, produced as a result of macro expansion, but somewhere between
    // use and parse, i.e. this is not parsed.
    //
    // NOTE(pag): This could represent an intermediate macro use.
    kMacroStepToken,

    // A parsed token, produced as a result of macro expansion.
    kMacroExpansionToken,

    // A file token, introduced because it was part of the file, and was
    // missing in the parse because it was a macro use.
    //
    // NOTE(pag): This is only for top-level uses of macros. Intermediate uses
    //            are represented as `kMacroStepToken`.
    kMacroUseToken,

    // A parsed token associated with a file token.
    kFileToken,

    // A token that wasn't parsed, e.g. due to being elided by an `#if 0`
    // conditional directive, and that we've injected back in to aid in
    // alignment with the original tokens.
    kMissingFileToken,

    // A marker token from PASTA, e.g. macro/file begin/end.
    kMarkerToken,
  };

  TokenInfo *next{nullptr};

  std::optional<pasta::Token> parsed_tok;
  std::optional<pasta::FileToken> file_tok;
  std::optional<pasta::MacroToken> macro_tok;
  Category category{kFileToken};
  bool is_va_args_concat{false};  // `, ## __VA_ARGS__`.
};

struct TokenSet {
  TokenSet *root;

  // First token info associated with this set.
  TokenInfo *info{nullptr};

  // File token associated with any parsed token in this set.
  std::optional<pasta::FileToken> file_tok;

  TokenSet(void)
      : root(this) {}

  TokenSet *Root(void) {
    if (this != root) {
      root = root->Root();
    }
    return root;
  }
};

// Represents a token substitution. This can be due to a macro expansion, or
// due to an X-macro file inclusion (i.e. where an include is nested inside
// of a declaration, and then the included file expands macros).
class Substitution {
 public:
  enum Kind {
    kFileBody,

    // An identity-like substitution that wraps around a macro argument.
    kMacroArgument,

    // Normal macro substitution kind. `before` points to a sequence of file
    // tokens, `after` points to its expansion.
    kMacroUse,
    kMacroExpansion,

    // Relates to use of `__VA_OPT__`.
    kVAOptUse,
    kVAOptArgument,
    kVAOptExpansion,

    // Some generic form of substitution, e.g. a parameter with its argument.
    kSubstitutionBefore,
    kSubstitutionAfter,

    kMacroParameterUse,
    kMacroParameterSubstitution,

    kStringifyBefore,
    kStringifyAfter,
    kConcatenateBefore,
    kConcatenateAfter,

    // An inclusion of a file nested inside of a top-level declaration, and so
    // the inclusion manifests as a kind of macro expansion.
    kInclusion,
    kDefinition,
    kDirective

  } kind;

  std::optional<pasta::MacroDirective> macro_dir;
  std::optional<pasta::MacroDefinition> macro_def;
  std::optional<pasta::MacroExpansion> macro_use;
  std::optional<pasta::MacroArgument> macro_arg;

  using Node = std::variant<TokenInfo *, Substitution *>;
  using NodeList = std::vector<Node>;

  NodeList before;

  Substitution *parent{nullptr};
  Substitution *after{nullptr};

  // A token that is logically a predecessor of `before`.
  TokenInfo *before_body{nullptr};
  TokenInfo *after_body{nullptr};

  bool is_va_args_concat{false};

  bool has_error{false};

  explicit Substitution(Kind kind_)
      : kind(kind_) {}

  TokenInfo *LeftCornerOfUse(void) const;
  TokenInfo *RightCornerOfUse(void) const;
  TokenInfo *LeftCornerOfExpansionOrUse(void) const;
  TokenInfo *RightCornerOfExpansionOrUse(void) const;

  void Print(std::ostream &os) const;
  void PrintDOT(std::ostream &os, bool first=true) const;
};

class TokenTreeImpl {
 public:
  // Backing storage for token info. Not necessarily all allocated tokens will
  // be used, but this is an upper bound on them. `deque` for pointer stability.
  std::deque<TokenInfo> tokens_alloc;

  // Backing storage for substitutions.
  std::deque<Substitution> substitutions_alloc;

  // Stack of substitutions associated with includes. When we exit a file, we
  // can set it as the `after` of the top substitution on this stack, then
  // pop it off.
  std::vector<Substitution *> includes;

  // Maps raw parsed tokens to token sets.
  std::unordered_map<const void *, TokenSet> parsed_sets;

  // Macro bodies.
  std::unordered_map<const void *, Substitution *> macro_body;

  D( std::string indent; )

  // Figure out if `node->after` looks like a macro argument pre-expansion of
  // `node`, and if so, return `node->after`, otherwise `nullptr`.
  Substitution *PreExpansionOf(Substitution *node);

  // Build an initial token info list. This contains all of the tokens that were
  // parsed, plus the file tokens that were macro uses. This does not contain
  // file tokens that were elided due to things like conditional macros, e.g.
  // `#if 0`.
  TokenInfo *BuildInitialTokenList(pasta::TokenRange range,
                                   uint64_t begin_index,
                                   uint64_t end_index,
                                   std::stringstream &err);

  bool TryFillBetweenFileTokens(
      Substitution *sub, TokenInfo *prev, TokenInfo *curr, bool &stopped_early,
      Substitution::NodeList &nodes);

  Substitution *GetMacroBody(pasta::MacroDefinition def,
                             std::stringstream &err);

  TokenInfo *TryGetBeforeToken(TokenInfo *curr);
  TokenInfo *TryGetAfterToken(TokenInfo *curr);
  void TryAddBeforeToken(Substitution *sub, TokenInfo *curr);
  void TryAddAfterToken(Substitution *sub, TokenInfo *prev);

  // Fill in the missing tokens from the token tree.
  void StripWhitespace(Substitution::NodeList &nodes);
  void HandleVAOpt(Substitution *sub, bool has_macro_token_in_arg=false);
  bool FillMissingFileTokens(Substitution *sub, std::stringstream &err);
  bool FillMissingFileTokensRec(Substitution *sub, bool &changed,
                                std::stringstream &err);

  bool FindSubstitutionBoundsRec(Substitution *sub, TokenInfo *lower_bound,
                                 TokenInfo *upper_bound);
  void FindSubstitutionBounds(void);
  Substitution *MergeArguments(Substitution *orig, Substitution *pre_arg,
                               std::stringstream &err);
  bool MergeArgPreExpansions(std::stringstream &err);
  bool MergeArgPreExpansion(Substitution *sub, Substitution *pre_exp,
                            std::stringstream &err);
  Substitution *TryInventMissingSubstitutions(
      Substitution *sub, TokenInfo *prev, Substitution::Node curr_node,
      unsigned next_index, bool &stopped_early);

  bool AddMissingPrefixes(
      Substitution *sub, TokenInfo *prev, Substitution::Node curr,
      bool &stopped_early, Substitution::NodeList &nodes,
      std::stringstream &err);

  Substitution *BuildMacroSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      std::optional<pasta::MacroToken> node, std::stringstream &err);

  Substitution *BuildMacroSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      std::optional<pasta::MacroArgument> node, std::stringstream &err);

  Substitution *BuildMacroSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      std::optional<pasta::MacroSubstitution> node, std::stringstream &err);

  Substitution *BuildMacroSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      std::optional<pasta::MacroExpansion> node, std::stringstream &err);

  Substitution *BuildMacroSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      std::optional<pasta::MacroDirective> node, std::stringstream &err);

  Substitution *BuildMacroSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      std::optional<pasta::MacroFileInclusion> node, std::stringstream &err);

  Substitution *BuildMacroSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      std::optional<pasta::MacroDefinition> node, std::stringstream &err);

  Substitution *BuildMacroSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      pasta::MacroNode node, std::stringstream &err);

  Substitution *BuildMacroSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      std::stringstream &err);

  Substitution *BuildFileSubstitutions(
      TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
      std::stringstream &err);

  Substitution *BuildSubstitutions(TokenInfo *&prev, TokenInfo *&curr,
                                   std::stringstream &err);

  Substitution *BuildSubstitutions(std::stringstream &err);

  Substitution *CreateSubstitution(Substitution::Kind kind);

  void FinalizeParameters(
      Substitution *sub,
      const std::unordered_map<std::string,
                               Substitution::NodeList> &params);

  static bool BoundsAreSane(const Substitution *sub);
  void AddOrClearInsaneBounds(Substitution *sub);

  // Try to unify tokens in the token list back to the same file token.
  void UnifyTokens(void);
  TokenSet *UnifyToken(TokenInfo *tok);
  TokenSet *Root(TokenInfo *tok);
};

static void Die(const TokenTreeImpl *impl) {
  std::unique_lock<std::mutex> locker(gPrintDOTLock);
  impl->substitutions_alloc.front().PrintDOT(std::cerr);
  std::cerr.flush();
  TT_ASSERT(false);
}

bool TokenTreeImpl::BoundsAreSane(const Substitution *sub) {
  if (!sub->before_body != !sub->after_body) {
    return false;
  }

  if (!sub->before_body || !sub->after_body) {
    return true;
  }

  if (!sub->before_body->file_tok != !sub->after_body->file_tok) {
    return false;
  }

  if (!sub->before_body->file_tok || !sub->after_body->file_tok) {
    return true;
  }

  if (pasta::File::Containing(sub->before_body->file_tok.value()) !=
      pasta::File::Containing(sub->after_body->file_tok.value())) {
    return false;
  }

  return sub->after_body->file_tok->Index() >
         sub->before_body->file_tok->Index();
}

void TokenTreeImpl::AddOrClearInsaneBounds(Substitution *sub) {
  bool retry = false;
  if (!sub->before_body) {
    TryAddBeforeToken(sub, sub->LeftCornerOfUse());
  } else {
    retry = true;
  }
  if (!sub->after_body) {
    TryAddAfterToken(sub, sub->RightCornerOfUse());
  } else {
    retry = true;
  }

  if (BoundsAreSane(sub)) {
    return;
  }

  sub->before_body = nullptr;
  sub->after_body = nullptr;

  if (!retry) {
    return;
  }

  TryAddBeforeToken(sub, sub->LeftCornerOfUse());
  TryAddAfterToken(sub, sub->RightCornerOfUse());

  if (!BoundsAreSane(sub)) {
    sub->before_body = nullptr;
    sub->after_body = nullptr;
  }
}

static void CollectUseTokensInto(
    const Substitution::NodeList &in, Substitution::NodeList &out) {
  for (Substitution::Node node : in) {
    if (std::holds_alternative<Substitution *>(node)) {
      CollectUseTokensInto(std::get<Substitution *>(node)->before, out);
    } else {
      out.emplace_back(std::move(node));
    }
  }
}

static void CollectUseTokensInto(
    const Substitution::NodeList &nodes, Substitution *sub) {
  CollectUseTokensInto(nodes, sub->before);
}

static bool InBeforeRestrictedRec(const Substitution *sub) {
  switch (sub->kind) {
    case Substitution::kMacroArgument:
    case Substitution::kVAOptUse:
    case Substitution::kVAOptArgument:
    case Substitution::kInclusion:
    case Substitution::kDefinition:
    case Substitution::kDirective:
      return true;
    case Substitution::kMacroExpansion:
    case Substitution::kVAOptExpansion:
    case Substitution::kSubstitutionAfter:
      return false;
    default:
      if (!sub->parent) {
        return false;
      } else {
        return InBeforeRestrictedRec(sub->parent);
      }
  }
}

static bool InBefore(const Substitution *sub) {
  // Figure out if we can bring in arbitrary tokens, or mostly just whitespace.
  switch (sub->kind) {
    case Substitution::kFileBody:
    case Substitution::kMacroUse:
    case Substitution::kMacroArgument:
    case Substitution::kMacroExpansion:
    case Substitution::kSubstitutionBefore:
    case Substitution::kVAOptUse:
    case Substitution::kVAOptArgument:
    case Substitution::kInclusion:
    case Substitution::kDefinition:
    case Substitution::kDirective:
      return true;
    default:
      break;
  }

  if (!sub->parent) {
    return false;
  }

  TT_ASSERT(sub->parent != sub);

  if (sub->parent->after == sub) {
    return InBeforeRestrictedRec(sub->parent);
  } else {
    return InBefore(sub->parent);
  }
}

template <typename T>
static std::string TokData(const T &tok) {
  switch (tok.Kind()) {
    case pasta::TokenKind::kComment:
      return "&lt;comment&gt;";
    case pasta::TokenKind::kUnknown:
      return "&lt;unk&gt;";
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
      default: ss << ch; break;
    }
  }
  return ss.str();
}

static void FixupNodeParents(Substitution *sub) {
  TT_ASSERT(!sub->parent || sub != sub->parent);
  if (sub->after) {
    TT_ASSERT(sub->after != sub);
    sub->after->parent = sub;
  }
  for (Substitution::Node &node : sub->before) {
    if (std::holds_alternative<Substitution *>(node)) {
      Substitution *child_sub = std::get<Substitution *>(node);
      TT_ASSERT(child_sub != sub);
      child_sub->parent = sub;
    }
  }
}

static TokenInfo *LeftCornerOfUse(Substitution::Node node) {
  if (std::holds_alternative<TokenInfo *>(node)) {
    return std::get<TokenInfo *>(node);
  } else if (auto tok = std::get<Substitution *>(node)->LeftCornerOfUse()) {
    return tok;
  }
  return nullptr;
}

static TokenInfo *RightCornerOfUse(Substitution::Node node) {
  if (std::holds_alternative<TokenInfo *>(node)) {
    return std::get<TokenInfo *>(node);
  } else if (auto tok = std::get<Substitution *>(node)->RightCornerOfUse()) {
    return tok;
  }
  return nullptr;
}

static TokenInfo *RightCornerOfUse(
    const Substitution::NodeList &before) {
  auto it = before.rbegin();
  auto end = before.rend();
  for (; it != end; ++it) {
    if (auto rc = ::indexer::RightCornerOfUse(*it)) {
      return rc;
    }
  }
  return nullptr;
}

static TokenInfo *LeftCornerOfExpansionOrUse(Substitution::Node node) {
  if (std::holds_alternative<TokenInfo *>(node)) {
    return std::get<TokenInfo *>(node);
  } else if (auto sub = std::get<Substitution *>(node)) {
    return sub->LeftCornerOfExpansionOrUse();
  }
  return nullptr;
}

static TokenInfo *RightCornerOfExpansionOrUse(Substitution::Node node) {
  if (std::holds_alternative<TokenInfo *>(node)) {
    return std::get<TokenInfo *>(node);
  } else if (auto sub = std::get<Substitution *>(node)) {
    return sub->RightCornerOfExpansionOrUse();
  }
  return nullptr;
}

// Figure out if `node->after` looks like a macro argument pre-expansion of
// `node`, and if so, return `node->after`, otherwise `nullptr`.
Substitution *TokenTreeImpl::PreExpansionOf(Substitution *node) {
  if (node->kind != Substitution::kMacroUse || !node->macro_def) {
    return nullptr;
  }

  if (!node->after || node->after->kind != Substitution::kMacroExpansion ||
      node->after->before.size() != 1u || node->after->after ||
      !std::holds_alternative<Substitution *>(node->after->before[0])) {
    return nullptr;
  }

  auto sub_exp = std::get<Substitution *>(node->after->before[0]);
  if (sub_exp->kind != Substitution::kMacroUse) {
    return nullptr;
  }

  if (node->macro_def.has_value() != sub_exp->macro_def.has_value()) {
    return nullptr;
  }

  if (node->macro_def &&
      node->macro_def->RawNode() != sub_exp->macro_def->RawNode()) {
    return nullptr;
  }

  TokenInfo *macro_name = LeftCornerOfUse(node);
  TokenInfo *exp_macro_name = LeftCornerOfUse(sub_exp);

  (void) Root(macro_name);
  (void) Root(exp_macro_name);

  return sub_exp;
}

TokenInfo *Substitution::LeftCornerOfUse(void) const {
  for (Substitution::Node ent : before) {
    if (auto lc = ::indexer::LeftCornerOfUse(std::move(ent))) {
      return lc;
    }
  }
  return nullptr;
}

TokenInfo *Substitution::RightCornerOfUse(void) const {
  return ::indexer::RightCornerOfUse(before);
}

TokenInfo *Substitution::LeftCornerOfExpansionOrUse(void) const {
  if (after) {
    return after->LeftCornerOfExpansionOrUse();
  } else {
    auto it = before.rbegin();
    auto end = before.rend();
    for (; it != end; ++it) {
      if (auto rc = ::indexer::LeftCornerOfExpansionOrUse(*it)) {
        return rc;
      }
    }
    return nullptr;
  }
}

TokenInfo *Substitution::RightCornerOfExpansionOrUse(void) const {
  if (after) {
    return after->RightCornerOfExpansionOrUse();
  } else {
    auto it = before.rbegin();
    auto end = before.rend();
    for (; it != end; ++it) {
      if (auto rc = ::indexer::RightCornerOfExpansionOrUse(*it)) {
        return rc;
      }
    }
    return nullptr;
  }
}

void Substitution::Print(std::ostream &os) const {
  if (before.empty()) {
//    TT_ASSERT(!after);
  }

  auto tok_data = [] (TokenInfo *info) -> std::string_view {
    std::string_view a, b, c;
    if (info->parsed_tok) {
      a = info->parsed_tok->Data();
    }
    if (info->macro_tok) {
      b = info->macro_tok->Data();
    }
    if (info->file_tok) {
      c = info->file_tok->Data();
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
      TT_ASSERT(false);
      return {};
    }
  };

  for (auto ent : before) {
    if (std::holds_alternative<TokenInfo *>(ent)) {
      auto info = std::get<TokenInfo *>(ent);
      switch (info->category) {
        case TokenInfo::kFileToken:
          std::cerr << tok_data(info);
          continue;
        case TokenInfo::kMacroUseToken:
        case TokenInfo::kMissingFileToken:
        case TokenInfo::kMacroStepToken:
        case TokenInfo::kMacroExpansionToken:
        case TokenInfo::kMarkerToken:
          std::cerr << "\033[4m" << tok_data(info) << "\033[0m";
          continue;
        default:
          continue;
      }
    } else {
      std::get<Substitution *>(ent)->Print(os);
    }
  }
}

void Substitution::PrintDOT(std::ostream &os, bool first) const {
  if (first) {
    os << "digraph {\n"
       << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";
  }

  if (after) {
    after->PrintDOT(os, false);
  }

  auto num_cols = before.size();
  if (before_body && before_body->file_tok) {
    ++num_cols;
  }
  if (after_body && after_body->file_tok) {
    ++num_cols;
  }

  os << "s" << reinterpret_cast<const void *>(this)
     << " [label=<<TABLE cellpadding=\"0\" cellspacing=\"0\" border=\"1\"";
  if (has_error) {
    os << " bgcolor=\"red\"";
  }
  if (InBefore(this)) {
    os << " color=\"brown\"";
  }
  os << "><TR><TD colspan=\"" << num_cols << "\">";
  switch (kind) {
    case kFileBody: os << "file body"; break;
    case kMacroArgument: os << "macro arg"; break;
    case kMacroUse: os << "macro use"; break;
    case kMacroExpansion: os << "macro exp"; break;
    case kVAOptUse: os << "va opt use"; break;
    case kVAOptArgument: os << "va opt arg"; break;
    case kVAOptExpansion: os << "va opt exp"; break;
    case kSubstitutionBefore: os << "sub before"; break;
    case kSubstitutionAfter: os << "sub after"; break;
    case kMacroParameterUse: os << "param use"; break;
    case kMacroParameterSubstitution: os << "param sub"; break;
    case kStringifyBefore: os << "string use"; break;
    case kStringifyAfter: os << "string sub"; break;
    case kConcatenateBefore: os << "concat use"; break;
    case kConcatenateAfter: os << "concat sub"; break;
    case kInclusion: os << "include"; break;
    case kDefinition: os << "define"; break;
    case kDirective: os << "directive"; break;
  }

  if (macro_def) {
    os << " def=" << macro_def->NameToken().Data() << '='
       << reinterpret_cast<uintptr_t>(macro_def->RawNode());
  }

  if (macro_use) {
    os << " use=" << reinterpret_cast<uintptr_t>(macro_use->RawNode());
  }

  os << "</TD></TR><TR>";

  if (before_body && before_body->file_tok) {
    os << "<TD>" << before_body->file_tok->Index() << "</TD>";
  }

  auto has_any = false;

  auto dump_tok = [&] (TokenInfo *info) {
    os << "<TD><TABLE cellpadding=\"0\" cellspacing=\"0\" border=\"0\">";
    if (info->file_tok) {
      os << "<TR><TD>FK=" << info->file_tok->KindName() << "</TD></TR>";
    }
    if (info->macro_tok) {
      os << "<TR><TD>MK=" << info->macro_tok->TokenKindName() << "</TD></TR>";
    }
    if (info->parsed_tok) {
      os << "<TR><TD>PK=" << info->parsed_tok->KindName() << "</TD></TR>";
      os << "<TR><TD>PI=" << info->parsed_tok->Index() << "</TD></TR>";
    }
    if (info->file_tok) {
      os << "<TR><TD>FI=" << info->file_tok->Index() << "</TD></TR>";
    }

    if (info->parsed_tok) {
      os << "<TR><TD><B>" << TokData(info->parsed_tok.value()) << "</B></TD></TR>";
    } else if (info->file_tok) {
      os << "<TR><TD><B>" << TokData(info->file_tok.value()) << "</B></TD></TR>";
    } else {
      os << "<TR><TD><FONT COLOR=\"red\">? ? ?</FONT></TD></TR>";
    }
    os << "</TABLE></TD>";
    has_any = true;
  };

  auto i = 0;
  for (auto ent : before) {
    if (std::holds_alternative<TokenInfo *>(ent)) {
      auto info = std::get<TokenInfo *>(ent);
      switch (info->category) {
        case TokenInfo::kFileToken:
        case TokenInfo::kMacroUseToken:
        case TokenInfo::kMissingFileToken:
        case TokenInfo::kMacroStepToken:
        case TokenInfo::kMacroExpansionToken:
          dump_tok(info);
          continue;
        case TokenInfo::kMarkerToken:
        default:
          continue;
      }
    } else {
      os << "<TD port=\"s" << (i++) << "\"> </TD>";
      has_any = true;
    }
  }

  if (!has_any && !num_cols) {
    os << "<TD> </TD>";
  }

  if (after_body && after_body->file_tok) {
    os << "<TD>" << after_body->file_tok->Index() << "</TD>";
  }

  os << "</TR></TABLE>>];\n";

  i = 0;
  for (auto ent : before) {
    if (std::holds_alternative<Substitution *>(ent)) {
      auto s = std::get<Substitution *>(ent);
      s->PrintDOT(os, false);

      if (s->after) {
        os << "s" << reinterpret_cast<const void *>(this)
           << ":s" << i << " -> s"
           << reinterpret_cast<const void *>(s) << " [label=\"before\"];\n"
           << "s" << reinterpret_cast<const void *>(this)
           << ":s" << i << " -> s"
           << reinterpret_cast<const void *>(s->after)
           << " [label=\"after\"];\n";
      } else {
        os << "s" << reinterpret_cast<const void *>(this)
           << ":s" << i << " -> s"
           << reinterpret_cast<const void *>(s) << ";\n";
      }

      ++i;
    }
  }

  if (first) {
    os << "}\n\n";
  }
}

static void ResolveFileLocation(TokenInfo *info) {
  for (auto pt = info->parsed_tok; pt && !info->file_tok;
       pt = pt->DerivedLocation()) {
    if (auto mt = pt->MacroLocation()) {
      info->file_tok = mt->FileLocation();
    } else {
      info->file_tok = pt->FileLocation();
    }
  }
  if (info->parsed_tok && info->parsed_tok->Index() == 2408) {
    TT_ASSERT(info->file_tok.has_value());
  }
}

// Build an initial token info list. This contains all of the tokens that were
// parsed, plus the file tokens that were macro uses. This does not contain
// file tokens that were elided due to things like conditional macros, e.g.
// `#if 0`.
TokenInfo *TokenTreeImpl::BuildInitialTokenList(pasta::TokenRange range,
                                                uint64_t begin_index,
                                                uint64_t end_index,
                                                std::stringstream &err) {
  int macro_depth = 0;
  TokenInfo *last_macro_use_token = nullptr;

  for (auto i = begin_index; i <= end_index; ++i) {
    pasta::Token tok = range[i];
    switch (tok.Role()) {
      default:
      case pasta::TokenRole::kInvalid:
        err << "Invalid or unexpected token in range";
        return nullptr;

      case pasta::TokenRole::kBeginOfMacroExpansionMarker: {
        TT_ASSERT(!last_macro_use_token);
        TT_ASSERT(tok.FileLocation().has_value());
        TokenInfo &info = tokens_alloc.emplace_back();
        info.file_tok = tok.FileLocation();
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kMarkerToken;
        last_macro_use_token = &info;
        ++macro_depth;
        continue;
      }

      case pasta::TokenRole::kEndOfMacroExpansionMarker: {
        TT_ASSERT(last_macro_use_token != nullptr);
        TokenInfo &info = tokens_alloc.emplace_back();
        pasta::File file = pasta::File::Containing(
            last_macro_use_token->file_tok.value());
        info.file_tok = file.Tokens().At(
            last_macro_use_token->file_tok->Index() + 1u);
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kMarkerToken;
        last_macro_use_token = nullptr;
        --macro_depth;
        TT_ASSERT(0 <= macro_depth);
        continue;
      }

      case pasta::TokenRole::kInitialMacroUseToken: {
        TT_ASSERT(0 < macro_depth);
        TT_ASSERT(last_macro_use_token != nullptr);
        TokenInfo &info = tokens_alloc.emplace_back();
        info.macro_tok = tok.MacroLocation();
        info.category = TokenInfo::kMacroUseToken;
        info.file_tok = tok.FileLocation();
        TT_ASSERT(info.macro_tok.has_value());
        info.parsed_tok = std::move(tok);
        ResolveFileLocation(&info);
        last_macro_use_token = &info;
        continue;
      }

      case pasta::TokenRole::kIntermediateMacroExpansionToken: {
        TT_ASSERT(0 < macro_depth);
        TT_ASSERT(last_macro_use_token != nullptr);
        TokenInfo &info = tokens_alloc.emplace_back();
        info.macro_tok = tok.MacroLocation();
        info.category = TokenInfo::kMacroStepToken;
        info.file_tok = tok.FileLocation();
        TT_ASSERT(info.macro_tok.has_value());
        info.parsed_tok = std::move(tok);
        ResolveFileLocation(&info);
        continue;
      }

      case pasta::TokenRole::kFinalMacroExpansionToken: {
        TT_ASSERT(0 < macro_depth);
        TT_ASSERT(last_macro_use_token != nullptr);
        TokenInfo &info = tokens_alloc.emplace_back();
        info.file_tok = tok.FileLocation();
        info.macro_tok = tok.MacroLocation();
        TT_ASSERT(info.macro_tok.has_value());
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kMacroExpansionToken;
        ResolveFileLocation(&info);
        continue;
      }

      case pasta::TokenRole::kBeginOfFileMarker:
      case pasta::TokenRole::kEndOfFileMarker: {
        TT_ASSERT(!last_macro_use_token);
        TT_ASSERT(tok.FileLocation().has_value());
        TokenInfo &info = tokens_alloc.emplace_back();
        info.file_tok = tok.FileLocation();
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kMarkerToken;
        continue;
      }

      case pasta::TokenRole::kFileToken: {
        TT_ASSERT(!macro_depth);
        TT_ASSERT(!last_macro_use_token);
        auto &info = tokens_alloc.emplace_back();
        info.file_tok = tok.FileLocation();
        TT_ASSERT(info.file_tok.has_value());
        TT_ASSERT(info.file_tok->Data() == tok.Data());
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kFileToken;
        continue;
      }
    }
  }

  // Link all of the tokens together.
  if (auto num_toks = tokens_alloc.size()) {
    for (auto i = 1ull, j = 0ull; i < num_toks; ++i, ++j) {
      tokens_alloc[j].next = &(tokens_alloc[i]);
    }

    return &(tokens_alloc.front());
  }

  err << "Cannot create token tree from empty token range";
  return nullptr;
}

Substitution *TokenTreeImpl::CreateSubstitution(Substitution::Kind kind) {
  return &(substitutions_alloc.emplace_back(kind));
}

static pasta::MacroNode RootNodeFrom(pasta::MacroNode node) {
  if (auto parent = node.Parent()) {
    return RootNodeFrom(parent.value());
  } else {
    return node;
  }
}

// `nodes` are the new nodes for `sub`.
bool TokenTreeImpl::TryFillBetweenFileTokens(
    Substitution *sub, TokenInfo *prev, TokenInfo *curr, bool &stopped_early,
    Substitution::NodeList &nodes) {

  if (!curr || !prev->file_tok || !curr->file_tok) {
    return false;
  }

  const bool in_before = InBefore(sub);

  TokenInfo * const min = sub->before_body;
  TokenInfo * const max = sub->after_body;

  if (!min || !min->file_tok || !max || !max->file_tok) {
    return false;
  }

  const pasta::FileToken prev_file_tok = prev->file_tok.value();
  const pasta::FileToken curr_file_tok = curr->file_tok.value();
  const pasta::File prev_file = pasta::File::Containing(prev_file_tok);
  const pasta::File curr_file = pasta::File::Containing(curr_file_tok);

  if (prev_file != curr_file ||
      prev_file != pasta::File::Containing(min->file_tok.value()) ||
      prev_file != pasta::File::Containing(max->file_tok.value())) {
    D( std::cerr << indent << "can't fill from two different files\n"; )
    return false;
  }

  const auto prev_i = prev_file_tok.Index();
  auto curr_i = curr_file_tok.Index();

  if (prev_i >= curr_i) {
    D( std::cerr << indent << "can't fill: prev_i=" << prev_i
                 << " >= curr_i=" << curr_i << "\n"; )
    return false;
  }

  const auto min_i = min->file_tok->Index();
  const auto max_i = max->file_tok->Index();
  TT_ASSERT(min_i <= max_i);

  // The range must not straddle the range of the stuff into which we're
  // injecting. It should either be in range, or out of range.
  if (prev_i < min_i && curr_i <= max_i) {
    D( std::cerr << indent << "can't straddle: prev_i=" << prev_i
                 << " < min_i=" << min_i << ", curr_i=" << curr_i
                 << " <= max_i=" << max_i << "\n"; )
    return false;
  }

  if (min_i <= prev_i && max_i < curr_i) {
    D( std::cerr << indent << "can't straddle: min_i=" << min_i
                 << " <= prev_i=" << prev_i << ", max_i=" << max_i
                 << " < curr_i=" << curr_i << "\n"; )
    return false;
  }

  pasta::FileTokenRange tokens = prev_file.Tokens();
  auto i = prev_i + 1u;  // `prev` is already present.
  bool seen_pound = false;
  bool prev_was_space = true;
  bool seen_ident = false;
  int paren_count = 0;
  bool in_va_opt = false;
  D( std::cerr << indent << "FillBetweenFileTokensInSameFile(" << i << ", "
               << curr_i << "; min_i=" << min_i << ", max_i=" << max_i
               << ")\n"; )

  const auto orig_end_i = curr_i;
  bool changed = false;
  bool comma_pound_vaarg = false;
  pasta::TokenKind ftk = prev_file_tok.Kind();
  pasta::TokenKind prev_ftk = pasta::TokenKind::kUnknown;
  for (; i < curr_i; ++i) {

    if (ftk != pasta::TokenKind::kUnknown) {
      prev_ftk = ftk;
    }

    pasta::FileToken ft = tokens[i];
    ftk = ft.Kind();

    // State machine to figure out if we need to stop early.
    switch (ftk) {
      case pasta::TokenKind::kHashHash:
        if (prev_ftk == pasta::TokenKind::kComma) {
          comma_pound_vaarg = true;
        }
        [[fallthrough]];
      case pasta::TokenKind::kHash:
        if (!in_before) {
          goto exit_loop;
        }
        D( std::cerr << indent << "seen pound (" << ft.Index() << ")\n"; )
        if (seen_pound) {
          goto exit_loop;
        }
        seen_ident = false;
        prev_was_space = false;
        seen_pound = true;
        goto keep_going;
      case pasta::TokenKind::kLParenthesis:
        if (!in_before) {
          goto exit_loop;

        } else if (in_va_opt) {
          ++paren_count;
          goto keep_going;

        } else if (prev_was_space && seen_ident) {
          D( std::cerr << indent << "Prev was space and seen ident\n"; )
          goto exit_loop;

        // Treat these like identifiers.
        } else {
          seen_ident = true;
          prev_was_space = true;
          goto keep_going;
        }
      case pasta::TokenKind::kRParenthesis:
        if (!in_before) {
          goto exit_loop;
        }
        seen_ident = false;
        prev_was_space = false;
        if (in_va_opt) {
          if (!--paren_count) {
            curr_i = (i + 1u);  // Stop before next iteration.
          }
          goto keep_going;

        } else if (prev_was_space && seen_ident) {
          D( std::cerr << indent << "Prev was space and seen ident\n"; )
          goto exit_loop;

        // Treat these like identifiers and spaces.
        } else {
          seen_ident = true;
          prev_was_space = true;
          goto keep_going;
        }
      // E.g. `4_WITH_CHECK` from MonetDB.
      case pasta::TokenKind::kNumericConstant:
      case pasta::TokenKind::kIdentifier:
      case pasta::TokenKind::kRawIdentifier: {
        if (!in_before) {
          goto exit_loop;
        }
        auto ft_data = ft.Data();
        if (ft_data == "__VA_OPT__" &&
            (seen_pound || !(prev_was_space && seen_ident))) {
          D( std::cerr << indent << "Disabling pound on " << ft_data << "\n"; )
          seen_pound = false;
          in_va_opt = true;
          seen_ident = false;

        } else if (seen_pound) {
          curr_i = (i + 1u);  // Stop before next iteration.

        } else if (prev_was_space && seen_ident) {
          D( std::cerr << indent << "Prev was space and seen ident\n"; )
          goto exit_loop;
        } else {
          D( std::cerr << indent << "seen ident (" << ft.Index() << "): "
                       << ft_data << '\n'; )
          seen_ident = true;
          prev_was_space = false;
        }
        goto keep_going;
      }
      case pasta::TokenKind::kUnknown:
      case pasta::TokenKind::kEndOfFile:
      case pasta::TokenKind::kEndOfDirective:
        D( std::cerr << indent << "seen space (" << ft.Index() << ")\n"; )
        prev_was_space = true;
        goto keep_going;
      default:
        if (!in_before) {
          goto exit_loop;

        } else if (seen_pound) {
          D( std::cerr << indent << "At space, Seen pound\n"; )
          sub->has_error = true;
          Die(this);
          return false;  // Used to be `goto exit_loop`.

        } else if (prev_was_space && seen_ident) {
          D( std::cerr << indent << "Prev was space and seen ident\n"; )
          goto exit_loop;

        } else {
          prev_was_space = false;
          seen_ident = false;
          goto keep_going;
        }
    }

  exit_loop:
    break;

  keep_going:

    // If we're adding tokens to a file level substitution, then we should only
    // really be adding whitespace. Everything else should get added into some
    // other kind of substitution.
    if (sub->kind == Substitution::kFileBody) {
      switch (ftk) {
        default:
          D( std::cerr
              << indent << "NOT adding token (" << i << ") to file level: "
              << ft.KindName() << ' ' << ft.Data() << '\n'; )
          goto exit_loop;
        case pasta::TokenKind::kUnknown:
        case pasta::TokenKind::kEndOfFile:
        case pasta::TokenKind::kEndOfDirective:
          break;
      }
    }

    // TODO(pag): Consider expanding `__VA_ARGS__` and other parameters
    //            to make their substitutions explicit.

    TokenInfo &info = tokens_alloc.emplace_back();
    info.file_tok = std::move(ft);
    D( std::cerr
        << indent << "Adding token (" << i << "): "
        << info.file_tok->KindName() << ' ' << info.file_tok->Data() << '\n'; )
    info.category = TokenInfo::kMissingFileToken;
    info.next = curr;
    prev->next = &info;
    prev = &info;
    UnifyToken(&info);
    nodes.emplace_back(&info);

    if (comma_pound_vaarg) {
      D( std::cerr << indent << "  is __VA_ARGS__ concat\n"; )
      info.is_va_args_concat = true;
    }

    switch (info.file_tok->Kind()) {
      case pasta::TokenKind::kUnknown:
      case pasta::TokenKind::kEndOfFile:
      case pasta::TokenKind::kEndOfDirective:
        break;
      default:
        changed = true;
        break;
    }
  }

  if (i != orig_end_i && changed) {
    D( std::cerr << indent << "Stopped early at i=" << i << " curr_i="
                 << orig_end_i << '\n'; )
    stopped_early = true;
  }

  return true;
}

static std::optional<unsigned> NextFromSameFile(
    Substitution *sub, unsigned i) {
  std::optional<pasta::FileToken> sub_bb;
  std::optional<pasta::FileToken> sub_ab;

  if (sub->before_body) {
    sub_bb = sub->before_body->file_tok;
  } else {
    return std::nullopt;
  }

  if (sub->after_body) {
    sub_ab = sub->after_body->file_tok;
  } else {
    return std::nullopt;
  }

  TokenInfo *next = nullptr;
  const size_t num_nodes = sub->before.size();

  for (; i < num_nodes; ++i) {
    next = LeftCornerOfUse(sub->before[i]);
    if (!next || !next->file_tok) {
      continue;
    }

    pasta::File next_file = pasta::File::Containing(next->file_tok.value());

    if (sub_bb &&
        ((sub_bb->Index() > next->file_tok->Index()) ||
         (next_file != pasta::File::Containing(sub_bb.value())))) {
      continue;
    }

    if (sub_ab &&
        ((sub_ab->Index() < next->file_tok->Index()) ||
         (next_file != pasta::File::Containing(sub_ab.value())))) {
      continue;
    }

    break;
  }

  if (!next) {
    return std::nullopt;
  }

  return i;
}

Substitution *TokenTreeImpl::TryInventMissingSubstitutions(
    Substitution *sub, TokenInfo *prev, Substitution::Node curr_node,
    unsigned next_index, bool &stopped_early) {

  std::optional<unsigned> next_i = NextFromSameFile(sub, next_index);
  if (!next_i) {
    D( std::cerr << indent << "No next token in same file\n"; )
    return nullptr;
  } else if (next_i.value() >= sub->before.size()) {
    D( std::cerr << indent << "Out-of-bounds token in same file: next_i="
        << next_i.value() << " before.size=" << sub->before.size() << '\n'; )
    return nullptr;
  }

  TokenInfo *next = LeftCornerOfUse(sub->before[next_i.value()]);
  if (!next || !next->file_tok) {
    return nullptr;
  }

  D( std::cerr
      << indent << "Next in same file (" << next->file_tok->Index() << "): "
      << next->file_tok->Data() << '\n'; )

  Substitution::NodeList missing_nodes;
  bool sub_stopped_early = false;
  if (!TryFillBetweenFileTokens(sub, prev, next, sub_stopped_early,
                                missing_nodes)) {
    return nullptr;
  }

  StripWhitespace(missing_nodes);

  // Nothing to substitute. Can happen with things like the `#` before an
  // `include`.
  if (missing_nodes.empty()) {
    D( std::cerr << indent << "Ignoring empty substitution\n"; )
    return nullptr;
  }

  D( std::cerr << indent << "Inventing missing substitution\n"; )
  Substitution *new_sub = CreateSubstitution(Substitution::kSubstitutionBefore);
  Substitution *new_exp = CreateSubstitution(Substitution::kSubstitutionAfter);

  new_exp->parent = new_sub;
  new_exp->before.emplace_back(std::move(curr_node));

  new_sub->parent = sub;
  new_sub->after = new_exp;
  new_sub->before = std::move(missing_nodes);

  FixupNodeParents(new_exp);
  FixupNodeParents(new_sub);

  if (sub_stopped_early) {
    stopped_early = true;
  }

  return new_sub;
}

bool TokenTreeImpl::AddMissingPrefixes(
    Substitution *sub, TokenInfo *prev, Substitution::Node curr_node,
    bool &stopped_early, Substitution::NodeList &nodes,
    std::stringstream &err) {

  TokenInfo *curr = LeftCornerOfUse(curr_node);
  if (!curr) {
    D( std::cerr << indent << "no left corner of use\n"; )
    return true;
  }

  if (curr->file_tok) {
    D( std::cerr
        << indent << "left corner of substitution ("
        << curr->file_tok->Index() << "): "
        << curr->file_tok->Data() << '\n'; )
  }

  if (TryFillBetweenFileTokens(sub, prev, curr, stopped_early, nodes)) {
    D( std::cerr << indent << "filled between file tokens\n"; )
    return true;
  }

  return false;
}

static Substitution *MacroArgument(Substitution::Node node) {
  if (std::holds_alternative<Substitution *>(node)) {
    auto sub = std::get<Substitution *>(node);
    if (sub->kind == Substitution::kMacroArgument) {
      return sub;
    }
  }
  return nullptr;
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
// Then tings like `another_macro` and the `#if` will be present in `orig` but
// not in `pre_exp`.
Substitution *TokenTreeImpl::MergeArguments(
    Substitution *orig, Substitution *pre_exp, std::stringstream &err) {
  TT_ASSERT(orig->macro_arg->Index() == pre_exp->macro_arg->Index());

  pre_exp->parent = orig->parent;
  pre_exp->before_body = orig->before_body;
  pre_exp->after_body = orig->after_body;

  orig->before_body = nullptr;
  orig->after_body = nullptr;
  orig->parent = nullptr;
  orig->after = nullptr;
  orig->before.clear();

  D( std::cerr << indent << "Merging argument and pre-expansion argument\n"; )
  return pre_exp;
}

bool TokenTreeImpl::MergeArgPreExpansions(std::stringstream &err) {
  auto max_i = substitutions_alloc.size();
  for (auto i = 0u; i < max_i; ++i) {
    Substitution *sub = &(substitutions_alloc[i]);
    Substitution *pre_exp = PreExpansionOf(sub);
    if (!pre_exp) {
      continue;
    }

    // Try to merge a pre-argument expansion.
    D( std::cerr << indent << "Merging pre-expansion " << pre_exp->macro_def->NameToken().Data() << '\n'; )
    if (MergeArgPreExpansion(sub, pre_exp, err)) {
      TT_ASSERT(!PreExpansionOf(sub));
    } else {
      err << "Unable to merge pre-argument expansion with macro use";
      return false;
    }
  }

  return true;
}

// Tries to unify a macro use with its pre-expansion phase, so that we don't
// doubly count macro uses in the indexer, and so that pre-expansions aren't
// presented in a confusing way.
bool TokenTreeImpl::MergeArgPreExpansion(Substitution *sub,
                                         Substitution *pre_exp,
                                         std::stringstream &err) {

  D( std::cerr << indent << "Merge pre expansion\n"; )
  D( indent += "  "; )

  Substitution::NodeList new_nodes;
  auto i = 0u;
  auto j = 0u;
  const auto max_i = sub->before.size();
  const auto max_j = pre_exp->before.size();

  auto num_i_args = 0u;
  auto num_j_args = 0u;
  auto changed = true;

//  TokenInfo *i_lc = nullptr;
  TokenInfo *i_rc = nullptr;
  TokenInfo *j_lc = nullptr;
  Substitution *i_arg = nullptr;
  Substitution *j_arg = nullptr;

  while (i < max_i && j < max_j && changed) {

    changed = false;
    Substitution::Node node_i = sub->before[i];
    Substitution::Node node_j = pre_exp->before[j];

    const auto i_is_tok = std::holds_alternative<TokenInfo *>(node_i);
//    i_lc = LeftCornerOfExpansionOrUse(node_i);
    i_rc = RightCornerOfExpansionOrUse(node_i);
    i_arg = MacroArgument(node_i);

    const auto j_is_tok = std::holds_alternative<TokenInfo *>(node_j);
    j_lc = LeftCornerOfUse(node_j);
    j_arg = MacroArgument(node_j);

    D(
      std::cerr
          << indent << "i=" << i << " j=" << j << " i_is_tok=" << i_is_tok
          << " j_is_tok=" << j_is_tok <<  " i_arg=" << (!!i_arg) << " j_arg="
          << (!!j_arg);

      if (i_rc && i_rc->file_tok) {
        std::cerr << " i_rc=" << i_rc->file_tok->Data();
      }

      if (j_lc && j_lc->file_tok) {
        std::cerr << " j_lc=" << j_lc->file_tok->Data();
      }

      std::cerr << '\n';
    )

    // Deal with things like injected whitespace.
    if (i_is_tok) {
      if (i_rc->category == TokenInfo::kMissingFileToken) {
        new_nodes.emplace_back(std::move(node_i));
        ++i;
        changed = true;
        continue;
      }

    // Deal with things like macros expanding to nothing or other injected
    // things.
    } else if (!i_arg && (!i_rc || !i_rc->parsed_tok)) {
      new_nodes.emplace_back(std::move(node_i));
      ++i;
      changed = true;
      continue;
    }

    // The macro name.
    if (j == 0u) {
      if (i_is_tok && j_is_tok) {
        new_nodes.emplace_back(std::move(node_i));
        ++i;
        ++j;
        changed = true;
        continue;

      } else if (j_is_tok) {
        TokenSet *i_rc_root = Root(i_rc);
        TokenSet *j_lc_root = Root(j_lc);
        if (!i_rc_root || i_rc_root != j_lc_root) {
          sub->has_error = true;
          pre_exp->has_error = true;
          Die(this);
          err << "Expected the right corner of the use's macro name to be the "
                 "left corner of the pre-expansion's macro name";
          return false;
        }

        // Add in the macro name.
        new_nodes.emplace_back(std::move(node_i));
        ++i;
        ++j;
        changed = true;
        continue;

      } else {
        sub->has_error = true;
        pre_exp->has_error = true;
        Die(this);
        err << "Expected the first node in a use and its pre-expansion to both "
               "be tokens, or for the use to be a substitution, and the pre-"
               "expansion to be a token";
        return false;
      }

    // Opening parenthesis of macro call.
    } else if (j == 1u) {
      if (i_rc->macro_tok->TokenKind() != pasta::TokenKind::kLParenthesis ||
          j_lc->macro_tok->TokenKind() != pasta::TokenKind::kLParenthesis) {
        err << "Failed to match opening parentheses";
        return false;
      }

      // Add in the l_paren.
      new_nodes.emplace_back(std::move(node_i));
      ++i;
      ++j;
      changed = true;
      continue;

    // Match up some arguments.
    } else if (i_arg && j_arg) {
      if (num_i_args != num_j_args) {
        err << "Out-of-sync macro arguments";
        return false;
      }

      if (auto new_arg = MergeArguments(i_arg, j_arg, err)) {
        new_arg->parent = sub;
        new_nodes.emplace_back(new_arg);
        ++i;
        ++j;
        ++num_i_args;
        ++num_j_args;
        changed = true;
        continue;

      } else {
        return false;
      }

    } else if (i_arg) {
      i_arg->has_error = true;
      Die(this);
      return false;  // TODO(pag): ???

    } else if (j_arg) {
      j_arg->has_error = true;
      Die(this);
      return false;  // TODO(pag): ???

    } else if (i_is_tok && j_is_tok) {
      TT_ASSERT(j_lc->parsed_tok.has_value());

      // Probably a comma.
      if (i_rc->parsed_tok->Data() == j_lc->parsed_tok->Data()) {
        new_nodes.emplace_back(std::move(node_j));
        ++i;
        ++j;
        changed = true;
        continue;
      }
    }
  }

  // Trailing arguments from the pre-expansion.
  if (!changed && i_rc && j_lc &&
      i_rc->macro_tok->TokenKind() == pasta::TokenKind::kRParenthesis &&
      j_lc->macro_tok->TokenKind() == pasta::TokenKind::kComma) {
    ++i;
    for (; j < max_j; ++j) {
      changed = true;
      new_nodes.emplace_back(pre_exp->before[j]);
    }
  }

  D( std::cerr
      << indent << "i=" << i << " j=" << j << " i_max=" << max_i
      << " j_max=" << max_j << '\n'; )

  if (!changed || i != max_i || j != max_j) {
    sub->has_error = true;
    pre_exp->has_error = true;
    Die(this);
    err << "Unable to complete merge";
    return false;
  }

  // Wipe out the intermediate expansion.
  TT_ASSERT(sub->after != pre_exp);
  sub->after->parent = nullptr;
  sub->after->after = nullptr;
  sub->after->before_body = nullptr;
  sub->after->after_body = nullptr;
  sub->after->macro_def.reset();
  sub->after->macro_use.reset();
  sub->after->before.clear();

  // Overwrite `sub->after` to point to the pre-expansion's `after`, so that
  // we eliminate the pre-expansion use altogether.
  sub->macro_use = std::move(pre_exp->macro_use);
  sub->before = std::move(new_nodes);
  sub->after = pre_exp->after;
  FixupNodeParents(sub);

  pre_exp->before_body = nullptr;
  pre_exp->after_body = nullptr;
  pre_exp->parent = nullptr;
  pre_exp->after = nullptr;
  pre_exp->before.clear();
  pre_exp->macro_def.reset();
  pre_exp->macro_use.reset();

  D( indent.resize(indent.size() - 2u); )
  return true;
}

// Get or create a substitution representing the body of the macro. Really, this
// is to get the beginning/ending tokens.
Substitution *TokenTreeImpl::GetMacroBody(pasta::MacroDefinition def,
                                          std::stringstream &err) {

  TokenInfo *prev = nullptr;
  Substitution *&body = macro_body[def.RawNode()];
  if (body) {
    return body;
  }

  auto name = def.NameToken();
  auto range = def.Nodes();
  auto it = range.begin();
  auto end = range.end();

  auto make_tok = [&] (const pasta::MacroNode &node) -> TokenInfo * {
    std::optional<pasta::MacroToken> tok = pasta::MacroToken::From(*it);
    if (!tok) {
      return nullptr;
    }

    TokenInfo &info = tokens_alloc.emplace_back();
    info.file_tok = tok->FileLocation();
    info.parsed_tok = tok->ParsedLocation();
    info.macro_tok = std::move(tok);
    info.category = TokenInfo::kMissingFileToken;

    UnifyToken(&info);
    if (prev) {
      prev->next = &info;
    }
    prev = &info;
    return &info;
  };

  body = CreateSubstitution(Substitution::kFileBody);

  // Advance to past the name.
  for (; it != end; ++it) {
    make_tok(*it);
    if (it->RawNode() == name.RawNode()) {
      ++it;
      break;
    }
  }

  // Go find the closing paren of the argument list.
  if (def.IsFunctionLike()) {
    auto paren_count = 0;
    for (; it != end; ++it) {
      if (TokenInfo *tok = make_tok(*it)) {
        auto kind = tok->macro_tok->TokenKind();
        if (kind == pasta::TokenKind::kLParenthesis) {
          ++paren_count;
        } else if (kind == pasta::TokenKind::kRParenthesis) {
          if (!--paren_count) {
            ++it;
            break;
          }
        }
      }
    }
  }

  body->macro_def = def;

  D( std::cerr << indent << "Macro body of " << def.NameToken().Data() << '\n'; )
  D( indent += "  "; )

  for (; it != end; ++it) {
    TokenInfo *tok = make_tok(*it);
    if (tok) {
      D( std::cerr << indent << tok->macro_tok->Data() << '\n'; )
      body->before.emplace_back(tok);
    }
  }

  StripWhitespace(body->before);
  AddOrClearInsaneBounds(body);

  D( indent.resize(indent.size()  - 2u); )

  return body;
}

TokenInfo *TokenTreeImpl::TryGetBeforeToken(TokenInfo *curr) {
  if (!curr || !curr->file_tok) {
    return nullptr;
  }

  UnifyToken(curr);

  auto index = curr->file_tok->Index();
  if (!index) {
    return nullptr;
  }
  pasta::File file = pasta::File::Containing(curr->file_tok.value());
  auto prev_file_tok = file.Tokens().At(index - 1u);
  if (!prev_file_tok) {
    return nullptr;
  }

  TokenInfo *before_tok = &(tokens_alloc.emplace_back());
  before_tok->file_tok = prev_file_tok;
  before_tok->next = curr;
  before_tok->category = TokenInfo::kMissingFileToken;
  UnifyToken(before_tok);
  return before_tok;
}


TokenInfo *TokenTreeImpl::TryGetAfterToken(TokenInfo *curr) {
  if (!curr || !curr->file_tok) {
    return nullptr;
  }

  UnifyToken(curr);

  auto index = curr->file_tok->Index();
  if (!index) {
    return nullptr;
  }

  pasta::File file = pasta::File::Containing(curr->file_tok.value());
  auto next_file_tok = file.Tokens().At(index + 1u);
  if (!next_file_tok) {
    return nullptr;
  }

  if (curr->next && curr->next->file_tok &&
      curr->next->file_tok->RawFileToken() == next_file_tok->RawFileToken()) {
    return curr->next;
  }

  TokenInfo *ater_tok = &(tokens_alloc.emplace_back());
  ater_tok->file_tok = next_file_tok;
  ater_tok->next = curr;
  ater_tok->category = TokenInfo::kMissingFileToken;
  UnifyToken(ater_tok);
  return ater_tok;
}

void TokenTreeImpl::TryAddBeforeToken(Substitution *sub, TokenInfo *curr) {
  if (sub->before_body) {
    return;
  } else {
    sub->before_body = TryGetBeforeToken(curr);
  }
}

void TokenTreeImpl::TryAddAfterToken(Substitution *sub, TokenInfo *prev) {
  if (sub->after_body) {
    return;
  } else {
    sub->after_body = TryGetAfterToken(prev);
  }
}

// Get rid of leading and trailing whitespace in all internal nodes.
void TokenTreeImpl::StripWhitespace(Substitution::NodeList &nodes) {

  auto remove_ws = [&nodes D(, this)] (void) {
    while (!nodes.empty()) {
      if (!std::holds_alternative<TokenInfo *>(nodes.back())) {
        break;
      }

      auto tok = std::get<TokenInfo *>(nodes.back());
      pasta::TokenKind tk = pasta::TokenKind::kIdentifier;  // Anything.
      if (tok->macro_tok) {
        tk = tok->macro_tok->TokenKind();
      } else if (tok->file_tok) {
        tk = tok->file_tok->Kind();
      }

      if (tk == pasta::TokenKind::kUnknown ||
          tk == pasta::TokenKind::kEndOfDirective ||
          tk == pasta::TokenKind::kEndOfFile) {
        D( std::cerr << indent << "Stripping whitespace token\n"; )
        nodes.pop_back();
      } else {
        break;
      }
    }
  };

  remove_ws();
  std::reverse(nodes.begin(), nodes.end());
  remove_ws();
  std::reverse(nodes.begin(), nodes.end());
}

void TokenTreeImpl::HandleVAOpt(
    Substitution *sub, bool has_macro_token_in_va_opt_arg) {

  Substitution::NodeList new_nodes;
  Substitution *va_opt = nullptr;
  auto i = 0u;
  for (Substitution::Node node : sub->before) {
    ++i;
    TokenInfo *tok = RightCornerOfExpansionOrUse(node);
    if (!tok || !tok->file_tok) {
      new_nodes.emplace_back(std::move(node));
      continue;
    }

    // NOTE(pag): The `__VA_OPT__` token should have been injected by the
    //            prefix stuff, so it should only have file token info.
    if (tok->file_tok->Data() != "__VA_OPT__") {
      new_nodes.emplace_back(std::move(node));
      continue;
    }

    va_opt = CreateSubstitution(Substitution::kVAOptUse);
    va_opt->before.emplace_back(std::move(node));
    va_opt->parent = sub;
    new_nodes.emplace_back(va_opt);
    break;
  }

  if (!va_opt) {
    D( std::cerr << indent << "Didn't find __VA_OPT__\n"; )
    return;
  }

  Substitution *va_arg = nullptr;
  Substitution *va_opt_sub;

  int paren_count = 0;
  auto max_i = sub->before.size();
  for (; i < max_i; ++i) {
    Substitution::Node node = sub->before[i];
    TokenInfo *tok = RightCornerOfExpansionOrUse(node);

    if (va_arg) {
      if (!tok || !tok->file_tok) {
        va_opt_sub->before.emplace_back(std::move(node));
      } else if (tok->file_tok->Kind() == pasta::TokenKind::kLParenthesis) {
        va_opt_sub->before.emplace_back(std::move(node));
        ++paren_count;
      } else if (tok->file_tok->Kind() == pasta::TokenKind::kRParenthesis) {
        if (!--paren_count) {
          D( std::cerr << indent << "Found __VA_OPT__ rparen ("
                       << tok->file_tok->Index() << ")\n"; )
          va_opt->before.emplace_back(std::move(node));
          ++i;
          break;
        } else {
          va_opt_sub->before.emplace_back(std::move(node));
        }

      // Argument token to the substitution.
      } else {
        va_opt_sub->before.emplace_back(std::move(node));
      }
      if (tok->parsed_tok && tok->macro_tok) {
        has_macro_token_in_va_opt_arg = true;
      }
    } else {
      if (!tok || !tok->file_tok) {
        va_opt->before.emplace_back(node);

      // Opening parenthesis of input tokens to `__VA_OPT__`.
      } else if (tok->file_tok->Kind() == pasta::TokenKind::kLParenthesis) {
        D( std::cerr << indent << "Found __VA_OPT__ lparen ("
                     << tok->file_tok->Index() << ")\n"; )
        va_arg = CreateSubstitution(Substitution::kVAOptArgument);
        va_arg->parent = va_opt;
        va_opt->before.emplace_back(std::move(node));
        va_opt->before.emplace_back(va_arg);

        va_opt_sub = CreateSubstitution(Substitution::kVAOptExpansion);
        va_opt_sub->parent = va_opt;
        va_opt->after = va_opt_sub;
        ++paren_count;

      // E.g. whitespace like `__VA_OPT__ (`.
      } else {
        va_opt->before.emplace_back(node);
      }
    }
  }

  if (!va_arg) {
    D( std::cerr << indent << "Didn't find argument of __VA_OPT__\n"; )
    return;
  }

  AddOrClearInsaneBounds(va_opt);

  if (has_macro_token_in_va_opt_arg) {
    CollectUseTokensInto(va_opt_sub->before, va_arg);
    AddOrClearInsaneBounds(va_arg);

    // NOTE(pag): Nesting a `__VA_OPT__` inside of itself isn't a thing, but if
    //            it were then we could recurse on `va_opt_sub`.

  // `__VA_OPT__` expanded to nothing.
  } else {
    va_arg->before.swap(va_opt_sub->before);
  }

  // Trailing tokens after `__VA_OPT__(...)`.
  for (; i < max_i; ++i) {
    new_nodes.emplace_back(sub->before[i]);
  }

  sub->before.swap(new_nodes);

  FixupNodeParents(va_arg);
  FixupNodeParents(va_opt);
  FixupNodeParents(sub);

  AddOrClearInsaneBounds(sub);
}

// Fill in the missing tokens from the token tree.
bool TokenTreeImpl::FillMissingFileTokens(Substitution *sub,
                                          std::stringstream &err) {
  auto ret = false;
  std::stringstream sub_err;
  auto i = 0u;
  auto max_i = sub->before.size() + 1u;

  for (bool changed = true; changed && i <= max_i; ++i) {
    changed = false;
    if (i >= 5) {
      sub->has_error = true;
      Die(this);

    }
    if (FillMissingFileTokensRec(sub, changed, sub_err)) {
      ret = true;
      max_i = sub->before.size() + 1u;
    } else if (!ret) {
      err << sub_err.str();
      break;
    } else {
      break;
    }
  }

  if (i > max_i) {
    Die(this);  // Probably an infinite loop.
  }

  return ret;
}

// Fill in the missing tokens from the token tree.
bool TokenTreeImpl::FillMissingFileTokensRec(Substitution *sub,
                                             bool &stopped_early,
                                             std::stringstream &err) {

  TokenInfo *prev = nullptr;
  if (sub->before_body && sub->before_body->file_tok) {
    D( std::cerr
        << indent << "before_body ("
        << sub->before_body->file_tok->Index() << "): "
        << sub->before_body->file_tok->KindName() << ' '
        << sub->before_body->file_tok->Data() << '\n'; )
    prev = sub->before_body;
  }

  // Add in a token that must be after the macro body into the token stream.
  // This provides a convenient upper-bound for things like expansions. We'll
  // pop it off later. It'll be visible by `AddMissingPrefixes` in the
  // below loop, but not directly visited by the loop below, because we
  // calculate `max_i` before adding `sub->after_body`.
  const auto max_i = sub->before.size();
  if (sub->after_body && sub->after_body->file_tok) {
    D( std::cerr
        << indent << "after_body ("
        << sub->after_body->file_tok->Index() << "): "
        << sub->after_body->file_tok->KindName() << ' '
        << sub->after_body->file_tok->Data() << '\n'; )
    sub->before.emplace_back(sub->after_body);
  }

  Substitution::NodeList new_nodes;
  pasta::TokenKind lck;

  D( indent += "  "; )

  for (auto i = 0u; i < max_i;) {
    Substitution::Node node = sub->before[i++];
    D( std::cerr << indent << "{\n"; )
    D( indent += "  "; )

    if (std::holds_alternative<TokenInfo *>(node)) {
      D(
        TokenInfo *nested_tok = std::get<TokenInfo *>(node);
        std::cerr << indent << "Token node";
        if (nested_tok->file_tok) {
          std::cerr << " (" << nested_tok->file_tok->Index() << "): "
                    << nested_tok->file_tok->Data();
        }
        std::cerr << '\n';
      )
    } else if (std::holds_alternative<Substitution *>(node)) {
      D( std::cerr << indent << "Substitution node\n"; )
      Substitution *nested_sub = std::get<Substitution *>(node);
      if (!FillMissingFileTokens(nested_sub, err)) {
        return false;
      }
    }
    if (prev) {

      bool stopped_early_nested1 = false;
      bool stopped_early_nested2 = false;
      D(
        if (prev->file_tok) {
          std::cerr
              << indent << "Prev (" << prev->file_tok->Index() << "): "
              << prev->file_tok->Data() << '\n';
        }
      )

      if (AddMissingPrefixes(sub, prev, node, stopped_early_nested1,
                             new_nodes, err)) {
        new_nodes.emplace_back(std::move(node));
        if (stopped_early_nested1) {
          if (!stopped_early) {
            D( std::cerr << indent << "!!! stopped_early_nested1\n"; )
          }
          stopped_early = true;
        }

      // We invented a substitution. Likely it is the substitution of a
      // macro parameter, a `__VA_ARGS__`, or a `__VA_OPT__`.
      } else if (Substitution *invented_node = TryInventMissingSubstitutions(
                     sub, prev, node, i, stopped_early_nested2)) {

        TokenInfo *invented_lc = LeftCornerOfUse(invented_node);
        if (!invented_lc || !invented_lc->file_tok) {
          sub->has_error = true;
          invented_node->has_error = true;
          Die(this);
          goto revisit_curr_again;

        } else if (lck = invented_lc->file_tok->Kind();
                   lck != pasta::TokenKind::kHash &&
                   lck != pasta::TokenKind::kHashHash &&
                   lck != pasta::TokenKind::kIdentifier &&
                   lck != pasta::TokenKind::kRawIdentifier) {

        revisit_curr_again:
          D( std::cerr << indent << "!!! triggering revisit on ("
                       << invented_lc->file_tok->Index() << "): "
                       << invented_lc->file_tok->Data() << '\n'; )
          // We've probably stripped leading whitespace from our invented node,
          // so go and add it in if we can.
          AddOrClearInsaneBounds(invented_node);

          bool ignore_missing = false;
          AddMissingPrefixes(sub, prev, invented_node,
                             ignore_missing, new_nodes, err);

          for (Substitution::Node bn : invented_node->before) {
            new_nodes.emplace_back(bn);
          }

          i -= 1u;  // Revisit.

          invented_node->before.clear();
          invented_node->after->before.clear();
          invented_node->after = nullptr;

        } else {

          // In the case of a parameter or `__VA_ARGS__`, we want to accumulate
          // more stuff into the `invented_node->after.before`.
          if (std::optional<unsigned> next_i = NextFromSameFile(sub, i)) {
            for (; i < next_i.value() && i < max_i; ++i) {
              D(
                if (auto tok = LeftCornerOfUse(sub->before[i]);
                    tok && tok->file_tok) {
                  std::cerr
                  << indent << "  Injecting ("
                      << tok->file_tok->Index() << ") into invented sub\n";
                }
              )
              invented_node->after->before.emplace_back(sub->before[i]);
            }
          }

          AddOrClearInsaneBounds(invented_node);
          AddOrClearInsaneBounds(invented_node->after);

          D( std::cerr << indent
                       << "invented substitution; going recursive {\n"; )
          D( indent += "  "; )

          if (!FillMissingFileTokens(invented_node, err)) {
            return false;
          }

          D( indent.resize(indent.size() - 2u); )
          D( std::cerr << indent << "}\n"; )

          // If we're in a vararg context, then check for `__VA_OPT__`, and turn
          // it into a substitution to nothing or to its contents.
          if (sub->macro_def && sub->macro_use) {
            auto in_vararg_context = sub->macro_use->Arguments().size() >
                                     sub->macro_def->NumExplicitParameters();
            HandleVAOpt(invented_node, in_vararg_context);
          }

          D( std::cerr << indent << "prefixing invented substitution\n"; )

          // We've probably stripped leading whitespace from our invented node,
          // so go and add it in if we can.
          bool ignore_missing = false;
          AddMissingPrefixes(sub, prev, invented_node,
                             ignore_missing, new_nodes, err);

          // Finally add our invent substitution in.
          new_nodes.emplace_back(invented_node);
        }

        if (stopped_early_nested2) {
          if (!stopped_early) {
            D( std::cerr << indent << "!!! stopped_early_nested2\n"; )
          }
          stopped_early = true;
        }

      } else {
        D( std::cerr << indent << "  didn't add intermediate nodes\n"; )
        new_nodes.emplace_back(std::move(node));
      }
    } else {
      new_nodes.emplace_back(std::move(node));
    }

    D( indent.resize(indent.size() - 2u); )
    D( std::cerr << indent << "}\n"; )

    if (auto next_prev = RightCornerOfUse(new_nodes.back())) {
      prev = next_prev;

    // This isn't ideal, so in a debug build we want to know about it, but in
    // a release build, at least something not too unreasonable will happen.
    } else {
//      TT_ASSERT(false);
    }
  }

  // TODO(pag): Technically, we could test the following:
  //
  //              if (sub != &(substitutions_alloc.front())) {
  //
  //            That would mean that if there is an include inside of an `enum`,
  //            for instance, and then if the included file had a bunch of
  //            leading/trailing whitespace/comments, then we'd elide those.
  if (sub->kind != Substitution::kFileBody) {
    StripWhitespace(new_nodes);
  }

  sub->before.swap(new_nodes);
  FixupNodeParents(sub);

  if (sub->kind == Substitution::kMacroExpansion && sub->macro_use) {
    HandleVAOpt(sub);
  }

  if (sub->after) {
    if (!FillMissingFileTokens(sub->after, err)) {
      return false;
    }
  }

  D( indent.resize(indent.size() - 2u); )
  return true;
}

Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    std::optional<pasta::MacroToken> node, std::stringstream &err) {

  // We may have filled in missing file tokens between macro use tokens, which
  // have file location information.
  for (; curr; prev = curr, curr = curr->next) {
    if (curr->category == TokenInfo::kMissingFileToken) {
      sub->before.emplace_back(curr);
    } else if (curr->macro_tok) {
      break;
    } else {
      err << "Found an unusual token";
      return nullptr;
    }
  }

  if (!curr || !curr->macro_tok) {
    err << "Failed to find the next macro token";
    return nullptr;
  }

  // Can happen when trying to align an argument containing conditional
  // directives in the use with pre-expansion form tht doesn't have the
  // conditional directives.
  if (curr->macro_tok->RawNode() != node->RawNode()) {
    return sub;
  }

  sub->before.emplace_back(curr);

  // Skip to the next token for the caller.
  prev = curr;
  curr = curr->next;
  return sub;
}

Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    std::optional<pasta::MacroArgument> node, std::stringstream &err) {

  Substitution *arg_sub = CreateSubstitution(Substitution::kMacroArgument);
  arg_sub->parent = sub;
  arg_sub->macro_arg = node;
  sub->before.emplace_back(arg_sub);

  for (const pasta::MacroNode &arg_node : node->Nodes()) {
    arg_sub = BuildMacroSubstitutions(
        prev, curr, arg_sub, arg_node, err);
    if (!arg_sub) {
      return nullptr;
    }
  }

  return sub;
}

Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    std::optional<pasta::MacroSubstitution> node, std::stringstream &err) {

  Substitution *exp_use = CreateSubstitution(Substitution::kSubstitutionBefore);
  Substitution *exp_sub = CreateSubstitution(Substitution::kSubstitutionAfter);
  exp_use->after = exp_sub;
  exp_use->parent = sub;
  exp_sub->parent = exp_use;
  sub->before.emplace_back(exp_use);

  for (const pasta::MacroNode &use_node : node->UsageNodes()) {
    exp_use = BuildMacroSubstitutions(
        prev, curr, exp_use, use_node, err);
    if (!exp_use) {
      return nullptr;
    }
  }

  for (const pasta::MacroNode &sub_node : node->SubstitutionNodes()) {
    exp_sub = BuildMacroSubstitutions(
        prev, curr, exp_sub, sub_node, err);
    if (!exp_sub) {
      return nullptr;
    }
  }

  return sub;
}

Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    std::optional<pasta::MacroExpansion> node, std::stringstream &err) {

  Substitution *exp_use = CreateSubstitution(Substitution::kMacroUse);
  Substitution *exp_sub = CreateSubstitution(Substitution::kMacroExpansion);
  exp_use->after = exp_sub;
  exp_use->parent = sub;
  exp_sub->parent = exp_use;
  sub->before.emplace_back(exp_use);

  for (const pasta::MacroNode &use_node : node->UsageNodes()) {
    exp_use = BuildMacroSubstitutions(
        prev, curr, exp_use, use_node, err);
    if (!exp_use) {
      return nullptr;
    }
  }

  for (const pasta::MacroNode &sub_node : node->SubstitutionNodes()) {
    exp_sub = BuildMacroSubstitutions(
        prev, curr, exp_sub, sub_node, err);
    if (!exp_sub) {
      return nullptr;
    }
  }

  exp_use->macro_def = node->Definition();
  exp_use->macro_use = std::move(node);

  exp_sub->macro_def = exp_use->macro_def;
  exp_sub->macro_use = exp_use->macro_use;

  if (!exp_sub->macro_def) {
    return sub;
  }

  // Try to find the real body.
  Substitution *macro_body = GetMacroBody(exp_sub->macro_def.value(), err);
  if (!macro_body) {
    err << "Unable to find macro body for macro with name '"
        << exp_sub->macro_def->NameToken().Data() << "'";
    return nullptr;
  }

  AddOrClearInsaneBounds(macro_body);
  exp_sub->before_body = macro_body->before_body;
  exp_sub->after_body = macro_body->after_body;

  return sub;
}

Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    std::optional<pasta::MacroDirective> node, std::stringstream &err) {
  Substitution *dir_use = CreateSubstitution(Substitution::kDirective);
  sub->before.emplace_back(dir_use);
  dir_use->parent = sub;

  for (const pasta::MacroNode &use_node : node->Nodes()) {
    dir_use = BuildMacroSubstitutions(
        prev, curr, dir_use, use_node, err);
    if (!dir_use) {
      return nullptr;
    }
  }

  dir_use->macro_dir = std::move(node);

  return sub;
}

Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    std::optional<pasta::MacroFileInclusion> node, std::stringstream &err) {
  Substitution *dir_use = CreateSubstitution(Substitution::kInclusion);
  sub->before.emplace_back(dir_use);
  dir_use->parent = sub;

  for (const pasta::MacroNode &use_node : node->Nodes()) {
    dir_use = BuildMacroSubstitutions(
        prev, curr, dir_use, use_node, err);
    if (!dir_use) {
      return nullptr;
    }
  }

  return sub;
}

Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    std::optional<pasta::MacroDefinition> node, std::stringstream &err) {
  Substitution *def = CreateSubstitution(Substitution::kDefinition);
  sub->before.emplace_back(def);
  def->parent = sub;

  for (const pasta::MacroNode &use_node : node->Nodes()) {
    def = BuildMacroSubstitutions(
        prev, curr, def, use_node, err);
    if (!def) {
      return nullptr;
    }
  }

  return sub;
}

Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    pasta::MacroNode node, std::stringstream &err) {
  switch (node.Kind()) {
    case pasta::MacroNodeKind::kInvalid:
      DCHECK(false);
      err << "Invalid substitution kind";
      return nullptr;
    case pasta::MacroNodeKind::kToken:
      return BuildMacroSubstitutions(
          prev, curr, sub, pasta::MacroToken::From(node), err);
    case pasta::MacroNodeKind::kArgument:
      return BuildMacroSubstitutions(
          prev, curr, sub, pasta::MacroArgument::From(node), err);
    case pasta::MacroNodeKind::kExpansion:
      return BuildMacroSubstitutions(
          prev, curr, sub, pasta::MacroExpansion::From(node), err);
    case pasta::MacroNodeKind::kSubstitution:
      return BuildMacroSubstitutions(
          prev, curr, sub, pasta::MacroSubstitution::From(node), err);
    case pasta::MacroNodeKind::kDirective:
      return BuildMacroSubstitutions(
          prev, curr, sub, pasta::MacroDirective::From(node), err);
    case pasta::MacroNodeKind::kInclude:
      return BuildMacroSubstitutions(
          prev, curr, sub, pasta::MacroFileInclusion::From(node), err);
    case pasta::MacroNodeKind::kDefine:
      return BuildMacroSubstitutions(
          prev, curr, sub, pasta::MacroDefinition::From(node), err);
    default:
      err << "Unexpected/unsupported substitution kind";
      return nullptr;
  }
}

// Starting with the left corner of the macro substitutions, build the macro
// uses bottom-up, working our way up to the root node.
Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    std::stringstream &err) {

  TokenInfo *before_body = curr;

  // Skip the marker token.
  DCHECK(curr->parsed_tok->Role() ==
         pasta::TokenRole::kBeginOfMacroExpansionMarker);
  prev = curr;
  curr = curr->next;

//  if (!before_body) {
//
//  } else {
//    TT_ASSERT(before_body->file_tok.has_value());
//    TT_ASSERT(curr->file_tok.has_value());
//    TT_ASSERT(before_body->file_tok->Index() < curr->file_tok->Index());
//  }

  TT_ASSERT(before_body->file_tok.has_value());
  TT_ASSERT(0u < before_body->file_tok->Index());
  TT_ASSERT(curr != nullptr);

  // Go find the first macro use token, which will be the left corner of our
  // macro expansion tree, and this will lead us to the root of the macro node.
  TokenInfo *use = curr;
  for (; use && use->category != TokenInfo::kMacroUseToken; use = use->next) {
    DCHECK(!use->parsed_tok);
    DCHECK(!use->parsed_tok->MacroLocation());
  }

  if (!use) {
    err << "Could not find first macro use token";
    return nullptr;
  }

  if (!use->macro_tok) {
    err << "First macro use token does not have a macro location";
    return nullptr;
  }

  sub = BuildMacroSubstitutions(
      prev, curr, sub, RootNodeFrom(use->macro_tok.value()), err);
  if (!sub) {
    return nullptr;
  }

  if (!curr || curr->category != TokenInfo::kMarkerToken) {
    sub->has_error = true;
    Die(this);
    err << "Expected a marker token at the end of macro expansion";
    return nullptr;
  }

  if (curr->parsed_tok->Role() !=
          pasta::TokenRole::kEndOfMacroExpansionMarker) {
    err << "Expected a macro expansion ending marker token at the end "
           "of macro expansion";
    return nullptr;
  }

  if (!sub->before.empty() &&
      std::holds_alternative<Substitution *>(sub->before.back())) {
    Substitution *nested_sub = std::get<Substitution *>(sub->before.back());
    nested_sub->before_body = before_body;
    nested_sub->after_body = curr;
    AddOrClearInsaneBounds(nested_sub);
  }

  // Skip the marker.
  prev = curr;
  curr = curr->next;
  return sub;
}

Substitution *TokenTreeImpl::BuildFileSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    std::stringstream &err) {

  TokenInfo * const before_body = curr;

  // Skip the beginning marker.
  DCHECK(curr->parsed_tok->Role() == pasta::TokenRole::kBeginOfFileMarker);
  prev = curr;
  curr = curr->next;

  // Recursively call the top-level builder starting with the first token
  // in the included file.
  Substitution *file_sub = BuildSubstitutions(prev, curr, err);
  if (!file_sub) {
    return nullptr;
  }

  file_sub->before_body = before_body;

  // Go add this file substitution to the previous inclusion directive.
  if (sub->before.empty() ||
      !std::holds_alternative<Substitution *>(sub->before.back())) {
    err << "The last thing in the current substitution "
           "should be a substitution";
    return nullptr;
  }

  Substitution *include_sub = std::get<Substitution *>(sub->before.back());
  if (include_sub->kind != Substitution::kInclusion) {
    err << "The last thing in the current substitution "
           "should be an inclusion";
    return nullptr;
  }

  include_sub->after = file_sub;
  file_sub->parent = include_sub;

  // Make sure that we're at the end of a file.
  if (!curr || curr->category != TokenInfo::kMarkerToken) {
    err << "Expected a marker token at the end of file";
    return nullptr;
  }

  if (curr->parsed_tok->Role() != pasta::TokenRole::kEndOfFileMarker) {
    err << "Expected a file ending marker token at the end of a file";
    return nullptr;
  }

  file_sub->after_body = curr;
  sub->after_body = curr;  // Push the parent forward.

  AddOrClearInsaneBounds(include_sub);
  AddOrClearInsaneBounds(file_sub);

  // Skip the marker.
  prev = curr;
  curr = curr->next;

  return sub;
}

Substitution *TokenTreeImpl::BuildSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, std::stringstream &err) {

  Substitution *sub = CreateSubstitution(Substitution::kFileBody);
  while (curr) {
    switch (curr->category) {
      // Basic case: just add the token in.
      case TokenInfo::kFileToken:
      case TokenInfo::kMissingFileToken:
        TryAddBeforeToken(sub, curr);
        sub->before.emplace_back(curr);
        prev = curr;
        curr = curr->next;
        continue;

      // Inside of a macro expansion region; this shoudln't happen.
      case TokenInfo::kMacroUseToken:
      case TokenInfo::kMacroStepToken:
      case TokenInfo::kMacroExpansionToken:
        sub->has_error = true;
        Die(this);
        err << "Macro tokens should not be seen here";
        return nullptr;

      // At a marker token.
      case TokenInfo::kMarkerToken:
        if (!sub->before_body) {
          sub->before_body = curr;
        }

        switch (curr->parsed_tok->Role()) {
          case pasta::TokenRole::kBeginOfFileMarker:
            sub = BuildFileSubstitutions(prev, curr, sub, err);
            if (!sub) {
              return nullptr;
            }
            continue;

          case pasta::TokenRole::kEndOfFileMarker:
            sub->after_body = curr; // Push it forward.
            AddOrClearInsaneBounds(sub);
            return sub;

          case pasta::TokenRole::kBeginOfMacroExpansionMarker:
            sub = BuildMacroSubstitutions(prev, curr, sub, err);
            if (!sub) {
              return nullptr;
            }
            continue;

          default:
            err << "Should not see this marker here";
            return nullptr;
        }
        break;
    }
  }

  if (prev) {
    if (prev->category == TokenInfo::kMarkerToken) {
      sub->after_body = prev;
      AddOrClearInsaneBounds(sub);
    } else {
      TryAddAfterToken(sub, prev);
    }
  }

  return sub;
}

bool TokenTreeImpl::FindSubstitutionBoundsRec(
    Substitution *sub, TokenInfo *lower_bound,
    TokenInfo *upper_bound) {
  TT_ASSERT(BoundsAreSane(sub));

  if (sub->after) {
    FindSubstitutionBoundsRec(sub->after, nullptr, nullptr);
  }

  // Wiped out node.
  if (!sub->parent && !sub->before_body && !sub->after_body &&
      sub->before.empty()) {
    return false;
  }

  if (!lower_bound || !lower_bound->file_tok) {
    lower_bound = sub->before_body;
  }

  if (!upper_bound || !upper_bound->file_tok) {
    upper_bound = sub->after_body;
  }

  if (!lower_bound || !upper_bound) {
    sub->before_body = nullptr;
    sub->after_body = nullptr;
    return false;
  }

  sub->before_body = lower_bound;
  sub->after_body = upper_bound;

  auto bi = lower_bound->file_tok->Index();
  auto ai = upper_bound->file_tok->Index();
  auto outer_file = pasta::File::Containing(sub->before_body->file_tok.value());

  auto restrict_sub = [&] (Substitution *nested_sub) -> bool {
    if (!nested_sub->before_body || !nested_sub->after_body) {
      nested_sub->before_body = nullptr;
      nested_sub->after_body = nullptr;
      FindSubstitutionBoundsRec(nested_sub, nullptr, nullptr);
      return false;
    }

    TT_ASSERT(nested_sub->parent == sub);
    TT_ASSERT(BoundsAreSane(nested_sub));

    auto inner_file = pasta::File::Containing(
        nested_sub->before_body->file_tok.value());
    if (inner_file != outer_file) {
      FindSubstitutionBoundsRec(nested_sub, nullptr, nullptr);
      return false;
    }

    auto old_before = nested_sub->before_body;
    auto old_after = nested_sub->after_body;

    auto sbi = old_before->file_tok->Index();
    auto sai = old_after->file_tok->Index();

    if ((sbi <= bi && ai <= sai) ||
        (sbi <= bi && bi <= sai) ||
        (sbi <= ai && ai <= sai)) {
      if (bi <= sbi && ai <= sai) {
        nested_sub->after_body = upper_bound;
      }

      if (sbi < bi && sai <= ai) {
        nested_sub->before_body = lower_bound;
      }
    }
    if (BoundsAreSane(nested_sub)) {
      FindSubstitutionBoundsRec(nested_sub, nested_sub->before_body,
                                nested_sub->after_body);
      return true;
    }

    nested_sub->has_error = true;
    Die(this);
    nested_sub->before_body = old_before;
    nested_sub->after_body = old_after;
    FindSubstitutionBoundsRec(nested_sub, nullptr, nullptr);
    return false;
  };

  // Restrict child substitutions. This goes in the forward direction.
  for (Substitution::Node &node : sub->before) {
    if (std::holds_alternative<TokenInfo *>(node)) {
      if (auto ti = std::get<TokenInfo *>(node)) {
        auto tii = ti->file_tok->Index();
        if (bi < tii && tii < ai) {
          lower_bound = ti;
          bi = tii;
        }
      }
      continue;
    } else if (std::holds_alternative<Substitution *>(node)) {
      Substitution *nested_sub = std::get<Substitution *>(node);
      if (restrict_sub(nested_sub)) {
        lower_bound = nested_sub->RightCornerOfUse();
        if (!lower_bound) {
          lower_bound = TryGetBeforeToken(nested_sub->after_body);
        }
        if (lower_bound && lower_bound->file_tok) {
          bi = lower_bound->file_tok->Index();
        }
      }
    }
  }

  // This goes in the backward direction.
  lower_bound = sub->before_body;
  upper_bound = sub->after_body;
  bi = lower_bound->file_tok->Index();
  ai = upper_bound->file_tok->Index();

  for (auto it = sub->before.rbegin(), end = sub->before.rend();
       it != end; ++it) {
    Substitution::Node &node = *it;
    if (std::holds_alternative<TokenInfo *>(node)) {
      if (auto ti = std::get<TokenInfo *>(node)) {
        auto tii = ti->file_tok->Index();
        if (bi < tii && tii < ai) {
          upper_bound = ti;
          ai = tii;
        }
      }
      continue;
    } else if (std::holds_alternative<Substitution *>(node)) {
      Substitution *nested_sub = std::get<Substitution *>(node);
      if (restrict_sub(nested_sub)) {
        upper_bound = nested_sub->LeftCornerOfUse();
        if (!upper_bound) {
          upper_bound = TryGetAfterToken(nested_sub->before_body);
        }
        if (upper_bound && upper_bound->file_tok) {
          ai = upper_bound->file_tok->Index();
        }
      }
    }
  }

  return true;
}

void TokenTreeImpl::FindSubstitutionBounds(void) {
  for (Substitution &sub : substitutions_alloc) {
    TT_ASSERT(!sub.after || sub.after->parent == &sub);

    AddOrClearInsaneBounds(&sub);
  }

  FindSubstitutionBoundsRec(&(substitutions_alloc.front()), nullptr, nullptr);
}

// Build the initial tree of substitutions.
Substitution *TokenTreeImpl::BuildSubstitutions(std::stringstream &err) {
  std::vector<Substitution *> subs;

  TokenInfo *prev = nullptr;
  TokenInfo * const first = &(tokens_alloc.front());
  TokenInfo *curr = first;  // NOTE(pag): Updated by reference.
  auto sub = BuildSubstitutions(prev, curr, err);
  if (!sub) {
    return nullptr;
  }

  return sub;
}

TokenSet *TokenTreeImpl::Root(TokenInfo *curr) {
  if (!curr || !curr->parsed_tok) {
    return nullptr;
  }

  return parsed_sets[curr->parsed_tok->RawToken()].Root();
}

TokenSet *TokenTreeImpl::UnifyToken(TokenInfo *curr) {
  TokenSet *parsed_set = Root(curr);
  if (!parsed_set) {
    return parsed_set;
  }

  if (!parsed_set->info) {
    parsed_set->info = curr;
  }

  if (!parsed_set->file_tok) {
    parsed_set->file_tok = curr->file_tok;

  } else if (!curr->file_tok) {
    curr->file_tok = parsed_set->file_tok;
  }

  std::optional<pasta::Token> derived_loc = curr->parsed_tok->DerivedLocation();
  if (!derived_loc) {
    return parsed_set;
  }

  TokenSet *prev_set = parsed_sets[derived_loc->RawToken()].Root();
  if (prev_set == parsed_set) {
    return parsed_set;
  }

  // The previous set might point out-of-fragment, e.g. to inside of a
  // `#define`.
  if (!prev_set->info) {
    prev_set->info = curr;
  }
  if (!prev_set->file_tok) {
    prev_set->file_tok = curr->file_tok;

  } else if (!curr->file_tok) {
    curr->file_tok = prev_set->file_tok;
  }

  if (!prev_set->file_tok) {
    prev_set->file_tok = derived_loc->FileLocation();
  } else if (!curr->file_tok) {
    curr->file_tok = prev_set->file_tok;
  }

  TT_ASSERT(parsed_set == parsed_set->Root());
  TT_ASSERT(prev_set == prev_set->Root());
  parsed_set->root = prev_set;  // Unify.
  return prev_set;
}

static bool TokenIsParamName(
    TokenInfo *tok, std::string &param_name,
    const std::unordered_map<std::string,
                             Substitution::NodeList> &params) {
  if (!tok->file_tok || tok->macro_tok || tok->parsed_tok) {
    return false;
  }

  switch (tok->file_tok->Kind()) {
    case pasta::TokenKind::kIdentifier:
    case pasta::TokenKind::kRawIdentifier:
      break;
    default:
      return false;
  }

  auto ftd = tok->file_tok->Data();
  param_name.clear();
  param_name.insert(param_name.end(), ftd.begin(), ftd.end());
  return params.count(param_name);
}

static void CollectExpansionTokensInto(
    const Substitution *in, Substitution::NodeList &out) {
  while (in->after) {
    in = in->after;
  }
  for (Substitution::Node node : in->before) {
    if (std::holds_alternative<Substitution *>(node)) {
      CollectExpansionTokensInto(std::get<Substitution *>(node), out);
    } else {
      out.emplace_back(std::move(node));
    }
  }
}

static void CollectArgumentsInto(
    const Substitution::NodeList &in, unsigned i,
    std::vector<Substitution::NodeList> &out) {

  for (auto max_i = in.size(); i < max_i; ++i) {
    Substitution::Node node = in[i];
    if (!std::holds_alternative<Substitution *>(node)) {
      continue;
    }
    Substitution *sub = std::get<Substitution *>(node);
    if (sub->kind == Substitution::kMacroArgument) {
      CollectExpansionTokensInto(sub, out.emplace_back());


    } else if (sub->kind == Substitution::kMacroUse && sub->after) {
      CollectArgumentsInto(sub->after->before, 0u, out);

    } else {
      CollectArgumentsInto(sub->before, 0u, out);
    }
  }
}

static void FindParameters(
    Substitution *sub,
    std::string &param_name,
    std::unordered_map<std::string, Substitution::NodeList> &params) {

  TT_ASSERT(sub->kind == Substitution::kMacroUse);

  Substitution::NodeList empty;
  std::vector<Substitution::NodeList> args;
  CollectArgumentsInto(sub->before, 1u /* Skip macro name */, args);

  auto i = 0u;

  bool seen_paren = false;
  for (pasta::MacroNode node : sub->macro_def->Nodes()) {
    auto tok = pasta::MacroToken::From(node);
    if (!tok) {
      continue;
    }

    switch (tok->TokenKind()) {
      case pasta::TokenKind::kLParenthesis:
        if (seen_paren) {
          goto done;
        } else {
          seen_paren = true;
          continue;
        }
      case pasta::TokenKind::kRParenthesis:
        goto done;
      case pasta::TokenKind::kIdentifier:
      case pasta::TokenKind::kRawIdentifier:
        if (!seen_paren) {
          continue;
        } else {
          std::string_view ftd = tok->Data();
          param_name.clear();
          param_name.insert(param_name.end(), ftd.begin(), ftd.end());

          if (i < args.size()) {
            D( std::cerr
                << "Found args for macro param name: "
                << param_name << '\n'; )
            params.emplace(param_name, args[i]);
          } else {
            D( std::cerr << "Found macro param name: " << param_name << '\n'; )
            params.emplace(param_name, empty);
          }
          ++i;
        }
        break;
      default:
        continue;
    }
  }
done:
  params.emplace("__VA_ARGS__", empty);
}

void TokenTreeImpl::FinalizeParameters(
    Substitution *sub,
    const std::unordered_map<std::string, Substitution::NodeList> &params) {

  const bool no_params = params.empty();
  std::string param_name;

  std::unordered_map<std::string, Substitution::NodeList> next_params;
  Substitution::NodeList new_before;

  auto i = 0u;
  for (const Substitution::Node &node : sub->before) {
    if (std::holds_alternative<TokenInfo *>(node)) {
      TokenInfo *tok = std::get<TokenInfo *>(node);

      // If this token was signalled to be a varargs concat, then it means
      // its containing substitution is one, so mark it as such.
      //
      // NOTE(pag): It may have been mislabeled as a `kConcatenateBefore`.
      if (tok->is_va_args_concat) {
        TT_ASSERT(sub->kind == Substitution::kConcatenateBefore ||
                  sub->kind == Substitution::kSubstitutionBefore ||
                  sub->kind == Substitution::kMacroParameterUse);
        sub->kind = Substitution::kMacroParameterUse;
        sub->after->kind = Substitution::kMacroParameterSubstitution;
        sub->is_va_args_concat = true;
        new_before.emplace_back(tok);
        continue;
      }

      // Try to re-label this substitution when specific operators are used.
      if (sub->kind == Substitution::kSubstitutionBefore && sub->after &&
          tok->file_tok) {
        switch (tok->file_tok->Kind()) {
          case pasta::TokenKind::kHash:
            if (!i) {
              sub->kind = Substitution::kStringifyBefore;
              sub->after->kind = Substitution::kStringifyAfter;
            }
            break;
          case pasta::TokenKind::kHashHash:
            if (i) {
              sub->kind = Substitution::kConcatenateBefore;
              sub->after->kind = Substitution::kConcatenateAfter;
            }
            break;
          default: break;
        }
      }

      if (no_params) {
        new_before.emplace_back(tok);
        continue;
      }

      if (!TokenIsParamName(tok, param_name, params)) {
        new_before.emplace_back(tok);
        continue;
      }

      Substitution *param_sub = CreateSubstitution(
          Substitution::kMacroParameterUse);
      Substitution *arg = CreateSubstitution(
          Substitution::kMacroParameterSubstitution);
      param_sub->before.emplace_back(std::move(node));
      param_sub->parent = sub;
      param_sub->after = arg;

      arg->parent = param_sub;
      arg->before = params.find(param_name)->second;

      new_before.emplace_back(param_sub);

    } else if (std::holds_alternative<Substitution *>(node)) {
      Substitution *nested_sub = std::get<Substitution *>(node);

      // Some parameters will have already have been recognized as substitutions
      // by `TryInventMissingSubstitutions`. Here, we try to recognize and
      // re-label them as such.
      if (nested_sub->after &&
          nested_sub->after->kind == Substitution::kSubstitutionAfter &&
          nested_sub->kind == Substitution::kSubstitutionBefore &&
          nested_sub->before.size() == 1u &&
          std::holds_alternative<TokenInfo *>(nested_sub->before.front()) &&
          TokenIsParamName(std::get<TokenInfo *>(nested_sub->before.front()),
                           param_name, params)) {

        nested_sub->kind = Substitution::kMacroParameterUse;
        nested_sub->after->kind = Substitution::kMacroParameterSubstitution;

        new_before.emplace_back(nested_sub);

      } else {
        FinalizeParameters(nested_sub, params);

        // It's just a normal nested substitution.
        if (!nested_sub->is_va_args_concat) {
          new_before.emplace_back(nested_sub);
          continue;
        }

        // It's a nested substitution with a `## __VA_ARGS__`, so we want to
        // find the `, ` in `, ## __VA_ARGS__` and move it into the nested
        // sub, and maybe into the `nested_sub->after`.

        std::vector<Substitution::Node> comma_etc;
        while (!new_before.empty()) {
          if (!std::holds_alternative<TokenInfo *>(new_before.back())) {
            nested_sub->has_error = true;
            Die(this);
            goto skip;
          }

          auto ti = std::get<TokenInfo *>(new_before.back());
          new_before.pop_back();
          comma_etc.push_back(ti);
          if (ti->file_tok &&
              ti->file_tok->Kind() == pasta::TokenKind::kComma) {
            break;
          }
        }

        // Add the `, ` before the `## __VA_ARGS__`.
        std::reverse(comma_etc.begin(), comma_etc.end());
        nested_sub->before.insert(nested_sub->before.begin(),
                                  comma_etc.begin(), comma_etc.end());

        // Add the `, ` before the expansion to maintain the commas.
        if (!nested_sub->after->before.empty()) {
          nested_sub->after->before.insert(
              nested_sub->after->before.begin(),
              comma_etc.begin(), comma_etc.end());
        }

      skip:
        new_before.emplace_back(nested_sub);
        continue;
      }

    } else {
      sub->has_error = true;
      Die(this);
    }

    ++i;
  }

  sub->before.swap(new_before);

  if (!sub->after) {
    return;
  }

  if (sub->kind == Substitution::kVAOptUse) {
    FinalizeParameters(sub->after, params);
    return;

  } else if (sub->kind != Substitution::kMacroUse) {
    FinalizeParameters(sub->after, next_params);
    return;
  }
  if (!sub->macro_def || !sub->macro_def->IsFunctionLike()) {
    return;
  }

  next_params.clear();
  FindParameters(sub, param_name, next_params);
  FinalizeParameters(sub->after, next_params);

}

// Try to unify tokens in the token list back to the same file token.
void TokenTreeImpl::UnifyTokens(void) {
  for (TokenInfo &curr : tokens_alloc) {
    UnifyToken(&curr);
  }

  for (TokenInfo &curr : tokens_alloc) {
    if (TokenSet *root_set = Root(&curr)) {
      TT_ASSERT(root_set->info != nullptr);
      TT_ASSERT(!curr.file_tok || (curr.file_tok && root_set->file_tok));
      curr.file_tok = root_set->file_tok;
    }
  }
}

TokenTree::~TokenTree(void) {}

// Create a token tree from the tokens in the inclusive range
// `[begin_index, end_index]` from `range`.
mx::Result<TokenTree, std::string>
TokenTree::Create(pasta::TokenRange range, uint64_t begin_index,
                  uint64_t end_index, bool fallback) {
  std::stringstream err;

  if (begin_index > end_index) {
    err << "Cannot create token tree; begin index (" << begin_index
        << ") is greater than end index (" << end_index << ")";
    return err.str();
  }

  if (auto range_size = range.Size(); end_index >= range_size) {
    err << "Cannot create token tree; end index (" << end_index
        << ") is greater than or equal to the range size ("
        << range_size << ")";
    return err.str();
  }

  auto impl = std::make_shared<TokenTreeImpl>();

  try {

    // Build and classify the initial list of tokens.
    if (!impl->BuildInitialTokenList(std::move(range), begin_index,
                                     end_index, err)) {
      return err.str();
    }

    Substitution *sub = impl->BuildSubstitutions(err);
    if (!sub) {
      return err.str();
    }

    impl->UnifyTokens();

    if (!fallback) {
      if (!impl->MergeArgPreExpansions(err)) {
        return err.str();
      }

      impl->FindSubstitutionBounds();

//      std::cerr << "\n\n";
//      impl->substitutions_alloc.front().PrintDOT(std::cerr);
//      std::cerr << "\n\n";

      // Fill in things like whitespace gaps between file tokens. This doesn't
      // do any tracking of substitutions.
      if (!impl->FillMissingFileTokens(sub, err)) {
        return err.str();
      }

      std::unordered_map<std::string, Substitution::NodeList> params;
      impl->FinalizeParameters(sub, params);
//
//      D(
//        std::cerr << "----------------------------------------------------- " << begin_index << " to " << end_index << " ---\n";
//        std::cerr << "----------------------------------------------------- " << impl->tokens_alloc.size() << " ---\n";
//        sub->Print(std::cerr);
//        std::cerr << "\n\n\n";
//        sub->PrintDOT(std::cerr);
//        std::cerr << "\n\n\n";
//        return std::string();
//      )
    }

    std::shared_ptr<const Substitution> ret(std::move(impl), sub);
    return TokenTree(std::move(ret));

  } catch (const char *msg) {
    return std::string(msg);
  }
}

std::optional<pasta::FileToken> TokenTreeNode::FileToken(void) const noexcept {
  if (const auto &ent = impl->before[offset];
      std::holds_alternative<TokenInfo *>(ent)) {
    return std::get<TokenInfo *>(ent)->file_tok;
  } else {
    return std::nullopt;
  }
}

std::optional<pasta::MacroToken> TokenTreeNode::MacroToken(void) const noexcept {
  if (const auto &ent = impl->before[offset];
      std::holds_alternative<TokenInfo *>(ent)) {
    return std::get<TokenInfo *>(ent)->macro_tok;
  } else {
    return std::nullopt;
  }
}

std::optional<pasta::Token> TokenTreeNode::Token(void) const noexcept {
  if (const auto &ent = impl->before[offset];
      std::holds_alternative<TokenInfo *>(ent)) {
    return std::get<TokenInfo *>(ent)->parsed_tok;
  } else {
    return std::nullopt;
  }
}

std::optional<std::tuple<mx::MacroSubstitutionKind, TokenTree>>
TokenTreeNode::MaybeSubTree(void) const noexcept {
  if (const auto &ent = impl->before[offset];
      std::holds_alternative<class Substitution *>(ent)) {

    auto lhs = std::get<class Substitution *>(ent);
    auto subtree_kind = mx::MacroSubstitutionKind::OTHER_DIRECTIVE;
    switch (lhs->kind) {
      case Substitution::kDefinition: {
        TokenTree before(std::shared_ptr<const class Substitution>(impl, lhs));
        return std::make_tuple(mx::MacroSubstitutionKind::DEFINE_DIRECTIVE,
                               std::move(before));
      }
      case Substitution::kDirective:
        if (!lhs->macro_dir) {
          subtree_kind = mx::MacroSubstitutionKind::OTHER_DIRECTIVE;
          break;
        }
        switch (lhs->macro_dir->DirectiveKind()) {
          case pasta::MacroDirectiveKind::kIf:
            subtree_kind = mx::MacroSubstitutionKind::IF_DIRECTIVE;
            break;
          case pasta::MacroDirectiveKind::kIfDefined:
            subtree_kind = mx::MacroSubstitutionKind::IFDEF_DIRECTIVE;
            break;
          case pasta::MacroDirectiveKind::kIfNotDefined:
            subtree_kind = mx::MacroSubstitutionKind::IFNDEF_DIRECTIVE;
            break;
          case pasta::MacroDirectiveKind::kElseIf:
            subtree_kind = mx::MacroSubstitutionKind::ELIF_DIRECTIVE;
            break;
          case pasta::MacroDirectiveKind::kElseIfDefined:
            subtree_kind = mx::MacroSubstitutionKind::ELIFDEF_DIRECTIVE;
            break;
          case pasta::MacroDirectiveKind::kElseIfNotDefined:
            subtree_kind = mx::MacroSubstitutionKind::ELIFNDEF_DIRECTIVE;
            break;
          case pasta::MacroDirectiveKind::kElse:
            subtree_kind = mx::MacroSubstitutionKind::ELSE_DIRECTIVE;
            break;
          case pasta::MacroDirectiveKind::kEndIf:
            subtree_kind = mx::MacroSubstitutionKind::ENDIF_DIRECTIVE;
            break;
          case pasta::MacroDirectiveKind::kDefine:
            subtree_kind = mx::MacroSubstitutionKind::DEFINE_DIRECTIVE;
            break;
          case pasta::MacroDirectiveKind::kUndefine:
            subtree_kind = mx::MacroSubstitutionKind::UNDEF_DIRECTIVE;
            break;
          case pasta::MacroDirectiveKind::kHashPragma:
            subtree_kind = mx::MacroSubstitutionKind::PRAGMA_DIRECTIVE;
            break;
          case pasta::MacroDirectiveKind::kC99Pragma:
            subtree_kind = mx::MacroSubstitutionKind::C99_PRAGMA_DIRECTIVE;
            break;
          case pasta::MacroDirectiveKind::kMicrosoftPragma:
            subtree_kind =
                mx::MacroSubstitutionKind::MICROSOFT_PRAGMA_DIRECTIVE;
            break;
          default:
            subtree_kind = mx::MacroSubstitutionKind::OTHER_DIRECTIVE;
            break;
        }
        break;
      case Substitution::kMacroArgument:
        subtree_kind = mx::MacroSubstitutionKind::MACRO_ARGUMENT;
        break;

      case Substitution::kVAOptArgument:
        subtree_kind = mx::MacroSubstitutionKind::VA_OPT_ARGUMENT;
        break;

      default:
        return std::nullopt;
    }

    TokenTree before(std::shared_ptr<const class Substitution>(impl, lhs));
    return std::make_tuple(subtree_kind, std::move(before));
  }
  return std::nullopt;
}

std::optional<std::tuple<mx::MacroSubstitutionKind, TokenTree, TokenTree>>
TokenTreeNode::MaybeSubstitution(void) const noexcept {
  if (const auto &ent = impl->before[offset];
      std::holds_alternative<class Substitution *>(ent)) {
    auto lhs = std::get<class Substitution *>(ent);
    auto rhs = lhs->after;

    TokenTree before(std::shared_ptr<const class Substitution>(impl, lhs));
    TokenTree after(std::shared_ptr<const class Substitution>(impl, rhs));

    switch (lhs->kind) {
      case Substitution::kInclusion:
        return std::make_tuple(
            mx::MacroSubstitutionKind::INCLUDE_DIRECTIVE,
            std::move(before), std::move(after));

      case Substitution::kMacroUse:
        return std::make_tuple(
            mx::MacroSubstitutionKind::MACRO,
            std::move(before), std::move(after));

      case Substitution::kVAOptUse:
        return std::make_tuple(
            mx::MacroSubstitutionKind::VA_OPT,
            std::move(before), std::move(after));

      case Substitution::kSubstitutionBefore:
        return std::make_tuple(
            mx::MacroSubstitutionKind::SUBSTITUTE,
            std::move(before), std::move(after));

      case Substitution::kMacroParameterUse:
        return std::make_tuple(
            mx::MacroSubstitutionKind::MACRO_PARAMETER,
            std::move(before), std::move(after));

      case Substitution::kStringifyBefore:
        return std::make_tuple(
            mx::MacroSubstitutionKind::STRINGIFY,
            std::move(before), std::move(after));

      case Substitution::kConcatenateBefore:
        return std::make_tuple(
            mx::MacroSubstitutionKind::CONCATENATE,
            std::move(before), std::move(after));

      // Sub-tree things.
      case Substitution::kDirective:
      case Substitution::kDefinition:
      case Substitution::kMacroArgument:
      case Substitution::kVAOptArgument:
        return std::nullopt;

      case Substitution::kMacroExpansion:
      case Substitution::kVAOptExpansion:
      case Substitution::kSubstitutionAfter:
      case Substitution::kMacroParameterSubstitution:
      case Substitution::kStringifyAfter:
      case Substitution::kConcatenateAfter:
      case Substitution::kFileBody:
        LOG(FATAL) << "Hrmm";
        break;
    }

  } else {
    return std::nullopt;
  }
}

bool TokenTreeNodeIterator::operator==(TokenTreeNodeIteratorEnd) const {
  return node.offset >= node.impl->before.size();
}

bool TokenTreeNodeIterator::operator!=(TokenTreeNodeIteratorEnd) const {
  return node.offset < node.impl->before.size();
}

TokenTreeNodeIterator TokenTree::begin(void) const noexcept {
  return TokenTreeNodeIterator(impl);
}

// Return the number of nodes in this tree.
unsigned TokenTree::NumNodes(void) const noexcept {
  return static_cast<unsigned>(impl->before.size());
}

}  // namespace indexer
