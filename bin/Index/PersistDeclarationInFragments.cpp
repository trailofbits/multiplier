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
namespace {

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
    case mx::DeclKind::ENUM_CONSTANT:
      return true;

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
    case mx::DeclKind::TYPE:
    case mx::DeclKind::TYPEDEF:
    case mx::DeclKind::TYPEDEF_NAME:
      return true;

    default:
      return false;
  }
}

static std::string SymbolName(const pasta::NamedDecl &decl) {
  switch (decl.Kind()) {
    case pasta::DeclKind::kNamespace: {
      auto ns = reinterpret_cast<const pasta::NamespaceDecl &>(decl);
      if (ns.IsAnonymousNamespace()) {
        return {};
      } else if (ns.IsInline()) {
        auto n = ns.Name();
        if (n.empty()) {
          return n;
        } else if (n[0] == '_') {  // E.g. `__1` in `std::__1`.
          return {};
        } else {
          return n;
        }
      } else {
        return ns.Name();
      }
    }
    default:
      return decl.Name();
  }
}

static std::string ContextualSymbolName(const pasta::NamedDecl &decl);

static std::string ContextualSymbolName(const pasta::DeclContext &dc) {
  pasta::Decl d(dc);
  if (auto nd = pasta::NamedDecl::From(d)) {
    return ContextualSymbolName(nd.value());
  } else if (auto dc_parent = dc.Parent()) {
    return ContextualSymbolName(dc_parent.value());
  } else {
    return {};
  }
}

std::string ContextualSymbolName(const pasta::NamedDecl &decl) {
  auto name = ContextualSymbolName(decl.DeclarationContext());
  if (name.empty()) {
    return decl.Name();
  } else {
    return name + "::" + decl.Name();
  }
}

}  // namespace

void PendingFragment::PersistDeclarationSymbols(
    IndexingContext &context, EntityMapper &em, pasta::AST &ast,
    mx::WorkerId worker_id) {
  for (const pasta::Decl &decl : decls_to_serialize) {
    if (auto nd = pasta::NamedDecl::From(decl);
        nd && ShouldGetSymbolName(decl)) {

      std::string str = ContextualSymbolName(nd.value());
      
      mx::RawEntityId id = em.EntityId(decl);
      context.databases[worker_id]->StoreEntities(
          id, str, mx::FromPasta(decl.Category()));
    }
  }
}

}  // namespace indexer
