// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/SourceIR.h>

#include <memory>
#include <string>

#ifdef MX_ENABLE_SOURCEIR
#include <unordered_map>
#include <vector>

#include <mlir/IR/OwningOpRef.h>
#include <mlir/InitAllDialects.h>

namespace llvm {
class SourceMgr;
} // namespace llvm

namespace mlir {
class MLIRContext;
class Operation;
} // namespace mlir

namespace mx {

class Fragment;
class FragmentImpl;

namespace {
class RegistryInitializer;
} // namespace

using MLIRContext     = mlir::MLIRContext;
using Module          = mlir::ModuleOp;
using OwningModuleRef = mlir::OwningOpRef<Module>;
using OperationMap    = std::unordered_map<uint64_t, std::vector<const mlir::Operation *>>;

class SourceIRImpl {
 private:
  friend class Fragment;
  friend class RegistryInitializer;

  MLIRContext mctx;
  OwningModuleRef mod;

  OperationMap deserialized_ops;

  std::shared_ptr<const FragmentImpl> frag;

  static mlir::DialectRegistry gRegistry;

 public:
  virtual ~SourceIRImpl(void);

  explicit SourceIRImpl(std::shared_ptr<const FragmentImpl> frag_, std::string_view mlir);

  const mlir::Operation *scope(void) const;

  VariantEntity EntityFor(EntityId id) const;

#define MX_DECLARE_ENTITY_FUNCTION(type_name, lower_name, e, v) \
	const OperationRange::OpVec *For##type_name(const type_name &lower_name) const; \

  MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_DECLARE_ENTITY_FUNCTION,
                              MX_DECLARE_ENTITY_FUNCTION)
#undef MX_DECLARE_ENTITY_FUNCTION

  void print(std::ostream &os) const;

};

} // namespace mx
#else
namespace mx {

class FragmentImpl;

class SourceIRImpl {
 public:
  virtual ~SourceIRImpl(void);

  explicit SourceIRImpl(
      std::shared_ptr<const FragmentImpl>, std::string_view) {}
};

} // namespace mx
#endif
