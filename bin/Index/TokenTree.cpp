// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "TokenTree.h"

#include <deque>
#include <glog/logging.h>
#include <optional>
#include <pasta/AST/Forward.h>
#include <pasta/AST/Token.h>
#include <pasta/Util/File.h>
#include <sstream>
#include <vector>

#include <iostream>

namespace mx {

struct TokenInfo {
  enum Category {
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
  Category category{kFileToken};
};

// Inclusive range `[begin, end]` of tokens.
struct TokenInfoRange {
  TokenInfo *begin;
  TokenInfo *end;
};

// Represents a token substitution. This can be due to a macro expansion, or
// due to an X-macro file inclusion (i.e. where an include is nested inside
// of a declaration, and then the included file expands macros).
struct Substitution {
  const enum Kind {
    // Default case, this is an identity substitution of `before` for itself,
    // i.e. this sustitution represents the tokens of `before`.
    kIdentity,

    // Normal macro substitution kind. `before` points to a sequence of file
    // tokens, `after` points to its expansion.
    kMacroUse,
    kMacroExpansion,

    // An inclusion of a file nested inside of a top-level declaration, and so
    // the inclusion manifests as a kind of macro expansion.
    kInclusion

  } kind;

  std::vector<std::variant<TokenInfo *, Substitution *>> before;

  Substitution *after;

  const pasta::File file;

  Substitution(Kind kind_, pasta::File file_)
      : kind(kind_),
        after(nullptr),
        file(file_) {}

  TokenInfo *RightCorner(void) {
    if (kind == Substitution::kInclusion) {
      if (after) {
        return after->RightCorner();
      }
    }
    if (!before.empty()) {
      auto ent = before.back();
      if (std::holds_alternative<TokenInfo *>(ent)) {
        return std::get<TokenInfo *>(ent);
      } else {
        return std::get<Substitution *>(ent)->RightCorner();
      }
    }
    return nullptr;
  }

  TokenInfo *RightCornerOfFile(pasta::File of_file) {
    if (file == of_file) {
      if (!before.empty()) {
        auto ent = before.back();
        if (std::holds_alternative<TokenInfo *>(ent)) {
          return std::get<TokenInfo *>(ent);
        } else {
          return std::get<Substitution *>(ent)->RightCornerOfFile(of_file);
        }
      }
    } else if (after) {
      return after->RightCornerOfFile(std::move(of_file));
    }

    return nullptr;
  }

  void Print(std::ostream &os) {
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
          case TokenInfo::kMarkerToken:
          default:
            continue;
        }
      } else {
        std::get<Substitution *>(ent)->Print(os);
      }
    }
  }

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

  void PrintDOT(std::ostream &os) {
    if (after) {
      after->PrintDOT(os);
    }

    os << "s" << reinterpret_cast<void *>(this)
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
          os << "s" << reinterpret_cast<void *>(this) << ":s" << i << " -> s"
             << reinterpret_cast<void *>(s) << " [label=\"before\"];\n"
             << "s" << reinterpret_cast<void *>(this) << ":s" << i << " -> s"
             << reinterpret_cast<void *>(s->after) << " [label=\"after\"];\n";
        } else {
          os << "s" << reinterpret_cast<void *>(this) << ":s" << i << " -> s"
             << reinterpret_cast<void *>(s) << ";\n";
        }

        ++i;
      }
    }
  }
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

  std::string data;
  std::vector<TokenKind> token_kinds;
  std::vector<unsigned> data_offsets;

  // Build an initial token info list. This contains all of the tokens that were
  // parsed, plus the file tokens that were macro uses. This does not contain
  // file tokens that were elided due to things like conditional macros, e.g.
  // `#if 0`.
  void BuildInitialTokenList(pasta::TokenRange range,
                             uint64_t begin_index,
                             uint64_t end_index);

  // Back-fill tokens from the beginning of the file `file`, up to but not
  // including the token at index `stop_index`.
  TokenInfo *BackFillFromBeginningOfFile(TokenInfo *prev, pasta::File file,
                                         uint64_t stop_index);

  // Back-fill tokens from the end of the file `file`, starting from the first
  // token after `after_index`.
  TokenInfo *BackFillFromEndOfFile(TokenInfo *prev, pasta::File file,
                                   uint64_t after_index);

  TokenInfo *BackFillFromRightCorner(
      TokenInfo *prev, TokenInfo *prev_file_token, TokenInfo *curr);

  // Back-fill tokens from between `a` and `b`, exclusive.
  TokenInfo *BackFillFromBetween(TokenInfo *prev, pasta::FileToken a,
                                 pasta::FileToken b);

  // Fill in the missing tokens from the token tree.
  Substitution *FillMissingFileTokens(std::stringstream &err);

  // Inject a missing token file token into the token stream after `prev`.
  // Return the new value for `prev`.
  TokenInfo *FillMissingToken(pasta::FileToken tok, TokenInfo *prev);

  void AddTokenToSubstitution(TokenInfo *tok);
  Substitution *CreateSubstitution(Substitution::Kind kind,
                                   pasta::File file);

  TokenInfo *HandleFileToken(TokenInfo *prev, TokenInfo *curr);
  TokenInfo *HandleMacroUseToken(TokenInfo *prev, TokenInfo *curr);
  TokenInfo *HandleMacroExpansionToken(TokenInfo *prev, TokenInfo *curr,
                                       std::stringstream &err);
  TokenInfo *HandleMarkerToken(TokenInfo *prev, TokenInfo *curr,
                               std::stringstream &err);

  TokenInfo *HandleBeginningOfFileMacroPath(TokenInfo *prev, TokenInfo *curr,
                                            std::stringstream &err);
  TokenInfo *HandleBeginningOfFile(TokenInfo *prev, TokenInfo *curr,
                                   std::stringstream &err);
  TokenInfo *HandleEndOfFile(TokenInfo *prev, TokenInfo *curr,
                             std::stringstream &err);
  TokenInfo *HandleBeginOfMacroExpansion(TokenInfo *prev, TokenInfo *curr,
                                         std::stringstream &err);
  TokenInfo *HandleEndOfMacroExpansion(TokenInfo *prev, TokenInfo *curr,
                                       std::stringstream &err);
};

// Back-fill tokens from the beginning of the file `file`, up to but not
// including the token at index `stop_index`.
TokenInfo *TokenTreeImpl::BackFillFromBeginningOfFile(TokenInfo *prev,
                                                      pasta::File file,
                                                      uint64_t stop_index) {
  pasta::FileTokenRange file_toks = file.Tokens();
  for (uint64_t i = 0u; i < stop_index; ++i) {
    prev = FillMissingToken(file_toks[i], prev);
  }
  return prev;
}

// Back-fill tokens from the end of the file `file`, starting from the first
// token after `after_index`.
TokenInfo *TokenTreeImpl::BackFillFromEndOfFile(
    TokenInfo *prev, pasta::File file, uint64_t after_index) {
  pasta::FileTokenRange file_toks = file.Tokens();
  auto max_i = file_toks.Size();
  for (uint64_t i = after_index + 1u; i < max_i; ++i) {
    prev = FillMissingToken(file_toks[i], prev);
  }
  return prev;
}

// Back-fill tokens from between `a` and `b`, exclusive.
TokenInfo *TokenTreeImpl::BackFillFromBetween(TokenInfo *prev,
                                              pasta::FileToken a,
                                              pasta::FileToken b) {
  pasta::File fa = pasta::File::Containing(a);
  pasta::File fb = pasta::File::Containing(b);
  if (fa == fb) {
    pasta::FileTokenRange file_toks = fa.Tokens();
    auto fai = a.Index();
    auto fbi = b.Index();
    CHECK_LE(fai, fbi);
    for (auto i = fai + 1u; i < fbi; ++i) {
      prev = FillMissingToken(file_toks[i], prev);
    }
  } else {
    prev = BackFillFromEndOfFile(prev, fa, a.Index());
    prev = BackFillFromBeginningOfFile(prev, fb, b.Index());
  }
  return prev;
}

TokenInfo *TokenTreeImpl::BackFillFromRightCorner(
    TokenInfo *prev, TokenInfo *prev_file_token, TokenInfo *curr) {
  DCHECK(!substitutions.empty());

  if (curr->file_tok.has_value()) {
    if (prev_file_token && prev_file_token->file_tok.has_value()) {
      return BackFillFromBetween(prev, prev_file_token->file_tok.value(),
                                 curr->file_tok.value());
    }
  }

  if (prev) {
    return prev;
  } else {
    return curr;
  }
}

// Build an initial token info list. This contains all of the tokens that were
// parsed, plus the file tokens that were macro uses. This does not contain
// file tokens that were elided due to things like conditional macros, e.g.
// `#if 0`.
void TokenTreeImpl::BuildInitialTokenList(pasta::TokenRange range,
                                          uint64_t begin_index,
                                          uint64_t end_index) {
  auto macro_depth = 0;
  for (auto i = begin_index; i <= end_index; ++i) {
    pasta::Token tok = range[i];

    switch (tok.Role()) {
      case pasta::TokenRole::kInvalid:
      case pasta::TokenRole::kPrintedToken:
        LOG(FATAL)
            << "Invalid or unexpected tokens in range";
        break;

      case pasta::TokenRole::kMacroExpansionToken: {
        auto &info = tokens_alloc.emplace_back();
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kMacroExpansionToken;
        continue;
      }

      case pasta::TokenRole::kBeginOfMacroExpansionMarker: {
        auto num_added = 0u;
        for (pasta::FileToken ft : tok.MacroUseTokens()) {
          auto &sub_info = tokens_alloc.emplace_back();
          sub_info.file_tok = std::move(ft);
          sub_info.category = TokenInfo::kMacroUseToken;
          ++num_added;
        }
        ++macro_depth;
        CHECK_LT(0u, num_added);
        auto &info = tokens_alloc.emplace_back();
        info.file_tok = tok.FileLocation();
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kMarkerToken;
        continue;
      }

      case pasta::TokenRole::kEndOfMacroExpansionMarker: {
        CHECK_LT(0, macro_depth);
        --macro_depth;
        auto &info = tokens_alloc.emplace_back();
        info.file_tok = tok.FileLocation();
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kMarkerToken;
        continue;
      }

      case pasta::TokenRole::kBeginOfFileMarker:
      case pasta::TokenRole::kEndOfFileMarker: {
        auto &info = tokens_alloc.emplace_back();
        info.file_tok = tok.FileLocation();
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kMarkerToken;
        continue;
      }

      case pasta::TokenRole::kFileToken: {
        CHECK_EQ(0, macro_depth);
        auto &info = tokens_alloc.emplace_back();
        info.file_tok = tok.FileLocation();
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kFileToken;
        continue;
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

// Inject a missing token file token into the token stream after `prev`.
// Return the new value for `prev`.
TokenInfo *TokenTreeImpl::FillMissingToken(pasta::FileToken tok,
                                           TokenInfo *prev) {
  switch (tok.Kind()) {
    case pasta::TokenKind::kEndOfFile:
    case pasta::TokenKind::kEndOfDirective:
    case pasta::TokenKind::kCodeCompletion:
      return prev;
    default:
      break;
  }

  TokenInfo &missing_info = tokens_alloc.emplace_back();
  missing_info.category = TokenInfo::kMissingFileToken;
  missing_info.file_tok = std::move(tok);

  if (prev) {
    missing_info.next = prev->next;
    prev->next = &missing_info;
  }

  AddTokenToSubstitution(&missing_info);

  return &missing_info;
}

void TokenTreeImpl::AddTokenToSubstitution(TokenInfo *tok) {
  if (!substitutions.empty()) {
    substitutions.back()->before.emplace_back(tok);
  }
}

Substitution *TokenTreeImpl::CreateSubstitution(Substitution::Kind kind,
                                                pasta::File file) {
  return &(substitutions_alloc.emplace_back(kind, std::move(file)));
}

TokenInfo *TokenTreeImpl::HandleFileToken(TokenInfo *prev, TokenInfo *curr) {
  CHECK(!substitutions.empty());
  CHECK(curr->file_tok.has_value());

  TokenInfo *last_from_file = substitutions.front()->RightCornerOfFile(
      pasta::File::Containing(curr->file_tok.value()));
  TokenInfo *first = BackFillFromRightCorner(
      prev, last_from_file, curr);
  AddTokenToSubstitution(curr);
  return first;
}

TokenInfo *TokenTreeImpl::HandleMacroUseToken(
    TokenInfo *prev, TokenInfo *curr) {

  CHECK(curr->file_tok.has_value());
  CHECK(!substitutions.empty());
  Substitution *parent = substitutions.back();

  TokenInfo *first = curr;

  auto curr_file = pasta::File::Containing(curr->file_tok.value());

  // Macro use is the first in the token list.
  if (!prev) {
    Substitution *use = CreateSubstitution(
        Substitution::kMacroUse, std::move(curr_file));
    parent->before.emplace_back(use);
    substitutions.push_back(use);

  // This is the Nth macro use token.
  } else if (prev->category == TokenInfo::kMacroUseToken) {
    first = prev;
    CHECK_LE(2u, substitutions.size());
    DCHECK(parent->kind == Substitution::kMacroUse);

  // This is the first macro use token, i.e. we're starting a macro.
  } else {
    DCHECK(parent->kind == Substitution::kIdentity);

    first = BackFillFromRightCorner(
        prev, substitutions.back()->RightCorner(), curr);
    Substitution *use = CreateSubstitution(
        Substitution::kMacroUse, std::move(curr_file));
    parent->before.emplace_back(use);
    substitutions.push_back(use);
  }

  AddTokenToSubstitution(curr);

  return first;
}

// Handle the beginning of a macro expansion. This should immediately follow
// the macro use tokens.
TokenInfo *TokenTreeImpl::HandleMacroExpansionToken(
    TokenInfo *prev, TokenInfo *curr, std::stringstream &err) {
  CHECK_NOTNULL(prev);

  CHECK_LE(2u, substitutions.size());
  DCHECK(substitutions.back()->kind == Substitution::kMacroExpansion);

  TokenInfo *first = prev;

  // This is the first token after the beginning of the macro expansion
  // marker.
  if (prev->category == TokenInfo::kMarkerToken) {
    CHECK(prev->parsed_tok.has_value());
    CHECK(prev->parsed_tok->Role() ==
            pasta::TokenRole::kBeginOfMacroExpansionMarker);

  // This is the Nth macro expansion token.
  } else if (prev->category == TokenInfo::kMacroExpansionToken) {

  // We don't recognize this.
  } else {
    DCHECK(false);
    err
        << "Unrecognized previous token category (" << int(prev->category)
        << ") when handling macro expansion token";
    return nullptr;
  }

  AddTokenToSubstitution(curr);
  return first;
}

static bool IsIncludeKeyword(pasta::FileToken ft) {
  switch (ft.PreProcessorKeywordKind()) {
    case pasta::PPKeywordKind::kInclude:
    case pasta::PPKeywordKind::kIncludeNext:
    case pasta::PPKeywordKind::kImport:
      return true;
    case pasta::PPKeywordKind::kNotKeyword: {
      auto data = ft.Data();
      return (data == "include" || data == "include_next" || data == "import");
    }
    default:
      return false;
  }
}

// We're entering a file, but the file path itself is the result of macro
// expansion.
TokenInfo *TokenTreeImpl::HandleBeginningOfFileMacroPath(
    TokenInfo *prev, TokenInfo *curr, std::stringstream &err) {
  CHECK_NOTNULL(prev);
  CHECK_LE(1u, substitutions.size());
  CHECK(!substitutions.empty());

  Substitution *parent = substitutions.back();
  CHECK(!parent->before.empty());
  CHECK(std::holds_alternative<Substitution *>(parent->before.back()));

  pasta::File curr_file = pasta::File::Containing(curr->file_tok.value());
  Substitution *file = CreateSubstitution(Substitution::kIdentity,
                                          std::move(curr_file));
  Substitution *inclusion = CreateSubstitution(Substitution::kInclusion,
                                               parent->file);
  TokenInfo *seen_hash = nullptr;
  TokenInfo *seen_include = nullptr;

  while (!parent->before.empty()) {
    auto ent = parent->before.back();
    parent->before.pop_back();
    inclusion->before.push_back(ent);

    if (!std::holds_alternative<TokenInfo *>(ent)) {
      seen_hash = nullptr;
      seen_include = nullptr;
      continue;
    }

    TokenInfo *ti = std::get<TokenInfo *>(ent);
    if (!ti->file_tok.has_value()) {
      continue;
    }

    pasta::FileToken ft = ti->file_tok.value();
    pasta::TokenKind tok_kind = ft.Kind();
    if (tok_kind == pasta::TokenKind::kHash) {
      if (seen_include) {
        seen_hash = ti;
        break;
      } else {
        continue;
      }

    } else if (tok_kind == pasta::TokenKind::kIdentifier ||
               tok_kind == pasta::TokenKind::kRawIdentifier) {
      if (IsIncludeKeyword(ft)) {
        seen_include = ti;
      } else {
        seen_hash = nullptr;
        seen_include = nullptr;
      }
    }
  }

  std::reverse(inclusion->before.begin(), inclusion->before.end());

  // If we dont' find the thing, then we might have had a macro expansion before
  // the inclusion but where the macro expansion is unrelated to the actual
  // file path.
  if (!seen_hash || !seen_include) {
    CHECK(parent->before.empty());
    parent->before.swap(inclusion->before);
    return nullptr;
  }

  parent->before.emplace_back(inclusion);
  inclusion->after = file;
  substitutions.push_back(file);
  AddTokenToSubstitution(curr);

  return prev;
}

// We're entering a file within a top-level declaration list. We need to go
// and find and inject the tokens prior to the `#include` directive, and
// we also want to treat the `#include` directive itself as a kind of macro
// substitution.
TokenInfo *TokenTreeImpl::HandleBeginningOfFile(
    TokenInfo *prev, TokenInfo *curr, std::stringstream &err) {

  // If the previous token is the end of a macro expansion then we're dealing
  // with a macro expansion inside of an `#include` directive, e.g.
  // `#include PATH` or `#include S(cstdio)` type of thing. This doesn't behave
  // in the same way as our normal handling, so we handle it specially.
  if (prev && prev->parsed_tok.has_value() &&
      prev->parsed_tok->Role() == pasta::TokenRole::kEndOfMacroExpansionMarker) {
    if (HandleBeginningOfFileMacroPath(prev, curr, err)) {
      return prev;
    }
  }

  CHECK(curr->file_tok.has_value());
  pasta::File curr_file = pasta::File::Containing(curr->file_tok.value());

  if (!prev) {
    Substitution *file = CreateSubstitution(
        Substitution::kIdentity, std::move(curr_file));
    substitutions.push_back(file);
    AddTokenToSubstitution(curr);
    return curr;
  }

  if (!prev->file_tok.has_value()) {
    DCHECK(false);
    err << "Beginning of file marker token is preceded by a token "
        << "without a file location";
    return nullptr;
  }

  CHECK(!substitutions.empty());

  Substitution *parent = substitutions.back();
  TokenInfo *prev_file_token = nullptr;

  // There's a macro expansion that happens just before the `#include`.
  if (prev->parsed_tok->Role() ==
      pasta::TokenRole::kEndOfMacroExpansionMarker) {
    prev_file_token = prev;

  // We have an include following an include.
  } else if (prev->parsed_tok->Role() == pasta::TokenRole::kEndOfFileMarker) {
    CHECK(std::holds_alternative<Substitution *>(parent->before.back()));
    auto inc = std::get<Substitution *>(parent->before.back());
    CHECK(inc->kind == Substitution::kInclusion);
    prev_file_token = inc->RightCornerOfFile(inc->file);

  // NOTE(pag): This deliberately uses `.front()`, whereas most cases use
  //            `.back()`. Starting at the front descends to the deepest file
  //            doing the inclusion, not the included file.
  } else {
    prev_file_token = parent->RightCorner();
  }

  if (!prev_file_token || !prev_file_token->file_tok.has_value()) {
    DCHECK(false);  // Should have at least found `prev`.
    prev_file_token = prev;
  }

  // Go find the next token in the same file as `prev_file_token`, then
  // copy that range. The `BackFill*` methods don't work between two "middle"
  // tokens where we're not sure where the bounds even are.
  pasta::FileToken pft = prev_file_token->file_tok.value();
  pasta::File pf = pasta::File::Containing(pft);
  pasta::FileTokenRange pfts = pf.Tokens();
  const auto pft_index = pft.Index();
  auto max_i = pfts.Size();
  int depth = 0;  // NOTE(pag): Could have self-inclusion.
  for (auto t = curr; t; t = t->next) {

    if (t->category == TokenInfo::kMarkerToken) {
      switch (t->parsed_tok->Role()) {
        case pasta::TokenRole::kBeginOfFileMarker:
          ++depth;
          break;
        case pasta::TokenRole::kEndOfFileMarker:
          --depth;
          break;
        default:
          break;
      }

      // Don't risk finding the "right" token via self-inclusion.
      if (depth) {
        continue;
      }
    }

    if (!t->file_tok.has_value()) {
      continue;
    }

    pasta::FileToken ft = prev_file_token->file_tok.value();
    if (ft.Index() <= pft_index) {
      continue;
    }

    if (pasta::File::Containing(ft) != pf) {
      continue;
    }

    max_i = ft.Index();
    break;
  }

  // Now try to find a `#include`-like construct in the range between the
  // previous file token and the candidate next file token (`max_i`).
  TokenInfo * const first = prev;
  TokenInfo *seen_hash = nullptr;
  TokenInfo *seen_include = nullptr;
  TokenInfo *after_directive = nullptr;

  for (auto i = pft_index + 1u; i < max_i && !after_directive; ++i) {
    pasta::FileToken sft = pfts[i];
    const pasta::TokenKind tok_kind = sft.Kind();

    TokenInfo * const old_prev = prev;
    CHECK_EQ(old_prev->next, curr);
    prev = FillMissingToken(sft, prev);

    // Look for the beginning of the directive.
    //
    // NOTE(pag): Can't do `#include #cstdio`, but can do `#include S(cstdio)`
    //            where `#define S(s) #s`.
    if (tok_kind == pasta::TokenKind::kHash) {
      seen_hash = prev;
      seen_include = nullptr;

    // Look for the `include` or similar keyword in the directive.
    } else if (tok_kind == pasta::TokenKind::kIdentifier ||
               tok_kind == pasta::TokenKind::kRawIdentifier) {
      if (!seen_hash) {
        continue;

      } else if (IsIncludeKeyword(sft)) {
        seen_include = prev;

      } else {
        seen_hash = nullptr;
        seen_include = nullptr;
      }

    // Now look for a new line after the end of the directive.
    } else if (tok_kind == pasta::TokenKind::kUnknown) {
      auto data = sft.Data();
      auto mute_newline = false;
      for (auto ch : data) {
        if ('\n' == ch) {
          if (mute_newline) {
            mute_newline = false;

          // Found the trailing new line; unlink it and remove it from the
          // substitution as well.
          } else if (seen_hash && seen_include) {
            CHECK_EQ(old_prev->next, prev);
            CHECK_EQ(prev->next, curr);
            substitutions.back()->before.pop_back();

            after_directive = prev;
            old_prev->next = curr;
            prev = old_prev;
            break;

          // Not in an include.
          } else {
            seen_hash = nullptr;
            seen_include = nullptr;
            break;
          }
        } else if ('\\' == ch) {
          mute_newline = true;
        }
      }

    // The `#include` is the last thing in this file, with no trailing new line.
    } else if (seen_hash && seen_include &&
               (tok_kind == pasta::TokenKind::kEndOfDirective ||
                tok_kind == pasta::TokenKind::kEndOfFile)) {
      CHECK_EQ(old_prev->next, prev);
      CHECK_EQ(prev->next, curr);
      substitutions.back()->before.pop_back();

      after_directive = prev;
      old_prev->next = curr;
      prev = old_prev;
      break;
    }
  }

  // We were unable to find the `#include` or include-like directive.
  if (!after_directive) {
    err << "Unable to locate include directive before "
        << pf.Path().generic_string() << ':' << pft.Line()
        << ':' << pft.Column();
    DCHECK(false) << err.str();
    return nullptr;
  }

  // By this point, we've backfilled up to the end of the include directive.
  CHECK_NOTNULL(seen_hash);
  CHECK_NOTNULL(seen_include);

  Substitution *file = CreateSubstitution(Substitution::kIdentity,
                                          std::move(curr_file));
  Substitution *inclusion = CreateSubstitution(Substitution::kInclusion,
                                               std::move(pf));

  CHECK(parent->kind == Substitution::kIdentity);
  CHECK(!parent->after);

  // Scan through the substitution tokens of the parent for the previously found
  // hash token, which is the beginning of the directive. We need to migrate
  // those tokens into `inclusion`.
  auto found = false;
  TokenInfo *first_found = nullptr;
  while (!parent->before.empty() && !found) {
    auto &ent = inclusion->before.emplace_back(std::move(parent->before.back()));
    parent->before.pop_back();
    if (std::holds_alternative<Substitution *>(ent)) {
      continue;
    } else {
      auto ti = std::get<TokenInfo *>(ent);
      if (ti->file_tok && !first_found) {
        first_found = ti;
      }
      found = ti == seen_hash;
    }
  }

  if (!found) {
    err << "Could not find beginning of '#include' or include-like directive";
    if (first_found) {
      auto ft = first_found->file_tok.value();
      auto file = pasta::File::Containing(ft);
      err << " near " << file.Path().generic_string()
          << ':' << ft.Line() << ':' << ft.Column();
    }
    DCHECK(false)
        << err.str();
    return nullptr;
  }

  std::reverse(inclusion->before.begin(), inclusion->before.end());
  parent->before.emplace_back(inclusion);
  inclusion->after = file;
  substitutions.push_back(file);
  AddTokenToSubstitution(curr);
  return first;
}

TokenInfo *TokenTreeImpl::HandleEndOfFile(TokenInfo *prev, TokenInfo *curr,
                                          std::stringstream &) {

  // Would be strange to start with an end-of-file marker, as it means we'd
  // be straddling two files, but taking nothing of value from the first file.
  CHECK_NOTNULL(prev);
  CHECK(curr->file_tok.has_value());

  TokenInfo *first = prev;

  // If we have a previous token from any file, then try to back-fill any
  // missing tokens.
  first = BackFillFromRightCorner(
      prev, substitutions.back()->RightCorner(), curr);

  // The top substitution on the stack should be a file.
  CHECK_LE(2u, substitutions.size());
  auto file = substitutions.back();
  CHECK(file->kind == Substitution::kIdentity);

  AddTokenToSubstitution(curr);

  // The next substitution on the stack is either an inclusion, or it's the
  // top-level identity substitution.
  substitutions.pop_back();

  return first;
}

TokenInfo *TokenTreeImpl::HandleBeginOfMacroExpansion(
    TokenInfo *prev, TokenInfo *curr, std::stringstream &err) {
  CHECK_NOTNULL(prev);
  CHECK_LE(2u, substitutions.size());
  CHECK(prev->category == TokenInfo::kMacroUseToken);

  TokenInfo *first = prev;
  Substitution *use = substitutions.back();
  substitutions.pop_back();
  CHECK(use->kind == Substitution::kMacroUse);
  Substitution *exp = CreateSubstitution(Substitution::kMacroExpansion,
                                         use->file  /* kind of a lie */);
  substitutions.push_back(exp);
  use->after = exp;
  AddTokenToSubstitution(curr);
  return first;
}

TokenInfo *TokenTreeImpl::HandleEndOfMacroExpansion(
    TokenInfo *prev, TokenInfo *curr, std::stringstream &err) {
  CHECK_NOTNULL(prev);
  CHECK_LE(2u, substitutions.size());

  TokenInfo *first = prev;
  Substitution *parent = substitutions.back();
  CHECK(parent->kind == Substitution::kMacroExpansion);

  if (prev->category == TokenInfo::kMacroExpansionToken) {

  // Empty macro expansions.
  } else if (prev->category == TokenInfo::kMarkerToken) {
    CHECK(prev->parsed_tok.has_value());
    CHECK(prev->parsed_tok->Role() ==
          pasta::TokenRole::kBeginOfMacroExpansionMarker);

  } else {
    DCHECK(false);
    err << "Unexpected predecessor token when handling end of macro expansion";
    return nullptr;
  }

  AddTokenToSubstitution(curr);
  substitutions.pop_back();
  return first;
}

TokenInfo *TokenTreeImpl::HandleMarkerToken(TokenInfo *prev, TokenInfo *curr,
                                            std::stringstream &err) {
  CHECK(curr->parsed_tok.has_value());
  switch (auto role = curr->parsed_tok->Role()) {
    case pasta::TokenRole::kInvalid:
    case pasta::TokenRole::kPrintedToken:
    case pasta::TokenRole::kFileToken:
    case pasta::TokenRole::kMacroExpansionToken:
      DCHECK(false);
      err << "Unexpected token role " << int(role)
          << " when handling marker token";
      return nullptr;

    case pasta::TokenRole::kBeginOfFileMarker:
      return HandleBeginningOfFile(prev, curr, err);
    case pasta::TokenRole::kEndOfFileMarker:
      return HandleEndOfFile(prev, curr, err);
    case pasta::TokenRole::kBeginOfMacroExpansionMarker:
      return HandleBeginOfMacroExpansion(prev, curr, err);
    case pasta::TokenRole::kEndOfMacroExpansionMarker:
      return HandleEndOfMacroExpansion(prev, curr, err);
  }
}

// Fill in the missing tokens from the token tree.
Substitution *TokenTreeImpl::FillMissingFileTokens(std::stringstream &err) {
  TokenInfo *first = &(tokens_alloc.front());
  Substitution *toks = nullptr;
  for (TokenInfo *curr = first; curr; curr = curr->next) {
    if (curr->file_tok.has_value()) {
      toks = CreateSubstitution(
          Substitution::kIdentity,
          pasta::File::Containing(curr->file_tok.value()));
      break;
    }
  }

  if (!toks) {
    err
        << "Could not find any file tokens associated with top-level "
        << "declaration tokens";
    return nullptr;
  }

  substitutions.push_back(toks);

  for (TokenInfo *curr = first, *prev = nullptr; curr;
       prev = curr, curr = curr->next) {

    switch (curr->category) {
      case TokenInfo::kFileToken:
        prev = HandleFileToken(prev, curr);
        break;
      case TokenInfo::kMacroExpansionToken:
        prev = HandleMacroExpansionToken(prev, curr, err);
        break;
      case TokenInfo::kMacroUseToken:
        prev = HandleMacroUseToken(prev, curr);
        break;
      case TokenInfo::kMarkerToken:
        prev = HandleMarkerToken(prev, curr, err);
        break;
      case TokenInfo::kMissingFileToken:
        err << "Broken invariant; missing file token?";
        return nullptr;
    }
    if (!prev) {
      return nullptr;
    }
  }

  CHECK(!substitutions.empty());

  return toks;
}

TokenTree::~TokenTree(void) {}

// Create a token tree from the tokens in the inclusive range
// `[begin_index, end_index]` from `range`.
Result<TokenTree, std::string>
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

//  std::cerr << "----------------------------------------------------- " << begin_index << " to " << end_index << " ---\n";

  impl->BuildInitialTokenList(std::move(range), begin_index, end_index);
  if (impl->tokens_alloc.empty()) {
    err << "Cannot create token tree from empty token range";
    return err.str();
  }

//  std::cerr << "----------------------------------------------------- " << impl->tokens_alloc.size() << " ---\n";
//  for (auto info = &(tokens_alloc.front()); info; info = info->next) {
//    switch (info->category) {
//      case TokenInfo::kFileToken:
//        std::cerr << info->file_tok->Data();
//        continue;
//      case TokenInfo::kMacroUseToken:
//      case TokenInfo::kMissingFileToken:
//        std::cerr << "\033[4m" << info->file_tok->Data() << "\033[0m";
//        continue;
//      case TokenInfo::kMarkerToken:
//      default:
//        continue;
//    }
//  }
  auto sub = impl->FillMissingFileTokens(err);
  if (!sub) {
    return err.str();
  }
//  std::cerr << "----------------------------------------------------- " << impl->tokens_alloc.size() << " ---\n";
//  sub->Print(std::cerr);
//  std::cerr
//      << "\n\ndigraph {\n"
//      << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";
//  sub->PrintDOT(std::cerr);
//  std::cerr << "\n}\n";
//  std::cerr << "\n\n\n";
  return TokenTree(std::move(impl));
}

}  // namespace mx
