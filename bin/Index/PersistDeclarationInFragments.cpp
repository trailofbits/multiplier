// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.


#include <type_traits>

#include <pasta/AST/Stmt.h>

#include "Context.h"
#include "Database.h"
#include "EntityMapper.h"
#include "PendingFragment.h"
#include "Util.h"

namespace indexer {

static bool ShouldGetSymbolName(const pasta::Decl &decl) {
  switch (mx::FromPasta(decl.Kind())) {
    case mx::DeclKind::FUNCTION:
    case mx::DeclKind::CXX_METHOD:
    case mx::DeclKind::CXX_DESTRUCTOR:
    case mx::DeclKind::CXX_CONVERSION:
    case mx::DeclKind::CXX_CONSTRUCTOR:
    case mx::DeclKind::CXX_DEDUCTION_GUIDE:
      return true;

    // Variables.
    case mx::DeclKind::VAR:
    case mx::DeclKind::DECOMPOSITION:
    case mx::DeclKind::VAR_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION:
      if (reinterpret_cast<const pasta::VarDecl &>(decl).IsLocalVariableDeclaration()) {
        return false;
      } else {
        return true;
      }

    // Tags.
    case mx::DeclKind::TAG:
    case mx::DeclKind::RECORD:
    case mx::DeclKind::CXX_RECORD:
    case mx::DeclKind::CLASS_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION:
    case mx::DeclKind::ENUM:
      return true;

    // Redeclarable templates.
    case mx::DeclKind::REDECLARABLE_TEMPLATE:
    case mx::DeclKind::FUNCTION_TEMPLATE:
    case mx::DeclKind::CLASS_TEMPLATE:
    case mx::DeclKind::VAR_TEMPLATE:
    case mx::DeclKind::TYPE_ALIAS_TEMPLATE:
      return true;

    default:
      return false;
  }
}

void PendingFragment::PersistDeclarationSymbols(
    IndexingContext &context, EntityMapper &em, pasta::AST &ast,
    mx::WorkerId worker_id) {
  for (const pasta::Decl &decl : decls_to_serialize) {
    if (ShouldGetSymbolName(decl)) {
      auto str = DeclToString(ast, decl);
      auto id = em.EntityId(decl);
      context.database[worker_id]->StoreEntities(id, str);
    }
  }
}

}

