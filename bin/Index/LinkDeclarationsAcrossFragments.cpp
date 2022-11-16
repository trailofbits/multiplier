// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "EntityMapper.h"
#include "NameMangler.h"
#include "PendingFragment.h"

namespace indexer {
namespace {

static void TrackRedeclarations(mx::WorkerId worker_id,
                                IndexingContext &context, EntityMapper &em,
                                const std::string &mangled_name,
                                std::vector<pasta::Decl> redecls) {
  for (const pasta::Decl &redecl_a : redecls) {
    if (mx::RawEntityId redecl_a_eid = em.EntityId(redecl_a)) {
      context.LinkMangledName(worker_id, mangled_name,  redecl_a_eid);

      for (const pasta::Decl &redecl_b : redecls) {
        if (mx::RawEntityId redecl_b_eid = em.EntityId(redecl_b)) {
          context.LinkDeclarations(worker_id, redecl_a_eid, redecl_b_eid);
        }
      }
    }
  }
}

}  // namespace

// Store information persistently to enable linking of declarations across
// fragments.
void PendingFragment::LinkDeclarations(mx::WorkerId worker_id,
                                       IndexingContext &context,
                                       EntityMapper &em,
                                       NameMangler &mangler) {
  std::string dummy_mangled_name;
  for (const pasta::Decl &decl : decls_to_serialize) {
    mx::RawEntityId eid = em.EntityId(decl);
    if (eid == mx::kInvalidEntityId) {
      continue;
    }

    if (auto func = pasta::FunctionDecl::From(decl)) {
      const auto &mangled_name = mangler.Mangle(decl);
      TrackRedeclarations(
        worker_id, context, em,
        mangler.MangledNameIsPrecise() ? mangled_name : dummy_mangled_name,
        func->Redeclarations());

    } else if (auto var = pasta::VarDecl::From(decl)) {
      if (var->IsLocalVariableDeclaration()) {
        continue;
      }

      const auto &mangled_name = mangler.Mangle(decl);
      TrackRedeclarations(
        worker_id, context, em,
        mangler.MangledNameIsPrecise() ? mangled_name : dummy_mangled_name,
        var->Redeclarations());

    } else if (auto tag = pasta::TagDecl::From(decl)) {
      TrackRedeclarations(worker_id, context, em, dummy_mangled_name,
                          tag->Redeclarations());

    } else if (auto tpl = pasta::RedeclarableTemplateDecl::From(decl)) {
      TrackRedeclarations(worker_id, context, em, dummy_mangled_name,
                          tpl->Redeclarations());

    } else {
      continue;
    }
  }
}

}  // namespace indexer
