// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <string>

#include <unordered_map>
#include <vector>

#include <mlir/IR/BuiltinOps.h>
#include <mlir/IR/DialectRegistry.h>
#include <mlir/IR/MLIRContext.h>
#include <mlir/IR/OwningOpRef.h>

#include "../Types.h"
#include "../EntityProvider.h"

namespace llvm {
class SourceMgr;
} // namespace llvm
namespace mx {

enum class DeclKind : unsigned char;
enum class StmtKind : unsigned char;
enum class TypeKind : unsigned char;

class Fragment;
class FragmentImpl;

namespace ir {

enum class AttributeKind : unsigned;
enum class OperationKind : unsigned;
enum class TypeKind : unsigned;

class SourceIRImpl {
 private:
  friend class Fragment;
  friend class FragmentImpl;

  const PackedCompilationId compilation_id;
  const EntityProviderPtr ep;

  mlir::OwningOpRef<mlir::ModuleOp> mod;

  std::unordered_map<ir::OperationKind, std::vector<mlir::Operation *>>
      operations;

  std::unordered_map<::mx::DeclKind, std::vector<mlir::Operation *>>
      declarations;

  std::unordered_map<::mx::StmtKind, std::vector<mlir::Operation *>>
      statements;

  std::unordered_map<::mx::TypeKind, std::vector<mlir::Operation *>>
      types;

  std::unordered_map<RawEntityId, std::vector<mlir::Operation *>>
      entities;

 public:
  virtual ~SourceIRImpl(void);

  explicit SourceIRImpl(PackedCompilationId compilation_id_, EntityProviderPtr ep_,
                        std::string_view mlir);

  mlir::Operation *scope(void) const;

//  VariantEntity EntityFor(EntityId id) const;
//
//#define MX_DECLARE_ENTITY_FUNCTION(type_name, lower_name, e, v) \
//	const OperationRange::OpVec *For##type_name(const type_name &lower_name) const; \
//
//  MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
//                              MX_IGNORE_ENTITY_CATEGORY,
//                              MX_DECLARE_ENTITY_FUNCTION,
//                              MX_IGNORE_ENTITY_CATEGORY,
//                              MX_DECLARE_ENTITY_FUNCTION,
//                              MX_DECLARE_ENTITY_FUNCTION)
//#undef MX_DECLARE_ENTITY_FUNCTION

};

}  // namespace ir
}  // namespace mx
