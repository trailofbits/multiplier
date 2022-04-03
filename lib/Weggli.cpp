// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "API.h"

#include <weggli.h>
#include <atomic>
#include <cassert>
#include <glog/logging.h>
#include <iostream>
#include <multiplier/Compress.h>
#include <multiplier/Weggli.h>

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
  match->variables.try_emplace(
      name, static_cast<unsigned>(start), static_cast<unsigned>(end));
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
    auto cb = reinterpret_cast<std::function<bool(const WeggliMatchData &)> *>(data);
    return (*cb)(match);

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

  const TreePtr qtree;
  const bool is_cpp;

 public:
  explicit WeggliQueryImpl(std::string_view query, bool is_cpp_)
      : qtree(weggli_new_query(query.data(), is_cpp_)),
        is_cpp(is_cpp_) {}

  ~WeggliQueryImpl(void) {
    if (qtree) {
      weggli_destroy_query(qtree);
    }
  }
};

WeggliQuery::WeggliQuery(std::string_view query, bool is_cpp)
    : impl(std::make_unique<WeggliQueryImpl>(query, is_cpp)) {}

WeggliQuery::~WeggliQuery(void) {}

void WeggliQuery::ForEachMatch(
    std::string_view source,
    std::function<bool(const WeggliMatchData &)> cb) const {

  if (!impl->qtree || source.empty()) {
    return;
  }

  auto matches = weggli_matches(impl->qtree, source.data(), impl->is_cpp);
  if (!matches) {
    return;
  }

  weggli_iter_matches(matches, WeggliCallback, &cb);
  weggli_destroy_matches(matches);
}

bool WeggliQuery::IsValid(void) const {
  return impl->qtree != nullptr;
}

}  // namespace mx
