// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Weggli.h"

#include "Fragment.h"

namespace mx {

WeggliQueryResultImpl::~WeggliQueryResultImpl(void) noexcept {}

WeggliQueryResultImpl::WeggliQueryResultImpl(
    std::string syntax_, EntityProvider::Ptr ep_, Response response,
    bool is_cpp)
    : syntax(std::move(syntax_)),
      ep(std::move(ep_)),
      query(syntax, is_cpp) {
  for (auto frag_id : response.getFragments()) {
    fragments.emplace_back().first = frag_id;
  }
}

FragmentImpl::Ptr WeggliQueryResultImpl::GetFragmentAtIndex(unsigned index) const {
  auto &entry = fragments[index];
  auto frag = entry.second.lock();
  if (!frag) {
    frag = ep->FragmentFor(ep, entry.first);
    entry.second = frag;
  }
  return frag;
}

EntityId WeggliQueryResultImpl::EntityContainingOffset(unsigned offset) const {
  auto it = offset_to_token.upper_bound(offset);
  if (it != offset_to_token.end()) {
    return it->second;
  } else {
    return kInvalidEntityId;
  }
}

void WeggliQueryResultImpl::GetUnparsedTokens(TokenSubstitutionList nodes) const {
  for (auto node : nodes) {
    if (std::holds_alternative<Token>(node)) {
      auto tok = std::get<Token>(node);
      auto tok_data = tok.data();

      // Skip empty tokens and whitespace.
      if (tok_data.empty() || tok.kind() == TokenKind::WHITESPACE) {
        continue;
      }

      fragment_buffer.insert(fragment_buffer.end(),
                             tok_data.begin(), tok_data.end());
      offset_to_token.emplace(
          static_cast<unsigned>(fragment_buffer.size()),
          tok.id());
      fragment_buffer.push_back(' ');

    } else {
      auto sub = std::get<mx::TokenSubstitution>(node);
      GetUnparsedTokens(sub.before());
    }
  }
}

WeggliQueryMatch::WeggliQueryMatch(
    std::shared_ptr<const FragmentImpl> frag_,
    std::shared_ptr<const TokenReader> impl_,
    unsigned index_, unsigned num_tokens_,
    std::unordered_map<std::string, TokenRange> var_matches_)
    : TokenRange(std::move(impl_), index_, num_tokens_),
      frag(std::move(frag_)),
      var_matches(std::move(var_matches_)) {}

std::optional<TokenRange> WeggliQueryMatch::variable_capture(const std::string &var) const {
  auto it = var_matches.find(var);
  if (it != var_matches.end()) {
    return it->second;
  } else {
    return std::nullopt;
  }
}

// Return a list of matched variables.
std::vector<std::string> WeggliQueryMatch::captured_variables(void) const {
  std::vector<std::string> ret;
  for (const auto &[var, _] : var_matches) {
    ret.emplace_back(var);
  }
  return ret;
}

WeggliQueryResult::WeggliQueryResult(
    std::shared_ptr<const WeggliQueryResultImpl> impl_)
    : impl(std::move(impl_)),
      num_fragments(impl->fragments.size()) {}

// Try to advance to the next result. There can be multiple results per
// fragment.
void WeggliQueryResultIterator::Advance(void) {
  while (index < num_fragments) {
      auto frag = impl->GetFragmentAtIndex(index);
      if (!frag) {
        ++index;
        continue;
      }

      // Reset the caches of data in the fragment, and the mapping of offsets
      // to token ids.
      if (impl->fragment_buffer_id != frag->id) {
        impl->next_weggli_match = 0u;
        impl->weggli_matches.clear();
        impl->fragment_buffer.clear();
        impl->fragment_buffer_id = frag->id;
        impl->GetUnparsedTokens(Fragment(frag).substitutions());

        impl->query.ForEachMatch(
            impl->fragment_buffer,
            [impl = impl.get()] (const WeggliMatchData &match) {
          impl->weggli_matches.emplace_back(match);
          return true;
        });
      }

      auto match_index = impl->next_weggli_match++;
      if (match_index >= impl->weggli_matches.size()) {
        ++index;  // Skip to next fragment.
        continue;
      }

      const WeggliMatchData &match = impl->weggli_matches[match_index];

      TokenRange range = frag->TokenRangeFor(
          frag,
          impl->EntityContainingOffset(match.begin_offset),
          impl->EntityContainingOffset(match.end_offset));

      std::unordered_map<std::string, TokenRange> var_matches;
      for (const auto &[var, range] : match.variables) {
        var_matches.emplace(
            var,
            frag->TokenRangeFor(
                frag,
                impl->EntityContainingOffset(range.first),
                impl->EntityContainingOffset(range.second)));
      }

      result.reset();
      result.emplace(frag, std::move(range.impl), range.index,
                     range.num_tokens, std::move(var_matches));
      return;
    }
}

}  // namespace mx
