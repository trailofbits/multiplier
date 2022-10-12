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

DEFINE_uint64(fragment_id, 0, "ID of the fragment from which to print structures");
DEFINE_uint64(file_id, 0, "ID of the file from which to print structures");
DEFINE_bool(show_locations, false, "Show the file locations of the structures");

static void PrintStructures(mx::Fragment fragment) {
  for (mx::TagDecl tag : mx::TagDecl::in(fragment)) {
    if (!tag.is_definition()) {
      continue;
    }

    auto file = mx::File::containing(fragment);

    std::cout
        << file.id() << '\t'
        << fragment.id() << '\t' << tag.id() << '\t'
        << tag.name();

    if (FLAGS_show_locations) {
      std::cout << '\t' << file_paths[file.id()].generic_string();
      if (auto tok = tag.token()) {
        if (auto line_col = tok.location(location_cache)) {
          std::cout << '\t' << line_col->first << '\t' << line_col->second;
        }
      }
    }

    std::cout << '\n';

    for (const mx::Decl &decl : tag.declarations_in_context()) {
      if (auto field = mx::NamedDecl::from(decl)) {
        std::cout << "\t\t" << field->id() << '\t' << field->name();
        if (FLAGS_show_locations) {
          std::cout << '\t' << file_paths[file.id()].generic_string();
          if (auto tok = field->token()) {
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

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT] [--fragment_id ID | --file_id ID]\n";

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
    PrintStructures(std::move(*fragment));

  } else if (FLAGS_file_id) {
    auto file = index.file(FLAGS_file_id);
    if (!file) {
      std::cerr << "Invalid file id " << FLAGS_file_id << std::endl;
      return EXIT_FAILURE;
    }
    for (mx::Fragment fragment : mx::Fragment::in(*file)) {
      PrintStructures(std::move(fragment));
    }

  } else {
    for (mx::File file : mx::File::in(index)) {
      for (mx::Fragment fragment : mx::Fragment::in(file)) {
        PrintStructures(std::move(fragment));
      }
    }
  }

  return EXIT_SUCCESS;
}
