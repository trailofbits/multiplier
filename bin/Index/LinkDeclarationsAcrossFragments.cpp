/*
 * LinkDeclarationsAcrossFragments.cpp
 *
 *  Created on: May 11, 2022
 *      Author: pag
 */

#include "Context.h"
#include "EntityMapper.h"
#include "NameMangler.h"
#include "PendingFragment.h"

namespace indexer {
namespace {

static void TrackRedeclarations(IndexingContext &context,
                                EntityMapper &em,
                                mx::RawEntityId eid,
                                std::vector<pasta::Decl> redecls) {
  for (const pasta::Decl &redecl : redecls) {
    if (mx::RawEntityId redecl_eid = em.EntityId(redecl);
        redecl_eid != eid && redecl_eid != mx::kInvalidEntityId) {
      context.LinkDeclarations(eid, redecl_eid);
    }
  }
}

}  // namespace

// Store information persistently to enable linking of declarations across
// fragments.
void PendingFragment::LinkDeclarations(IndexingContext &context,
                                       EntityMapper &em,
                                       NameMangler &mangler) {
  for (const pasta::Decl &decl : decls_to_serialize) {
    mx::RawEntityId eid = em.EntityId(decl);
    if (eid == mx::kInvalidEntityId) {
      continue;
    }

    if (auto func = pasta::FunctionDecl::From(decl)) {
      TrackRedeclarations(context, em, eid, func->Redeclarations());
      context.LinkMangledName(mangler.Mangle(decl), eid);

    } else if (auto var = pasta::VarDecl::From(decl)) {
      if (var->IsLocalVariableDeclaration()) {
        continue;
      }

      TrackRedeclarations(context, em, eid, var->Redeclarations());
      context.LinkMangledName(mangler.Mangle(decl), eid);

    } else if (auto tag = pasta::TagDecl::From(decl)) {
      TrackRedeclarations(context, em, eid, tag->Redeclarations());

    } else if (auto tpl = pasta::RedeclarableTemplateDecl::From(decl)) {
      TrackRedeclarations(context, em, eid, tpl->Redeclarations());

    } else {
      continue;
    }
  }
}

}  // namespace indexer
