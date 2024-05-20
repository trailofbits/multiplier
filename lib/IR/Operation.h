// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#define MX_IR_FOR_EACH_MLIR_OP(_builtin, _llvm, _memref, _abi, _ll, _hl, _core, _meta, _unsup) \
   _builtin("builtin.module", OperationKind::BUILTIN_MODULE, mlir::ModuleOp) \
   _builtin("builtin.unrealized_conversion_cast", OperationKind::BUILTIN_UNREALIZED_CONVERSION_CAST, mlir::UnrealizedConversionCastOp) \
   _llvm("llvm.ashr", OperationKind::LLVM_ASHR, mlir::LLVM::AShrOp) \
   _llvm("llvm.add", OperationKind::LLVM_ADD, mlir::LLVM::AddOp) \
   _llvm("llvm.addrspacecast", OperationKind::LLVM_ADDRSPACECAST, mlir::LLVM::AddrSpaceCastOp) \
   _llvm("llvm.mlir.addressof", OperationKind::LLVM_MLIR_ADDRESSOF, mlir::LLVM::AddressOfOp) \
   _llvm("llvm.alloca", OperationKind::LLVM_ALLOCA, mlir::LLVM::AllocaOp) \
   _llvm("llvm.and", OperationKind::LLVM_AND, mlir::LLVM::AndOp) \
   _llvm("llvm.cmpxchg", OperationKind::LLVM_CMPXCHG, mlir::LLVM::AtomicCmpXchgOp) \
   _llvm("llvm.atomicrmw", OperationKind::LLVM_ATOMICRMW, mlir::LLVM::AtomicRMWOp) \
   _llvm("llvm.bitcast", OperationKind::LLVM_BITCAST, mlir::LLVM::BitcastOp) \
   _llvm("llvm.br", OperationKind::LLVM_BR, mlir::LLVM::BrOp) \
   _llvm("llvm.call_intrinsic", OperationKind::LLVM_CALL_INTRINSIC, mlir::LLVM::CallIntrinsicOp) \
   _llvm("llvm.call", OperationKind::LLVM_CALL, mlir::LLVM::CallOp) \
   _llvm("llvm.comdat", OperationKind::LLVM_COMDAT, mlir::LLVM::ComdatOp) \
   _llvm("llvm.comdat_selector", OperationKind::LLVM_COMDAT_SELECTOR, mlir::LLVM::ComdatSelectorOp) \
   _llvm("llvm.cond_br", OperationKind::LLVM_COND_BR, mlir::LLVM::CondBrOp) \
   _llvm("llvm.mlir.constant", OperationKind::LLVM_MLIR_CONSTANT, mlir::LLVM::ConstantOp) \
   _llvm("llvm.extractelement", OperationKind::LLVM_EXTRACTELEMENT, mlir::LLVM::ExtractElementOp) \
   _llvm("llvm.extractvalue", OperationKind::LLVM_EXTRACTVALUE, mlir::LLVM::ExtractValueOp) \
   _llvm("llvm.fadd", OperationKind::LLVM_FADD, mlir::LLVM::FAddOp) \
   _llvm("llvm.fcmp", OperationKind::LLVM_FCMP, mlir::LLVM::FCmpOp) \
   _llvm("llvm.fdiv", OperationKind::LLVM_FDIV, mlir::LLVM::FDivOp) \
   _llvm("llvm.fmul", OperationKind::LLVM_FMUL, mlir::LLVM::FMulOp) \
   _llvm("llvm.fneg", OperationKind::LLVM_FNEG, mlir::LLVM::FNegOp) \
   _llvm("llvm.fpext", OperationKind::LLVM_FPEXT, mlir::LLVM::FPExtOp) \
   _llvm("llvm.fptosi", OperationKind::LLVM_FPTOSI, mlir::LLVM::FPToSIOp) \
   _llvm("llvm.fptoui", OperationKind::LLVM_FPTOUI, mlir::LLVM::FPToUIOp) \
   _llvm("llvm.fptrunc", OperationKind::LLVM_FPTRUNC, mlir::LLVM::FPTruncOp) \
   _llvm("llvm.frem", OperationKind::LLVM_FREM, mlir::LLVM::FRemOp) \
   _llvm("llvm.fsub", OperationKind::LLVM_FSUB, mlir::LLVM::FSubOp) \
   _llvm("llvm.fence", OperationKind::LLVM_FENCE, mlir::LLVM::FenceOp) \
   _llvm("llvm.freeze", OperationKind::LLVM_FREEZE, mlir::LLVM::FreezeOp) \
   _llvm("llvm.getelementptr", OperationKind::LLVM_GETELEMENTPTR, mlir::LLVM::GEPOp) \
   _llvm("llvm.mlir.global_ctors", OperationKind::LLVM_MLIR_GLOBAL_CTORS, mlir::LLVM::GlobalCtorsOp) \
   _llvm("llvm.mlir.global_dtors", OperationKind::LLVM_MLIR_GLOBAL_DTORS, mlir::LLVM::GlobalDtorsOp) \
   _llvm("llvm.mlir.global", OperationKind::LLVM_MLIR_GLOBAL, mlir::LLVM::GlobalOp) \
   _llvm("llvm.icmp", OperationKind::LLVM_ICMP, mlir::LLVM::ICmpOp) \
   _llvm("llvm.inline_asm", OperationKind::LLVM_INLINE_ASM, mlir::LLVM::InlineAsmOp) \
   _llvm("llvm.insertelement", OperationKind::LLVM_INSERTELEMENT, mlir::LLVM::InsertElementOp) \
   _llvm("llvm.insertvalue", OperationKind::LLVM_INSERTVALUE, mlir::LLVM::InsertValueOp) \
   _llvm("llvm.inttoptr", OperationKind::LLVM_INTTOPTR, mlir::LLVM::IntToPtrOp) \
   _llvm("llvm.invoke", OperationKind::LLVM_INVOKE, mlir::LLVM::InvokeOp) \
   _llvm("llvm.func", OperationKind::LLVM_FUNC, mlir::LLVM::LLVMFuncOp) \
   _llvm("llvm.lshr", OperationKind::LLVM_LSHR, mlir::LLVM::LShrOp) \
   _llvm("llvm.landingpad", OperationKind::LLVM_LANDINGPAD, mlir::LLVM::LandingpadOp) \
   _llvm("llvm.linker_options", OperationKind::LLVM_LINKER_OPTIONS, mlir::LLVM::LinkerOptionsOp) \
   _llvm("llvm.load", OperationKind::LLVM_LOAD, mlir::LLVM::LoadOp) \
   _llvm("llvm.mul", OperationKind::LLVM_MUL, mlir::LLVM::MulOp) \
   _llvm("llvm.mlir.none", OperationKind::LLVM_MLIR_NONE, mlir::LLVM::NoneTokenOp) \
   _llvm("llvm.or", OperationKind::LLVM_OR, mlir::LLVM::OrOp) \
   _llvm("llvm.mlir.poison", OperationKind::LLVM_MLIR_POISON, mlir::LLVM::PoisonOp) \
   _llvm("llvm.ptrtoint", OperationKind::LLVM_PTRTOINT, mlir::LLVM::PtrToIntOp) \
   _llvm("llvm.resume", OperationKind::LLVM_RESUME, mlir::LLVM::ResumeOp) \
   _llvm("llvm.return", OperationKind::LLVM_RETURN, mlir::LLVM::ReturnOp) \
   _llvm("llvm.sdiv", OperationKind::LLVM_SDIV, mlir::LLVM::SDivOp) \
   _llvm("llvm.sext", OperationKind::LLVM_SEXT, mlir::LLVM::SExtOp) \
   _llvm("llvm.sitofp", OperationKind::LLVM_SITOFP, mlir::LLVM::SIToFPOp) \
   _llvm("llvm.srem", OperationKind::LLVM_SREM, mlir::LLVM::SRemOp) \
   _llvm("llvm.select", OperationKind::LLVM_SELECT, mlir::LLVM::SelectOp) \
   _llvm("llvm.shl", OperationKind::LLVM_SHL, mlir::LLVM::ShlOp) \
   _llvm("llvm.shufflevector", OperationKind::LLVM_SHUFFLEVECTOR, mlir::LLVM::ShuffleVectorOp) \
   _llvm("llvm.store", OperationKind::LLVM_STORE, mlir::LLVM::StoreOp) \
   _llvm("llvm.sub", OperationKind::LLVM_SUB, mlir::LLVM::SubOp) \
   _llvm("llvm.switch", OperationKind::LLVM_SWITCH, mlir::LLVM::SwitchOp) \
   _llvm("llvm.trunc", OperationKind::LLVM_TRUNC, mlir::LLVM::TruncOp) \
   _llvm("llvm.udiv", OperationKind::LLVM_UDIV, mlir::LLVM::UDivOp) \
   _llvm("llvm.uitofp", OperationKind::LLVM_UITOFP, mlir::LLVM::UIToFPOp) \
   _llvm("llvm.urem", OperationKind::LLVM_UREM, mlir::LLVM::URemOp) \
   _llvm("llvm.mlir.undef", OperationKind::LLVM_MLIR_UNDEF, mlir::LLVM::UndefOp) \
   _llvm("llvm.unreachable", OperationKind::LLVM_UNREACHABLE, mlir::LLVM::UnreachableOp) \
   _llvm("llvm.xor", OperationKind::LLVM_XOR, mlir::LLVM::XOrOp) \
   _llvm("llvm.zext", OperationKind::LLVM_ZEXT, mlir::LLVM::ZExtOp) \
   _llvm("llvm.mlir.zero", OperationKind::LLVM_MLIR_ZERO, mlir::LLVM::ZeroOp) \
   _llvm("llvm.intr.abs", OperationKind::LLVM_INTR_ABS, mlir::LLVM::AbsOp) \
   _llvm("llvm.intr.annotation", OperationKind::LLVM_INTR_ANNOTATION, mlir::LLVM::Annotation) \
   _llvm("llvm.intr.assume", OperationKind::LLVM_INTR_ASSUME, mlir::LLVM::AssumeOp) \
   _llvm("llvm.intr.bitreverse", OperationKind::LLVM_INTR_BITREVERSE, mlir::LLVM::BitReverseOp) \
   _llvm("llvm.intr.bswap", OperationKind::LLVM_INTR_BSWAP, mlir::LLVM::ByteSwapOp) \
   _llvm("llvm.intr.copysign", OperationKind::LLVM_INTR_COPYSIGN, mlir::LLVM::CopySignOp) \
   _llvm("llvm.intr.coro.align", OperationKind::LLVM_INTR_CORO_ALIGN, mlir::LLVM::CoroAlignOp) \
   _llvm("llvm.intr.coro.begin", OperationKind::LLVM_INTR_CORO_BEGIN, mlir::LLVM::CoroBeginOp) \
   _llvm("llvm.intr.coro.end", OperationKind::LLVM_INTR_CORO_END, mlir::LLVM::CoroEndOp) \
   _llvm("llvm.intr.coro.free", OperationKind::LLVM_INTR_CORO_FREE, mlir::LLVM::CoroFreeOp) \
   _llvm("llvm.intr.coro.id", OperationKind::LLVM_INTR_CORO_ID, mlir::LLVM::CoroIdOp) \
   _llvm("llvm.intr.coro.promise", OperationKind::LLVM_INTR_CORO_PROMISE, mlir::LLVM::CoroPromiseOp) \
   _llvm("llvm.intr.coro.resume", OperationKind::LLVM_INTR_CORO_RESUME, mlir::LLVM::CoroResumeOp) \
   _llvm("llvm.intr.coro.save", OperationKind::LLVM_INTR_CORO_SAVE, mlir::LLVM::CoroSaveOp) \
   _llvm("llvm.intr.coro.size", OperationKind::LLVM_INTR_CORO_SIZE, mlir::LLVM::CoroSizeOp) \
   _llvm("llvm.intr.coro.suspend", OperationKind::LLVM_INTR_CORO_SUSPEND, mlir::LLVM::CoroSuspendOp) \
   _llvm("llvm.intr.cos", OperationKind::LLVM_INTR_COS, mlir::LLVM::CosOp) \
   _llvm("llvm.intr.ctlz", OperationKind::LLVM_INTR_CTLZ, mlir::LLVM::CountLeadingZerosOp) \
   _llvm("llvm.intr.cttz", OperationKind::LLVM_INTR_CTTZ, mlir::LLVM::CountTrailingZerosOp) \
   _llvm("llvm.intr.ctpop", OperationKind::LLVM_INTR_CTPOP, mlir::LLVM::CtPopOp) \
   _llvm("llvm.intr.dbg.declare", OperationKind::LLVM_INTR_DBG_DECLARE, mlir::LLVM::DbgDeclareOp) \
   _llvm("llvm.intr.dbg.label", OperationKind::LLVM_INTR_DBG_LABEL, mlir::LLVM::DbgLabelOp) \
   _llvm("llvm.intr.dbg.value", OperationKind::LLVM_INTR_DBG_VALUE, mlir::LLVM::DbgValueOp) \
   _llvm("llvm.intr.debugtrap", OperationKind::LLVM_INTR_DEBUGTRAP, mlir::LLVM::DebugTrap) \
   _llvm("llvm.intr.eh.typeid.for", OperationKind::LLVM_INTR_EH_TYPEID_FOR, mlir::LLVM::EhTypeidForOp) \
   _llvm("llvm.intr.exp2", OperationKind::LLVM_INTR_EXP2, mlir::LLVM::Exp2Op) \
   _llvm("llvm.intr.exp", OperationKind::LLVM_INTR_EXP, mlir::LLVM::ExpOp) \
   _llvm("llvm.intr.expect", OperationKind::LLVM_INTR_EXPECT, mlir::LLVM::ExpectOp) \
   _llvm("llvm.intr.expect.with.probability", OperationKind::LLVM_INTR_EXPECT_WITH_PROBABILITY, mlir::LLVM::ExpectWithProbabilityOp) \
   _llvm("llvm.intr.fabs", OperationKind::LLVM_INTR_FABS, mlir::LLVM::FAbsOp) \
   _llvm("llvm.intr.ceil", OperationKind::LLVM_INTR_CEIL, mlir::LLVM::FCeilOp) \
   _llvm("llvm.intr.floor", OperationKind::LLVM_INTR_FLOOR, mlir::LLVM::FFloorOp) \
   _llvm("llvm.intr.fma", OperationKind::LLVM_INTR_FMA, mlir::LLVM::FMAOp) \
   _llvm("llvm.intr.fmuladd", OperationKind::LLVM_INTR_FMULADD, mlir::LLVM::FMulAddOp) \
   _llvm("llvm.intr.trunc", OperationKind::LLVM_INTR_TRUNC, mlir::LLVM::FTruncOp) \
   _llvm("llvm.intr.fshl", OperationKind::LLVM_INTR_FSHL, mlir::LLVM::FshlOp) \
   _llvm("llvm.intr.fshr", OperationKind::LLVM_INTR_FSHR, mlir::LLVM::FshrOp) \
   _llvm("llvm.intr.get.active.lane.mask", OperationKind::LLVM_INTR_GET_ACTIVE_LANE_MASK, mlir::LLVM::GetActiveLaneMaskOp) \
   _llvm("llvm.intr.invariant.end", OperationKind::LLVM_INTR_INVARIANT_END, mlir::LLVM::InvariantEndOp) \
   _llvm("llvm.intr.invariant.start", OperationKind::LLVM_INTR_INVARIANT_START, mlir::LLVM::InvariantStartOp) \
   _llvm("llvm.intr.is.constant", OperationKind::LLVM_INTR_IS_CONSTANT, mlir::LLVM::IsConstantOp) \
   _llvm("llvm.intr.is.fpclass", OperationKind::LLVM_INTR_IS_FPCLASS, mlir::LLVM::IsFPClass) \
   _llvm("llvm.intr.lifetime.end", OperationKind::LLVM_INTR_LIFETIME_END, mlir::LLVM::LifetimeEndOp) \
   _llvm("llvm.intr.lifetime.start", OperationKind::LLVM_INTR_LIFETIME_START, mlir::LLVM::LifetimeStartOp) \
   _llvm("llvm.intr.llrint", OperationKind::LLVM_INTR_LLRINT, mlir::LLVM::LlrintOp) \
   _llvm("llvm.intr.llround", OperationKind::LLVM_INTR_LLROUND, mlir::LLVM::LlroundOp) \
   _llvm("llvm.intr.log10", OperationKind::LLVM_INTR_LOG10, mlir::LLVM::Log10Op) \
   _llvm("llvm.intr.log2", OperationKind::LLVM_INTR_LOG2, mlir::LLVM::Log2Op) \
   _llvm("llvm.intr.log", OperationKind::LLVM_INTR_LOG, mlir::LLVM::LogOp) \
   _llvm("llvm.intr.lrint", OperationKind::LLVM_INTR_LRINT, mlir::LLVM::LrintOp) \
   _llvm("llvm.intr.lround", OperationKind::LLVM_INTR_LROUND, mlir::LLVM::LroundOp) \
   _llvm("llvm.intr.masked.load", OperationKind::LLVM_INTR_MASKED_LOAD, mlir::LLVM::MaskedLoadOp) \
   _llvm("llvm.intr.masked.store", OperationKind::LLVM_INTR_MASKED_STORE, mlir::LLVM::MaskedStoreOp) \
   _llvm("llvm.intr.matrix.column.major.load", OperationKind::LLVM_INTR_MATRIX_COLUMN_MAJOR_LOAD, mlir::LLVM::MatrixColumnMajorLoadOp) \
   _llvm("llvm.intr.matrix.column.major.store", OperationKind::LLVM_INTR_MATRIX_COLUMN_MAJOR_STORE, mlir::LLVM::MatrixColumnMajorStoreOp) \
   _llvm("llvm.intr.matrix.multiply", OperationKind::LLVM_INTR_MATRIX_MULTIPLY, mlir::LLVM::MatrixMultiplyOp) \
   _llvm("llvm.intr.matrix.transpose", OperationKind::LLVM_INTR_MATRIX_TRANSPOSE, mlir::LLVM::MatrixTransposeOp) \
   _llvm("llvm.intr.maxnum", OperationKind::LLVM_INTR_MAXNUM, mlir::LLVM::MaxNumOp) \
   _llvm("llvm.intr.maximum", OperationKind::LLVM_INTR_MAXIMUM, mlir::LLVM::MaximumOp) \
   _llvm("llvm.intr.memcpy.inline", OperationKind::LLVM_INTR_MEMCPY_INLINE, mlir::LLVM::MemcpyInlineOp) \
   _llvm("llvm.intr.memcpy", OperationKind::LLVM_INTR_MEMCPY, mlir::LLVM::MemcpyOp) \
   _llvm("llvm.intr.memmove", OperationKind::LLVM_INTR_MEMMOVE, mlir::LLVM::MemmoveOp) \
   _llvm("llvm.intr.memset", OperationKind::LLVM_INTR_MEMSET, mlir::LLVM::MemsetOp) \
   _llvm("llvm.intr.minnum", OperationKind::LLVM_INTR_MINNUM, mlir::LLVM::MinNumOp) \
   _llvm("llvm.intr.minimum", OperationKind::LLVM_INTR_MINIMUM, mlir::LLVM::MinimumOp) \
   _llvm("llvm.intr.nearbyint", OperationKind::LLVM_INTR_NEARBYINT, mlir::LLVM::NearbyintOp) \
   _llvm("llvm.intr.experimental.noalias.scope.decl", OperationKind::LLVM_INTR_EXPERIMENTAL_NOALIAS_SCOPE_DECL, mlir::LLVM::NoAliasScopeDeclOp) \
   _llvm("llvm.intr.powi", OperationKind::LLVM_INTR_POWI, mlir::LLVM::PowIOp) \
   _llvm("llvm.intr.pow", OperationKind::LLVM_INTR_POW, mlir::LLVM::PowOp) \
   _llvm("llvm.intr.prefetch", OperationKind::LLVM_INTR_PREFETCH, mlir::LLVM::Prefetch) \
   _llvm("llvm.intr.ptr.annotation", OperationKind::LLVM_INTR_PTR_ANNOTATION, mlir::LLVM::PtrAnnotation) \
   _llvm("llvm.intr.rint", OperationKind::LLVM_INTR_RINT, mlir::LLVM::RintOp) \
   _llvm("llvm.intr.roundeven", OperationKind::LLVM_INTR_ROUNDEVEN, mlir::LLVM::RoundEvenOp) \
   _llvm("llvm.intr.round", OperationKind::LLVM_INTR_ROUND, mlir::LLVM::RoundOp) \
   _llvm("llvm.intr.sadd.sat", OperationKind::LLVM_INTR_SADD_SAT, mlir::LLVM::SAddSat) \
   _llvm("llvm.intr.sadd.with.overflow", OperationKind::LLVM_INTR_SADD_WITH_OVERFLOW, mlir::LLVM::SAddWithOverflowOp) \
   _llvm("llvm.intr.smax", OperationKind::LLVM_INTR_SMAX, mlir::LLVM::SMaxOp) \
   _llvm("llvm.intr.smin", OperationKind::LLVM_INTR_SMIN, mlir::LLVM::SMinOp) \
   _llvm("llvm.intr.smul.with.overflow", OperationKind::LLVM_INTR_SMUL_WITH_OVERFLOW, mlir::LLVM::SMulWithOverflowOp) \
   _llvm("llvm.intr.ssa.copy", OperationKind::LLVM_INTR_SSA_COPY, mlir::LLVM::SSACopyOp) \
   _llvm("llvm.intr.sshl.sat", OperationKind::LLVM_INTR_SSHL_SAT, mlir::LLVM::SSHLSat) \
   _llvm("llvm.intr.ssub.sat", OperationKind::LLVM_INTR_SSUB_SAT, mlir::LLVM::SSubSat) \
   _llvm("llvm.intr.ssub.with.overflow", OperationKind::LLVM_INTR_SSUB_WITH_OVERFLOW, mlir::LLVM::SSubWithOverflowOp) \
   _llvm("llvm.intr.sin", OperationKind::LLVM_INTR_SIN, mlir::LLVM::SinOp) \
   _llvm("llvm.intr.sqrt", OperationKind::LLVM_INTR_SQRT, mlir::LLVM::SqrtOp) \
   _llvm("llvm.intr.stackrestore", OperationKind::LLVM_INTR_STACKRESTORE, mlir::LLVM::StackRestoreOp) \
   _llvm("llvm.intr.stacksave", OperationKind::LLVM_INTR_STACKSAVE, mlir::LLVM::StackSaveOp) \
   _llvm("llvm.intr.experimental.stepvector", OperationKind::LLVM_INTR_EXPERIMENTAL_STEPVECTOR, mlir::LLVM::StepVectorOp) \
   _llvm("llvm.intr.threadlocal.address", OperationKind::LLVM_INTR_THREADLOCAL_ADDRESS, mlir::LLVM::ThreadlocalAddressOp) \
   _llvm("llvm.intr.trap", OperationKind::LLVM_INTR_TRAP, mlir::LLVM::Trap) \
   _llvm("llvm.intr.uadd.sat", OperationKind::LLVM_INTR_UADD_SAT, mlir::LLVM::UAddSat) \
   _llvm("llvm.intr.uadd.with.overflow", OperationKind::LLVM_INTR_UADD_WITH_OVERFLOW, mlir::LLVM::UAddWithOverflowOp) \
   _llvm("llvm.intr.ubsantrap", OperationKind::LLVM_INTR_UBSANTRAP, mlir::LLVM::UBSanTrap) \
   _llvm("llvm.intr.umax", OperationKind::LLVM_INTR_UMAX, mlir::LLVM::UMaxOp) \
   _llvm("llvm.intr.umin", OperationKind::LLVM_INTR_UMIN, mlir::LLVM::UMinOp) \
   _llvm("llvm.intr.umul.with.overflow", OperationKind::LLVM_INTR_UMUL_WITH_OVERFLOW, mlir::LLVM::UMulWithOverflowOp) \
   _llvm("llvm.intr.ushl.sat", OperationKind::LLVM_INTR_USHL_SAT, mlir::LLVM::USHLSat) \
   _llvm("llvm.intr.usub.sat", OperationKind::LLVM_INTR_USUB_SAT, mlir::LLVM::USubSat) \
   _llvm("llvm.intr.usub.with.overflow", OperationKind::LLVM_INTR_USUB_WITH_OVERFLOW, mlir::LLVM::USubWithOverflowOp) \
   _llvm("llvm.intr.vp.ashr", OperationKind::LLVM_INTR_VP_ASHR, mlir::LLVM::VPAShrOp) \
   _llvm("llvm.intr.vp.add", OperationKind::LLVM_INTR_VP_ADD, mlir::LLVM::VPAddOp) \
   _llvm("llvm.intr.vp.and", OperationKind::LLVM_INTR_VP_AND, mlir::LLVM::VPAndOp) \
   _llvm("llvm.intr.vp.fadd", OperationKind::LLVM_INTR_VP_FADD, mlir::LLVM::VPFAddOp) \
   _llvm("llvm.intr.vp.fdiv", OperationKind::LLVM_INTR_VP_FDIV, mlir::LLVM::VPFDivOp) \
   _llvm("llvm.intr.vp.fmuladd", OperationKind::LLVM_INTR_VP_FMULADD, mlir::LLVM::VPFMulAddOp) \
   _llvm("llvm.intr.vp.fmul", OperationKind::LLVM_INTR_VP_FMUL, mlir::LLVM::VPFMulOp) \
   _llvm("llvm.intr.vp.fneg", OperationKind::LLVM_INTR_VP_FNEG, mlir::LLVM::VPFNegOp) \
   _llvm("llvm.intr.vp.fpext", OperationKind::LLVM_INTR_VP_FPEXT, mlir::LLVM::VPFPExtOp) \
   _llvm("llvm.intr.vp.fptosi", OperationKind::LLVM_INTR_VP_FPTOSI, mlir::LLVM::VPFPToSIOp) \
   _llvm("llvm.intr.vp.fptoui", OperationKind::LLVM_INTR_VP_FPTOUI, mlir::LLVM::VPFPToUIOp) \
   _llvm("llvm.intr.vp.fptrunc", OperationKind::LLVM_INTR_VP_FPTRUNC, mlir::LLVM::VPFPTruncOp) \
   _llvm("llvm.intr.vp.frem", OperationKind::LLVM_INTR_VP_FREM, mlir::LLVM::VPFRemOp) \
   _llvm("llvm.intr.vp.fsub", OperationKind::LLVM_INTR_VP_FSUB, mlir::LLVM::VPFSubOp) \
   _llvm("llvm.intr.vp.fma", OperationKind::LLVM_INTR_VP_FMA, mlir::LLVM::VPFmaOp) \
   _llvm("llvm.intr.vp.inttoptr", OperationKind::LLVM_INTR_VP_INTTOPTR, mlir::LLVM::VPIntToPtrOp) \
   _llvm("llvm.intr.vp.lshr", OperationKind::LLVM_INTR_VP_LSHR, mlir::LLVM::VPLShrOp) \
   _llvm("llvm.intr.vp.load", OperationKind::LLVM_INTR_VP_LOAD, mlir::LLVM::VPLoadOp) \
   _llvm("llvm.intr.vp.merge", OperationKind::LLVM_INTR_VP_MERGE, mlir::LLVM::VPMergeMinOp) \
   _llvm("llvm.intr.vp.mul", OperationKind::LLVM_INTR_VP_MUL, mlir::LLVM::VPMulOp) \
   _llvm("llvm.intr.vp.or", OperationKind::LLVM_INTR_VP_OR, mlir::LLVM::VPOrOp) \
   _llvm("llvm.intr.vp.ptrtoint", OperationKind::LLVM_INTR_VP_PTRTOINT, mlir::LLVM::VPPtrToIntOp) \
   _llvm("llvm.intr.vp.reduce.add", OperationKind::LLVM_INTR_VP_REDUCE_ADD, mlir::LLVM::VPReduceAddOp) \
   _llvm("llvm.intr.vp.reduce.and", OperationKind::LLVM_INTR_VP_REDUCE_AND, mlir::LLVM::VPReduceAndOp) \
   _llvm("llvm.intr.vp.reduce.fadd", OperationKind::LLVM_INTR_VP_REDUCE_FADD, mlir::LLVM::VPReduceFAddOp) \
   _llvm("llvm.intr.vp.reduce.fmax", OperationKind::LLVM_INTR_VP_REDUCE_FMAX, mlir::LLVM::VPReduceFMaxOp) \
   _llvm("llvm.intr.vp.reduce.fmin", OperationKind::LLVM_INTR_VP_REDUCE_FMIN, mlir::LLVM::VPReduceFMinOp) \
   _llvm("llvm.intr.vp.reduce.fmul", OperationKind::LLVM_INTR_VP_REDUCE_FMUL, mlir::LLVM::VPReduceFMulOp) \
   _llvm("llvm.intr.vp.reduce.mul", OperationKind::LLVM_INTR_VP_REDUCE_MUL, mlir::LLVM::VPReduceMulOp) \
   _llvm("llvm.intr.vp.reduce.or", OperationKind::LLVM_INTR_VP_REDUCE_OR, mlir::LLVM::VPReduceOrOp) \
   _llvm("llvm.intr.vp.reduce.smax", OperationKind::LLVM_INTR_VP_REDUCE_SMAX, mlir::LLVM::VPReduceSMaxOp) \
   _llvm("llvm.intr.vp.reduce.smin", OperationKind::LLVM_INTR_VP_REDUCE_SMIN, mlir::LLVM::VPReduceSMinOp) \
   _llvm("llvm.intr.vp.reduce.umax", OperationKind::LLVM_INTR_VP_REDUCE_UMAX, mlir::LLVM::VPReduceUMaxOp) \
   _llvm("llvm.intr.vp.reduce.umin", OperationKind::LLVM_INTR_VP_REDUCE_UMIN, mlir::LLVM::VPReduceUMinOp) \
   _llvm("llvm.intr.vp.reduce.xor", OperationKind::LLVM_INTR_VP_REDUCE_XOR, mlir::LLVM::VPReduceXorOp) \
   _llvm("llvm.intr.vp.sdiv", OperationKind::LLVM_INTR_VP_SDIV, mlir::LLVM::VPSDivOp) \
   _llvm("llvm.intr.vp.sext", OperationKind::LLVM_INTR_VP_SEXT, mlir::LLVM::VPSExtOp) \
   _llvm("llvm.intr.vp.sitofp", OperationKind::LLVM_INTR_VP_SITOFP, mlir::LLVM::VPSIToFPOp) \
   _llvm("llvm.intr.vp.srem", OperationKind::LLVM_INTR_VP_SREM, mlir::LLVM::VPSRemOp) \
   _llvm("llvm.intr.vp.select", OperationKind::LLVM_INTR_VP_SELECT, mlir::LLVM::VPSelectMinOp) \
   _llvm("llvm.intr.vp.shl", OperationKind::LLVM_INTR_VP_SHL, mlir::LLVM::VPShlOp) \
   _llvm("llvm.intr.vp.store", OperationKind::LLVM_INTR_VP_STORE, mlir::LLVM::VPStoreOp) \
   _llvm("llvm.intr.experimental.vp.strided.load", OperationKind::LLVM_INTR_EXPERIMENTAL_VP_STRIDED_LOAD, mlir::LLVM::VPStridedLoadOp) \
   _llvm("llvm.intr.experimental.vp.strided.store", OperationKind::LLVM_INTR_EXPERIMENTAL_VP_STRIDED_STORE, mlir::LLVM::VPStridedStoreOp) \
   _llvm("llvm.intr.vp.sub", OperationKind::LLVM_INTR_VP_SUB, mlir::LLVM::VPSubOp) \
   _llvm("llvm.intr.vp.trunc", OperationKind::LLVM_INTR_VP_TRUNC, mlir::LLVM::VPTruncOp) \
   _llvm("llvm.intr.vp.udiv", OperationKind::LLVM_INTR_VP_UDIV, mlir::LLVM::VPUDivOp) \
   _llvm("llvm.intr.vp.uitofp", OperationKind::LLVM_INTR_VP_UITOFP, mlir::LLVM::VPUIToFPOp) \
   _llvm("llvm.intr.vp.urem", OperationKind::LLVM_INTR_VP_UREM, mlir::LLVM::VPURemOp) \
   _llvm("llvm.intr.vp.xor", OperationKind::LLVM_INTR_VP_XOR, mlir::LLVM::VPXorOp) \
   _llvm("llvm.intr.vp.zext", OperationKind::LLVM_INTR_VP_ZEXT, mlir::LLVM::VPZExtOp) \
   _llvm("llvm.intr.vacopy", OperationKind::LLVM_INTR_VACOPY, mlir::LLVM::VaCopyOp) \
   _llvm("llvm.intr.vaend", OperationKind::LLVM_INTR_VAEND, mlir::LLVM::VaEndOp) \
   _llvm("llvm.intr.vastart", OperationKind::LLVM_INTR_VASTART, mlir::LLVM::VaStartOp) \
   _llvm("llvm.intr.var.annotation", OperationKind::LLVM_INTR_VAR_ANNOTATION, mlir::LLVM::VarAnnotation) \
   _llvm("llvm.intr.masked.compressstore", OperationKind::LLVM_INTR_MASKED_COMPRESSSTORE, mlir::LLVM::masked_compressstore) \
   _llvm("llvm.intr.masked.expandload", OperationKind::LLVM_INTR_MASKED_EXPANDLOAD, mlir::LLVM::masked_expandload) \
   _llvm("llvm.intr.masked.gather", OperationKind::LLVM_INTR_MASKED_GATHER, mlir::LLVM::masked_gather) \
   _llvm("llvm.intr.masked.scatter", OperationKind::LLVM_INTR_MASKED_SCATTER, mlir::LLVM::masked_scatter) \
   _llvm("llvm.intr.vector.extract", OperationKind::LLVM_INTR_VECTOR_EXTRACT, mlir::LLVM::vector_extract) \
   _llvm("llvm.intr.vector.insert", OperationKind::LLVM_INTR_VECTOR_INSERT, mlir::LLVM::vector_insert) \
   _llvm("llvm.intr.vector.reduce.add", OperationKind::LLVM_INTR_VECTOR_REDUCE_ADD, mlir::LLVM::vector_reduce_add) \
   _llvm("llvm.intr.vector.reduce.and", OperationKind::LLVM_INTR_VECTOR_REDUCE_AND, mlir::LLVM::vector_reduce_and) \
   _llvm("llvm.intr.vector.reduce.fadd", OperationKind::LLVM_INTR_VECTOR_REDUCE_FADD, mlir::LLVM::vector_reduce_fadd) \
   _llvm("llvm.intr.vector.reduce.fmax", OperationKind::LLVM_INTR_VECTOR_REDUCE_FMAX, mlir::LLVM::vector_reduce_fmax) \
   _llvm("llvm.intr.vector.reduce.fmaximum", OperationKind::LLVM_INTR_VECTOR_REDUCE_FMAXIMUM, mlir::LLVM::vector_reduce_fmaximum) \
   _llvm("llvm.intr.vector.reduce.fmin", OperationKind::LLVM_INTR_VECTOR_REDUCE_FMIN, mlir::LLVM::vector_reduce_fmin) \
   _llvm("llvm.intr.vector.reduce.fminimum", OperationKind::LLVM_INTR_VECTOR_REDUCE_FMINIMUM, mlir::LLVM::vector_reduce_fminimum) \
   _llvm("llvm.intr.vector.reduce.fmul", OperationKind::LLVM_INTR_VECTOR_REDUCE_FMUL, mlir::LLVM::vector_reduce_fmul) \
   _llvm("llvm.intr.vector.reduce.mul", OperationKind::LLVM_INTR_VECTOR_REDUCE_MUL, mlir::LLVM::vector_reduce_mul) \
   _llvm("llvm.intr.vector.reduce.or", OperationKind::LLVM_INTR_VECTOR_REDUCE_OR, mlir::LLVM::vector_reduce_or) \
   _llvm("llvm.intr.vector.reduce.smax", OperationKind::LLVM_INTR_VECTOR_REDUCE_SMAX, mlir::LLVM::vector_reduce_smax) \
   _llvm("llvm.intr.vector.reduce.smin", OperationKind::LLVM_INTR_VECTOR_REDUCE_SMIN, mlir::LLVM::vector_reduce_smin) \
   _llvm("llvm.intr.vector.reduce.umax", OperationKind::LLVM_INTR_VECTOR_REDUCE_UMAX, mlir::LLVM::vector_reduce_umax) \
   _llvm("llvm.intr.vector.reduce.umin", OperationKind::LLVM_INTR_VECTOR_REDUCE_UMIN, mlir::LLVM::vector_reduce_umin) \
   _llvm("llvm.intr.vector.reduce.xor", OperationKind::LLVM_INTR_VECTOR_REDUCE_XOR, mlir::LLVM::vector_reduce_xor) \
   _llvm("llvm.intr.vscale", OperationKind::LLVM_INTR_VSCALE, mlir::LLVM::vscale) \
   _memref("memref.assume_alignment", OperationKind::MEMREF_ASSUME_ALIGNMENT, mlir::memref::AssumeAlignmentOp) \
   _memref("memref.atomic_rmw", OperationKind::MEMREF_ATOMIC_RMW, mlir::memref::AtomicRMWOp) \
   _memref("memref.atomic_yield", OperationKind::MEMREF_ATOMIC_YIELD, mlir::memref::AtomicYieldOp) \
   _memref("memref.copy", OperationKind::MEMREF_COPY, mlir::memref::CopyOp) \
   _memref("memref.generic_atomic_rmw", OperationKind::MEMREF_GENERIC_ATOMIC_RMW, mlir::memref::GenericAtomicRMWOp) \
   _memref("memref.load", OperationKind::MEMREF_LOAD, mlir::memref::LoadOp) \
   _memref("memref.alloc", OperationKind::MEMREF_ALLOC, mlir::memref::AllocOp) \
   _memref("memref.alloca", OperationKind::MEMREF_ALLOCA, mlir::memref::AllocaOp) \
   _memref("memref.alloca_scope", OperationKind::MEMREF_ALLOCA_SCOPE, mlir::memref::AllocaScopeOp) \
   _memref("memref.alloca_scope.return", OperationKind::MEMREF_ALLOCA_SCOPE_RETURN, mlir::memref::AllocaScopeReturnOp) \
   _memref("memref.cast", OperationKind::MEMREF_CAST, mlir::memref::CastOp) \
   _memref("memref.collapse_shape", OperationKind::MEMREF_COLLAPSE_SHAPE, mlir::memref::CollapseShapeOp) \
   _memref("memref.dealloc", OperationKind::MEMREF_DEALLOC, mlir::memref::DeallocOp) \
   _memref("memref.dim", OperationKind::MEMREF_DIM, mlir::memref::DimOp) \
   _memref("memref.dma_start", OperationKind::MEMREF_DMA_START, mlir::memref::DmaStartOp) \
   _memref("memref.dma_wait", OperationKind::MEMREF_DMA_WAIT, mlir::memref::DmaWaitOp) \
   _memref("memref.expand_shape", OperationKind::MEMREF_EXPAND_SHAPE, mlir::memref::ExpandShapeOp) \
   _memref("memref.extract_aligned_pointer_as_index", OperationKind::MEMREF_EXTRACT_ALIGNED_POINTER_AS_INDEX, mlir::memref::ExtractAlignedPointerAsIndexOp) \
   _memref("memref.extract_strided_metadata", OperationKind::MEMREF_EXTRACT_STRIDED_METADATA, mlir::memref::ExtractStridedMetadataOp) \
   _memref("memref.get_global", OperationKind::MEMREF_GET_GLOBAL, mlir::memref::GetGlobalOp) \
   _memref("memref.global", OperationKind::MEMREF_GLOBAL, mlir::memref::GlobalOp) \
   _memref("memref.memory_space_cast", OperationKind::MEMREF_MEMORY_SPACE_CAST, mlir::memref::MemorySpaceCastOp) \
   _memref("memref.prefetch", OperationKind::MEMREF_PREFETCH, mlir::memref::PrefetchOp) \
   _memref("memref.rank", OperationKind::MEMREF_RANK, mlir::memref::RankOp) \
   _memref("memref.realloc", OperationKind::MEMREF_REALLOC, mlir::memref::ReallocOp) \
   _memref("memref.reinterpret_cast", OperationKind::MEMREF_REINTERPRET_CAST, mlir::memref::ReinterpretCastOp) \
   _memref("memref.reshape", OperationKind::MEMREF_RESHAPE, mlir::memref::ReshapeOp) \
   _memref("memref.store", OperationKind::MEMREF_STORE, mlir::memref::StoreOp) \
   _memref("memref.transpose", OperationKind::MEMREF_TRANSPOSE, mlir::memref::TransposeOp) \
   _memref("memref.view", OperationKind::MEMREF_VIEW, mlir::memref::ViewOp) \
   _memref("memref.subview", OperationKind::MEMREF_SUBVIEW, mlir::memref::SubViewOp) \
   _abi("abi.call_args", OperationKind::ABI_CALL_ARGS, vast::abi::CallArgsOp) \
   _abi("abi.call_exec", OperationKind::ABI_CALL_EXEC, vast::abi::CallExecutionOp) \
   _abi("abi.call", OperationKind::ABI_CALL, vast::abi::CallOp) \
   _abi("abi.call_rets", OperationKind::ABI_CALL_RETS, vast::abi::CallRetsOp) \
   _abi("abi.direct", OperationKind::ABI_DIRECT, vast::abi::DirectOp) \
   _abi("abi.epilogue", OperationKind::ABI_EPILOGUE, vast::abi::EpilogueOp) \
   _abi("abi.func", OperationKind::ABI_FUNC, vast::abi::FuncOp) \
   _abi("abi.indirect", OperationKind::ABI_INDIRECT, vast::abi::IndirectOp) \
   _abi("abi.prologue", OperationKind::ABI_PROLOGUE, vast::abi::PrologueOp) \
   _abi("abi.ret_direct", OperationKind::ABI_RET_DIRECT, vast::abi::RetDirectOp) \
   _abi("abi.yield", OperationKind::ABI_YIELD, vast::abi::YieldOp) \
   _ll("ll.alloca", OperationKind::LL_ALLOCA, vast::ll::Alloca) \
   _ll("ll.arg_alloca", OperationKind::LL_ARG_ALLOCA, vast::ll::ArgAlloca) \
   _ll("ll.br", OperationKind::LL_BR, vast::ll::Br) \
   _ll("ll.concat", OperationKind::LL_CONCAT, vast::ll::Concat) \
   _ll("ll.cond_br", OperationKind::LL_COND_BR, vast::ll::CondBr) \
   _ll("ll.cond_scope_ret", OperationKind::LL_COND_SCOPE_RET, vast::ll::CondScopeRet) \
   _ll("ll.extract", OperationKind::LL_EXTRACT, vast::ll::Extract) \
   _ll("ll.initialize", OperationKind::LL_INITIALIZE, vast::ll::InitializeVar) \
   _ll("ll.inline_scope", OperationKind::LL_INLINE_SCOPE, vast::ll::InlineScope) \
   _ll("ll.load", OperationKind::LL_LOAD, vast::ll::Load) \
   _ll("ll.func", OperationKind::LL_FUNC, vast::ll::FuncOp) \
   _ll("ll.gep", OperationKind::LL_GEP, vast::ll::StructGEPOp) \
   _ll("ll.return", OperationKind::LL_RETURN, vast::ll::ReturnOp) \
   _ll("ll.scope", OperationKind::LL_SCOPE, vast::ll::Scope) \
   _ll("ll.scope_recurse", OperationKind::LL_SCOPE_RECURSE, vast::ll::ScopeRecurse) \
   _ll("ll.scope_ret", OperationKind::LL_SCOPE_RET, vast::ll::ScopeRet) \
   _ll("ll.store", OperationKind::LL_STORE, vast::ll::Store) \
   _ll("ll.subscript", OperationKind::LL_SUBSCRIPT, vast::ll::Subscript) \
   _ll("ll.uninitialized_var", OperationKind::LL_UNINITIALIZED_VAR, vast::ll::UninitializedVar) \
   _hl("hl.access", OperationKind::HL_ACCESS, vast::hl::AccessSpecifierOp) \
   _hl("hl.assign.fadd", OperationKind::HL_ASSIGN_FADD, vast::hl::AddFAssignOp) \
   _hl("hl.fadd", OperationKind::HL_FADD, vast::hl::AddFOp) \
   _hl("hl.assign.add", OperationKind::HL_ASSIGN_ADD, vast::hl::AddIAssignOp) \
   _hl("hl.add", OperationKind::HL_ADD, vast::hl::AddIOp) \
   _hl("hl.labeladdr", OperationKind::HL_LABELADDR, vast::hl::AddrLabelExpr) \
   _hl("hl.addressof", OperationKind::HL_ADDRESSOF, vast::hl::AddressOf) \
   _hl("hl.alignof.expr", OperationKind::HL_ALIGNOF_EXPR, vast::hl::AlignOfExprOp) \
   _hl("hl.alignof.type", OperationKind::HL_ALIGNOF_TYPE, vast::hl::AlignOfTypeOp) \
   _hl("hl.asm", OperationKind::HL_ASM, vast::hl::AsmOp) \
   _hl("hl.assign", OperationKind::HL_ASSIGN, vast::hl::AssignOp) \
   _hl("hl.assign.bin.ashr", OperationKind::HL_ASSIGN_BIN_ASHR, vast::hl::BinAShrAssignOp) \
   _hl("hl.bin.ashr", OperationKind::HL_BIN_ASHR, vast::hl::BinAShrOp) \
   _hl("hl.assign.bin.and", OperationKind::HL_ASSIGN_BIN_AND, vast::hl::BinAndAssignOp) \
   _hl("hl.bin.and", OperationKind::HL_BIN_AND, vast::hl::BinAndOp) \
   _hl("hl.bin.comma", OperationKind::HL_BIN_COMMA, vast::hl::BinComma) \
   _hl("hl.bin.land", OperationKind::HL_BIN_LAND, vast::hl::BinLAndOp) \
   _hl("hl.bin.lor", OperationKind::HL_BIN_LOR, vast::hl::BinLOrOp) \
   _hl("hl.assign.bin.lshr", OperationKind::HL_ASSIGN_BIN_LSHR, vast::hl::BinLShrAssignOp) \
   _hl("hl.bin.lshr", OperationKind::HL_BIN_LSHR, vast::hl::BinLShrOp) \
   _hl("hl.assign.bin.or", OperationKind::HL_ASSIGN_BIN_OR, vast::hl::BinOrAssignOp) \
   _hl("hl.bin.or", OperationKind::HL_BIN_OR, vast::hl::BinOrOp) \
   _hl("hl.assign.bin.shl", OperationKind::HL_ASSIGN_BIN_SHL, vast::hl::BinShlAssignOp) \
   _hl("hl.bin.shl", OperationKind::HL_BIN_SHL, vast::hl::BinShlOp) \
   _hl("hl.assign.bin.xor", OperationKind::HL_ASSIGN_BIN_XOR, vast::hl::BinXorAssignOp) \
   _hl("hl.bin.xor", OperationKind::HL_BIN_XOR, vast::hl::BinXorOp) \
   _hl("hl.builtin_bitcast", OperationKind::HL_BUILTIN_BITCAST, vast::hl::BuiltinBitCastOp) \
   _hl("hl.cstyle_cast", OperationKind::HL_CSTYLE_CAST, vast::hl::CStyleCastOp) \
   _hl("hl.call", OperationKind::HL_CALL, vast::hl::CallOp) \
   _hl("hl.class", OperationKind::HL_CLASS, vast::hl::ClassDeclOp) \
   _hl("hl.cmp", OperationKind::HL_CMP, vast::hl::CmpOp) \
   _hl("hl.const", OperationKind::HL_CONST, vast::hl::ConstantOp) \
   _hl("hl.base", OperationKind::HL_BASE, vast::hl::CxxBaseSpecifierOp) \
   _hl("hl.cxxstruct", OperationKind::HL_CXXSTRUCT, vast::hl::CxxStructDeclOp) \
   _hl("hl.ref", OperationKind::HL_REF, vast::hl::DeclRefOp) \
   _hl("hl.deref", OperationKind::HL_DEREF, vast::hl::Deref) \
   _hl("hl.assign.fdiv", OperationKind::HL_ASSIGN_FDIV, vast::hl::DivFAssignOp) \
   _hl("hl.fdiv", OperationKind::HL_FDIV, vast::hl::DivFOp) \
   _hl("hl.assign.sdiv", OperationKind::HL_ASSIGN_SDIV, vast::hl::DivSAssignOp) \
   _hl("hl.sdiv", OperationKind::HL_SDIV, vast::hl::DivSOp) \
   _hl("hl.assign.udiv", OperationKind::HL_ASSIGN_UDIV, vast::hl::DivUAssignOp) \
   _hl("hl.udiv", OperationKind::HL_UDIV, vast::hl::DivUOp) \
   _hl("hl.enum.const", OperationKind::HL_ENUM_CONST, vast::hl::EnumConstantOp) \
   _hl("hl.enum", OperationKind::HL_ENUM, vast::hl::EnumDeclOp) \
   _hl("hl.enumref", OperationKind::HL_ENUMREF, vast::hl::EnumRefOp) \
   _hl("hl.expr", OperationKind::HL_EXPR, vast::hl::ExprOp) \
   _hl("hl.gnu.extension", OperationKind::HL_GNU_EXTENSION, vast::hl::ExtensionOp) \
   _hl("hl.fcmp", OperationKind::HL_FCMP, vast::hl::FCmpOp) \
   _hl("hl.field", OperationKind::HL_FIELD, vast::hl::FieldDeclOp) \
   _hl("hl.funcref", OperationKind::HL_FUNCREF, vast::hl::FuncRefOp) \
   _hl("hl.globref", OperationKind::HL_GLOBREF, vast::hl::GlobalRefOp) \
   _hl("hl.break", OperationKind::HL_BREAK, vast::hl::BreakOp) \
   _hl("hl.case", OperationKind::HL_CASE, vast::hl::CaseOp) \
   _hl("hl.cond", OperationKind::HL_COND, vast::hl::CondOp) \
   _hl("hl.cond.yield", OperationKind::HL_COND_YIELD, vast::hl::CondYieldOp) \
   _hl("hl.continue", OperationKind::HL_CONTINUE, vast::hl::ContinueOp) \
   _hl("hl.default", OperationKind::HL_DEFAULT, vast::hl::DefaultOp) \
   _hl("hl.do", OperationKind::HL_DO, vast::hl::DoOp) \
   _hl("hl.empty.decl", OperationKind::HL_EMPTY_DECL, vast::hl::EmptyDeclOp) \
   _hl("hl.for", OperationKind::HL_FOR, vast::hl::ForOp) \
   _hl("hl.func", OperationKind::HL_FUNC, vast::hl::FuncOp) \
   _hl("hl.goto", OperationKind::HL_GOTO, vast::hl::GotoStmt) \
   _hl("hl.if", OperationKind::HL_IF, vast::hl::IfOp) \
   _hl("hl.label.decl", OperationKind::HL_LABEL_DECL, vast::hl::LabelDeclOp) \
   _hl("hl.label", OperationKind::HL_LABEL, vast::hl::LabelStmt) \
   _hl("hl.skip", OperationKind::HL_SKIP, vast::hl::SkipStmt) \
   _hl("hl.switch", OperationKind::HL_SWITCH, vast::hl::SwitchOp) \
   _hl("hl.type.yield", OperationKind::HL_TYPE_YIELD, vast::hl::TypeYieldOp) \
   _hl("hl.value.yield", OperationKind::HL_VALUE_YIELD, vast::hl::ValueYieldOp) \
   _hl("hl.var", OperationKind::HL_VAR, vast::hl::VarDeclOp) \
   _hl("hl.while", OperationKind::HL_WHILE, vast::hl::WhileOp) \
   _hl("hl.implicit_cast", OperationKind::HL_IMPLICIT_CAST, vast::hl::ImplicitCastOp) \
   _hl("hl.indirect_call", OperationKind::HL_INDIRECT_CALL, vast::hl::IndirectCallOp) \
   _hl("hl.initlist", OperationKind::HL_INITLIST, vast::hl::InitListExpr) \
   _hl("hl.lnot", OperationKind::HL_LNOT, vast::hl::LNotOp) \
   _hl("hl.minus", OperationKind::HL_MINUS, vast::hl::MinusOp) \
   _hl("hl.assign.fmul", OperationKind::HL_ASSIGN_FMUL, vast::hl::MulFAssignOp) \
   _hl("hl.fmul", OperationKind::HL_FMUL, vast::hl::MulFOp) \
   _hl("hl.assign.mul", OperationKind::HL_ASSIGN_MUL, vast::hl::MulIAssignOp) \
   _hl("hl.mul", OperationKind::HL_MUL, vast::hl::MulIOp) \
   _hl("hl.not", OperationKind::HL_NOT, vast::hl::NotOp) \
   _hl("hl.plus", OperationKind::HL_PLUS, vast::hl::PlusOp) \
   _hl("hl.post.dec", OperationKind::HL_POST_DEC, vast::hl::PostDecOp) \
   _hl("hl.post.inc", OperationKind::HL_POST_INC, vast::hl::PostIncOp) \
   _hl("hl.pre.dec", OperationKind::HL_PRE_DEC, vast::hl::PreDecOp) \
   _hl("hl.pre.inc", OperationKind::HL_PRE_INC, vast::hl::PreIncOp) \
   _hl("hl.predefined.expr", OperationKind::HL_PREDEFINED_EXPR, vast::hl::PredefinedExpr) \
   _hl("hl.member", OperationKind::HL_MEMBER, vast::hl::RecordMemberOp) \
   _hl("hl.assign.frem", OperationKind::HL_ASSIGN_FREM, vast::hl::RemFAssignOp) \
   _hl("hl.frem", OperationKind::HL_FREM, vast::hl::RemFOp) \
   _hl("hl.assign.srem", OperationKind::HL_ASSIGN_SREM, vast::hl::RemSAssignOp) \
   _hl("hl.srem", OperationKind::HL_SREM, vast::hl::RemSOp) \
   _hl("hl.assign.urem", OperationKind::HL_ASSIGN_UREM, vast::hl::RemUAssignOp) \
   _hl("hl.urem", OperationKind::HL_UREM, vast::hl::RemUOp) \
   _hl("hl.return", OperationKind::HL_RETURN, vast::hl::ReturnOp) \
   _hl("hl.sizeof.expr", OperationKind::HL_SIZEOF_EXPR, vast::hl::SizeOfExprOp) \
   _hl("hl.sizeof.type", OperationKind::HL_SIZEOF_TYPE, vast::hl::SizeOfTypeOp) \
   _hl("hl.stmt.expr", OperationKind::HL_STMT_EXPR, vast::hl::StmtExprOp) \
   _hl("hl.struct", OperationKind::HL_STRUCT, vast::hl::StructDeclOp) \
   _hl("hl.assign.fsub", OperationKind::HL_ASSIGN_FSUB, vast::hl::SubFAssignOp) \
   _hl("hl.fsub", OperationKind::HL_FSUB, vast::hl::SubFOp) \
   _hl("hl.assign.sub", OperationKind::HL_ASSIGN_SUB, vast::hl::SubIAssignOp) \
   _hl("hl.sub", OperationKind::HL_SUB, vast::hl::SubIOp) \
   _hl("hl.subscript", OperationKind::HL_SUBSCRIPT, vast::hl::SubscriptOp) \
   _hl("hl.this", OperationKind::HL_THIS, vast::hl::ThisOp) \
   _hl("hl.translation_unit", OperationKind::HL_TRANSLATION_UNIT, vast::hl::TranslationUnitOp) \
   _hl("hl.type", OperationKind::HL_TYPE, vast::hl::TypeDeclOp) \
   _hl("hl.typedef", OperationKind::HL_TYPEDEF, vast::hl::TypeDefOp) \
   _hl("hl.typeof.expr", OperationKind::HL_TYPEOF_EXPR, vast::hl::TypeOfExprOp) \
   _hl("hl.union", OperationKind::HL_UNION, vast::hl::UnionDeclOp) \
   _hl("hl.unreachable", OperationKind::HL_UNREACHABLE, vast::hl::UnreachableOp) \
   _hl("hl.va_arg_expr", OperationKind::HL_VA_ARG_EXPR, vast::hl::VAArgExpr) \
   _core("core.bin.land", OperationKind::CORE_BIN_LAND, vast::core::BinLAndOp) \
   _core("core.bin.lor", OperationKind::CORE_BIN_LOR, vast::core::BinLOrOp) \
   _core("core.implicit.return", OperationKind::CORE_IMPLICIT_RETURN, vast::core::ImplicitReturnOp) \
   _core("core.lazy.op", OperationKind::CORE_LAZY_OP, vast::core::LazyOp) \
   _core("core.scope", OperationKind::CORE_SCOPE, vast::core::ScopeOp) \
   _core("core.select", OperationKind::CORE_SELECT, vast::core::SelectOp) \
   _unsup("unsup.decl", OperationKind::UNSUP_DECL, vast::unsup::UnsupportedDecl) \
   _unsup("unsup.stmt", OperationKind::UNSUP_STMT, vast::unsup::UnsupportedStmt)

#define MX_IR_NUM_MLIR_OPS 431

