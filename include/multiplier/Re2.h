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

#include <gap/core/generator.hpp>

#include "Compiler.h"

namespace mx {

class File;
class Fragment;
class RegexQueryImpl;
class RegexQueryMatch;
class RegexQueryMatchImpl;

// A regular expression.
class MX_EXPORT RegexQuery final {
 private:
  friend class Index;
  friend class RegexQueryMatch;
  friend class RegexQueryMatchImpl;

  std::shared_ptr<RegexQueryImpl> impl;

  /* implicit */ inline RegexQuery(std::shared_ptr<RegexQueryImpl> impl_)
      : impl(std::move(impl_)) {}

 public:
  static RegexQuery from(const RegexQueryMatch &match);

  RegexQuery(void) = default;

  // TODO(pag): Eventually make a `Create` static method and return a result
  //            type.
  explicit RegexQuery(std::string pattern);

  ~RegexQuery();

  // Search for matches in `source`. Each match is returned as a string
  // view, corresponding to the range `[begin_offset, end_offset)` in `source`.
  // `match` also points into `source`.
  void for_each_match(
      std::string_view source,
      std::function<bool(std::string_view /* match */,
                         unsigned /* begin_offset */,
                         unsigned /* end_offset */)> cb) const;

  // Returns the underlying pattern.
  std::string_view pattern(void) const;

  // Returns `true` if we successfully compiled this regular expression.
  bool is_valid(void) const;

  // Match this regular expression against a file.
  gap::generator<RegexQueryMatch> match_fragments(const File &) const &;

  // Match this regular expression against a fragment.
  gap::generator<RegexQueryMatch> match_fragments(const Fragment &) const &;
};

}  // namespace mx
