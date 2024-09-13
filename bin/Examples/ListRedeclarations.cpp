// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <sstream>

#include "Index.h"
#include <multiplier/AST.h>

DEFINE_uint64(declaration_id, 0, "ID of the declaration to print the redeclarations of");
DEFINE_bool(show_locations, false, "Show the file locations of the redeclarations");

int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] --declaration_id ID\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample(FLAGS_show_locations);

  auto maybe_decl = index.entity(FLAGS_declaration_id);
  if (!std::holds_alternative<mx::Decl>(maybe_decl)) {
    std::cerr << "Invalid declaration id " << FLAGS_declaration_id << std::endl;
    return EXIT_FAILURE;
  }

  mx::Decl decl = std::get<mx::Decl>(maybe_decl);
  for (mx::Decl redecl : decl.redeclarations()) {
    mx::Fragment fragment = mx::Fragment::containing(redecl);
    auto file = mx::File::containing(fragment);

    std::cout
        << (file ? file->id().Pack() : mx::kInvalidEntityId) << '\t'
        << fragment.id() << '\t'
        << redecl.id() << '\t'
        << (redecl.is_definition() ? "def\t" : "decl\t")
        << mx::EnumeratorName(redecl.kind());

    if (auto named_redecl = mx::NamedDecl::from(redecl)) {
      std::cout << '\t' << named_redecl->name();
    }

    if (FLAGS_show_locations && file) {
      std::cout << '\t' << file_paths[file->id()].generic_string();
      if (auto tok = redecl.token()) {
        if (auto line_col = tok.location(location_cache)) {
          std::cout << '\t' << line_col->first << '\t' << line_col->second;
        }
      }
    }

    std::cout << '\n';
  }

  return EXIT_SUCCESS;
}
