// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "API.h"

namespace mx {

class RegexQueryResultImpl {
 public:
  using Response = capnp::Response<mx::rpc::Multiplier::RegexQueryResults>;

  using Ptr = std::shared_ptr<const RegexQueryResultImpl>;

  virtual ~RegexQueryResultImpl(void) noexcept;

  RegexQueryResultImpl(
      std::string syntax_, EntityProvider::Ptr ep_, Response response_);

  const std::string pattern;

  // Needed for us to be able to look up the file containing this fragment,
  // or look up entities related to other fragments.
  const EntityProvider::Ptr ep;

  // Client-local version of the query to be run on each fragment.
  const RegExpr re;

  // Buffer of fragment data.
  mutable std::string fragment_buffer;
  mutable std::map<unsigned, EntityId> offset_to_token;

  mutable mx::FragmentId fragment_buffer_id{kInvalidEntityId};

  mutable std::string file_buffer;

  mutable mx::FileId file_buffer_id{kInvalidEntityId};

  mutable std::vector<std::tuple<
  std::string, unsigned, unsigned>> regex_matches;

  mutable unsigned next_regex_match{0};

  // List of fragments that matches
  mutable std::vector<std::pair<mx::FragmentId,
                      std::weak_ptr<const FragmentImpl>>> fragments;

  // Lust of files that matches
  mutable std::vector<std::pair<mx::FileId,
                      std::weak_ptr<const FileImpl>>> files;

  mutable std::vector<std::tuple<mx::FileId, mx::FragmentId>> matches;

  std::shared_ptr<const FragmentImpl> GetFragmentAtIndex(unsigned index) const;

  std::shared_ptr<const FileImpl> GetFileAtIndex(unsigned index) const;

  EntityId EntityContainingOffset(unsigned offset) const;

  void GetUnparsedTokens(TokenSubstitutionList nodes) const;

  void GetFileContents(File) const;
};


}  // namespace mx
