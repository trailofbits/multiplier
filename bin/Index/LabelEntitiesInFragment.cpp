// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <glog/logging.h>
#include <multiplier/AST.h>

#include "PendingFragment.h"
#include "Util.h"
#include "Visitor.h"

namespace indexer {
namespace {

// Labels entities (decls, stmts, types, tokens). The idea here is that in
// `rpc::Fragment`, which is derived from a Cap'n Proto schema, we have a
// lists of entities (decls, stmts, etc.). We index code at the granularity of
// fragments (represented here as `PendingFragment`) which contain one or more
// top-level declarations. Each fragment has a unique code ID, and there is an
// `ast::EntityList` associated with each fragment. We'd like to be able to
// reference across fragments, and to do so deterministically. The way we do
// this is that we assign IDs to each entity in a deterministic way for each
// fragment, so then we we go and build the serialized form of a fragment,
// then we can just use these IDs to build up the references and know that
// things will generally work out. One trick is our IDs are compound: they
// include the fragment ID, the entity kind, the entity sub-kind, and then
// the offset in the shared entity list `rpc::Fragment::entities`. This way,
// it's easy to identify exactly which entity we need to reference inside of an
// entity list.
class EntityLabeller final : public EntityVisitor {
 public:
  EntityIdMap &entity_ids;
  PendingFragment &fragment;

  inline explicit EntityLabeller(EntityIdMap &entity_ids_,
                                 PendingFragment &fragment_)
      : entity_ids(entity_ids_),
        fragment(fragment_) {}

  virtual ~EntityLabeller(void) = default;

  bool Enter(const pasta::Decl &entity) final;
  bool Enter(const pasta::Stmt &entity) final;
  bool Label(const pasta::Token &entity);
};

bool EntityLabeller::Enter(const pasta::Decl &entity) {
  auto kind = entity.Kind();
  mx::DeclarationId id;
  id.fragment_id = fragment.fragment_id;
  id.offset = static_cast<uint32_t>(fragment.decls_to_serialize.size());
  id.kind = mx::FromPasta(kind);

  if (entity_ids.emplace(entity.RawDecl(), id).second) {

    // NOTE(pag): Will visit in `PendingTokenRange::Build()`.
    fragment.decls_to_serialize.emplace_back(entity);
    return true;
  } else {
    return false;
  }
}

bool EntityLabeller::Enter(const pasta::Stmt &entity) {
  auto kind = entity.Kind();
  mx::StatementId id;
  id.fragment_id = fragment.fragment_id;
  id.offset = static_cast<uint32_t>(fragment.stmts_to_serialize.size());
  id.kind = mx::FromPasta(kind);

  if (entity_ids.emplace(entity.RawStmt(), id).second) {

    // NOTE(pag): Will visit in `PendingTokenRange::Build()`.
    fragment.stmts_to_serialize.emplace_back(entity);
    return true;

  } else {
    return false;
  }
}

bool EntityLabeller::Label(const pasta::Token &entity) {
  auto index = entity.Index();
  CHECK_LE(fragment.begin_index, index);
  CHECK_LE(index, fragment.end_index);
  mx::FragmentTokenId id;
  id.fragment_id = fragment.fragment_id;
  id.offset = static_cast<uint32_t>(index - fragment.begin_index);
  id.kind = TokenKindFromPasta(entity);

  if (entity_ids.emplace(entity.RawToken(), id).second) {
    return true;
  } else {
    return false;
  }
}

}  // namespace

// Label the initial entities of this fragment. This focuses on finding the
// entities that syntactically belong to this fragment, and assigning them
// IDs. Labeling happens first for all fragments, then we run `Build` for
// new fragments that we want to serialize.
void PendingFragment::Label(EntityIdMap &entity_ids,
                            const pasta::TokenRange &tok_range) {
  EntityLabeller labeller(entity_ids, *this);

  for (auto i = begin_index; i <= end_index; ++i) {
    (void) labeller.Label(tok_range[i]);
  }

  // Go top-down through the top-level declarations of this pending fragment
  // and build up an initial list of `decls_to_serialize` and
  // `stmts_to_serialize`. This list will be expanded to fixpoint by
  // `PendingFragment::Build`.
  for (const pasta::Decl &decl : decls) {
    (void) labeller.Accept(decl);
  }
}

}  // namespace indexer
