// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <glog/logging.h>

#include <multiplier/Entities/MacroKind.h>

#include "Context.h"
#include "PASTA.h"
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

  // Tracks the index of the next parsed token. Logic surrounding this
  // processing is replicated when serializing `TokenTree`s. The key is that
  // we want to serialize the final parsed tokens, and not any marker tokens
  // or intermediate macro expansion tokens.
  unsigned next_parsed_token_index{0u};

  inline explicit EntityLabeller(EntityIdMap &entity_ids_,
                                 PendingFragment &fragment_)
      : entity_ids(entity_ids_),
        fragment(fragment_) {}

  virtual ~EntityLabeller(void) = default;

  bool Enter(const pasta::Decl &entity) final;
  bool Enter(const pasta::Stmt &entity) final;
  bool Enter(const pasta::Type &entity) final;

  // Create initial fragment token IDs for all of the tokens in the range of
  // this fragment. This needs to be careful about assigning IDs to tokens that
  // aren't actually parsed, i.e. tokens whose roles are things like
  // intermediate macro expansions.
  //
  // NOTE(pag): This labeling process is tightly coupled with how tokens are
  //            serialized into fragments, and how token trees are serialized
  //            into fragments.
  bool Label(const pasta::Token &entity);

  // Create initial macro IDs for all of the top-level macros in the range of
  // this fragment.
  bool Label(const pasta::Macro &entity);
};

bool EntityLabeller::Enter(const pasta::Decl &entity) {
  auto kind = entity.Kind();
  mx::DeclarationId id;
  id.fragment_id = fragment.fragment_index;
  id.offset = static_cast<uint32_t>(fragment.decls_to_serialize.size());
  id.kind = mx::FromPasta(kind);
  id.is_definition = IsDefinition(entity);

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
  id.fragment_id = fragment.fragment_index;
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

bool EntityLabeller::Enter(const pasta::Type &entity) {
  auto kind = entity.Kind();
  mx::TypeId id;
  id.fragment_id = fragment.fragment_index;
  id.offset = static_cast<uint32_t>(fragment.types_to_serialize.size());
  id.kind = mx::FromPasta(kind);

  if (entity_ids.emplace(entity.RawType(), id).second) {

    // NOTE(pag): Will visit in `PendingTokenRange::Build()`.
    fragment.types_to_serialize.emplace_back(entity);
    return true;

  } else {
    return false;
  }
}

// Create initial fragment token IDs for all of the tokens in the range of
// this fragment. This needs to be careful about assigning IDs to tokens that
// aren't actually parsed, i.e. tokens whose roles are things like
// intermediate macro expansions.
//
// NOTE(pag): This labeling process is tightly coupled with how tokens are
//            serialized into fragments, and how token trees are serialized
//            into fragments.
bool EntityLabeller::Label(const pasta::Token &entity) {
  auto index = entity.Index();
  CHECK_LE(fragment.begin_index, index);
  CHECK_LE(index, fragment.end_index);

  mx::ParsedTokenId id;
  switch (entity.Role()) {
    // This is a token that actually reached the parser.
    case pasta::TokenRole::kFileToken:
    case pasta::TokenRole::kFinalMacroExpansionToken:
      id.offset = next_parsed_token_index++;
      break;

    // Alias whatever the next ID to be generated is.
    case pasta::TokenRole::kBeginOfFileMarker:
    case pasta::TokenRole::kBeginOfMacroExpansionMarker:
    case pasta::TokenRole::kInitialMacroUseToken:
    case pasta::TokenRole::kIntermediateMacroExpansionToken:
//      id.offset = next_parsed_token_index;
      return false;

    // Alias whatever the previous ID to be generated is.
    case pasta::TokenRole::kEndOfFileMarker:
    case pasta::TokenRole::kEndOfMacroExpansionMarker:
//      CHECK_LT(0u, next_parsed_token_index);
//      id.offset = next_parsed_token_index - 1u;
      return false;

    case pasta::TokenRole::kInvalid:
    case pasta::TokenRole::kEndOfInternalMacroEventMarker:
      return false;
  }

  id.fragment_id = fragment.fragment_index;
  id.kind = TokenKindFromPasta(entity);

  return entity_ids.emplace(entity.RawToken(), id).second;
}

// Create initial macro IDs for all of the top-level macros in the range of
// this fragment.
bool EntityLabeller::Label(const pasta::Macro &entity) {
  mx::MacroId id;
  id.kind = mx::FromPasta(entity.Kind());
  id.fragment_id = fragment.fragment_index;
  id.offset = static_cast<uint32_t>(fragment.macros_to_serialize.size());

  // If we added this node (we should have), then add in a `nullopt` reservation
  // to `macros_to_serialize`.
  //
  // NOTE(pag): `CountSubstitutions` in Persist.cpp fills in the empty slots.
  if (entity_ids.emplace(entity.RawMacro(), id).second) {
    fragment.macros_to_serialize.emplace_back();
    return true;

  } else {
    LOG(FATAL) << "Top-level macro already labelled?";
    return false;
  }
}

}  // namespace

// Label the initial entities of this fragment. This focuses on finding the
// entities that syntactically belong to this fragment, and assigning them
// IDs. Labeling happens first for all fragments, then we run `Build` for
// new fragments that we want to serialize.
void LabelEntitiesInFragment(PendingFragment &pf, EntityIdMap &entity_ids,
                             const pasta::TokenRange &tok_range) {
  EntityLabeller labeller(entity_ids, pf);

  for (uint64_t i = pf.begin_index; i <= pf.end_index; ++i) {
    pasta::Token tok = tok_range[i];
    if (IsParsedToken(tok)) {
      (void) labeller.Label(tok);
    }
  }

  // Go top-down through the top-level declarations of this pending fragment
  // and build up an initial list of `decls_to_serialize` and
  // `stmts_to_serialize`. This list will be expanded to fixpoint by
  // `PendingFragment::Build`.
  //
  // This process is manual, as opposed to `PendingFragment::Build` being a
  // more automated process, because the "hands on touch" of the manual effort
  // lets us be a bit more decisive about what should actually belong to a given
  // fragment, and stop when we go too far, whereas the automated approach might
  // just scoop everything reachable into a fragment, even if it doesn't really
  // belong there.
  for (const pasta::Decl &decl : pf.top_level_decls) {
    (void) labeller.Accept(decl);
  }

  for (const pasta::Macro &macro : pf.top_level_macros) {
    (void) labeller.Label(macro);
  }
}

}  // namespace indexer
