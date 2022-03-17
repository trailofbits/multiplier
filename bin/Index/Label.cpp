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
  auto &next_offset = next_decl_offset[{code.code_id, kind}];
  mx::DeclarationId id;
  id.code_id = code.code_id;
  id.offset = next_offset;
  id.kind = mx::FromPasta(kind);

  if (entity_ids.emplace(entity.RawDecl(), id).second) {
    ++next_offset;
    code.num_decls_of_kind[kind] = next_offset;
    return true;
  } else {
    return false;
  }
}

bool EntityLabeller::Enter(const pasta::Stmt &entity) {
  auto kind = entity.Kind();
  auto &next_offset = next_stmt_offset[{code.code_id, kind}];
  mx::StatementId id;
  id.code_id = code.code_id;
  id.offset = next_offset;
  id.kind = mx::FromPasta(kind);

  if (entity_ids.emplace(entity.RawStmt(), id).second) {
    ++next_offset;
    code.num_stmts_of_kind[kind] = next_offset;
    return true;
  } else {
    return false;
  }
}

bool EntityLabeller::Label(const pasta::Token &entity) {
  auto kind = entity.Kind();
  auto index = entity.Index();
  CHECK_LE(code.begin_index, index);
  CHECK_LE(index, code.end_index);
  mx::TokenId id;
  id.code_id = code.code_id;
  id.offset = static_cast<uint32_t>(index - code.begin_index);
  id.kind = mx::FromPasta(kind);

  if (entity_ids.emplace(entity.RawToken(), id).second) {
    return true;
  } else {
    return false;
  }
}

CodeChunk EntityLabeller::EnterCode(
    mx::CodeId code_id_, std::vector<pasta::Decl> tlds,
    const pasta::TokenRange &range, uint64_t begin_index_,
    uint64_t end_index_) {

  code.code_id = code_id_;
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
