// Copyright (c) 2024-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Entity.h>
#include <multiplier/Frontend/MacroSubstitution.h>
#include <multiplier/Frontend/Token.h>

#include "Fragment.h"
#include "Token.h"
#include "multiplier/Types.h"

namespace mx {

namespace {

template <typename T>
VariantEntity get_entity_as_variant(std::optional<TokenContext> ctx);

template <>
VariantEntity get_entity_as_variant<Decl>(std::optional<TokenContext> ctx) {
  auto maybe_entity = ctx->as_declaration();
  if (maybe_entity) {
    return std::move(maybe_entity.value());
  }
  return NotAnEntity{};
}

template <>
VariantEntity get_entity_as_variant<Stmt>(std::optional<TokenContext> ctx) {
  auto maybe_entity = ctx->as_statement();
  if (maybe_entity) {
    return std::move(maybe_entity.value());
  }
  return NotAnEntity{};
}

template <typename T>
static gap::generator<T> EntityOverlapping(mx::MacroSubstitution sub) {
  auto first = sub.first_fully_substituted_token().parsed_token();
  auto last = sub.last_fully_substituted_token().parsed_token();
  if (!first || !last) {
    co_return;
  }

  auto begin = first.id().Extract<ParsedTokenId>();
  auto end = last.id().Extract<ParsedTokenId>();
  if ((begin->fragment_id != end->fragment_id) ||
      (begin->offset > end->offset)) {
    assert(false);
    co_return;
  }

  auto frag_tokens = Fragment::containing(first)->parsed_tokens();
  if (!frag_tokens) {
    assert(false);
    co_return;
  }
  std::vector<RawEntityId> seen;

  for (auto i = begin->offset; i <= end->offset; ++i) {
    Token expansion_tok = frag_tokens[i];
    for (auto context = expansion_tok.context(); 
            context; context = context->parent()) {

      auto variant = get_entity_as_variant<T>(context);
      if (!std::holds_alternative<T>(variant)) {
        continue;
      }

      auto eid = context->entity_id();
      if (std::find(seen.begin(), seen.end(), eid) != seen.end()) {
        continue;
      }

      seen.push_back(eid);

      T entity = std::move(std::get<T>(variant));
      if (!entity.tokens().index_of(expansion_tok)) {
        break;
      }

      co_yield std::move(entity);
    }
  }
}

}  // namespace

} // namespace mx