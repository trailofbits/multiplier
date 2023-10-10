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

DEFINE_string(function_name, "strchr", "Function other than strchr to test for sketchy reuse.");
DEFINE_uint32(argument_index, 0, "Index of the argument of the string haystack.");

using TaintMap = std::unordered_map<mx::PackedDeclId, std::vector<mx::CallExpr>>;

static std::optional<mx::FunctionDecl> StrchrEntityExists(
    const mx::Index &index) {

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

// TODO(pag): This is a band-aid fix to Issue #286.
static mx::PackedDeclId CanonicalId(mx::ValueDecl vd) {
  if (vd.kind() == mx::DeclKind::PARM_VAR) {
    return vd.id();
  } else {
    return vd.canonical_declaration().id();
  }
}

void TaintTrack(mx::FunctionDecl &func, TaintMap &map) {
  for (mx::CallExpr call : func.callers()) {
    std::optional<mx::Expr> haystack_arg =
        call.nth_argument(FLAGS_argument_index);
    if (!haystack_arg) {
      continue;
    }

    std::optional<mx::DeclRefExpr> ptr_arg =
        mx::DeclRefExpr::from(haystack_arg->ignore_casts());
    if (!ptr_arg) {
      continue;
    }

    map[CanonicalId(ptr_arg->declaration())].push_back(call);
  }
}

int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE]\n"
    << " [--function_name NAME (strchr)]\n"
    << " [--argument_index INDEX (0)]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample(true);

  std::optional<mx::FunctionDecl> func = StrchrEntityExists(index);
  if (!func) {
    std::cerr
        << "Could not find " << FLAGS_function_name
        << " entity in database." << std::endl;
    return EXIT_FAILURE;
  }

  TaintMap map;
  TaintTrack(*func, map);

  for (const auto &[decl_source_id, sinks] : map) {

    // Only care about matchings where strchr operates multiple times.
    if (sinks.size() < 2) {
      continue;
    }

    std::optional<mx::ValueDecl> source = mx::ValueDecl::by_id(
        index, decl_source_id);
    std::unordered_set<mx::RawEntityId> highlight_ids =
        FileTokenIdsFor(source->tokens());

    mx::Fragment fragment = mx::Fragment::containing(*source);
    auto file = mx::File::containing(fragment);

    std::cout
        << "Variable source (id: " << decl_source_id << "): '"
        << source->tokens().file_tokens().data()
        << "' propagates to " << sinks.size()
        << " calls to " << FLAGS_function_name << ":" << std::endl;

    for (const mx::CallExpr &sink : sinks) {

      std::unordered_set<mx::RawEntityId> sink_ids =
          FileTokenIdsFor(sink.tokens());
      highlight_ids.insert(sink_ids.begin(), sink_ids.end());

      std::cout
          << (file ? file->id().Pack() : mx::kInvalidEntityId) << '\t'
          << fragment.id() << '\t'
          << sink.id() << '\t'
          << sink.tokens().file_tokens().data()
          << std::endl;
    }

    RenderFragment(std::cout, mx::Fragment::containing(*source),
                   std::move(highlight_ids), "\t", true);

    std::cout << "\n\n";
  }

  return EXIT_SUCCESS;
}
