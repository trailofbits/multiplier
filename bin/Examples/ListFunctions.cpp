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
DEFINE_uint64(fragment_id, 0, "ID of the fragment from which to print function names");
DEFINE_uint64(file_id, 0, "ID of the file from which to print function names");
DEFINE_bool(list_variables, false, "Should we list the variables inside of functions?");
DEFINE_bool(show_locations, false, "Show the file locations of the functions?");

std::unordered_map<mx::FileId, std::filesystem::path> file_paths;
mx::FileLocationCache location_cache;

static void PrintFunctionNames(mx::Fragment fragment) {
  for (mx::FunctionDecl func : mx::FunctionDecl::in(fragment)) {
    auto file = mx::File::containing(fragment);

    std::cout
        << file.id() << '\t'
        << fragment.id() << '\t' << func.id() << '\t'
        << (func.is_definition() ? "def\t" : "decl\t")
        << func.name();

    if (FLAGS_show_locations) {
      std::cout << '\t' << file_paths[file.id()].generic_string();
      if (auto tok = func.token()) {
        if (auto line_col = tok.location(location_cache)) {
          std::cout << '\t' << line_col->first << '\t' << line_col->second;
        }
      }
    }

    std::cout << '\n';

    if (FLAGS_list_variables) {
      for (const mx::Decl &var : func.declarations_in_context()) {
        std::cout
            << '\t' << var.id() << '\t' << mx::EnumeratorName(var.kind());

        if (auto named_decl = mx::NamedDecl::from(var)) {
          std::cout << '\t' << named_decl->name();
        }

        if (FLAGS_show_locations) {
          std::cout << '\t' << file_paths[file.id()].generic_string();
          if (auto tok = var.token()) {
            if (auto line_col = tok.location(location_cache)) {
              std::cout << '\t' << line_col->first << '\t' << line_col->second;
            }
          }
        }

        std::cout << '\n';
      }
      std::cout << '\n';
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

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index index(mx::EntityProvider::in_memory_cache(
      mx::EntityProvider::from_remote(
          FLAGS_host, FLAGS_port)));

  if (FLAGS_show_locations) {
    for (auto [path, id] : index.file_paths()) {
      file_paths.emplace(id, std::move(path));
    }
  }

  if (FLAGS_fragment_id) {
    auto fragment = index.fragment(FLAGS_fragment_id);
    if (!fragment) {
      std::cerr << "Invalid fragment id " << FLAGS_fragment_id << std::endl;
      return EXIT_FAILURE;
    }
    PrintFunctionNames(std::move(*fragment));

  } else if (FLAGS_file_id) {
    auto file = index.file(FLAGS_file_id);
    if (!file) {
      std::cerr << "Invalid file id " << FLAGS_file_id << std::endl;
      return EXIT_FAILURE;
    }
    for (mx::Fragment fragment : mx::Fragment::in(*file)) {
      PrintFunctionNames(std::move(fragment));
    }

  } else {
    for (mx::File file : mx::File::in(index)) {
      for (mx::Fragment fragment : mx::Fragment::in(file)) {
        PrintFunctionNames(std::move(fragment));
      }
    }
  }

  return EXIT_SUCCESS;
}
