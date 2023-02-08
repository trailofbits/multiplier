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

DEFINE_bool(show_locations, false, "Show the file locations of the functions?");
DEFINE_string(function_name, "strchr", "Function other than strchr to test for sketchy reuse.");

using TaintMap = std::unordered_map<mx::PackedDeclId, std::vector<mx::CallExpr>>;

static std::optional<mx::FunctionDecl> StrchrEntityExists(const mx::Index &index) {
  for (mx::NamedEntity ne : index.query_entities(FLAGS_function_name)) {
    if (!std::holds_alternative<mx::NamedDecl>(ne)) {
      continue;
    }

    auto func = mx::FunctionDecl::from(std::get<mx::NamedDecl>(ne));
    if (func && func->name() == FLAGS_function_name) {
      return func;
    }
  }
  return std::nullopt;
}

void TaintTrack(const mx::FunctionDecl &func, TaintMap &map) {
  for (mx::Reference ref : func.references()) {
    auto taint_source = ref.as_statement();
    for (mx::CallExpr call : mx::CallExpr::containing(*taint_source)) {
      if (auto orig_decl = call.direct_callee()) {
        
        std::optional<mx::Expr> first_arg = call.nth_argument(0);
        if (!first_arg) {
          continue;
        }

        std::optional<mx::DeclRefExpr> ptr_arg = mx::DeclRefExpr::from(first_arg->ignore_casts());
        if (!ptr_arg) {
          continue;
        }

        // originating declaration source (parameter or variable declaration)
        mx::ValueDecl decl_source = ptr_arg->declaration();
        mx::PackedDeclId decl_source_id = decl_source.canonical_declaration().id();

        // save instances of the strchr call corresponding to the original declaration
        map[decl_source_id].push_back(call);
      }
    }
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

  std::optional<mx::FunctionDecl> func = StrchrEntityExists(index);
  if (!func) {
      std::cerr << "Could not find " << FLAGS_function_name << " entity in database." << std::endl;
      return EXIT_FAILURE;
  }

  TaintMap map;
  TaintTrack(*func, map);

  for (const auto& [decl_source_id, sinks] : map) {

    // unless specified, only care about matchings where strchr operates multiple times
    if (sinks.size() < 2) {
      continue;
    }

    auto source = index.entity(decl_source_id);
    std::cout << "Variable source (id: " << decl_source_id << "): '" << source->tokens().file_tokens().data()
      << "' propagates to " << sinks.size() << " calls to strchr:" << std::endl;


    for (const auto& sink : sinks) {
        std::cout << "\t" << sink.id() << " " << sink.tokens().file_tokens().data() << std::endl;
    }
  }

  return EXIT_SUCCESS;
}
