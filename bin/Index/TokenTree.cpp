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
  enum Kind {
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

  } kind{kIdentity};

  std::vector<std::variant<TokenInfo *, Substitution *>> before;

  Substitution *after;

//  TokenInfo *LeftCorner(void) {
//    for (auto ent : before) {
//      if (std::holds_alternative<TokenInfo *>(ent)) {
//        return std::get<TokenInfo *>(ent);
//      } else {
//        auto sub = std::get<Substitution *>(ent);
//        if (auto lc = sub->LeftCorner()) {
//          return lc;
//        }
//      }
//    }
//    return nullptr;
//  }

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

    auto i = 0;
    auto has_any = false;
    for (auto ent : before) {
      if (std::holds_alternative<TokenInfo *>(ent)) {
        auto info = std::get<TokenInfo *>(ent);
        switch (info->category) {
          case TokenInfo::kFileToken:
            os << "<TD>" << TokData(info->file_tok->Data()) << "</TD>";
            has_any = true;
            continue;
          case TokenInfo::kMacroExpansionToken:
            os << "<TD>" << TokData(info->parsed_tok->Data()) << "</TD>";
            has_any = true;
            continue;
          case TokenInfo::kMacroUseToken:
          case TokenInfo::kMissingFileToken:
            os << "<TD><U>" << TokData(info->file_tok->Data()) << "</U></TD>";
            has_any = true;
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

  TokenInfo *BackFillFromRightCorner(TokenInfo *prev, TokenInfo *curr);

  // Back-fill tokens from between `a` and `b`, exclusive.
  TokenInfo *BackFillFromBetween(TokenInfo *prev, pasta::FileToken a,
                                 pasta::FileToken b);

  // Fill in the missing tokens from the token tree.
  Substitution *FillMissingFileTokens(std::stringstream &err);

  // Inject a missing token file token into the token stream after `prev`.
  // Return the new value for `prev`.
  TokenInfo *FillMissingToken(pasta::FileToken tok, TokenInfo *prev);

//  // Build an include substitution.
//  Substitution *BuildInclude(
//      TokenInfo *hash_loc, TokenInfo *include_loc, TokenInfo *less,
//      TokenInfo *path, TokenInfo *greater, TokenInfo *eod);
//
//  // Try to isolate the tokens of an `#include`-like directive. Mostly this just
//  // looks for the beginning of an apparent directive (i.e. a `#`) and the end
//  // (a new line), as we're scanning the file tokens, and we might need to deal
//  // with the actual file name being a macro subject to expansion.
//  Substitution *FindInclude(pasta::File file, uint64_t start_index,
//                            TokenInfo *prev);

  void AddTokenToSubstitution(TokenInfo *tok);
  Substitution *CreateSubstitution(Substitution::Kind kind);

  TokenInfo *HandleFileToken(TokenInfo *prev, TokenInfo *curr);
  TokenInfo *HandleMacroUseToken(TokenInfo *prev, TokenInfo *curr);
  TokenInfo *HandleMacroExpansionToken(TokenInfo *prev, TokenInfo *curr,
                                       std::stringstream &err);
  TokenInfo *HandleMarkerToken(TokenInfo *prev, TokenInfo *curr,
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
    prev = BackFillFromEndOfFile(prev, fb, b.Index());
    prev = BackFillFromBeginningOfFile(prev, fa, a.Index());
  }
  return prev;
}

TokenInfo *TokenTreeImpl::BackFillFromRightCorner(
    TokenInfo *prev, TokenInfo *curr) {
  DCHECK(!substitutions.empty());

  if (curr->file_tok.has_value()) {
    auto prev_file_token = substitutions.back()->RightCorner();
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

Substitution *TokenTreeImpl::CreateSubstitution(Substitution::Kind kind) {
  auto &sub = substitutions_alloc.emplace_back();
  sub.kind = kind;
  return &sub;
}

//// Return `true` if `data` contains one or more whitespace characters, and
//// nothing else.
//static bool IsWhitespace(std::string_view data) {
//  auto is_whitespace = false;
//  for (auto ch : data) {
//    switch (ch) {
//      case ' ': case '\t': case '\r': case '\n': case '\\':
//        is_whitespace = true;
//        continue;
//      default:
//        return false;
//    }
//  }
//  return is_whitespace;
//}

//// Build an include substitution.
//Substitution *TokenTreeImpl::BuildInclude(
//    TokenInfo *hash_loc, TokenInfo *include_loc, TokenInfo *less,
//    TokenInfo *path, TokenInfo *greater, TokenInfo *eod) {
//
//  CHECK_NOTNULL(hash_loc);
//  CHECK_NOTNULL(include_loc);
//  CHECK_NOTNULL(eod);
//
//  CHECK_LT(hash_loc->file_tok->Index(), include_loc->file_tok->Index());
//  CHECK_LT(include_loc->file_tok->Index(), eod->file_tok->Index());
//
//  (void) less;
//  (void) path;
//  (void) greater;
//
//  Substitution * const sub = &(substitutions_alloc.emplace_back());
//
//  for (auto tok = hash_loc; tok < eod; tok = tok->next) {
//    if (tok->file_tok) {
//      sub->before.emplace_back(tok);
//    }
//  }
//
//  return sub;
//}
//
//// Try to isolate the tokens of an `#include`-like directive. Mostly this just
//// looks for the beginning of an apparent directive (i.e. a `#`) and the end
//// (a new line), as we're scanning the file tokens, and we might need to deal
//// with the actual file name being a macro subject to expansion.
//Substitution *TokenTreeImpl::FindInclude(pasta::File file, uint64_t start_index,
//                                         TokenInfo *prev) {
//
//  TokenInfo * const orig_prev = prev;
//  TokenInfo * const orig_next = prev->next;
//
//  auto prev_file_toks = file.Tokens();
//  TokenInfo *hash_loc = nullptr;
//  TokenInfo *include_loc = nullptr;
//  TokenInfo *less_loc = nullptr;
//  TokenInfo *greater_loc = nullptr;
//  TokenInfo *path_loc = nullptr;
//  for (size_t i = start_index, max_i = prev_file_toks.Size();
//       i < max_i; ++i) {
//    auto ft = prev_file_toks[i];
//    auto data = ft.Data();
//    auto mute_new_line = false;
//    auto tok = FillMissingToken(ft, prev);
//    switch (ft.Kind()) {
//      case pasta::TokenKind::kHash:
//        hash_loc = tok;
//        break;
//      case pasta::TokenKind::kIdentifier:
//      case pasta::TokenKind::kRawIdentifier:
//        switch (ft.PreProcessorKeywordKind()) {
//          case pasta::PPKeywordKind::kInclude:
//          case pasta::PPKeywordKind::kIncludeNext:
//          case pasta::PPKeywordKind::kImport:
//            include_loc = tok;
//            break;
//          default:
//            if (data == "include" || data == "include_next" ||
//                data == "import") {
//              include_loc = tok;
//            }
//            break;
//        }
//        break;
//      case pasta::TokenKind::kLess:
//        less_loc = tok;
//        break;
//      case pasta::TokenKind::kGreater:
//        greater_loc = tok;
//        break;
//      case pasta::TokenKind::kStringLiteral:
//      case pasta::TokenKind::kUtf8StringLiteral:
//      case pasta::TokenKind::kUtf16StringLiteral:
//      case pasta::TokenKind::kUtf32StringLiteral:
//      case pasta::TokenKind::kWideStringLiteral:
//        path_loc = tok;
//        break;
//
//      case pasta::TokenKind::kEndOfDirective:
//      case pasta::TokenKind::kUnknown:
//        // Found some random stuff before the `#include`. For example,
//        // might be some macro defines, comments, etc.
//        if (!hash_loc || !include_loc) {
//          break;
//        }
//
//        for (auto ch : data) {
//          if ('\n' == ch) {
//            if (mute_new_line) {
//              mute_new_line = false;
//              continue;
//
//            // Found the end of the directive. try to build it.
//            } else {
//              return BuildInclude(hash_loc, include_loc, less_loc,
//                                  path_loc, greater_loc, tok);
//            }
//
//          // Line continuation.
//          } else if ('\\') {
//            mute_new_line = true;
//            continue;
//
//          } else {
//            continue;
//          }
//        }
//        break;
//
//      default:
//        continue;
//    }
//  }
//
//  // Elide all added tokens.
//  orig_prev->next = orig_next;
//  return nullptr;
//}

TokenInfo *TokenTreeImpl::HandleFileToken(TokenInfo *prev, TokenInfo *curr) {
  CHECK(!substitutions.empty());
  CHECK(curr->file_tok.has_value());

  TokenInfo *first = BackFillFromRightCorner(prev, curr);
  AddTokenToSubstitution(curr);
  return first;
}

TokenInfo *TokenTreeImpl::HandleMacroUseToken(
    TokenInfo *prev, TokenInfo *curr) {

  CHECK(!substitutions.empty());
  Substitution *parent = substitutions.back();

  TokenInfo *first = curr;

  // Macro use is the first in the token list.
  if (!prev) {
    Substitution *use = CreateSubstitution(Substitution::kMacroUse);
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

    first = BackFillFromRightCorner(prev, curr);
    Substitution *use = CreateSubstitution(Substitution::kMacroUse);
    parent->before.emplace_back(use);
    substitutions.push_back(use);
  }

  AddTokenToSubstitution(curr);

  return first;
}

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

TokenInfo *TokenTreeImpl::HandleBeginningOfFile(
    TokenInfo *prev, TokenInfo *curr, std::stringstream &err) {

  if (!prev) {
    substitutions.push_back(CreateSubstitution(Substitution::kIdentity));
    AddTokenToSubstitution(curr);
    return curr;
  }

  if (!prev->file_tok.has_value()) {
    DCHECK(false);
    err << "Beginning of file marker token is preceded by a token "
        << "without a file location";
    return nullptr;
  }

  CHECK(curr->file_tok.has_value());
  CHECK(!substitutions.empty());

  auto prev_file_token = substitutions.back()->RightCorner();
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

    auto old_prev = prev;
    prev = FillMissingToken(sft, prev);

    // Look for the beginning of the directive.
    //
    // NOTE(pag): Can't do `#include #cstdio`, but can do `#include S(cstdio)`
    //            where `#define S(s) #s`.
    if (tok_kind == pasta::TokenKind::kHash) {
      seen_hash = prev;
      seen_include = nullptr;

    // Look for the `include` or similar keyword in the directive.
    } else if ((tok_kind == pasta::TokenKind::kIdentifier ||
                tok_kind == pasta::TokenKind::kRawIdentifier) &&
               seen_hash) {
      switch (sft.PreProcessorKeywordKind()) {
        case pasta::PPKeywordKind::kInclude:
        case pasta::PPKeywordKind::kIncludeNext:
        case pasta::PPKeywordKind::kImport:
          seen_include = prev;
          break;
        case pasta::PPKeywordKind::kNotKeyword: {
          auto data = sft.Data();
          if (data == "include" || data == "include_next" || data == "import") {
            seen_include = prev;
          }
          break;
        }
        default:
          seen_hash = nullptr;
          seen_include = nullptr;
          break;
      }

    // Now look for a new line after the end of the directive.
    } else if (seen_hash && seen_include &&
               tok_kind == pasta::TokenKind::kUnknown) {
      auto data = sft.Data();
      auto mute_newline = false;
      for (auto ch : data) {
        if ('\n' == ch) {
          if (mute_newline) {
            mute_newline = false;

          // Found the trailing new line; unlink it.
          } else {
            CHECK_EQ(old_prev->next, prev);
            CHECK_EQ(prev->next, curr);
            after_directive = prev;
            old_prev->next = curr;
            prev = old_prev;
            break;
          }
        } else if ('\\' == ch) {
          mute_newline = true;
        }
      }
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

  Substitution *parent = substitutions.back();
  Substitution *file = CreateSubstitution(Substitution::kIdentity);
  Substitution *inclusion = CreateSubstitution(Substitution::kInclusion);

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
  first = BackFillFromRightCorner(prev, curr);

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
  Substitution *exp = CreateSubstitution(Substitution::kMacroExpansion);
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

  Substitution * const toks = CreateSubstitution(Substitution::kIdentity);
  substitutions.push_back(toks);

  for (TokenInfo *curr = &(tokens_alloc.front()), *prev = nullptr; curr;
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

#if 0
  TokenInfo * const first = &(tokens_alloc.front());
//  CHECK(first->parsed_tok.has_value());
  CHECK(first->file_tok.has_value());

  std::vector<std::pair<pasta::File, pasta::FileToken>> last_tok_from_file;

  // Base case to track that we're always in something.
  last_tok_from_file.emplace_back(
      pasta::File::Containing(first->file_tok.value()),
      first->file_tok.value());


  auto create_substitution = [this] (Substitution::Kind kind) -> Substitution * {
    auto sub = &(substitutions_alloc.emplace_back());
    sub->kind = kind;
    return sub;
  };

  auto yield_file_tok = [&substitutions] (TokenInfo *tok) {
    CHECK(!substitutions.empty());
    substitutions.back()->before.emplace_back(tok);
  };

  auto yield_substitution = [&substitutions] (Substitution *sub) {
    CHECK(!substitutions.empty());
    substitutions.back()->before.emplace_back(sub);
  };

  auto enter_substitution = [&substitutions] (Substitution *sub) {
    substitutions.push_back(sub);
  };

  auto exit_substitution = [&substitutions] (void) {
    substitutions.pop_back();
  };

//  auto push_substitution = [&substitutions] (Substitution *sub) {
//    CHECK(!substitutions.empty());
//    substitutions.back()->before.emplace_back(sub);
//    substitutions.push_back(sub);
//  };
//
//  auto pop_substitution = [&substitutions] (void) {
//    CHECK_LE(substitutions.size(), 2u);
//    auto last_sub = substitutions.back();
//    substitutions.pop_back();
////    substitutions.back()->after
//  };

  substitutions.push_back(create_substitution(Substitution::Kind::kIdentity));

  TokenInfo *prev = nullptr;
  for (auto curr = first; curr; prev = curr, curr = curr->next) {
    DCHECK_NE(curr, prev);
    CHECK(!last_tok_from_file.empty());

    std::cerr
        << "prev=" << reinterpret_cast<void *>(prev)
        << " curr=" << reinterpret_cast<void *>(curr)
        << " substitutions=" << substitutions.size()
        << '\n';

    switch (curr->category) {
      case TokenInfo::kMissingFileToken:
        err << "Broken invariant; missing file token?";
        return nullptr;

      // The macro use tokens are taken from a file, and so we know that they
      // are "fine." We can rely on the expansion begin/end markers to tell
      // us what to fill around.
      case TokenInfo::kMacroUseToken:

        // Entering a macro use.
        if (!prev || prev->category != TokenInfo::kMacroUseToken) {

          if (prev) {
            CHECK(prev->file_tok.has_value());
            CHECK(curr->file_tok.has_value());
            auto old_prev = prev;

            // Go collect stuff like whitespace prior to the use of a macro
            // token.
            prev = BackFillFromBetween(prev, prev->file_tok.value(),
                                       curr->file_tok.value());
            if (old_prev != prev) {
              CHECK_EQ(prev->next, curr);
              for (auto tok = old_prev->next; tok != curr; tok = tok->next) {
                yield_file_tok(tok);  // Collect into substitution.
              }
            }
          }

          auto sub = create_substitution(Substitution::Kind::kMacroUse);
          yield_substitution(sub);
          enter_substitution(sub);

        } else {
          // Should be inside the top-level identity substitution, and at least
          // one other substitution (i.e. for a macro expansion).
          DCHECK_LE(2u, substitutions.size());
          DCHECK(substitutions.back()->kind == Substitution::Kind::kMacroUse);
        }

        yield_file_tok(curr);
        last_tok_from_file.back().second = std::move(curr->file_tok.value());
        continue;

      // With macro expansion tokens there's nothing to do really.
      case TokenInfo::kMacroExpansionToken:

        // Should at least be inside the top-level identity substitution,
        // then the macro expansion substitution.
        DCHECK_LE(2u, substitutions.size());

        yield_file_tok(curr);
        continue;

      default:
        if (!prev) {
          CHECK(curr->file_tok.has_value());
          yield_file_tok(curr);
          continue;
        } else {
          break;
        }
    }

    CHECK(curr->parsed_tok.has_value());
    pasta::Token curr_tok = curr->parsed_tok.value();
    const pasta::TokenRole curr_tok_role = curr_tok.Role();

    pasta::TokenRole prev_tok_role = pasta::TokenRole::kInvalid;
    if (prev) {
      if (prev->parsed_tok) {
        prev_tok_role = prev->parsed_tok->Role();
      } else {
        CHECK(prev->category == TokenInfo::kMacroUseToken);
        prev_tok_role = pasta::TokenRole::kFileToken;
      }
    }

    // At the beginning of a macro expansion.
    if (pasta::TokenRole::kBeginOfMacroExpansionMarker == curr_tok_role) {
      CHECK_NOTNULL(prev);
      CHECK(prev->category == TokenInfo::kMacroUseToken);
      CHECK_LE(2u, substitutions.size());
      auto use_sub = substitutions.back();
      CHECK(use_sub->kind == Substitution::Kind::kMacroUse);
      auto exp_sub = create_substitution(Substitution::Kind::kMacroExpansion);
      use_sub->after = exp_sub;
      exit_substitution();
      enter_substitution(exp_sub);
      yield_file_tok(curr);
      continue;

    // At the end of a macro expansion.
    } else if (pasta::TokenRole::kEndOfMacroExpansionMarker == curr_tok_role) {
      CHECK_NOTNULL(prev);
      CHECK(prev->category == TokenInfo::kMacroExpansionToken ||
            prev_tok_role == pasta::TokenRole::kBeginOfMacroExpansionMarker);
      CHECK_LE(2u, substitutions.size());
      auto exp_sub = substitutions.back();
      CHECK(exp_sub->kind == Substitution::Kind::kMacroExpansion);
      yield_file_tok(curr);
      exit_substitution();
      continue;
    }

//    // We must be at the end of a macro expansion.
//    if (prev->category == TokenInfo::kMacroExpansionToken) {
//
//      // Should at least be inside the top-level identity substitution,
//      // then the macro use substitution, and then the macro expansion
//      // substitution.
//      DCHECK_LE(2u, substitutions.size());
//
//      CHECK(curr_tok.Role() == pasta::TokenRole::kEndOfMacroExpansionMarker);
//
//      yield_file_tok(curr);
//      exit_substitution();  // Macro expansion.
//
////      last_tok_from_file.back().second = std::move(curr_file_tok);
//      continue;
//    }

    CHECK(curr->file_tok.has_value());
    CHECK(prev->file_tok.has_value());

    pasta::FileToken prev_file_tok = prev->file_tok.value();
    pasta::File prev_file = pasta::File::Containing(prev_file_tok);

    pasta::FileToken curr_file_tok = curr->file_tok.value();
    pasta::File curr_file = pasta::File::Containing(curr_file_tok);

    auto prev_index = prev_file_tok.Index();
    auto curr_index = curr_file_tok.Index();

    // We need to track the last token seen from each file. For example
    // we might have the X-macro pattern used as follows:
    //
    //      enum Blah {
    //      #define MAKE_BLAH(x) x,
    //      #include "BlahEnumerators.h"
    //      };
    //
    // And so when we get to the end-of-file marker before the `};`, we need
    // to make sure that any of the file tokens after the last parsed token
    // from `BlahEnumerators.h`, e.g. whitespace, comments, `#undef`s, etc,
    // end up being injected before our end-of-file marker.
    if (pasta::TokenRole::kBeginOfFileMarker == curr_tok_role) {

      // We may need to back-fill before this marker; handled below. To do
      // that, we need to find the corresponding end-of-file marker, then find
      // the next token, then back fill from what's before the next token.
      //
      // TODO(pag): This will probably back-fill whitespace to the wrong spot.
      auto f = 1u;
      std::optional<TokenInfo *> found_at;
      for (auto n = curr->next; n; n = n->next) {
        if (n->parsed_tok) {
          switch (n->parsed_tok->Role()) {
            case pasta::TokenRole::kBeginOfFileMarker:
              ++f;
              continue;
            case pasta::TokenRole::kEndOfFileMarker:
              --f;
              if (!f) {
                break;
              }
              [[clang::fallthrough]];
            default:
              continue;
          }

          // `n` points to the end of file marker matching `curr_tok`.
          if (n->next) {

            // It must have a file token, because either it's another marker,
            // or the usage tokens from a macro expansion.
            found_at = n->next;
          }
          break;
        }
      }

      if (!found_at) {
        LOG(ERROR)
            << "Token tree range straddles two files "
            << prev_file.Path().generic_string() << ':'
            << prev_file_tok.Line() << ':' << prev_file_tok.Column()
            << " and "
            << curr_file.Path().generic_string() << ':'
            << curr_file_tok.Line() << ':' << curr_file_tok.Column();

      } else {
        TokenInfo *next_info_in_prev_file = *found_at;
        CHECK(next_info_in_prev_file->file_tok.has_value());
        const pasta::FileToken &next_tok_from_prev_file =
            next_info_in_prev_file->file_tok.value();

        // Likely X-Macro case, where `prev->file_tok` is followed by something
        // that is eventually followed by an `#include`.
        if (auto expected_prev_file =
                pasta::File::Containing(next_tok_from_prev_file);
            expected_prev_file != prev_file) {
          auto sub = FindInclude(prev_file, prev_file_tok.Index() + 1u, prev);
          if (!sub) {
            err
                << "Unexpected change of file from "
                << expected_prev_file.Path().generic_string() << ':'
                << next_tok_from_prev_file.Line() << ':'
                << next_tok_from_prev_file.Column() << " to "
                << prev_file.Path().generic_string() << ':'
                << prev_file_tok.Line() << ':' << prev_file_tok.Column()
                << " in token stream could not be "
                << "matched with an X-macro-like inclusion";

            assert(false);
            return nullptr;

          } else {
            CHECK(next_info_in_prev_file->parsed_tok.has_value());
            CHECK(next_info_in_prev_file->parsed_tok->Role() ==
                  pasta::TokenRole::kBeginOfFileMarker);

            TokenInfo * const include_directive = sub->LeftCorner();
            CHECK_NOTNULL(include_directive);

            // Back fill the tokens found prior to the `#include` directive
            // into the current substitution.
            for (auto tok = prev->next; tok != include_directive;
                tok = tok->next) {
              yield_file_tok(tok);
            }

            // Add the include directive itself into the current substituion.
            yield_substitution(sub);

            // Enter the file as the substituted tokens for the inclusion
            // directive.
            sub->after = create_substitution(Substitution::Kind::kInclusion);
            enter_substitution(sub->after);
          }
        }

        pasta::FileTokenRange missing_toks = prev_file.Tokens();
        auto prev_was_whitespace = false;

        // We take a bit of extra care here to try to detect the case where
        // we don't inject the whitespace that would probably follow a
        // `#include`. This isn't quite good enough, as we could have whitespace
        // and comments and such following, but oh well.
        std::optional<pasta::FileToken> missing_tok;
        for (auto i = prev_file_tok.Index() + 1u,
                  max_i = next_tok_from_prev_file.Index();
             i < max_i; ++i) {
          if (missing_tok) {
            last_tok_from_file.back().second = missing_tok.value();
            prev = FillMissingToken(std::move(*missing_tok), prev);
            prev_was_whitespace = IsWhitespace(prev->file_tok->Data());
          } else {
            missing_tok = missing_toks[i];
          }
        }
        if (missing_tok && !prev_was_whitespace) {
          last_tok_from_file.back().second = missing_tok.value();
          prev = FillMissingToken(std::move(*missing_tok), prev);
        }
      }

      last_tok_from_file.emplace_back(curr_file, curr_file_tok);
      continue;

    // We're about to exit a file, make sure to back-fill any trailing tokens
    // from within the end of that file.
    } else if (pasta::TokenRole::kEndOfFileMarker == curr_tok_role) {
      CHECK_LE(2u, substitutions.size());

      pasta::File exited_file = last_tok_from_file.back().first;
      pasta::FileToken exited_tok = last_tok_from_file.back().second;

      last_tok_from_file.pop_back();
      if (last_tok_from_file.empty()) {
        err
            << "Token tree range straddles two files "
            << prev_file.Path().generic_string() << ':'
            << prev_file_tok.Line() << ':' << prev_file_tok.Column()
            << " and "
            << curr_file.Path().generic_string() << ':'
            << curr_file_tok.Line() << ':' << curr_file_tok.Column();
        return nullptr;
      }

      pasta::FileTokenRange exited_toks = exited_file.Tokens();

      // The included/imported file appeared empty to the parser, e.g. it was
      // actually empty, or just full of whitespace, or perhaps all the code was
      // disabled by macros.
      if (prev_tok_role == pasta::TokenRole::kBeginOfFileMarker) {
        for (auto exited_tok : exited_toks) {
          prev = FillMissingToken(std::move(exited_tok), prev);
          yield_file_tok(prev);
        }

      // The included/imported file appeared non-empty to the parser; see if
      // we need to back fill.
      } else {
        for (uint64_t i = exited_tok.Index() + 1u, max_i = exited_toks.Size();
             i < max_i; ++i) {
          prev = FillMissingToken(exited_toks[i], prev);
          yield_file_tok(prev);
        }
      }

      yield_file_tok(curr);
      exit_substitution();  // Exit this substitution.

      continue;
    }

    // We've just left a file, now we're resuming in another file. Make it
    // look like we're continuing on where we left off.
    if (prev_file != curr_file) {
      CHECK(prev_tok_role == pasta::TokenRole::kEndOfFileMarker);
      CHECK(last_tok_from_file.back().first == curr_file);
      prev_file = curr_file;
      prev_file_tok = last_tok_from_file.back().second;
      prev_index = last_tok_from_file.back().second.Index();
    }

    // The previous token is at the same spot, and that should only happen
    // with marker tokens (e.g. macro expansions, file begins).
    if (prev_index == curr_index) {
      CHECK(prev->category == TokenInfo::kMarkerToken ||
            curr->category == TokenInfo::kMarkerToken);

    // We are missing some tokens so we need to inject them.
    } else if (prev_index < curr_index) {
      pasta::FileTokenRange missing_toks = prev_file.Tokens();
      for (auto i = prev_index + 1u; i < curr_index; ++i) {
        prev = FillMissingToken(missing_toks[i], prev);
        yield_file_tok(prev);
      }

    } else {
      err
          << "Out-of-order file tokens in file "
          << prev_file.Path().generic_string()
          << " " << prev_file_tok.Line() << ':' << prev_file_tok.Column()
          << " before " << curr_file_tok.Line() << ':'
          << curr_file_tok.Column();
      return nullptr;
    }

    // Keep track of the last token from the current file.
    last_tok_from_file.back().second = std::move(curr_file_tok);
  }

  // Do a final sweep through to inject any missing things. We sometimes have
  // missing things due to macros.
  prev = first;

//  auto prev_file_tok = first->file_tok.value();
//  auto prev_index = prev_file_tok.Index();
//
//  for (auto curr = first->next; curr; prev = curr, curr = curr->next) {
//    if (TokenInfo::kMacroExpansionToken == curr->category) {
//      continue;
//    }
//
//    auto curr_index = curr->file_tok->Index();
//    if (prev_index == curr_index || (prev_index + 1u) == curr_index) {
//
//      if ((TokenInfo::kMacroExpansionToken != curr->category &&
//           TokenInfo::kMarkerToken != curr->category) ||
//          (pasta::TokenRole::kEndOfMacroExpansionMarker !=
//           curr->parsed_tok->Role())) {
//        prev_file_tok = curr->file_tok.value();
//        prev_index = curr_index;
//      }
//
//      continue;
//    }
//
//    auto prev_file = pasta::File::Containing(prev_file_tok);
//    auto curr_file = pasta::File::Containing(*(curr->file_tok));
//    if (prev_file != curr_file) {
//      prev_file_tok = curr->file_tok.value();
//      prev_index = curr_index;
//      continue;
//    }
//
//    pasta::FileTokenRange missing_toks = prev_file.Tokens();
//    for (auto i = prev_index + 1u; i < curr_index; ++i) {
//      prev = FillMissingToken(missing_toks[i], prev);
//    }
//
//    prev_index = curr_index;
//    prev_file_tok = curr->file_tok.value();
//  }

  CHECK_EQ(substitutions.size(), 1u);

  return first;
#endif
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

  std::cerr << "----------------------------------------------------- " << begin_index << " to " << end_index << " ---\n";

  impl->BuildInitialTokenList(std::move(range), begin_index, end_index);
  if (impl->tokens_alloc.empty()) {
    err << "Cannot create token tree from empty token range";
    return err.str();
  }

  std::cerr << "----------------------------------------------------- " << impl->tokens_alloc.size() << " ---\n";
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
  std::cerr << "----------------------------------------------------- " << impl->tokens_alloc.size() << " ---\n";
  std::cerr
      << "digraph {\n"
      << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";
  sub->PrintDOT(std::cerr);
  std::cerr << "\n}\n";
  std::cerr << "\n\n\n";
  return TokenTree(std::move(impl));
}

}  // namespace mx
