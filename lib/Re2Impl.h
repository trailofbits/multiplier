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

}  // namespace mx
