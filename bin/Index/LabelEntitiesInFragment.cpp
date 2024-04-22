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

// Figure out the fragment index of a given token.
static std::optional<mx::PackedFragmentId> IdentifyAsNestedFragmentToken(
    PendingFragment &pf, const pasta::PrintedToken &tok,
    bool might_have_nested_fragments) {

#define D(...)

  auto frag_index = pf.fragment_index;

  // If we're dealing with printed tokens, then we need to manually determine
  // which tokens needs to be excised. This is somewhat tedious as it involves
  // the token contexts.
  if (pf.parsed_tokens_are_printed) {

    D( std::cerr << tok.Index() << ' ' << tok.Data() << '\n'; )

    mx::RawEntityId parent_frag_index = pf.fragment_index;
    if (pf.raw_parent_entity) {
      auto parent_eid = pf.em.EntityId(pf.raw_parent_entity);
      if (auto parent_did = mx::EntityId(parent_eid).Extract<mx::DeclId>()) {
        parent_frag_index = parent_did->fragment_id;
        D( std::cerr << "\tparent frag index is " << parent_frag_index << '\n'; )
      }
    }

    for (const pasta::TokenContext &ctx : TokenContexts(tok)) {
      auto kind = ctx.Kind();
      if (pasta::TokenContextKind::kAST == kind) {
        break;
      }

      if (pasta::TokenContextKind::kDecl != kind) {
        D( std::cerr << "\tresetting on " << ctx.KindName() << '\n'; )
        frag_index = pf.fragment_index;
        continue;
      }

      auto did = mx::EntityId(pf.em.EntityId(ctx.Data())).Extract<mx::DeclId>();
      if (!did) {
        D( std::cerr << "\tno decl id\n"; )
        continue;
      }

      auto decl_frag_index = did->fragment_id;

      if (decl_frag_index == pf.fragment_index) {
        if (frag_index != pf.fragment_index) {
          D( std::cerr << "\t\texiting on next same frag\n"; )
          break;
        }

        D( std::cerr << "\t\tsame frag: " << pf.fragment_index << '\n'; )
        break;
      }

      if (decl_frag_index == parent_frag_index) {
        D( std::cerr << "\t\texiting to parent frag\n"; )
        frag_index = pf.fragment_index;
        break;
      }

      D( std::cerr << "\t\tfound: " << decl_frag_index << '\n'; )
      frag_index = decl_frag_index;
    }

  // If we're dealing with parsed tokens, then we might need to excise some
  // template code.
  } else if (might_have_nested_fragments) {

    auto pt = tok.DerivedLocation();
    if (!pt) {
      assert(false);
      return std::nullopt;
    }

    // Find the largest interval that is contained within `pf` that contains
    // `pt`. We only want the largest (i.e. outermost) one, because any smaller
    // ones nested inside of that will be discovered (via this mechanism) as
    // nested fragments of that fragment.
    mx::EntityOffset max_interval_size = 0u;
    pf.em.nested_fragment_bounds.visit_overlapping(
        pt->Index(),
        [&] (const FragmentBounds &bounds) {
          auto interval_size = bounds.stop - bounds.start + 1u;
          auto interval_frag = bounds.value.Unpack().fragment_id;
          if (interval_size > max_interval_size &&
              interval_frag != pf.fragment_index &&
              bounds.start > pf.first_parsed_token_index &&
              bounds.stop < pf.last_parsed_token_index) {
            max_interval_size = interval_size;
            frag_index = interval_frag;
          }
        });

  } else {
      return std::nullopt;
  }

  if (frag_index == pf.fragment_index) {
      return std::nullopt;
  }

  return mx::FragmentId(frag_index);
}

// Search for gaps between two tokens identified in the same nested fragment,
// and then fill them.
static void IdentifyNestedFragmentTokens(
    PendingFragment &pf, bool might_have_nested_fragments) {

  if (!pf.parsed_tokens_are_printed && !might_have_nested_fragments) {
    return;
  }

  std::optional<std::pair<mx::EntityOffset, mx::PackedFragmentId>> prev;

  for (auto tok : pf.parsed_tokens) {
    auto fid = IdentifyAsNestedFragmentToken(
        pf, tok, might_have_nested_fragments);

    if (!fid) {
      continue;
    }

    auto ti = tok.Index();
    if (prev && (prev->first + 1u) < ti && prev->second == fid.value()) {
      for (auto i = prev->first + 1u; i < ti; ++i) {
        pf.token_to_nested_fragment.emplace(
            RawEntity(pf.parsed_tokens[i]), fid.value());
      }
    }

    pf.token_to_nested_fragment.emplace(RawEntity(tok), fid.value());

    prev.reset();
    prev.emplace(ti, fid.value());
  }
}

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

  // Vector of the next declarations to visit. This lets us do breadth-first
  // visiting.
  std::vector<pasta::Decl> next_decls;

  explicit EntityLabeller(PendingFragment &fragment_);

  virtual ~EntityLabeller(void);

  bool Enter(const pasta::Decl &entity) final;

  void Accept(const pasta::Decl &entity) final;

  // Don't enter these.
  void Accept(const pasta::Stmt &) final {}
  void Accept(const pasta::Type &) final {}
  void Accept(const pasta::Attr &) final {}

  // NOTE(pag): Don't label statements as they are not referenceable across
  //            fragments, and if we did label them, then we'd want them to
  //            be fragment-specific, and that data would get wiped out by
  //            `EntityMapper::ResetForFragment`.
  bool Enter(const pasta::Stmt &) final {
    return true;
  }

  // NOTE(pag): Don't recursively descend into types. We may end up walking
  //            from a `FunctionProtoType` into a `typedef` (e.g. an argument
  //            or return value type), and that `typedef` is likely part of
  //            a different fragment, and we don't want to pull in things like
  //            structures from that other fragment.
  //
  // NOTE(pag): We can't rely on the order of types being deterministic for
  //            the "same" fragment in different translation units.
  bool Enter(const pasta::Type &) final {
    return false;
  }

  // NOTE(pag): Don't go into attributes. They can be shared by multiple
  //            fragments, and can contain types / statements. We'll deal with
  //            them later and more comprehensively during the building phase.
  //
  //            Another reason not to visit these is that because they can be
  //            duplicated so much, it means we sometimes internalize the
  //            duplicated versions into fragments, but this mechanism uses
  //            per-fragment storage in the `EntityLabeller`, which gets
  //            cleaned out between fragment persisting by
  //            `EntityMapper::ResetForFragment`, so we don't want to give
  //            something an ID, then lose track of it, and then assign a
  //            new ID to it. That would result in a kind of double
  //            serialization.
  bool Enter(const pasta::Attr &attr) final {
    return false;
  }

  void Run(void);

  // Create initial fragment token IDs for all of the tokens in the range of
  // this fragment. This needs to be careful about assigning IDs to tokens that
  // aren't actually parsed, i.e. tokens whose roles are things like
  // intermediate macro expansions.
  //
  // NOTE(pag): This labeling process is tightly coupled with how tokens are
  //            serialized into fragments, and how token trees are serialized
  //            into fragments.
  bool Label(const pasta::PrintedToken &entity);

  // Create initial macro IDs for all of the top-level macros in the range of
  // this fragment.
  bool Label(const pasta::Macro &entity);

  private:
   bool ShouldLabelDecl(const pasta::Decl &decl);
};

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
  next_decls.emplace_back(entity);
}

void EntityLabeller::Run(void) {
  std::vector<pasta::Decl> curr_decls;

  while (!next_decls.empty()) {
    curr_decls.swap(next_decls);
    next_decls.clear();
    for (const auto &decl : curr_decls) {
      this->EntityVisitor::Accept(decl);
    }
  }
}

bool EntityLabeller::ShouldLabelDecl(const pasta::Decl &decl) {
  if (!em.IsTopLevel(decl)) {
    return true;
  }

  // If we've encountered a top-level declaration, then make sure it's part of
  // this fragment. We don't want to enter into another fragment.
  auto end = fragment.top_level_decls.end();
  if (std::find(fragment.top_level_decls.begin(), end, decl) != end) {
    return true;
  }

  return false;
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
  auto raw_entity = RawEntity(entity);

  // Figure out if this token is in a sub-range of tokens belonging to a
  // nested fragment.
  if (fragment.token_to_nested_fragment.count(raw_entity)) {
    return false;
  }

  mx::ParsedTokenId id;    
  id.offset = fragment.num_parsed_tokens++;
  id.fragment_id = fragment.fragment_index;
  id.kind = TokenKindFromPasta(entity);

  CHECK(em.token_tree_ids.emplace(raw_entity, id).second);

  std::optional<pasta::Token> pt = entity.DerivedLocation();
  if (!pt) {
    return true;
  }

  // NOTE(pag): We may see the same token come up multiple times, especially
  //            if this is purely printed tokens, rather than parsed tokens
  //            aligned with printed tokens. A good example is that the
  //            pure pretty-printed code will separately print the syntax for
  //            each attribute in its own `__attribute__` block, whereas in
  //            the pasrsed source code, multiple attributes may belong to the
  //            same syntactical block.
  em.token_tree_ids.emplace(RawEntity(pt.value()), id);

  return true;
}

// Create initial macro IDs for all of the top-level macros in the range of
// this fragment.
bool EntityLabeller::Label(const pasta::Macro &entity) {
  if (!IsVisibleAcrossFragments(entity)) {
    return false;
  }

  auto &entity_list = fragment.EntityListFor(entity);

  mx::MacroId id;
  id.kind = mx::FromPasta(entity.Kind());
  id.fragment_id = fragment.fragment_index;
  id.offset = static_cast<mx::EntityOffset>(entity_list.size());

  // Macro directives and macro `#define` parameters can be referenced by other
  // fragments that contain expansions of those definitions, and substitutions
  // of those parameters for arguments.
  CHECK(em.entity_ids.emplace(entity.RawMacro(), id).second);

  // CHECK(em.token_tree_ids.emplace(entity.RawMacro(), id).second);

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

}  // namespace

// Initialize the entity labeller for a fragment. This focuses only on the top-
// level entities.
void InitializeEntityLabeller(PendingFragment &pf) {

  EntityLabeller labeller(pf);

  // TODO(pag): Define macro directives and their parameters need to be
  //            part of the global entity map, not the per-fragment ones.
  //
  //            Make sure to check and fix uses of `PerFragmentEntityId` in
  //            entity mapper.

  for (const auto &macro : pf.top_level_macros) {
    (void) labeller.Label(macro);
  }

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

  for (const pasta::Decl &decl : pf.top_level_decls) {
    (void) labeller.EntityVisitor::Accept(decl);
  }

  labeller.Run();
}

// Label the parsed tokens of this fragment. This focuses on finding the
// entities that syntactically belong to this fragment, and assigning them
// IDs. Labeling happens first for all fragments, then we run `Build` for
// new fragments that we want to serialize.
void LabelTokensInFragment(PendingFragment &pf) {

  if (pf.has_labelled_tokens) {
    return;  // Already done.
  }

  EntityLabeller labeller(pf);
  pf.has_labelled_tokens = true;

  auto might_have_nested_fragments =
      pf.num_top_level_declarations == 1u &&
      pf.file_location.has_value() &&
      (pf.first_parsed_token_index + 2u) <= pf.last_parsed_token_index;

  IdentifyNestedFragmentTokens(pf, might_have_nested_fragments);

  // Visit all of the tokens; it's possible we came across something that was
  // missed by the above process.
  for (auto tok : pf.parsed_tokens) {
    (void) labeller.Label(tok);
  }

  CHECK(labeller.next_decls.empty());
}

}  // namespace indexer
