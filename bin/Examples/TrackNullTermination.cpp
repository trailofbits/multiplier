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

// Where to do a stop and determine if null-termination exists
static const std::unordered_map<std::string_view, unsigned int> kTaintSinks = {
  {"strlen", 0u},  
};

static void TrackPotentialSink(const mx::CallExpr call_expr) {
  std::optional<mx::FunctionDecl> func_decl = call_expr.direct_callee();
  if (!func_decl) {
    return;
  }

  std::string_view risky_call = func_decl->name();
  if (!kTaintSinks.contains(risky_call)) {
    return;
  }

  std::optional<mx::Expr> haystack_arg = call_expr.nth_argument(kTaintSinks.at(risky_call));
  if (!haystack_arg) {
    return;
  }


  std::optional<mx::DeclRefExpr> decl =
      mx::DeclRefExpr::from(haystack_arg->ignore_casts());
  if (!decl) {
    return;
  }

  // TODO: at this point generate a backward slice of the parameter
  std::cout << risky_call << " " << decl->tokens().data() << std::endl;
}


static void TrackNullTermination(mx::Fragment fragment) {
  for (mx::CallExpr call_expr : mx::CallExpr::in(fragment)) {
    TrackPotentialSink(call_expr);
  }
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

  mx::Index index = InitExample(true);

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
