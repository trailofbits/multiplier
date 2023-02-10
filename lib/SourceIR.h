// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <string>

#include <multiplier/Fragment.h>
#include <multiplier/Types.h>

#ifdef MX_ENABLE_SOURCEIR
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

class SourceIRImpl {
 private:
  friend class Fragment;

  std::shared_ptr<MLIRContext> mctx;
  OwningModuleRef mod;

  std::shared_ptr<const FragmentImpl> frag;

 public:
  virtual ~SourceIRImpl(void);

  explicit SourceIRImpl(std::shared_ptr<const FragmentImpl> frag_, std::string_view &mlir);

  mlir::Operation *scope(void) const;

  VariantEntity entity_for(EntityId id);

  void print(std::string &str) const;

};

}
#else
namespace mx {

class Fragment;
class FragmentImpl;

class SourceIRImpl {
 private:
  friend class Fragment;

  std::shared_ptr<const FragmentImpl> frag;

 public:
  virtual ~SourceIRImpl(void);

  explicit SourceIRImpl(
      std::shared_ptr<const FragmentImpl> frag_, std::string_view&)
    : frag(frag_) {}
};

}
#endif
