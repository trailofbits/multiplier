// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Re2.h"

#include <cassert>

#ifndef MX_DISABLE_RE2

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
    if (!result.data()) {
      continue;
    }

    // NOTE(pag): We allow empty results.
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

void RegexQuery::for_each_match(
    std::string_view source,
    std::function<bool(
        std::string_view /* match */,
        unsigned /* begin_offset */,
        unsigned /* end_offset */)> cb) const {
  if (impl) {
    impl->ForEachMatch(source, std::move(cb));
  }
}

// Returns the underlying pattern.
std::string_view RegexQuery::pattern(void) const {
  if (impl) {
    // NOTE(pag): Need to remove the wrapping `(` and `)`.
    return std::string_view(impl->pattern).substr(1u, impl->pattern.size() - 2u);
  } else {
    return {};
  }
}

// Returns `true` if we successfully compiled this regular expression.
bool RegexQuery::is_valid(void) const {
  return impl && impl->IsValid();
}

}  // namespace mx

#else

namespace mx {

// NOTE(pag): `RE2::FindAndConsume` is a variadic function taking additional
//            arguments per sub-match, hence the requirement for enclosing
//            `pattern_` in a match group with `(` and `)`.
RegexQueryImpl::RegexQueryImpl(std::string pattern_)
    : pattern("(" + pattern_ + ")") {}

void RegexQueryImpl::ForEachMatch(
    std::string_view contents,
    std::function<bool(std::string_view /* match */,
                       unsigned /* begin_offset */,
                       unsigned /* end_offset */)> cb) {}

RegexQuery::RegexQuery(std::string pattern)
    : impl(std::make_shared<RegexQueryImpl>(std::move(pattern))) {}

RegexQuery::~RegexQuery(void) {}

void RegexQuery::for_each_match(
    std::string_view source,
    std::function<bool(
        std::string_view /* match */,
        unsigned /* begin_offset */,
        unsigned /* end_offset */)> cb) const {}

// Returns the underlying pattern.
std::string_view RegexQuery::pattern(void) const {
    return {};
}

// Returns `true` if we successfully compiled this regular expression.
bool RegexQuery::is_valid(void) const {
  return false;
}

}  // namespace mx

#endif   // MX_DISABLE_RE2
