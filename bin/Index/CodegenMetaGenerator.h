// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <vast/Util/Common.hpp>
#include <vast/Translation/CodeGen.hpp>
#include <vast/Translation/CodeGenContext.hpp>
#include <vast/Translation/CodeGenVisitor.hpp>
#include <vast/Translation/CodeGenBuilder.hpp>
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
     : ast(ast), mctx(mctx), em(em) {}

   mlir::Location unknown_location() const {
     return mlir::UnknownLoc::get(mctx);
   }

   mlir::Location make_location(clang::SourceLocation &loc) const {
     auto file_token = ast.Adopt(loc).FileLocation();
     if (!file_token) {
       return unknown_location();
     }

     auto file = pasta::File::Containing(file_token);
     auto name = file? file->Path().generic_string() : "unknown";
     auto line = file_token->Line();
     auto col  = file_token->Column();
     return { mlir::FileLineColLoc::get(mctx, name, line, col) };
   }

   mlir::Location make_location(const auto token, clang::SourceLocation &loc) const {
     if (auto raw_entity_id = em.EntityId(token); raw_entity_id != mx::kInvalidEntityId) {
       auto entity_loc = make_location(loc);
       auto attr = vast::meta::IdentifierAttr::get(mctx, raw_entity_id);
       return mlir::FusedLoc::get({entity_loc}, attr, mctx);
     }
     return unknown_location();
   }

   mlir::Location make_location_type(auto type,  clang::SourceLocation &loc) const {
     auto raw_entity_id = em.EntityIdOfType(type);
     auto entity_loc = mlir::OpaqueLoc::get(reinterpret_cast<void *>(raw_entity_id), mctx);
     auto attr = vast::meta::IdentifierAttr::get(mctx, raw_entity_id);
     return mlir::FusedLoc::get({entity_loc}, attr, mctx);
   }


   vast::hl::DefaultMeta get(const clang::Decl *decl) const {
     auto loc = decl->getLocation();
     return {make_location(decl, loc)};
   }

   vast::hl::DefaultMeta get(const clang::Stmt *stmt) const {
     auto loc = stmt->getBeginLoc();
     return {make_location(stmt, loc)};
   }

   vast::hl::DefaultMeta get(const clang::TypeLoc &tyloc) const {
     auto loc =  tyloc.getBeginLoc();
     return {make_location_type(tyloc.getTypePtr(), loc)};
   }

   vast::hl::DefaultMeta get(const clang::Type *type) const {
     return get(clang::TypeLoc(type, nullptr));
   }

   vast::hl::DefaultMeta get(clang::QualType type) const {
     if (auto type_ptr = type.getTypePtrOrNull()) {
       return get(clang::TypeLoc(type, nullptr));;
     }
     return {unknown_location()};
   }

   const pasta::AST &ast;
   mlir::MLIRContext *mctx;
   const EntityMapper &em;
};

} // namespace indexer
