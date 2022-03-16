// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <multiplier/Action.h>
#include <multiplier/RPC.capnp.h>
#include <multiplier/API.h>
#include <multiplier/Weggli.h>

#include <unordered_map>

#include "Context.h"

namespace indexer {

class SearchAction final : public mx::Action {
 private:
  const std::shared_ptr<SearchingContext> context;

  mx::WeggliQuery::Ptr query_tree;

  const std::string syntax;

  std::string GetFileContents(mx::FileId);

 public:
  virtual ~SearchAction(void);

  SearchAction(std::shared_ptr<SearchingContext> context_,
               std::string_view syntax_string);

  void QuerySyntaxInFile(mx::FileId file_id, const std::string &query);

  std::pair<uint32_t, uint32_t> ConvertOffsetToLine(
      const std::string &file, uint64_t start, uint64_t end);

  void GetFragmentMatches(
      mx::FileId file_id, uint32_t start, uint32_t end);

  // Build and index the AST.
  void Run(mx::Executor exe, mx::WorkerId worker_id) final;
};


} //namespace search
