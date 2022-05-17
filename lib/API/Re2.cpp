// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Re2.h"

#include <cassert>

#include "File.h"
#include "Fragment.h"

#include "../Re2.h"

namespace mx {

RegexQueryResultImpl::~RegexQueryResultImpl(void) noexcept {}

RegexQueryResultImpl::RegexQueryResultImpl(
    const RegexQuery &query_, EntityProvider::Ptr ep_, Response response)
    : query(query_),
      ep(std::move(ep_)) {

  auto fragment_ids_reader = response.getFragments();
  fragment_ids.reserve(fragment_ids_reader.size());

  for (mx::FragmentId frag_id : fragment_ids_reader) {
    fragment_ids.emplace_back(frag_id);
  }
}

EntityId RegexQueryResultImpl::EntityContainingOffset(unsigned offset) const {
  auto it = offset_to_index.upper_bound(offset);
  if (it != offset_to_index.end()) {
    return it->second;
  } else {
    return kInvalidEntityId;
  }
}

bool RegexQueryResultImpl::InitForFragment(mx::FragmentId frag_id) {
  frag = ep->FragmentFor(ep, frag_id);
  if (!frag) {
    return false;
  }

  Fragment hl_frag(frag);

  matches.clear();
  offset_to_index.clear();
  next_match_index = 0u;
  frag_file_tokens = hl_frag.file_tokens();
  offset_to_index.clear();

  // Do the regex search on fragments token first.
  query.ForEachMatch(
      frag_file_tokens.data(),
      [this] (std::string_view match, unsigned begin, unsigned end) {
    matches.emplace_back(match, begin, end);
    return true;
  });

  if (matches.empty()) {
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

std::optional<RegexQueryMatch>
RegexQueryResultImpl::GetNextMatchInFragment(void) {
  // Get the next match result.
  const unsigned match_index = next_match_index++;
  if (match_index >= matches.size()) {
    frag.reset();
    return std::nullopt;
  }

  // NOTE(pag): `match` covers `[begin_offset, end_offset)` of the file token
  //            buffer produced by `impl->frag_file_tokens.data()`.
  auto [match, begin_offset, end_offset] = matches[match_index];
  assert(begin_offset < end_offset);

  auto begin_token_index_it = offset_to_index.upper_bound(begin_offset);
  auto end_token_index_it = offset_to_index.upper_bound(end_offset - 1u);

  // This shouldn't be possible, the match should always fall inside of the
  // buffer.
  if (begin_token_index_it == offset_to_index.end() ||
      end_token_index_it == offset_to_index.end()) {
    assert(false);
    frag.reset();
    return std::nullopt;
  }

  return RegexQueryMatch(
      frag_file_tokens.slice(begin_token_index_it->second,
                             end_token_index_it->second + 1u),
      match, frag, query);
}

void RegexQueryResultIterator::Advance(void) {
  while (index < num_matches) {

    // We don't yet have any matches for `index`, so go compute them.
    if (!impl->frag) {
      if (!impl->InitForFragment(impl->fragment_ids[index])) {
        ++index;
        continue;
      }
    }

    result = impl->GetNextMatchInFragment();
    if (result) {
      return;
    }

    ++index;
  }
}

RegexQueryMatch::~RegexQueryMatch(void) {}

RegexQueryMatch::RegexQueryMatch(TokenRange range_,
                                 std::string_view data_range,
                                 std::shared_ptr<const FragmentImpl> frag_,
                                 const RegexQuery &query_)
    : TokenRange(std::move(range_)),
      frag(std::move(frag_)),
      query(query_.impl) {

  int num_captures = query->re.NumberOfCapturingGroups();
  assert(1 <= num_captures);

  matched_ranges.reserve(static_cast<unsigned>(num_captures));
  matched_ranges.push_back(data_range);

  std::vector<re2::StringPiece> parts;
  parts.resize(static_cast<unsigned>(num_captures) + 2u);
  auto ret = query->re.Match(data_range, 0, data_range.size(),
                             re2::RE2::Anchor::UNANCHORED,
                             &(parts[0]), num_captures + 1);
  if (ret) {
    // `0` is the whole range, which we've already added.
    // `1` is to skip over the `(` and `)` that our Re2 wrapper applies.
    for (auto i = 2; i <= num_captures; ++i) {
      auto part = parts[static_cast<unsigned>(i)];
      auto x = matched_ranges.size();
      if (!part.data()) {
        matched_ranges.emplace_back();
      } else {
        matched_ranges.emplace_back(part.data(), part.size());
      }
    }
  }
}

// Translate a data capture into a token range catpure.
std::optional<TokenRange> RegexQueryMatch::TranslateCapture(
    std::string_view capture) const {

  auto begin_ptr = capture.data();
  auto end_ptr = &(begin_ptr[capture.size()]);

#ifndef NDEBUG
  auto data_range = matched_ranges[0];
  auto data_begin_ptr = data_range.data();
  auto data_end_ptr = &(data_begin_ptr[data_range.size()]);
  assert(begin_ptr >= data_begin_ptr);
  assert(begin_ptr < data_end_ptr);
  assert(end_ptr >= data_begin_ptr);
  assert(end_ptr <= data_end_ptr);
#endif

  std::optional<unsigned> begin_index;
  std::optional<unsigned> end_index;

  for (size_t i = 0u, max_i = size(); i < max_i; ++i) {
    Token tok = (*this)[i];
    std::string_view tok_data = tok.data();
    auto tok_begin = tok_data.data();
    auto tok_end = &(tok_begin[tok_data.size()]);
    if (tok_begin <= begin_ptr && begin_ptr < tok_end) {
      begin_index = i;
      end_index = i;
    }
    if (tok_begin < end_ptr && end_ptr <= tok_end) {
      end_index = i;
      break;
    }
  }

  if (begin_index && end_index) {
    return slice(*begin_index, *end_index + 1u);
  }

  return std::nullopt;
}

// Return the captured tokens for a given named capture group.
std::optional<TokenRange> RegexQueryMatch::captured_tokens(
    const std::string &var) const {
  std::optional<std::string_view> maybe_data = captured_data(var);
  if (!maybe_data) {
    return std::nullopt;
  } else {
    return TranslateCapture(*maybe_data);
  }
}

// Return the captured data for a given named capture group.
std::optional<std::string_view> RegexQueryMatch::captured_data(
    const std::string &var) const {

  const auto &named_captures = query->re.NamedCapturingGroups();
  auto index_it = named_captures.find(var);
  if (index_it == named_captures.end()) {
    return std::nullopt;
  } else {
    return captured_data(static_cast<unsigned>(index_it->second));
  }
}

// Return the captured tokens for a given indexed capture group.
std::optional<TokenRange> RegexQueryMatch::captured_tokens(
    size_t index) const {
  std::optional<std::string_view> maybe_data = captured_data(index);
  if (!maybe_data) {
    return std::nullopt;
  } else {
    return TranslateCapture(*maybe_data);
  }
}

// Return the captured data for a given indexed capture group.
std::optional<std::string_view> RegexQueryMatch::captured_data(
    size_t capture_index) const {
  if (capture_index < matched_ranges.size()) {
    if (auto ret = matched_ranges[capture_index]; ret.data()) {
      return ret;
    }
  }
  return std::nullopt;
}

// Return the number of capture groups.
size_t RegexQueryMatch::num_captures(void) const {
  return matched_ranges.size();
}

// Return a list of matched variables.
std::vector<std::string> RegexQueryMatch::captured_variables(void) const {
  std::vector<std::string> ret;
  for (const auto &[name, capture_index] : query->re.NamedCapturingGroups()) {
    ret.emplace_back(name);
  }
  return ret;
}


RegexQueryResult::RegexQueryResult(std::shared_ptr<RegexQueryResultImpl> impl_)
    : impl(std::move(impl_)),
      num_fragments(impl->fragment_ids.size()) {}

}  // namespace mx
