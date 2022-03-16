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
#include <tuple>


namespace mx {

class WeggliQueryImpl;

struct WeggliQueryData final {
  // raw offset of the query matches captured by weggli
  std::vector<std::tuple<size_t, size_t>> captures;
  // raw offset of the variable match capture by weggli
  std::vector<std::tuple<std::string, size_t, size_t>> variables;
};

class WeggliQuery final {
 public:
  using Ptr = std::shared_ptr<WeggliQuery>;

  using TreePtr = void*;
  using ResultPtr = void*;
  using ResultsPtr = void*;
  using UserDataPtr = void*;

  using ResultCallback = bool(*)(const void*, void*);

  explicit WeggliQuery(std::string query);

  virtual ~WeggliQuery();

  ResultsPtr FindMatches(std::string source, bool is_cpp);

  void DestroyMatches(ResultsPtr results);

  void IterateMatches(ResultsPtr results, WeggliQueryData *data);

  bool IsValid(void);

 private:
  std::unique_ptr<WeggliQueryImpl> impl;

  const std::string syntax;
};

}

