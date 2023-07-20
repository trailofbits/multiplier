// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include "PASTA.h"

#include <multiplier/AST.h>

namespace mx {
DeclKind FromPasta(pasta::DeclKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DeclKind::ACCESS_SPEC;
    case 1: return DeclKind::BINDING;
    case 2: return DeclKind::BLOCK;
    case 3: return DeclKind::BUILTIN_TEMPLATE;
    case 4: return DeclKind::CXX_CONSTRUCTOR;
    case 5: return DeclKind::CXX_CONVERSION;
    case 6: return DeclKind::CXX_DEDUCTION_GUIDE;
    case 7: return DeclKind::CXX_DESTRUCTOR;
    case 8: return DeclKind::CXX_METHOD;
    case 9: return DeclKind::CXX_RECORD;
    case 10: return DeclKind::CAPTURED;
    case 11: return DeclKind::CLASS_SCOPE_FUNCTION_SPECIALIZATION;
    case 12: return DeclKind::CLASS_TEMPLATE;
    case 13: return DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION;
    case 14: return DeclKind::CLASS_TEMPLATE_SPECIALIZATION;
    case 15: return DeclKind::CONCEPT;
    case 16: return DeclKind::CONSTRUCTOR_USING_SHADOW;
    case 17: return DeclKind::DECOMPOSITION;
    case 18: return DeclKind::EMPTY;
    case 19: return DeclKind::ENUM_CONSTANT;
    case 20: return DeclKind::ENUM;
    case 21: return DeclKind::EXPORT;
    case 22: return DeclKind::EXTERN_C_CONTEXT;
    case 23: return DeclKind::FIELD;
    case 24: return DeclKind::FILE_SCOPE_ASM;
    case 25: return DeclKind::FRIEND;
    case 26: return DeclKind::FRIEND_TEMPLATE;
    case 27: return DeclKind::FUNCTION;
    case 28: return DeclKind::FUNCTION_TEMPLATE;
    case 29: return DeclKind::HLSL_BUFFER;
    case 30: return DeclKind::IMPLICIT_CONCEPT_SPECIALIZATION;
    case 31: return DeclKind::IMPLICIT_PARAM;
    case 32: return DeclKind::IMPORT;
    case 33: return DeclKind::INDIRECT_FIELD;
    case 34: return DeclKind::LABEL;
    case 35: return DeclKind::LIFETIME_EXTENDED_TEMPORARY;
    case 36: return DeclKind::LINKAGE_SPEC;
    case 37: return DeclKind::MS_GUID;
    case 38: return DeclKind::MS_PROPERTY;
    case 39: return DeclKind::NAMESPACE_ALIAS;
    case 40: return DeclKind::NAMESPACE;
    case 41: return DeclKind::NON_TYPE_TEMPLATE_PARM;
    case 42: return DeclKind::OMP_ALLOCATE;
    case 43: return DeclKind::OMP_CAPTURED_EXPR;
    case 44: return DeclKind::OMP_DECLARE_MAPPER;
    case 45: return DeclKind::OMP_DECLARE_REDUCTION;
    case 46: return DeclKind::OMP_REQUIRES;
    case 47: return DeclKind::OMP_THREAD_PRIVATE;
    case 48: return DeclKind::OBJ_C_AT_DEFS_FIELD;
    case 49: return DeclKind::OBJ_C_CATEGORY;
    case 50: return DeclKind::OBJ_C_CATEGORY_IMPL;
    case 51: return DeclKind::OBJ_C_COMPATIBLE_ALIAS;
    case 52: return DeclKind::OBJ_C_IMPLEMENTATION;
    case 53: return DeclKind::OBJ_C_INTERFACE;
    case 54: return DeclKind::OBJ_C_IVAR;
    case 55: return DeclKind::OBJ_C_METHOD;
    case 56: return DeclKind::OBJ_C_PROPERTY;
    case 57: return DeclKind::OBJ_C_PROPERTY_IMPL;
    case 58: return DeclKind::OBJ_C_PROTOCOL;
    case 59: return DeclKind::OBJ_C_TYPE_PARAM;
    case 60: return DeclKind::PARM_VAR;
    case 61: return DeclKind::PRAGMA_COMMENT;
    case 62: return DeclKind::PRAGMA_DETECT_MISMATCH;
    case 63: return DeclKind::RECORD;
    case 64: return DeclKind::REQUIRES_EXPR_BODY;
    case 65: return DeclKind::STATIC_ASSERT;
    case 66: return DeclKind::TEMPLATE_PARAM_OBJECT;
    case 67: return DeclKind::TEMPLATE_TEMPLATE_PARM;
    case 68: return DeclKind::TEMPLATE_TYPE_PARM;
    case 69: return DeclKind::TOP_LEVEL_STMT;
    case 70: return DeclKind::TRANSLATION_UNIT;
    case 71: return DeclKind::TYPE_ALIAS;
    case 72: return DeclKind::TYPE_ALIAS_TEMPLATE;
    case 73: return DeclKind::TYPEDEF;
    case 74: return DeclKind::UNNAMED_GLOBAL_CONSTANT;
    case 75: return DeclKind::UNRESOLVED_USING_IF_EXISTS;
    case 76: return DeclKind::UNRESOLVED_USING_TYPENAME;
    case 77: return DeclKind::UNRESOLVED_USING_VALUE;
    case 78: return DeclKind::USING;
    case 79: return DeclKind::USING_DIRECTIVE;
    case 80: return DeclKind::USING_ENUM;
    case 81: return DeclKind::USING_PACK;
    case 82: return DeclKind::USING_SHADOW;
    case 83: return DeclKind::VAR;
    case 84: return DeclKind::VAR_TEMPLATE;
    case 85: return DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION;
    case 86: return DeclKind::VAR_TEMPLATE_SPECIALIZATION;
    default: __builtin_unreachable();
  }
}

AttrKind FromPasta(pasta::AttrKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AttrKind::A_ARCH64_SVE_PCS;
    case 1: return AttrKind::A_ARCH64_VECTOR_PCS;
    case 2: return AttrKind::AMDGPU_FLAT_WORK_GROUP_SIZE;
    case 3: return AttrKind::AMDGPU_KERNEL_CALL;
    case 4: return AttrKind::AMDGPU_NUM_SGPR;
    case 5: return AttrKind::AMDGPU_NUM_VGPR;
    case 6: return AttrKind::AMDGPU_WAVES_PER_EU;
    case 7: return AttrKind::ARM_INTERRUPT;
    case 8: return AttrKind::AVR_INTERRUPT;
    case 9: return AttrKind::AVR_SIGNAL;
    case 10: return AttrKind::ABI_TAG;
    case 11: return AttrKind::ACQUIRE_CAPABILITY;
    case 12: return AttrKind::ACQUIRE_HANDLE;
    case 13: return AttrKind::ACQUIRED_AFTER;
    case 14: return AttrKind::ACQUIRED_BEFORE;
    case 15: return AttrKind::ADDRESS_SPACE;
    case 16: return AttrKind::ALIAS;
    case 17: return AttrKind::ALIGN_MAC68K;
    case 18: return AttrKind::ALIGN_NATURAL;
    case 19: return AttrKind::ALIGN_VALUE;
    case 20: return AttrKind::ALIGNED;
    case 21: return AttrKind::ALLOC_ALIGN;
    case 22: return AttrKind::ALLOC_SIZE;
    case 23: return AttrKind::ALWAYS_DESTROY;
    case 24: return AttrKind::ALWAYS_INLINE;
    case 25: return AttrKind::ANALYZER_NO_RETURN;
    case 26: return AttrKind::ANNOTATE;
    case 27: return AttrKind::ANNOTATE_TYPE;
    case 28: return AttrKind::ANY_X86_INTERRUPT;
    case 29: return AttrKind::ANY_X86_NO_CALLER_SAVED_REGISTERS;
    case 30: return AttrKind::ANY_X86_NO_CF_CHECK;
    case 31: return AttrKind::ARC_WEAKREF_UNAVAILABLE;
    case 32: return AttrKind::ARGUMENT_WITH_TYPE_TAG;
    case 33: return AttrKind::ARM_BUILTIN_ALIAS;
    case 34: return AttrKind::ARM_MVE_STRICT_POLYMORPHISM;
    case 35: return AttrKind::ARTIFICIAL;
    case 36: return AttrKind::ASM_LABEL;
    case 37: return AttrKind::ASSERT_CAPABILITY;
    case 38: return AttrKind::ASSERT_EXCLUSIVE_LOCK;
    case 39: return AttrKind::ASSERT_SHARED_LOCK;
    case 40: return AttrKind::ASSUME_ALIGNED;
    case 41: return AttrKind::ASSUMPTION;
    case 42: return AttrKind::AVAILABILITY;
    case 43: return AttrKind::BPF_PRESERVE_ACCESS_INDEX;
    case 44: return AttrKind::BTF_DECL_TAG;
    case 45: return AttrKind::BTF_TYPE_TAG;
    case 46: return AttrKind::BLOCKS;
    case 47: return AttrKind::BUILTIN_ALIAS;
    case 48: return AttrKind::BUILTIN;
    case 49: return AttrKind::C11_NO_RETURN;
    case 50: return AttrKind::C_DECL;
    case 51: return AttrKind::CF_AUDITED_TRANSFER;
    case 52: return AttrKind::CF_CONSUMED;
    case 53: return AttrKind::CF_GUARD;
    case 54: return AttrKind::CFI_CANONICAL_JUMP_TABLE;
    case 55: return AttrKind::CF_RETURNS_NOT_RETAINED;
    case 56: return AttrKind::CF_RETURNS_RETAINED;
    case 57: return AttrKind::CF_UNKNOWN_TRANSFER;
    case 58: return AttrKind::CPU_DISPATCH;
    case 59: return AttrKind::CPU_SPECIFIC;
    case 60: return AttrKind::CUDA_CONSTANT;
    case 61: return AttrKind::CUDA_DEVICE;
    case 62: return AttrKind::CUDA_DEVICE_BUILTIN_SURFACE_TYPE;
    case 63: return AttrKind::CUDA_DEVICE_BUILTIN_TEXTURE_TYPE;
    case 64: return AttrKind::CUDA_GLOBAL;
    case 65: return AttrKind::CUDA_HOST;
    case 66: return AttrKind::CUDA_INVALID_TARGET;
    case 67: return AttrKind::CUDA_LAUNCH_BOUNDS;
    case 68: return AttrKind::CUDA_SHARED;
    case 69: return AttrKind::CXX11_NO_RETURN;
    case 70: return AttrKind::CALLABLE_WHEN;
    case 71: return AttrKind::CALLBACK;
    case 72: return AttrKind::CALLED_ONCE;
    case 73: return AttrKind::CAPABILITY;
    case 74: return AttrKind::CAPTURED_RECORD;
    case 75: return AttrKind::CARRIES_DEPENDENCY;
    case 76: return AttrKind::CLEANUP;
    case 77: return AttrKind::CMSE_NS_CALL;
    case 78: return AttrKind::CMSE_NS_ENTRY;
    case 79: return AttrKind::CODE_SEG;
    case 80: return AttrKind::COLD;
    case 81: return AttrKind::COMMON;
    case 82: return AttrKind::CONST;
    case 83: return AttrKind::CONST_INIT;
    case 84: return AttrKind::CONSTRUCTOR;
    case 85: return AttrKind::CONSUMABLE;
    case 86: return AttrKind::CONSUMABLE_AUTO_CAST;
    case 87: return AttrKind::CONSUMABLE_SET_ON_READ;
    case 88: return AttrKind::CONVERGENT;
    case 89: return AttrKind::DLL_EXPORT;
    case 90: return AttrKind::DLL_EXPORT_STATIC_LOCAL;
    case 91: return AttrKind::DLL_IMPORT;
    case 92: return AttrKind::DLL_IMPORT_STATIC_LOCAL;
    case 93: return AttrKind::DEPRECATED;
    case 94: return AttrKind::DESTRUCTOR;
    case 95: return AttrKind::DIAGNOSE_AS_BUILTIN;
    case 96: return AttrKind::DIAGNOSE_IF;
    case 97: return AttrKind::DISABLE_SANITIZER_INSTRUMENTATION;
    case 98: return AttrKind::DISABLE_TAIL_CALLS;
    case 99: return AttrKind::EMPTY_BASES;
    case 100: return AttrKind::ENABLE_IF;
    case 101: return AttrKind::ENFORCE_TCB;
    case 102: return AttrKind::ENFORCE_TCB_LEAF;
    case 103: return AttrKind::ENUM_EXTENSIBILITY;
    case 104: return AttrKind::ERROR;
    case 105: return AttrKind::EXCLUDE_FROM_EXPLICIT_INSTANTIATION;
    case 106: return AttrKind::EXCLUSIVE_TRYLOCK_FUNCTION;
    case 107: return AttrKind::EXTERNAL_SOURCE_SYMBOL;
    case 108: return AttrKind::FALL_THROUGH;
    case 109: return AttrKind::FAST_CALL;
    case 110: return AttrKind::FINAL;
    case 111: return AttrKind::FLAG_ENUM;
    case 112: return AttrKind::FLATTEN;
    case 113: return AttrKind::FORMAT_ARG;
    case 114: return AttrKind::FORMAT;
    case 115: return AttrKind::FUNCTION_RETURN_THUNKS;
    case 116: return AttrKind::GNU_INLINE;
    case 117: return AttrKind::GUARDED_BY;
    case 118: return AttrKind::GUARDED_VAR;
    case 119: return AttrKind::HIP_MANAGED;
    case 120: return AttrKind::HLSL_GROUP_SHARED_ADDRESS_SPACE;
    case 121: return AttrKind::HLSL_NUM_THREADS;
    case 122: return AttrKind::HLSL_RESOURCE;
    case 123: return AttrKind::HLSL_RESOURCE_BINDING;
    case 124: return AttrKind::HLSLSV__DISPATCH_THREAD_ID;
    case 125: return AttrKind::HLSLSV__GROUP_INDEX;
    case 126: return AttrKind::HLSL_SHADER;
    case 127: return AttrKind::HOT;
    case 128: return AttrKind::IB_ACTION;
    case 129: return AttrKind::IB_OUTLET;
    case 130: return AttrKind::IB_OUTLET_COLLECTION;
    case 131: return AttrKind::I_FUNC;
    case 132: return AttrKind::INIT_PRIORITY;
    case 133: return AttrKind::INIT_SEG;
    case 134: return AttrKind::INTEL_OCL_BICC;
    case 135: return AttrKind::INTERNAL_LINKAGE;
    case 136: return AttrKind::LTO_VISIBILITY_PUBLIC;
    case 137: return AttrKind::LAYOUT_VERSION;
    case 138: return AttrKind::LEAF;
    case 139: return AttrKind::LIFETIME_BOUND;
    case 140: return AttrKind::LIKELY;
    case 141: return AttrKind::LOADER_UNINITIALIZED;
    case 142: return AttrKind::LOCK_RETURNED;
    case 143: return AttrKind::LOCKS_EXCLUDED;
    case 144: return AttrKind::LOOP_HINT;
    case 145: return AttrKind::M68K_INTERRUPT;
    case 146: return AttrKind::MIG_SERVER_ROUTINE_;
    case 147: return AttrKind::MSABI;
    case 148: return AttrKind::MS_ALLOCATOR;
    case 149: return AttrKind::MS_INHERITANCE;
    case 150: return AttrKind::MS_NO_V_TABLE;
    case 151: return AttrKind::MSP430_INTERRUPT;
    case 152: return AttrKind::MS_STRUCT;
    case 153: return AttrKind::MS_VTOR_DISP;
    case 154: return AttrKind::MAX_FIELD_ALIGNMENT;
    case 155: return AttrKind::MAY_ALIAS;
    case 156: return AttrKind::MAYBE_UNDEF;
    case 157: return AttrKind::MICRO_MIPS;
    case 158: return AttrKind::MIN_SIZE;
    case 159: return AttrKind::MIN_VECTOR_WIDTH;
    case 160: return AttrKind::MIPS16;
    case 161: return AttrKind::MIPS_INTERRUPT;
    case 162: return AttrKind::MIPS_LONG_CALL;
    case 163: return AttrKind::MIPS_SHORT_CALL;
    case 164: return AttrKind::MODE;
    case 165: return AttrKind::MUST_TAIL;
    case 166: return AttrKind::NS_CONSUMED;
    case 167: return AttrKind::NS_CONSUMES_SELF;
    case 168: return AttrKind::NS_ERROR_DOMAIN;
    case 169: return AttrKind::NS_RETURNS_AUTORELEASED;
    case 170: return AttrKind::NS_RETURNS_NOT_RETAINED;
    case 171: return AttrKind::NS_RETURNS_RETAINED;
    case 172: return AttrKind::NAKED;
    case 173: return AttrKind::NO_ALIAS;
    case 174: return AttrKind::NO_BUILTIN;
    case 175: return AttrKind::NO_COMMON;
    case 176: return AttrKind::NO_DEBUG;
    case 177: return AttrKind::NO_DEREF;
    case 178: return AttrKind::NO_DESTROY;
    case 179: return AttrKind::NO_DUPLICATE;
    case 180: return AttrKind::NO_ESCAPE;
    case 181: return AttrKind::NO_INLINE;
    case 182: return AttrKind::NO_INSTRUMENT_FUNCTION;
    case 183: return AttrKind::NO_MERGE;
    case 184: return AttrKind::NO_MICRO_MIPS;
    case 185: return AttrKind::NO_MIPS16;
    case 186: return AttrKind::NO_PROFILE_FUNCTION;
    case 187: return AttrKind::NO_RANDOMIZE_LAYOUT;
    case 188: return AttrKind::NO_RETURN;
    case 189: return AttrKind::NO_SANITIZE;
    case 190: return AttrKind::NO_SPECULATIVE_LOAD_HARDENING;
    case 191: return AttrKind::NO_SPLIT_STACK;
    case 192: return AttrKind::NO_STACK_PROTECTOR;
    case 193: return AttrKind::NO_THREAD_SAFETY_ANALYSIS;
    case 194: return AttrKind::NO_THROW;
    case 195: return AttrKind::NO_UNIQUE_ADDRESS;
    case 196: return AttrKind::NO_UWTABLE;
    case 197: return AttrKind::NON_NULL;
    case 198: return AttrKind::NOT_TAIL_CALLED;
    case 199: return AttrKind::OMP_ALLOCATE_DECL;
    case 200: return AttrKind::OMP_CAPTURE_KIND;
    case 201: return AttrKind::OMP_CAPTURE_NO_INIT;
    case 202: return AttrKind::OMP_DECLARE_SIMD_DECL;
    case 203: return AttrKind::OMP_DECLARE_TARGET_DECL;
    case 204: return AttrKind::OMP_DECLARE_VARIANT;
    case 205: return AttrKind::OMP_REFERENCED_VAR;
    case 206: return AttrKind::OMP_THREAD_PRIVATE_DECL;
    case 207: return AttrKind::OS_CONSUMED;
    case 208: return AttrKind::OS_CONSUMES_THIS;
    case 209: return AttrKind::OS_RETURNS_NOT_RETAINED;
    case 210: return AttrKind::OS_RETURNS_RETAINED;
    case 211: return AttrKind::OS_RETURNS_RETAINED_ON_NON_ZERO;
    case 212: return AttrKind::OS_RETURNS_RETAINED_ON_ZERO;
    case 213: return AttrKind::OBJ_C_BOXABLE;
    case 214: return AttrKind::OBJ_C_BRIDGE;
    case 215: return AttrKind::OBJ_C_BRIDGE_MUTABLE;
    case 216: return AttrKind::OBJ_C_BRIDGE_RELATED;
    case 217: return AttrKind::OBJ_C_CLASS_STUB;
    case 218: return AttrKind::OBJ_C_DESIGNATED_INITIALIZER;
    case 219: return AttrKind::OBJ_C_DIRECT;
    case 220: return AttrKind::OBJ_C_DIRECT_MEMBERS;
    case 221: return AttrKind::OBJ_C_EXCEPTION;
    case 222: return AttrKind::OBJ_C_EXPLICIT_PROTOCOL_IMPL;
    case 223: return AttrKind::OBJ_C_EXTERNALLY_RETAINED;
    case 224: return AttrKind::OBJ_CGC;
    case 225: return AttrKind::OBJ_C_INDEPENDENT_CLASS;
    case 226: return AttrKind::OBJ_C_INERT_UNSAFE_UNRETAINED;
    case 227: return AttrKind::OBJ_C_KIND_OF;
    case 228: return AttrKind::OBJ_C_METHOD_FAMILY;
    case 229: return AttrKind::OBJ_CNS_OBJECT;
    case 230: return AttrKind::OBJ_C_NON_LAZY_CLASS;
    case 231: return AttrKind::OBJ_C_NON_RUNTIME_PROTOCOL;
    case 232: return AttrKind::OBJ_C_OWNERSHIP;
    case 233: return AttrKind::OBJ_C_PRECISE_LIFETIME;
    case 234: return AttrKind::OBJ_C_REQUIRES_PROPERTY_DEFS;
    case 235: return AttrKind::OBJ_C_REQUIRES_SUPER;
    case 236: return AttrKind::OBJ_C_RETURNS_INNER_POINTER;
    case 237: return AttrKind::OBJ_C_ROOT_CLASS;
    case 238: return AttrKind::OBJ_C_RUNTIME_NAME;
    case 239: return AttrKind::OBJ_C_RUNTIME_VISIBLE;
    case 240: return AttrKind::OBJ_C_SUBCLASSING_RESTRICTED;
    case 241: return AttrKind::OPEN_CL_ACCESS;
    case 242: return AttrKind::OPEN_CL_CONSTANT_ADDRESS_SPACE;
    case 243: return AttrKind::OPEN_CL_GENERIC_ADDRESS_SPACE;
    case 244: return AttrKind::OPEN_CL_GLOBAL_ADDRESS_SPACE;
    case 245: return AttrKind::OPEN_CL_GLOBAL_DEVICE_ADDRESS_SPACE;
    case 246: return AttrKind::OPEN_CL_GLOBAL_HOST_ADDRESS_SPACE;
    case 247: return AttrKind::OPEN_CL_INTEL_REQD_SUB_GROUP_SIZE;
    case 248: return AttrKind::OPEN_CL_KERNEL;
    case 249: return AttrKind::OPEN_CL_LOCAL_ADDRESS_SPACE;
    case 250: return AttrKind::OPEN_CL_PRIVATE_ADDRESS_SPACE;
    case 251: return AttrKind::OPEN_CL_UNROLL_HINT;
    case 252: return AttrKind::OPTIMIZE_NONE;
    case 253: return AttrKind::OVERLOADABLE;
    case 254: return AttrKind::OVERRIDE;
    case 255: return AttrKind::OWNER;
    case 256: return AttrKind::OWNERSHIP;
    case 257: return AttrKind::PACKED;
    case 258: return AttrKind::PARAM_TYPESTATE;
    case 259: return AttrKind::PASCAL;
    case 260: return AttrKind::PASS_OBJECT_SIZE;
    case 261: return AttrKind::PATCHABLE_FUNCTION_ENTRY;
    case 262: return AttrKind::PCS;
    case 263: return AttrKind::POINTER;
    case 264: return AttrKind::PRAGMA_CLANG_BSS_SECTION;
    case 265: return AttrKind::PRAGMA_CLANG_DATA_SECTION;
    case 266: return AttrKind::PRAGMA_CLANG_RELRO_SECTION;
    case 267: return AttrKind::PRAGMA_CLANG_RODATA_SECTION;
    case 268: return AttrKind::PRAGMA_CLANG_TEXT_SECTION;
    case 269: return AttrKind::PREFERRED_NAME;
    case 270: return AttrKind::PRESERVE_ALL;
    case 271: return AttrKind::PRESERVE_MOST;
    case 272: return AttrKind::PT_GUARDED_BY;
    case 273: return AttrKind::PT_GUARDED_VAR;
    case 274: return AttrKind::PTR32;
    case 275: return AttrKind::PTR64;
    case 276: return AttrKind::PURE;
    case 277: return AttrKind::RISCV_INTERRUPT;
    case 278: return AttrKind::RANDOMIZE_LAYOUT;
    case 279: return AttrKind::READ_ONLY_PLACEMENT;
    case 280: return AttrKind::REG_CALL;
    case 281: return AttrKind::REINITIALIZES;
    case 282: return AttrKind::RELEASE_CAPABILITY;
    case 283: return AttrKind::RELEASE_HANDLE;
    case 284: return AttrKind::RENDER_SCRIPT_KERNEL;
    case 285: return AttrKind::REQD_WORK_GROUP_SIZE;
    case 286: return AttrKind::REQUIRES_CAPABILITY;
    case 287: return AttrKind::RESTRICT;
    case 288: return AttrKind::RETAIN;
    case 289: return AttrKind::RETURN_TYPESTATE;
    case 290: return AttrKind::RETURNS_NON_NULL;
    case 291: return AttrKind::RETURNS_TWICE;
    case 292: return AttrKind::S_PTR;
    case 293: return AttrKind::SYCL_KERNEL;
    case 294: return AttrKind::SYCL_SPECIAL_CLASS;
    case 295: return AttrKind::SCOPED_LOCKABLE;
    case 296: return AttrKind::SECTION;
    case 297: return AttrKind::SELECT_ANY;
    case 298: return AttrKind::SENTINEL;
    case 299: return AttrKind::SET_TYPESTATE;
    case 300: return AttrKind::SHARED_TRYLOCK_FUNCTION;
    case 301: return AttrKind::SPECULATIVE_LOAD_HARDENING;
    case 302: return AttrKind::STANDALONE_DEBUG;
    case 303: return AttrKind::STD_CALL;
    case 304: return AttrKind::STRICT_FP;
    case 305: return AttrKind::STRICT_GUARD_STACK_CHECK;
    case 306: return AttrKind::SUPPRESS;
    case 307: return AttrKind::SWIFT_ASYNC;
    case 308: return AttrKind::SWIFT_ASYNC_CALL;
    case 309: return AttrKind::SWIFT_ASYNC_CONTEXT;
    case 310: return AttrKind::SWIFT_ASYNC_ERROR;
    case 311: return AttrKind::SWIFT_ASYNC_NAME;
    case 312: return AttrKind::SWIFT_ATTR;
    case 313: return AttrKind::SWIFT_BRIDGE;
    case 314: return AttrKind::SWIFT_BRIDGED_TYPEDEF;
    case 315: return AttrKind::SWIFT_CALL;
    case 316: return AttrKind::SWIFT_CONTEXT;
    case 317: return AttrKind::SWIFT_ERROR;
    case 318: return AttrKind::SWIFT_ERROR_RESULT;
    case 319: return AttrKind::SWIFT_INDIRECT_RESULT;
    case 320: return AttrKind::SWIFT_NAME;
    case 321: return AttrKind::SWIFT_NEW_TYPE;
    case 322: return AttrKind::SWIFT_OBJ_C_MEMBERS;
    case 323: return AttrKind::SWIFT_PRIVATE;
    case 324: return AttrKind::SYS_VABI;
    case 325: return AttrKind::TLS_MODEL;
    case 326: return AttrKind::TARGET;
    case 327: return AttrKind::TARGET_CLONES;
    case 328: return AttrKind::TARGET_VERSION;
    case 329: return AttrKind::TEST_TYPESTATE;
    case 330: return AttrKind::THIS_CALL;
    case 331: return AttrKind::THREAD;
    case 332: return AttrKind::TRANSPARENT_UNION;
    case 333: return AttrKind::TRIVIAL_ABI;
    case 334: return AttrKind::TRY_ACQUIRE_CAPABILITY;
    case 335: return AttrKind::TYPE_NON_NULL;
    case 336: return AttrKind::TYPE_NULL_UNSPECIFIED;
    case 337: return AttrKind::TYPE_NULLABLE;
    case 338: return AttrKind::TYPE_NULLABLE_RESULT;
    case 339: return AttrKind::TYPE_TAG_FOR_DATATYPE;
    case 340: return AttrKind::TYPE_VISIBILITY;
    case 341: return AttrKind::U_PTR;
    case 342: return AttrKind::UNAVAILABLE;
    case 343: return AttrKind::UNINITIALIZED;
    case 344: return AttrKind::UNLIKELY;
    case 345: return AttrKind::UNUSED;
    case 346: return AttrKind::USE_HANDLE;
    case 347: return AttrKind::USED;
    case 348: return AttrKind::USING_IF_EXISTS;
    case 349: return AttrKind::UUID;
    case 350: return AttrKind::VEC_RETURN;
    case 351: return AttrKind::VEC_TYPE_HINT;
    case 352: return AttrKind::VECTOR_CALL;
    case 353: return AttrKind::VISIBILITY;
    case 354: return AttrKind::WARN_UNUSED;
    case 355: return AttrKind::WARN_UNUSED_RESULT;
    case 356: return AttrKind::WEAK;
    case 357: return AttrKind::WEAK_IMPORT;
    case 358: return AttrKind::WEAK_REF;
    case 359: return AttrKind::WEB_ASSEMBLY_EXPORT_NAME;
    case 360: return AttrKind::WEB_ASSEMBLY_IMPORT_MODULE;
    case 361: return AttrKind::WEB_ASSEMBLY_IMPORT_NAME;
    case 362: return AttrKind::WORK_GROUP_SIZE_HINT;
    case 363: return AttrKind::X86_FORCE_ALIGN_ARG_POINTER;
    case 364: return AttrKind::X_RAY_INSTRUMENT;
    case 365: return AttrKind::X_RAY_LOG_ARGS;
    case 366: return AttrKind::ZERO_CALL_USED_REGS;
    default: __builtin_unreachable();
  }
}

AArch64SVEPcsAttrSpelling FromPasta(pasta::AArch64SVEPcsAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AArch64SVEPcsAttrSpelling::GNU_AARCH64_SVE_PCS;
    case 1: return AArch64SVEPcsAttrSpelling::CXX11_CLANG_AARCH64_SVE_PCS;
    case 2: return AArch64SVEPcsAttrSpelling::C2X_CLANG_AARCH64_SVE_PCS;
    case 15: return AArch64SVEPcsAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AArch64VectorPcsAttrSpelling FromPasta(pasta::AArch64VectorPcsAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AArch64VectorPcsAttrSpelling::GNU_AARCH64_VECTOR_PCS;
    case 1: return AArch64VectorPcsAttrSpelling::CXX11_CLANG_AARCH64_VECTOR_PCS;
    case 2: return AArch64VectorPcsAttrSpelling::C2X_CLANG_AARCH64_VECTOR_PCS;
    case 15: return AArch64VectorPcsAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AMDGPUFlatWorkGroupSizeAttrSpelling FromPasta(pasta::AMDGPUFlatWorkGroupSizeAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AMDGPUFlatWorkGroupSizeAttrSpelling::GNU_AMDGPU_FLAT_WORK_GROUP_SIZE;
    case 1: return AMDGPUFlatWorkGroupSizeAttrSpelling::CXX11_CLANG_AMDGPU_FLAT_WORK_GROUP_SIZE;
    case 15: return AMDGPUFlatWorkGroupSizeAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AMDGPUKernelCallAttrSpelling FromPasta(pasta::AMDGPUKernelCallAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AMDGPUKernelCallAttrSpelling::GNU_AMDGPU_KERNEL;
    case 1: return AMDGPUKernelCallAttrSpelling::CXX11_CLANG_AMDGPU_KERNEL;
    case 2: return AMDGPUKernelCallAttrSpelling::C2X_CLANG_AMDGPU_KERNEL;
    case 15: return AMDGPUKernelCallAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AMDGPUNumSGPRAttrSpelling FromPasta(pasta::AMDGPUNumSGPRAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AMDGPUNumSGPRAttrSpelling::GNU_AMDGPU_NUM_SGPR;
    case 1: return AMDGPUNumSGPRAttrSpelling::CXX11_CLANG_AMDGPU_NUM_SGPR;
    case 15: return AMDGPUNumSGPRAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AMDGPUNumVGPRAttrSpelling FromPasta(pasta::AMDGPUNumVGPRAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AMDGPUNumVGPRAttrSpelling::GNU_AMDGPU_NUM_VGPR;
    case 1: return AMDGPUNumVGPRAttrSpelling::CXX11_CLANG_AMDGPU_NUM_VGPR;
    case 15: return AMDGPUNumVGPRAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AMDGPUWavesPerEUAttrSpelling FromPasta(pasta::AMDGPUWavesPerEUAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AMDGPUWavesPerEUAttrSpelling::GNU_AMDGPU_WAVES_PER_EU;
    case 1: return AMDGPUWavesPerEUAttrSpelling::CXX11_CLANG_AMDGPU_WAVES_PER_EU;
    case 15: return AMDGPUWavesPerEUAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ARMInterruptAttrInterruptType FromPasta(pasta::ARMInterruptAttrInterruptType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ARMInterruptAttrInterruptType::IRQ;
    case 1: return ARMInterruptAttrInterruptType::FIQ;
    case 2: return ARMInterruptAttrInterruptType::SWI;
    case 3: return ARMInterruptAttrInterruptType::ABORT;
    case 4: return ARMInterruptAttrInterruptType::UNDEF;
    case 5: return ARMInterruptAttrInterruptType::GENERIC;
    default: __builtin_unreachable();
  }
}

ARMInterruptAttrSpelling FromPasta(pasta::ARMInterruptAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ARMInterruptAttrSpelling::GNU_INTERRUPT;
    case 1: return ARMInterruptAttrSpelling::CXX11_GNU_INTERRUPT;
    case 2: return ARMInterruptAttrSpelling::C2X_GNU_INTERRUPT;
    case 15: return ARMInterruptAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AVRInterruptAttrSpelling FromPasta(pasta::AVRInterruptAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AVRInterruptAttrSpelling::GNU_INTERRUPT;
    case 1: return AVRInterruptAttrSpelling::CXX11_GNU_INTERRUPT;
    case 2: return AVRInterruptAttrSpelling::C2X_GNU_INTERRUPT;
    case 15: return AVRInterruptAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AVRSignalAttrSpelling FromPasta(pasta::AVRSignalAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AVRSignalAttrSpelling::GNU_SIGNAL;
    case 1: return AVRSignalAttrSpelling::CXX11_GNU_SIGNAL;
    case 2: return AVRSignalAttrSpelling::C2X_GNU_SIGNAL;
    case 15: return AVRSignalAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AbiTagAttrSpelling FromPasta(pasta::AbiTagAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AbiTagAttrSpelling::GNU_ABI_TAG;
    case 1: return AbiTagAttrSpelling::CXX11_GNU_ABI_TAG;
    case 15: return AbiTagAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AcquireCapabilityAttrSpelling FromPasta(pasta::AcquireCapabilityAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AcquireCapabilityAttrSpelling::GNU_ACQUIRE_CAPABILITY;
    case 1: return AcquireCapabilityAttrSpelling::CXX11_CLANG_ACQUIRE_CAPABILITY;
    case 2: return AcquireCapabilityAttrSpelling::GNU_ACQUIRE_SHARED_CAPABILITY;
    case 3: return AcquireCapabilityAttrSpelling::CXX11_CLANG_ACQUIRE_SHARED_CAPABILITY;
    case 4: return AcquireCapabilityAttrSpelling::GNU_EXCLUSIVE_LOCK_FUNCTION;
    case 5: return AcquireCapabilityAttrSpelling::GNU_SHARED_LOCK_FUNCTION;
    case 15: return AcquireCapabilityAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AcquireHandleAttrSpelling FromPasta(pasta::AcquireHandleAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AcquireHandleAttrSpelling::GNU_ACQUIRE_HANDLE;
    case 1: return AcquireHandleAttrSpelling::CXX11_CLANG_ACQUIRE_HANDLE;
    case 2: return AcquireHandleAttrSpelling::C2X_CLANG_ACQUIRE_HANDLE;
    case 15: return AcquireHandleAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AddressSpaceAttrSpelling FromPasta(pasta::AddressSpaceAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AddressSpaceAttrSpelling::GNU_ADDRESS_SPACE;
    case 1: return AddressSpaceAttrSpelling::CXX11_CLANG_ADDRESS_SPACE;
    case 2: return AddressSpaceAttrSpelling::C2X_CLANG_ADDRESS_SPACE;
    case 15: return AddressSpaceAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AliasAttrSpelling FromPasta(pasta::AliasAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AliasAttrSpelling::GNU_ALIAS;
    case 1: return AliasAttrSpelling::CXX11_GNU_ALIAS;
    case 2: return AliasAttrSpelling::C2X_GNU_ALIAS;
    case 15: return AliasAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AlignedAttrSpelling FromPasta(pasta::AlignedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AlignedAttrSpelling::GNU_ALIGNED;
    case 1: return AlignedAttrSpelling::CXX11_GNU_ALIGNED;
    case 2: return AlignedAttrSpelling::C2X_GNU_ALIGNED;
    case 3: return AlignedAttrSpelling::DECLSPEC_ALIGN;
    case 4: return AlignedAttrSpelling::KEYWORD_ALIGNAS;
    case 5: return AlignedAttrSpelling::KEYWORD__ALIGNAS;
    case 15: return AlignedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AllocAlignAttrSpelling FromPasta(pasta::AllocAlignAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AllocAlignAttrSpelling::GNU_ALLOC_ALIGN;
    case 1: return AllocAlignAttrSpelling::CXX11_GNU_ALLOC_ALIGN;
    case 2: return AllocAlignAttrSpelling::C2X_GNU_ALLOC_ALIGN;
    case 15: return AllocAlignAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AllocSizeAttrSpelling FromPasta(pasta::AllocSizeAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AllocSizeAttrSpelling::GNU_ALLOC_SIZE;
    case 1: return AllocSizeAttrSpelling::CXX11_GNU_ALLOC_SIZE;
    case 2: return AllocSizeAttrSpelling::C2X_GNU_ALLOC_SIZE;
    case 15: return AllocSizeAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AlwaysDestroyAttrSpelling FromPasta(pasta::AlwaysDestroyAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AlwaysDestroyAttrSpelling::GNU_ALWAYS_DESTROY;
    case 1: return AlwaysDestroyAttrSpelling::CXX11_CLANG_ALWAYS_DESTROY;
    case 15: return AlwaysDestroyAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AlwaysInlineAttrSpelling FromPasta(pasta::AlwaysInlineAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AlwaysInlineAttrSpelling::GNU_ALWAYS_INLINE;
    case 1: return AlwaysInlineAttrSpelling::CXX11_GNU_ALWAYS_INLINE;
    case 2: return AlwaysInlineAttrSpelling::C2X_GNU_ALWAYS_INLINE;
    case 3: return AlwaysInlineAttrSpelling::CXX11_CLANG_ALWAYS_INLINE;
    case 4: return AlwaysInlineAttrSpelling::C2X_CLANG_ALWAYS_INLINE;
    case 5: return AlwaysInlineAttrSpelling::KEYWORD_FORCEINLINE;
    case 15: return AlwaysInlineAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AnnotateAttrSpelling FromPasta(pasta::AnnotateAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AnnotateAttrSpelling::GNU_ANNOTATE;
    case 1: return AnnotateAttrSpelling::CXX11_CLANG_ANNOTATE;
    case 2: return AnnotateAttrSpelling::C2X_CLANG_ANNOTATE;
    case 15: return AnnotateAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AnnotateTypeAttrSpelling FromPasta(pasta::AnnotateTypeAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AnnotateTypeAttrSpelling::CXX11_CLANG_ANNOTATE_TYPE;
    case 1: return AnnotateTypeAttrSpelling::C2X_CLANG_ANNOTATE_TYPE;
    case 15: return AnnotateTypeAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AnyX86InterruptAttrSpelling FromPasta(pasta::AnyX86InterruptAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AnyX86InterruptAttrSpelling::GNU_INTERRUPT;
    case 1: return AnyX86InterruptAttrSpelling::CXX11_GNU_INTERRUPT;
    case 2: return AnyX86InterruptAttrSpelling::C2X_GNU_INTERRUPT;
    case 15: return AnyX86InterruptAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AnyX86NoCallerSavedRegistersAttrSpelling FromPasta(pasta::AnyX86NoCallerSavedRegistersAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AnyX86NoCallerSavedRegistersAttrSpelling::GNU_NO_CALLER_SAVED_REGISTERS;
    case 1: return AnyX86NoCallerSavedRegistersAttrSpelling::CXX11_GNU_NO_CALLER_SAVED_REGISTERS;
    case 2: return AnyX86NoCallerSavedRegistersAttrSpelling::C2X_GNU_NO_CALLER_SAVED_REGISTERS;
    case 15: return AnyX86NoCallerSavedRegistersAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AnyX86NoCfCheckAttrSpelling FromPasta(pasta::AnyX86NoCfCheckAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AnyX86NoCfCheckAttrSpelling::GNU_NOCF_CHECK;
    case 1: return AnyX86NoCfCheckAttrSpelling::CXX11_GNU_NOCF_CHECK;
    case 2: return AnyX86NoCfCheckAttrSpelling::C2X_GNU_NOCF_CHECK;
    case 15: return AnyX86NoCfCheckAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ArcWeakrefUnavailableAttrSpelling FromPasta(pasta::ArcWeakrefUnavailableAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ArcWeakrefUnavailableAttrSpelling::GNU_OBJC_ARC_WEAK_REFERENCE_UNAVAILABLE;
    case 1: return ArcWeakrefUnavailableAttrSpelling::CXX11_CLANG_OBJC_ARC_WEAK_REFERENCE_UNAVAILABLE;
    case 2: return ArcWeakrefUnavailableAttrSpelling::C2X_CLANG_OBJC_ARC_WEAK_REFERENCE_UNAVAILABLE;
    case 15: return ArcWeakrefUnavailableAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ArgumentWithTypeTagAttrSpelling FromPasta(pasta::ArgumentWithTypeTagAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ArgumentWithTypeTagAttrSpelling::GNU_ARGUMENT_WITH_TYPE_TAG;
    case 1: return ArgumentWithTypeTagAttrSpelling::CXX11_CLANG_ARGUMENT_WITH_TYPE_TAG;
    case 2: return ArgumentWithTypeTagAttrSpelling::C2X_CLANG_ARGUMENT_WITH_TYPE_TAG;
    case 3: return ArgumentWithTypeTagAttrSpelling::GNU_POINTER_WITH_TYPE_TAG;
    case 4: return ArgumentWithTypeTagAttrSpelling::CXX11_CLANG_POINTER_WITH_TYPE_TAG;
    case 5: return ArgumentWithTypeTagAttrSpelling::C2X_CLANG_POINTER_WITH_TYPE_TAG;
    case 15: return ArgumentWithTypeTagAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ArmBuiltinAliasAttrSpelling FromPasta(pasta::ArmBuiltinAliasAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ArmBuiltinAliasAttrSpelling::GNU_CLANG_ARM_BUILTIN_ALIAS;
    case 1: return ArmBuiltinAliasAttrSpelling::CXX11_CLANG_CLANG_ARM_BUILTIN_ALIAS;
    case 2: return ArmBuiltinAliasAttrSpelling::C2X_CLANG_CLANG_ARM_BUILTIN_ALIAS;
    case 15: return ArmBuiltinAliasAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ArmMveStrictPolymorphismAttrSpelling FromPasta(pasta::ArmMveStrictPolymorphismAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ArmMveStrictPolymorphismAttrSpelling::GNU_CLANG_ARM_MVE_STRICT_POLYMORPHISM;
    case 1: return ArmMveStrictPolymorphismAttrSpelling::CXX11_CLANG_CLANG_ARM_MVE_STRICT_POLYMORPHISM;
    case 2: return ArmMveStrictPolymorphismAttrSpelling::C2X_CLANG_CLANG_ARM_MVE_STRICT_POLYMORPHISM;
    case 15: return ArmMveStrictPolymorphismAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ArrayTypeArraySizeModifier FromPasta(pasta::ArrayTypeArraySizeModifier e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ArrayTypeArraySizeModifier::NORMAL;
    case 1: return ArrayTypeArraySizeModifier::STATIC;
    case 2: return ArrayTypeArraySizeModifier::STAR;
    default: __builtin_unreachable();
  }
}

ArtificialAttrSpelling FromPasta(pasta::ArtificialAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ArtificialAttrSpelling::GNU_ARTIFICIAL;
    case 1: return ArtificialAttrSpelling::CXX11_GNU_ARTIFICIAL;
    case 2: return ArtificialAttrSpelling::C2X_GNU_ARTIFICIAL;
    case 15: return ArtificialAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AsmLabelAttrSpelling FromPasta(pasta::AsmLabelAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AsmLabelAttrSpelling::KEYWORD_ASSEMBLY;
    case 15: return AsmLabelAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AssertCapabilityAttrSpelling FromPasta(pasta::AssertCapabilityAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AssertCapabilityAttrSpelling::GNU_ASSERT_CAPABILITY;
    case 1: return AssertCapabilityAttrSpelling::CXX11_CLANG_ASSERT_CAPABILITY;
    case 2: return AssertCapabilityAttrSpelling::GNU_ASSERT_SHARED_CAPABILITY;
    case 3: return AssertCapabilityAttrSpelling::CXX11_CLANG_ASSERT_SHARED_CAPABILITY;
    case 15: return AssertCapabilityAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AssumeAlignedAttrSpelling FromPasta(pasta::AssumeAlignedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AssumeAlignedAttrSpelling::GNU_ASSUME_ALIGNED;
    case 1: return AssumeAlignedAttrSpelling::CXX11_GNU_ASSUME_ALIGNED;
    case 2: return AssumeAlignedAttrSpelling::C2X_GNU_ASSUME_ALIGNED;
    case 15: return AssumeAlignedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AssumptionAttrSpelling FromPasta(pasta::AssumptionAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AssumptionAttrSpelling::GNU_ASSUME;
    case 1: return AssumptionAttrSpelling::CXX11_CLANG_ASSUME;
    case 2: return AssumptionAttrSpelling::C2X_CLANG_ASSUME;
    case 15: return AssumptionAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

AtomicExprAtomicOp FromPasta(pasta::AtomicExprAtomicOp e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AtomicExprAtomicOp::C11_ATOMIC_INITIALIZER;
    case 1: return AtomicExprAtomicOp::C11_ATOMIC_LOAD;
    case 2: return AtomicExprAtomicOp::C11_ATOMIC_STORE;
    case 3: return AtomicExprAtomicOp::C11_ATOMIC_EXCHANGE;
    case 4: return AtomicExprAtomicOp::C11_ATOMIC_COMPARE_EXCHANGE_STRONG;
    case 5: return AtomicExprAtomicOp::C11_ATOMIC_COMPARE_EXCHANGE_WEAK;
    case 6: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_ADD;
    case 7: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_SUB;
    case 8: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_AND;
    case 9: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_OR;
    case 10: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_XOR;
    case 11: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_NAND;
    case 12: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_MAX;
    case 13: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_MIN;
    case 14: return AtomicExprAtomicOp::ATOMIC_LOAD;
    case 15: return AtomicExprAtomicOp::ATOMIC_LOAD_N;
    case 16: return AtomicExprAtomicOp::ATOMIC_STORE;
    case 17: return AtomicExprAtomicOp::ATOMIC_STORE_N;
    case 18: return AtomicExprAtomicOp::ATOMIC_EXCHANGE;
    case 19: return AtomicExprAtomicOp::ATOMIC_EXCHANGE_N;
    case 20: return AtomicExprAtomicOp::ATOMIC_COMPARE_EXCHANGE;
    case 21: return AtomicExprAtomicOp::ATOMIC_COMPARE_EXCHANGE_N;
    case 22: return AtomicExprAtomicOp::ATOMIC_FETCH_ADD;
    case 23: return AtomicExprAtomicOp::ATOMIC_FETCH_SUB;
    case 24: return AtomicExprAtomicOp::ATOMIC_FETCH_AND;
    case 25: return AtomicExprAtomicOp::ATOMIC_FETCH_OR;
    case 26: return AtomicExprAtomicOp::ATOMIC_FETCH_XOR;
    case 27: return AtomicExprAtomicOp::ATOMIC_FETCH_NAND;
    case 28: return AtomicExprAtomicOp::ATOMIC_ADD_FETCH;
    case 29: return AtomicExprAtomicOp::ATOMIC_SUB_FETCH;
    case 30: return AtomicExprAtomicOp::ATOMIC_AND_FETCH;
    case 31: return AtomicExprAtomicOp::ATOMIC_OR_FETCH;
    case 32: return AtomicExprAtomicOp::ATOMIC_XOR_FETCH;
    case 33: return AtomicExprAtomicOp::ATOMIC_MAX_FETCH;
    case 34: return AtomicExprAtomicOp::ATOMIC_MIN_FETCH;
    case 35: return AtomicExprAtomicOp::ATOMIC_NAND_FETCH;
    case 36: return AtomicExprAtomicOp::OPENCL_ATOMIC_INITIALIZER;
    case 37: return AtomicExprAtomicOp::OPENCL_ATOMIC_LOAD;
    case 38: return AtomicExprAtomicOp::OPENCL_ATOMIC_STORE;
    case 39: return AtomicExprAtomicOp::OPENCL_ATOMIC_EXCHANGE;
    case 40: return AtomicExprAtomicOp::OPENCL_ATOMIC_COMPARE_EXCHANGE_STRONG;
    case 41: return AtomicExprAtomicOp::OPENCL_ATOMIC_COMPARE_EXCHANGE_WEAK;
    case 42: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_ADD;
    case 43: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_SUB;
    case 44: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_AND;
    case 45: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_OR;
    case 46: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_XOR;
    case 47: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_MIN;
    case 48: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_MAX;
    case 49: return AtomicExprAtomicOp::ATOMIC_FETCH_MIN;
    case 50: return AtomicExprAtomicOp::ATOMIC_FETCH_MAX;
    case 51: return AtomicExprAtomicOp::HIP_ATOMIC_LOAD;
    case 52: return AtomicExprAtomicOp::HIP_ATOMIC_STORE;
    case 53: return AtomicExprAtomicOp::HIP_ATOMIC_COMPARE_EXCHANGE_WEAK;
    case 54: return AtomicExprAtomicOp::HIP_ATOMIC_COMPARE_EXCHANGE_STRONG;
    case 55: return AtomicExprAtomicOp::HIP_ATOMIC_EXCHANGE;
    case 56: return AtomicExprAtomicOp::HIP_ATOMIC_FETCH_ADD;
    case 57: return AtomicExprAtomicOp::HIP_ATOMIC_FETCH_AND;
    case 58: return AtomicExprAtomicOp::HIP_ATOMIC_FETCH_OR;
    case 59: return AtomicExprAtomicOp::HIP_ATOMIC_FETCH_XOR;
    case 60: return AtomicExprAtomicOp::HIP_ATOMIC_FETCH_MIN;
    case 61: return AtomicExprAtomicOp::HIP_ATOMIC_FETCH_MAX;
    default: __builtin_unreachable();
  }
}

AvailabilityAttrSpelling FromPasta(pasta::AvailabilityAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AvailabilityAttrSpelling::GNU_AVAILABILITY;
    case 1: return AvailabilityAttrSpelling::CXX11_CLANG_AVAILABILITY;
    case 2: return AvailabilityAttrSpelling::C2X_CLANG_AVAILABILITY;
    case 15: return AvailabilityAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

BPFPreserveAccessIndexAttrSpelling FromPasta(pasta::BPFPreserveAccessIndexAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return BPFPreserveAccessIndexAttrSpelling::GNU_PRESERVE_ACCESS_INDEX;
    case 1: return BPFPreserveAccessIndexAttrSpelling::CXX11_CLANG_PRESERVE_ACCESS_INDEX;
    case 2: return BPFPreserveAccessIndexAttrSpelling::C2X_CLANG_PRESERVE_ACCESS_INDEX;
    case 15: return BPFPreserveAccessIndexAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

BTFDeclTagAttrSpelling FromPasta(pasta::BTFDeclTagAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return BTFDeclTagAttrSpelling::GNU_BTF_DECLARATION_TAG;
    case 1: return BTFDeclTagAttrSpelling::CXX11_CLANG_BTF_DECLARATION_TAG;
    case 2: return BTFDeclTagAttrSpelling::C2X_CLANG_BTF_DECLARATION_TAG;
    case 15: return BTFDeclTagAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

BTFTypeTagAttrSpelling FromPasta(pasta::BTFTypeTagAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return BTFTypeTagAttrSpelling::GNU_BTF_TYPE_TAG;
    case 1: return BTFTypeTagAttrSpelling::CXX11_CLANG_BTF_TYPE_TAG;
    case 2: return BTFTypeTagAttrSpelling::C2X_CLANG_BTF_TYPE_TAG;
    case 15: return BTFTypeTagAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

BlocksAttrBlockType FromPasta(pasta::BlocksAttrBlockType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return BlocksAttrBlockType::BY_REFERENCE;
    default: __builtin_unreachable();
  }
}

BlocksAttrSpelling FromPasta(pasta::BlocksAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return BlocksAttrSpelling::GNU_BLOCKS;
    case 1: return BlocksAttrSpelling::CXX11_CLANG_BLOCKS;
    case 2: return BlocksAttrSpelling::C2X_CLANG_BLOCKS;
    case 15: return BlocksAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

BuiltinAliasAttrSpelling FromPasta(pasta::BuiltinAliasAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return BuiltinAliasAttrSpelling::CXX11_CLANG_BUILTIN_ALIAS;
    case 1: return BuiltinAliasAttrSpelling::C2X_CLANG_BUILTIN_ALIAS;
    case 2: return BuiltinAliasAttrSpelling::GNU_CLANG_BUILTIN_ALIAS;
    case 15: return BuiltinAliasAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

BuiltinTypeKind FromPasta(pasta::BuiltinTypeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return BuiltinTypeKind::OCL_IMAGE_1D_RO;
    case 1: return BuiltinTypeKind::OCL_IMAGE_1D_ARRAY_RO;
    case 2: return BuiltinTypeKind::OCL_IMAGE_1D_BUFFER_RO;
    case 3: return BuiltinTypeKind::OCL_IMAGE_2D_RO;
    case 4: return BuiltinTypeKind::OCL_IMAGE_2D_ARRAY_RO;
    case 5: return BuiltinTypeKind::OCL_IMAGE_2D_DEPTH_RO;
    case 6: return BuiltinTypeKind::OCL_IMAGE_2D_ARRAY_DEPTH_RO;
    case 7: return BuiltinTypeKind::OCL_IMAGE_2D_MSAARO;
    case 8: return BuiltinTypeKind::OCL_IMAGE_2D_ARRAY_MSAARO;
    case 9: return BuiltinTypeKind::OCL_IMAGE_2D_MSAA_DEPTH_RO;
    case 10: return BuiltinTypeKind::OCL_IMAGE_2D_ARRAY_MSAA_DEPTH_RO;
    case 11: return BuiltinTypeKind::OCL_IMAGE_3D_RO;
    case 12: return BuiltinTypeKind::OCL_IMAGE_1D_WO;
    case 13: return BuiltinTypeKind::OCL_IMAGE_1D_ARRAY_WO;
    case 14: return BuiltinTypeKind::OCL_IMAGE_1D_BUFFER_WO;
    case 15: return BuiltinTypeKind::OCL_IMAGE_2D_WO;
    case 16: return BuiltinTypeKind::OCL_IMAGE_2D_ARRAY_WO;
    case 17: return BuiltinTypeKind::OCL_IMAGE_2D_DEPTH_WO;
    case 18: return BuiltinTypeKind::OCL_IMAGE_2D_ARRAY_DEPTH_WO;
    case 19: return BuiltinTypeKind::OCL_IMAGE_2D_MSAAWO;
    case 20: return BuiltinTypeKind::OCL_IMAGE_2D_ARRAY_MSAAWO;
    case 21: return BuiltinTypeKind::OCL_IMAGE_2D_MSAA_DEPTH_WO;
    case 22: return BuiltinTypeKind::OCL_IMAGE_2D_ARRAY_MSAA_DEPTH_WO;
    case 23: return BuiltinTypeKind::OCL_IMAGE_3D_WO;
    case 24: return BuiltinTypeKind::OCL_IMAGE_1D_RW;
    case 25: return BuiltinTypeKind::OCL_IMAGE_1D_ARRAY_RW;
    case 26: return BuiltinTypeKind::OCL_IMAGE_1D_BUFFER_RW;
    case 27: return BuiltinTypeKind::OCL_IMAGE_2D_RW;
    case 28: return BuiltinTypeKind::OCL_IMAGE_2D_ARRAY_RW;
    case 29: return BuiltinTypeKind::OCL_IMAGE_2D_DEPTH_RW;
    case 30: return BuiltinTypeKind::OCL_IMAGE_2D_ARRAY_DEPTH_RW;
    case 31: return BuiltinTypeKind::OCL_IMAGE_2D_MSAARW;
    case 32: return BuiltinTypeKind::OCL_IMAGE_2D_ARRAY_MSAARW;
    case 33: return BuiltinTypeKind::OCL_IMAGE_2D_MSAA_DEPTH_RW;
    case 34: return BuiltinTypeKind::OCL_IMAGE_2D_ARRAY_MSAA_DEPTH_RW;
    case 35: return BuiltinTypeKind::OCL_IMAGE_3D_RW;
    case 36: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_MCE_PAYLOAD;
    case 37: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_PAYLOAD;
    case 38: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_REF_PAYLOAD;
    case 39: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_SIC_PAYLOAD;
    case 40: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_MCE_RESULT;
    case 41: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_RESULT;
    case 42: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_REF_RESULT;
    case 43: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_SIC_RESULT;
    case 44: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_RESULT_SINGLE_REFERENCE_STREAMOUT;
    case 45: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_RESULT_DUAL_REFERENCE_STREAMOUT;
    case 46: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_SINGLE_REFERENCE_STREAMIN;
    case 47: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_DUAL_REFERENCE_STREAMIN;
    case 48: return BuiltinTypeKind::SVE_INT8;
    case 49: return BuiltinTypeKind::SVE_INT16;
    case 50: return BuiltinTypeKind::SVE_INT32;
    case 51: return BuiltinTypeKind::SVE_INT64;
    case 52: return BuiltinTypeKind::SVE_UINT8;
    case 53: return BuiltinTypeKind::SVE_UINT16;
    case 54: return BuiltinTypeKind::SVE_UINT32;
    case 55: return BuiltinTypeKind::SVE_UINT64;
    case 56: return BuiltinTypeKind::SVE_FLOAT16;
    case 57: return BuiltinTypeKind::SVE_FLOAT32;
    case 58: return BuiltinTypeKind::SVE_FLOAT64;
    case 59: return BuiltinTypeKind::SVE_B_FLOAT16;
    case 60: return BuiltinTypeKind::SVE_INT8X2;
    case 61: return BuiltinTypeKind::SVE_INT16X2;
    case 62: return BuiltinTypeKind::SVE_INT32X2;
    case 63: return BuiltinTypeKind::SVE_INT64X2;
    case 64: return BuiltinTypeKind::SVE_UINT8X2;
    case 65: return BuiltinTypeKind::SVE_UINT16X2;
    case 66: return BuiltinTypeKind::SVE_UINT32X2;
    case 67: return BuiltinTypeKind::SVE_UINT64X2;
    case 68: return BuiltinTypeKind::SVE_FLOAT16X2;
    case 69: return BuiltinTypeKind::SVE_FLOAT32X2;
    case 70: return BuiltinTypeKind::SVE_FLOAT64X2;
    case 71: return BuiltinTypeKind::SVE_B_FLOAT16X2;
    case 72: return BuiltinTypeKind::SVE_INT8X3;
    case 73: return BuiltinTypeKind::SVE_INT16X3;
    case 74: return BuiltinTypeKind::SVE_INT32X3;
    case 75: return BuiltinTypeKind::SVE_INT64X3;
    case 76: return BuiltinTypeKind::SVE_UINT8X3;
    case 77: return BuiltinTypeKind::SVE_UINT16X3;
    case 78: return BuiltinTypeKind::SVE_UINT32X3;
    case 79: return BuiltinTypeKind::SVE_UINT64X3;
    case 80: return BuiltinTypeKind::SVE_FLOAT16X3;
    case 81: return BuiltinTypeKind::SVE_FLOAT32X3;
    case 82: return BuiltinTypeKind::SVE_FLOAT64X3;
    case 83: return BuiltinTypeKind::SVE_B_FLOAT16X3;
    case 84: return BuiltinTypeKind::SVE_INT8X4;
    case 85: return BuiltinTypeKind::SVE_INT16X4;
    case 86: return BuiltinTypeKind::SVE_INT32X4;
    case 87: return BuiltinTypeKind::SVE_INT64X4;
    case 88: return BuiltinTypeKind::SVE_UINT8X4;
    case 89: return BuiltinTypeKind::SVE_UINT16X4;
    case 90: return BuiltinTypeKind::SVE_UINT32X4;
    case 91: return BuiltinTypeKind::SVE_UINT64X4;
    case 92: return BuiltinTypeKind::SVE_FLOAT16X4;
    case 93: return BuiltinTypeKind::SVE_FLOAT32X4;
    case 94: return BuiltinTypeKind::SVE_FLOAT64X4;
    case 95: return BuiltinTypeKind::SVE_B_FLOAT16X4;
    case 96: return BuiltinTypeKind::SVE_BOOLEAN;
    case 97: return BuiltinTypeKind::VECTOR_QUAD;
    case 98: return BuiltinTypeKind::VECTOR_PAIR;
    case 99: return BuiltinTypeKind::RVV_INT8MF8;
    case 100: return BuiltinTypeKind::RVV_INT8MF4;
    case 101: return BuiltinTypeKind::RVV_INT8MF2;
    case 102: return BuiltinTypeKind::RVV_INT8M1;
    case 103: return BuiltinTypeKind::RVV_INT8M2;
    case 104: return BuiltinTypeKind::RVV_INT8M4;
    case 105: return BuiltinTypeKind::RVV_INT8M8;
    case 106: return BuiltinTypeKind::RVV_UINT8MF8;
    case 107: return BuiltinTypeKind::RVV_UINT8MF4;
    case 108: return BuiltinTypeKind::RVV_UINT8MF2;
    case 109: return BuiltinTypeKind::RVV_UINT8M1;
    case 110: return BuiltinTypeKind::RVV_UINT8M2;
    case 111: return BuiltinTypeKind::RVV_UINT8M4;
    case 112: return BuiltinTypeKind::RVV_UINT8M8;
    case 113: return BuiltinTypeKind::RVV_INT16MF4;
    case 114: return BuiltinTypeKind::RVV_INT16MF2;
    case 115: return BuiltinTypeKind::RVV_INT16M1;
    case 116: return BuiltinTypeKind::RVV_INT16M2;
    case 117: return BuiltinTypeKind::RVV_INT16M4;
    case 118: return BuiltinTypeKind::RVV_INT16M8;
    case 119: return BuiltinTypeKind::RVV_UINT16MF4;
    case 120: return BuiltinTypeKind::RVV_UINT16MF2;
    case 121: return BuiltinTypeKind::RVV_UINT16M1;
    case 122: return BuiltinTypeKind::RVV_UINT16M2;
    case 123: return BuiltinTypeKind::RVV_UINT16M4;
    case 124: return BuiltinTypeKind::RVV_UINT16M8;
    case 125: return BuiltinTypeKind::RVV_INT32MF2;
    case 126: return BuiltinTypeKind::RVV_INT32M1;
    case 127: return BuiltinTypeKind::RVV_INT32M2;
    case 128: return BuiltinTypeKind::RVV_INT32M4;
    case 129: return BuiltinTypeKind::RVV_INT32M8;
    case 130: return BuiltinTypeKind::RVV_UINT32MF2;
    case 131: return BuiltinTypeKind::RVV_UINT32M1;
    case 132: return BuiltinTypeKind::RVV_UINT32M2;
    case 133: return BuiltinTypeKind::RVV_UINT32M4;
    case 134: return BuiltinTypeKind::RVV_UINT32M8;
    case 135: return BuiltinTypeKind::RVV_INT64M1;
    case 136: return BuiltinTypeKind::RVV_INT64M2;
    case 137: return BuiltinTypeKind::RVV_INT64M4;
    case 138: return BuiltinTypeKind::RVV_INT64M8;
    case 139: return BuiltinTypeKind::RVV_UINT64M1;
    case 140: return BuiltinTypeKind::RVV_UINT64M2;
    case 141: return BuiltinTypeKind::RVV_UINT64M4;
    case 142: return BuiltinTypeKind::RVV_UINT64M8;
    case 143: return BuiltinTypeKind::RVV_FLOAT16MF4;
    case 144: return BuiltinTypeKind::RVV_FLOAT16MF2;
    case 145: return BuiltinTypeKind::RVV_FLOAT16M1;
    case 146: return BuiltinTypeKind::RVV_FLOAT16M2;
    case 147: return BuiltinTypeKind::RVV_FLOAT16M4;
    case 148: return BuiltinTypeKind::RVV_FLOAT16M8;
    case 149: return BuiltinTypeKind::RVV_FLOAT32MF2;
    case 150: return BuiltinTypeKind::RVV_FLOAT32M1;
    case 151: return BuiltinTypeKind::RVV_FLOAT32M2;
    case 152: return BuiltinTypeKind::RVV_FLOAT32M4;
    case 153: return BuiltinTypeKind::RVV_FLOAT32M8;
    case 154: return BuiltinTypeKind::RVV_FLOAT64M1;
    case 155: return BuiltinTypeKind::RVV_FLOAT64M2;
    case 156: return BuiltinTypeKind::RVV_FLOAT64M4;
    case 157: return BuiltinTypeKind::RVV_FLOAT64M8;
    case 158: return BuiltinTypeKind::RVV_BOOL1;
    case 159: return BuiltinTypeKind::RVV_BOOL2;
    case 160: return BuiltinTypeKind::RVV_BOOL4;
    case 161: return BuiltinTypeKind::RVV_BOOL8;
    case 162: return BuiltinTypeKind::RVV_BOOL16;
    case 163: return BuiltinTypeKind::RVV_BOOL32;
    case 164: return BuiltinTypeKind::RVV_BOOL64;
    case 165: return BuiltinTypeKind::VOID;
    case 166: return BuiltinTypeKind::BOOLEAN;
    case 167: return BuiltinTypeKind::CHARACTER_U;
    case 168: return BuiltinTypeKind::U_CHAR;
    case 169: return BuiltinTypeKind::W_CHAR_U;
    case 170: return BuiltinTypeKind::CHAR8;
    case 171: return BuiltinTypeKind::CHAR16;
    case 172: return BuiltinTypeKind::CHAR32;
    case 173: return BuiltinTypeKind::U_SHORT;
    case 174: return BuiltinTypeKind::U_INT;
    case 175: return BuiltinTypeKind::U_LONG;
    case 176: return BuiltinTypeKind::U_LONG_LONG;
    case 177: return BuiltinTypeKind::U_INT128;
    case 178: return BuiltinTypeKind::CHARACTER_S;
    case 179: return BuiltinTypeKind::S_CHAR;
    case 180: return BuiltinTypeKind::W_CHAR_S;
    case 181: return BuiltinTypeKind::SHORT;
    case 182: return BuiltinTypeKind::INT;
    case 183: return BuiltinTypeKind::LONG;
    case 184: return BuiltinTypeKind::LONG_LONG;
    case 185: return BuiltinTypeKind::INT128;
    case 186: return BuiltinTypeKind::SHORT_ACCUM;
    case 187: return BuiltinTypeKind::ACCUM;
    case 188: return BuiltinTypeKind::LONG_ACCUM;
    case 189: return BuiltinTypeKind::U_SHORT_ACCUM;
    case 190: return BuiltinTypeKind::U_ACCUM;
    case 191: return BuiltinTypeKind::U_LONG_ACCUM;
    case 192: return BuiltinTypeKind::SHORT_FRACT;
    case 193: return BuiltinTypeKind::FRACT;
    case 194: return BuiltinTypeKind::LONG_FRACT;
    case 195: return BuiltinTypeKind::U_SHORT_FRACT;
    case 196: return BuiltinTypeKind::U_FRACT;
    case 197: return BuiltinTypeKind::U_LONG_FRACT;
    case 198: return BuiltinTypeKind::SAT_SHORT_ACCUM;
    case 199: return BuiltinTypeKind::SAT_ACCUM;
    case 200: return BuiltinTypeKind::SAT_LONG_ACCUM;
    case 201: return BuiltinTypeKind::SAT_U_SHORT_ACCUM;
    case 202: return BuiltinTypeKind::SAT_U_ACCUM;
    case 203: return BuiltinTypeKind::SAT_U_LONG_ACCUM;
    case 204: return BuiltinTypeKind::SAT_SHORT_FRACT;
    case 205: return BuiltinTypeKind::SAT_FRACT;
    case 206: return BuiltinTypeKind::SAT_LONG_FRACT;
    case 207: return BuiltinTypeKind::SAT_U_SHORT_FRACT;
    case 208: return BuiltinTypeKind::SAT_U_FRACT;
    case 209: return BuiltinTypeKind::SAT_U_LONG_FRACT;
    case 210: return BuiltinTypeKind::HALF;
    case 211: return BuiltinTypeKind::FLOAT;
    case 212: return BuiltinTypeKind::DOUBLE;
    case 213: return BuiltinTypeKind::LONG_DOUBLE;
    case 214: return BuiltinTypeKind::FLOAT16;
    case 215: return BuiltinTypeKind::B_FLOAT16;
    case 216: return BuiltinTypeKind::FLOAT128;
    case 217: return BuiltinTypeKind::IBM128;
    case 218: return BuiltinTypeKind::NULL_POINTER;
    case 219: return BuiltinTypeKind::OBJ_C_ID;
    case 220: return BuiltinTypeKind::OBJ_C_CLASS;
    case 221: return BuiltinTypeKind::OBJ_C_SEL;
    case 222: return BuiltinTypeKind::OCL_SAMPLER;
    case 223: return BuiltinTypeKind::OCL_EVENT;
    case 224: return BuiltinTypeKind::OCL_CLK_EVENT;
    case 225: return BuiltinTypeKind::OCL_QUEUE;
    case 226: return BuiltinTypeKind::OCL_RESERVE_ID;
    case 227: return BuiltinTypeKind::DEPENDENT;
    case 228: return BuiltinTypeKind::OVERLOAD;
    case 229: return BuiltinTypeKind::BOUND_MEMBER;
    case 230: return BuiltinTypeKind::PSEUDO_OBJECT;
    case 231: return BuiltinTypeKind::UNKNOWN_ANY;
    case 232: return BuiltinTypeKind::BUILTIN_FN;
    case 233: return BuiltinTypeKind::ARC_UNBRIDGED_CAST;
    case 234: return BuiltinTypeKind::INCOMPLETE_MATRIX_INDEX;
    case 235: return BuiltinTypeKind::OMP_ARRAY_SECTION;
    case 236: return BuiltinTypeKind::OMP_ARRAY_SHAPING;
    case 237: return BuiltinTypeKind::OMP_ITERATOR;
    default: __builtin_unreachable();
  }
}

CDeclAttrSpelling FromPasta(pasta::CDeclAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CDeclAttrSpelling::GNU_CDECL;
    case 1: return CDeclAttrSpelling::CXX11_GNU_CDECL;
    case 2: return CDeclAttrSpelling::C2X_GNU_CDECL;
    case 3: return CDeclAttrSpelling::KEYWORD_CDECL;
    case 15: return CDeclAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CFAuditedTransferAttrSpelling FromPasta(pasta::CFAuditedTransferAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CFAuditedTransferAttrSpelling::GNU_CF_AUDITED_TRANSFER;
    case 1: return CFAuditedTransferAttrSpelling::CXX11_CLANG_CF_AUDITED_TRANSFER;
    case 2: return CFAuditedTransferAttrSpelling::C2X_CLANG_CF_AUDITED_TRANSFER;
    case 15: return CFAuditedTransferAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CFConsumedAttrSpelling FromPasta(pasta::CFConsumedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CFConsumedAttrSpelling::GNU_CF_CONSUMED;
    case 1: return CFConsumedAttrSpelling::CXX11_CLANG_CF_CONSUMED;
    case 2: return CFConsumedAttrSpelling::C2X_CLANG_CF_CONSUMED;
    case 15: return CFConsumedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CFGuardAttrGuardArg FromPasta(pasta::CFGuardAttrGuardArg e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CFGuardAttrGuardArg::NOCF;
    default: __builtin_unreachable();
  }
}

CFGuardAttrSpelling FromPasta(pasta::CFGuardAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CFGuardAttrSpelling::DECLSPEC_GUARD;
    case 1: return CFGuardAttrSpelling::GNU_GUARD;
    case 2: return CFGuardAttrSpelling::CXX11_CLANG_GUARD;
    case 3: return CFGuardAttrSpelling::C2X_CLANG_GUARD;
    case 15: return CFGuardAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CFICanonicalJumpTableAttrSpelling FromPasta(pasta::CFICanonicalJumpTableAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CFICanonicalJumpTableAttrSpelling::GNU_CFI_CANONICAL_JUMP_TABLE;
    case 1: return CFICanonicalJumpTableAttrSpelling::CXX11_CLANG_CFI_CANONICAL_JUMP_TABLE;
    case 2: return CFICanonicalJumpTableAttrSpelling::C2X_CLANG_CFI_CANONICAL_JUMP_TABLE;
    case 15: return CFICanonicalJumpTableAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CFReturnsNotRetainedAttrSpelling FromPasta(pasta::CFReturnsNotRetainedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CFReturnsNotRetainedAttrSpelling::GNU_CF_RETURNS_NOT_RETAINED;
    case 1: return CFReturnsNotRetainedAttrSpelling::CXX11_CLANG_CF_RETURNS_NOT_RETAINED;
    case 2: return CFReturnsNotRetainedAttrSpelling::C2X_CLANG_CF_RETURNS_NOT_RETAINED;
    case 15: return CFReturnsNotRetainedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CFReturnsRetainedAttrSpelling FromPasta(pasta::CFReturnsRetainedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CFReturnsRetainedAttrSpelling::GNU_CF_RETURNS_RETAINED;
    case 1: return CFReturnsRetainedAttrSpelling::CXX11_CLANG_CF_RETURNS_RETAINED;
    case 2: return CFReturnsRetainedAttrSpelling::C2X_CLANG_CF_RETURNS_RETAINED;
    case 15: return CFReturnsRetainedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CFUnknownTransferAttrSpelling FromPasta(pasta::CFUnknownTransferAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CFUnknownTransferAttrSpelling::GNU_CF_UNKNOWN_TRANSFER;
    case 1: return CFUnknownTransferAttrSpelling::CXX11_CLANG_CF_UNKNOWN_TRANSFER;
    case 2: return CFUnknownTransferAttrSpelling::C2X_CLANG_CF_UNKNOWN_TRANSFER;
    case 15: return CFUnknownTransferAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CPUDispatchAttrSpelling FromPasta(pasta::CPUDispatchAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CPUDispatchAttrSpelling::GNU_CPU_DISPATCH;
    case 1: return CPUDispatchAttrSpelling::CXX11_CLANG_CPU_DISPATCH;
    case 2: return CPUDispatchAttrSpelling::C2X_CLANG_CPU_DISPATCH;
    case 3: return CPUDispatchAttrSpelling::DECLSPEC_CPU_DISPATCH;
    case 15: return CPUDispatchAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CPUSpecificAttrSpelling FromPasta(pasta::CPUSpecificAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CPUSpecificAttrSpelling::GNU_CPU_SPECIFIC;
    case 1: return CPUSpecificAttrSpelling::CXX11_CLANG_CPU_SPECIFIC;
    case 2: return CPUSpecificAttrSpelling::C2X_CLANG_CPU_SPECIFIC;
    case 3: return CPUSpecificAttrSpelling::DECLSPEC_CPU_SPECIFIC;
    case 15: return CPUSpecificAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CUDAConstantAttrSpelling FromPasta(pasta::CUDAConstantAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CUDAConstantAttrSpelling::GNU_CONSTANT;
    case 1: return CUDAConstantAttrSpelling::DECLSPEC_CONSTANT;
    case 15: return CUDAConstantAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CUDADeviceAttrSpelling FromPasta(pasta::CUDADeviceAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CUDADeviceAttrSpelling::GNU_DEVICE;
    case 1: return CUDADeviceAttrSpelling::DECLSPEC_DEVICE;
    case 15: return CUDADeviceAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CUDADeviceBuiltinSurfaceTypeAttrSpelling FromPasta(pasta::CUDADeviceBuiltinSurfaceTypeAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CUDADeviceBuiltinSurfaceTypeAttrSpelling::GNU_DEVICE_BUILTIN_SURFACE_TYPE;
    case 1: return CUDADeviceBuiltinSurfaceTypeAttrSpelling::DECLSPEC_DEVICE_BUILTIN_SURFACE_TYPE;
    case 15: return CUDADeviceBuiltinSurfaceTypeAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CUDADeviceBuiltinTextureTypeAttrSpelling FromPasta(pasta::CUDADeviceBuiltinTextureTypeAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CUDADeviceBuiltinTextureTypeAttrSpelling::GNU_DEVICE_BUILTIN_TEXTURE_TYPE;
    case 1: return CUDADeviceBuiltinTextureTypeAttrSpelling::DECLSPEC_DEVICE_BUILTIN_TEXTURE_TYPE;
    case 15: return CUDADeviceBuiltinTextureTypeAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CUDAGlobalAttrSpelling FromPasta(pasta::CUDAGlobalAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CUDAGlobalAttrSpelling::GNU_GLOBAL;
    case 1: return CUDAGlobalAttrSpelling::DECLSPEC_GLOBAL;
    case 15: return CUDAGlobalAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CUDAHostAttrSpelling FromPasta(pasta::CUDAHostAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CUDAHostAttrSpelling::GNU_HOST;
    case 1: return CUDAHostAttrSpelling::DECLSPEC_HOST;
    case 15: return CUDAHostAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CUDALaunchBoundsAttrSpelling FromPasta(pasta::CUDALaunchBoundsAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CUDALaunchBoundsAttrSpelling::GNU_LAUNCH_BOUNDS;
    case 1: return CUDALaunchBoundsAttrSpelling::DECLSPEC_LAUNCH_BOUNDS;
    case 15: return CUDALaunchBoundsAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CUDASharedAttrSpelling FromPasta(pasta::CUDASharedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CUDASharedAttrSpelling::GNU_SHARED;
    case 1: return CUDASharedAttrSpelling::DECLSPEC_SHARED;
    case 15: return CUDASharedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CXX11NoReturnAttrSpelling FromPasta(pasta::CXX11NoReturnAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CXX11NoReturnAttrSpelling::CXX11_NORETURN;
    case 1: return CXX11NoReturnAttrSpelling::C2XNORETURN;
    case 2: return CXX11NoReturnAttrSpelling::C2X_NORETURN;
    case 15: return CXX11NoReturnAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CXXConstructExprConstructionKind FromPasta(pasta::CXXConstructExprConstructionKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CXXConstructExprConstructionKind::COMPLETE;
    case 1: return CXXConstructExprConstructionKind::NON_VIRTUAL_BASE;
    case 2: return CXXConstructExprConstructionKind::VIRTUAL_BASE;
    case 3: return CXXConstructExprConstructionKind::DELEGATING;
    default: __builtin_unreachable();
  }
}

CXXNewExprInitializationStyle FromPasta(pasta::CXXNewExprInitializationStyle e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CXXNewExprInitializationStyle::NO_INITIALIZER;
    case 1: return CXXNewExprInitializationStyle::CALL_INITIALIZER;
    case 2: return CXXNewExprInitializationStyle::LIST_INITIALIZER;
    default: __builtin_unreachable();
  }
}

CXXRecordDeclLambdaDependencyKind FromPasta(pasta::CXXRecordDeclLambdaDependencyKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CXXRecordDeclLambdaDependencyKind::UNKNOWN;
    case 1: return CXXRecordDeclLambdaDependencyKind::ALWAYS_DEPENDENT;
    case 2: return CXXRecordDeclLambdaDependencyKind::NEVER_DEPENDENT;
    default: __builtin_unreachable();
  }
}

CallExprADLCallKind FromPasta(pasta::CallExprADLCallKind e) {
  switch (static_cast<int>(e)) {
    case 0: return CallExprADLCallKind::NOT_ADL;
    case 1: return CallExprADLCallKind::USES_ADL;
    default: __builtin_unreachable();
  }
}

CallableWhenAttrConsumedState FromPasta(pasta::CallableWhenAttrConsumedState e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CallableWhenAttrConsumedState::UNKNOWN;
    case 1: return CallableWhenAttrConsumedState::CONSUMED;
    case 2: return CallableWhenAttrConsumedState::UNCONSUMED;
    default: __builtin_unreachable();
  }
}

CallableWhenAttrSpelling FromPasta(pasta::CallableWhenAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CallableWhenAttrSpelling::GNU_CALLABLE_WHEN;
    case 1: return CallableWhenAttrSpelling::CXX11_CLANG_CALLABLE_WHEN;
    case 15: return CallableWhenAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CallbackAttrSpelling FromPasta(pasta::CallbackAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CallbackAttrSpelling::GNU_CALLBACK;
    case 1: return CallbackAttrSpelling::CXX11_CLANG_CALLBACK;
    case 2: return CallbackAttrSpelling::C2X_CLANG_CALLBACK;
    case 15: return CallbackAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CalledOnceAttrSpelling FromPasta(pasta::CalledOnceAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CalledOnceAttrSpelling::GNU_CALLED_ONCE;
    case 1: return CalledOnceAttrSpelling::CXX11_CLANG_CALLED_ONCE;
    case 2: return CalledOnceAttrSpelling::C2X_CLANG_CALLED_ONCE;
    case 15: return CalledOnceAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CapabilityAttrSpelling FromPasta(pasta::CapabilityAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CapabilityAttrSpelling::GNU_CAPABILITY;
    case 1: return CapabilityAttrSpelling::CXX11_CLANG_CAPABILITY;
    case 2: return CapabilityAttrSpelling::GNU_SHARED_CAPABILITY;
    case 3: return CapabilityAttrSpelling::CXX11_CLANG_SHARED_CAPABILITY;
    case 15: return CapabilityAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CapturedStmtVariableCaptureKind FromPasta(pasta::CapturedStmtVariableCaptureKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CapturedStmtVariableCaptureKind::THIS;
    case 1: return CapturedStmtVariableCaptureKind::BY_REFERENCE;
    case 2: return CapturedStmtVariableCaptureKind::BY_COPY;
    case 3: return CapturedStmtVariableCaptureKind::VLA_TYPE;
    default: __builtin_unreachable();
  }
}

CarriesDependencyAttrSpelling FromPasta(pasta::CarriesDependencyAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CarriesDependencyAttrSpelling::GNU_CARRIES_DEPENDENCY;
    case 1: return CarriesDependencyAttrSpelling::CXX11_CARRIES_DEPENDENCY;
    case 15: return CarriesDependencyAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CharacterLiteralCharacterKind FromPasta(pasta::CharacterLiteralCharacterKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CharacterLiteralCharacterKind::ASCII;
    case 1: return CharacterLiteralCharacterKind::WIDE;
    case 2: return CharacterLiteralCharacterKind::UTF8;
    case 3: return CharacterLiteralCharacterKind::UTF16;
    case 4: return CharacterLiteralCharacterKind::UTF32;
    default: __builtin_unreachable();
  }
}

CleanupAttrSpelling FromPasta(pasta::CleanupAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CleanupAttrSpelling::GNU_CLEANUP;
    case 1: return CleanupAttrSpelling::CXX11_GNU_CLEANUP;
    case 2: return CleanupAttrSpelling::C2X_GNU_CLEANUP;
    case 15: return CleanupAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ColdAttrSpelling FromPasta(pasta::ColdAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ColdAttrSpelling::GNU_COLD;
    case 1: return ColdAttrSpelling::CXX11_GNU_COLD;
    case 2: return ColdAttrSpelling::C2X_GNU_COLD;
    case 15: return ColdAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

CommonAttrSpelling FromPasta(pasta::CommonAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CommonAttrSpelling::GNU_COMMON;
    case 1: return CommonAttrSpelling::CXX11_GNU_COMMON;
    case 2: return CommonAttrSpelling::C2X_GNU_COMMON;
    case 15: return CommonAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ConstAttrSpelling FromPasta(pasta::ConstAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ConstAttrSpelling::GNU_CONST;
    case 1: return ConstAttrSpelling::CXX11_GNU_CONST;
    case 2: return ConstAttrSpelling::C2X_GNU_CONST;
    case 15: return ConstAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ConstInitAttrSpelling FromPasta(pasta::ConstInitAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ConstInitAttrSpelling::KEYWORD_CONSTINIT;
    case 1: return ConstInitAttrSpelling::GNU_REQUIRE_CONSTANT_INITIALIZATION;
    case 2: return ConstInitAttrSpelling::CXX11_CLANG_REQUIRE_CONSTANT_INITIALIZATION;
    case 15: return ConstInitAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ConstantExprResultStorageKind FromPasta(pasta::ConstantExprResultStorageKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ConstantExprResultStorageKind::NONE;
    case 1: return ConstantExprResultStorageKind::INT64;
    case 2: return ConstantExprResultStorageKind::AP_VALUE;
    default: __builtin_unreachable();
  }
}

ConstructorAttrSpelling FromPasta(pasta::ConstructorAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ConstructorAttrSpelling::GNU_CONSTRUCTOR;
    case 1: return ConstructorAttrSpelling::CXX11_GNU_CONSTRUCTOR;
    case 2: return ConstructorAttrSpelling::C2X_GNU_CONSTRUCTOR;
    case 15: return ConstructorAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ConsumableAttrConsumedState FromPasta(pasta::ConsumableAttrConsumedState e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ConsumableAttrConsumedState::UNKNOWN;
    case 1: return ConsumableAttrConsumedState::CONSUMED;
    case 2: return ConsumableAttrConsumedState::UNCONSUMED;
    default: __builtin_unreachable();
  }
}

ConsumableAttrSpelling FromPasta(pasta::ConsumableAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ConsumableAttrSpelling::GNU_CONSUMABLE;
    case 1: return ConsumableAttrSpelling::CXX11_CLANG_CONSUMABLE;
    case 15: return ConsumableAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ConsumableAutoCastAttrSpelling FromPasta(pasta::ConsumableAutoCastAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ConsumableAutoCastAttrSpelling::GNU_CONSUMABLE_AUTO_CAST_STATE;
    case 1: return ConsumableAutoCastAttrSpelling::CXX11_CLANG_CONSUMABLE_AUTO_CAST_STATE;
    case 15: return ConsumableAutoCastAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ConsumableSetOnReadAttrSpelling FromPasta(pasta::ConsumableSetOnReadAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ConsumableSetOnReadAttrSpelling::GNU_CONSUMABLE_STATE_ON_READ;
    case 1: return ConsumableSetOnReadAttrSpelling::CXX11_CLANG_CONSUMABLE_STATE_ON_READ;
    case 15: return ConsumableSetOnReadAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ConvergentAttrSpelling FromPasta(pasta::ConvergentAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ConvergentAttrSpelling::GNU_CONVERGENT;
    case 1: return ConvergentAttrSpelling::CXX11_CLANG_CONVERGENT;
    case 2: return ConvergentAttrSpelling::C2X_CLANG_CONVERGENT;
    case 15: return ConvergentAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

DLLExportAttrSpelling FromPasta(pasta::DLLExportAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DLLExportAttrSpelling::DECLSPEC_DLLEXPORT;
    case 1: return DLLExportAttrSpelling::GNU_DLLEXPORT;
    case 2: return DLLExportAttrSpelling::CXX11_GNU_DLLEXPORT;
    case 3: return DLLExportAttrSpelling::C2X_GNU_DLLEXPORT;
    case 15: return DLLExportAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

DLLImportAttrSpelling FromPasta(pasta::DLLImportAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DLLImportAttrSpelling::DECLSPEC_DLLIMPORT;
    case 1: return DLLImportAttrSpelling::GNU_DLLIMPORT;
    case 2: return DLLImportAttrSpelling::CXX11_GNU_DLLIMPORT;
    case 3: return DLLImportAttrSpelling::C2X_GNU_DLLIMPORT;
    case 15: return DLLImportAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

DeclFriendObjectKind FromPasta(pasta::DeclFriendObjectKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DeclFriendObjectKind::NONE;
    case 1: return DeclFriendObjectKind::DECLARED;
    case 2: return DeclFriendObjectKind::UNDECLARED;
    default: __builtin_unreachable();
  }
}

DeclIdentifierNamespace FromPasta(pasta::DeclIdentifierNamespace e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return DeclIdentifierNamespace::LABEL;
    case 2: return DeclIdentifierNamespace::TAG;
    case 4: return DeclIdentifierNamespace::TYPE;
    case 8: return DeclIdentifierNamespace::MEMBER;
    case 16: return DeclIdentifierNamespace::NAMESPACE;
    case 32: return DeclIdentifierNamespace::ORDINARY;
    case 64: return DeclIdentifierNamespace::OBJ_C_PROTOCOL;
    case 128: return DeclIdentifierNamespace::ORDINARY_FRIEND;
    case 256: return DeclIdentifierNamespace::TAG_FRIEND;
    case 512: return DeclIdentifierNamespace::USING;
    case 1024: return DeclIdentifierNamespace::NON_MEMBER_OPERATOR;
    case 2048: return DeclIdentifierNamespace::LOCAL_EXTERN;
    case 4096: return DeclIdentifierNamespace::OMP_REDUCTION;
    case 8192: return DeclIdentifierNamespace::OMP_MAPPER;
    default: __builtin_unreachable();
  }
}

DeclModuleOwnershipKind FromPasta(pasta::DeclModuleOwnershipKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DeclModuleOwnershipKind::UNOWNED;
    case 1: return DeclModuleOwnershipKind::VISIBLE;
    case 2: return DeclModuleOwnershipKind::VISIBLE_WHEN_IMPORTED;
    case 3: return DeclModuleOwnershipKind::REACHABLE_WHEN_IMPORTED;
    case 4: return DeclModuleOwnershipKind::MODULE_PRIVATE;
    default: __builtin_unreachable();
  }
}

DeclObjCDeclQualifier FromPasta(pasta::DeclObjCDeclQualifier e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DeclObjCDeclQualifier::NONE;
    case 1: return DeclObjCDeclQualifier::IN;
    case 2: return DeclObjCDeclQualifier::INOUT;
    case 4: return DeclObjCDeclQualifier::OUT;
    case 8: return DeclObjCDeclQualifier::BYCOPY;
    case 16: return DeclObjCDeclQualifier::BYREF;
    case 32: return DeclObjCDeclQualifier::ONEWAY;
    case 64: return DeclObjCDeclQualifier::CS_NULLABILITY;
    default: __builtin_unreachable();
  }
}

DeprecatedAttrSpelling FromPasta(pasta::DeprecatedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DeprecatedAttrSpelling::GNU_DEPRECATED;
    case 1: return DeprecatedAttrSpelling::CXX11_GNU_DEPRECATED;
    case 2: return DeprecatedAttrSpelling::C2X_GNU_DEPRECATED;
    case 3: return DeprecatedAttrSpelling::DECLSPEC_DEPRECATED;
    case 4: return DeprecatedAttrSpelling::CXX11_DEPRECATED;
    case 5: return DeprecatedAttrSpelling::C2X_DEPRECATED;
    case 15: return DeprecatedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

DestructorAttrSpelling FromPasta(pasta::DestructorAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DestructorAttrSpelling::GNU_DESTRUCTOR;
    case 1: return DestructorAttrSpelling::CXX11_GNU_DESTRUCTOR;
    case 2: return DestructorAttrSpelling::C2X_GNU_DESTRUCTOR;
    case 15: return DestructorAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

DiagnoseAsBuiltinAttrSpelling FromPasta(pasta::DiagnoseAsBuiltinAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DiagnoseAsBuiltinAttrSpelling::GNU_DIAGNOSE_AS_BUILTIN;
    case 1: return DiagnoseAsBuiltinAttrSpelling::CXX11_CLANG_DIAGNOSE_AS_BUILTIN;
    case 2: return DiagnoseAsBuiltinAttrSpelling::C2X_CLANG_DIAGNOSE_AS_BUILTIN;
    case 15: return DiagnoseAsBuiltinAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

DiagnoseIfAttrDiagnosticType FromPasta(pasta::DiagnoseIfAttrDiagnosticType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DiagnoseIfAttrDiagnosticType::ERROR;
    case 1: return DiagnoseIfAttrDiagnosticType::WARNING;
    default: __builtin_unreachable();
  }
}

DisableSanitizerInstrumentationAttrSpelling FromPasta(pasta::DisableSanitizerInstrumentationAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DisableSanitizerInstrumentationAttrSpelling::GNU_DISABLE_SANITIZER_INSTRUMENTATION;
    case 1: return DisableSanitizerInstrumentationAttrSpelling::CXX11_CLANG_DISABLE_SANITIZER_INSTRUMENTATION;
    case 2: return DisableSanitizerInstrumentationAttrSpelling::C2X_CLANG_DISABLE_SANITIZER_INSTRUMENTATION;
    case 15: return DisableSanitizerInstrumentationAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

DisableTailCallsAttrSpelling FromPasta(pasta::DisableTailCallsAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DisableTailCallsAttrSpelling::GNU_DISABLE_TAIL_CALLS;
    case 1: return DisableTailCallsAttrSpelling::CXX11_CLANG_DISABLE_TAIL_CALLS;
    case 2: return DisableTailCallsAttrSpelling::C2X_CLANG_DISABLE_TAIL_CALLS;
    case 15: return DisableTailCallsAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

EnforceTCBAttrSpelling FromPasta(pasta::EnforceTCBAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return EnforceTCBAttrSpelling::GNU_ENFORCE_TCB;
    case 1: return EnforceTCBAttrSpelling::CXX11_CLANG_ENFORCE_TCB;
    case 2: return EnforceTCBAttrSpelling::C2X_CLANG_ENFORCE_TCB;
    case 15: return EnforceTCBAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

EnforceTCBLeafAttrSpelling FromPasta(pasta::EnforceTCBLeafAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return EnforceTCBLeafAttrSpelling::GNU_ENFORCE_TCB_LEAF;
    case 1: return EnforceTCBLeafAttrSpelling::CXX11_CLANG_ENFORCE_TCB_LEAF;
    case 2: return EnforceTCBLeafAttrSpelling::C2X_CLANG_ENFORCE_TCB_LEAF;
    case 15: return EnforceTCBLeafAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

EnumExtensibilityAttrKind FromPasta(pasta::EnumExtensibilityAttrKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return EnumExtensibilityAttrKind::CLOSED;
    case 1: return EnumExtensibilityAttrKind::OPEN;
    default: __builtin_unreachable();
  }
}

EnumExtensibilityAttrSpelling FromPasta(pasta::EnumExtensibilityAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return EnumExtensibilityAttrSpelling::GNU_ENUM_EXTENSIBILITY;
    case 1: return EnumExtensibilityAttrSpelling::CXX11_CLANG_ENUM_EXTENSIBILITY;
    case 2: return EnumExtensibilityAttrSpelling::C2X_CLANG_ENUM_EXTENSIBILITY;
    case 15: return EnumExtensibilityAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ErrorAttrSpelling FromPasta(pasta::ErrorAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ErrorAttrSpelling::GNU_ERROR;
    case 1: return ErrorAttrSpelling::CXX11_GNU_ERROR;
    case 2: return ErrorAttrSpelling::C2X_GNU_ERROR;
    case 3: return ErrorAttrSpelling::GNU_WARNING;
    case 4: return ErrorAttrSpelling::CXX11_GNU_WARNING;
    case 5: return ErrorAttrSpelling::C2X_GNU_WARNING;
    case 15: return ErrorAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ExcludeFromExplicitInstantiationAttrSpelling FromPasta(pasta::ExcludeFromExplicitInstantiationAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExcludeFromExplicitInstantiationAttrSpelling::GNU_EXCLUDE_FROM_EXPLICIT_INSTANTIATION;
    case 1: return ExcludeFromExplicitInstantiationAttrSpelling::CXX11_CLANG_EXCLUDE_FROM_EXPLICIT_INSTANTIATION;
    case 2: return ExcludeFromExplicitInstantiationAttrSpelling::C2X_CLANG_EXCLUDE_FROM_EXPLICIT_INSTANTIATION;
    case 15: return ExcludeFromExplicitInstantiationAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ExprConstantExprKind FromPasta(pasta::ExprConstantExprKind e) {
  switch (static_cast<int>(e)) {
    case 0: return ExprConstantExprKind::NORMAL;
    case 1: return ExprConstantExprKind::NON_CLASS_TEMPLATE_ARGUMENT;
    case 2: return ExprConstantExprKind::CLASS_TEMPLATE_ARGUMENT;
    case 3: return ExprConstantExprKind::IMMEDIATE_INVOCATION;
    default: __builtin_unreachable();
  }
}

ExprLValueClassification FromPasta(pasta::ExprLValueClassification e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExprLValueClassification::VALID;
    case 1: return ExprLValueClassification::NOT_OBJECT_TYPE;
    case 2: return ExprLValueClassification::INCOMPLETE_VOID_TYPE;
    case 3: return ExprLValueClassification::DUPLICATE_VECTOR_COMPONENTS;
    case 4: return ExprLValueClassification::INVALID_EXPRESSION;
    case 5: return ExprLValueClassification::INVALID_MESSAGE_EXPRESSION;
    case 6: return ExprLValueClassification::MEMBER_FUNCTION;
    case 7: return ExprLValueClassification::SUB_OBJ_C_PROPERTY_SETTING;
    case 8: return ExprLValueClassification::CLASS_TEMPORARY;
    case 9: return ExprLValueClassification::ARRAY_TEMPORARY;
    default: __builtin_unreachable();
  }
}

ExprNullPointerConstantKind FromPasta(pasta::ExprNullPointerConstantKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExprNullPointerConstantKind::NOT_NULL;
    case 1: return ExprNullPointerConstantKind::ZERO_EXPRESSION;
    case 2: return ExprNullPointerConstantKind::ZERO_LITERAL;
    case 3: return ExprNullPointerConstantKind::CXX11_NULLPTR;
    case 4: return ExprNullPointerConstantKind::GNU_NULL;
    default: __builtin_unreachable();
  }
}

ExprNullPointerConstantValueDependence FromPasta(pasta::ExprNullPointerConstantValueDependence e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExprNullPointerConstantValueDependence::NEVER_VALUE_DEPENDENT;
    case 1: return ExprNullPointerConstantValueDependence::VALUE_DEPENDENT_IS_NULL;
    case 2: return ExprNullPointerConstantValueDependence::VALUE_DEPENDENT_IS_NOT_NULL;
    default: __builtin_unreachable();
  }
}

ExprSideEffectsKind FromPasta(pasta::ExprSideEffectsKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExprSideEffectsKind::NO_SIDE_EFFECTS;
    case 1: return ExprSideEffectsKind::ALLOW_UNDEFINED_BEHAVIOR;
    case 2: return ExprSideEffectsKind::ALLOW_SIDE_EFFECTS;
    default: __builtin_unreachable();
  }
}

ExprisModifiableLvalueResult FromPasta(pasta::ExprisModifiableLvalueResult e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExprisModifiableLvalueResult::VALID;
    case 1: return ExprisModifiableLvalueResult::NOT_OBJECT_TYPE;
    case 2: return ExprisModifiableLvalueResult::INCOMPLETE_VOID_TYPE;
    case 3: return ExprisModifiableLvalueResult::DUPLICATE_VECTOR_COMPONENTS;
    case 4: return ExprisModifiableLvalueResult::INVALID_EXPRESSION;
    case 5: return ExprisModifiableLvalueResult::L_VALUE_CAST;
    case 6: return ExprisModifiableLvalueResult::INCOMPLETE_TYPE;
    case 7: return ExprisModifiableLvalueResult::CONST_QUALIFIED;
    case 8: return ExprisModifiableLvalueResult::CONST_QUALIFIED_FIELD;
    case 9: return ExprisModifiableLvalueResult::CONST_ADDRESS_SPACE;
    case 10: return ExprisModifiableLvalueResult::ARRAY_TYPE;
    case 11: return ExprisModifiableLvalueResult::NO_SETTER_PROPERTY;
    case 12: return ExprisModifiableLvalueResult::MEMBER_FUNCTION;
    case 13: return ExprisModifiableLvalueResult::SUB_OBJ_C_PROPERTY_SETTING;
    case 14: return ExprisModifiableLvalueResult::INVALID_MESSAGE_EXPRESSION;
    case 15: return ExprisModifiableLvalueResult::CLASS_TEMPORARY;
    case 16: return ExprisModifiableLvalueResult::ARRAY_TEMPORARY;
    default: __builtin_unreachable();
  }
}

ExternalSourceSymbolAttrSpelling FromPasta(pasta::ExternalSourceSymbolAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExternalSourceSymbolAttrSpelling::GNU_EXTERNAL_SOURCE_SYMBOL;
    case 1: return ExternalSourceSymbolAttrSpelling::CXX11_CLANG_EXTERNAL_SOURCE_SYMBOL;
    case 2: return ExternalSourceSymbolAttrSpelling::C2X_CLANG_EXTERNAL_SOURCE_SYMBOL;
    case 15: return ExternalSourceSymbolAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

FallThroughAttrSpelling FromPasta(pasta::FallThroughAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FallThroughAttrSpelling::CXX11_FALLTHROUGH;
    case 1: return FallThroughAttrSpelling::C2X_FALLTHROUGH;
    case 2: return FallThroughAttrSpelling::CXX11_CLANG_FALLTHROUGH;
    case 3: return FallThroughAttrSpelling::GNU_FALLTHROUGH;
    case 4: return FallThroughAttrSpelling::CXX11_GNU_FALLTHROUGH;
    case 5: return FallThroughAttrSpelling::C2X_GNU_FALLTHROUGH;
    case 15: return FallThroughAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

FastCallAttrSpelling FromPasta(pasta::FastCallAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FastCallAttrSpelling::GNU_FASTCALL;
    case 1: return FastCallAttrSpelling::CXX11_GNU_FASTCALL;
    case 2: return FastCallAttrSpelling::C2X_GNU_FASTCALL;
    case 3: return FastCallAttrSpelling::KEYWORD_FASTCALL;
    case 15: return FastCallAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

FinalAttrSpelling FromPasta(pasta::FinalAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FinalAttrSpelling::KEYWORD_FINAL;
    case 1: return FinalAttrSpelling::KEYWORD_SEALED;
    case 15: return FinalAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

FlagEnumAttrSpelling FromPasta(pasta::FlagEnumAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FlagEnumAttrSpelling::GNU_FLAG_ENUM;
    case 1: return FlagEnumAttrSpelling::CXX11_CLANG_FLAG_ENUM;
    case 2: return FlagEnumAttrSpelling::C2X_CLANG_FLAG_ENUM;
    case 15: return FlagEnumAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

FlattenAttrSpelling FromPasta(pasta::FlattenAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FlattenAttrSpelling::GNU_FLATTEN;
    case 1: return FlattenAttrSpelling::CXX11_GNU_FLATTEN;
    case 2: return FlattenAttrSpelling::C2X_GNU_FLATTEN;
    case 15: return FlattenAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

FormatArgAttrSpelling FromPasta(pasta::FormatArgAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FormatArgAttrSpelling::GNU_FORMAT_ARGUMENT;
    case 1: return FormatArgAttrSpelling::CXX11_GNU_FORMAT_ARGUMENT;
    case 2: return FormatArgAttrSpelling::C2X_GNU_FORMAT_ARGUMENT;
    case 15: return FormatArgAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

FormatAttrSpelling FromPasta(pasta::FormatAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FormatAttrSpelling::GNU_FORMAT;
    case 1: return FormatAttrSpelling::CXX11_GNU_FORMAT;
    case 2: return FormatAttrSpelling::C2X_GNU_FORMAT;
    case 15: return FormatAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

FunctionDeclTemplatedKind FromPasta(pasta::FunctionDeclTemplatedKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FunctionDeclTemplatedKind::NON_TEMPLATE;
    case 1: return FunctionDeclTemplatedKind::FUNCTION_TEMPLATE;
    case 2: return FunctionDeclTemplatedKind::MEMBER_SPECIALIZATION;
    case 3: return FunctionDeclTemplatedKind::FUNCTION_TEMPLATE_SPECIALIZATION;
    case 4: return FunctionDeclTemplatedKind::DEPENDENT_FUNCTION_TEMPLATE_SPECIALIZATION;
    case 5: return FunctionDeclTemplatedKind::DEPENDENT_NON_TEMPLATE;
    default: __builtin_unreachable();
  }
}

FunctionReturnThunksAttrKind FromPasta(pasta::FunctionReturnThunksAttrKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FunctionReturnThunksAttrKind::KEEP;
    case 1: return FunctionReturnThunksAttrKind::EXTERN;
    default: __builtin_unreachable();
  }
}

FunctionReturnThunksAttrSpelling FromPasta(pasta::FunctionReturnThunksAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FunctionReturnThunksAttrSpelling::GNU_FUNCTION_RETURN;
    case 1: return FunctionReturnThunksAttrSpelling::CXX11_GNU_FUNCTION_RETURN;
    case 2: return FunctionReturnThunksAttrSpelling::C2X_GNU_FUNCTION_RETURN;
    case 15: return FunctionReturnThunksAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

GNUInlineAttrSpelling FromPasta(pasta::GNUInlineAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return GNUInlineAttrSpelling::GNU_GNU_INLINE;
    case 1: return GNUInlineAttrSpelling::CXX11_GNU_GNU_INLINE;
    case 2: return GNUInlineAttrSpelling::C2X_GNU_GNU_INLINE;
    case 15: return GNUInlineAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

GuardedVarAttrSpelling FromPasta(pasta::GuardedVarAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return GuardedVarAttrSpelling::GNU_GUARDED_VARIABLE;
    case 1: return GuardedVarAttrSpelling::CXX11_CLANG_GUARDED_VARIABLE;
    case 15: return GuardedVarAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

HIPManagedAttrSpelling FromPasta(pasta::HIPManagedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return HIPManagedAttrSpelling::GNU_MANAGED;
    case 1: return HIPManagedAttrSpelling::DECLSPEC_MANAGED;
    case 15: return HIPManagedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

HLSLResourceAttrResourceClass FromPasta(pasta::HLSLResourceAttrResourceClass e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return HLSLResourceAttrResourceClass::SRV;
    case 1: return HLSLResourceAttrResourceClass::UAV;
    case 2: return HLSLResourceAttrResourceClass::C_BUFFER;
    case 3: return HLSLResourceAttrResourceClass::SAMPLER;
    default: __builtin_unreachable();
  }
}

HLSLResourceAttrResourceKind FromPasta(pasta::HLSLResourceAttrResourceKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return HLSLResourceAttrResourceKind::TEXTURE1_D;
    case 1: return HLSLResourceAttrResourceKind::TEXTURE2_D;
    case 2: return HLSLResourceAttrResourceKind::TEXTURE2_DMS;
    case 3: return HLSLResourceAttrResourceKind::TEXTURE3_D;
    case 4: return HLSLResourceAttrResourceKind::TEXTURE_CUBE;
    case 5: return HLSLResourceAttrResourceKind::TEXTURE1_D_ARRAY;
    case 6: return HLSLResourceAttrResourceKind::TEXTURE2_D_ARRAY;
    case 7: return HLSLResourceAttrResourceKind::TEXTURE2_DMS_ARRAY;
    case 8: return HLSLResourceAttrResourceKind::TEXTURE_CUBE_ARRAY;
    case 9: return HLSLResourceAttrResourceKind::TYPED_BUFFER;
    case 10: return HLSLResourceAttrResourceKind::RAW_BUFFER;
    case 11: return HLSLResourceAttrResourceKind::STRUCTURED_BUFFER;
    case 12: return HLSLResourceAttrResourceKind::C_BUFFER_KIND;
    case 13: return HLSLResourceAttrResourceKind::SAMPLER_KIND;
    case 14: return HLSLResourceAttrResourceKind::T_BUFFER;
    case 15: return HLSLResourceAttrResourceKind::RT_ACCELERATION_STRUCTURE;
    case 16: return HLSLResourceAttrResourceKind::FEEDBACK_TEXTURE2_D;
    case 17: return HLSLResourceAttrResourceKind::FEEDBACK_TEXTURE2_D_ARRAY;
    default: __builtin_unreachable();
  }
}

HLSLShaderAttrShaderType FromPasta(pasta::HLSLShaderAttrShaderType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return HLSLShaderAttrShaderType::PIXEL;
    case 1: return HLSLShaderAttrShaderType::VERTEX;
    case 2: return HLSLShaderAttrShaderType::GEOMETRY;
    case 3: return HLSLShaderAttrShaderType::HULL;
    case 4: return HLSLShaderAttrShaderType::DOMAIN_;
    case 5: return HLSLShaderAttrShaderType::COMPUTE;
    case 6: return HLSLShaderAttrShaderType::LIBRARY;
    case 7: return HLSLShaderAttrShaderType::RAY_GENERATION;
    case 8: return HLSLShaderAttrShaderType::INTERSECTION;
    case 9: return HLSLShaderAttrShaderType::ANY_HIT;
    case 10: return HLSLShaderAttrShaderType::CLOSEST_HIT;
    case 11: return HLSLShaderAttrShaderType::MISS;
    case 12: return HLSLShaderAttrShaderType::CALLABLE;
    case 13: return HLSLShaderAttrShaderType::MESH;
    case 14: return HLSLShaderAttrShaderType::AMPLIFICATION;
    default: __builtin_unreachable();
  }
}

HotAttrSpelling FromPasta(pasta::HotAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return HotAttrSpelling::GNU_HOT;
    case 1: return HotAttrSpelling::CXX11_GNU_HOT;
    case 2: return HotAttrSpelling::C2X_GNU_HOT;
    case 15: return HotAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

IBActionAttrSpelling FromPasta(pasta::IBActionAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return IBActionAttrSpelling::GNU_IBACTION;
    case 1: return IBActionAttrSpelling::CXX11_CLANG_IBACTION;
    case 2: return IBActionAttrSpelling::C2X_CLANG_IBACTION;
    case 15: return IBActionAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

IBOutletAttrSpelling FromPasta(pasta::IBOutletAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return IBOutletAttrSpelling::GNU_IBOUTLET;
    case 1: return IBOutletAttrSpelling::CXX11_CLANG_IBOUTLET;
    case 2: return IBOutletAttrSpelling::C2X_CLANG_IBOUTLET;
    case 15: return IBOutletAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

IBOutletCollectionAttrSpelling FromPasta(pasta::IBOutletCollectionAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return IBOutletCollectionAttrSpelling::GNU_IBOUTLETCOLLECTION;
    case 1: return IBOutletCollectionAttrSpelling::CXX11_CLANG_IBOUTLETCOLLECTION;
    case 2: return IBOutletCollectionAttrSpelling::C2X_CLANG_IBOUTLETCOLLECTION;
    case 15: return IBOutletCollectionAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

IFuncAttrSpelling FromPasta(pasta::IFuncAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return IFuncAttrSpelling::GNU_IFUNC;
    case 1: return IFuncAttrSpelling::CXX11_GNU_IFUNC;
    case 2: return IFuncAttrSpelling::C2X_GNU_IFUNC;
    case 15: return IFuncAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ImplicitCastExprOnStack FromPasta(pasta::ImplicitCastExprOnStack e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ImplicitCastExprOnStack::ON_STACK;
    default: __builtin_unreachable();
  }
}

ImplicitParamDeclImplicitParamKind FromPasta(pasta::ImplicitParamDeclImplicitParamKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ImplicitParamDeclImplicitParamKind::OBJ_C_SELF;
    case 1: return ImplicitParamDeclImplicitParamKind::OBJ_C_CMD;
    case 2: return ImplicitParamDeclImplicitParamKind::CXX_THIS;
    case 3: return ImplicitParamDeclImplicitParamKind::CXXVTT;
    case 4: return ImplicitParamDeclImplicitParamKind::CAPTURED_CONTEXT;
    case 5: return ImplicitParamDeclImplicitParamKind::THREAD_PRIVATE_VARIABLE;
    case 6: return ImplicitParamDeclImplicitParamKind::OTHER;
    default: __builtin_unreachable();
  }
}

InitPriorityAttrSpelling FromPasta(pasta::InitPriorityAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return InitPriorityAttrSpelling::GNU_INITIALIZER_PRIORITY;
    case 1: return InitPriorityAttrSpelling::CXX11_GNU_INITIALIZER_PRIORITY;
    case 15: return InitPriorityAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

IntelOclBiccAttrSpelling FromPasta(pasta::IntelOclBiccAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return IntelOclBiccAttrSpelling::GNU_INTEL_OCL_BICC;
    case 1: return IntelOclBiccAttrSpelling::CXX11_CLANG_INTEL_OCL_BICC;
    case 15: return IntelOclBiccAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

InternalLinkageAttrSpelling FromPasta(pasta::InternalLinkageAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return InternalLinkageAttrSpelling::GNU_INTERNAL_LINKAGE;
    case 1: return InternalLinkageAttrSpelling::CXX11_CLANG_INTERNAL_LINKAGE;
    case 2: return InternalLinkageAttrSpelling::C2X_CLANG_INTERNAL_LINKAGE;
    case 15: return InternalLinkageAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

LTOVisibilityPublicAttrSpelling FromPasta(pasta::LTOVisibilityPublicAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return LTOVisibilityPublicAttrSpelling::GNU_LTO_VISIBILITY_PUBLIC;
    case 1: return LTOVisibilityPublicAttrSpelling::CXX11_CLANG_LTO_VISIBILITY_PUBLIC;
    case 2: return LTOVisibilityPublicAttrSpelling::C2X_CLANG_LTO_VISIBILITY_PUBLIC;
    case 15: return LTOVisibilityPublicAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

LeafAttrSpelling FromPasta(pasta::LeafAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return LeafAttrSpelling::GNU_LEAF;
    case 1: return LeafAttrSpelling::CXX11_GNU_LEAF;
    case 2: return LeafAttrSpelling::C2X_GNU_LEAF;
    case 15: return LeafAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

LifetimeBoundAttrSpelling FromPasta(pasta::LifetimeBoundAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return LifetimeBoundAttrSpelling::GNU_LIFETIMEBOUND;
    case 1: return LifetimeBoundAttrSpelling::CXX11_CLANG_LIFETIMEBOUND;
    case 15: return LifetimeBoundAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

LikelyAttrSpelling FromPasta(pasta::LikelyAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return LikelyAttrSpelling::CXX11_LIKELY;
    case 1: return LikelyAttrSpelling::C2X_CLANG_LIKELY;
    case 15: return LikelyAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

LinkageSpecDeclLanguageIDs FromPasta(pasta::LinkageSpecDeclLanguageIDs e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return LinkageSpecDeclLanguageIDs::C;
    case 2: return LinkageSpecDeclLanguageIDs::CXX;
    default: __builtin_unreachable();
  }
}

LoaderUninitializedAttrSpelling FromPasta(pasta::LoaderUninitializedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return LoaderUninitializedAttrSpelling::GNU_LOADER_UNINITIALIZED;
    case 1: return LoaderUninitializedAttrSpelling::CXX11_CLANG_LOADER_UNINITIALIZED;
    case 2: return LoaderUninitializedAttrSpelling::C2X_CLANG_LOADER_UNINITIALIZED;
    case 15: return LoaderUninitializedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

LoopHintAttrLoopHintState FromPasta(pasta::LoopHintAttrLoopHintState e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return LoopHintAttrLoopHintState::ENABLE;
    case 1: return LoopHintAttrLoopHintState::DISABLE;
    case 2: return LoopHintAttrLoopHintState::NUMERIC;
    case 3: return LoopHintAttrLoopHintState::FIXED_WIDTH;
    case 4: return LoopHintAttrLoopHintState::SCALABLE_WIDTH;
    case 5: return LoopHintAttrLoopHintState::ASSUME_SAFETY;
    case 6: return LoopHintAttrLoopHintState::FULL;
    default: __builtin_unreachable();
  }
}

LoopHintAttrOptionType FromPasta(pasta::LoopHintAttrOptionType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return LoopHintAttrOptionType::VECTORIZE;
    case 1: return LoopHintAttrOptionType::VECTORIZE_WIDTH;
    case 2: return LoopHintAttrOptionType::INTERLEAVE;
    case 3: return LoopHintAttrOptionType::INTERLEAVE_COUNT;
    case 4: return LoopHintAttrOptionType::UNROLL;
    case 5: return LoopHintAttrOptionType::UNROLL_COUNT;
    case 6: return LoopHintAttrOptionType::UNROLL_AND_JAM;
    case 7: return LoopHintAttrOptionType::UNROLL_AND_JAM_COUNT;
    case 8: return LoopHintAttrOptionType::PIPELINE_DISABLED;
    case 9: return LoopHintAttrOptionType::PIPELINE_INITIATION_INTERVAL;
    case 10: return LoopHintAttrOptionType::DISTRIBUTE;
    case 11: return LoopHintAttrOptionType::VECTORIZE_PREDICATE;
    default: __builtin_unreachable();
  }
}

LoopHintAttrSpelling FromPasta(pasta::LoopHintAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return LoopHintAttrSpelling::PRAGMA_CLANG_LOOP;
    case 1: return LoopHintAttrSpelling::PRAGMA_UNROLL;
    case 2: return LoopHintAttrSpelling::PRAGMA_NOUNROLL;
    case 3: return LoopHintAttrSpelling::PRAGMA_UNROLL_AND_JAM;
    case 4: return LoopHintAttrSpelling::PRAGMA_NOUNROLL_AND_JAM;
    case 15: return LoopHintAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

MIGServerRoutineAttrSpelling FromPasta(pasta::MIGServerRoutineAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return MIGServerRoutineAttrSpelling::GNU_MIG_SERVER_ROUTINE;
    case 1: return MIGServerRoutineAttrSpelling::CXX11_CLANG_MIG_SERVER_ROUTINE;
    case 2: return MIGServerRoutineAttrSpelling::C2X_CLANG_MIG_SERVER_ROUTINE;
    case 15: return MIGServerRoutineAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

MSABIAttrSpelling FromPasta(pasta::MSABIAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return MSABIAttrSpelling::GNU_MS_ABI;
    case 1: return MSABIAttrSpelling::CXX11_GNU_MS_ABI;
    case 2: return MSABIAttrSpelling::C2X_GNU_MS_ABI;
    case 15: return MSABIAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

MSInheritanceAttrSpelling FromPasta(pasta::MSInheritanceAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return MSInheritanceAttrSpelling::KEYWORD_SINGLE_INHERITANCE;
    case 1: return MSInheritanceAttrSpelling::KEYWORD_MULTIPLE_INHERITANCE;
    case 2: return MSInheritanceAttrSpelling::KEYWORD_VIRTUAL_INHERITANCE;
    case 3: return MSInheritanceAttrSpelling::KEYWORD_UNSPECIFIED_INHERITANCE;
    case 15: return MSInheritanceAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

MSP430InterruptAttrSpelling FromPasta(pasta::MSP430InterruptAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return MSP430InterruptAttrSpelling::GNU_INTERRUPT;
    case 1: return MSP430InterruptAttrSpelling::CXX11_GNU_INTERRUPT;
    case 2: return MSP430InterruptAttrSpelling::C2X_GNU_INTERRUPT;
    case 15: return MSP430InterruptAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

MSStructAttrSpelling FromPasta(pasta::MSStructAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return MSStructAttrSpelling::GNU_MS_STRUCT;
    case 1: return MSStructAttrSpelling::CXX11_GNU_MS_STRUCT;
    case 2: return MSStructAttrSpelling::C2X_GNU_MS_STRUCT;
    case 15: return MSStructAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

MayAliasAttrSpelling FromPasta(pasta::MayAliasAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return MayAliasAttrSpelling::GNU_MAY_ALIAS;
    case 1: return MayAliasAttrSpelling::CXX11_GNU_MAY_ALIAS;
    case 2: return MayAliasAttrSpelling::C2X_GNU_MAY_ALIAS;
    case 15: return MayAliasAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

MaybeUndefAttrSpelling FromPasta(pasta::MaybeUndefAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return MaybeUndefAttrSpelling::GNU_MAYBE_UNDEF;
    case 1: return MaybeUndefAttrSpelling::CXX11_CLANG_MAYBE_UNDEF;
    case 2: return MaybeUndefAttrSpelling::C2X_CLANG_MAYBE_UNDEF;
    case 15: return MaybeUndefAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

MicroMipsAttrSpelling FromPasta(pasta::MicroMipsAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return MicroMipsAttrSpelling::GNU_MICROMIPS;
    case 1: return MicroMipsAttrSpelling::CXX11_GNU_MICROMIPS;
    case 2: return MicroMipsAttrSpelling::C2X_GNU_MICROMIPS;
    case 15: return MicroMipsAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

MinSizeAttrSpelling FromPasta(pasta::MinSizeAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return MinSizeAttrSpelling::GNU_MINSIZE;
    case 1: return MinSizeAttrSpelling::CXX11_CLANG_MINSIZE;
    case 2: return MinSizeAttrSpelling::C2X_CLANG_MINSIZE;
    case 15: return MinSizeAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

MinVectorWidthAttrSpelling FromPasta(pasta::MinVectorWidthAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return MinVectorWidthAttrSpelling::GNU_MIN_VECTOR_WIDTH;
    case 1: return MinVectorWidthAttrSpelling::CXX11_CLANG_MIN_VECTOR_WIDTH;
    case 2: return MinVectorWidthAttrSpelling::C2X_CLANG_MIN_VECTOR_WIDTH;
    case 15: return MinVectorWidthAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

Mips16AttrSpelling FromPasta(pasta::Mips16AttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return Mips16AttrSpelling::GNU_MIPS16;
    case 1: return Mips16AttrSpelling::CXX11_GNU_MIPS16;
    case 2: return Mips16AttrSpelling::C2X_GNU_MIPS16;
    case 15: return Mips16AttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

MipsInterruptAttrInterruptType FromPasta(pasta::MipsInterruptAttrInterruptType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return MipsInterruptAttrInterruptType::SW0;
    case 1: return MipsInterruptAttrInterruptType::SW1;
    case 2: return MipsInterruptAttrInterruptType::HW0;
    case 3: return MipsInterruptAttrInterruptType::HW1;
    case 4: return MipsInterruptAttrInterruptType::HW2;
    case 5: return MipsInterruptAttrInterruptType::HW3;
    case 6: return MipsInterruptAttrInterruptType::HW4;
    case 7: return MipsInterruptAttrInterruptType::HW5;
    case 8: return MipsInterruptAttrInterruptType::EIC;
    default: __builtin_unreachable();
  }
}

MipsInterruptAttrSpelling FromPasta(pasta::MipsInterruptAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return MipsInterruptAttrSpelling::GNU_INTERRUPT;
    case 1: return MipsInterruptAttrSpelling::CXX11_GNU_INTERRUPT;
    case 2: return MipsInterruptAttrSpelling::C2X_GNU_INTERRUPT;
    case 15: return MipsInterruptAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

MipsLongCallAttrSpelling FromPasta(pasta::MipsLongCallAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return MipsLongCallAttrSpelling::GNU_LONG_CALL;
    case 1: return MipsLongCallAttrSpelling::CXX11_GNU_LONG_CALL;
    case 2: return MipsLongCallAttrSpelling::C2X_GNU_LONG_CALL;
    case 3: return MipsLongCallAttrSpelling::GNU_FAR;
    case 4: return MipsLongCallAttrSpelling::CXX11_GNU_FAR;
    case 5: return MipsLongCallAttrSpelling::C2X_GNU_FAR;
    case 15: return MipsLongCallAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

MipsShortCallAttrSpelling FromPasta(pasta::MipsShortCallAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return MipsShortCallAttrSpelling::GNU_SHORT_CALL;
    case 1: return MipsShortCallAttrSpelling::CXX11_GNU_SHORT_CALL;
    case 2: return MipsShortCallAttrSpelling::C2X_GNU_SHORT_CALL;
    case 3: return MipsShortCallAttrSpelling::GNU_NEAR;
    case 4: return MipsShortCallAttrSpelling::CXX11_GNU_NEAR;
    case 5: return MipsShortCallAttrSpelling::C2X_GNU_NEAR;
    case 15: return MipsShortCallAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ModeAttrSpelling FromPasta(pasta::ModeAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ModeAttrSpelling::GNU_MODE;
    case 1: return ModeAttrSpelling::CXX11_GNU_MODE;
    case 2: return ModeAttrSpelling::C2X_GNU_MODE;
    case 15: return ModeAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

MustTailAttrSpelling FromPasta(pasta::MustTailAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return MustTailAttrSpelling::GNU_MUSTTAIL;
    case 1: return MustTailAttrSpelling::CXX11_CLANG_MUSTTAIL;
    case 2: return MustTailAttrSpelling::C2X_CLANG_MUSTTAIL;
    case 15: return MustTailAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NSConsumedAttrSpelling FromPasta(pasta::NSConsumedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NSConsumedAttrSpelling::GNU_NS_CONSUMED;
    case 1: return NSConsumedAttrSpelling::CXX11_CLANG_NS_CONSUMED;
    case 2: return NSConsumedAttrSpelling::C2X_CLANG_NS_CONSUMED;
    case 15: return NSConsumedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NSConsumesSelfAttrSpelling FromPasta(pasta::NSConsumesSelfAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NSConsumesSelfAttrSpelling::GNU_NS_CONSUMES_SELF;
    case 1: return NSConsumesSelfAttrSpelling::CXX11_CLANG_NS_CONSUMES_SELF;
    case 2: return NSConsumesSelfAttrSpelling::C2X_CLANG_NS_CONSUMES_SELF;
    case 15: return NSConsumesSelfAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NSReturnsAutoreleasedAttrSpelling FromPasta(pasta::NSReturnsAutoreleasedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NSReturnsAutoreleasedAttrSpelling::GNU_NS_RETURNS_AUTORELEASED;
    case 1: return NSReturnsAutoreleasedAttrSpelling::CXX11_CLANG_NS_RETURNS_AUTORELEASED;
    case 2: return NSReturnsAutoreleasedAttrSpelling::C2X_CLANG_NS_RETURNS_AUTORELEASED;
    case 15: return NSReturnsAutoreleasedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NSReturnsNotRetainedAttrSpelling FromPasta(pasta::NSReturnsNotRetainedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NSReturnsNotRetainedAttrSpelling::GNU_NS_RETURNS_NOT_RETAINED;
    case 1: return NSReturnsNotRetainedAttrSpelling::CXX11_CLANG_NS_RETURNS_NOT_RETAINED;
    case 2: return NSReturnsNotRetainedAttrSpelling::C2X_CLANG_NS_RETURNS_NOT_RETAINED;
    case 15: return NSReturnsNotRetainedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NSReturnsRetainedAttrSpelling FromPasta(pasta::NSReturnsRetainedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NSReturnsRetainedAttrSpelling::GNU_NS_RETURNS_RETAINED;
    case 1: return NSReturnsRetainedAttrSpelling::CXX11_CLANG_NS_RETURNS_RETAINED;
    case 2: return NSReturnsRetainedAttrSpelling::C2X_CLANG_NS_RETURNS_RETAINED;
    case 15: return NSReturnsRetainedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NakedAttrSpelling FromPasta(pasta::NakedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NakedAttrSpelling::GNU_NAKED;
    case 1: return NakedAttrSpelling::CXX11_GNU_NAKED;
    case 2: return NakedAttrSpelling::C2X_GNU_NAKED;
    case 3: return NakedAttrSpelling::DECLSPEC_NAKED;
    case 15: return NakedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NamedDeclExplicitVisibilityKind FromPasta(pasta::NamedDeclExplicitVisibilityKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NamedDeclExplicitVisibilityKind::VISIBILITY_FOR_TYPE;
    case 1: return NamedDeclExplicitVisibilityKind::VISIBILITY_FOR_VALUE;
    default: __builtin_unreachable();
  }
}

NoBuiltinAttrSpelling FromPasta(pasta::NoBuiltinAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoBuiltinAttrSpelling::GNU_NO_BUILTIN;
    case 1: return NoBuiltinAttrSpelling::CXX11_CLANG_NO_BUILTIN;
    case 2: return NoBuiltinAttrSpelling::C2X_CLANG_NO_BUILTIN;
    case 15: return NoBuiltinAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoCommonAttrSpelling FromPasta(pasta::NoCommonAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoCommonAttrSpelling::GNU_NOCOMMON;
    case 1: return NoCommonAttrSpelling::CXX11_GNU_NOCOMMON;
    case 2: return NoCommonAttrSpelling::C2X_GNU_NOCOMMON;
    case 15: return NoCommonAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoDebugAttrSpelling FromPasta(pasta::NoDebugAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoDebugAttrSpelling::GNU_NODEBUG;
    case 1: return NoDebugAttrSpelling::CXX11_GNU_NODEBUG;
    case 2: return NoDebugAttrSpelling::C2X_GNU_NODEBUG;
    case 15: return NoDebugAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoDerefAttrSpelling FromPasta(pasta::NoDerefAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoDerefAttrSpelling::GNU_NODEREF;
    case 1: return NoDerefAttrSpelling::CXX11_CLANG_NODEREF;
    case 2: return NoDerefAttrSpelling::C2X_CLANG_NODEREF;
    case 15: return NoDerefAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoDestroyAttrSpelling FromPasta(pasta::NoDestroyAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoDestroyAttrSpelling::GNU_NO_DESTROY;
    case 1: return NoDestroyAttrSpelling::CXX11_CLANG_NO_DESTROY;
    case 15: return NoDestroyAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoDuplicateAttrSpelling FromPasta(pasta::NoDuplicateAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoDuplicateAttrSpelling::GNU_NODUPLICATE;
    case 1: return NoDuplicateAttrSpelling::CXX11_CLANG_NODUPLICATE;
    case 2: return NoDuplicateAttrSpelling::C2X_CLANG_NODUPLICATE;
    case 15: return NoDuplicateAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoEscapeAttrSpelling FromPasta(pasta::NoEscapeAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoEscapeAttrSpelling::GNU_NOESCAPE;
    case 1: return NoEscapeAttrSpelling::CXX11_CLANG_NOESCAPE;
    case 2: return NoEscapeAttrSpelling::C2X_CLANG_NOESCAPE;
    case 15: return NoEscapeAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoInlineAttrSpelling FromPasta(pasta::NoInlineAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoInlineAttrSpelling::KEYWORD_NOINLINE;
    case 1: return NoInlineAttrSpelling::GNU_NOINLINE;
    case 2: return NoInlineAttrSpelling::CXX11_GNU_NOINLINE;
    case 3: return NoInlineAttrSpelling::C2X_GNU_NOINLINE;
    case 4: return NoInlineAttrSpelling::CXX11_CLANG_NOINLINE;
    case 5: return NoInlineAttrSpelling::C2X_CLANG_NOINLINE;
    case 6: return NoInlineAttrSpelling::DECLSPEC_NOINLINE;
    case 15: return NoInlineAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoInstrumentFunctionAttrSpelling FromPasta(pasta::NoInstrumentFunctionAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoInstrumentFunctionAttrSpelling::GNU_NO_INSTRUMENT_FUNCTION;
    case 1: return NoInstrumentFunctionAttrSpelling::CXX11_GNU_NO_INSTRUMENT_FUNCTION;
    case 2: return NoInstrumentFunctionAttrSpelling::C2X_GNU_NO_INSTRUMENT_FUNCTION;
    case 15: return NoInstrumentFunctionAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoMergeAttrSpelling FromPasta(pasta::NoMergeAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoMergeAttrSpelling::GNU_NOMERGE;
    case 1: return NoMergeAttrSpelling::CXX11_CLANG_NOMERGE;
    case 2: return NoMergeAttrSpelling::C2X_CLANG_NOMERGE;
    case 15: return NoMergeAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoMicroMipsAttrSpelling FromPasta(pasta::NoMicroMipsAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoMicroMipsAttrSpelling::GNU_NOMICROMIPS;
    case 1: return NoMicroMipsAttrSpelling::CXX11_GNU_NOMICROMIPS;
    case 2: return NoMicroMipsAttrSpelling::C2X_GNU_NOMICROMIPS;
    case 15: return NoMicroMipsAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoMips16AttrSpelling FromPasta(pasta::NoMips16AttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoMips16AttrSpelling::GNU_NOMIPS16;
    case 1: return NoMips16AttrSpelling::CXX11_GNU_NOMIPS16;
    case 2: return NoMips16AttrSpelling::C2X_GNU_NOMIPS16;
    case 15: return NoMips16AttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoProfileFunctionAttrSpelling FromPasta(pasta::NoProfileFunctionAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoProfileFunctionAttrSpelling::GNU_NO_PROFILE_INSTRUMENT_FUNCTION;
    case 1: return NoProfileFunctionAttrSpelling::CXX11_GNU_NO_PROFILE_INSTRUMENT_FUNCTION;
    case 2: return NoProfileFunctionAttrSpelling::C2X_GNU_NO_PROFILE_INSTRUMENT_FUNCTION;
    case 15: return NoProfileFunctionAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoRandomizeLayoutAttrSpelling FromPasta(pasta::NoRandomizeLayoutAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoRandomizeLayoutAttrSpelling::GNU_NO_RANDOMIZE_LAYOUT;
    case 1: return NoRandomizeLayoutAttrSpelling::CXX11_GNU_NO_RANDOMIZE_LAYOUT;
    case 2: return NoRandomizeLayoutAttrSpelling::C2X_GNU_NO_RANDOMIZE_LAYOUT;
    case 15: return NoRandomizeLayoutAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoReturnAttrSpelling FromPasta(pasta::NoReturnAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoReturnAttrSpelling::GNU_NORETURN;
    case 1: return NoReturnAttrSpelling::CXX11_GNU_NORETURN;
    case 2: return NoReturnAttrSpelling::C2X_GNU_NORETURN;
    case 3: return NoReturnAttrSpelling::DECLSPEC_NORETURN;
    case 15: return NoReturnAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoSanitizeAttrSpelling FromPasta(pasta::NoSanitizeAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoSanitizeAttrSpelling::GNU_NO_SANITIZE;
    case 1: return NoSanitizeAttrSpelling::CXX11_CLANG_NO_SANITIZE;
    case 2: return NoSanitizeAttrSpelling::C2X_CLANG_NO_SANITIZE;
    case 15: return NoSanitizeAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoSpeculativeLoadHardeningAttrSpelling FromPasta(pasta::NoSpeculativeLoadHardeningAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoSpeculativeLoadHardeningAttrSpelling::GNU_NO_SPECULATIVE_LOAD_HARDENING;
    case 1: return NoSpeculativeLoadHardeningAttrSpelling::CXX11_CLANG_NO_SPECULATIVE_LOAD_HARDENING;
    case 2: return NoSpeculativeLoadHardeningAttrSpelling::C2X_CLANG_NO_SPECULATIVE_LOAD_HARDENING;
    case 15: return NoSpeculativeLoadHardeningAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoSplitStackAttrSpelling FromPasta(pasta::NoSplitStackAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoSplitStackAttrSpelling::GNU_NO_SPLIT_STACK;
    case 1: return NoSplitStackAttrSpelling::CXX11_GNU_NO_SPLIT_STACK;
    case 2: return NoSplitStackAttrSpelling::C2X_GNU_NO_SPLIT_STACK;
    case 15: return NoSplitStackAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoStackProtectorAttrSpelling FromPasta(pasta::NoStackProtectorAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoStackProtectorAttrSpelling::GNU_NO_STACK_PROTECTOR;
    case 1: return NoStackProtectorAttrSpelling::CXX11_CLANG_NO_STACK_PROTECTOR;
    case 2: return NoStackProtectorAttrSpelling::C2X_CLANG_NO_STACK_PROTECTOR;
    case 3: return NoStackProtectorAttrSpelling::DECLSPEC_SAFEBUFFERS;
    case 15: return NoStackProtectorAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoThreadSafetyAnalysisAttrSpelling FromPasta(pasta::NoThreadSafetyAnalysisAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoThreadSafetyAnalysisAttrSpelling::GNU_NO_THREAD_SAFETY_ANALYSIS;
    case 1: return NoThreadSafetyAnalysisAttrSpelling::CXX11_CLANG_NO_THREAD_SAFETY_ANALYSIS;
    case 2: return NoThreadSafetyAnalysisAttrSpelling::C2X_CLANG_NO_THREAD_SAFETY_ANALYSIS;
    case 15: return NoThreadSafetyAnalysisAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoThrowAttrSpelling FromPasta(pasta::NoThrowAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoThrowAttrSpelling::GNU_NOTHROW;
    case 1: return NoThrowAttrSpelling::CXX11_GNU_NOTHROW;
    case 2: return NoThrowAttrSpelling::C2X_GNU_NOTHROW;
    case 3: return NoThrowAttrSpelling::DECLSPEC_NOTHROW;
    case 15: return NoThrowAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NoUwtableAttrSpelling FromPasta(pasta::NoUwtableAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NoUwtableAttrSpelling::GNU_NOUWTABLE;
    case 1: return NoUwtableAttrSpelling::CXX11_CLANG_NOUWTABLE;
    case 2: return NoUwtableAttrSpelling::C2X_CLANG_NOUWTABLE;
    case 15: return NoUwtableAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NonNullAttrSpelling FromPasta(pasta::NonNullAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NonNullAttrSpelling::GNU_NONNULL;
    case 1: return NonNullAttrSpelling::CXX11_GNU_NONNULL;
    case 2: return NonNullAttrSpelling::C2X_GNU_NONNULL;
    case 15: return NonNullAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

NotTailCalledAttrSpelling FromPasta(pasta::NotTailCalledAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NotTailCalledAttrSpelling::GNU_NOT_TAIL_CALLED;
    case 1: return NotTailCalledAttrSpelling::CXX11_CLANG_NOT_TAIL_CALLED;
    case 2: return NotTailCalledAttrSpelling::C2X_CLANG_NOT_TAIL_CALLED;
    case 15: return NotTailCalledAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

OMPAllocateDeclAttrAllocatorTypeTy FromPasta(pasta::OMPAllocateDeclAttrAllocatorTypeTy e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OMPAllocateDeclAttrAllocatorTypeTy::OMP_NULL_MEMORY_ALLOC;
    case 1: return OMPAllocateDeclAttrAllocatorTypeTy::OMP_DEFAULT_MEMORY_ALLOC;
    case 2: return OMPAllocateDeclAttrAllocatorTypeTy::OMP_LARGE_CAP_MEMORY_ALLOC;
    case 3: return OMPAllocateDeclAttrAllocatorTypeTy::OMP_CONST_MEMORY_ALLOC;
    case 4: return OMPAllocateDeclAttrAllocatorTypeTy::OMP_HIGH_BW_MEMORY_ALLOC;
    case 5: return OMPAllocateDeclAttrAllocatorTypeTy::OMP_LOW_LAT_MEMORY_ALLOC;
    case 6: return OMPAllocateDeclAttrAllocatorTypeTy::OMPC_GROUP_MEMORY_ALLOC;
    case 7: return OMPAllocateDeclAttrAllocatorTypeTy::OMPP_TEAM_MEMORY_ALLOC;
    case 8: return OMPAllocateDeclAttrAllocatorTypeTy::OMP_THREAD_MEMORY_ALLOC;
    case 9: return OMPAllocateDeclAttrAllocatorTypeTy::OMP_USER_DEFINED_MEMORY_ALLOC;
    default: __builtin_unreachable();
  }
}

OMPDeclareReductionDeclInitKind FromPasta(pasta::OMPDeclareReductionDeclInitKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OMPDeclareReductionDeclInitKind::CALL_INITIALIZER;
    case 1: return OMPDeclareReductionDeclInitKind::DIRECT_INITIALIZER;
    case 2: return OMPDeclareReductionDeclInitKind::COPY_INITIALIZER;
    default: __builtin_unreachable();
  }
}

OMPDeclareSimdDeclAttrBranchStateTy FromPasta(pasta::OMPDeclareSimdDeclAttrBranchStateTy e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OMPDeclareSimdDeclAttrBranchStateTy::UNDEFINED;
    case 1: return OMPDeclareSimdDeclAttrBranchStateTy::INBRANCH;
    case 2: return OMPDeclareSimdDeclAttrBranchStateTy::NOTINBRANCH;
    default: __builtin_unreachable();
  }
}

OMPDeclareTargetDeclAttrDevTypeTy FromPasta(pasta::OMPDeclareTargetDeclAttrDevTypeTy e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OMPDeclareTargetDeclAttrDevTypeTy::HOST;
    case 1: return OMPDeclareTargetDeclAttrDevTypeTy::NO_HOST;
    case 2: return OMPDeclareTargetDeclAttrDevTypeTy::ANY;
    default: __builtin_unreachable();
  }
}

OMPDeclareTargetDeclAttrMapTypeTy FromPasta(pasta::OMPDeclareTargetDeclAttrMapTypeTy e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OMPDeclareTargetDeclAttrMapTypeTy::TO;
    case 1: return OMPDeclareTargetDeclAttrMapTypeTy::ENTER;
    case 2: return OMPDeclareTargetDeclAttrMapTypeTy::LINK;
    default: __builtin_unreachable();
  }
}

OSConsumedAttrSpelling FromPasta(pasta::OSConsumedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OSConsumedAttrSpelling::GNU_OS_CONSUMED;
    case 1: return OSConsumedAttrSpelling::CXX11_CLANG_OS_CONSUMED;
    case 2: return OSConsumedAttrSpelling::C2X_CLANG_OS_CONSUMED;
    case 15: return OSConsumedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

OSConsumesThisAttrSpelling FromPasta(pasta::OSConsumesThisAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OSConsumesThisAttrSpelling::GNU_OS_CONSUMES_THIS;
    case 1: return OSConsumesThisAttrSpelling::CXX11_CLANG_OS_CONSUMES_THIS;
    case 2: return OSConsumesThisAttrSpelling::C2X_CLANG_OS_CONSUMES_THIS;
    case 15: return OSConsumesThisAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

OSReturnsNotRetainedAttrSpelling FromPasta(pasta::OSReturnsNotRetainedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OSReturnsNotRetainedAttrSpelling::GNU_OS_RETURNS_NOT_RETAINED;
    case 1: return OSReturnsNotRetainedAttrSpelling::CXX11_CLANG_OS_RETURNS_NOT_RETAINED;
    case 2: return OSReturnsNotRetainedAttrSpelling::C2X_CLANG_OS_RETURNS_NOT_RETAINED;
    case 15: return OSReturnsNotRetainedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

OSReturnsRetainedAttrSpelling FromPasta(pasta::OSReturnsRetainedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OSReturnsRetainedAttrSpelling::GNU_OS_RETURNS_RETAINED;
    case 1: return OSReturnsRetainedAttrSpelling::CXX11_CLANG_OS_RETURNS_RETAINED;
    case 2: return OSReturnsRetainedAttrSpelling::C2X_CLANG_OS_RETURNS_RETAINED;
    case 15: return OSReturnsRetainedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

OSReturnsRetainedOnNonZeroAttrSpelling FromPasta(pasta::OSReturnsRetainedOnNonZeroAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OSReturnsRetainedOnNonZeroAttrSpelling::GNU_OS_RETURNS_RETAINED_ON_NON_ZERO;
    case 1: return OSReturnsRetainedOnNonZeroAttrSpelling::CXX11_CLANG_OS_RETURNS_RETAINED_ON_NON_ZERO;
    case 2: return OSReturnsRetainedOnNonZeroAttrSpelling::C2X_CLANG_OS_RETURNS_RETAINED_ON_NON_ZERO;
    case 15: return OSReturnsRetainedOnNonZeroAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

OSReturnsRetainedOnZeroAttrSpelling FromPasta(pasta::OSReturnsRetainedOnZeroAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OSReturnsRetainedOnZeroAttrSpelling::GNU_OS_RETURNS_RETAINED_ON_ZERO;
    case 1: return OSReturnsRetainedOnZeroAttrSpelling::CXX11_CLANG_OS_RETURNS_RETAINED_ON_ZERO;
    case 2: return OSReturnsRetainedOnZeroAttrSpelling::C2X_CLANG_OS_RETURNS_RETAINED_ON_ZERO;
    case 15: return OSReturnsRetainedOnZeroAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCBoxableAttrSpelling FromPasta(pasta::ObjCBoxableAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCBoxableAttrSpelling::GNU_OBJC_BOXABLE;
    case 1: return ObjCBoxableAttrSpelling::CXX11_CLANG_OBJC_BOXABLE;
    case 2: return ObjCBoxableAttrSpelling::C2X_CLANG_OBJC_BOXABLE;
    case 15: return ObjCBoxableAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCBridgeAttrSpelling FromPasta(pasta::ObjCBridgeAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCBridgeAttrSpelling::GNU_OBJC_BRIDGE;
    case 1: return ObjCBridgeAttrSpelling::CXX11_CLANG_OBJC_BRIDGE;
    case 2: return ObjCBridgeAttrSpelling::C2X_CLANG_OBJC_BRIDGE;
    case 15: return ObjCBridgeAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCBridgeMutableAttrSpelling FromPasta(pasta::ObjCBridgeMutableAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCBridgeMutableAttrSpelling::GNU_OBJC_BRIDGE_MUTABLE;
    case 1: return ObjCBridgeMutableAttrSpelling::CXX11_CLANG_OBJC_BRIDGE_MUTABLE;
    case 2: return ObjCBridgeMutableAttrSpelling::C2X_CLANG_OBJC_BRIDGE_MUTABLE;
    case 15: return ObjCBridgeMutableAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCBridgeRelatedAttrSpelling FromPasta(pasta::ObjCBridgeRelatedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCBridgeRelatedAttrSpelling::GNU_OBJC_BRIDGE_RELATED;
    case 1: return ObjCBridgeRelatedAttrSpelling::CXX11_CLANG_OBJC_BRIDGE_RELATED;
    case 2: return ObjCBridgeRelatedAttrSpelling::C2X_CLANG_OBJC_BRIDGE_RELATED;
    case 15: return ObjCBridgeRelatedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCClassStubAttrSpelling FromPasta(pasta::ObjCClassStubAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCClassStubAttrSpelling::GNU_OBJC_CLASS_STUB;
    case 1: return ObjCClassStubAttrSpelling::CXX11_CLANG_OBJC_CLASS_STUB;
    case 2: return ObjCClassStubAttrSpelling::C2X_CLANG_OBJC_CLASS_STUB;
    case 15: return ObjCClassStubAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCDesignatedInitializerAttrSpelling FromPasta(pasta::ObjCDesignatedInitializerAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCDesignatedInitializerAttrSpelling::GNU_OBJC_DESIGNATED_INITIALIZER;
    case 1: return ObjCDesignatedInitializerAttrSpelling::CXX11_CLANG_OBJC_DESIGNATED_INITIALIZER;
    case 2: return ObjCDesignatedInitializerAttrSpelling::C2X_CLANG_OBJC_DESIGNATED_INITIALIZER;
    case 15: return ObjCDesignatedInitializerAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCDirectAttrSpelling FromPasta(pasta::ObjCDirectAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCDirectAttrSpelling::GNU_OBJC_DIRECT;
    case 1: return ObjCDirectAttrSpelling::CXX11_CLANG_OBJC_DIRECT;
    case 2: return ObjCDirectAttrSpelling::C2X_CLANG_OBJC_DIRECT;
    case 15: return ObjCDirectAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCDirectMembersAttrSpelling FromPasta(pasta::ObjCDirectMembersAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCDirectMembersAttrSpelling::GNU_OBJC_DIRECT_MEMBERS;
    case 1: return ObjCDirectMembersAttrSpelling::CXX11_CLANG_OBJC_DIRECT_MEMBERS;
    case 2: return ObjCDirectMembersAttrSpelling::C2X_CLANG_OBJC_DIRECT_MEMBERS;
    case 15: return ObjCDirectMembersAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCExceptionAttrSpelling FromPasta(pasta::ObjCExceptionAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCExceptionAttrSpelling::GNU_OBJC_EXCEPTION;
    case 1: return ObjCExceptionAttrSpelling::CXX11_CLANG_OBJC_EXCEPTION;
    case 2: return ObjCExceptionAttrSpelling::C2X_CLANG_OBJC_EXCEPTION;
    case 15: return ObjCExceptionAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCExplicitProtocolImplAttrSpelling FromPasta(pasta::ObjCExplicitProtocolImplAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCExplicitProtocolImplAttrSpelling::GNU_OBJC_PROTOCOL_REQUIRES_EXPLICIT_IMPLEMENTATION;
    case 1: return ObjCExplicitProtocolImplAttrSpelling::CXX11_CLANG_OBJC_PROTOCOL_REQUIRES_EXPLICIT_IMPLEMENTATION;
    case 2: return ObjCExplicitProtocolImplAttrSpelling::C2X_CLANG_OBJC_PROTOCOL_REQUIRES_EXPLICIT_IMPLEMENTATION;
    case 15: return ObjCExplicitProtocolImplAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCExternallyRetainedAttrSpelling FromPasta(pasta::ObjCExternallyRetainedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCExternallyRetainedAttrSpelling::GNU_OBJC_EXTERNALLY_RETAINED;
    case 1: return ObjCExternallyRetainedAttrSpelling::CXX11_CLANG_OBJC_EXTERNALLY_RETAINED;
    case 2: return ObjCExternallyRetainedAttrSpelling::C2X_CLANG_OBJC_EXTERNALLY_RETAINED;
    case 15: return ObjCExternallyRetainedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCGCAttrSpelling FromPasta(pasta::ObjCGCAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCGCAttrSpelling::GNU_OBJC_GC;
    case 1: return ObjCGCAttrSpelling::CXX11_CLANG_OBJC_GC;
    case 2: return ObjCGCAttrSpelling::C2X_CLANG_OBJC_GC;
    case 15: return ObjCGCAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCIndependentClassAttrSpelling FromPasta(pasta::ObjCIndependentClassAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCIndependentClassAttrSpelling::GNU_OBJC_INDEPENDENT_CLASS;
    case 1: return ObjCIndependentClassAttrSpelling::CXX11_CLANG_OBJC_INDEPENDENT_CLASS;
    case 2: return ObjCIndependentClassAttrSpelling::C2X_CLANG_OBJC_INDEPENDENT_CLASS;
    case 15: return ObjCIndependentClassAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCIvarDeclAccessControl FromPasta(pasta::ObjCIvarDeclAccessControl e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCIvarDeclAccessControl::NONE;
    case 1: return ObjCIvarDeclAccessControl::PRIVATE;
    case 2: return ObjCIvarDeclAccessControl::PROTECTED;
    case 3: return ObjCIvarDeclAccessControl::PUBLIC;
    case 4: return ObjCIvarDeclAccessControl::PACKAGE;
    default: __builtin_unreachable();
  }
}

ObjCMessageExprReceiverKind FromPasta(pasta::ObjCMessageExprReceiverKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCMessageExprReceiverKind::CLASS;
    case 1: return ObjCMessageExprReceiverKind::INSTANCE;
    case 2: return ObjCMessageExprReceiverKind::SUPER_CLASS;
    case 3: return ObjCMessageExprReceiverKind::SUPER_INSTANCE;
    default: __builtin_unreachable();
  }
}

ObjCMethodDeclImplementationControl FromPasta(pasta::ObjCMethodDeclImplementationControl e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCMethodDeclImplementationControl::NONE;
    case 1: return ObjCMethodDeclImplementationControl::REQUIRED;
    case 2: return ObjCMethodDeclImplementationControl::OPTIONAL;
    default: __builtin_unreachable();
  }
}

ObjCMethodFamilyAttrFamilyKind FromPasta(pasta::ObjCMethodFamilyAttrFamilyKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCMethodFamilyAttrFamilyKind::NONE;
    case 1: return ObjCMethodFamilyAttrFamilyKind::ALLOC;
    case 2: return ObjCMethodFamilyAttrFamilyKind::COPY;
    case 3: return ObjCMethodFamilyAttrFamilyKind::INITIALIZER;
    case 4: return ObjCMethodFamilyAttrFamilyKind::MUTABLE_COPY;
    case 5: return ObjCMethodFamilyAttrFamilyKind::NEW;
    default: __builtin_unreachable();
  }
}

ObjCMethodFamilyAttrSpelling FromPasta(pasta::ObjCMethodFamilyAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCMethodFamilyAttrSpelling::GNU_OBJC_METHOD_FAMILY;
    case 1: return ObjCMethodFamilyAttrSpelling::CXX11_CLANG_OBJC_METHOD_FAMILY;
    case 2: return ObjCMethodFamilyAttrSpelling::C2X_CLANG_OBJC_METHOD_FAMILY;
    case 15: return ObjCMethodFamilyAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCNSObjectAttrSpelling FromPasta(pasta::ObjCNSObjectAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCNSObjectAttrSpelling::GNUNS_OBJECT;
    case 1: return ObjCNSObjectAttrSpelling::CXX11_CLANG_NS_OBJECT;
    case 2: return ObjCNSObjectAttrSpelling::C2X_CLANG_NS_OBJECT;
    case 15: return ObjCNSObjectAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCNonLazyClassAttrSpelling FromPasta(pasta::ObjCNonLazyClassAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCNonLazyClassAttrSpelling::GNU_OBJC_NONLAZY_CLASS;
    case 1: return ObjCNonLazyClassAttrSpelling::CXX11_CLANG_OBJC_NONLAZY_CLASS;
    case 2: return ObjCNonLazyClassAttrSpelling::C2X_CLANG_OBJC_NONLAZY_CLASS;
    case 15: return ObjCNonLazyClassAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCNonRuntimeProtocolAttrSpelling FromPasta(pasta::ObjCNonRuntimeProtocolAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCNonRuntimeProtocolAttrSpelling::GNU_OBJC_NON_RUNTIME_PROTOCOL;
    case 1: return ObjCNonRuntimeProtocolAttrSpelling::CXX11_CLANG_OBJC_NON_RUNTIME_PROTOCOL;
    case 2: return ObjCNonRuntimeProtocolAttrSpelling::C2X_CLANG_OBJC_NON_RUNTIME_PROTOCOL;
    case 15: return ObjCNonRuntimeProtocolAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCOwnershipAttrSpelling FromPasta(pasta::ObjCOwnershipAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCOwnershipAttrSpelling::GNU_OBJC_OWNERSHIP;
    case 1: return ObjCOwnershipAttrSpelling::CXX11_CLANG_OBJC_OWNERSHIP;
    case 2: return ObjCOwnershipAttrSpelling::C2X_CLANG_OBJC_OWNERSHIP;
    case 15: return ObjCOwnershipAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCPreciseLifetimeAttrSpelling FromPasta(pasta::ObjCPreciseLifetimeAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCPreciseLifetimeAttrSpelling::GNU_OBJC_PRECISE_LIFETIME;
    case 1: return ObjCPreciseLifetimeAttrSpelling::CXX11_CLANG_OBJC_PRECISE_LIFETIME;
    case 2: return ObjCPreciseLifetimeAttrSpelling::C2X_CLANG_OBJC_PRECISE_LIFETIME;
    case 15: return ObjCPreciseLifetimeAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCPropertyDeclPropertyControl FromPasta(pasta::ObjCPropertyDeclPropertyControl e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCPropertyDeclPropertyControl::NONE;
    case 1: return ObjCPropertyDeclPropertyControl::REQUIRED;
    case 2: return ObjCPropertyDeclPropertyControl::OPTIONAL;
    default: __builtin_unreachable();
  }
}

ObjCPropertyDeclSetterKind FromPasta(pasta::ObjCPropertyDeclSetterKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCPropertyDeclSetterKind::ASSIGN;
    case 1: return ObjCPropertyDeclSetterKind::RETAIN;
    case 2: return ObjCPropertyDeclSetterKind::COPY;
    case 3: return ObjCPropertyDeclSetterKind::WEAK;
    default: __builtin_unreachable();
  }
}

ObjCPropertyImplDeclKind FromPasta(pasta::ObjCPropertyImplDeclKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCPropertyImplDeclKind::SYNTHESIZE;
    case 1: return ObjCPropertyImplDeclKind::DYNAMIC;
    default: __builtin_unreachable();
  }
}

ObjCRequiresPropertyDefsAttrSpelling FromPasta(pasta::ObjCRequiresPropertyDefsAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCRequiresPropertyDefsAttrSpelling::GNU_OBJC_REQUIRES_PROPERTY_DEFINITIONS;
    case 1: return ObjCRequiresPropertyDefsAttrSpelling::CXX11_CLANG_OBJC_REQUIRES_PROPERTY_DEFINITIONS;
    case 2: return ObjCRequiresPropertyDefsAttrSpelling::C2X_CLANG_OBJC_REQUIRES_PROPERTY_DEFINITIONS;
    case 15: return ObjCRequiresPropertyDefsAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCRequiresSuperAttrSpelling FromPasta(pasta::ObjCRequiresSuperAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCRequiresSuperAttrSpelling::GNU_OBJC_REQUIRES_SUPER;
    case 1: return ObjCRequiresSuperAttrSpelling::CXX11_CLANG_OBJC_REQUIRES_SUPER;
    case 2: return ObjCRequiresSuperAttrSpelling::C2X_CLANG_OBJC_REQUIRES_SUPER;
    case 15: return ObjCRequiresSuperAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCReturnsInnerPointerAttrSpelling FromPasta(pasta::ObjCReturnsInnerPointerAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCReturnsInnerPointerAttrSpelling::GNU_OBJC_RETURNS_INNER_POINTER;
    case 1: return ObjCReturnsInnerPointerAttrSpelling::CXX11_CLANG_OBJC_RETURNS_INNER_POINTER;
    case 2: return ObjCReturnsInnerPointerAttrSpelling::C2X_CLANG_OBJC_RETURNS_INNER_POINTER;
    case 15: return ObjCReturnsInnerPointerAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCRootClassAttrSpelling FromPasta(pasta::ObjCRootClassAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCRootClassAttrSpelling::GNU_OBJC_ROOT_CLASS;
    case 1: return ObjCRootClassAttrSpelling::CXX11_CLANG_OBJC_ROOT_CLASS;
    case 2: return ObjCRootClassAttrSpelling::C2X_CLANG_OBJC_ROOT_CLASS;
    case 15: return ObjCRootClassAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCRuntimeNameAttrSpelling FromPasta(pasta::ObjCRuntimeNameAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCRuntimeNameAttrSpelling::GNU_OBJC_RUNTIME_NAME;
    case 1: return ObjCRuntimeNameAttrSpelling::CXX11_CLANG_OBJC_RUNTIME_NAME;
    case 2: return ObjCRuntimeNameAttrSpelling::C2X_CLANG_OBJC_RUNTIME_NAME;
    case 15: return ObjCRuntimeNameAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCRuntimeVisibleAttrSpelling FromPasta(pasta::ObjCRuntimeVisibleAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCRuntimeVisibleAttrSpelling::GNU_OBJC_RUNTIME_VISIBLE;
    case 1: return ObjCRuntimeVisibleAttrSpelling::CXX11_CLANG_OBJC_RUNTIME_VISIBLE;
    case 2: return ObjCRuntimeVisibleAttrSpelling::C2X_CLANG_OBJC_RUNTIME_VISIBLE;
    case 15: return ObjCRuntimeVisibleAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ObjCSubclassingRestrictedAttrSpelling FromPasta(pasta::ObjCSubclassingRestrictedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCSubclassingRestrictedAttrSpelling::GNU_OBJC_SUBCLASSING_RESTRICTED;
    case 1: return ObjCSubclassingRestrictedAttrSpelling::CXX11_CLANG_OBJC_SUBCLASSING_RESTRICTED;
    case 2: return ObjCSubclassingRestrictedAttrSpelling::C2X_CLANG_OBJC_SUBCLASSING_RESTRICTED;
    case 15: return ObjCSubclassingRestrictedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

OpenCLAccessAttrSpelling FromPasta(pasta::OpenCLAccessAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenCLAccessAttrSpelling::KEYWORD_READ_ONLY;
    case 2: return OpenCLAccessAttrSpelling::KEYWORD_WRITE_ONLY;
    case 4: return OpenCLAccessAttrSpelling::KEYWORD_READ_WRITE;
    case 15: return OpenCLAccessAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

OpenCLConstantAddressSpaceAttrSpelling FromPasta(pasta::OpenCLConstantAddressSpaceAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenCLConstantAddressSpaceAttrSpelling::KEYWORD_CONSTANT;
    case 2: return OpenCLConstantAddressSpaceAttrSpelling::GNU_OPENCL_CONSTANT;
    case 3: return OpenCLConstantAddressSpaceAttrSpelling::CXX11_CLANG_OPENCL_CONSTANT;
    case 4: return OpenCLConstantAddressSpaceAttrSpelling::C2X_CLANG_OPENCL_CONSTANT;
    case 15: return OpenCLConstantAddressSpaceAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

OpenCLGenericAddressSpaceAttrSpelling FromPasta(pasta::OpenCLGenericAddressSpaceAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenCLGenericAddressSpaceAttrSpelling::KEYWORD_GENERIC;
    case 2: return OpenCLGenericAddressSpaceAttrSpelling::GNU_OPENCL_GENERIC;
    case 3: return OpenCLGenericAddressSpaceAttrSpelling::CXX11_CLANG_OPENCL_GENERIC;
    case 4: return OpenCLGenericAddressSpaceAttrSpelling::C2X_CLANG_OPENCL_GENERIC;
    case 15: return OpenCLGenericAddressSpaceAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

OpenCLGlobalAddressSpaceAttrSpelling FromPasta(pasta::OpenCLGlobalAddressSpaceAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenCLGlobalAddressSpaceAttrSpelling::KEYWORD_GLOBAL;
    case 2: return OpenCLGlobalAddressSpaceAttrSpelling::GNU_OPENCL_GLOBAL;
    case 3: return OpenCLGlobalAddressSpaceAttrSpelling::CXX11_CLANG_OPENCL_GLOBAL;
    case 4: return OpenCLGlobalAddressSpaceAttrSpelling::C2X_CLANG_OPENCL_GLOBAL;
    case 15: return OpenCLGlobalAddressSpaceAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

OpenCLGlobalDeviceAddressSpaceAttrSpelling FromPasta(pasta::OpenCLGlobalDeviceAddressSpaceAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenCLGlobalDeviceAddressSpaceAttrSpelling::GNU_OPENCL_GLOBAL_DEVICE;
    case 1: return OpenCLGlobalDeviceAddressSpaceAttrSpelling::CXX11_CLANG_OPENCL_GLOBAL_DEVICE;
    case 2: return OpenCLGlobalDeviceAddressSpaceAttrSpelling::C2X_CLANG_OPENCL_GLOBAL_DEVICE;
    case 15: return OpenCLGlobalDeviceAddressSpaceAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

OpenCLGlobalHostAddressSpaceAttrSpelling FromPasta(pasta::OpenCLGlobalHostAddressSpaceAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenCLGlobalHostAddressSpaceAttrSpelling::GNU_OPENCL_GLOBAL_HOST;
    case 1: return OpenCLGlobalHostAddressSpaceAttrSpelling::CXX11_CLANG_OPENCL_GLOBAL_HOST;
    case 2: return OpenCLGlobalHostAddressSpaceAttrSpelling::C2X_CLANG_OPENCL_GLOBAL_HOST;
    case 15: return OpenCLGlobalHostAddressSpaceAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

OpenCLKernelAttrSpelling FromPasta(pasta::OpenCLKernelAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenCLKernelAttrSpelling::KEYWORD_KERNEL;
    case 15: return OpenCLKernelAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

OpenCLLocalAddressSpaceAttrSpelling FromPasta(pasta::OpenCLLocalAddressSpaceAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenCLLocalAddressSpaceAttrSpelling::KEYWORD_LOCAL;
    case 2: return OpenCLLocalAddressSpaceAttrSpelling::GNU_OPENCL_LOCAL;
    case 3: return OpenCLLocalAddressSpaceAttrSpelling::CXX11_CLANG_OPENCL_LOCAL;
    case 4: return OpenCLLocalAddressSpaceAttrSpelling::C2X_CLANG_OPENCL_LOCAL;
    case 15: return OpenCLLocalAddressSpaceAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

OpenCLPrivateAddressSpaceAttrSpelling FromPasta(pasta::OpenCLPrivateAddressSpaceAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenCLPrivateAddressSpaceAttrSpelling::KEYWORD_PRIVATE;
    case 2: return OpenCLPrivateAddressSpaceAttrSpelling::GNU_OPENCL_PRIVATE;
    case 3: return OpenCLPrivateAddressSpaceAttrSpelling::CXX11_CLANG_OPENCL_PRIVATE;
    case 4: return OpenCLPrivateAddressSpaceAttrSpelling::C2X_CLANG_OPENCL_PRIVATE;
    case 15: return OpenCLPrivateAddressSpaceAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

OptimizeNoneAttrSpelling FromPasta(pasta::OptimizeNoneAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OptimizeNoneAttrSpelling::GNU_OPTNONE;
    case 1: return OptimizeNoneAttrSpelling::CXX11_CLANG_OPTNONE;
    case 2: return OptimizeNoneAttrSpelling::C2X_CLANG_OPTNONE;
    case 15: return OptimizeNoneAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

OverloadableAttrSpelling FromPasta(pasta::OverloadableAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OverloadableAttrSpelling::GNU_OVERLOADABLE;
    case 1: return OverloadableAttrSpelling::CXX11_CLANG_OVERLOADABLE;
    case 2: return OverloadableAttrSpelling::C2X_CLANG_OVERLOADABLE;
    case 15: return OverloadableAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

OwnershipAttrOwnershipKind FromPasta(pasta::OwnershipAttrOwnershipKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OwnershipAttrOwnershipKind::HOLDS;
    case 1: return OwnershipAttrOwnershipKind::RETURNS;
    case 2: return OwnershipAttrOwnershipKind::TAKES;
    default: __builtin_unreachable();
  }
}

OwnershipAttrSpelling FromPasta(pasta::OwnershipAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OwnershipAttrSpelling::GNU_OWNERSHIP_HOLDS;
    case 1: return OwnershipAttrSpelling::CXX11_CLANG_OWNERSHIP_HOLDS;
    case 2: return OwnershipAttrSpelling::C2X_CLANG_OWNERSHIP_HOLDS;
    case 3: return OwnershipAttrSpelling::GNU_OWNERSHIP_RETURNS;
    case 4: return OwnershipAttrSpelling::CXX11_CLANG_OWNERSHIP_RETURNS;
    case 5: return OwnershipAttrSpelling::C2X_CLANG_OWNERSHIP_RETURNS;
    case 6: return OwnershipAttrSpelling::GNU_OWNERSHIP_TAKES;
    case 7: return OwnershipAttrSpelling::CXX11_CLANG_OWNERSHIP_TAKES;
    case 8: return OwnershipAttrSpelling::C2X_CLANG_OWNERSHIP_TAKES;
    case 15: return OwnershipAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

PackedAttrSpelling FromPasta(pasta::PackedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PackedAttrSpelling::GNU_PACKED;
    case 1: return PackedAttrSpelling::CXX11_GNU_PACKED;
    case 2: return PackedAttrSpelling::C2X_GNU_PACKED;
    case 15: return PackedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ParamTypestateAttrConsumedState FromPasta(pasta::ParamTypestateAttrConsumedState e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ParamTypestateAttrConsumedState::UNKNOWN;
    case 1: return ParamTypestateAttrConsumedState::CONSUMED;
    case 2: return ParamTypestateAttrConsumedState::UNCONSUMED;
    default: __builtin_unreachable();
  }
}

ParamTypestateAttrSpelling FromPasta(pasta::ParamTypestateAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ParamTypestateAttrSpelling::GNU_PARAMETER_TYPESTATE;
    case 1: return ParamTypestateAttrSpelling::CXX11_CLANG_PARAMETER_TYPESTATE;
    case 15: return ParamTypestateAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

PascalAttrSpelling FromPasta(pasta::PascalAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PascalAttrSpelling::GNU_PASCAL;
    case 1: return PascalAttrSpelling::CXX11_CLANG_PASCAL;
    case 2: return PascalAttrSpelling::C2X_CLANG_PASCAL;
    case 3: return PascalAttrSpelling::KEYWORD_PASCAL;
    case 15: return PascalAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

PassObjectSizeAttrSpelling FromPasta(pasta::PassObjectSizeAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PassObjectSizeAttrSpelling::GNU_PASS_OBJECT_SIZE;
    case 1: return PassObjectSizeAttrSpelling::CXX11_CLANG_PASS_OBJECT_SIZE;
    case 2: return PassObjectSizeAttrSpelling::C2X_CLANG_PASS_OBJECT_SIZE;
    case 3: return PassObjectSizeAttrSpelling::GNU_PASS_DYNAMIC_OBJECT_SIZE;
    case 4: return PassObjectSizeAttrSpelling::CXX11_CLANG_PASS_DYNAMIC_OBJECT_SIZE;
    case 5: return PassObjectSizeAttrSpelling::C2X_CLANG_PASS_DYNAMIC_OBJECT_SIZE;
    case 15: return PassObjectSizeAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

PatchableFunctionEntryAttrSpelling FromPasta(pasta::PatchableFunctionEntryAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PatchableFunctionEntryAttrSpelling::GNU_PATCHABLE_FUNCTION_ENTRY;
    case 1: return PatchableFunctionEntryAttrSpelling::CXX11_GNU_PATCHABLE_FUNCTION_ENTRY;
    case 2: return PatchableFunctionEntryAttrSpelling::C2X_GNU_PATCHABLE_FUNCTION_ENTRY;
    case 15: return PatchableFunctionEntryAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

PcsAttrPCSType FromPasta(pasta::PcsAttrPCSType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PcsAttrPCSType::AAPCS;
    case 1: return PcsAttrPCSType::VFP;
    default: __builtin_unreachable();
  }
}

PcsAttrSpelling FromPasta(pasta::PcsAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PcsAttrSpelling::GNU_PCS;
    case 1: return PcsAttrSpelling::CXX11_GNU_PCS;
    case 2: return PcsAttrSpelling::C2X_GNU_PCS;
    case 15: return PcsAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

PredefinedExprIdentKind FromPasta(pasta::PredefinedExprIdentKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PredefinedExprIdentKind::FUNC;
    case 1: return PredefinedExprIdentKind::FUNCTION;
    case 2: return PredefinedExprIdentKind::L_FUNCTION;
    case 3: return PredefinedExprIdentKind::FUNC_D_NAME;
    case 4: return PredefinedExprIdentKind::FUNC_SIG;
    case 5: return PredefinedExprIdentKind::L_FUNC_SIG;
    case 6: return PredefinedExprIdentKind::PRETTY_FUNCTION;
    case 7: return PredefinedExprIdentKind::PRETTY_FUNCTION_NO_VIRTUAL;
    default: __builtin_unreachable();
  }
}

PreferredNameAttrSpelling FromPasta(pasta::PreferredNameAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PreferredNameAttrSpelling::GNU_PREFERRED_NAME;
    case 1: return PreferredNameAttrSpelling::CXX11_CLANG_PREFERRED_NAME;
    case 15: return PreferredNameAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

PreserveAllAttrSpelling FromPasta(pasta::PreserveAllAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PreserveAllAttrSpelling::GNU_PRESERVE_ALL;
    case 1: return PreserveAllAttrSpelling::CXX11_CLANG_PRESERVE_ALL;
    case 2: return PreserveAllAttrSpelling::C2X_CLANG_PRESERVE_ALL;
    case 15: return PreserveAllAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

PreserveMostAttrSpelling FromPasta(pasta::PreserveMostAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PreserveMostAttrSpelling::GNU_PRESERVE_MOST;
    case 1: return PreserveMostAttrSpelling::CXX11_CLANG_PRESERVE_MOST;
    case 2: return PreserveMostAttrSpelling::C2X_CLANG_PRESERVE_MOST;
    case 15: return PreserveMostAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

PtGuardedVarAttrSpelling FromPasta(pasta::PtGuardedVarAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PtGuardedVarAttrSpelling::GNU_PT_GUARDED_VARIABLE;
    case 1: return PtGuardedVarAttrSpelling::CXX11_CLANG_PT_GUARDED_VARIABLE;
    case 15: return PtGuardedVarAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

PureAttrSpelling FromPasta(pasta::PureAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PureAttrSpelling::GNU_PURE;
    case 1: return PureAttrSpelling::CXX11_GNU_PURE;
    case 2: return PureAttrSpelling::C2X_GNU_PURE;
    case 15: return PureAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

QualifiedTypeDestructionKind FromPasta(pasta::QualifiedTypeDestructionKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return QualifiedTypeDestructionKind::NONE;
    case 1: return QualifiedTypeDestructionKind::CXX_DESTRUCTOR;
    case 2: return QualifiedTypeDestructionKind::OBJC_STRONG_LIFETIME;
    case 3: return QualifiedTypeDestructionKind::OBJC_WEAK_LIFETIME;
    case 4: return QualifiedTypeDestructionKind::NONTRIVIAL_C_STRUCT;
    default: __builtin_unreachable();
  }
}

QualifiedTypePrimitiveCopyKind FromPasta(pasta::QualifiedTypePrimitiveCopyKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return QualifiedTypePrimitiveCopyKind::TRIVIAL;
    case 1: return QualifiedTypePrimitiveCopyKind::VOLATILE_TRIVIAL;
    case 2: return QualifiedTypePrimitiveCopyKind::ARC_STRONG;
    case 3: return QualifiedTypePrimitiveCopyKind::ARC_WEAK;
    case 4: return QualifiedTypePrimitiveCopyKind::STRUCT;
    default: __builtin_unreachable();
  }
}

QualifiedTypePrimitiveDefaultInitializeKind FromPasta(pasta::QualifiedTypePrimitiveDefaultInitializeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return QualifiedTypePrimitiveDefaultInitializeKind::TRIVIAL;
    case 1: return QualifiedTypePrimitiveDefaultInitializeKind::ARC_STRONG;
    case 2: return QualifiedTypePrimitiveDefaultInitializeKind::ARC_WEAK;
    case 3: return QualifiedTypePrimitiveDefaultInitializeKind::STRUCT;
    default: __builtin_unreachable();
  }
}

RISCVInterruptAttrInterruptType FromPasta(pasta::RISCVInterruptAttrInterruptType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return RISCVInterruptAttrInterruptType::USER;
    case 1: return RISCVInterruptAttrInterruptType::SUPERVISOR;
    case 2: return RISCVInterruptAttrInterruptType::MACHINE;
    default: __builtin_unreachable();
  }
}

RISCVInterruptAttrSpelling FromPasta(pasta::RISCVInterruptAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return RISCVInterruptAttrSpelling::GNU_INTERRUPT;
    case 1: return RISCVInterruptAttrSpelling::CXX11_GNU_INTERRUPT;
    case 2: return RISCVInterruptAttrSpelling::C2X_GNU_INTERRUPT;
    case 15: return RISCVInterruptAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

RandomizeLayoutAttrSpelling FromPasta(pasta::RandomizeLayoutAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return RandomizeLayoutAttrSpelling::GNU_RANDOMIZE_LAYOUT;
    case 1: return RandomizeLayoutAttrSpelling::CXX11_GNU_RANDOMIZE_LAYOUT;
    case 2: return RandomizeLayoutAttrSpelling::C2X_GNU_RANDOMIZE_LAYOUT;
    case 15: return RandomizeLayoutAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ReadOnlyPlacementAttrSpelling FromPasta(pasta::ReadOnlyPlacementAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ReadOnlyPlacementAttrSpelling::GNU_ENFORCE_READ_ONLY_PLACEMENT;
    case 1: return ReadOnlyPlacementAttrSpelling::CXX11_CLANG_ENFORCE_READ_ONLY_PLACEMENT;
    case 2: return ReadOnlyPlacementAttrSpelling::C2X_CLANG_ENFORCE_READ_ONLY_PLACEMENT;
    case 15: return ReadOnlyPlacementAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

RecordDeclArgPassingKind FromPasta(pasta::RecordDeclArgPassingKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return RecordDeclArgPassingKind::CAN_PASS_IN_REGS;
    case 1: return RecordDeclArgPassingKind::CANNOT_PASS_IN_REGS;
    case 2: return RecordDeclArgPassingKind::CAN_NEVER_PASS_IN_REGS;
    default: __builtin_unreachable();
  }
}

RegCallAttrSpelling FromPasta(pasta::RegCallAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return RegCallAttrSpelling::GNU_REGCALL;
    case 1: return RegCallAttrSpelling::CXX11_GNU_REGCALL;
    case 2: return RegCallAttrSpelling::C2X_GNU_REGCALL;
    case 3: return RegCallAttrSpelling::KEYWORD_REGCALL;
    case 15: return RegCallAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ReinitializesAttrSpelling FromPasta(pasta::ReinitializesAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ReinitializesAttrSpelling::GNU_REINITIALIZES;
    case 1: return ReinitializesAttrSpelling::CXX11_CLANG_REINITIALIZES;
    case 15: return ReinitializesAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ReleaseCapabilityAttrSpelling FromPasta(pasta::ReleaseCapabilityAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ReleaseCapabilityAttrSpelling::GNU_RELEASE_CAPABILITY;
    case 1: return ReleaseCapabilityAttrSpelling::CXX11_CLANG_RELEASE_CAPABILITY;
    case 2: return ReleaseCapabilityAttrSpelling::GNU_RELEASE_SHARED_CAPABILITY;
    case 3: return ReleaseCapabilityAttrSpelling::CXX11_CLANG_RELEASE_SHARED_CAPABILITY;
    case 4: return ReleaseCapabilityAttrSpelling::GNU_RELEASE_GENERIC_CAPABILITY;
    case 5: return ReleaseCapabilityAttrSpelling::CXX11_CLANG_RELEASE_GENERIC_CAPABILITY;
    case 6: return ReleaseCapabilityAttrSpelling::GNU_UNLOCK_FUNCTION;
    case 7: return ReleaseCapabilityAttrSpelling::CXX11_CLANG_UNLOCK_FUNCTION;
    case 15: return ReleaseCapabilityAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ReleaseHandleAttrSpelling FromPasta(pasta::ReleaseHandleAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ReleaseHandleAttrSpelling::GNU_RELEASE_HANDLE;
    case 1: return ReleaseHandleAttrSpelling::CXX11_CLANG_RELEASE_HANDLE;
    case 2: return ReleaseHandleAttrSpelling::C2X_CLANG_RELEASE_HANDLE;
    case 15: return ReleaseHandleAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

RequiresCapabilityAttrSpelling FromPasta(pasta::RequiresCapabilityAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return RequiresCapabilityAttrSpelling::GNU_REQUIRES_CAPABILITY;
    case 1: return RequiresCapabilityAttrSpelling::CXX11_CLANG_REQUIRES_CAPABILITY;
    case 2: return RequiresCapabilityAttrSpelling::GNU_EXCLUSIVE_LOCKS_REQUIRED;
    case 3: return RequiresCapabilityAttrSpelling::CXX11_CLANG_EXCLUSIVE_LOCKS_REQUIRED;
    case 4: return RequiresCapabilityAttrSpelling::GNU_REQUIRES_SHARED_CAPABILITY;
    case 5: return RequiresCapabilityAttrSpelling::CXX11_CLANG_REQUIRES_SHARED_CAPABILITY;
    case 6: return RequiresCapabilityAttrSpelling::GNU_SHARED_LOCKS_REQUIRED;
    case 7: return RequiresCapabilityAttrSpelling::CXX11_CLANG_SHARED_LOCKS_REQUIRED;
    case 15: return RequiresCapabilityAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

RestrictAttrSpelling FromPasta(pasta::RestrictAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return RestrictAttrSpelling::DECLSPEC_RESTRICT;
    case 1: return RestrictAttrSpelling::GNU_MALLOC;
    case 2: return RestrictAttrSpelling::CXX11_GNU_MALLOC;
    case 3: return RestrictAttrSpelling::C2X_GNU_MALLOC;
    case 15: return RestrictAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

RetainAttrSpelling FromPasta(pasta::RetainAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return RetainAttrSpelling::GNU_RETAIN;
    case 1: return RetainAttrSpelling::CXX11_GNU_RETAIN;
    case 2: return RetainAttrSpelling::C2X_GNU_RETAIN;
    case 15: return RetainAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ReturnTypestateAttrConsumedState FromPasta(pasta::ReturnTypestateAttrConsumedState e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ReturnTypestateAttrConsumedState::UNKNOWN;
    case 1: return ReturnTypestateAttrConsumedState::CONSUMED;
    case 2: return ReturnTypestateAttrConsumedState::UNCONSUMED;
    default: __builtin_unreachable();
  }
}

ReturnTypestateAttrSpelling FromPasta(pasta::ReturnTypestateAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ReturnTypestateAttrSpelling::GNU_RETURN_TYPESTATE;
    case 1: return ReturnTypestateAttrSpelling::CXX11_CLANG_RETURN_TYPESTATE;
    case 15: return ReturnTypestateAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ReturnsNonNullAttrSpelling FromPasta(pasta::ReturnsNonNullAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ReturnsNonNullAttrSpelling::GNU_RETURNS_NONNULL;
    case 1: return ReturnsNonNullAttrSpelling::CXX11_GNU_RETURNS_NONNULL;
    case 2: return ReturnsNonNullAttrSpelling::C2X_GNU_RETURNS_NONNULL;
    case 15: return ReturnsNonNullAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ReturnsTwiceAttrSpelling FromPasta(pasta::ReturnsTwiceAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ReturnsTwiceAttrSpelling::GNU_RETURNS_TWICE;
    case 1: return ReturnsTwiceAttrSpelling::CXX11_GNU_RETURNS_TWICE;
    case 2: return ReturnsTwiceAttrSpelling::C2X_GNU_RETURNS_TWICE;
    case 15: return ReturnsTwiceAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

SYCLKernelAttrSpelling FromPasta(pasta::SYCLKernelAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SYCLKernelAttrSpelling::GNU_SYCL_KERNEL;
    case 1: return SYCLKernelAttrSpelling::CXX11_CLANG_SYCL_KERNEL;
    case 2: return SYCLKernelAttrSpelling::C2X_CLANG_SYCL_KERNEL;
    case 15: return SYCLKernelAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

SYCLSpecialClassAttrSpelling FromPasta(pasta::SYCLSpecialClassAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SYCLSpecialClassAttrSpelling::GNU_SYCL_SPECIAL_CLASS;
    case 1: return SYCLSpecialClassAttrSpelling::CXX11_CLANG_SYCL_SPECIAL_CLASS;
    case 2: return SYCLSpecialClassAttrSpelling::C2X_CLANG_SYCL_SPECIAL_CLASS;
    case 15: return SYCLSpecialClassAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ScopedLockableAttrSpelling FromPasta(pasta::ScopedLockableAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ScopedLockableAttrSpelling::GNU_SCOPED_LOCKABLE;
    case 1: return ScopedLockableAttrSpelling::CXX11_CLANG_SCOPED_LOCKABLE;
    case 15: return ScopedLockableAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

SectionAttrSpelling FromPasta(pasta::SectionAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SectionAttrSpelling::GNU_SECTION;
    case 1: return SectionAttrSpelling::CXX11_GNU_SECTION;
    case 2: return SectionAttrSpelling::C2X_GNU_SECTION;
    case 3: return SectionAttrSpelling::DECLSPEC_ALLOCATE;
    case 15: return SectionAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

SelectAnyAttrSpelling FromPasta(pasta::SelectAnyAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SelectAnyAttrSpelling::DECLSPEC_SELECTANY;
    case 1: return SelectAnyAttrSpelling::GNU_SELECTANY;
    case 2: return SelectAnyAttrSpelling::CXX11_GNU_SELECTANY;
    case 3: return SelectAnyAttrSpelling::C2X_GNU_SELECTANY;
    case 15: return SelectAnyAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

SentinelAttrSpelling FromPasta(pasta::SentinelAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SentinelAttrSpelling::GNU_SENTINEL;
    case 1: return SentinelAttrSpelling::CXX11_GNU_SENTINEL;
    case 2: return SentinelAttrSpelling::C2X_GNU_SENTINEL;
    case 15: return SentinelAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

SetTypestateAttrConsumedState FromPasta(pasta::SetTypestateAttrConsumedState e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SetTypestateAttrConsumedState::UNKNOWN;
    case 1: return SetTypestateAttrConsumedState::CONSUMED;
    case 2: return SetTypestateAttrConsumedState::UNCONSUMED;
    default: __builtin_unreachable();
  }
}

SetTypestateAttrSpelling FromPasta(pasta::SetTypestateAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SetTypestateAttrSpelling::GNU_TYPESTATE;
    case 1: return SetTypestateAttrSpelling::CXX11_CLANG_TYPESTATE;
    case 15: return SetTypestateAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

SourceLocExprIdentKind FromPasta(pasta::SourceLocExprIdentKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SourceLocExprIdentKind::FUNCTION;
    case 1: return SourceLocExprIdentKind::FILE;
    case 2: return SourceLocExprIdentKind::LINE;
    case 3: return SourceLocExprIdentKind::COLUMN;
    case 4: return SourceLocExprIdentKind::SOURCE_TOKEN_STRUCT;
    default: __builtin_unreachable();
  }
}

SpeculativeLoadHardeningAttrSpelling FromPasta(pasta::SpeculativeLoadHardeningAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SpeculativeLoadHardeningAttrSpelling::GNU_SPECULATIVE_LOAD_HARDENING;
    case 1: return SpeculativeLoadHardeningAttrSpelling::CXX11_CLANG_SPECULATIVE_LOAD_HARDENING;
    case 2: return SpeculativeLoadHardeningAttrSpelling::C2X_CLANG_SPECULATIVE_LOAD_HARDENING;
    case 15: return SpeculativeLoadHardeningAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

StandaloneDebugAttrSpelling FromPasta(pasta::StandaloneDebugAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return StandaloneDebugAttrSpelling::GNU_STANDALONE_DEBUG;
    case 1: return StandaloneDebugAttrSpelling::CXX11_CLANG_STANDALONE_DEBUG;
    case 15: return StandaloneDebugAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

StdCallAttrSpelling FromPasta(pasta::StdCallAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return StdCallAttrSpelling::GNU_STDCALL;
    case 1: return StdCallAttrSpelling::CXX11_GNU_STDCALL;
    case 2: return StdCallAttrSpelling::C2X_GNU_STDCALL;
    case 3: return StdCallAttrSpelling::KEYWORD_STDCALL;
    case 15: return StdCallAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

StmtLikelihood FromPasta(pasta::StmtLikelihood e) {
  switch (static_cast<int>(e)) {
    case -1: return StmtLikelihood::UNLIKELY;
    case 0: return StmtLikelihood::NONE;
    case 1: return StmtLikelihood::LIKELY;
    default: __builtin_unreachable();
  }
}

StmtKind FromPasta(pasta::StmtKind e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return StmtKind::GCC_ASM_STMT;
    case 2: return StmtKind::MS_ASM_STMT;
    case 3: return StmtKind::BREAK_STMT;
    case 4: return StmtKind::CXX_CATCH_STMT;
    case 5: return StmtKind::CXX_FOR_RANGE_STMT;
    case 6: return StmtKind::CXX_TRY_STMT;
    case 7: return StmtKind::CAPTURED_STMT;
    case 8: return StmtKind::COMPOUND_STMT;
    case 9: return StmtKind::CONTINUE_STMT;
    case 10: return StmtKind::CORETURN_STMT;
    case 11: return StmtKind::COROUTINE_BODY_STMT;
    case 12: return StmtKind::DECL_STMT;
    case 13: return StmtKind::DO_STMT;
    case 14: return StmtKind::FOR_STMT;
    case 15: return StmtKind::GOTO_STMT;
    case 16: return StmtKind::IF_STMT;
    case 17: return StmtKind::INDIRECT_GOTO_STMT;
    case 18: return StmtKind::MS_DEPENDENT_EXISTS_STMT;
    case 19: return StmtKind::NULL_STMT;
    case 20: return StmtKind::OMP_CANONICAL_LOOP;
    case 21: return StmtKind::OMP_ATOMIC_DIRECTIVE;
    case 22: return StmtKind::OMP_BARRIER_DIRECTIVE;
    case 23: return StmtKind::OMP_CANCEL_DIRECTIVE;
    case 24: return StmtKind::OMP_CANCELLATION_POINT_DIRECTIVE;
    case 25: return StmtKind::OMP_CRITICAL_DIRECTIVE;
    case 26: return StmtKind::OMP_DEPOBJ_DIRECTIVE;
    case 27: return StmtKind::OMP_DISPATCH_DIRECTIVE;
    case 28: return StmtKind::OMP_ERROR_DIRECTIVE;
    case 29: return StmtKind::OMP_FLUSH_DIRECTIVE;
    case 30: return StmtKind::OMP_INTEROP_DIRECTIVE;
    case 31: return StmtKind::OMP_DISTRIBUTE_DIRECTIVE;
    case 32: return StmtKind::OMP_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE;
    case 33: return StmtKind::OMP_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE;
    case 34: return StmtKind::OMP_DISTRIBUTE_SIMD_DIRECTIVE;
    case 35: return StmtKind::OMP_FOR_DIRECTIVE;
    case 36: return StmtKind::OMP_FOR_SIMD_DIRECTIVE;
    case 37: return StmtKind::OMP_GENERIC_LOOP_DIRECTIVE;
    case 38: return StmtKind::OMP_MASKED_TASK_LOOP_DIRECTIVE;
    case 39: return StmtKind::OMP_MASKED_TASK_LOOP_SIMD_DIRECTIVE;
    case 40: return StmtKind::OMP_MASTER_TASK_LOOP_DIRECTIVE;
    case 41: return StmtKind::OMP_MASTER_TASK_LOOP_SIMD_DIRECTIVE;
    case 42: return StmtKind::OMP_PARALLEL_FOR_DIRECTIVE;
    case 43: return StmtKind::OMP_PARALLEL_FOR_SIMD_DIRECTIVE;
    case 44: return StmtKind::OMP_PARALLEL_GENERIC_LOOP_DIRECTIVE;
    case 45: return StmtKind::OMP_PARALLEL_MASKED_TASK_LOOP_DIRECTIVE;
    case 46: return StmtKind::OMP_PARALLEL_MASKED_TASK_LOOP_SIMD_DIRECTIVE;
    case 47: return StmtKind::OMP_PARALLEL_MASTER_TASK_LOOP_DIRECTIVE;
    case 48: return StmtKind::OMP_PARALLEL_MASTER_TASK_LOOP_SIMD_DIRECTIVE;
    case 49: return StmtKind::OMP_SIMD_DIRECTIVE;
    case 50: return StmtKind::OMP_TARGET_PARALLEL_FOR_SIMD_DIRECTIVE;
    case 51: return StmtKind::OMP_TARGET_PARALLEL_GENERIC_LOOP_DIRECTIVE;
    case 52: return StmtKind::OMP_TARGET_SIMD_DIRECTIVE;
    case 53: return StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_DIRECTIVE;
    case 54: return StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE;
    case 55: return StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE;
    case 56: return StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE;
    case 57: return StmtKind::OMP_TARGET_TEAMS_GENERIC_LOOP_DIRECTIVE;
    case 58: return StmtKind::OMP_TASK_LOOP_DIRECTIVE;
    case 59: return StmtKind::OMP_TASK_LOOP_SIMD_DIRECTIVE;
    case 60: return StmtKind::OMP_TEAMS_DISTRIBUTE_DIRECTIVE;
    case 61: return StmtKind::OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE;
    case 62: return StmtKind::OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE;
    case 63: return StmtKind::OMP_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE;
    case 64: return StmtKind::OMP_TEAMS_GENERIC_LOOP_DIRECTIVE;
    case 65: return StmtKind::OMP_TILE_DIRECTIVE;
    case 66: return StmtKind::OMP_UNROLL_DIRECTIVE;
    case 67: return StmtKind::OMP_MASKED_DIRECTIVE;
    case 68: return StmtKind::OMP_MASTER_DIRECTIVE;
    case 69: return StmtKind::OMP_META_DIRECTIVE;
    case 70: return StmtKind::OMP_ORDERED_DIRECTIVE;
    case 71: return StmtKind::OMP_PARALLEL_DIRECTIVE;
    case 72: return StmtKind::OMP_PARALLEL_MASKED_DIRECTIVE;
    case 73: return StmtKind::OMP_PARALLEL_MASTER_DIRECTIVE;
    case 74: return StmtKind::OMP_PARALLEL_SECTIONS_DIRECTIVE;
    case 75: return StmtKind::OMP_SCAN_DIRECTIVE;
    case 76: return StmtKind::OMP_SECTION_DIRECTIVE;
    case 77: return StmtKind::OMP_SECTIONS_DIRECTIVE;
    case 78: return StmtKind::OMP_SINGLE_DIRECTIVE;
    case 79: return StmtKind::OMP_TARGET_DATA_DIRECTIVE;
    case 80: return StmtKind::OMP_TARGET_DIRECTIVE;
    case 81: return StmtKind::OMP_TARGET_ENTER_DATA_DIRECTIVE;
    case 82: return StmtKind::OMP_TARGET_EXIT_DATA_DIRECTIVE;
    case 83: return StmtKind::OMP_TARGET_PARALLEL_DIRECTIVE;
    case 84: return StmtKind::OMP_TARGET_PARALLEL_FOR_DIRECTIVE;
    case 85: return StmtKind::OMP_TARGET_TEAMS_DIRECTIVE;
    case 86: return StmtKind::OMP_TARGET_UPDATE_DIRECTIVE;
    case 87: return StmtKind::OMP_TASK_DIRECTIVE;
    case 88: return StmtKind::OMP_TASKGROUP_DIRECTIVE;
    case 89: return StmtKind::OMP_TASKWAIT_DIRECTIVE;
    case 90: return StmtKind::OMP_TASKYIELD_DIRECTIVE;
    case 91: return StmtKind::OMP_TEAMS_DIRECTIVE;
    case 92: return StmtKind::OBJ_C_AT_CATCH_STMT;
    case 93: return StmtKind::OBJ_C_AT_FINALLY_STMT;
    case 94: return StmtKind::OBJ_C_AT_SYNCHRONIZED_STMT;
    case 95: return StmtKind::OBJ_C_AT_THROW_STMT;
    case 96: return StmtKind::OBJ_C_AT_TRY_STMT;
    case 97: return StmtKind::OBJ_C_AUTORELEASE_POOL_STMT;
    case 98: return StmtKind::OBJ_C_FOR_COLLECTION_STMT;
    case 99: return StmtKind::RETURN_STMT;
    case 100: return StmtKind::SEH_EXCEPT_STMT;
    case 101: return StmtKind::SEH_FINALLY_STMT;
    case 102: return StmtKind::SEH_LEAVE_STMT;
    case 103: return StmtKind::SEH_TRY_STMT;
    case 104: return StmtKind::CASE_STMT;
    case 105: return StmtKind::DEFAULT_STMT;
    case 106: return StmtKind::SWITCH_STMT;
    case 107: return StmtKind::ATTRIBUTED_STMT;
    case 108: return StmtKind::BINARY_CONDITIONAL_OPERATOR;
    case 109: return StmtKind::CONDITIONAL_OPERATOR;
    case 110: return StmtKind::ADDR_LABEL_EXPR;
    case 111: return StmtKind::ARRAY_INIT_INDEX_EXPR;
    case 112: return StmtKind::ARRAY_INIT_LOOP_EXPR;
    case 113: return StmtKind::ARRAY_SUBSCRIPT_EXPR;
    case 114: return StmtKind::ARRAY_TYPE_TRAIT_EXPR;
    case 115: return StmtKind::AS_TYPE_EXPR;
    case 116: return StmtKind::ATOMIC_EXPR;
    case 117: return StmtKind::BINARY_OPERATOR;
    case 118: return StmtKind::COMPOUND_ASSIGN_OPERATOR;
    case 119: return StmtKind::BLOCK_EXPR;
    case 120: return StmtKind::CXX_BIND_TEMPORARY_EXPR;
    case 121: return StmtKind::CXX_BOOL_LITERAL_EXPR;
    case 122: return StmtKind::CXX_CONSTRUCT_EXPR;
    case 123: return StmtKind::CXX_TEMPORARY_OBJECT_EXPR;
    case 124: return StmtKind::CXX_DEFAULT_ARG_EXPR;
    case 125: return StmtKind::CXX_DEFAULT_INIT_EXPR;
    case 126: return StmtKind::CXX_DELETE_EXPR;
    case 127: return StmtKind::CXX_DEPENDENT_SCOPE_MEMBER_EXPR;
    case 128: return StmtKind::CXX_FOLD_EXPR;
    case 129: return StmtKind::CXX_INHERITED_CTOR_INIT_EXPR;
    case 130: return StmtKind::CXX_NEW_EXPR;
    case 131: return StmtKind::CXX_NOEXCEPT_EXPR;
    case 132: return StmtKind::CXX_NULL_PTR_LITERAL_EXPR;
    case 133: return StmtKind::CXX_PAREN_LIST_INIT_EXPR;
    case 134: return StmtKind::CXX_PSEUDO_DESTRUCTOR_EXPR;
    case 135: return StmtKind::CXX_REWRITTEN_BINARY_OPERATOR;
    case 136: return StmtKind::CXX_SCALAR_VALUE_INIT_EXPR;
    case 137: return StmtKind::CXX_STD_INITIALIZER_LIST_EXPR;
    case 138: return StmtKind::CXX_THIS_EXPR;
    case 139: return StmtKind::CXX_THROW_EXPR;
    case 140: return StmtKind::CXX_TYPEID_EXPR;
    case 141: return StmtKind::CXX_UNRESOLVED_CONSTRUCT_EXPR;
    case 142: return StmtKind::CXX_UUIDOF_EXPR;
    case 143: return StmtKind::CALL_EXPR;
    case 144: return StmtKind::CUDA_KERNEL_CALL_EXPR;
    case 145: return StmtKind::CXX_MEMBER_CALL_EXPR;
    case 146: return StmtKind::CXX_OPERATOR_CALL_EXPR;
    case 147: return StmtKind::USER_DEFINED_LITERAL;
    case 148: return StmtKind::BUILTIN_BIT_CAST_EXPR;
    case 149: return StmtKind::C_STYLE_CAST_EXPR;
    case 150: return StmtKind::CXX_FUNCTIONAL_CAST_EXPR;
    case 151: return StmtKind::CXX_ADDRSPACE_CAST_EXPR;
    case 152: return StmtKind::CXX_CONST_CAST_EXPR;
    case 153: return StmtKind::CXX_DYNAMIC_CAST_EXPR;
    case 154: return StmtKind::CXX_REINTERPRET_CAST_EXPR;
    case 155: return StmtKind::CXX_STATIC_CAST_EXPR;
    case 156: return StmtKind::OBJ_C_BRIDGED_CAST_EXPR;
    case 157: return StmtKind::IMPLICIT_CAST_EXPR;
    case 158: return StmtKind::CHARACTER_LITERAL;
    case 159: return StmtKind::CHOOSE_EXPR;
    case 160: return StmtKind::COMPOUND_LITERAL_EXPR;
    case 161: return StmtKind::CONCEPT_SPECIALIZATION_EXPR;
    case 162: return StmtKind::CONVERT_VECTOR_EXPR;
    case 163: return StmtKind::COAWAIT_EXPR;
    case 164: return StmtKind::COYIELD_EXPR;
    case 165: return StmtKind::DECL_REF_EXPR;
    case 166: return StmtKind::DEPENDENT_COAWAIT_EXPR;
    case 167: return StmtKind::DEPENDENT_SCOPE_DECL_REF_EXPR;
    case 168: return StmtKind::DESIGNATED_INIT_EXPR;
    case 169: return StmtKind::DESIGNATED_INIT_UPDATE_EXPR;
    case 170: return StmtKind::EXPRESSION_TRAIT_EXPR;
    case 171: return StmtKind::EXT_VECTOR_ELEMENT_EXPR;
    case 172: return StmtKind::FIXED_POINT_LITERAL;
    case 173: return StmtKind::FLOATING_LITERAL;
    case 174: return StmtKind::CONSTANT_EXPR;
    case 175: return StmtKind::EXPR_WITH_CLEANUPS;
    case 176: return StmtKind::FUNCTION_PARM_PACK_EXPR;
    case 177: return StmtKind::GNU_NULL_EXPR;
    case 178: return StmtKind::GENERIC_SELECTION_EXPR;
    case 179: return StmtKind::IMAGINARY_LITERAL;
    case 180: return StmtKind::IMPLICIT_VALUE_INIT_EXPR;
    case 181: return StmtKind::INIT_LIST_EXPR;
    case 182: return StmtKind::INTEGER_LITERAL;
    case 183: return StmtKind::LAMBDA_EXPR;
    case 184: return StmtKind::MS_PROPERTY_REF_EXPR;
    case 185: return StmtKind::MS_PROPERTY_SUBSCRIPT_EXPR;
    case 186: return StmtKind::MATERIALIZE_TEMPORARY_EXPR;
    case 187: return StmtKind::MATRIX_SUBSCRIPT_EXPR;
    case 188: return StmtKind::MEMBER_EXPR;
    case 189: return StmtKind::NO_INIT_EXPR;
    case 190: return StmtKind::OMP_ARRAY_SECTION_EXPR;
    case 191: return StmtKind::OMP_ARRAY_SHAPING_EXPR;
    case 192: return StmtKind::OMP_ITERATOR_EXPR;
    case 193: return StmtKind::OBJ_C_ARRAY_LITERAL;
    case 194: return StmtKind::OBJ_C_AVAILABILITY_CHECK_EXPR;
    case 195: return StmtKind::OBJ_C_BOOL_LITERAL_EXPR;
    case 196: return StmtKind::OBJ_C_BOXED_EXPR;
    case 197: return StmtKind::OBJ_C_DICTIONARY_LITERAL;
    case 198: return StmtKind::OBJ_C_ENCODE_EXPR;
    case 199: return StmtKind::OBJ_C_INDIRECT_COPY_RESTORE_EXPR;
    case 200: return StmtKind::OBJ_C_ISA_EXPR;
    case 201: return StmtKind::OBJ_C_IVAR_REF_EXPR;
    case 202: return StmtKind::OBJ_C_MESSAGE_EXPR;
    case 203: return StmtKind::OBJ_C_PROPERTY_REF_EXPR;
    case 204: return StmtKind::OBJ_C_PROTOCOL_EXPR;
    case 205: return StmtKind::OBJ_C_SELECTOR_EXPR;
    case 206: return StmtKind::OBJ_C_STRING_LITERAL;
    case 207: return StmtKind::OBJ_C_SUBSCRIPT_REF_EXPR;
    case 208: return StmtKind::OFFSET_OF_EXPR;
    case 209: return StmtKind::OPAQUE_VALUE_EXPR;
    case 210: return StmtKind::UNRESOLVED_LOOKUP_EXPR;
    case 211: return StmtKind::UNRESOLVED_MEMBER_EXPR;
    case 212: return StmtKind::PACK_EXPANSION_EXPR;
    case 213: return StmtKind::PAREN_EXPR;
    case 214: return StmtKind::PAREN_LIST_EXPR;
    case 215: return StmtKind::PREDEFINED_EXPR;
    case 216: return StmtKind::PSEUDO_OBJECT_EXPR;
    case 217: return StmtKind::RECOVERY_EXPR;
    case 218: return StmtKind::REQUIRES_EXPR;
    case 219: return StmtKind::SYCL_UNIQUE_STABLE_NAME_EXPR;
    case 220: return StmtKind::SHUFFLE_VECTOR_EXPR;
    case 221: return StmtKind::SIZE_OF_PACK_EXPR;
    case 222: return StmtKind::SOURCE_LOC_EXPR;
    case 223: return StmtKind::STMT_EXPR;
    case 224: return StmtKind::STRING_LITERAL;
    case 225: return StmtKind::SUBST_NON_TYPE_TEMPLATE_PARM_EXPR;
    case 226: return StmtKind::SUBST_NON_TYPE_TEMPLATE_PARM_PACK_EXPR;
    case 227: return StmtKind::TYPE_TRAIT_EXPR;
    case 228: return StmtKind::TYPO_EXPR;
    case 229: return StmtKind::UNARY_EXPR_OR_TYPE_TRAIT_EXPR;
    case 230: return StmtKind::UNARY_OPERATOR;
    case 231: return StmtKind::VA_ARG_EXPR;
    case 232: return StmtKind::LABEL_STMT;
    case 233: return StmtKind::WHILE_STMT;
    default: __builtin_unreachable();
  }
}

StringLiteralStringKind FromPasta(pasta::StringLiteralStringKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return StringLiteralStringKind::ORDINARY;
    case 1: return StringLiteralStringKind::WIDE;
    case 2: return StringLiteralStringKind::UTF8;
    case 3: return StringLiteralStringKind::UTF16;
    case 4: return StringLiteralStringKind::UTF32;
    default: __builtin_unreachable();
  }
}

SwiftAsyncAttrKind FromPasta(pasta::SwiftAsyncAttrKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SwiftAsyncAttrKind::NONE;
    case 1: return SwiftAsyncAttrKind::SWIFT_PRIVATE;
    case 2: return SwiftAsyncAttrKind::NOT_SWIFT_PRIVATE;
    default: __builtin_unreachable();
  }
}

SwiftAsyncAttrSpelling FromPasta(pasta::SwiftAsyncAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SwiftAsyncAttrSpelling::GNU_SWIFT_ASYNC;
    case 1: return SwiftAsyncAttrSpelling::CXX11_CLANG_SWIFT_ASYNC;
    case 2: return SwiftAsyncAttrSpelling::C2X_CLANG_SWIFT_ASYNC;
    case 15: return SwiftAsyncAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

SwiftAsyncCallAttrSpelling FromPasta(pasta::SwiftAsyncCallAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SwiftAsyncCallAttrSpelling::GNU_SWIFTASYNCCALL;
    case 1: return SwiftAsyncCallAttrSpelling::CXX11_CLANG_SWIFTASYNCCALL;
    case 2: return SwiftAsyncCallAttrSpelling::C2X_CLANG_SWIFTASYNCCALL;
    case 15: return SwiftAsyncCallAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

SwiftAsyncContextAttrSpelling FromPasta(pasta::SwiftAsyncContextAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SwiftAsyncContextAttrSpelling::GNU_SWIFT_ASYNC_CONTEXT;
    case 1: return SwiftAsyncContextAttrSpelling::CXX11_CLANG_SWIFT_ASYNC_CONTEXT;
    case 2: return SwiftAsyncContextAttrSpelling::C2X_CLANG_SWIFT_ASYNC_CONTEXT;
    case 15: return SwiftAsyncContextAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

SwiftAsyncErrorAttrConventionKind FromPasta(pasta::SwiftAsyncErrorAttrConventionKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SwiftAsyncErrorAttrConventionKind::NONE;
    case 1: return SwiftAsyncErrorAttrConventionKind::NON_NULL_ERROR;
    case 2: return SwiftAsyncErrorAttrConventionKind::ZERO_ARGUMENT;
    case 3: return SwiftAsyncErrorAttrConventionKind::NON_ZERO_ARGUMENT;
    default: __builtin_unreachable();
  }
}

SwiftAsyncErrorAttrSpelling FromPasta(pasta::SwiftAsyncErrorAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SwiftAsyncErrorAttrSpelling::GNU_SWIFT_ASYNC_ERROR;
    case 1: return SwiftAsyncErrorAttrSpelling::CXX11_CLANG_SWIFT_ASYNC_ERROR;
    case 2: return SwiftAsyncErrorAttrSpelling::C2X_CLANG_SWIFT_ASYNC_ERROR;
    case 15: return SwiftAsyncErrorAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

SwiftCallAttrSpelling FromPasta(pasta::SwiftCallAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SwiftCallAttrSpelling::GNU_SWIFTCALL;
    case 1: return SwiftCallAttrSpelling::CXX11_CLANG_SWIFTCALL;
    case 2: return SwiftCallAttrSpelling::C2X_CLANG_SWIFTCALL;
    case 15: return SwiftCallAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

SwiftContextAttrSpelling FromPasta(pasta::SwiftContextAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SwiftContextAttrSpelling::GNU_SWIFT_CONTEXT;
    case 1: return SwiftContextAttrSpelling::CXX11_CLANG_SWIFT_CONTEXT;
    case 2: return SwiftContextAttrSpelling::C2X_CLANG_SWIFT_CONTEXT;
    case 15: return SwiftContextAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

SwiftErrorAttrConventionKind FromPasta(pasta::SwiftErrorAttrConventionKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SwiftErrorAttrConventionKind::NONE;
    case 1: return SwiftErrorAttrConventionKind::NON_NULL_ERROR;
    case 2: return SwiftErrorAttrConventionKind::NULL_RESULT;
    case 3: return SwiftErrorAttrConventionKind::ZERO_RESULT;
    case 4: return SwiftErrorAttrConventionKind::NON_ZERO_RESULT;
    default: __builtin_unreachable();
  }
}

SwiftErrorResultAttrSpelling FromPasta(pasta::SwiftErrorResultAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SwiftErrorResultAttrSpelling::GNU_SWIFT_ERROR_RESULT;
    case 1: return SwiftErrorResultAttrSpelling::CXX11_CLANG_SWIFT_ERROR_RESULT;
    case 2: return SwiftErrorResultAttrSpelling::C2X_CLANG_SWIFT_ERROR_RESULT;
    case 15: return SwiftErrorResultAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

SwiftIndirectResultAttrSpelling FromPasta(pasta::SwiftIndirectResultAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SwiftIndirectResultAttrSpelling::GNU_SWIFT_INDIRECT_RESULT;
    case 1: return SwiftIndirectResultAttrSpelling::CXX11_CLANG_SWIFT_INDIRECT_RESULT;
    case 2: return SwiftIndirectResultAttrSpelling::C2X_CLANG_SWIFT_INDIRECT_RESULT;
    case 15: return SwiftIndirectResultAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

SwiftNewTypeAttrNewtypeKind FromPasta(pasta::SwiftNewTypeAttrNewtypeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SwiftNewTypeAttrNewtypeKind::STRUCT;
    case 1: return SwiftNewTypeAttrNewtypeKind::ENUM;
    default: __builtin_unreachable();
  }
}

SwiftNewTypeAttrSpelling FromPasta(pasta::SwiftNewTypeAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SwiftNewTypeAttrSpelling::GNU_SWIFT_NEWTYPE;
    case 1: return SwiftNewTypeAttrSpelling::GNU_SWIFT_WRAPPER;
    case 15: return SwiftNewTypeAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

SysVABIAttrSpelling FromPasta(pasta::SysVABIAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SysVABIAttrSpelling::GNU_SYSV_ABI;
    case 1: return SysVABIAttrSpelling::CXX11_GNU_SYSV_ABI;
    case 2: return SysVABIAttrSpelling::C2X_GNU_SYSV_ABI;
    case 15: return SysVABIAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

TLSModelAttrSpelling FromPasta(pasta::TLSModelAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TLSModelAttrSpelling::GNU_TLS_MODEL;
    case 1: return TLSModelAttrSpelling::CXX11_GNU_TLS_MODEL;
    case 2: return TLSModelAttrSpelling::C2X_GNU_TLS_MODEL;
    case 15: return TLSModelAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

TargetAttrSpelling FromPasta(pasta::TargetAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TargetAttrSpelling::GNU_TARGET;
    case 1: return TargetAttrSpelling::CXX11_GNU_TARGET;
    case 2: return TargetAttrSpelling::C2X_GNU_TARGET;
    case 15: return TargetAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

TargetClonesAttrSpelling FromPasta(pasta::TargetClonesAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TargetClonesAttrSpelling::GNU_TARGET_CLONES;
    case 1: return TargetClonesAttrSpelling::CXX11_GNU_TARGET_CLONES;
    case 2: return TargetClonesAttrSpelling::C2X_GNU_TARGET_CLONES;
    case 15: return TargetClonesAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

TargetVersionAttrSpelling FromPasta(pasta::TargetVersionAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TargetVersionAttrSpelling::GNU_TARGET_VERSION;
    case 1: return TargetVersionAttrSpelling::CXX11_GNU_TARGET_VERSION;
    case 2: return TargetVersionAttrSpelling::C2X_GNU_TARGET_VERSION;
    case 15: return TargetVersionAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

TemplateArgumentKind FromPasta(pasta::TemplateArgumentKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TemplateArgumentKind::EMPTY;
    case 1: return TemplateArgumentKind::TYPE;
    case 2: return TemplateArgumentKind::DECLARATION;
    case 3: return TemplateArgumentKind::NULL_POINTER;
    case 4: return TemplateArgumentKind::INTEGRAL;
    case 5: return TemplateArgumentKind::TEMPLATE;
    case 6: return TemplateArgumentKind::TEMPLATE_EXPANSION;
    case 7: return TemplateArgumentKind::EXPRESSION;
    case 8: return TemplateArgumentKind::PACK;
    default: __builtin_unreachable();
  }
}

TestTypestateAttrConsumedState FromPasta(pasta::TestTypestateAttrConsumedState e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TestTypestateAttrConsumedState::CONSUMED;
    case 1: return TestTypestateAttrConsumedState::UNCONSUMED;
    default: __builtin_unreachable();
  }
}

TestTypestateAttrSpelling FromPasta(pasta::TestTypestateAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TestTypestateAttrSpelling::GNU_TEST_TYPESTATE;
    case 1: return TestTypestateAttrSpelling::CXX11_CLANG_TEST_TYPESTATE;
    case 15: return TestTypestateAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ThisCallAttrSpelling FromPasta(pasta::ThisCallAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ThisCallAttrSpelling::GNU_THISCALL;
    case 1: return ThisCallAttrSpelling::CXX11_GNU_THISCALL;
    case 2: return ThisCallAttrSpelling::C2X_GNU_THISCALL;
    case 3: return ThisCallAttrSpelling::KEYWORD_THISCALL;
    case 15: return ThisCallAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

TransparentUnionAttrSpelling FromPasta(pasta::TransparentUnionAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TransparentUnionAttrSpelling::GNU_TRANSPARENT_UNION;
    case 1: return TransparentUnionAttrSpelling::CXX11_GNU_TRANSPARENT_UNION;
    case 2: return TransparentUnionAttrSpelling::C2X_GNU_TRANSPARENT_UNION;
    case 15: return TransparentUnionAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

TrivialABIAttrSpelling FromPasta(pasta::TrivialABIAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TrivialABIAttrSpelling::GNU_TRIVIAL_ABI;
    case 1: return TrivialABIAttrSpelling::CXX11_CLANG_TRIVIAL_ABI;
    case 15: return TrivialABIAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

TryAcquireCapabilityAttrSpelling FromPasta(pasta::TryAcquireCapabilityAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TryAcquireCapabilityAttrSpelling::GNU_TRY_ACQUIRE_CAPABILITY;
    case 1: return TryAcquireCapabilityAttrSpelling::CXX11_CLANG_TRY_ACQUIRE_CAPABILITY;
    case 2: return TryAcquireCapabilityAttrSpelling::GNU_TRY_ACQUIRE_SHARED_CAPABILITY;
    case 3: return TryAcquireCapabilityAttrSpelling::CXX11_CLANG_TRY_ACQUIRE_SHARED_CAPABILITY;
    case 15: return TryAcquireCapabilityAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

TypeScalarTypeKind FromPasta(pasta::TypeScalarTypeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TypeScalarTypeKind::C_POINTER;
    case 1: return TypeScalarTypeKind::BLOCK_POINTER;
    case 2: return TypeScalarTypeKind::OBJ_C_OBJECT_POINTER;
    case 3: return TypeScalarTypeKind::MEMBER_POINTER;
    case 4: return TypeScalarTypeKind::BOOLEAN;
    case 5: return TypeScalarTypeKind::INTEGRAL;
    case 6: return TypeScalarTypeKind::FLOATING;
    case 7: return TypeScalarTypeKind::INTEGRAL_COMPLEX;
    case 8: return TypeScalarTypeKind::FLOATING_COMPLEX;
    case 9: return TypeScalarTypeKind::FIXED_POINT;
    default: __builtin_unreachable();
  }
}

TypeKind FromPasta(pasta::TypeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TypeKind::ADJUSTED;
    case 1: return TypeKind::DECAYED;
    case 2: return TypeKind::CONSTANT_ARRAY;
    case 3: return TypeKind::DEPENDENT_SIZED_ARRAY;
    case 4: return TypeKind::INCOMPLETE_ARRAY;
    case 5: return TypeKind::VARIABLE_ARRAY;
    case 6: return TypeKind::ATOMIC;
    case 7: return TypeKind::ATTRIBUTED;
    case 8: return TypeKind::BTF_TAG_ATTRIBUTED;
    case 9: return TypeKind::BIT_INT;
    case 10: return TypeKind::BLOCK_POINTER;
    case 11: return TypeKind::BUILTIN;
    case 12: return TypeKind::COMPLEX;
    case 13: return TypeKind::DECLTYPE;
    case 14: return TypeKind::AUTO;
    case 15: return TypeKind::DEDUCED_TEMPLATE_SPECIALIZATION;
    case 16: return TypeKind::DEPENDENT_ADDRESS_SPACE;
    case 17: return TypeKind::DEPENDENT_BIT_INT;
    case 18: return TypeKind::DEPENDENT_NAME;
    case 19: return TypeKind::DEPENDENT_SIZED_EXT_VECTOR;
    case 20: return TypeKind::DEPENDENT_TEMPLATE_SPECIALIZATION;
    case 21: return TypeKind::DEPENDENT_VECTOR;
    case 22: return TypeKind::ELABORATED;
    case 23: return TypeKind::FUNCTION_NO_PROTO;
    case 24: return TypeKind::FUNCTION_PROTO;
    case 25: return TypeKind::INJECTED_CLASS_NAME;
    case 26: return TypeKind::MACRO_QUALIFIED;
    case 27: return TypeKind::CONSTANT_MATRIX;
    case 28: return TypeKind::DEPENDENT_SIZED_MATRIX;
    case 29: return TypeKind::MEMBER_POINTER;
    case 30: return TypeKind::OBJ_C_OBJECT_POINTER;
    case 31: return TypeKind::OBJ_C_OBJECT;
    case 32: return TypeKind::OBJ_C_INTERFACE;
    case 33: return TypeKind::OBJ_C_TYPE_PARAM;
    case 34: return TypeKind::PACK_EXPANSION;
    case 35: return TypeKind::PAREN;
    case 36: return TypeKind::PIPE;
    case 37: return TypeKind::POINTER;
    case 38: return TypeKind::L_VALUE_REFERENCE;
    case 39: return TypeKind::R_VALUE_REFERENCE;
    case 40: return TypeKind::SUBST_TEMPLATE_TYPE_PARM_PACK;
    case 41: return TypeKind::SUBST_TEMPLATE_TYPE_PARM;
    case 42: return TypeKind::ENUM;
    case 43: return TypeKind::RECORD;
    case 44: return TypeKind::TEMPLATE_SPECIALIZATION;
    case 45: return TypeKind::TEMPLATE_TYPE_PARM;
    case 46: return TypeKind::TYPE_OF_EXPR;
    case 47: return TypeKind::TYPE_OF;
    case 48: return TypeKind::TYPEDEF;
    case 49: return TypeKind::UNARY_TRANSFORM;
    case 50: return TypeKind::UNRESOLVED_USING;
    case 51: return TypeKind::USING;
    case 52: return TypeKind::VECTOR;
    case 53: return TypeKind::EXT_VECTOR;
    case 54: return TypeKind::QUALIFIED;
    default: __builtin_unreachable();
  }
}

TypeTagForDatatypeAttrSpelling FromPasta(pasta::TypeTagForDatatypeAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TypeTagForDatatypeAttrSpelling::GNU_TYPE_TAG_FOR_DATATYPE;
    case 1: return TypeTagForDatatypeAttrSpelling::CXX11_CLANG_TYPE_TAG_FOR_DATATYPE;
    case 2: return TypeTagForDatatypeAttrSpelling::C2X_CLANG_TYPE_TAG_FOR_DATATYPE;
    case 15: return TypeTagForDatatypeAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

TypeVisibilityAttrSpelling FromPasta(pasta::TypeVisibilityAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TypeVisibilityAttrSpelling::GNU_TYPE_VISIBILITY;
    case 1: return TypeVisibilityAttrSpelling::CXX11_CLANG_TYPE_VISIBILITY;
    case 2: return TypeVisibilityAttrSpelling::C2X_CLANG_TYPE_VISIBILITY;
    case 15: return TypeVisibilityAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

TypeVisibilityAttrVisibilityType FromPasta(pasta::TypeVisibilityAttrVisibilityType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TypeVisibilityAttrVisibilityType::DEFAULT;
    case 1: return TypeVisibilityAttrVisibilityType::HIDDEN;
    case 2: return TypeVisibilityAttrVisibilityType::PROTECTED;
    default: __builtin_unreachable();
  }
}

UnaryTransformTypeUTTKind FromPasta(pasta::UnaryTransformTypeUTTKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return UnaryTransformTypeUTTKind::ADD_LVALUE_REFERENCE;
    case 1: return UnaryTransformTypeUTTKind::ADD_POINTER;
    case 2: return UnaryTransformTypeUTTKind::ADD_RVALUE_REFERENCE;
    case 3: return UnaryTransformTypeUTTKind::DECAY;
    case 4: return UnaryTransformTypeUTTKind::MAKE_SIGNED;
    case 5: return UnaryTransformTypeUTTKind::MAKE_UNSIGNED;
    case 6: return UnaryTransformTypeUTTKind::REMOVE_ALL_EXTENTS;
    case 7: return UnaryTransformTypeUTTKind::REMOVE_CONST;
    case 8: return UnaryTransformTypeUTTKind::REMOVE_CV;
    case 9: return UnaryTransformTypeUTTKind::REMOVE_CV_REFERENCE;
    case 10: return UnaryTransformTypeUTTKind::REMOVE_EXTENT;
    case 11: return UnaryTransformTypeUTTKind::REMOVE_POINTER;
    case 12: return UnaryTransformTypeUTTKind::REMOVE_REFERENCE;
    case 13: return UnaryTransformTypeUTTKind::REMOVE_RESTRICT;
    case 14: return UnaryTransformTypeUTTKind::REMOVE_VOLATILE;
    case 15: return UnaryTransformTypeUTTKind::ENUM_UNDERLYING_TYPE;
    default: __builtin_unreachable();
  }
}

UnavailableAttrImplicitReason FromPasta(pasta::UnavailableAttrImplicitReason e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return UnavailableAttrImplicitReason::NONE;
    case 1: return UnavailableAttrImplicitReason::ARC_FORBIDDEN_TYPE;
    case 2: return UnavailableAttrImplicitReason::FORBIDDEN_WEAK;
    case 3: return UnavailableAttrImplicitReason::ARC_FORBIDDEN_CONVERSION;
    case 4: return UnavailableAttrImplicitReason::ARC_INIT_RETURNS_UNRELATED;
    case 5: return UnavailableAttrImplicitReason::ARC_FIELD_WITH_OWNERSHIP;
    default: __builtin_unreachable();
  }
}

UnavailableAttrSpelling FromPasta(pasta::UnavailableAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return UnavailableAttrSpelling::GNU_UNAVAILABLE;
    case 1: return UnavailableAttrSpelling::CXX11_CLANG_UNAVAILABLE;
    case 2: return UnavailableAttrSpelling::C2X_CLANG_UNAVAILABLE;
    case 15: return UnavailableAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

UninitializedAttrSpelling FromPasta(pasta::UninitializedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return UninitializedAttrSpelling::GNU_UNINITIALIZED;
    case 1: return UninitializedAttrSpelling::CXX11_CLANG_UNINITIALIZED;
    case 15: return UninitializedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

UnlikelyAttrSpelling FromPasta(pasta::UnlikelyAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return UnlikelyAttrSpelling::CXX11_UNLIKELY;
    case 1: return UnlikelyAttrSpelling::C2X_CLANG_UNLIKELY;
    case 15: return UnlikelyAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

UnusedAttrSpelling FromPasta(pasta::UnusedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return UnusedAttrSpelling::CXX11_MAYBE_UNUSED;
    case 1: return UnusedAttrSpelling::GNU_UNUSED;
    case 2: return UnusedAttrSpelling::CXX11_GNU_UNUSED;
    case 3: return UnusedAttrSpelling::C2X_GNU_UNUSED;
    case 4: return UnusedAttrSpelling::C2X_MAYBE_UNUSED;
    case 15: return UnusedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

UseHandleAttrSpelling FromPasta(pasta::UseHandleAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return UseHandleAttrSpelling::GNU_USE_HANDLE;
    case 1: return UseHandleAttrSpelling::CXX11_CLANG_USE_HANDLE;
    case 2: return UseHandleAttrSpelling::C2X_CLANG_USE_HANDLE;
    case 15: return UseHandleAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

UsedAttrSpelling FromPasta(pasta::UsedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return UsedAttrSpelling::GNU_USED;
    case 1: return UsedAttrSpelling::CXX11_GNU_USED;
    case 2: return UsedAttrSpelling::C2X_GNU_USED;
    case 15: return UsedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

UserDefinedLiteralLiteralOperatorKind FromPasta(pasta::UserDefinedLiteralLiteralOperatorKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return UserDefinedLiteralLiteralOperatorKind::RAW;
    case 1: return UserDefinedLiteralLiteralOperatorKind::TEMPLATE;
    case 2: return UserDefinedLiteralLiteralOperatorKind::INTEGER;
    case 3: return UserDefinedLiteralLiteralOperatorKind::FLOATING;
    case 4: return UserDefinedLiteralLiteralOperatorKind::STRING;
    case 5: return UserDefinedLiteralLiteralOperatorKind::CHARACTER;
    default: __builtin_unreachable();
  }
}

UsingIfExistsAttrSpelling FromPasta(pasta::UsingIfExistsAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return UsingIfExistsAttrSpelling::GNU_USING_IF_EXISTS;
    case 1: return UsingIfExistsAttrSpelling::CXX11_CLANG_USING_IF_EXISTS;
    case 15: return UsingIfExistsAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

UuidAttrSpelling FromPasta(pasta::UuidAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return UuidAttrSpelling::DECLSPEC_UUID;
    case 1: return UuidAttrSpelling::MICROSOFT_UUID;
    case 15: return UuidAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

VarDeclDefinitionKind FromPasta(pasta::VarDeclDefinitionKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return VarDeclDefinitionKind::DECLARATION_ONLY;
    case 1: return VarDeclDefinitionKind::TENTATIVE_DEFINITION;
    case 2: return VarDeclDefinitionKind::DEFINITION;
    default: __builtin_unreachable();
  }
}

VarDeclInitializationStyle FromPasta(pasta::VarDeclInitializationStyle e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return VarDeclInitializationStyle::C_INIT;
    case 1: return VarDeclInitializationStyle::CALL_INITIALIZER;
    case 2: return VarDeclInitializationStyle::LIST_INITIALIZER;
    case 3: return VarDeclInitializationStyle::PARENTHESIS_LIST_INITIALIZER;
    default: __builtin_unreachable();
  }
}

VarDeclTLSKind FromPasta(pasta::VarDeclTLSKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return VarDeclTLSKind::NONE;
    case 1: return VarDeclTLSKind::STATIC;
    case 2: return VarDeclTLSKind::DYNAMIC;
    default: __builtin_unreachable();
  }
}

VecReturnAttrSpelling FromPasta(pasta::VecReturnAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return VecReturnAttrSpelling::GNU_VECRETURN;
    case 1: return VecReturnAttrSpelling::CXX11_CLANG_VECRETURN;
    case 15: return VecReturnAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

VectorCallAttrSpelling FromPasta(pasta::VectorCallAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return VectorCallAttrSpelling::GNU_VECTORCALL;
    case 1: return VectorCallAttrSpelling::CXX11_CLANG_VECTORCALL;
    case 2: return VectorCallAttrSpelling::C2X_CLANG_VECTORCALL;
    case 3: return VectorCallAttrSpelling::KEYWORD_VECTORCALL;
    case 15: return VectorCallAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

VectorTypeVectorKind FromPasta(pasta::VectorTypeVectorKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return VectorTypeVectorKind::GENERIC_VECTOR;
    case 1: return VectorTypeVectorKind::ALTI_VEC_VECTOR;
    case 2: return VectorTypeVectorKind::ALTI_VEC_PIXEL;
    case 3: return VectorTypeVectorKind::ALTI_VEC_BOOLEAN;
    case 4: return VectorTypeVectorKind::NEON_VECTOR;
    case 5: return VectorTypeVectorKind::NEON_POLY_VECTOR;
    case 6: return VectorTypeVectorKind::SVE_FIXED_LENGTH_DATA_VECTOR;
    case 7: return VectorTypeVectorKind::SVE_FIXED_LENGTH_PREDICATE_VECTOR;
    default: __builtin_unreachable();
  }
}

VisibilityAttrSpelling FromPasta(pasta::VisibilityAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return VisibilityAttrSpelling::GNU_VISIBILITY;
    case 1: return VisibilityAttrSpelling::CXX11_GNU_VISIBILITY;
    case 2: return VisibilityAttrSpelling::C2X_GNU_VISIBILITY;
    case 15: return VisibilityAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

VisibilityAttrVisibilityType FromPasta(pasta::VisibilityAttrVisibilityType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return VisibilityAttrVisibilityType::DEFAULT;
    case 1: return VisibilityAttrVisibilityType::HIDDEN;
    case 2: return VisibilityAttrVisibilityType::PROTECTED;
    default: __builtin_unreachable();
  }
}

WarnUnusedAttrSpelling FromPasta(pasta::WarnUnusedAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return WarnUnusedAttrSpelling::GNU_WARN_UNUSED;
    case 1: return WarnUnusedAttrSpelling::CXX11_GNU_WARN_UNUSED;
    case 2: return WarnUnusedAttrSpelling::C2X_GNU_WARN_UNUSED;
    case 15: return WarnUnusedAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

WarnUnusedResultAttrSpelling FromPasta(pasta::WarnUnusedResultAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return WarnUnusedResultAttrSpelling::CXX11_NODISCARD;
    case 1: return WarnUnusedResultAttrSpelling::C2X_NODISCARD;
    case 2: return WarnUnusedResultAttrSpelling::CXX11_CLANG_WARN_UNUSED_RESULT;
    case 3: return WarnUnusedResultAttrSpelling::GNU_WARN_UNUSED_RESULT;
    case 4: return WarnUnusedResultAttrSpelling::CXX11_GNU_WARN_UNUSED_RESULT;
    case 5: return WarnUnusedResultAttrSpelling::C2X_GNU_WARN_UNUSED_RESULT;
    case 15: return WarnUnusedResultAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

WeakAttrSpelling FromPasta(pasta::WeakAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return WeakAttrSpelling::GNU_WEAK;
    case 1: return WeakAttrSpelling::CXX11_GNU_WEAK;
    case 2: return WeakAttrSpelling::C2X_GNU_WEAK;
    case 15: return WeakAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

WeakImportAttrSpelling FromPasta(pasta::WeakImportAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return WeakImportAttrSpelling::GNU_WEAK_IMPORT;
    case 1: return WeakImportAttrSpelling::CXX11_CLANG_WEAK_IMPORT;
    case 2: return WeakImportAttrSpelling::C2X_CLANG_WEAK_IMPORT;
    case 15: return WeakImportAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

WeakRefAttrSpelling FromPasta(pasta::WeakRefAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return WeakRefAttrSpelling::GNU_WEAKREF;
    case 1: return WeakRefAttrSpelling::CXX11_GNU_WEAKREF;
    case 2: return WeakRefAttrSpelling::C2X_GNU_WEAKREF;
    case 15: return WeakRefAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

WebAssemblyExportNameAttrSpelling FromPasta(pasta::WebAssemblyExportNameAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return WebAssemblyExportNameAttrSpelling::GNU_EXPORT_NAME;
    case 1: return WebAssemblyExportNameAttrSpelling::CXX11_CLANG_EXPORT_NAME;
    case 2: return WebAssemblyExportNameAttrSpelling::C2X_CLANG_EXPORT_NAME;
    case 15: return WebAssemblyExportNameAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

WebAssemblyImportModuleAttrSpelling FromPasta(pasta::WebAssemblyImportModuleAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return WebAssemblyImportModuleAttrSpelling::GNU_IMPORT_MODULE;
    case 1: return WebAssemblyImportModuleAttrSpelling::CXX11_CLANG_IMPORT_MODULE;
    case 2: return WebAssemblyImportModuleAttrSpelling::C2X_CLANG_IMPORT_MODULE;
    case 15: return WebAssemblyImportModuleAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

WebAssemblyImportNameAttrSpelling FromPasta(pasta::WebAssemblyImportNameAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return WebAssemblyImportNameAttrSpelling::GNU_IMPORT_NAME;
    case 1: return WebAssemblyImportNameAttrSpelling::CXX11_CLANG_IMPORT_NAME;
    case 2: return WebAssemblyImportNameAttrSpelling::C2X_CLANG_IMPORT_NAME;
    case 15: return WebAssemblyImportNameAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

X86ForceAlignArgPointerAttrSpelling FromPasta(pasta::X86ForceAlignArgPointerAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return X86ForceAlignArgPointerAttrSpelling::GNU_FORCE_ALIGN_ARGUMENT_POINTER;
    case 1: return X86ForceAlignArgPointerAttrSpelling::CXX11_GNU_FORCE_ALIGN_ARGUMENT_POINTER;
    case 2: return X86ForceAlignArgPointerAttrSpelling::C2X_GNU_FORCE_ALIGN_ARGUMENT_POINTER;
    case 15: return X86ForceAlignArgPointerAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

XRayInstrumentAttrSpelling FromPasta(pasta::XRayInstrumentAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return XRayInstrumentAttrSpelling::GNU_XRAY_ALWAYS_INSTRUMENT;
    case 1: return XRayInstrumentAttrSpelling::CXX11_CLANG_XRAY_ALWAYS_INSTRUMENT;
    case 2: return XRayInstrumentAttrSpelling::C2X_CLANG_XRAY_ALWAYS_INSTRUMENT;
    case 3: return XRayInstrumentAttrSpelling::GNU_XRAY_NEVER_INSTRUMENT;
    case 4: return XRayInstrumentAttrSpelling::CXX11_CLANG_XRAY_NEVER_INSTRUMENT;
    case 5: return XRayInstrumentAttrSpelling::C2X_CLANG_XRAY_NEVER_INSTRUMENT;
    case 15: return XRayInstrumentAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

XRayLogArgsAttrSpelling FromPasta(pasta::XRayLogArgsAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return XRayLogArgsAttrSpelling::GNU_XRAY_LOG_ARGUMENTS;
    case 1: return XRayLogArgsAttrSpelling::CXX11_CLANG_XRAY_LOG_ARGUMENTS;
    case 2: return XRayLogArgsAttrSpelling::C2X_CLANG_XRAY_LOG_ARGUMENTS;
    case 15: return XRayLogArgsAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ZeroCallUsedRegsAttrSpelling FromPasta(pasta::ZeroCallUsedRegsAttrSpelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ZeroCallUsedRegsAttrSpelling::GNU_ZERO_CALL_USED_REGS;
    case 1: return ZeroCallUsedRegsAttrSpelling::CXX11_GNU_ZERO_CALL_USED_REGS;
    case 2: return ZeroCallUsedRegsAttrSpelling::C2X_GNU_ZERO_CALL_USED_REGS;
    case 15: return ZeroCallUsedRegsAttrSpelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

ZeroCallUsedRegsAttrZeroCallUsedRegsKind FromPasta(pasta::ZeroCallUsedRegsAttrZeroCallUsedRegsKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ZeroCallUsedRegsAttrZeroCallUsedRegsKind::SKIP;
    case 1: return ZeroCallUsedRegsAttrZeroCallUsedRegsKind::USED_GPR_ARG;
    case 2: return ZeroCallUsedRegsAttrZeroCallUsedRegsKind::USED_GPR;
    case 3: return ZeroCallUsedRegsAttrZeroCallUsedRegsKind::USED_ARGUMENT;
    case 4: return ZeroCallUsedRegsAttrZeroCallUsedRegsKind::USED;
    case 5: return ZeroCallUsedRegsAttrZeroCallUsedRegsKind::ALL_GPR_ARG;
    case 6: return ZeroCallUsedRegsAttrZeroCallUsedRegsKind::ALL_GPR;
    case 7: return ZeroCallUsedRegsAttrZeroCallUsedRegsKind::ALL_ARGUMENT;
    case 8: return ZeroCallUsedRegsAttrZeroCallUsedRegsKind::ALL;
    default: __builtin_unreachable();
  }
}

ASTDumpOutputFormat FromPasta(pasta::ASTDumpOutputFormat e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ASTDumpOutputFormat::DEFAULT;
    case 1: return ASTDumpOutputFormat::JSON;
    default: __builtin_unreachable();
  }
}

AccessSpecifier FromPasta(pasta::AccessSpecifier e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AccessSpecifier::PUBLIC;
    case 1: return AccessSpecifier::PROTECTED;
    case 2: return AccessSpecifier::PRIVATE;
    case 3: return AccessSpecifier::NONE;
    default: __builtin_unreachable();
  }
}

AddrSpaceMapMangling FromPasta(pasta::AddrSpaceMapMangling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AddrSpaceMapMangling::TARGET;
    case 1: return AddrSpaceMapMangling::ON;
    case 2: return AddrSpaceMapMangling::OFF;
    default: __builtin_unreachable();
  }
}

AlignRequirementKind FromPasta(pasta::AlignRequirementKind e) {
  switch (static_cast<int>(e)) {
    case 0: return AlignRequirementKind::NONE;
    case 1: return AlignRequirementKind::REQUIRED_BY_TYPEDEF;
    case 2: return AlignRequirementKind::REQUIRED_BY_RECORD;
    case 3: return AlignRequirementKind::REQUIRED_BY_ENUM;
    default: __builtin_unreachable();
  }
}

AltivecSrcCompatKind FromPasta(pasta::AltivecSrcCompatKind e) {
  switch (static_cast<int>(e)) {
    case 0: return AltivecSrcCompatKind::MIXED;
    case 1: return AltivecSrcCompatKind::GCC;
    case 2: return AltivecSrcCompatKind::XL;
    default: __builtin_unreachable();
  }
}

ArgumentKind FromPasta(pasta::ArgumentKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ArgumentKind::STD_STRING;
    case 1: return ArgumentKind::C_STRING;
    case 2: return ArgumentKind::SINT;
    case 3: return ArgumentKind::UINT;
    case 4: return ArgumentKind::TOKENKIND;
    case 5: return ArgumentKind::IDENTIFIERINFO;
    case 6: return ArgumentKind::ADDRSPACE;
    case 7: return ArgumentKind::QUALIFIED;
    case 8: return ArgumentKind::QUALTYPE;
    case 9: return ArgumentKind::DECLARATIONNAME;
    case 10: return ArgumentKind::NAMEDDECL;
    case 11: return ArgumentKind::NESTEDNAMESPEC;
    case 12: return ArgumentKind::DECLCONTEXT;
    case 13: return ArgumentKind::QUALTYPE_PAIR;
    case 14: return ArgumentKind::ATTRIBUTE;
    default: __builtin_unreachable();
  }
}

ArrayTypeTrait FromPasta(pasta::ArrayTypeTrait e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ArrayTypeTrait::ARRAY_RANK;
    case 1: return ArrayTypeTrait::ARRAY_EXTENT;
    default: __builtin_unreachable();
  }
}

AtomicScopeModelKind FromPasta(pasta::AtomicScopeModelKind e) {
  switch (static_cast<int>(e)) {
    case 0: return AtomicScopeModelKind::NONE;
    case 1: return AtomicScopeModelKind::OPEN_CL;
    case 2: return AtomicScopeModelKind::HIP;
    default: __builtin_unreachable();
  }
}

AutoTypeKeyword FromPasta(pasta::AutoTypeKeyword e) {
  switch (static_cast<int>(e)) {
    case 0: return AutoTypeKeyword::AUTO;
    case 1: return AutoTypeKeyword::DECLTYPE_AUTO;
    case 2: return AutoTypeKeyword::GNU_AUTO_TYPE;
    default: __builtin_unreachable();
  }
}

AvailabilityResult FromPasta(pasta::AvailabilityResult e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AvailabilityResult::AVAILABLE;
    case 1: return AvailabilityResult::NOT_YET_INTRODUCED;
    case 2: return AvailabilityResult::DEPRECATED;
    case 3: return AvailabilityResult::UNAVAILABLE;
    default: __builtin_unreachable();
  }
}

BinaryOperatorKind FromPasta(pasta::BinaryOperatorKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return BinaryOperatorKind::POINTER_MEMORY_D;
    case 1: return BinaryOperatorKind::POINTER_MEMORY_I;
    case 2: return BinaryOperatorKind::MUL;
    case 3: return BinaryOperatorKind::DIV;
    case 4: return BinaryOperatorKind::REM;
    case 5: return BinaryOperatorKind::ADD;
    case 6: return BinaryOperatorKind::SUB;
    case 7: return BinaryOperatorKind::SHL;
    case 8: return BinaryOperatorKind::SHR;
    case 9: return BinaryOperatorKind::CMP;
    case 10: return BinaryOperatorKind::LT;
    case 11: return BinaryOperatorKind::GT;
    case 12: return BinaryOperatorKind::LE;
    case 13: return BinaryOperatorKind::GE;
    case 14: return BinaryOperatorKind::EQ;
    case 15: return BinaryOperatorKind::NE;
    case 16: return BinaryOperatorKind::AND;
    case 17: return BinaryOperatorKind::XOR;
    case 18: return BinaryOperatorKind::OR;
    case 19: return BinaryOperatorKind::L_AND;
    case 20: return BinaryOperatorKind::L_OR;
    case 21: return BinaryOperatorKind::ASSIGN;
    case 22: return BinaryOperatorKind::MUL_ASSIGN;
    case 23: return BinaryOperatorKind::DIV_ASSIGN;
    case 24: return BinaryOperatorKind::REM_ASSIGN;
    case 25: return BinaryOperatorKind::ADD_ASSIGN;
    case 26: return BinaryOperatorKind::SUB_ASSIGN;
    case 27: return BinaryOperatorKind::SHL_ASSIGN;
    case 28: return BinaryOperatorKind::SHR_ASSIGN;
    case 29: return BinaryOperatorKind::AND_ASSIGN;
    case 30: return BinaryOperatorKind::XOR_ASSIGN;
    case 31: return BinaryOperatorKind::OR_ASSIGN;
    case 32: return BinaryOperatorKind::COMMA;
    default: __builtin_unreachable();
  }
}

Bits FromPasta(pasta::Bits e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return Bits::NONE;
    case 1: return Bits::UNEXPANDED_PACK;
    case 2: return Bits::INSTANTIATION;
    case 4: return Bits::TYPE;
    case 8: return Bits::VALUE;
    case 12: return Bits::DEPENDENT;
    case 16: return Bits::ERROR;
    case 32: return Bits::VARIABLY_MODIFIED;
    case 19: return Bits::SYNTACTIC;
    case 62: return Bits::SEMANTIC;
    default: __builtin_unreachable();
  }
}

CallingConv FromPasta(pasta::CallingConv e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CallingConv::C;
    case 1: return CallingConv::X86_STD_CALL;
    case 2: return CallingConv::X86_FAST_CALL;
    case 3: return CallingConv::X86_THIS_CALL;
    case 4: return CallingConv::X86_VECTOR_CALL;
    case 5: return CallingConv::X86_PASCAL;
    case 6: return CallingConv::WIN64;
    case 7: return CallingConv::X8664_SYS_V;
    case 8: return CallingConv::X86_REG_CALL;
    case 9: return CallingConv::AAPCS;
    case 10: return CallingConv::AAPCSVFP;
    case 11: return CallingConv::INTEL_OCL_BICC;
    case 12: return CallingConv::SPIR_FUNCTION;
    case 13: return CallingConv::OPEN_CL_KERNEL;
    case 14: return CallingConv::SWIFT;
    case 15: return CallingConv::SWIFT_ASYNC;
    case 16: return CallingConv::PRESERVE_MOST;
    case 17: return CallingConv::PRESERVE_ALL;
    case 18: return CallingConv::A_ARCH64_VECTOR_CALL;
    case 19: return CallingConv::A_ARCH64_SVEPCS;
    case 20: return CallingConv::AMDGPU_KERNEL_CALL;
    default: __builtin_unreachable();
  }
}

CanThrowResult FromPasta(pasta::CanThrowResult e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CanThrowResult::CANNOT;
    case 1: return CanThrowResult::DEPENDENT;
    case 2: return CanThrowResult::CAN;
    default: __builtin_unreachable();
  }
}

CapturedRegionKind FromPasta(pasta::CapturedRegionKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CapturedRegionKind::DEFAULT;
    case 1: return CapturedRegionKind::OBJ_C_AT_FINALLY;
    case 2: return CapturedRegionKind::OPEN_MP;
    default: __builtin_unreachable();
  }
}

CastKind FromPasta(pasta::CastKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CastKind::DEPENDENT;
    case 1: return CastKind::BIT_CAST;
    case 2: return CastKind::L_VALUE_BIT_CAST;
    case 3: return CastKind::L_VALUE_TO_R_VALUE_BIT_CAST;
    case 4: return CastKind::L_VALUE_TO_R_VALUE;
    case 5: return CastKind::NO_OPERATION;
    case 6: return CastKind::BASE_TO_DERIVED;
    case 7: return CastKind::DERIVED_TO_BASE;
    case 8: return CastKind::UNCHECKED_DERIVED_TO_BASE;
    case 9: return CastKind::DYNAMIC;
    case 10: return CastKind::TO_UNION;
    case 11: return CastKind::ARRAY_TO_POINTER_DECAY;
    case 12: return CastKind::FUNCTION_TO_POINTER_DECAY;
    case 13: return CastKind::NULL_TO_POINTER;
    case 14: return CastKind::NULL_TO_MEMBER_POINTER;
    case 15: return CastKind::BASE_TO_DERIVED_MEMBER_POINTER;
    case 16: return CastKind::DERIVED_TO_BASE_MEMBER_POINTER;
    case 17: return CastKind::MEMBER_POINTER_TO_BOOLEAN;
    case 18: return CastKind::REINTERPRET_MEMBER_POINTER;
    case 19: return CastKind::USER_DEFINED_CONVERSION;
    case 20: return CastKind::CONSTRUCTOR_CONVERSION;
    case 21: return CastKind::INTEGRAL_TO_POINTER;
    case 22: return CastKind::POINTER_TO_INTEGRAL;
    case 23: return CastKind::POINTER_TO_BOOLEAN;
    case 24: return CastKind::TO_VOID;
    case 25: return CastKind::MATRIX_CAST;
    case 26: return CastKind::VECTOR_SPLAT;
    case 27: return CastKind::INTEGRAL_CAST;
    case 28: return CastKind::INTEGRAL_TO_BOOLEAN;
    case 29: return CastKind::INTEGRAL_TO_FLOATING;
    case 30: return CastKind::FLOATING_TO_FIXED_POINT;
    case 31: return CastKind::FIXED_POINT_TO_FLOATING;
    case 32: return CastKind::FIXED_POINT_CAST;
    case 33: return CastKind::FIXED_POINT_TO_INTEGRAL;
    case 34: return CastKind::INTEGRAL_TO_FIXED_POINT;
    case 35: return CastKind::FIXED_POINT_TO_BOOLEAN;
    case 36: return CastKind::FLOATING_TO_INTEGRAL;
    case 37: return CastKind::FLOATING_TO_BOOLEAN;
    case 38: return CastKind::BOOLEAN_TO_SIGNED_INTEGRAL;
    case 39: return CastKind::FLOATING_CAST;
    case 40: return CastKind::C_POINTER_TO_OBJ_C_POINTER_CAST;
    case 41: return CastKind::BLOCK_POINTER_TO_OBJ_C_POINTER_CAST;
    case 42: return CastKind::ANY_POINTER_TO_BLOCK_POINTER_CAST;
    case 43: return CastKind::OBJ_C_OBJECT_L_VALUE_CAST;
    case 44: return CastKind::FLOATING_REAL_TO_COMPLEX;
    case 45: return CastKind::FLOATING_COMPLEX_TO_REAL;
    case 46: return CastKind::FLOATING_COMPLEX_TO_BOOLEAN;
    case 47: return CastKind::FLOATING_COMPLEX_CAST;
    case 48: return CastKind::FLOATING_COMPLEX_TO_INTEGRAL_COMPLEX;
    case 49: return CastKind::INTEGRAL_REAL_TO_COMPLEX;
    case 50: return CastKind::INTEGRAL_COMPLEX_TO_REAL;
    case 51: return CastKind::INTEGRAL_COMPLEX_TO_BOOLEAN;
    case 52: return CastKind::INTEGRAL_COMPLEX_CAST;
    case 53: return CastKind::INTEGRAL_COMPLEX_TO_FLOATING_COMPLEX;
    case 54: return CastKind::ARC_PRODUCE_OBJECT;
    case 55: return CastKind::ARC_CONSUME_OBJECT;
    case 56: return CastKind::ARC_RECLAIM_RETURNED_OBJECT;
    case 57: return CastKind::ARC_EXTEND_BLOCK_OBJECT;
    case 58: return CastKind::ATOMIC_TO_NON_ATOMIC;
    case 59: return CastKind::NON_ATOMIC_TO_ATOMIC;
    case 60: return CastKind::COPY_AND_AUTORELEASE_BLOCK_OBJECT;
    case 61: return CastKind::BUILTIN_FN_TO_FN_POINTER;
    case 62: return CastKind::ZERO_TO_OCL_OPAQUE_TYPE;
    case 63: return CastKind::ADDRESS_SPACE_CONVERSION;
    case 64: return CastKind::INT_TO_OCL_SAMPLER;
    default: __builtin_unreachable();
  }
}

ClangABI FromPasta(pasta::ClangABI e) {
  switch (static_cast<int>(e)) {
    case 0: return ClangABI::VER38;
    case 1: return ClangABI::VER4;
    case 2: return ClangABI::VER6;
    case 3: return ClangABI::VER7;
    case 4: return ClangABI::VER9;
    case 5: return ClangABI::VER11;
    case 6: return ClangABI::VER12;
    case 7: return ClangABI::VER14;
    case 8: return ClangABI::VER15;
    case 9: return ClangABI::LATEST;
    default: __builtin_unreachable();
  }
}

CommentKind FromPasta(pasta::CommentKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CommentKind::INVALID;
    case 1: return CommentKind::ORDINARY_BCPL;
    case 2: return CommentKind::ORDINARY_C;
    case 3: return CommentKind::BCPL_SLASH;
    case 4: return CommentKind::BCPL_EXCL;
    case 5: return CommentKind::JAVA_DOC;
    case 6: return CommentKind::QT;
    case 7: return CommentKind::MERGED;
    default: __builtin_unreachable();
  }
}

ComparisonCategoryResult FromPasta(pasta::ComparisonCategoryResult e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return ComparisonCategoryResult::EQUAL;
    case 1: return ComparisonCategoryResult::EQUIVALENT;
    case 2: return ComparisonCategoryResult::LESS;
    case 3: return ComparisonCategoryResult::GREATER;
    case 4: return ComparisonCategoryResult::UNORDERED;
    default: __builtin_unreachable();
  }
}

ComparisonCategoryType FromPasta(pasta::ComparisonCategoryType e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return ComparisonCategoryType::PARTIAL_ORDERING;
    case 1: return ComparisonCategoryType::WEAK_ORDERING;
    case 2: return ComparisonCategoryType::STRONG_ORDERING;
    default: __builtin_unreachable();
  }
}

CompilingModuleKind FromPasta(pasta::CompilingModuleKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CompilingModuleKind::NONE;
    case 1: return CompilingModuleKind::MODULE_MAP;
    case 2: return CompilingModuleKind::HEADER_UNIT;
    case 3: return CompilingModuleKind::MODULE_INTERFACE;
    default: __builtin_unreachable();
  }
}

ConstexprSpecKind FromPasta(pasta::ConstexprSpecKind e) {
  switch (static_cast<int>(e)) {
    case 0: return ConstexprSpecKind::UNSPECIFIED;
    case 1: return ConstexprSpecKind::CONSTEXPR;
    case 2: return ConstexprSpecKind::CONSTEVAL;
    case 3: return ConstexprSpecKind::CONSTINIT;
    default: __builtin_unreachable();
  }
}

CoreFoundationABI FromPasta(pasta::CoreFoundationABI e) {
  switch (static_cast<int>(e)) {
    case 0: return CoreFoundationABI::UNSPECIFIED;
    case 1: return CoreFoundationABI::STANDALONE;
    case 2: return CoreFoundationABI::OBJECTIVE_C;
    case 3: return CoreFoundationABI::SWIFT;
    case 4: return CoreFoundationABI::SWIFT50;
    case 5: return CoreFoundationABI::SWIFT42;
    case 6: return CoreFoundationABI::SWIFT41;
    default: __builtin_unreachable();
  }
}

DataPositionTy FromPasta(pasta::DataPositionTy e) {
  switch (static_cast<unsigned long>(e)) {
    case 0: return DataPositionTy::POSX;
    case 1: return DataPositionTy::POSV;
    case 2: return DataPositionTy::POSE;
    case 3: return DataPositionTy::POS_UPDATE_EXPRESSION;
    case 4: return DataPositionTy::POSD;
    case 5: return DataPositionTy::POS_CONDITION;
    case 6: return DataPositionTy::POSR;
    default: __builtin_unreachable();
  }
}

DebugSrcHashKind FromPasta(pasta::DebugSrcHashKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DebugSrcHashKind::DSHMD5;
    case 1: return DebugSrcHashKind::DSHSHA1;
    case 2: return DebugSrcHashKind::DSHSHA256;
    default: __builtin_unreachable();
  }
}

DefaultArgKind FromPasta(pasta::DefaultArgKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DefaultArgKind::NONE;
    case 1: return DefaultArgKind::UNPARSED;
    case 2: return DefaultArgKind::UNINSTANTIATED;
    case 3: return DefaultArgKind::NORMAL;
    default: __builtin_unreachable();
  }
}

DefaultCallingConvention FromPasta(pasta::DefaultCallingConvention e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DefaultCallingConvention::NONE;
    case 1: return DefaultCallingConvention::C_DECL;
    case 2: return DefaultCallingConvention::FAST_CALL;
    case 3: return DefaultCallingConvention::STD_CALL;
    case 4: return DefaultCallingConvention::VECTOR_CALL;
    case 5: return DefaultCallingConvention::REG_CALL;
    default: __builtin_unreachable();
  }
}

DefaultVisiblityExportMapping FromPasta(pasta::DefaultVisiblityExportMapping e) {
  switch (static_cast<int>(e)) {
    case 0: return DefaultVisiblityExportMapping::NONE;
    case 1: return DefaultVisiblityExportMapping::EXPLICIT;
    case 2: return DefaultVisiblityExportMapping::ALL;
    default: __builtin_unreachable();
  }
}

DiagnosticLevelMask FromPasta(pasta::DiagnosticLevelMask e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DiagnosticLevelMask::NONE;
    case 1: return DiagnosticLevelMask::NOTE;
    case 2: return DiagnosticLevelMask::REMARK;
    case 4: return DiagnosticLevelMask::WARNING;
    case 8: return DiagnosticLevelMask::ERROR;
    case 15: return DiagnosticLevelMask::ALL;
    default: __builtin_unreachable();
  }
}

ElaboratedTypeKeyword FromPasta(pasta::ElaboratedTypeKeyword e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ElaboratedTypeKeyword::STRUCT;
    case 1: return ElaboratedTypeKeyword::INTERFACE;
    case 2: return ElaboratedTypeKeyword::UNION;
    case 3: return ElaboratedTypeKeyword::CLASS;
    case 4: return ElaboratedTypeKeyword::ENUM;
    case 5: return ElaboratedTypeKeyword::TYPENAME;
    case 6: return ElaboratedTypeKeyword::NONE;
    default: __builtin_unreachable();
  }
}

EmbedBitcodeKind FromPasta(pasta::EmbedBitcodeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return EmbedBitcodeKind::EMBED_OFF;
    case 1: return EmbedBitcodeKind::EMBED_ALL;
    case 2: return EmbedBitcodeKind::EMBED_BITCODE;
    case 3: return EmbedBitcodeKind::EMBED_MARKER;
    default: __builtin_unreachable();
  }
}

EscapeChar FromPasta(pasta::EscapeChar e) {
  switch (static_cast<int>(e)) {
    case 1: return EscapeChar::SINGLE;
    case 2: return EscapeChar::DOUBLE;
    case 3: return EscapeChar::SINGLE_AND_DOUBLE;
    default: __builtin_unreachable();
  }
}

ExceptionHandlingKind FromPasta(pasta::ExceptionHandlingKind e) {
  switch (static_cast<int>(e)) {
    case 0: return ExceptionHandlingKind::NONE;
    case 1: return ExceptionHandlingKind::SJ_LJ;
    case 2: return ExceptionHandlingKind::WIN_EH;
    case 3: return ExceptionHandlingKind::DWARF_CFI;
    case 4: return ExceptionHandlingKind::WASM;
    default: __builtin_unreachable();
  }
}

ExceptionSpecificationType FromPasta(pasta::ExceptionSpecificationType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExceptionSpecificationType::NONE;
    case 1: return ExceptionSpecificationType::DYNAMIC_NONE;
    case 2: return ExceptionSpecificationType::DYNAMIC;
    case 3: return ExceptionSpecificationType::MS_ANY;
    case 4: return ExceptionSpecificationType::NO_THROW;
    case 5: return ExceptionSpecificationType::BASIC_NOEXCEPT;
    case 6: return ExceptionSpecificationType::DEPENDENT_NOEXCEPT;
    case 7: return ExceptionSpecificationType::NOEXCEPT_FALSE;
    case 8: return ExceptionSpecificationType::NOEXCEPT_TRUE;
    case 9: return ExceptionSpecificationType::UNEVALUATED;
    case 10: return ExceptionSpecificationType::UNINSTANTIATED;
    case 11: return ExceptionSpecificationType::UNPARSED;
    default: __builtin_unreachable();
  }
}

ExcessPrecisionKind FromPasta(pasta::ExcessPrecisionKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExcessPrecisionKind::FPP_STANDARD;
    case 1: return ExcessPrecisionKind::FPP_FAST;
    case 2: return ExcessPrecisionKind::FPP_NONE;
    default: __builtin_unreachable();
  }
}

ExclusionType FromPasta(pasta::ExclusionType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExclusionType::ALLOW;
    case 1: return ExclusionType::SKIP;
    case 2: return ExclusionType::FORBID;
    default: __builtin_unreachable();
  }
}

ExplicitSpecKind FromPasta(pasta::ExplicitSpecKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExplicitSpecKind::RESOLVED_FALSE;
    case 1: return ExplicitSpecKind::RESOLVED_TRUE;
    case 2: return ExplicitSpecKind::UNRESOLVED;
    default: __builtin_unreachable();
  }
}

ExprDependence FromPasta(pasta::ExprDependence e) {
  switch (static_cast<unsigned char>(e)) {
    case 1: return ExprDependence::UNEXPANDED_PACK;
    case 2: return ExprDependence::INSTANTIATION;
    case 4: return ExprDependence::TYPE;
    case 8: return ExprDependence::VALUE;
    case 16: return ExprDependence::ERROR;
    case 0: return ExprDependence::NONE;
    case 31: return ExprDependence::ALL;
    case 12: return ExprDependence::TYPE_VALUE;
    case 6: return ExprDependence::TYPE_INSTANTIATION;
    case 10: return ExprDependence::VALUE_INSTANTIATION;
    case 14: return ExprDependence::TYPE_VALUE_INSTANTIATION;
    case 26: return ExprDependence::ERROR_DEPENDENT;
    default: __builtin_unreachable();
  }
}

ExprObjectKind FromPasta(pasta::ExprObjectKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExprObjectKind::ORDINARY;
    case 1: return ExprObjectKind::BIT_FIELD;
    case 2: return ExprObjectKind::VECTOR_COMPONENT;
    case 3: return ExprObjectKind::OBJ_C_PROPERTY;
    case 4: return ExprObjectKind::OBJ_C_SUBSCRIPT;
    case 5: return ExprObjectKind::MATRIX_COMPONENT;
    default: __builtin_unreachable();
  }
}

ExprOffsets FromPasta(pasta::ExprOffsets e) {
  switch (static_cast<int>(e)) {
    case 0: return ExprOffsets::ALLOCATOR;
    case 1: return ExprOffsets::ALLOCATOR_TRAITS;
    case 2: return ExprOffsets::TOTAL;
    default: __builtin_unreachable();
  }
}

ExprValueKind FromPasta(pasta::ExprValueKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExprValueKind::PR_VALUE;
    case 1: return ExprValueKind::L_VALUE;
    case 2: return ExprValueKind::X_VALUE;
    default: __builtin_unreachable();
  }
}

ExpressionTrait FromPasta(pasta::ExpressionTrait e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExpressionTrait::IS_L_VALUE_EXPRESSION;
    case 1: return ExpressionTrait::IS_R_VALUE_EXPRESSION;
    default: __builtin_unreachable();
  }
}

ExtKind FromPasta(pasta::ExtKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExtKind::ALWAYS;
    case 1: return ExtKind::NEVER;
    case 2: return ExtKind::REPLY_HAZY;
    default: __builtin_unreachable();
  }
}

ExtendArgsKind FromPasta(pasta::ExtendArgsKind e) {
  switch (static_cast<int>(e)) {
    case 0: return ExtendArgsKind::EXTEND_TO32;
    case 1: return ExtendArgsKind::EXTEND_TO64;
    default: __builtin_unreachable();
  }
}

FPEvalMethodKind FromPasta(pasta::FPEvalMethodKind e) {
  switch (static_cast<int>(e)) {
    case -1: return FPEvalMethodKind::FEM_INDETERMINABLE;
    case 0: return FPEvalMethodKind::FEM_SOURCE;
    case 1: return FPEvalMethodKind::FEM_DOUBLE;
    case 2: return FPEvalMethodKind::FEM_EXTENDED;
    case 3: return FPEvalMethodKind::FEM_UNSET_ON_COMMAND_LINE;
    default: __builtin_unreachable();
  }
}

FPExceptionModeKind FromPasta(pasta::FPExceptionModeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FPExceptionModeKind::IGNORE;
    case 1: return FPExceptionModeKind::MAY_TRAP;
    case 2: return FPExceptionModeKind::STRICT;
    case 3: return FPExceptionModeKind::DEFAULT;
    default: __builtin_unreachable();
  }
}

FPModeKind FromPasta(pasta::FPModeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FPModeKind::OFF;
    case 1: return FPModeKind::ON;
    case 2: return FPModeKind::FAST;
    case 3: return FPModeKind::FAST_HONOR_PRAGMAS;
    default: __builtin_unreachable();
  }
}

FiniteLoopsKind FromPasta(pasta::FiniteLoopsKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FiniteLoopsKind::LANGUAGE;
    case 1: return FiniteLoopsKind::ALWAYS;
    case 2: return FiniteLoopsKind::NEVER;
    default: __builtin_unreachable();
  }
}

Flags FromPasta(pasta::Flags e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return Flags::F_INLINE;
    case 2: return Flags::F_NESTED;
    default: __builtin_unreachable();
  }
}

FramePointerKind FromPasta(pasta::FramePointerKind e) {
  switch (static_cast<int>(e)) {
    case 0: return FramePointerKind::NONE;
    case 1: return FramePointerKind::NON_LEAF;
    case 2: return FramePointerKind::ALL;
    default: __builtin_unreachable();
  }
}

GC FromPasta(pasta::GC e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return GC::GC_NONE;
    case 1: return GC::WEAK;
    case 2: return GC::STRONG;
    default: __builtin_unreachable();
  }
}

GCMode FromPasta(pasta::GCMode e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return GCMode::NON_GC;
    case 1: return GCMode::GC_ONLY;
    case 2: return GCMode::HYBRID_GC;
    default: __builtin_unreachable();
  }
}

GPUDefaultStreamKind FromPasta(pasta::GPUDefaultStreamKind e) {
  switch (static_cast<int>(e)) {
    case 0: return GPUDefaultStreamKind::LEGACY;
    case 1: return GPUDefaultStreamKind::PER_THREAD;
    default: __builtin_unreachable();
  }
}

GVALinkage FromPasta(pasta::GVALinkage e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return GVALinkage::INTERNAL;
    case 1: return GVALinkage::AVAILABLE_EXTERNALLY;
    case 2: return GVALinkage::DISCARDABLE_ODR;
    case 3: return GVALinkage::STRONG_EXTERNAL;
    case 4: return GVALinkage::STRONG_ODR;
    default: __builtin_unreachable();
  }
}

GetBuiltinTypeError FromPasta(pasta::GetBuiltinTypeError e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return GetBuiltinTypeError::NONE;
    case 1: return GetBuiltinTypeError::MISSING_TYPE;
    case 2: return GetBuiltinTypeError::MISSING_STDIO;
    case 3: return GetBuiltinTypeError::MISSING;
    case 4: return GetBuiltinTypeError::MISSING_UCONTEXT;
    default: __builtin_unreachable();
  }
}

HLSLLangStd FromPasta(pasta::HLSLLangStd e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return HLSLLangStd::HLSL_UNSET;
    case 2015: return HLSLLangStd::HLSL2015;
    case 2016: return HLSLLangStd::HLSL2016;
    case 2017: return HLSLLangStd::HLSL2017;
    case 2018: return HLSLLangStd::HLSL2018;
    case 2021: return HLSLLangStd::HLSL2021;
    case 2029: return HLSLLangStd::HLSL202X;
    default: __builtin_unreachable();
  }
}

ID FromPasta(pasta::ID e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return ID::WORK_GROUP;
    case 2: return ID::DEVICE;
    case 3: return ID::ALL_SVM_DEVICES;
    case 4: return ID::SUB_GROUP;
    default: __builtin_unreachable();
  }
}

IdentifierInfoFlag FromPasta(pasta::IdentifierInfoFlag e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return IdentifierInfoFlag::ZERO_ARGUMENT;
    case 2: return IdentifierInfoFlag::ONE_ARGUMENT;
    case 7: return IdentifierInfoFlag::MULTI_ARGUMENT;
    default: __builtin_unreachable();
  }
}

IfStatementKind FromPasta(pasta::IfStatementKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return IfStatementKind::ORDINARY;
    case 1: return IfStatementKind::CONSTEXPR;
    case 2: return IfStatementKind::CONSTEVAL_NON_NEGATED;
    case 3: return IfStatementKind::CONSTEVAL_NEGATED;
    default: __builtin_unreachable();
  }
}

ImbueAttribute FromPasta(pasta::ImbueAttribute e) {
  switch (static_cast<int>(e)) {
    case 0: return ImbueAttribute::NONE;
    case 1: return ImbueAttribute::ALWAYS;
    case 2: return ImbueAttribute::NEVER;
    case 3: return ImbueAttribute::ALWAYSARG1;
    default: __builtin_unreachable();
  }
}

InClassInitStyle FromPasta(pasta::InClassInitStyle e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return InClassInitStyle::NO_INITIALIZER;
    case 1: return InClassInitStyle::COPY_INITIALIZER;
    case 2: return InClassInitStyle::LIST_INITIALIZER;
    default: __builtin_unreachable();
  }
}

InheritedDesignatedInitializersState FromPasta(pasta::InheritedDesignatedInitializersState e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return InheritedDesignatedInitializersState::UNKNOWN;
    case 1: return InheritedDesignatedInitializersState::INHERITED;
    case 2: return InheritedDesignatedInitializersState::NOT_INHERITED;
    default: __builtin_unreachable();
  }
}

InitStorageKind FromPasta(pasta::InitStorageKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return InitStorageKind::NO_INITIALIZER;
    case 1: return InitStorageKind::IN_CLASS_COPY_INITIALIZER;
    case 2: return InitStorageKind::IN_CLASS_LIST_INITIALIZER;
    case 3: return InitStorageKind::CAPTURED_VLA_TYPE;
    default: __builtin_unreachable();
  }
}

InlineAsmDialectKind FromPasta(pasta::InlineAsmDialectKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return InlineAsmDialectKind::IADATT;
    case 1: return InlineAsmDialectKind::IAD_INTEL;
    default: __builtin_unreachable();
  }
}

InlineVariableDefinitionKind FromPasta(pasta::InlineVariableDefinitionKind e) {
  switch (static_cast<int>(e)) {
    case 0: return InlineVariableDefinitionKind::NONE;
    case 1: return InlineVariableDefinitionKind::WEAK;
    case 2: return InlineVariableDefinitionKind::WEAK_UNKNOWN;
    case 3: return InlineVariableDefinitionKind::STRONG;
    default: __builtin_unreachable();
  }
}

InliningMethod FromPasta(pasta::InliningMethod e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return InliningMethod::NORMAL_INLINING;
    case 1: return InliningMethod::ONLY_HINT_INLINING;
    case 2: return InliningMethod::ONLY_ALWAYS_INLINING;
    default: __builtin_unreachable();
  }
}

Kinds FromPasta(pasta::Kinds e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return Kinds::L_VALUE;
    case 1: return Kinds::X_VALUE;
    case 2: return Kinds::FUNCTION;
    case 3: return Kinds::VOID;
    case 4: return Kinds::ADDRESSABLE_VOID;
    case 5: return Kinds::DUPLICATE_VECTOR_COMPONENTS;
    case 6: return Kinds::MEMBER_FUNCTION;
    case 7: return Kinds::SUB_OBJ_C_PROPERTY_SETTING;
    case 8: return Kinds::CLASS_TEMPORARY;
    case 9: return Kinds::ARRAY_TEMPORARY;
    case 10: return Kinds::OBJ_C_MESSAGE_R_VALUE;
    case 11: return Kinds::PR_VALUE;
    default: __builtin_unreachable();
  }
}

LambdaCaptureDefault FromPasta(pasta::LambdaCaptureDefault e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return LambdaCaptureDefault::NONE;
    case 1: return LambdaCaptureDefault::BY_COPY;
    case 2: return LambdaCaptureDefault::BY_REFERENCE;
    default: __builtin_unreachable();
  }
}

LambdaCaptureKind FromPasta(pasta::LambdaCaptureKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return LambdaCaptureKind::THIS;
    case 1: return LambdaCaptureKind::STAR_THIS;
    case 2: return LambdaCaptureKind::BY_COPY;
    case 3: return LambdaCaptureKind::BY_REFERENCE;
    case 4: return LambdaCaptureKind::VLA_TYPE;
    default: __builtin_unreachable();
  }
}

LangAS FromPasta(pasta::LangAS e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return LangAS::DEFAULT;
    case 1: return LangAS::OPENCL_GLOBAL;
    case 2: return LangAS::OPENCL_LOCAL;
    case 3: return LangAS::OPENCL_CONSTANT;
    case 4: return LangAS::OPENCL_PRIVATE;
    case 5: return LangAS::OPENCL_GENERIC;
    case 6: return LangAS::OPENCL_GLOBAL_DEVICE;
    case 7: return LangAS::OPENCL_GLOBAL_HOST;
    case 8: return LangAS::CUDA_DEVICE;
    case 9: return LangAS::CUDA_CONSTANT;
    case 10: return LangAS::CUDA_SHARED;
    case 11: return LangAS::SYCL_GLOBAL;
    case 12: return LangAS::SYCL_GLOBAL_DEVICE;
    case 13: return LangAS::SYCL_GLOBAL_HOST;
    case 14: return LangAS::SYCL_LOCAL;
    case 15: return LangAS::SYCL_PRIVATE;
    case 16: return LangAS::PTR32_SPTR;
    case 17: return LangAS::PTR32_UPTR;
    case 18: return LangAS::PTR64;
    case 19: return LangAS::HLSL_GROUPSHARED;
    default: __builtin_unreachable();
  }
}

LangFeatures FromPasta(pasta::LangFeatures e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return LangFeatures::LINE_COMMENT;
    case 2: return LangFeatures::C99;
    case 4: return LangFeatures::C11;
    case 8: return LangFeatures::C17;
    case 16: return LangFeatures::C2X;
    case 32: return LangFeatures::C_PLUS_PLUS;
    case 64: return LangFeatures::C_PLUS_PLUS11;
    case 128: return LangFeatures::C_PLUS_PLUS14;
    case 256: return LangFeatures::C_PLUS_PLUS17;
    case 512: return LangFeatures::C_PLUS_PLUS20;
    case 1024: return LangFeatures::C_PLUS_PLUS2B;
    case 2048: return LangFeatures::DIGRAPHS;
    case 4096: return LangFeatures::GNU_MODE;
    case 8192: return LangFeatures::HEX_FLOAT;
    case 16384: return LangFeatures::OPEN_CL;
    case 32768: return LangFeatures::HLSL;
    default: __builtin_unreachable();
  }
}

Language FromPasta(pasta::Language e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return Language::UNKNOWN;
    case 1: return Language::ASSEMBLY;
    case 2: return Language::LLVMIR;
    case 3: return Language::C;
    case 4: return Language::CXX;
    case 5: return Language::OBJ_C;
    case 6: return Language::OBJ_CXX;
    case 7: return Language::OPEN_CL;
    case 8: return Language::OPEN_CLCXX;
    case 9: return Language::CUDA;
    case 10: return Language::RENDER_SCRIPT;
    case 11: return Language::HIP;
    case 12: return Language::HLSL;
    default: __builtin_unreachable();
  }
}

LanguageLinkage FromPasta(pasta::LanguageLinkage e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return LanguageLinkage::C_LANGUAGE_LINKAGE;
    case 1: return LanguageLinkage::CXX_LANGUAGE_LINKAGE;
    case 2: return LanguageLinkage::NO_LANGUAGE_LINKAGE;
    default: __builtin_unreachable();
  }
}

LaxVectorConversionKind FromPasta(pasta::LaxVectorConversionKind e) {
  switch (static_cast<int>(e)) {
    case 0: return LaxVectorConversionKind::NONE;
    case 1: return LaxVectorConversionKind::INTEGER;
    case 2: return LaxVectorConversionKind::ALL;
    default: __builtin_unreachable();
  }
}

Level FromPasta(pasta::Level e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return Level::IGNORED;
    case 1: return Level::NOTE;
    case 2: return Level::REMARK;
    case 3: return Level::WARNING;
    case 4: return Level::ERROR;
    case 5: return Level::FATAL;
    default: __builtin_unreachable();
  }
}

Linkage FromPasta(pasta::Linkage e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return Linkage::NO_LINKAGE;
    case 1: return Linkage::INTERNAL_LINKAGE;
    case 2: return Linkage::UNIQUE_EXTERNAL_LINKAGE;
    case 3: return Linkage::VISIBLE_NO_LINKAGE;
    case 4: return Linkage::MODULE_INTERNAL_LINKAGE;
    case 5: return Linkage::MODULE_LINKAGE;
    case 6: return Linkage::EXTERNAL_LINKAGE;
    default: __builtin_unreachable();
  }
}

MSInheritanceModel FromPasta(pasta::MSInheritanceModel e) {
  switch (static_cast<int>(e)) {
    case 0: return MSInheritanceModel::SINGLE;
    case 1: return MSInheritanceModel::MULTIPLE;
    case 2: return MSInheritanceModel::VIRTUAL;
    case 3: return MSInheritanceModel::UNSPECIFIED;
    default: __builtin_unreachable();
  }
}

MSVCMajorVersion FromPasta(pasta::MSVCMajorVersion e) {
  switch (static_cast<unsigned>(e)) {
    case 1600: return MSVCMajorVersion::MSVC2010;
    case 1700: return MSVCMajorVersion::MSVC2012;
    case 1800: return MSVCMajorVersion::MSVC2013;
    case 1900: return MSVCMajorVersion::MSVC2015;
    case 1910: return MSVCMajorVersion::MSVC2017;
    case 1912: return MSVCMajorVersion::MSVC20175;
    case 1914: return MSVCMajorVersion::MSVC20177;
    case 1920: return MSVCMajorVersion::MSVC2019;
    case 1925: return MSVCMajorVersion::MSVC20195;
    case 1928: return MSVCMajorVersion::MSVC20198;
    default: __builtin_unreachable();
  }
}

MSVtorDispMode FromPasta(pasta::MSVtorDispMode e) {
  switch (static_cast<int>(e)) {
    case 0: return MSVtorDispMode::NEVER;
    case 1: return MSVtorDispMode::FOR_VIRTUAL_BASE_OVERRIDE;
    case 2: return MSVtorDispMode::FOR_VF_TABLE;
    default: __builtin_unreachable();
  }
}

MethodRefFlags FromPasta(pasta::MethodRefFlags e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return MethodRefFlags::METHOD_REFERENCE_NONE;
    case 1: return MethodRefFlags::METHOD_REFERENCE_GETTER;
    case 2: return MethodRefFlags::METHOD_REFERENCE_SETTER;
    default: __builtin_unreachable();
  }
}

ModifiableType FromPasta(pasta::ModifiableType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ModifiableType::UNTESTED;
    case 1: return ModifiableType::MODIFIABLE;
    case 2: return ModifiableType::R_VALUE;
    case 3: return ModifiableType::FUNCTION;
    case 4: return ModifiableType::L_VALUE_CAST;
    case 5: return ModifiableType::NO_SETTER_PROPERTY;
    case 6: return ModifiableType::CONST_QUALIFIED;
    case 7: return ModifiableType::CONST_QUALIFIED_FIELD;
    case 8: return ModifiableType::CONST_ADDRESS_SPACE;
    case 9: return ModifiableType::ARRAY_TYPE;
    case 10: return ModifiableType::INCOMPLETE_TYPE;
    default: __builtin_unreachable();
  }
}

MultiVersionKind FromPasta(pasta::MultiVersionKind e) {
  switch (static_cast<int>(e)) {
    case 0: return MultiVersionKind::NONE;
    case 1: return MultiVersionKind::TARGET;
    case 2: return MultiVersionKind::CPU_SPECIFIC;
    case 3: return MultiVersionKind::CPU_DISPATCH;
    case 4: return MultiVersionKind::TARGET_CLONES;
    case 5: return MultiVersionKind::TARGET_VERSION;
    default: __builtin_unreachable();
  }
}

NameKind FromPasta(pasta::NameKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NameKind::TEMPLATE;
    case 1: return NameKind::OVERLOADED_TEMPLATE;
    case 2: return NameKind::ASSUMED_TEMPLATE;
    case 3: return NameKind::QUALIFIED_TEMPLATE;
    case 4: return NameKind::DEPENDENT_TEMPLATE;
    case 5: return NameKind::SUBST_TEMPLATE_TEMPLATE_PARM;
    case 6: return NameKind::SUBST_TEMPLATE_TEMPLATE_PARM_PACK;
    case 7: return NameKind::USING_TEMPLATE;
    default: __builtin_unreachable();
  }
}

NeedExtraManglingDecl FromPasta(pasta::NeedExtraManglingDecl e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NeedExtraManglingDecl::NEED_EXTRA_MANGLING_DECLARATION;
    default: __builtin_unreachable();
  }
}

NestedNameSpecifierDependence FromPasta(pasta::NestedNameSpecifierDependence e) {
  switch (static_cast<unsigned char>(e)) {
    case 1: return NestedNameSpecifierDependence::UNEXPANDED_PACK;
    case 2: return NestedNameSpecifierDependence::INSTANTIATION;
    case 4: return NestedNameSpecifierDependence::DEPENDENT;
    case 8: return NestedNameSpecifierDependence::ERROR;
    case 0: return NestedNameSpecifierDependence::NONE;
    case 6: return NestedNameSpecifierDependence::DEPENDENT_INSTANTIATION;
    case 15: return NestedNameSpecifierDependence::ALL;
    default: __builtin_unreachable();
  }
}

NonOdrUseReason FromPasta(pasta::NonOdrUseReason e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NonOdrUseReason::NONE;
    case 1: return NonOdrUseReason::UNEVALUATED;
    case 2: return NonOdrUseReason::CONSTANT;
    case 3: return NonOdrUseReason::DISCARDED;
    default: __builtin_unreachable();
  }
}

NonceObjCInterface FromPasta(pasta::NonceObjCInterface e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NonceObjCInterface::OBJ_C_INTERFACE;
    default: __builtin_unreachable();
  }
}

NullabilityKind FromPasta(pasta::NullabilityKind e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return NullabilityKind::NON_NULL;
    case 1: return NullabilityKind::NULLABLE;
    case 2: return NullabilityKind::UNSPECIFIED;
    case 3: return NullabilityKind::NULLABLE_RESULT;
    default: __builtin_unreachable();
  }
}

ObjCBridgeCastKind FromPasta(pasta::ObjCBridgeCastKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCBridgeCastKind::BRIDGE;
    case 1: return ObjCBridgeCastKind::BRIDGE_TRANSFER;
    case 2: return ObjCBridgeCastKind::BRIDGE_RETAINED;
    default: __builtin_unreachable();
  }
}

ObjCDispatchMethodKind FromPasta(pasta::ObjCDispatchMethodKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCDispatchMethodKind::LEGACY;
    case 1: return ObjCDispatchMethodKind::NON_LEGACY;
    case 2: return ObjCDispatchMethodKind::MIXED;
    default: __builtin_unreachable();
  }
}

ObjCInstanceTypeFamily FromPasta(pasta::ObjCInstanceTypeFamily e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCInstanceTypeFamily::NONE;
    case 1: return ObjCInstanceTypeFamily::ARRAY;
    case 2: return ObjCInstanceTypeFamily::DICTIONARY;
    case 3: return ObjCInstanceTypeFamily::SINGLETON;
    case 4: return ObjCInstanceTypeFamily::INITIALIZER;
    case 5: return ObjCInstanceTypeFamily::RETURNS_SELF;
    default: __builtin_unreachable();
  }
}

ObjCLifetime FromPasta(pasta::ObjCLifetime e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCLifetime::NONE;
    case 1: return ObjCLifetime::EXPLICIT_NONE;
    case 2: return ObjCLifetime::STRONG;
    case 3: return ObjCLifetime::WEAK;
    case 4: return ObjCLifetime::AUTORELEASING;
    default: __builtin_unreachable();
  }
}

ObjCMethodFamily FromPasta(pasta::ObjCMethodFamily e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCMethodFamily::NONE;
    case 1: return ObjCMethodFamily::ALLOC;
    case 2: return ObjCMethodFamily::COPY;
    case 3: return ObjCMethodFamily::INITIALIZER;
    case 4: return ObjCMethodFamily::MUTABLE_COPY;
    case 5: return ObjCMethodFamily::NEW;
    case 6: return ObjCMethodFamily::AUTORELEASE;
    case 7: return ObjCMethodFamily::DEALLOC;
    case 8: return ObjCMethodFamily::FINALIZE;
    case 9: return ObjCMethodFamily::RELEASE;
    case 10: return ObjCMethodFamily::RETAIN;
    case 11: return ObjCMethodFamily::RETAIN_COUNT;
    case 12: return ObjCMethodFamily::SELF;
    case 13: return ObjCMethodFamily::INITIALIZE;
    case 14: return ObjCMethodFamily::PERFORM_SELECTOR;
    default: __builtin_unreachable();
  }
}

ObjCPropertyQueryKind FromPasta(pasta::ObjCPropertyQueryKind e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return ObjCPropertyQueryKind::QUERY_UNKNOWN;
    case 1: return ObjCPropertyQueryKind::QUERY_INSTANCE;
    case 2: return ObjCPropertyQueryKind::QUERY_CLASS;
    default: __builtin_unreachable();
  }
}

ObjCStringFormatFamily FromPasta(pasta::ObjCStringFormatFamily e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCStringFormatFamily::NONE;
    case 1: return ObjCStringFormatFamily::NS_STRING;
    case 2: return ObjCStringFormatFamily::CF_STRING;
    default: __builtin_unreachable();
  }
}

ObjCSubstitutionContext FromPasta(pasta::ObjCSubstitutionContext e) {
  switch (static_cast<int>(e)) {
    case 0: return ObjCSubstitutionContext::ORDINARY;
    case 1: return ObjCSubstitutionContext::RESULT;
    case 2: return ObjCSubstitutionContext::PARAMETER;
    case 3: return ObjCSubstitutionContext::PROPERTY;
    case 4: return ObjCSubstitutionContext::SUPERCLASS;
    default: __builtin_unreachable();
  }
}

ObjCTypeParamVariance FromPasta(pasta::ObjCTypeParamVariance e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return ObjCTypeParamVariance::INVARIANT;
    case 1: return ObjCTypeParamVariance::COVARIANT;
    case 2: return ObjCTypeParamVariance::CONTRAVARIANT;
    default: __builtin_unreachable();
  }
}

OnOffSwitch FromPasta(pasta::OnOffSwitch e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OnOffSwitch::ON;
    case 1: return OnOffSwitch::OFF;
    case 2: return OnOffSwitch::DEFAULT;
    default: __builtin_unreachable();
  }
}

OnStackType FromPasta(pasta::OnStackType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OnStackType::ON_STACK;
    default: __builtin_unreachable();
  }
}

OpenMPAdjustArgsOpKind FromPasta(pasta::OpenMPAdjustArgsOpKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPAdjustArgsOpKind::ADJUSTARGS_NOTHING;
    case 1: return OpenMPAdjustArgsOpKind::ADJUSTARGS_NEED_DEVICE_POINTER;
    case 2: return OpenMPAdjustArgsOpKind::ADJUSTARGS_UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPAtClauseKind FromPasta(pasta::OpenMPAtClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPAtClauseKind::AT_COMPILATION;
    case 1: return OpenMPAtClauseKind::AT_EXECUTION;
    case 2: return OpenMPAtClauseKind::AT_UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPAtomicDefaultMemOrderClauseKind FromPasta(pasta::OpenMPAtomicDefaultMemOrderClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPAtomicDefaultMemOrderClauseKind::SEQ_CST;
    case 1: return OpenMPAtomicDefaultMemOrderClauseKind::ACQ_REL;
    case 2: return OpenMPAtomicDefaultMemOrderClauseKind::RELAXED;
    case 3: return OpenMPAtomicDefaultMemOrderClauseKind::UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPBindClauseKind FromPasta(pasta::OpenMPBindClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPBindClauseKind::BIND_TEAMS;
    case 1: return OpenMPBindClauseKind::BIND_PARALLEL;
    case 2: return OpenMPBindClauseKind::BIND_THREAD;
    case 3: return OpenMPBindClauseKind::BIND_UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPDefaultmapClauseKind FromPasta(pasta::OpenMPDefaultmapClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPDefaultmapClauseKind::SCALAR;
    case 1: return OpenMPDefaultmapClauseKind::AGGREGATE;
    case 2: return OpenMPDefaultmapClauseKind::POINTER;
    case 3: return OpenMPDefaultmapClauseKind::UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPDefaultmapClauseModifier FromPasta(pasta::OpenMPDefaultmapClauseModifier e) {
  switch (static_cast<unsigned>(e)) {
    case 3: return OpenMPDefaultmapClauseModifier::UNKNOWN;
    case 4: return OpenMPDefaultmapClauseModifier::ALLOC;
    case 5: return OpenMPDefaultmapClauseModifier::TO;
    case 6: return OpenMPDefaultmapClauseModifier::FROM;
    case 7: return OpenMPDefaultmapClauseModifier::TOFROM;
    case 9: return OpenMPDefaultmapClauseModifier::NONE;
    case 10: return OpenMPDefaultmapClauseModifier::DEFAULT;
    case 11: return OpenMPDefaultmapClauseModifier::PRESENT;
    default: __builtin_unreachable();
  }
}

OpenMPDependClauseKind FromPasta(pasta::OpenMPDependClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPDependClauseKind::IN;
    case 1: return OpenMPDependClauseKind::OUT;
    case 2: return OpenMPDependClauseKind::INOUT;
    case 3: return OpenMPDependClauseKind::MUTEXINOUTSET;
    case 4: return OpenMPDependClauseKind::DEPOBJ;
    case 5: return OpenMPDependClauseKind::SOURCE;
    case 6: return OpenMPDependClauseKind::SINK;
    case 7: return OpenMPDependClauseKind::INOUTSET;
    case 8: return OpenMPDependClauseKind::OUTALLMEMORY;
    case 9: return OpenMPDependClauseKind::INOUTALLMEMORY;
    case 10: return OpenMPDependClauseKind::UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPDeviceClauseModifier FromPasta(pasta::OpenMPDeviceClauseModifier e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPDeviceClauseModifier::ANCESTOR;
    case 1: return OpenMPDeviceClauseModifier::DEVICE_NUM;
    case 2: return OpenMPDeviceClauseModifier::UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPDeviceType FromPasta(pasta::OpenMPDeviceType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPDeviceType::HOST;
    case 1: return OpenMPDeviceType::NOHOST;
    case 2: return OpenMPDeviceType::ANY;
    case 3: return OpenMPDeviceType::UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPDistScheduleClauseKind FromPasta(pasta::OpenMPDistScheduleClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPDistScheduleClauseKind::STATIC;
    case 1: return OpenMPDistScheduleClauseKind::UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPGrainsizeClauseModifier FromPasta(pasta::OpenMPGrainsizeClauseModifier e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPGrainsizeClauseModifier::GRAINSIZE_STRICT;
    case 1: return OpenMPGrainsizeClauseModifier::GRAINSIZE_UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPLastprivateModifier FromPasta(pasta::OpenMPLastprivateModifier e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPLastprivateModifier::CONDITIONAL;
    case 1: return OpenMPLastprivateModifier::UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPLinearClauseKind FromPasta(pasta::OpenMPLinearClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPLinearClauseKind::VALUE;
    case 1: return OpenMPLinearClauseKind::REFERENCE;
    case 2: return OpenMPLinearClauseKind::UVAL;
    case 3: return OpenMPLinearClauseKind::UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPMapClauseKind FromPasta(pasta::OpenMPMapClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPMapClauseKind::ALLOC;
    case 1: return OpenMPMapClauseKind::TO;
    case 2: return OpenMPMapClauseKind::FROM;
    case 3: return OpenMPMapClauseKind::TOFROM;
    case 4: return OpenMPMapClauseKind::DELETE;
    case 5: return OpenMPMapClauseKind::RELEASE;
    case 6: return OpenMPMapClauseKind::UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPMapModifierKind FromPasta(pasta::OpenMPMapModifierKind e) {
  switch (static_cast<unsigned>(e)) {
    case 6: return OpenMPMapModifierKind::UNKNOWN;
    case 7: return OpenMPMapModifierKind::ALWAYS;
    case 8: return OpenMPMapModifierKind::CLOSE;
    case 9: return OpenMPMapModifierKind::MAPPER;
    case 10: return OpenMPMapModifierKind::ITERATOR;
    case 11: return OpenMPMapModifierKind::PRESENT;
    case 12: return OpenMPMapModifierKind::OMPX_HOLD;
    default: __builtin_unreachable();
  }
}

OpenMPMotionModifierKind FromPasta(pasta::OpenMPMotionModifierKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPMotionModifierKind::MOTIONMODIFIER_MAPPER;
    case 1: return OpenMPMotionModifierKind::MOTIONMODIFIER_PRESENT;
    case 2: return OpenMPMotionModifierKind::MOTIONMODIFIER_UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPNumTasksClauseModifier FromPasta(pasta::OpenMPNumTasksClauseModifier e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPNumTasksClauseModifier::NUMTASKS_STRICT;
    case 1: return OpenMPNumTasksClauseModifier::NUMTASKS_UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPOrderClauseKind FromPasta(pasta::OpenMPOrderClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPOrderClauseKind::CONCURRENT;
    case 1: return OpenMPOrderClauseKind::UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPOrderClauseModifier FromPasta(pasta::OpenMPOrderClauseModifier e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return OpenMPOrderClauseModifier::MODIFIER_UNKNOWN;
    case 2: return OpenMPOrderClauseModifier::MODIFIER_REPRODUCIBLE;
    case 3: return OpenMPOrderClauseModifier::MODIFIER_UNCONSTRAINED;
    case 4: return OpenMPOrderClauseModifier::MODIFIER_LAST;
    default: __builtin_unreachable();
  }
}

OpenMPReductionClauseModifier FromPasta(pasta::OpenMPReductionClauseModifier e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPReductionClauseModifier::DEFAULT;
    case 1: return OpenMPReductionClauseModifier::INSCAN;
    case 2: return OpenMPReductionClauseModifier::TASK;
    case 3: return OpenMPReductionClauseModifier::UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPScheduleClauseKind FromPasta(pasta::OpenMPScheduleClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPScheduleClauseKind::STATIC;
    case 1: return OpenMPScheduleClauseKind::DYNAMIC;
    case 2: return OpenMPScheduleClauseKind::GUIDED;
    case 3: return OpenMPScheduleClauseKind::AUTO;
    case 4: return OpenMPScheduleClauseKind::RUNTIME;
    case 5: return OpenMPScheduleClauseKind::UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPScheduleClauseModifier FromPasta(pasta::OpenMPScheduleClauseModifier e) {
  switch (static_cast<unsigned>(e)) {
    case 5: return OpenMPScheduleClauseModifier::UNKNOWN;
    case 6: return OpenMPScheduleClauseModifier::MONOTONIC;
    case 7: return OpenMPScheduleClauseModifier::NONMONOTONIC;
    case 8: return OpenMPScheduleClauseModifier::SIMD;
    default: __builtin_unreachable();
  }
}

OpenMPSeverityClauseKind FromPasta(pasta::OpenMPSeverityClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPSeverityClauseKind::SEVERITY_FATAL;
    case 1: return OpenMPSeverityClauseKind::SEVERITY_WARNING;
    case 2: return OpenMPSeverityClauseKind::SEVERITY_UNKNOWN;
    default: __builtin_unreachable();
  }
}

OverloadedOperatorKind FromPasta(pasta::OverloadedOperatorKind e) {
  switch (static_cast<int>(e)) {
    case 0: return OverloadedOperatorKind::NONE;
    case 1: return OverloadedOperatorKind::NEW;
    case 2: return OverloadedOperatorKind::DELETE;
    case 3: return OverloadedOperatorKind::ARRAY_NEW;
    case 4: return OverloadedOperatorKind::ARRAY_DELETE;
    case 5: return OverloadedOperatorKind::PLUS;
    case 6: return OverloadedOperatorKind::MINUS;
    case 7: return OverloadedOperatorKind::STAR;
    case 8: return OverloadedOperatorKind::SLASH;
    case 9: return OverloadedOperatorKind::PERCENT;
    case 10: return OverloadedOperatorKind::CARET;
    case 11: return OverloadedOperatorKind::AMP;
    case 12: return OverloadedOperatorKind::PIPE;
    case 13: return OverloadedOperatorKind::TILDE;
    case 14: return OverloadedOperatorKind::EXCLAIM;
    case 15: return OverloadedOperatorKind::EQUAL;
    case 16: return OverloadedOperatorKind::LESS;
    case 17: return OverloadedOperatorKind::GREATER;
    case 18: return OverloadedOperatorKind::PLUS_EQUAL;
    case 19: return OverloadedOperatorKind::MINUS_EQUAL;
    case 20: return OverloadedOperatorKind::STAR_EQUAL;
    case 21: return OverloadedOperatorKind::SLASH_EQUAL;
    case 22: return OverloadedOperatorKind::PERCENT_EQUAL;
    case 23: return OverloadedOperatorKind::CARET_EQUAL;
    case 24: return OverloadedOperatorKind::AMP_EQUAL;
    case 25: return OverloadedOperatorKind::PIPE_EQUAL;
    case 26: return OverloadedOperatorKind::LESS_LESS;
    case 27: return OverloadedOperatorKind::GREATER_GREATER;
    case 28: return OverloadedOperatorKind::LESS_LESS_EQUAL;
    case 29: return OverloadedOperatorKind::GREATER_GREATER_EQUAL;
    case 30: return OverloadedOperatorKind::EQUAL_EQUAL;
    case 31: return OverloadedOperatorKind::EXCLAIM_EQUAL;
    case 32: return OverloadedOperatorKind::LESS_EQUAL;
    case 33: return OverloadedOperatorKind::GREATER_EQUAL;
    case 34: return OverloadedOperatorKind::SPACESHIP;
    case 35: return OverloadedOperatorKind::AMP_AMP;
    case 36: return OverloadedOperatorKind::PIPE_PIPE;
    case 37: return OverloadedOperatorKind::PLUS_PLUS;
    case 38: return OverloadedOperatorKind::MINUS_MINUS;
    case 39: return OverloadedOperatorKind::COMMA;
    case 40: return OverloadedOperatorKind::ARROW_STAR;
    case 41: return OverloadedOperatorKind::ARROW;
    case 42: return OverloadedOperatorKind::CALL;
    case 43: return OverloadedOperatorKind::SUBSCRIPT;
    case 44: return OverloadedOperatorKind::CONDITIONAL;
    case 45: return OverloadedOperatorKind::COAWAIT;
    default: __builtin_unreachable();
  }
}

OverloadsShown FromPasta(pasta::OverloadsShown e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OverloadsShown::ALL;
    case 1: return OverloadsShown::BEST;
    default: __builtin_unreachable();
  }
}

ParameterABI FromPasta(pasta::ParameterABI e) {
  switch (static_cast<int>(e)) {
    case 0: return ParameterABI::ORDINARY;
    case 1: return ParameterABI::SWIFT_INDIRECT_RESULT;
    case 2: return ParameterABI::SWIFT_ERROR_RESULT;
    case 3: return ParameterABI::SWIFT_CONTEXT;
    case 4: return ParameterABI::SWIFT_ASYNC_CONTEXT;
    default: __builtin_unreachable();
  }
}

ParenLocsOffsets FromPasta(pasta::ParenLocsOffsets e) {
  switch (static_cast<int>(e)) {
    case 0: return ParenLocsOffsets::L_PAREN_TOKEN;
    case 1: return ParenLocsOffsets::R_PAREN_TOKEN;
    case 2: return ParenLocsOffsets::TOTAL;
    default: __builtin_unreachable();
  }
}

PragmaFloatControlKind FromPasta(pasta::PragmaFloatControlKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PragmaFloatControlKind::UNKNOWN;
    case 1: return PragmaFloatControlKind::PRECISE;
    case 2: return PragmaFloatControlKind::NO_PRECISE;
    case 3: return PragmaFloatControlKind::EXCEPT;
    case 4: return PragmaFloatControlKind::NO_EXCEPT;
    case 5: return PragmaFloatControlKind::PUSH;
    case 6: return PragmaFloatControlKind::POP;
    default: __builtin_unreachable();
  }
}

PragmaMSCommentKind FromPasta(pasta::PragmaMSCommentKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PragmaMSCommentKind::UNKNOWN;
    case 1: return PragmaMSCommentKind::LINKER;
    case 2: return PragmaMSCommentKind::LIB;
    case 3: return PragmaMSCommentKind::COMPILER;
    case 4: return PragmaMSCommentKind::EXE_STRING;
    case 5: return PragmaMSCommentKind::USER;
    default: __builtin_unreachable();
  }
}

PragmaMSPointersToMembersKind FromPasta(pasta::PragmaMSPointersToMembersKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PragmaMSPointersToMembersKind::BEST_CASE;
    case 1: return PragmaMSPointersToMembersKind::FULL_GENERALITY_SINGLE_INHERITANCE;
    case 2: return PragmaMSPointersToMembersKind::FULL_GENERALITY_MULTIPLE_INHERITANCE;
    case 3: return PragmaMSPointersToMembersKind::FULL_GENERALITY_VIRTUAL_INHERITANCE;
    default: __builtin_unreachable();
  }
}

PragmaMSStructKind FromPasta(pasta::PragmaMSStructKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PragmaMSStructKind::OFF;
    case 1: return PragmaMSStructKind::ON;
    default: __builtin_unreachable();
  }
}

PragmaSectionFlag FromPasta(pasta::PragmaSectionFlag e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PragmaSectionFlag::NONE;
    case 1: return PragmaSectionFlag::READ;
    case 2: return PragmaSectionFlag::WRITE;
    case 4: return PragmaSectionFlag::EXECUTE;
    case 8: return PragmaSectionFlag::IMPLICIT;
    case 16: return PragmaSectionFlag::ZERO_INITIALIZER;
    case 2147483648: return PragmaSectionFlag::INVALID;
    default: __builtin_unreachable();
  }
}

ProfileInstrKind FromPasta(pasta::ProfileInstrKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ProfileInstrKind::PROFILE_NONE;
    case 1: return ProfileInstrKind::PROFILE_CLANG_INSTR;
    case 2: return ProfileInstrKind::PROFILE_IR_INSTR;
    case 3: return ProfileInstrKind::PROFILE_CSIR_INSTR;
    default: __builtin_unreachable();
  }
}

Qualified FromPasta(pasta::Qualified e) {
  switch (static_cast<int>(e)) {
    case 0: return Qualified::NONE;
    case 1: return Qualified::AS_WRITTEN;
    case 2: return Qualified::FULLY;
    default: __builtin_unreachable();
  }
}

RangeExprOffset FromPasta(pasta::RangeExprOffset e) {
  switch (static_cast<int>(e)) {
    case 0: return RangeExprOffset::BEGIN;
    case 1: return RangeExprOffset::END;
    case 2: return RangeExprOffset::STEP;
    case 3: return RangeExprOffset::TOTAL;
    default: __builtin_unreachable();
  }
}

RangeLocOffset FromPasta(pasta::RangeLocOffset e) {
  switch (static_cast<int>(e)) {
    case 0: return RangeLocOffset::ASSIGN_TOKEN;
    case 2: return RangeLocOffset::SECOND_COLON_TOKEN;
    case 3: return RangeLocOffset::TOTAL;
    default: __builtin_unreachable();
  }
}

RefQualifierKind FromPasta(pasta::RefQualifierKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return RefQualifierKind::NONE;
    case 1: return RefQualifierKind::L_VALUE;
    case 2: return RefQualifierKind::R_VALUE;
    default: __builtin_unreachable();
  }
}

RemarkKind FromPasta(pasta::RemarkKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return RemarkKind::MISSING;
    case 1: return RemarkKind::ENABLED;
    case 2: return RemarkKind::ENABLED_EVERYTHING;
    case 3: return RemarkKind::DISABLED;
    case 4: return RemarkKind::DISABLED_EVERYTHING;
    case 5: return RemarkKind::WITH_PATTERN;
    default: __builtin_unreachable();
  }
}

ReservedIdentifierStatus FromPasta(pasta::ReservedIdentifierStatus e) {
  switch (static_cast<int>(e)) {
    case 0: return ReservedIdentifierStatus::NOT_RESERVED;
    case 1: return ReservedIdentifierStatus::STARTS_WITH_UNDERSCORE_AT_GLOBAL_SCOPE;
    case 2: return ReservedIdentifierStatus::STARTS_WITH_UNDERSCORE_AND_IS_EXTERN_C;
    case 3: return ReservedIdentifierStatus::STARTS_WITH_DOUBLE_UNDERSCORE;
    case 4: return ReservedIdentifierStatus::STARTS_WITH_UNDERSCORE_FOLLOWED_BY_CAPITAL_LETTER;
    case 5: return ReservedIdentifierStatus::CONTAINS_DOUBLE_UNDERSCORE;
    default: __builtin_unreachable();
  }
}

SFINAEResponse FromPasta(pasta::SFINAEResponse e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SFINAEResponse::SUBSTITUTION_FAILURE;
    case 1: return SFINAEResponse::SUPPRESS;
    case 2: return SFINAEResponse::REPORT;
    case 3: return SFINAEResponse::ACCESS_CONTROL;
    default: __builtin_unreachable();
  }
}

SYCLMajorVersion FromPasta(pasta::SYCLMajorVersion e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SYCLMajorVersion::VERSION_NONE;
    case 1: return SYCLMajorVersion::VERSION2017;
    case 2: return SYCLMajorVersion::VERSION2020;
    default: __builtin_unreachable();
  }
}

SanitizerOrdinal FromPasta(pasta::SanitizerOrdinal e) {
  switch (static_cast<unsigned long>(e)) {
    case 0: return SanitizerOrdinal::ADDRESS;
    case 1: return SanitizerOrdinal::POINTER_COMPARE;
    case 2: return SanitizerOrdinal::POINTER_SUBTRACT;
    case 3: return SanitizerOrdinal::KERNEL_ADDRESS;
    case 4: return SanitizerOrdinal::HW_ADDRESS;
    case 5: return SanitizerOrdinal::KERNEL_HW_ADDRESS;
    case 6: return SanitizerOrdinal::MEMTAG_STACK;
    case 7: return SanitizerOrdinal::MEMTAG_HEAP;
    case 8: return SanitizerOrdinal::MEMTAG_GLOBALS;
    case 9: return SanitizerOrdinal::MEMORY_TAG_GROUP;
    case 10: return SanitizerOrdinal::MEMORY;
    case 11: return SanitizerOrdinal::KERNEL_MEMORY;
    case 12: return SanitizerOrdinal::FUZZER;
    case 13: return SanitizerOrdinal::FUZZER_NO_LINK;
    case 14: return SanitizerOrdinal::THREAD;
    case 15: return SanitizerOrdinal::LEAK;
    case 16: return SanitizerOrdinal::ALIGNMENT;
    case 17: return SanitizerOrdinal::ARRAY_BOUNDS;
    case 18: return SanitizerOrdinal::BOOLEAN;
    case 19: return SanitizerOrdinal::BUILTIN;
    case 20: return SanitizerOrdinal::ENUM;
    case 21: return SanitizerOrdinal::FLOAT_CAST_OVERFLOW;
    case 22: return SanitizerOrdinal::FLOAT_DIVIDE_BY_ZERO;
    case 23: return SanitizerOrdinal::FUNCTION;
    case 24: return SanitizerOrdinal::INTEGER_DIVIDE_BY_ZERO;
    case 25: return SanitizerOrdinal::NONNULL_ATTRIBUTE;
    case 26: return SanitizerOrdinal::NULL_;
    case 27: return SanitizerOrdinal::NULLABILITY_ARGUMENT;
    case 28: return SanitizerOrdinal::NULLABILITY_ASSIGN;
    case 29: return SanitizerOrdinal::NULLABILITY_RETURN;
    case 30: return SanitizerOrdinal::NULLABILITY_GROUP;
    case 31: return SanitizerOrdinal::OBJECT_SIZE;
    case 32: return SanitizerOrdinal::POINTER_OVERFLOW;
    case 33: return SanitizerOrdinal::RETURN;
    case 34: return SanitizerOrdinal::RETURNS_NONNULL_ATTRIBUTE;
    case 35: return SanitizerOrdinal::SHIFT_BASE;
    case 36: return SanitizerOrdinal::SHIFT_EXPONENT;
    case 37: return SanitizerOrdinal::SHIFT_GROUP;
    case 38: return SanitizerOrdinal::SIGNED_INTEGER_OVERFLOW;
    case 39: return SanitizerOrdinal::UNREACHABLE;
    case 40: return SanitizerOrdinal::VLA_BOUND;
    case 41: return SanitizerOrdinal::VPTR;
    case 42: return SanitizerOrdinal::UNSIGNED_INTEGER_OVERFLOW;
    case 43: return SanitizerOrdinal::UNSIGNED_SHIFT_BASE;
    case 44: return SanitizerOrdinal::DATA_FLOW;
    case 45: return SanitizerOrdinal::CFI_CAST_STRICT;
    case 46: return SanitizerOrdinal::CFI_DERIVED_CAST;
    case 47: return SanitizerOrdinal::CFII_CALL;
    case 48: return SanitizerOrdinal::CFIMF_CALL;
    case 49: return SanitizerOrdinal::CFI_UNRELATED_CAST;
    case 50: return SanitizerOrdinal::CFINV_CALL;
    case 51: return SanitizerOrdinal::CFIV_CALL;
    case 52: return SanitizerOrdinal::CFI_GROUP;
    case 53: return SanitizerOrdinal::KCFI;
    case 54: return SanitizerOrdinal::SAFE_STACK;
    case 55: return SanitizerOrdinal::SHADOW_CALL_STACK;
    case 56: return SanitizerOrdinal::UNDEFINED_GROUP;
    case 57: return SanitizerOrdinal::UNDEFINED_TRAP_GROUP;
    case 58: return SanitizerOrdinal::IMPLICIT_UNSIGNED_INTEGER_TRUNCATION;
    case 59: return SanitizerOrdinal::IMPLICIT_SIGNED_INTEGER_TRUNCATION;
    case 60: return SanitizerOrdinal::IMPLICIT_INTEGER_TRUNCATION_GROUP;
    case 61: return SanitizerOrdinal::IMPLICIT_INTEGER_SIGN_CHANGE;
    case 62: return SanitizerOrdinal::IMPLICIT_INTEGER_ARITHMETIC_VALUE_CHANGE_GROUP;
    case 63: return SanitizerOrdinal::OBJ_C_CAST;
    case 64: return SanitizerOrdinal::IMPLICIT_CONVERSION_GROUP;
    case 65: return SanitizerOrdinal::INTEGER_GROUP;
    case 66: return SanitizerOrdinal::LOCAL_BOUNDS;
    case 67: return SanitizerOrdinal::BOUNDS_GROUP;
    case 68: return SanitizerOrdinal::SCUDO;
    case 69: return SanitizerOrdinal::ALL_GROUP;
    case 70: return SanitizerOrdinal::COUNT;
    default: __builtin_unreachable();
  }
}

SelectorLocationsKind FromPasta(pasta::SelectorLocationsKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SelectorLocationsKind::NON_STANDARD;
    case 1: return SelectorLocationsKind::STANDARD_NO_SPACE;
    case 2: return SelectorLocationsKind::STANDARD_WITH_SPACE;
    default: __builtin_unreachable();
  }
}

ShaderStage FromPasta(pasta::ShaderStage e) {
  switch (static_cast<int>(e)) {
    case 0: return ShaderStage::PIXEL;
    case 1: return ShaderStage::VERTEX;
    case 2: return ShaderStage::GEOMETRY;
    case 3: return ShaderStage::HULL;
    case 4: return ShaderStage::DOMAIN_;
    case 5: return ShaderStage::COMPUTE;
    case 6: return ShaderStage::LIBRARY;
    case 7: return ShaderStage::RAY_GENERATION;
    case 8: return ShaderStage::INTERSECTION;
    case 9: return ShaderStage::ANY_HIT;
    case 10: return ShaderStage::CLOSEST_HIT;
    case 11: return ShaderStage::MISS;
    case 12: return ShaderStage::CALLABLE;
    case 13: return ShaderStage::MESH;
    case 14: return ShaderStage::AMPLIFICATION;
    case 15: return ShaderStage::INVALID;
    default: __builtin_unreachable();
  }
}

SignReturnAddressKeyKind FromPasta(pasta::SignReturnAddressKeyKind e) {
  switch (static_cast<int>(e)) {
    case 0: return SignReturnAddressKeyKind::A_KEY;
    case 1: return SignReturnAddressKeyKind::B_KEY;
    default: __builtin_unreachable();
  }
}

SignReturnAddressScopeKind FromPasta(pasta::SignReturnAddressScopeKind e) {
  switch (static_cast<int>(e)) {
    case 0: return SignReturnAddressScopeKind::NONE;
    case 1: return SignReturnAddressScopeKind::NON_LEAF;
    case 2: return SignReturnAddressScopeKind::ALL;
    default: __builtin_unreachable();
  }
}

SignedOverflowBehaviorTy FromPasta(pasta::SignedOverflowBehaviorTy e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SignedOverflowBehaviorTy::UNDEFINED;
    case 1: return SignedOverflowBehaviorTy::DEFINED;
    case 2: return SignedOverflowBehaviorTy::TRAPPING;
    default: __builtin_unreachable();
  }
}

SpecialMemberFlags FromPasta(pasta::SpecialMemberFlags e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return SpecialMemberFlags::DEFAULT_CONSTRUCTOR;
    case 2: return SpecialMemberFlags::COPY_CONSTRUCTOR;
    case 4: return SpecialMemberFlags::MOVE_CONSTRUCTOR;
    case 8: return SpecialMemberFlags::COPY_ASSIGNMENT;
    case 16: return SpecialMemberFlags::MOVE_ASSIGNMENT;
    case 32: return SpecialMemberFlags::DESTRUCTOR;
    case 63: return SpecialMemberFlags::ALL;
    default: __builtin_unreachable();
  }
}

SpecifierKind FromPasta(pasta::SpecifierKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SpecifierKind::IDENTIFIER;
    case 1: return SpecifierKind::NAMESPACE;
    case 2: return SpecifierKind::NAMESPACE_ALIAS;
    case 3: return SpecifierKind::TYPE_SPEC;
    case 4: return SpecifierKind::TYPE_SPEC_WITH_TEMPLATE;
    case 5: return SpecifierKind::GLOBAL;
    case 6: return SpecifierKind::SUPER;
    default: __builtin_unreachable();
  }
}

StackProtectorMode FromPasta(pasta::StackProtectorMode e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return StackProtectorMode::OFF;
    case 1: return StackProtectorMode::ON;
    case 2: return StackProtectorMode::STRONG;
    case 3: return StackProtectorMode::REQ;
    default: __builtin_unreachable();
  }
}

StorageClass FromPasta(pasta::StorageClass e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return StorageClass::NONE;
    case 1: return StorageClass::EXTERN;
    case 2: return StorageClass::STATIC;
    case 3: return StorageClass::PRIVATE_EXTERN;
    case 4: return StorageClass::AUTO;
    case 5: return StorageClass::REGISTER;
    default: __builtin_unreachable();
  }
}

StorageDuration FromPasta(pasta::StorageDuration e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return StorageDuration::FULL_EXPRESSION;
    case 1: return StorageDuration::AUTOMATIC;
    case 2: return StorageDuration::THREAD;
    case 3: return StorageDuration::STATIC;
    case 4: return StorageDuration::DYNAMIC;
    default: __builtin_unreachable();
  }
}

StoredNameKind FromPasta(pasta::StoredNameKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return StoredNameKind::STORED_IDENTIFIER;
    case 1: return StoredNameKind::STORED_OBJ_C_ZERO_ARGUMENT_SELECTOR;
    case 2: return StoredNameKind::STORED_OBJ_C_ONE_ARGUMENT_SELECTOR;
    case 3: return StoredNameKind::STORED_CXX_CONSTRUCTOR_NAME;
    case 4: return StoredNameKind::STORED_CXX_DESTRUCTOR_NAME;
    case 5: return StoredNameKind::STORED_CXX_CONVERSION_FUNCTION_NAME;
    case 6: return StoredNameKind::STORED_CXX_OPERATOR_NAME;
    case 7: return StoredNameKind::STORED_DECLARATION_NAME_EXTRA;
    case 8: return StoredNameKind::UNCOMMON_NAME_KIND_OFFSET;
    default: __builtin_unreachable();
  }
}

StoredSpecifierKind FromPasta(pasta::StoredSpecifierKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return StoredSpecifierKind::STORED_IDENTIFIER;
    case 1: return StoredSpecifierKind::STORED_DECLARATION;
    case 2: return StoredSpecifierKind::STORED_TYPE_SPEC;
    case 3: return StoredSpecifierKind::STORED_TYPE_SPEC_WITH_TEMPLATE;
    default: __builtin_unreachable();
  }
}

StrictFlexArraysLevelKind FromPasta(pasta::StrictFlexArraysLevelKind e) {
  switch (static_cast<int>(e)) {
    case 0: return StrictFlexArraysLevelKind::DEFAULT;
    case 1: return StrictFlexArraysLevelKind::ONE_ZERO_OR_INCOMPLETE;
    case 2: return StrictFlexArraysLevelKind::ZERO_OR_INCOMPLETE;
    case 3: return StrictFlexArraysLevelKind::INCOMPLETE_ONLY;
    default: __builtin_unreachable();
  }
}

StructReturnConventionKind FromPasta(pasta::StructReturnConventionKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return StructReturnConventionKind::DEFAULT;
    case 1: return StructReturnConventionKind::ON_STACK;
    case 2: return StructReturnConventionKind::IN_REGS;
    default: __builtin_unreachable();
  }
}

SubExpr FromPasta(pasta::SubExpr e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SubExpr::CALLEE;
    case 1: return SubExpr::LHS;
    case 2: return SubExpr::RHS;
    case 3: return SubExpr::COUNT;
    default: __builtin_unreachable();
  }
}

SubStmt FromPasta(pasta::SubStmt e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SubStmt::BODY;
    case 1: return SubStmt::PROMISE;
    case 2: return SubStmt::INITIALIZER_SUSPEND;
    case 3: return SubStmt::FINAL_SUSPEND;
    case 4: return SubStmt::ON_EXCEPTION;
    case 5: return SubStmt::ON_FALLTHROUGH;
    case 6: return SubStmt::ALLOCATE;
    case 7: return SubStmt::DEALLOCATE;
    case 8: return SubStmt::RETURN_VALUE;
    case 9: return SubStmt::RETURN_STATEMENT;
    case 10: return SubStmt::RETURN_STATEMENT_ON_ALLOC_FAILURE;
    default: __builtin_unreachable();
  }
}

SwiftAsyncFramePointerKind FromPasta(pasta::SwiftAsyncFramePointerKind e) {
  switch (static_cast<int>(e)) {
    case 0: return SwiftAsyncFramePointerKind::AUTO;
    case 1: return SwiftAsyncFramePointerKind::ALWAYS;
    case 2: return SwiftAsyncFramePointerKind::NEVER;
    default: __builtin_unreachable();
  }
}

SyncScope FromPasta(pasta::SyncScope e) {
  switch (static_cast<int>(e)) {
    case 0: return SyncScope::HIP_SINGLE_THREAD;
    case 1: return SyncScope::HIP_WAVEFRONT;
    case 2: return SyncScope::HIP_WORKGROUP;
    case 3: return SyncScope::HIP_AGENT;
    case 4: return SyncScope::HIP_SYSTEM;
    case 5: return SyncScope::OPEN_CL_WORK_GROUP;
    case 6: return SyncScope::OPEN_CL_DEVICE;
    case 7: return SyncScope::OPEN_CL_ALL_SVM_DEVICES;
    case 8: return SyncScope::OPEN_CL_SUB_GROUP;
    default: __builtin_unreachable();
  }
}

Syntax FromPasta(pasta::Syntax e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return Syntax::GNU;
    case 1: return Syntax::CXX11;
    case 2: return Syntax::C2X;
    case 3: return Syntax::DECLSPEC;
    case 4: return Syntax::MICROSOFT;
    case 5: return Syntax::KEYWORD;
    case 6: return Syntax::PRAGMA;
    case 7: return Syntax::CONTEXT_SENSITIVE_KEYWORD;
    case 8: return Syntax::HLSL_SEMANTIC;
    default: __builtin_unreachable();
  }
}

TLSModel FromPasta(pasta::TLSModel e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TLSModel::GENERAL_DYNAMIC_TLS_MODEL;
    case 1: return TLSModel::LOCAL_DYNAMIC_TLS_MODEL;
    case 2: return TLSModel::INITIAL_EXEC_TLS_MODEL;
    case 3: return TLSModel::LOCAL_EXEC_TLS_MODEL;
    default: __builtin_unreachable();
  }
}

TQ FromPasta(pasta::TQ e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return TQ::CONST;
    case 2: return TQ::RESTRICT;
    case 4: return TQ::VOLATILE;
    case 7: return TQ::CVR_MASK;
    default: __builtin_unreachable();
  }
}

TagTypeKind FromPasta(pasta::TagTypeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TagTypeKind::STRUCT;
    case 1: return TagTypeKind::INTERFACE;
    case 2: return TagTypeKind::UNION;
    case 3: return TagTypeKind::CLASS;
    case 4: return TagTypeKind::ENUM;
    default: __builtin_unreachable();
  }
}

TailPaddingUseRules FromPasta(pasta::TailPaddingUseRules e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TailPaddingUseRules::ALWAYS_USE_TAIL_PADDING;
    case 1: return TailPaddingUseRules::USE_TAIL_PADDING_UNLESS_POD03;
    case 2: return TailPaddingUseRules::USE_TAIL_PADDING_UNLESS_POD11;
    default: __builtin_unreachable();
  }
}

TemplateArgumentDependence FromPasta(pasta::TemplateArgumentDependence e) {
  switch (static_cast<unsigned char>(e)) {
    case 1: return TemplateArgumentDependence::UNEXPANDED_PACK;
    case 2: return TemplateArgumentDependence::INSTANTIATION;
    case 4: return TemplateArgumentDependence::DEPENDENT;
    case 8: return TemplateArgumentDependence::ERROR;
    case 0: return TemplateArgumentDependence::NONE;
    case 6: return TemplateArgumentDependence::DEPENDENT_INSTANTIATION;
    case 15: return TemplateArgumentDependence::ALL;
    default: __builtin_unreachable();
  }
}

TemplateNameDependence FromPasta(pasta::TemplateNameDependence e) {
  switch (static_cast<unsigned char>(e)) {
    case 1: return TemplateNameDependence::UNEXPANDED_PACK;
    case 2: return TemplateNameDependence::INSTANTIATION;
    case 4: return TemplateNameDependence::DEPENDENT;
    case 8: return TemplateNameDependence::ERROR;
    case 0: return TemplateNameDependence::NONE;
    case 6: return TemplateNameDependence::DEPENDENT_INSTANTIATION;
    case 15: return TemplateNameDependence::ALL;
    default: __builtin_unreachable();
  }
}

TemplateSpecializationKind FromPasta(pasta::TemplateSpecializationKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TemplateSpecializationKind::UNDECLARED;
    case 1: return TemplateSpecializationKind::IMPLICIT_INSTANTIATION;
    case 2: return TemplateSpecializationKind::EXPLICIT_SPECIALIZATION;
    case 3: return TemplateSpecializationKind::EXPLICIT_INSTANTIATION_DECLARATION;
    case 4: return TemplateSpecializationKind::EXPLICIT_INSTANTIATION_DEFINITION;
    default: __builtin_unreachable();
  }
}

TextDiagnosticFormat FromPasta(pasta::TextDiagnosticFormat e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TextDiagnosticFormat::CLANG;
    case 1: return TextDiagnosticFormat::MSVC;
    case 2: return TextDiagnosticFormat::VI;
    case 3: return TextDiagnosticFormat::SARIF;
    default: __builtin_unreachable();
  }
}

ThreadModelKind FromPasta(pasta::ThreadModelKind e) {
  switch (static_cast<int>(e)) {
    case 0: return ThreadModelKind::POSIX;
    case 1: return ThreadModelKind::SINGLE;
    default: __builtin_unreachable();
  }
}

ThreadStorageClassSpecifier FromPasta(pasta::ThreadStorageClassSpecifier e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ThreadStorageClassSpecifier::UNSPECIFIED;
    case 1: return ThreadStorageClassSpecifier::__THREAD;
    case 2: return ThreadStorageClassSpecifier::THREAD_LOCAL;
    case 3: return ThreadStorageClassSpecifier::_THREAD_LOCAL;
    default: __builtin_unreachable();
  }
}

TokenKind FromPasta(pasta::TokenKind e) {
  switch (static_cast<unsigned short>(e)) {
    case 0: return TokenKind::UNKNOWN;
    case 1: return TokenKind::END_OF_FILE;
    case 2: return TokenKind::END_OF_DIRECTIVE;
    case 3: return TokenKind::CODE_COMPLETION;
    case 4: return TokenKind::COMMENT;
    case 5: return TokenKind::IDENTIFIER;
    case 6: return TokenKind::IDENTIFIER;
    case 7: return TokenKind::NUMERIC_CONSTANT;
    case 8: return TokenKind::CHARACTER_CONSTANT;
    case 9: return TokenKind::WIDE_CHARACTER_CONSTANT;
    case 10: return TokenKind::UTF8_CHARACTER_CONSTANT;
    case 11: return TokenKind::UTF16_CHARACTER_CONSTANT;
    case 12: return TokenKind::UTF32_CHARACTER_CONSTANT;
    case 13: return TokenKind::STRING_LITERAL;
    case 14: return TokenKind::WIDE_STRING_LITERAL;
    case 15: return TokenKind::HEADER_NAME;
    case 16: return TokenKind::UTF8_STRING_LITERAL;
    case 17: return TokenKind::UTF16_STRING_LITERAL;
    case 18: return TokenKind::UTF32_STRING_LITERAL;
    case 19: return TokenKind::L_SQUARE;
    case 20: return TokenKind::R_SQUARE;
    case 21: return TokenKind::L_PARENTHESIS;
    case 22: return TokenKind::R_PARENTHESIS;
    case 23: return TokenKind::L_BRACE;
    case 24: return TokenKind::R_BRACE;
    case 25: return TokenKind::PERIOD;
    case 26: return TokenKind::ELLIPSIS;
    case 27: return TokenKind::AMP;
    case 28: return TokenKind::AMP_AMP;
    case 29: return TokenKind::AMP_EQUAL;
    case 30: return TokenKind::STAR;
    case 31: return TokenKind::STAR_EQUAL;
    case 32: return TokenKind::PLUS;
    case 33: return TokenKind::PLUS_PLUS;
    case 34: return TokenKind::PLUS_EQUAL;
    case 35: return TokenKind::MINUS;
    case 36: return TokenKind::ARROW;
    case 37: return TokenKind::MINUS_MINUS;
    case 38: return TokenKind::MINUS_EQUAL;
    case 39: return TokenKind::TILDE;
    case 40: return TokenKind::EXCLAIM;
    case 41: return TokenKind::EXCLAIM_EQUAL;
    case 42: return TokenKind::SLASH;
    case 43: return TokenKind::SLASH_EQUAL;
    case 44: return TokenKind::PERCENT;
    case 45: return TokenKind::PERCENT_EQUAL;
    case 46: return TokenKind::LESS;
    case 47: return TokenKind::LESS_LESS;
    case 48: return TokenKind::LESS_EQUAL;
    case 49: return TokenKind::LESS_LESS_EQUAL;
    case 50: return TokenKind::SPACESHIP;
    case 51: return TokenKind::GREATER;
    case 52: return TokenKind::GREATER_GREATER;
    case 53: return TokenKind::GREATER_EQUAL;
    case 54: return TokenKind::GREATER_GREATER_EQUAL;
    case 55: return TokenKind::CARET;
    case 56: return TokenKind::CARET_EQUAL;
    case 57: return TokenKind::PIPE;
    case 58: return TokenKind::PIPE_PIPE;
    case 59: return TokenKind::PIPE_EQUAL;
    case 60: return TokenKind::QUESTION;
    case 61: return TokenKind::COLON;
    case 62: return TokenKind::SEMI;
    case 63: return TokenKind::EQUAL;
    case 64: return TokenKind::EQUAL_EQUAL;
    case 65: return TokenKind::COMMA;
    case 66: return TokenKind::HASH;
    case 67: return TokenKind::HASH_HASH;
    case 68: return TokenKind::HASHAT;
    case 69: return TokenKind::PERIOD_STAR;
    case 70: return TokenKind::ARROW_STAR;
    case 71: return TokenKind::COLON_COLON;
    case 72: return TokenKind::AT;
    case 73: return TokenKind::LESS_LESS_LESS;
    case 74: return TokenKind::GREATER_GREATER_GREATER;
    case 75: return TokenKind::CARETCARET;
    case 76: return TokenKind::KEYWORD_AUTO;
    case 77: return TokenKind::KEYWORD_BREAK;
    case 78: return TokenKind::KEYWORD_CASE;
    case 79: return TokenKind::KEYWORD_CHARACTER;
    case 80: return TokenKind::KEYWORD_CONST;
    case 81: return TokenKind::KEYWORD_CONTINUE;
    case 82: return TokenKind::KEYWORD_DEFAULT;
    case 83: return TokenKind::KEYWORD_DO;
    case 84: return TokenKind::KEYWORD_DOUBLE;
    case 85: return TokenKind::KEYWORD_ELSE;
    case 86: return TokenKind::KEYWORD_ENUM;
    case 87: return TokenKind::KEYWORD_EXTERN;
    case 88: return TokenKind::KEYWORD_FLOAT;
    case 89: return TokenKind::KEYWORD_FOR;
    case 90: return TokenKind::KEYWORD_GOTO;
    case 91: return TokenKind::KEYWORD_IF;
    case 92: return TokenKind::KEYWORD_INT;
    case 93: return TokenKind::KEYWORD__EXT_INT;
    case 94: return TokenKind::KEYWORD__BIT_INT;
    case 95: return TokenKind::KEYWORD_LONG;
    case 96: return TokenKind::KEYWORD_REGISTER;
    case 97: return TokenKind::KEYWORD_RETURN;
    case 98: return TokenKind::KEYWORD_SHORT;
    case 99: return TokenKind::KEYWORD_SIGNED;
    case 100: return TokenKind::KEYWORD_SIZEOF;
    case 101: return TokenKind::KEYWORD_STATIC;
    case 102: return TokenKind::KEYWORD_STRUCT;
    case 103: return TokenKind::KEYWORD_SWITCH;
    case 104: return TokenKind::KEYWORD_TYPEDEF;
    case 105: return TokenKind::KEYWORD_UNION;
    case 106: return TokenKind::KEYWORD_UNSIGNED;
    case 107: return TokenKind::KEYWORD_VOID;
    case 108: return TokenKind::KEYWORD_VOLATILE;
    case 109: return TokenKind::KEYWORD_WHILE;
    case 110: return TokenKind::KEYWORD__ALIGNAS;
    case 111: return TokenKind::KEYWORD__ALIGNOF;
    case 112: return TokenKind::KEYWORD__ATOMIC;
    case 113: return TokenKind::KEYWORD__BOOLEAN;
    case 114: return TokenKind::KEYWORD__COMPLEX;
    case 115: return TokenKind::KEYWORD__GENERIC;
    case 116: return TokenKind::KEYWORD__IMAGINARY;
    case 117: return TokenKind::KEYWORD__NORETURN;
    case 118: return TokenKind::KEYWORD__STATIC_ASSERT;
    case 119: return TokenKind::KEYWORD__THREAD_LOCAL;
    case 120: return TokenKind::KEYWORD___FUNC__;
    case 121: return TokenKind::KEYWORD___OBJC_YES;
    case 122: return TokenKind::KEYWORD___OBJC_NO;
    case 123: return TokenKind::KEYWORD_ASSEMBLY;
    case 124: return TokenKind::KEYWORD_BOOLEAN;
    case 125: return TokenKind::KEYWORD_CATCH;
    case 126: return TokenKind::KEYWORD_CLASS;
    case 127: return TokenKind::KEYWORD_CONST_CAST;
    case 128: return TokenKind::KEYWORD_DELETE;
    case 129: return TokenKind::KEYWORD_DYNAMIC_CAST;
    case 130: return TokenKind::KEYWORD_EXPLICIT;
    case 131: return TokenKind::KEYWORD_EXPORT;
    case 132: return TokenKind::KEYWORD_FALSE;
    case 133: return TokenKind::KEYWORD_FRIEND;
    case 134: return TokenKind::KEYWORD_MUTABLE;
    case 135: return TokenKind::KEYWORD_NAMESPACE;
    case 136: return TokenKind::KEYWORD_NEW;
    case 137: return TokenKind::KEYWORD_OPERATOR;
    case 138: return TokenKind::KEYWORD_PRIVATE;
    case 139: return TokenKind::KEYWORD_PROTECTED;
    case 140: return TokenKind::KEYWORD_PUBLIC;
    case 141: return TokenKind::KEYWORD_REINTERPRET_CAST;
    case 142: return TokenKind::KEYWORD_STATIC_CAST;
    case 143: return TokenKind::KEYWORD_TEMPLATE;
    case 144: return TokenKind::KEYWORD_THIS;
    case 145: return TokenKind::KEYWORD_THROW;
    case 146: return TokenKind::KEYWORD_TRUE;
    case 147: return TokenKind::KEYWORD_TRY;
    case 148: return TokenKind::KEYWORD_TYPENAME;
    case 149: return TokenKind::KEYWORD_TYPEID;
    case 150: return TokenKind::KEYWORD_USING;
    case 151: return TokenKind::KEYWORD_VIRTUAL;
    case 152: return TokenKind::KEYWORD_WCHAR_T;
    case 153: return TokenKind::KEYWORD_RESTRICT;
    case 154: return TokenKind::KEYWORD_INLINE;
    case 155: return TokenKind::KEYWORD_ALIGNAS;
    case 156: return TokenKind::KEYWORD_ALIGNOF;
    case 157: return TokenKind::KEYWORD_CHAR16_T;
    case 158: return TokenKind::KEYWORD_CHAR32_T;
    case 159: return TokenKind::KEYWORD_CONSTEXPR;
    case 160: return TokenKind::KEYWORD_DECLTYPE;
    case 161: return TokenKind::KEYWORD_NOEXCEPT;
    case 162: return TokenKind::KEYWORD_NULLPTR;
    case 163: return TokenKind::KEYWORD_STATIC_ASSERT;
    case 164: return TokenKind::KEYWORD_THREAD_LOCAL;
    case 165: return TokenKind::KEYWORD_CO_AWAIT;
    case 166: return TokenKind::KEYWORD_CO_RETURN;
    case 167: return TokenKind::KEYWORD_CO_YIELD;
    case 168: return TokenKind::KEYWORD_MODULE;
    case 169: return TokenKind::KEYWORD_IMPORT;
    case 170: return TokenKind::KEYWORD_CONSTEVAL;
    case 171: return TokenKind::KEYWORD_CONSTINIT;
    case 172: return TokenKind::KEYWORD_CONCEPT;
    case 173: return TokenKind::KEYWORD_REQUIRES;
    case 174: return TokenKind::KEYWORD_CHAR8_T;
    case 175: return TokenKind::KEYWORD__FLOAT16;
    case 176: return TokenKind::KEYWORD_TYPEOF;
    case 177: return TokenKind::KEYWORD_TYPEOF_UNQUALIFIED;
    case 178: return TokenKind::KEYWORD__ACCUM;
    case 179: return TokenKind::KEYWORD__FRACT;
    case 180: return TokenKind::KEYWORD__SAT;
    case 181: return TokenKind::KEYWORD__DECIMAL32;
    case 182: return TokenKind::KEYWORD__DECIMAL64;
    case 183: return TokenKind::KEYWORD__DECIMAL128;
    case 184: return TokenKind::KEYWORD___NULL;
    case 185: return TokenKind::KEYWORD___ALIGNOF;
    case 186: return TokenKind::KEYWORD___ATTRIBUTE;
    case 187: return TokenKind::KEYWORD___BUILTIN_CHOOSE_EXPRESSION;
    case 188: return TokenKind::KEYWORD___BUILTIN_OFFSETOF;
    case 189: return TokenKind::KEYWORD___BUILTIN_FILE;
    case 190: return TokenKind::KEYWORD___BUILTIN_FUNCTION;
    case 191: return TokenKind::KEYWORD___BUILTIN_LINE;
    case 192: return TokenKind::KEYWORD___BUILTIN_COLUMN;
    case 193: return TokenKind::KEYWORD___BUILTIN_SOURCE_TOKEN;
    case 194: return TokenKind::KEYWORD___BUILTIN_TYPES_COMPATIBLE_P;
    case 195: return TokenKind::KEYWORD___BUILTIN_VA_ARGUMENT;
    case 196: return TokenKind::KEYWORD___EXTENSION__;
    case 197: return TokenKind::KEYWORD___FLOAT128;
    case 198: return TokenKind::KEYWORD___IBM128;
    case 199: return TokenKind::KEYWORD___IMAG;
    case 200: return TokenKind::KEYWORD___INT128;
    case 201: return TokenKind::KEYWORD___LABEL__;
    case 202: return TokenKind::KEYWORD___REAL;
    case 203: return TokenKind::KEYWORD___THREAD;
    case 204: return TokenKind::KEYWORD___FUNCTION__;
    case 205: return TokenKind::KEYWORD___PRETTYFUNCTION__;
    case 206: return TokenKind::KEYWORD___AUTO_TYPE;
    case 207: return TokenKind::KEYWORD___FUNCDNAME__;
    case 208: return TokenKind::KEYWORD___FUNCSIG__;
    case 209: return TokenKind::KEYWORD_LFUNCTION__;
    case 210: return TokenKind::KEYWORD_LFUNCSIG__;
    case 211: return TokenKind::KEYWORD___IS_INTERFACE_CLASS;
    case 212: return TokenKind::KEYWORD___IS_SEALED;
    case 213: return TokenKind::KEYWORD___IS_DESTRUCTIBLE;
    case 214: return TokenKind::KEYWORD___IS_TRIVIALLY_DESTRUCTIBLE;
    case 215: return TokenKind::KEYWORD___IS_NOTHROW_DESTRUCTIBLE;
    case 216: return TokenKind::KEYWORD___IS_NOTHROW_ASSIGNABLE;
    case 217: return TokenKind::KEYWORD___IS_CONSTRUCTIBLE;
    case 218: return TokenKind::KEYWORD___IS_NOTHROW_CONSTRUCTIBLE;
    case 219: return TokenKind::KEYWORD___IS_ASSIGNABLE;
    case 220: return TokenKind::KEYWORD___HAS_NOTHROW_MOVE_ASSIGN;
    case 221: return TokenKind::KEYWORD___HAS_TRIVIAL_MOVE_ASSIGN;
    case 222: return TokenKind::KEYWORD___HAS_TRIVIAL_MOVE_CONSTRUCTOR;
    case 223: return TokenKind::KEYWORD___HAS_NOTHROW_ASSIGN;
    case 224: return TokenKind::KEYWORD___HAS_NOTHROW_COPY;
    case 225: return TokenKind::KEYWORD___HAS_NOTHROW_CONSTRUCTOR;
    case 226: return TokenKind::KEYWORD___HAS_TRIVIAL_ASSIGN;
    case 227: return TokenKind::KEYWORD___HAS_TRIVIAL_COPY;
    case 228: return TokenKind::KEYWORD___HAS_TRIVIAL_CONSTRUCTOR;
    case 229: return TokenKind::KEYWORD___HAS_TRIVIAL_DESTRUCTOR;
    case 230: return TokenKind::KEYWORD___HAS_VIRTUAL_DESTRUCTOR;
    case 231: return TokenKind::KEYWORD___IS_ABSTRACT;
    case 232: return TokenKind::KEYWORD___IS_AGGREGATE;
    case 233: return TokenKind::KEYWORD___IS_BASE_OF;
    case 234: return TokenKind::KEYWORD___IS_CLASS;
    case 235: return TokenKind::KEYWORD___IS_CONVERTIBLE_TO;
    case 236: return TokenKind::KEYWORD___IS_EMPTY;
    case 237: return TokenKind::KEYWORD___IS_ENUM;
    case 238: return TokenKind::KEYWORD___IS_FINAL;
    case 239: return TokenKind::KEYWORD___IS_LITERAL;
    case 240: return TokenKind::KEYWORD___IS_POD;
    case 241: return TokenKind::KEYWORD___IS_POLYMORPHIC;
    case 242: return TokenKind::KEYWORD___IS_STANDARD_LAYOUT;
    case 243: return TokenKind::KEYWORD___IS_TRIVIAL;
    case 244: return TokenKind::KEYWORD___IS_TRIVIALLY_ASSIGNABLE;
    case 245: return TokenKind::KEYWORD___IS_TRIVIALLY_CONSTRUCTIBLE;
    case 246: return TokenKind::KEYWORD___IS_TRIVIALLY_COPYABLE;
    case 247: return TokenKind::KEYWORD___IS_UNION;
    case 248: return TokenKind::KEYWORD___HAS_UNIQUE_OBJECT_REPRESENTATIONS;
    case 249: return TokenKind::KEYWORD___ADD_LVALUE_REFERENCE;
    case 250: return TokenKind::KEYWORD___ADD_POINTER;
    case 251: return TokenKind::KEYWORD___ADD_RVALUE_REFERENCE;
    case 252: return TokenKind::KEYWORD___DECAY;
    case 253: return TokenKind::KEYWORD___MAKE_SIGNED;
    case 254: return TokenKind::KEYWORD___MAKE_UNSIGNED;
    case 255: return TokenKind::KEYWORD___REMOVE_ALL_EXTENTS;
    case 256: return TokenKind::KEYWORD___REMOVE_CONST;
    case 257: return TokenKind::KEYWORD___REMOVE_CV;
    case 258: return TokenKind::KEYWORD___REMOVE_CVREF;
    case 259: return TokenKind::KEYWORD___REMOVE_EXTENT;
    case 260: return TokenKind::KEYWORD___REMOVE_POINTER;
    case 261: return TokenKind::KEYWORD___REMOVE_REFERENCE_T;
    case 262: return TokenKind::KEYWORD___REMOVE_RESTRICT;
    case 263: return TokenKind::KEYWORD___REMOVE_VOLATILE;
    case 264: return TokenKind::KEYWORD___UNDERLYING_TYPE;
    case 265: return TokenKind::KEYWORD___IS_TRIVIALLY_RELOCATABLE;
    case 266: return TokenKind::KEYWORD___IS_BOUNDED_ARRAY;
    case 267: return TokenKind::KEYWORD___IS_UNBOUNDED_ARRAY;
    case 268: return TokenKind::KEYWORD___IS_NULLPTR;
    case 269: return TokenKind::KEYWORD___IS_SCOPED_ENUM;
    case 270: return TokenKind::KEYWORD___IS_REFERENCEABLE;
    case 271: return TokenKind::KEYWORD___REFERENCE_BINDS_TO_TEMPORARY;
    case 272: return TokenKind::KEYWORD___IS_LVALUE_EXPRESSION;
    case 273: return TokenKind::KEYWORD___IS_RVALUE_EXPRESSION;
    case 274: return TokenKind::KEYWORD___IS_ARITHMETIC;
    case 275: return TokenKind::KEYWORD___IS_FLOATING_POINT;
    case 276: return TokenKind::KEYWORD___IS_INTEGRAL;
    case 277: return TokenKind::KEYWORD___IS_COMPLETE_TYPE;
    case 278: return TokenKind::KEYWORD___IS_VOID;
    case 279: return TokenKind::KEYWORD___IS_ARRAY;
    case 280: return TokenKind::KEYWORD___IS_FUNCTION;
    case 281: return TokenKind::KEYWORD___IS_REFERENCE;
    case 282: return TokenKind::KEYWORD___IS_LVALUE_REFERENCE;
    case 283: return TokenKind::KEYWORD___IS_RVALUE_REFERENCE;
    case 284: return TokenKind::KEYWORD___IS_FUNDAMENTAL;
    case 285: return TokenKind::KEYWORD___IS_OBJECT;
    case 286: return TokenKind::KEYWORD___IS_SCALAR;
    case 287: return TokenKind::KEYWORD___IS_COMPOUND;
    case 288: return TokenKind::KEYWORD___IS_POINTER;
    case 289: return TokenKind::KEYWORD___IS_MEMBER_OBJECT_POINTER;
    case 290: return TokenKind::KEYWORD___IS_MEMBER_FUNCTION_POINTER;
    case 291: return TokenKind::KEYWORD___IS_MEMBER_POINTER;
    case 292: return TokenKind::KEYWORD___IS_CONST;
    case 293: return TokenKind::KEYWORD___IS_VOLATILE;
    case 294: return TokenKind::KEYWORD___IS_SIGNED;
    case 295: return TokenKind::KEYWORD___IS_UNSIGNED;
    case 296: return TokenKind::KEYWORD___IS_SAME;
    case 297: return TokenKind::KEYWORD___IS_CONVERTIBLE;
    case 298: return TokenKind::KEYWORD___ARRAY_RANK;
    case 299: return TokenKind::KEYWORD___ARRAY_EXTENT;
    case 300: return TokenKind::KEYWORD___PRIVATE_EXTERN__;
    case 301: return TokenKind::KEYWORD___MODULE_PRIVATE__;
    case 302: return TokenKind::KEYWORD___BUILTIN_PTRAUTH_TYPE_DISCRIMINATOR;
    case 303: return TokenKind::KEYWORD___BUILTIN_XNU_TYPE_SIGNATURE;
    case 304: return TokenKind::KEYWORD___BUILTIN_XNU_TYPE_SUMMARY;
    case 305: return TokenKind::KEYWORD___BUILTIN_TMO_TYPE_METADATA;
    case 306: return TokenKind::KEYWORD___BUILTIN_XNU_TYPES_COMPATIBLE;
    case 307: return TokenKind::KEYWORD___DECLSPEC;
    case 308: return TokenKind::KEYWORD___CDECL;
    case 309: return TokenKind::KEYWORD___STDCALL;
    case 310: return TokenKind::KEYWORD___FASTCALL;
    case 311: return TokenKind::KEYWORD___THISCALL;
    case 312: return TokenKind::KEYWORD___REGCALL;
    case 313: return TokenKind::KEYWORD___VECTORCALL;
    case 314: return TokenKind::KEYWORD___FORCEINLINE;
    case 315: return TokenKind::KEYWORD___UNALIGNED;
    case 316: return TokenKind::KEYWORD___SUPER;
    case 317: return TokenKind::KEYWORD___GLOBAL;
    case 318: return TokenKind::KEYWORD___LOCAL;
    case 319: return TokenKind::KEYWORD___CONSTANT;
    case 320: return TokenKind::KEYWORD___PRIVATE;
    case 321: return TokenKind::KEYWORD___GENERIC;
    case 322: return TokenKind::KEYWORD___KERNEL;
    case 323: return TokenKind::KEYWORD___READ_ONLY;
    case 324: return TokenKind::KEYWORD___WRITE_ONLY;
    case 325: return TokenKind::KEYWORD___READ_WRITE;
    case 326: return TokenKind::KEYWORD___BUILTIN_ASTYPE;
    case 327: return TokenKind::KEYWORD_VEC_STEP;
    case 328: return TokenKind::KEYWORD_IMAGE_1D_T;
    case 329: return TokenKind::KEYWORD_IMAGE_1D_ARRAY_T;
    case 330: return TokenKind::KEYWORD_IMAGE_1D_BUFFER_T;
    case 331: return TokenKind::KEYWORD_IMAGE_2D_T;
    case 332: return TokenKind::KEYWORD_IMAGE_2D_ARRAY_T;
    case 333: return TokenKind::KEYWORD_IMAGE_2D_DEPTH_T;
    case 334: return TokenKind::KEYWORD_IMAGE_2D_ARRAY_DEPTH_T;
    case 335: return TokenKind::KEYWORD_IMAGE_2D_MSAA_T;
    case 336: return TokenKind::KEYWORD_IMAGE_2D_ARRAY_MSAA_T;
    case 337: return TokenKind::KEYWORD_IMAGE_2D_MSAA_DEPTH_T;
    case 338: return TokenKind::KEYWORD_IMAGE_2D_ARRAY_MSAA_DEPTH_T;
    case 339: return TokenKind::KEYWORD_IMAGE_3D_T;
    case 340: return TokenKind::KEYWORD_PIPE;
    case 341: return TokenKind::KEYWORD_ADDRSPACE_CAST;
    case 342: return TokenKind::KEYWORD___NOINLINE__;
    case 343: return TokenKind::KEYWORD_CBUFFER;
    case 344: return TokenKind::KEYWORD_TBUFFER;
    case 345: return TokenKind::KEYWORD_GROUPSHARED;
    case 346: return TokenKind::KEYWORD___BUILTIN_OMP_REQUIRED_SIMD_ALIGN;
    case 347: return TokenKind::KEYWORD___PASCAL;
    case 348: return TokenKind::KEYWORD___VECTOR;
    case 349: return TokenKind::KEYWORD___PIXEL;
    case 350: return TokenKind::KEYWORD___BOOLEAN;
    case 351: return TokenKind::KEYWORD___BF16;
    case 352: return TokenKind::KEYWORD_HALF;
    case 353: return TokenKind::KEYWORD___BRIDGE;
    case 354: return TokenKind::KEYWORD___BRIDGE_TRANSFER;
    case 355: return TokenKind::KEYWORD___BRIDGE_RETAINED;
    case 356: return TokenKind::KEYWORD___BRIDGE_RETAIN;
    case 357: return TokenKind::KEYWORD___COVARIANT;
    case 358: return TokenKind::KEYWORD___CONTRAVARIANT;
    case 359: return TokenKind::KEYWORD___KINDOF;
    case 360: return TokenKind::KEYWORD__NONNULL;
    case 361: return TokenKind::KEYWORD__NULLABLE;
    case 362: return TokenKind::KEYWORD__NULLABLE_RESULT;
    case 363: return TokenKind::KEYWORD__NULL_UNSPECIFIED;
    case 364: return TokenKind::KEYWORD___PTR64;
    case 365: return TokenKind::KEYWORD___PTR32;
    case 366: return TokenKind::KEYWORD___SPTR;
    case 367: return TokenKind::KEYWORD___UPTR;
    case 368: return TokenKind::KEYWORD___W64;
    case 369: return TokenKind::KEYWORD___UUIDOF;
    case 370: return TokenKind::KEYWORD___TRY;
    case 371: return TokenKind::KEYWORD___FINALLY;
    case 372: return TokenKind::KEYWORD___LEAVE;
    case 373: return TokenKind::KEYWORD___INT64;
    case 374: return TokenKind::KEYWORD___IF_EXISTS;
    case 375: return TokenKind::KEYWORD___IF_NOT_EXISTS;
    case 376: return TokenKind::KEYWORD___SINGLE_INHERITANCE;
    case 377: return TokenKind::KEYWORD___MULTIPLE_INHERITANCE;
    case 378: return TokenKind::KEYWORD___VIRTUAL_INHERITANCE;
    case 379: return TokenKind::KEYWORD___INTERFACE;
    case 380: return TokenKind::KEYWORD___BUILTIN_CONVERTVECTOR;
    case 381: return TokenKind::KEYWORD___BUILTIN_BIT_CAST;
    case 382: return TokenKind::KEYWORD___BUILTIN_AVAILABLE;
    case 383: return TokenKind::KEYWORD___BUILTIN_SYCL_UNIQUE_STABLE_NAME;
    case 384: return TokenKind::KEYWORD___UNKNOWN_ANYTYPE;
    case 385: return TokenKind::ANNOT_CXXSCOPE;
    case 386: return TokenKind::ANNOT_TYPENAME;
    case 387: return TokenKind::ANNOT_TEMPLATE_ID;
    case 388: return TokenKind::ANNOT_NON_TYPE;
    case 389: return TokenKind::ANNOT_NON_TYPE_UNDECLARED;
    case 390: return TokenKind::ANNOT_NON_TYPE_DEPENDENT;
    case 391: return TokenKind::ANNOT_OVERLOAD;
    case 392: return TokenKind::ANNOT_PRIMARY_EXPRESSION;
    case 393: return TokenKind::ANNOT_DECLTYPE;
    case 394: return TokenKind::ANNOT_PRAGMA_UNUSED;
    case 395: return TokenKind::ANNOT_PRAGMA_VIS;
    case 396: return TokenKind::ANNOT_PRAGMA_PACK;
    case 397: return TokenKind::ANNOT_PRAGMA_PARSER_CRASH;
    case 398: return TokenKind::ANNOT_PRAGMA_CAPTURED;
    case 399: return TokenKind::ANNOT_PRAGMA_DUMP;
    case 400: return TokenKind::ANNOT_PRAGMA_MSSTRUCT;
    case 401: return TokenKind::ANNOT_PRAGMA_ALIGN;
    case 402: return TokenKind::ANNOT_PRAGMA_WEAK;
    case 403: return TokenKind::ANNOT_PRAGMA_WEAKALIAS;
    case 404: return TokenKind::ANNOT_PRAGMA_REDEFINE_EXTNAME;
    case 405: return TokenKind::ANNOT_PRAGMA_FP_CONTRACT;
    case 406: return TokenKind::ANNOT_PRAGMA_FENV_ACCESS;
    case 407: return TokenKind::ANNOT_PRAGMA_FENV_ACCESS_MS;
    case 408: return TokenKind::ANNOT_PRAGMA_FENV_ROUND;
    case 409: return TokenKind::ANNOT_PRAGMA_FLOAT_CONTROL;
    case 410: return TokenKind::ANNOT_PRAGMA_MS_POINTERS_TO_MEMBERS;
    case 411: return TokenKind::ANNOT_PRAGMA_MS_VTORDISP;
    case 412: return TokenKind::ANNOT_PRAGMA_MS_PRAGMA;
    case 413: return TokenKind::ANNOT_PRAGMA_OPENCL_EXTENSION;
    case 414: return TokenKind::ANNOT_ATTRIBUTE_OPENMP;
    case 415: return TokenKind::ANNOT_PRAGMA_OPENMP;
    case 416: return TokenKind::ANNOT_PRAGMA_OPENMP_END;
    case 417: return TokenKind::ANNOT_PRAGMA_LOOP_HINT;
    case 418: return TokenKind::ANNOT_PRAGMA_FP;
    case 419: return TokenKind::ANNOT_PRAGMA_ATTRIBUTE;
    case 420: return TokenKind::ANNOT_PRAGMA_RISCV;
    case 421: return TokenKind::ANNOT_MODULE_INCLUDE;
    case 422: return TokenKind::ANNOT_MODULE_BEGIN;
    case 423: return TokenKind::ANNOT_MODULE_END;
    case 424: return TokenKind::ANNOT_HEADER_UNIT;
    default: __builtin_unreachable();
  }
}

TrailingAllocKind FromPasta(pasta::TrailingAllocKind e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return TrailingAllocKind::TAK_INHERITS_CONSTRUCTOR;
    case 2: return TrailingAllocKind::TAK_HAS_TAIL_EXPLICIT;
    default: __builtin_unreachable();
  }
}

TranslationUnitKind FromPasta(pasta::TranslationUnitKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TranslationUnitKind::COMPLETE;
    case 1: return TranslationUnitKind::PREFIX;
    case 2: return TranslationUnitKind::MODULE;
    case 3: return TranslationUnitKind::INCREMENTAL;
    default: __builtin_unreachable();
  }
}

TrivialAutoVarInitKind FromPasta(pasta::TrivialAutoVarInitKind e) {
  switch (static_cast<int>(e)) {
    case 0: return TrivialAutoVarInitKind::UNINITIALIZED;
    case 1: return TrivialAutoVarInitKind::ZERO;
    case 2: return TrivialAutoVarInitKind::PATTERN;
    default: __builtin_unreachable();
  }
}

TypeDependence FromPasta(pasta::TypeDependence e) {
  switch (static_cast<unsigned char>(e)) {
    case 1: return TypeDependence::UNEXPANDED_PACK;
    case 2: return TypeDependence::INSTANTIATION;
    case 4: return TypeDependence::DEPENDENT;
    case 8: return TypeDependence::VARIABLY_MODIFIED;
    case 16: return TypeDependence::ERROR;
    case 0: return TypeDependence::NONE;
    case 31: return TypeDependence::ALL;
    case 6: return TypeDependence::DEPENDENT_INSTANTIATION;
    default: __builtin_unreachable();
  }
}

TypeLocClass FromPasta(pasta::TypeLocClass e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TypeLocClass::ADJUSTED;
    case 1: return TypeLocClass::DECAYED;
    case 2: return TypeLocClass::CONSTANT_ARRAY;
    case 3: return TypeLocClass::DEPENDENT_SIZED_ARRAY;
    case 4: return TypeLocClass::INCOMPLETE_ARRAY;
    case 5: return TypeLocClass::VARIABLE_ARRAY;
    case 6: return TypeLocClass::ATOMIC;
    case 7: return TypeLocClass::ATTRIBUTED;
    case 8: return TypeLocClass::BTF_TAG_ATTRIBUTED;
    case 9: return TypeLocClass::BIT_INT;
    case 10: return TypeLocClass::BLOCK_POINTER;
    case 11: return TypeLocClass::BUILTIN;
    case 12: return TypeLocClass::COMPLEX;
    case 13: return TypeLocClass::DECLTYPE;
    case 14: return TypeLocClass::AUTO;
    case 15: return TypeLocClass::DEDUCED_TEMPLATE_SPECIALIZATION;
    case 16: return TypeLocClass::DEPENDENT_ADDRESS_SPACE;
    case 17: return TypeLocClass::DEPENDENT_BIT_INT;
    case 18: return TypeLocClass::DEPENDENT_NAME;
    case 19: return TypeLocClass::DEPENDENT_SIZED_EXT_VECTOR;
    case 20: return TypeLocClass::DEPENDENT_TEMPLATE_SPECIALIZATION;
    case 21: return TypeLocClass::DEPENDENT_VECTOR;
    case 22: return TypeLocClass::ELABORATED;
    case 23: return TypeLocClass::FUNCTION_NO_PROTO;
    case 24: return TypeLocClass::FUNCTION_PROTO;
    case 25: return TypeLocClass::INJECTED_CLASS_NAME;
    case 26: return TypeLocClass::MACRO_QUALIFIED;
    case 27: return TypeLocClass::CONSTANT_MATRIX;
    case 28: return TypeLocClass::DEPENDENT_SIZED_MATRIX;
    case 29: return TypeLocClass::MEMBER_POINTER;
    case 30: return TypeLocClass::OBJ_C_OBJECT_POINTER;
    case 31: return TypeLocClass::OBJ_C_OBJECT;
    case 32: return TypeLocClass::OBJ_C_INTERFACE;
    case 33: return TypeLocClass::OBJ_C_TYPE_PARAMETER;
    case 34: return TypeLocClass::PACK_EXPANSION;
    case 35: return TypeLocClass::PARENTHESIS;
    case 36: return TypeLocClass::PIPE;
    case 37: return TypeLocClass::POINTER;
    case 38: return TypeLocClass::L_VALUE_REFERENCE;
    case 39: return TypeLocClass::R_VALUE_REFERENCE;
    case 40: return TypeLocClass::SUBST_TEMPLATE_TYPE_PARM_PACK;
    case 41: return TypeLocClass::SUBST_TEMPLATE_TYPE_PARM;
    case 42: return TypeLocClass::ENUM;
    case 43: return TypeLocClass::RECORD;
    case 44: return TypeLocClass::TEMPLATE_SPECIALIZATION;
    case 45: return TypeLocClass::TEMPLATE_TYPE_PARM;
    case 46: return TypeLocClass::TYPE_OF_EXPRESSION;
    case 47: return TypeLocClass::TYPE_OF;
    case 48: return TypeLocClass::TYPEDEF;
    case 49: return TypeLocClass::UNARY_TRANSFORM;
    case 50: return TypeLocClass::UNRESOLVED_USING;
    case 51: return TypeLocClass::USING;
    case 52: return TypeLocClass::VECTOR;
    case 53: return TypeLocClass::EXT_VECTOR;
    case 54: return TypeLocClass::QUALIFIED;
    default: __builtin_unreachable();
  }
}

TypeOfKind FromPasta(pasta::TypeOfKind e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return TypeOfKind::QUALIFIED;
    case 1: return TypeOfKind::UNQUALIFIED;
    default: __builtin_unreachable();
  }
}

TypeSpecifierSign FromPasta(pasta::TypeSpecifierSign e) {
  switch (static_cast<int>(e)) {
    case 0: return TypeSpecifierSign::UNSPECIFIED;
    case 1: return TypeSpecifierSign::SIGNED;
    case 2: return TypeSpecifierSign::UNSIGNED;
    default: __builtin_unreachable();
  }
}

TypeSpecifierType FromPasta(pasta::TypeSpecifierType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TypeSpecifierType::UNSPECIFIED;
    case 1: return TypeSpecifierType::VOID;
    case 2: return TypeSpecifierType::CHARACTER;
    case 3: return TypeSpecifierType::WCHAR;
    case 4: return TypeSpecifierType::CHAR8;
    case 5: return TypeSpecifierType::CHAR16;
    case 6: return TypeSpecifierType::CHAR32;
    case 7: return TypeSpecifierType::INT;
    case 8: return TypeSpecifierType::INT128;
    case 9: return TypeSpecifierType::BITINT;
    case 10: return TypeSpecifierType::HALF;
    case 11: return TypeSpecifierType::FLOAT16;
    case 12: return TypeSpecifierType::ACCUM;
    case 13: return TypeSpecifierType::FRACT;
    case 14: return TypeSpecifierType::B_FLOAT16;
    case 15: return TypeSpecifierType::FLOAT;
    case 16: return TypeSpecifierType::DOUBLE;
    case 17: return TypeSpecifierType::FLOAT128;
    case 18: return TypeSpecifierType::IBM128;
    case 19: return TypeSpecifierType::BOOLEAN;
    case 20: return TypeSpecifierType::DECIMAL32;
    case 21: return TypeSpecifierType::DECIMAL64;
    case 22: return TypeSpecifierType::DECIMAL128;
    case 23: return TypeSpecifierType::ENUM;
    case 24: return TypeSpecifierType::UNION;
    case 25: return TypeSpecifierType::STRUCT;
    case 26: return TypeSpecifierType::CLASS;
    case 27: return TypeSpecifierType::INTERFACE;
    case 28: return TypeSpecifierType::TYPENAME;
    case 29: return TypeSpecifierType::TYPEOF_TYPE;
    case 30: return TypeSpecifierType::TYPEOF_EXPRESSION;
    case 31: return TypeSpecifierType::TYPEOF_UNQUALIFIED_TYPE;
    case 32: return TypeSpecifierType::TYPEOF_UNQUALIFIED_EXPRESSION;
    case 33: return TypeSpecifierType::DECLTYPE;
    case 34: return TypeSpecifierType::ADD_LVALUE_REFERENCE;
    case 35: return TypeSpecifierType::ADD_POINTER;
    case 36: return TypeSpecifierType::ADD_RVALUE_REFERENCE;
    case 37: return TypeSpecifierType::DECAY;
    case 38: return TypeSpecifierType::MAKE_SIGNED;
    case 39: return TypeSpecifierType::MAKE_UNSIGNED;
    case 40: return TypeSpecifierType::REMOVE_ALL_EXTENTS;
    case 41: return TypeSpecifierType::REMOVE_CONST;
    case 42: return TypeSpecifierType::REMOVE_CV;
    case 43: return TypeSpecifierType::REMOVE_CVREF;
    case 44: return TypeSpecifierType::REMOVE_EXTENT;
    case 45: return TypeSpecifierType::REMOVE_POINTER;
    case 46: return TypeSpecifierType::REMOVE_REFERENCE_T;
    case 47: return TypeSpecifierType::REMOVE_RESTRICT;
    case 48: return TypeSpecifierType::REMOVE_VOLATILE;
    case 49: return TypeSpecifierType::UNDERLYING_TYPE;
    case 50: return TypeSpecifierType::AUTO;
    case 51: return TypeSpecifierType::DECLTYPE_AUTO;
    case 52: return TypeSpecifierType::AUTO_TYPE;
    case 53: return TypeSpecifierType::UNKNOWN_ANYTYPE;
    case 54: return TypeSpecifierType::ATOMIC;
    case 55: return TypeSpecifierType::IMAGE_1D_T;
    case 56: return TypeSpecifierType::IMAGE_1D_ARRAY_T;
    case 57: return TypeSpecifierType::IMAGE_1D_BUFFER_T;
    case 58: return TypeSpecifierType::IMAGE_2D_T;
    case 59: return TypeSpecifierType::IMAGE_2D_ARRAY_T;
    case 60: return TypeSpecifierType::IMAGE_2D_DEPTH_T;
    case 61: return TypeSpecifierType::IMAGE_2D_ARRAY_DEPTH_T;
    case 62: return TypeSpecifierType::IMAGE_2D_MSAA_T;
    case 63: return TypeSpecifierType::IMAGE_2D_ARRAY_MSAA_T;
    case 64: return TypeSpecifierType::IMAGE_2D_MSAA_DEPTH_T;
    case 65: return TypeSpecifierType::IMAGE_2D_ARRAY_MSAA_DEPTH_T;
    case 66: return TypeSpecifierType::IMAGE_3D_T;
    case 67: return TypeSpecifierType::ERROR;
    default: __builtin_unreachable();
  }
}

TypeSpecifierWidth FromPasta(pasta::TypeSpecifierWidth e) {
  switch (static_cast<int>(e)) {
    case 0: return TypeSpecifierWidth::UNSPECIFIED;
    case 1: return TypeSpecifierWidth::SHORT;
    case 2: return TypeSpecifierWidth::LONG;
    case 3: return TypeSpecifierWidth::LONG_LONG;
    default: __builtin_unreachable();
  }
}

TypeSpecifiersPipe FromPasta(pasta::TypeSpecifiersPipe e) {
  switch (static_cast<int>(e)) {
    case 0: return TypeSpecifiersPipe::UNSPECIFIED;
    case 1: return TypeSpecifiersPipe::PIPE;
    default: __builtin_unreachable();
  }
}

TypeTrait FromPasta(pasta::TypeTrait e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TypeTrait::IS_INTERFACE_CLASS;
    case 1: return TypeTrait::IS_SEALED;
    case 2: return TypeTrait::IS_DESTRUCTIBLE;
    case 3: return TypeTrait::IS_TRIVIALLY_DESTRUCTIBLE;
    case 4: return TypeTrait::IS_NOTHROW_DESTRUCTIBLE;
    case 5: return TypeTrait::HAS_NOTHROW_MOVE_ASSIGN;
    case 6: return TypeTrait::HAS_TRIVIAL_MOVE_ASSIGN;
    case 7: return TypeTrait::HAS_TRIVIAL_MOVE_CONSTRUCTOR;
    case 8: return TypeTrait::HAS_NOTHROW_ASSIGN;
    case 9: return TypeTrait::HAS_NOTHROW_COPY;
    case 10: return TypeTrait::HAS_NOTHROW_CONSTRUCTOR;
    case 11: return TypeTrait::HAS_TRIVIAL_ASSIGN;
    case 12: return TypeTrait::HAS_TRIVIAL_COPY;
    case 13: return TypeTrait::HAS_TRIVIAL_DEFAULT_CONSTRUCTOR;
    case 14: return TypeTrait::HAS_TRIVIAL_DESTRUCTOR;
    case 15: return TypeTrait::HAS_VIRTUAL_DESTRUCTOR;
    case 16: return TypeTrait::IS_ABSTRACT;
    case 17: return TypeTrait::IS_AGGREGATE;
    case 18: return TypeTrait::IS_CLASS;
    case 19: return TypeTrait::IS_EMPTY;
    case 20: return TypeTrait::IS_ENUM;
    case 21: return TypeTrait::IS_FINAL;
    case 22: return TypeTrait::IS_LITERAL;
    case 23: return TypeTrait::IS_POD;
    case 24: return TypeTrait::IS_POLYMORPHIC;
    case 25: return TypeTrait::IS_STANDARD_LAYOUT;
    case 26: return TypeTrait::IS_TRIVIAL;
    case 27: return TypeTrait::IS_TRIVIALLY_COPYABLE;
    case 28: return TypeTrait::IS_UNION;
    case 29: return TypeTrait::HAS_UNIQUE_OBJECT_REPRESENTATIONS;
    case 30: return TypeTrait::IS_TRIVIALLY_RELOCATABLE;
    case 31: return TypeTrait::IS_BOUNDED_ARRAY;
    case 32: return TypeTrait::IS_UNBOUNDED_ARRAY;
    case 33: return TypeTrait::IS_NULL_POINTER;
    case 34: return TypeTrait::IS_SCOPED_ENUM;
    case 35: return TypeTrait::IS_REFERENCEABLE;
    case 36: return TypeTrait::IS_ARITHMETIC;
    case 37: return TypeTrait::IS_FLOATING_POINT;
    case 38: return TypeTrait::IS_INTEGRAL;
    case 39: return TypeTrait::IS_COMPLETE_TYPE;
    case 40: return TypeTrait::IS_VOID;
    case 41: return TypeTrait::IS_ARRAY;
    case 42: return TypeTrait::IS_FUNCTION;
    case 43: return TypeTrait::IS_REFERENCE;
    case 44: return TypeTrait::IS_LVALUE_REFERENCE;
    case 45: return TypeTrait::IS_RVALUE_REFERENCE;
    case 46: return TypeTrait::IS_FUNDAMENTAL;
    case 47: return TypeTrait::IS_OBJECT;
    case 48: return TypeTrait::IS_SCALAR;
    case 49: return TypeTrait::IS_COMPOUND;
    case 50: return TypeTrait::IS_POINTER;
    case 51: return TypeTrait::IS_MEMBER_OBJECT_POINTER;
    case 52: return TypeTrait::IS_MEMBER_FUNCTION_POINTER;
    case 53: return TypeTrait::IS_MEMBER_POINTER;
    case 54: return TypeTrait::IS_CONST;
    case 55: return TypeTrait::IS_VOLATILE;
    case 56: return TypeTrait::IS_SIGNED;
    case 57: return TypeTrait::IS_UNSIGNED;
    case 58: return TypeTrait::TYPE_COMPATIBLE;
    case 59: return TypeTrait::IS_NOTHROW_ASSIGNABLE;
    case 60: return TypeTrait::IS_ASSIGNABLE;
    case 61: return TypeTrait::IS_BASE_OF;
    case 62: return TypeTrait::IS_CONVERTIBLE_TO;
    case 63: return TypeTrait::IS_TRIVIALLY_ASSIGNABLE;
    case 64: return TypeTrait::REFERENCE_BINDS_TO_TEMPORARY;
    case 65: return TypeTrait::IS_SAME;
    case 66: return TypeTrait::IS_CONVERTIBLE;
    case 67: return TypeTrait::XNU_TYPE_COMPATIBLE;
    case 68: return TypeTrait::IS_CONSTRUCTIBLE;
    case 69: return TypeTrait::IS_NOTHROW_CONSTRUCTIBLE;
    case 70: return TypeTrait::IS_TRIVIALLY_CONSTRUCTIBLE;
    default: __builtin_unreachable();
  }
}

UnaryExprOrTypeTrait FromPasta(pasta::UnaryExprOrTypeTrait e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return UnaryExprOrTypeTrait::SIZE_OF;
    case 1: return UnaryExprOrTypeTrait::ALIGN_OF;
    case 2: return UnaryExprOrTypeTrait::PREFERRED_ALIGN_OF;
    case 3: return UnaryExprOrTypeTrait::POINTER_AUTH_TYPE_DISCRIMINATOR;
    case 4: return UnaryExprOrTypeTrait::XNU_TYPE_SIGNATURE;
    case 5: return UnaryExprOrTypeTrait::XNU_TYPE_SUMMARY;
    case 6: return UnaryExprOrTypeTrait::TMO_TYPE_GET_METADATA;
    case 7: return UnaryExprOrTypeTrait::VEC_STEP;
    case 8: return UnaryExprOrTypeTrait::OPEN_MP_REQUIRED_SIMD_ALIGN;
    default: __builtin_unreachable();
  }
}

UnaryOperatorKind FromPasta(pasta::UnaryOperatorKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return UnaryOperatorKind::POST_INCREMENT;
    case 1: return UnaryOperatorKind::POST_DEC;
    case 2: return UnaryOperatorKind::PRE_INCREMENT;
    case 3: return UnaryOperatorKind::PRE_DEC;
    case 4: return UnaryOperatorKind::ADDRESS_OF;
    case 5: return UnaryOperatorKind::DEREF;
    case 6: return UnaryOperatorKind::PLUS;
    case 7: return UnaryOperatorKind::MINUS;
    case 8: return UnaryOperatorKind::NOT;
    case 9: return UnaryOperatorKind::L_NOT;
    case 10: return UnaryOperatorKind::REAL;
    case 11: return UnaryOperatorKind::IMAG;
    case 12: return UnaryOperatorKind::EXTENSION;
    case 13: return UnaryOperatorKind::COAWAIT;
    default: __builtin_unreachable();
  }
}

APValueKind FromPasta(pasta::APValueKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return APValueKind::NONE;
    case 1: return APValueKind::INDETERMINATE;
    case 2: return APValueKind::INT;
    case 3: return APValueKind::FLOAT;
    case 4: return APValueKind::FIXED_POINT;
    case 5: return APValueKind::COMPLEX_INT;
    case 6: return APValueKind::COMPLEX_FLOAT;
    case 7: return APValueKind::L_VALUE;
    case 8: return APValueKind::VECTOR;
    case 9: return APValueKind::ARRAY;
    case 10: return APValueKind::STRUCT;
    case 11: return APValueKind::UNION;
    case 12: return APValueKind::MEMBER_POINTER;
    case 13: return APValueKind::ADDRESS_LABEL_DIFF;
    default: __builtin_unreachable();
  }
}

VectorLibrary FromPasta(pasta::VectorLibrary e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return VectorLibrary::NO_LIBRARY;
    case 1: return VectorLibrary::ACCELERATE;
    case 2: return VectorLibrary::LIBMVEC;
    case 3: return VectorLibrary::MASSV;
    case 4: return VectorLibrary::SVML;
    case 5: return VectorLibrary::SLEEF;
    case 6: return VectorLibrary::DARWIN_LIBSYSTEM_M;
    default: __builtin_unreachable();
  }
}

Visibility FromPasta(pasta::Visibility e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return Visibility::HIDDEN_VISIBILITY;
    case 1: return Visibility::PROTECTED_VISIBILITY;
    case 2: return Visibility::DEFAULT_VISIBILITY;
    default: __builtin_unreachable();
  }
}

AttributeSyntax FromPasta(pasta::AttributeSyntax e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AttributeSyntax::GNU;
    case 1: return AttributeSyntax::CXX11;
    case 2: return AttributeSyntax::C2X;
    case 3: return AttributeSyntax::DECLSPEC;
    case 4: return AttributeSyntax::MICROSOFT;
    case 5: return AttributeSyntax::KEYWORD;
    case 6: return AttributeSyntax::PRAGMA;
    case 7: return AttributeSyntax::CONTEXT_SENSITIVE_KEYWORD;
    default: __builtin_unreachable();
  }
}

DeclCategory FromPasta(pasta::DeclCategory e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DeclCategory::UNKNOWN;
    case 1: return DeclCategory::LOCAL_VARIABLE;
    case 2: return DeclCategory::GLOBAL_VARIABLE;
    case 3: return DeclCategory::PARAMETER_VARIABLE;
    case 4: return DeclCategory::FUNCTION;
    case 5: return DeclCategory::INSTANCE_METHOD;
    case 6: return DeclCategory::INSTANCE_MEMBER;
    case 7: return DeclCategory::CLASS_METHOD;
    case 8: return DeclCategory::CLASS_MEMBER;
    case 9: return DeclCategory::THIS;
    case 10: return DeclCategory::CLASS;
    case 11: return DeclCategory::STRUCTURE;
    case 12: return DeclCategory::UNION;
    case 13: return DeclCategory::CONCEPT;
    case 14: return DeclCategory::INTERFACE;
    case 15: return DeclCategory::ENUMERATION;
    case 16: return DeclCategory::ENUMERATOR;
    case 17: return DeclCategory::NAMESPACE;
    case 18: return DeclCategory::TYPE_ALIAS;
    case 19: return DeclCategory::TEMPLATE_TYPE_PARAMETER;
    case 20: return DeclCategory::TEMPLATE_VALUE_PARAMETER;
    case 21: return DeclCategory::LABEL;
    default: __builtin_unreachable();
  }
}

MacroKind FromPasta(pasta::MacroKind e) {
  switch (static_cast<unsigned char>(e)) {
    case 1: return MacroKind::SUBSTITUTION;
    case 2: return MacroKind::EXPANSION;
    case 3: return MacroKind::ARGUMENT;
    case 4: return MacroKind::PARAMETER;
    case 5: return MacroKind::OTHER_DIRECTIVE;
    case 6: return MacroKind::IF_DIRECTIVE;
    case 7: return MacroKind::IF_DEFINED_DIRECTIVE;
    case 8: return MacroKind::IF_NOT_DEFINED_DIRECTIVE;
    case 9: return MacroKind::ELSE_IF_DIRECTIVE;
    case 10: return MacroKind::ELSE_IF_DEFINED_DIRECTIVE;
    case 11: return MacroKind::ELSE_IF_NOT_DEFINED_DIRECTIVE;
    case 12: return MacroKind::ELSE_DIRECTIVE;
    case 13: return MacroKind::END_IF_DIRECTIVE;
    case 14: return MacroKind::DEFINE_DIRECTIVE;
    case 15: return MacroKind::UNDEFINE_DIRECTIVE;
    case 16: return MacroKind::PRAGMA_DIRECTIVE;
    case 17: return MacroKind::INCLUDE_DIRECTIVE;
    case 18: return MacroKind::INCLUDE_NEXT_DIRECTIVE;
    case 19: return MacroKind::INCLUDE_MACROS_DIRECTIVE;
    case 20: return MacroKind::IMPORT_DIRECTIVE;
    case 21: return MacroKind::PARAMETER_SUBSTITUTION;
    case 22: return MacroKind::STRINGIFY;
    case 23: return MacroKind::CONCATENATE;
    case 24: return MacroKind::VA_OPT;
    case 25: return MacroKind::VA_OPT_ARGUMENT;
    default: __builtin_unreachable();
  }
}

PathKind FromPasta(pasta::PathKind e) {
  switch (static_cast<signed char>(e)) {
    case 47: return PathKind::UNIX;
    case 92: return PathKind::WINDOWS;
    default: __builtin_unreachable();
  }
}

FileType FromPasta(pasta::FileType e) {
  switch (static_cast<signed char>(e)) {
    case 0: return FileType::NONE;
    case -1: return FileType::NOT_FOUND;
    case 1: return FileType::REGULAR;
    case 2: return FileType::DIRECTORY;
    case 3: return FileType::SYMBOLIC_LINK;
    case 4: return FileType::BLOCK;
    case 5: return FileType::CHARACTER;
    case 6: return FileType::FIRST_IN_FIRST_OUT;
    case 7: return FileType::SOCKET;
    case 8: return FileType::KNKNOWN;
    default: __builtin_unreachable();
  }
}

CompilerName FromPasta(pasta::CompilerName e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CompilerName::UNKNOWN;
    case 1: return CompilerName::CLANG;
    case 2: return CompilerName::APPLE_CLANG;
    case 3: return CompilerName::CLANG_CL;
    case 4: return CompilerName::CL;
    case 5: return CompilerName::GNU;
    default: __builtin_unreachable();
  }
}

IncludePathLocation FromPasta(pasta::IncludePathLocation e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return IncludePathLocation::ABSOLUTE;
    case 1: return IncludePathLocation::SYSROOT_RELATIVE;
    default: __builtin_unreachable();
  }
}

TargetLanguage FromPasta(pasta::TargetLanguage e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TargetLanguage::C;
    case 1: return TargetLanguage::CXX;
    default: __builtin_unreachable();
  }
}

PseudoKind FromPasta(pasta::PseudoKind e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return PseudoKind::TEMPLATE_ARGUMENT;
    case 1: return PseudoKind::TEMPLATE_PARAMETER_LIST;
    case 2: return PseudoKind::CXX_BASE_SPECIFIER;
    case 3: return PseudoKind::DESIGNATOR;
    default: __builtin_unreachable();
  }
}

TokenCategory FromPasta(pasta::TokenCategory e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return TokenCategory::UNKNOWN;
    case 1: return TokenCategory::IDENTIFIER;
    case 2: return TokenCategory::MACRO_NAME;
    case 3: return TokenCategory::MACRO_PARAMETER_NAME;
    case 4: return TokenCategory::MACRO_DIRECTIVE_NAME;
    case 5: return TokenCategory::KEYWORD;
    case 6: return TokenCategory::OBJECTIVE_C_KEYWORD;
    case 7: return TokenCategory::BUILTIN_TYPE_NAME;
    case 8: return TokenCategory::PUNCTUATION;
    case 9: return TokenCategory::LITERAL;
    case 10: return TokenCategory::COMMENT;
    case 11: return TokenCategory::LOCAL_VARIABLE;
    case 12: return TokenCategory::GLOBAL_VARIABLE;
    case 13: return TokenCategory::PARAMETER_VARIABLE;
    case 14: return TokenCategory::FUNCTION;
    case 15: return TokenCategory::INSTANCE_METHOD;
    case 16: return TokenCategory::INSTANCE_MEMBER;
    case 17: return TokenCategory::CLASS_METHOD;
    case 18: return TokenCategory::CLASS_MEMBER;
    case 19: return TokenCategory::THIS;
    case 20: return TokenCategory::CLASS;
    case 21: return TokenCategory::STRUCT;
    case 22: return TokenCategory::UNION;
    case 23: return TokenCategory::CONCEPT;
    case 24: return TokenCategory::INTERFACE;
    case 25: return TokenCategory::ENUM;
    case 26: return TokenCategory::ENUMERATOR;
    case 27: return TokenCategory::NAMESPACE;
    case 28: return TokenCategory::TYPE_ALIAS;
    case 29: return TokenCategory::TEMPLATE_PARAMETER_TYPE;
    case 30: return TokenCategory::TEMPLATE_PARAMETER_VALUE;
    case 31: return TokenCategory::LABEL;
    case 32: return TokenCategory::WHITESPACE;
    case 33: return TokenCategory::FILE_NAME;
    case 34: return TokenCategory::LINE_NUMBER;
    case 35: return TokenCategory::COLUMN_NUMBER;
    default: __builtin_unreachable();
  }
}

}  // namespace mx
