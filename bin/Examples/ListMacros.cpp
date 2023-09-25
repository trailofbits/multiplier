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

DEFINE_bool(show_locations, false, "Show the file locations of the macros?");

static void PrintMacroNames(mx::Index index) {
  for (mx::DefineMacroDirective macro : mx::DefineMacroDirective::in(index)) {
    auto file = mx::File::containing(macro);
    auto fragment = mx::Fragment::containing(macro);

    std::cout
        << (file ? file->id().Pack() : mx::kInvalidEntityId) << '\t'
        << fragment.id() << '\t'
        << macro.id() << '\t'
        << macro.name().data();

    if (FLAGS_show_locations && file) {
      std::cout << '\t' << file_paths[file->id()].generic_string();
      if (auto tok = macro.name()) {
        if (auto line_col = tok.location(location_cache)) {
          std::cout << '\t' << line_col->first << '\t' << line_col->second;
        }
      }
    }

    std::cout << '\n';
  }
}

int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE]\n"
    << " [--show_locations]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  PrintMacroNames(InitExample(FLAGS_show_locations));
  return EXIT_SUCCESS;
}
