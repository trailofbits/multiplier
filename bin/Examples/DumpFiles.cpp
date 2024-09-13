// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdlib>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <fstream>
#include <iostream>
#include <multiplier/Index.h>
#include <sstream>

DECLARE_bool(help);
DECLARE_string(db);
DEFINE_string(output_dir, "", "Directory into which all indexed source files will be saved");

int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " --db DATABASE --output_dir DIR\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  if (FLAGS_output_dir.empty()) {
    std::cerr << "--output_dir cannot be empty.\n";
    return EXIT_FAILURE;
  }

  std::filesystem::path output_dir(FLAGS_output_dir);
  if (!std::filesystem::is_directory(output_dir)) {
    std::cerr << "Output directory " << output_dir
              << " doesn't exist or isn't a directory.\n";
    return EXIT_FAILURE;
  }

  mx::Index index(mx::Index::from_database(FLAGS_db));
  for (mx::File file : index.files()) {
    for (std::filesystem::path path : file.paths()) {
      auto file_name = std::to_string(file.id().Pack()) + "_" +
                       path.filename().generic_string();

      std::filesystem::path new_path = output_dir / file_name;
      std::ofstream dumper(new_path);
      dumper << file.data();
      break;
    }
  }

  return EXIT_SUCCESS;
}
