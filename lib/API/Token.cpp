// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Token.h"
#include "File.h"
#include "Fragment.h"
#include "Use.h"
#include <multiplier/Entities/TokenKind.h>

#include <cassert>

namespace mx {
namespace {

static const std::shared_ptr<InvalidTokenReader> kInvalidTokenReader =
    std::make_shared<InvalidTokenReader>();

}  // namespace

TokenReader::~TokenReader(void) noexcept {}

TokenReader::Ptr TokenReader::ReaderForToken(
    const TokenReader::Ptr &self, const EntityProvider::Ptr &ep,
    EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<FileTokenId>(vid)) {
    FileTokenId tid = std::get<FileTokenId>(vid);
    if (auto fp = dynamic_cast<const PackedFileImpl *>(self.get());
        fp && fp->file_id == tid.file_id && tid.offset < fp->num_tokens) {
      return self;

    } else if (auto file = ep->FileFor(ep, tid.file_id);
               file && tid.offset < file->num_tokens) {
      return file->TokenReader(file);
    }

  } else if (std::holds_alternative<ParsedTokenId>(vid)) {
    ParsedTokenId tid = std::get<ParsedTokenId>(vid);
    if (auto fp = dynamic_cast<const PackedFragmentImpl *>(self.get());
        fp && fp->fragment_id == tid.fragment_id &&
        tid.offset < fp->num_parsed_tokens) {
      return self;

    } else if (auto frag = ep->FragmentFor(ep, tid.fragment_id);
               frag && tid.offset < frag->num_parsed_tokens) {
      return frag->TokenReader(frag);
    }

  } else if (std::holds_alternative<MacroTokenId>(vid)) {
    MacroTokenId tid = std::get<MacroTokenId>(vid);
    if (auto fp = dynamic_cast<const PackedFragmentImpl *>(self.get());
        fp && fp->fragment_id == tid.fragment_id &&
        fp->num_parsed_tokens <= tid.offset &&
        tid.offset < fp->num_tokens) {
      return self;

    } else if (auto frag = ep->FragmentFor(ep, tid.fragment_id);
               frag && frag->num_parsed_tokens <= tid.offset &&
               tid.offset < frag->num_tokens) {
      return frag->TokenReader(frag);
    }
  }

  return kInvalidTokenReader;
}

InvalidTokenReader::~InvalidTokenReader(void) noexcept {}

// Return the number of tokens accessible to this reader.
unsigned InvalidTokenReader::NumTokens(void) const {
  return 0u;
}

// Return the kind of the Nth token.
TokenKind InvalidTokenReader::NthTokenKind(unsigned) const {
  return TokenKind::UNKNOWN;
}

// Return the data of the Nth token.
std::string_view InvalidTokenReader::NthTokenData(unsigned) const {
  return {};
}

// Return the id of the token from which the Nth token is derived.
EntityId InvalidTokenReader::NthDerivedTokenId(unsigned) const {
  return kInvalidEntityId;
}

// Return the id of the Nth token.
EntityId InvalidTokenReader::NthTokenId(unsigned) const {
  return kInvalidEntityId;
}

EntityId InvalidTokenReader::NthFileTokenId(unsigned) const {
  return kInvalidEntityId;
}

// Return the token reader for another file.
TokenReader::Ptr InvalidTokenReader::ReaderForToken(
    const Ptr &self, RawEntityId id) const {
  return {};
}

// Returns `true` if `this` is logically equivalent to `that`.
bool InvalidTokenReader::Equals(const TokenReader *) const {
  return false;
}

Token::Token(void)
    : impl(kInvalidTokenReader),
      offset(0) {}

// Return `true` if this is a valid token.
Token::operator bool(void) const {
  return !dynamic_cast<const InvalidTokenReader *>(impl.get());
}

// Kind of this token.
TokenKind Token::kind(void) const {
  return impl->NthTokenKind(offset);
}

// Return the data of this token.
std::string_view Token::data(void) const & {
  return impl->NthTokenData(offset);
}

// Return the ID of this token.
EntityId Token::id(void) const {
  return impl->NthTokenId(offset);
}

// Return the token from which this token was derived. This can be a macro
// token or a file token.
std::optional<Token> Token::derived_token(void) const {
  mx::RawEntityId eid = impl->NthDerivedTokenId(offset);
  VariantId vid = EntityId(eid).Unpack();

  unsigned offset = 0u;

  if (std::holds_alternative<FileTokenId>(vid)) {
    offset = std::get<FileTokenId>(vid).offset;

  } else if (std::holds_alternative<ParsedTokenId>(vid)) {
    offset = std::get<ParsedTokenId>(vid).offset;

  } else if (std::holds_alternative<MacroTokenId>(vid)) {
    offset = std::get<MacroTokenId>(vid).offset;

  } else {
    return std::nullopt;
  }

  auto reader = impl->ReaderForToken(impl, eid);
  if (!reader || !reader->NumTokens()) {
    return std::nullopt;
  }

  return Token(std::move(reader), offset);
}

// Return the version of this token from a file, if any. If this is a parsed
// or macro token, then this will walk the derivation chain back to a file
// token.
std::optional<Token> Token::file_token(void) const {
  VariantId vid = EntityId(impl->NthFileTokenId(offset)).Unpack();
  if (!std::holds_alternative<FileTokenId>(vid)) {
    return std::nullopt;
  }

  FileTokenId fid = std::get<FileTokenId>(vid);
  auto fr = impl->ReaderForToken(impl, fid.file_id);
  if (!fr) {
    return std::nullopt;
  }

  return Token(std::move(fr), fid.offset);
}

// Return the version of this token from a file, if any. If there isn't a
// one-to-one correspondence between this token and a file token, then it
// likely means this token exists inside of a macro expansion. If that is the
// case, then this will return the beginning token of the macro expansion.
std::optional<Token> Token::nearest_file_token(void) const {
  for (auto i = 0u; i <= offset; ++i) {
    EntityId eid(impl->NthFileTokenId(offset - i));
    VariantId vid = eid.Unpack();
    if (std::holds_alternative<FileTokenId>(vid)) {
      FileTokenId fid = std::get<FileTokenId>(vid);
      if (auto fr = impl->ReaderForToken(impl, eid)) {
        return Token(std::move(fr), fid.offset);
      }
    }
  }

  return std::nullopt;
}

// Return the set of all uses of this token within its fragment (if it's a
// fragment token).
UseRange<TokenUseSelector> Token::uses(void) const {
  if (auto frag = Fragment::containing(*this)) {
    FragmentImpl::Ptr frag_ptr = std::move(frag->impl);
    return std::make_shared<UseIteratorImpl>(std::move(frag_ptr), *this);
  } else {
    return {};
  }
}

// Return the list of parsed tokens in the fragment. This doesn't
// include all tokens, i.e. macro use tokens, comments, etc.
TokenList Token::in(const Fragment &frag) {
  return frag.parsed_tokens();
}

// Return the list of tokens in this file.
TokenList Token::in(const File &file) {
  return file.tokens();
}

// Return the token list containing a particular token.
TokenList TokenList::containing(Token tok) {
  if (tok) {
    if (auto num_tokens = tok.impl->NumTokens()) {
      return TokenList(std::move(tok.impl), num_tokens);
    }
  }
  return TokenList();
}

// Return the token list containing a particular token range.
TokenList TokenList::containing(const TokenRange &range) {
  if (range.impl) {
    return TokenList(range.impl, range.impl->NumTokens());
  } else {
    return TokenList();
  }
}

TokenRange::TokenRange(void)
    : impl(kInvalidTokenReader),
      index(0),
      num_tokens(0) {}

TokenRange::TokenRange(const Token &tok)
    : impl(tok.impl),
      index(tok.offset),
      num_tokens(tok.impl ? (tok.offset + 1u) : 0u) {}

// Return the token at index `index`.
Token TokenRange::operator[](size_t relative_index) const {
  auto effective_index = (index + relative_index);
  if (effective_index >= num_tokens) {
    throw std::out_of_range(
        "Index " + std::to_string(relative_index) +
        " is out of range on mx::TokenRange");
  } else {
    return Token(impl, effective_index);
  }
}

// Return the first token.
Token TokenRange::front(void) const {
  return Token(impl, index);
}

// Return the last token.
Token TokenRange::back(void) const {
  return Token(impl, num_tokens - 1u);
}

// Return a slice of this token range. If the indices given are invalid, then
// an empty token range is returned. The indices cover the tokens in the
// exclusive range `[start_index, end_index)`.
TokenRange TokenRange::slice(size_t start_index,
                             size_t end_index) const noexcept {
  if (end_index <= start_index || start_index >= num_tokens ||
      end_index > num_tokens || (index + start_index) >= num_tokens ||
      (index + end_index) > num_tokens ||
      static_cast<unsigned>(index + start_index) != (index + start_index) ||
      static_cast<unsigned>(index + end_index) != (index + end_index)) {
    return TokenRange();
  } else {
    return TokenRange(impl, static_cast<unsigned>(index + start_index),
                      static_cast<unsigned>(index + end_index));
  }
}

// Returns the index of `that` in this range, or `std::nullopt`.
std::optional<unsigned> TokenRange::index_of(const Token &that) const noexcept {
  if (!impl || !impl->Equals(that.impl.get())) {
    return std::nullopt;
  }

  VariantId vid = EntityId(that.id()).Unpack();
  if (std::holds_alternative<ParsedTokenId>(vid)) {
    auto id = std::get<ParsedTokenId>(vid);
    if (id.offset < index) {
      return std::nullopt;
    }

    if (id.offset >= num_tokens) {
      return std::nullopt;
    }

    return id.offset - index;

  } else if (std::holds_alternative<FileTokenId>(vid)) {
    auto id = std::get<FileTokenId>(vid);
    if (id.offset < index) {
      return std::nullopt;
    }

    if (id.offset >= num_tokens) {
      return std::nullopt;
    }

    return id.offset - index;

  } else {
    return std::nullopt;
  }
}

// Return the underlying token data associated with the tokens covered by this
// token range.
std::string_view TokenRange::data(void) const & {
  if (!impl || impl.get() == kInvalidTokenReader.get() || !num_tokens) {
    return {};
  }

  auto data_begin = impl->NthTokenData(index);
  auto data_end = impl->NthTokenData(num_tokens - 1u);
  auto size = static_cast<size_t>(data_end.data() - data_begin.data()) +
              data_end.size();

  if (static_cast<uint32_t>(size) != size) {
    assert(false);
    return {};
  }

  return std::string_view(data_begin.data(), size);
}

// Convert this token range into a file token range.
TokenRange TokenRange::file_tokens(void) const noexcept {
  TokenRange ret;
  if (!impl || impl.get() == kInvalidTokenReader.get() || !num_tokens) {
    return ret;
  }

  // It's already a file token range.
  if (dynamic_cast<const PackedFileImpl *>(impl.get())) {
    return *this;
  }

  RawEntityId file_id = kInvalidEntityId;

  // Find the nearest file token for the first token.
  for (auto i = 0u; i <= index; ++i) {
    EntityId eid(impl->NthFileTokenId(index - i));
    VariantId vid = eid.Unpack();
    if (std::holds_alternative<FileTokenId>(vid)) {
      FileTokenId fid = std::get<FileTokenId>(vid);
      if (auto fr = impl->ReaderForToken(impl, eid)) {
        ret.impl = std::move(fr);
        ret.index = fid.offset;
        file_id = fid.file_id;
        break;
      }
    }
  }

  if (file_id == kInvalidEntityId) {
    return ret;
  }

  // Hope for an exact match with the last token in the range.
  if (auto last_fid = impl->NthFileTokenId(num_tokens - 1u);
      last_fid != kInvalidEntityId) {
    VariantId vid = EntityId(last_fid).Unpack();
    if (std::holds_alternative<FileTokenId>(vid)) {
      FileTokenId fid = std::get<FileTokenId>(vid);
      if (fid.file_id == file_id) {
        ret.num_tokens = fid.offset + 1u;
        return ret;
      }
    }
  }

  // Try to find the file token for one-past-the-end of this token range, then
  // we'll take the file token from before that. Failing that, we'll need to
  // match up on the exact token, then mark the num tokens as that token's
  // offset plus one.
  auto offset_shift = 0u;
  for (auto i = 0u; i <= num_tokens; ++i) {
    VariantId vid = EntityId(impl->NthFileTokenId(num_tokens - i)).Unpack();
    if (std::holds_alternative<FileTokenId>(vid)) {
      FileTokenId fid = std::get<FileTokenId>(vid);
      if (fid.file_id == file_id) {
        ret.num_tokens = fid.offset + offset_shift;
        return ret;
      }
    }
    offset_shift = 1u;
  }

  // Worst case, the range of the only token :-/
  ret.num_tokens = ret.index + 1u;
  return ret;
}

// Strip leading and trailing whitespace.
TokenRange TokenRange::strip_whitespace(void) const noexcept {
  TokenRange ret(*this);
  for (; ret.index < ret.num_tokens; ++ret.index) {
    const TokenKind kind = impl->NthTokenKind(ret.index);
    if (kind == TokenKind::WHITESPACE) {
      continue;
    } else if (kind == TokenKind::UNKNOWN &&
               impl->NthTokenData(ret.index).empty()) {
      continue;
    } else {
      break;
    }
  }

  for (; ret.num_tokens > ret.index; --ret.num_tokens) {
    const TokenKind kind = impl->NthTokenKind(ret.num_tokens - 1u);
    if (kind == TokenKind::WHITESPACE) {
      continue;
    } else if (kind == TokenKind::UNKNOWN &&
               impl->NthTokenData(ret.num_tokens - 1u).empty()) {
      continue;
    } else {
      break;
    }
  }

  if (ret.num_tokens <= ret.index) {
    ret.num_tokens = 0;
    ret.index = 0;
  }

  return ret;
}

}  // namespace mx
