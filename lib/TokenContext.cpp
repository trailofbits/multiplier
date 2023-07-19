// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "TokenContext.h"
#include "Fragment.h"

#include <cassert>
#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/Designator.h>
#include <multiplier/Entities/Type.h>

#include "Type.h"
#include "Types.h"

namespace mx {

#define MX_DEFINE_GETTER(type_name, lower_name, enum_name, category) \
    std::optional<type_name> FragmentTokenContextReader::as_ ## lower_name(RawEntityId entity_id) const { \
      if (impl && CategoryFromEntityId(entity_id) == EntityCategory::enum_name) { \
        if (auto ptr = impl->ep->type_name ## For(impl->ep, entity_id)) { \
          return type_name(std::move(ptr)); \
        } \
        assert(false); \
      } \
      return std::nullopt; \
    }

MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DEFINE_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DEFINE_GETTER,
                            MX_DEFINE_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY)
#undef MX_DEFINE_GETTER

std::optional<TokenContextReader::Reader>
FragmentTokenContextReader::TokenContexts(EntityOffset offset) const {
  auto contexts_reader = impl->reader.getParsedTokenContexts();
  if (offset >= contexts_reader.size()) {
    assert(false);
    return std::nullopt;
  }
  return contexts_reader[offset];
}

std::optional<unsigned>
FragmentTokenContextReader::TokenContextOffsets(EntityOffset offset) const {
  unsigned tagged_offset = impl->reader.getParsedTokenContextOffsets()[offset];
  if (!(tagged_offset & 1u)) {
    assert(!tagged_offset);
    return std::nullopt;
  }
  return tagged_offset;
}

#define MX_DEFINE_GETTER(type_name, lower_name, enum_name, category) \
    std::optional<type_name> TypeTokenContextReader::as_ ## lower_name(RawEntityId entity_id) const { \
      if (impl && CategoryFromEntityId(entity_id) == EntityCategory::enum_name) { \
        if (auto ptr = impl->ep->type_name ## For(impl->ep, entity_id)) { \
         return type_name(std::move(ptr)); \
        } \
        assert(false); \
      } \
      return std::nullopt; \
    }

MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DEFINE_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DEFINE_GETTER,
                            MX_DEFINE_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY)
#undef MX_DEFINE_GETTER

std::optional<TokenContextReader::Reader>
TypeTokenContextReader::TokenContexts(EntityOffset offset) const {
  auto contexts_reader = impl->frag_reader.getTypeTokenContexts();
  if (offset >= contexts_reader.size()) {
    assert(false);
    return std::nullopt;
  }
  return contexts_reader[offset];
}

std::optional<unsigned>
TypeTokenContextReader::TokenContextOffsets(EntityOffset offset) const {
  unsigned tagged_offset = impl->frag_reader.getTypeTokenContextOffsets()[offset];
  if (!(tagged_offset & 1u)) {
    assert(!tagged_offset);
    return std::nullopt;
  }
  return tagged_offset;
}

std::optional<TokenContext> TokenContext::of(const Token &tok) {
  return tok.context();
}

// Return the context node that identifies how this token relates to the AST.
//
// NOTE(pag): This works parsed and type tokens, and not all tokens
//            are guaranteed to have a context.
std::optional<TokenContext> Token::context(void) const {
  if (!impl) {
    return std::nullopt;
  }

  TokenContextReaderPtr reader =
      impl->TokenContextReaderFor(impl, offset, id());
  if (!reader) {
    return std::nullopt;
  }

  std::optional<unsigned> tagged_offset = reader->TokenContextOffsets(offset);
  if (!tagged_offset.has_value()) {
    assert(false);
    return std::nullopt;
  }

  unsigned untagged_offset = tagged_offset.value() >> 1u;
  auto tc = reader->TokenContexts(untagged_offset);
  if (!tc.has_value()) {
    assert(false);
    return std::nullopt;
  }

  // NOTE(pag): +1 to skip `kInvalid`.
  TokenContext ret(std::move(reader));
  ret.entity_id = tc->getEntityId();
  ret.offset = untagged_offset;

  assert(ret.entity_id != kInvalidEntityId);

  if (auto parent_index = tc->getParentIndex()) {
    ret.parent_offset = parent_index >> 1u;
  }

  if (auto alias_index = tc->getAliasIndex()) {
    ret.alias_offset = alias_index >> 1u;
  }

  return ret;
}

#define MX_DEFINE_GETTER(type_name, lower_name, enum_name, category) \
    std::optional<type_name> TokenContext::as_ ## lower_name(void) const { \
      if (reader && CategoryFromEntityId(entity_id) == EntityCategory::enum_name) { \
        return reader->as_ ## lower_name(entity_id); \
      } \
      return std::nullopt; \
    }

MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DEFINE_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DEFINE_GETTER,
                            MX_DEFINE_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY)
#undef MX_DEFINE_GETTER

// Return the aliased context.
std::optional<TokenContext> TokenContext::aliasee(void) const {
  if (!reader || !alias_offset.has_value()) {
    return std::nullopt;
  }

  auto tc = reader->TokenContexts(parent_offset.value());
  if (!tc.has_value()) {
    assert(false);
    return std::nullopt;
  }

  TokenContext ret(reader);
  assert(entity_id == tc->getEntityId());
  assert(!tc->getAliasIndex());
  ret.entity_id = entity_id;
  ret.offset = alias_offset.value();
  assert(ret.offset != offset);
  return ret;
}

// Return the parent context.
std::optional<TokenContext> TokenContext::parent(void) const {
  if (!reader || !parent_offset.has_value()) {
    return std::nullopt;
  }

  auto tc = reader->TokenContexts(parent_offset.value());
  if (!tc.has_value()) {
    assert(false);
    return std::nullopt;
  }

  // NOTE(pag): `+1` to skip `kInvalid`.
  TokenContext ret(reader);
  ret.entity_id = tc->getEntityId();
  ret.offset = parent_offset.value();

  assert(ret.offset != offset);
  assert(ret.entity_id != kInvalidEntityId);

  if (auto parent_index = tc->getParentIndex()) {
    ret.parent_offset = parent_index >> 1u;
  }

  if (auto alias_index = tc->getAliasIndex()) {
    ret.alias_offset = alias_index >> 1u;
  }

  return ret;
}

}  // namespace mx
