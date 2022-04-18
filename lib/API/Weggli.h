// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "API.h"

namespace mx {

class WeggliQueryResultImpl {
 public:
  using Response = capnp::Response<mx::rpc::Multiplier::WeggliQueryResults>;

  using Ptr = std::shared_ptr<const WeggliQueryResultImpl>;

  virtual ~WeggliQueryResultImpl(void) noexcept;

  WeggliQueryResultImpl(std::string syntax_, EntityProvider::Ptr ep_,
                        Response response_, bool is_cpp);

  const std::string syntax;

  // Needed for us to be able to look up the file containing this fragment,
  // or look up entities related to other fragments.
  const EntityProvider::Ptr ep;

  // Client-local version of the query to be run on each fragment.
  const WeggliQuery query;

  // Buffer of fragment data.
  mutable std::string fragment_buffer;
  mutable std::map<unsigned, EntityId> offset_to_token;
  mutable mx::FragmentId fragment_buffer_id{kInvalidEntityId};
  mutable std::vector<WeggliMatchData> weggli_matches;
  mutable unsigned next_weggli_match{0};

  // List of fragments in this file.
  mutable std::vector<std::pair<mx::FragmentId,
                      std::weak_ptr<const FragmentImpl>>> fragments;

  std::shared_ptr<const FragmentImpl> GetFragmentAtIndex(unsigned index) const;

  EntityId EntityContainingOffset(unsigned offset) const;

  void GetUnparsedTokens(TokenSubstitutionList nodes) const;
};

}  // namespace mx
