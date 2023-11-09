// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/MemRef/Operation.h>

namespace mx::ir::memref {
std::optional<Operation> Operation::from(const ::mx::ir::Operation &that) {
  switch (that.kind()) {
    default: return std::nullopt;
    case mx::ir::OperationKind::MEMREF_ASSUME_ALIGNMENT:
    case mx::ir::OperationKind::MEMREF_ATOMIC_RMW:
    case mx::ir::OperationKind::MEMREF_ATOMIC_YIELD:
    case mx::ir::OperationKind::MEMREF_COPY:
    case mx::ir::OperationKind::MEMREF_GENERIC_ATOMIC_RMW:
    case mx::ir::OperationKind::MEMREF_LOAD:
    case mx::ir::OperationKind::MEMREF_ALLOC:
    case mx::ir::OperationKind::MEMREF_ALLOCA:
    case mx::ir::OperationKind::MEMREF_ALLOCA_SCOPE:
    case mx::ir::OperationKind::MEMREF_ALLOCA_SCOPE_RETURN:
    case mx::ir::OperationKind::MEMREF_CAST:
    case mx::ir::OperationKind::MEMREF_COLLAPSE_SHAPE:
    case mx::ir::OperationKind::MEMREF_DEALLOC:
    case mx::ir::OperationKind::MEMREF_DIM:
    case mx::ir::OperationKind::MEMREF_DMA_START:
    case mx::ir::OperationKind::MEMREF_DMA_WAIT:
    case mx::ir::OperationKind::MEMREF_EXPAND_SHAPE:
    case mx::ir::OperationKind::MEMREF_EXTRACT_ALIGNED_POINTER_AS_INDEX:
    case mx::ir::OperationKind::MEMREF_EXTRACT_STRIDED_METADATA:
    case mx::ir::OperationKind::MEMREF_GET_GLOBAL:
    case mx::ir::OperationKind::MEMREF_GLOBAL:
    case mx::ir::OperationKind::MEMREF_MEMORY_SPACE_CAST:
    case mx::ir::OperationKind::MEMREF_PREFETCH:
    case mx::ir::OperationKind::MEMREF_RANK:
    case mx::ir::OperationKind::MEMREF_REALLOC:
    case mx::ir::OperationKind::MEMREF_REINTERPRET_CAST:
    case mx::ir::OperationKind::MEMREF_RESHAPE:
    case mx::ir::OperationKind::MEMREF_STORE:
    case mx::ir::OperationKind::MEMREF_TRANSPOSE:
    case mx::ir::OperationKind::MEMREF_VIEW:
    case mx::ir::OperationKind::MEMREF_SUBVIEW:
    case mx::ir::OperationKind::MEMREF_TENSOR_STORE:
      return reinterpret_cast<const Operation &>(that);
  }
}

}  // namespace mx::ir::memref
