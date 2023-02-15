// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <string>

#include <multiplier/Index.h>
#include <multiplier/Fragment.h>
#include <multiplier/Types.h>

#ifdef MX_ENABLE_SOURCEIR
#include <unordered_map>
#include <unordered_set>

#include <mlir/IR/OwningOpRef.h>
#include <mlir/InitAllDialects.h>

namespace llvm {
class SourceMgr;
}

namespace mlir {
class MLIRContext;
class Operation;
}

namespace mx {

class Fragment;
class FragmentImpl;

using MLIRContext     = mlir::MLIRContext;
using Module          = mlir::ModuleOp;
using OwningModuleRef = mlir::OwningOpRef<Module>;
using OperationMap = std::unordered_map<uint64_t, std::unordered_set<const mlir::Operation*>>;

class SourceIRImpl {
 private:
  friend class Fragment;

  MLIRContext mctx;
  OwningModuleRef mod;

  OperationMap deserialized_ops;

  std::shared_ptr<const FragmentImpl> frag;

  static mlir::DialectRegistry registry;

  static const mlir::DialectRegistry& Registry(void);

 public:
  virtual ~SourceIRImpl(void);

  explicit SourceIRImpl(std::shared_ptr<const FragmentImpl> frag_, std::string_view &mlir);

  mlir::Operation *scope(void) const;

  VariantEntity EntityFor(EntityId id) const;

#define MX_DECLARE_ENTITY_FUNCTION(type_name, lower_name, e, v) \
	const OperationRange::Set* For##type_name(const type_name &lower_name) const; \

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
      std::shared_ptr<const FragmentImpl>, std::string_view &) {}
};

} // namespace mx
#endif
