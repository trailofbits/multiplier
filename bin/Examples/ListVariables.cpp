// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdlib>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <multiplier/AST/VarDecl.h>
#include <sstream>
#include <unordered_map>

#include "Index.h"

DECLARE_bool(help);
DEFINE_uint64(fragment_id, 0, "ID of the fragment from which to print variable names");
DEFINE_uint64(file_id, 0, "ID of the file from which to print variable names");
DEFINE_bool(show_locations, false, "Show the file locations of the variable?");

static void PrintVariableNames(mx::Index index) {
  mx::QualifiedNameRenderOptions opts;

  for (mx::VarDecl var : mx::VarDecl::in(index)) {
    auto fragment = mx::Fragment::containing(var);
    auto file = mx::File::containing(fragment);

    std::cout
        << (file ? file->id().Pack() : mx::kInvalidEntityId) << '\t'
        << fragment.id().Pack() << '\t'
        << var.id().Pack() << '\t'
        << var.qualified_name(opts).data()
        << (var.is_definition() ? "\tdef" : "\tdecl");

    if (FLAGS_show_locations && file) {
      std::cout << '\t' << file_paths[file->id()].generic_string();
      if (auto tok = var.token()) {
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
    << " [--show_locations SHOW_LOCATIONS]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  PrintVariableNames(InitExample(FLAGS_show_locations));
  return EXIT_SUCCESS;
}
