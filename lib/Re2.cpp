// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Re2.h"

namespace mx {

// NOTE(pag): `RE2::FindAndConsume` is a variadic function taking additional
//            arguments per sub-match, hence the requirement for enclosing
//            `pattern_` in a match group with `(` and `)`.
RegexQueryImpl::RegexQueryImpl(std::string pattern_)
    : pattern("(" + pattern_ + ")"),
      re(pattern) {}

void RegexQueryImpl::ForEachMatch(
    std::string_view contents,
    std::function<bool(std::string_view /* match */,
                       unsigned /* begin_offset */,
                       unsigned /* end_offset */)> cb) {
  if (!IsValid()) {
    return;
  }

  re2::StringPiece input(contents);
  re2::StringPiece result;

  while (re2::RE2::FindAndConsume(&input, re, &result)) {
    if (result.empty()) {
      continue;
    }

    std::string_view match(result.data(), result.size());
    assert(contents.begin() <= match.begin());
    assert(match.end() <= contents.end());

    unsigned begin_offset =
        static_cast<unsigned>(result.data() - contents.data());
    unsigned end_offset = static_cast<unsigned>(begin_offset + result.size());

    // NOTE(pag): Match is `[begin_offset, end_offset)`.
    cb(match, begin_offset, end_offset);
  }
}

RegexQuery::RegexQuery(std::string pattern)
    : impl(std::make_shared<RegexQueryImpl>(std::move(pattern))) {}

RegexQuery::~RegexQuery(void) {}

void RegexQuery::ForEachMatch(
    std::string_view source,
    std::function<bool(
        std::string_view /* match */,
        unsigned /* begin_offset */,
        unsigned /* end_offset */)> cb) const {
  impl->ForEachMatch(source, std::move(cb));
}

// Returns the underlying pattern.
std::string_view RegexQuery::Pattern(void) const {

  // NOTE(pag): Need to remove the wrapping `(` and `)`.
  return std::string_view(impl->pattern).substr(1u, impl->pattern.size() - 2u);
}

// Returns `true` if we successfully compiled this regular expression.
bool RegexQuery::IsValid(void) const {
  return impl->IsValid();
}

}  // namespace mx
