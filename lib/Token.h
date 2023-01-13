// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "API.h"

namespace mx {

class FragmentImpl;
class FileImpl;

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

  // Return the id of the token from which the Nth token is derived.
  virtual EntityId NthDerivedTokenId(unsigned token_index) const = 0;

  // Return the id of the parsed token which is derived from the Nth token.
  virtual EntityId NthParsedTokenId(unsigned token_index) const = 0;

  // Return the id of the macro containing the Nth token.
  virtual EntityId NthContainingMacroId(unsigned token_index) const = 0;

  // Return an entity id associated with the Nth token.
  virtual EntityId NthRelatedEntityId(unsigned token_index) const = 0;

  // Return the id of the Nth token.
  virtual EntityId NthTokenId(unsigned token_index) const = 0;

  // Return the file id of the Nth token, if any. If this is a file token reader
  // then this is equivalent to `NthTokenId(token_index)`, i.e. the file token
  // is self-referencing. However, if this is a parsed token reader, then this
  // is the file token associated with the file token, if any.
  virtual EntityId NthFileTokenId(unsigned token_index) const = 0;

  // Return the token reader for another token. Returns a null reader on
  // failure.
  virtual Ptr ReaderForToken(const Ptr &self, RawEntityId id) const = 0;

  // Returns `true` if `this` is logically equivalent to `that`.
  virtual bool Equals(const TokenReader *that) const = 0;

  static Ptr ReaderForToken(const Ptr &self, const EntityProvider::Ptr &ep,
                            EntityId eid);

  virtual const FragmentImpl *OwningFragment(void) const noexcept;
  virtual const FileImpl *OwningFile(void) const noexcept;
};

// Used for invalid tokens.
class InvalidTokenReader final : public TokenReader {
 public:
  virtual ~InvalidTokenReader(void) noexcept;

  // Return the number of tokens accessible to this reader.
  unsigned NumTokens(void) const override;

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(unsigned) const override;

  // Return the data of the Nth token.
  std::string_view NthTokenData(unsigned) const override;

  // Return the id of the token from which the Nth token is derived.
  EntityId NthDerivedTokenId(unsigned) const override;

  // Return the id of the parsed token which is derived from the Nth token.
  EntityId NthParsedTokenId(unsigned) const override;

  // Return the id of the macro containing the Nth token.
  EntityId NthContainingMacroId(unsigned) const override;

  // Return an entity id associated with the Nth token.
  EntityId NthRelatedEntityId(unsigned) const override;

  // Return the id of the Nth token.
  EntityId NthTokenId(unsigned) const override;
  EntityId NthFileTokenId(unsigned) const override;

  // Return the token reader for another file.
  Ptr ReaderForToken(const Ptr &self, RawEntityId id) const override;
  
  // Returns `true` if `this` is logically equivalent to `that`.
  bool Equals(const TokenReader *) const override;
};

}  // namespace mx
