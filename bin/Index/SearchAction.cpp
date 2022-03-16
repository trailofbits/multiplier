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
#include "Util.h"

namespace indexer {

#define WeggliIterMatchCaptures   weggli_iter_match_captures
#define WeggliIterMatchVariables  weggli_iter_match_variables
#define WeggliIterMatches         weggli_iter_matches
#define WeggliNewQuery            weggli_new_query
#define WeggliDestroyQuery        weggli_destroy_query
#define WeggliMatches             weggli_matches
#define WeggliDestroyMatches      weggli_destroy_matches

namespace {

struct ScanData {
 public:
  // File ID
  mx::FileId file_id;

  // raw offset of the query matches captured by weggli
  std::vector<std::tuple<size_t, size_t>> capture_offset;

  // raw offset of the variable match capture by weggli
  std::vector<std::tuple<std::string, size_t, size_t>> variable_offset;
};


// The callback function gets called on seeing a match
bool SearchCapturesHandler(size_t start, size_t end, void *userdata) {
  auto data = static_cast<ScanData*>(userdata);
  if (data == nullptr){
    LOG(ERROR) << "SearchCapturesHandler: userdata not provided!";
    return true;
  }
  data->capture_offset.emplace_back(start, end);
  return true;
}

// The callback function gets called on seeing a variable match
bool SearchVariableHandler(const char *name, size_t start, size_t end, void *userdata) {
  auto data = static_cast<ScanData*>(userdata);
  if (data == nullptr){
    LOG(ERROR) << "SearchVariableHandler: userdata not provided!";
    return true;
  }

  data->variable_offset.emplace_back(std::string(name), start, end);
  return true;
}

bool SearchMatchHandler(const QueryResult *result, void *userdata) {
  WeggliIterMatchCaptures(result, SearchCapturesHandler, userdata);
  std::cerr << "====== Finished raw captures ======\n";
  WeggliIterMatchVariables(result, SearchVariableHandler, userdata);
  std::cerr << "====== Finished variable captures ======\n";
  return true;
}

} // namespace

std::string SearchAction::GetFileContents(mx::FileId file_id) {
  std::string file_contents;

  auto maybe_contents = context->GetSerializedFile(file_id);
  if (!maybe_contents) {
    // Its possible that the file_id is invalid and does not
    // have contents. return empty string in such case.
    return {};
  }

#if 0
  capnp::FlatArrayMessageReader reader(maybe_contents.value());
  auto file = reader.getRoot<mx::rpc::File>();
  for (auto tokens : file.getTokens()) {
    capnp::Text::Reader data_reader = tokens.getData();
    file_contents += std::string(data_reader.cStr());
  }

#endif
  return maybe_contents.value();
}

void SearchAction::QueryStringFromFile(mx::FileId file_id,
                                       const std::string &query) {
  if (query.empty() || file_id == 0) {
    LOG(ERROR) << "Failed to query string! empty query string or file_id\n"
               << "query_string: " << query << " file id: " << file_id;
    return;
  }

  // Get contents from file id
  auto file = GetFileContents(file_id);

  // Create a new weggli query from the query string. The query
  // string passed should be null terminated
  QueryTree *qtree = WeggliNewQuery(query.c_str(), false);
  if (qtree == nullptr) {
    LOG(ERROR) << "Failed to create new query tree for the query "
                  "string : "<< query;
    return;
  }

  // Get the matches for the new query created; The source provided
  // should be null terminated string
  QueryResults *results = WeggliMatches(qtree, file.c_str(), false);
  if (results == nullptr) {
    LOG(ERROR) << "Failed to get matches for the query string : " << query;
    return;
  }

  auto data = std::make_unique<ScanData>();
  WeggliIterMatches(results, SearchMatchHandler, static_cast<void*>(data.get()));

  for (auto &[start, end] : data->capture_offset) {
    auto [start_line, end_line] = ConvertOffsetToLine(file, start, end);
    GetFragmentMatchesFromFile(file_id, start_line, end_line);
  }

  for (auto &[name, start, end] : data->variable_offset) {
    auto [start_line, end_line] = ConvertOffsetToLine(file, start, end);
    GetFragmentMatchesFromFile(file_id, start_line, end_line);
  }

  WeggliDestroyMatches(results);
  WeggliDestroyQuery(qtree);
}


SearchAction::~SearchAction(void) {}

SearchAction::SearchAction(
    std::shared_ptr<SearchingContext> context_,
    pasta::FileManager file_manager_,
    std::string_view query_string_)
    : context(std::move(context_)),
      file_manager(std::move(file_manager_)),
      query_string(query_string_){}


void SearchAction::Run(mx::Executor exe, mx::WorkerId worker_id) {
  if (query_string.empty()) {
    LOG(ERROR) << "Empty query string. Don't search";
    return;
  }

  LOG(ERROR) << "Query string to be searched " << query_string
             << " worker id " << worker_id;


  // Check if there is any file in the persistent map. If not
  // return here
  auto max_file_id = context->GetMaxFileId();
  if (!max_file_id) {
    LOG(ERROR) << "No file available for query!";
    return;
  }

  LOG(ERROR) << "Maximum number of file available for scan " << max_file_id.value();


  // Get next file id to scan
  auto [file_id, is_valid] = context->GetNextFileId();
  while (file_id > 0 && is_valid) {

    // Query string to a file
    QueryStringFromFile(file_id, query_string);

    auto next_file = context->GetNextFileId();
    file_id = next_file.first;
    is_valid = next_file.second;
  }

}

std::pair<int32_t, int32_t> SearchAction::ConvertOffsetToLine(
    const std::string &file, size_t start, size_t end) {

  int32_t line_start = -1;
  int32_t line_end = -1;

  std::istringstream input{file};
  size_t start_index = input.tellg();

  auto counter = 0u;
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

void SearchAction::GetFragmentMatchesFromFile(
    mx::FileId file_id, size_t line_start, size_t line_end) {

  auto maybe_contents = context->GetSerializedFile(file_id);
  if (!maybe_contents) {
    return;
  }

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
#if 0

    capnp::Data::Reader reader(reinterpret_cast<const capnp::byte *>(
        maybe_contents.value().data()), maybe_contents.value().size());

    //capnp::FlatArrayMessageReader reader(maybe_contents.value());
    auto fragment = reader.getRoot<mx::rpc::Fragment>();
    auto fragment_first_line = fragment.getFirstLine();
    auto fragment_last_line = fragment.getLastLine();

    if ((line_start >= fragment_first_line) && (line_end <= fragment_last_line)) {
      context->fragments_result.emplace(file_id, fragment_id);
    }
#endif
  }

}

} // namespace indexer


