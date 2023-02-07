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

#define TARGET "strchr"

DEFINE_uint64(fragment_id, 0, "ID of the fragment to check for sketch strchr usage");
DEFINE_uint64(file_id, 0, "ID of the file to check for sketch strchr usage");
DEFINE_bool(show_locations, false, "Show the file locations of the functions?");

using TaintPair = std::pair<mx::PackedDeclId, std::vector<mx::PackedStmtId>>;
using TaintMap = std::unordered_map<mx::PackedDeclId, std::vector<mx::PackedStmtId>>;

// TODO: remove if we don't care about fragment granularity of searches
static void FindSketchyStrchr(mx::Fragment fragment) {
  for (mx::FunctionDecl func : mx::FunctionDecl::in(fragment)) {
    auto file = mx::File::containing(fragment);

    std::cout
        << (file ? file->id().Pack() : mx::kInvalidEntityId) << '\t'
        << fragment.id() << '\t'
        << func.id() << '\t'
        << func.name()
        << (func.is_definition() ? "\tdef" : "\tdecl");

    if (FLAGS_show_locations && file) {
      std::cout << '\t' << file_paths[file->id()].generic_string();
      if (auto tok = func.token()) {
        if (auto line_col = tok.location(location_cache)) {
          std::cout << '\t' << line_col->first << '\t' << line_col->second;
        }
      }
    }

    std::cout << '\n';

    /*
    if (FLAGS_list_variables) {
      for (const mx::Decl &var : func.declarations_in_context()) {
        std::cout
            << "\t\t" << var.id() << '\t' << mx::EnumeratorName(var.kind());

        if (auto named_decl = mx::NamedDecl::from(var)) {
          std::cout << '\t' << named_decl->name();
        }

        if (FLAGS_show_locations && file) {
          std::cout << '\t' << file_paths[file->id()].generic_string();
          if (auto tok = var.token()) {
            if (auto line_col = tok.location(location_cache)) {
              std::cout << '\t' << line_col->first << '\t' << line_col->second;
            }
          }
        }

        std::cout << '\n';
      }
    }
    */
  }
}

static std::optional<mx::FunctionDecl> StrchrEntityExists(const mx::Index &index) {
    for (mx::NamedEntity ne : index.query_entities(TARGET)) {
        if (!std::holds_alternative<mx::NamedDecl>(ne)) {
            continue;
        }

        auto func = mx::FunctionDecl::from(std::get<mx::NamedDecl>(ne));
        if (!func || func->name() != TARGET) {
            continue;
        }
        return func;
    }
    return std::nullopt;
}

void TaintTrack(const mx::FunctionDecl &strchr, TaintMap &map) {
    for (mx::Reference ref : strchr.references()) {
        auto taint_source = ref.as_statement();
        for (mx::CallExpr call : mx::CallExpr::containing(*taint_source)) {
            
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
            mx::PackedDeclId decl_source_id = decl_source.id();

            // check if strchr argument has the originating source used by another strchr
            if (map.contains(decl_source_id)) {
              map[decl_source_id].push_back(call.id());
            } else {
              map.insert(std::make_pair(decl_source_id, std::vector<mx::PackedStmtId>()));
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
      std::cerr << "Could not find " << TARGET << " entity in database." << std::endl;
      return EXIT_FAILURE;
  }

  TaintMap map;
  TaintTrack(*func, map);

  for (const auto& [decl_source_id, sinks] : map) {

    // unless specified, only care about matchings where strchr operates multiple times
    if (sinks.size() != 2) {
      continue;
    }

    auto source = index.entity(decl_source_id);
    std::cout << "Variable source (id: " << decl_source_id << "): " << source->tokens().data()
      << " propagates to " << sinks.size() << " calls to strchr:" << std::endl;


    for (const auto& sink_id : sinks) {
        auto sink = index.entity(sink_id);
        std::cout << "\t" << sink_id << " " << sink->tokens().data() << std::endl;
    }
  }

  /*
  if (FLAGS_fragment_id) {
    auto fragment = index.fragment(FLAGS_fragment_id);
    if (!fragment) {
      std::cerr << "Invalid fragment id " << FLAGS_fragment_id << std::endl;
      return EXIT_FAILURE;
    }
    FindSketchyStrchr(std::move(*fragment));

  } else if (FLAGS_file_id) {
    auto file = index.file(FLAGS_file_id);
    if (!file) {
      std::cerr << "Invalid file id " << FLAGS_file_id << std::endl;
      return EXIT_FAILURE;
    }
    for (mx::Fragment fragment : file->fragments()) {
      FindSketchyStrchr(std::move(fragment));
    }

  } else {
    for (mx::File file : index.files()) {
      for (mx::Fragment fragment : file.fragments()) {
        FindSketchyStrchr(std::move(fragment));
      }
    }
  }
  */

  return EXIT_SUCCESS;
}
