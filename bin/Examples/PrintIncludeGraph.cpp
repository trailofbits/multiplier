// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>

#include <map>
#include <set>
#include <utility>
#include <variant>

#include "Index.h"
#include <multiplier/AST.h>

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] --entity_id ID [--length N]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample(true);

  std::cout
      << "digraph {\n"
      << "  node [shape=record margin=0 nojustify=false labeljust=l font=courier];\n";

  for (mx::File file : index.files()) {
    mx::PackedFileId fid = file.id();
    std::cout
        << "f" << fid << " [label=\"" << file_paths[fid].generic_string()
        << "\"];\n";

    for (mx::MacroReference ref : file.references()) {
      auto inc = mx::IncludeLikeMacroDirective::from(ref.macro());
      if (!inc) {
        assert(false);
        continue;
      }

      auto containing_file = mx::File::containing(inc.value());
      if (!containing_file) {
        continue;
      }

      std::cout
          << "f" << containing_file->id()
          << " -> f" << fid
          << " [label=\"" << mx::EnumeratorName(inc->kind()) << "\"];\n";
    }
  }

  std::cout << "}\n";

  return EXIT_SUCCESS;
}
