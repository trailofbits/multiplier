// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Token.h"

#include <deque>
#include <glog/logging.h>
#include <optional>
#include <pasta/AST/Token.h>
#include <pasta/Util/File.h>
#include <sstream>
#include <vector>

#include <iostream>

namespace mx {
namespace {

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

// Build an initial token info list. This contains all of the tokens that were
// parsed, plus the file tokens that were macro uses. This does not contain
// file tokens that were elided due to things like conditional macros, e.g.
// `#if 0`.
static void BuildInitialTokenList(pasta::TokenRange range,
                                  uint64_t begin_index,
                                  uint64_t end_index,
                                  std::deque<TokenInfo> &info_alloc) {
  for (auto i = begin_index; i <= end_index; ++i) {
    pasta::Token tok = range[i];
    auto &info = info_alloc.emplace_back();

    switch (tok.Role()) {
      case pasta::TokenRole::kInvalid:
      case pasta::TokenRole::kPrintedToken:
        LOG(FATAL)
            << "Invalid or unexpected tokens in range";
        break;

      case pasta::TokenRole::kMacroExpansionToken:
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kMacroExpansionToken;
        continue;

      case pasta::TokenRole::kBeginOfMacroExpansionMarker: {
        auto num_added = 0u;
        for (pasta::FileToken ft : tok.MacroUseTokens()) {
          auto &sub_info = info_alloc.emplace_back();
          sub_info.file_tok = std::move(ft);
          sub_info.category = TokenInfo::kMacroUseToken;
          ++num_added;
        }
        CHECK_LT(0u, num_added);
        [[clang::fallthrough]];
      }

      case pasta::TokenRole::kBeginOfFileMarker:
      case pasta::TokenRole::kEndOfFileMarker:
      case pasta::TokenRole::kEndOfMacroExpansionMarker:
        info.file_tok = tok.FileLocation();
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kMarkerToken;
        continue;

      case pasta::TokenRole::kFileToken:
        info.file_tok = tok.FileLocation();
        info.parsed_tok = std::move(tok);
        info.category = TokenInfo::kFileToken;
        continue;
    }
  }

  // Link them all together.
  auto it = info_alloc.begin();
  auto end = info_alloc.end();
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
static TokenInfo *FillMissingToken(std::deque<TokenInfo> &info_alloc,
                                   pasta::FileToken tok,
                                   TokenInfo *prev) {
  switch (mx::FromClang(tok.Kind())) {
    case mx::TokenKind::TK_eof:
    case mx::TokenKind::TK_eod:
    case mx::TokenKind::TK_code_completion:
      return prev;
    default:
      break;
  }

  TokenInfo &missing_info = info_alloc.emplace_back();
  missing_info.next = prev->next;
  missing_info.category = TokenInfo::kMissingFileToken;
  missing_info.file_tok = std::move(tok);
  prev->next = &missing_info;
  prev = &missing_info;
  return &missing_info;
}

// Return `true` if `data` contains one or more whitespace characters, and
// nothing else.
static bool IsWhitespace(std::string_view data) {
  auto is_whitespace = false;
  for (auto ch : data) {
    switch (ch) {
      case ' ': case '\t': case '\r': case '\n': case '\\':
        is_whitespace = true;
        continue;
      default:
        return false;
    }
  }
  return is_whitespace;
}

// Fill in the missing tokens from the token tree.
static TokenInfo *FillMissingFileTokens(std::deque<TokenInfo> &info_alloc,
                                        std::stringstream &err) {

  TokenInfo * const first = &(info_alloc.front());
  CHECK(first->parsed_tok.has_value());
  CHECK(first->file_tok.has_value());

  std::vector<std::pair<pasta::File, pasta::FileToken>> last_tok_from_file;

  // Base case to track that we're always in something.
  last_tok_from_file.emplace_back(
      pasta::File::Containing(first->file_tok.value()),
      first->file_tok.value());

  TokenInfo *prev = first;
  for (auto curr = first->next; curr; prev = curr, curr = curr->next) {
    DCHECK_NE(curr, prev);
    CHECK(!last_tok_from_file.empty());

    switch (curr->category) {
      case TokenInfo::kMissingFileToken:
        err << "Broken invariant; missing file token?";
        return nullptr;

      // The macro use tokens are taken from a file, and so we know that they
      // are "fine." We can rely on the expansion begin/end markers to tell
      // us what to fill around.
      case TokenInfo::kMacroUseToken:
        last_tok_from_file.back().second = std::move(curr->file_tok.value());
        continue;

      // With macro expansion tokens there's nothing to do really.
      case TokenInfo::kMacroExpansionToken:
        continue;

      default:
        break;
    }

    const pasta::Token &curr_tok = curr->parsed_tok.value();
    pasta::FileToken curr_file_tok = curr->file_tok.value();

    // We must be at the end of a macro expansion.
    if (prev->category == TokenInfo::kMacroExpansionToken) {
      CHECK(curr_tok.Role() == pasta::TokenRole::kEndOfMacroExpansionMarker);
//      last_tok_from_file.back().second = std::move(curr_file_tok);
      continue;
    }

    CHECK(curr->parsed_tok.has_value());
    CHECK(curr->file_tok.has_value());
    CHECK(prev->file_tok.has_value());

//    const pasta::Token &prev_tok = prev->parsed_tok.value();
    pasta::TokenRole prev_tok_role = pasta::TokenRole::kInvalid;
    if (prev->parsed_tok) {
      prev_tok_role = prev->parsed_tok->Role();
    } else {
      CHECK(prev->category == TokenInfo::kMacroUseToken);
      prev_tok_role = pasta::TokenRole::kFileToken;
    }

    pasta::FileToken prev_file_tok = prev->file_tok.value();
    pasta::File prev_file = pasta::File::Containing(prev_file_tok);

    pasta::File curr_file = pasta::File::Containing(curr_file_tok);
    const pasta::TokenRole curr_tok_role = curr_tok.Role();

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
        CHECK(pasta::File::Containing(next_tok_from_prev_file) == prev_file);

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
            prev = FillMissingToken(info_alloc, std::move(*missing_tok), prev);
            prev_was_whitespace = IsWhitespace(prev->file_tok->Data());
          } else {
            missing_tok = missing_toks[i];
          }
        }
        if (missing_tok && !prev_was_whitespace) {
          last_tok_from_file.back().second = missing_tok.value();
          prev = FillMissingToken(info_alloc, std::move(*missing_tok), prev);
        }
      }

      last_tok_from_file.emplace_back(curr_file, curr_file_tok);
      continue;

    // We're about to exit a file, make sure to back-fill any trailing tokens
    // from within the end of that file.
    } else if (pasta::TokenRole::kEndOfFileMarker == curr_tok_role) {
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
          prev = FillMissingToken(info_alloc, std::move(exited_tok), prev);
        }

      // The included/imported file appeared non-empty to the parser; see if
      // we need to back fill.
      } else {
        for (uint64_t i = exited_tok.Index() + 1u, max_i = exited_toks.Size();
             i < max_i; ++i) {
          prev = FillMissingToken(info_alloc, exited_toks[i], prev);
        }
      }

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
        prev = FillMissingToken(info_alloc, missing_toks[i], prev);
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

  auto prev_file_tok = first->file_tok.value();
  auto prev_index = prev_file_tok.Index();

  for (auto curr = first->next; curr; prev = curr, curr = curr->next) {
    if (TokenInfo::kMacroExpansionToken == curr->category) {
      continue;
    }

    auto curr_index = curr->file_tok->Index();
    if (prev_index == curr_index || (prev_index + 1u) == curr_index) {

      if ((TokenInfo::kMacroExpansionToken != curr->category &&
           TokenInfo::kMarkerToken != curr->category) ||
          (pasta::TokenRole::kEndOfMacroExpansionMarker !=
           curr->parsed_tok->Role())) {
        prev_file_tok = curr->file_tok.value();
        prev_index = curr_index;
      }

      continue;
    }

    auto prev_file = pasta::File::Containing(prev_file_tok);
    auto curr_file = pasta::File::Containing(*(curr->file_tok));
    if (prev_file != curr_file) {
      prev_file_tok = curr->file_tok.value();
      prev_index = curr_index;
      continue;
    }

    pasta::FileTokenRange missing_toks = prev_file.Tokens();
    for (auto i = prev_index + 1u; i < curr_index; ++i) {
      prev = FillMissingToken(info_alloc, missing_toks[i], prev);
    }

    prev_index = curr_index;
    prev_file_tok = curr->file_tok.value();
  }

  return first;
}

}  // namespace

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

  std::deque<TokenInfo> info_alloc;
  BuildInitialTokenList(std::move(range), begin_index, end_index, info_alloc);
  if (info_alloc.empty()) {
    err << "Cannot create token tree from empty token range";
    return err.str();
  }

//  std::cerr << "----------------------------------------------------- " << info_alloc.size() << " ---\n";
//  for (auto info = &(info_alloc.front()); info; info = info->next) {
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
  auto info = FillMissingFileTokens(info_alloc, err);
  if (!info) {
    return err.str();
  }
//  std::cerr << "----------------------------------------------------- " << info_alloc.size() << " ---\n";
//  for (; info; info = info->next) {
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
//  std::cerr << "\n\n\n";
  return TokenTree(std::move(impl));
}

}  // namespace mx
