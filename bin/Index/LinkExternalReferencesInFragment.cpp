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

// Identify all unique entity IDs referenced by this fragment,
// and map them to the fragment ID in the data store.
void LinkExternalReferencesInFragment(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    EntityMapper &em) {

  for (const pasta::Stmt &stmt : pf.stmts_to_serialize) {
    mx::RawEntityId stmt_id = em.EntityId(stmt);
    mx::VariantId vid = mx::EntityId(stmt_id).Unpack();
    if (!std::holds_alternative<mx::StmtId>(vid)) {
      assert(false);
      continue;
    }

    mx::StmtId sid = std::get<mx::StmtId>(vid);
    if (sid.fragment_id != pf.fragment_index) {
      assert(false);
      continue;  // This is weird?
    }

    std::optional<pasta::Decl> ref_decl = ReferencedDecl(stmt);
    if (!ref_decl) {
      continue;
    }

    mx::RawEntityId decl_id = em.EntityId(ref_decl.value());
    vid = mx::EntityId(decl_id).Unpack();
    if (!std::holds_alternative<mx::DeclId>(vid)) {
      assert(false);
      continue;
    }

    database.AddAsync(mx::ReferenceRecord{stmt_id, decl_id});
  }

  for (const std::optional<TokenTree> &tt : pf.macros_to_serialize) {
    if (!tt) {

      // TODO(pag): Remove this assertion later; really it's a failure to
      //            construct a token tree, and we do have a backup path
      //            in `Persist.cpp`.
      assert(false);
      continue;
    }

    std::optional<pasta::Macro> m = tt->Macro();
    if (!m) {
      continue;
    }

    mx::RawEntityId macro_id = em.EntityId(tt->RawNode());
    if (macro_id == mx::kInvalidEntityId) {
      macro_id = em.EntityId(m.value());
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

          database.AddAsync(mx::ReferenceRecord{macro_id, def_id});
        }
        break;

      // Files are always treated as references.
      case mx::MacroKind::INCLUDE_DIRECTIVE:
      case mx::MacroKind::INCLUDE_MACROS_DIRECTIVE:
      case mx::MacroKind::INCLUDE_NEXT_DIRECTIVE:
      case mx::MacroKind::IMPORT_DIRECTIVE:
        if (auto inc = pasta::IncludeLikeMacroDirective::From(m.value())) {
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

          database.AddAsync(mx::ReferenceRecord{macro_id, file_id});
        }
        break;
    }
  }
}

}  // namespace indexer
