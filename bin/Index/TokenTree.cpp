// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "TokenTree.h"

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

namespace indexer {

struct TokenInfo {
  enum Category {
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
    // Default case, this is an identity substitution of `before` for itself,
    // i.e. this substitution represents the tokens of `before`.
    kIdentity,

    // An identity-like substitution that wraps around a macro argument.
    kMacroArgument,

    // Normal macro substitution kind. `before` points to a sequence of file
    // tokens, `after` points to its expansion.
    kMacroUse,
    kMacroExpansion,

    kVAOptUse,
    kVAOptArgument,
    kVAOptExpansion,

    // Some generic form of substitution, e.g. a parameter with its argument.
    kSubstitution,

    // An inclusion of a file nested inside of a top-level declaration, and so
    // the inclusion manifests as a kind of macro expansion.
    kInclusion,
    kDefinition,
    kDirective

  } kind;

  std::optional<pasta::MacroDefinition> macro_def;
  std::optional<pasta::MacroExpansion> macro_use;

  using Node = std::variant<TokenInfo *, Substitution *>;

  std::vector<Node> before;

  Substitution *parent{nullptr};
  Substitution *after{nullptr};

  // A token that is logically a predecessor of `before`.
  TokenInfo *before_body{nullptr};
  TokenInfo *after_body{nullptr};

  explicit Substitution(Kind kind_)
      : kind(kind_) {}

  TokenInfo *LeftCornerOfUse(void) const;
  TokenInfo *RightCornerOfUse(void) const;
  TokenInfo *RightCornerOfExpansionOrUse(void) const;
//  bool EqualToBefore(const Substitution *that) const;
  void Print(std::ostream &os) const;
  void PrintDOT(std::ostream &os) const;
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

  std::string indent;

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
      TokenInfo *prev, TokenInfo *curr, TokenInfo *min, TokenInfo *max,
      std::vector<Substitution::Node> &nodes);

  Substitution *GetMacroBody(pasta::MacroDefinition def,
                             std::stringstream &err);

  void TryAddBeforeToken(Substitution *sub, TokenInfo *curr);
  void TryAddAfterToken(Substitution *sub, TokenInfo *prev);

  // Fill in the missing tokens from the token tree.
  void StripWhitespace(std::vector<Substitution::Node> &nodes);
  void CollectUseTokensInto(const std::vector<Substitution::Node> &nodes,
                            Substitution *sub);
  void HandleVAOpt(Substitution *sub, bool has_macro_token_in_arg=false);
  bool FillMissingFileTokens(Substitution *sub, std::stringstream &err);
  void FindSubstitutionBounds(void);
  bool MergeArgPreExpansions(std::stringstream &err);
  bool MergeArgPreExpansion(Substitution *sub, Substitution *pre_exp,
                            std::stringstream &err);
  bool TryInventMissingSubstitutions(
      Substitution *sub, TokenInfo *prev, Substitution::Node curr_node,
      unsigned next_index, std::vector<Substitution::Node> &nodes);
  bool AddNodeAndMissingPrefixes(
      Substitution *sub, TokenInfo *prev, Substitution::Node curr,
      unsigned next_index, std::vector<Substitution::Node> &nodes,
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

  // Try to unify tokens in the token list back to the same file token.
  void UnifyTokens(TokenInfo *first);
  TokenSet *UnifyToken(TokenInfo *tok);
  TokenSet *Root(TokenInfo *tok);
};

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
    const std::vector<Substitution::Node> &before) {
  auto it = before.rbegin();
  auto end = before.rend();
  for (; it != end; ++it) {
    if (auto rc = ::indexer::RightCornerOfUse(*it)) {
      return rc;
    }
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
  TokenSet *macro_name_root = Root(macro_name);
  TokenSet *exp_macro_name_root = Root(exp_macro_name);

  if (!macro_name_root || macro_name_root != exp_macro_name_root) {
    return nullptr;
  }

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
  for (auto ent : before) {
    if (std::holds_alternative<TokenInfo *>(ent)) {
      auto info = std::get<TokenInfo *>(ent);
      switch (info->category) {
        case TokenInfo::kFileToken:
          std::cerr << info->file_tok->Data();
          continue;
        case TokenInfo::kMacroUseToken:
        case TokenInfo::kMissingFileToken:
          std::cerr << "\033[4m" << info->file_tok->Data() << "\033[0m";
          continue;
        case TokenInfo::kMacroStepToken:
        case TokenInfo::kMarkerToken:
        default:
          continue;
      }
    } else {
      std::get<Substitution *>(ent)->Print(os);
    }
  }
}

void Substitution::PrintDOT(std::ostream &os) const {
  if (after) {
    after->PrintDOT(os);
  }

  os << "s" << reinterpret_cast<const void *>(this)
     << " [label=<<TABLE cellpadding=\"0\" cellspacing=\"0\" border=\"1\"><TR>";

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
    }
    if (info->file_tok) {
      os << "<TR><TD>FT=" << info->file_tok->Index() << "</TD></TR>";
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

  if (!has_any) {
    os << "<TD> </TD>";
  }

  os << "</TR></TABLE>>];\n";

  i = 0;
  for (auto ent : before) {
    if (std::holds_alternative<Substitution *>(ent)) {
      auto s = std::get<Substitution *>(ent);
      s->PrintDOT(os);

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
  for (auto i = begin_index; i <= end_index; ++i) {
    pasta::Token tok = range[i];
    switch (tok.Role()) {
      default:
      case pasta::TokenRole::kInvalid:
        err << "Invalid or unexpected token in range";
        return nullptr;

      case pasta::TokenRole::kBeginOfMacroExpansionMarker: {
        DCHECK(tok.FileLocation().has_value());
        TokenInfo &info = tokens_alloc.emplace_back();
        info.file_tok = tok.FileLocation();
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kMarkerToken;
        ++macro_depth;
        continue;
      }

      case pasta::TokenRole::kEndOfMacroExpansionMarker: {
        DCHECK(tok.FileLocation().has_value());
        TokenInfo &info = tokens_alloc.emplace_back();
        info.file_tok = tok.FileLocation();
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kMarkerToken;
        --macro_depth;
        DCHECK_LE(0, macro_depth);
        continue;
      }

      case pasta::TokenRole::kIntermediateMacroExpansionToken: {
        DCHECK_LT(0, macro_depth);
        TokenInfo &info = tokens_alloc.emplace_back();
        if (auto file_tok = tok.FileLocation()) {
          info.file_tok = std::move(file_tok);
          info.category = TokenInfo::kMacroUseToken;
        } else {
          info.category = TokenInfo::kMacroStepToken;
        }
        info.macro_tok = tok.MacroLocation();
        if (!info.file_tok && info.macro_tok) {
          info.file_tok = info.macro_tok->FileLocation();
        }
        info.parsed_tok = std::move(tok);
        continue;
      }

      case pasta::TokenRole::kFinalMacroExpansionToken: {
        DCHECK_LT(0, macro_depth);
        TokenInfo &info = tokens_alloc.emplace_back();
        if (auto file_tok = tok.FileLocation()) {
          info.file_tok = std::move(file_tok);
        }
        info.macro_tok = tok.MacroLocation();
        if (!info.file_tok && info.macro_tok) {
          info.file_tok = info.macro_tok->FileLocation();
        }
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kMacroExpansionToken;
        continue;
      }

      case pasta::TokenRole::kBeginOfFileMarker:
      case pasta::TokenRole::kEndOfFileMarker: {
        DCHECK(tok.FileLocation().has_value());
        TokenInfo &info = tokens_alloc.emplace_back();
        info.file_tok = tok.FileLocation();
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kMarkerToken;
        continue;
      }

      case pasta::TokenRole::kFileToken: {
        DCHECK_EQ(0, macro_depth);
        auto &info = tokens_alloc.emplace_back();
        info.file_tok = tok.FileLocation();
        DCHECK(info.file_tok.has_value());
        DCHECK_EQ(info.file_tok->Data(), tok.Data());
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
//
//bool TokenTreeImpl::FillMacroToken(TokenInfo *&prev, TokenInfo *&curr,
//                                   const pasta::MacroToken &node,
//                                   std::stringstream &err) {
//
//  switch (curr->category) {
//    // This is a intermediate or final macro expansion token.
//    case TokenInfo::kMacroExpansionToken:
//    case TokenInfo::kMacroStepToken:
//      CHECK(curr->parsed_tok.has_value());
//      CHECK(curr->parsed_tok == node.ParsedLocation());
//      break;
//
//    // This is a macro usage token.
//    case TokenInfo::kMacroUseToken:
//      CHECK(curr->parsed_tok.has_value());
//      CHECK(curr->file_tok == node.FileLocation());
//      if (prev) {
//        prev_top_level = FillBetweenFileTokens(prev_top_level, prev, curr);
//      }
//      break;
//
//    default:
//      err << "Trying to fill a macro token, but next token "
//             "info kind is not associated with a macro";
//      return false;
//  }
//
//  curr->macro_tok = node;
//  AddTokenToSubstitution(curr);
//  prev = curr;
//  curr = curr->next;
//  return true;
//}
//
//// Fill in the missing tokens from the token tree.
//bool TokenTreeImpl::FillTokensFromMacro(TokenInfo *&prev, TokenInfo *&curr,
//                                        pasta::MacroNode node,
//                                        std::stringstream &err) {
//
//  auto fill_nodes = [&, this] (pasta::MacroNodeRange range) -> bool {
//    for (pasta::MacroNode child_node : range) {
//      if (!FillTokensFromMacro(prev, curr, std::move(child_node), err)) {
//        return false;
//      }
//    }
//    return true;
//  };
//
//  auto do_directive =
//      [&, this] (Substitution::Kind kind) -> bool {
//        const auto &dir = reinterpret_cast<const pasta::MacroDirective &>(node);
//        const auto hash_file_tok = dir.HashToken().FileLocation();
//        if (!hash_file_tok) {
//          err
//              << "Unable to find file containing hash token of directive";
//          return false;
//        }
//        auto sub = CreateSubstitution(kind);
//        if (kind == Substitution::kInclusion) {
//          includes.push_back(sub);
//        }
//        substitutions.push_back(sub);
//        if (!fill_nodes(dir.Nodes())) {
//          return false;
//        }
//        DCHECK_EQ(substitutions.back(), sub);
//        substitutions.pop_back();
//        return true;
//      };
//
//  switch (node.Kind()) {
//    case pasta::MacroNodeKind::kToken:
//      return FillMacroToken(
//          prev, curr, reinterpret_cast<pasta::MacroToken &>(node), err);
//
//    case pasta::MacroNodeKind::kExpansion:
//    case pasta::MacroNodeKind::kSubstitution: {
//      auto &sub = reinterpret_cast<pasta::MacroSubstitution &>(node);
//      Substitution *use = CreateSubstitution(Substitution::kMacroUse);
//      use->after = CreateSubstitution(Substitution::kMacroExpansion);
//
//      // Process the used tokens.
//      substitutions.push_back(use);
//      if (!fill_nodes(sub.UsageNodes())) {
//        return false;
//      }
//      DCHECK_EQ(substitutions.back(), use);
//      substitutions.pop_back();
//
//      // Process the substituted tokens.
//      substitutions.push_back(use->after);
//      if (!fill_nodes(sub.SubstitutionNodes())) {
//        return false;
//      }
//      DCHECK_EQ(substitutions.back(), use->after);
//      substitutions.pop_back();
//      return true;
//    }
//
//    case pasta::MacroNodeKind::kDirective:
//      return do_directive(Substitution::kDirective);
//    case pasta::MacroNodeKind::kDefine:
//      return do_directive(Substitution::kDefinition);
//    case pasta::MacroNodeKind::kInclude:
//      return do_directive(Substitution::kInclusion);
//
//    case pasta::MacroNodeKind::kArgument:
//      return fill_nodes(reinterpret_cast<pasta::MacroArgument &>(node).Nodes());
//  }
//
//  return false;
//}

bool TokenTreeImpl::TryFillBetweenFileTokens(
    TokenInfo *prev, TokenInfo *curr, TokenInfo *min, TokenInfo *max,

    std::vector<Substitution::Node> &nodes) {
  if (!prev->file_tok || !curr->file_tok) {
    return false;
  }

  pasta::FileToken prev_file_tok = prev->file_tok.value();
  pasta::FileToken curr_file_tok = curr->file_tok.value();
  pasta::File prev_file = pasta::File::Containing(prev_file_tok);
  pasta::File curr_file = pasta::File::Containing(curr_file_tok);

  if (prev_file != curr_file) {
    std::cerr << indent << "can't fill from two different files\n";
    return false;
  }

  auto prev_i = prev_file_tok.Index();
  auto curr_i = curr_file_tok.Index();

  if (prev_i >= curr_i) {
    std::cerr << indent << "can't fill: prev_i=" << prev_i << " >= curr_i=" << curr_i << "\n";
    return false;
  }

  auto min_i = 0ull;
  auto max_i = ~0ull;

  if (min && min->file_tok) {
    if (pasta::File::Containing(min->file_tok.value()) == prev_file) {
      min_i = min->file_tok->Index();
    }
  }

  if (max && max->file_tok) {
    if (pasta::File::Containing(max->file_tok.value()) == prev_file) {
      max_i = max->file_tok->Index();
    }
  }

  // The range must not straddle the range of the stuff into which we're
  // injecting. It should either be in range, or out of range.
  if (min_i < max_i) {
    if (prev_i < min_i && curr_i <= max_i) {
      std::cerr << indent << "can't straddle: prev_i=" << prev_i << " < min_i=" << min_i << ", curr_i=" << curr_i << " <= max_i=" << max_i << "\n";
      return false;
    }

    if (min_i <= prev_i && max_i < curr_i) {
      std::cerr << indent << "can't straddle: min_i=" << min_i << " <= prev_i=" << prev_i << ", max_i=" << max_i << " < curr_i=" << curr_i << "\n";
      return false;
    }
  }

  pasta::FileTokenRange tokens = prev_file.Tokens();
  auto i = prev_i + 1u;  // `prev` is already present.
//  if (i > curr_i) {
//    substitutions_alloc.front().PrintDOT(std::cerr);
//  }
//  CHECK_LE(i, max_i);
  bool seen_pound = false;
  int paren_count = 0;
  bool collect_parens = false;
  std::cerr << indent << "FillBetweenFileTokensInSameFile(" << i << ", " << curr_i << ")\n";
  for (; i < curr_i; ++i) {
    pasta::FileToken ft = tokens[i];
    switch (ft.Kind()) {
      case pasta::TokenKind::kHash:
      case pasta::TokenKind::kHashHash:
        std::cerr << indent << "seen pound (" << ft.Index() << ")\n";
        if (seen_pound) {
          goto exit_loop;
        }
        seen_pound = true;
        goto keep_going;
      case pasta::TokenKind::kLParenthesis:
        if (collect_parens) {
          ++paren_count;
        }
        goto keep_going;
      case pasta::TokenKind::kRParenthesis:
        if (collect_parens && !--paren_count) {
          curr_i = (i + 1u);  // Stop before next iteration.
        }
        goto keep_going;
      case pasta::TokenKind::kIdentifier:
      case pasta::TokenKind::kRawIdentifier:
        if (seen_pound) {
          if (ft.Data() == "__VA_OPT__") {
            collect_parens = true;
            seen_pound = false;  // Might be internal to parens.
          } else {
            curr_i = (i + 1u);  // Stop before next iteration.
          }
        }
        goto keep_going;
      case pasta::TokenKind::kUnknown:
      case pasta::TokenKind::kEndOfFile:
      case pasta::TokenKind::kEndOfDirective:
        goto keep_going;
      default:
        if (seen_pound) {
          assert(false);
          goto exit_loop;
        }
        goto keep_going;
    }

  exit_loop:
    break;

  keep_going:

    // TODO(pag): Consider expanding `__VA_ARGS__` and other parameters
    //            to make their substitutions explicit.

    TokenInfo &info = tokens_alloc.emplace_back();
    info.file_tok = std::move(ft);
    std::cerr
        << indent << "Adding token (" << i << "): "
        << info.file_tok->KindName() << ' ' << info.file_tok->Data() << '\n';
    info.category = TokenInfo::kMissingFileToken;
    info.next = curr;
    prev->next = &info;
    prev = &info;
    UnifyToken(&info);
    nodes.emplace_back(&info);
  }

  CHECK_EQ(i, curr_i);
  CHECK(prev->file_tok.has_value());

  return true;
}

bool TokenTreeImpl::TryInventMissingSubstitutions(
    Substitution *sub, TokenInfo *prev, Substitution::Node curr_node,
    unsigned next_index, std::vector<Substitution::Node> &nodes) {

  if (!prev->file_tok) {
//    if (next_index == 1u) {
//      prev = sub->before_body;
//      if (!prev->file_tok) {
//        return false;
//      }
//    } else {
    return false;
//    }
  }

  std::optional<pasta::FileToken> sub_bb;
  std::optional<pasta::FileToken> sub_ab;

  if (sub->before_body) {
    sub_bb = sub->before_body->file_tok;
  }
  if (sub->after_body) {
    sub_ab = sub->after_body->file_tok;
  }

  TokenInfo *next = nullptr;
  const size_t num_nodes = sub->before.size();

  for (auto i = next_index; i < num_nodes; ++i) {
    next = LeftCornerOfUse(sub->before[i]);
    if (!next || !next->file_tok) {
      continue;
    }

    pasta::File next_file = pasta::File::Containing(next->file_tok.value());

    if (sub_bb &&
        ((sub_bb->Index() >= next->file_tok->Index()) ||
         (next_file != pasta::File::Containing(sub_bb.value())))) {
      continue;
    }

    if (sub_ab &&
        ((sub_ab->Index() <= next->file_tok->Index()) ||
         (next_file != pasta::File::Containing(sub_ab.value())))) {
      continue;
    }

    break;
  }

  if (!next) {
    return false;
  }

  std::vector<Substitution::Node> missing_nodes;
  if (!TryFillBetweenFileTokens(prev, next, sub->before_body, sub->after_body,
                                missing_nodes)) {
    return false;
  }

  StripWhitespace(missing_nodes);

  Substitution *new_exp = nullptr;
  std::cerr << indent << "Inventing missing substitution\n";
  Substitution *new_sub = CreateSubstitution(Substitution::kSubstitution);
  if (std::holds_alternative<Substitution *>(curr_node)) {
    new_exp = std::get<Substitution *>(curr_node);
  } else {
    new_exp = CreateSubstitution(Substitution::kIdentity);
    new_exp->parent = new_sub;
    new_exp->before.emplace_back(std::move(curr_node));
  }

  new_sub->parent = sub;
  new_sub->after = new_exp;
  new_sub->before = std::move(missing_nodes);

  if (sub->macro_def && sub->macro_use) {
    auto in_vararg_context = sub->macro_use->Arguments().size() >
                             sub->macro_def->NumExplicitParameters();
    HandleVAOpt(new_sub, in_vararg_context);
  }

  nodes.emplace_back(new_sub);
  return true;
}

bool TokenTreeImpl::AddNodeAndMissingPrefixes(
    Substitution *sub, TokenInfo *prev, Substitution::Node curr_node,
    unsigned next_index,
    std::vector<Substitution::Node> &nodes, std::stringstream &err) {


  TokenInfo *curr = LeftCornerOfUse(curr_node);
  if (!curr) {
    std::cerr << indent << "no left corner of use\n";
    nodes.emplace_back(std::move(curr_node));
    return true;
  }

  if (curr->file_tok) {
    std::cerr
        << indent << "left corner of substitution ("
        << curr->file_tok->Index() << "): "
        << curr->file_tok->Data() << '\n';
  }

  if (TryFillBetweenFileTokens(prev, curr, sub->before_body, sub->after_body,
                               nodes)) {
    nodes.emplace_back(std::move(curr_node));
    return true;
  }

  // Try to go and find the next file token in this area.
  if (TryInventMissingSubstitutions(sub, prev, curr_node, next_index, nodes)) {
    curr_node = nodes.back();
    nodes.pop_back();
    AddNodeAndMissingPrefixes(sub, prev, std::move(curr_node), next_index,
                              nodes, err);
    std::cerr << indent << "invented substitutions\n";
    return true;
  }

  std::cerr << indent << "no invention\n";
  nodes.emplace_back(std::move(curr_node));
  return true;
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

bool TokenTreeImpl::MergeArgPreExpansions(std::stringstream &err) {
  auto max_i = substitutions_alloc.size();
  for (auto i = 0u; i < max_i; ++i) {
    Substitution *sub = &(substitutions_alloc[i]);
    Substitution *pre_exp = PreExpansionOf(sub);
    if (!pre_exp) {
      continue;
    }

    // Try to merge a pre-argument expansion.
    std::cerr << indent << "Merging pre-expansion " << pre_exp->macro_def->NameToken().Data() << '\n';
    if (MergeArgPreExpansion(sub, pre_exp, err)) {
      sub->macro_use = std::move(pre_exp->macro_use);
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

  std::cerr << indent << "Merge pre expansion\n";
  indent += "  ";

  std::vector<Substitution::Node> new_nodes;
  auto i = 0u;
  auto j = 0u;
  const auto max_i = sub->before.size();
  const auto max_j = pre_exp->before.size();

  auto num_i_args = 0u;
  auto num_j_args = 0u;
  auto changed = true;

  while (i < max_i && j < max_j) {
    if (!changed) {
      break;
    }

    changed = false;
    Substitution::Node node_i = sub->before[i];
    Substitution::Node node_j = pre_exp->before[j];

    const auto i_is_tok = std::holds_alternative<TokenInfo *>(node_i);
    TokenInfo * const i_rc = RightCornerOfExpansionOrUse(node_i);
    Substitution * const i_arg = MacroArgument(node_i);

    const auto j_is_tok = std::holds_alternative<TokenInfo *>(node_j);
    TokenInfo * const j_lc = LeftCornerOfUse(node_j);
    Substitution * const j_arg = MacroArgument(node_j);

    std::cerr
        << indent << "i=" << i << " j=" << j << " i_is_tok=" << i_is_tok
        << " j_is_tok=" << j_is_tok <<  " i_arg=" << (!!i_arg) << " j_arg="
        << (!!j_arg) << '\n';

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
          substitutions_alloc.front().PrintDOT(std::cerr);
          assert(false);
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
        substitutions_alloc.front().PrintDOT(std::cerr);
        assert(false);
        err << "Expected the first node in a use and its pre-expansion to both "
               "be tokens, or for the use to be a substitution, and the pre-"
               "expansion to be a token";
        return false;
      }

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

      new_nodes.emplace_back(std::move(node_j));
      ++i;
      ++j;
      ++num_i_args;
      ++num_j_args;
      changed = true;
      continue;

    } else if (i_arg) {
      assert(false);
      // TODO(pag): ???

    } else if (j_arg) {
      assert(false);
      // TODO(pag): ???

    } else if (i_is_tok && j_is_tok) {
      assert(j_lc->parsed_tok.has_value());

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

  std::cerr
      << indent << "i=" << i << " j=" << j << " i_max=" << max_i
      << " j_max=" << max_j << '\n';

  if (!changed || i != max_i || j != max_j) {
    substitutions_alloc.front().PrintDOT(std::cerr);
    err << "Unable to complete merge";
    return false;
  }

  // Overwrite `sub->after` to point to the pre-expansion's `after`, so that
  // we eliminate the pre-expansion use altogether.
  sub->before.swap(new_nodes);
  sub->after = pre_exp->after;
  if (sub->after) {
    sub->after->parent = sub;
  }
  indent.resize(indent.size() - 2u);
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

  body = CreateSubstitution(Substitution::kIdentity);

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

  std::cerr << indent << "Macro body of " << def.NameToken().Data() << '\n';
  indent += "  ";

  for (; it != end; ++it) {
    TokenInfo *tok = make_tok(*it);
    if (tok) {
      std::cerr << indent << tok->macro_tok->Data() << '\n';
      body->before.emplace_back(tok);
    }
  }

  StripWhitespace(body->before);
  TryAddBeforeToken(body, body->LeftCornerOfUse());
  TryAddAfterToken(body, body->RightCornerOfUse());
  assert(body->before_body != nullptr);
  assert(body->after_body != nullptr);

  indent.resize(indent.size()  - 2u);

  return body;
}

void TokenTreeImpl::TryAddBeforeToken(Substitution *sub, TokenInfo *curr) {
  UnifyToken(curr);

  if (sub->before_body || !curr || !curr->file_tok) {
    return;
  }

  if (auto index = curr->file_tok->Index()) {
    pasta::File file = pasta::File::Containing(curr->file_tok.value());
    sub->before_body = &(tokens_alloc.emplace_back());
    sub->before_body->file_tok = file.Tokens().At(index - 1u);
    sub->before_body->next = curr;
    sub->before_body->category = TokenInfo::kMissingFileToken;
    UnifyToken(sub->before_body);
  }
}

void TokenTreeImpl::TryAddAfterToken(Substitution *sub, TokenInfo *prev) {
  if (sub->after_body || !prev || !prev->file_tok) {
    return;
  }

  pasta::File file = pasta::File::Containing(prev->file_tok.value());
  sub->after_body = &(tokens_alloc.emplace_back());
  sub->after_body->file_tok = file.Tokens().At(prev->file_tok->Index() + 1u);
  sub->after_body->category = TokenInfo::kMissingFileToken;
  UnifyToken(sub->after_body);

  prev->next = sub->after_body;
}

// Get rid of leading and trailing whitespace in all internal nodes.
void TokenTreeImpl::StripWhitespace(std::vector<Substitution::Node> &nodes) {

  auto remove_ws = [&nodes, this] (void) {
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
        std::cerr << indent << "Stripping whitespace token\n";
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

void TokenTreeImpl::CollectUseTokensInto(
    const std::vector<Substitution::Node> &nodes,
    Substitution *sub) {
  for (Substitution::Node node : nodes) {
    if (std::holds_alternative<Substitution *>(node)) {
      CollectUseTokensInto(std::get<Substitution *>(node)->before, sub);
    } else {
      sub->before.emplace_back(std::move(node));
    }
  }
}

void TokenTreeImpl::HandleVAOpt(
    Substitution *sub, bool has_macro_token_in_va_opt_arg) {
  std::vector<Substitution::Node> new_nodes;
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
    if (tok->file_tok->Data() == "__VA_OPT__") {
      va_opt = CreateSubstitution(Substitution::kVAOptUse);
      va_opt->before.emplace_back(std::move(node));
      va_opt->parent = sub;
      new_nodes.emplace_back(va_opt);
      break;
    }
  }

  if (!va_opt) {
    std::cerr << indent << "Didn't find __VA_OPT__\n";
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
    std::cerr << indent << "Didn't find argument of __VA_OPT__\n";
    return;
  }

  TryAddBeforeToken(va_opt, va_opt->LeftCornerOfUse());
  TryAddAfterToken(va_opt, va_opt->RightCornerOfUse());

  if (has_macro_token_in_va_opt_arg) {
    CollectUseTokensInto(va_opt_sub->before, va_arg);
    TryAddBeforeToken(va_arg, va_arg->LeftCornerOfUse());
    TryAddAfterToken(va_arg, va_arg->RightCornerOfUse());

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
  TryAddBeforeToken(sub, sub->LeftCornerOfUse());
  TryAddAfterToken(sub, sub->RightCornerOfUse());
}

// Fill in the missing tokens from the token tree.
bool TokenTreeImpl::FillMissingFileTokens(Substitution *sub,
                                          std::stringstream &err) {

  TokenInfo *prev = nullptr;
  if (sub->before_body && sub->before_body->file_tok) {
    std::cerr
        << indent << "before_body ("
        << sub->before_body->file_tok->Index() << "): "
        << sub->before_body->file_tok->KindName() << ' '
        << sub->before_body->file_tok->Data() << '\n';
    prev = sub->before_body;
  }

  // Add in a token that must be after the macro body into the token stream.
  // This provides a convenient upper-bound for things like expansions. We'll
  // pop it off later. It'll be visible by `AddNodeAndMissingPrefixes` in the
  // below loop, but not directly visited by the loop below, because we
  // calculate `max_i` before adding `sub->after_body`.
  const auto max_i = sub->before.size();
  if (sub->after_body && sub->after_body->file_tok) {
    std::cerr
        << indent << "after_body ("
        << sub->after_body->file_tok->Index() << "): "
        << sub->after_body->file_tok->KindName() << ' '
        << sub->after_body->file_tok->Data() << '\n';
    sub->before.emplace_back(sub->after_body);
  }

  std::vector<Substitution::Node> new_nodes;

  indent += "  ";

  for (auto i = 0u; i < max_i;) {
    Substitution::Node node = sub->before[i++];
    std::cerr << indent << "{\n";
    indent += "  ";

    if (std::holds_alternative<TokenInfo *>(node)) {
      TokenInfo *nested_tok = std::get<TokenInfo *>(node);
      std::cerr << indent << "Token node";
      if (nested_tok->file_tok) {
        std::cerr << " (" << nested_tok->file_tok->Index() << "): " << nested_tok->file_tok->Data();
      }
      std::cerr << '\n';
    } else if (std::holds_alternative<Substitution *>(node)) {
      std::cerr << indent << "Substitution node\n";
      Substitution *nested_sub = std::get<Substitution *>(node);
      if (!FillMissingFileTokens(nested_sub, err)) {
        return false;
      }
    }
    if (prev) {
      if (prev->file_tok) {
        std::cerr
            << indent << "Prev (" << prev->file_tok->Index() << "): "
            << prev->file_tok->Data() << '\n';
      }
      if (!AddNodeAndMissingPrefixes(sub, prev, std::move(node),
                                     i, new_nodes, err)) {
        std::cerr << indent << "  didn't add intermediate nodes\n";
        return false;
      }
    } else {
      new_nodes.emplace_back(std::move(node));
    }

    indent.resize(indent.size() - 2u);
    std::cerr << indent << "}\n";

    if (auto next_prev = RightCornerOfUse(new_nodes.back())) {
      prev = next_prev;

    // The way we invent substitutions can sometimes result in nothing expanding
    // into something. This typically happens where there's a trailing
    // `__VA_ARGS__` in an argument list.
    } else if (auto new_rc = RightCornerOfUse(new_nodes);
               new_rc && prev == new_rc && new_rc->file_tok &&
               new_rc->file_tok->Data() == "__VA_ARGS__") {
      std::cerr << indent << "Added empty node that follows __VA_ARGS__";
      auto nested_sub = std::get<Substitution *>(new_nodes.back());
      new_nodes.pop_back();
      assert(std::holds_alternative<Substitution *>(new_nodes.back()));
      assert(nested_sub->before.empty());
      assert(nested_sub->after != nullptr);
      assert(!nested_sub->after->after);
      auto nested_va_args = std::get<Substitution *>(new_nodes.back());
      nested_va_args->after->before.insert(
          nested_va_args->after->before.end(),
          nested_sub->after->before.begin(), nested_sub->after->before.end());

    // This isn't ideal, so in a debug build we want to know about it, but in
    // a release build, at least something not too unreasonable will happen.
    } else {
      assert(false);
    }
  }

  if (sub != &(substitutions_alloc.front())) {
    StripWhitespace(new_nodes);
  }

  sub->before.swap(new_nodes);

  if (sub->kind == Substitution::kMacroExpansion && sub->macro_use) {
    HandleVAOpt(sub);
  }

  if (sub->after) {
    if (!FillMissingFileTokens(sub->after, err)) {
      return false;
    }
  }

  indent.resize(indent.size() - 2u);
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

  if (curr->macro_tok->RawNode() != node->RawNode()) {
    err << "Could not align macro token with " << curr->parsed_tok->Data();
    return nullptr;
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

  Substitution *exp_use = CreateSubstitution(Substitution::kSubstitution);
  Substitution *exp_sub = CreateSubstitution(Substitution::kIdentity);
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

  exp_sub->before_body = macro_body->before_body;
  exp_sub->after_body = macro_body->after_body;

  return sub;
}

Substitution *TokenTreeImpl::BuildMacroSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    std::optional<pasta::MacroDirective> node, std::stringstream &err) {
  Substitution *dir_use = CreateSubstitution(Substitution::kDirective);
  sub->before.emplace_back(dir_use);
  sub->parent = sub;

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

  TokenInfo * const before_body = curr;

  // Skip the marker token.
  DCHECK(curr->parsed_tok->Role() ==
         pasta::TokenRole::kBeginOfMacroExpansionMarker);
  prev = curr;
  curr = curr->next;

  assert(curr != nullptr);

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

  // Skip the marker.
  prev = curr;
  curr = curr->next;

  return sub;
}

Substitution *TokenTreeImpl::BuildSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, std::stringstream &err) {

  Substitution *sub = CreateSubstitution(Substitution::kIdentity);
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
    } else {
      TryAddAfterToken(sub, prev);
    }
  }

  return sub;
}

void TokenTreeImpl::FindSubstitutionBounds(void) {
  for (Substitution &sub : substitutions_alloc) {
    TryAddBeforeToken(&sub, sub.LeftCornerOfUse());
    TryAddAfterToken(&sub, sub.RightCornerOfUse());

    if (!sub.before_body || !sub.after_body) {
      continue;
    }

    if (!sub.before_body->file_tok) {
      sub.before_body = nullptr;
      continue;
    }

    if (!sub.after_body->file_tok) {
      sub.after_body = nullptr;
      continue;
    }

    if (pasta::File::Containing(sub.before_body->file_tok.value()) !=
        pasta::File::Containing(sub.after_body->file_tok.value())) {
      sub.before_body = nullptr;
      sub.after_body = nullptr;
      continue;
    }

    if (sub.before_body->file_tok->Index() >
        sub.after_body->file_tok->Index()) {
      assert(false);
      sub.before_body = nullptr;
      sub.after_body = nullptr;
      continue;
    }
  }
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

  UnifyTokens(first);

  if (!MergeArgPreExpansions(err)) {
    return nullptr;
  }

  FindSubstitutionBounds();

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
  }

  std::optional<pasta::Token> derived_loc =
      curr->parsed_tok->DerivedLocation();
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
  }
  if (!prev_set->file_tok) {
    prev_set->file_tok = derived_loc->FileLocation();
  }

  assert(parsed_set == parsed_set->Root());
  assert(prev_set == prev_set->Root());
  parsed_set->root = prev_set;  // Unify.
  return prev_set;
}

// Try to unify tokens in the token list back to the same file token.
void TokenTreeImpl::UnifyTokens(TokenInfo *first) {
  for (TokenInfo &curr : tokens_alloc) {
    UnifyToken(&curr);
  }

  for (TokenInfo &curr : tokens_alloc) {
    if (TokenSet *root_set = Root(&curr)) {
      assert(root_set->info != nullptr);
      assert(!curr.file_tok || (curr.file_tok && root_set->file_tok));
      curr.file_tok = root_set->file_tok;
    }
  }
}

TokenTree::~TokenTree(void) {}

// Create a token tree from the tokens in the inclusive range
// `[begin_index, end_index]` from `range`.
mx::Result<TokenTree, std::string>
TokenTree::Create(pasta::TokenRange range, uint64_t begin_index,
                  uint64_t end_index) {
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

  // Try to get a token that exists before and after `range`.

  // Build and classify the initial list of tokens.
  if (!impl->BuildInitialTokenList(std::move(range), begin_index,
                                   end_index, err)) {
    return err.str();
  }

  Substitution *sub = impl->BuildSubstitutions(err);
  if (!sub) {
    return err.str();
  }

  // Fill in things like whitespace gaps between file tokens. This doesn't
  // do any tracking of substitutions.
  if (!impl->FillMissingFileTokens(sub, err)) {
    return err.str();
  }

  std::cerr << "----------------------------------------------------- " << begin_index << " to " << end_index << " ---\n";

  std::cerr << "----------------------------------------------------- " << impl->tokens_alloc.size() << " ---\n";
  sub->Print(std::cerr);
  std::cerr << "\n\n\n";
  sub->PrintDOT(std::cerr);
  std::cerr << "\n\n\n";
  return std::string();

  std::shared_ptr<const Substitution> ret(std::move(impl), sub);
  return TokenTree(std::move(ret));
}

std::optional<pasta::FileToken> TokenTreeNode::FileToken(void) const noexcept {
  if (const auto &ent = impl->before[offset];
      std::holds_alternative<TokenInfo *>(ent)) {
    return std::get<TokenInfo *>(ent)->file_tok;
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

std::optional<std::tuple<mx::TokenSubstitutionKind, TokenTree, TokenTree>>
TokenTreeNode::MaybeSubstitution(void) const noexcept {
  if (const auto &ent = impl->before[offset];
      std::holds_alternative<class Substitution *>(ent)) {
    auto lhs = std::get<class Substitution *>(ent);
    auto rhs = lhs->after;
    CHECK_NOTNULL(rhs);

    TokenTree before(std::shared_ptr<const class Substitution>(impl, lhs));
    TokenTree after(std::shared_ptr<const class Substitution>(impl, rhs));

    switch (lhs->kind) {
      case Substitution::kInclusion:
        return std::make_tuple(
            mx::TokenSubstitutionKind::INCLUDE_EXPANSION,
            std::move(before), std::move(after));

      case Substitution::kMacroUse:
      case Substitution::kVAOptUse:
        if (lhs->before.size() == 1u) {
          return std::make_tuple(
              mx::TokenSubstitutionKind::MACRO_EXPANSION,
              std::move(before), std::move(after));
        } else {
          return std::make_tuple(
              mx::TokenSubstitutionKind::FUNCTION_LIKE_MACRO_EXPANSION,
              std::move(before), std::move(after));
        }

      case Substitution::kSubstitution:
        return std::make_tuple(
            mx::TokenSubstitutionKind::SUBSTITUTION,
            std::move(before), std::move(after));

      case Substitution::kDefinition:
      case Substitution::kDirective:
      case Substitution::kMacroArgument:
      case Substitution::kMacroExpansion:
      case Substitution::kVAOptArgument:
      case Substitution::kVAOptExpansion:
      case Substitution::kIdentity:
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
