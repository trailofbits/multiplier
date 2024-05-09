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

DEFINE_bool(show_locations, false, "Show the file locations of the structures");

static void PrintStructures(mx::Index index) {
  mx::QualifiedNameRenderOptions opts;

  for (mx::TagDecl tag : mx::TagDecl::in(index)) {
    if (!tag.is_definition()) {
      continue;
    }

    auto fragment = mx::Fragment::containing(tag);
    auto file = mx::File::containing(fragment);

    std::cout
        << (file ? file->id().Pack() : mx::kInvalidEntityId) << '\t'
        << fragment.id().Pack() << '\t' << tag.id() << '\t'
        << tag.qualified_name(opts).data();

    if (FLAGS_show_locations && file) {
      std::cout << '\t' << file_paths[file->id()].generic_string();
      if (auto tok = tag.token()) {
        if (auto line_col = tok.location(location_cache)) {
          std::cout << '\t' << line_col->first << '\t' << line_col->second;
        }
      }
    }

    std::cout << '\n';

    for (const mx::Decl &decl : tag.contained_declarations()) {
      if (auto field = mx::NamedDecl::from(decl)) {
        std::cout << "\t\t" << field->id() << '\t' << field->name();
        if (FLAGS_show_locations && file) {
          std::cout << '\t' << file_paths[file->id()].generic_string();
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

int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  PrintStructures(InitExample(FLAGS_show_locations));
  return EXIT_SUCCESS;
}
