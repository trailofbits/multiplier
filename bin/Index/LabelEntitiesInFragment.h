// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <vector>

#include "Visitor.h"

namespace pasta {
class Attr;
class Decl;
class Macro;
class Stmt;
class Type;
}  // namespace pasta
namespace indexer {

class EntityMapper;
class PendingFragment;

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

  std::vector<pasta::Decl> next_decls;
  std::vector<pasta::Stmt> next_stmts;
  std::vector<pasta::Type> next_types;

  // Tracks the index of the next parsed token. Logic surrounding this
  // processing is replicated when serializing `TokenTree`s. The key is that
  // we want to serialize the final parsed tokens, and not any marker tokens
  // or intermediate macro expansion tokens.
  unsigned next_parsed_token_index{0u};

  explicit EntityLabeller(PendingFragment &fragment_);

  virtual ~EntityLabeller(void);

  bool Enter(const pasta::Decl &entity) final;

  void Accept(const pasta::Decl &entity) final;

  // NOTE(pag): Don't label statements as they are not referenceable across
  //            fragments, and if we did label them, then we'd want them to
  //            be fragment-specific, and that data would get wiped out by
  //            `EntityMapper::ResetForFragment`.
  bool Enter(const pasta::Stmt &) final {
    return true;
  }

  void Accept(const pasta::Stmt &) final {}

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

  void Accept(const pasta::Type &entity) final;

  bool Enter(const pasta::Attr &attr) final;

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

// Initialize the entity labeller for a fragment. This focuses only on the top-
// level entities.
void InitializeEntityLabeller(PendingFragment &pf);

// Label the initial entities of this fragment. This focuses on finding the
// entities that syntactically belong to this fragment, and assigning them
// IDs. Labeling happens first for all fragments, then we run `Build` for
// new fragments that we want to serialize.
void LabelDeclsInFragment(PendingFragment &pf);

// Label the parsed tokens and macros of this fragment. This focuses on finding the
// entities that syntactically belong to this fragment, and assigning them
// IDs. Labeling happens first for all fragments, then we run `Build` for
// new fragments that we want to serialize.
void LabelTokensAndMacrosInFragment(PendingFragment &pf);

}  // namespace indexer
