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

class ReExprImpl;

struct ExprMatchData final {
  // raw offset of the query matches captured by Weggli.
  unsigned begin_offset{~0u};
  unsigned end_offset{0u};

  std::unordered_map<std::string, std::pair<unsigned, unsigned>> variables;
};

class ReExpr final {
 public:

  explicit ReExpr(std::string_view query, bool is_cpp);

  ~ReExpr();

  void ForEachMatch(std::string_view source,
                    std::function<bool(const ExprMatchData &)> cb) const;

  bool IsValid(void) const;

 private:
  std::unique_ptr<ReExprImpl> impl;
};

}
