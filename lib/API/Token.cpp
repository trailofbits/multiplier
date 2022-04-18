// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Token.h"
#include "File.h"
#include "Fragment.h"

namespace mx {
namespace {

static const std::shared_ptr<InvalidTokenReader> kInvalidTokenReader =
    std::make_shared<InvalidTokenReader>();

}  // namespace

TokenReader::~TokenReader(void) noexcept {}
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

// Return the id of the Nth token.
EntityId InvalidTokenReader::NthTokenId(unsigned) const {
  return kInvalidEntityId;
}

EntityId InvalidTokenReader::NthFileTokenId(unsigned token_index) const {
  return kInvalidEntityId;
}

// Return the token reader for another file.
TokenReader::Ptr InvalidTokenReader::ReaderForFile(
    const Ptr &self, mx::FileId id) const {
  return {};
}

Token::Token(void)
    : impl(kInvalidTokenReader),
      index(0) {}

// Return `true` if this is a valid token.
Token::operator bool(void) const {
  return !dynamic_cast<const InvalidTokenReader *>(impl.get());
}

// Kind of this token.
TokenKind Token::kind(void) const {
  return impl->NthTokenKind(index);
}

// Return the data of this token.
std::string_view Token::data(void) const {
  return impl->NthTokenData(index);
}

// Return the ID of this token.
EntityId Token::id(void) const {
  return impl->NthTokenId(index);
}

// Return the version of this token from a file, if any.
std::optional<Token> Token::file_token(void) const {
  VariantId vid = EntityId(impl->NthFileTokenId(index)).Unpack();
  if (!std::holds_alternative<FileTokenId>(vid)) {
    return std::nullopt;
  }

  FileTokenId fid = std::get<FileTokenId>(vid);
  auto fr = impl->ReaderForFile(impl, fid.file_id);
  if (!fr) {
    return std::nullopt;
  }

  return Token(std::move(fr), fid.offset);
}

// Return the list of parsed tokens in the fragment. This doesn't
// include all tokens, i.e. macro use tokens, comments, etc.
TokenList Token::in(const Fragment &frag) {
  auto tokens = frag.impl->TokenReader(frag.impl);
  auto num_tokens = tokens->NumTokens();
  return TokenList(std::move(tokens), num_tokens);
}

// Return the list of tokens in this file.
TokenList Token::in(const File &file) {
  auto tokens = file.impl->TokenReader(file.impl);
  auto num_tokens = tokens->NumTokens();
  return TokenList(std::move(tokens), num_tokens);
}

// Return the token list containing a particular token.
TokenList TokenList::containing(Token tok) {
  if (tok) {
    auto num_tokens = tok.impl->NumTokens();
    return TokenList(std::move(tok.impl), num_tokens);
  } else {
    return TokenList();
  }
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
    : index(0),
      num_tokens(0) {}

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

// Return the underlying token data associated with the tokens covered by this
// token range.
std::string_view TokenRange::data(void) const {
  if (!impl || impl.get() == kInvalidTokenReader.get() || !num_tokens) {
    return {};
  }

  auto data_begin = impl->NthTokenData(index);
  auto data_end = impl->NthTokenData(index + num_tokens - 1u);
  auto size = static_cast<size_t>(data_end.data() - data_begin.data()) +
              data_end.size();

  if (static_cast<uint32_t>(size) != size) {
    assert(false);
    return {};
  }

  return std::string_view(data_begin.data(), size);
}

}  // namespace mx
