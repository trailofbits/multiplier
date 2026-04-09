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
    case OpCode::VA_START: return "VA_START";
    case OpCode::VA_COPY: return "VA_COPY";
    case OpCode::VA_END: return "VA_END";
    case OpCode::ENTER_SCOPE: return "ENTER_SCOPE";
    case OpCode::EXIT_SCOPE: return "EXIT_SCOPE";
    case OpCode::PARAM_PTR: return "PARAM_PTR";
    case OpCode::GLOBAL_PTR: return "GLOBAL_PTR";
    case OpCode::THREAD_LOCAL_PTR: return "THREAD_LOCAL_PTR";
    case OpCode::FUNC_PTR: return "FUNC_PTR";
    case OpCode::BITWISE: return "BITWISE";
    case OpCode::FLOAT: return "FLOAT";
    case OpCode::UNDEFINED: return "UNDEFINED";
    case OpCode::FRAME_PTR: return "FRAME_PTR";
    case OpCode::RETURN_ADDRESS: return "RETURN_ADDRESS";
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
    case OpCode::RETURN_PTR: return "RETURN_PTR";
  }
  return "UNKNOWN";
}

const char *EnumeratorName(ConstOp op) noexcept {
  switch (op) {
    case ConstOp::INT8: return "INT8";
    case ConstOp::INT16: return "INT16";
    case ConstOp::INT32: return "INT32";
    case ConstOp::INT64: return "INT64";
    case ConstOp::UINT8: return "UINT8";
    case ConstOp::UINT16: return "UINT16";
    case ConstOp::UINT32: return "UINT32";
    case ConstOp::UINT64: return "UINT64";
    case ConstOp::FLOAT32: return "FLOAT32";
    case ConstOp::FLOAT64: return "FLOAT64";
    case ConstOp::FLOAT16: return "FLOAT16";
    case ConstOp::NULL_PTR: return "NULL_PTR";
    case ConstOp::INF32: return "INF32";
    case ConstOp::INF64: return "INF64";
    case ConstOp::NAN32: return "NAN32";
    case ConstOp::NAN64: return "NAN64";
    case ConstOp::WCHAR16: return "WCHAR16";
    case ConstOp::WCHAR32: return "WCHAR32";
    case ConstOp::BOOL: return "BOOL";
  }
  return "UNKNOWN";
}

const char *EnumeratorName(AllocaKind op) noexcept {
  switch (op) {
    case AllocaKind::LOCAL: return "LOCAL";
    case AllocaKind::ARG: return "ARG";
    case AllocaKind::RETURN: return "RETURN";
    case AllocaKind::DYNAMIC: return "DYNAMIC";
  }
  return "UNKNOWN";
}

const char *EnumeratorName(CastOp op) noexcept {
  switch (op) {
    case CastOp::SEXT_I8_I16: return "SEXT_I8_I16";
    case CastOp::SEXT_I8_I32: return "SEXT_I8_I32";
    case CastOp::SEXT_I8_I64: return "SEXT_I8_I64";
    case CastOp::SEXT_I16_I32: return "SEXT_I16_I32";
    case CastOp::SEXT_I16_I64: return "SEXT_I16_I64";
    case CastOp::SEXT_I32_I64: return "SEXT_I32_I64";
    case CastOp::ZEXT_I8_I16: return "ZEXT_I8_I16";
    case CastOp::ZEXT_I8_I32: return "ZEXT_I8_I32";
    case CastOp::ZEXT_I8_I64: return "ZEXT_I8_I64";
    case CastOp::ZEXT_I16_I32: return "ZEXT_I16_I32";
    case CastOp::ZEXT_I16_I64: return "ZEXT_I16_I64";
    case CastOp::ZEXT_I32_I64: return "ZEXT_I32_I64";
    case CastOp::TRUNC_I16_I8: return "TRUNC_I16_I8";
    case CastOp::TRUNC_I32_I8: return "TRUNC_I32_I8";
    case CastOp::TRUNC_I64_I8: return "TRUNC_I64_I8";
    case CastOp::TRUNC_I32_I16: return "TRUNC_I32_I16";
    case CastOp::TRUNC_I64_I16: return "TRUNC_I64_I16";
    case CastOp::TRUNC_I64_I32: return "TRUNC_I64_I32";
    case CastOp::F32_TO_F64: return "F32_TO_F64";
    case CastOp::F64_TO_F32: return "F64_TO_F32";
    case CastOp::SI8_TO_F32: return "SI8_TO_F32";
    case CastOp::SI8_TO_F64: return "SI8_TO_F64";
    case CastOp::SI16_TO_F32: return "SI16_TO_F32";
    case CastOp::SI16_TO_F64: return "SI16_TO_F64";
    case CastOp::SI32_TO_F32: return "SI32_TO_F32";
    case CastOp::SI32_TO_F64: return "SI32_TO_F64";
    case CastOp::SI64_TO_F32: return "SI64_TO_F32";
    case CastOp::SI64_TO_F64: return "SI64_TO_F64";
    case CastOp::UI8_TO_F32: return "UI8_TO_F32";
    case CastOp::UI8_TO_F64: return "UI8_TO_F64";
    case CastOp::UI16_TO_F32: return "UI16_TO_F32";
    case CastOp::UI16_TO_F64: return "UI16_TO_F64";
    case CastOp::UI32_TO_F32: return "UI32_TO_F32";
    case CastOp::UI32_TO_F64: return "UI32_TO_F64";
    case CastOp::UI64_TO_F32: return "UI64_TO_F32";
    case CastOp::UI64_TO_F64: return "UI64_TO_F64";
    case CastOp::F32_TO_SI8: return "F32_TO_SI8";
    case CastOp::F32_TO_SI16: return "F32_TO_SI16";
    case CastOp::F32_TO_SI32: return "F32_TO_SI32";
    case CastOp::F32_TO_SI64: return "F32_TO_SI64";
    case CastOp::F64_TO_SI8: return "F64_TO_SI8";
    case CastOp::F64_TO_SI16: return "F64_TO_SI16";
    case CastOp::F64_TO_SI32: return "F64_TO_SI32";
    case CastOp::F64_TO_SI64: return "F64_TO_SI64";
    case CastOp::F32_TO_UI8: return "F32_TO_UI8";
    case CastOp::F32_TO_UI16: return "F32_TO_UI16";
    case CastOp::F32_TO_UI32: return "F32_TO_UI32";
    case CastOp::F32_TO_UI64: return "F32_TO_UI64";
    case CastOp::F64_TO_UI8: return "F64_TO_UI8";
    case CastOp::F64_TO_UI16: return "F64_TO_UI16";
    case CastOp::F64_TO_UI32: return "F64_TO_UI32";
    case CastOp::F64_TO_UI64: return "F64_TO_UI64";
    case CastOp::PTR_TO_I32: return "PTR_TO_I32";
    case CastOp::PTR_TO_I64: return "PTR_TO_I64";
    case CastOp::I32_TO_PTR: return "I32_TO_PTR";
    case CastOp::I64_TO_PTR: return "I64_TO_PTR";
    case CastOp::BITCAST: return "BITCAST";
    case CastOp::IDENTITY: return "IDENTITY";
  }
  return "UNKNOWN";
}

const char *EnumeratorName(MemOp op) noexcept {
  switch (op) {
    case MemOp::LOAD_LE_8: return "LOAD_LE_8";
    case MemOp::LOAD_LE_16: return "LOAD_LE_16";
    case MemOp::LOAD_LE_32: return "LOAD_LE_32";
    case MemOp::LOAD_LE_64: return "LOAD_LE_64";
    case MemOp::LOAD_BE_8: return "LOAD_BE_8";
    case MemOp::LOAD_BE_16: return "LOAD_BE_16";
    case MemOp::LOAD_BE_32: return "LOAD_BE_32";
    case MemOp::LOAD_BE_64: return "LOAD_BE_64";
    case MemOp::STORE_LE_8: return "STORE_LE_8";
    case MemOp::STORE_LE_16: return "STORE_LE_16";
    case MemOp::STORE_LE_32: return "STORE_LE_32";
    case MemOp::STORE_LE_64: return "STORE_LE_64";
    case MemOp::STORE_BE_8: return "STORE_BE_8";
    case MemOp::STORE_BE_16: return "STORE_BE_16";
    case MemOp::STORE_BE_32: return "STORE_BE_32";
    case MemOp::STORE_BE_64: return "STORE_BE_64";
    case MemOp::ATOMIC_LOAD_LE_8: return "ATOMIC_LOAD_LE_8";
    case MemOp::ATOMIC_LOAD_LE_16: return "ATOMIC_LOAD_LE_16";
    case MemOp::ATOMIC_LOAD_LE_32: return "ATOMIC_LOAD_LE_32";
    case MemOp::ATOMIC_LOAD_LE_64: return "ATOMIC_LOAD_LE_64";
    case MemOp::ATOMIC_LOAD_BE_8: return "ATOMIC_LOAD_BE_8";
    case MemOp::ATOMIC_LOAD_BE_16: return "ATOMIC_LOAD_BE_16";
    case MemOp::ATOMIC_LOAD_BE_32: return "ATOMIC_LOAD_BE_32";
    case MemOp::ATOMIC_LOAD_BE_64: return "ATOMIC_LOAD_BE_64";
    case MemOp::ATOMIC_STORE_LE_8: return "ATOMIC_STORE_LE_8";
    case MemOp::ATOMIC_STORE_LE_16: return "ATOMIC_STORE_LE_16";
    case MemOp::ATOMIC_STORE_LE_32: return "ATOMIC_STORE_LE_32";
    case MemOp::ATOMIC_STORE_LE_64: return "ATOMIC_STORE_LE_64";
    case MemOp::ATOMIC_STORE_BE_8: return "ATOMIC_STORE_BE_8";
    case MemOp::ATOMIC_STORE_BE_16: return "ATOMIC_STORE_BE_16";
    case MemOp::ATOMIC_STORE_BE_32: return "ATOMIC_STORE_BE_32";
    case MemOp::ATOMIC_STORE_BE_64: return "ATOMIC_STORE_BE_64";
    case MemOp::MEMSET: return "MEMSET";
    case MemOp::MEMCPY: return "MEMCPY";
    case MemOp::MEMMOVE: return "MEMMOVE";
    case MemOp::MEMCMP: return "MEMCMP";
    case MemOp::MEMCHR: return "MEMCHR";
    case MemOp::BZERO: return "BZERO";
    case MemOp::STRLEN: return "STRLEN";
    case MemOp::STRNLEN: return "STRNLEN";
    case MemOp::STRCMP: return "STRCMP";
    case MemOp::STRNCMP: return "STRNCMP";
    case MemOp::STRCHR: return "STRCHR";
    case MemOp::STRRCHR: return "STRRCHR";
    case MemOp::STRSTR: return "STRSTR";
    case MemOp::STRCPY: return "STRCPY";
    case MemOp::STRNCPY: return "STRNCPY";
    case MemOp::STRCAT: return "STRCAT";
    case MemOp::STRNCAT: return "STRNCAT";
    case MemOp::STPCPY: return "STPCPY";
    case MemOp::STPNCPY: return "STPNCPY";
    case MemOp::STRTOI32: return "STRTOI32";
    case MemOp::STRTOI64: return "STRTOI64";
    case MemOp::STRTOU32: return "STRTOU32";
    case MemOp::STRTOU64: return "STRTOU64";
    case MemOp::STRTOF32: return "STRTOF32";
    case MemOp::STRTOF64: return "STRTOF64";
    case MemOp::BIT_READ_LE: return "BIT_READ_LE";
    case MemOp::BIT_WRITE_LE: return "BIT_WRITE_LE";
    case MemOp::BIT_READ_BE: return "BIT_READ_BE";
    case MemOp::BIT_WRITE_BE: return "BIT_WRITE_BE";
    case MemOp::CMPXCHG_LE_8: return "CMPXCHG_LE_8";
    case MemOp::CMPXCHG_LE_16: return "CMPXCHG_LE_16";
    case MemOp::CMPXCHG_LE_32: return "CMPXCHG_LE_32";
    case MemOp::CMPXCHG_LE_64: return "CMPXCHG_LE_64";
    case MemOp::CMPXCHG_BE_8: return "CMPXCHG_BE_8";
    case MemOp::CMPXCHG_BE_16: return "CMPXCHG_BE_16";
    case MemOp::CMPXCHG_BE_32: return "CMPXCHG_BE_32";
    case MemOp::CMPXCHG_BE_64: return "CMPXCHG_BE_64";
    case MemOp::CONSUME_VA_PARAM: return "CONSUME_VA_PARAM";
  }
  return "UNKNOWN";
}

const char *EnumeratorName(BitwiseOp op) noexcept {
  switch (op) {
    case BitwiseOp::BSWAP16: return "BSWAP16";
    case BitwiseOp::BSWAP32: return "BSWAP32";
    case BitwiseOp::BSWAP64: return "BSWAP64";
    case BitwiseOp::POPCOUNT: return "POPCOUNT";
    case BitwiseOp::CLZ: return "CLZ";
    case BitwiseOp::CTZ: return "CTZ";
    case BitwiseOp::FFS: return "FFS";
    case BitwiseOp::PARITY: return "PARITY";
    case BitwiseOp::ROTL: return "ROTL";
    case BitwiseOp::ROTR: return "ROTR";
    case BitwiseOp::ABS: return "ABS";
    case BitwiseOp::EXPECT: return "EXPECT";
    case BitwiseOp::ASSUME: return "ASSUME";
  }
  return "UNKNOWN";
}

const char *EnumeratorName(FloatOp op) noexcept {
  switch (op) {
    case FloatOp::ISNAN: return "ISNAN";
    case FloatOp::ISINF: return "ISINF";
    case FloatOp::ISFINITE: return "ISFINITE";
    case FloatOp::FABS: return "FABS";
    case FloatOp::COPYSIGN: return "COPYSIGN";
    case FloatOp::FMIN: return "FMIN";
    case FloatOp::FMAX: return "FMAX";
    case FloatOp::CEIL: return "CEIL";
    case FloatOp::FLOOR: return "FLOOR";
    case FloatOp::ROUND: return "ROUND";
    case FloatOp::TRUNC: return "TRUNC";
    case FloatOp::SQRT: return "SQRT";
    case FloatOp::INF: return "INF";
    case FloatOp::NAN_VAL: return "NAN_VAL";
    case FloatOp::FLOAT_HUGE: return "FLOAT_HUGE";
    case FloatOp::SIN: return "SIN";
    case FloatOp::COS: return "COS";
    case FloatOp::TAN: return "TAN";
    case FloatOp::ASIN: return "ASIN";
    case FloatOp::ACOS: return "ACOS";
    case FloatOp::ATAN: return "ATAN";
    case FloatOp::ATAN2: return "ATAN2";
    case FloatOp::EXP: return "EXP";
    case FloatOp::EXP2: return "EXP2";
    case FloatOp::LOG: return "LOG";
    case FloatOp::LOG2: return "LOG2";
    case FloatOp::LOG10: return "LOG10";
    case FloatOp::POW: return "POW";
    case FloatOp::FMOD: return "FMOD";
    case FloatOp::REMAINDER: return "REMAINDER";
    case FloatOp::FMA: return "FMA";
    case FloatOp::SINH: return "SINH";
    case FloatOp::COSH: return "COSH";
    case FloatOp::TANH: return "TANH";
    case FloatOp::HYPOT: return "HYPOT";
    case FloatOp::ERF: return "ERF";
    case FloatOp::ERFC: return "ERFC";
    case FloatOp::TGAMMA: return "TGAMMA";
    case FloatOp::LGAMMA: return "LGAMMA";
    case FloatOp::FDIM: return "FDIM";
    case FloatOp::SIGNBIT: return "SIGNBIT";
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
    case StructureKind::EXPRESSION_SCOPE: return "EXPRESSION_SCOPE";
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
    case IREntityKind::IR_STRUCTURE: return "IR_STRUCTURE";
  }
  return "UNKNOWN";
}

}  // namespace mx
