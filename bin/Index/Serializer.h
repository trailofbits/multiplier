// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Visitor.h"

#include <multiplier/RPC.capnp.h>

namespace pasta {
class File;
}  // namespace pasta
namespace indexer {

using EntityIdMap = std::unordered_map<const void *, mx::EntityId>;

using FragmentBuilder = mx::rpc::Fragment::Builder;

// Summary information about a group of top-level declarations that are
// somehow lexically/syntactically "stuck together" and thus serialized
// together. For example, `int optind, opterr, optopt;` is one example of
// being syntactically stuck together. Another example would be a C macro
// that expands into two separate top-level declarations. We don't want to
// break this macro expansion into two, as in the original source file it
// represents a single logical thing.
struct PendingFragment {
  mx::FragmentId fragment_id;
  std::vector<pasta::Decl> decls;
  uint64_t begin_index;
  uint64_t end_index;

  // The number of entities that will be stored in the serialized
  // `rpc::Fragment` generated from this `PendingFragment`. We count the number of
  // entities because we need to pre-allocate space with Cap'n Proto. We
  // distinguish entities from "pseudo" entities, where an entity is uniquely
  // identifiable via an `mx::EntityId`, whereas a pseudo entity is not uniquely
  // identifiable, but is attached to some other entity. For example, a
  // `TemplateParamterList` or a `TemplateArgument` is a pseudo entity.
  unsigned num_decl_entities{0u};
  unsigned num_stmt_entities{0u};
  unsigned num_pseudo_entities{0u};
};

class EntitySerializer final : public EntityVisitor {
 public:
  EntityIdMap entity_ids;
  mx::FragmentId code_id;
  mx::RawEntityId parent_decl_id{mx::kInvalidEntityId};
  mx::RawEntityId parent_stmt_id{mx::kInvalidEntityId};
  mx::RawEntityId current_decl_id{mx::kInvalidEntityId};
  mx::RawEntityId current_stmt_id{mx::kInvalidEntityId};
  unsigned next_pseudo_entity_offset{0};
  std::unordered_set<mx::RawEntityId> serialized_entities;
  const std::unordered_map<pasta::File, mx::FileId> &file_ids;

  ::capnp::List<::mx::ast::Decl, ::capnp::Kind::STRUCT>::Builder
      decl_builder;
  ::capnp::List<::mx::ast::Stmt, ::capnp::Kind::STRUCT>::Builder
      stmt_builder;
  ::capnp::List<::mx::ast::Pseudo, ::capnp::Kind::STRUCT>::Builder
      pseudo_builder;

  const pasta::TokenRange range;

  virtual ~EntitySerializer(void);

  inline EntitySerializer(
      pasta::TokenRange range_, EntityIdMap entity_ids_,
      const std::unordered_map<pasta::File, mx::FileId> &file_ids_)
      : entity_ids(std::move(entity_ids_)),
        code_id(mx::kInvalidEntityId),
        file_ids(file_ids_),
        range(std::move(range_)) {}

  void SerializeCodeEntities(PendingFragment code, FragmentBuilder &builder);

  mx::FileId FileId(const pasta::File &file);
  mx::RawEntityId EntityId(const pasta::Decl &entity);
  mx::RawEntityId EntityId(const pasta::Stmt &entity);
  mx::RawEntityId EntityId(const pasta::Token &entity);
  mx::RawEntityId EntityId(const pasta::FileToken &entity);

  bool Enter(const pasta::Decl &entity) final;
  bool Enter(const pasta::Stmt &entity) final;
  void Enter(const pasta::Decl &, std::vector<pasta::TemplateArgument>) final;
  void Enter(const pasta::Stmt &, std::vector<pasta::TemplateArgument>) final;
  void Enter(const pasta::Decl &, std::vector<pasta::CXXBaseSpecifier>) final;
  void Enter(const pasta::Decl &, std::vector<pasta::TemplateParameterList>) final;
  void Enter(const pasta::Decl &, const pasta::TemplateParameterList &) final;
  void Enter(const pasta::Stmt &, const pasta::TemplateParameterList &) final;
};

}  // namespace indexer
