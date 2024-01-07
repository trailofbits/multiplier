// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "EntityProvider.h"

#include <multiplier/Frontend/DefineMacroDirective.h>
#include <multiplier/Frontend/MacroExpansion.h>
#include <multiplier/Frontend/MacroParameterSubstitution.h>
#include <multiplier/Frontend/MacroSubstitution.h>
#include <multiplier/Frontend/MacroVAOpt.h>

namespace mx {

class FragmentImpl;
class FileImpl;

using TokenContextReaderPtr = std::shared_ptr<const TokenContextReader>;
using TokenReaderPtr = std::shared_ptr<const TokenReader>;

class TokenReader {
 public:
  using Ptr = TokenReaderPtr;

  virtual ~TokenReader(void) noexcept;

  // Return the number of tokens accessible to this reader.
  virtual EntityOffset NumTokens(void) const = 0;

  // Return the kind of the Nth token.
  virtual TokenKind NthTokenKind(EntityOffset token_index) const = 0;

  // Return the kind of the Nth token.
  virtual TokenCategory NthTokenCategory(EntityOffset token_index) const;

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

  // Return the entity associated with the Nth token.
  virtual VariantEntity NthRelatedEntity(EntityOffset token_index) const = 0;

  // Return the id of the Nth token.
  virtual EntityId NthTokenId(EntityOffset token_index) const = 0;

  // Return the file id of the Nth token, if any. If this is a file token reader
  // then this is equivalent to `NthTokenId(token_index)`, i.e. the file token
  // is self-referencing. However, if this is a parsed token reader, then this
  // is the file token associated with the file token, if any.
  virtual EntityId NthFileTokenId(EntityOffset token_index) const = 0;

  // Returns `true` if `this` is logically equivalent to `that`.
  virtual bool Equals(const TokenReader *that) const = 0;

  // Returns `true` if `this` is logically equivalent to `that`.
  inline bool Equals(const std::shared_ptr<const TokenReader> &that) const {
    return Equals(that.get());
  }

  static EntityProviderPtr EntityProviderFor(const Token &);

  static Ptr ReaderForToken(const Ptr &self, const EntityProviderPtr &ep,
                            EntityId eid);

  virtual const FragmentImpl *NthOwningFragment(EntityOffset) const noexcept;
  virtual const FileImpl *NthOwningFile(EntityOffset) const noexcept;
  virtual const TypeImpl *NthOwningType(EntityOffset) const noexcept;

  // The contract of `Owning*` and `NthOwning*` is that if these methods return
  // a raw pointer of the thing, then the shared pointer managing `this`
  // (i.e. this `TokenReader` instance) can be aliased to the return value, and
  // will match the lifetime of the returned pointer.
  virtual const FragmentImpl *OwningFragment(void) const noexcept;
  virtual const FileImpl *OwningFile(void) const noexcept;
  virtual const TypeImpl *OwningType(void) const noexcept;

  virtual TokenContextReaderPtr TokenContextReaderFor(
      const Ptr &self, EntityOffset offset, EntityId eid) const noexcept;

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

  // Return the entity associated with the Nth token.
  VariantEntity NthRelatedEntity(EntityOffset token_index) const override;

  // Return the id of the Nth token.
  EntityId NthTokenId(EntityOffset) const override;
  EntityId NthFileTokenId(EntityOffset) const override;

  // Returns `true` if `this` is logically equivalent to `that`.
  bool Equals(const TokenReader *) const override;
};

// Used to proxy another token reader.
class ProxyTokenReader : public TokenReader {
 protected:
  Ptr next;

 public:
  /* implicit */ inline ProxyTokenReader(Ptr next_)
      : next(std::move(next_)) {}

  virtual ~ProxyTokenReader(void) noexcept;

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

  // Return the entity associated with the Nth token.
  VariantEntity NthRelatedEntity(EntityOffset token_index) const override;

  // Return the id of the Nth token.
  EntityId NthTokenId(EntityOffset) const override;
  EntityId NthFileTokenId(EntityOffset) const override;

  // Returns `true` if `this` is logically equivalent to `that`.
  bool Equals(const TokenReader *) const override;

  const FragmentImpl *NthOwningFragment(EntityOffset) const noexcept override;
  const FileImpl *NthOwningFile(EntityOffset) const noexcept override;
  const TypeImpl *NthOwningType(EntityOffset) const noexcept override;

  const FragmentImpl *OwningFragment(void) const noexcept override;
  const FileImpl *OwningFile(void) const noexcept override;
  const TypeImpl *OwningType(void) const noexcept override;

  TokenContextReaderPtr TokenContextReaderFor(
      const Ptr &self, EntityOffset offset, EntityId eid) const noexcept override;
};

// Used for custom token ranges.
class CustomTokenReader final : public TokenReader {
 public:
  const std::shared_ptr<const FragmentImpl> fragment;  // Optional.

  std::string data;
  std::vector<EntityOffset> data_offset;
  std::vector<RawEntityId> derived_token_ids;
  std::vector<RawEntityId> parsed_token_ids;
  std::vector<RawEntityId> containing_macro_ids;
  std::vector<VariantEntity> related_entities;
  std::vector<RawEntityId> token_ids;
  std::vector<RawEntityId> file_token_ids;
  std::vector<TokenKind> token_kinds;
  std::vector<TokenCategory> token_categories;

  CustomTokenReader(FragmentImplPtr fragment_);

  virtual ~CustomTokenReader(void) noexcept;

  // Append a token into this reader.
  void Append(TokenImplPtr reader, EntityOffset offset) noexcept;

  // Append a simple token into this reader.
  void Append(UserToken stok) noexcept;

  // Return the number of tokens accessible to this reader.
  EntityOffset NumTokens(void) const override;

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(EntityOffset) const override;

  // Return the category of the Nth token.
  TokenCategory NthTokenCategory(EntityOffset) const override;

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

  // Return the entity associated with the Nth token.
  VariantEntity NthRelatedEntity(EntityOffset token_index) const override;

  // Return the id of the Nth token.
  EntityId NthTokenId(EntityOffset) const override;
  EntityId NthFileTokenId(EntityOffset) const override;

  // Returns `true` if `this` is logically equivalent to `that`.
  bool Equals(const TokenReader *) const override;

  // TODO(pag): Add NthOwningFragment and NthOwningFile?

  const FragmentImpl *OwningFragment(void) const noexcept override;
};

}  // namespace mx
