// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/Interpret/ConcretePolicy.h>
#include <multiplier/IR/Interpret/ConcreteOps.h>
#include <multiplier/IR/InstructionKinds.h>

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <string>

namespace mx::ir::interpret {

// ===========================================================================
// Construction
// ===========================================================================

ConcretePolicy::ConcretePolicy(ConcreteMemory &memory,
                               FunctionResolver func_resolver,
                               GlobalResolver global_resolver)
    : memory_(memory),
      func_resolver_(std::move(func_resolver)),
      global_resolver_(std::move(global_resolver)) {}

// ===========================================================================
// Shared memory helpers — free functions usable by any policy.
// ===========================================================================

uint64_t concrete_extract_address(const Value &val) {
  if (auto *p = as_pointer(val)) {
    return concrete_address(*p);
  }
  if (auto *s = std::get_if<ScalarValue>(&val)) {
    return s->bits;
  }
  return 0;
}

bool concrete_has_address(const Value &val) {
  if (auto *p = as_pointer(val)) {
    return is_concrete(*p);
  }
  return std::holds_alternative<ScalarValue>(val);
}

void concrete_write_to_mem(ConcreteMemory &memory_, uint64_t address,
                           const Value &val, size_t size) {
  uint64_t bits = 0;
  size_t val_width = 8;
  if (auto *ptr = as_pointer(val)) {
    bits = concrete_address(*ptr);
  } else if (auto *s = std::get_if<ScalarValue>(&val)) {
    if (s->is_float && s->width == 8 && size <= 4) {
      // Narrow f64 → f32: the value holds double bits but the target slot
      // is 4 bytes (e.g. Python float stored to a float32 parameter).
      float f = static_cast<float>(s->as_f64());
      uint32_t fbits;
      std::memcpy(&fbits, &f, sizeof(fbits));
      bits = fbits;
      val_width = 4;
    } else {
      bits = s->bits;
      if (s->width > 0) val_width = s->width;
    }
  }
  // Pointer(0) and Undefined both write zero.
  size = std::min(size, val_width);
  memory_.write(address, &bits,
                static_cast<uint32_t>(std::min(size, sizeof(bits))));
}

Value concrete_read_from_mem(ConcreteMemory &memory_, uint64_t address,
                             size_t size, bool is_float) {
  uint64_t bits = 0;
  memory_.read(address, &bits,
               static_cast<uint32_t>(std::min(size, sizeof(bits))));
  if (is_float) {
    // Return raw bits with float tag — no interpretation.
    return (size <= 4) ? ScalarValue{bits & 0xFFFFFFFFu, 4, true}
                       : ScalarValue{bits, 8, true};
  }
  // Sign-extend for integer reads.
  int64_t v;
  std::memcpy(&v, &bits, sizeof(v));
  switch (size) {
    case 1: v = static_cast<int64_t>(static_cast<int8_t>(v)); break;
    case 2: v = static_cast<int64_t>(static_cast<int16_t>(v)); break;
    case 4: v = static_cast<int64_t>(static_cast<int32_t>(v)); break;
    default: break;
  }
  return make_int(v);
}

// ===========================================================================
// Free functions: stateless concrete value operations
// ===========================================================================

Value concrete_make_const(ConstOp op, int64_t signed_val,
                          uint64_t unsigned_val) {
  using enum ConstOp;
  switch (op) {
    case INT8:  return make_int(static_cast<int64_t>(static_cast<int8_t>(signed_val)), 1);
    case INT16: return make_int(static_cast<int64_t>(static_cast<int16_t>(signed_val)), 2);
    case INT32: return make_int(static_cast<int64_t>(static_cast<int32_t>(signed_val)), 4);
    case INT64: return make_int(signed_val, 8);
    case UINT8:  return ScalarValue::from_u64(unsigned_val & 0xFFu, 1);
    case UINT16: return ScalarValue::from_u64(unsigned_val & 0xFFFFu, 2);
    case UINT32: return ScalarValue::from_u64(unsigned_val & 0xFFFFFFFFu, 4);
    case UINT64: return ScalarValue::from_u64(unsigned_val, 8);
    case BOOL:   return ScalarValue::from_u64(unsigned_val ? 1u : 0u, 1);
    case WCHAR16: return ScalarValue::from_u64(unsigned_val & 0xFFFFu, 2);
    case WCHAR32: return ScalarValue::from_u64(unsigned_val & 0xFFFFFFFFu, 4);
    case NULL_PTR: return Pointer(0);
    case FLOAT16:
    case FLOAT32: {
      // The int pool stores float values as their double representation
      // in the signed_val field. Reinterpret and narrow.
      double d;
      std::memcpy(&d, &signed_val, sizeof(d));
      return make_float32(static_cast<float>(d));
    }
    case FLOAT64: {
      double d;
      std::memcpy(&d, &signed_val, sizeof(d));
      return make_float(d);
    }
    case INF32: return make_float32(std::numeric_limits<float>::infinity());
    case INF64: return make_float(std::numeric_limits<double>::infinity());
    case NAN32: return make_float32(std::numeric_limits<float>::quiet_NaN());
    case NAN64: return make_float(std::numeric_limits<double>::quiet_NaN());
  }
  return Undefined{};
}

Value concrete_binary_op(OpCode op, const Value &lhs, const Value &rhs) {
  using enum OpCode;

  if (op == LOGICAL_AND) return make_int(is_truthy(lhs) && is_truthy(rhs) ? 1 : 0);
  if (op == LOGICAL_OR) return make_int(is_truthy(lhs) || is_truthy(rhs) ? 1 : 0);

  // Float binary ops.
  if (IsFloatArithmetic(op)) {
    auto fn = [](double a, double b, OpCode o) -> double {
      switch (o) {
        case FADD_32: case FADD_64: return a + b;
        case FSUB_32: case FSUB_64: return a - b;
        case FMUL_32: case FMUL_64: return a * b;
        case FDIV_32: case FDIV_64: return a / b;
        case FREM_32: case FREM_64: return std::fmod(a, b);
        default: return 0.0;
      }
    };
    double result = fn(as_float(lhs), as_float(rhs), op);
    unsigned v = static_cast<unsigned>(op);
    bool is_f32 = (v % 2 == 1);  // odd = 32-bit
    return is_f32 ? make_float32(static_cast<float>(result))
                  : make_float(result);
  }

  // Integer binary ops: width encoded as op % 4.
  int64_t l = as_int(lhs);
  int64_t r = as_int(rhs);
  uint64_t ul = as_uint(lhs);
  uint64_t ur = as_uint(rhs);

  // Find the width index (0=8, 1=16, 2=32, 3=64).
  unsigned base;
  if (op >= SHR_8)        base = static_cast<unsigned>(SHR_8);
  else if (op >= SHL_8)   base = static_cast<unsigned>(SHL_8);
  else if (op >= BIT_XOR_8) base = static_cast<unsigned>(BIT_XOR_8);
  else if (op >= BIT_OR_8)  base = static_cast<unsigned>(BIT_OR_8);
  else if (op >= BIT_AND_8) base = static_cast<unsigned>(BIT_AND_8);
  else if (op >= USHR_8)  base = static_cast<unsigned>(USHR_8);
  else if (op >= UREM_8)  base = static_cast<unsigned>(UREM_8);
  else if (op >= UDIV_8)  base = static_cast<unsigned>(UDIV_8);
  else if (op >= REM_8)   base = static_cast<unsigned>(REM_8);
  else if (op >= DIV_8)   base = static_cast<unsigned>(DIV_8);
  else if (op >= MUL_8)   base = static_cast<unsigned>(MUL_8);
  else if (op >= SUB_8)   base = static_cast<unsigned>(SUB_8);
  else                    base = static_cast<unsigned>(ADD_8);

  unsigned wi = (static_cast<unsigned>(op) - base) & 3u;

  if (op >= ADD_8 && op <= ADD_64)
    return SignedIntBinOp(l, r, wi, [](auto a, auto b) { return a + b; });
  if (op >= SUB_8 && op <= SUB_64)
    return SignedIntBinOp(l, r, wi, [](auto a, auto b) { return a - b; });
  if (op >= MUL_8 && op <= MUL_64)
    return SignedIntBinOp(l, r, wi, [](auto a, auto b) { return a * b; });
  if (op >= DIV_8 && op <= DIV_64)
    return SignedIntBinOp(l, r, wi, [](auto a, auto b) { return b ? a / b : 0; });
  if (op >= REM_8 && op <= REM_64)
    return SignedIntBinOp(l, r, wi, [](auto a, auto b) { return b ? a % b : 0; });
  if (op >= UDIV_8 && op <= UDIV_64)
    return UnsignedIntBinOp(ul, ur, wi, [](auto a, auto b) { return b ? a / b : 0; });
  if (op >= UREM_8 && op <= UREM_64)
    return UnsignedIntBinOp(ul, ur, wi, [](auto a, auto b) { return b ? a % b : 0; });
  if (op >= USHR_8 && op <= USHR_64)
    return UnsignedIntBinOp(ul, ur, wi, [&](auto a, auto b) {
      return static_cast<decltype(a)>(a >> (b & ShiftMask(wi)));
    });
  if (op >= BIT_AND_8 && op <= BIT_AND_64)
    return UnsignedIntBinOp(ul, ur, wi, [](auto a, auto b) { return a & b; });
  if (op >= BIT_OR_8 && op <= BIT_OR_64)
    return UnsignedIntBinOp(ul, ur, wi, [](auto a, auto b) { return a | b; });
  if (op >= BIT_XOR_8 && op <= BIT_XOR_64)
    return UnsignedIntBinOp(ul, ur, wi, [](auto a, auto b) { return a ^ b; });
  if (op >= SHL_8 && op <= SHL_64)
    return UnsignedIntBinOp(ul, ur, wi, [&](auto a, auto b) {
      return static_cast<decltype(a)>(a << (b & ShiftMask(wi)));
    });
  if (op >= SHR_8 && op <= SHR_64)
    return SignedIntBinOp(l, r, wi, [&](auto a, auto b) {
      return static_cast<decltype(a)>(a >> (b & ShiftMask(wi)));
    });

  // Atomic ops used as RMW underlying ops.
  if (op >= ATOMIC_ADD_8 && op <= ATOMIC_ADD_64)
    return SignedIntBinOp(l, r, wi, [](auto a, auto b) { return a + b; });
  if (op >= ATOMIC_SUB_8 && op <= ATOMIC_SUB_64)
    return SignedIntBinOp(l, r, wi, [](auto a, auto b) { return a - b; });
  if (op >= ATOMIC_AND_8 && op <= ATOMIC_AND_64)
    return UnsignedIntBinOp(ul, ur, wi, [](auto a, auto b) { return a & b; });
  if (op >= ATOMIC_OR_8 && op <= ATOMIC_OR_64)
    return UnsignedIntBinOp(ul, ur, wi, [](auto a, auto b) { return a | b; });
  if (op >= ATOMIC_XOR_8 && op <= ATOMIC_XOR_64)
    return UnsignedIntBinOp(ul, ur, wi, [](auto a, auto b) { return a ^ b; });
  if (op >= ATOMIC_NAND_8 && op <= ATOMIC_NAND_64)
    return UnsignedIntBinOp(ul, ur, wi, [](auto a, auto b) { return ~(a & b); });

  return Undefined{};
}

Value concrete_unary_op(OpCode op, const Value &operand) {
  using enum OpCode;

  if (op == LOGICAL_NOT) return make_int(!is_truthy(operand) ? 1 : 0);

  if (op == FNEG_32) return make_float32(-as_float32(operand));
  if (op == FNEG_64) return make_float(-as_float(operand));

  int64_t v = as_int(operand);
  uint64_t uv = as_uint(operand);

  if (op >= NEG_8 && op <= NEG_64) {
    unsigned wi = static_cast<unsigned>(op) - static_cast<unsigned>(NEG_8);
    return SignedIntUnaryOp(v, wi, [](auto a) { return -a; });
  }
  if (op >= BIT_NOT_8 && op <= BIT_NOT_64) {
    unsigned wi = static_cast<unsigned>(op) - static_cast<unsigned>(BIT_NOT_8);
    return UnsignedIntUnaryOp(uv, wi, [](auto a) { return ~a; });
  }
  if (op >= ABS_8 && op <= ABS_64) {
    unsigned wi = static_cast<unsigned>(op) - static_cast<unsigned>(ABS_8);
    return SignedIntUnaryOp(v, wi, [](auto a) { return a < 0 ? -a : a; });
  }

  return Undefined{};
}

Value concrete_compare(OpCode op, const Value &lhs, const Value &rhs) {
  using enum OpCode;

  // Float comparisons.
  if (IsFloatComparison(op)) {
    double fl = as_float(lhs), fr = as_float(rhs);
    bool result = false;
    switch (op) {
      case FCMP_EQ_32: case FCMP_EQ_64: result = fl == fr; break;
      case FCMP_NE_32: case FCMP_NE_64: result = fl != fr; break;
      case FCMP_LT_32: case FCMP_LT_64: result = fl < fr; break;
      case FCMP_LE_32: case FCMP_LE_64: result = fl <= fr; break;
      case FCMP_GT_32: case FCMP_GT_64: result = fl > fr; break;
      case FCMP_GE_32: case FCMP_GE_64: result = fl >= fr; break;
      default: break;
    }
    return make_int(result ? 1 : 0);
  }

  // Pointer comparisons.
  auto *pl = as_pointer(lhs);
  auto *pr = as_pointer(rhs);
  if (pl || pr) {
    uint64_t la = pl ? concrete_address(*pl) : 0;
    uint64_t ra = pr ? concrete_address(*pr) : 0;
    // Null pointer (address 0) comparison.
    bool result = false;
    if (op >= CMP_EQ_8 && op <= CMP_EQ_64) result = la == ra;
    else if (op >= CMP_NE_8 && op <= CMP_NE_64) result = la != ra;
    else if (op >= CMP_LT_8 && op <= CMP_LT_64) result = static_cast<int64_t>(la) < static_cast<int64_t>(ra);
    else if (op >= CMP_LE_8 && op <= CMP_LE_64) result = static_cast<int64_t>(la) <= static_cast<int64_t>(ra);
    else if (op >= CMP_GT_8 && op <= CMP_GT_64) result = static_cast<int64_t>(la) > static_cast<int64_t>(ra);
    else if (op >= CMP_GE_8 && op <= CMP_GE_64) result = static_cast<int64_t>(la) >= static_cast<int64_t>(ra);
    else if (op >= UCMP_LT_8 && op <= UCMP_LT_64) result = la < ra;
    else if (op >= UCMP_LE_8 && op <= UCMP_LE_64) result = la <= ra;
    else if (op >= UCMP_GT_8 && op <= UCMP_GT_64) result = la > ra;
    else if (op >= UCMP_GE_8 && op <= UCMP_GE_64) result = la >= ra;
    return make_int(result ? 1 : 0);
  }

  int64_t l = as_int(lhs), r = as_int(rhs);
  uint64_t ul = as_uint(lhs), ur = as_uint(rhs);

  unsigned base;
  if (op >= UCMP_GE_8)      base = static_cast<unsigned>(UCMP_GE_8);
  else if (op >= UCMP_GT_8)  base = static_cast<unsigned>(UCMP_GT_8);
  else if (op >= UCMP_LE_8)  base = static_cast<unsigned>(UCMP_LE_8);
  else if (op >= UCMP_LT_8)  base = static_cast<unsigned>(UCMP_LT_8);
  else if (op >= CMP_GE_8)  base = static_cast<unsigned>(CMP_GE_8);
  else if (op >= CMP_GT_8)  base = static_cast<unsigned>(CMP_GT_8);
  else if (op >= CMP_LE_8)  base = static_cast<unsigned>(CMP_LE_8);
  else if (op >= CMP_LT_8)  base = static_cast<unsigned>(CMP_LT_8);
  else if (op >= CMP_NE_8)  base = static_cast<unsigned>(CMP_NE_8);
  else                       base = static_cast<unsigned>(CMP_EQ_8);

  unsigned wi = (static_cast<unsigned>(op) - base) & 3u;

  if (op >= CMP_EQ_8 && op <= CMP_EQ_64)
    return SignedIntBinOp(l, r, wi, [](auto a, auto b) -> decltype(a) { return a == b ? 1 : 0; });
  if (op >= CMP_NE_8 && op <= CMP_NE_64)
    return SignedIntBinOp(l, r, wi, [](auto a, auto b) -> decltype(a) { return a != b ? 1 : 0; });
  if (op >= CMP_LT_8 && op <= CMP_LT_64)
    return SignedIntBinOp(l, r, wi, [](auto a, auto b) -> decltype(a) { return a < b ? 1 : 0; });
  if (op >= CMP_LE_8 && op <= CMP_LE_64)
    return SignedIntBinOp(l, r, wi, [](auto a, auto b) -> decltype(a) { return a <= b ? 1 : 0; });
  if (op >= CMP_GT_8 && op <= CMP_GT_64)
    return SignedIntBinOp(l, r, wi, [](auto a, auto b) -> decltype(a) { return a > b ? 1 : 0; });
  if (op >= CMP_GE_8 && op <= CMP_GE_64)
    return SignedIntBinOp(l, r, wi, [](auto a, auto b) -> decltype(a) { return a >= b ? 1 : 0; });
  if (op >= UCMP_LT_8 && op <= UCMP_LT_64)
    return UnsignedIntBinOp(ul, ur, wi, [](auto a, auto b) -> decltype(a) { return a < b ? 1 : 0; });
  if (op >= UCMP_LE_8 && op <= UCMP_LE_64)
    return UnsignedIntBinOp(ul, ur, wi, [](auto a, auto b) -> decltype(a) { return a <= b ? 1 : 0; });
  if (op >= UCMP_GT_8 && op <= UCMP_GT_64)
    return UnsignedIntBinOp(ul, ur, wi, [](auto a, auto b) -> decltype(a) { return a > b ? 1 : 0; });
  if (op >= UCMP_GE_8 && op <= UCMP_GE_64)
    return UnsignedIntBinOp(ul, ur, wi, [](auto a, auto b) -> decltype(a) { return a >= b ? 1 : 0; });

  return make_int(0);
}

Value concrete_cast(CastOp op, const Value &operand) {
  // Pointer-related casts.
  if (auto *p = as_pointer(operand)) {
    if (IsPtrToInt(op)) return make_int(static_cast<int64_t>(concrete_address(*p)));
    return operand;  // ptr-to-ptr bitcasts.
  }

  if (IsIntToPtr(op)) {
    return make_ptr(static_cast<uint64_t>(as_int(operand)));
  }

  // Float-to-int.
  if (IsFloatToInt(op)) {
    double fv = as_float(operand);
    if (IsFloatToSigned(op)) return make_int(static_cast<int64_t>(fv));
    return make_int(static_cast<int64_t>(static_cast<uint64_t>(fv)));
  }

  // Int-to-float.
  if (IsIntToFloat(op)) {
    // Determine source width from the CastOp.
    unsigned src_bytes = 8;
    switch (op) {
      case CastOp::SI8_TO_F32: case CastOp::SI8_TO_F64:
      case CastOp::UI8_TO_F32: case CastOp::UI8_TO_F64:
        src_bytes = 1; break;
      case CastOp::SI16_TO_F32: case CastOp::SI16_TO_F64:
      case CastOp::UI16_TO_F32: case CastOp::UI16_TO_F64:
        src_bytes = 2; break;
      case CastOp::SI32_TO_F32: case CastOp::SI32_TO_F64:
      case CastOp::UI32_TO_F32: case CastOp::UI32_TO_F64:
        src_bytes = 4; break;
      default: src_bytes = 8; break;
    }

    if (IsSignedToFloat(op)) {
      int64_t sv = as_int(operand);
      switch (src_bytes) {
        case 1: sv = static_cast<int64_t>(static_cast<int8_t>(sv)); break;
        case 2: sv = static_cast<int64_t>(static_cast<int16_t>(sv)); break;
        case 4: sv = static_cast<int64_t>(static_cast<int32_t>(sv)); break;
        default: break;
      }
      double result = static_cast<double>(sv);
      return IsToFloat32(op) ? make_float32(static_cast<float>(result))
                             : make_float(result);
    }
    // Unsigned: mask to source width to undo sign-extension from memory.
    uint64_t uv = as_uint(operand);
    uint64_t mask = (src_bytes >= 8) ? ~uint64_t{0}
                                     : ((uint64_t{1} << (src_bytes * 8)) - 1);
    uv &= mask;
    double result = static_cast<double>(uv);
    return IsToFloat32(op) ? make_float32(static_cast<float>(result))
                           : make_float(result);
  }

  // Float widening/narrowing.
  if (op == CastOp::F64_TO_F32) return make_float32(static_cast<float>(as_float(operand)));
  if (op == CastOp::F32_TO_F64) return make_float(static_cast<double>(as_float32(operand)));

  // Integer sign/zero extend and truncate — delegate to width dispatch.
  int64_t v = as_int(operand);
  uint64_t uv = as_uint(operand);

  if (IsSignExtend(op)) {
    unsigned src_w = SignExtendSourceWidth(op);
    switch (src_w) {
      case 1: v = static_cast<int64_t>(static_cast<int8_t>(v)); break;
      case 2: v = static_cast<int64_t>(static_cast<int16_t>(v)); break;
      case 4: v = static_cast<int64_t>(static_cast<int32_t>(v)); break;
      default: break;
    }
    return make_int(v);
  }

  if (IsZeroExtend(op)) {
    unsigned src_w = ZeroExtendSourceWidth(op);
    uint64_t mask = (src_w >= 8) ? ~uint64_t{0} : ((uint64_t{1} << (src_w * 8)) - 1);
    return make_int(static_cast<int64_t>(uv & mask));
  }

  if (IsTruncate(op)) {
    unsigned dst_w = TruncateDestWidth(op);
    switch (dst_w) {
      case 1: return make_int(static_cast<int64_t>(static_cast<int8_t>(v)), 1);
      case 2: return make_int(static_cast<int64_t>(static_cast<int16_t>(v)), 2);
      case 4: return make_int(static_cast<int64_t>(static_cast<int32_t>(v)), 4);
      default: break;
    }
  }

  if (op == CastOp::IDENTITY) return operand;

  return operand;
}

Value concrete_ptr_add(const Value &base, const Value &index,
                       int64_t element_size) {
  auto *p = as_pointer(base);
  if (p && is_concrete(*p)) {
    return make_ptr(concrete_address(*p) +
                    static_cast<uint64_t>(as_int(index) * element_size));
  }
  if (is_null(base)) {
    return make_ptr(static_cast<uint64_t>(as_int(index) * element_size));
  }
  return Undefined{};
}

Value concrete_ptr_diff(const Value &lhs, const Value &rhs,
                        int64_t element_size) {
  auto *pl = as_pointer(lhs);
  auto *pr = as_pointer(rhs);
  uint64_t la = pl ? concrete_address(*pl) : static_cast<uint64_t>(as_int(lhs));
  uint64_t ra = pr ? concrete_address(*pr) : static_cast<uint64_t>(as_int(rhs));
  int64_t diff = static_cast<int64_t>(la) - static_cast<int64_t>(ra);
  if (element_size > 0) diff /= element_size;
  return make_int(diff);
}

Value concrete_ptr_offset(const Value &base, int64_t byte_offset) {
  auto *p = as_pointer(base);
  if (p && is_concrete(*p)) {
    return make_ptr(concrete_address(*p) + byte_offset);
  }
  return Undefined{};
}

Value concrete_select(const Value &cond, const Value &if_true,
                      const Value &if_false) {
  return is_truthy(cond) ? if_true : if_false;
}

Value concrete_bitwise_intrinsic(OpCode width_op, BitwiseOp sub,
                                 const Value &val_in, const Value &val2) {
  using enum BitwiseOp;
  using enum OpCode;

  uint64_t v = as_uint(val_in);
  uint64_t v2 = as_uint(val2);

  unsigned width_bits;
  switch (width_op) {
    case BITWISE_8:  width_bits = 8; break;
    case BITWISE_16: width_bits = 16; break;
    case BITWISE_32: width_bits = 32; break;
    case BITWISE_64: width_bits = 64; break;
    default: return make_undef();
  }

  switch (sub) {
    case BSWAP_16:
      return make_int(static_cast<int64_t>(__builtin_bswap16(
          static_cast<uint16_t>(v))));
    case BSWAP_32:
      return make_int(static_cast<int64_t>(__builtin_bswap32(
          static_cast<uint32_t>(v))));
    case BSWAP_64:
      return make_int(static_cast<int64_t>(__builtin_bswap64(v)));

    case POPCOUNT:
      if (width_bits <= 32)
        return make_int(static_cast<int64_t>(
            __builtin_popcount(static_cast<unsigned>(
                static_cast<uint32_t>(v)))));
      return make_int(static_cast<int64_t>(
          __builtin_popcountll(static_cast<unsigned long long>(v))));

    case CLZ:
      switch (width_bits) {
        case 8:
          return make_int(static_cast<int64_t>(
              __builtin_clz(static_cast<unsigned>(
                  static_cast<uint8_t>(v))) - 24));
        case 16:
          return make_int(static_cast<int64_t>(
              __builtin_clz(static_cast<unsigned>(
                  static_cast<uint16_t>(v))) - 16));
        case 32:
          return make_int(static_cast<int64_t>(
              __builtin_clz(static_cast<unsigned>(
                  static_cast<uint32_t>(v)))));
        case 64:
          return make_int(static_cast<int64_t>(
              __builtin_clzll(static_cast<unsigned long long>(v))));
        default: break;
      }
      break;

    case CTZ:
      if (width_bits <= 32)
        return make_int(static_cast<int64_t>(
            __builtin_ctz(static_cast<unsigned>(
                static_cast<uint32_t>(v)))));
      return make_int(static_cast<int64_t>(
          __builtin_ctzll(static_cast<unsigned long long>(v))));

    case FFS:
      if (width_bits <= 32)
        return make_int(static_cast<int64_t>(
            __builtin_ffs(static_cast<int>(static_cast<int32_t>(v)))));
      return make_int(static_cast<int64_t>(
          __builtin_ffsll(static_cast<long long>(
              static_cast<int64_t>(v)))));

    case PARITY:
      if (width_bits <= 32)
        return make_int(static_cast<int64_t>(
            __builtin_parity(static_cast<unsigned>(
                static_cast<uint32_t>(v)))));
      return make_int(static_cast<int64_t>(
          __builtin_parityll(static_cast<unsigned long long>(v))));

    case ROTL: {
      unsigned amt = static_cast<unsigned>(v2) % width_bits;
      if (amt == 0) return make_int(static_cast<int64_t>(v));
      switch (width_bits) {
        case 8: {
          auto x = static_cast<uint8_t>(v);
          return make_int(static_cast<int64_t>(
              static_cast<uint8_t>((x << amt) | (x >> (8 - amt)))));
        }
        case 16: {
          auto x = static_cast<uint16_t>(v);
          return make_int(static_cast<int64_t>(
              static_cast<uint16_t>((x << amt) | (x >> (16 - amt)))));
        }
        case 32: {
          auto x = static_cast<uint32_t>(v);
          return make_int(static_cast<int64_t>((x << amt) | (x >> (32 - amt))));
        }
        case 64:
          return make_int(static_cast<int64_t>(
              (v << amt) | (v >> (64 - amt))));
        default: break;
      }
      break;
    }

    case ROTR: {
      unsigned amt = static_cast<unsigned>(v2) % width_bits;
      if (amt == 0) return make_int(static_cast<int64_t>(v));
      switch (width_bits) {
        case 8: {
          auto x = static_cast<uint8_t>(v);
          return make_int(static_cast<int64_t>(
              static_cast<uint8_t>((x >> amt) | (x << (8 - amt)))));
        }
        case 16: {
          auto x = static_cast<uint16_t>(v);
          return make_int(static_cast<int64_t>(
              static_cast<uint16_t>((x >> amt) | (x << (16 - amt)))));
        }
        case 32: {
          auto x = static_cast<uint32_t>(v);
          return make_int(static_cast<int64_t>((x >> amt) | (x << (32 - amt))));
        }
        case 64:
          return make_int(static_cast<int64_t>(
              (v >> amt) | (v << (64 - amt))));
        default: break;
      }
      break;
    }
  }

  return make_undef();
}

Value concrete_float_intrinsic(FloatOp sub,
                               const std::vector<Value> &operands) {
  using enum FloatOp;

  auto d = [&](size_t i) -> double {
    return i < operands.size() ? as_float(operands[i]) : 0.0;
  };
  auto f = [&](size_t i) -> float {
    return i < operands.size() ? as_float32(operands[i]) : 0.0f;
  };

  switch (sub) {
    case ISNAN_32:    return make_int(std::isnan(f(0)) ? 1 : 0);
    case ISNAN_64:    return make_int(std::isnan(d(0)) ? 1 : 0);
    case ISINF_32:    return make_int(std::isinf(f(0)) ? 1 : 0);
    case ISINF_64:    return make_int(std::isinf(d(0)) ? 1 : 0);
    case ISFINITE_32: return make_int(std::isfinite(f(0)) ? 1 : 0);
    case ISFINITE_64: return make_int(std::isfinite(d(0)) ? 1 : 0);
    case SIGNBIT_32:  return make_int(std::signbit(f(0)) ? 1 : 0);
    case SIGNBIT_64:  return make_int(std::signbit(d(0)) ? 1 : 0);
    case INF_32:  return make_float32(std::numeric_limits<float>::infinity());
    case INF_64:  return make_float(std::numeric_limits<double>::infinity());
    case NAN_32:  return make_float32(std::numeric_limits<float>::quiet_NaN());
    case NAN_64:  return make_float(std::numeric_limits<double>::quiet_NaN());
    case HUGE_32: return make_float32(HUGE_VALF);
    case HUGE_64: return make_float(HUGE_VAL);
    case FABS_32:      return make_float32(std::fabs(f(0)));
    case FABS_64:      return make_float(std::fabs(d(0)));
    case CEIL_32:      return make_float32(std::ceil(f(0)));
    case CEIL_64:      return make_float(std::ceil(d(0)));
    case FLOOR_32:     return make_float32(std::floor(f(0)));
    case FLOOR_64:     return make_float(std::floor(d(0)));
    case ROUND_32:     return make_float32(std::round(f(0)));
    case ROUND_64:     return make_float(std::round(d(0)));
    case TRUNC_32:     return make_float32(std::trunc(f(0)));
    case TRUNC_64:     return make_float(std::trunc(d(0)));
    case SQRT_32:      return make_float32(std::sqrt(f(0)));
    case SQRT_64:      return make_float(std::sqrt(d(0)));
    case SIN_32:       return make_float32(std::sin(f(0)));
    case SIN_64:       return make_float(std::sin(d(0)));
    case COS_32:       return make_float32(std::cos(f(0)));
    case COS_64:       return make_float(std::cos(d(0)));
    case TAN_32:       return make_float32(std::tan(f(0)));
    case TAN_64:       return make_float(std::tan(d(0)));
    case ASIN_32:      return make_float32(std::asin(f(0)));
    case ASIN_64:      return make_float(std::asin(d(0)));
    case ACOS_32:      return make_float32(std::acos(f(0)));
    case ACOS_64:      return make_float(std::acos(d(0)));
    case ATAN_32:      return make_float32(std::atan(f(0)));
    case ATAN_64:      return make_float(std::atan(d(0)));
    case EXP_32:       return make_float32(std::exp(f(0)));
    case EXP_64:       return make_float(std::exp(d(0)));
    case EXP2_32:      return make_float32(std::exp2(f(0)));
    case EXP2_64:      return make_float(std::exp2(d(0)));
    case LOG_32:       return make_float32(std::log(f(0)));
    case LOG_64:       return make_float(std::log(d(0)));
    case LOG2_32:      return make_float32(std::log2(f(0)));
    case LOG2_64:      return make_float(std::log2(d(0)));
    case LOG10_32:     return make_float32(std::log10(f(0)));
    case LOG10_64:     return make_float(std::log10(d(0)));
    case SINH_32:      return make_float32(std::sinh(f(0)));
    case SINH_64:      return make_float(std::sinh(d(0)));
    case COSH_32:      return make_float32(std::cosh(f(0)));
    case COSH_64:      return make_float(std::cosh(d(0)));
    case TANH_32:      return make_float32(std::tanh(f(0)));
    case TANH_64:      return make_float(std::tanh(d(0)));
    case ERF_32:       return make_float32(std::erf(f(0)));
    case ERF_64:       return make_float(std::erf(d(0)));
    case ERFC_32:      return make_float32(std::erfc(f(0)));
    case ERFC_64:      return make_float(std::erfc(d(0)));
    case TGAMMA_32:    return make_float32(std::tgamma(f(0)));
    case TGAMMA_64:    return make_float(std::tgamma(d(0)));
    case LGAMMA_32:    return make_float32(std::lgamma(f(0)));
    case LGAMMA_64:    return make_float(std::lgamma(d(0)));
    case COPYSIGN_32:  return make_float32(std::copysign(f(0), f(1)));
    case COPYSIGN_64:  return make_float(std::copysign(d(0), d(1)));
    case FMIN_32:      return make_float32(std::fmin(f(0), f(1)));
    case FMIN_64:      return make_float(std::fmin(d(0), d(1)));
    case FMAX_32:      return make_float32(std::fmax(f(0), f(1)));
    case FMAX_64:      return make_float(std::fmax(d(0), d(1)));
    case ATAN2_32:     return make_float32(std::atan2(f(0), f(1)));
    case ATAN2_64:     return make_float(std::atan2(d(0), d(1)));
    case POW_32:       return make_float32(std::pow(f(0), f(1)));
    case POW_64:       return make_float(std::pow(d(0), d(1)));
    case FMOD_32:      return make_float32(std::fmod(f(0), f(1)));
    case FMOD_64:      return make_float(std::fmod(d(0), d(1)));
    case REMAINDER_32: return make_float32(std::remainder(f(0), f(1)));
    case REMAINDER_64: return make_float(std::remainder(d(0), d(1)));
    case HYPOT_32:     return make_float32(std::hypot(f(0), f(1)));
    case HYPOT_64:     return make_float(std::hypot(d(0), d(1)));
    case FDIM_32:      return make_float32(std::fdim(f(0), f(1)));
    case FDIM_64:      return make_float(std::fdim(d(0), d(1)));
    case FMA_32:       return make_float32(std::fma(f(0), f(1), f(2)));
    case FMA_64:       return make_float(std::fma(d(0), d(1), d(2)));
  }

  return make_undef();
}

std::optional<bool> concrete_is_true(const Value &val) {
  return is_truthy(val);
}

// ===========================================================================
// ConcretePolicy — value extraction / construction (interpreter bookkeeping)
// ===========================================================================

std::optional<uint64_t> ConcretePolicy::extract_address(const Value &val) {
  if (auto *p = as_pointer(val)) return concrete_address(*p);
  return std::nullopt;
}

int64_t ConcretePolicy::extract_int(const Value &val) { return as_int(val); }

uint64_t ConcretePolicy::extract_uint(const Value &val) { return as_uint(val); }

Value ConcretePolicy::make_literal_int(int64_t v, uint8_t w) {
  return make_int(v, w);
}

Value ConcretePolicy::make_literal_ptr(uint64_t a) { return make_ptr(a); }

Value ConcretePolicy::make_default() { return Undefined{}; }

bool ConcretePolicy::has_address(const Value &val) {
  return concrete_has_address(val);
}

// ===========================================================================
// ConcretePolicy thin wrappers — delegate to free functions above
// ===========================================================================

Value ConcretePolicy::make_const(ConstOp op, int64_t signed_val,
                                 uint64_t unsigned_val) {
  return concrete_make_const(op, signed_val, unsigned_val);
}

Value ConcretePolicy::make_null_ptr(void) { return Pointer(0); }

Value ConcretePolicy::binary_op(OpCode op, const Value &lhs,
                                const Value &rhs) {
  return concrete_binary_op(op, lhs, rhs);
}

Value ConcretePolicy::unary_op(OpCode op, const Value &operand) {
  return concrete_unary_op(op, operand);
}

Value ConcretePolicy::compare(OpCode op, const Value &lhs,
                              const Value &rhs) {
  return concrete_compare(op, lhs, rhs);
}

Value ConcretePolicy::cast(CastOp op, const Value &operand) {
  return concrete_cast(op, operand);
}

Value ConcretePolicy::ptr_add(const Value &base, const Value &index,
                              int64_t element_size) {
  return concrete_ptr_add(base, index, element_size);
}

Value ConcretePolicy::ptr_diff(const Value &lhs, const Value &rhs,
                               int64_t element_size) {
  return concrete_ptr_diff(lhs, rhs, element_size);
}

Value ConcretePolicy::ptr_offset(const Value &base, int64_t byte_offset) {
  return concrete_ptr_offset(base, byte_offset);
}

Value ConcretePolicy::select(const Value &cond, const Value &if_true,
                             const Value &if_false) {
  return concrete_select(cond, if_true, if_false);
}

Value ConcretePolicy::bitwise_intrinsic(OpCode width_op, BitwiseOp sub,
                                        const Value &val,
                                        const Value &val2) {
  return concrete_bitwise_intrinsic(width_op, sub, val, val2);
}

Value ConcretePolicy::float_intrinsic(FloatOp sub,
                                      const std::vector<Value> &operands) {
  return concrete_float_intrinsic(sub, operands);
}

std::optional<bool> ConcretePolicy::is_true(const Value &val) {
  return concrete_is_true(val);
}

// ===========================================================================
// 4. Memory
// ===========================================================================

Value ConcretePolicy::mem_allocate(NoOpScheduler &, uint64_t size_bytes,
                                   uint64_t align_bytes) {
  return make_ptr(memory_.allocate(size_bytes, align_bytes));
}

void ConcretePolicy::mem_free(NoOpScheduler &, const Value &address) {
  if (concrete_has_address(address)) {
    memory_.free(concrete_extract_address(address));
  }
}

bool ConcretePolicy::mem_read(NoOpScheduler &, const Value &addr,
                              const MemAccessHint &hint, Value &result) {
  if (!concrete_has_address(addr)) {
    result = Undefined{};
    return true;  // not dead, just couldn't read
  }
  result = concrete_read_from_mem(memory_, concrete_extract_address(addr),
                                  hint.size_bytes, hint.is_float);
  return true;
}

bool ConcretePolicy::mem_write(NoOpScheduler &, const Value &addr,
                               const Value &val,
                               const MemAccessHint &hint) {
  if (!concrete_has_address(addr)) return true;
  concrete_write_to_mem(memory_, concrete_extract_address(addr), val,
                        hint.size_bytes);
  return true;
}

bool concrete_mem_bulk_op(ConcreteMemory &memory_, MemOp sub,
                          const std::vector<Value> &ops,
                          const MemoryInst &mi, Value &result) {
  result = make_undef();
  using MO = ir::MemOp;

  switch (sub) {
    case MO::MEMSET: {
      if (ops.size() >= 3) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p) && as_int(ops[2]) > 0) {
          memory_.memset(concrete_address(*p),
                         static_cast<uint8_t>(as_int(ops[1])),
                         static_cast<uint32_t>(as_int(ops[2])));
        }
      }
      result = ops.empty() ? make_undef() : ops[0];
      break;
    }
    case MO::MEMCPY:
    case MO::MEMMOVE: {
      if (ops.size() >= 3) {
        auto *dp = as_pointer(ops[0]);
        int64_t len = as_int(ops[2]);
        if (dp && is_concrete(*dp) && len > 0) {
          auto *sp = as_pointer(ops[1]);
          if (sp && is_concrete(*sp)) {
            memory_.memcpy(concrete_address(*dp), concrete_address(*sp),
                           static_cast<uint32_t>(len));
          } else if (auto *sv = std::get_if<ScalarValue>(&ops[1])) {
            memory_.write(concrete_address(*dp), &sv->bits,
                          static_cast<uint32_t>(
                              std::min(static_cast<size_t>(len),
                                       sizeof(sv->bits))));
          }
        }
      }
      result = ops.empty() ? make_undef() : ops[0];
      break;
    }
    case MO::BZERO: {
      if (ops.size() >= 2) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p) && as_int(ops[1]) > 0) {
          memory_.memset(concrete_address(*p), 0,
                         static_cast<uint32_t>(as_int(ops[1])));
        }
      }
      result = ops.empty() ? make_undef() : ops[0];
      break;
    }
    case MO::STRLEN: {
      if (ops.size() >= 1) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p)) {
          uint64_t addr = concrete_address(*p);
          size_t len = 0;
          uint8_t byte = 0;
          while (true) {
            memory_.read(addr + len, &byte, 1);
            if (byte == 0) break;
            ++len;
          }
          result = make_int(static_cast<int64_t>(len));
        }
      }
      break;
    }
    case MO::STRNLEN: {
      if (ops.size() >= 2) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p)) {
          uint64_t addr = concrete_address(*p);
          size_t maxlen = static_cast<size_t>(as_int(ops[1]));
          size_t len = 0;
          uint8_t byte = 0;
          while (len < maxlen) {
            memory_.read(addr + len, &byte, 1);
            if (byte == 0) break;
            ++len;
          }
          result = make_int(static_cast<int64_t>(len));
        }
      }
      break;
    }
    case MO::STRCMP: {
      if (ops.size() >= 2) {
        auto *p0 = as_pointer(ops[0]);
        auto *p1 = as_pointer(ops[1]);
        if (p0 && p1 && is_concrete(*p0) && is_concrete(*p1)) {
          uint64_t a0 = concrete_address(*p0);
          uint64_t a1 = concrete_address(*p1);
          int cmp = 0;
          for (size_t i = 0; ; ++i) {
            uint8_t c0 = 0, c1 = 0;
            memory_.read(a0 + i, &c0, 1);
            memory_.read(a1 + i, &c1, 1);
            if (c0 != c1) { cmp = (c0 < c1) ? -1 : 1; break; }
            if (c0 == 0) break;
          }
          result = make_int(cmp);
        }
      }
      break;
    }
    case MO::STRNCMP: {
      if (ops.size() >= 3) {
        auto *p0 = as_pointer(ops[0]);
        auto *p1 = as_pointer(ops[1]);
        if (p0 && p1 && is_concrete(*p0) && is_concrete(*p1)) {
          uint64_t a0 = concrete_address(*p0);
          uint64_t a1 = concrete_address(*p1);
          size_t n = static_cast<size_t>(as_int(ops[2]));
          int cmp = 0;
          for (size_t i = 0; i < n; ++i) {
            uint8_t c0 = 0, c1 = 0;
            memory_.read(a0 + i, &c0, 1);
            memory_.read(a1 + i, &c1, 1);
            if (c0 != c1) { cmp = (c0 < c1) ? -1 : 1; break; }
            if (c0 == 0) break;
          }
          result = make_int(cmp);
        }
      }
      break;
    }
    case MO::MEMCMP: {
      if (ops.size() >= 3) {
        auto *p0 = as_pointer(ops[0]);
        auto *p1 = as_pointer(ops[1]);
        if (p0 && p1 && is_concrete(*p0) && is_concrete(*p1)) {
          size_t len = static_cast<size_t>(as_int(ops[2]));
          std::vector<uint8_t> buf0(len, 0), buf1(len, 0);
          memory_.read(concrete_address(*p0), buf0.data(),
                       static_cast<uint32_t>(len));
          memory_.read(concrete_address(*p1), buf1.data(),
                       static_cast<uint32_t>(len));
          result = make_int(std::memcmp(buf0.data(), buf1.data(), len));
        }
      }
      break;
    }
    case MO::MEMCHR: {
      if (ops.size() >= 3) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p)) {
          uint64_t addr = concrete_address(*p);
          size_t len = static_cast<size_t>(as_int(ops[2]));
          uint8_t needle = static_cast<uint8_t>(as_int(ops[1]));
          for (size_t i = 0; i < len; ++i) {
            uint8_t byte = 0;
            memory_.read(addr + i, &byte, 1);
            if (byte == needle) {
              result = make_ptr(addr + i);
              break;
            }
          }
        }
      }
      break;
    }
    case MO::STRCHR: {
      if (ops.size() >= 2) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p)) {
          uint64_t addr = concrete_address(*p);
          uint8_t needle = static_cast<uint8_t>(as_int(ops[1]));
          bool found = false;
          for (size_t i = 0; ; ++i) {
            uint8_t byte = 0;
            memory_.read(addr + i, &byte, 1);
            if (byte == needle) {
              result = make_ptr(addr + i);
              found = true;
              break;
            }
            if (byte == 0) break;
          }
          if (!found) {
            if (needle == 0) {
              for (size_t i = 0; ; ++i) {
                uint8_t byte = 0;
                memory_.read(addr + i, &byte, 1);
                if (byte == 0) {
                  result = make_ptr(addr + i);
                  found = true;
                  break;
                }
              }
            }
            if (!found) result = make_null();
          }
        }
      }
      break;
    }
    case MO::STRRCHR: {
      if (ops.size() >= 2) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p)) {
          uint64_t addr = concrete_address(*p);
          uint8_t needle = static_cast<uint8_t>(as_int(ops[1]));
          int64_t last_pos = -1;
          for (size_t i = 0; ; ++i) {
            uint8_t byte = 0;
            memory_.read(addr + i, &byte, 1);
            if (byte == needle) last_pos = static_cast<int64_t>(i);
            if (byte == 0) break;
          }
          result = (last_pos >= 0)
              ? make_ptr(addr + static_cast<uint64_t>(last_pos))
              : make_null();
        }
      }
      break;
    }
    case MO::STRSTR: {
      if (ops.size() >= 2) {
        auto *p0 = as_pointer(ops[0]);
        auto *p1 = as_pointer(ops[1]);
        if (p0 && p1 && is_concrete(*p0) && is_concrete(*p1)) {
          uint64_t ha = concrete_address(*p0);
          uint64_t na = concrete_address(*p1);
          std::string haystack, needle_str;
          for (size_t i = 0; ; ++i) {
            uint8_t b = 0; memory_.read(ha + i, &b, 1);
            if (b == 0) break;
            haystack.push_back(static_cast<char>(b));
          }
          for (size_t i = 0; ; ++i) {
            uint8_t b = 0; memory_.read(na + i, &b, 1);
            if (b == 0) break;
            needle_str.push_back(static_cast<char>(b));
          }
          if (needle_str.empty()) {
            result = ops[0];
          } else {
            auto pos = haystack.find(needle_str);
            result = (pos != std::string::npos)
                ? make_ptr(ha + pos) : make_null();
          }
        }
      }
      break;
    }
    case MO::STRCPY: {
      if (ops.size() >= 2) {
        auto *dp = as_pointer(ops[0]);
        auto *sp = as_pointer(ops[1]);
        if (dp && sp && is_concrete(*dp) && is_concrete(*sp)) {
          uint64_t da = concrete_address(*dp), sa = concrete_address(*sp);
          for (size_t i = 0; ; ++i) {
            uint8_t c = 0; memory_.read(sa + i, &c, 1);
            memory_.write(da + i, &c, 1);
            if (c == 0) break;
          }
        }
      }
      result = ops.empty() ? make_undef() : ops[0];
      break;
    }
    case MO::STRNCPY: {
      if (ops.size() >= 3) {
        auto *dp = as_pointer(ops[0]);
        auto *sp = as_pointer(ops[1]);
        if (dp && sp && is_concrete(*dp) && is_concrete(*sp)) {
          uint64_t da = concrete_address(*dp), sa = concrete_address(*sp);
          size_t n = static_cast<size_t>(as_int(ops[2]));
          bool hit_null = false;
          for (size_t i = 0; i < n; ++i) {
            uint8_t c = 0;
            if (!hit_null) { memory_.read(sa + i, &c, 1); if (c == 0) hit_null = true; }
            memory_.write(da + i, &c, 1);
          }
        }
      }
      result = ops.empty() ? make_undef() : ops[0];
      break;
    }
    case MO::STRCAT: {
      if (ops.size() >= 2) {
        auto *dp = as_pointer(ops[0]);
        auto *sp = as_pointer(ops[1]);
        if (dp && sp && is_concrete(*dp) && is_concrete(*sp)) {
          uint64_t da = concrete_address(*dp), sa = concrete_address(*sp);
          size_t dlen = 0;
          uint8_t byte = 0;
          while (true) { memory_.read(da + dlen, &byte, 1); if (byte == 0) break; ++dlen; }
          for (size_t i = 0; ; ++i) {
            uint8_t c = 0; memory_.read(sa + i, &c, 1);
            memory_.write(da + dlen + i, &c, 1);
            if (c == 0) break;
          }
        }
      }
      result = ops.empty() ? make_undef() : ops[0];
      break;
    }
    case MO::STRNCAT: {
      if (ops.size() >= 3) {
        auto *dp = as_pointer(ops[0]);
        auto *sp = as_pointer(ops[1]);
        if (dp && sp && is_concrete(*dp) && is_concrete(*sp)) {
          uint64_t da = concrete_address(*dp), sa = concrete_address(*sp);
          size_t n = static_cast<size_t>(as_int(ops[2]));
          size_t dlen = 0;
          uint8_t byte = 0;
          while (true) { memory_.read(da + dlen, &byte, 1); if (byte == 0) break; ++dlen; }
          size_t i = 0;
          for (; i < n; ++i) {
            uint8_t c = 0; memory_.read(sa + i, &c, 1);
            if (c == 0) break;
            memory_.write(da + dlen + i, &c, 1);
          }
          uint8_t nul = 0; memory_.write(da + dlen + i, &nul, 1);
        }
      }
      result = ops.empty() ? make_undef() : ops[0];
      break;
    }
    case MO::STPCPY: {
      if (ops.size() >= 2) {
        auto *dp = as_pointer(ops[0]);
        auto *sp = as_pointer(ops[1]);
        if (dp && sp && is_concrete(*dp) && is_concrete(*sp)) {
          uint64_t da = concrete_address(*dp), sa = concrete_address(*sp);
          size_t i = 0;
          for (; ; ++i) {
            uint8_t c = 0; memory_.read(sa + i, &c, 1);
            memory_.write(da + i, &c, 1);
            if (c == 0) break;
          }
          result = make_ptr(da + i);
        }
      }
      break;
    }
    case MO::STPNCPY: {
      if (ops.size() >= 3) {
        auto *dp = as_pointer(ops[0]);
        auto *sp = as_pointer(ops[1]);
        if (dp && sp && is_concrete(*dp) && is_concrete(*sp)) {
          uint64_t da = concrete_address(*dp), sa = concrete_address(*sp);
          size_t n = static_cast<size_t>(as_int(ops[2]));
          bool hit_null = false;
          size_t null_pos = n;
          for (size_t i = 0; i < n; ++i) {
            uint8_t c = 0;
            if (!hit_null) { memory_.read(sa + i, &c, 1); if (c == 0) { hit_null = true; null_pos = i; } }
            memory_.write(da + i, &c, 1);
          }
          result = make_ptr(da + null_pos);
        }
      }
      break;
    }
    case MO::STRTOI32: case MO::STRTOI64:
    case MO::STRTOU32: case MO::STRTOU64:
    case MO::STRTOF32: case MO::STRTOF64: {
      if (ops.size() >= 1) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p)) {
          uint64_t addr = concrete_address(*p);
          std::string str;
          for (size_t i = 0; ; ++i) {
            uint8_t b = 0; memory_.read(addr + i, &b, 1);
            if (b == 0) break;
            str.push_back(static_cast<char>(b));
          }
          switch (sub) {
            case MO::STRTOI32: result = make_int(static_cast<int64_t>(std::strtol(str.c_str(), nullptr, 10))); break;
            case MO::STRTOI64: result = make_int(static_cast<int64_t>(std::strtoll(str.c_str(), nullptr, 10))); break;
            case MO::STRTOU32: result = make_int(static_cast<int64_t>(std::strtoul(str.c_str(), nullptr, 10))); break;
            case MO::STRTOU64: result = make_int(static_cast<int64_t>(std::strtoull(str.c_str(), nullptr, 10))); break;
            case MO::STRTOF32: result = make_float(static_cast<double>(std::strtof(str.c_str(), nullptr))); break;
            case MO::STRTOF64: result = make_float(std::strtod(str.c_str(), nullptr)); break;
            default: break;
          }
        }
      }
      break;
    }
    case MO::BIT_READ_LE: case MO::BIT_READ_BE: {
      if (ops.size() >= 1) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p)) {
          uint64_t addr = concrete_address(*p);
          uint32_t bo = mi.bit_offset();
          uint32_t bw = mi.bit_width();
          uint32_t first_byte = bo / 8;
          uint32_t last_byte = (bo + bw - 1) / 8;
          uint32_t num_bytes = last_byte - first_byte + 1;
          std::vector<uint8_t> buf(num_bytes, 0);
          memory_.read(addr + first_byte, buf.data(), num_bytes);
          uint64_t raw = 0;
          if (sub == MO::BIT_READ_LE) {
            for (uint32_t i = 0; i < num_bytes; ++i)
              raw |= static_cast<uint64_t>(buf[i]) << (i * 8);
            raw >>= (bo % 8);
          } else {
            for (uint32_t i = 0; i < num_bytes; ++i)
              raw = (raw << 8) | buf[i];
            uint32_t top_bits = num_bytes * 8;
            uint32_t shift = top_bits - (bo % 8) - bw;
            raw >>= shift;
          }
          uint64_t mask = (bw >= 64) ? ~uint64_t{0} : ((uint64_t{1} << bw) - 1);
          raw &= mask;
          result = make_int(static_cast<int64_t>(raw));
        }
      }
      break;
    }
    case MO::BIT_WRITE_LE: case MO::BIT_WRITE_BE: {
      if (ops.size() >= 2) {
        auto *p = as_pointer(ops[0]);
        if (p && is_concrete(*p)) {
          uint64_t addr = concrete_address(*p);
          uint32_t bo = mi.bit_offset();
          uint32_t bw = mi.bit_width();
          uint64_t val = static_cast<uint64_t>(as_int(ops[1]));
          uint64_t mask = (bw >= 64) ? ~uint64_t{0} : ((uint64_t{1} << bw) - 1);
          val &= mask;
          uint32_t first_byte = bo / 8;
          uint32_t last_byte = (bo + bw - 1) / 8;
          uint32_t num_bytes = last_byte - first_byte + 1;
          std::vector<uint8_t> buf(num_bytes, 0);
          memory_.read(addr + first_byte, buf.data(), num_bytes);
          if (sub == MO::BIT_WRITE_LE) {
            uint64_t raw = 0;
            for (uint32_t i = 0; i < num_bytes; ++i)
              raw |= static_cast<uint64_t>(buf[i]) << (i * 8);
            uint32_t shift = bo % 8;
            raw &= ~(mask << shift);
            raw |= (val << shift);
            for (uint32_t i = 0; i < num_bytes; ++i)
              buf[i] = static_cast<uint8_t>(raw >> (i * 8));
          } else {
            uint64_t raw = 0;
            for (uint32_t i = 0; i < num_bytes; ++i)
              raw = (raw << 8) | buf[i];
            uint32_t top_bits = num_bytes * 8;
            uint32_t shift = top_bits - (bo % 8) - bw;
            raw &= ~(mask << shift);
            raw |= (val << shift);
            for (uint32_t i = 0; i < num_bytes; ++i)
              buf[num_bytes - 1 - i] = static_cast<uint8_t>(raw >> (i * 8));
          }
          memory_.write(addr + first_byte, buf.data(), num_bytes);
        }
      }
      break;
    }
    case MO::CONSUME_VA_PARAM:
      break;
    default:
      if (ir::IsCmpxchg(sub)) {
        result = make_undef();
      }
      break;
  }
  return true;
}

bool ConcretePolicy::mem_bulk_op(NoOpScheduler &, MemOp sub,
                                 const std::vector<Value> &ops,
                                 const MemoryInst &mi, Value &result) {
  return concrete_mem_bulk_op(memory_, sub, ops, mi, result);
}

void ConcretePolicy::mem_poison(const Value &addr) {
  if (concrete_has_address(addr)) {
    memory_.poison(concrete_extract_address(addr));
  }
}

void ConcretePolicy::mem_unpoison(const Value &addr) {
  if (concrete_has_address(addr)) {
    memory_.unpoison(concrete_extract_address(addr));
  }
}

bool ConcretePolicy::is_undefined(const Value &val) {
  return std::holds_alternative<Undefined>(val);
}

// ===========================================================================
// 5. Resolution
// ===========================================================================

bool ConcretePolicy::resolve_branch(NoOpScheduler &,
                                    const Value &condition,
                                    IRBlock true_block,
                                    IRBlock false_block,
                                    IRBlock &chosen_block) {
  // Concrete: always take the true path (condition was already checked
  // via is_true which returned a concrete bool, so this shouldn't
  // normally be called for concrete execution).
  chosen_block = true_block;
  return true;
}

bool ConcretePolicy::resolve_call(NoOpScheduler &,
                                  const IRInstruction &,
                                  RawEntityId target_eid,
                                  RawEntityId indirect_target_eid,
                                  const std::vector<Value> &,
                                  bool, CallResolution<Value> &resolution) {
  if (func_resolver_) {
    for (auto eid : {target_eid, indirect_target_eid}) {
      if (eid != kInvalidEntityId) {
        if (auto ir = func_resolver_(eid)) {
          resolution.action = CallAction::INLINE;
          resolution.return_value = Undefined{};
          resolution.callee_ir = *std::move(ir);
          return true;
        }
      }
    }
  }
  resolution.action = CallAction::SKIP;
  resolution.return_value = Undefined{};
  return true;
}

bool ConcretePolicy::resolve_global(NoOpScheduler &,
                                    RawEntityId entity_id,
                                    GlobalResolution &resolution) {
  if (global_resolver_) {
    if (auto info = global_resolver_(entity_id)) {
      resolution = GlobalResolution{.info = *std::move(info)};
      return true;
    }
  }
  resolution = GlobalResolution{};
  return true;
}

}  // namespace mx::ir::interpret
