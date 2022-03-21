// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Visitor.h"

namespace pasta {
class File;
}  // namespace pasta
namespace indexer {

using EntityIdMap = std::unordered_map<const void *, mx::EntityId>;

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
  std::map<pasta::DeclKind, unsigned> num_decls_of_kind;
  std::map<pasta::StmtKind, unsigned> num_stmts_of_kind;
};

class EntitySerializer final : public EntityVisitor {
 private:
  const pasta::TokenRange range;
  EntityIdMap entity_ids;
  mx::FragmentId code_id;
  std::unordered_set<uint64_t> serialized_entities;
  const std::unordered_map<pasta::File, mx::FileId> &file_ids;

#define MX_DECLARE_DECL_LIST_BUILDER(decl) \
    ::capnp::List<::mx::ast::decl ## Decl, ::capnp::Kind::STRUCT>::Builder decl ## Decl_builder;

#define MX_DECLARE_STMT_LIST_BUILDER(stmt) \
    ::capnp::List<::mx::ast::stmt, ::capnp::Kind::STRUCT>::Builder stmt ## _builder;

  PASTA_FOR_EACH_DECL_IMPL(MX_DECLARE_DECL_LIST_BUILDER, PASTA_IGNORE_ABSTRACT)
  PASTA_FOR_EACH_STMT_IMPL(MX_DECLARE_STMT_LIST_BUILDER,
                           MX_DECLARE_STMT_LIST_BUILDER,
                           MX_DECLARE_STMT_LIST_BUILDER,
                           MX_DECLARE_STMT_LIST_BUILDER,
                           MX_DECLARE_STMT_LIST_BUILDER,
                           PASTA_IGNORE_ABSTRACT)

#undef MX_DECLARE_STMT_LIST_BUILDER
#undef MX_DECLARE_DECL_LIST_BUILDER

  void Serialize(mx::ast::Token::Builder token, const pasta::Token &entity);

 public:
  virtual ~EntitySerializer(void);

  inline EntitySerializer(pasta::TokenRange range_, EntityIdMap entity_ids_,
                          const std::unordered_map<pasta::File, mx::FileId> &file_ids_)
      : range(std::move(range_)),
        entity_ids(std::move(entity_ids_)),
        code_id(mx::kInvalidEntityId),
        file_ids(file_ids_) {}

  void SerializeCodeEntities(
      CodeChunk code, mx::ast::EntityList::Builder entities);

  uint64_t EntityId(const pasta::Decl &entity);
  uint64_t EntityId(const pasta::Stmt &entity);
  uint64_t EntityId(const pasta::Token &entity);
  uint64_t EntityId(const pasta::FileToken &entity);

  bool Enter(const pasta::Decl &entity) final;
  bool Enter(const pasta::Stmt &entity) final;
};

}  // namespace indexer
