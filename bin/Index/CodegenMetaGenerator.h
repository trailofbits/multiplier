// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cassert>

#include <vast/Util/Common.hpp>
#include <vast/CodeGen/CodeGenBuilder.hpp>
#include <vast/CodeGen/CodeGenVisitor.hpp>
#include <vast/CodeGen/CodeGenMeta.hpp>
#include <vast/Dialect/Meta/MetaTypes.hpp>

#include <pasta/AST/AST.h>

#include "EntityMapper.h"

namespace mlir {
class Location;
class MLIRContext;
}

namespace indexer {

class MetaGenerator final : public vast::cg::meta_generator {
 private:

  // Pasta AST context
  const pasta::AST &ast;

  // Entity mapper; The entity id gets embedded as meta data
  const EntityMapper &em;

  // MLIR context for generating the mlir location from source loc
  mlir::MLIRContext * const mctx;

  const mlir::Location unknown_location;

 public:
  MetaGenerator(const pasta::AST &ast, mlir::MLIRContext &mctx_,
                const EntityMapper &em)
      : ast(ast),
        em(em),
        mctx(&mctx_),
        unknown_location(mlir::UnknownLoc::get(mctx)) {}

  mlir::Location location(const clang::Decl *decl) const final {
    return {Location(decl)};
  }

  mlir::Location location(const clang::Expr *expr) const final {
    return {Location(expr)};
  }

  mlir::Location location(const clang::Stmt *stmt) const final {
    return {Location(stmt)};
  }

  mlir::Location location(const clang::Type *type) const {
    return {Location(type)};
  }

  mlir::Location location(const clang::Attr *type) const {
    return {Location(type)};
  }

  mlir::Location location(const clang::QualType type) const {
    if (auto type_ptr = type.getTypePtrOrNull()) {
      return {Location(type_ptr)};
    }
    return {unknown_location};
  }

  mlir::Location location(auto token) const {
    return {unknown_location};
  }

 private:
  mlir::Location Location(const clang::Decl *decl) const {
    if (auto raw_entity_id = em.EntityId(decl);
        raw_entity_id != mx::kInvalidEntityId) {
      auto attr = vast::meta::IdentifierAttr::get(mctx, raw_entity_id);
      return mlir::FusedLoc::get({}, attr, mctx);
    }
    return unknown_location;
  }

  mlir::Location Location(const clang::Stmt *stmt) const {
    if (auto raw_entity_id = em.EntityId(stmt);
        raw_entity_id != mx::kInvalidEntityId) {
      auto attr = vast::meta::IdentifierAttr::get(mctx, raw_entity_id);
      return mlir::FusedLoc::get({}, attr, mctx);
    }
    return unknown_location;
  }

  mlir::Location Location(const clang::Attr *attr_) const {
    if (auto raw_entity_id = em.EntityId(attr_);
        raw_entity_id != mx::kInvalidEntityId) {
      auto attr = vast::meta::IdentifierAttr::get(mctx, raw_entity_id);
      return mlir::FusedLoc::get({}, attr, mctx);
    }
    return unknown_location;
  }

  mlir::Location Location(const clang::Type *type) const {
    if (auto raw_entity_id = em.EntityIdOfType(type);
        raw_entity_id != mx::kInvalidEntityId) {
      auto attr = vast::meta::IdentifierAttr::get(mctx, raw_entity_id);
      return mlir::FusedLoc::get({}, attr, mctx);
    }
    return unknown_location;
  }
};

} // namespace indexer
