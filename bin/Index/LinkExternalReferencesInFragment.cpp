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

#include "EntityMapper.h"
#include "PASTA.h"
#include "PendingFragment.h"
#include "TokenTree.h"
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
      database.AddAsync(mx::ReferenceRecord{pf.fragment_id, raw_id});
    }
  }

  // TODO(pag): Add references for macros and files.
  for (const std::optional<TokenTree> &tt : pf.macros_to_serialize) {
    if (!tt) {
      continue;
    }

    std::optional<pasta::Macro> m = tt->Macro();
    if (!m) {
      continue;
    }

    mx::RawEntityId raw_id = em.EntityId(tt->RawNode());
    if (raw_id == mx::kInvalidEntityId) {
      raw_id = em.EntityId(m.value());
    }

    if (raw_id == mx::kInvalidEntityId) {
      continue;
    }

    mx::VariantId vid = mx::EntityId(raw_id).Unpack();
    if (!std::holds_alternative<mx::MacroId>(vid)) {
      assert(false);
      continue;
    }

    mx::MacroId mid = std::get<mx::MacroId>(vid);
    if (mid.fragment_id != pf.fragment_index) {
      assert(false);
      continue;  // This is weird?
    }

    switch (tt->Kind()) {
      default:
        break;

      // Have the expansion marked as a reference of the definition.
      case mx::MacroKind::EXPANSION:
        if (auto exp = pasta::MacroExpansion::From(m.value())) {
          std::optional<pasta::DefineMacroDirective> def = exp->Definition();
          if (!def) {
            continue;
          }

          raw_id = em.EntityId(def.value());
          vid = mx::EntityId(raw_id).Unpack();
          if (!std::holds_alternative<mx::MacroId>(vid)) {
            assert(false);
            continue;
          }

          mid = std::get<mx::MacroId>(vid);
          if (mid.fragment_id != pf.fragment_index) {
            database.AddAsync(mx::ReferenceRecord{pf.fragment_id, raw_id});
          }
        }
        break;

      // Files are always treated as references.
      case mx::MacroKind::INCLUDE_DIRECTIVE:
      case mx::MacroKind::INCLUDE_MACROS_DIRECTIVE:
      case mx::MacroKind::INCLUDE_NEXT_DIRECTIVE:
      case mx::MacroKind::IMPORT_DIRECTIVE:
        if (auto id = pasta::IncludeLikeMacroDirective::From(m.value())) {
          std::optional<pasta::File> f = id->IncludedFile();
          if (!f) {
            continue;
          }

          raw_id = em.EntityId(f.value());
          vid = mx::EntityId(raw_id).Unpack();
          if (!std::holds_alternative<mx::FileId>(vid)) {
            assert(false);
            continue;
          }

          database.AddAsync(mx::ReferenceRecord{pf.fragment_id, raw_id});
        }
        break;
    }
  }
}

}  // namespace indexer
