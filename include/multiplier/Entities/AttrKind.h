// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class AttrKind : unsigned short {
  A_ARCH64_SVE_PCS,
  A_ARCH64_VECTOR_PCS,
  AMDGPU_FLAT_WORK_GROUP_SIZE,
  AMDGPU_KERNEL_CALL,
  AMDGPU_NUM_SGPR,
  AMDGPU_NUM_VGPR,
  AMDGPU_WAVES_PER_EU,
  ARM_INTERRUPT,
  AVR_INTERRUPT,
  AVR_SIGNAL,
  ABI_TAG,
  ACQUIRE_CAPABILITY,
  ACQUIRE_HANDLE,
  ACQUIRED_AFTER,
  ACQUIRED_BEFORE,
  ADDRESS_SPACE,
  ALIAS,
  ALIGN_MAC68K,
  ALIGN_NATURAL,
  ALIGN_VALUE,
  ALIGNED,
  ALLOC_ALIGN,
  ALLOC_SIZE,
  ALWAYS_DESTROY,
  ALWAYS_INLINE,
  ANALYZER_NO_RETURN,
  ANNOTATE,
  ANNOTATE_TYPE,
  ANY_X86_INTERRUPT,
  ANY_X86_NO_CALLER_SAVED_REGISTERS,
  ANY_X86_NO_CF_CHECK,
  ARC_WEAKREF_UNAVAILABLE,
  ARGUMENT_WITH_TYPE_TAG,
  ARM_BUILTIN_ALIAS,
  ARM_MVE_STRICT_POLYMORPHISM,
  ARM_STREAMING,
  ARTIFICIAL,
  ASM_LABEL,
  ASSERT_CAPABILITY,
  ASSERT_EXCLUSIVE_LOCK,
  ASSERT_SHARED_LOCK,
  ASSUME_ALIGNED,
  ASSUMPTION,
  AVAILABILITY,
  AVAILABLE_ONLY_IN_DEFAULT_EVAL_METHOD,
  BPF_PRESERVE_ACCESS_INDEX,
  BTF_DECL_TAG,
  BTF_TYPE_TAG,
  BLOCKS,
  BUILTIN_ALIAS,
  BUILTIN,
  C11_NO_RETURN,
  C_DECL,
  CF_AUDITED_TRANSFER,
  CF_CONSUMED,
  CF_GUARD,
  CFI_CANONICAL_JUMP_TABLE,
  CF_RETURNS_NOT_RETAINED,
  CF_RETURNS_RETAINED,
  CF_UNKNOWN_TRANSFER,
  CPU_DISPATCH,
  CPU_SPECIFIC,
  CUDA_CONSTANT,
  CUDA_DEVICE,
  CUDA_DEVICE_BUILTIN_SURFACE_TYPE,
  CUDA_DEVICE_BUILTIN_TEXTURE_TYPE,
  CUDA_GLOBAL,
  CUDA_HOST,
  CUDA_INVALID_TARGET,
  CUDA_LAUNCH_BOUNDS,
  CUDA_SHARED,
  CXX11_NO_RETURN,
  CALLABLE_WHEN,
  CALLBACK,
  CALLED_ONCE,
  CAPABILITY,
  CAPTURED_RECORD,
  CARRIES_DEPENDENCY,
  CLEANUP,
  CMSE_NS_CALL,
  CMSE_NS_ENTRY,
  CODE_SEG,
  COLD,
  COMMON,
  CONST,
  CONST_INIT,
  CONSTRUCTOR,
  CONSUMABLE,
  CONSUMABLE_AUTO_CAST,
  CONSUMABLE_SET_ON_READ,
  CONVERGENT,
  DLL_EXPORT,
  DLL_EXPORT_STATIC_LOCAL,
  DLL_IMPORT,
  DLL_IMPORT_STATIC_LOCAL,
  DEPRECATED,
  DESTRUCTOR,
  DIAGNOSE_AS_BUILTIN,
  DIAGNOSE_IF,
  DISABLE_SANITIZER_INSTRUMENTATION,
  DISABLE_TAIL_CALLS,
  EMPTY_BASES,
  ENABLE_IF,
  ENFORCE_TCB,
  ENFORCE_TCB_LEAF,
  ENUM_EXTENSIBILITY,
  ERROR,
  EXCLUDE_FROM_EXPLICIT_INSTANTIATION,
  EXCLUSIVE_TRYLOCK_FUNCTION,
  EXTERNAL_SOURCE_SYMBOL,
  FALL_THROUGH,
  FAST_CALL,
  FINAL,
  FLAG_ENUM,
  FLATTEN,
  FORMAT_ARG,
  FORMAT,
  FUNCTION_RETURN_THUNKS,
  GNU_INLINE,
  GUARDED_BY,
  GUARDED_VAR,
  HIP_MANAGED,
  HLSL_GROUP_SHARED_ADDRESS_SPACE,
  HLSL_NUM_THREADS,
  HLSL_RESOURCE,
  HLSL_RESOURCE_BINDING,
  HLSLSV__DISPATCH_THREAD_ID,
  HLSLSV__GROUP_INDEX,
  HLSL_SHADER,
  HOT,
  IB_ACTION,
  IB_OUTLET,
  IB_OUTLET_COLLECTION,
  I_FUNC,
  INIT_PRIORITY,
  INIT_SEG,
  INTEL_OCL_BICC,
  INTERNAL_LINKAGE,
  LTO_VISIBILITY_PUBLIC,
  LAYOUT_VERSION,
  LEAF,
  LIFETIME_BOUND,
  LIKELY,
  LOADER_UNINITIALIZED,
  LOCK_RETURNED,
  LOCKS_EXCLUDED,
  LOOP_HINT,
  M68K_INTERRUPT,
  MIG_SERVER_ROUTINE_,
  MSABI,
  MS_ALLOCATOR,
  MS_INHERITANCE,
  MS_NO_V_TABLE,
  MSP430_INTERRUPT,
  MS_STRUCT,
  MS_VTOR_DISP,
  MAX_FIELD_ALIGNMENT,
  MAY_ALIAS,
  MAYBE_UNDEF,
  MICRO_MIPS,
  MIN_SIZE,
  MIN_VECTOR_WIDTH,
  MIPS16,
  MIPS_INTERRUPT,
  MIPS_LONG_CALL,
  MIPS_SHORT_CALL,
  MODE,
  MUST_TAIL,
  NS_CONSUMED,
  NS_CONSUMES_SELF,
  NS_ERROR_DOMAIN,
  NS_RETURNS_AUTORELEASED,
  NS_RETURNS_NOT_RETAINED,
  NS_RETURNS_RETAINED,
  NVPTX_KERNEL,
  NAKED,
  NO_ALIAS,
  NO_BUILTIN,
  NO_COMMON,
  NO_DEBUG,
  NO_DEREF,
  NO_DESTROY,
  NO_DUPLICATE,
  NO_ESCAPE,
  NO_INLINE,
  NO_INSTRUMENT_FUNCTION,
  NO_MERGE,
  NO_MICRO_MIPS,
  NO_MIPS16,
  NO_PROFILE_FUNCTION,
  NO_RANDOMIZE_LAYOUT,
  NO_RETURN,
  NO_SANITIZE,
  NO_SPECULATIVE_LOAD_HARDENING,
  NO_SPLIT_STACK,
  NO_STACK_PROTECTOR,
  NO_THREAD_SAFETY_ANALYSIS,
  NO_THROW,
  NO_UNIQUE_ADDRESS,
  NO_UWTABLE,
  NON_NULL,
  NOT_TAIL_CALLED,
  OMP_ALLOCATE_DECL,
  OMP_CAPTURE_KIND,
  OMP_CAPTURE_NO_INIT,
  OMP_DECLARE_SIMD_DECL,
  OMP_DECLARE_TARGET_DECL,
  OMP_DECLARE_VARIANT,
  OMP_REFERENCED_VAR,
  OMP_THREAD_PRIVATE_DECL,
  OS_CONSUMED,
  OS_CONSUMES_THIS,
  OS_RETURNS_NOT_RETAINED,
  OS_RETURNS_RETAINED,
  OS_RETURNS_RETAINED_ON_NON_ZERO,
  OS_RETURNS_RETAINED_ON_ZERO,
  OBJ_C_BOXABLE,
  OBJ_C_BRIDGE,
  OBJ_C_BRIDGE_MUTABLE,
  OBJ_C_BRIDGE_RELATED,
  OBJ_C_CLASS_STUB,
  OBJ_C_DESIGNATED_INITIALIZER,
  OBJ_C_DIRECT,
  OBJ_C_DIRECT_MEMBERS,
  OBJ_C_EXCEPTION,
  OBJ_C_EXPLICIT_PROTOCOL_IMPL,
  OBJ_C_EXTERNALLY_RETAINED,
  OBJ_CGC,
  OBJ_C_INDEPENDENT_CLASS,
  OBJ_C_INERT_UNSAFE_UNRETAINED,
  OBJ_C_KIND_OF,
  OBJ_C_METHOD_FAMILY,
  OBJ_CNS_OBJECT,
  OBJ_C_NON_LAZY_CLASS,
  OBJ_C_NON_RUNTIME_PROTOCOL,
  OBJ_C_OWNERSHIP,
  OBJ_C_PRECISE_LIFETIME,
  OBJ_C_REQUIRES_PROPERTY_DEFS,
  OBJ_C_REQUIRES_SUPER,
  OBJ_C_RETURNS_INNER_POINTER,
  OBJ_C_ROOT_CLASS,
  OBJ_C_RUNTIME_NAME,
  OBJ_C_RUNTIME_VISIBLE,
  OBJ_C_SUBCLASSING_RESTRICTED,
  OPEN_CL_ACCESS,
  OPEN_CL_CONSTANT_ADDRESS_SPACE,
  OPEN_CL_GENERIC_ADDRESS_SPACE,
  OPEN_CL_GLOBAL_ADDRESS_SPACE,
  OPEN_CL_GLOBAL_DEVICE_ADDRESS_SPACE,
  OPEN_CL_GLOBAL_HOST_ADDRESS_SPACE,
  OPEN_CL_INTEL_REQD_SUB_GROUP_SIZE,
  OPEN_CL_KERNEL,
  OPEN_CL_LOCAL_ADDRESS_SPACE,
  OPEN_CL_PRIVATE_ADDRESS_SPACE,
  OPEN_CL_UNROLL_HINT,
  OPTIMIZE_NONE,
  OVERLOADABLE,
  OVERRIDE,
  OWNER,
  OWNERSHIP,
  PACKED,
  PARAM_TYPESTATE,
  PASCAL,
  PASS_OBJECT_SIZE,
  PATCHABLE_FUNCTION_ENTRY,
  PCS,
  POINTER,
  PRAGMA_CLANG_BSS_SECTION,
  PRAGMA_CLANG_DATA_SECTION,
  PRAGMA_CLANG_RELRO_SECTION,
  PRAGMA_CLANG_RODATA_SECTION,
  PRAGMA_CLANG_TEXT_SECTION,
  PREFERRED_NAME,
  PRESERVE_ALL,
  PRESERVE_MOST,
  PT_GUARDED_BY,
  PT_GUARDED_VAR,
  PTR32,
  PTR64,
  PURE,
  RISCV_INTERRUPT,
  RANDOMIZE_LAYOUT,
  READ_ONLY_PLACEMENT,
  REG_CALL,
  REINITIALIZES,
  RELEASE_CAPABILITY,
  RELEASE_HANDLE,
  RENDER_SCRIPT_KERNEL,
  REQD_WORK_GROUP_SIZE,
  REQUIRES_CAPABILITY,
  RESTRICT,
  RETAIN,
  RETURN_TYPESTATE,
  RETURNS_NON_NULL,
  RETURNS_TWICE,
  S_PTR,
  SYCL_KERNEL,
  SYCL_SPECIAL_CLASS,
  SCOPED_LOCKABLE,
  SECTION,
  SELECT_ANY,
  SENTINEL,
  SET_TYPESTATE,
  SHARED_TRYLOCK_FUNCTION,
  SPECULATIVE_LOAD_HARDENING,
  STANDALONE_DEBUG,
  STD_CALL,
  STRICT_FP,
  STRICT_GUARD_STACK_CHECK,
  SUPPRESS,
  SWIFT_ASYNC,
  SWIFT_ASYNC_CALL,
  SWIFT_ASYNC_CONTEXT,
  SWIFT_ASYNC_ERROR,
  SWIFT_ASYNC_NAME,
  SWIFT_ATTR,
  SWIFT_BRIDGE,
  SWIFT_BRIDGED_TYPEDEF,
  SWIFT_CALL,
  SWIFT_CONTEXT,
  SWIFT_ERROR,
  SWIFT_ERROR_RESULT,
  SWIFT_INDIRECT_RESULT,
  SWIFT_NAME,
  SWIFT_NEW_TYPE,
  SWIFT_OBJ_C_MEMBERS,
  SWIFT_PRIVATE,
  SYS_VABI,
  TLS_MODEL,
  TARGET,
  TARGET_CLONES,
  TARGET_VERSION,
  TEST_TYPESTATE,
  THIS_CALL,
  THREAD,
  TRANSPARENT_UNION,
  TRIVIAL_ABI,
  TRY_ACQUIRE_CAPABILITY,
  TYPE_NON_NULL,
  TYPE_NULL_UNSPECIFIED,
  TYPE_NULLABLE,
  TYPE_NULLABLE_RESULT,
  TYPE_TAG_FOR_DATATYPE,
  TYPE_VISIBILITY,
  U_PTR,
  UNAVAILABLE,
  UNINITIALIZED,
  UNLIKELY,
  UNSAFE_BUFFER_USAGE,
  UNUSED,
  USE_HANDLE,
  USED,
  USING_IF_EXISTS,
  UUID,
  VEC_RETURN,
  VEC_TYPE_HINT,
  VECTOR_CALL,
  VISIBILITY,
  WARN_UNUSED,
  WARN_UNUSED_RESULT,
  WEAK,
  WEAK_IMPORT,
  WEAK_REF,
  WEB_ASSEMBLY_EXPORT_NAME,
  WEB_ASSEMBLY_FUNCREF,
  WEB_ASSEMBLY_IMPORT_MODULE,
  WEB_ASSEMBLY_IMPORT_NAME,
  WORK_GROUP_SIZE_HINT,
  X86_FORCE_ALIGN_ARG_POINTER,
  X_RAY_INSTRUMENT,
  X_RAY_LOG_ARGS,
  ZERO_CALL_USED_REGS,
};

inline static const char *EnumerationName(AttrKind) {
  return "AttrKind";
}

inline static constexpr unsigned NumEnumerators(AttrKind) {
  return 372;
}

const char *EnumeratorName(AttrKind);

} // namespace mx
