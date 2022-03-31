// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdlib>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <multiplier/API.h>
#include <sstream>

DECLARE_bool(help);
DEFINE_string(host, "localhost", "Hostname of mx-server. Use 'unix' for a UNIX domain socket.");
DEFINE_string(port, "50051", "Port of mx-server. Use a path and 'unix' for the host for a UNIX domain socket.");
DEFINE_uint64(fragment_id, 0, "ID of the fragment to print");

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT] --fragment_id ID\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index index(mx::EntityProvider::from_remote(
      FLAGS_host, FLAGS_port));
  auto fragment = index.fragment(FLAGS_fragment_id);
  if (!fragment) {
    std::cerr << "Invalid fragment id " << FLAGS_fragment_id << std::endl;
    return EXIT_FAILURE;
  }

  for (mx::Token token : mx::Token::in(*fragment)) {
    for (mx::DeclRefExpr expr : mx::DeclRefExpr::containing(token)) {
      mx::ValueDecl used_decl = expr.declaration();
      if (auto var = mx::VarDecl::from(used_decl)) {
        std::cout << token.data() << "\tvar\t" << var->name() << std::endl;

      } else if (auto func = mx::FunctionDecl::from(used_decl)) {
        std::cout << token.data() << "\tfunc\t" << func->name() << std::endl;

      } else if (auto field = mx::FieldDecl::from(used_decl)) {
        std::cout << token.data() << "\tfield\t" << field->name() << std::endl;

      } else {
        std::cout << token.data() << "\tother\t" << used_decl.name() << std::endl;
      }
    }
  }

  return EXIT_SUCCESS;
}
