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

DEFINE_uint64(entity_id, 0, "ID of the entity to print");

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] --entity_id ID\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample(true);
  
  mx::TokenRange entity_tokens;
  std::optional<mx::Fragment> fragment;

  auto maybe_entity = index.entity(FLAGS_entity_id);
  if (std::holds_alternative<mx::Decl>(maybe_entity)) {
    auto entity = std::get<mx::Decl>(maybe_entity);
    fragment.emplace(mx::Fragment::containing(entity));
    entity_tokens = entity.tokens();

  } else if (std::holds_alternative<mx::Stmt>(maybe_entity)) {
    auto entity = std::get<mx::Stmt>(maybe_entity);
    fragment.emplace(mx::Fragment::containing(entity));
    entity_tokens = entity.tokens();

  } else if (std::holds_alternative<mx::Attr>(maybe_entity)) {
    auto entity = std::get<mx::Attr>(maybe_entity);
    fragment.emplace(mx::Fragment::containing(entity));
    entity_tokens = entity.tokens();

//  } else if (std::holds_alternative<mx::Macro>(maybe_entity)) {
//    auto entity = std::get<mx::Macro>(maybe_entity);
//    fragment.emplace(mx::Fragment::containing(entity));
//    entity_tokens = entity.tokens();

  } else if (std::holds_alternative<mx::CXXBaseSpecifier>(maybe_entity)) {
    auto entity = std::get<mx::CXXBaseSpecifier>(maybe_entity);
    fragment.emplace(mx::Fragment::containing(entity));
    entity_tokens = entity.tokens();

  } else if (std::holds_alternative<mx::Designator>(maybe_entity)) {
    auto entity = std::get<mx::Designator>(maybe_entity);
    fragment.emplace(mx::Fragment::containing(entity));
    entity_tokens = entity.tokens();

//  } else if (std::holds_alternative<mx::TemplateArgument>(maybe_entity)) {
//    auto entity = std::get<mx::TemplateArgument>(maybe_entity);
//    fragment.emplace(mx::Fragment::containing(entity));
//    entity_tokens = entity.tokens();

  } else if (std::holds_alternative<mx::TemplateParameterList>(maybe_entity)) {
    auto entity = std::get<mx::TemplateParameterList>(maybe_entity);
    fragment.emplace(mx::Fragment::containing(entity));
    entity_tokens = entity.tokens();

  } else if (std::holds_alternative<mx::Token>(maybe_entity)) {
    auto entity = std::get<mx::Token>(maybe_entity);
    fragment = mx::Fragment::containing(entity);
    entity_tokens = entity;
  }

  if (!fragment) {
    std::cerr
        << "Invalid or unsupported entity id " << FLAGS_entity_id << std::endl;
    return EXIT_FAILURE;
  }

  // Print out the tokens of this fragment as they appear in the file.
  RenderFragment(std::cout, *fragment, entity_tokens, "", true);
  std::cout << '\n';

  return EXIT_SUCCESS;
}
