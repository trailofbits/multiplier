// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <sstream>

#include "Index.h"
#include <multiplier/AST.h>

DEFINE_uint64(entity_id, 0, "ID of the entity to print");

namespace {

mx::TokenRange TryGetTokens(const mx::VariantEntity &entity) {
  if (std::holds_alternative<mx::Stmt>(entity)) {
    return std::get<mx::Stmt>(entity).tokens();
  }

  if (std::holds_alternative<mx::Decl>(entity)) {
    return std::get<mx::Decl>(entity).tokens();
  }

  if (std::holds_alternative<mx::Attr>(entity)) {
    return std::get<mx::Attr>(entity).tokens();
  }

  if (std::holds_alternative<mx::Designator>(entity)) {
    return std::get<mx::Designator>(entity).tokens();
  }

  if (std::holds_alternative<mx::CXXBaseSpecifier>(entity)) {
    return std::get<mx::CXXBaseSpecifier>(entity).tokens();
  }

  if (std::holds_alternative<mx::CXXCtorInitializer>(entity)) {
    return std::get<mx::CXXCtorInitializer>(entity).tokens();
  }

  if (std::holds_alternative<mx::Macro>(entity)) {
    return std::get<mx::Macro>(entity).root().use_tokens();
  }

  if (std::holds_alternative<mx::Token>(entity)) {
    return std::get<mx::Token>(entity);
  }

  return mx::TokenRange();
}

}  // namespace

int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] --entity_id ID\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample(true);

  auto maybe_entity = index.entity(FLAGS_entity_id);

  auto references = mx::Reference::to(maybe_entity);
  for (mx::Reference ref : references) {
    auto context = ref.context();
    auto referer = ref.as_variant();
    auto frag = mx::Fragment::containing(referer);
    if (!frag) {
      continue;
    }

    mx::TokenRange entity_tokens = TryGetTokens(context);
    if (!entity_tokens) {
      entity_tokens = TryGetTokens(referer);
    }

    if (!entity_tokens) {
      continue;
    }

    std::cout
        << "Context ID: " << mx::EntityId(context).Pack() << '\n'
        << "Referer ID: " << mx::EntityId(referer).Pack() << '\n'
        << "Reference kind: " << ref.kind().data() << '\n';

    // Print out the tokens of this fragment as they appear in the file.
    RenderFragment(std::cout, *frag, entity_tokens, "", true);
    std::cout << "\n\n";

  }
  return EXIT_SUCCESS;
}
