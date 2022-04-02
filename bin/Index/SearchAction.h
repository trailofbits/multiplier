// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <map>
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
  std::string file_contents;
  std::map<unsigned, unsigned> eol_offset_to_line_num;

  void FillFileContents(mx::FileId);

 public:
  virtual ~SearchAction(void);

  SearchAction(std::shared_ptr<SearchingContext> context_,
               std::string_view syntax_string);

  void QuerySyntaxInFile(mx::FileId file_id);

  void GetFragmentMatches(
      mx::FileId file_id, uint32_t start, uint32_t end);

  // Build and index the AST.
  void Run(mx::Executor exe, mx::WorkerId worker_id) final;
};


} //namespace search
