// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <vast/Util/Common.hpp>
#include <vast/CodeGen/CodeGen.hpp>
#include <vast/CodeGen/CodeGenContext.hpp>
#include <vast/CodeGen/CodeGenVisitor.hpp>
#include <vast/CodeGen/CodeGenBuilder.hpp>
#include <vast/Dialect/Meta/MetaTypes.hpp>

#include <pasta/AST/AST.h>

#include "EntityMapper.h"

namespace mlir {
class Location;
class MLIRContext;
}

namespace indexer {

class MetaGenerator {
 public:
  MetaGenerator(const pasta::AST &ast, mlir::MLIRContext *mctx,  const EntityMapper &em)
  : ast(ast), em(em), mctx(mctx) {}

  vast::cg::DefaultMeta get(const clang::Decl *decl) const {
    return {Location(decl)};
  }

  vast::cg::DefaultMeta get(const clang::Stmt *stmt) const {
    return {Location(stmt)};
  }

  vast::cg::DefaultMeta get(const clang::Type *type) const {
    return {Location(type)};
  }

  vast::cg::DefaultMeta get(const clang::QualType type) const {
    if (auto type_ptr = type.getTypePtrOrNull()) {
      return {Location(type_ptr)};
    }
    return {LocationUnknown()};
  }

  vast::cg::DefaultMeta get(auto token) const {
    return {LocationUnknown()};
  }

 private:
  mlir::Location LocationUnknown() const {
    return mlir::UnknownLoc::get(mctx);
  }

  // Get mlir Location from the clang source location
  mlir::Location Location(clang::SourceLocation &loc) const {
    auto file_token = ast.Adopt(loc).FileLocation();

    // Return unknown location if file_token is not valid
    if (!file_token) {
      return LocationUnknown();
    }

    auto file = pasta::File::Containing(file_token);
    auto name = file != std::nullopt? file->Path().generic_string() : "unknown";
    auto line = file_token->Line();
    auto col  = file_token->Column();
    return { mlir::FileLineColLoc::get(mctx, name, line, col) };
  }

  mlir::Location Location(const clang::Decl *decl) const {
    if (auto raw_entity_id = em.EntityId(decl); raw_entity_id != mx::kInvalidEntityId) {
      auto attr = vast::meta::IdentifierAttr::get(mctx, raw_entity_id);
      auto loc = decl->getLocation();
      return mlir::FusedLoc::get({Location(loc)}, attr, mctx);
    }
    return LocationUnknown();
  }

  mlir::Location Location(const clang::Stmt *stmt) const {
    if (auto raw_entity_id = em.EntityId(stmt); raw_entity_id != mx::kInvalidEntityId) {
      auto attr = vast::meta::IdentifierAttr::get(mctx, raw_entity_id);
      auto loc = stmt->getBeginLoc();
      return mlir::FusedLoc::get({Location(loc)}, attr, mctx);
    }
    return LocationUnknown();
  }

  mlir::Location Location(const clang::Type *type) const {
    if ( auto raw_entity_id = em.EntityIdOfType(type); raw_entity_id != mx::kInvalidEntityId) {
      auto attr = vast::meta::IdentifierAttr::get(mctx, raw_entity_id);

      // clang::Type does not have source location; Leave it empty and
      // only fuse the attribute metadata
      return mlir::FusedLoc::get({}, attr, mctx);
    }
    return LocationUnknown();
  }

  // Pasta AST context
  const pasta::AST &ast;

  // Entity mapper; The entity id gets embedded as meta data
  const EntityMapper &em;

  // MLIR context for generating the mlir location from source loc
  mlir::MLIRContext *mctx;
};

} // namespace indexer
