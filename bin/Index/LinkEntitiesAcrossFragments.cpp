// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <multiplier/Database.h>

#include "EntityMapper.h"
#include "NameMangler.h"
#include "PendingFragment.h"

namespace indexer {
namespace {

static void TrackRedeclarations(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    const EntityMapper &em, const std::string &mangled_name,
    const pasta::Decl &decl, std::vector<pasta::Decl> redecls) {

  mx::RawEntityId a_id = em.EntityId(decl);
  mx::VariantId a_vid = mx::EntityId(a_id).Unpack();
  if (!std::holds_alternative<mx::DeclarationId>(a_vid)) {
    assert(false);
    return;
  }

  mx::DeclarationId decl_id = std::get<mx::DeclarationId>(a_vid);
  if (decl_id.fragment_id != pf.fragment_index) {
    assert(false);
    return;
  }

  database.AddAsync(mx::MangledNameRecord{a_id, mangled_name});

  for (const pasta::Decl &redecl : redecls) {
    mx::RawEntityId b_id = em.EntityId(redecl);
    if (a_id == b_id) {
      continue;
    }

    mx::VariantId b_vid = mx::EntityId(b_id).Unpack();
    if (!std::holds_alternative<mx::DeclarationId>(b_vid)) {
      assert(false);
      continue;
    }

    mx::DeclarationId redecl_id = std::get<mx::DeclarationId>(b_vid);
    database.AddAsync(mx::RedeclarationRecord{decl_id, redecl_id});
  }
}

}  // namespace

// Store information persistently to enable linking of declarations across
// fragments.
void LinkEntitiesAcrossFragments(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    const EntityMapper &em, const NameMangler &mangler) {

  std::string dummy_mangled_name;
  for (const pasta::Decl &decl : pf.decls_to_serialize) {
    mx::RawEntityId eid = em.EntityId(decl);
    if (eid == mx::kInvalidEntityId) {
      continue;
    }

    if (auto func = pasta::FunctionDecl::From(decl)) {
      const auto &mangled_name = mangler.Mangle(decl);
      TrackRedeclarations(
          database, pf, em,
          (mangler.MangledNameIsPrecise() ? mangled_name : dummy_mangled_name),
          decl, func->Redeclarations());

    } else if (auto var = pasta::VarDecl::From(decl)) {
      if (var->IsLocalVariableDeclaration()) {
        continue;
      }

      const auto &mangled_name = mangler.Mangle(decl);
      TrackRedeclarations(
          database, pf, em,
          (mangler.MangledNameIsPrecise() ? mangled_name : dummy_mangled_name),
          decl, var->Redeclarations());

    } else if (auto tag = pasta::TagDecl::From(decl)) {
      TrackRedeclarations(database, pf, em, dummy_mangled_name,
                          decl, tag->Redeclarations());

    } else if (auto tpl = pasta::RedeclarableTemplateDecl::From(decl)) {
      TrackRedeclarations(database, pf, em, dummy_mangled_name,
                          decl, tpl->Redeclarations());

    } else {
      continue;
    }
  }
}

}  // namespace indexer
