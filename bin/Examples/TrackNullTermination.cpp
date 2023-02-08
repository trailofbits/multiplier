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

DEFINE_uint64(fragment_id, 0, "ID of the fragment from which to print function names");
DEFINE_uint64(file_id, 0, "ID of the file from which to print function names");
DEFINE_bool(show_locations, false, "Show the file locations of the functions?");

struct LibraryModel {
  std::string_view func_name;
  unsigned arg_index;
};

// Which calls and arguments to taint track
static const LibraryModel kTaintSources[] = {
  {"read", 1u},
};

// Where to do a stop and determine if null-termination exists
static const LibraryModel kTaintSinks[] = {
  {"strlen", 0u},  
};

//
static void TaintFunctionArgument() {

}

static void NullTerminationCheck() {

}

static void TaintRiskyFunctions(const mx::Index &index) {

  std::vector<mx::FunctionDecl> found_decls;
  for (libraryModel source : kTaintSources) {
    for (mx::NamedEntity ne : index.query_entities(source.func_name)) {
      if (!std::holds_alternative<mx::NamedDecl>(ne)) {
        continue;
      }

      auto func = mx::FunctionDecl::from(std::get<mx::NamedDecl>(ne));
      if (func && func->name() == source.func_name) {
        found_decls.push_back(func);
      }
    }
  }
}


static void TrackNullTermination(mx::Fragment fragment) {
  
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] [--fragment_id ID | --file_id ID]"
    << " [--list_variables LIST_VARIABLES] [--show_locations SHOW_LOCATIONS]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample(FLAGS_show_locations);

  // Start by
  TaintRiskyFunctions(index);

  if (FLAGS_fragment_id) {
    auto fragment = index.fragment(FLAGS_fragment_id);
    if (!fragment) {
      std::cerr << "Invalid fragment id " << FLAGS_fragment_id << std::endl;
      return EXIT_FAILURE;
    }
    TrackNullTermination(std::move(*fragment));

  } else if (FLAGS_file_id) {
    auto file = index.file(FLAGS_file_id);
    if (!file) {
      std::cerr << "Invalid file id " << FLAGS_file_id << std::endl;
      return EXIT_FAILURE;
    }
    for (mx::Fragment fragment : file->fragments()) {
      TrackNullTermination(std::move(fragment));
    }

  } else {
    for (mx::File file : index.files()) {
      for (mx::Fragment fragment : file.fragments()) {
        TrackNullTermination(std::move(fragment));
      }
    }
  }

  return EXIT_SUCCESS;
}
