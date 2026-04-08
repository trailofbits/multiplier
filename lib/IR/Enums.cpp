// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/OpCode.h>
#include <multiplier/IR/ObjectKind.h>
#include <multiplier/IR/BlockKind.h>
#include <multiplier/IR/FunctionKind.h>
#include <multiplier/IR/StructureKind.h>
#include <multiplier/Types.h>

namespace mx::ir {

const char *EnumeratorName(OpCode op) noexcept {
  switch (op) {
    case OpCode::CONST: return "CONST";
    case OpCode::ALLOCA: return "ALLOCA";
    case OpCode::MEMORY: return "MEMORY";
    case OpCode::GEP_FIELD: return "GEP_FIELD";
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
    case OpCode::CAST: return "CAST";
    case OpCode::CALL: return "CALL";
    case OpCode::READ_MODIFY_WRITE: return "READ_MODIFY_WRITE";
    case OpCode::SELECT: return "SELECT";
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
    case OpCode::IMPLICIT_UNREACHABLE: return "IMPLICIT_UNREACHABLE";
    case OpCode::VA_PACK: return "VA_PACK";
    case OpCode::VA_START: return "VA_START";
    case OpCode::VA_ARG: return "VA_ARG";
    case OpCode::VA_COPY: return "VA_COPY";
    case OpCode::VA_END: return "VA_END";
    case OpCode::ENTER_SCOPE: return "ENTER_SCOPE";
    case OpCode::EXIT_SCOPE: return "EXIT_SCOPE";
    // MULTIMEM removed: merged into MEMORY.
    case OpCode::PARAM_READ: return "PARAM_READ";
    case OpCode::GLOBAL_PTR: return "GLOBAL_PTR";
    case OpCode::THREAD_LOCAL_PTR: return "THREAD_LOCAL_PTR";
    case OpCode::FUNC_PTR: return "FUNC_PTR";
    case OpCode::BITWISE: return "BITWISE";
    case OpCode::FLOAT: return "FLOAT";
    case OpCode::UNDEFINED: return "UNDEFINED";
    case OpCode::DYNAMIC_ALLOCA: return "DYNAMIC_ALLOCA";
    case OpCode::FRAME_PTR: return "FRAME_PTR";
    case OpCode::RETURN_PTR: return "RETURN_PTR";
    case OpCode::ADD_OVERFLOW: return "ADD_OVERFLOW";
    case OpCode::SUB_OVERFLOW: return "SUB_OVERFLOW";
    case OpCode::MUL_OVERFLOW: return "MUL_OVERFLOW";
    case OpCode::ATOMIC_ADD: return "ATOMIC_ADD";
    case OpCode::ATOMIC_SUB: return "ATOMIC_SUB";
    case OpCode::ATOMIC_AND: return "ATOMIC_AND";
    case OpCode::ATOMIC_OR: return "ATOMIC_OR";
    case OpCode::ATOMIC_XOR: return "ATOMIC_XOR";
    case OpCode::ATOMIC_NAND: return "ATOMIC_NAND";
    case OpCode::ATOMIC_EXCHANGE: return "ATOMIC_EXCHANGE";
    case OpCode::LAST_VALUE: return "LAST_VALUE";
    case OpCode::UNKNOWN: return "UNKNOWN";
  }
  return "UNKNOWN";
}

const char *EnumeratorName(FunctionKind kind) noexcept {
  switch (kind) {
    case FunctionKind::NORMAL: return "NORMAL";
    case FunctionKind::GLOBAL_INITIALIZER: return "GLOBAL_INITIALIZER";
    case FunctionKind::THREAD_LOCAL_INITIALIZER: return "THREAD_LOCAL_INITIALIZER";
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

const char *EnumeratorName(StructureKind kind) noexcept {
  switch (kind) {
    case StructureKind::FUNCTION_SCOPE: return "FUNCTION_SCOPE";
    case StructureKind::SCOPE: return "SCOPE";
    case StructureKind::IF: return "IF";
    case StructureKind::IF_THEN: return "IF_THEN";
    case StructureKind::IF_ELSE: return "IF_ELSE";
    case StructureKind::FOR: return "FOR";
    case StructureKind::FOR_INIT: return "FOR_INIT";
    case StructureKind::FOR_CONDITION: return "FOR_CONDITION";
    case StructureKind::FOR_BODY: return "FOR_BODY";
    case StructureKind::FOR_INCREMENT: return "FOR_INCREMENT";
    case StructureKind::WHILE: return "WHILE";
    case StructureKind::WHILE_CONDITION: return "WHILE_CONDITION";
    case StructureKind::WHILE_BODY: return "WHILE_BODY";
    case StructureKind::DO_WHILE: return "DO_WHILE";
    case StructureKind::DO_WHILE_BODY: return "DO_WHILE_BODY";
    case StructureKind::DO_WHILE_CONDITION: return "DO_WHILE_CONDITION";
    case StructureKind::SWITCH: return "SWITCH";
    case StructureKind::SWITCH_CASE: return "SWITCH_CASE";
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
    case BlockKind::FRAME: return "FRAME";
    case BlockKind::COMPENSATION: return "COMPENSATION";
    case BlockKind::LOOP_PREHEADER: return "LOOP_PREHEADER";
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
    case IREntityKind::IR_SWITCH_CASE: return "IR_SWITCH_CASE";
    case IREntityKind::IR_STRUCTURE: return "IR_STRUCTURE";
  }
  return "UNKNOWN";
}

}  // namespace mx
