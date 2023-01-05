// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "WeggliImpl.h"

#include <cassert>
#include <multiplier/Types.h>

#include "File.h"
#include "Fragment.h"

namespace mx {

WeggliQueryResultImpl::~WeggliQueryResultImpl(void) noexcept {}

WeggliQueryResultImpl::WeggliQueryResultImpl(
    const WeggliQuery &query_, EntityProvider::Ptr ep_,
    FragmentIdList fragment_ids)
    : query(query_),
      ep(std::move(ep_)),
      fragments(std::move(fragment_ids)) {}

WeggliQueryResultImpl::WeggliQueryResultImpl(const WeggliQuery &query_,
                                             FragmentImpl::Ptr frag_)
    : query(query_),
      ep(frag_->ep) {

  FragmentId fid(frag_->fragment_id);
  fragments.push_back(fid);
  (void) InitForFragment(std::move(frag_));
}

bool WeggliQueryResultImpl::InitForFragment(FragmentImpl::Ptr frag_) {
  frag = std::move(frag_);
  next_weggli_match = 0u;
  weggli_matches.clear();
  offset_to_index.clear();
  frag_file_tokens = Fragment(frag).file_tokens();
  query.for_each_match(
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

WeggliQueryResult::WeggliQueryResult(
    std::shared_ptr<WeggliQueryResultImpl> impl_)
    : impl(std::move(impl_)),
      num_fragments(impl ? impl->fragments.size() : 0ul) {}

// Try to advance to the next result. There can be multiple results per
// fragment.
void WeggliQueryResultIterator::Advance(void) {
  result.reset();
  while (index < num_fragments) {

    // Reset the caches of data in the fragment, and the mapping of offsets
    // to token ids.
    if (!impl->frag) {
      auto frag = impl->ep->FragmentFor(impl->ep, impl->fragments[index]);
      if (!frag) {
        ++index;
        continue;
      }

      if (!impl->InitForFragment(std::move(frag))) {
        ++index;
        continue;
      }
    }

    auto match_index = impl->next_weggli_match++;
    if (match_index >= impl->weggli_matches.size()) {
      impl->frag.reset();
      ++index;  // Skip to next fragment.
      continue;
    }

    WeggliMatchData &match = impl->weggli_matches[match_index];

    auto frag_data = impl->frag_file_tokens.data();

    assert(match.begin_offset <= match.end_offset);
    assert(match.end_offset <= frag_data.size());

    auto offset_to_index_end = impl->offset_to_index.end();
    auto begin_token_index_it =
        impl->offset_to_index.upper_bound(match.begin_offset);
    auto end_token_index_it =
        impl->offset_to_index.upper_bound(match.end_offset - 1u);

    // This shouldn't be possible, the match should always fall inside of the
    // buffer.
    if (begin_token_index_it == offset_to_index_end ||
        end_token_index_it == offset_to_index_end) {
      assert(false);
      return;
    }

    assert(begin_token_index_it->second <= end_token_index_it->second);

    TokenRange range = impl->frag_file_tokens.slice(
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

      begin_token_index_it = impl->offset_to_index.upper_bound(
          sub_match.first);
      end_token_index_it = impl->offset_to_index.upper_bound(
          sub_match.second - 1u);

      // This shouldn't be possible, the match should always fall inside of the
      // buffer.
      if (begin_token_index_it == offset_to_index_end ||
          end_token_index_it == offset_to_index_end) {
        assert(false);
        return;
      }

      matched_tokens.emplace_back(impl->frag_file_tokens.slice(
          begin_token_index_it->second, end_token_index_it->second + 1u));
    }

    result.emplace(impl->frag, std::move(range.impl), range.index,
                   range.num_tokens,
                   std::move(match_data),
                   std::move(match.variables),
                   std::move(matched_data),
                   std::move(matched_tokens));
    return;
  }
}

#ifndef MX_DISABLE_WEGGLI

// Match this Weggli query against a file.
WeggliQueryResult WeggliQuery::match_fragments(const File &file) const {
  auto &reader = file.impl->Reader();

  std::map<unsigned, unsigned> eol_offset_to_line_num;
  for (mx::rpc::UpperBound::Reader ubr : reader.getEolOffsets()) {
    eol_offset_to_line_num.emplace(ubr.getOffset(), ubr.getVal());
  }

  std::vector<unsigned> line_nums;

  this->for_each_match(
      file.data(),
      [&eol_offset_to_line_num, &line_nums]
      (WeggliMatchData match) -> bool {
        unsigned prev_line = 0;
        for (auto i = match.begin_offset; i < match.end_offset; ++i) {
          auto line_it = eol_offset_to_line_num.upper_bound(i);
          if (line_it != eol_offset_to_line_num.end()) {
            auto line = line_it->second;
            if (line != prev_line) {
              prev_line = line;
              line_nums.push_back(line);
            }
          }
        }
        return true;
      });

  if (line_nums.empty()) {
    return {};
  }

  const EntityProvider::Ptr &ep = file.impl->ep;
  return std::make_shared<WeggliQueryResultImpl>(
      *this, ep,
      ep->FragmentsCoveringLines(ep, file.id(), std::move(line_nums)));
}

// Match this Weggli query against a fragment.
WeggliQueryResult WeggliQuery::match_fragments(const Fragment &frag) const {
  return std::make_shared<WeggliQueryResultImpl>(*this, frag.impl);
}

#else

WeggliQueryResult WeggliQuery::match_fragments(const File &) const {
  return {};
}

WeggliQueryResult WeggliQuery::match_fragments(const Fragment &) const {
  return {};
}

#endif  // MX_DISABLE_WEGGLI

}  // namespace mx
