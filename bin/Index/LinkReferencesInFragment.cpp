// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.


#include <type_traits>

#include <multiplier/PASTA.h>
#include <pasta/AST/Stmt.h>

#include "Context.h"
#include "EntityMapper.h"
#include "PendingFragment.h"
#include "Util.h"

namespace indexer {
namespace {

// NOTE(pag): Keep in sync with `../lib/API/API.cpp` version of the same
//            function.
static bool MayHaveRemoteRedeclarations(const pasta::Decl &decl) {
  switch (mx::FromPasta(decl.Kind())) {
    // Functions / methods.
    case mx::DeclKind::FUNCTION:
    case mx::DeclKind::CXX_METHOD:
    case mx::DeclKind::CXX_DESTRUCTOR:
    case mx::DeclKind::CXX_CONVERSION:
    case mx::DeclKind::CXX_CONSTRUCTOR:
    case mx::DeclKind::CXX_DEDUCTION_GUIDE:
      return true;

    // Variables.
    case mx::DeclKind::VAR:
    case mx::DeclKind::PARM_VAR:
    case mx::DeclKind::OMP_CAPTURED_EXPR:
    case mx::DeclKind::IMPLICIT_PARAM:
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

    // Enumerators.
    case mx::DeclKind::ENUM_CONSTANT:

    // Redeclarable templates.
    case mx::DeclKind::REDECLARABLE_TEMPLATE:
    case mx::DeclKind::FUNCTION_TEMPLATE:
    case mx::DeclKind::CLASS_TEMPLATE:
    case mx::DeclKind::VAR_TEMPLATE:
    case mx::DeclKind::TYPE_ALIAS_TEMPLATE:
      return true;

    // Fields.
    case mx::DeclKind::FIELD:
    case mx::DeclKind::INDIRECT_FIELD:
      return true;

    // Types.
    case mx::DeclKind::TYPE_ALIAS:
    // case mx::DeclKind::TYPE_ALIAS_TEMPLATE:
    case mx::DeclKind::TYPE:
    case mx::DeclKind::TYPEDEF:
    case mx::DeclKind::TYPEDEF_NAME:
      return true;

    default:
      return false;
  }
}

}  // namespace

void PendingFragment::LinkReferences(
    IndexingContext &context, EntityMapper &em) {
  for (const pasta::Stmt &stmt : stmts_to_serialize) {
    if (stmt.Kind() == pasta::StmtKind::kImplicitCastExpr) {
      continue;
    }
    if (auto ref_decl = ReferencedDecl(stmt)) {
      auto used_decl = std::move(ref_decl.value());
      if (MayHaveRemoteRedeclarations(used_decl)) {
        auto used_decl_id = em.EntityId(used_decl);
        context.LinkReferenceInFragment(used_decl_id, fragment_id);
      }
    }
  }
}

}  // namespace indexer
