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
DEFINE_uint64(entity_id, 0, "ID of the entity to print the uses of");

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT] --entity_id ID\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index index(mx::EntityProvider::from_remote(
      FLAGS_host, FLAGS_port));

  auto maybe_entity = index.entity(FLAGS_entity_id);
  if (std::holds_alternative<mx::Decl>(maybe_entity)) {
    mx::Decl decl = std::get<mx::Decl>(maybe_entity);

    for (const mx::DeclUse &use : decl.uses()) {
      mx::Fragment fragment = mx::Fragment::containing(use);
      mx::File file = mx::File::containing(fragment);

      std::cout
          << file.id() << '\t'
          << fragment.id() << '\t';

      if (auto decl_user = use.as_declaration()) {
        std::cout
            << decl_user->id() << '\t'
            << mx::EnumeratorName(decl_user->kind());

      } else if (auto stmt_user = use.as_statement()) {
        if (auto call_expr = mx::CallExpr::from(stmt_user)) {

        }
        std::cout
            << stmt_user->id() << '\t'
            << mx::EnumeratorName(stmt_user->kind());

      } else if (auto type_user = use.as_type()) {
        std::cout
            << type_user->id() << '\t'
            << mx::EnumeratorName(type_user->kind());

      } else if (auto cxx_base_spec = use.as_cxx_base_specifier()) {

      } else if (auto tpl_arg = use.as_template_argument()) {

      } else if (auto tpl_param_list = use.as_template_parameter_list()) {

      }

      std::cout << '\n';
      for (auto selector : mx::EnumerationRange<mx::DeclUseSelector>()) {
        if (use.has_selector(selector)) {
          std::cout << '\t' << mx::EnumeratorName(selector) << '\n';
        }
      }
    }

  } else {
    std::cerr << "Invalid declaration id " << FLAGS_entity_id << std::endl;
    return EXIT_FAILURE;
  }
//
//
//  for (mx::Decl redecl : decl.redeclarations()) {
//    mx::Fragment fragment = mx::Fragment::containing(redecl);
//    mx::File file = mx::File::containing(fragment);
//
//    std::cout
//        << file.id() << '\t'
//        << fragment.id() << '\t'
//        << redecl.id() << '\t'
//        << (redecl.is_definition() ? "def\t" : "decl\t")
//        << mx::EnumeratorName(redecl.kind());
//
//    if (auto named_redecl = mx::NamedDecl::from(redecl)) {
//      std::cout << '\t' << named_redecl->name() << '\n';
//    }
//  }

  return EXIT_SUCCESS;
}
