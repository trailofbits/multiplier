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
    case OpCode::LOGICAL_AND: return "LOGICAL_AND";
    case OpCode::LOGICAL_OR: return "LOGICAL_OR";
    case OpCode::PTR_DIFF_32: return "PTR_DIFF_32";
    case OpCode::PTR_DIFF_64: return "PTR_DIFF_64";
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
    case OpCode::BITWISE_8: return "BITWISE_8";
    case OpCode::BITWISE_16: return "BITWISE_16";
    case OpCode::BITWISE_32: return "BITWISE_32";
    case OpCode::BITWISE_64: return "BITWISE_64";
    case OpCode::ABS_8: return "ABS_8";
    case OpCode::ABS_16: return "ABS_16";
    case OpCode::ABS_32: return "ABS_32";
    case OpCode::ABS_64: return "ABS_64";
    case OpCode::FLOAT: return "FLOAT";
    case OpCode::UNDEFINED: return "UNDEFINED";
    case OpCode::ATOMIC_ADD_8: return "ATOMIC_ADD_8";
    case OpCode::ATOMIC_ADD_16: return "ATOMIC_ADD_16";
    case OpCode::ATOMIC_ADD_32: return "ATOMIC_ADD_32";
    case OpCode::ATOMIC_ADD_64: return "ATOMIC_ADD_64";
    case OpCode::ATOMIC_SUB_8: return "ATOMIC_SUB_8";
    case OpCode::ATOMIC_SUB_16: return "ATOMIC_SUB_16";
    case OpCode::ATOMIC_SUB_32: return "ATOMIC_SUB_32";
    case OpCode::ATOMIC_SUB_64: return "ATOMIC_SUB_64";
    case OpCode::ATOMIC_AND_8: return "ATOMIC_AND_8";
    case OpCode::ATOMIC_AND_16: return "ATOMIC_AND_16";
    case OpCode::ATOMIC_AND_32: return "ATOMIC_AND_32";
    case OpCode::ATOMIC_AND_64: return "ATOMIC_AND_64";
    case OpCode::ATOMIC_OR_8: return "ATOMIC_OR_8";
    case OpCode::ATOMIC_OR_16: return "ATOMIC_OR_16";
    case OpCode::ATOMIC_OR_32: return "ATOMIC_OR_32";
    case OpCode::ATOMIC_OR_64: return "ATOMIC_OR_64";
    case OpCode::ATOMIC_XOR_8: return "ATOMIC_XOR_8";
    case OpCode::ATOMIC_XOR_16: return "ATOMIC_XOR_16";
    case OpCode::ATOMIC_XOR_32: return "ATOMIC_XOR_32";
    case OpCode::ATOMIC_XOR_64: return "ATOMIC_XOR_64";
    case OpCode::ATOMIC_NAND_8: return "ATOMIC_NAND_8";
    case OpCode::ATOMIC_NAND_16: return "ATOMIC_NAND_16";
    case OpCode::ATOMIC_NAND_32: return "ATOMIC_NAND_32";
    case OpCode::ATOMIC_NAND_64: return "ATOMIC_NAND_64";
    case OpCode::ATOMIC_EXCHANGE_8: return "ATOMIC_EXCHANGE_8";
    case OpCode::ATOMIC_EXCHANGE_16: return "ATOMIC_EXCHANGE_16";
    case OpCode::ATOMIC_EXCHANGE_32: return "ATOMIC_EXCHANGE_32";
    case OpCode::ATOMIC_EXCHANGE_64: return "ATOMIC_EXCHANGE_64";
    case OpCode::ADD_OVERFLOW_8: return "ADD_OVERFLOW_8";
    case OpCode::ADD_OVERFLOW_16: return "ADD_OVERFLOW_16";
    case OpCode::ADD_OVERFLOW_32: return "ADD_OVERFLOW_32";
    case OpCode::ADD_OVERFLOW_64: return "ADD_OVERFLOW_64";
    case OpCode::SUB_OVERFLOW_8: return "SUB_OVERFLOW_8";
    case OpCode::SUB_OVERFLOW_16: return "SUB_OVERFLOW_16";
    case OpCode::SUB_OVERFLOW_32: return "SUB_OVERFLOW_32";
    case OpCode::SUB_OVERFLOW_64: return "SUB_OVERFLOW_64";
    case OpCode::MUL_OVERFLOW_8: return "MUL_OVERFLOW_8";
    case OpCode::MUL_OVERFLOW_16: return "MUL_OVERFLOW_16";
    case OpCode::MUL_OVERFLOW_32: return "MUL_OVERFLOW_32";
    case OpCode::MUL_OVERFLOW_64: return "MUL_OVERFLOW_64";
    case OpCode::LAST_VALUE: return "LAST_VALUE";
    case OpCode::UNKNOWN: return "UNKNOWN";
    case OpCode::FCMP_EQ_32: return "FCMP_EQ_32";
    case OpCode::FCMP_EQ_64: return "FCMP_EQ_64";
    case OpCode::FCMP_NE_32: return "FCMP_NE_32";
    case OpCode::FCMP_NE_64: return "FCMP_NE_64";
    case OpCode::FCMP_LT_32: return "FCMP_LT_32";
    case OpCode::FCMP_LT_64: return "FCMP_LT_64";
    case OpCode::FCMP_LE_32: return "FCMP_LE_32";
    case OpCode::FCMP_LE_64: return "FCMP_LE_64";
    case OpCode::FCMP_GT_32: return "FCMP_GT_32";
    case OpCode::FCMP_GT_64: return "FCMP_GT_64";
    case OpCode::FCMP_GE_32: return "FCMP_GE_32";
    case OpCode::FCMP_GE_64: return "FCMP_GE_64";
    case OpCode::FADD_32: return "FADD_32";
    case OpCode::FADD_64: return "FADD_64";
    case OpCode::FSUB_32: return "FSUB_32";
    case OpCode::FSUB_64: return "FSUB_64";
    case OpCode::FMUL_32: return "FMUL_32";
    case OpCode::FMUL_64: return "FMUL_64";
    case OpCode::FDIV_32: return "FDIV_32";
    case OpCode::FDIV_64: return "FDIV_64";
    case OpCode::FREM_32: return "FREM_32";
    case OpCode::FREM_64: return "FREM_64";
    case OpCode::FNEG_32: return "FNEG_32";
    case OpCode::FNEG_64: return "FNEG_64";
    case OpCode::ADD_8: return "ADD_8";
    case OpCode::ADD_16: return "ADD_16";
    case OpCode::ADD_32: return "ADD_32";
    case OpCode::ADD_64: return "ADD_64";
    case OpCode::SUB_8: return "SUB_8";
    case OpCode::SUB_16: return "SUB_16";
    case OpCode::SUB_32: return "SUB_32";
    case OpCode::SUB_64: return "SUB_64";
    case OpCode::MUL_8: return "MUL_8";
    case OpCode::MUL_16: return "MUL_16";
    case OpCode::MUL_32: return "MUL_32";
    case OpCode::MUL_64: return "MUL_64";
    case OpCode::DIV_8: return "DIV_8";
    case OpCode::DIV_16: return "DIV_16";
    case OpCode::DIV_32: return "DIV_32";
    case OpCode::DIV_64: return "DIV_64";
    case OpCode::REM_8: return "REM_8";
    case OpCode::REM_16: return "REM_16";
    case OpCode::REM_32: return "REM_32";
    case OpCode::REM_64: return "REM_64";
    case OpCode::UDIV_8: return "UDIV_8";
    case OpCode::UDIV_16: return "UDIV_16";
    case OpCode::UDIV_32: return "UDIV_32";
    case OpCode::UDIV_64: return "UDIV_64";
    case OpCode::UREM_8: return "UREM_8";
    case OpCode::UREM_16: return "UREM_16";
    case OpCode::UREM_32: return "UREM_32";
    case OpCode::UREM_64: return "UREM_64";
    case OpCode::USHR_8: return "USHR_8";
    case OpCode::USHR_16: return "USHR_16";
    case OpCode::USHR_32: return "USHR_32";
    case OpCode::USHR_64: return "USHR_64";
    case OpCode::BIT_AND_8: return "BIT_AND_8";
    case OpCode::BIT_AND_16: return "BIT_AND_16";
    case OpCode::BIT_AND_32: return "BIT_AND_32";
    case OpCode::BIT_AND_64: return "BIT_AND_64";
    case OpCode::BIT_OR_8: return "BIT_OR_8";
    case OpCode::BIT_OR_16: return "BIT_OR_16";
    case OpCode::BIT_OR_32: return "BIT_OR_32";
    case OpCode::BIT_OR_64: return "BIT_OR_64";
    case OpCode::BIT_XOR_8: return "BIT_XOR_8";
    case OpCode::BIT_XOR_16: return "BIT_XOR_16";
    case OpCode::BIT_XOR_32: return "BIT_XOR_32";
    case OpCode::BIT_XOR_64: return "BIT_XOR_64";
    case OpCode::SHL_8: return "SHL_8";
    case OpCode::SHL_16: return "SHL_16";
    case OpCode::SHL_32: return "SHL_32";
    case OpCode::SHL_64: return "SHL_64";
    case OpCode::SHR_8: return "SHR_8";
    case OpCode::SHR_16: return "SHR_16";
    case OpCode::SHR_32: return "SHR_32";
    case OpCode::SHR_64: return "SHR_64";
    case OpCode::CMP_EQ_8: return "CMP_EQ_8";
    case OpCode::CMP_EQ_16: return "CMP_EQ_16";
    case OpCode::CMP_EQ_32: return "CMP_EQ_32";
    case OpCode::CMP_EQ_64: return "CMP_EQ_64";
    case OpCode::CMP_NE_8: return "CMP_NE_8";
    case OpCode::CMP_NE_16: return "CMP_NE_16";
    case OpCode::CMP_NE_32: return "CMP_NE_32";
    case OpCode::CMP_NE_64: return "CMP_NE_64";
    case OpCode::CMP_LT_8: return "CMP_LT_8";
    case OpCode::CMP_LT_16: return "CMP_LT_16";
    case OpCode::CMP_LT_32: return "CMP_LT_32";
    case OpCode::CMP_LT_64: return "CMP_LT_64";
    case OpCode::CMP_LE_8: return "CMP_LE_8";
    case OpCode::CMP_LE_16: return "CMP_LE_16";
    case OpCode::CMP_LE_32: return "CMP_LE_32";
    case OpCode::CMP_LE_64: return "CMP_LE_64";
    case OpCode::CMP_GT_8: return "CMP_GT_8";
    case OpCode::CMP_GT_16: return "CMP_GT_16";
    case OpCode::CMP_GT_32: return "CMP_GT_32";
    case OpCode::CMP_GT_64: return "CMP_GT_64";
    case OpCode::CMP_GE_8: return "CMP_GE_8";
    case OpCode::CMP_GE_16: return "CMP_GE_16";
    case OpCode::CMP_GE_32: return "CMP_GE_32";
    case OpCode::CMP_GE_64: return "CMP_GE_64";
    case OpCode::UCMP_LT_8: return "UCMP_LT_8";
    case OpCode::UCMP_LT_16: return "UCMP_LT_16";
    case OpCode::UCMP_LT_32: return "UCMP_LT_32";
    case OpCode::UCMP_LT_64: return "UCMP_LT_64";
    case OpCode::UCMP_LE_8: return "UCMP_LE_8";
    case OpCode::UCMP_LE_16: return "UCMP_LE_16";
    case OpCode::UCMP_LE_32: return "UCMP_LE_32";
    case OpCode::UCMP_LE_64: return "UCMP_LE_64";
    case OpCode::UCMP_GT_8: return "UCMP_GT_8";
    case OpCode::UCMP_GT_16: return "UCMP_GT_16";
    case OpCode::UCMP_GT_32: return "UCMP_GT_32";
    case OpCode::UCMP_GT_64: return "UCMP_GT_64";
    case OpCode::UCMP_GE_8: return "UCMP_GE_8";
    case OpCode::UCMP_GE_16: return "UCMP_GE_16";
    case OpCode::UCMP_GE_32: return "UCMP_GE_32";
    case OpCode::UCMP_GE_64: return "UCMP_GE_64";
    case OpCode::NEG_8: return "NEG_8";
    case OpCode::NEG_16: return "NEG_16";
    case OpCode::NEG_32: return "NEG_32";
    case OpCode::NEG_64: return "NEG_64";
    case OpCode::BIT_NOT_8: return "BIT_NOT_8";
    case OpCode::BIT_NOT_16: return "BIT_NOT_16";
    case OpCode::BIT_NOT_32: return "BIT_NOT_32";
    case OpCode::BIT_NOT_64: return "BIT_NOT_64";
    case OpCode::PTR_ADD_32: return "PTR_ADD_32";
    case OpCode::PTR_ADD_64: return "PTR_ADD_64";
    case OpCode::GEP_FIELD_32: return "GEP_FIELD_32";
    case OpCode::GEP_FIELD_64: return "GEP_FIELD_64";
    case OpCode::GLOBAL_PTR_32: return "GLOBAL_PTR_32";
    case OpCode::GLOBAL_PTR_64: return "GLOBAL_PTR_64";
    case OpCode::THREAD_LOCAL_PTR_32: return "THREAD_LOCAL_PTR_32";
    case OpCode::THREAD_LOCAL_PTR_64: return "THREAD_LOCAL_PTR_64";
    case OpCode::FUNC_PTR_32: return "FUNC_PTR_32";
    case OpCode::FUNC_PTR_64: return "FUNC_PTR_64";
    case OpCode::STRING_PTR_32: return "STRING_PTR_32";
    case OpCode::STRING_PTR_64: return "STRING_PTR_64";
    case OpCode::PARAM_PTR_32: return "PARAM_PTR_32";
    case OpCode::PARAM_PTR_64: return "PARAM_PTR_64";
    case OpCode::FRAME_PTR_32: return "FRAME_PTR_32";
    case OpCode::FRAME_PTR_64: return "FRAME_PTR_64";
    case OpCode::RETURN_PTR_32: return "RETURN_PTR_32";
    case OpCode::RETURN_PTR_64: return "RETURN_PTR_64";
    case OpCode::RETURN_ADDRESS_32: return "RETURN_ADDRESS_32";
    case OpCode::RETURN_ADDRESS_64: return "RETURN_ADDRESS_64";
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
    case MemOp::LOAD_F32_LE: return "LOAD_F32_LE";
    case MemOp::LOAD_F64_LE: return "LOAD_F64_LE";
    case MemOp::LOAD_F32_BE: return "LOAD_F32_BE";
    case MemOp::LOAD_F64_BE: return "LOAD_F64_BE";
    case MemOp::STORE_F32_LE: return "STORE_F32_LE";
    case MemOp::STORE_F64_LE: return "STORE_F64_LE";
    case MemOp::STORE_F32_BE: return "STORE_F32_BE";
    case MemOp::STORE_F64_BE: return "STORE_F64_BE";
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
    // (ABS moved to sized opcode)
  }
  return "UNKNOWN";
}

const char *EnumeratorName(FloatOp op) noexcept {
  switch (op) {
    case FloatOp::ISNAN_32: return "ISNAN_32";
    case FloatOp::ISNAN_64: return "ISNAN_64";
    case FloatOp::ISINF_32: return "ISINF_32";
    case FloatOp::ISINF_64: return "ISINF_64";
    case FloatOp::ISFINITE_32: return "ISFINITE_32";
    case FloatOp::ISFINITE_64: return "ISFINITE_64";
    case FloatOp::FABS_32: return "FABS_32";
    case FloatOp::FABS_64: return "FABS_64";
    case FloatOp::COPYSIGN_32: return "COPYSIGN_32";
    case FloatOp::COPYSIGN_64: return "COPYSIGN_64";
    case FloatOp::FMIN_32: return "FMIN_32";
    case FloatOp::FMIN_64: return "FMIN_64";
    case FloatOp::FMAX_32: return "FMAX_32";
    case FloatOp::FMAX_64: return "FMAX_64";
    case FloatOp::CEIL_32: return "CEIL_32";
    case FloatOp::CEIL_64: return "CEIL_64";
    case FloatOp::FLOOR_32: return "FLOOR_32";
    case FloatOp::FLOOR_64: return "FLOOR_64";
    case FloatOp::ROUND_32: return "ROUND_32";
    case FloatOp::ROUND_64: return "ROUND_64";
    case FloatOp::TRUNC_32: return "TRUNC_32";
    case FloatOp::TRUNC_64: return "TRUNC_64";
    case FloatOp::SQRT_32: return "SQRT_32";
    case FloatOp::SQRT_64: return "SQRT_64";
    case FloatOp::INF_32: return "INF_32";
    case FloatOp::INF_64: return "INF_64";
    case FloatOp::NAN_32: return "NAN_32";
    case FloatOp::NAN_64: return "NAN_64";
    case FloatOp::HUGE_32: return "HUGE_32";
    case FloatOp::HUGE_64: return "HUGE_64";
    case FloatOp::SIN_32: return "SIN_32";
    case FloatOp::SIN_64: return "SIN_64";
    case FloatOp::COS_32: return "COS_32";
    case FloatOp::COS_64: return "COS_64";
    case FloatOp::TAN_32: return "TAN_32";
    case FloatOp::TAN_64: return "TAN_64";
    case FloatOp::ASIN_32: return "ASIN_32";
    case FloatOp::ASIN_64: return "ASIN_64";
    case FloatOp::ACOS_32: return "ACOS_32";
    case FloatOp::ACOS_64: return "ACOS_64";
    case FloatOp::ATAN_32: return "ATAN_32";
    case FloatOp::ATAN_64: return "ATAN_64";
    case FloatOp::ATAN2_32: return "ATAN2_32";
    case FloatOp::ATAN2_64: return "ATAN2_64";
    case FloatOp::EXP_32: return "EXP_32";
    case FloatOp::EXP_64: return "EXP_64";
    case FloatOp::EXP2_32: return "EXP2_32";
    case FloatOp::EXP2_64: return "EXP2_64";
    case FloatOp::LOG_32: return "LOG_32";
    case FloatOp::LOG_64: return "LOG_64";
    case FloatOp::LOG2_32: return "LOG2_32";
    case FloatOp::LOG2_64: return "LOG2_64";
    case FloatOp::LOG10_32: return "LOG10_32";
    case FloatOp::LOG10_64: return "LOG10_64";
    case FloatOp::POW_32: return "POW_32";
    case FloatOp::POW_64: return "POW_64";
    case FloatOp::FMOD_32: return "FMOD_32";
    case FloatOp::FMOD_64: return "FMOD_64";
    case FloatOp::REMAINDER_32: return "REMAINDER_32";
    case FloatOp::REMAINDER_64: return "REMAINDER_64";
    case FloatOp::FMA_32: return "FMA_32";
    case FloatOp::FMA_64: return "FMA_64";
    case FloatOp::SINH_32: return "SINH_32";
    case FloatOp::SINH_64: return "SINH_64";
    case FloatOp::COSH_32: return "COSH_32";
    case FloatOp::COSH_64: return "COSH_64";
    case FloatOp::TANH_32: return "TANH_32";
    case FloatOp::TANH_64: return "TANH_64";
    case FloatOp::HYPOT_32: return "HYPOT_32";
    case FloatOp::HYPOT_64: return "HYPOT_64";
    case FloatOp::ERF_32: return "ERF_32";
    case FloatOp::ERF_64: return "ERF_64";
    case FloatOp::ERFC_32: return "ERFC_32";
    case FloatOp::ERFC_64: return "ERFC_64";
    case FloatOp::TGAMMA_32: return "TGAMMA_32";
    case FloatOp::TGAMMA_64: return "TGAMMA_64";
    case FloatOp::LGAMMA_32: return "LGAMMA_32";
    case FloatOp::LGAMMA_64: return "LGAMMA_64";
    case FloatOp::FDIM_32: return "FDIM_32";
    case FloatOp::FDIM_64: return "FDIM_64";
    case FloatOp::SIGNBIT_32: return "SIGNBIT_32";
    case FloatOp::SIGNBIT_64: return "SIGNBIT_64";
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
