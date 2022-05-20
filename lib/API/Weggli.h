// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Fragment.h"

#include <map>
#include <multiplier/Weggli.h>

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
  std::string fragment_buffer;
  std::map<unsigned, EntityId> offset_to_token;
  std::vector<WeggliMatchData> weggli_matches;
  unsigned next_weggli_match{0};

  // List of fragments in this file.
  std::vector<FragmentId> fragments;

  using Response =
      capnp::Response<mx::rpc::Multiplier::WeggliQueryFragmentsResults>;

  EntityId EntityContainingOffset(unsigned offset) const;

  ~WeggliQueryResultImpl(void) noexcept;

  WeggliQueryResultImpl(const WeggliQuery &query_, EntityProvider::Ptr ep_,
                        Response response_);

  WeggliQueryResultImpl(const WeggliQuery &query_, FragmentImpl::Ptr frag_);

  void GetUnparsedTokens(TokenSubstitutionList nodes);

  void InitForFragment(void);
};

}  // namespace mx
