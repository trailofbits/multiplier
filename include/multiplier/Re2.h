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

class RegExprImpl;

class RegExpr final {
 public:

  explicit RegExpr(std::string_view pattern);

  ~RegExpr();

  void ForEachMatch(
      std::string_view source,
      std::function<bool(const std::string &pattern,
                         unsigned begin_offset,
                         unsigned end_offset)> cb) const;

  bool IsValid(void) const;

 private:
  std::unique_ptr<RegExprImpl> impl;
};

}
