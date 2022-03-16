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

#include <unordered_map>

#include "Context.h"

namespace indexer {

class SearchAction final : public mx::Action {
 private:
  const std::shared_ptr<SearchingContext> context;
  const pasta::FileManager file_manager;

  const std::string query_string;

  // Look through all files referenced by the AST get their unique IDs. If this
  // is the first time seeing a file, then tokenize the file.
  void MaybePersistFile(
      mx::WorkerId worker_id, const mx::Executor &exe, pasta::File file);

 public:
  virtual ~SearchAction(void);

  SearchAction(std::shared_ptr<SearchingContext> context_,
                        pasta::FileManager file_manager_,
                        std::string_view query_string);


  std::string GetFileContents(mx::FileId);

  void QueryStringFromFile(mx::FileId file_id, const std::string &query);


  std::pair<int32_t, int32_t> ConvertOffsetToLine(
      const std::string &file, size_t start, size_t end);

  void GetFragmentMatchesFromFile(mx::FileId file_id, size_t line_start, size_t line_end);

  // Build and index the AST.
  void Run(mx::Executor exe, mx::WorkerId worker_id) final;
};


} //namespace search
