// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>

#include <multiplier/Token.h>
#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/Designator.h>
#include <multiplier/Entities/Macro.h>
#include <multiplier/Entities/Stmt.h>

namespace mlir {
class Operation;
}

namespace mx {

class Fragment;
class Decl;
class Stmt;
class SourceIRImpl;

class SourceIR {
 private:
  friend class Fragment;

  std::shared_ptr<SourceIRImpl> impl;

  inline SourceIR(std::shared_ptr<SourceIRImpl> impl_)
    : impl(std::move(impl_)) {}

 public:
  std::shared_ptr<const mlir::Operation> for_decl(const mx::Decl &decl) const;

  std::shared_ptr<const mlir::Operation> for_stmt(const mx::Stmt &stmt) const;

  VariantEntity entity_for(const mlir::Operation *op) const;

  VariantEntity entity_for(const std::shared_ptr<const mlir::Operation> op) const;

  std::optional<mx::Decl> decl_for(const mlir::Operation *op) const;

  inline std::optional<mx::Decl> decl_for(const std::shared_ptr<const mlir::Operation> op) const {
    return decl_for(op.get());
  }

  std::optional<mx::Stmt> stmt_for(const mlir::Operation *op) const;

  inline std::optional<mx::Stmt> stmt_for(const std::shared_ptr<const mlir::Operation> op) const {
    return stmt_for(op.get());
  }

  std::string operator*(void) const;

  void print(std::string &str) const;
};

}
