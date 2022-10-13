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
  TokenInfo *root{nullptr};

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

    // Normal macro substitution kind. `before` points to a sequence of file
    // tokens, `after` points to its expansion.
    kMacroUse,
    kMacroExpansion,

    // An inclusion of a file nested inside of a top-level declaration, and so
    // the inclusion manifests as a kind of macro expansion.
    kInclusion,
    kDefinition,
    kDirective

  } kind;

  std::vector<std::variant<TokenInfo *, Substitution *>> before;

  Substitution *after{nullptr};

  explicit Substitution(Kind kind_)
      : kind(kind_) {}

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

  // Substitution stack keeps track of file tokens and their substitutions.
  std::vector<Substitution *> substitutions;

  // Stack of substitutions associated with includes. When we exit a file, we
  // can set it as the `after` of the top substitution on this stack, then
  // pop it off.
  std::vector<Substitution *> includes;

  std::string data;

  // Build an initial token info list. This contains all of the tokens that were
  // parsed, plus the file tokens that were macro uses. This does not contain
  // file tokens that were elided due to things like conditional macros, e.g.
  // `#if 0`.
  TokenInfo *BuildInitialTokenList(pasta::TokenRange range,
                                   uint64_t begin_index,
                                   uint64_t end_index,
                                   std::stringstream &err);

  TokenInfo *FillBetweenFileTokesnInSameFile(
      TokenInfo *prev, TokenInfo *curr, pasta::File file,
      pasta::FileToken prev_file_tok, pasta::FileToken curr_file_tok);

  // Fill in any missing tokens from a file between `prev` and `curr`.
  void FillBetweenFileTokens(TokenInfo *prev_file_tok, TokenInfo *prev,
                             TokenInfo *curr);

//  bool FillMacroToken(TokenInfo *&prev, TokenInfo *&curr,
//                      const pasta::MacroToken &node,
//                      std::stringstream &err);

//  // Fill in the missing tokens from the token tree.
//  bool FillTokensFromMacro(TokenInfo *&prev, TokenInfo *&curr,
//                           pasta::MacroNode node,
//                           std::stringstream &err);

  // Fill in the missing tokens from the token tree.
  bool FillMissingFileTokens(std::stringstream &err);


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
    os << "<TR><TD>PK=" << info->parsed_tok->KindName() << "</TD></TR>";
    if (info->root) {
//
//      if (info->root->parsed_tok) {
//        os << "<TR><TD>PT=" << info->root->parsed_tok->Index() << "</TD></TR>";
//      }

      if (info->root->file_tok) {
        os << "<TR><TD>FT=" << info->root->file_tok->Index() << "</TD></TR>";
      }
    }

    os << "<TR><TD><B>" << TokData(info->parsed_tok.value()) << "</B></TD></TR>";
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

//static bool IsIncludeKeyword(pasta::FileToken ft) {
//  switch (ft.PreProcessorKeywordKind()) {
//    case pasta::PPKeywordKind::kInclude:
//    case pasta::PPKeywordKind::kIncludeNext:
//    case pasta::PPKeywordKind::kImport:
//      return true;
//    default:
//      return false;
//  }
//}

TokenInfo *TokenTreeImpl::FillBetweenFileTokesnInSameFile(
    TokenInfo *prev, TokenInfo *curr, pasta::File file,
    pasta::FileToken prev_file_tok, pasta::FileToken curr_file_tok) {
  assert(false);
//  pasta::FileTokenRange tokens = file.Tokens();
//  auto i = prev_file_tok.Index() + 1u;  // `prev` is already present.
//  auto max_i = curr_file_tok.Index();
//  CHECK_LE(i, max_i);
//  std::cerr << "FillBetweenFileTokesnInSameFile(" << i << ", " << max_i << ")\n";
//  for (; i < max_i; ++i) {
//    TokenInfo &info = tokens_alloc.emplace_back();
//    info.file_tok = tokens[i];
//    std::cerr << " Adding token(" << i << "): " << info.file_tok->Data() << '\n';
//    info.category = TokenInfo::kMissingFileToken;
//    info.next = curr;
//    prev->next = &info;
//    prev = &info;
//  }
//
//  CHECK_EQ(i, max_i);
//  CHECK(prev->file_tok.has_value());
  return prev;
}

// Fill in any missing tokens from a file between `prev` and `curr`.
//
// Invariant: `prev_top_level` has a file token. `prev->next == curr`.
void TokenTreeImpl::FillBetweenFileTokens(TokenInfo *prev_top_level,
                                          TokenInfo *prev,
                                          TokenInfo *curr) {
  DCHECK_NE(prev_top_level, curr);
  DCHECK_EQ(prev->next, curr);
  DCHECK(prev_top_level->file_tok.has_value());
  DCHECK(curr->file_tok.has_value());

  pasta::FileToken prev_file_tok = prev_top_level->file_tok.value();
  pasta::FileToken curr_file_tok = curr->file_tok.value();
  pasta::File prev_file = pasta::File::Containing(prev_file_tok);
  pasta::File curr_file = pasta::File::Containing(curr_file_tok);

  // Happy path, fill between the two sets of tokens.
  if (prev_file == curr_file) {
    FillBetweenFileTokesnInSameFile(prev, curr, std::move(curr_file),
                                    std::move(prev_file_tok),
                                    std::move(curr_file_tok));
    return;
  }

  // Unhappy path. This relates to an `#include` directive. This breaks down
  // into two cases:
  //
  //    1)  `prev_file` contains an `#include`. We want the substitution of
  //        that include to be the tokens of `curr_file`. We might need to fill
  //        in missing tokens from the beginning of `curr_file`.
  //
  //    2)  `curr_file` contains an `#include`, and `prev_file` is the file
  //        that was included. Thus we are leaving `prev_file`, and might need
  //        to fill in missing tokens from the end of `prev_file`, and then
  //        "complete" the substitution of the `#include`.
  LOG(ERROR) << "Unhappy path!";
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

// Fill in the missing tokens from the token tree.
bool TokenTreeImpl::FillMissingFileTokens(std::stringstream &err) {
  assert(false);
//  // Previous top-level file token.
//  std::vector<TokenInfo *> prev_top_levels;
//  prev_top_levels.push_back(nullptr);
//
//  // Iterate over the initial tokens filled in.
//  for (TokenInfo *curr = &(tokens_alloc.front()), *prev = nullptr; curr;
//       prev = curr, curr = curr->next) {
//    TokenInfo * const prev_top_level = prev_top_levels.back();
//
//    DCHECK_NE(prev_top_level, curr);
//    DCHECK(curr->parsed_tok.has_value());
//
//    const pasta::TokenRole role = curr->parsed_tok->Role();
//    switch (curr->category) {
//      case TokenInfo::kMarkerToken:
//        switch (role) {
//          case pasta::TokenRole::kBeginOfFileMarker:
//            prev_top_levels.push_back(nullptr);
//            break;
//          case pasta::TokenRole::kEndOfFileMarker:
//            prev_top_levels.pop_back();
//            break;
//          default:
//            break;
//        }
//        break;
//
//      case TokenInfo::kFileToken:
//      case TokenInfo::kMacroUseToken:
//        if (curr->file_tok.has_value()) {
//          DCHECK(curr->file_tok.has_value());
//          if (prev_top_level) {
//            DCHECK(prev_top_level->file_tok.has_value());
//            std::cerr << "prev(" << prev_top_level->file_tok->Index() << "): " << prev_top_level->file_tok->Data() << '\n';
//            std::cerr << "curr(" << curr->file_tok->Index() << "): " << curr->file_tok->Data() << '\n';
//            FillBetweenFileTokens(prev_top_level, prev, curr);
//          }
//          prev_top_levels.back() = curr;
//        }
//        break;
//
//      case TokenInfo::kMacroStepToken:
//      case TokenInfo::kMacroExpansionToken:
//        DCHECK_NOTNULL(prev_top_level);
//        DCHECK(curr->parsed_tok.has_value());
//        DCHECK(curr->parsed_tok->MacroLocation().has_value());
//        DCHECK(!curr->file_tok.has_value());
//        break;
//
//      default:
//        err
//            << "Unexpected token info category in token list";
//        return false;
//    }
//  }

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

  Substitution *arg_sub = CreateSubstitution(Substitution::kIdentity);
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

  Substitution *exp_use = CreateSubstitution(Substitution::kMacroUse);
  Substitution *exp_sub = CreateSubstitution(Substitution::kMacroExpansion);
  exp_use->after = exp_sub;
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
    std::optional<pasta::MacroDirective> node, std::stringstream &err) {
  Substitution *dir_use = CreateSubstitution(Substitution::kDirective);
  sub->before.emplace_back(dir_use);

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

  // Skip the marker.
  prev = curr;
  curr = curr->next;
  return sub;
}

Substitution *TokenTreeImpl::BuildFileSubstitutions(
    TokenInfo *&prev, TokenInfo *&curr, Substitution *sub,
    std::stringstream &err) {

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
        switch (curr->parsed_tok->Role()) {
          case pasta::TokenRole::kBeginOfFileMarker:
            sub = BuildFileSubstitutions(prev, curr, sub, err);
            if (!sub) {
              return nullptr;
            }
            continue;

          case pasta::TokenRole::kEndOfFileMarker:
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

  return sub;
}

Substitution *TokenTreeImpl::BuildSubstitutions(std::stringstream &err) {
  std::vector<Substitution *> subs;

  TokenInfo *prev = nullptr;
  TokenInfo * const first = &(tokens_alloc.front());
  TokenInfo *curr = first;  // NOTE(pag): Updated by reference.
  if (auto sub = BuildSubstitutions(prev, curr, err)) {
    UnifyTokens(first);
    return sub;
  }

  return nullptr;
}

// Try to unify tokens in the token list back to the same file token.
void TokenTreeImpl::UnifyTokens(TokenInfo *first) {
  std::unordered_map<const void *, TokenSet> parsed_sets;

  for (TokenInfo *curr = first; curr; curr = curr->next) {
    assert(curr->parsed_tok.has_value());
    if (!curr->parsed_tok) {
      continue;
    }

    TokenSet &parsed_set = parsed_sets[curr->parsed_tok->RawToken()];
    if (!parsed_set.info) {
      parsed_set.info = curr;
    }
    if (!parsed_set.file_tok) {
      parsed_set.file_tok = curr->file_tok;
    }

    std::optional<pasta::Token> derived_loc =
        curr->parsed_tok->DerivedLocation();
    if (!derived_loc) {
      continue;
    }

    TokenSet *prev_set = parsed_sets[derived_loc->RawToken()].Root();
    if (prev_set == &parsed_set) {
      continue;
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

    parsed_set.Root()->root = prev_set;  // Unify.
  }

  for (TokenInfo *curr = first; curr; curr = curr->next) {
    assert(curr->parsed_tok.has_value());
    if (!curr->parsed_tok) {
      continue;
    }

    TokenSet *root_set = parsed_sets[curr->parsed_tok->RawToken()].Root();
    assert(root_set->info != nullptr);
    assert(!curr->file_tok || (curr->file_tok && root_set->file_tok));
    curr->root = root_set->info;
    assert(curr->root != nullptr);
    curr->file_tok = root_set->file_tok;
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

  // Build and classify the initial list of tokens.
  if (!impl->BuildInitialTokenList(std::move(range), begin_index,
                                   end_index, err)) {
    return err.str();
  }

//  // Fill in things like whitespace gaps between file tokens. This doesn't
//  // do any tracking of substitutions.
//  if (!impl->FillMissingFileTokens(err)) {
//    return err.str();
//  }

  Substitution *sub = impl->BuildSubstitutions(err);
  if (!sub) {
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
        if (lhs->before.size() == 1u) {
          return std::make_tuple(
              mx::TokenSubstitutionKind::MACRO_EXPANSION,
              std::move(before), std::move(after));
        } else {
          return std::make_tuple(
              mx::TokenSubstitutionKind::FUNCTION_LIKE_MACRO_EXPANSION,
              std::move(before), std::move(after));
        }

      case Substitution::kDefinition:
      case Substitution::kDirective:
      case Substitution::kMacroExpansion:
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
