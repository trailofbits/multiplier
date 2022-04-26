// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <functional>
#include <memory>
#include <string_view>
#include <string>
#include <vector>

namespace mx {

class RegexQueryImpl;
class RegexQueryMatch;

// A regular expression.
class RegexQuery final {
 private:
  friend class Index;
  friend class RegexQueryMatch;

  std::shared_ptr<RegexQueryImpl> impl;

  RegexQuery(void) = delete;

 public:

  // TODO(pag): Eventually make a `Create` static method and return a result
  //            type.
  explicit RegexQuery(std::string pattern);

  ~RegexQuery();

  // Search for matches in `source`. Each match is returned as a string
  // view, corresponding to the range `[begin_offset, end_offset)` in `source`.
  // `match` also points into `source`.
  void ForEachMatch(
      std::string_view source,
      std::function<bool(std::string_view /* match */,
                         unsigned /* begin_offset */,
                         unsigned /* end_offset */)> cb) const;

  // Returns the underlying pattern.
  std::string_view Pattern(void) const;

  // Returns `true` if we successfully compiled this regular expression.
  bool IsValid(void) const;
};

}  // namespace mx
