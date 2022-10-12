// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdlib>
#include <filesystem>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <multiplier/Index.h>
#include <multiplier/Re2.h>
#include <fstream>
#include <sstream>

DECLARE_bool(help);
DECLARE_string(host);
DECLARE_string(port);
DEFINE_string(query, "", "Query pattern to be searched");
DEFINE_uint64(fragment_id, 0, "ID of the fragment in which to perform the search");

std::string GetFileContaining(mx::Index &index, mx::RawEntityId file_id) {
  for (auto [path, id] : index.file_paths()) {
    if (id == file_id) {
      return path.generic_string();
    }
  }
  return {};
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT] [--fragment_id ID]\n"
    << " --query QUERY_STRING";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (1 >= argc || FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  if (FLAGS_query.empty()) {
    std::cerr
        << "Must specify regular expression string to be searched for."
        << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index index(mx::EntityProvider::from_remote(
      FLAGS_host, FLAGS_port));

  mx::RegexQuery query(FLAGS_query);

  mx::RegexQueryResult results;

  // Query a specific fragment.
  if (FLAGS_fragment_id) {
    auto fragment = index.fragment(FLAGS_fragment_id);
    if (!fragment) {
      std::cerr << "Invalid fragment id " << FLAGS_fragment_id << std::endl;
      return EXIT_FAILURE;
    }

    results = fragment->query(query);
  
  // Query the whole index.
  } else {
    results = index.query_fragments(query);
  }

  for (const mx::RegexQueryMatch &match : results) {
    mx::Fragment frag = mx::Fragment::containing(match);
    mx::File file = mx::File::containing(frag);
    std::cout
        << frag.id() << '\t' << GetFileContaining(index, file.id())
        << std::endl;

    for (size_t i = 0u, max_i = match.num_captures(); i < max_i; ++i) {
      if (auto data = match.captured_data(i)) {
        std::cout << "\t[" << i << "] = \t" << *data << '\n';
      }
    }

    std::cout << "\n\n";
  }

  return EXIT_SUCCESS;
}
