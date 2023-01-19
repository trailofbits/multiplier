// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Weggli.h>

#include <map>
#include <multiplier/Types.h>

#include "Fragment.h"

namespace mx {

class WeggliQueryResultImpl final {
 public:
  using Ptr = std::shared_ptr<WeggliQueryResultImpl>;

  // Client-local version of the query to be run on each fragment.
  const WeggliQuery query;

  // Needed for us to be able to look up the file containing this fragment,
  // or look up entities related to other fragments.
  const EntityProvider::Ptr ep;

  // Buffer of fragment data.
  FragmentImpl::Ptr frag;
  TokenRange frag_file_tokens;
  std::map<unsigned, unsigned> offset_to_index;
  std::vector<WeggliMatchData> weggli_matches;
  unsigned next_weggli_match{0};

  // List of fragments in this file.
  FragmentIdList fragments;

  ~WeggliQueryResultImpl(void) noexcept;

  WeggliQueryResultImpl(const WeggliQuery &query_, EntityProvider::Ptr ep_,
                        FragmentIdList fragment_ids);

  WeggliQueryResultImpl(const WeggliQuery &query_, FragmentImpl::Ptr frag_);

  bool InitForFragment(FragmentImpl::Ptr frag_);

  gap::generator<WeggliQueryMatch> Enumerate(void);
};

}  // namespace mx
