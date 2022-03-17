// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Serializer.h"

#include <cassert>
#include <glog/logging.h>
#include <pasta/AST/Token.h>

#include "Serialize.h"

namespace indexer {
namespace {

}  // namespace

uint64_t EntitySerializer::EntityId(const pasta::Decl &entity) const {
  if (auto it = entity_ids.find(entity.RawDecl()); it != entity_ids.end()) {
    return it->second;
  } else {
    return mx::kInvalidEntityId;
  }
}

uint64_t EntitySerializer::EntityId(const pasta::Stmt &entity) const {
  if (auto it = entity_ids.find(entity.RawStmt()); it != entity_ids.end()) {
    return it->second;
  } else {
    return mx::kInvalidEntityId;
  }
}

uint64_t EntitySerializer::EntityId(const pasta::Token &entity) const {
  if (auto it = entity_ids.find(entity.RawToken()); it != entity_ids.end()) {
    return it->second;
  } else {
    return mx::kInvalidEntityId;
  }
}

bool EntitySerializer::Enter(const pasta::Decl &entity) {

  // Only serialize if we have a valid entity ID for this.
  const uint64_t id = EntityId(entity);
  if (!id) {
    LOG(FATAL) << "bad entity id";
    return false;
  }

  mx::EntityId ent_id(id);
  mx::VariantId unpacked_id = ent_id.Unpack();
  CHECK(std::holds_alternative<mx::DeclarationId>(unpacked_id));
  mx::DeclarationId decl_id = std::get<mx::DeclarationId>(unpacked_id);

  // This entity doesn't belong in this code chunk. Not sure if/when this will
  // happen.
  if (decl_id.code_id != code_id) {
    LOG(FATAL)
        << "wrong list";
    return false;
  }

  // Don't re-serialize if we've done it already.
  if (!serialized_entities.emplace(id).second) {
    return false;
  }

  auto offset = decl_id.offset;
  switch (entity.Kind()) {
#define MX_SERIALIZE_DECL(decl) \
    case pasta::DeclKind::k ## decl: { \
      Serialize ## decl ## Decl( \
         *this, \
         decl ## Decl_builder[offset], \
         reinterpret_cast<const pasta::decl ## Decl &>(entity)); \
      return true; \
    }

    PASTA_FOR_EACH_DECL_IMPL(MX_SERIALIZE_DECL, PASTA_IGNORE_ABSTRACT)

#undef MX_SERIALIZE_DECL
    default:
      return false;
  }
}

bool EntitySerializer::Enter(const pasta::Stmt &entity) {

  // Only serialize if we have a valid entity ID for this.
  const uint64_t id = EntityId(entity);
  if (!id) {
    return false;
  }

  // Don't re-serialize if we've done it already.
  if (!serialized_entities.emplace(id).second) {
    return false;
  }

  mx::EntityId ent_id(id);
  mx::VariantId unpacked_id = ent_id.Unpack();
  CHECK(std::holds_alternative<mx::StatementId>(unpacked_id));
  mx::StatementId stmt_id = std::get<mx::StatementId>(unpacked_id);

  // This entity doesn't belong in this code chunk. Not sure if/when this will
  // happen.
  if (stmt_id.code_id != code_id) {
    DLOG(ERROR)
        << "Attempting to serialize into wrong entity list";
    return false;
  }

  auto offset = stmt_id.offset;
  switch (entity.Kind()) {
#define MX_SERIALIZE_STMT(stmt) \
    case pasta::StmtKind::k ## stmt: { \
      Serialize ## stmt( \
          *this, \
          stmt ## _builder[offset], \
          reinterpret_cast<const pasta::stmt &>(entity)); \
      return true; \
    }
    PASTA_FOR_EACH_STMT_IMPL(MX_SERIALIZE_STMT,
                             MX_SERIALIZE_STMT,
                             MX_SERIALIZE_STMT,
                             MX_SERIALIZE_STMT,
                             MX_SERIALIZE_STMT,
                             PASTA_IGNORE_ABSTRACT)
#undef MX_SERIALIZE_STMT
    default:
      return false;
  }
}

void EntitySerializer::Serialize(mx::ast::Token::Builder token,
                                 const pasta::Token &entity) {
  std::string data(entity.Data().data(), entity.Data().size());
  token.setKind(static_cast<mx::ast::TokenKind>(mx::FromPasta(entity.Kind())));
  token.setData(data);
}

}  // namespace indexer
