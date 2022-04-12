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
#include <multiplier/API.h>
#include <fstream>
#include <sstream>

DECLARE_bool(help);
DEFINE_string(host, "localhost", "Hostname of mx-server. Use 'unix' for a UNIX domain socket.");
DEFINE_string(port, "50051", "Port of mx-server. Use a path and 'unix' for the host for a UNIX domain socket.");
DEFINE_string(regex, "", "Query pattern to be searched");

static void PrintUnparsedTokens(mx::TokenSubstitutionList nodes) {
  for (auto node : nodes) {
    if (std::holds_alternative<mx::Token>(node)) {
      auto tok = std::get<mx::Token>(node);
      std::cout << tok.data();
    } else {
      auto sub = std::get<mx::TokenSubstitution>(node);
      PrintUnparsedTokens(sub.before());
    }
  }
}

std::string GetFileContaining(mx::Index &index, mx::FileId file_id) {
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
    << " [--host HOST] [--port PORT]\n"
    << " --query QUERY_STRING";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);


  if (1 >= argc || FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  if (FLAGS_regex.empty()) {
    std::cerr
        << "Must specify regular expression string to be searched for.";
    return EXIT_FAILURE;
  }

  mx::Index index(mx::EntityProvider::from_remote(
      FLAGS_host, FLAGS_port));

  for (mx::SyntaxQueryMatch match : index.regex_query(FLAGS_regex)) {
    mx::Fragment frag = mx::Fragment::containing(match);
    mx::File file = mx::File::containing(frag);
    auto sep = "\t";
    std::cout << frag.id() << sep << GetFileContaining(index, file.id())
        << ":" << frag.first_line() << "\n";

    PrintUnparsedTokens(frag.unparsed_tokens());
    std::cout << "\n\n";
  }
  return EXIT_SUCCESS;
}


