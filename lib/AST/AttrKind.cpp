// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AttrKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AttrKind e) {
  switch (e) {
    case AttrKind::A_ARCH64_SVE_PCS: return "A_ARCH64_SVE_PCS";
    case AttrKind::A_ARCH64_VECTOR_PCS: return "A_ARCH64_VECTOR_PCS";
    case AttrKind::AMDGPU_FLAT_WORK_GROUP_SIZE: return "AMDGPU_FLAT_WORK_GROUP_SIZE";
    case AttrKind::AMDGPU_KERNEL_CALL: return "AMDGPU_KERNEL_CALL";
    case AttrKind::AMDGPU_NUM_SGPR: return "AMDGPU_NUM_SGPR";
    case AttrKind::AMDGPU_NUM_VGPR: return "AMDGPU_NUM_VGPR";
    case AttrKind::AMDGPU_WAVES_PER_EU: return "AMDGPU_WAVES_PER_EU";
    case AttrKind::ARM_INTERRUPT: return "ARM_INTERRUPT";
    case AttrKind::AVR_INTERRUPT: return "AVR_INTERRUPT";
    case AttrKind::AVR_SIGNAL: return "AVR_SIGNAL";
    case AttrKind::ABI_TAG: return "ABI_TAG";
    case AttrKind::ACQUIRE_CAPABILITY: return "ACQUIRE_CAPABILITY";
    case AttrKind::ACQUIRE_HANDLE: return "ACQUIRE_HANDLE";
    case AttrKind::ACQUIRED_AFTER: return "ACQUIRED_AFTER";
    case AttrKind::ACQUIRED_BEFORE: return "ACQUIRED_BEFORE";
    case AttrKind::ADDRESS_SPACE: return "ADDRESS_SPACE";
    case AttrKind::ALIAS: return "ALIAS";
    case AttrKind::ALIGN_MAC68K: return "ALIGN_MAC68K";
    case AttrKind::ALIGN_NATURAL: return "ALIGN_NATURAL";
    case AttrKind::ALIGN_VALUE: return "ALIGN_VALUE";
    case AttrKind::ALIGNED: return "ALIGNED";
    case AttrKind::ALLOC_ALIGN: return "ALLOC_ALIGN";
    case AttrKind::ALLOC_SIZE: return "ALLOC_SIZE";
    case AttrKind::ALWAYS_DESTROY: return "ALWAYS_DESTROY";
    case AttrKind::ALWAYS_INLINE: return "ALWAYS_INLINE";
    case AttrKind::ANALYZER_NO_RETURN: return "ANALYZER_NO_RETURN";
    case AttrKind::ANNOTATE: return "ANNOTATE";
    case AttrKind::ANNOTATE_TYPE: return "ANNOTATE_TYPE";
    case AttrKind::ANY_X86_INTERRUPT: return "ANY_X86_INTERRUPT";
    case AttrKind::ANY_X86_NO_CALLER_SAVED_REGISTERS: return "ANY_X86_NO_CALLER_SAVED_REGISTERS";
    case AttrKind::ANY_X86_NO_CF_CHECK: return "ANY_X86_NO_CF_CHECK";
    case AttrKind::ARC_WEAKREF_UNAVAILABLE: return "ARC_WEAKREF_UNAVAILABLE";
    case AttrKind::ARGUMENT_WITH_TYPE_TAG: return "ARGUMENT_WITH_TYPE_TAG";
    case AttrKind::ARM_BUILTIN_ALIAS: return "ARM_BUILTIN_ALIAS";
    case AttrKind::ARM_IN: return "ARM_IN";
    case AttrKind::ARM_IN_OUT: return "ARM_IN_OUT";
    case AttrKind::ARM_LOCALLY_STREAMING: return "ARM_LOCALLY_STREAMING";
    case AttrKind::ARM_MVE_STRICT_POLYMORPHISM: return "ARM_MVE_STRICT_POLYMORPHISM";
    case AttrKind::ARM_NEW: return "ARM_NEW";
    case AttrKind::ARM_OUT: return "ARM_OUT";
    case AttrKind::ARM_PRESERVES: return "ARM_PRESERVES";
    case AttrKind::ARM_STREAMING: return "ARM_STREAMING";
    case AttrKind::ARM_STREAMING_COMPATIBLE: return "ARM_STREAMING_COMPATIBLE";
    case AttrKind::ARTIFICIAL: return "ARTIFICIAL";
    case AttrKind::ASM_LABEL: return "ASM_LABEL";
    case AttrKind::ASSERT_CAPABILITY: return "ASSERT_CAPABILITY";
    case AttrKind::ASSERT_EXCLUSIVE_LOCK: return "ASSERT_EXCLUSIVE_LOCK";
    case AttrKind::ASSERT_SHARED_LOCK: return "ASSERT_SHARED_LOCK";
    case AttrKind::ASSUME_ALIGNED: return "ASSUME_ALIGNED";
    case AttrKind::ASSUMPTION: return "ASSUMPTION";
    case AttrKind::AVAILABILITY: return "AVAILABILITY";
    case AttrKind::AVAILABLE_ONLY_IN_DEFAULT_EVAL_METHOD: return "AVAILABLE_ONLY_IN_DEFAULT_EVAL_METHOD";
    case AttrKind::BPF_PRESERVE_ACCESS_INDEX: return "BPF_PRESERVE_ACCESS_INDEX";
    case AttrKind::BPF_PRESERVE_STATIC_OFFSET: return "BPF_PRESERVE_STATIC_OFFSET";
    case AttrKind::BTF_DECL_TAG: return "BTF_DECL_TAG";
    case AttrKind::BTF_TYPE_TAG: return "BTF_TYPE_TAG";
    case AttrKind::BLOCKS: return "BLOCKS";
    case AttrKind::BUILTIN_ALIAS: return "BUILTIN_ALIAS";
    case AttrKind::BUILTIN: return "BUILTIN";
    case AttrKind::C11_NO_RETURN: return "C11_NO_RETURN";
    case AttrKind::C_DECL: return "C_DECL";
    case AttrKind::CF_AUDITED_TRANSFER: return "CF_AUDITED_TRANSFER";
    case AttrKind::CF_CONSUMED: return "CF_CONSUMED";
    case AttrKind::CF_GUARD: return "CF_GUARD";
    case AttrKind::CFI_CANONICAL_JUMP_TABLE: return "CFI_CANONICAL_JUMP_TABLE";
    case AttrKind::CF_RETURNS_NOT_RETAINED: return "CF_RETURNS_NOT_RETAINED";
    case AttrKind::CF_RETURNS_RETAINED: return "CF_RETURNS_RETAINED";
    case AttrKind::CF_UNKNOWN_TRANSFER: return "CF_UNKNOWN_TRANSFER";
    case AttrKind::CPU_DISPATCH: return "CPU_DISPATCH";
    case AttrKind::CPU_SPECIFIC: return "CPU_SPECIFIC";
    case AttrKind::CUDA_CONSTANT: return "CUDA_CONSTANT";
    case AttrKind::CUDA_DEVICE: return "CUDA_DEVICE";
    case AttrKind::CUDA_DEVICE_BUILTIN_SURFACE_TYPE: return "CUDA_DEVICE_BUILTIN_SURFACE_TYPE";
    case AttrKind::CUDA_DEVICE_BUILTIN_TEXTURE_TYPE: return "CUDA_DEVICE_BUILTIN_TEXTURE_TYPE";
    case AttrKind::CUDA_GLOBAL: return "CUDA_GLOBAL";
    case AttrKind::CUDA_HOST: return "CUDA_HOST";
    case AttrKind::CUDA_INVALID_TARGET: return "CUDA_INVALID_TARGET";
    case AttrKind::CUDA_LAUNCH_BOUNDS: return "CUDA_LAUNCH_BOUNDS";
    case AttrKind::CUDA_SHARED: return "CUDA_SHARED";
    case AttrKind::CXX11_NO_RETURN: return "CXX11_NO_RETURN";
    case AttrKind::CALLABLE_WHEN: return "CALLABLE_WHEN";
    case AttrKind::CALLBACK: return "CALLBACK";
    case AttrKind::CALLED_ONCE: return "CALLED_ONCE";
    case AttrKind::CAPABILITY: return "CAPABILITY";
    case AttrKind::CAPTURED_RECORD: return "CAPTURED_RECORD";
    case AttrKind::CARRIES_DEPENDENCY: return "CARRIES_DEPENDENCY";
    case AttrKind::CLEANUP: return "CLEANUP";
    case AttrKind::CMSE_NS_CALL: return "CMSE_NS_CALL";
    case AttrKind::CMSE_NS_ENTRY: return "CMSE_NS_ENTRY";
    case AttrKind::CODE_ALIGN: return "CODE_ALIGN";
    case AttrKind::CODE_MODEL: return "CODE_MODEL";
    case AttrKind::CODE_SEG: return "CODE_SEG";
    case AttrKind::COLD: return "COLD";
    case AttrKind::COMMON: return "COMMON";
    case AttrKind::CONST: return "CONST";
    case AttrKind::CONST_INIT: return "CONST_INIT";
    case AttrKind::CONSTRUCTOR: return "CONSTRUCTOR";
    case AttrKind::CONSUMABLE: return "CONSUMABLE";
    case AttrKind::CONSUMABLE_AUTO_CAST: return "CONSUMABLE_AUTO_CAST";
    case AttrKind::CONSUMABLE_SET_ON_READ: return "CONSUMABLE_SET_ON_READ";
    case AttrKind::CONVERGENT: return "CONVERGENT";
    case AttrKind::CORO_DISABLE_LIFETIME_BOUND: return "CORO_DISABLE_LIFETIME_BOUND";
    case AttrKind::CORO_LIFETIME_BOUND: return "CORO_LIFETIME_BOUND";
    case AttrKind::CORO_ONLY_DESTROY_WHEN_COMPLETE: return "CORO_ONLY_DESTROY_WHEN_COMPLETE";
    case AttrKind::CORO_RETURN_TYPE: return "CORO_RETURN_TYPE";
    case AttrKind::CORO_WRAPPER: return "CORO_WRAPPER";
    case AttrKind::COUNTED_BY: return "COUNTED_BY";
    case AttrKind::DLL_EXPORT: return "DLL_EXPORT";
    case AttrKind::DLL_EXPORT_STATIC_LOCAL: return "DLL_EXPORT_STATIC_LOCAL";
    case AttrKind::DLL_IMPORT: return "DLL_IMPORT";
    case AttrKind::DLL_IMPORT_STATIC_LOCAL: return "DLL_IMPORT_STATIC_LOCAL";
    case AttrKind::DEPRECATED: return "DEPRECATED";
    case AttrKind::DESTRUCTOR: return "DESTRUCTOR";
    case AttrKind::DIAGNOSE_AS_BUILTIN: return "DIAGNOSE_AS_BUILTIN";
    case AttrKind::DIAGNOSE_IF: return "DIAGNOSE_IF";
    case AttrKind::DISABLE_SANITIZER_INSTRUMENTATION: return "DISABLE_SANITIZER_INSTRUMENTATION";
    case AttrKind::DISABLE_TAIL_CALLS: return "DISABLE_TAIL_CALLS";
    case AttrKind::EMPTY_BASES: return "EMPTY_BASES";
    case AttrKind::ENABLE_IF: return "ENABLE_IF";
    case AttrKind::ENFORCE_TCB: return "ENFORCE_TCB";
    case AttrKind::ENFORCE_TCB_LEAF: return "ENFORCE_TCB_LEAF";
    case AttrKind::ENUM_EXTENSIBILITY: return "ENUM_EXTENSIBILITY";
    case AttrKind::ERROR: return "ERROR";
    case AttrKind::EXCLUDE_FROM_EXPLICIT_INSTANTIATION: return "EXCLUDE_FROM_EXPLICIT_INSTANTIATION";
    case AttrKind::EXCLUSIVE_TRYLOCK_FUNCTION: return "EXCLUSIVE_TRYLOCK_FUNCTION";
    case AttrKind::EXTERNAL_SOURCE_SYMBOL: return "EXTERNAL_SOURCE_SYMBOL";
    case AttrKind::FALL_THROUGH: return "FALL_THROUGH";
    case AttrKind::FAST_CALL: return "FAST_CALL";
    case AttrKind::FINAL: return "FINAL";
    case AttrKind::FLAG_ENUM: return "FLAG_ENUM";
    case AttrKind::FLATTEN: return "FLATTEN";
    case AttrKind::FORMAT_ARG: return "FORMAT_ARG";
    case AttrKind::FORMAT: return "FORMAT";
    case AttrKind::FUNCTION_RETURN_THUNKS: return "FUNCTION_RETURN_THUNKS";
    case AttrKind::GNU_INLINE: return "GNU_INLINE";
    case AttrKind::GUARDED_BY: return "GUARDED_BY";
    case AttrKind::GUARDED_VAR: return "GUARDED_VAR";
    case AttrKind::HIP_MANAGED: return "HIP_MANAGED";
    case AttrKind::HLSL_GROUP_SHARED_ADDRESS_SPACE: return "HLSL_GROUP_SHARED_ADDRESS_SPACE";
    case AttrKind::HLSL_NUM_THREADS: return "HLSL_NUM_THREADS";
    case AttrKind::HLSL_PARAM_MODIFIER: return "HLSL_PARAM_MODIFIER";
    case AttrKind::HLSL_RESOURCE: return "HLSL_RESOURCE";
    case AttrKind::HLSL_RESOURCE_BINDING: return "HLSL_RESOURCE_BINDING";
    case AttrKind::HLSLSV__DISPATCH_THREAD_ID: return "HLSLSV__DISPATCH_THREAD_ID";
    case AttrKind::HLSLSV__GROUP_INDEX: return "HLSLSV__GROUP_INDEX";
    case AttrKind::HLSL_SHADER: return "HLSL_SHADER";
    case AttrKind::HOT: return "HOT";
    case AttrKind::IB_ACTION: return "IB_ACTION";
    case AttrKind::IB_OUTLET: return "IB_OUTLET";
    case AttrKind::IB_OUTLET_COLLECTION: return "IB_OUTLET_COLLECTION";
    case AttrKind::I_FUNC: return "I_FUNC";
    case AttrKind::INIT_PRIORITY: return "INIT_PRIORITY";
    case AttrKind::INIT_SEG: return "INIT_SEG";
    case AttrKind::INTEL_OCL_BICC: return "INTEL_OCL_BICC";
    case AttrKind::INTERNAL_LINKAGE: return "INTERNAL_LINKAGE";
    case AttrKind::LTO_VISIBILITY_PUBLIC: return "LTO_VISIBILITY_PUBLIC";
    case AttrKind::LAYOUT_VERSION: return "LAYOUT_VERSION";
    case AttrKind::LEAF: return "LEAF";
    case AttrKind::LIFETIME_BOUND: return "LIFETIME_BOUND";
    case AttrKind::LIKELY: return "LIKELY";
    case AttrKind::LOADER_UNINITIALIZED: return "LOADER_UNINITIALIZED";
    case AttrKind::LOCK_RETURNED: return "LOCK_RETURNED";
    case AttrKind::LOCKS_EXCLUDED: return "LOCKS_EXCLUDED";
    case AttrKind::LOOP_HINT: return "LOOP_HINT";
    case AttrKind::M68K_INTERRUPT: return "M68K_INTERRUPT";
    case AttrKind::M68K_RTD: return "M68K_RTD";
    case AttrKind::MIG_SERVER_ROUTINE_: return "MIG_SERVER_ROUTINE_";
    case AttrKind::MSABI: return "MSABI";
    case AttrKind::MS_ALLOCATOR: return "MS_ALLOCATOR";
    case AttrKind::MS_CONSTEXPR: return "MS_CONSTEXPR";
    case AttrKind::MS_INHERITANCE: return "MS_INHERITANCE";
    case AttrKind::MS_NO_V_TABLE: return "MS_NO_V_TABLE";
    case AttrKind::MSP430_INTERRUPT: return "MSP430_INTERRUPT";
    case AttrKind::MS_STRUCT: return "MS_STRUCT";
    case AttrKind::MS_VTOR_DISP: return "MS_VTOR_DISP";
    case AttrKind::MAX_FIELD_ALIGNMENT: return "MAX_FIELD_ALIGNMENT";
    case AttrKind::MAY_ALIAS: return "MAY_ALIAS";
    case AttrKind::MAYBE_UNDEF: return "MAYBE_UNDEF";
    case AttrKind::MICRO_MIPS: return "MICRO_MIPS";
    case AttrKind::MIN_SIZE: return "MIN_SIZE";
    case AttrKind::MIN_VECTOR_WIDTH: return "MIN_VECTOR_WIDTH";
    case AttrKind::MIPS16: return "MIPS16";
    case AttrKind::MIPS_INTERRUPT: return "MIPS_INTERRUPT";
    case AttrKind::MIPS_LONG_CALL: return "MIPS_LONG_CALL";
    case AttrKind::MIPS_SHORT_CALL: return "MIPS_SHORT_CALL";
    case AttrKind::MODE: return "MODE";
    case AttrKind::MUST_TAIL: return "MUST_TAIL";
    case AttrKind::NS_CONSUMED: return "NS_CONSUMED";
    case AttrKind::NS_CONSUMES_SELF: return "NS_CONSUMES_SELF";
    case AttrKind::NS_ERROR_DOMAIN: return "NS_ERROR_DOMAIN";
    case AttrKind::NS_RETURNS_AUTORELEASED: return "NS_RETURNS_AUTORELEASED";
    case AttrKind::NS_RETURNS_NOT_RETAINED: return "NS_RETURNS_NOT_RETAINED";
    case AttrKind::NS_RETURNS_RETAINED: return "NS_RETURNS_RETAINED";
    case AttrKind::NVPTX_KERNEL: return "NVPTX_KERNEL";
    case AttrKind::NAKED: return "NAKED";
    case AttrKind::NO_ALIAS: return "NO_ALIAS";
    case AttrKind::NO_BUILTIN: return "NO_BUILTIN";
    case AttrKind::NO_COMMON: return "NO_COMMON";
    case AttrKind::NO_DEBUG: return "NO_DEBUG";
    case AttrKind::NO_DEREF: return "NO_DEREF";
    case AttrKind::NO_DESTROY: return "NO_DESTROY";
    case AttrKind::NO_DUPLICATE: return "NO_DUPLICATE";
    case AttrKind::NO_ESCAPE: return "NO_ESCAPE";
    case AttrKind::NO_INLINE: return "NO_INLINE";
    case AttrKind::NO_INSTRUMENT_FUNCTION: return "NO_INSTRUMENT_FUNCTION";
    case AttrKind::NO_MERGE: return "NO_MERGE";
    case AttrKind::NO_MICRO_MIPS: return "NO_MICRO_MIPS";
    case AttrKind::NO_MIPS16: return "NO_MIPS16";
    case AttrKind::NO_PROFILE_FUNCTION: return "NO_PROFILE_FUNCTION";
    case AttrKind::NO_RANDOMIZE_LAYOUT: return "NO_RANDOMIZE_LAYOUT";
    case AttrKind::NO_RETURN: return "NO_RETURN";
    case AttrKind::NO_SANITIZE: return "NO_SANITIZE";
    case AttrKind::NO_SPECULATIVE_LOAD_HARDENING: return "NO_SPECULATIVE_LOAD_HARDENING";
    case AttrKind::NO_SPLIT_STACK: return "NO_SPLIT_STACK";
    case AttrKind::NO_STACK_PROTECTOR: return "NO_STACK_PROTECTOR";
    case AttrKind::NO_THREAD_SAFETY_ANALYSIS: return "NO_THREAD_SAFETY_ANALYSIS";
    case AttrKind::NO_THROW: return "NO_THROW";
    case AttrKind::NO_UNIQUE_ADDRESS: return "NO_UNIQUE_ADDRESS";
    case AttrKind::NO_UWTABLE: return "NO_UWTABLE";
    case AttrKind::NON_NULL: return "NON_NULL";
    case AttrKind::NOT_TAIL_CALLED: return "NOT_TAIL_CALLED";
    case AttrKind::OMP_ALLOCATE_DECL: return "OMP_ALLOCATE_DECL";
    case AttrKind::OMP_CAPTURE_KIND: return "OMP_CAPTURE_KIND";
    case AttrKind::OMP_CAPTURE_NO_INIT: return "OMP_CAPTURE_NO_INIT";
    case AttrKind::OMP_DECLARE_SIMD_DECL: return "OMP_DECLARE_SIMD_DECL";
    case AttrKind::OMP_DECLARE_TARGET_DECL: return "OMP_DECLARE_TARGET_DECL";
    case AttrKind::OMP_DECLARE_VARIANT: return "OMP_DECLARE_VARIANT";
    case AttrKind::OMP_REFERENCED_VAR: return "OMP_REFERENCED_VAR";
    case AttrKind::OMP_THREAD_PRIVATE_DECL: return "OMP_THREAD_PRIVATE_DECL";
    case AttrKind::OS_CONSUMED: return "OS_CONSUMED";
    case AttrKind::OS_CONSUMES_THIS: return "OS_CONSUMES_THIS";
    case AttrKind::OS_RETURNS_NOT_RETAINED: return "OS_RETURNS_NOT_RETAINED";
    case AttrKind::OS_RETURNS_RETAINED: return "OS_RETURNS_RETAINED";
    case AttrKind::OS_RETURNS_RETAINED_ON_NON_ZERO: return "OS_RETURNS_RETAINED_ON_NON_ZERO";
    case AttrKind::OS_RETURNS_RETAINED_ON_ZERO: return "OS_RETURNS_RETAINED_ON_ZERO";
    case AttrKind::OBJ_C_BOXABLE: return "OBJ_C_BOXABLE";
    case AttrKind::OBJ_C_BRIDGE: return "OBJ_C_BRIDGE";
    case AttrKind::OBJ_C_BRIDGE_MUTABLE: return "OBJ_C_BRIDGE_MUTABLE";
    case AttrKind::OBJ_C_BRIDGE_RELATED: return "OBJ_C_BRIDGE_RELATED";
    case AttrKind::OBJ_C_CLASS_STUB: return "OBJ_C_CLASS_STUB";
    case AttrKind::OBJ_C_DESIGNATED_INITIALIZER: return "OBJ_C_DESIGNATED_INITIALIZER";
    case AttrKind::OBJ_C_DIRECT: return "OBJ_C_DIRECT";
    case AttrKind::OBJ_C_DIRECT_MEMBERS: return "OBJ_C_DIRECT_MEMBERS";
    case AttrKind::OBJ_C_EXCEPTION: return "OBJ_C_EXCEPTION";
    case AttrKind::OBJ_C_EXPLICIT_PROTOCOL_IMPL: return "OBJ_C_EXPLICIT_PROTOCOL_IMPL";
    case AttrKind::OBJ_C_EXTERNALLY_RETAINED: return "OBJ_C_EXTERNALLY_RETAINED";
    case AttrKind::OBJ_CGC: return "OBJ_CGC";
    case AttrKind::OBJ_C_INDEPENDENT_CLASS: return "OBJ_C_INDEPENDENT_CLASS";
    case AttrKind::OBJ_C_INERT_UNSAFE_UNRETAINED: return "OBJ_C_INERT_UNSAFE_UNRETAINED";
    case AttrKind::OBJ_C_KIND_OF: return "OBJ_C_KIND_OF";
    case AttrKind::OBJ_C_METHOD_FAMILY: return "OBJ_C_METHOD_FAMILY";
    case AttrKind::OBJ_CNS_OBJECT: return "OBJ_CNS_OBJECT";
    case AttrKind::OBJ_C_NON_LAZY_CLASS: return "OBJ_C_NON_LAZY_CLASS";
    case AttrKind::OBJ_C_NON_RUNTIME_PROTOCOL: return "OBJ_C_NON_RUNTIME_PROTOCOL";
    case AttrKind::OBJ_C_OWNERSHIP: return "OBJ_C_OWNERSHIP";
    case AttrKind::OBJ_C_PRECISE_LIFETIME: return "OBJ_C_PRECISE_LIFETIME";
    case AttrKind::OBJ_C_REQUIRES_PROPERTY_DEFS: return "OBJ_C_REQUIRES_PROPERTY_DEFS";
    case AttrKind::OBJ_C_REQUIRES_SUPER: return "OBJ_C_REQUIRES_SUPER";
    case AttrKind::OBJ_C_RETURNS_INNER_POINTER: return "OBJ_C_RETURNS_INNER_POINTER";
    case AttrKind::OBJ_C_ROOT_CLASS: return "OBJ_C_ROOT_CLASS";
    case AttrKind::OBJ_C_RUNTIME_NAME: return "OBJ_C_RUNTIME_NAME";
    case AttrKind::OBJ_C_RUNTIME_VISIBLE: return "OBJ_C_RUNTIME_VISIBLE";
    case AttrKind::OBJ_C_SUBCLASSING_RESTRICTED: return "OBJ_C_SUBCLASSING_RESTRICTED";
    case AttrKind::OPEN_CL_ACCESS: return "OPEN_CL_ACCESS";
    case AttrKind::OPEN_CL_CONSTANT_ADDRESS_SPACE: return "OPEN_CL_CONSTANT_ADDRESS_SPACE";
    case AttrKind::OPEN_CL_GENERIC_ADDRESS_SPACE: return "OPEN_CL_GENERIC_ADDRESS_SPACE";
    case AttrKind::OPEN_CL_GLOBAL_ADDRESS_SPACE: return "OPEN_CL_GLOBAL_ADDRESS_SPACE";
    case AttrKind::OPEN_CL_GLOBAL_DEVICE_ADDRESS_SPACE: return "OPEN_CL_GLOBAL_DEVICE_ADDRESS_SPACE";
    case AttrKind::OPEN_CL_GLOBAL_HOST_ADDRESS_SPACE: return "OPEN_CL_GLOBAL_HOST_ADDRESS_SPACE";
    case AttrKind::OPEN_CL_INTEL_REQD_SUB_GROUP_SIZE: return "OPEN_CL_INTEL_REQD_SUB_GROUP_SIZE";
    case AttrKind::OPEN_CL_KERNEL: return "OPEN_CL_KERNEL";
    case AttrKind::OPEN_CL_LOCAL_ADDRESS_SPACE: return "OPEN_CL_LOCAL_ADDRESS_SPACE";
    case AttrKind::OPEN_CL_PRIVATE_ADDRESS_SPACE: return "OPEN_CL_PRIVATE_ADDRESS_SPACE";
    case AttrKind::OPEN_CL_UNROLL_HINT: return "OPEN_CL_UNROLL_HINT";
    case AttrKind::OPTIMIZE_NONE: return "OPTIMIZE_NONE";
    case AttrKind::OVERLOADABLE: return "OVERLOADABLE";
    case AttrKind::OVERRIDE: return "OVERRIDE";
    case AttrKind::OWNER: return "OWNER";
    case AttrKind::OWNERSHIP: return "OWNERSHIP";
    case AttrKind::PACKED: return "PACKED";
    case AttrKind::PARAM_TYPESTATE: return "PARAM_TYPESTATE";
    case AttrKind::PASCAL: return "PASCAL";
    case AttrKind::PASS_OBJECT_SIZE: return "PASS_OBJECT_SIZE";
    case AttrKind::PATCHABLE_FUNCTION_ENTRY: return "PATCHABLE_FUNCTION_ENTRY";
    case AttrKind::PCS: return "PCS";
    case AttrKind::POINTER: return "POINTER";
    case AttrKind::PRAGMA_CLANG_BSS_SECTION: return "PRAGMA_CLANG_BSS_SECTION";
    case AttrKind::PRAGMA_CLANG_DATA_SECTION: return "PRAGMA_CLANG_DATA_SECTION";
    case AttrKind::PRAGMA_CLANG_RELRO_SECTION: return "PRAGMA_CLANG_RELRO_SECTION";
    case AttrKind::PRAGMA_CLANG_RODATA_SECTION: return "PRAGMA_CLANG_RODATA_SECTION";
    case AttrKind::PRAGMA_CLANG_TEXT_SECTION: return "PRAGMA_CLANG_TEXT_SECTION";
    case AttrKind::PREFERRED_NAME: return "PREFERRED_NAME";
    case AttrKind::PREFERRED_TYPE: return "PREFERRED_TYPE";
    case AttrKind::PRESERVE_ALL: return "PRESERVE_ALL";
    case AttrKind::PRESERVE_MOST: return "PRESERVE_MOST";
    case AttrKind::PT_GUARDED_BY: return "PT_GUARDED_BY";
    case AttrKind::PT_GUARDED_VAR: return "PT_GUARDED_VAR";
    case AttrKind::PTR32: return "PTR32";
    case AttrKind::PTR64: return "PTR64";
    case AttrKind::PURE: return "PURE";
    case AttrKind::RISCV_INTERRUPT: return "RISCV_INTERRUPT";
    case AttrKind::RANDOMIZE_LAYOUT: return "RANDOMIZE_LAYOUT";
    case AttrKind::READ_ONLY_PLACEMENT: return "READ_ONLY_PLACEMENT";
    case AttrKind::REG_CALL: return "REG_CALL";
    case AttrKind::REINITIALIZES: return "REINITIALIZES";
    case AttrKind::RELEASE_CAPABILITY: return "RELEASE_CAPABILITY";
    case AttrKind::RELEASE_HANDLE: return "RELEASE_HANDLE";
    case AttrKind::RENDER_SCRIPT_KERNEL: return "RENDER_SCRIPT_KERNEL";
    case AttrKind::REQD_WORK_GROUP_SIZE: return "REQD_WORK_GROUP_SIZE";
    case AttrKind::REQUIRES_CAPABILITY: return "REQUIRES_CAPABILITY";
    case AttrKind::RESTRICT: return "RESTRICT";
    case AttrKind::RETAIN: return "RETAIN";
    case AttrKind::RETURN_TYPESTATE: return "RETURN_TYPESTATE";
    case AttrKind::RETURNS_NON_NULL: return "RETURNS_NON_NULL";
    case AttrKind::RETURNS_TWICE: return "RETURNS_TWICE";
    case AttrKind::S_PTR: return "S_PTR";
    case AttrKind::SYCL_KERNEL: return "SYCL_KERNEL";
    case AttrKind::SYCL_SPECIAL_CLASS: return "SYCL_SPECIAL_CLASS";
    case AttrKind::SCOPED_LOCKABLE: return "SCOPED_LOCKABLE";
    case AttrKind::SECTION: return "SECTION";
    case AttrKind::SELECT_ANY: return "SELECT_ANY";
    case AttrKind::SENTINEL: return "SENTINEL";
    case AttrKind::SET_TYPESTATE: return "SET_TYPESTATE";
    case AttrKind::SHARED_TRYLOCK_FUNCTION: return "SHARED_TRYLOCK_FUNCTION";
    case AttrKind::SPECULATIVE_LOAD_HARDENING: return "SPECULATIVE_LOAD_HARDENING";
    case AttrKind::STANDALONE_DEBUG: return "STANDALONE_DEBUG";
    case AttrKind::STD_CALL: return "STD_CALL";
    case AttrKind::STRICT_FP: return "STRICT_FP";
    case AttrKind::STRICT_GUARD_STACK_CHECK: return "STRICT_GUARD_STACK_CHECK";
    case AttrKind::SUPPRESS: return "SUPPRESS";
    case AttrKind::SWIFT_ASYNC: return "SWIFT_ASYNC";
    case AttrKind::SWIFT_ASYNC_CALL: return "SWIFT_ASYNC_CALL";
    case AttrKind::SWIFT_ASYNC_CONTEXT: return "SWIFT_ASYNC_CONTEXT";
    case AttrKind::SWIFT_ASYNC_ERROR: return "SWIFT_ASYNC_ERROR";
    case AttrKind::SWIFT_ASYNC_NAME: return "SWIFT_ASYNC_NAME";
    case AttrKind::SWIFT_ATTR: return "SWIFT_ATTR";
    case AttrKind::SWIFT_BRIDGE: return "SWIFT_BRIDGE";
    case AttrKind::SWIFT_BRIDGED_TYPEDEF: return "SWIFT_BRIDGED_TYPEDEF";
    case AttrKind::SWIFT_CALL: return "SWIFT_CALL";
    case AttrKind::SWIFT_CONTEXT: return "SWIFT_CONTEXT";
    case AttrKind::SWIFT_ERROR: return "SWIFT_ERROR";
    case AttrKind::SWIFT_ERROR_RESULT: return "SWIFT_ERROR_RESULT";
    case AttrKind::SWIFT_IMPORT_AS_NON_GENERIC: return "SWIFT_IMPORT_AS_NON_GENERIC";
    case AttrKind::SWIFT_IMPORT_PROPERTY_AS_ACCESSORS: return "SWIFT_IMPORT_PROPERTY_AS_ACCESSORS";
    case AttrKind::SWIFT_INDIRECT_RESULT: return "SWIFT_INDIRECT_RESULT";
    case AttrKind::SWIFT_NAME: return "SWIFT_NAME";
    case AttrKind::SWIFT_NEW_TYPE: return "SWIFT_NEW_TYPE";
    case AttrKind::SWIFT_OBJ_C_MEMBERS: return "SWIFT_OBJ_C_MEMBERS";
    case AttrKind::SWIFT_PRIVATE: return "SWIFT_PRIVATE";
    case AttrKind::SWIFT_VERSIONED_ADDITION: return "SWIFT_VERSIONED_ADDITION";
    case AttrKind::SWIFT_VERSIONED_REMOVAL: return "SWIFT_VERSIONED_REMOVAL";
    case AttrKind::SYS_VABI: return "SYS_VABI";
    case AttrKind::TLS_MODEL: return "TLS_MODEL";
    case AttrKind::TARGET: return "TARGET";
    case AttrKind::TARGET_CLONES: return "TARGET_CLONES";
    case AttrKind::TARGET_VERSION: return "TARGET_VERSION";
    case AttrKind::TEST_TYPESTATE: return "TEST_TYPESTATE";
    case AttrKind::THIS_CALL: return "THIS_CALL";
    case AttrKind::THREAD: return "THREAD";
    case AttrKind::TRANSPARENT_UNION: return "TRANSPARENT_UNION";
    case AttrKind::TRIVIAL_ABI: return "TRIVIAL_ABI";
    case AttrKind::TRY_ACQUIRE_CAPABILITY: return "TRY_ACQUIRE_CAPABILITY";
    case AttrKind::TYPE_NON_NULL: return "TYPE_NON_NULL";
    case AttrKind::TYPE_NULL_UNSPECIFIED: return "TYPE_NULL_UNSPECIFIED";
    case AttrKind::TYPE_NULLABLE: return "TYPE_NULLABLE";
    case AttrKind::TYPE_NULLABLE_RESULT: return "TYPE_NULLABLE_RESULT";
    case AttrKind::TYPE_TAG_FOR_DATATYPE: return "TYPE_TAG_FOR_DATATYPE";
    case AttrKind::TYPE_VISIBILITY: return "TYPE_VISIBILITY";
    case AttrKind::U_PTR: return "U_PTR";
    case AttrKind::UNAVAILABLE: return "UNAVAILABLE";
    case AttrKind::UNINITIALIZED: return "UNINITIALIZED";
    case AttrKind::UNLIKELY: return "UNLIKELY";
    case AttrKind::UNSAFE_BUFFER_USAGE: return "UNSAFE_BUFFER_USAGE";
    case AttrKind::UNUSED: return "UNUSED";
    case AttrKind::USE_HANDLE: return "USE_HANDLE";
    case AttrKind::USED: return "USED";
    case AttrKind::USING_IF_EXISTS: return "USING_IF_EXISTS";
    case AttrKind::UUID: return "UUID";
    case AttrKind::VEC_RETURN: return "VEC_RETURN";
    case AttrKind::VEC_TYPE_HINT: return "VEC_TYPE_HINT";
    case AttrKind::VECTOR_CALL: return "VECTOR_CALL";
    case AttrKind::VISIBILITY: return "VISIBILITY";
    case AttrKind::WARN_UNUSED: return "WARN_UNUSED";
    case AttrKind::WARN_UNUSED_RESULT: return "WARN_UNUSED_RESULT";
    case AttrKind::WEAK: return "WEAK";
    case AttrKind::WEAK_IMPORT: return "WEAK_IMPORT";
    case AttrKind::WEAK_REF: return "WEAK_REF";
    case AttrKind::WEB_ASSEMBLY_EXPORT_NAME: return "WEB_ASSEMBLY_EXPORT_NAME";
    case AttrKind::WEB_ASSEMBLY_FUNCREF: return "WEB_ASSEMBLY_FUNCREF";
    case AttrKind::WEB_ASSEMBLY_IMPORT_MODULE: return "WEB_ASSEMBLY_IMPORT_MODULE";
    case AttrKind::WEB_ASSEMBLY_IMPORT_NAME: return "WEB_ASSEMBLY_IMPORT_NAME";
    case AttrKind::WORK_GROUP_SIZE_HINT: return "WORK_GROUP_SIZE_HINT";
    case AttrKind::X86_FORCE_ALIGN_ARG_POINTER: return "X86_FORCE_ALIGN_ARG_POINTER";
    case AttrKind::X_RAY_INSTRUMENT: return "X_RAY_INSTRUMENT";
    case AttrKind::X_RAY_LOG_ARGS: return "X_RAY_LOG_ARGS";
    case AttrKind::ZERO_CALL_USED_REGS: return "ZERO_CALL_USED_REGS";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
