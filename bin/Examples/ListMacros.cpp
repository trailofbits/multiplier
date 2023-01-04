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

DEFINE_uint64(fragment_id, 0, "ID of the fragment from which to print macro names");
DEFINE_uint64(file_id, 0, "ID of the file from which to print macro names");
DEFINE_bool(show_locations, false, "Show the file locations of the macros?");

static void PrintMacroNames(mx::Fragment fragment) {
  for (mx::DefineMacroDirective macro : mx::DefineMacroDirective::in(fragment)) {
    auto file = mx::File::containing(fragment);

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

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] [--fragment_id ID | --file_id ID]"
    << " [--show_locations SHOW_LOCATIONS]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample(FLAGS_show_locations);

  if (FLAGS_fragment_id) {
    auto fragment = index.fragment(FLAGS_fragment_id);
    if (!fragment) {
      std::cerr << "Invalid fragment id " << FLAGS_fragment_id << std::endl;
      return EXIT_FAILURE;
    }
    PrintMacroNames(std::move(*fragment));

  } else if (FLAGS_file_id) {
    auto file = index.file(FLAGS_file_id);
    if (!file) {
      std::cerr << "Invalid file id " << FLAGS_file_id << std::endl;
      return EXIT_FAILURE;
    }
    for (mx::Fragment fragment : file->fragments()) {
      PrintMacroNames(std::move(fragment));
    }

  } else {
    for (mx::File file : index.files()) {
      for (mx::Fragment fragment : file.fragments()) {
        PrintMacroNames(std::move(fragment));
      }
    }
  }

  return EXIT_SUCCESS;
}
