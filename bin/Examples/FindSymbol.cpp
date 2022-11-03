// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.


#include <gflags/gflags.h>
#include <glog/logging.h>
#include <sstream>

#include "Index.h"
#include <multiplier/AST.h>

DECLARE_bool(help);
DECLARE_string(db);
DEFINE_string(name, "", "Search for the symbol with name");

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] --name SYMBOL_NAME";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (1 >= argc || FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  if (FLAGS_name.empty()) {
    std::cerr
        << "Must specify symbol name to be searched for."
        << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index index(mx::EntityProvider::from_database(FLAGS_db));

  for (auto category : mx::EnumerationRange<mx::DeclCategory>()) {
    auto symbols = index.query_entities(FLAGS_name, category);
    for (const mx::NamedDecl &decl : symbols) {
      std::cout << decl.id() << '\t' << decl.name() << std::endl;
    }
  }

  return EXIT_SUCCESS;
}

