// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Re2.h"

#include <map>

#include "Fragment.h"
#include "Types.h"

#pragma GCC visibility push(hidden)
namespace mx {

class RegexQueryResultImpl final {
 public:

  // Client-local version of the query to be run on each fragment.
  const RegexQuery query;

  // Needed for us to be able to look up the file containing this fragment,
  // or look up entities related to other fragments.
  const EntityProviderPtr ep;

  // Maps the offsets bytes following tokens to indexes of tokens in
  // `frag_file_tokens`. This is useful to go from a match offset to a file
  // token using `std::upper_bound`.
  std::map<unsigned, unsigned> offset_to_index;

  // The fragment containing the match.
  FragmentImplPtr frag;

  // Range of file tokens covering this fragment.
  TokenRange frag_file_tokens;

  // List of matches within `buffer`, which corresponds to the file data
  // covering the code of `frag`.
  std::vector<std::tuple<std::string_view, unsigned, unsigned>>
      matches;

  // Index of next result in `matches` that has to be returned to the calling
  // code.
  unsigned next_match_index{0};

  // List of fragments that might match.
  FragmentIdList fragment_ids;

  using Ptr = std::shared_ptr<RegexQueryResultImpl>;

  ~RegexQueryResultImpl(void) noexcept;

  RegexQueryResultImpl(
      const RegexQuery &re_, EntityProviderPtr ep_,
      FragmentIdList fragment_ids);

  RegexQueryResultImpl(const RegexQuery &re_, FragmentImplPtr frag_);

  bool InitForFragment(FragmentImplPtr frag_);
  bool InitForFragment(PackedFragmentId frag_id);

  std::optional<RegexQueryMatch> GetNextMatchInFragment(void);

  gap::generator<RegexQueryMatch> Enumerate(void) &;
};

class RegexQueryMatchImpl final : public ProxyTokenReader {
 public:
  virtual ~RegexQueryMatchImpl(void);

  // The actual range of matched data. This is possibly a sub-sequence of
  // `this->TokenRange::data()`.
  std::vector<std::string_view> matched_ranges;

  // Fragment with the match.
  std::shared_ptr<const FragmentImpl> frag;

  // The regular expression used.
  std::shared_ptr<RegexQueryImpl> query;

  // Translate a data capture into a token range capture.
  std::optional<std::pair<unsigned, unsigned>> TranslateCapture(
      const TokenRange &self, std::string_view capture) const;

  RegexQueryMatchImpl(const TokenRange &range_, std::string_view data_range_,
                      std::shared_ptr<const FragmentImpl> frag_,
                      const RegexQuery &query_);
};

}  // namespace mx
#pragma GCC visibility pop
