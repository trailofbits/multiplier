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
DEFINE_bool(exact, false, "Should we match exactly the specified name?");

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

  mx::Index index(mx::Index::in_memory_cache(
      mx::Index::from_database(FLAGS_db)));

  for (const mx::NamedEntity &ent : index.query_entities(FLAGS_name)) {
    if (std::holds_alternative<mx::NamedDecl>(ent)) {
      mx::NamedDecl decl = std::get<mx::NamedDecl>(ent);
      if (FLAGS_exact && decl.name() != FLAGS_name) {
        continue;
      }

      mx::Fragment frag = mx::Fragment::containing(decl);

      std::optional<mx::File> file = mx::File::containing(frag);
      std::cout
          << (file ? file->id().Pack() : mx::kInvalidEntityId) << '\t'
          << frag.id() << '\t'
          << decl.id() << '\t' << decl.name() << '\t'
          << mx::EnumeratorName(decl.kind()) << std::endl;

    } else if (std::holds_alternative<mx::DefineMacroDirective>(ent)) {
      mx::DefineMacroDirective macro = std::get<mx::DefineMacroDirective>(ent);
      if (FLAGS_exact && macro.name().data() != FLAGS_name) {
        continue;
      }

      mx::Fragment frag = mx::Fragment::containing(macro);
      std::optional<mx::File> file = mx::File::containing(frag);
      std::cout
            << (file ? file->id().Pack() : mx::kInvalidEntityId) << '\t'
            << frag.id() << '\t'
            << macro.id() << '\t' << macro.name().data() << '\t'
            << mx::EnumeratorName(macro.kind()) << std::endl;

    }
  }

  return EXIT_SUCCESS;
}

