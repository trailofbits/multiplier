// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/OperationKind.h>

namespace mx {

const char *EnumeratorName(ir::OperationKind kind) {
  switch (kind) {
    default: return "UNKNOWN";
    case ir::OperationKind::BUILTIN_MODULE: return "BUILTIN_MODULE";
    case ir::OperationKind::BUILTIN_UNREALIZED_CONVERSION_CAST: return "BUILTIN_UNREALIZED_CONVERSION_CAST";
    case ir::OperationKind::LLVM_ASHR: return "LLVM_ASHR";
    case ir::OperationKind::LLVM_ACCESS_GROUP: return "LLVM_ACCESS_GROUP";
    case ir::OperationKind::LLVM_ADD: return "LLVM_ADD";
    case ir::OperationKind::LLVM_ADDRSPACECAST: return "LLVM_ADDRSPACECAST";
    case ir::OperationKind::LLVM_MLIR_ADDRESSOF: return "LLVM_MLIR_ADDRESSOF";
    case ir::OperationKind::LLVM_ALIAS_SCOPE_DOMAIN: return "LLVM_ALIAS_SCOPE_DOMAIN";
    case ir::OperationKind::LLVM_ALIAS_SCOPE: return "LLVM_ALIAS_SCOPE";
    case ir::OperationKind::LLVM_ALLOCA: return "LLVM_ALLOCA";
    case ir::OperationKind::LLVM_AND: return "LLVM_AND";
    case ir::OperationKind::LLVM_CMPXCHG: return "LLVM_CMPXCHG";
    case ir::OperationKind::LLVM_ATOMICRMW: return "LLVM_ATOMICRMW";
    case ir::OperationKind::LLVM_BITCAST: return "LLVM_BITCAST";
    case ir::OperationKind::LLVM_BR: return "LLVM_BR";
    case ir::OperationKind::LLVM_CALL: return "LLVM_CALL";
    case ir::OperationKind::LLVM_COND_BR: return "LLVM_COND_BR";
    case ir::OperationKind::LLVM_MLIR_CONSTANT: return "LLVM_MLIR_CONSTANT";
    case ir::OperationKind::LLVM_EXTRACTELEMENT: return "LLVM_EXTRACTELEMENT";
    case ir::OperationKind::LLVM_EXTRACTVALUE: return "LLVM_EXTRACTVALUE";
    case ir::OperationKind::LLVM_FADD: return "LLVM_FADD";
    case ir::OperationKind::LLVM_FCMP: return "LLVM_FCMP";
    case ir::OperationKind::LLVM_FDIV: return "LLVM_FDIV";
    case ir::OperationKind::LLVM_FMUL: return "LLVM_FMUL";
    case ir::OperationKind::LLVM_FNEG: return "LLVM_FNEG";
    case ir::OperationKind::LLVM_FPEXT: return "LLVM_FPEXT";
    case ir::OperationKind::LLVM_FPTOSI: return "LLVM_FPTOSI";
    case ir::OperationKind::LLVM_FPTOUI: return "LLVM_FPTOUI";
    case ir::OperationKind::LLVM_FPTRUNC: return "LLVM_FPTRUNC";
    case ir::OperationKind::LLVM_FREM: return "LLVM_FREM";
    case ir::OperationKind::LLVM_FSUB: return "LLVM_FSUB";
    case ir::OperationKind::LLVM_FENCE: return "LLVM_FENCE";
    case ir::OperationKind::LLVM_FREEZE: return "LLVM_FREEZE";
    case ir::OperationKind::LLVM_GETELEMENTPTR: return "LLVM_GETELEMENTPTR";
    case ir::OperationKind::LLVM_MLIR_GLOBAL_CTORS: return "LLVM_MLIR_GLOBAL_CTORS";
    case ir::OperationKind::LLVM_MLIR_GLOBAL_DTORS: return "LLVM_MLIR_GLOBAL_DTORS";
    case ir::OperationKind::LLVM_MLIR_GLOBAL: return "LLVM_MLIR_GLOBAL";
    case ir::OperationKind::LLVM_ICMP: return "LLVM_ICMP";
    case ir::OperationKind::LLVM_INLINE_ASM: return "LLVM_INLINE_ASM";
    case ir::OperationKind::LLVM_INSERTELEMENT: return "LLVM_INSERTELEMENT";
    case ir::OperationKind::LLVM_INSERTVALUE: return "LLVM_INSERTVALUE";
    case ir::OperationKind::LLVM_INTTOPTR: return "LLVM_INTTOPTR";
    case ir::OperationKind::LLVM_INVOKE: return "LLVM_INVOKE";
    case ir::OperationKind::LLVM_FUNC: return "LLVM_FUNC";
    case ir::OperationKind::LLVM_LSHR: return "LLVM_LSHR";
    case ir::OperationKind::LLVM_LANDINGPAD: return "LLVM_LANDINGPAD";
    case ir::OperationKind::LLVM_LOAD: return "LLVM_LOAD";
    case ir::OperationKind::LLVM_METADATA: return "LLVM_METADATA";
    case ir::OperationKind::LLVM_MUL: return "LLVM_MUL";
    case ir::OperationKind::LLVM_MLIR_NULL: return "LLVM_MLIR_NULL";
    case ir::OperationKind::LLVM_OR: return "LLVM_OR";
    case ir::OperationKind::LLVM_PTRTOINT: return "LLVM_PTRTOINT";
    case ir::OperationKind::LLVM_RESUME: return "LLVM_RESUME";
    case ir::OperationKind::LLVM_RETURN: return "LLVM_RETURN";
    case ir::OperationKind::LLVM_SDIV: return "LLVM_SDIV";
    case ir::OperationKind::LLVM_SEXT: return "LLVM_SEXT";
    case ir::OperationKind::LLVM_SITOFP: return "LLVM_SITOFP";
    case ir::OperationKind::LLVM_SREM: return "LLVM_SREM";
    case ir::OperationKind::LLVM_SELECT: return "LLVM_SELECT";
    case ir::OperationKind::LLVM_SHL: return "LLVM_SHL";
    case ir::OperationKind::LLVM_SHUFFLEVECTOR: return "LLVM_SHUFFLEVECTOR";
    case ir::OperationKind::LLVM_STORE: return "LLVM_STORE";
    case ir::OperationKind::LLVM_SUB: return "LLVM_SUB";
    case ir::OperationKind::LLVM_SWITCH: return "LLVM_SWITCH";
    case ir::OperationKind::LLVM_TBAA_ROOT: return "LLVM_TBAA_ROOT";
    case ir::OperationKind::LLVM_TBAA_TAG: return "LLVM_TBAA_TAG";
    case ir::OperationKind::LLVM_TBAA_TYPE_DESC: return "LLVM_TBAA_TYPE_DESC";
    case ir::OperationKind::LLVM_TRUNC: return "LLVM_TRUNC";
    case ir::OperationKind::LLVM_UDIV: return "LLVM_UDIV";
    case ir::OperationKind::LLVM_UITOFP: return "LLVM_UITOFP";
    case ir::OperationKind::LLVM_UREM: return "LLVM_UREM";
    case ir::OperationKind::LLVM_MLIR_UNDEF: return "LLVM_MLIR_UNDEF";
    case ir::OperationKind::LLVM_UNREACHABLE: return "LLVM_UNREACHABLE";
    case ir::OperationKind::LLVM_XOR: return "LLVM_XOR";
    case ir::OperationKind::LLVM_ZEXT: return "LLVM_ZEXT";
    case ir::OperationKind::LLVM_INTR_ABS: return "LLVM_INTR_ABS";
    case ir::OperationKind::LLVM_INTR_ASSUME: return "LLVM_INTR_ASSUME";
    case ir::OperationKind::LLVM_INTR_BITREVERSE: return "LLVM_INTR_BITREVERSE";
    case ir::OperationKind::LLVM_CALL_INTRINSIC: return "LLVM_CALL_INTRINSIC";
    case ir::OperationKind::LLVM_INTR_COPYSIGN: return "LLVM_INTR_COPYSIGN";
    case ir::OperationKind::LLVM_INTR_CORO_ALIGN: return "LLVM_INTR_CORO_ALIGN";
    case ir::OperationKind::LLVM_INTR_CORO_BEGIN: return "LLVM_INTR_CORO_BEGIN";
    case ir::OperationKind::LLVM_INTR_CORO_END: return "LLVM_INTR_CORO_END";
    case ir::OperationKind::LLVM_INTR_CORO_FREE: return "LLVM_INTR_CORO_FREE";
    case ir::OperationKind::LLVM_INTR_CORO_ID: return "LLVM_INTR_CORO_ID";
    case ir::OperationKind::LLVM_INTR_CORO_RESUME: return "LLVM_INTR_CORO_RESUME";
    case ir::OperationKind::LLVM_INTR_CORO_SAVE: return "LLVM_INTR_CORO_SAVE";
    case ir::OperationKind::LLVM_INTR_CORO_SIZE: return "LLVM_INTR_CORO_SIZE";
    case ir::OperationKind::LLVM_INTR_CORO_SUSPEND: return "LLVM_INTR_CORO_SUSPEND";
    case ir::OperationKind::LLVM_INTR_COS: return "LLVM_INTR_COS";
    case ir::OperationKind::LLVM_INTR_CTLZ: return "LLVM_INTR_CTLZ";
    case ir::OperationKind::LLVM_INTR_CTTZ: return "LLVM_INTR_CTTZ";
    case ir::OperationKind::LLVM_INTR_CTPOP: return "LLVM_INTR_CTPOP";
    case ir::OperationKind::LLVM_INTR_DBG_ADDR: return "LLVM_INTR_DBG_ADDR";
    case ir::OperationKind::LLVM_INTR_DBG_DECLARE: return "LLVM_INTR_DBG_DECLARE";
    case ir::OperationKind::LLVM_INTR_DBG_VALUE: return "LLVM_INTR_DBG_VALUE";
    case ir::OperationKind::LLVM_INTR_EH_TYPEID_FOR: return "LLVM_INTR_EH_TYPEID_FOR";
    case ir::OperationKind::LLVM_INTR_EXP2: return "LLVM_INTR_EXP2";
    case ir::OperationKind::LLVM_INTR_EXP: return "LLVM_INTR_EXP";
    case ir::OperationKind::LLVM_INTR_FABS: return "LLVM_INTR_FABS";
    case ir::OperationKind::LLVM_INTR_CEIL: return "LLVM_INTR_CEIL";
    case ir::OperationKind::LLVM_INTR_FLOOR: return "LLVM_INTR_FLOOR";
    case ir::OperationKind::LLVM_INTR_FMA: return "LLVM_INTR_FMA";
    case ir::OperationKind::LLVM_INTR_FMULADD: return "LLVM_INTR_FMULADD";
    case ir::OperationKind::LLVM_INTR_TRUNC: return "LLVM_INTR_TRUNC";
    case ir::OperationKind::LLVM_INTR_GET_ACTIVE_LANE_MASK: return "LLVM_INTR_GET_ACTIVE_LANE_MASK";
    case ir::OperationKind::LLVM_INTR_IS_FPCLASS: return "LLVM_INTR_IS_FPCLASS";
    case ir::OperationKind::LLVM_INTR_LIFETIME_END: return "LLVM_INTR_LIFETIME_END";
    case ir::OperationKind::LLVM_INTR_LIFETIME_START: return "LLVM_INTR_LIFETIME_START";
    case ir::OperationKind::LLVM_INTR_LOG10: return "LLVM_INTR_LOG10";
    case ir::OperationKind::LLVM_INTR_LOG2: return "LLVM_INTR_LOG2";
    case ir::OperationKind::LLVM_INTR_LOG: return "LLVM_INTR_LOG";
    case ir::OperationKind::LLVM_INTR_MASKED_LOAD: return "LLVM_INTR_MASKED_LOAD";
    case ir::OperationKind::LLVM_INTR_MASKED_STORE: return "LLVM_INTR_MASKED_STORE";
    case ir::OperationKind::LLVM_INTR_MATRIX_COLUMN_MAJOR_LOAD: return "LLVM_INTR_MATRIX_COLUMN_MAJOR_LOAD";
    case ir::OperationKind::LLVM_INTR_MATRIX_COLUMN_MAJOR_STORE: return "LLVM_INTR_MATRIX_COLUMN_MAJOR_STORE";
    case ir::OperationKind::LLVM_INTR_MATRIX_MULTIPLY: return "LLVM_INTR_MATRIX_MULTIPLY";
    case ir::OperationKind::LLVM_INTR_MATRIX_TRANSPOSE: return "LLVM_INTR_MATRIX_TRANSPOSE";
    case ir::OperationKind::LLVM_INTR_MAXNUM: return "LLVM_INTR_MAXNUM";
    case ir::OperationKind::LLVM_INTR_MAXIMUM: return "LLVM_INTR_MAXIMUM";
    case ir::OperationKind::LLVM_INTR_MEMCPY_INLINE: return "LLVM_INTR_MEMCPY_INLINE";
    case ir::OperationKind::LLVM_INTR_MEMCPY: return "LLVM_INTR_MEMCPY";
    case ir::OperationKind::LLVM_INTR_MEMMOVE: return "LLVM_INTR_MEMMOVE";
    case ir::OperationKind::LLVM_INTR_MEMSET: return "LLVM_INTR_MEMSET";
    case ir::OperationKind::LLVM_INTR_MINNUM: return "LLVM_INTR_MINNUM";
    case ir::OperationKind::LLVM_INTR_MINIMUM: return "LLVM_INTR_MINIMUM";
    case ir::OperationKind::LLVM_INTR_POWI: return "LLVM_INTR_POWI";
    case ir::OperationKind::LLVM_INTR_POW: return "LLVM_INTR_POW";
    case ir::OperationKind::LLVM_INTR_PREFETCH: return "LLVM_INTR_PREFETCH";
    case ir::OperationKind::LLVM_INTR_ROUNDEVEN: return "LLVM_INTR_ROUNDEVEN";
    case ir::OperationKind::LLVM_INTR_ROUND: return "LLVM_INTR_ROUND";
    case ir::OperationKind::LLVM_INTR_SADD_WITH_OVERFLOW: return "LLVM_INTR_SADD_WITH_OVERFLOW";
    case ir::OperationKind::LLVM_INTR_SMAX: return "LLVM_INTR_SMAX";
    case ir::OperationKind::LLVM_INTR_SMIN: return "LLVM_INTR_SMIN";
    case ir::OperationKind::LLVM_INTR_SMUL_WITH_OVERFLOW: return "LLVM_INTR_SMUL_WITH_OVERFLOW";
    case ir::OperationKind::LLVM_INTR_SSUB_WITH_OVERFLOW: return "LLVM_INTR_SSUB_WITH_OVERFLOW";
    case ir::OperationKind::LLVM_INTR_SIN: return "LLVM_INTR_SIN";
    case ir::OperationKind::LLVM_INTR_SQRT: return "LLVM_INTR_SQRT";
    case ir::OperationKind::LLVM_INTR_STACKRESTORE: return "LLVM_INTR_STACKRESTORE";
    case ir::OperationKind::LLVM_INTR_STACKSAVE: return "LLVM_INTR_STACKSAVE";
    case ir::OperationKind::LLVM_INTR_EXPERIMENTAL_STEPVECTOR: return "LLVM_INTR_EXPERIMENTAL_STEPVECTOR";
    case ir::OperationKind::LLVM_INTR_UADD_WITH_OVERFLOW: return "LLVM_INTR_UADD_WITH_OVERFLOW";
    case ir::OperationKind::LLVM_INTR_UMAX: return "LLVM_INTR_UMAX";
    case ir::OperationKind::LLVM_INTR_UMIN: return "LLVM_INTR_UMIN";
    case ir::OperationKind::LLVM_INTR_UMUL_WITH_OVERFLOW: return "LLVM_INTR_UMUL_WITH_OVERFLOW";
    case ir::OperationKind::LLVM_INTR_USUB_WITH_OVERFLOW: return "LLVM_INTR_USUB_WITH_OVERFLOW";
    case ir::OperationKind::LLVM_INTR_VP_ASHR: return "LLVM_INTR_VP_ASHR";
    case ir::OperationKind::LLVM_INTR_VP_ADD: return "LLVM_INTR_VP_ADD";
    case ir::OperationKind::LLVM_INTR_VP_AND: return "LLVM_INTR_VP_AND";
    case ir::OperationKind::LLVM_INTR_VP_FADD: return "LLVM_INTR_VP_FADD";
    case ir::OperationKind::LLVM_INTR_VP_FDIV: return "LLVM_INTR_VP_FDIV";
    case ir::OperationKind::LLVM_INTR_VP_FMUL: return "LLVM_INTR_VP_FMUL";
    case ir::OperationKind::LLVM_INTR_VP_FNEG: return "LLVM_INTR_VP_FNEG";
    case ir::OperationKind::LLVM_INTR_VP_FPEXT: return "LLVM_INTR_VP_FPEXT";
    case ir::OperationKind::LLVM_INTR_VP_FPTOSI: return "LLVM_INTR_VP_FPTOSI";
    case ir::OperationKind::LLVM_INTR_VP_FPTOUI: return "LLVM_INTR_VP_FPTOUI";
    case ir::OperationKind::LLVM_INTR_VP_FPTRUNC: return "LLVM_INTR_VP_FPTRUNC";
    case ir::OperationKind::LLVM_INTR_VP_FREM: return "LLVM_INTR_VP_FREM";
    case ir::OperationKind::LLVM_INTR_VP_FSUB: return "LLVM_INTR_VP_FSUB";
    case ir::OperationKind::LLVM_INTR_VP_FMA: return "LLVM_INTR_VP_FMA";
    case ir::OperationKind::LLVM_INTR_VP_INTTOPTR: return "LLVM_INTR_VP_INTTOPTR";
    case ir::OperationKind::LLVM_INTR_VP_LSHR: return "LLVM_INTR_VP_LSHR";
    case ir::OperationKind::LLVM_INTR_VP_LOAD: return "LLVM_INTR_VP_LOAD";
    case ir::OperationKind::LLVM_INTR_VP_MERGE: return "LLVM_INTR_VP_MERGE";
    case ir::OperationKind::LLVM_INTR_VP_MUL: return "LLVM_INTR_VP_MUL";
    case ir::OperationKind::LLVM_INTR_VP_OR: return "LLVM_INTR_VP_OR";
    case ir::OperationKind::LLVM_INTR_VP_PTRTOINT: return "LLVM_INTR_VP_PTRTOINT";
    case ir::OperationKind::LLVM_INTR_VP_REDUCE_ADD: return "LLVM_INTR_VP_REDUCE_ADD";
    case ir::OperationKind::LLVM_INTR_VP_REDUCE_AND: return "LLVM_INTR_VP_REDUCE_AND";
    case ir::OperationKind::LLVM_INTR_VP_REDUCE_FADD: return "LLVM_INTR_VP_REDUCE_FADD";
    case ir::OperationKind::LLVM_INTR_VP_REDUCE_FMAX: return "LLVM_INTR_VP_REDUCE_FMAX";
    case ir::OperationKind::LLVM_INTR_VP_REDUCE_FMIN: return "LLVM_INTR_VP_REDUCE_FMIN";
    case ir::OperationKind::LLVM_INTR_VP_REDUCE_FMUL: return "LLVM_INTR_VP_REDUCE_FMUL";
    case ir::OperationKind::LLVM_INTR_VP_REDUCE_MUL: return "LLVM_INTR_VP_REDUCE_MUL";
    case ir::OperationKind::LLVM_INTR_VP_REDUCE_OR: return "LLVM_INTR_VP_REDUCE_OR";
    case ir::OperationKind::LLVM_INTR_VP_REDUCE_SMAX: return "LLVM_INTR_VP_REDUCE_SMAX";
    case ir::OperationKind::LLVM_INTR_VP_REDUCE_SMIN: return "LLVM_INTR_VP_REDUCE_SMIN";
    case ir::OperationKind::LLVM_INTR_VP_REDUCE_UMAX: return "LLVM_INTR_VP_REDUCE_UMAX";
    case ir::OperationKind::LLVM_INTR_VP_REDUCE_UMIN: return "LLVM_INTR_VP_REDUCE_UMIN";
    case ir::OperationKind::LLVM_INTR_VP_REDUCE_XOR: return "LLVM_INTR_VP_REDUCE_XOR";
    case ir::OperationKind::LLVM_INTR_VP_SDIV: return "LLVM_INTR_VP_SDIV";
    case ir::OperationKind::LLVM_INTR_VP_SEXT: return "LLVM_INTR_VP_SEXT";
    case ir::OperationKind::LLVM_INTR_VP_SITOFP: return "LLVM_INTR_VP_SITOFP";
    case ir::OperationKind::LLVM_INTR_VP_SREM: return "LLVM_INTR_VP_SREM";
    case ir::OperationKind::LLVM_INTR_VP_SELECT: return "LLVM_INTR_VP_SELECT";
    case ir::OperationKind::LLVM_INTR_VP_SHL: return "LLVM_INTR_VP_SHL";
    case ir::OperationKind::LLVM_INTR_VP_STORE: return "LLVM_INTR_VP_STORE";
    case ir::OperationKind::LLVM_INTR_EXPERIMENTAL_VP_STRIDED_LOAD: return "LLVM_INTR_EXPERIMENTAL_VP_STRIDED_LOAD";
    case ir::OperationKind::LLVM_INTR_EXPERIMENTAL_VP_STRIDED_STORE: return "LLVM_INTR_EXPERIMENTAL_VP_STRIDED_STORE";
    case ir::OperationKind::LLVM_INTR_VP_SUB: return "LLVM_INTR_VP_SUB";
    case ir::OperationKind::LLVM_INTR_VP_TRUNC: return "LLVM_INTR_VP_TRUNC";
    case ir::OperationKind::LLVM_INTR_VP_UDIV: return "LLVM_INTR_VP_UDIV";
    case ir::OperationKind::LLVM_INTR_VP_UITOFP: return "LLVM_INTR_VP_UITOFP";
    case ir::OperationKind::LLVM_INTR_VP_UREM: return "LLVM_INTR_VP_UREM";
    case ir::OperationKind::LLVM_INTR_VP_XOR: return "LLVM_INTR_VP_XOR";
    case ir::OperationKind::LLVM_INTR_VP_ZEXT: return "LLVM_INTR_VP_ZEXT";
    case ir::OperationKind::LLVM_INTR_VACOPY: return "LLVM_INTR_VACOPY";
    case ir::OperationKind::LLVM_INTR_VAEND: return "LLVM_INTR_VAEND";
    case ir::OperationKind::LLVM_INTR_VASTART: return "LLVM_INTR_VASTART";
    case ir::OperationKind::LLVM_INTR_MASKED_COMPRESSSTORE: return "LLVM_INTR_MASKED_COMPRESSSTORE";
    case ir::OperationKind::LLVM_INTR_MASKED_EXPANDLOAD: return "LLVM_INTR_MASKED_EXPANDLOAD";
    case ir::OperationKind::LLVM_INTR_MASKED_GATHER: return "LLVM_INTR_MASKED_GATHER";
    case ir::OperationKind::LLVM_INTR_MASKED_SCATTER: return "LLVM_INTR_MASKED_SCATTER";
    case ir::OperationKind::LLVM_INTR_VECTOR_EXTRACT: return "LLVM_INTR_VECTOR_EXTRACT";
    case ir::OperationKind::LLVM_INTR_VECTOR_INSERT: return "LLVM_INTR_VECTOR_INSERT";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_ADD: return "LLVM_INTR_VECTOR_REDUCE_ADD";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_AND: return "LLVM_INTR_VECTOR_REDUCE_AND";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_FADD: return "LLVM_INTR_VECTOR_REDUCE_FADD";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_FMAX: return "LLVM_INTR_VECTOR_REDUCE_FMAX";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_FMIN: return "LLVM_INTR_VECTOR_REDUCE_FMIN";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_FMUL: return "LLVM_INTR_VECTOR_REDUCE_FMUL";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_MUL: return "LLVM_INTR_VECTOR_REDUCE_MUL";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_OR: return "LLVM_INTR_VECTOR_REDUCE_OR";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_SMAX: return "LLVM_INTR_VECTOR_REDUCE_SMAX";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_SMIN: return "LLVM_INTR_VECTOR_REDUCE_SMIN";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_UMAX: return "LLVM_INTR_VECTOR_REDUCE_UMAX";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_UMIN: return "LLVM_INTR_VECTOR_REDUCE_UMIN";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_XOR: return "LLVM_INTR_VECTOR_REDUCE_XOR";
    case ir::OperationKind::LLVM_INTR_VSCALE: return "LLVM_INTR_VSCALE";
    case ir::OperationKind::SCF_CONDITION: return "SCF_CONDITION";
    case ir::OperationKind::SCF_EXECUTE_REGION: return "SCF_EXECUTE_REGION";
    case ir::OperationKind::SCF_FOR: return "SCF_FOR";
    case ir::OperationKind::SCF_FOREACH_THREAD: return "SCF_FOREACH_THREAD";
    case ir::OperationKind::SCF_IF: return "SCF_IF";
    case ir::OperationKind::SCF_INDEX_SWITCH: return "SCF_INDEX_SWITCH";
    case ir::OperationKind::SCF_PARALLEL: return "SCF_PARALLEL";
    case ir::OperationKind::SCF_FOREACH_THREAD_PERFORM_CONCURRENTLY: return "SCF_FOREACH_THREAD_PERFORM_CONCURRENTLY";
    case ir::OperationKind::SCF_REDUCE: return "SCF_REDUCE";
    case ir::OperationKind::SCF_REDUCE_RETURN: return "SCF_REDUCE_RETURN";
    case ir::OperationKind::SCF_WHILE: return "SCF_WHILE";
    case ir::OperationKind::SCF_YIELD: return "SCF_YIELD";
    case ir::OperationKind::MEMREF_ASSUME_ALIGNMENT: return "MEMREF_ASSUME_ALIGNMENT";
    case ir::OperationKind::MEMREF_ATOMIC_RMW: return "MEMREF_ATOMIC_RMW";
    case ir::OperationKind::MEMREF_ATOMIC_YIELD: return "MEMREF_ATOMIC_YIELD";
    case ir::OperationKind::MEMREF_COPY: return "MEMREF_COPY";
    case ir::OperationKind::MEMREF_GENERIC_ATOMIC_RMW: return "MEMREF_GENERIC_ATOMIC_RMW";
    case ir::OperationKind::MEMREF_LOAD: return "MEMREF_LOAD";
    case ir::OperationKind::MEMREF_ALLOC: return "MEMREF_ALLOC";
    case ir::OperationKind::MEMREF_ALLOCA: return "MEMREF_ALLOCA";
    case ir::OperationKind::MEMREF_ALLOCA_SCOPE: return "MEMREF_ALLOCA_SCOPE";
    case ir::OperationKind::MEMREF_ALLOCA_SCOPE_RETURN: return "MEMREF_ALLOCA_SCOPE_RETURN";
    case ir::OperationKind::MEMREF_CAST: return "MEMREF_CAST";
    case ir::OperationKind::MEMREF_COLLAPSE_SHAPE: return "MEMREF_COLLAPSE_SHAPE";
    case ir::OperationKind::MEMREF_DEALLOC: return "MEMREF_DEALLOC";
    case ir::OperationKind::MEMREF_DIM: return "MEMREF_DIM";
    case ir::OperationKind::MEMREF_DMA_START: return "MEMREF_DMA_START";
    case ir::OperationKind::MEMREF_DMA_WAIT: return "MEMREF_DMA_WAIT";
    case ir::OperationKind::MEMREF_EXPAND_SHAPE: return "MEMREF_EXPAND_SHAPE";
    case ir::OperationKind::MEMREF_EXTRACT_ALIGNED_POINTER_AS_INDEX: return "MEMREF_EXTRACT_ALIGNED_POINTER_AS_INDEX";
    case ir::OperationKind::MEMREF_EXTRACT_STRIDED_METADATA: return "MEMREF_EXTRACT_STRIDED_METADATA";
    case ir::OperationKind::MEMREF_GET_GLOBAL: return "MEMREF_GET_GLOBAL";
    case ir::OperationKind::MEMREF_GLOBAL: return "MEMREF_GLOBAL";
    case ir::OperationKind::MEMREF_PREFETCH: return "MEMREF_PREFETCH";
    case ir::OperationKind::MEMREF_RANK: return "MEMREF_RANK";
    case ir::OperationKind::MEMREF_REALLOC: return "MEMREF_REALLOC";
    case ir::OperationKind::MEMREF_REINTERPRET_CAST: return "MEMREF_REINTERPRET_CAST";
    case ir::OperationKind::MEMREF_RESHAPE: return "MEMREF_RESHAPE";
    case ir::OperationKind::MEMREF_STORE: return "MEMREF_STORE";
    case ir::OperationKind::MEMREF_TRANSPOSE: return "MEMREF_TRANSPOSE";
    case ir::OperationKind::MEMREF_VIEW: return "MEMREF_VIEW";
    case ir::OperationKind::MEMREF_SUBVIEW: return "MEMREF_SUBVIEW";
    case ir::OperationKind::MEMREF_TENSOR_STORE: return "MEMREF_TENSOR_STORE";
    case ir::OperationKind::LL_BR: return "LL_BR";
    case ir::OperationKind::LL_CONCAT: return "LL_CONCAT";
    case ir::OperationKind::LL_COND_BR: return "LL_COND_BR";
    case ir::OperationKind::LL_COND_SCOPE_RET: return "LL_COND_SCOPE_RET";
    case ir::OperationKind::LL_EXTRACT: return "LL_EXTRACT";
    case ir::OperationKind::LL_INITIALIZE: return "LL_INITIALIZE";
    case ir::OperationKind::LL_INLINE_SCOPE: return "LL_INLINE_SCOPE";
    case ir::OperationKind::LL_FUNC: return "LL_FUNC";
    case ir::OperationKind::LL_GEP: return "LL_GEP";
    case ir::OperationKind::LL_RETURN: return "LL_RETURN";
    case ir::OperationKind::LL_SCOPE: return "LL_SCOPE";
    case ir::OperationKind::LL_SCOPE_RECURSE: return "LL_SCOPE_RECURSE";
    case ir::OperationKind::LL_SCOPE_RET: return "LL_SCOPE_RET";
    case ir::OperationKind::LL_UNINITIALIZED_VAR: return "LL_UNINITIALIZED_VAR";
    case ir::OperationKind::HL_ACCESS: return "HL_ACCESS";
    case ir::OperationKind::HL_ASSIGN_FADD: return "HL_ASSIGN_FADD";
    case ir::OperationKind::HL_FADD: return "HL_FADD";
    case ir::OperationKind::HL_ASSIGN_ADD: return "HL_ASSIGN_ADD";
    case ir::OperationKind::HL_ADD: return "HL_ADD";
    case ir::OperationKind::HL_LABELADDR: return "HL_LABELADDR";
    case ir::OperationKind::HL_ADDRESSOF: return "HL_ADDRESSOF";
    case ir::OperationKind::HL_ALIGNOF_EXPR: return "HL_ALIGNOF_EXPR";
    case ir::OperationKind::HL_ALIGNOF_TYPE: return "HL_ALIGNOF_TYPE";
    case ir::OperationKind::HL_ASSIGN: return "HL_ASSIGN";
    case ir::OperationKind::HL_ASSIGN_BIN_AND: return "HL_ASSIGN_BIN_AND";
    case ir::OperationKind::HL_BIN_AND: return "HL_BIN_AND";
    case ir::OperationKind::HL_BIN_COMMA: return "HL_BIN_COMMA";
    case ir::OperationKind::HL_BIN_LAND: return "HL_BIN_LAND";
    case ir::OperationKind::HL_BIN_LOR: return "HL_BIN_LOR";
    case ir::OperationKind::HL_ASSIGN_BIN_OR: return "HL_ASSIGN_BIN_OR";
    case ir::OperationKind::HL_BIN_OR: return "HL_BIN_OR";
    case ir::OperationKind::HL_ASSIGN_BIN_SHL: return "HL_ASSIGN_BIN_SHL";
    case ir::OperationKind::HL_BIN_SHL: return "HL_BIN_SHL";
    case ir::OperationKind::HL_ASSIGN_BIN_SHR: return "HL_ASSIGN_BIN_SHR";
    case ir::OperationKind::HL_BIN_SHR: return "HL_BIN_SHR";
    case ir::OperationKind::HL_ASSIGN_BIN_XOR: return "HL_ASSIGN_BIN_XOR";
    case ir::OperationKind::HL_BIN_XOR: return "HL_BIN_XOR";
    case ir::OperationKind::HL_BUILTIN_BITCAST: return "HL_BUILTIN_BITCAST";
    case ir::OperationKind::HL_CSTYLE_CAST: return "HL_CSTYLE_CAST";
    case ir::OperationKind::HL_CALL: return "HL_CALL";
    case ir::OperationKind::HL_CLASS: return "HL_CLASS";
    case ir::OperationKind::HL_CMP: return "HL_CMP";
    case ir::OperationKind::HL_CONST: return "HL_CONST";
    case ir::OperationKind::HL_BASE: return "HL_BASE";
    case ir::OperationKind::HL_CXXSTRUCT: return "HL_CXXSTRUCT";
    case ir::OperationKind::HL_REF: return "HL_REF";
    case ir::OperationKind::HL_DEREF: return "HL_DEREF";
    case ir::OperationKind::HL_ASSIGN_FDIV: return "HL_ASSIGN_FDIV";
    case ir::OperationKind::HL_FDIV: return "HL_FDIV";
    case ir::OperationKind::HL_ASSIGN_SDIV: return "HL_ASSIGN_SDIV";
    case ir::OperationKind::HL_SDIV: return "HL_SDIV";
    case ir::OperationKind::HL_ASSIGN_UDIV: return "HL_ASSIGN_UDIV";
    case ir::OperationKind::HL_UDIV: return "HL_UDIV";
    case ir::OperationKind::HL_ENUM_CONST: return "HL_ENUM_CONST";
    case ir::OperationKind::HL_ENUM: return "HL_ENUM";
    case ir::OperationKind::HL_ENUMREF: return "HL_ENUMREF";
    case ir::OperationKind::HL_EXPR: return "HL_EXPR";
    case ir::OperationKind::HL_GNU_EXTENSION: return "HL_GNU_EXTENSION";
    case ir::OperationKind::HL_FCMP: return "HL_FCMP";
    case ir::OperationKind::HL_FIELD: return "HL_FIELD";
    case ir::OperationKind::HL_FUNCREF: return "HL_FUNCREF";
    case ir::OperationKind::HL_GLOBREF: return "HL_GLOBREF";
    case ir::OperationKind::HL_BREAK: return "HL_BREAK";
    case ir::OperationKind::HL_CASE: return "HL_CASE";
    case ir::OperationKind::HL_COND: return "HL_COND";
    case ir::OperationKind::HL_COND_YIELD: return "HL_COND_YIELD";
    case ir::OperationKind::HL_CONTINUE: return "HL_CONTINUE";
    case ir::OperationKind::HL_DEFAULT: return "HL_DEFAULT";
    case ir::OperationKind::HL_DO: return "HL_DO";
    case ir::OperationKind::HL_EMPTY_DECL: return "HL_EMPTY_DECL";
    case ir::OperationKind::HL_FOR: return "HL_FOR";
    case ir::OperationKind::HL_FUNC: return "HL_FUNC";
    case ir::OperationKind::HL_GOTO: return "HL_GOTO";
    case ir::OperationKind::HL_IF: return "HL_IF";
    case ir::OperationKind::HL_LABEL_DECL: return "HL_LABEL_DECL";
    case ir::OperationKind::HL_LABEL: return "HL_LABEL";
    case ir::OperationKind::HL_SKIP: return "HL_SKIP";
    case ir::OperationKind::HL_SWITCH: return "HL_SWITCH";
    case ir::OperationKind::HL_TYPE_YIELD: return "HL_TYPE_YIELD";
    case ir::OperationKind::HL_VALUE_YIELD: return "HL_VALUE_YIELD";
    case ir::OperationKind::HL_VAR: return "HL_VAR";
    case ir::OperationKind::HL_WHILE: return "HL_WHILE";
    case ir::OperationKind::HL_IMPLICIT_CAST: return "HL_IMPLICIT_CAST";
    case ir::OperationKind::HL_INDIRECT_CALL: return "HL_INDIRECT_CALL";
    case ir::OperationKind::HL_INITLIST: return "HL_INITLIST";
    case ir::OperationKind::HL_LNOT: return "HL_LNOT";
    case ir::OperationKind::HL_MINUS: return "HL_MINUS";
    case ir::OperationKind::HL_ASSIGN_FMUL: return "HL_ASSIGN_FMUL";
    case ir::OperationKind::HL_FMUL: return "HL_FMUL";
    case ir::OperationKind::HL_ASSIGN_MUL: return "HL_ASSIGN_MUL";
    case ir::OperationKind::HL_MUL: return "HL_MUL";
    case ir::OperationKind::HL_NOT: return "HL_NOT";
    case ir::OperationKind::HL_PLUS: return "HL_PLUS";
    case ir::OperationKind::HL_POST_DEC: return "HL_POST_DEC";
    case ir::OperationKind::HL_POST_INC: return "HL_POST_INC";
    case ir::OperationKind::HL_PRE_DEC: return "HL_PRE_DEC";
    case ir::OperationKind::HL_PRE_INC: return "HL_PRE_INC";
    case ir::OperationKind::HL_PREDEFINED_EXPR: return "HL_PREDEFINED_EXPR";
    case ir::OperationKind::HL_MEMBER: return "HL_MEMBER";
    case ir::OperationKind::HL_ASSIGN_FREM: return "HL_ASSIGN_FREM";
    case ir::OperationKind::HL_FREM: return "HL_FREM";
    case ir::OperationKind::HL_ASSIGN_SREM: return "HL_ASSIGN_SREM";
    case ir::OperationKind::HL_SREM: return "HL_SREM";
    case ir::OperationKind::HL_ASSIGN_UREM: return "HL_ASSIGN_UREM";
    case ir::OperationKind::HL_UREM: return "HL_UREM";
    case ir::OperationKind::HL_RETURN: return "HL_RETURN";
    case ir::OperationKind::HL_SIZEOF_EXPR: return "HL_SIZEOF_EXPR";
    case ir::OperationKind::HL_SIZEOF_TYPE: return "HL_SIZEOF_TYPE";
    case ir::OperationKind::HL_STMT_EXPR: return "HL_STMT_EXPR";
    case ir::OperationKind::HL_STRUCT: return "HL_STRUCT";
    case ir::OperationKind::HL_ASSIGN_FSUB: return "HL_ASSIGN_FSUB";
    case ir::OperationKind::HL_FSUB: return "HL_FSUB";
    case ir::OperationKind::HL_ASSIGN_SUB: return "HL_ASSIGN_SUB";
    case ir::OperationKind::HL_SUB: return "HL_SUB";
    case ir::OperationKind::HL_SUBSCRIPT: return "HL_SUBSCRIPT";
    case ir::OperationKind::HL_THIS: return "HL_THIS";
    case ir::OperationKind::HL_TRANSLATION_UNIT: return "HL_TRANSLATION_UNIT";
    case ir::OperationKind::HL_TYPE: return "HL_TYPE";
    case ir::OperationKind::HL_TYPEDEF: return "HL_TYPEDEF";
    case ir::OperationKind::HL_TYPEOF_EXPR: return "HL_TYPEOF_EXPR";
    case ir::OperationKind::HL_TYPEOF_TYPE: return "HL_TYPEOF_TYPE";
    case ir::OperationKind::HL_UNION: return "HL_UNION";
    case ir::OperationKind::HL_UNREACHABLE: return "HL_UNREACHABLE";
    case ir::OperationKind::CORE_BIN_LAND: return "CORE_BIN_LAND";
    case ir::OperationKind::CORE_BIN_LOR: return "CORE_BIN_LOR";
    case ir::OperationKind::CORE_LAZY_OP: return "CORE_LAZY_OP";
    case ir::OperationKind::CORE_SELECT: return "CORE_SELECT";
    case ir::OperationKind::CORE_SCOPE: return "CORE_SCOPE";
    case ir::OperationKind::UNSUP_DECL: return "UNSUP_DECL";
    case ir::OperationKind::UNSUP_STMT: return "UNSUP_STMT";
  }
}

}  // namespace mx
