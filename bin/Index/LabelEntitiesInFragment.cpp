// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <glog/logging.h>

#include <multiplier/Frontend/MacroKind.h>

#include "Context.h"
#include "EntityMapper.h"
#include "PASTA.h"
#include "PendingFragment.h"
#include "TypeMapper.h"
#include "Util.h"

#include "LabelEntitiesInFragment.h"

namespace indexer {
namespace {

static bool IsAcceptableRepeatedToken(const pasta::Token &tok) {
  switch (tok.Kind()) {
    case pasta::TokenKind::kUnknown:
    case pasta::TokenKind::kKeyword__Attribute:
    case pasta::TokenKind::kKeyword__Declspec:
    case pasta::TokenKind::kLParenthesis:
    case pasta::TokenKind::kRParenthesis:
      return true;
    default:
      return false;
  }
}

}  // namespace

EntityLabeller::~EntityLabeller(void) {};

EntityLabeller::EntityLabeller(PendingFragment &fragment_)
    : em(fragment_.em),
      fragment(fragment_) {}

bool EntityLabeller::Enter(const pasta::Decl &entity) {
  if (ShouldHideFromIndexer(entity)) {
    return false;
  }

  if (!ShouldLabelDecl(entity)) {
    return false;
  }
  
  if (!fragment.TryAdd(entity)) {
    return false;
  }

  return true;
}

void EntityLabeller::Accept(const pasta::Decl &entity) {
  next_decls.push_back(entity);
}

void EntityLabeller::Accept(const pasta::Type &entity) {
  next_types.push_back(entity);
}

bool EntityLabeller::Enter(const pasta::Attr &attr) {
  fragment.TryAdd(attr);

  // NOTE(pag): Want to return `true` because some attributes contain constant
  //            expressions.
  //
  // TODO(pag): Consider `return fragment.TryAdd`, given that it now has logic
  //            to figure out if the attribute ought belong to this fragment
  //            or not.
  return true;
}

void EntityLabeller::Run(void) {
  std::vector<pasta::Decl> curr_decls;
  std::vector<pasta::Type> curr_types;

  for (auto changed = true; changed; ) {
    changed = false;
    curr_decls.swap(next_decls);
    curr_types.swap(next_types);

    // NOTE(pag): Macros are handled in `Persist.cpp`, because we want to
    //            merge expansions and argument pre-expansion phases.

    next_decls.clear();
    next_types.clear();

    for (const pasta::Decl &entity : curr_decls) {
      changed = true;
      this->EntityVisitor::Accept(entity);
    }

    for (const pasta::Type &entity : curr_types) {
      changed = true;
      this->EntityVisitor::Accept(entity);
    }
  }
}

bool EntityLabeller::ShouldLabelDecl(const pasta::Decl &decl) {
  if (!em.IsTopLevel(decl)) {
    return true;
  }

  auto end = fragment.top_level_decls.end();
  return std::find(fragment.top_level_decls.begin(), end, decl) != end;
}

// Create initial fragment token IDs for all of the tokens in the range of
// this fragment. This needs to be careful about assigning IDs to tokens that
// aren't actually parsed, i.e. tokens whose roles are things like
// intermediate macro expansions.
//
// NOTE(pag): This labeling process is tightly coupled with how tokens are
//            serialized into fragments, and how token trees are serialized
//            into fragments.
bool EntityLabeller::Label(const pasta::PrintedToken &entity) {
  CHECK(fragment.parsed_tokens.Contains(entity));
  mx::ParsedTokenId id;    
  id.offset = next_parsed_token_index++;
  id.fragment_id = fragment.fragment_index;
  id.kind = TokenKindFromPasta(entity);

  CHECK(em.token_tree_ids.emplace(RawEntity(entity), id).second);

  if (std::optional<pasta::Token> pt = entity.DerivedLocation()) {

    // NOTE(pag): This can happen where a printed attribute ends up referring
    //            back to a macro directive marker, where the macro directive
    //            is something like the following:
    //
    //    #pragma clang attribute push(__attribute__((...)), apply_to=...)
    //
    //            These kinds of attributes are annoying because they don't
    //            communicate that they were implicitly applied.
    if (!IsParsedToken(pt.value())) {
      CHECK(pt->Role() == pasta::TokenRole::kMacroDirectiveMarker);
      return true;
    }

    auto raw_pt = RawEntity(pt.value());

    // NOTE(pag): We may see the same token come up multiple times, especially
    //            if this is purely printed tokens, rather than parsed tokens
    //            aligned with printed tokens. A good example is that the
    //            pure pretty-printed code will separately print the syntax for
    //            each attribute in its own `__attribute__` block, whereas in
    //            the pasrsed source code, multiple attributes may belong to the
    //            same syntactical block.
    if (!em.token_tree_ids.emplace(raw_pt, id).second) {
      LOG_IF(ERROR, !IsAcceptableRepeatedToken(pt.value()))
            << "Token kind " << pt.value().KindName()
            << " is repeated and exist in the token tree!";
    }
  }

  // // If we didn't just add the token, then we should be in the nested fragment
  // // case, and we want to overwrite the token id.
  // if (!res.second) {
  //   mx::EntityId prev_id(res.first->second);
  //   CHECK_NE(prev_id.Extract<mx::ParsedTokenId>()->fragment_id,
  //            fragment.fragment_index);
  //   res.first->second = id;
  // }

  return true;
}

// Create initial macro IDs for all of the top-level macros in the range of
// this fragment.
bool EntityLabeller::Label(const pasta::Macro &entity) {
  auto &entity_list = fragment.EntityListFor(entity);

  mx::MacroId id;
  id.kind = mx::FromPasta(entity.Kind());
  id.fragment_id = fragment.fragment_index;
  id.offset = static_cast<mx::EntityOffset>(entity_list.size());

  // Macro directives and macro `#define` parameters can be referenced by other
  // fragments that contain expansions of those definitions, and substitutions
  // of those parameters for arguments.
  if (AreVisibleAcrossFragments(entity)) {
    CHECK(em.entity_ids.emplace(entity.RawMacro(), id).second);
  }

  CHECK(em.token_tree_ids.emplace(entity.RawMacro(), id).second);

  // NOTE(pag): `TokenTreeSerializationSchedule::RecordEntityId` in Persist.cpp
  //            fills in the empty slots.
  fragment.EntityListFor(entity).emplace_back();

  // Define directives should go and provide entity ids for their
  // parameters, as they can be referenced by `MacroParameterSubstitution`s.
  if (id.kind != mx::MacroKind::DEFINE_DIRECTIVE) {
    return true;
  }

  auto def = pasta::DefineMacroDirective::From(entity);
  if (!def) {
    DCHECK(false);
    return true;
  }

  for (pasta::Macro param : def->Parameters()) {
    Label(param);
  }

  return true;
}

// Initialize the entity labeller for a fragment. This focuses only on the top-
// level entities.
void InitializeEntityLabeller(PendingFragment &pf) {
  CHECK(!pf.has_labelled_decls);
  CHECK(!pf.labeller);

  pf.labeller.reset(new EntityLabeller(pf));

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

  CHECK(pf.decls_to_serialize.empty());

#ifndef NDEBUG
  const EntityMapper &em = pf.em;
   // The NDEBUG condition check will get hit often if we add all template
   // and specialization AST node as new TLDS. The TLD may be reached from the 
   // other fragment causing the id to exist in the mapper.
  for (const pasta::Decl &decl : pf.top_level_decls) {
    CHECK_EQ(em.EntityId(decl), mx::kInvalidEntityId);
  }
#endif

  for (const pasta::Decl &decl : pf.top_level_decls) {
    (void) pf.labeller->EntityVisitor::Accept(decl);
  }
}

// Label the initial entities of this fragment. This focuses on finding the
// entities that syntactically belong to this fragment, and assigning them
// IDs. Labeling happens first for all fragments, then we run `Build` for
// new fragments that we want to serialize.
void LabelDeclsInFragment(PendingFragment &pf) {
  CHECK(!!pf.labeller);

  if (pf.has_labelled_decls) {
    return;
  }

  pf.has_labelled_decls = true;

#ifndef NDEBUG
  const EntityMapper &em = pf.em;
   // The NDEBUG condition check will get hit often if we add all template
   // and specialization AST node as new TLDS. The TLD may be reached from the 
   // other fragment causing the id to exist in the mapper.
  for (const pasta::Decl &decl : pf.top_level_decls) {
    CHECK_NE(em.EntityId(decl), mx::kInvalidEntityId);
  }
#endif

  pf.labeller->Run();
}

// Label the parsed tokens and macros of this fragment. This focuses on finding the
// entities that syntactically belong to this fragment, and assigning them
// IDs. Labeling happens first for all fragments, then we run `Build` for
// new fragments that we want to serialize.
void LabelTokensAndMacrosInFragment(PendingFragment &pf) {

  if (pf.has_labelled_tokens) {
    return;  // Already done.
  }

  pf.has_labelled_tokens = true;

  EntityLabeller labeller(pf);

  // TODO(pag): Define macro directives and their parameters need to be
  //            part of the global entity map, not the per-fragment ones.
  //
  //            Make sure to check and fix uses of `PerFragmentEntityId` in
  //            entity mapper.

  for (const pasta::Macro &macro : pf.top_level_macros) {
    (void) pf.labeller->Label(macro);
  }

  // Visit all of the tokens; it's possible we came across something that was
  // missed by the above process.
  for (pasta::PrintedToken tok : pf.parsed_tokens) {
    (void) pf.labeller->Label(tok);
  }

  pf.labeller->Run();
}

}  // namespace indexer
