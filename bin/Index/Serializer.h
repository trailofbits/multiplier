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

using EntityListBuilder = capnp::List<mx::ast::Entity, capnp::Kind::STRUCT>::Builder;
using FragmentBuilder = mx::rpc::Fragment::Builder;

// Summary information about a group of top-level declarations that are
// somehow lexically/syntactically "stuck together" and thus serialized
// together. For example, `int optind, opterr, optopt;` is one example of
// being syntactically stuck together. Another example would be a C macro
// that expands into two separate top-level declarations. We don't want to
// break this macro expansion into two, as in the original source file it
// represents a single logical thing.
struct CodeChunk {
  mx::FragmentId fragment_id;
  std::vector<pasta::Decl> decls;
  uint64_t begin_index;
  uint64_t end_index;
  unsigned num_entities{0u};
  unsigned num_template_arguments{0u};
};

class EntitySerializer final : public EntityVisitor {
 public:
  EntityIdMap entity_ids;
  mx::FragmentId code_id;
  unsigned next_pseudo_entity_offset{0};
  std::unordered_set<uint64_t> serialized_entities;
  const std::unordered_map<pasta::File, mx::FileId> &file_ids;

  ::capnp::List<::mx::ast::Entity, ::capnp::Kind::STRUCT>::Builder
      entity_builder;

  const pasta::TokenRange range;

  void Serialize(mx::rpc::Token::Builder token, const pasta::Token &entity);

  virtual ~EntitySerializer(void);

  inline EntitySerializer(
      pasta::TokenRange range_, EntityIdMap entity_ids_,
      const std::unordered_map<pasta::File, mx::FileId> &file_ids_)
      : entity_ids(std::move(entity_ids_)),
        code_id(mx::kInvalidEntityId),
        file_ids(file_ids_),
        range(std::move(range_)) {}

  void SerializeCodeEntities(CodeChunk code, FragmentBuilder &builder);

  mx::FileId FileId(const pasta::File &file);
  uint64_t EntityId(const pasta::Decl &entity);
  uint64_t EntityId(const pasta::Stmt &entity);
  uint64_t EntityId(const pasta::Token &entity);
  uint64_t EntityId(const pasta::FileToken &entity);

  bool Enter(const pasta::Decl &entity) final;
  bool Enter(const pasta::Stmt &entity) final;
  void Enter(const pasta::Decl &entity, std::vector<pasta::TemplateArgument>) final;
  void Enter(const pasta::Stmt &entity, std::vector<pasta::TemplateArgument>) final;
};

}  // namespace indexer
