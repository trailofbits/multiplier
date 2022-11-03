// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>

#include "Index.h"
#include <multiplier/AST.h>

DEFINE_uint64(entity_id, 0, "ID of the entity to print the uses of");
DEFINE_bool(show_locations, false, "Show the locations of users?");
DEFINE_bool(highlight_user, false, "Should we print the fragment with the user highlighted?");

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] --entity_id ID"
    << " [--show_locations SHOW_LOCATIONS] [--highlight_user HIGHLIGHT_USER]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample(FLAGS_show_locations);

  auto maybe_entity = index.entity(FLAGS_entity_id);
  if (std::holds_alternative<mx::Decl>(maybe_entity)) {
    mx::Decl decl = std::get<mx::Decl>(maybe_entity);

    for (const mx::DeclUse &use : decl.uses()) {
      mx::Fragment fragment = mx::Fragment::containing(use);
      mx::File file = mx::File::containing(fragment);

      std::cout
          << file.id() << '\t'
          << fragment.id();

      mx::TokenRange highlight_range;
      mx::Token token;

      if (auto decl_user = use.as_declaration()) {
        std::cout
            << '\t' << decl_user->id() << '\t'
            << mx::EnumeratorName(decl_user->kind());

        token = decl_user->token();
        highlight_range = decl_user->tokens();

      } else if (auto stmt_user = use.as_statement()) {
        std::cout
            << '\t' << stmt_user->id() << '\t'
            << mx::EnumeratorName(stmt_user->kind());

        highlight_range = stmt_user->tokens();
        if (highlight_range) {
          token = highlight_range[0];
        }

      } else if (auto type_user = use.as_type()) {
        std::cout
            << '\t' << type_user->id() << '\t'
            << mx::EnumeratorName(type_user->kind());
      }

      // Show the location of the user.
      if (FLAGS_show_locations && token) {
        std::cout << '\t' << file_paths[file.id()].generic_string();
        if (auto line_col = token.location(location_cache)) {
          std::cout << '\t' << line_col->first << '\t' << line_col->second;
        }
      }

      std::cout << '\n';

      // Print out the selectors for the uses, i.e. the enumerators that
      // correspond to methods whose return values match the entity id, or
      // one of the redeclarations of the entity.
      for (auto selector : mx::EnumerationRange<mx::DeclUseSelector>()) {
        if (use.has_selector(selector)) {
          std::cout << "\t\t\t" << mx::EnumeratorName(selector) << '\n';
        }
      }

      // Highlight the user code.
      if (FLAGS_highlight_user && highlight_range.size()) {
        RenderFragment(std::cout, fragment, highlight_range, "\t",
                       FLAGS_show_locations);
        std::cout << "\n\n";
      }
    }

  } else {
    std::cerr << "Invalid declaration id " << FLAGS_entity_id << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
