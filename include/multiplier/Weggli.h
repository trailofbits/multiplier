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
#include <unordered_map>
#include <vector>
#include <tuple>

namespace mx {

class WeggliQueryImpl;
class Index;

struct WeggliMatchData final {
  // raw offset of the query matches captured by Weggli.
  unsigned begin_offset{~0u};
  unsigned end_offset{0u};

  std::unordered_map<std::string, std::pair<unsigned, unsigned>> variables;
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

  ~WeggliQuery();

  void ForEachMatch(std::string_view source,
                    std::function<bool(const WeggliMatchData &)> cb) const;

  bool IsValid(void) const;

  std::string_view Pattern(void) const;
  bool IsCPlusPlus(void) const;
};

}  // namespace mx
