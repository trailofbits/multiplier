// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include "../Compiler.h"

namespace mx::ir {

// Sub-opcodes for CONST. Stored in the int pool (int_pool[0]).
// Encodes both the type and width of the constant.
enum class ConstOp : uint8_t {
  INT8 = 0,
  INT16 = 1,
  INT32 = 2,
  INT64 = 3,
  UINT8 = 4,
  UINT16 = 5,
  UINT32 = 6,
  UINT64 = 7,
  FLOAT32 = 8,
  FLOAT64 = 9,
  FLOAT16 = 10,
  NULL_PTR = 11,
  INF32 = 12,
  INF64 = 13,
  NAN32 = 14,
  NAN64 = 15,
  WCHAR16 = 16,
  WCHAR32 = 17,
  BOOL = 18,
};

// Sub-opcodes for ALLOCA. Stored in the int pool (int_pool[0]).
enum class AllocaKind : uint8_t {
  LOCAL = 0,       // regular local variable
  ARG = 1,         // argument passing alloca in EXPRESSION_SCOPE
  RETURN = 2,      // return value storage in EXPRESSION_SCOPE
  DYNAMIC = 3,     // runtime-sized (VLA, alloca())
};

// Sub-opcodes for CAST. Stored in the int pool (int_pool[0]).
enum class CastOp : uint8_t {
  // Sign-extend
  SEXT_I8_I16 = 0,
  SEXT_I8_I32,
  SEXT_I8_I64,
  SEXT_I16_I32,
  SEXT_I16_I64,
  SEXT_I32_I64,

  // Zero-extend
  ZEXT_I8_I16,
  ZEXT_I8_I32,
  ZEXT_I8_I64,
  ZEXT_I16_I32,
  ZEXT_I16_I64,
  ZEXT_I32_I64,

  // Truncate
  TRUNC_I16_I8,
  TRUNC_I32_I8,
  TRUNC_I64_I8,
  TRUNC_I32_I16,
  TRUNC_I64_I16,
  TRUNC_I64_I32,

  // Float widening/narrowing
  F32_TO_F64,
  F64_TO_F32,

  // Signed int to float
  SI8_TO_F32,
  SI8_TO_F64,
  SI16_TO_F32,
  SI16_TO_F64,
  SI32_TO_F32,
  SI32_TO_F64,
  SI64_TO_F32,
  SI64_TO_F64,

  // Unsigned int to float
  UI8_TO_F32,
  UI8_TO_F64,
  UI16_TO_F32,
  UI16_TO_F64,
  UI32_TO_F32,
  UI32_TO_F64,
  UI64_TO_F32,
  UI64_TO_F64,

  // Float to signed int
  F32_TO_SI8,
  F32_TO_SI16,
  F32_TO_SI32,
  F32_TO_SI64,
  F64_TO_SI8,
  F64_TO_SI16,
  F64_TO_SI32,
  F64_TO_SI64,

  // Float to unsigned int
  F32_TO_UI8,
  F32_TO_UI16,
  F32_TO_UI32,
  F32_TO_UI64,
  F64_TO_UI8,
  F64_TO_UI16,
  F64_TO_UI32,
  F64_TO_UI64,

  // Pointer conversions
  PTR_TO_I32,
  PTR_TO_I64,
  I32_TO_PTR,
  I64_TO_PTR,

  // Bitcast (reinterpret bits, same size)
  BITCAST,

  // Identity (no-op, replaces COPY for implicit conversions)
  IDENTITY,
};

// CastOp classification helpers.
inline bool IsSignExtend(CastOp op) {
  return op >= CastOp::SEXT_I8_I16 && op <= CastOp::SEXT_I32_I64;
}

inline bool IsZeroExtend(CastOp op) {
  return op >= CastOp::ZEXT_I8_I16 && op <= CastOp::ZEXT_I32_I64;
}

inline bool IsTruncate(CastOp op) {
  return op >= CastOp::TRUNC_I16_I8 && op <= CastOp::TRUNC_I64_I32;
}

inline bool IsIntToFloat(CastOp op) {
  return op >= CastOp::SI8_TO_F32 && op <= CastOp::UI64_TO_F64;
}

inline bool IsFloatToInt(CastOp op) {
  return op >= CastOp::F32_TO_SI8 && op <= CastOp::F64_TO_UI64;
}

inline bool IsPtrToInt(CastOp op) {
  return op == CastOp::PTR_TO_I32 || op == CastOp::PTR_TO_I64;
}

inline bool IsIntToPtr(CastOp op) {
  return op == CastOp::I32_TO_PTR || op == CastOp::I64_TO_PTR;
}

inline bool IsFloatToSigned(CastOp op) {
  return op >= CastOp::F32_TO_SI8 && op <= CastOp::F64_TO_SI64;
}

inline bool IsSignedToFloat(CastOp op) {
  return op >= CastOp::SI8_TO_F32 && op <= CastOp::SI64_TO_F64;
}

inline bool IsToFloat32(CastOp op) {
  unsigned v = static_cast<unsigned>(op);
  // The *_TO_F32 variants alternate: even index = F32, odd = F64.
  // SI8_TO_F32=22, SI8_TO_F64=23, SI16_TO_F32=24, ...
  // UI8_TO_F32=30, UI8_TO_F64=31, ...
  if (op >= CastOp::SI8_TO_F32 && op <= CastOp::UI64_TO_F64) {
    return (v % 2) == (static_cast<unsigned>(CastOp::SI8_TO_F32) % 2);
  }
  return false;
}

// Source width in bytes for sign-extension.
inline unsigned SignExtendSourceWidth(CastOp op) {
  switch (op) {
    case CastOp::SEXT_I8_I16:
    case CastOp::SEXT_I8_I32:
    case CastOp::SEXT_I8_I64: return 1;
    case CastOp::SEXT_I16_I32:
    case CastOp::SEXT_I16_I64: return 2;
    case CastOp::SEXT_I32_I64: return 4;
    default: return 8;
  }
}

// Source width in bytes for zero-extension.
inline unsigned ZeroExtendSourceWidth(CastOp op) {
  switch (op) {
    case CastOp::ZEXT_I8_I16:
    case CastOp::ZEXT_I8_I32:
    case CastOp::ZEXT_I8_I64: return 1;
    case CastOp::ZEXT_I16_I32:
    case CastOp::ZEXT_I16_I64: return 2;
    case CastOp::ZEXT_I32_I64: return 4;
    default: return 8;
  }
}

// Destination width in bytes for truncation.
inline unsigned TruncateDestWidth(CastOp op) {
  switch (op) {
    case CastOp::TRUNC_I16_I8:
    case CastOp::TRUNC_I32_I8:
    case CastOp::TRUNC_I64_I8: return 1;
    case CastOp::TRUNC_I32_I16:
    case CastOp::TRUNC_I64_I16: return 2;
    case CastOp::TRUNC_I64_I32: return 4;
    default: return 8;
  }
}

// Single unified opcode enum for all IR instruction types. The C++ class
// hierarchy on the read side is derived from this enum.
enum class OpCode : uint8_t {
  // Constant (sub-opcode in int_pool[0] selects ConstOp).
  CONST = 0,

  // Memory (ALLOCA sub-opcode in int_pool[0] selects AllocaKind).
  ALLOCA = 1,
  MEMORY = 2,          // Unified load/store/bulk/string (sub-opcode in int_pool[0] selects MemOp).

  // Logical (produce 0 or 1, no width).
  LOGICAL_AND = 15,
  LOGICAL_OR = 16,

  LOGICAL_NOT = 26,

  // Cast (sub-opcode in int_pool[0] selects CastOp).
  CAST = 27,

  // Call
  CALL = 28,

  // Read-modify-write: reads from address, applies an operation, writes back.
  // operands = [address, rhs_operand0, rhs_operand1, ...].
  // The loaded value is the implicit LHS of the underlying op.
  // flags: bit 0 = returns new value (1) or old value (0, post-increment).
  // int_pool[0] = underlying opcode (ADD, SUB, PTR_ADD, ATOMIC_ADD, etc.)
  // int_pool[1] = element size (for PTR_ADD only, 0 otherwise)
  // int_pool[2] = is_big_endian (0 = little-endian, 1 = big-endian)
  READ_MODIFY_WRITE = 29,

  // Misc
  SELECT = 30,

  // Terminators
  COND_BRANCH = 31,
  SWITCH = 32,
  RET = 33,
  UNREACHABLE = 34,
  BREAK = 35,
  CONTINUE = 36,
  GOTO = 37,              // explicit goto label;
  IMPLICIT_GOTO = 38,     // structural CFG edge (e.g., end of if-then -> merge)
  FALLTHROUGH = 39,       // explicit [[fallthrough]]
  IMPLICIT_FALLTHROUGH = 40, // implicit (no break at end of case)
  IMPLICIT_UNREACHABLE = 41, // structurally unreachable (patched empty block)

  // Variadic argument handling
  VA_START = 43,          // binds va_list to function's variadic pack; op[0] = va_list
  VA_COPY = 45,           // copies va_list; op[0] = dest, op[1] = src
  VA_END = 46,            // releases va_list; op[0] = va_list

  // Scope entry/exit markers (not terminators).
  ENTER_SCOPE = 47,        // marks scope entry; extra = IRStructureId of scope
  EXIT_SCOPE = 48,         // marks scope exit; extra = IRStructureId of scope

  // (Pointer-producing ops are sized: see GEP_FIELD_32/64, PTR_ADD_32/64,
  //  PARAM_PTR_32/64, GLOBAL_PTR_32/64, etc. at the end of the enum.)

  // (BITWISE and ABS are sized: see end of enum.)

  // Floating-point operations. Sub-opcode in int_pool[0] selects the
  // specific operation (see FloatOp enum). op[0] = primary operand.
  FLOAT = 54,

  // Undefined/poison value. Represents a value that is architecturally
  // undefined (e.g., __builtin_clz(0)). An analyzer should flag any use.
  UNDEFINED = 55,

  // (FRAME_PTR and RETURN_ADDRESS are sized: see end of enum.)

  // (Overflow and atomic ops are sized: see end of enum.)

  // Evaluate all operands, return the last one's value.
  LAST_VALUE = 69,

  // Unknown / unhandled expression
  UNKNOWN = 70,

  // (RETURN_PTR is sized: see end of enum.)

  // Floating-point comparisons (IEEE 754 semantics, width-specific).
  FCMP_EQ_32 = 79,  FCMP_EQ_64 = 80,
  FCMP_NE_32 = 81,  FCMP_NE_64 = 82,
  FCMP_LT_32 = 83,  FCMP_LT_64 = 84,
  FCMP_LE_32 = 85,  FCMP_LE_64 = 86,
  FCMP_GT_32 = 87,  FCMP_GT_64 = 88,
  FCMP_GE_32 = 89,  FCMP_GE_64 = 90,

  // Floating-point arithmetic (width-specific).
  // Integer ADD/SUB/MUL/DIV/REM must not be used for float operands.
  FADD_32 = 91,    FADD_64 = 92,
  FSUB_32 = 93,    FSUB_64 = 94,
  FMUL_32 = 95,    FMUL_64 = 96,
  FDIV_32 = 97,    FDIV_64 = 98,
  FREM_32 = 99,    FREM_64 = 100,   // C fmod semantics.
  FNEG_32 = 101,   FNEG_64 = 102,

  // Width-specific integer arithmetic (signed).
  ADD_8 = 103, ADD_16 = 104, ADD_32 = 105, ADD_64 = 106,
  SUB_8 = 107, SUB_16 = 108, SUB_32 = 109, SUB_64 = 110,
  MUL_8 = 111, MUL_16 = 112, MUL_32 = 113, MUL_64 = 114,
  DIV_8 = 115, DIV_16 = 116, DIV_32 = 117, DIV_64 = 118,
  REM_8 = 119, REM_16 = 120, REM_32 = 121, REM_64 = 122,

  // Width-specific unsigned arithmetic.
  UDIV_8 = 123, UDIV_16 = 124, UDIV_32 = 125, UDIV_64 = 126,
  UREM_8 = 127, UREM_16 = 128, UREM_32 = 129, UREM_64 = 130,
  USHR_8 = 131, USHR_16 = 132, USHR_32 = 133, USHR_64 = 134,

  // Width-specific bitwise operations.
  BIT_AND_8 = 135, BIT_AND_16 = 136, BIT_AND_32 = 137, BIT_AND_64 = 138,
  BIT_OR_8 = 139, BIT_OR_16 = 140, BIT_OR_32 = 141, BIT_OR_64 = 142,
  BIT_XOR_8 = 143, BIT_XOR_16 = 144, BIT_XOR_32 = 145, BIT_XOR_64 = 146,
  SHL_8 = 147, SHL_16 = 148, SHL_32 = 149, SHL_64 = 150,
  SHR_8 = 151, SHR_16 = 152, SHR_32 = 153, SHR_64 = 154,

  // Width-specific signed comparisons.
  CMP_EQ_8 = 155, CMP_EQ_16 = 156, CMP_EQ_32 = 157, CMP_EQ_64 = 158,
  CMP_NE_8 = 159, CMP_NE_16 = 160, CMP_NE_32 = 161, CMP_NE_64 = 162,
  CMP_LT_8 = 163, CMP_LT_16 = 164, CMP_LT_32 = 165, CMP_LT_64 = 166,
  CMP_LE_8 = 167, CMP_LE_16 = 168, CMP_LE_32 = 169, CMP_LE_64 = 170,
  CMP_GT_8 = 171, CMP_GT_16 = 172, CMP_GT_32 = 173, CMP_GT_64 = 174,
  CMP_GE_8 = 175, CMP_GE_16 = 176, CMP_GE_32 = 177, CMP_GE_64 = 178,

  // Width-specific unsigned comparisons.
  UCMP_LT_8 = 179, UCMP_LT_16 = 180, UCMP_LT_32 = 181, UCMP_LT_64 = 182,
  UCMP_LE_8 = 183, UCMP_LE_16 = 184, UCMP_LE_32 = 185, UCMP_LE_64 = 186,
  UCMP_GT_8 = 187, UCMP_GT_16 = 188, UCMP_GT_32 = 189, UCMP_GT_64 = 190,
  UCMP_GE_8 = 191, UCMP_GE_16 = 192, UCMP_GE_32 = 193, UCMP_GE_64 = 194,

  // Width-specific unary operations.
  NEG_8 = 195, NEG_16 = 196, NEG_32 = 197, NEG_64 = 198,
  BIT_NOT_8 = 199, BIT_NOT_16 = 200, BIT_NOT_32 = 201, BIT_NOT_64 = 202,

  // Width-specific pointer operations.
  PTR_ADD_32 = 203,           PTR_ADD_64 = 204,
  GEP_FIELD_32 = 205,        GEP_FIELD_64 = 206,
  GLOBAL_PTR_32 = 207,       GLOBAL_PTR_64 = 208,
  THREAD_LOCAL_PTR_32 = 209,  THREAD_LOCAL_PTR_64 = 210,
  FUNC_PTR_32 = 211,         FUNC_PTR_64 = 212,
  STRING_PTR_32 = 213,       STRING_PTR_64 = 214,
  PARAM_PTR_32 = 215,        PARAM_PTR_64 = 216,
  FRAME_PTR_32 = 217,        FRAME_PTR_64 = 218,
  RETURN_PTR_32 = 219,       RETURN_PTR_64 = 220,
  RETURN_ADDRESS_32 = 221,   RETURN_ADDRESS_64 = 222,

  // Width-specific atomic RMW underlying opcodes.
  ATOMIC_ADD_8 = 223, ATOMIC_ADD_16 = 224, ATOMIC_ADD_32 = 225, ATOMIC_ADD_64 = 226,
  ATOMIC_SUB_8 = 227, ATOMIC_SUB_16 = 228, ATOMIC_SUB_32 = 229, ATOMIC_SUB_64 = 230,
  ATOMIC_AND_8 = 231, ATOMIC_AND_16 = 232, ATOMIC_AND_32 = 233, ATOMIC_AND_64 = 234,
  ATOMIC_OR_8 = 235, ATOMIC_OR_16 = 236, ATOMIC_OR_32 = 237, ATOMIC_OR_64 = 238,
  ATOMIC_XOR_8 = 239, ATOMIC_XOR_16 = 240, ATOMIC_XOR_32 = 241, ATOMIC_XOR_64 = 242,
  ATOMIC_NAND_8 = 243, ATOMIC_NAND_16 = 244, ATOMIC_NAND_32 = 245, ATOMIC_NAND_64 = 246,
  ATOMIC_EXCHANGE_8 = 247, ATOMIC_EXCHANGE_16 = 248, ATOMIC_EXCHANGE_32 = 249, ATOMIC_EXCHANGE_64 = 250,

  // Width-specific overflow-checked arithmetic (RMW underlying opcodes).
  // Placed in gap left by removed unsized opcodes (56-67).
  ADD_OVERFLOW_8 = 56, ADD_OVERFLOW_16 = 57, ADD_OVERFLOW_32 = 58, ADD_OVERFLOW_64 = 59,
  SUB_OVERFLOW_8 = 60, SUB_OVERFLOW_16 = 61, SUB_OVERFLOW_32 = 62, SUB_OVERFLOW_64 = 63,
  MUL_OVERFLOW_8 = 64, MUL_OVERFLOW_16 = 65, MUL_OVERFLOW_32 = 66, MUL_OVERFLOW_64 = 67,

  // Width-specific pointer difference (result is ptrdiff_t).
  PTR_DIFF_32 = 3,    PTR_DIFF_64 = 4,

  // Width-specific bitwise intrinsics (sub-opcode in int_pool[0] selects BitwiseOp).
  BITWISE_8 = 5,  BITWISE_16 = 6,  BITWISE_32 = 7,  BITWISE_64 = 8,

  // Width-specific integer absolute value.
  ABS_8 = 9,  ABS_16 = 10,  ABS_32 = 11,  ABS_64 = 12,
};

// Returns the human-readable name of an opcode.
inline static const char *EnumerationName(OpCode) {
  return "OpCode";
}

MX_EXPORT const char *EnumeratorName(OpCode op) noexcept;
MX_EXPORT const char *EnumeratorName(ConstOp op) noexcept;
MX_EXPORT const char *EnumeratorName(AllocaKind op) noexcept;
MX_EXPORT const char *EnumeratorName(CastOp op) noexcept;

inline static constexpr unsigned NumEnumerators(OpCode) {
  return 251u;
}

// Sub-opcodes for MEMORY. Stored in the int pool (int_pool[0]).
// Encodes direction (load/store), atomicity, endianness, access width,
// plus bulk memory and string operations.
enum class MemOp : uint8_t {
  // Loads (non-atomic, little-endian)
  LOAD_LE_8 = 0, LOAD_LE_16 = 1, LOAD_LE_32 = 2, LOAD_LE_64 = 3,
  // Loads (non-atomic, big-endian)
  LOAD_BE_8 = 4, LOAD_BE_16 = 5, LOAD_BE_32 = 6, LOAD_BE_64 = 7,
  // Stores (non-atomic, little-endian)
  STORE_LE_8 = 8, STORE_LE_16 = 9, STORE_LE_32 = 10, STORE_LE_64 = 11,
  // Stores (non-atomic, big-endian)
  STORE_BE_8 = 12, STORE_BE_16 = 13, STORE_BE_32 = 14, STORE_BE_64 = 15,
  // Atomic loads (little-endian)
  ATOMIC_LOAD_LE_8 = 16, ATOMIC_LOAD_LE_16 = 17, ATOMIC_LOAD_LE_32 = 18, ATOMIC_LOAD_LE_64 = 19,
  // Atomic loads (big-endian)
  ATOMIC_LOAD_BE_8 = 20, ATOMIC_LOAD_BE_16 = 21, ATOMIC_LOAD_BE_32 = 22, ATOMIC_LOAD_BE_64 = 23,
  // Atomic stores (little-endian)
  ATOMIC_STORE_LE_8 = 24, ATOMIC_STORE_LE_16 = 25, ATOMIC_STORE_LE_32 = 26, ATOMIC_STORE_LE_64 = 27,
  // Atomic stores (big-endian)
  ATOMIC_STORE_BE_8 = 28, ATOMIC_STORE_BE_16 = 29, ATOMIC_STORE_BE_32 = 30, ATOMIC_STORE_BE_64 = 31,

  // Memory operations.
  MEMSET = 32, MEMCPY = 33, MEMMOVE = 34, MEMCMP = 35, MEMCHR = 36, BZERO = 37,
  // String operations.
  STRLEN = 38, STRNLEN = 39, STRCMP = 40, STRNCMP = 41, STRCHR = 42, STRRCHR = 43,
  STRSTR = 44, STRCPY = 45, STRNCPY = 46, STRCAT = 47, STRNCAT = 48, STPCPY = 49, STPNCPY = 50,
  // String-to-number.
  STRTOI32 = 51, STRTOI64 = 52, STRTOU32 = 53, STRTOU64 = 54, STRTOF32 = 55, STRTOF64 = 56,

  // Bit-field access. Reads/writes individual bit ranges within memory.
  //
  // Addressing model:
  //   The address operand (op[0]) points to the base of the containing
  //   object (e.g., the struct). bit_offset is measured from the LSB of
  //   the first byte at that address, in the target's bit numbering:
  //
  //   Little-endian: bit 0 is the LSB of byte 0. bit_offset=10, width=5
  //   means bits [10..14] spanning bytes 1-2:
  //     byte 0: [7:0]   byte 1: [15:8]   byte 2: [23:16]
  //     field occupies byte1[2:0] and byte2[1:0]
  //
  //   Big-endian: bit 0 is the MSB of byte 0. Layout is reversed.
  //
  // int_pool layout: [MemOp sub-opcode, bit_offset, bit_width]
  // bit_offset and bit_width are compile-time constants (not operands).
  //
  // Bit-field access (see documentation above).
  BIT_READ_LE = 57, BIT_WRITE_LE = 58,
  BIT_READ_BE = 59, BIT_WRITE_BE = 60,

  // Atomic compare-and-exchange (sized, endian-aware).
  // op[0]=target, op[1]=expected_ptr, op[2]=desired. Returns bool.
  CMPXCHG_LE_8 = 61, CMPXCHG_LE_16 = 62, CMPXCHG_LE_32 = 63, CMPXCHG_LE_64 = 64,
  CMPXCHG_BE_8 = 65, CMPXCHG_BE_16 = 66, CMPXCHG_BE_32 = 67, CMPXCHG_BE_64 = 68,

  // Variadic argument consumption. op[0]=va_list_ptr. Reads the current
  // va_list index, memcpys from the corresponding variadic argument alloca
  // in the caller's EXPRESSION_SCOPE, then increments the va_list index.
  // type_entity_id specifies the type/size being consumed.
  CONSUME_VA_PARAM = 69,

  // Float loads/stores (non-atomic).
  LOAD_F32_LE = 70, LOAD_F64_LE = 71,
  LOAD_F32_BE = 72, LOAD_F64_BE = 73,
  STORE_F32_LE = 74, STORE_F64_LE = 75,
  STORE_F32_BE = 76, STORE_F64_BE = 77,
};

// MemOp classification helpers.
inline bool IsLoad(MemOp op) { return static_cast<uint8_t>(op) < 8; }
inline bool IsStore(MemOp op) { auto v = static_cast<uint8_t>(op); return v >= 8 && v < 16; }
inline bool IsAtomicLoad(MemOp op) { auto v = static_cast<uint8_t>(op); return v >= 16 && v < 24; }
inline bool IsAtomicStore(MemOp op) { auto v = static_cast<uint8_t>(op); return v >= 24 && v < 32; }
inline bool IsFloatLoad(MemOp op) { return op >= MemOp::LOAD_F32_LE && op <= MemOp::LOAD_F64_BE; }
inline bool IsFloatStore(MemOp op) { return op >= MemOp::STORE_F32_LE && op <= MemOp::STORE_F64_BE; }
inline bool IsAnyLoad(MemOp op) { return IsLoad(op) || IsAtomicLoad(op) || IsFloatLoad(op); }
inline bool IsAnyStore(MemOp op) { return IsStore(op) || IsAtomicStore(op) || IsFloatStore(op); }
inline bool IsAtomic(MemOp op) { return static_cast<uint8_t>(op) >= 16 && static_cast<uint8_t>(op) < 32; }
inline bool IsBigEndian(MemOp op) {
  if (static_cast<uint8_t>(op) < 32) return (static_cast<uint8_t>(op) % 8) >= 4;
  if (IsFloatLoad(op) || IsFloatStore(op)) {
    return op == MemOp::LOAD_F32_BE || op == MemOp::LOAD_F64_BE ||
           op == MemOp::STORE_F32_BE || op == MemOp::STORE_F64_BE;
  }
  return false;
}
inline unsigned AccessSize(MemOp op) {
  if (static_cast<uint8_t>(op) < 32) {
    switch (static_cast<uint8_t>(op) % 4) { case 0: return 1; case 1: return 2; case 2: return 4; case 3: return 8; }
  }
  if (IsFloatLoad(op) || IsFloatStore(op)) {
    return (op == MemOp::LOAD_F32_LE || op == MemOp::LOAD_F32_BE ||
            op == MemOp::STORE_F32_LE || op == MemOp::STORE_F32_BE) ? 4 : 8;
  }
  return 0;
}
inline bool IsDirectLoadStore(MemOp op) {
  return static_cast<uint8_t>(op) < 32 || IsFloatLoad(op) || IsFloatStore(op);
}
inline bool IsStringToNumber(MemOp op) { return op >= MemOp::STRTOI32 && op <= MemOp::STRTOF64; }
inline bool IsMemoryBulk(MemOp op) { return op >= MemOp::MEMSET && op <= MemOp::BZERO; }
inline bool IsStringOp(MemOp op) { return op >= MemOp::STRLEN && op <= MemOp::STPNCPY; }
inline bool IsBitAccess(MemOp op) { return op >= MemOp::BIT_READ_LE && op <= MemOp::BIT_WRITE_BE; }
inline bool IsCmpxchg(MemOp op) { return op >= MemOp::CMPXCHG_LE_8 && op <= MemOp::CMPXCHG_BE_64; }
inline bool IsBitRead(MemOp op) { return op == MemOp::BIT_READ_LE || op == MemOp::BIT_READ_BE; }
inline bool IsBitWrite(MemOp op) { return op == MemOp::BIT_WRITE_LE || op == MemOp::BIT_WRITE_BE; }

// Sub-opcodes for BITWISE_8/16/32/64. Stored in the int pool.
// Width comes from the parent opcode, not the sub-opcode (except BSWAP
// which has its own width in the name since only 16/32/64 make sense).
enum class BitwiseOp : uint8_t {
  BSWAP_16 = 0,           // Reverse bytes of 16-bit value.
  BSWAP_32 = 1,           // Reverse bytes of 32-bit value.
  BSWAP_64 = 2,           // Reverse bytes of 64-bit value.
  POPCOUNT = 3,            // Number of set bits.
  CLZ = 4,                 // Count leading zeros. UNDEFINED for 0.
  CTZ = 5,                 // Count trailing zeros. UNDEFINED for 0.
  FFS = 6,                 // Find first set (1-indexed). 0 for input 0.
  PARITY = 7,              // 1 if odd number of set bits.
  ROTL = 8,                // Rotate left. op[0]=value, op[1]=amount.
  ROTR = 9,                // Rotate right. op[0]=value, op[1]=amount.
};

// Sub-opcodes for FLOAT. Stored in the int pool.
// Each operation has _32 (float) and _64 (double) variants.
// Laid out as pairs: _32 at even indices, _64 at odd.
enum class FloatOp : uint8_t {
  ISNAN_32 = 0,    ISNAN_64 = 1,       // Returns bool.
  ISINF_32 = 2,    ISINF_64 = 3,       // Returns bool.
  ISFINITE_32 = 4, ISFINITE_64 = 5,    // Returns bool.
  FABS_32 = 6,     FABS_64 = 7,        // Returns |x|.
  COPYSIGN_32 = 8, COPYSIGN_64 = 9,    // op[0]=x, op[1]=y. Returns x with sign of y.
  FMIN_32 = 10,    FMIN_64 = 11,       // Returns min.
  FMAX_32 = 12,    FMAX_64 = 13,       // Returns max.
  CEIL_32 = 14,    CEIL_64 = 15,       // Returns ceil(x).
  FLOOR_32 = 16,   FLOOR_64 = 17,      // Returns floor(x).
  ROUND_32 = 18,   ROUND_64 = 19,      // Returns round(x).
  TRUNC_32 = 20,   TRUNC_64 = 21,      // Returns trunc(x).
  SQRT_32 = 22,    SQRT_64 = 23,       // Returns sqrt(x). UNDEFINED for negative.
  INF_32 = 24,     INF_64 = 25,        // No operands. Returns +infinity.
  NAN_32 = 26,     NAN_64 = 27,        // No operands. Returns NaN.
  HUGE_32 = 28,    HUGE_64 = 29,       // No operands. Returns HUGE_VAL.
  SIN_32 = 30,     SIN_64 = 31,
  COS_32 = 32,     COS_64 = 33,
  TAN_32 = 34,     TAN_64 = 35,
  ASIN_32 = 36,    ASIN_64 = 37,       // UNDEFINED for |x|>1.
  ACOS_32 = 38,    ACOS_64 = 39,       // UNDEFINED for |x|>1.
  ATAN_32 = 40,    ATAN_64 = 41,
  ATAN2_32 = 42,   ATAN2_64 = 43,      // op[0]=y, op[1]=x.
  EXP_32 = 44,     EXP_64 = 45,
  EXP2_32 = 46,    EXP2_64 = 47,
  LOG_32 = 48,     LOG_64 = 49,        // UNDEFINED for x<=0.
  LOG2_32 = 50,    LOG2_64 = 51,
  LOG10_32 = 52,   LOG10_64 = 53,
  POW_32 = 54,     POW_64 = 55,        // op[0]=base, op[1]=exp.
  FMOD_32 = 56,    FMOD_64 = 57,       // C fmod.
  REMAINDER_32 = 58, REMAINDER_64 = 59, // IEEE remainder.
  FMA_32 = 60,     FMA_64 = 61,        // op[0]=x, op[1]=y, op[2]=z. x*y+z.
  SINH_32 = 62,    SINH_64 = 63,
  COSH_32 = 64,    COSH_64 = 65,
  TANH_32 = 66,    TANH_64 = 67,
  HYPOT_32 = 68,   HYPOT_64 = 69,      // sqrt(x^2+y^2).
  ERF_32 = 70,     ERF_64 = 71,
  ERFC_32 = 72,    ERFC_64 = 73,
  TGAMMA_32 = 74,  TGAMMA_64 = 75,
  LGAMMA_32 = 76,  LGAMMA_64 = 77,
  FDIM_32 = 78,    FDIM_64 = 79,       // max(x-y, 0).
  SIGNBIT_32 = 80, SIGNBIT_64 = 81,    // Returns bool.
};

// Classification helpers.
inline bool IsTerminator(OpCode op) {
  return op >= OpCode::COND_BRANCH && op <= OpCode::IMPLICIT_UNREACHABLE;
}

inline bool IsReadModifyWrite(OpCode op) {
  return op == OpCode::READ_MODIFY_WRITE;
}

inline bool IsConstant(OpCode op) {
  return op == OpCode::CONST;
}

inline bool IsBinaryOp(OpCode op) {
  return op == OpCode::LOGICAL_AND || op == OpCode::LOGICAL_OR ||
         op == OpCode::PTR_DIFF_32 || op == OpCode::PTR_DIFF_64 ||
         (op >= OpCode::FCMP_EQ_32 && op <= OpCode::FCMP_GE_64) ||
         (op >= OpCode::FADD_32 && op <= OpCode::FREM_64) ||
         (op >= OpCode::ADD_8 && op <= OpCode::SHR_64) ||
         (op >= OpCode::CMP_EQ_8 && op <= OpCode::UCMP_GE_64);
}

inline bool IsFloatArithmetic(OpCode op) {
  return op >= OpCode::FADD_32 && op <= OpCode::FNEG_64;
}

inline bool IsComparison(OpCode op) {
  return (op >= OpCode::FCMP_EQ_32 && op <= OpCode::FCMP_GE_64) ||
         (op >= OpCode::CMP_EQ_8 && op <= OpCode::UCMP_GE_64);
}

inline bool IsFloatComparison(OpCode op) {
  return op >= OpCode::FCMP_EQ_32 && op <= OpCode::FCMP_GE_64;
}

inline bool IsUnaryOp(OpCode op) {
  return op == OpCode::LOGICAL_NOT ||
         op == OpCode::FNEG_32 || op == OpCode::FNEG_64 ||
         (op >= OpCode::NEG_8 && op <= OpCode::BIT_NOT_64) ||
         (op >= OpCode::ABS_8 && op <= OpCode::ABS_64);
}

inline bool IsCast(OpCode op) {
  return op == OpCode::CAST;
}

inline bool IsPtrOp(OpCode op) {
  return (op >= OpCode::PTR_ADD_32 && op <= OpCode::RETURN_ADDRESS_64);
}

inline bool IsMemoryOp(OpCode op) {
  return op == OpCode::MEMORY || op == OpCode::ALLOCA ||
         (op >= OpCode::GEP_FIELD_32 && op <= OpCode::GEP_FIELD_64) ||
         (op >= OpCode::PTR_ADD_32 && op <= OpCode::PTR_ADD_64);
}

// MemOp write classification (bulk ops that write to memory).
inline bool IsMemoryWrite(MemOp op) {
  return IsAnyStore(op) ||
         op == MemOp::MEMSET || op == MemOp::MEMCPY ||
         op == MemOp::MEMMOVE || op == MemOp::BZERO ||
         op == MemOp::STRCPY || op == MemOp::STRNCPY ||
         op == MemOp::STRCAT || op == MemOp::STRNCAT ||
         op == MemOp::STPCPY || op == MemOp::STPNCPY;
}

MX_EXPORT const char *EnumeratorName(MemOp op) noexcept;
MX_EXPORT const char *EnumeratorName(BitwiseOp op) noexcept;
MX_EXPORT const char *EnumeratorName(FloatOp op) noexcept;

// EnumerationName / NumEnumerators for sub-opcodes (needed by Python bindings).
inline static const char *EnumerationName(ConstOp) { return "ConstOp"; }
inline static constexpr unsigned NumEnumerators(ConstOp) { return 19u; }

inline static const char *EnumerationName(AllocaKind) { return "AllocaKind"; }
inline static constexpr unsigned NumEnumerators(AllocaKind) { return 4u; }

inline static const char *EnumerationName(CastOp) { return "CastOp"; }
inline static constexpr unsigned NumEnumerators(CastOp) { return 58u; }

inline static const char *EnumerationName(MemOp) { return "MemOp"; }
inline static constexpr unsigned NumEnumerators(MemOp) { return 78u; }

inline static const char *EnumerationName(BitwiseOp) { return "BitwiseOp"; }
inline static constexpr unsigned NumEnumerators(BitwiseOp) { return 10u; }

inline static const char *EnumerationName(FloatOp) { return "FloatOp"; }
inline static constexpr unsigned NumEnumerators(FloatOp) { return 82u; }

}  // namespace mx::ir
