// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/TypeKind.h>

namespace mx {

const char *EnumeratorName(ir::TypeKind kind) {
  switch (kind) {
    default: return "UNKNOWN";
    case ir::TypeKind::LLVM_ARRAY: return "LLVM_ARRAY";
    case ir::TypeKind::LLVM_FIXED_VECTOR: return "LLVM_FIXED_VECTOR";
    case ir::TypeKind::LLVM_FUNCTION: return "LLVM_FUNCTION";
    case ir::TypeKind::LLVM_POINTER: return "LLVM_POINTER";
    case ir::TypeKind::LLVM_SCALABLE_VECTOR: return "LLVM_SCALABLE_VECTOR";
    case ir::TypeKind::LLVM_TARGET_EXT: return "LLVM_TARGET_EXT";
    case ir::TypeKind::ADJUSTED: return "ADJUSTED";
    case ir::TypeKind::ARRAY: return "ARRAY";
    case ir::TypeKind::ATTRIBUTED: return "ATTRIBUTED";
    case ir::TypeKind::B_FLOAT16: return "B_FLOAT16";
    case ir::TypeKind::BOOL: return "BOOL";
    case ir::TypeKind::CHAR: return "CHAR";
    case ir::TypeKind::DECAYED: return "DECAYED";
    case ir::TypeKind::DOUBLE: return "DOUBLE";
    case ir::TypeKind::ELABORATED: return "ELABORATED";
    case ir::TypeKind::ENUM: return "ENUM";
    case ir::TypeKind::FLOAT128: return "FLOAT128";
    case ir::TypeKind::FLOAT: return "FLOAT";
    case ir::TypeKind::HALF: return "HALF";
    case ir::TypeKind::INT128: return "INT128";
    case ir::TypeKind::INT: return "INT";
    case ir::TypeKind::L_VALUE: return "L_VALUE";
    case ir::TypeKind::LABEL: return "LABEL";
    case ir::TypeKind::LONG_DOUBLE: return "LONG_DOUBLE";
    case ir::TypeKind::LONG_LONG: return "LONG_LONG";
    case ir::TypeKind::LONG: return "LONG";
    case ir::TypeKind::PAREN: return "PAREN";
    case ir::TypeKind::POINTER: return "POINTER";
    case ir::TypeKind::R_VALUE: return "R_VALUE";
    case ir::TypeKind::RECORD: return "RECORD";
    case ir::TypeKind::REFERENCE: return "REFERENCE";
    case ir::TypeKind::SHORT: return "SHORT";
    case ir::TypeKind::TYPE_OF_EXPR: return "TYPE_OF_EXPR";
    case ir::TypeKind::TYPE_OF_TYPE: return "TYPE_OF_TYPE";
    case ir::TypeKind::TYPEDEF: return "TYPEDEF";
    case ir::TypeKind::VOID: return "VOID";
    case ir::TypeKind::FUNCTION: return "FUNCTION";
    case ir::TypeKind::UNSUPPORTED: return "UNSUPPORTED";
  }
}

}  // namespace mx
