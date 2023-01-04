// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <functional>
#include <memory>
#include <string>
#include <string_view>
#include <vector>
#include <tuple>

namespace mx {

class File;
class Fragment;
class Index;
class WeggliQueryImpl;
class WeggliQueryResult;

struct WeggliMatchData final {
  // Raw offsets of the query matches captured by Weggli.
  unsigned begin_offset{~0u};
  unsigned end_offset{0u};

  using MatchRange = std::pair<unsigned, unsigned>;

  std::vector<std::string> variables;
  std::vector<MatchRange> matches;
};

class WeggliQuery final {
 private:
  friend class Index;

  std::shared_ptr<WeggliQueryImpl> impl;

 public:
  using TreePtr = void *;
  using ResultPtr = void *;
  using ResultsPtr = void *;
  using UserDataPtr = void *;

  WeggliQuery(void) = default;
  explicit WeggliQuery(std::string query, bool is_cpp);

  ~WeggliQuery(void);

  void for_each_match(std::string_view source,
                      std::function<bool(WeggliMatchData)> cb) const;

  bool is_valid(void) const;

  std::string_view pattern(void) const;

  bool is_c_plus_plus(void) const;

  // Match this Weggli query against a file.
  WeggliQueryResult match_fragments(const File &) const;

  // Match this Weggli query against a fragment.
  WeggliQueryResult match_fragments(const Fragment &) const;
};

}  // namespace mx
