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
#include <multiplier/Index.h>
#include <multiplier/Weggli.h>

#include <unordered_map>

#include "Context.h"

namespace indexer {

class WeggliSearchAction final : public mx::Action {
 private:
  const std::shared_ptr<SearchingContext> context;
  const mx::WeggliQuery query_tree;

  std::map<unsigned, unsigned> eol_offset_to_line_num;

 public:
  virtual ~WeggliSearchAction(void);

  WeggliSearchAction(std::shared_ptr<SearchingContext> context_,
                     std::string syntax_string, bool is_cpp);

  void QuerySyntaxInFile(mx::WorkerId worker_id, mx::RawEntityId file_id);

  // Build and index the AST.
  void Run(mx::Executor exe, mx::WorkerId worker_id) final;
};


} //namespace search
