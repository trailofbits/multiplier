// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

//#include <cassert>
//#include <map>
#include <multiplier/AST.capnp.h>
#include <multiplier/AST.h>
#include <multiplier/RPC.capnp.h>
#include <multiplier/Types.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Forward.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>
#include <pasta/Util/File.h>
#include <cassert>
#include <map>
#include <unordered_map>
#include <unordered_set>

#include "Context.h"

namespace indexer {

using EntityIdMap = std::unordered_map<const void *, mx::EntityId>;
using FileIdMap = std::unordered_map<pasta::File, mx::RawEntityId>;
using TypeKey = std::pair<const void *, uint32_t>;
using TypeIdMap = std::map<TypeKey, mx::EntityId>;
using PseudoOffsetMap = std::unordered_map<const void *, uint32_t>;
using Pseudo = std::variant<pasta::TemplateArgument,
                            pasta::CXXBaseSpecifier,
                            pasta::TemplateParameterList,
                            pasta::Designator>;

class EntityMapper;
class IndexingContext;
class NameMangler;

// Summary information about a group of top-level declarations that are
// somehow lexically/syntactically "stuck together" and thus serialized
// together. For example, `int optind, opterr, optopt;` is one example of
// being syntactically stuck together. Another example would be a C macro
// that expands into two separate top-level declarations. We don't want to
// break this macro expansion into two, as in the original source file it
// represents a single logical thing.
struct PendingFragment {

  // Unique ID of the fragment containing the top-level declarations `decls`.
  mx::RawEntityId fragment_id;

  // Top-level declarations. These are the roots of serialization.
  std::vector<pasta::Decl> decls;

  // Offsets of the serialized version of types in this fragment.
  //
  // NOTE(pag): Types are redundantly represented in/across fragments; no
  //            de-duplication is done.
  //
  // TODO(pag): Eventually split PASTA's `Type` back into a `QualType` and
  //            a `Type`?
  TypeIdMap type_ids;

  // Entity IDs for parentage tracking.
  EntityIdMap parent_decl_ids;
  EntityIdMap parent_stmt_ids;

  // Offsets of the serialized version of pseudo entities in this fragment.
  PseudoOffsetMap pseudo_offsets;

  // Declarations, statements, types, and pseudo-entities to serialize, in their
  // order of appearance and serialization.
  std::vector<pasta::Decl> decls_to_serialize;
  std::vector<pasta::Stmt> stmts_to_serialize;
  std::vector<pasta::Type> types_to_serialize;

  // We distinguish entities from "pseudo" entities, where an entity is uniquely
  // identifiable via an `mx::EntityId`, whereas a pseudo entity is not uniquely
  // identifiable, but is attached to some other entity. For example, a
  // `TemplateParamterList` or a `TemplateArgument` is a pseudo entity.
  std::vector<Pseudo> pseudos_to_serialize;

  // Inclusive range of indices into the parsed tokens.
  uint64_t begin_index;
  uint64_t end_index;

  // Label the initial entities of this fragment. This focuses on finding the
  // entities that syntactically belong to this fragment, and assigning them
  // IDs. Labeling happens first for all fragments, then we run `Build` for
  // new fragments that we want to serialize.
  //
  // NOTE(pag): Implemented in `LabelEntitiesInFragment.cpp`.
  void Label(EntityIdMap &entity_ids, const pasta::TokenRange &range);

  // Build the fragment. This fills out the decls/stmts/types to serialize.
  //
  // NOTE(pag): Implemented in `BuildPendingFragment.cpp`.
  void Build(EntityIdMap &entity_ids, FileIdMap &file_ids,
             const pasta::TokenRange &tokens);

  // Label the parent entity ids.
  void LabelParents(EntityMapper &em);

  // Serialize the built-out fragments.
  void Serialize(EntityMapper &em, mx::rpc::Fragment::Builder &b);

  // Store information persistently to enable linking of declarations across
  // fragments.
  void LinkDeclarations(IndexingContext &context, EntityMapper &em,
                        NameMangler &mangler);

  // Identify all unique entity IDs used by this fragment, and map them to the
  // fragment ID in the data store.
  void FindDeclarationUses(
      IndexingContext &context, mx::rpc::Fragment::Builder &b);

  // Identify all explicit references to entities.
  //
  // TODO(pag): Eventually make this identify the type of reference, or use
  //            the SourceIR to do so.
  void LinkReferences(IndexingContext &context, EntityMapper &em);

  // Store serialized declaration fragments symbol to the persistent store
  void PersistDeclarationSymbols(IndexingContext &context, EntityMapper &em,
                                 pasta::AST &ast, mx::WorkerId worker_id);
};

}  // namespace indexer
