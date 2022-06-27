// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Lexer.h"

DECLARE_bool(help);
DEFINE_string(file, "", "Read query from file");
DEFINE_string(query, "", "Use argument value as query");

static void DumpTokens(lexer::Lexer& lexer) {
  for (;;) {
    auto token = lexer.Next();
    if (token.kind == lexer::TokenKind::EndFile)
      break;
    std::cout << "Span(" << token.span.begin << ", "
      << token.span.end << "), " << token.spelling << ", "
      << EnumeratorName(token.kind) << "\n";
  }
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT] [--fragment_id ID | --file_id ID]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  if (FLAGS_file != std::string("")) {
    auto stream = std::fstream(FLAGS_file);
    if (stream) {
      lexer::Lexer lexer(stream);
      DumpTokens(lexer);
    } else {
      std::cerr << "Failed to open file " << FLAGS_file << ": "
                << strerror(errno) << std::endl;
    }
  } else if (FLAGS_query != std::string("")) {
    auto stream = std::stringstream(FLAGS_query);
    lexer::Lexer lexer(stream);
    DumpTokens(lexer);
  } else {
    lexer::Lexer lexer(std::cin);
    DumpTokens(lexer);
  }

  return EXIT_SUCCESS;
}
