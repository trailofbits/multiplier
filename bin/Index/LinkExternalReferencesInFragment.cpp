// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <multiplier/Database.h>
#include <multiplier/Entities/MacroKind.h>
#include <multiplier/Types.h>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Stmt.h>
#include <pasta/Util/File.h>
#include <unordered_set>

#include "EntityMapper.h"
#include "PASTA.h"
#include "PendingFragment.h"
#include "TokenTree.h"
#include "Util.h"

namespace indexer {

// Identify the reference kind and update the records. The function
// goes through the AST node of referrer and assigned the reference
// kind for the decl. The functions are defined in `References.cpp`
extern void DeclReferenceKind(
    const pasta::AST &ast, const EntityMapper &em,
    const pasta::Stmt &stmt, const pasta::Decl &ref,
     mx::ReferenceRecord &record);

extern void DeclReferenceKind(
    const pasta::AST &ast, const EntityMapper &em,
    const pasta::Decl &decl, const pasta::Decl &ref,
    mx::ReferenceRecord &record);

extern void DeclReferenceKind(
    const pasta::AST &ast, const EntityMapper &em,
    const pasta::Designator &designator, const pasta::Decl &ref,
    mx::ReferenceRecord &record);

namespace {

template <typename Entity>
static void AddDeclReferenceFrom(
    const pasta::AST &ast, mx::DatabaseWriter &database, const EntityMapper &em,
    const Entity &from_entity, mx::RawEntityId from_id,
    const pasta::Decl &to_entity) {
  
  mx::RawEntityId to_id = em.EntityId(to_entity);
  mx::VariantId vid = mx::EntityId(to_id).Unpack();
  if (!std::holds_alternative<mx::DeclId>(vid)) {
    assert(false);
    return;
  }

  // The referer context id will be same as `from_id` by default. The
  // DeclReferenceKind function updates it based on the AST analysis
  // of the context in which declaration is referred.
  mx::ReferenceRecord record{
      from_id, to_id, from_id, mx::BuiltinReferenceKind::USE};
  DeclReferenceKind(ast, em, from_entity, to_entity, record);
  database.AddAsync(record);
}

template <typename EntityId, typename EntityKindListMap>
static void AddDeclReferencesFrom(
    const pasta::AST &ast, mx::DatabaseWriter &database,
    const PendingFragment &pf,
    const EntityKindListMap &entities) {

  for (auto from_entity : Entities(entities)) {
    mx::RawEntityId from_id = pf.em.EntityId(from_entity);
    mx::VariantId vid = mx::EntityId(from_id).Unpack();

    if (!std::holds_alternative<EntityId>(vid)) {
      assert(false);
      continue;
    }

    EntityId eid = std::get<EntityId>(vid);
    if (eid.fragment_id != pf.fragment_index) {
      assert(false);
      continue;  // This is weird?
    }

    for (pasta::Decl to_entity : DeclReferencesFrom(from_entity)) {
      AddDeclReferenceFrom(ast, database, pf.em, from_entity, from_id, to_entity);
    }
  }
}

}  // namespace

// Identify all unique entity IDs referenced by this fragment,
// and map them to the fragment ID in the data store.
void LinkExternalReferencesInFragment(
    const pasta::AST &ast, mx::DatabaseWriter &database,
    const PendingFragment &pf) {

  const EntityMapper &em = pf.em;
  
  // XREF(pag): Issue #214. We want to record references to other decls that are
  //            expressed in types. In PASTA, we don't present Clang's
  //            `TypeLoc`s, so we need to instead go through the types to find
  //            which ones are explicitly referenced.
  AddDeclReferencesFrom<mx::DeclId>(ast, database, pf, pf.decls_to_serialize);
  AddDeclReferencesFrom<mx::StmtId>(ast, database, pf, pf.stmts_to_serialize);

  // XREF(pag): Issue #192. Make sure we record references from designators
  //            to fields.
  for (pasta::Designator from_entity : Entities(pf.designators_to_serialize)) {
    mx::RawEntityId from_id = em.EntityId(from_entity);
    mx::VariantId vid = mx::EntityId(from_id).Unpack();
    if (!std::holds_alternative<mx::DesignatorId>(vid)) {
      assert(false);
      continue;
    }

    auto to_field = from_entity.Field();
    if (!to_field) {
      continue;
    }

    AddDeclReferenceFrom(ast, database, pf.em,
                         from_entity, from_id, to_field.value());
  }

  for (auto maybe_tt : Entities(pf.macros_to_serialize)) {
    if (!maybe_tt) {

      // TODO(pag): Remove this assertion later; really it's a failure to
      //            construct a token tree, and we do have a backup path
      //            in `Persist.cpp`.
      assert(false);
      continue;
    }

    const TokenTree &tt = maybe_tt.value();
    std::optional<pasta::Macro> maybe_macro = tt.Macro();
    if (!maybe_macro) {
      continue;
    }

    const pasta::Macro &m = maybe_macro.value();
    mx::RawEntityId macro_id = em.EntityId(tt);
    if (macro_id == mx::kInvalidEntityId) {
      macro_id = em.EntityId(m);
    }

    mx::VariantId vid = mx::EntityId(macro_id).Unpack();
    if (!std::holds_alternative<mx::MacroId>(vid)) {
      assert(false);
      continue;
    }

    mx::MacroId mid = std::get<mx::MacroId>(vid);
    if (mid.fragment_id != pf.fragment_index) {
      assert(false);
      continue;  // This is weird?
    }

    switch (tt.Kind()) {
      default:
        break;

      // Have the expansion marked as a reference of the definition.
      case mx::MacroKind::EXPANSION:
        if (auto exp = pasta::MacroExpansion::From(m)) {
          std::optional<pasta::DefineMacroDirective> def = exp->Definition();
          if (!def) {
            continue;
          }

          mx::RawEntityId def_id = em.EntityId(def.value());
          vid = mx::EntityId(def_id).Unpack();
          if (!std::holds_alternative<mx::MacroId>(vid)) {
            auto macro_name = def->Name();
            if (!macro_name) {
              continue;  // Probably in a conditionally disabled region.
            }

            // Builtin or command-line specified macros have no location.
            //
            // NOTE(pag): The persistence for macros re-interprets macros with
            //            no definition site as substitutions instead of macro
            //            expansions.
            //
            // TODO(pag): Find a way to give these file locations. See related
            //            issue/condition in `FindTLMs` in file
            //            `bin/Index/IndexCompileJob.cpp`.
            if (!macro_name->FileLocation()) {
              continue;
            }

            assert(false);
            continue;
          }

          // The referrer context id will be same as `macro_id` by default
          // and assigned the same.
          database.AddAsync(mx::ReferenceRecord{
              macro_id, def_id, macro_id, mx::BuiltinReferenceKind::EXPANSION_OF});
        }
        break;

      // Files are always treated as references.
      case mx::MacroKind::INCLUDE_DIRECTIVE:
      case mx::MacroKind::INCLUDE_MACROS_DIRECTIVE:
      case mx::MacroKind::INCLUDE_NEXT_DIRECTIVE:
      case mx::MacroKind::IMPORT_DIRECTIVE:
        if (auto inc = pasta::IncludeLikeMacroDirective::From(m)) {
          std::optional<pasta::File> f = inc->IncludedFile();
          if (!f) {
            continue;
          }

          mx::RawEntityId file_id = em.EntityId(f.value());
          vid = mx::EntityId(file_id).Unpack();
          if (!std::holds_alternative<mx::FileId>(vid)) {
            assert(false);
            continue;
          }

          // The referrer context id will be same as `macro_id` by default
          // and assigned the same.
          database.AddAsync(mx::ReferenceRecord{
              macro_id, file_id, macro_id, mx::BuiltinReferenceKind::INCLUSION});
        }
        break;
    }
  }
}

}  // namespace indexer
