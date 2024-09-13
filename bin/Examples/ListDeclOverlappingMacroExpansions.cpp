// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <sstream>

#include "Index.h"
#include <multiplier/AST.h>
#include <multiplier/Frontend.h>

void PrintDeclOverlappingMacroSubstitution(const mx::Fragment &fragment, const mx::Macro &macro) {
  if (auto sub = mx::MacroSubstitution::from(macro)) {
    auto overlapping_decls = sub->parsed_tokens().overlapping_declarations();
    for (auto decl : overlapping_decls) {
      std::cout
        << fragment.id() << "\t\t"
        << decl.id() << "\t\t"
        << sub->id() << "\t\t"
        << decl.token().data() << "\t\t"
        << sub->name_or_operator().data()
        << "\n";
    }
  }
}

void PrintDeclCoveringMacroSubstitution(const mx::Fragment &fragment, const mx::Macro &macro) {
  if (auto sub = mx::MacroSubstitution::from(macro)) {
    if (auto decl = sub->parsed_tokens().covering_declaration()) {
      std::cout
        << fragment.id() << "\t\t"
        << decl->id() << "\t\t"
        << sub->id() << "\t\t"
        << decl->token().data() << "\t\t"
        << sub->name_or_operator().data()
        << "\n";
    }
  }
}

int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample();

  std::cout << "\nOverlapping declarations to the Macro expansion" << std::endl;
  for (mx::File file : index.files()) {
    for (mx::PackedFragmentId frag_id : file.fragment_ids()) {
      std::optional<mx::Fragment> fragment = index.fragment(frag_id);
      if (!fragment) {
        std::cerr << "Invalid fragment id " << frag_id << std::endl;
        continue;
      }

      for (mx::PreprocessedEntity node : fragment->preprocessed_code()) {
        if (auto macro = std::get_if<mx::Macro>(&node)) {
          PrintDeclOverlappingMacroSubstitution(fragment.value(), *macro);
        }
      }
    }
  }

  std::cout << "\nCovering declaration to the Macro expansion" << std::endl;
  for (mx::File file : index.files()) {
    for (mx::PackedFragmentId frag_id : file.fragment_ids()) {
      std::optional<mx::Fragment> fragment = index.fragment(frag_id);
      if (!fragment) {
        std::cerr << "Invalid fragment id " << frag_id << std::endl;
        continue;
      }

      for (mx::PreprocessedEntity node : fragment->preprocessed_code()) {
        if (auto macro = std::get_if<mx::Macro>(&node)) {
          PrintDeclCoveringMacroSubstitution(fragment.value(), *macro);
        }
      }
    }
  }

  return EXIT_SUCCESS;
}
