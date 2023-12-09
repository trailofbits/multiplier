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
    case ir::OperationKind::LLVM_ADD: return "LLVM_ADD";
    case ir::OperationKind::LLVM_ADDRSPACECAST: return "LLVM_ADDRSPACECAST";
    case ir::OperationKind::LLVM_MLIR_ADDRESSOF: return "LLVM_MLIR_ADDRESSOF";
    case ir::OperationKind::LLVM_ALLOCA: return "LLVM_ALLOCA";
    case ir::OperationKind::LLVM_AND: return "LLVM_AND";
    case ir::OperationKind::LLVM_CMPXCHG: return "LLVM_CMPXCHG";
    case ir::OperationKind::LLVM_ATOMICRMW: return "LLVM_ATOMICRMW";
    case ir::OperationKind::LLVM_BITCAST: return "LLVM_BITCAST";
    case ir::OperationKind::LLVM_BR: return "LLVM_BR";
    case ir::OperationKind::LLVM_CALL: return "LLVM_CALL";
    case ir::OperationKind::LLVM_COMDAT: return "LLVM_COMDAT";
    case ir::OperationKind::LLVM_COMDAT_SELECTOR: return "LLVM_COMDAT_SELECTOR";
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
    case ir::OperationKind::LLVM_MLIR_POISON: return "LLVM_MLIR_POISON";
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
    case ir::OperationKind::LLVM_TRUNC: return "LLVM_TRUNC";
    case ir::OperationKind::LLVM_UDIV: return "LLVM_UDIV";
    case ir::OperationKind::LLVM_UITOFP: return "LLVM_UITOFP";
    case ir::OperationKind::LLVM_UREM: return "LLVM_UREM";
    case ir::OperationKind::LLVM_MLIR_UNDEF: return "LLVM_MLIR_UNDEF";
    case ir::OperationKind::LLVM_UNREACHABLE: return "LLVM_UNREACHABLE";
    case ir::OperationKind::LLVM_XOR: return "LLVM_XOR";
    case ir::OperationKind::LLVM_ZEXT: return "LLVM_ZEXT";
    case ir::OperationKind::LLVM_INTR_ABS: return "LLVM_INTR_ABS";
    case ir::OperationKind::LLVM_INTR_ANNOTATION: return "LLVM_INTR_ANNOTATION";
    case ir::OperationKind::LLVM_INTR_ASSUME: return "LLVM_INTR_ASSUME";
    case ir::OperationKind::LLVM_INTR_BITREVERSE: return "LLVM_INTR_BITREVERSE";
    case ir::OperationKind::LLVM_INTR_BSWAP: return "LLVM_INTR_BSWAP";
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
    case ir::OperationKind::LLVM_INTR_DBG_DECLARE: return "LLVM_INTR_DBG_DECLARE";
    case ir::OperationKind::LLVM_INTR_DBG_LABEL: return "LLVM_INTR_DBG_LABEL";
    case ir::OperationKind::LLVM_INTR_DBG_VALUE: return "LLVM_INTR_DBG_VALUE";
    case ir::OperationKind::LLVM_INTR_DEBUGTRAP: return "LLVM_INTR_DEBUGTRAP";
    case ir::OperationKind::LLVM_INTR_EH_TYPEID_FOR: return "LLVM_INTR_EH_TYPEID_FOR";
    case ir::OperationKind::LLVM_INTR_EXP2: return "LLVM_INTR_EXP2";
    case ir::OperationKind::LLVM_INTR_EXP: return "LLVM_INTR_EXP";
    case ir::OperationKind::LLVM_INTR_EXPECT: return "LLVM_INTR_EXPECT";
    case ir::OperationKind::LLVM_INTR_EXPECT_WITH_PROBABILITY: return "LLVM_INTR_EXPECT_WITH_PROBABILITY";
    case ir::OperationKind::LLVM_INTR_FABS: return "LLVM_INTR_FABS";
    case ir::OperationKind::LLVM_INTR_CEIL: return "LLVM_INTR_CEIL";
    case ir::OperationKind::LLVM_INTR_FLOOR: return "LLVM_INTR_FLOOR";
    case ir::OperationKind::LLVM_INTR_FMA: return "LLVM_INTR_FMA";
    case ir::OperationKind::LLVM_INTR_FMULADD: return "LLVM_INTR_FMULADD";
    case ir::OperationKind::LLVM_INTR_TRUNC: return "LLVM_INTR_TRUNC";
    case ir::OperationKind::LLVM_INTR_FSHL: return "LLVM_INTR_FSHL";
    case ir::OperationKind::LLVM_INTR_FSHR: return "LLVM_INTR_FSHR";
    case ir::OperationKind::LLVM_INTR_GET_ACTIVE_LANE_MASK: return "LLVM_INTR_GET_ACTIVE_LANE_MASK";
    case ir::OperationKind::LLVM_INTR_IS_CONSTANT: return "LLVM_INTR_IS_CONSTANT";
    case ir::OperationKind::LLVM_INTR_IS_FPCLASS: return "LLVM_INTR_IS_FPCLASS";
    case ir::OperationKind::LLVM_INTR_LIFETIME_END: return "LLVM_INTR_LIFETIME_END";
    case ir::OperationKind::LLVM_INTR_LIFETIME_START: return "LLVM_INTR_LIFETIME_START";
    case ir::OperationKind::LLVM_INTR_LLRINT: return "LLVM_INTR_LLRINT";
    case ir::OperationKind::LLVM_INTR_LLROUND: return "LLVM_INTR_LLROUND";
    case ir::OperationKind::LLVM_INTR_LOG10: return "LLVM_INTR_LOG10";
    case ir::OperationKind::LLVM_INTR_LOG2: return "LLVM_INTR_LOG2";
    case ir::OperationKind::LLVM_INTR_LOG: return "LLVM_INTR_LOG";
    case ir::OperationKind::LLVM_INTR_LRINT: return "LLVM_INTR_LRINT";
    case ir::OperationKind::LLVM_INTR_LROUND: return "LLVM_INTR_LROUND";
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
    case ir::OperationKind::LLVM_INTR_NEARBYINT: return "LLVM_INTR_NEARBYINT";
    case ir::OperationKind::LLVM_INTR_EXPERIMENTAL_NOALIAS_SCOPE_DECL: return "LLVM_INTR_EXPERIMENTAL_NOALIAS_SCOPE_DECL";
    case ir::OperationKind::LLVM_INTR_POWI: return "LLVM_INTR_POWI";
    case ir::OperationKind::LLVM_INTR_POW: return "LLVM_INTR_POW";
    case ir::OperationKind::LLVM_INTR_PREFETCH: return "LLVM_INTR_PREFETCH";
    case ir::OperationKind::LLVM_INTR_PTR_ANNOTATION: return "LLVM_INTR_PTR_ANNOTATION";
    case ir::OperationKind::LLVM_INTR_RINT: return "LLVM_INTR_RINT";
    case ir::OperationKind::LLVM_INTR_ROUNDEVEN: return "LLVM_INTR_ROUNDEVEN";
    case ir::OperationKind::LLVM_INTR_ROUND: return "LLVM_INTR_ROUND";
    case ir::OperationKind::LLVM_INTR_SADD_SAT: return "LLVM_INTR_SADD_SAT";
    case ir::OperationKind::LLVM_INTR_SADD_WITH_OVERFLOW: return "LLVM_INTR_SADD_WITH_OVERFLOW";
    case ir::OperationKind::LLVM_INTR_SMAX: return "LLVM_INTR_SMAX";
    case ir::OperationKind::LLVM_INTR_SMIN: return "LLVM_INTR_SMIN";
    case ir::OperationKind::LLVM_INTR_SMUL_WITH_OVERFLOW: return "LLVM_INTR_SMUL_WITH_OVERFLOW";
    case ir::OperationKind::LLVM_INTR_SSA_COPY: return "LLVM_INTR_SSA_COPY";
    case ir::OperationKind::LLVM_INTR_SSHL_SAT: return "LLVM_INTR_SSHL_SAT";
    case ir::OperationKind::LLVM_INTR_SSUB_SAT: return "LLVM_INTR_SSUB_SAT";
    case ir::OperationKind::LLVM_INTR_SSUB_WITH_OVERFLOW: return "LLVM_INTR_SSUB_WITH_OVERFLOW";
    case ir::OperationKind::LLVM_INTR_SIN: return "LLVM_INTR_SIN";
    case ir::OperationKind::LLVM_INTR_SQRT: return "LLVM_INTR_SQRT";
    case ir::OperationKind::LLVM_INTR_STACKRESTORE: return "LLVM_INTR_STACKRESTORE";
    case ir::OperationKind::LLVM_INTR_STACKSAVE: return "LLVM_INTR_STACKSAVE";
    case ir::OperationKind::LLVM_INTR_EXPERIMENTAL_STEPVECTOR: return "LLVM_INTR_EXPERIMENTAL_STEPVECTOR";
    case ir::OperationKind::LLVM_INTR_THREADLOCAL_ADDRESS: return "LLVM_INTR_THREADLOCAL_ADDRESS";
    case ir::OperationKind::LLVM_INTR_TRAP: return "LLVM_INTR_TRAP";
    case ir::OperationKind::LLVM_INTR_UADD_SAT: return "LLVM_INTR_UADD_SAT";
    case ir::OperationKind::LLVM_INTR_UADD_WITH_OVERFLOW: return "LLVM_INTR_UADD_WITH_OVERFLOW";
    case ir::OperationKind::LLVM_INTR_UBSANTRAP: return "LLVM_INTR_UBSANTRAP";
    case ir::OperationKind::LLVM_INTR_UMAX: return "LLVM_INTR_UMAX";
    case ir::OperationKind::LLVM_INTR_UMIN: return "LLVM_INTR_UMIN";
    case ir::OperationKind::LLVM_INTR_UMUL_WITH_OVERFLOW: return "LLVM_INTR_UMUL_WITH_OVERFLOW";
    case ir::OperationKind::LLVM_INTR_USHL_SAT: return "LLVM_INTR_USHL_SAT";
    case ir::OperationKind::LLVM_INTR_USUB_SAT: return "LLVM_INTR_USUB_SAT";
    case ir::OperationKind::LLVM_INTR_USUB_WITH_OVERFLOW: return "LLVM_INTR_USUB_WITH_OVERFLOW";
    case ir::OperationKind::LLVM_INTR_VP_ASHR: return "LLVM_INTR_VP_ASHR";
    case ir::OperationKind::LLVM_INTR_VP_ADD: return "LLVM_INTR_VP_ADD";
    case ir::OperationKind::LLVM_INTR_VP_AND: return "LLVM_INTR_VP_AND";
    case ir::OperationKind::LLVM_INTR_VP_FADD: return "LLVM_INTR_VP_FADD";
    case ir::OperationKind::LLVM_INTR_VP_FDIV: return "LLVM_INTR_VP_FDIV";
    case ir::OperationKind::LLVM_INTR_VP_FMULADD: return "LLVM_INTR_VP_FMULADD";
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
    case ir::OperationKind::LLVM_INTR_VAR_ANNOTATION: return "LLVM_INTR_VAR_ANNOTATION";
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
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_FMAXIMUM: return "LLVM_INTR_VECTOR_REDUCE_FMAXIMUM";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_FMIN: return "LLVM_INTR_VECTOR_REDUCE_FMIN";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_FMINIMUM: return "LLVM_INTR_VECTOR_REDUCE_FMINIMUM";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_FMUL: return "LLVM_INTR_VECTOR_REDUCE_FMUL";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_MUL: return "LLVM_INTR_VECTOR_REDUCE_MUL";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_OR: return "LLVM_INTR_VECTOR_REDUCE_OR";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_SMAX: return "LLVM_INTR_VECTOR_REDUCE_SMAX";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_SMIN: return "LLVM_INTR_VECTOR_REDUCE_SMIN";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_UMAX: return "LLVM_INTR_VECTOR_REDUCE_UMAX";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_UMIN: return "LLVM_INTR_VECTOR_REDUCE_UMIN";
    case ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_XOR: return "LLVM_INTR_VECTOR_REDUCE_XOR";
    case ir::OperationKind::LLVM_INTR_VSCALE: return "LLVM_INTR_VSCALE";
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
    case ir::OperationKind::MEMREF_MEMORY_SPACE_CAST: return "MEMREF_MEMORY_SPACE_CAST";
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
    case ir::OperationKind::ABI_CALL_ARGS: return "ABI_CALL_ARGS";
    case ir::OperationKind::ABI_CALL_EXEC: return "ABI_CALL_EXEC";
    case ir::OperationKind::ABI_CALL: return "ABI_CALL";
    case ir::OperationKind::ABI_CALL_RETS: return "ABI_CALL_RETS";
    case ir::OperationKind::ABI_DIRECT: return "ABI_DIRECT";
    case ir::OperationKind::ABI_EPILOGUE: return "ABI_EPILOGUE";
    case ir::OperationKind::ABI_FUNC: return "ABI_FUNC";
    case ir::OperationKind::ABI_PROLOGUE: return "ABI_PROLOGUE";
    case ir::OperationKind::ABI_RET_DIRECT: return "ABI_RET_DIRECT";
    case ir::OperationKind::ABI_TODO: return "ABI_TODO";
    case ir::OperationKind::ABI_WRAP_FN: return "ABI_WRAP_FN";
    case ir::OperationKind::ABI_YIELD: return "ABI_YIELD";
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
    case ir::OperationKind::HL_ASM: return "HL_ASM";
    case ir::OperationKind::HL_ASSIGN: return "HL_ASSIGN";
    case ir::OperationKind::HL_ASSIGN_BIN_ASHR: return "HL_ASSIGN_BIN_ASHR";
    case ir::OperationKind::HL_BIN_ASHR: return "HL_BIN_ASHR";
    case ir::OperationKind::HL_ASSIGN_BIN_AND: return "HL_ASSIGN_BIN_AND";
    case ir::OperationKind::HL_BIN_AND: return "HL_BIN_AND";
    case ir::OperationKind::HL_BIN_COMMA: return "HL_BIN_COMMA";
    case ir::OperationKind::HL_BIN_LAND: return "HL_BIN_LAND";
    case ir::OperationKind::HL_BIN_LOR: return "HL_BIN_LOR";
    case ir::OperationKind::HL_ASSIGN_BIN_LSHR: return "HL_ASSIGN_BIN_LSHR";
    case ir::OperationKind::HL_BIN_LSHR: return "HL_BIN_LSHR";
    case ir::OperationKind::HL_ASSIGN_BIN_OR: return "HL_ASSIGN_BIN_OR";
    case ir::OperationKind::HL_BIN_OR: return "HL_BIN_OR";
    case ir::OperationKind::HL_ASSIGN_BIN_SHL: return "HL_ASSIGN_BIN_SHL";
    case ir::OperationKind::HL_BIN_SHL: return "HL_BIN_SHL";
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
    case ir::OperationKind::CORE_IMPLICIT_RETURN: return "CORE_IMPLICIT_RETURN";
    case ir::OperationKind::CORE_LAZY_OP: return "CORE_LAZY_OP";
    case ir::OperationKind::CORE_SCOPE: return "CORE_SCOPE";
    case ir::OperationKind::CORE_SELECT: return "CORE_SELECT";
    case ir::OperationKind::UNSUP_DECL: return "UNSUP_DECL";
    case ir::OperationKind::UNSUP_STMT: return "UNSUP_STMT";
  }
}

bool IsBuiltinOperationKind(ir::OperationKind kind) {
  switch (kind) {
    default:
      return false;
    case mx::ir::OperationKind::BUILTIN_MODULE:
    case mx::ir::OperationKind::BUILTIN_UNREALIZED_CONVERSION_CAST:
      return true;
  }
}

bool IsLLVMIROperationKind(ir::OperationKind kind) {
  switch (kind) {
    default:
      return false;
    case mx::ir::OperationKind::LLVM_ASHR:
    case mx::ir::OperationKind::LLVM_ADD:
    case mx::ir::OperationKind::LLVM_ADDRSPACECAST:
    case mx::ir::OperationKind::LLVM_MLIR_ADDRESSOF:
    case mx::ir::OperationKind::LLVM_ALLOCA:
    case mx::ir::OperationKind::LLVM_AND:
    case mx::ir::OperationKind::LLVM_CMPXCHG:
    case mx::ir::OperationKind::LLVM_ATOMICRMW:
    case mx::ir::OperationKind::LLVM_BITCAST:
    case mx::ir::OperationKind::LLVM_BR:
    case mx::ir::OperationKind::LLVM_CALL:
    case mx::ir::OperationKind::LLVM_COMDAT:
    case mx::ir::OperationKind::LLVM_COMDAT_SELECTOR:
    case mx::ir::OperationKind::LLVM_COND_BR:
    case mx::ir::OperationKind::LLVM_MLIR_CONSTANT:
    case mx::ir::OperationKind::LLVM_EXTRACTELEMENT:
    case mx::ir::OperationKind::LLVM_EXTRACTVALUE:
    case mx::ir::OperationKind::LLVM_FADD:
    case mx::ir::OperationKind::LLVM_FCMP:
    case mx::ir::OperationKind::LLVM_FDIV:
    case mx::ir::OperationKind::LLVM_FMUL:
    case mx::ir::OperationKind::LLVM_FNEG:
    case mx::ir::OperationKind::LLVM_FPEXT:
    case mx::ir::OperationKind::LLVM_FPTOSI:
    case mx::ir::OperationKind::LLVM_FPTOUI:
    case mx::ir::OperationKind::LLVM_FPTRUNC:
    case mx::ir::OperationKind::LLVM_FREM:
    case mx::ir::OperationKind::LLVM_FSUB:
    case mx::ir::OperationKind::LLVM_FENCE:
    case mx::ir::OperationKind::LLVM_FREEZE:
    case mx::ir::OperationKind::LLVM_GETELEMENTPTR:
    case mx::ir::OperationKind::LLVM_MLIR_GLOBAL_CTORS:
    case mx::ir::OperationKind::LLVM_MLIR_GLOBAL_DTORS:
    case mx::ir::OperationKind::LLVM_MLIR_GLOBAL:
    case mx::ir::OperationKind::LLVM_ICMP:
    case mx::ir::OperationKind::LLVM_INLINE_ASM:
    case mx::ir::OperationKind::LLVM_INSERTELEMENT:
    case mx::ir::OperationKind::LLVM_INSERTVALUE:
    case mx::ir::OperationKind::LLVM_INTTOPTR:
    case mx::ir::OperationKind::LLVM_INVOKE:
    case mx::ir::OperationKind::LLVM_FUNC:
    case mx::ir::OperationKind::LLVM_LSHR:
    case mx::ir::OperationKind::LLVM_LANDINGPAD:
    case mx::ir::OperationKind::LLVM_LOAD:
    case mx::ir::OperationKind::LLVM_METADATA:
    case mx::ir::OperationKind::LLVM_MUL:
    case mx::ir::OperationKind::LLVM_MLIR_NULL:
    case mx::ir::OperationKind::LLVM_OR:
    case mx::ir::OperationKind::LLVM_MLIR_POISON:
    case mx::ir::OperationKind::LLVM_PTRTOINT:
    case mx::ir::OperationKind::LLVM_RESUME:
    case mx::ir::OperationKind::LLVM_RETURN:
    case mx::ir::OperationKind::LLVM_SDIV:
    case mx::ir::OperationKind::LLVM_SEXT:
    case mx::ir::OperationKind::LLVM_SITOFP:
    case mx::ir::OperationKind::LLVM_SREM:
    case mx::ir::OperationKind::LLVM_SELECT:
    case mx::ir::OperationKind::LLVM_SHL:
    case mx::ir::OperationKind::LLVM_SHUFFLEVECTOR:
    case mx::ir::OperationKind::LLVM_STORE:
    case mx::ir::OperationKind::LLVM_SUB:
    case mx::ir::OperationKind::LLVM_SWITCH:
    case mx::ir::OperationKind::LLVM_TRUNC:
    case mx::ir::OperationKind::LLVM_UDIV:
    case mx::ir::OperationKind::LLVM_UITOFP:
    case mx::ir::OperationKind::LLVM_UREM:
    case mx::ir::OperationKind::LLVM_MLIR_UNDEF:
    case mx::ir::OperationKind::LLVM_UNREACHABLE:
    case mx::ir::OperationKind::LLVM_XOR:
    case mx::ir::OperationKind::LLVM_ZEXT:
    case mx::ir::OperationKind::LLVM_INTR_ABS:
    case mx::ir::OperationKind::LLVM_INTR_ANNOTATION:
    case mx::ir::OperationKind::LLVM_INTR_ASSUME:
    case mx::ir::OperationKind::LLVM_INTR_BITREVERSE:
    case mx::ir::OperationKind::LLVM_INTR_BSWAP:
    case mx::ir::OperationKind::LLVM_CALL_INTRINSIC:
    case mx::ir::OperationKind::LLVM_INTR_COPYSIGN:
    case mx::ir::OperationKind::LLVM_INTR_CORO_ALIGN:
    case mx::ir::OperationKind::LLVM_INTR_CORO_BEGIN:
    case mx::ir::OperationKind::LLVM_INTR_CORO_END:
    case mx::ir::OperationKind::LLVM_INTR_CORO_FREE:
    case mx::ir::OperationKind::LLVM_INTR_CORO_ID:
    case mx::ir::OperationKind::LLVM_INTR_CORO_RESUME:
    case mx::ir::OperationKind::LLVM_INTR_CORO_SAVE:
    case mx::ir::OperationKind::LLVM_INTR_CORO_SIZE:
    case mx::ir::OperationKind::LLVM_INTR_CORO_SUSPEND:
    case mx::ir::OperationKind::LLVM_INTR_COS:
    case mx::ir::OperationKind::LLVM_INTR_CTLZ:
    case mx::ir::OperationKind::LLVM_INTR_CTTZ:
    case mx::ir::OperationKind::LLVM_INTR_CTPOP:
    case mx::ir::OperationKind::LLVM_INTR_DBG_DECLARE:
    case mx::ir::OperationKind::LLVM_INTR_DBG_LABEL:
    case mx::ir::OperationKind::LLVM_INTR_DBG_VALUE:
    case mx::ir::OperationKind::LLVM_INTR_DEBUGTRAP:
    case mx::ir::OperationKind::LLVM_INTR_EH_TYPEID_FOR:
    case mx::ir::OperationKind::LLVM_INTR_EXP2:
    case mx::ir::OperationKind::LLVM_INTR_EXP:
    case mx::ir::OperationKind::LLVM_INTR_EXPECT:
    case mx::ir::OperationKind::LLVM_INTR_EXPECT_WITH_PROBABILITY:
    case mx::ir::OperationKind::LLVM_INTR_FABS:
    case mx::ir::OperationKind::LLVM_INTR_CEIL:
    case mx::ir::OperationKind::LLVM_INTR_FLOOR:
    case mx::ir::OperationKind::LLVM_INTR_FMA:
    case mx::ir::OperationKind::LLVM_INTR_FMULADD:
    case mx::ir::OperationKind::LLVM_INTR_TRUNC:
    case mx::ir::OperationKind::LLVM_INTR_FSHL:
    case mx::ir::OperationKind::LLVM_INTR_FSHR:
    case mx::ir::OperationKind::LLVM_INTR_GET_ACTIVE_LANE_MASK:
    case mx::ir::OperationKind::LLVM_INTR_IS_CONSTANT:
    case mx::ir::OperationKind::LLVM_INTR_IS_FPCLASS:
    case mx::ir::OperationKind::LLVM_INTR_LIFETIME_END:
    case mx::ir::OperationKind::LLVM_INTR_LIFETIME_START:
    case mx::ir::OperationKind::LLVM_INTR_LLRINT:
    case mx::ir::OperationKind::LLVM_INTR_LLROUND:
    case mx::ir::OperationKind::LLVM_INTR_LOG10:
    case mx::ir::OperationKind::LLVM_INTR_LOG2:
    case mx::ir::OperationKind::LLVM_INTR_LOG:
    case mx::ir::OperationKind::LLVM_INTR_LRINT:
    case mx::ir::OperationKind::LLVM_INTR_LROUND:
    case mx::ir::OperationKind::LLVM_INTR_MASKED_LOAD:
    case mx::ir::OperationKind::LLVM_INTR_MASKED_STORE:
    case mx::ir::OperationKind::LLVM_INTR_MATRIX_COLUMN_MAJOR_LOAD:
    case mx::ir::OperationKind::LLVM_INTR_MATRIX_COLUMN_MAJOR_STORE:
    case mx::ir::OperationKind::LLVM_INTR_MATRIX_MULTIPLY:
    case mx::ir::OperationKind::LLVM_INTR_MATRIX_TRANSPOSE:
    case mx::ir::OperationKind::LLVM_INTR_MAXNUM:
    case mx::ir::OperationKind::LLVM_INTR_MAXIMUM:
    case mx::ir::OperationKind::LLVM_INTR_MEMCPY_INLINE:
    case mx::ir::OperationKind::LLVM_INTR_MEMCPY:
    case mx::ir::OperationKind::LLVM_INTR_MEMMOVE:
    case mx::ir::OperationKind::LLVM_INTR_MEMSET:
    case mx::ir::OperationKind::LLVM_INTR_MINNUM:
    case mx::ir::OperationKind::LLVM_INTR_MINIMUM:
    case mx::ir::OperationKind::LLVM_INTR_NEARBYINT:
    case mx::ir::OperationKind::LLVM_INTR_EXPERIMENTAL_NOALIAS_SCOPE_DECL:
    case mx::ir::OperationKind::LLVM_INTR_POWI:
    case mx::ir::OperationKind::LLVM_INTR_POW:
    case mx::ir::OperationKind::LLVM_INTR_PREFETCH:
    case mx::ir::OperationKind::LLVM_INTR_PTR_ANNOTATION:
    case mx::ir::OperationKind::LLVM_INTR_RINT:
    case mx::ir::OperationKind::LLVM_INTR_ROUNDEVEN:
    case mx::ir::OperationKind::LLVM_INTR_ROUND:
    case mx::ir::OperationKind::LLVM_INTR_SADD_SAT:
    case mx::ir::OperationKind::LLVM_INTR_SADD_WITH_OVERFLOW:
    case mx::ir::OperationKind::LLVM_INTR_SMAX:
    case mx::ir::OperationKind::LLVM_INTR_SMIN:
    case mx::ir::OperationKind::LLVM_INTR_SMUL_WITH_OVERFLOW:
    case mx::ir::OperationKind::LLVM_INTR_SSA_COPY:
    case mx::ir::OperationKind::LLVM_INTR_SSHL_SAT:
    case mx::ir::OperationKind::LLVM_INTR_SSUB_SAT:
    case mx::ir::OperationKind::LLVM_INTR_SSUB_WITH_OVERFLOW:
    case mx::ir::OperationKind::LLVM_INTR_SIN:
    case mx::ir::OperationKind::LLVM_INTR_SQRT:
    case mx::ir::OperationKind::LLVM_INTR_STACKRESTORE:
    case mx::ir::OperationKind::LLVM_INTR_STACKSAVE:
    case mx::ir::OperationKind::LLVM_INTR_EXPERIMENTAL_STEPVECTOR:
    case mx::ir::OperationKind::LLVM_INTR_THREADLOCAL_ADDRESS:
    case mx::ir::OperationKind::LLVM_INTR_TRAP:
    case mx::ir::OperationKind::LLVM_INTR_UADD_SAT:
    case mx::ir::OperationKind::LLVM_INTR_UADD_WITH_OVERFLOW:
    case mx::ir::OperationKind::LLVM_INTR_UBSANTRAP:
    case mx::ir::OperationKind::LLVM_INTR_UMAX:
    case mx::ir::OperationKind::LLVM_INTR_UMIN:
    case mx::ir::OperationKind::LLVM_INTR_UMUL_WITH_OVERFLOW:
    case mx::ir::OperationKind::LLVM_INTR_USHL_SAT:
    case mx::ir::OperationKind::LLVM_INTR_USUB_SAT:
    case mx::ir::OperationKind::LLVM_INTR_USUB_WITH_OVERFLOW:
    case mx::ir::OperationKind::LLVM_INTR_VP_ASHR:
    case mx::ir::OperationKind::LLVM_INTR_VP_ADD:
    case mx::ir::OperationKind::LLVM_INTR_VP_AND:
    case mx::ir::OperationKind::LLVM_INTR_VP_FADD:
    case mx::ir::OperationKind::LLVM_INTR_VP_FDIV:
    case mx::ir::OperationKind::LLVM_INTR_VP_FMULADD:
    case mx::ir::OperationKind::LLVM_INTR_VP_FMUL:
    case mx::ir::OperationKind::LLVM_INTR_VP_FNEG:
    case mx::ir::OperationKind::LLVM_INTR_VP_FPEXT:
    case mx::ir::OperationKind::LLVM_INTR_VP_FPTOSI:
    case mx::ir::OperationKind::LLVM_INTR_VP_FPTOUI:
    case mx::ir::OperationKind::LLVM_INTR_VP_FPTRUNC:
    case mx::ir::OperationKind::LLVM_INTR_VP_FREM:
    case mx::ir::OperationKind::LLVM_INTR_VP_FSUB:
    case mx::ir::OperationKind::LLVM_INTR_VP_FMA:
    case mx::ir::OperationKind::LLVM_INTR_VP_INTTOPTR:
    case mx::ir::OperationKind::LLVM_INTR_VP_LSHR:
    case mx::ir::OperationKind::LLVM_INTR_VP_LOAD:
    case mx::ir::OperationKind::LLVM_INTR_VP_MERGE:
    case mx::ir::OperationKind::LLVM_INTR_VP_MUL:
    case mx::ir::OperationKind::LLVM_INTR_VP_OR:
    case mx::ir::OperationKind::LLVM_INTR_VP_PTRTOINT:
    case mx::ir::OperationKind::LLVM_INTR_VP_REDUCE_ADD:
    case mx::ir::OperationKind::LLVM_INTR_VP_REDUCE_AND:
    case mx::ir::OperationKind::LLVM_INTR_VP_REDUCE_FADD:
    case mx::ir::OperationKind::LLVM_INTR_VP_REDUCE_FMAX:
    case mx::ir::OperationKind::LLVM_INTR_VP_REDUCE_FMIN:
    case mx::ir::OperationKind::LLVM_INTR_VP_REDUCE_FMUL:
    case mx::ir::OperationKind::LLVM_INTR_VP_REDUCE_MUL:
    case mx::ir::OperationKind::LLVM_INTR_VP_REDUCE_OR:
    case mx::ir::OperationKind::LLVM_INTR_VP_REDUCE_SMAX:
    case mx::ir::OperationKind::LLVM_INTR_VP_REDUCE_SMIN:
    case mx::ir::OperationKind::LLVM_INTR_VP_REDUCE_UMAX:
    case mx::ir::OperationKind::LLVM_INTR_VP_REDUCE_UMIN:
    case mx::ir::OperationKind::LLVM_INTR_VP_REDUCE_XOR:
    case mx::ir::OperationKind::LLVM_INTR_VP_SDIV:
    case mx::ir::OperationKind::LLVM_INTR_VP_SEXT:
    case mx::ir::OperationKind::LLVM_INTR_VP_SITOFP:
    case mx::ir::OperationKind::LLVM_INTR_VP_SREM:
    case mx::ir::OperationKind::LLVM_INTR_VP_SELECT:
    case mx::ir::OperationKind::LLVM_INTR_VP_SHL:
    case mx::ir::OperationKind::LLVM_INTR_VP_STORE:
    case mx::ir::OperationKind::LLVM_INTR_EXPERIMENTAL_VP_STRIDED_LOAD:
    case mx::ir::OperationKind::LLVM_INTR_EXPERIMENTAL_VP_STRIDED_STORE:
    case mx::ir::OperationKind::LLVM_INTR_VP_SUB:
    case mx::ir::OperationKind::LLVM_INTR_VP_TRUNC:
    case mx::ir::OperationKind::LLVM_INTR_VP_UDIV:
    case mx::ir::OperationKind::LLVM_INTR_VP_UITOFP:
    case mx::ir::OperationKind::LLVM_INTR_VP_UREM:
    case mx::ir::OperationKind::LLVM_INTR_VP_XOR:
    case mx::ir::OperationKind::LLVM_INTR_VP_ZEXT:
    case mx::ir::OperationKind::LLVM_INTR_VACOPY:
    case mx::ir::OperationKind::LLVM_INTR_VAEND:
    case mx::ir::OperationKind::LLVM_INTR_VASTART:
    case mx::ir::OperationKind::LLVM_INTR_VAR_ANNOTATION:
    case mx::ir::OperationKind::LLVM_INTR_MASKED_COMPRESSSTORE:
    case mx::ir::OperationKind::LLVM_INTR_MASKED_EXPANDLOAD:
    case mx::ir::OperationKind::LLVM_INTR_MASKED_GATHER:
    case mx::ir::OperationKind::LLVM_INTR_MASKED_SCATTER:
    case mx::ir::OperationKind::LLVM_INTR_VECTOR_EXTRACT:
    case mx::ir::OperationKind::LLVM_INTR_VECTOR_INSERT:
    case mx::ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_ADD:
    case mx::ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_AND:
    case mx::ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_FADD:
    case mx::ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_FMAX:
    case mx::ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_FMAXIMUM:
    case mx::ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_FMIN:
    case mx::ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_FMINIMUM:
    case mx::ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_FMUL:
    case mx::ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_MUL:
    case mx::ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_OR:
    case mx::ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_SMAX:
    case mx::ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_SMIN:
    case mx::ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_UMAX:
    case mx::ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_UMIN:
    case mx::ir::OperationKind::LLVM_INTR_VECTOR_REDUCE_XOR:
    case mx::ir::OperationKind::LLVM_INTR_VSCALE:
      return true;
  }
}

bool IsMemRefOperationKind(ir::OperationKind kind) {
  switch (kind) {
    default:
      return false;
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
      return true;
  }
}

bool IsABIOperationKind(ir::OperationKind kind) {
  switch (kind) {
    default:
      return false;
    case mx::ir::OperationKind::ABI_CALL_ARGS:
    case mx::ir::OperationKind::ABI_CALL_EXEC:
    case mx::ir::OperationKind::ABI_CALL:
    case mx::ir::OperationKind::ABI_CALL_RETS:
    case mx::ir::OperationKind::ABI_DIRECT:
    case mx::ir::OperationKind::ABI_EPILOGUE:
    case mx::ir::OperationKind::ABI_FUNC:
    case mx::ir::OperationKind::ABI_PROLOGUE:
    case mx::ir::OperationKind::ABI_RET_DIRECT:
    case mx::ir::OperationKind::ABI_TODO:
    case mx::ir::OperationKind::ABI_WRAP_FN:
    case mx::ir::OperationKind::ABI_YIELD:
      return true;
  }
}

bool IsLowLevelOperationKind(ir::OperationKind kind) {
  switch (kind) {
    default:
      return false;
    case mx::ir::OperationKind::LL_BR:
    case mx::ir::OperationKind::LL_CONCAT:
    case mx::ir::OperationKind::LL_COND_BR:
    case mx::ir::OperationKind::LL_COND_SCOPE_RET:
    case mx::ir::OperationKind::LL_EXTRACT:
    case mx::ir::OperationKind::LL_INITIALIZE:
    case mx::ir::OperationKind::LL_INLINE_SCOPE:
    case mx::ir::OperationKind::LL_FUNC:
    case mx::ir::OperationKind::LL_GEP:
    case mx::ir::OperationKind::LL_RETURN:
    case mx::ir::OperationKind::LL_SCOPE:
    case mx::ir::OperationKind::LL_SCOPE_RECURSE:
    case mx::ir::OperationKind::LL_SCOPE_RET:
    case mx::ir::OperationKind::LL_UNINITIALIZED_VAR:
      return true;
  }
}

bool IsHighLevelOperationKind(ir::OperationKind kind) {
  switch (kind) {
    default:
      return false;
    case mx::ir::OperationKind::HL_ACCESS:
    case mx::ir::OperationKind::HL_ASSIGN_FADD:
    case mx::ir::OperationKind::HL_FADD:
    case mx::ir::OperationKind::HL_ASSIGN_ADD:
    case mx::ir::OperationKind::HL_ADD:
    case mx::ir::OperationKind::HL_LABELADDR:
    case mx::ir::OperationKind::HL_ADDRESSOF:
    case mx::ir::OperationKind::HL_ALIGNOF_EXPR:
    case mx::ir::OperationKind::HL_ALIGNOF_TYPE:
    case mx::ir::OperationKind::HL_ASM:
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
      return true;
  }
}

bool IsCoreOperationKind(ir::OperationKind kind) {
  switch (kind) {
    default:
      return false;
    case mx::ir::OperationKind::CORE_BIN_LAND:
    case mx::ir::OperationKind::CORE_BIN_LOR:
    case mx::ir::OperationKind::CORE_IMPLICIT_RETURN:
    case mx::ir::OperationKind::CORE_LAZY_OP:
    case mx::ir::OperationKind::CORE_SCOPE:
    case mx::ir::OperationKind::CORE_SELECT:
      return true;
  }
}

bool IsMetaOperationKind(ir::OperationKind kind) {
  switch (kind) {
    default:
      return false;
  }
}

bool IsUnsupportedOperationKind(ir::OperationKind kind) {
  switch (kind) {
    default:
      return false;
    case mx::ir::OperationKind::UNSUP_DECL:
    case mx::ir::OperationKind::UNSUP_STMT:
      return true;
  }
}

}  // namespace mx
