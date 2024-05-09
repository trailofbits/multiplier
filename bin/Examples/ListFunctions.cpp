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

DEFINE_bool(list_variables, false, "Should we list the variables inside of functions?");
DEFINE_bool(show_locations, false, "Show the file locations of the functions?");

static void PrintFunctionNames(mx::Index index) {
  mx::QualifiedNameRenderOptions opts;

  for (mx::FunctionDecl func : mx::FunctionDecl::in(index)) {
    auto file = mx::File::containing(func);
    auto fragment = mx::Fragment::containing(func);
    auto qual_name = func.qualified_name(opts);
    std::cout
        << (file ? file->id().Pack() : mx::kInvalidEntityId) << '\t'
        << fragment.id() << '\t'
        << func.id() << '\t'
        << qual_name.data()
        << (func.is_definition() ? "\tdef" : "\tdecl");

    if (FLAGS_show_locations && file) {
      std::cout << '\t' << file_paths[file->id()].generic_string();
      if (auto tok = func.token()) {
        if (auto line_col = tok.location(location_cache)) {
          std::cout << '\t' << line_col->first << '\t' << line_col->second;
        }
      }
    }

    std::cout << '\n';

    if (FLAGS_list_variables) {
      for (const mx::Decl &var : func.contained_declarations()) {
        std::cout
            << "\t\t" << var.id() << '\t' << mx::EnumeratorName(var.kind());

        if (auto named_decl = mx::NamedDecl::from(var)) {
          std::cout << '\t' << named_decl->name();
        }

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
  }
}

int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE]\n"
    << " [--list_variables]\n"
    << " [--show_locations]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  PrintFunctionNames(InitExample(FLAGS_show_locations));

  return EXIT_SUCCESS;
}
