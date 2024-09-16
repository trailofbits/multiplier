// Copyright (c) 2023-present, Trail of Bits, Inc.
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

class Decl;
class Fragment;
class FragmentImpl;
class Stmt;

namespace ir {

enum class AttributeKind : unsigned;
enum class OperationKind : unsigned;
enum class TypeKind : unsigned;

class SourceIRImpl {
 public:
  friend class ::mx::Decl;
  friend class ::mx::Fragment;
  friend class ::mx::FragmentImpl;
  friend class ::mx::Stmt;

  const PackedCompilationId compilation_id;
  const EntityProviderPtr ep;

  mlir::OwningOpRef<mlir::ModuleOp> mod;

  using IdOpPair = std::pair<mx::RawEntityId, mlir::Operation *>;
  using IdOpPairList = std::vector<IdOpPair>;

  template <typename T>
  using IdOpPairListMap = std::unordered_map<T, IdOpPairList>;

  // All operations.
  std::unordered_map<ir::OperationKind, std::vector<mlir::Operation *>>
      operations;

  // Operations that belong to the high-level dialect, and have a corresponding
  // entity ID.
  IdOpPairListMap<::mx::DeclKind> declarations;
  IdOpPairListMap<::mx::StmtKind> statements;

  // High-level operations that have an entity id.
  std::unordered_map<
      mx::RawEntityId,
      std::vector<std::pair<OperationKind, mlir::Operation *>>>
      entities;

  virtual ~SourceIRImpl(void);

  explicit SourceIRImpl(PackedCompilationId compilation_id_, EntityProviderPtr ep_,
                        std::string_view mlir);

  mlir::Operation *scope(void) const;

  std::optional<Operation> OperationFor(
      const std::shared_ptr<const SourceIRImpl> &self,
      RawEntityId eid) const noexcept;
};

bool OperationIdsMatch(mlir::Operation *a, mlir::Operation *b);

bool BlocksMatch(
    const std::shared_ptr<const SourceIRImpl> &a_mod, mlir::Block *a,
    const std::shared_ptr<const SourceIRImpl> &b_mod, mlir::Block *b);

// Return a reference to the global MLIR context.
mlir::MLIRContext &GlobalMLIRContext(void);

}  // namespace ir
}  // namespace mx
