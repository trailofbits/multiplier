// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <multiplier/Database.h>
#include <multiplier/Types.h>
#include <pasta/AST/Stmt.h>

#include "EntityMapper.h"
#include "PASTA.h"
#include "PendingFragment.h"
#include "Util.h"

namespace indexer {

// Identify all unique entity IDs referenced by this fragment,
// and map them to the fragment ID in the data store.
void LinkExternalReferencesInFragment(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    EntityMapper &em) {

  for (const pasta::Stmt &stmt : pf.stmts_to_serialize) {
    std::optional<pasta::Decl> ref_decl = ReferencedDecl(stmt);
    if (!ref_decl) {
      continue;
    }

    mx::RawEntityId raw_id = em.EntityId(ref_decl.value());
    mx::VariantId vid = mx::EntityId(raw_id).Unpack();
    if (!std::holds_alternative<mx::DeclarationId>(vid)) {
      assert(false);
      continue;
    }

    // We're referencing something in another fragment, so by definition it's
    // an external reference.
    mx::DeclarationId did = std::get<mx::DeclarationId>(vid);
    if (did.fragment_id != pf.fragment_index) {
      database.AddAsync(mx::FragmentUsingEntityRecord{pf.fragment_id, raw_id});
    }
  }
}

}  // namespace indexer
