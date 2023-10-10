// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/AST.capnp.h>
#include <multiplier/Entities/Type.h>

#include "Entity.h"
#include "Token.h"
#include "TokenContext.h"

namespace mx {

class TypeImpl;

class ReadTypeTokens final : public TokenReader {
 public:
  TypeImpl * const type;

  inline ReadTypeTokens(TypeImpl *type_)
      : type(type_) {}

  virtual ~ReadTypeTokens(void) = default;

  // Return the number of tokens in the fragment.
  EntityOffset NumTokens(void) const final;

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(EntityOffset index) const final;

  // Return the data of the Nth token.
  std::string_view NthTokenData(EntityOffset index) const final;

  // Return the id of the token from which the Nth token is derived.
  EntityId NthDerivedTokenId(EntityOffset token_index) const final;

  // Return the id of the parsed token which is derived from the Nth token.
  EntityId NthParsedTokenId(EntityOffset token_index) const final;

  // Return the id of the macro containing the Nth token.
  EntityId NthContainingMacroId(EntityOffset) const final;

  // Return an entity id associated with the Nth token.
  EntityId NthRelatedEntityId(EntityOffset) const final;

  // Return the entity associated with the Nth token.
  VariantEntity NthRelatedEntity(EntityOffset) const final;

  // Return the id of the Nth token.
  EntityId NthTokenId(EntityOffset token_index) const final;
  EntityId NthFileTokenId(EntityOffset token_index) const final;

  // Returns `true` if `this` is logically equivalent to `that`.
  bool Equals(const class TokenReader *that) const final;

  const TypeImpl *OwningType(void) const noexcept final;

};

// Interface for accessing type.
class TypeImpl {
 private:
  friend class ReadTypeTokens;
  friend class TokenReader;

  using FragmentReader = typename rpc::Type::Reader;
  using TypeReader  = typename ast::Type::Reader;

  // Stores the Cap'n-Proto serialized data.;
  const kj::Array<capnp::word> data;
  capnp::FlatArrayMessageReader message;

  // Type token reader
  const ReadTypeTokens type_token_reader;
  const TypeTokenContextReader token_context_reader;
 public:
  // Needed for us to be able to look up entities related to other types
  // or fragments.
  const std::shared_ptr<EntityProvider> ep;

  // The reader used to read type tokens and serialized types
  const FragmentReader frag_reader;
  const TypeReader reader;

  const PackedTypeId type_id;
  unsigned num_type_tokens;

  explicit TypeImpl(std::shared_ptr<EntityProvider> ep_,
                    kj::Array<capnp::word> data_,
                    RawEntityId id_);

  virtual ~TypeImpl(void) = default;

  TokenReader::Ptr
  TypeTokenReader(const TypeImplPtr &) const;

  TokenContextReader::Ptr
  TokenContextReader(const TokenImplPtr &) const;

  std::string_view Data(void) const & noexcept;

  // Return the token associated with a specific entity ID.
  std::optional<Token> TokenFor(const TypeImplPtr &, EntityId id,
                                bool can_fail=false) const;

  // Return the inclusive token range associated with two entity IDs.
  TokenRange TokenRangeFor(const TypeImplPtr &, EntityId begin_id,
                           EntityId end_id) const;

  SpecificEntityId<TypeTokenId> BeginToken(void) const;
  SpecificEntityId<TypeTokenId> EndToken(void) const;

};

}  // namespace mx
