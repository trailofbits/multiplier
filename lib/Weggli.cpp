// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "API.h"

#include <weggli.h>
#include <atomic>
#include <cassert>
#include <iostream>
#include <multiplier/Compress.h>
#include <multiplier/Weggli.h>

namespace mx {

class WeggliQueryImpl final {
 private:
  friend class WeggliQuery;

  using Ptr = std::shared_ptr<WeggliQueryImpl>;

  using TreePtr = struct QueryTree*;
  using ResultPtr = struct QueryResult*;
  using ResultsPtr = struct QueryResults*;
  using UserDataPtr = void*;

  TreePtr qtree;

  std::string query;

 public:
  explicit WeggliQueryImpl(std::string query) {
    qtree = weggli_new_query(query.c_str(), false);
  }

  virtual ~WeggliQueryImpl() {
    if (qtree) {
      weggli_destroy_query(qtree);
    }
  }

  bool IsValid(void) {
    return qtree != nullptr;
  }

  ResultsPtr FindMatches(std::string source, bool cpp) {
    if (qtree) {
      return weggli_matches(qtree, source.c_str(), cpp);
    }
    return nullptr;
  }

  void DestroyMatches(ResultsPtr results) {
    if (results) {
      weggli_destroy_matches(results);
    }
  }

  static void IterateMatches(ResultsPtr results, UserDataPtr userdata) {
    weggli_iter_matches(
        results,WeggliQueryImpl::MatchesCallback, userdata);
  }

  static bool MatchesCallback(const struct QueryResult *result, void *userdata) {
    weggli_iter_match_captures(
        result, WeggliQueryImpl::CaptureMatchesCallback, userdata);
    weggli_iter_match_variables(
        result,WeggliQueryImpl::VariableMatchesCallback, userdata);
    return true;
  }

  static bool CaptureMatchesCallback(size_t start, size_t end, void *userdata) {
    auto query_data = static_cast<WeggliQueryData*>(userdata);
    if (query_data == nullptr){
      std::cerr << "CaptureMatchesCallback: userdata not provided!";
      return true;
    }
    query_data->captures.emplace_back(start, end);
    return true;

  }

  static bool VariableMatchesCallback(
      const char* name, size_t start, size_t end, UserDataPtr userdata) {
    auto query_data = static_cast<WeggliQueryData*>(userdata);
    if (query_data == nullptr){
      std::cerr << "VariableMatchesCallback: userdata not provided!";
      return true;
    }
    query_data->variables.emplace_back(std::string(name), start, end);
    return true;
  }
};

WeggliQuery::WeggliQuery(std::string query)
    : syntax(query),
      impl(std::make_unique<WeggliQueryImpl>(query)){}

WeggliQuery::~WeggliQuery(){}

WeggliQuery::ResultsPtr
WeggliQuery::FindMatches(std::string source, bool cpp) {
  return impl->FindMatches(source, cpp);
}

void WeggliQuery::DestroyMatches(ResultsPtr results) {
  impl->DestroyMatches(
      reinterpret_cast<WeggliQueryImpl::ResultsPtr>(results));
}

void WeggliQuery::IterateMatches(ResultsPtr results, WeggliQueryData *data) {
  if (results) {
    WeggliQueryImpl::IterateMatches(
        reinterpret_cast<WeggliQueryImpl::ResultsPtr>(results), data);
  }
}

bool WeggliQuery::IsValid(void) {
  return impl->IsValid();
}

}
