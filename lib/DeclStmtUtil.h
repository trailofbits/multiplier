// Copyright (c) 2024-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <iostream>

#include <multiplier/Entity.h>
#include <multiplier/Frontend/MacroSubstitution.h>
#include <multiplier/Frontend/Token.h>
#include <tuple>

#include "Fragment.h"
#include "Token.h"
#include "multiplier/Types.h"

namespace mx {

namespace {

template <typename T>
static gap::generator<T> EntityOverlapping(const mx::TokenRange tokens) {
  auto begin = tokens.front().id().Extract<ParsedTokenId>();
  auto end = tokens.back().id().Extract<ParsedTokenId>();
  // if begin and end token have invalid fragment id. It is possible if MacroSubstitution
  // substitute to empty data
  if (!begin->fragment_id || !end->fragment_id) {
    co_return;
  }

  // Verify if the fragment id is same and offset are in order
  if ((begin->fragment_id != end->fragment_id) || (begin->offset > end->offset)) {
    assert(false);
    co_return;
  }

  auto frag_tokens = Fragment::containing(tokens.front())->parsed_tokens();
  if (frag_tokens.empty()) {
    assert(false);
    co_return;
  }

  std::vector<RawEntityId> seen;
  for (auto i = begin->offset; i <= end->offset; ++i) {
    Token expansion_tok = frag_tokens[i];
    for (auto context = expansion_tok.context(); 
         context; context = context->parent()) {

      auto variant = context->as_variant();
      if (!std::holds_alternative<T>(variant)) {
        continue;
      }

      auto eid = context->entity_id();
      if (std::find(seen.begin(), seen.end(), eid) != seen.end()) {
        break;
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

template <typename T>
static std::optional<T> EntityCovering(const TokenRange &tokens) {
  // Get the overlapping entities and check if both first and last token fall
  // in the declaration/statments token range
  for (auto entity : EntityOverlapping<T>(tokens)) {
    if (!entity.tokens().index_of(tokens.front()) || !entity.tokens().index_of(tokens.back())) {
      continue;
    }
    return entity;
  }
  return std::nullopt;
}

}  // namespace

} // namespace mx