// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/Operation.h>

namespace mx::ir::hl {
std::optional<Operation> Operation::from(const ::mx::ir::Operation &that) {
  switch (that.kind()) {
    default: return std::nullopt;
    case mx::ir::OperationKind::HL_ACCESS:
    case mx::ir::OperationKind::HL_ASSIGN_FADD:
    case mx::ir::OperationKind::HL_FADD:
    case mx::ir::OperationKind::HL_ASSIGN_ADD:
    case mx::ir::OperationKind::HL_ADD:
    case mx::ir::OperationKind::HL_LABELADDR:
    case mx::ir::OperationKind::HL_ADDRESSOF:
    case mx::ir::OperationKind::HL_ALIGNOF_EXPR:
    case mx::ir::OperationKind::HL_ALIGNOF_TYPE:
    case mx::ir::OperationKind::HL_ASSIGN:
    case mx::ir::OperationKind::HL_ASSIGN_BIN_ASHR:
    case mx::ir::OperationKind::HL_BIN_ASHR:
    case mx::ir::OperationKind::HL_ASSIGN_BIN_AND:
    case mx::ir::OperationKind::HL_BIN_AND:
    case mx::ir::OperationKind::HL_BIN_COMMA:
    case mx::ir::OperationKind::HL_BIN_LAND:
    case mx::ir::OperationKind::HL_BIN_LOR:
    case mx::ir::OperationKind::HL_ASSIGN_BIN_LSHR:
    case mx::ir::OperationKind::HL_BIN_LSHR:
    case mx::ir::OperationKind::HL_ASSIGN_BIN_OR:
    case mx::ir::OperationKind::HL_BIN_OR:
    case mx::ir::OperationKind::HL_ASSIGN_BIN_SHL:
    case mx::ir::OperationKind::HL_BIN_SHL:
    case mx::ir::OperationKind::HL_ASSIGN_BIN_XOR:
    case mx::ir::OperationKind::HL_BIN_XOR:
    case mx::ir::OperationKind::HL_BUILTIN_BITCAST:
    case mx::ir::OperationKind::HL_CSTYLE_CAST:
    case mx::ir::OperationKind::HL_CALL:
    case mx::ir::OperationKind::HL_CLASS:
    case mx::ir::OperationKind::HL_CMP:
    case mx::ir::OperationKind::HL_CONST:
    case mx::ir::OperationKind::HL_BASE:
    case mx::ir::OperationKind::HL_CXXSTRUCT:
    case mx::ir::OperationKind::HL_REF:
    case mx::ir::OperationKind::HL_DEREF:
    case mx::ir::OperationKind::HL_ASSIGN_FDIV:
    case mx::ir::OperationKind::HL_FDIV:
    case mx::ir::OperationKind::HL_ASSIGN_SDIV:
    case mx::ir::OperationKind::HL_SDIV:
    case mx::ir::OperationKind::HL_ASSIGN_UDIV:
    case mx::ir::OperationKind::HL_UDIV:
    case mx::ir::OperationKind::HL_ENUM_CONST:
    case mx::ir::OperationKind::HL_ENUM:
    case mx::ir::OperationKind::HL_ENUMREF:
    case mx::ir::OperationKind::HL_EXPR:
    case mx::ir::OperationKind::HL_GNU_EXTENSION:
    case mx::ir::OperationKind::HL_FCMP:
    case mx::ir::OperationKind::HL_FIELD:
    case mx::ir::OperationKind::HL_FUNCREF:
    case mx::ir::OperationKind::HL_GLOBREF:
    case mx::ir::OperationKind::HL_BREAK:
    case mx::ir::OperationKind::HL_CASE:
    case mx::ir::OperationKind::HL_COND:
    case mx::ir::OperationKind::HL_COND_YIELD:
    case mx::ir::OperationKind::HL_CONTINUE:
    case mx::ir::OperationKind::HL_DEFAULT:
    case mx::ir::OperationKind::HL_DO:
    case mx::ir::OperationKind::HL_EMPTY_DECL:
    case mx::ir::OperationKind::HL_FOR:
    case mx::ir::OperationKind::HL_FUNC:
    case mx::ir::OperationKind::HL_GOTO:
    case mx::ir::OperationKind::HL_IF:
    case mx::ir::OperationKind::HL_LABEL_DECL:
    case mx::ir::OperationKind::HL_LABEL:
    case mx::ir::OperationKind::HL_SKIP:
    case mx::ir::OperationKind::HL_SWITCH:
    case mx::ir::OperationKind::HL_TYPE_YIELD:
    case mx::ir::OperationKind::HL_VALUE_YIELD:
    case mx::ir::OperationKind::HL_VAR:
    case mx::ir::OperationKind::HL_WHILE:
    case mx::ir::OperationKind::HL_IMPLICIT_CAST:
    case mx::ir::OperationKind::HL_INDIRECT_CALL:
    case mx::ir::OperationKind::HL_INITLIST:
    case mx::ir::OperationKind::HL_LNOT:
    case mx::ir::OperationKind::HL_MINUS:
    case mx::ir::OperationKind::HL_ASSIGN_FMUL:
    case mx::ir::OperationKind::HL_FMUL:
    case mx::ir::OperationKind::HL_ASSIGN_MUL:
    case mx::ir::OperationKind::HL_MUL:
    case mx::ir::OperationKind::HL_NOT:
    case mx::ir::OperationKind::HL_PLUS:
    case mx::ir::OperationKind::HL_POST_DEC:
    case mx::ir::OperationKind::HL_POST_INC:
    case mx::ir::OperationKind::HL_PRE_DEC:
    case mx::ir::OperationKind::HL_PRE_INC:
    case mx::ir::OperationKind::HL_PREDEFINED_EXPR:
    case mx::ir::OperationKind::HL_MEMBER:
    case mx::ir::OperationKind::HL_ASSIGN_FREM:
    case mx::ir::OperationKind::HL_FREM:
    case mx::ir::OperationKind::HL_ASSIGN_SREM:
    case mx::ir::OperationKind::HL_SREM:
    case mx::ir::OperationKind::HL_ASSIGN_UREM:
    case mx::ir::OperationKind::HL_UREM:
    case mx::ir::OperationKind::HL_RETURN:
    case mx::ir::OperationKind::HL_SIZEOF_EXPR:
    case mx::ir::OperationKind::HL_SIZEOF_TYPE:
    case mx::ir::OperationKind::HL_STMT_EXPR:
    case mx::ir::OperationKind::HL_STRUCT:
    case mx::ir::OperationKind::HL_ASSIGN_FSUB:
    case mx::ir::OperationKind::HL_FSUB:
    case mx::ir::OperationKind::HL_ASSIGN_SUB:
    case mx::ir::OperationKind::HL_SUB:
    case mx::ir::OperationKind::HL_SUBSCRIPT:
    case mx::ir::OperationKind::HL_THIS:
    case mx::ir::OperationKind::HL_TRANSLATION_UNIT:
    case mx::ir::OperationKind::HL_TYPE:
    case mx::ir::OperationKind::HL_TYPEDEF:
    case mx::ir::OperationKind::HL_TYPEOF_EXPR:
    case mx::ir::OperationKind::HL_TYPEOF_TYPE:
    case mx::ir::OperationKind::HL_UNION:
    case mx::ir::OperationKind::HL_UNREACHABLE:
      return reinterpret_cast<const Operation &>(that);
  }
}

}  // namespace mx::ir::hl
