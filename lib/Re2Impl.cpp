// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Re2Impl.h"

#include <algorithm>
#include <cassert>
#include <multiplier/Index.h>
#include <multiplier/Types.h>

#include "File.h"
#include "Fragment.h"
#include "Token.h"
#include "Util.h"

#ifndef MX_DISABLE_RE2

namespace mx {

RegexQueryResultImpl::~RegexQueryResultImpl(void) noexcept {}

RegexQueryResultImpl::RegexQueryResultImpl(
    const RegexQuery &query_, EntityProvider::Ptr ep_,
    FragmentIdList fragment_ids_)
    : query(query_),
      ep(std::move(ep_)),
      fragment_ids(std::move(fragment_ids_)) {}

RegexQueryResultImpl::RegexQueryResultImpl(
    const RegexQuery &query_, FragmentImplPtr frag_)
    : query(query_),
      ep(frag_->ep) {
  FragmentId fid(frag_->fragment_id);
  fragment_ids.push_back(fid);
  (void) InitForFragment(std::move(frag_));
}

bool RegexQueryResultImpl::InitForFragment(FragmentImplPtr frag_) {
  frag = std::move(frag_);
  Fragment hl_frag(frag);

  matches.clear();
  offset_to_index.clear();
  next_match_index = 0u;
  frag_file_tokens = hl_frag.file_tokens();

  // Do the regex search on fragments token first.
  query.for_each_match(
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
    offset += static_cast<unsigned>(tok.data().size());
    offset_to_index.emplace(offset, index++);
  }

  assert(!offset_to_index.empty());

  return true;
}

bool RegexQueryResultImpl::InitForFragment(PackedFragmentId frag_id) {
  return InitForFragment(ep->FragmentFor(ep, frag_id.Pack()));
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

  assert(begin_token_index_it->second <= end_token_index_it->second);

  return RegexQueryMatch(
      frag_file_tokens.slice(begin_token_index_it->second,
                             end_token_index_it->second + 1u),
      match, frag, query);
}

RegexQueryMatch::~RegexQueryMatch(void) {}

RegexQueryMatch::RegexQueryMatch(TokenRange range_ /* file token range */,
                                 std::string_view data_range /* file data */,
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
                             re2::RE2::Anchor::ANCHOR_BOTH,
                             &(parts[0]), num_captures + 1);
  if (ret) {
    // `0` is the whole range, which we've already added.
    // `1` is to skip over the `(` and `)` that our Re2 wrapper applies.
    for (auto i = 2; i <= num_captures; ++i) {
      auto part = parts[static_cast<unsigned>(i)];
      if (!part.data()) {
        matched_ranges.emplace_back();
      } else {
        matched_ranges.emplace_back(part.data(), part.size());
      }
    }
  }
}

// Translate a data capture into a token range capture.
std::optional<TokenRange> RegexQueryMatch::TranslateCapture(
    std::string_view capture) const {

  auto begin_ptr = capture.data();
  auto end_ptr = &(begin_ptr[capture.size()]);

#ifndef NDEBUG
  auto data_range = matched_ranges[0];
  auto data_begin_ptr = data_range.data();
  auto data_end_ptr = &(data_begin_ptr[data_range.size()]);
  assert(begin_ptr >= data_begin_ptr);
  assert(begin_ptr <= data_end_ptr);  // Empty capture.
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

// Return the index of a capture variable.
std::optional<size_t> RegexQueryMatch::index_of_captured_variable(
    const std::string &var) const {

  const auto &named_captures = query->re.NamedCapturingGroups();
  auto index_it = named_captures.find(var);
  if (index_it == named_captures.end()) {
    return std::nullopt;
  } else {
    return static_cast<unsigned>(index_it->second);
  }
}

// Return the captured tokens for a given named capture group.
std::optional<TokenRange> RegexQueryMatch::captured_tokens(
    const std::string &var) const {
  std::optional<std::string_view> maybe_data = captured_data(var);
  if (!maybe_data) {
    return std::nullopt;
  } else {
    if (index_of_captured_variable(var).value()) {
      return TranslateCapture(*maybe_data);
    } else {
      return *this;
    }
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
std::optional<TokenRange> RegexQueryMatch::captured_tokens(size_t ti) const {
  std::optional<std::string_view> maybe_data = captured_data(ti);
  if (!maybe_data) {
    return std::nullopt;
  } else if (ti) {
    return TranslateCapture(*maybe_data);
  } else {
    return *this;
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

gap::generator<RegexQueryMatch> RegexQueryResultImpl::Enumerate(void) {
  size_t index = 0;
  size_t num_matches = fragment_ids.size();

  while (index < num_matches) {
    // We don't yet have any matches for `index`, so go compute them.
    if (!frag) {
      if (!InitForFragment(fragment_ids[index])) {
        ++index;
        continue;
      }
    }

    if (auto result = GetNextMatchInFragment()) {
      co_yield *result;
    }

    ++index;
  }
}

RegexQuery RegexQuery::from(const RegexQueryMatch &match) {
  return RegexQuery(match.query);
}

// Match this regular expression against a file.
gap::generator<RegexQueryMatch> RegexQuery::match_fragments(
    const File &file) const {
  const auto &reader = file.impl->reader;
  std::vector<EntityOffset> matched_offsets;

  this->for_each_match(
      file.data(),
      [&matched_offsets]
      (std::string_view, unsigned begin, unsigned end) -> bool {
        if (begin < end) {
          matched_offsets.push_back(begin);
        }
        return true;
      });

  std::sort(matched_offsets.begin(), matched_offsets.end());
  auto unique_it = std::unique(matched_offsets.begin(), matched_offsets.end());
  matched_offsets.erase(unique_it, matched_offsets.end());

  if (matched_offsets.empty()) {
    co_return;
  }

  const auto byte_offsets = reader.getTokenOffsets();
  const auto tok_kinds = reader.getTokenKinds();
  const auto num_file_toks = tok_kinds.size();
  const auto it_begin = byte_offsets.begin();
  const auto it_end = byte_offsets.end();

  // Convert from byte offsets to token offsets.
  for (EntityOffset &offset : matched_offsets) {
    auto it = LowerBound(it_begin, it_end, offset);
    if (it == it_end) {
      assert(false);
      continue;
    }

    auto diff = it - it_begin;
    if (0 > diff) {
      assert(false);
      offset = ~0u;
      continue;
    }

    offset = static_cast<EntityOffset>(diff);
    if (offset >= num_file_toks) {
      assert(false);
      offset = ~0u;
    }
  }

  const EntityProvider::Ptr &ep = file.impl->ep;
  RegexQueryResultImpl result_impl(
      *this, ep,
      ep->FragmentsCoveringTokens(ep, file.id(), std::move(matched_offsets)));
  for (auto match : result_impl.Enumerate()) {
    co_yield match;
  }
}

// Match this regular expression against a fragment.
gap::generator<RegexQueryMatch> RegexQuery::match_fragments(
    const Fragment &frag) const {
  RegexQueryResultImpl result_impl(*this, frag.impl);
  for (auto match : result_impl.Enumerate()) {
    co_yield match;
  }
}

}  // namespace mx

#else
namespace mx {

RegexQueryResultImpl::~RegexQueryResultImpl(void) noexcept {}

RegexQueryResultImpl::RegexQueryResultImpl(
    const RegexQuery &query_, EntityProvider::Ptr ep_, FragmentIdList)
    : query(query_),
      ep(std::move(ep_)) {}

RegexQueryResultImpl::RegexQueryResultImpl(
    const RegexQuery &query_, FragmentImplPtr frag_)
    : query(query_),
      ep(frag_->ep) {}

bool RegexQueryResultImpl::InitForFragment(FragmentImplPtr frag_) {
  return false;
}

bool RegexQueryResultImpl::InitForFragment(RawEntityId frag_id) {
  return false;
}

std::optional<RegexQueryMatch>
RegexQueryResultImpl::GetNextMatchInFragment(void) {
    return std::nullopt;
}

gap::generator<RegexQueryMatch> RegexQueryResultImpl::Enumerate(void) {
  co_return;
}

RegexQueryMatch::~RegexQueryMatch(void) {}

RegexQueryMatch::RegexQueryMatch(TokenRange range_ /* file token range */,
                                 std::string_view data_range /* file data */,
                                 std::shared_ptr<const FragmentImpl> frag_,
                                 const RegexQuery &query_)
    : TokenRange(std::move(range_)),
      frag(std::move(frag_)),
      query(query_.impl) {}

// Translate a data capture into a token range capture.
std::optional<TokenRange> RegexQueryMatch::TranslateCapture(
    std::string_view capture) const {
  return std::nullopt;
}

// Return the index of a capture variable.
std::optional<size_t> RegexQueryMatch::index_of_captured_variable(
    const std::string &var) const {
  return std::nullopt;
}

// Return the captured tokens for a given named capture group.
std::optional<TokenRange> RegexQueryMatch::captured_tokens(
    const std::string &var) const {
  return std::nullopt;
}

// Return the captured data for a given named capture group.
std::optional<std::string_view> RegexQueryMatch::captured_data(
    const std::string &var) const {
  return std::nullopt;
}

// Return the captured tokens for a given indexed capture group.
std::optional<TokenRange> RegexQueryMatch::captured_tokens(
    size_t index) const {
  return std::nullopt;
}

// Return the captured data for a given indexed capture group.
std::optional<std::string_view> RegexQueryMatch::captured_data(
    size_t capture_index) const {
  return std::nullopt;
}

// Return the number of capture groups.
size_t RegexQueryMatch::num_captures(void) const {
  return 0;
}

// Return a list of matched variables.
std::vector<std::string> RegexQueryMatch::captured_variables(void) const {
  return {};
}

RegexQuery RegexQuery::from(const RegexQueryMatch &match) {
  return RegexQuery(match.query);
}

// Match this regular expression against a file.
gap::generator<RegexQueryMatch> RegexQuery::match_fragments(const File &) const {
  co_return;
}

gap::generator<RegexQueryMatch> RegexQuery::match_fragments(const Fragment &) const {
  co_return;
}

}  // namespace mx

#endif   // MX_DISABLE_RE2

