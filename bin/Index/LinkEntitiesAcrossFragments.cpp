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

static void TrackRedeclarations(mx::DatabaseWriter &database,
                                const EntityMapper &em,
                                const std::string &mangled_name,
                                std::vector<pasta::Decl> redecls) {
  for (const pasta::Decl &redecl_a : redecls) {
    mx::RawEntityId a = em.EntityId(redecl_a);
    if (!a) {
      continue;
    }

    mx::VariantId a_vid = mx::EntityId(a).Unpack();
    if (!std::holds_alternative<mx::DeclarationId>(a_vid)) {
      assert(false);
      continue;
    }

    mx::DeclarationId a_id = std::get<mx::DeclarationId>(a_vid);

    database.AddAsync(mx::MangledNameRecord{a, mangled_name});

    for (const pasta::Decl &redecl_b : redecls) {
      mx::RawEntityId b = em.EntityId(redecl_b);
      if (a == b || !b) {
        continue;
      }

      mx::VariantId b_vid = mx::EntityId(b).Unpack();
      if (!std::holds_alternative<mx::DeclarationId>(b_vid)) {
        assert(false);
        continue;
      }

      mx::DeclarationId b_id = std::get<mx::DeclarationId>(b_vid);
      database.AddAsync(mx::RedeclarationRecord{a_id, b_id},
                        mx::RedeclarationRecord{b_id, a_id});
    }
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
          database, em,
          (mangler.MangledNameIsPrecise() ? mangled_name : dummy_mangled_name),
          func->Redeclarations());

    } else if (auto var = pasta::VarDecl::From(decl)) {
      if (var->IsLocalVariableDeclaration()) {
        continue;
      }

      const auto &mangled_name = mangler.Mangle(decl);
      TrackRedeclarations(
          database, em,
          (mangler.MangledNameIsPrecise() ? mangled_name : dummy_mangled_name),
          var->Redeclarations());

    } else if (auto tag = pasta::TagDecl::From(decl)) {
      TrackRedeclarations(database, em, dummy_mangled_name,
                          tag->Redeclarations());

    } else if (auto tpl = pasta::RedeclarableTemplateDecl::From(decl)) {
      TrackRedeclarations(database, em, dummy_mangled_name,
                          tpl->Redeclarations());

    } else {
      continue;
    }
  }
}

}  // namespace indexer
