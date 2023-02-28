// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdlib>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <multiplier/Entities/CallExpr.h>
#include <multiplier/Entities/FunctionDecl.h>
#include <multiplier/Entities/MacroArgument.h>
#include <multiplier/Entities/MacroExpansion.h>
#include <multiplier/File.h>
#include <multiplier/Fragment.h>
#include <sstream>

#include "Index.h"

DECLARE_bool(help);

static bool IsDerivedFromTopLevelMacroArgument(mx::Token tok) {
  for (auto dt = tok.derived_token(); dt; dt = dt.derived_token()) {
    for (mx::MacroArgument arg : mx::MacroArgument::containing(dt)) {
      if (std::optional<mx::Macro> exp = arg.parent()) {
        return !exp->parent();
      }
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db file]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index index = InitExample(true);

  for (mx::CallExpr call : mx::CallExpr::in(index)) {

    std::optional<mx::FunctionDecl> called_func = call.direct_callee();
    if (called_func) {
      std::string_view func_name = called_func->name();
      if (func_name == "abort" || func_name == "__assert_rtn" ||
          func_name.starts_with("__builtin_")) {
        continue;
      }
    }

    for (mx::Token parsed_tok : call.tokens()) {

      // NOTE(pag): We don't want to find things like `memcpy(...)` where
      //            `memcpy` is the macro itself, expanding to something like
      //            `__builtin_memcpy_chk(...)`. Instead, we want to find
      //            `macro(... func(...) ...)`.
      //
      // NOTE(pag): This will skip things like `macro1(macro2(...))` where
      //            `macro2` expands to a call.
      if (!IsDerivedFromTopLevelMacroArgument(parsed_tok)) {
        goto next;
      }

      for (mx::MacroExpansion exp : mx::MacroExpansion::containing(parsed_tok)) {
        mx::TokenRange call_tokens = call.tokens().file_tokens();
        mx::Fragment fragment = mx::Fragment::containing(call);
        auto file = mx::File::containing(fragment);

        if (file) {
          std::cout << "Location: " << file_paths[file->id()].generic_string();
          if (auto tok = call_tokens[0]) {
            if (auto line_col = tok.location(location_cache)) {
              std::cout << ':' << line_col->first << ':' << line_col->second;
            }
          }
          std::cout << '\n';
        }

        if (file) {
          std::cout
              << "File ID: " << file->id() << '\n';
        }

        std::cout
            << "Frag ID: " << fragment.id()
            << "\nCall ID: " << call.id()
            << "\nExpansion ID: " << exp.id() << "\n";

        if (called_func) {
          std::cout
              << "Function ID: " << called_func->id()
              << "\nFunction name: " << called_func->name() << '\n';
        }

        RenderFragment(std::cout, fragment, call_tokens, "\t", true);
        std::cout << "\n\n";
        goto next;
      }
    }
  next:
    continue;
  }
}
