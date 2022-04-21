// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Serializer.h"

#include <capnp/common.h>
#include <capnp/message.h>
#include <cassert>
#include <glog/logging.h>
#include <pasta/AST/Forward.h>
#include <pasta/AST/Token.h>
#include <pasta/Util/File.h>

#include "Serialize.h"
#include "Util.h"

namespace indexer {
namespace {

struct SaveRestoreEntityId {
 public:
  mx::RawEntityId &ref;
  const mx::RawEntityId old_val;

  SaveRestoreEntityId(mx::RawEntityId &ref_, mx::RawEntityId new_val)
      : ref(ref_),
        old_val(ref) {
    ref = new_val;
  }

  ~SaveRestoreEntityId(void) {
    ref = old_val;
  }
};

}  // namespace

EntitySerializer::~EntitySerializer(void) {}

mx::RawEntityId EntitySerializer::EntityId(const pasta::Decl &entity) {
  if (auto it = entity_ids.find(entity.RawDecl()); it != entity_ids.end()) {
    return it->second;
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId EntitySerializer::EntityId(const pasta::Stmt &entity) {
  if (auto it = entity_ids.find(entity.RawStmt()); it != entity_ids.end()) {
    return it->second;
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId EntitySerializer::EntityId(const pasta::Token &entity) {
  if (auto it = entity_ids.find(entity.RawToken()); it != entity_ids.end()) {
    return it->second;

  // If we fail to resolve the parsed token to an entity ID, then try to
  // see if it's associated with a `pasta::FileToken`, and if so, then form
  // an entity ID for that. We unify `Token` and `FileToken` in our serialized
  // representation, because we always want references to "point somewhere."
  } else if (auto ft = entity.FileLocation()) {
    return this->EntityId(ft.value());
  
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::FileId EntitySerializer::FileId(const pasta::File &file) {
  if (auto fit = file_ids.find(file); fit != file_ids.end()) {
    return fit->second;
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId EntitySerializer::EntityId(const pasta::FileToken &entity) {
  if (auto it = entity_ids.find(entity.RawFileToken());
      it != entity_ids.end()) {
    return it->second;
  }

  auto file = pasta::File::Containing(entity);
  if (auto file_id = FileId(file); file_id != mx::kInvalidEntityId) {
    mx::FileTokenId id;
    id.file_id = file_id;
    id.kind = TokenKindFromPasta(entity);
    id.offset = static_cast<uint32_t>(entity.Index());
    ::mx::EntityId ret_id(id);
    entity_ids.emplace(entity.RawFileToken(), ret_id);
    return ret_id;
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId EntitySerializer::EntityId(const pasta::Type &entity) {
  std::pair<const void *, uint32_t> type_key(entity.RawType(),
                                             entity.RawQualifiers());
  assert(type_key.first != nullptr);

  mx::RawEntityId &raw_id = lazy_type_id[type_key];
  if (raw_id == mx::kInvalidEntityId) {
    mx::TypeId id;
    id.fragment_id = code_id;
    id.kind = mx::FromPasta(entity.Kind());
    id.offset = static_cast<uint32_t>(types_to_serialize.size());
    assert(id.offset == types_to_serialize.size());
    raw_id = mx::EntityId(id);

    types_to_serialize.emplace_back(entity);
    assert(types_to_serialize.back().RawType() != nullptr);
  }

  return raw_id;
}

bool EntitySerializer::Enter(const pasta::Decl &entity) {
  SaveRestoreEntityId save_parent_decl(parent_decl_id, current_decl_id);

  // Only serialize if we have a valid entity ID for this.
  const mx::RawEntityId id = EntityId(entity);
  if (!id) {
    LOG(FATAL) << "bad entity id";
    return false;
  }

  SaveRestoreEntityId save_current_decl(current_decl_id, id);

  mx::EntityId ent_id(id);
  mx::VariantId unpacked_id = ent_id.Unpack();
  CHECK(std::holds_alternative<mx::DeclarationId>(unpacked_id));
  mx::DeclarationId decl_id = std::get<mx::DeclarationId>(unpacked_id);

  // This entity doesn't belong in this code chunk. Not sure if/when this will
  // happen.
  if (decl_id.fragment_id != code_id) {
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
         decl_builder[offset], \
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
  SaveRestoreEntityId save_parent_stmt(parent_stmt_id, current_stmt_id);

  // Only serialize if we have a valid entity ID for this.
  const mx::RawEntityId id = EntityId(entity);
  if (!id) {
    return false;
  }

  SaveRestoreEntityId save_current_stmt(current_stmt_id, id);

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
  if (stmt_id.fragment_id != code_id) {
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
          stmt_builder[offset], \
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

// Reset the serializer in preparation to serialize `fragment`.
void EntitySerializer::PrepareToSerialize(const PendingFragment &fragment) {
  serialized_entities.clear();
  lazy_type_id.clear();
  types_to_serialize.clear();
  code_id = fragment.fragment_id;
  next_pseudo_entity_offset = 0;
  parent_decl_id = mx::kInvalidEntityId;
  parent_stmt_id = mx::kInvalidEntityId;
  current_decl_id = mx::kInvalidEntityId;
  current_stmt_id = mx::kInvalidEntityId;
}

void EntitySerializer::SerializeTypes(FragmentBuilder &builder) {

  // First pass does "fake" serialization to expand the set of types until
  // nothing is added to `types_to_serialize`.
  for (auto i = 0u; i < types_to_serialize.size(); ++i) {
    pasta::Type entity = types_to_serialize[i];  // NOTE(pag): Might resize.
    capnp::MallocMessageBuilder message;
    mx::ast::Type::Builder b = message.initRoot<mx::ast::Type>();
    switch (entity.Kind()) {
#define MX_SERIALIZE_TYPE(type) \
    case pasta::TypeKind::k ## type: { \
      Serialize ## type ## Type ( \
          *this, b, reinterpret_cast<const pasta::type ## Type &>(entity)); \
      break; \
    }
      PASTA_FOR_EACH_TYPE_IMPL(MX_SERIALIZE_TYPE,
                               PASTA_IGNORE_ABSTRACT)
    }
  }

  auto num_types = static_cast<uint32_t>(types_to_serialize.size());
  assert(lazy_type_id.size() == num_types);

  // Second pass actually does the real serialization.
  auto type_builder = builder.initTypes(num_types);
  auto i = 0u;
  for (const pasta::Type &entity : types_to_serialize) {
    mx::ast::Type::Builder b = type_builder[i++];
    switch (entity.Kind()) {
      PASTA_FOR_EACH_TYPE_IMPL(MX_SERIALIZE_TYPE,
                               PASTA_IGNORE_ABSTRACT)
    }
  }

#undef MX_SERIALIZE_TYPE
}

void EntitySerializer::Enter(
    const pasta::Decl &, std::vector<pasta::TemplateArgument>) {}
void EntitySerializer::Enter(
    const pasta::Stmt &, std::vector<pasta::TemplateArgument>) {}
void EntitySerializer::Enter(
    const pasta::Decl &, std::vector<pasta::CXXBaseSpecifier>) {}
void EntitySerializer::Enter(
    const pasta::Decl &, std::vector<pasta::TemplateParameterList>) {}
void EntitySerializer::Enter(
    const pasta::Decl &, const pasta::TemplateParameterList &) {}
void EntitySerializer::Enter(
    const pasta::Stmt &, const pasta::TemplateParameterList &) {}

}  // namespace indexer
