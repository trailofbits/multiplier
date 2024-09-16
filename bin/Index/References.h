// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <gap/coro/generator.hpp>
#include <optional>
#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>
#include <multiplier/Database.h>

namespace indexer {

class EntityMapper;

// Generate reference records to functions, variables, fields, enumerators, etc.
//
// This function works by starting at `stmt`, which is something like a
// `DeclRefExpr` which references `decl`, and then ascends up through the parent
// links.
gap::generator<mx::ReferenceRecord> EnumerateStmtToDeclReferences(
    const EntityMapper *em, pasta::Stmt /* from_ */ stmt, pasta::Decl to_decl);

// Get the reference kind for types referenced by a declaration.
gap::generator<mx::ReferenceRecord> EnumerateDeclToTypeReferences(
    const EntityMapper *em, pasta::Decl from_decl, pasta::Decl to_decl);

// Get the references for fields referenced by a designator.
gap::generator<mx::ReferenceRecord> EnumerateDesignatorToDeclReferences(
    const EntityMapper *em, pasta::Designator from_designator,
    pasta::Decl to_decl);

// Try to find the `Decl` referenced by a particular `type`.
std::optional<pasta::Decl> ReferencedDecl(const pasta::Type &type);

// Try to find the `Decl` referenced by a particular `stmt`.
std::optional<pasta::Decl> ReferencedDecl(const pasta::Stmt &stmt);

// Try to find the `Decl` referenced by a particular `stmt`.
gap::generator<pasta::Decl> DeclReferencesFrom(pasta::Decl decl);

// Try to find the `Decl` referenced by a particular `stmt`.
gap::generator<pasta::Decl> DeclReferencesFrom(pasta::Stmt stmt);

// Try to find the `Decl` referenced by a particular `type`.
gap::generator<pasta::Decl> DeclReferencesFrom(pasta::Type type);

// Try to find the `Decl` referenced by a particular `designator`.
gap::generator<pasta::Decl> DeclReferencesFrom(pasta::Designator designator);

}  // namespace indexer
