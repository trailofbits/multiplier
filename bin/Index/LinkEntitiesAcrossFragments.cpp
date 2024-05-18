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

#include <glog/logging.h>

namespace indexer {
namespace {

static void TrackRedeclarations(
    mx::DatabaseWriter &database, mx::RawEntityId fragment_index,
    const EntityMapper &em, const std::string &mangled_name,
    const pasta::Decl &decl, std::vector<pasta::Decl> redecls) {

  auto raw_decl_id = em.EntityId(decl);
  auto decl_id = mx::EntityId(raw_decl_id).Extract<mx::DeclId>();
  if (!decl_id) {
    return;
  }

  if (decl_id->fragment_id != fragment_index) {
    assert(false);
    return;
  }

  // If the mangled_name is empty, it should not be added to the table.
  // It goes around it and add redecls to the redecl record table.
  if (!mangled_name.empty()) {
    database.AddAsync(mx::MangledNameRecord{raw_decl_id, mangled_name});
  }

  for (const pasta::Decl &redecl : redecls) {

    auto redecl_id = em.SpecificEntityId<mx::DeclId>(redecl);
    if (!redecl_id || decl_id.value() == redecl_id.value()) {
      continue;
    }

    database.AddAsync(mx::RedeclarationRecord{
        decl_id.value(), redecl_id.value()});
  }
}

// Fill in the `CONTAINS` relation.
void LinkLexicalDeclContext(
    mx::DatabaseWriter &database, const EntityMapper &em,
    const pasta::Decl &decl, mx::RawEntityId child_eid) {
  std::optional<pasta::DeclContext> dc =
      IsLambda(decl) ? decl.DeclarationContext() :
      decl.LexicalDeclarationContext();

  if (!dc) {
    return;
  }

  auto dc_decl = pasta::Decl::From(dc.value());
  if (!dc_decl) {
    return;
  }

  auto parent_eid = em.EntityId(dc_decl);
  if (parent_eid == mx::kInvalidEntityId) {
    return;
  }

  if (parent_eid == child_eid) {
    assert(false);
    return;
  }

  assert(decl.CanonicalDeclaration() != dc_decl->CanonicalDeclaration());

  mx::ReferenceRecord record{parent_eid, child_eid, parent_eid,
                             mx::BuiltinReferenceKind::CONTAINS};
  database.AddAsync(record);
}

}  // namespace

// Store information persistently to enable linking of declarations across
// fragments.
void LinkEntitiesAcrossFragments(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    const NameMangler &mangler) {

  const EntityMapper &em = pf.em;

  std::string dummy_mangled_name;
  for (const pasta::Decl &decl : Entities(pf.decls_to_serialize)) {
    mx::RawEntityId eid = em.EntityId(decl);
    if (eid == mx::kInvalidEntityId) {
      assert(false);
      continue;
    }

    if (auto func = pasta::FunctionDecl::From(decl)) {
      const auto &mangled_name = mangler.Mangle(decl);
      TrackRedeclarations(
          database, pf.fragment_index, em,
          (mangler.MangledNameIsPrecise() ? mangled_name : dummy_mangled_name),
          decl, func->Redeclarations());

      // Don't mark a function template pattern as being part of a class.
      if (!func->DescribedFunctionTemplate()) {
        LinkLexicalDeclContext(database, em, decl, eid);
      }

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

      // Don't mark a variable template pattern as being part of a class.
      if (!var->DescribedVariableTemplate()) {
        LinkLexicalDeclContext(database, em, decl, eid);
      }

    } else if (auto cls = pasta::CXXRecordDecl::From(decl)) {
      TrackRedeclarations(database, pf.fragment_index, em, dummy_mangled_name,
                          decl, cls->Redeclarations());

      // Don't mark a class template pattern as being part of a class.
      if (!cls->DescribedClassTemplate()) {
        LinkLexicalDeclContext(database, em, decl, eid);
      }

    } else if (auto tag = pasta::TagDecl::From(decl)) {
      TrackRedeclarations(database, pf.fragment_index, em, dummy_mangled_name,
                          decl, tag->Redeclarations());

      LinkLexicalDeclContext(database, em, decl, eid);

    } else if (auto tpl = pasta::RedeclarableTemplateDecl::From(decl)) {
      TrackRedeclarations(database, pf.fragment_index, em, dummy_mangled_name,
                          decl, tpl->Redeclarations());

      LinkLexicalDeclContext(database, em, decl, eid);

    } else if (auto tad = pasta::TypeAliasDecl::From(decl)) {
      if (!tad->DescribedAliasTemplate()) {
        LinkLexicalDeclContext(database, em, decl, eid);
      }

    } else {
      LinkLexicalDeclContext(database, em, decl, eid);
    }
  }
}

}  // namespace indexer
