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
  virtual EntityOffset NumTokens(void) const = 0;

  // Return the kind of the Nth token.
  virtual TokenKind NthTokenKind(EntityOffset token_index) const = 0;

  // Return the data of the Nth token.
  virtual std::string_view NthTokenData(EntityOffset token_index) const = 0;

  // Return the id of the token from which the Nth token is derived.
  virtual EntityId NthDerivedTokenId(EntityOffset token_index) const = 0;

  // Return the id of the parsed token which is derived from the Nth token.
  virtual EntityId NthParsedTokenId(EntityOffset token_index) const = 0;

  // Return the id of the macro containing the Nth token.
  virtual EntityId NthContainingMacroId(EntityOffset token_index) const = 0;

  // Return an entity id associated with the Nth token.
  virtual EntityId NthRelatedEntityId(EntityOffset token_index) const = 0;

  // Return the id of the Nth token.
  virtual EntityId NthTokenId(EntityOffset token_index) const = 0;

  // Return the file id of the Nth token, if any. If this is a file token reader
  // then this is equivalent to `NthTokenId(token_index)`, i.e. the file token
  // is self-referencing. However, if this is a parsed token reader, then this
  // is the file token associated with the file token, if any.
  virtual EntityId NthFileTokenId(EntityOffset token_index) const = 0;

  // Return the token reader for another token. Returns a null reader on
  // failure.
  virtual Ptr ReaderForToken(const Ptr &self, RawEntityId id) const = 0;

  // Returns `true` if `this` is logically equivalent to `that`.
  virtual bool Equals(const TokenReader *that) const = 0;

  // Returns `true` if `this` is logically equivalent to `that`.
  inline bool Equals(const std::shared_ptr<const TokenReader> &that) const {
    return Equals(that.get());
  }

  static Ptr ReaderForToken(const Ptr &self, const EntityProvider::Ptr &ep,
                            EntityId eid);

  virtual const FragmentImpl *OwningFragment(void) const noexcept;
  virtual const FileImpl *OwningFile(void) const noexcept;

  static Token TokenFor(const Ptr &self, RawEntityId eid) noexcept;
};

// Used for invalid tokens.
class InvalidTokenReader final : public TokenReader {
 public:
  virtual ~InvalidTokenReader(void) noexcept;

  // Return the number of tokens accessible to this reader.
  EntityOffset NumTokens(void) const override;

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(EntityOffset) const override;

  // Return the data of the Nth token.
  std::string_view NthTokenData(EntityOffset) const override;

  // Return the id of the token from which the Nth token is derived.
  EntityId NthDerivedTokenId(EntityOffset) const override;

  // Return the id of the parsed token which is derived from the Nth token.
  EntityId NthParsedTokenId(EntityOffset) const override;

  // Return the id of the macro containing the Nth token.
  EntityId NthContainingMacroId(EntityOffset) const override;

  // Return an entity id associated with the Nth token.
  EntityId NthRelatedEntityId(EntityOffset) const override;

  // Return the id of the Nth token.
  EntityId NthTokenId(EntityOffset) const override;
  EntityId NthFileTokenId(EntityOffset) const override;

  // Return the token reader for another file.
  Ptr ReaderForToken(const Ptr &self, RawEntityId id) const override;
  
  // Returns `true` if `this` is logically equivalent to `that`.
  bool Equals(const TokenReader *) const override;
};

}  // namespace mx
