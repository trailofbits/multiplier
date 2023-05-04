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
#include "TypeFragment.h"

#include <glog/logging.h>

namespace indexer {
namespace {

static void TrackRedeclarations(
    mx::DatabaseWriter &database, mx::RawEntityId fragment_index,
    const EntityMapper &em, const std::string &mangled_name,
    const pasta::Decl &decl, std::vector<pasta::Decl> redecls) {

  mx::RawEntityId a_id = em.EntityId(decl);
  mx::VariantId a_vid = mx::EntityId(a_id).Unpack();
  if (!std::holds_alternative<mx::DeclId>(a_vid)) {
    assert(false);
    return;
  }

  mx::DeclId decl_id = std::get<mx::DeclId>(a_vid);
  if (decl_id.fragment_id != fragment_index) {
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
    if (!std::holds_alternative<mx::DeclId>(b_vid)) {
      assert(false);
      continue;
    }

    mx::DeclId redecl_id = std::get<mx::DeclId>(b_vid);
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
          database, pf.fragment_index, em,
          (mangler.MangledNameIsPrecise() ? mangled_name : dummy_mangled_name),
          decl, func->Redeclarations());

    } else if (auto var = pasta::VarDecl::From(decl)) {
      switch (var->Category()) {
        case pasta::DeclCategory::kGlobalVariable:
        case pasta::DeclCategory::kParameterVariable:
        case pasta::DeclCategory::kClassMember: {
          const auto &mangled_name = mangler.Mangle(decl);
          TrackRedeclarations(
              database, pf.fragment_index, em,
              (mangler.MangledNameIsPrecise() ? mangled_name : dummy_mangled_name),
              decl, var->Redeclarations());
          break;
        }
        default:
          break;
      }

    } else if (auto tag = pasta::TagDecl::From(decl)) {
      TrackRedeclarations(database, pf.fragment_index, em, dummy_mangled_name,
                          decl, tag->Redeclarations());

    } else if (auto tpl = pasta::RedeclarableTemplateDecl::From(decl)) {
      TrackRedeclarations(database, pf.fragment_index, em, dummy_mangled_name,
                          decl, tpl->Redeclarations());

    } else {
      continue;
    }
  }
}

}  // namespace indexer
