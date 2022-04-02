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

void SearchAction::FillFileContents(mx::FileId file_id) {

  file_contents.clear();
  auto maybe_contents = context->GetSerializedFile(file_id);
  if (!maybe_contents) {
    return;  // Bad file ID. This is expected for the way we get them.
  }

  file_contents.reserve(maybe_contents->size());

  WithUncompressedMessageImpl(
      "file", maybe_contents.value(),
      [this] (capnp::MessageReader &reader) {
    auto file = reader.getRoot<mx::rpc::File>();
    for (auto tokens : file.getTokens()) {
      capnp::Text::Reader data_reader = tokens.getData();
      auto tok_begin = data_reader.cStr();
      auto tok_end = &(tok_begin[data_reader.size()]);
      file_contents.insert(file_contents.end(), tok_begin, tok_end);
    }
  });
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

void SearchAction::QuerySyntaxInFile(mx::FileId file_id) {

  // Get the contents of the file
  FillFileContents(file_id);
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

  // Create an upper-bounding map of byte offsets to line numbers.
  eol_offset_to_line_num.clear();
  auto line = 1;
  auto offset = 0;
  for (auto ch : file_contents) {
    ++offset;
    if ('\n' == ch) {
      eol_offset_to_line_num.emplace(offset, line);
      ++line;
    }
  }

  auto end_it = eol_offset_to_line_num.end();

  for (auto [start, end] : data->captures) {
    auto start_line_it = eol_offset_to_line_num.upper_bound(start);
    auto end_line_it = eol_offset_to_line_num.upper_bound(end);
    if (start_line_it != end_it && end_line_it != end_it) {
      GetFragmentMatches(file_id, start_line_it->second, end_line_it->second);
    }
  }

  for (auto [name, start, end] : data->variables) {
    auto start_line_it = eol_offset_to_line_num.upper_bound(start);
    auto end_line_it = eol_offset_to_line_num.upper_bound(end);
    if (start_line_it != end_it && end_line_it != end_it) {
      GetFragmentMatches(file_id, start_line_it->second, end_line_it->second);
    }
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

void SearchAction::Run(mx::Executor, mx::WorkerId) {
  if (syntax.empty()) {
    LOG(ERROR) << "Empty syntax string, exiting without query!";
    return;
  }

  if (!query_tree || !query_tree->IsValid()) {
    LOG(ERROR) << "Failed to create query tree for syntax " << syntax;
    return;
  }

  while (true) {
    mx::FileId file_id = context->local_next_file_id.fetch_add(1ull);
    if (file_id >= context->server_context.next_file_id.load()) {
      break;
    }
    QuerySyntaxInFile(file_id);
  }
}

} // namespace indexer


