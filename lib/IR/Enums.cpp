// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/OpCode.h>
#include <multiplier/IR/ObjectKind.h>
#include <multiplier/IR/BlockKind.h>
#include <multiplier/Types.h>

namespace mx::ir {

const char *EnumeratorName(OpCode op) noexcept {
  switch (op) {
    case OpCode::BLOCK_ARG_DEF: return "BLOCK_ARG_DEF";
    case OpCode::CONST_INT: return "CONST_INT";
    case OpCode::CONST_FLOAT: return "CONST_FLOAT";
    case OpCode::CONST_NULL: return "CONST_NULL";
    case OpCode::ALLOCA: return "ALLOCA";
    case OpCode::LOAD: return "LOAD";
    case OpCode::STORE: return "STORE";
    case OpCode::ADDRESS_OF: return "ADDRESS_OF";
    case OpCode::GEP_FIELD: return "GEP_FIELD";
    case OpCode::GEP_INDEX: return "GEP_INDEX";
    case OpCode::PTR_ADD: return "PTR_ADD";
    case OpCode::ADD: return "ADD";
    case OpCode::SUB: return "SUB";
    case OpCode::MUL: return "MUL";
    case OpCode::DIV: return "DIV";
    case OpCode::REM: return "REM";
    case OpCode::BIT_AND: return "BIT_AND";
    case OpCode::BIT_OR: return "BIT_OR";
    case OpCode::BIT_XOR: return "BIT_XOR";
    case OpCode::SHL: return "SHL";
    case OpCode::SHR: return "SHR";
    case OpCode::LOGICAL_AND: return "LOGICAL_AND";
    case OpCode::LOGICAL_OR: return "LOGICAL_OR";
    case OpCode::PTR_DIFF: return "PTR_DIFF";
    case OpCode::CMP_EQ: return "CMP_EQ";
    case OpCode::CMP_NE: return "CMP_NE";
    case OpCode::CMP_LT: return "CMP_LT";
    case OpCode::CMP_LE: return "CMP_LE";
    case OpCode::CMP_GT: return "CMP_GT";
    case OpCode::CMP_GE: return "CMP_GE";
    case OpCode::NEG: return "NEG";
    case OpCode::BIT_NOT: return "BIT_NOT";
    case OpCode::LOGICAL_NOT: return "LOGICAL_NOT";
    case OpCode::CAST_SEXT: return "CAST_SEXT";
    case OpCode::CAST_ZEXT: return "CAST_ZEXT";
    case OpCode::CAST_TRUNC: return "CAST_TRUNC";
    case OpCode::CAST_BITCAST: return "CAST_BITCAST";
    case OpCode::CAST_PTR_TO_INT: return "CAST_PTR_TO_INT";
    case OpCode::CAST_INT_TO_PTR: return "CAST_INT_TO_PTR";
    case OpCode::CAST_FP_TO_SI: return "CAST_FP_TO_SI";
    case OpCode::CAST_SI_TO_FP: return "CAST_SI_TO_FP";
    case OpCode::CAST_FP_TRUNC: return "CAST_FP_TRUNC";
    case OpCode::CAST_FP_EXT: return "CAST_FP_EXT";
    case OpCode::CAST_INT_CAST: return "CAST_INT_CAST";
    case OpCode::CAST_FP_CAST: return "CAST_FP_CAST";
    case OpCode::SIZE_OF: return "SIZE_OF";
    case OpCode::CALL: return "CALL";
    case OpCode::INC_DEC: return "INC_DEC";
    case OpCode::COMPOUND_ASSIGN: return "COMPOUND_ASSIGN";
    case OpCode::SELECT: return "SELECT";
    case OpCode::COPY: return "COPY";
    case OpCode::COND_BRANCH: return "COND_BRANCH";
    case OpCode::SWITCH: return "SWITCH";
    case OpCode::RET: return "RET";
    case OpCode::UNREACHABLE: return "UNREACHABLE";
    case OpCode::BREAK: return "BREAK";
    case OpCode::CONTINUE: return "CONTINUE";
    case OpCode::GOTO: return "GOTO";
    case OpCode::IMPLICIT_GOTO: return "IMPLICIT_GOTO";
    case OpCode::FALLTHROUGH: return "FALLTHROUGH";
    case OpCode::IMPLICIT_FALLTHROUGH: return "IMPLICIT_FALLTHROUGH";
    case OpCode::VA_PACK: return "VA_PACK";
    case OpCode::VA_START: return "VA_START";
    case OpCode::VA_ARG: return "VA_ARG";
    case OpCode::VA_COPY: return "VA_COPY";
    case OpCode::VA_END: return "VA_END";
    case OpCode::UNKNOWN: return "UNKNOWN";
  }
  return "UNKNOWN";
}

const char *EnumeratorName(ObjectKind kind) noexcept {
  switch (kind) {
    case ObjectKind::LOCAL: return "LOCAL";
    case ObjectKind::LOCAL_VALUE: return "LOCAL_VALUE";
    case ObjectKind::PARAMETER: return "PARAMETER";
    case ObjectKind::PARAMETER_VALUE: return "PARAMETER_VALUE";
    case ObjectKind::GLOBAL: return "GLOBAL";
    case ObjectKind::THREAD_LOCAL: return "THREAD_LOCAL";
    case ObjectKind::STRING_LITERAL: return "STRING_LITERAL";
    case ObjectKind::COMPOUND_LITERAL: return "COMPOUND_LITERAL";
    case ObjectKind::RETURN_SLOT: return "RETURN_SLOT";
    case ObjectKind::ALLOCA: return "ALLOCA";
    case ObjectKind::HEAP: return "HEAP";
  }
  return "UNKNOWN";
}

const char *EnumeratorName(BlockKind kind) noexcept {
  switch (kind) {
    case BlockKind::ENTRY: return "ENTRY";
    case BlockKind::IF_THEN: return "IF_THEN";
    case BlockKind::IF_ELSE: return "IF_ELSE";
    case BlockKind::IF_MERGE: return "IF_MERGE";
    case BlockKind::LOOP_CONDITION: return "LOOP_CONDITION";
    case BlockKind::LOOP_BODY: return "LOOP_BODY";
    case BlockKind::LOOP_EXIT: return "LOOP_EXIT";
    case BlockKind::LOOP_INCREMENT: return "LOOP_INCREMENT";
    case BlockKind::SWITCH_CASE: return "SWITCH_CASE";
    case BlockKind::SWITCH_DEFAULT: return "SWITCH_DEFAULT";
    case BlockKind::SWITCH_EXIT: return "SWITCH_EXIT";
    case BlockKind::LABEL: return "LABEL";
    case BlockKind::UNREACHABLE: return "UNREACHABLE";
    case BlockKind::GENERIC: return "GENERIC";
  }
  return "UNKNOWN";
}

}  // namespace mx::ir

namespace mx {

const char *EnumeratorName(IREntityKind kind) noexcept {
  switch (kind) {
    case IREntityKind::IR_FUNCTION: return "IR_FUNCTION";
    case IREntityKind::IR_BLOCK: return "IR_BLOCK";
    case IREntityKind::IR_INSTRUCTION: return "IR_INSTRUCTION";
    case IREntityKind::IR_OBJECT: return "IR_OBJECT";
  }
  return "UNKNOWN";
}

}  // namespace mx
