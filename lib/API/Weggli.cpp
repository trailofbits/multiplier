// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Weggli.h"

#include <cassert>

#include "Fragment.h"
#include "multiplier/Types.h"

namespace mx {

WeggliQueryResultImpl::~WeggliQueryResultImpl(void) noexcept {}

WeggliQueryResultImpl::WeggliQueryResultImpl(
    const WeggliQuery &query_, EntityProvider::Ptr ep_,
    std::vector<RawEntityId> fragment_ids)
    : query(query_),
      ep(std::move(ep_)),
      fragments(std::move(fragment_ids)) {}

WeggliQueryResultImpl::WeggliQueryResultImpl(const WeggliQuery &query_,
                                             FragmentImpl::Ptr frag_)
    : query(query_),
      ep(frag_->ep) {

  fragments.push_back(frag_->fragment_id);
  (void) InitForFragment(std::move(frag_));
}

bool WeggliQueryResultImpl::InitForFragment(FragmentImpl::Ptr frag_) {
  frag = std::move(frag_);
  next_weggli_match = 0u;
  weggli_matches.clear();
  offset_to_index.clear();
  frag_file_tokens = Fragment(frag).file_tokens();
  query.ForEachMatch(
      frag_file_tokens.data(),
      [this] (WeggliMatchData match) {
        weggli_matches.emplace_back(std::move(match));
        return true;
      });

  if (weggli_matches.empty()) {
    frag.reset();
    return false;
  }

  // Create a mapping of just-after-end-of-token offset to token index, so
  // that we can use `upper_bound` to find the token containing a matched
  // offset.
  unsigned offset = 0u;
  unsigned index = 0u;
  for (const Token &tok : frag_file_tokens) {
    offset += tok.data().size();
    offset_to_index.emplace(offset, index++);
  }

  assert(!offset_to_index.empty());
  return true;
}

gap::generator<WeggliQueryMatch>
WeggliQueryResultImpl::enumerate(void) {
  unsigned index = 0;
  unsigned num_fragments = fragments.size();
  while (index < num_fragments) {

    // Reset the caches of data in the fragment, and the mapping of offsets
    // to token ids.
    if (!frag) {
      auto frag = ep->FragmentFor(ep, fragments[index]);
      if (!frag) {
        ++index;
        continue;
      }

      if (!InitForFragment(std::move(frag))) {
        ++index;
        continue;
      }
    }

    auto match_index = next_weggli_match++;
    if (match_index >= weggli_matches.size()) {
      frag.reset();
      ++index;  // Skip to next fragment.
      continue;
    }

    WeggliMatchData &match = weggli_matches[match_index];

    auto frag_data = frag_file_tokens.data();

    assert(match.begin_offset <= match.end_offset);
    assert(match.end_offset <= frag_data.size());

    auto offset_to_index_end = offset_to_index.end();
    auto begin_token_index_it =
        offset_to_index.upper_bound(match.begin_offset);
    auto end_token_index_it =
        offset_to_index.upper_bound(match.end_offset - 1u);

    // This shouldn't be possible, the match should always fall inside of the
    // buffer.
    if (begin_token_index_it == offset_to_index_end ||
        end_token_index_it == offset_to_index_end) {
      assert(false);
      co_return;
    }

    assert(begin_token_index_it->second <= end_token_index_it->second);

    TokenRange range = frag_file_tokens.slice(
        begin_token_index_it->second, end_token_index_it->second + 1u);

    std::string_view match_data = frag_data.substr(
        match.begin_offset, match.end_offset - match.begin_offset + 1);

    std::vector<TokenRange> matched_tokens;
    std::vector<std::string_view> matched_data;

    for (WeggliMatchData::MatchRange sub_match : match.matches) {
      assert(sub_match.first <= sub_match.second);
      matched_data.emplace_back(frag_data.substr(
          sub_match.first,
          sub_match.second - sub_match.first));

      begin_token_index_it = offset_to_index.upper_bound(
          sub_match.first);
      end_token_index_it = offset_to_index.upper_bound(
          sub_match.second - 1u);

      // This shouldn't be possible, the match should always fall inside of the
      // buffer.
      if (begin_token_index_it == offset_to_index_end ||
          end_token_index_it == offset_to_index_end) {
        assert(false);
        co_return;
      }

      matched_tokens.emplace_back(frag_file_tokens.slice(
          begin_token_index_it->second, end_token_index_it->second + 1u));
    }

    co_yield WeggliQueryMatch(frag, std::move(range.impl), range.index,
                              range.num_tokens,
                              std::move(match_data),
                              std::move(match.variables),
                              std::move(matched_data),
                              std::move(matched_tokens));
  }
}

WeggliQueryMatch::WeggliQueryMatch(
    std::shared_ptr<const FragmentImpl> frag_,
    std::shared_ptr<const TokenReader> impl_,
    unsigned index_, unsigned num_tokens_,
    std::string_view match_data_,
    std::vector<std::string> variables_,
    std::vector<std::string_view> matched_data_,
    std::vector<TokenRange> matched_tokens_)
    : TokenRange(std::move(impl_), index_, num_tokens_),
      frag(std::move(frag_)),
      match_data(std::move(match_data_)),
      variables(std::move(variables_)),
      matched_data(std::move(matched_data_)),
      matched_tokens(std::move(matched_tokens_)) {}

std::optional<TokenRange> WeggliQueryMatch::captured_tokens(
    const std::string &var) const {
  if (auto index = index_of_captured_variable(var)) {
    return matched_tokens[index.value() - 1u];
  }
  return std::nullopt;
}

// Return the captured tokens for a given indexed capture group.
std::optional<TokenRange> WeggliQueryMatch::captured_tokens(
    size_t capture_index) const {
  if (!capture_index) {
    return *this;
  } else if (auto real_index = capture_index - 1u;
             real_index < matched_tokens.size()) {
    return matched_tokens[real_index];
  } else {
    return std::nullopt;
  }
}

// Return the captured data for a given named capture group.
std::optional<std::string_view> WeggliQueryMatch::captured_data(
    const std::string &var) const {
  if (auto index = index_of_captured_variable(var)) {
    return matched_data[index.value() - 1u];
  }
  return std::nullopt;
}

// Return the captured data for a given indexed capture group.
std::optional<std::string_view> WeggliQueryMatch::captured_data(
    size_t capture_index) const {
  if (!capture_index) {
    return match_data;
  } else if (auto real_index = capture_index - 1u;
             real_index < matched_data.size()) {
    return matched_data[real_index];
  } else {
    return std::nullopt;
  }
}

// Return the index of a captured variable.
std::optional<size_t> WeggliQueryMatch::index_of_captured_variable(
    const std::string &var) const {
  size_t i = 1u;  // Index `0` is reserved for the whole capture.
  for (const auto &matched_var : variables) {
    if (matched_var == var) {
      return i;
    }
    ++i;
  }
  return std::nullopt;
}

}  // namespace mx
