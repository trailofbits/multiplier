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
#include <vector>

#include <iostream>

namespace indexer {

struct TokenInfo {
  enum Category {
    // A token, produced as a result of macro expansion, but somewhere between
    // use and parse, i.e. this is not parsed.
    kMacroStepToken,

    // A parsed token, produced as a result of macro expansion.
    kMacroExpansionToken,

    // A file token, introduced because it was part of the file, and was
    // missing in the parse because it was a macro use.
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

// Represents a token substitution. This can be due to a macro expansion, or
// due to an X-macro file inclusion (i.e. where an include is nested inside
// of a declaration, and then the included file expands macros).
class Substitution {
 public:
  const enum Kind {
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
  void BuildInitialTokenList(pasta::TokenRange range,
                             uint64_t begin_index,
                             uint64_t end_index);

  TokenInfo *FillBetweenFileTokesnInSameFile(
      TokenInfo *prev, TokenInfo *curr, pasta::File file,
      pasta::FileToken prev_file_tok, pasta::FileToken curr_file_tok);

  // Fill in any missing tokens from a file between `prev` and `curr`.
  TokenInfo *FillBetweenFileTokens(TokenInfo *prev, TokenInfo *curr);

  bool FillMacroToken(TokenInfo *&prev, TokenInfo *&curr,
                      const pasta::MacroToken &node,
                      std::stringstream &err);

  // Fill in the missing tokens from the token tree.
  bool FillTokensFromMacro(TokenInfo *&prev, TokenInfo *&curr,
                           pasta::MacroNode node,
                           std::stringstream &err);

  // Fill in the missing tokens from the token tree.
  Substitution *FillMissingFileTokens(std::stringstream &err);

  void AddTokenToSubstitution(TokenInfo *tok);

  Substitution *CreateSubstitution(Substitution::Kind kind);
};

static std::string TokData(std::string_view data) {
  std::stringstream ss;
  for (auto ch : data) {
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
  auto dump_ft = [&] (TokenInfo *info) {
    if (auto tk = info->file_tok->Kind();
        tk == pasta::TokenKind::kComment || tk == pasta::TokenKind::kUnknown) {
      // Skip.
    } else if (tk == pasta::TokenKind::kCharacterConstant ||
               tk == pasta::TokenKind::kUtf8CharacterConstant ||
               tk == pasta::TokenKind::kUtf16CharacterConstant ||
               tk == pasta::TokenKind::kUtf32CharacterConstant ||
               tk == pasta::TokenKind::kWideCharacterConstant ||
               tk == pasta::TokenKind::kStringLiteral ||
               tk == pasta::TokenKind::kUtf8StringLiteral ||
               tk == pasta::TokenKind::kUtf16StringLiteral ||
               tk == pasta::TokenKind::kUtf32StringLiteral ||
               tk == pasta::TokenKind::kWideStringLiteral) {

      os << "<TD>&lt;str&gt;</TD>";
      has_any = true;

    } else {
      os << "<TD>" << TokData(info->file_tok->Data()) << "</TD>";
      has_any = true;
    }
  };

  auto i = 0;
  for (auto ent : before) {
    if (std::holds_alternative<TokenInfo *>(ent)) {
      auto info = std::get<TokenInfo *>(ent);
      switch (info->category) {
        case TokenInfo::kFileToken:
          dump_ft(info);
          continue;
        case TokenInfo::kMacroExpansionToken:
          os << "<TD>" << TokData(info->parsed_tok->Data()) << "</TD>";
          has_any = true;
          continue;
        case TokenInfo::kMacroUseToken:
        case TokenInfo::kMissingFileToken:
          dump_ft(info);
          continue;
        case TokenInfo::kMacroStepToken:
        case TokenInfo::kMarkerToken:
          continue;
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
void TokenTreeImpl::BuildInitialTokenList(pasta::TokenRange range,
                                          uint64_t begin_index,
                                          uint64_t end_index) {
  int macro_depth = 0;
  for (auto i = begin_index; i <= end_index; ++i) {
    pasta::Token tok = range[i];
    switch (tok.Role()) {
      case pasta::TokenRole::kInvalid:
        DLOG(FATAL)
            << "Invalid or unexpected token in range";
        tokens_alloc.clear();
        return;

      case pasta::TokenRole::kBeginOfMacroExpansionMarker: {
        DCHECK(tok.FileLocation().has_value());
        auto &info = tokens_alloc.emplace_back();
        info.file_tok = tok.FileLocation();
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kMarkerToken;
        ++macro_depth;
        break;
      }

      case pasta::TokenRole::kEndOfMacroExpansionMarker: {
        DCHECK(tok.FileLocation().has_value());
        auto &info = tokens_alloc.emplace_back();
        info.file_tok = tok.FileLocation();
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kMarkerToken;
        --macro_depth;
        DCHECK_LE(0, macro_depth);
        break;
      }

      case pasta::TokenRole::kIntermediateMacroExpansionToken: {
        DCHECK_LT(0, macro_depth);
        auto &info = tokens_alloc.emplace_back();
        if (auto file_tok = tok.FileLocation()) {
          info.file_tok = std::move(file_tok);
          info.category = TokenInfo::kMacroUseToken;
        } else {
          info.category = TokenInfo::kMacroStepToken;
        }
        info.parsed_tok = std::move(tok);
        break;
      }
      case pasta::TokenRole::kFinalMacroExpansionToken: {
        DCHECK_LT(0, macro_depth);
        auto &info = tokens_alloc.emplace_back();
        if (auto file_tok = tok.FileLocation()) {
          info.file_tok = std::move(file_tok);
        }
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kMacroExpansionToken;
        break;
      }

      case pasta::TokenRole::kBeginOfFileMarker:
      case pasta::TokenRole::kEndOfFileMarker: {
        DCHECK(tok.FileLocation().has_value());
        auto &info = tokens_alloc.emplace_back();
        info.file_tok = tok.FileLocation();
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kMarkerToken;
        break;
      }

      case pasta::TokenRole::kFileToken: {
        DCHECK_EQ(0, macro_depth);
        auto &info = tokens_alloc.emplace_back();
        info.file_tok = tok.FileLocation();
        DCHECK(info.file_tok.has_value());
        DCHECK_EQ(info.file_tok->Data(), tok.Data());
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kFileToken;
        break;
      }
    }
  }

  // Link them all together.
  auto it = tokens_alloc.begin();
  auto end = tokens_alloc.end();
  if (it != end) {
    TokenInfo *prev = &*it;
    for (++it; it != end; ++it) {
      TokenInfo *curr = &*it;
      prev->next = curr;
      prev = curr;
    }
  }
}

void TokenTreeImpl::AddTokenToSubstitution(TokenInfo *tok) {
  CHECK(!substitutions.empty());
  substitutions.back()->before.emplace_back(tok);
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
  pasta::FileTokenRange tokens = file.Tokens();
  auto i = prev_file_tok.Index();
  auto max_i = curr_file_tok.Index();
  for (; i < max_i; ++i) {
    TokenInfo &info = tokens_alloc.emplace_back();
    info.file_tok = std::move(prev_file_tok);
    info.category = TokenInfo::kMissingFileToken;
    info.next = curr;
    prev_file_tok = tokens[i];
    prev->next = &info;
    prev = &info;
  }

  CHECK_EQ(i, max_i);
  return prev;
}

// Fill in any missing tokens from a file between `prev` and `curr`.
TokenInfo *TokenTreeImpl::FillBetweenFileTokens(TokenInfo *prev,
                                                TokenInfo *curr) {
  DCHECK_NE(prev, curr);

  if (!prev->file_tok.has_value()) {
    return prev;
  }

  if (!curr->file_tok.has_value()) {
    return prev;
  }

  pasta::FileToken prev_file_tok = prev->file_tok.value();
  pasta::FileToken curr_file_tok = curr->file_tok.value();
  pasta::File prev_file = pasta::File::Containing(prev_file_tok);
  pasta::File curr_file = pasta::File::Containing(curr_file_tok);

  // Happy path, fill between the two sets of tokens.
  if (prev_file == curr_file) {
    return FillBetweenFileTokesnInSameFile(prev, curr, std::move(curr_file),
                                           std::move(prev_file_tok),
                                           std::move(curr_file_tok));
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

  return prev;
}

static pasta::MacroNode RootNodeFrom(pasta::MacroNode node) {
  if (auto parent = node.Parent()) {
    return RootNodeFrom(parent.value());
  } else {
    return node;
  }
}

bool TokenTreeImpl::FillMacroToken(TokenInfo *&prev, TokenInfo *&curr,
                                   const pasta::MacroToken &node,
                                   std::stringstream &err) {

  switch (curr->category) {
    // This is a intermediate or final macro expansion token.
    case TokenInfo::kMacroExpansionToken:
    case TokenInfo::kMacroStepToken:
      CHECK(curr->parsed_tok.has_value());
      CHECK(curr->parsed_tok == node.ParsedLocation());
      break;

    // This is a macro usage token.
    case TokenInfo::kMacroUseToken:
      CHECK(curr->parsed_tok.has_value());
      CHECK(curr->file_tok == node.FileLocation());
      if (prev) {
        prev = FillBetweenFileTokens(prev, curr);
      }
      break;

    default:
      err << "Trying to fill a macro token, but next token "
             "info kind is not associated with a macro";
      return false;
  }

  curr->macro_tok = node;
  AddTokenToSubstitution(curr);
  prev = curr;
  curr = curr->next;
  return true;
}

// Fill in the missing tokens from the token tree.
bool TokenTreeImpl::FillTokensFromMacro(TokenInfo *&prev, TokenInfo *&curr,
                                        pasta::MacroNode node,
                                        std::stringstream &err) {

  auto fill_nodes = [&, this] (pasta::MacroNodeRange range) -> bool {
    for (pasta::MacroNode child_node : range) {
      if (!FillTokensFromMacro(prev, curr, std::move(child_node), err)) {
        return false;
      }
    }
    return true;
  };

  auto do_directive =
      [&, this] (Substitution::Kind kind) -> bool {
        const auto &dir = reinterpret_cast<const pasta::MacroDirective &>(node);
        const auto hash_file_tok = dir.HashToken().FileLocation();
        if (!hash_file_tok) {
          err
              << "Unable to find file containing hash token of directive";
          return false;
        }
        auto sub = CreateSubstitution(kind);
        if (kind == Substitution::kInclusion) {
          includes.push_back(sub);
        }
        substitutions.push_back(sub);
        if (!fill_nodes(dir.Nodes())) {
          return false;
        }
        DCHECK_EQ(substitutions.back(), sub);
        substitutions.pop_back();
        return true;
      };

  switch (node.Kind()) {
    case pasta::MacroNodeKind::kToken:
      return FillMacroToken(
          prev, curr, reinterpret_cast<pasta::MacroToken &>(node), err);

    case pasta::MacroNodeKind::kExpansion:
    case pasta::MacroNodeKind::kSubstitution: {
      auto &sub = reinterpret_cast<pasta::MacroSubstitution &>(node);
      Substitution *use = CreateSubstitution(Substitution::kMacroUse);
      use->after = CreateSubstitution(Substitution::kMacroExpansion);

      // Process the used tokens.
      substitutions.push_back(use);
      if (!fill_nodes(sub.UsageNodes())) {
        return false;
      }
      DCHECK_EQ(substitutions.back(), use);
      substitutions.pop_back();

      // Process the substituted tokens.
      substitutions.push_back(use->after);
      if (!fill_nodes(sub.SubstitutionNodes())) {
        return false;
      }
      DCHECK_EQ(substitutions.back(), use->after);
      substitutions.pop_back();
      return true;
    }

    case pasta::MacroNodeKind::kDirective:
      return do_directive(Substitution::kDirective);
    case pasta::MacroNodeKind::kDefine:
      return do_directive(Substitution::kDefinition);
    case pasta::MacroNodeKind::kInclude:
      return do_directive(Substitution::kInclusion);

    case pasta::MacroNodeKind::kArgument:
      return fill_nodes(reinterpret_cast<pasta::MacroArgument &>(node).Nodes());
  }

  return false;
}

// Fill in the missing tokens from the token tree.
Substitution *TokenTreeImpl::FillMissingFileTokens(std::stringstream &err) {

  substitutions.push_back(CreateSubstitution(Substitution::kIdentity));

  TokenInfo *prev = nullptr;
  std::optional<pasta::MacroNode> node_to_process;

  // Iterate over the initial tokens filled in. These should all have file
  for (TokenInfo *curr = &(tokens_alloc.front()); curr; curr = curr->next) {
    DCHECK_NE(prev, curr);
    DCHECK(curr->parsed_tok.has_value());

    const pasta::TokenRole role = curr->parsed_tok->Role();
    switch (curr->category) {
      case TokenInfo::kMarkerToken:
      case TokenInfo::kFileToken:
        if (role == pasta::TokenRole::kBeginOfFileMarker) {
          substitutions.push_back(CreateSubstitution(Substitution::kIdentity));
        }

        DCHECK(curr->file_tok.has_value());
        if (prev) {
          prev = FillBetweenFileTokens(prev, curr);
        } else {
          prev = curr;
        }
        AddTokenToSubstitution(curr);

        if (role == pasta::TokenRole::kEndOfFileMarker) {
          if (!includes.empty()) {
            includes.back()->after = substitutions.back();
            includes.pop_back();
          }

          // If we entered a file.
          //
          // NOTE(pag): There can be subtle interactions between this and
          //            `FindDeclRange` in `IndexCompileJob.cpp` in the presence
          //            of corner cases.
          if (1u < substitutions.size()) {
            substitutions.pop_back();
          }
        }
        break;

      // Fill in the macro tokens and substitutions.
      case TokenInfo::kMacroUseToken:
      case TokenInfo::kMacroStepToken:
      case TokenInfo::kMacroExpansionToken: {
        std::optional<pasta::MacroToken> macro_tok =
            curr->parsed_tok->MacroLocation();
        DCHECK(macro_tok.has_value());
        if (!FillTokensFromMacro(
            prev, curr, RootNodeFrom(macro_tok.value()), err)) {
          return nullptr;
        }
        break;
      }
      default:
        err
            << "Unexpected token info category in token list";
        return nullptr;
    }
  }

  CHECK_EQ(substitutions.size(), 1u);
  return substitutions.back();
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
  impl->BuildInitialTokenList(std::move(range), begin_index, end_index);
  if (impl->tokens_alloc.empty()) {
    err << "Cannot create token tree from empty token range";
    return err.str();
  }

  auto sub = impl->FillMissingFileTokens(err);
  if (!sub) {
    return err.str();
  }

  std::cerr << "----------------------------------------------------- " << begin_index << " to " << end_index << " ---\n";

  std::cerr << "----------------------------------------------------- " << impl->tokens_alloc.size() << " ---\n";
  sub->Print(std::cerr);
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
