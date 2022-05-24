// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Fragment.h"

#include <cassert>

namespace mx {

// Return the token context associated with a token.
//
// NOTE(pag): This only works with parsed tokens, and not all parsed tokens
//            are guaranteed to have a context.
std::optional<TokenContext> TokenContext::of(const Token &tok) {
  if (!tok.impl) {
    return std::nullopt;
  }

  auto frag = dynamic_cast<const PackedFragmentImpl *>(tok.impl.get());
  if (!frag) {
    return std::nullopt;
  }

  FragmentReader frag_reader = frag->Fragment();
  unsigned offset = frag_reader.getTokenContextOffsets()[tok.offset];
  mx::rpc::TokenContext::Reader tc = frag_reader.getTokenContexts()[offset];
  std::shared_ptr<const FragmentImpl> frag_ptr(tok.impl, frag);

  // NOTE(pag): +1 to skip `kInvalid`.
  TokenContext ret(std::move(frag_ptr));
  ret.entity_id = tc.getEntityId();
  ret.offset = offset;

  assert(ret.entity_id != kInvalidEntityId);

  if (auto parent_index = tc.getParentIndex()) {
    ret.parent_offset = parent_index >> 1u;
  }

  if (auto alias_index = tc.getAliasIndex()) {
    ret.alias_offset = alias_index >> 1u;
  }

  return ret;
}

std::optional<Decl> TokenContext::as_declaration(void) const {
  EntityId id(entity_id);
  if (impl && std::holds_alternative<DeclarationId>(id.Unpack())) {
    return impl->DeclFor(impl, id);
  } else {
    return std::nullopt;
  }
}

std::optional<Stmt> TokenContext::as_statement(void) const {
  EntityId id(entity_id);
  if (impl && std::holds_alternative<StatementId>(id.Unpack())) {
    return impl->StmtFor(impl, id);
  } else {
    return std::nullopt;
  }
}

std::optional<Type> TokenContext::as_type(void) const {
  EntityId id(entity_id);
  if (impl && std::holds_alternative<TypeId>(id.Unpack())) {
    return impl->TypeFor(impl, id);
  } else {
    return std::nullopt;
  }
}

// Return the aliased context.
std::optional<TokenContext> TokenContext::aliasee(void) const {
  if (!impl || !alias_offset.has_value()) {
    return std::nullopt;

  } else {
    auto tc = impl->Fragment().getTokenContexts()[alias_offset.value()];
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

  auto tc = impl->Fragment().getTokenContexts()[parent_offset.value()];

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
