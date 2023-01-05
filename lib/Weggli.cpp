// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Weggli.h>

#ifndef MX_DISABLE_WEGGLI

#include <weggli.h>

namespace mx {
namespace {

static bool CaptureMatchesCallback(size_t start, size_t end, void *data) {
  if (!data) {
    return false;
  }

  auto match = static_cast<WeggliMatchData *>(data);
  match->begin_offset = std::min(
      match->begin_offset, static_cast<unsigned>(start));
  match->end_offset = std::max(match->end_offset, static_cast<unsigned>(end));

  return true;
}

static bool VariableMatchesCallback(
    const char *name, size_t start, size_t end, void *data) {
  if (!data) {
    return false;
  }

  auto match = static_cast<WeggliMatchData *>(data);
  match->variables.emplace_back(name);
  match->matches.emplace_back(static_cast<unsigned>(start),
                              static_cast<unsigned>(end));
  return true;
}

static bool WeggliCallback(const struct QueryResult *result, void *data) {
  if (!data) {
    return false;
  }

  WeggliMatchData match;
  weggli_iter_match_captures(result, CaptureMatchesCallback, &match);
  weggli_iter_match_variables(result, VariableMatchesCallback, &match);
  if (match.begin_offset < match.end_offset) {
    auto cb = reinterpret_cast<std::function<bool(WeggliMatchData)> *>(data);
    return (*cb)(std::move(match));

  } else {
    return true;
  }
}

}  // namespace

class WeggliQueryImpl final {
 public:
  using TreePtr = struct QueryTree *;
  using ResultPtr = struct QueryResult *;
  using ResultsPtr = struct QueryResults *;
  using UserDataPtr = void*;

  const std::string pattern;
  const TreePtr qtree;
  const bool is_cpp;

 public:
  explicit WeggliQueryImpl(std::string query_, bool is_cpp_)
      : pattern(std::move(query_)),
        qtree(weggli_new_query(pattern.data(), is_cpp_)),
        is_cpp(is_cpp_) {}

  ~WeggliQueryImpl(void) {
    if (qtree) {
      weggli_destroy_query(qtree);
    }
  }
};

WeggliQuery::WeggliQuery(std::string query, bool is_cpp)
    : impl(std::make_shared<WeggliQueryImpl>(std::move(query), is_cpp)) {}

WeggliQuery::~WeggliQuery(void) {}

void WeggliQuery::for_each_match(
    std::string_view source,
    std::function<bool(WeggliMatchData)> cb) const {

  if (!impl || !impl->qtree || source.empty()) {
    return;
  }

  auto matches = weggli_matches(impl->qtree, source.data(), source.size(),
                                impl->is_cpp);
  if (!matches) {
    return;
  }

  weggli_iter_matches(matches, WeggliCallback, &cb);
  weggli_destroy_matches(matches);
}

std::string_view WeggliQuery::pattern(void) const {
  return impl ? impl->pattern : std::string_view();
}

bool WeggliQuery::is_valid(void) const {
  return impl && impl->qtree != nullptr;
}

bool WeggliQuery::is_c_plus_plus(void) const {
  return impl && impl->is_cpp;
}

}  // namespace mx
#else
namespace mx {

class WeggliQueryImpl {};

WeggliQuery::WeggliQuery(std::string, bool)
    : impl() {}

WeggliQuery::~WeggliQuery(void) {}

void WeggliQuery::for_each_match(
    std::string_view, std::function<bool(WeggliMatchData)>) const {}

bool WeggliQuery::is_valid(void) const {
  return false;
}

std::string_view WeggliQuery::pattern(void) const {
  return {};
}

bool WeggliQuery::is_c_plus_plus(void) const {
  return false;
}

}  // namespace mx
#endif   // MX_DISABLE_WEGGLI
