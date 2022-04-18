// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "API.h"

namespace mx {

class TokenReader {
 public:
  using Ptr = std::shared_ptr<const TokenReader>;

  virtual ~TokenReader(void) noexcept;

  // Return the number of tokens accessible to this reader.
  virtual unsigned NumTokens(void) const = 0;

  // Return the kind of the Nth token.
  virtual TokenKind NthTokenKind(unsigned token_index) const = 0;

  // Return the data of the Nth token.
  virtual std::string_view NthTokenData(unsigned token_index) const = 0;

  // Return the id of the Nth token.
  virtual EntityId NthTokenId(unsigned token_index) const = 0;

  // Return the file id of the Nth token, if any. If this is a file token reader
  // then this is equivalent to `NthTokenId(token_index)`, i.e. the file token
  // is self-referencing. However, if this is a parsed token reader, then this
  // is the file token associated with the file token, if any.
  virtual EntityId NthFileTokenId(unsigned token_index) const = 0;

  // Return the token reader for another file.
  virtual Ptr ReaderForFile(const Ptr &self, mx::FileId id) const = 0;
};

struct BeforeTag {};
struct AfterTag {};

class TokenSubstitutionListImpl {
 public:
  const std::shared_ptr<const FragmentImpl> fragment;
  const NodeReader nodes;

  TokenSubstitutionListImpl(std::shared_ptr<const FragmentImpl> fragment_);

  TokenSubstitutionListImpl(std::shared_ptr<const FragmentImpl> fragment_,
                            unsigned offset, BeforeTag);

  TokenSubstitutionListImpl(std::shared_ptr<const FragmentImpl> fragment_,
                            unsigned offset, AfterTag);
};

// Used for invalid tokens.
class InvalidTokenReader final : public TokenReader {
 public:
  virtual ~InvalidTokenReader(void) noexcept;

  // Return the number of tokens accessible to this reader.
  unsigned NumTokens(void) const final;

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(unsigned) const final;

  // Return the data of the Nth token.
  std::string_view NthTokenData(unsigned) const final;

  // Return the id of the Nth token.
  EntityId NthTokenId(unsigned token_index) const final;
  EntityId NthFileTokenId(unsigned token_index) const final;

  // Return the token reader for another file.
  Ptr ReaderForFile(const Ptr &self, mx::FileId id) const final;
};

}  // namespace mx
