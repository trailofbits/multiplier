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
    std::cerr << "never captures?\n";
    return false;
  }

  auto match = static_cast<WeggliMatchData *>(data);
  match->begin_offset = std::min(
      match->begin_offset, static_cast<unsigned>(start));
  match->end_offset = std::max(match->end_offset, static_cast<unsigned>(end));

  std::cerr << "capture [" << match->begin_offset << ", " << match->end_offset << ")\n";

  return true;
}

static bool VariableMatchesCallback(
    const char *name, size_t start, size_t end, void *data) {
  if (!data) {
    std::cerr << "never captures 2?\n";
    return false;
  }

  std::cerr << "var capture\n";

  auto match = static_cast<WeggliMatchData *>(data);
  match->variables.try_emplace(
      name, static_cast<unsigned>(start), static_cast<unsigned>(end));
  return true;
}

static bool WeggliCallback(const struct QueryResult *result, void *data) {
  if (!data) {
    std::cerr << "no user data to WeggliCallback\n";
    return false;
  }

  std::cerr << "iterating captures...\n";

  WeggliMatchData match;
  weggli_iter_match_captures(result, CaptureMatchesCallback, &match);
  weggli_iter_match_variables(result, VariableMatchesCallback, &match);
  if (match.begin_offset < match.end_offset) {
    std::cerr << "yay\n";
    auto cb = reinterpret_cast<std::function<bool(const WeggliMatchData &)> *>(data);
    return (*cb)(match);

  } else {
    std::cerr << "nay\n";
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
        is_cpp(is_cpp_) {
    std::cerr << "query is '" << query << "' is_cpp=" << is_cpp << "\n";
  }

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
    std::cerr << "no qtree or file empty\n";
    return;
  }

  std::cerr << "trying to match on source " << source <<'\n';
  auto matches = weggli_matches(impl->qtree, source.data(), impl->is_cpp);
  if (!matches) {
    std::cerr << "really no matches\n";
    return;
  }

  std::cerr << "collecting matches...\n";
  weggli_iter_matches(matches, WeggliCallback, &cb);
  weggli_destroy_matches(matches);
}

bool WeggliQuery::IsValid(void) const {
  return impl->qtree != nullptr;
}

}  // namespace mx
