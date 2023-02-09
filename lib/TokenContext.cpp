// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Fragment.h"

#include <cassert>
#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/Designator.h>
#include <multiplier/Entities/Type.h>

#include "Types.h"

namespace mx {


std::optional<TokenContext> TokenContext::of(const Token &tok) {
  return tok.context();
}

// Return the context node that identifies how this token relates to the AST.
//
// NOTE(pag): This only works with parsed tokens, and not all parsed tokens
//            are guaranteed to have a context.
std::optional<TokenContext> Token::context(void) const {
  if (!impl) {
    return std::nullopt;
  }

  const FragmentImpl *frag = impl->OwningFragment();
  if (!frag) {
    return std::nullopt;
  }

  // Only parsed tokens have token contexts.
  if (offset >= frag->num_parsed_tokens) {
    return std::nullopt;
  }

  // Make sure this is indeed a parsed token.
  if (!std::holds_alternative<ParsedTokenId>(id().Unpack())) {
    return std::nullopt;
  }

  const auto &frag_reader = frag->reader;
  unsigned tagged_offset = frag_reader.getParsedTokenContextOffsets()[offset];
  if (!(tagged_offset & 1u)) {
    assert(!tagged_offset);
    return std::nullopt;
  }

  unsigned untagged_offset = tagged_offset >> 1u;
  auto contexts_reader = frag_reader.getParsedTokenContexts();
  if (untagged_offset >= contexts_reader.size()) {
    assert(false);
    return std::nullopt;
  }

  mx::rpc::TokenContext::Reader tc = contexts_reader[untagged_offset];
  std::shared_ptr<const FragmentImpl> frag_ptr(impl, frag);

  // NOTE(pag): +1 to skip `kInvalid`.
  TokenContext ret(std::move(frag_ptr));
  ret.entity_id = tc.getEntityId();
  ret.offset = untagged_offset;

  assert(ret.entity_id != kInvalidEntityId);

  if (auto parent_index = tc.getParentIndex()) {
    ret.parent_offset = parent_index >> 1u;
  }

  if (auto alias_index = tc.getAliasIndex()) {
    ret.alias_offset = alias_index >> 1u;
  }

  return ret;
}

#define MX_DEFINE_GETTER(type_name, lower_name, enum_name, category) \
    std::optional<type_name> TokenContext::as_ ## lower_name(void) const { \
      if (impl && CategoryFromEntityId(entity_id) == EntityCategory::enum_name) { \
        if (auto ptr = impl->ep->type_name ## For(impl->ep, entity_id)) { \
          return type_name(std::move(ptr)); \
        } \
      } \
      return std::nullopt; \
    }

MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DEFINE_GETTER,
                            MX_DEFINE_GETTER)
#undef MX_DEFINE_GETTER

// Return the aliased context.
std::optional<TokenContext> TokenContext::aliasee(void) const {
  if (!impl || !alias_offset.has_value()) {
    return std::nullopt;

  } else {
    auto tc = impl->reader.getParsedTokenContexts()[alias_offset.value()];
    (void) tc;
    TokenContext ret(impl);
    assert(entity_id == tc.getEntityId());
    assert(!tc.getAliasIndex());
    ret.entity_id = entity_id;
    ret.offset = alias_offset.value();
    assert(ret.offset != offset);
    return ret;
  }
}

// Return the parent context.
std::optional<TokenContext> TokenContext::parent(void) const {
  if (!impl || !parent_offset.has_value()) {
    return std::nullopt;
  }

  auto tc = impl->reader.getParsedTokenContexts()[parent_offset.value()];

  // NOTE(pag): `+1` to skip `kInvalid`.
  TokenContext ret(impl);
  ret.entity_id = tc.getEntityId();
  ret.offset = parent_offset.value();

  assert(ret.offset != offset);
  assert(ret.entity_id != kInvalidEntityId);

  if (auto parent_index = tc.getParentIndex()) {
    ret.parent_offset = parent_index >> 1u;
  }

  if (auto alias_index = tc.getAliasIndex()) {
    ret.alias_offset = alias_index >> 1u;
  }

  return ret;
}

}  // namespace mx
