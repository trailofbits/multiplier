// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdlib>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <multiplier/Index.h>
#include <sstream>

DECLARE_bool(help);
DEFINE_string(host, "localhost", "Hostname of mx-server. Use 'unix' for a UNIX domain socket.");
DEFINE_string(port, "50051", "Port of mx-server. Use a path and 'unix' for the host for a UNIX domain socket.");
DEFINE_uint64(declaration_id, 0, "ID of the declaration to print the redeclarations of");
DEFINE_bool(show_locations, false, "Show the file locations of the redeclarations");

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT] --declaration_id ID\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index index(mx::EntityProvider::from_remote(
      FLAGS_host, FLAGS_port));


  std::unordered_map<mx::FileId, std::filesystem::path> file_paths;
  mx::FileLocationCache location_cache;

  if (FLAGS_show_locations) {
    for (auto [path, id] : index.file_paths()) {
      file_paths.emplace(id, std::move(path));
    }
  }

  auto maybe_decl = index.entity(FLAGS_declaration_id);
  if (!std::holds_alternative<mx::Decl>(maybe_decl)) {
    std::cerr << "Invalid declaration id " << FLAGS_declaration_id << std::endl;
    return EXIT_FAILURE;
  }

  mx::Decl decl = std::get<mx::Decl>(maybe_decl);
  for (mx::Decl redecl : decl.redeclarations()) {
    mx::Fragment fragment = mx::Fragment::containing(redecl);
    mx::File file = mx::File::containing(fragment);

    std::cout
        << file.id() << '\t'
        << fragment.id() << '\t'
        << redecl.id() << '\t'
        << (redecl.is_definition() ? "def\t" : "decl\t")
        << mx::EnumeratorName(redecl.kind());

    if (auto named_redecl = mx::NamedDecl::from(redecl)) {
      std::cout << '\t' << named_redecl->name();
    }

    if (FLAGS_show_locations) {
      std::cout << '\t' << file_paths[file.id()].generic_string();
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
