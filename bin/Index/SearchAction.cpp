// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "SearchAction.h"

#include <capnp/message.h>
#include <capnp/serialize.h>
#include <glog/logging.h>
#include <kj/async-io.h>
#include <kj/debug.h>
#include <kj/exception.h>
#include <kj/string.h>

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

#include <weggli.h>

#include "Context.h"
#include "Compress.h"
#include "Util.h"

namespace indexer {

std::string SearchAction::GetFileContents(mx::FileId file_id) {
  std::string file_contents;

  auto maybe_contents = context->GetSerializedFile(file_id);
  if (!maybe_contents) {
    return {};
  }

  WithUncompressedMessageImpl(
      "file", maybe_contents.value(),
      [&file_contents] (capnp::MessageReader &reader) {
    auto file = reader.getRoot<mx::rpc::File>();
    for (auto tokens : file.getTokens()) {
      capnp::Text::Reader data_reader = tokens.getData();
      file_contents += std::string(data_reader.cStr());
    }
  });

  return file_contents;
}

std::pair<uint32_t, uint32_t> SearchAction::ConvertOffsetToLine(
    const std::string &file, uint64_t start, uint64_t end) {

  auto line_start = 0u;
  auto line_end = 0u;
  auto counter = 0u;

  std::istringstream input{file};
  size_t start_index = input.tellg();
  while (false == input.eof()) {
    std::string   line;
    std::getline(input, line);
    counter++;

    size_t end_index = input.tellg();
    if (start >= start_index && start <= (start_index + line.size())) {
      line_start = counter;
    }

    if (end >= start_index && end <= (start_index + line.size())) {
      line_end = counter;
    }

    start_index = end_index;
  }

  return {line_start, line_end};
}

void SearchAction::GetFragmentMatches(
    mx::FileId file_id, uint32_t line_start, uint32_t line_end) {

  std::vector<mx::FragmentId> fragment_ids;
  context->ScanFilePrefix(file_id,
      [file_id, &fragment_ids] (mx::FileId found_file_id,
                                mx::FragmentId fragment_id) {
        DCHECK_EQ(file_id, found_file_id);
        fragment_ids.push_back(fragment_id);
        return file_id == found_file_id;
      });

  for (auto &fragment_id : fragment_ids) {
    auto maybe_contents = context->GetSerializedFragment(fragment_id);
    if (!maybe_contents) {
      continue;
    }

    WithUncompressedMessageImpl("fragment", maybe_contents.value(),
                                [&] (capnp::MessageReader &reader) {
      auto fragment = reader.getRoot<mx::rpc::Fragment>();
      auto fragment_first_line = fragment.getFirstLine();
      auto fragment_last_line = fragment.getLastLine();
      if ((line_start >= fragment_first_line) && (line_end <= fragment_last_line)) {
        context->fragments_result.emplace(file_id, fragment_id);
      }
    });
  }

}

void SearchAction::QuerySyntaxInFile(mx::FileId file_id,
                                     const std::string &query) {

  // Get the contents of the file
  auto file_contents = GetFileContents(file_id);
  if (file_contents.empty()) {
    // Invalid file id. It is common and should
    // return for next file id scan
    return;
  }

  LOG(INFO) << "Looking for syntax matches in file with id " << file_id;

  auto matches = query_tree->FindMatches(file_contents, false);
  if (!matches) {
    LOG(ERROR) << "Failed to find matches in file with id " << file_id;
    return;
  }

  auto data = std::make_unique<mx::WeggliQueryData>();
  query_tree->IterateMatches(matches, data.get());

  // Destroy matches after iterating through them
  query_tree->DestroyMatches(matches);


  for (auto [start, end] : data->captures) {
    auto [start_line, end_line] = ConvertOffsetToLine(file_contents, start, end);
    GetFragmentMatches(file_id, start_line, end_line);
  }

  for (auto [name, start, end] : data->variables) {
    auto [start_line, end_line] = ConvertOffsetToLine(file_contents, start, end);
    GetFragmentMatches(file_id, start_line, end_line);
  }
}


SearchAction::~SearchAction(void) {}

SearchAction::SearchAction(
    std::shared_ptr<SearchingContext> context_,
    std::string_view syntax_)
    : context(std::move(context_)),
      syntax(syntax_){
  query_tree = std::make_shared<mx::WeggliQuery>(syntax);
}


void SearchAction::Run(mx::Executor exe, mx::WorkerId worker_id) {
  if (syntax.empty()) {
    LOG(ERROR) << "Empty syntax string, exiting without query!";
    return;
  }

  LOG(INFO) << "Querying for the syntax " << syntax
            << " worker id " << worker_id;

  if (!query_tree || !query_tree->IsValid()) {
    LOG(ERROR) << "Failed to create query tree for syntax " << syntax;
    return;
  }

  // Check if there is any file in the persistent map. If not
  // return here
  auto max_file_id = context->GetMaxFileId();
  if (!max_file_id) {
    LOG(ERROR) << "No file id found in the persistent map!";
    return;
  }

  LOG(INFO) << "Maximum number of file available for scan "
            << max_file_id.value();

  context->ForEachFile(
      syntax, [&](std::string syntax, mx::FileId id) {
    QuerySyntaxInFile(id, syntax);
  });
}

} // namespace indexer


