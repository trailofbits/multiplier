// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Token.h"

#include <cassert>
#include <cctype>
#include <clang/Basic/TokenKinds.h>
#include <multiplier/Compress.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Token.h>
#include <pasta/Util/File.h>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

namespace mx {
namespace {

static constexpr auto kTabSize = 4u;
static const char * const kLowerHex = "0123456789abcdef";
static const char * const kUpperHex = "0123456789ABCDEF";
static const char * const kOctal = "01234567";

static const char *kTokenSpelling[] = {

#define PUNCTUATOR(tok, spelling) spelling,
#define KEYWORD(tok, avail) #tok,
#define TOK(tok) "",
#include "clang/Basic/TokenKinds.def"

#define PPKEYWORD(tok) "#" #tok,
#include "clang/Basic/TokenKinds.def"

#define OBJC_AT_KEYWORD(tok) "@" #tok,
#include "clang/Basic/TokenKinds.def"
};

static const std::unordered_map<std::string_view, TokenKind> kSpellingToKind{
#define PUNCTUATOR(tok, spelling) {spelling, TokenKind::TK_ ## tok},
#define KEYWORD(tok, avail) {#tok, TokenKind::TK_kw_ ## tok},
#include "clang/Basic/TokenKinds.def"

#define PPKEYWORD(tok) {"#" #tok, TokenKind::TK_pp_ ## tok},
#include "clang/Basic/TokenKinds.def"

#define OBJC_AT_KEYWORD(tok) {"@" #tok, TokenKind::TK_objc_ ## tok},
#include "clang/Basic/TokenKinds.def"
};

enum class CompressedTokenState {

  kInvalid,

  // A token whose spelling is fetched from data.
  kToken,
  kTokenWithLeadingSpaces,
  kTokenWithLeadingNewLine,
  kTokenWithLeadingNewLineAndSpaces,

  // A token's whose spelling is deterministic, and so doesn't need to be
  // stored.
  kTokenWithImpliedSpelling,
  kTokenWithImpliedSpellingAndLeadingSpaces,
  kTokenWithImpliedSpellingAndLeadingNewLine,
  kTokenWithImpliedSpellingAndLeadingNewLineAndSpaces,

  // Whitespace that couldn't be easily summarized into a compressed token
  // kind, and so much be fetched from data.
  kUncompressedWhitespace,

  // Zero-or-more new lines leading new lines, no leading spaces.
  kNewLines,

  // Zero-or-more new lines leading new lines with line continuations,
  // no leading spaces.
  kNewLinesWithContinuations,

  // Zero-or-more new lines, one-or-more leading spaces.
  kNewLinesAndSpaces,

  // Zero-or-more new lines with line continuations, one-or-more leading spaces.
  kNewLinesWithContinuationsAndSpaces,

  kIdentifier1,
  kIdentifier2,

  kNumber1,  // E.g. 1.
  kNumber2,  // E.g. 10, 1u, 1l.

  kHex1,  // E.g. `0xF`
  kHex2,  // E.g. `0xFF`.
  kHex3,  // E.g. `0xFFF`.

  kOctal1,  // E.g. `01`.
  kOctal2,  // E.g. `011`.
  kOctal3,  // E.g. `0777`.
  kOctal4,  // E.g. `07777`.
};

enum class DecompressionStatus {
  kTokenAndWhitespace,
  kTokenOnly,
  kWhitespaceOnly,
  kFailedInvalidKind,
  kFailedNoImpliedSpelling,
  kFailedUnknown,
};

enum CompressedTokenStateImpl {

  // Whitespace only, or a token with implied spelling.
  kCompressedToken,

  // A token with concrete spelling.
  kToken,

  // Embedding of the token data inside of the token.
  kInlineAscii,

  // Embedding of the token data inside of the token.
  kInlineNumbers
};

enum class NumberKind {
  kOctal,  // Leading `0` injected.
  kHex,  // Leading `0x` injected.
};

union CompressedTokenKind {
  uint16_t flat{0};

  // A token. The state tells us whether or not to look into the `data` to see
  // if the token's spelling is in the data or if it can be inferred from the
  // kind.
  struct {
    uint16_t state:2;
    uint16_t has_leading_new_line:1;
    uint16_t leading_spaces:4;
    uint16_t kind:9;
  } __attribute__((packed)) token;

  // Zero-or-more new lines, and no spaces.
  struct {
    uint16_t state:2;
    uint16_t use_leading_line_continuations:1;
    uint16_t leading_new_lines:4;
    uint16_t whitespace_kind:9;
  } __attribute__((packed)) new_lines;

  // The difference between `excess_kind` and the maximum `TokenKind` is the
  // number of leading spaces.
  struct {
    uint16_t state:2;
    uint16_t use_leading_line_continuations:1;
    uint16_t leading_new_lines:4;
    uint16_t excess_kind:9;
  } __attribute__((packed)) whitespace;

  // One or two 7-bit ASCII characters.
  struct {
    uint16_t state:2;
    uint16_t ascii_0:7;
    uint16_t ascii_1:7;
  } __attribute__((packed)) ascii_2;

  // One, two, or three hexadecimal digits. Auto-prefixed with `0x`.
  struct {
    uint16_t state:2;
    uint16_t number_kind:1;
    uint16_t is_upper:1;
    uint16_t hex_0:4;
    uint16_t hex_1:4;
    uint16_t hex_2:4;
  } __attribute__((packed)) hex_3;

  // One, two, or three decimal digits. Auto-prefixed with `0o`.
  struct {
    uint16_t state:2;
    uint16_t number_kind:1;
    uint16_t unused:1;
    uint16_t octal_0:3;
    uint16_t octal_1:3;
    uint16_t octal_2:3;
    uint16_t octal_3:3;
  } __attribute__((packed)) octal_4;

  // Interpret and return the state of this token.
  CompressedTokenState State(void) const;

  // Consume zero or more bytes from `data`, updating `data` in place, and
  // render the uncompressed whitespace into `ws_spelling` and token data
  // into `tok_spelling`, and then return the kind of `token` and the status of
  // the decompression.
  std::pair<DecompressionStatus, TokenKind> Uncompress(
      std::string &ws_spelling, std::string &tok_spelling,
      const char *&data) const noexcept;

} __attribute__((packed));

static_assert(sizeof(CompressedTokenKind) == sizeof(TokenKind));

static constexpr CompressedTokenKind kAllOnesToken = {
    static_cast<uint16_t>(0xFFu)};
static const auto kMaxEmbeddedLeadingSpaces =
    kAllOnesToken.token.leading_spaces;
static constexpr auto kMaxTokenKind = static_cast<uint16_t>(TokenKind::MAX);
static constexpr auto kWhitespaceKind =
    static_cast<uint16_t>(TokenKind::TK_whitespace);

static bool IsIdentifierBegin(int ch) {
  return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || '_' == ch;
}

static bool IsDigit(int ch) {
  return '0' <= ch && ch <= '9';
}

static uint16_t HexToDigit(char ch, uint16_t *is_uppercase, bool *failed) {
  switch (ch) {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
      return static_cast<uint16_t>(ch - '0');
    case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
      return static_cast<uint16_t>(ch - 'a');
    case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
      *is_uppercase = static_cast<uint16_t>(1);
      return static_cast<uint16_t>(ch - 'A');
    default:
      *failed = true;
      return static_cast<uint16_t>(0);
  }
}

static uint16_t OctalToDigit(char ch, bool *failed) {
  switch (ch) {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7':
      return static_cast<uint16_t>(ch - '0');
    default:
      *failed = true;
      return static_cast<uint16_t>(0);
  }
}

// Make sure that nine bits is enough to hold any valid `TokenKind`. We use
// nine bits in the `CompressedTokenKind`.
static constexpr struct {
  uint16_t bits:9;
} kTokenStorage = {kMaxTokenKind};

static_assert(kTokenStorage.bits == kMaxTokenKind);
static_assert(TokenKind::TK_unknown == static_cast<TokenKind>(0u));

static constexpr auto kMaxSpelling = sizeof(kTokenSpelling) /
                                     sizeof(kTokenSpelling[0]);

// kCompressedToken
static CompressedTokenState State0(CompressedTokenKind t) {
  if (t.token.kind != kWhitespaceKind) {
    if (t.token.kind > kMaxTokenKind) {
      if (t.whitespace.use_leading_line_continuations) {
        return CompressedTokenState::kNewLinesWithContinuationsAndSpaces;
      } else {
        return CompressedTokenState::kNewLinesAndSpaces;
      }
    } else {
      if (t.token.kind >= kMaxSpelling) {
        assert(false);
        return CompressedTokenState::kInvalid;

      } else if (!kTokenSpelling[t.token.kind][0]) {
        assert(false);
        return CompressedTokenState::kInvalid;

      } else if (t.token.has_leading_new_line) {
        if (t.token.leading_spaces) {
          return CompressedTokenState::kTokenWithImpliedSpellingAndLeadingNewLineAndSpaces;
        } else {
          return CompressedTokenState::kTokenWithImpliedSpellingAndLeadingNewLine;
        }

      } else {
        if (t.token.leading_spaces) {
          return CompressedTokenState::kTokenWithImpliedSpellingAndLeadingSpaces;
        } else {
          return CompressedTokenState::kTokenWithImpliedSpelling;
        }
      }
    }

  // Zero-or-more new lines, and no spaces.
  } else {
    if (t.new_lines.use_leading_line_continuations) {
      return CompressedTokenState::kNewLinesWithContinuations;
    } else {
      return CompressedTokenState::kNewLines;
    }
  }
}

// kToken
static CompressedTokenState State1(CompressedTokenKind t) {
  if (t.token.kind != kWhitespaceKind) {
    if (t.token.kind > kMaxTokenKind) {
      assert(false);
      return CompressedTokenState::kInvalid;
    } else {
      if (t.token.has_leading_new_line) {
        if (t.token.leading_spaces) {
          return CompressedTokenState::kTokenWithLeadingNewLineAndSpaces;
        } else {
          return CompressedTokenState::kTokenWithLeadingNewLine;
        }
      } else {
        if (t.token.leading_spaces) {
          return CompressedTokenState::kTokenWithLeadingSpaces;
        } else {
          return CompressedTokenState::kToken;
        }
      }
    }
  } else {
    return CompressedTokenState::kUncompressedWhitespace;
  }
}

// kInlineAscii
static CompressedTokenState State2(CompressedTokenKind t) {
  if (IsIdentifierBegin(t.ascii_2.ascii_0)) {
    if (t.ascii_2.ascii_1) {
      if (std::isprint(static_cast<char>(t.ascii_2.ascii_1))) {
        return CompressedTokenState::kIdentifier2;
      } else {
        assert(false);
        return CompressedTokenState::kInvalid;
      }
    } else {
      return CompressedTokenState::kIdentifier1;
    }
  } else if (IsDigit(t.ascii_2.ascii_0)) {
    if (t.ascii_2.ascii_1) {
      if (std::isprint(static_cast<char>(t.ascii_2.ascii_1))) {
        return CompressedTokenState::kNumber2;
      } else {
        assert(false);
        return CompressedTokenState::kInvalid;
      }
    } else {
      return CompressedTokenState::kNumber1;
    }
  } else {
    assert(false);
    return CompressedTokenState::kInvalid;
  }
}

// kInlineNumbers
static CompressedTokenState State3(CompressedTokenKind t) {
  switch (static_cast<NumberKind>(t.hex_3.number_kind)) {
    case NumberKind::kOctal:
      if (t.octal_4.octal_0) {
        return CompressedTokenState::kOctal4;
      } else if (t.octal_4.octal_1) {
        return CompressedTokenState::kOctal3;
      } else if (t.octal_4.octal_2) {
        return CompressedTokenState::kOctal2;
      } else if (t.octal_4.octal_3) {
        return CompressedTokenState::kOctal1;
      } else {
        assert(false);
        return CompressedTokenState::kInvalid;
      }
    case NumberKind::kHex:
      if (t.hex_3.hex_0) {
        return CompressedTokenState::kHex3;
      } else if (t.hex_3.hex_1) {
        return CompressedTokenState::kHex2;
      } else if (t.hex_3.hex_2) {
        return CompressedTokenState::kHex1;
      } else {
        assert(false);
        return CompressedTokenState::kInvalid;
      }
  }
  assert(false);
  return CompressedTokenState::kInvalid;
}

struct Whitespace {
  unsigned num_leading_spaces{0u};
  unsigned num_leading_new_lines{0u};
  unsigned num_line_continuations{0u};
  bool has_unexpected_stuff{false};
  bool has_non_whitespace{false};
  bool has_whitespace{false};
};

static Whitespace SummarizeWhitespace(std::string_view tok_data) {
  Whitespace ret;
  for (auto ch : tok_data) {
    if (ch == '\\') {
      // ret.has_whitespace = true;
      ret.num_line_continuations++;
      ret.num_leading_spaces = 0u;

    } else if (ch == '\n') {
      ret.has_whitespace = true;
      ret.num_leading_new_lines++;
      ret.num_leading_spaces = 0u;

    } else if (ch == ' ') {
      ret.has_whitespace = true;
      ret.num_leading_spaces++;

    } else if (ch == '\t') {
      ret.has_whitespace = true;
      ret.num_leading_spaces += kTabSize;

    } else if (!isascii(ch) || !std::isprint(ch)) {
      ret.has_unexpected_stuff = true;
      break;

    } else {
      ret.has_non_whitespace = true;
      break;
    }
  }
  return ret;
}

static bool CompressInteger(std::string_view tok_data,
                            CompressedTokenKind *ct_out) {
  CompressedTokenKind ct = {};
  char data[8] = {};
  auto tok_len = 0u;
  for (auto ch : tok_data) {
    if (!isascii(ch)) {
      return false;
    } else {
      data[tok_len++] = ch;
    }
  }

  assert(data[0] == '0');
  assert(2 <= tok_len);

  bool failed = false;

  // Hex.
  if (data[1] == 'x' && data[1] == 'X' && 3 <= tok_len && data[2] != '0') {
    uint16_t uppercase = 0;

    // kHex3
    if (tok_len == 5) {
      ct.hex_3.state = static_cast<uint16_t>(
          CompressedTokenStateImpl::kInlineNumbers);
      ct.hex_3.number_kind = static_cast<uint16_t>(NumberKind::kHex);
      ct.hex_3.hex_0 = HexToDigit(data[2], &uppercase, &failed);
      ct.hex_3.hex_1 = HexToDigit(data[3], &uppercase, &failed);
      ct.hex_3.hex_2 = HexToDigit(data[4], &uppercase, &failed);
      ct.hex_3.is_upper = uppercase;
      assert(failed || ct.hex_3.hex_0 != 0);

    // kHex2
    } else if (tok_len == 4) {
      ct.hex_3.state = static_cast<uint16_t>(
          CompressedTokenStateImpl::kInlineNumbers);
      ct.hex_3.number_kind = static_cast<uint16_t>(NumberKind::kHex);
      ct.hex_3.hex_1 = HexToDigit(data[2], &uppercase, &failed);
      ct.hex_3.hex_2 = HexToDigit(data[3], &uppercase, &failed);
      assert(failed || ct.hex_3.hex_1 != 0);
      ct.hex_3.is_upper = uppercase;

    // kHex1
    } else if (tok_len == 3) {
      ct.hex_3.state = static_cast<uint16_t>(
          CompressedTokenStateImpl::kInlineNumbers);
      ct.hex_3.number_kind = static_cast<uint16_t>(NumberKind::kHex);
      ct.hex_3.hex_2 = HexToDigit(data[2], &uppercase, &failed);
      assert(failed || ct.hex_3.hex_2 != 0);
      ct.hex_3.is_upper = uppercase;

    } else {
      return false;
    }

  // Octal.
  } else if ('1' <= data[1] && data[1] <= '7' && 2 <= tok_len) {

    // kOctal4
    if (tok_len == 5) {
      ct.octal_4.state = static_cast<uint16_t>(
          CompressedTokenStateImpl::kInlineNumbers);
      ct.octal_4.number_kind = static_cast<uint16_t>(
          NumberKind::kOctal);
      ct.octal_4.octal_0 = OctalToDigit(data[1], &failed);
      ct.octal_4.octal_1 = OctalToDigit(data[2], &failed);
      ct.octal_4.octal_2 = OctalToDigit(data[3], &failed);
      ct.octal_4.octal_3 = OctalToDigit(data[4], &failed);
      assert(failed || ct.octal_4.octal_0 != 0);

    // kOctal3
    } else if (tok_len == 4) {
      ct.octal_4.state = static_cast<uint16_t>(
          CompressedTokenStateImpl::kInlineNumbers);
      ct.octal_4.number_kind = static_cast<uint16_t>(
          NumberKind::kOctal);
      ct.octal_4.octal_1 = OctalToDigit(data[1], &failed);
      ct.octal_4.octal_2 = OctalToDigit(data[2], &failed);
      ct.octal_4.octal_3 = OctalToDigit(data[3], &failed);
      assert(failed || ct.octal_4.octal_1 != 0);

    // kOctal2
    } else if (tok_len == 3) {
      ct.octal_4.state = static_cast<uint16_t>(
          CompressedTokenStateImpl::kInlineNumbers);
      ct.octal_4.number_kind = static_cast<uint16_t>(
          NumberKind::kOctal);
      ct.octal_4.octal_2 = OctalToDigit(data[1], &failed);
      ct.octal_4.octal_3 = OctalToDigit(data[2], &failed);
      assert(failed || ct.octal_4.octal_2 != 0);

    // kOctal1
    } else if (tok_len == 2) {
      ct.octal_4.state = static_cast<uint16_t>(
          CompressedTokenStateImpl::kInlineNumbers);
      ct.octal_4.number_kind = static_cast<uint16_t>(
          NumberKind::kOctal);
      ct.octal_4.octal_3 = OctalToDigit(data[1], &failed);
      assert(failed || ct.octal_4.octal_3 != 0);

    } else {
      return false;
    }

  } else {
    return false;
  }

  // E.g. `0x0L` or `0L`.
  if (failed) {
    return false;
  }

  *ct_out = ct;
  return true;
}

static bool CompressAscii(std::string_view tok_data, size_t tok_len,
                          CompressedTokenKind *ct_out) {
  assert(0 < tok_len);
  if (!IsIdentifierBegin(tok_data[0]) && !IsDigit(tok_data[0])) {
    return false;
  }

  CompressedTokenKind ct = {};

  // kIdentifier2 or kNumber2.
  if (tok_len == 2 && isprint(tok_data[1])) {
    ct.ascii_2.state = static_cast<uint16_t>(
        CompressedTokenStateImpl::kInlineAscii);
    ct.ascii_2.ascii_0 = static_cast<uint16_t>(tok_data[0]);
    ct.ascii_2.ascii_1 = static_cast<uint16_t>(tok_data[1]);
    *ct_out = ct;
    return true;

  // kIdentifier1 or kNumber1
  } else if (tok_len == 1 && isascii(tok_data[0])) {
    ct.ascii_2.state = static_cast<uint16_t>(
        CompressedTokenStateImpl::kInlineAscii);
    ct.ascii_2.ascii_0 = static_cast<uint16_t>(tok_data[0]);
    *ct_out = ct;
    return true;

  } else {
    return false;
  }
}

static bool CompressWhitespace(std::string_view tok_data, Whitespace ws,
                               CompressedTokenKind *ct_out) {

  // We encountered some unusual characters; materialize the whitespace.
  if (ws.has_non_whitespace || ws.has_unexpected_stuff) {
    return false;
  }

  // Some new lines are preceded by line continuations, while others aren't.
  // Materialize the whitespace.
  if (ws.num_line_continuations &&
      ws.num_line_continuations != ws.num_leading_new_lines) {
    return false;
  }

  CompressedTokenKind ct = {};

  // Zero leading spaces.
  if (!ws.num_leading_spaces) {
    ct.new_lines.whitespace_kind = kWhitespaceKind;
    ct.new_lines.leading_new_lines =
        static_cast<uint16_t>(ws.num_leading_new_lines);

    // Overflow, materialize the whitespace.
    if (ct.new_lines.leading_new_lines != ws.num_leading_new_lines) {
      return false;
    }

    if (ws.num_line_continuations) {
      ct.new_lines.use_leading_line_continuations = static_cast<uint16_t>(1);
    }

    *ct_out = ct;
    return true;

  // One or more leading spaces.
  } else {

    ct.whitespace.leading_new_lines =
        static_cast<uint16_t>(ws.num_leading_new_lines);

    // Overflow, materialize the whitespace.
    if (ct.whitespace.leading_new_lines != ws.num_leading_new_lines) {
      return false;
    }

    if (ws.num_line_continuations) {
      ct.whitespace.use_leading_line_continuations = static_cast<uint16_t>(1);
    }

    auto excess = kMaxTokenKind + ws.num_leading_spaces;
    ct.whitespace.excess_kind = static_cast<uint16_t>(excess);

    // Overflow, materialize the whitespace.
    if (excess != ct.whitespace.excess_kind) {
      return false;
    }

    *ct_out = ct;
    return true;
  }
}

static bool CompressSingleImpl(TokenKind tok_kind, std::string_view tok_data,
                               CompressedTokenKind *ct_out,
                               std::string &output) {

  auto tok_len = tok_data.size();

  // kNewLines.
  if (!tok_len) {
    static_assert(
        !static_cast<uint16_t>(CompressedTokenStateImpl::kCompressedToken));
    *ct_out = {};
    return true;
  }

  auto ws = SummarizeWhitespace(tok_data);

  // Normalize whitespace.
  if (TokenKind::TK_unknown == tok_kind && ws.has_whitespace &&
      !ws.has_non_whitespace && !ws.has_unexpected_stuff) {
    tok_kind = TokenKind::TK_whitespace;
  }

  // It's a whitespace token.
  if (TokenKind::TK_whitespace == tok_kind) {
    if (CompressWhitespace(tok_data, ws, ct_out)) {
      return true;

    // kUncompressedWhitespace.
    } else {
      ct_out->token.kind = kWhitespaceKind;
      ct_out->token.state = static_cast<uint16_t>(
          CompressedTokenStateImpl::kToken);
      output.insert(output.end(), tok_data.begin(), tok_data.end());
      output.push_back('\0');
      return true;
    }

  } else if (TokenKind::TK_eof == tok_kind) {
    return false;
  }

  // Normalize keywords.
  if (auto kws = pasta::KeywordSpellingOrNull(ToPasta(tok_kind))) {
    tok_data = kws;
  }

  // Normalize by spelling.
  if (auto it = kSpellingToKind.find(tok_data); it != kSpellingToKind.end()) {
    tok_kind = it->second;
  }

  CompressedTokenKind ct = {};
  auto tok_kind_u = static_cast<unsigned>(tok_kind);

  // kToken, but where we don't try to summarize the whitespace of the token
  // into a prefix, because otherwise we'd end up introducing a token that
  // wasn't actually present.
  if (ws.has_whitespace) {
    ct.token.state = static_cast<uint16_t>(
        CompressedTokenStateImpl::kToken);
    ct.token.kind = static_cast<uint16_t>(tok_kind);
    output.insert(output.end(), tok_data.begin(), tok_data.end());
    output.push_back('\0');
    *ct_out = ct;
    return true;

  // kTokenWithImpliedSpelling
  } else if (tok_kind_u < kMaxSpelling &&
             tok_data == kTokenSpelling[tok_kind_u]) {
    static_assert(
        !static_cast<uint16_t>(CompressedTokenStateImpl::kCompressedToken));
    assert(!ct_out->token.state);
    ct_out->token.kind = static_cast<uint16_t>(tok_kind);
    return true;

  // kHex1, kHex2, kHex3, kOctal1, kOctal2, kOctal3, kOctal4.
  } else if (TokenKind::TK_numeric_constant == tok_kind &&
             2 <= tok_len && tok_len <= 6 && tok_data[0] == '0' &&
             CompressInteger(tok_data, ct_out)) {
    return true;

  // kIdentifier1, kIdentifier2, kNumber1, kNumber2
  } else if (CompressAscii(tok_data, tok_len, ct_out)) {
    return true;

  // kToken
  } else {
    ct.token.state = static_cast<uint16_t>(
        CompressedTokenStateImpl::kToken);
    ct.token.kind = static_cast<uint16_t>(tok_kind);
    output.insert(output.end(), tok_data.begin(), tok_data.end());
    output.push_back('\0');
    *ct_out = ct;
    return true;
  }
}

// Interpret and return the state of this token.
CompressedTokenState CompressedTokenKind::State(void) const {
  switch (static_cast<CompressedTokenStateImpl>(token.state)) {
    case CompressedTokenStateImpl::kCompressedToken:
      return State0(*this);
    case CompressedTokenStateImpl::kToken:
      return State1(*this);
    case CompressedTokenStateImpl::kInlineAscii:
      return State2(*this);
    case CompressedTokenStateImpl::kInlineNumbers:
      return State3(*this);
  }
  assert(false);
  return CompressedTokenState::kInvalid;
}

// Consume zero or more bytes from `data`, updating `data` in place, and
// render the uncompressed whitespace into `ws_spelling` and token data
// into `tok_spelling`, and then return the kind of `token` and the status of
// the decompression.
std::pair<DecompressionStatus, TokenKind> CompressedTokenKind::Uncompress(
    std::string &ws_spelling, std::string &tok_spelling,
    const char *&data) const noexcept {

  auto add_data = [] (std::string &buff, const char *data) {
    while (auto ch = *data++) {
      buff.push_back(ch);
    }
    return data;
  };

  auto add_repeats = [] (std::string &buff, unsigned num, char ch) {
    for (auto i = 0u; i < num; ++i) {
      buff.push_back(ch);
    }
  };

  auto add_continations = [] (std::string &buff, unsigned num_lines,
                              unsigned num_spaces) {
    assert(0 < num_lines);
    buff.push_back(' ');
    buff.push_back('\\');
    buff.push_back('\n');
    for (auto i = 1u; i < num_lines; ++i) {
      for (auto s = 0u; s < num_spaces; ++s) {
        buff.push_back(' ');
      }
      buff.push_back('\\');
      buff.push_back('\n');
    }
  };

  switch (State()) {
    case CompressedTokenState::kInvalid:
      assert(false);
      return {DecompressionStatus::kFailedInvalidKind, TokenKind::TK_unknown};

    case CompressedTokenState::kToken: {
      data = add_data(tok_spelling, data);
      return {DecompressionStatus::kTokenOnly,
              static_cast<TokenKind>(token.kind)};
    }
    case CompressedTokenState::kTokenWithLeadingSpaces: {
      add_repeats(ws_spelling, token.leading_spaces, ' ');
      data = add_data(tok_spelling, data);
      return {DecompressionStatus::kTokenAndWhitespace,
              static_cast<TokenKind>(token.kind)};
    }
    case CompressedTokenState::kTokenWithLeadingNewLine: {
      ws_spelling.push_back('\n');
      data = add_data(tok_spelling, data);
      return {DecompressionStatus::kTokenAndWhitespace,
              static_cast<TokenKind>(token.kind)};
    }
    case CompressedTokenState::kTokenWithLeadingNewLineAndSpaces: {
      ws_spelling.push_back('\n');
      add_repeats(ws_spelling, token.leading_spaces, ' ');
      data = add_data(tok_spelling, data);
      return {DecompressionStatus::kTokenAndWhitespace,
              static_cast<TokenKind>(token.kind)};
    }

    case CompressedTokenState::kTokenWithImpliedSpelling: {
      tok_spelling += kTokenSpelling[token.kind];
      return {DecompressionStatus::kTokenOnly,
              static_cast<TokenKind>(token.kind)};
    }

    case CompressedTokenState::kTokenWithImpliedSpellingAndLeadingSpaces: {
      add_repeats(ws_spelling, token.leading_spaces, ' ');
      tok_spelling += kTokenSpelling[token.kind];
      return {DecompressionStatus::kTokenAndWhitespace,
              static_cast<TokenKind>(token.kind)};
    }

    case CompressedTokenState::kTokenWithImpliedSpellingAndLeadingNewLine: {
      ws_spelling.push_back('\n');
      tok_spelling += kTokenSpelling[token.kind];
      return {DecompressionStatus::kTokenAndWhitespace,
              static_cast<TokenKind>(token.kind)};
    }

    case CompressedTokenState::kTokenWithImpliedSpellingAndLeadingNewLineAndSpaces: {
      ws_spelling.push_back('\n');
      add_repeats(ws_spelling, token.leading_spaces, ' ');
      tok_spelling += kTokenSpelling[token.kind];
      return {DecompressionStatus::kTokenAndWhitespace,
              static_cast<TokenKind>(token.kind)};
    }

    case CompressedTokenState::kUncompressedWhitespace:
      data = add_data(ws_spelling, data);
      return {DecompressionStatus::kWhitespaceOnly, TokenKind::TK_whitespace};

    case CompressedTokenState::kNewLines:
      add_repeats(ws_spelling, new_lines.leading_new_lines, '\n');
      return {DecompressionStatus::kWhitespaceOnly, TokenKind::TK_whitespace};

    case CompressedTokenState::kNewLinesWithContinuations:
      add_continations(ws_spelling, new_lines.leading_new_lines, 0);
      return {DecompressionStatus::kWhitespaceOnly, TokenKind::TK_whitespace};

    case CompressedTokenState::kNewLinesAndSpaces: {
      unsigned num_spaces = whitespace.excess_kind - kMaxTokenKind;
      add_repeats(ws_spelling, whitespace.leading_new_lines, '\n');
      add_repeats(ws_spelling, num_spaces, ' ');
      return {DecompressionStatus::kWhitespaceOnly, TokenKind::TK_whitespace};
    }

    case CompressedTokenState::kNewLinesWithContinuationsAndSpaces: {
      unsigned num_spaces = whitespace.excess_kind - kMaxTokenKind;
      add_continations(ws_spelling, new_lines.leading_new_lines, num_spaces);
      add_repeats(ws_spelling, num_spaces, ' ');
      return {DecompressionStatus::kWhitespaceOnly, TokenKind::TK_whitespace};
    }

    case CompressedTokenState::kIdentifier1:
      tok_spelling.push_back(static_cast<char>(ascii_2.ascii_0));
      return {DecompressionStatus::kTokenOnly, TokenKind::TK_identifier};

    case CompressedTokenState::kIdentifier2:
      tok_spelling.push_back(static_cast<char>(ascii_2.ascii_0));
      tok_spelling.push_back(static_cast<char>(ascii_2.ascii_1));
      return {DecompressionStatus::kTokenOnly, TokenKind::TK_identifier};

    case CompressedTokenState::kNumber1:
      tok_spelling.push_back(static_cast<char>(ascii_2.ascii_0));
      return {DecompressionStatus::kTokenOnly, TokenKind::TK_numeric_constant};

    case CompressedTokenState::kNumber2:
      tok_spelling.push_back(static_cast<char>(ascii_2.ascii_0));
      tok_spelling.push_back(static_cast<char>(ascii_2.ascii_1));
      return {DecompressionStatus::kTokenOnly, TokenKind::TK_numeric_constant};

    case CompressedTokenState::kHex1:
      tok_spelling.push_back('0');
      tok_spelling.push_back('x');
      if (hex_3.is_upper) {
        tok_spelling.push_back(kUpperHex[hex_3.hex_2]);
      } else {
        tok_spelling.push_back(kLowerHex[hex_3.hex_2]);
      }
      return {DecompressionStatus::kTokenOnly, TokenKind::TK_numeric_constant};

    case CompressedTokenState::kHex2:
      tok_spelling.push_back('0');
      tok_spelling.push_back('x');
      if (hex_3.is_upper) {
        tok_spelling.push_back(kUpperHex[hex_3.hex_1]);
        tok_spelling.push_back(kUpperHex[hex_3.hex_2]);
      } else {
        tok_spelling.push_back(kLowerHex[hex_3.hex_1]);
        tok_spelling.push_back(kLowerHex[hex_3.hex_2]);
      }
      return {DecompressionStatus::kTokenOnly, TokenKind::TK_numeric_constant};

    case CompressedTokenState::kHex3:
      tok_spelling.push_back('0');
      tok_spelling.push_back('x');
      if (hex_3.is_upper) {
        tok_spelling.push_back(kUpperHex[hex_3.hex_0]);
        tok_spelling.push_back(kUpperHex[hex_3.hex_1]);
        tok_spelling.push_back(kUpperHex[hex_3.hex_2]);
      } else {
        tok_spelling.push_back(kLowerHex[hex_3.hex_0]);
        tok_spelling.push_back(kLowerHex[hex_3.hex_1]);
        tok_spelling.push_back(kLowerHex[hex_3.hex_2]);
      }
      return {DecompressionStatus::kTokenOnly, TokenKind::TK_numeric_constant};


    case CompressedTokenState::kOctal1:
      tok_spelling.push_back('0');
      tok_spelling.push_back(kOctal[octal_4.octal_3]);
      return {DecompressionStatus::kTokenOnly, TokenKind::TK_numeric_constant};

    case CompressedTokenState::kOctal2:
      tok_spelling.push_back('0');
      tok_spelling.push_back(kOctal[octal_4.octal_2]);
      tok_spelling.push_back(kOctal[octal_4.octal_3]);
      return {DecompressionStatus::kTokenOnly, TokenKind::TK_numeric_constant};

    case CompressedTokenState::kOctal3:
      tok_spelling.push_back('0');
      tok_spelling.push_back(kOctal[octal_4.octal_1]);
      tok_spelling.push_back(kOctal[octal_4.octal_2]);
      tok_spelling.push_back(kOctal[octal_4.octal_3]);
      return {DecompressionStatus::kTokenOnly, TokenKind::TK_numeric_constant};

    case CompressedTokenState::kOctal4:
      tok_spelling.push_back('0');
      tok_spelling.push_back(kOctal[octal_4.octal_0]);
      tok_spelling.push_back(kOctal[octal_4.octal_1]);
      tok_spelling.push_back(kOctal[octal_4.octal_2]);
      tok_spelling.push_back(kOctal[octal_4.octal_3]);
      return {DecompressionStatus::kTokenOnly, TokenKind::TK_numeric_constant};
  }

  assert(false);
  return {DecompressionStatus::kFailedUnknown, TokenKind::TK_unknown};
}

static bool CompressSingle(TokenKind tok_kind, std::string_view tok_data,
                           std::vector<uint16_t> &states,
                           std::string &output);

static bool CompressLeadingWhitespace(std::string_view whitespace_data,
                                      TokenKind tok_kind,
                                      std::string_view tok_data,
                                      std::vector<uint16_t> &states,
                                      std::string &output) {

  // Whitespace before an EOF.
  if (TokenKind::TK_eof == tok_kind) {
    return CompressSingle(TokenKind::TK_whitespace, whitespace_data,
                          states, output);
  }

  auto ws_ws = SummarizeWhitespace(whitespace_data);
  auto tok_ws = SummarizeWhitespace(tok_data);

  if (whitespace_data.empty() ||
      tok_ws.has_whitespace ||
      ws_ws.has_non_whitespace ||
      ws_ws.has_unexpected_stuff ||
      ws_ws.num_leading_new_lines > 1 ||
      ws_ws.num_leading_spaces > kMaxEmbeddedLeadingSpaces ||
      ws_ws.num_line_continuations != 0) {
    return CompressSingle(TokenKind::TK_whitespace, whitespace_data,
                          states, output) &&
           CompressSingle(tok_kind, tok_data, states, output);
  }

  CompressedTokenKind ct = {};
  const auto old_output_size = output.size();
  if (!CompressSingleImpl(tok_kind, tok_data, &ct, output)) {
    return false;
  }

  // Fold the leading whitespace into the token itself.
  if (auto state = ct.State();
      CompressedTokenState::kToken == state ||
      CompressedTokenState::kTokenWithImpliedSpelling == state) {
    if (ws_ws.num_leading_new_lines) {
      ct.token.has_leading_new_line = static_cast<uint16_t>(1);
    }
    ct.token.leading_spaces = static_cast<uint16_t>(
        ws_ws.num_leading_spaces);
    states.emplace_back(ct.flat);
    return true;
  }

  // Token was in the wrong state; materialize both.
  output.resize(old_output_size);
  return CompressSingle(TokenKind::TK_whitespace, whitespace_data,
                        states, output) &&
         CompressSingle(tok_kind, tok_data, states, output);
}

bool CompressSingle(TokenKind tok_kind, std::string_view tok_data,
                    std::vector<uint16_t> &states,
                    std::string &output) {
  CompressedTokenKind ct = {};
  if (CompressSingleImpl(tok_kind, tok_data, &ct, output)) {
    states.emplace_back(ct.flat);
    return true;
  } else {
    return false;
  }
}

#ifndef NDEBUG
static std::string_view StripWhitespace(std::string_view data) {
  while (auto size = data.size()) {
    switch (data.back()) {
      case '\r':
      case '\n':
      case '\t':
      case ' ':
      case '\\':
        data = data.substr(0, size - 1u);
        break;
      default:
        goto done_trailing;
    }
  }
done_trailing:
  while (auto size = data.size()) {
    switch (data.front()) {
      case '\r':
      case '\n':
      case '\t':
      case ' ':
      case '\\':
        data = data.substr(1, size - 1u);
        break;
      default:
        return data;
    }
  }

  return data;
}
#endif

}  // namespace

Token::~Token(void) {}

// Is this a valid token?
bool Token::IsValid(void) const noexcept {
  if (impl) {
    return index < impl->token_kinds.size();
  } else {
    return false;
  }
}

// Return the kind of this token.
TokenKind Token::Kind(void) const noexcept {
  if (impl && index < impl->token_kinds.size()) {
    return impl->token_kinds[index];
  } else {
    return TokenKind::TK_unknown;
  }
}

// Return the data of this token.
std::string_view Token::Data(void) const noexcept {
  auto next_index = index + 1u;
  if (impl && next_index < impl->data_offsets.size()) {
    auto start_offset = impl->data_offsets[index];
    auto len = impl->data_offsets[next_index] - start_offset;
    return std::string_view(impl->data).substr(start_offset, len);
  } else {
    return {};
  }
}

TokenList::TokenList(void)
    : impl(std::make_shared<TokenListImpl>()) {
  impl->data_offsets.push_back(0u);
  impl->data.push_back('\0');
}

TokenList::~TokenList(void) {}

// Return the token data as a single string.
std::string_view TokenList::Data(void) const noexcept {
  return std::string_view(impl->data).substr(0, impl->data.size() - 1u);
}

// Return the number of tokens in this token list.
unsigned TokenList::Size(void) const noexcept {
  return static_cast<unsigned>(impl->token_kinds.size());
}

void TokenListImpl::AddToken(std::string_view tok_data, TokenKind tok_kind,
                             std::vector<uint16_t> &dummy_states,
                             std::string &dummy_output) {
  dummy_states.clear();
  dummy_output.clear();
  if (!CompressSingle(tok_kind, tok_data, dummy_states, dummy_output)) {
    assert(false);
    return;
  }

  if (!dummy_output.empty()) {
    assert(dummy_output.back() == '\0');
  } else {
    dummy_output.push_back('\0');
  }

  assert(dummy_states.size() == 1u);

  CompressedTokenKind tk;
  tk.flat = dummy_states[0];
  const char *data_inout = dummy_output.data();
  const auto data_offset = static_cast<unsigned>(data.size());
  auto [status, new_tok_kind] = tk.Uncompress(data, data, data_inout);
  assert(data_offset <= data.size());
  assert(status == DecompressionStatus::kTokenOnly ||
         status == DecompressionStatus::kWhitespaceOnly);

  data_offsets.push_back(data_offset);
  token_kinds.push_back(new_tok_kind);

#ifndef NDEBUG
  std::string_view new_tok_data(data);
  new_tok_data = new_tok_data.substr(
      data_offset, static_cast<unsigned>(data.size()) - data_offset);
  assert(StripWhitespace(new_tok_data) == StripWhitespace(tok_data));
#endif
}

// Create a token list from a file token range.
TokenList TokenList::Create(const pasta::FileTokenRange &toks) {
  auto ls = std::make_shared<TokenListImpl>();

  std::vector<uint16_t> dummy_states;
  std::string dummy_output;

  for (pasta::FileToken tok : toks) {
    if (auto kind = FromPasta(tok.Kind()); TokenKind::TK_eof != kind) {
      ls->AddToken(tok.Data(), kind, dummy_states, dummy_output);
    } else {
      break;
    }
  }
  ls->data_offsets.push_back(static_cast<unsigned>(ls->data.size()));
  ls->data.push_back('\0');
  return TokenList(std::move(ls));
}

// Create a token list from a printed token range.
TokenList TokenList::Create(const pasta::PrintedTokenRange &toks) {
  auto ls = std::make_shared<TokenListImpl>();
  std::vector<uint16_t> dummy_states;
  std::string dummy_output;
  for (pasta::PrintedToken tok : toks) {
    if (auto kind = FromPasta(tok.Kind()); TokenKind::TK_eof != kind) {
      ls->AddToken(tok.Data(), kind, dummy_states, dummy_output);
    } else {
      break;
    }
  }
  ls->data_offsets.push_back(static_cast<unsigned>(ls->data.size()));
  ls->data.push_back('\0');
  return TokenList(std::move(ls));
}

// Create a token list from a parsed token range.
TokenList TokenList::Create(const pasta::TokenRange &toks) {
  auto ls = std::make_shared<TokenListImpl>();
  std::vector<uint16_t> dummy_states;
  std::string dummy_output;
  for (pasta::Token tok : toks) {
    if (auto kind = FromPasta(tok.Kind()); TokenKind::TK_eof != kind) {
      ls->AddToken(tok.Data(), kind, dummy_states, dummy_output);
    } else {
      break;
    }
  }
  ls->data_offsets.push_back(static_cast<unsigned>(ls->data.size()));
  ls->data.push_back('\0');
  return TokenList(std::move(ls));
}

// Uncompress a token list from its Flatbuffers-serialized form.
Result<TokenList, std::string> TokenList::Create(
    const CompressedTokenList &toks) {

  std::stringstream ss;

  auto contents = toks.Contents();
  auto kinds = toks.TokenKinds();
  if (!kinds) {
    if (contents) {
      ss << "Empty token kinds list with non-empty contents list";
      return ss.str();
    } else {
      return TokenList();
    }
  }

  std::string_view data_in = "\0\0";
  if (contents) {
    auto data_begin = reinterpret_cast<const char *>(contents->Data());
    data_in = std::string_view(data_begin, contents->size());
  }

  auto data_in_size = data_in.size();
  std::string uncompressed;

  // Not GZIP compressed.
  if (data_in.back() == '\0') {
    data_in = data_in.substr(0, data_in_size - 1u);

  // GZIP-compresses.
  } else if (data_in.back() == static_cast<char>(1)) {
    if (data_in.size() < 4u) {
      ss << "Corrupted token list contents; compressed contents "
            "should contain an uncompressed size";
      return ss.str();
    }

    size_t uncompressed_size = 0;
    uncompressed_size |= static_cast<uint8_t>(data_in[data_in_size - 2u]);
    uncompressed_size <<= 8u;
    uncompressed_size |= static_cast<uint8_t>(data_in[data_in_size - 3u]);
    uncompressed_size <<= 8u;
    uncompressed_size |= static_cast<uint8_t>(data_in[data_in_size - 4u]);

    data_in = data_in.substr(0, data_in_size - 4u);
    auto maybe_uncompressed = TryUncompress(data_in, uncompressed_size);
    if (maybe_uncompressed.Succeeded()) {
      uncompressed = maybe_uncompressed.TakeValue();
      data_in = uncompressed;

    } else {
      ss << "Error uncompressing compressed token contents: "
         << maybe_uncompressed.TakeError().message();
      return ss.str();
    }

  // Corrupted.
  } else {
    ss << "Corrupted token list contents; last byte should be 0 or 1";
    return ss.str();
  }

  std::string ws;
  std::string token;

  auto data = data_in.data();
  auto tk_begin = reinterpret_cast<const CompressedTokenKind *>(kinds->Data());
  auto tk_end = &(tk_begin[kinds->size()]);
  auto ls = std::make_shared<TokenListImpl>();

  for (auto tk = tk_begin; tk < tk_end; ++tk) {

    ws.clear();
    token.clear();

    auto [status, kind] = tk->Uncompress(ws, token, data);
    ls->data_offsets.push_back(static_cast<unsigned>(ls->data.size()));
    switch (status) {
      case DecompressionStatus::kTokenAndWhitespace:
        ls->data.insert(ls->data.end(), ws.begin(), ws.end());
        ls->token_kinds.push_back(TokenKind::TK_whitespace);

        ls->data_offsets.push_back(static_cast<unsigned>(ls->data.size()));
        ls->data.insert(ls->data.end(), token.begin(), token.end());
        ls->token_kinds.push_back(kind);
        continue;

      case DecompressionStatus::kTokenOnly:
        ls->data.insert(ls->data.end(), token.begin(), token.end());
        ls->token_kinds.push_back(kind);
        continue;

      case DecompressionStatus::kWhitespaceOnly:
        ls->data.insert(ls->data.end(), ws.begin(), ws.end());
        ls->token_kinds.push_back(TokenKind::TK_whitespace);
        continue;

      case DecompressionStatus::kFailedInvalidKind:
        ss << "Failed to decode compressed token list; "
              "found compressed token kind in invalid state";
        return ss.str();
      case DecompressionStatus::kFailedNoImpliedSpelling:
        ss << "Failed to decode compressed token list; "
              "missing implied spelling for token";
        return ss.str();
      case DecompressionStatus::kFailedUnknown:
        ss << "Failed to decode compressed token list for unknown reason";
        return ss.str();
    }
  }

  ls->data_offsets.push_back(static_cast<unsigned>(ls->data.size()));
  ls->data.push_back('\0');
  return TokenList(std::move(ls));
}

// Serialize this token list into a "compressed token list," as represented
// by a Flatbuffers message.
Result<flatbuffers::Offset<CompressedTokenList>, std::string>
TokenList::Compress(flatbuffers::FlatBufferBuilder &fbb) {
  std::string output;
  std::vector<uint16_t> states;
  std::string_view data(impl->data);

  auto i = 0u;
  auto it = impl->token_kinds.begin();
  auto end = impl->token_kinds.end();
  while (it != end) {
    auto tok_kind = *it++;
    auto start_offset = impl->data_offsets[i++];
    auto end_offset = impl->data_offsets[i];
    std::string_view tok_data = data.substr(
        start_offset, end_offset - start_offset);

    assert(TokenKind::TK_eof != tok_kind);

    if (it == end) {
      if (!CompressSingle(tok_kind, tok_data, states, output)) {
        std::stringstream ss;
        ss << "Unable to compress single token " << NameOf(tok_kind)
           << " with data <<<" << tok_data << ">>>";
        return ss.str();
      } else {
        break;
      }
    }

    auto next_tok_kind = *it;
    auto next_end_offset = impl->data_offsets[i + 1u];
    std::string_view next_tok_data = data.substr(
        end_offset, next_end_offset - end_offset);

    // We found some leading whitespace before `it`.
    if (tok_kind == TokenKind::TK_whitespace) {
      if (CompressLeadingWhitespace(tok_data, next_tok_kind, next_tok_data,
                                    states, output)) {
        ++it;  // Skip over the token following the whitespace.
        ++i;
      } else {
        std::stringstream ss;
        ss << "Unable to compress token " << NameOf(next_tok_kind)
           << " with data <<<" << next_tok_data
           << ">>> and leading whitespace <<<" << tok_data << ">>>";
        return ss.str();
      }
    } else {
      if (!CompressSingle(tok_kind, tok_data, states, output)) {
        std::stringstream ss;
        ss << "Unable to compress single token " << NameOf(tok_kind)
           << " with data <<<" << tok_data << ">>>";
        return ss.str();
      }
    }
  }

  const auto old_size = output.size();
  char is_compressed = '\0';
  if (old_size && old_size == (old_size & 0xFFFFFFu)) {
    auto maybe_compressed = TryCompress(output);
    if (maybe_compressed.Succeeded()) {
      if ((maybe_compressed->size() + 4u) < old_size) {
        output = maybe_compressed.TakeValue();
        output.push_back(static_cast<char>(old_size >> 0));
        output.push_back(static_cast<char>(old_size >> 8));
        output.push_back(static_cast<char>(old_size >> 16));
        is_compressed = static_cast<char>(1);
      }
    }
  }
  output.push_back(is_compressed);

  auto contents = fbb.CreateVector(
      reinterpret_cast<const uint8_t *>(output.data()), output.size());
  auto kinds = fbb.CreateVector(states.data(), states.size());
  CompressedTokenListBuilder tlb(fbb);
  tlb.add_Contents(std::move(contents));
  tlb.add_TokenKinds(std::move(kinds));
  return tlb.Finish();
}

}  // namespace mx
