// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Label.h"

#include <glog/logging.h>
#include <multiplier/AST.h>

namespace indexer {

EntityLabeller::~EntityLabeller(void) {}

bool EntityLabeller::Enter(const pasta::Decl &entity) {
  auto kind = entity.Kind();
  auto &next_offset = next_entity_offset[code.fragment_id];
  mx::DeclarationId id;
  id.fragment_id = code.fragment_id;
  id.offset = next_offset;
  id.kind = mx::FromPasta(kind);

  if (entity_ids.emplace(entity.RawDecl(), id).second) {
    ++next_offset;
    ++code.num_entities;
    return true;
  } else {
    return false;
  }
}

bool EntityLabeller::Enter(const pasta::Stmt &entity) {
  auto kind = entity.Kind();
  auto &next_offset = next_entity_offset[code.fragment_id];
  mx::StatementId id;
  id.fragment_id = code.fragment_id;
  id.offset = next_offset;
  id.kind = mx::FromPasta(kind);

  if (entity_ids.emplace(entity.RawStmt(), id).second) {
    ++next_offset;
    ++code.num_entities;
    return true;
  } else {
    return false;
  }
}


void EntityLabeller::Enter(
    const pasta::Decl &, std::vector<pasta::TemplateArgument> args) {
  code.num_pseudo_entities += static_cast<unsigned>(args.size());
}

void EntityLabeller::Enter(
    const pasta::Stmt &, std::vector<pasta::TemplateArgument> args) {
  code.num_pseudo_entities += static_cast<unsigned>(args.size());
}

void EntityLabeller::Enter(
    const pasta::Decl &, std::vector<pasta::CXXBaseSpecifier> bases) {
  code.num_pseudo_entities += static_cast<unsigned>(bases.size());
}

void EntityLabeller::Enter(
    const pasta::Decl &, std::vector<pasta::TemplateParameterList> params) {
  code.num_pseudo_entities += static_cast<unsigned>(params.size());
}

void EntityLabeller::Enter(
    const pasta::Decl &, const pasta::TemplateParameterList &) {
  code.num_pseudo_entities += 1u;
}

void EntityLabeller::Enter(
    const pasta::Stmt &, const pasta::TemplateParameterList &) {
  code.num_pseudo_entities += 1u;
}

bool EntityLabeller::Label(const pasta::Token &entity) {
  auto kind = entity.Kind();
  auto index = entity.Index();
  CHECK_LE(code.begin_index, index);
  CHECK_LE(index, code.end_index);
  mx::FragmentTokenId id;
  id.fragment_id = code.fragment_id;
  id.offset = static_cast<uint32_t>(index - code.begin_index);
  id.kind = mx::FromPasta(kind);

  if (entity_ids.emplace(entity.RawToken(), id).second) {
    return true;
  } else {
    return false;
  }
}

CodeChunk EntityLabeller::EnterCode(
    mx::FragmentId code_id_, std::vector<pasta::Decl> tlds,
    const pasta::TokenRange &range, uint64_t begin_index_,
    uint64_t end_index_) {

  code.fragment_id = code_id_;
  code.begin_index = begin_index_;
  code.end_index = end_index_;
  code.decls = std::move(tlds);

  for (auto i = begin_index_; i <= end_index_; ++i) {
    Label(range[i]);
  }
  for (const pasta::Decl &tld : code.decls) {
    this->DeclVisitor::Accept(tld);
  }

  return std::move(code);
}

}  // namespace indexer
