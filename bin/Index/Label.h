// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Serializer.h"
#include "Visitor.h"

namespace indexer {

// Labels entities (decls, stmts, types, tokens). The idea here is that in
// `ast::EntityList`, which is derived from a Cap'n Proto schema, we have a
// bunch of lists of different types of entities (decls, stmts, etc.). We index
// code at the granularity of "code chunks," which contain one or more top-level
// declarations. Each code chunk has a unique code ID, and there is an
// `ast::EntityList` associated with each code chunk. We'd like to be able to
// reference across code chunks, and to do so deterministically. The way we do
// this is that we assign IDs to each entity in a deterministic way for each
// code chunk, so then we we go and build the serialized form of a code chunk,
// then we can just use these IDs to build up the references and know that
// things will generally work out. One trick is our IDs are compound: they
// include the code chunk ID, the entity kind, the entity sub-kind, and then
// the offset in one of the many `List(...)` types inside of the
// `ast::EntityList`. This way, it's easy to identify exactly which entity we
// need to reference inside of an entity list.
class EntityLabeller final : public EntityVisitor {
 private:
  EntityIdMap entity_ids;
  CodeChunk code;
  std::map<std::pair<mx::FragmentId, pasta::DeclKind>, uint32_t> next_decl_offset;
  std::map<std::pair<mx::FragmentId, pasta::StmtKind>, uint32_t> next_stmt_offset;
//  std::map<std::pair<mx::CodeId, pasta::TypeKind>, uint32_t> next_type_offset;

  bool Enter(const pasta::Decl &entity) final;
  bool Enter(const pasta::Stmt &entity) final;
  bool Label(const pasta::Token &entity);

 public:
  virtual ~EntityLabeller(void);

  CodeChunk EnterCode(mx::FragmentId code_id_, std::vector<pasta::Decl> tlds,
                      const pasta::TokenRange &range,
                      uint64_t begin_index_, uint64_t end_index_);

  inline EntityIdMap TakeEntityIds(void) {
    return std::move(entity_ids);
  }
};

}  // namespace indexer
