// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <string>
#include <string_view>
#include <vector>

#include "Fragment.h"

namespace mx {

class EntityProvider;
class File;
class FileImpl;
class Fragment;
class FragmentImpl;
class Index;
class RemoteEntityProvider;
class RegexQuery;
class RegexQueryImpl;
class RegexQueryMatch;
class InvalidEntityProvider;

// The range of tokens that matches a regular expression.
class RegexQueryMatch : public TokenRange {
 private:
  friend class File;
  friend class Fragment;
  friend class RegexQuery;
  friend class RegexQueryResultImpl;

  // The actual range of matched data. This is possibly a sub-sequence of
  // `this->TokenRange::data()`.
  std::vector<std::string_view> matched_ranges;

  // Fragment with the match.
  std::shared_ptr<const FragmentImpl> frag;

  // The regular expression used.
  std::shared_ptr<RegexQueryImpl> query;

  // Translate a data capture into a token range capture.
  std::optional<TokenRange> TranslateCapture(std::string_view capture) const;

  RegexQueryMatch(TokenRange range_, std::string_view data_range_,
                  std::shared_ptr<const FragmentImpl> frag_,
                  const RegexQuery &query_);

  RegexQueryMatch(void) = delete;

 public:
  ~RegexQueryMatch(void);

  // The actual range of matched data. This is possibly a sub-sequence of
  // `this->TokenRange::data()`.
  inline std::string_view data(void) const noexcept {
    return matched_ranges[0];
  }

  // Return the index of a capture variable.
  std::optional<size_t> index_of_captured_variable(const std::string &var) const;

  // Return the captured tokens for a given named capture group.
  std::optional<TokenRange> captured_tokens(const std::string &var) const;

  // Return the captured data for a given named capture group.
  std::optional<std::string_view> captured_data(const std::string &var) const;

  // Return the captured tokens for a given indexed capture group.
  std::optional<TokenRange> captured_tokens(size_t catpture_index) const;

  // Return the captured data for a given indexed capture group.
  std::optional<std::string_view> captured_data(size_t capture_index) const;

  // Return a list of named capture groups.
  std::vector<std::string> captured_variables(void) const;

  // Return the number of capture groups.
  size_t num_captures(void) const;
};

}  // namespace mx
