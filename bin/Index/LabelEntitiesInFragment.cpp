// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <glog/logging.h>

#include <multiplier/Entities/MacroKind.h>

#include "Context.h"
#include "EntityMapper.h"
#include "PASTA.h"
#include "PendingFragment.h"
#include "TypeMapper.h"
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
  EntityMapper &em;
  PendingFragment &fragment;

  // Is this a new fragment? This affects whether or not we keep track of types.
  // We don't want `PendingFragment` for a pre-existing type to "take ownership"
  // of a type, only to have that pending fragment "thrown away" later (due to
  // it being redundant), yet have other fragments in the TU point to type IDs
  // that logically belong to this type.
  const bool is_new_fragment{true};

  std::vector<pasta::Decl> next_decls;
  std::vector<pasta::Stmt> next_stmts;
  std::vector<pasta::Type> next_types;

  // Tracks the index of the next parsed token. Logic surrounding this
  // processing is replicated when serializing `TokenTree`s. The key is that
  // we want to serialize the final parsed tokens, and not any marker tokens
  // or intermediate macro expansion tokens.
  unsigned next_parsed_token_index{0u};

  inline explicit EntityLabeller(EntityMapper &em_,
                                 PendingFragment &fragment_,
                                 bool is_new_fragment_)
      : em(em_),
        fragment(fragment_),
        is_new_fragment(is_new_fragment_) {}

  virtual ~EntityLabeller(void) = default;

  bool Enter(const pasta::Decl &entity) final {
    return fragment.Add(entity, em.entity_ids);
  }

  bool Enter(const pasta::Stmt &entity) final {
    return fragment.Add(entity, em.entity_ids);
  }

  bool Enter(const pasta::Type &entity) final {
    if (is_new_fragment) {
      return fragment.Add(entity, em.tm);
    } else {
      return false;
    }
  }

  void Run(void) {
    std::vector<pasta::Decl> curr_decls;
    std::vector<pasta::Stmt> curr_stmts;
    std::vector<pasta::Type> curr_types;

    for (auto changed = true; changed; ) {
      changed = false;
      curr_decls.swap(next_decls);
      curr_stmts.swap(next_stmts);
      curr_types.swap(next_types);

      // NOTE(pag): Macros are handled in `Persist.cpp`, because we want to
      //            merge expansions and argument pre-expansion phases.

      next_decls.clear();
      next_stmts.clear();
      next_types.clear();

      for (const auto &entity : curr_decls) {
        changed = true;
        this->EntityVisitor::Accept(entity);
      }

      for (const auto &entity : curr_stmts) {
        changed = true;
        this->EntityVisitor::Accept(entity);
      }

      for (const auto &entity : curr_types) {
        changed = true;
        this->EntityVisitor::Accept(entity);
      }
    }
  }

  void Accept(const pasta::Decl &entity) final {
    next_decls.push_back(entity);
  }

  void Accept(const pasta::Stmt &entity) final {
    next_stmts.push_back(entity);
  }

  void Accept(const pasta::Type &entity) final {
    next_types.push_back(entity);
  }

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
      return false;

    // Alias whatever the previous ID to be generated is.
    case pasta::TokenRole::kEndOfFileMarker:
    case pasta::TokenRole::kEndOfMacroExpansionMarker:
      return false;

    case pasta::TokenRole::kInvalid:
    case pasta::TokenRole::kEndOfInternalMacroEventMarker:
      return false;
  }

  id.fragment_id = fragment.fragment_index;
  id.kind = TokenKindFromPasta(entity);

  return em.entity_ids.emplace(entity.RawToken(), id).second;
}

// Create initial macro IDs for all of the top-level macros in the range of
// this fragment.
bool EntityLabeller::Label(const pasta::Macro &entity) {
  mx::MacroId id;
  id.kind = mx::FromPasta(entity.Kind());
  id.fragment_id = fragment.fragment_index;
  id.offset = static_cast<mx::EntityOffset>(fragment.macros_to_serialize.size());

  // If we added this node (we should have), then add in a `nullopt` reservation
  // to `macros_to_serialize`.
  if (!em.entity_ids.emplace(entity.RawMacro(), id).second) {
    LOG(FATAL) << "Top-level macro already labelled?";
    return false;
  }

  // NOTE(pag): `TokenTreeSerializationSchedule::RecordEntityId` in Persist.cpp
  //            fills in the empty slots.
  fragment.macros_to_serialize.emplace_back();

  // Define directives should go and provide entity ids for their
  // parameters, as they can be referenced by `MacroParameterSubstitution`s.
  if (id.kind != mx::MacroKind::DEFINE_DIRECTIVE) {
    return true;
  }

  if (auto def = pasta::DefineMacroDirective::From(entity)) {
    for (pasta::Macro param : def->Parameters()) {
      Label(param);
    }
    return true;
  }

  assert(false);
  return true;
}

}  // namespace

// Label the initial entities of this fragment. This focuses on finding the
// entities that syntactically belong to this fragment, and assigning them
// IDs. Labeling happens first for all fragments, then we run `Build` for
// new fragments that we want to serialize.
void LabelEntitiesInFragment(PendingFragment &pf, EntityMapper &em,
                             const pasta::TokenRange &tok_range,
                             bool is_new_fragment) {
  EntityLabeller labeller(em, pf, is_new_fragment);

  // Go top-down through the top-level declarations of this pending fragment
  // and build up an initial list of `decls_to_serialize` and
  // `stmts_to_serialize`. This list will be expanded to fixpoint by
  // `PendingFragment::Build`.
  //
  // This process is manual, as opposed to `BuildPendingFragment` being a
  // more automated process, because the "hands on touch" of the manual effort
  // lets us be a bit more decisive about what should actually belong to a given
  // fragment, and stop when we go too far, whereas the automated approach might
  // just scoop everything reachable into a fragment, even if it doesn't really
  // belong there.
  //
  // NOTE(pag): We can do `labeller.Run` after all of the `Accept`s. This is
  //            what we used to do. To mitigate / limit the issues caused by
  //            #396 (https://github.com/trailofbits/multiplier/issues/396), we
  //            do it each time, so that the decls that should go into child
  //            fragments are at the end of the `pf.top_level_decls` list.

  assert(pf.decls_to_serialize.empty());

  for (const pasta::Decl &decl : pf.top_level_decls) {
    (void) labeller.Accept(decl);
    labeller.Run();
  }

  for (const pasta::Macro &macro : pf.top_level_macros) {
    (void) labeller.Label(macro);
  }

  // Visit all of the tokens; it's possible we came across something that was
  // missed by the above process.
  for (uint64_t i = pf.begin_index; i <= pf.end_index; ++i) {
    pasta::Token tok = tok_range[i];
    if (IsParsedToken(tok)) {
      (void) labeller.Label(tok);
    }
  }

  labeller.Run();
}

}  // namespace indexer
