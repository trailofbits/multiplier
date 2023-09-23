// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Type.h"

#include <multiplier/Index.h>

#include "Fragment.h"
#include "Reference.h"
#include "Types.h"

namespace mx {

// Return the number of tokens in the fragment.
EntityOffset ReadTypeTokens::NumTokens(void) const {
  return type->num_type_tokens;
}

// Return the kind of the Nth token.
TokenKind ReadTypeTokens::NthTokenKind(EntityOffset to) const {
  if (to >= type->num_type_tokens) {
    return TokenKind::UNKNOWN;
  }
  return static_cast<TokenKind>(type->frag_reader.getTokenKinds()[to]);
}

// Return the data of the Nth token.
std::string_view ReadTypeTokens::NthTokenData(EntityOffset to) const {
  if (to >= type->num_type_tokens) {
    return {};
  }

  const auto &reader = type->frag_reader;
  auto tor = reader.getTokenOffsets();
  auto bo = tor[to];
  auto eo = tor[to + 1u];
  return std::string_view(&(reader.getTokenData().cStr()[bo]), (eo - bo));
}

EntityId ReadTypeTokens::NthDerivedTokenId(EntityOffset) const {
  return {};
}

// Return the id of the parsed token which is derived from the Nth token.
EntityId ReadTypeTokens::NthParsedTokenId(EntityOffset) const {
  return {};
}

// Return the id of the macro containing the Nth token.
EntityId ReadTypeTokens::NthContainingMacroId(EntityOffset) const {
  return {};
}

// Return an entity id associated with the Nth token id
EntityId ReadTypeTokens::NthRelatedEntityId(EntityOffset to) const {
  if (to >= type->num_type_tokens) {
    return kInvalidEntityId;
  }

  return type->frag_reader.getRelatedEntityId()[to];
}

// Return the entity associated with the Nth token entity
VariantEntity ReadTypeTokens::NthRelatedEntity(EntityOffset to) const {
  return Index(type->ep).entity(NthRelatedEntityId(to));
}

// Return the id of the Nth token.
EntityId ReadTypeTokens::NthTokenId(EntityOffset to) const {
  if (to >= type->num_type_tokens) {
    return kInvalidEntityId;
  }

  TypeTokenId id;
  id.type_id = type->type_id.Unpack().type_id;
  id.type_kind = type->type_id.Unpack().kind;
  id.kind = static_cast<TokenKind>(type->frag_reader.getTokenKinds()[to]);
  id.offset = to;
  return id;
}

EntityId ReadTypeTokens::NthFileTokenId(EntityOffset) const {
  return {};
}

// Returns `true` if `this` is logically equivalent to `that`.
bool ReadTypeTokens::Equals(const class TokenReader *that_) const {
  if (!dynamic_cast<const ReadTypeTokens *>(that_)) {
    return false;
  } else if (this == that_) {
    return true;
  }

  auto that = that_->OwningType();
  if (type == that) {
    return true;
  }

  if (!that || that->type_id != type->type_id ||
      that->ep.get() != type->ep.get()) {
    return false;
  }

  return true;
}

const TypeImpl *ReadTypeTokens::OwningType(void) const noexcept {
  return type;
}

TypeImpl::TypeImpl(std::shared_ptr<EntityProvider> ep_,
                   kj::Array<capnp::word> data_,
                   RawEntityId id_)
    : data(kj::mv(data_)), message(data, kOptions),
      type_token_reader(this),
      token_context_reader(this),
      ep(std::move(ep_)),
      frag_reader(message.getRoot<rpc::Type>()),
      reader(frag_reader.getType()),
      type_id(TypeIdFromEntityId(id_).value()),
      num_type_tokens(frag_reader.getTypeTokenContextOffsets().size()) {

  assert((num_type_tokens + 1u) == frag_reader.getTokenOffsets().size());
  assert(num_type_tokens == frag_reader.getTokenKinds().size());
  assert(num_type_tokens == frag_reader.getRelatedEntityId().size());
  assert(num_type_tokens == frag_reader.getTypeTokenContextOffsets().size());
}

// Return a reader for the type tokens associated with the type
TokenReader::Ptr TypeImpl::TypeTokenReader(const TypeImplPtr &self) const {
  return TokenReader::Ptr(self, &type_token_reader);
}

TokenContextReader::Ptr
TypeImpl::TokenContextReader(const TokenImplPtr &ptr) const {
  return TokenContextReader::Ptr(ptr, &token_context_reader);
}

std::string_view TypeImpl::Data(void) const & noexcept {
  if (frag_reader.hasTokenData()) {
    if (auto toks = frag_reader.getTokenData(); auto size = toks.size()) {
      return std::string_view(toks.cStr(), size);
    }
  }
  return {};
}

// Return the token associated with a specific entity ID.
std::optional<Token> TypeImpl::TokenFor(
    const TypeImplPtr &self, EntityId eid, bool can_fail) const {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeTokenId>(vid)) {
    const TypeTokenId ttid = std::get<TypeTokenId>(vid);
    TypeId tid(ttid);

    // It's a token inside of the current type.
    if (tid.type_id == self->type_id.Unpack().type_id) {
      Token tok(self->TypeTokenReader(self), ttid.offset);
      if (tok.id() == eid) {
        return tok;
      } else {
        assert(false);
      }

      // It's a token inside of another type, go get the other type.
    } else if (TypeImplPtr other_type = ep->TypeFor(ep, tid)) {
      return other_type->TokenFor(other_type, eid, can_fail);
    }
  }

  if (can_fail) {
    return Token();
  }

  return std::nullopt;
}

// Return the inclusive token range associated with two entity IDs.
TokenRange TypeImpl::TokenRangeFor(
    const TypeImplPtr &self, EntityId begin_id, EntityId end_id) const {
  VariantId bvid = begin_id.Unpack();
  VariantId evid = end_id.Unpack();

  if (std::holds_alternative<TypeTokenId>(bvid)) {
    if (!std::holds_alternative<TypeTokenId>(evid)) {
      return TokenRange();
    }

    auto btid = std::get<TypeTokenId>(bvid);
    auto etid = std::get<TypeTokenId>(evid);
    if (btid.type_id != etid.type_id || btid.offset > etid.offset) {
      return TokenRange();
    }

    TypeId tid(btid);

    // It's a token inside of the current type.
    if (btid.type_id == self->type_id.Unpack().type_id) {
      if (etid.offset < num_type_tokens) {
        return TokenRange(self->TypeTokenReader(self), btid.offset, etid.offset + 1u);
      }
      // if the token does not belong to another type
    } else if (TypeImplPtr other_type =  ep->TypeFor(ep, tid)) {
      return other_type->TokenRangeFor(other_type, begin_id, end_id);
    }
  }

  return TokenRange();
}

SpecificEntityId<TypeTokenId> TypeImpl::BeginToken(void) const {
  TypeTokenId id;
  id.type_id = type_id.Unpack().type_id;
  id.type_kind = type_id.Unpack().kind;
  id.kind = static_cast<TokenKind>(frag_reader.getTokenKinds()[0]);
  id.offset = static_cast<EntityOffset>(0);
  return id;
}

SpecificEntityId<TypeTokenId> TypeImpl::EndToken(void) const {
  TypeTokenId id;
  id.type_id = type_id.Unpack().type_id;
  id.type_kind = type_id.Unpack().kind;
  id.kind = static_cast<TokenKind>(frag_reader.getTokenKinds()[num_type_tokens - 1]);
  id.offset = static_cast<EntityOffset>(num_type_tokens - 1);
  return id;
}

SpecificEntityId<TypeId> Type::id(void) const {
  auto type_id = impl->type_id.Unpack().type_id;
  return TypeId(type_id, kind());
}

// References to this type.
gap::generator<Reference> Type::references(void) const & {
  const EntityProviderPtr &ep = impl->ep;
  for (auto [ref_id, ref_kind] : ep->References(ep, id().Pack())) {
    if (auto [eptr, category] = ReferencedEntity(ep, ref_id); eptr) {
      co_yield Reference(std::move(eptr), ref_id, category, ref_kind);
    }
  }
}

// TokenRange for the type
TokenRange Type::tokens(void) const {
  return impl->TokenRangeFor(impl, impl->BeginToken(), impl->EndToken());
}

}  // namespace mx
