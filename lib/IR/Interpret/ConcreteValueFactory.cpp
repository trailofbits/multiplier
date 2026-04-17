// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/Interpret/ConcreteValueFactory.h>

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <limits>

namespace mx::ir::interpret {
namespace {

// ---------------------------------------------------------------------------
// Width-dispatch helpers
// ---------------------------------------------------------------------------

// Signed integer binary operation dispatched by width tag (offset from base).
// `width_index` is 0=8-bit, 1=16-bit, 2=32-bit, 3=64-bit.
template <typename Op>
Value SignedIntBinOp(int64_t l, int64_t r, unsigned width_index, Op op_fn) {
  switch (width_index) {
    case 0: return MakeInt(static_cast<int64_t>(
        op_fn(static_cast<int8_t>(l), static_cast<int8_t>(r))));
    case 1: return MakeInt(static_cast<int64_t>(
        op_fn(static_cast<int16_t>(l), static_cast<int16_t>(r))));
    case 2: return MakeInt(static_cast<int64_t>(
        op_fn(static_cast<int32_t>(l), static_cast<int32_t>(r))));
    case 3: return MakeInt(op_fn(l, r));
    default: assert(false); return MakeUndef();
  }
}

// Unsigned integer binary operation dispatched by width tag.
template <typename Op>
Value UnsignedIntBinOp(uint64_t l, uint64_t r, unsigned width_index,
                       Op op_fn) {
  switch (width_index) {
    case 0: return MakeInt(static_cast<int64_t>(
        op_fn(static_cast<uint8_t>(l), static_cast<uint8_t>(r))));
    case 1: return MakeInt(static_cast<int64_t>(
        op_fn(static_cast<uint16_t>(l), static_cast<uint16_t>(r))));
    case 2: return MakeInt(static_cast<int64_t>(
        op_fn(static_cast<uint32_t>(l), static_cast<uint32_t>(r))));
    case 3: return MakeInt(static_cast<int64_t>(
        op_fn(static_cast<uint64_t>(l), static_cast<uint64_t>(r))));
    default: assert(false); return MakeUndef();
  }
}

// Signed integer unary operation dispatched by width tag.
template <typename Op>
Value SignedIntUnaryOp(int64_t v, unsigned width_index, Op op_fn) {
  switch (width_index) {
    case 0: return MakeInt(static_cast<int64_t>(
        op_fn(static_cast<int8_t>(v))));
    case 1: return MakeInt(static_cast<int64_t>(
        op_fn(static_cast<int16_t>(v))));
    case 2: return MakeInt(static_cast<int64_t>(
        op_fn(static_cast<int32_t>(v))));
    case 3: return MakeInt(op_fn(v));
    default: assert(false); return MakeUndef();
  }
}

// Unsigned integer unary operation dispatched by width tag.
template <typename Op>
Value UnsignedIntUnaryOp(uint64_t v, unsigned width_index, Op op_fn) {
  switch (width_index) {
    case 0: return MakeInt(static_cast<int64_t>(
        op_fn(static_cast<uint8_t>(v))));
    case 1: return MakeInt(static_cast<int64_t>(
        op_fn(static_cast<uint16_t>(v))));
    case 2: return MakeInt(static_cast<int64_t>(
        op_fn(static_cast<uint32_t>(v))));
    case 3: return MakeInt(static_cast<int64_t>(op_fn(v)));
    default: assert(false); return MakeUndef();
  }
}

// Shift-amount mask for a given width index.
static unsigned ShiftMask(unsigned width_index) {
  static constexpr unsigned masks[] = {7u, 15u, 31u, 63u};
  assert(width_index < 4);
  return masks[width_index];
}

}  // namespace

// ---------------------------------------------------------------------------
// BinaryOp
// ---------------------------------------------------------------------------

Value ConcreteValueFactory::BinaryOp(OpCode op, const Value &lhs,
                                     const Value &rhs) {
  using enum OpCode;

  // Logical short-circuit style (but both sides already evaluated).
  if (op == LOGICAL_AND) return MakeInt(IsTruthy(lhs) && IsTruthy(rhs) ? 1 : 0);
  if (op == LOGICAL_OR) return MakeInt(IsTruthy(lhs) || IsTruthy(rhs) ? 1 : 0);

  // Float arithmetic.
  auto float64 = [&](auto fn) -> Value {
    return MakeFloat(fn(AsFloat(lhs), AsFloat(rhs)));
  };
  auto float32 = [&](auto fn) -> Value {
    return MakeFloat32(fn(AsFloat32(lhs), AsFloat32(rhs)));
  };

  switch (op) {
    case FADD_32: return float32([](float a, float b) { return a + b; });
    case FADD_64: return float64([](double a, double b) { return a + b; });
    case FSUB_32: return float32([](float a, float b) { return a - b; });
    case FSUB_64: return float64([](double a, double b) { return a - b; });
    case FMUL_32: return float32([](float a, float b) { return a * b; });
    case FMUL_64: return float64([](double a, double b) { return a * b; });
    case FDIV_32: return float32([](float a, float b) { return a / b; });
    case FDIV_64: return float64([](double a, double b) { return a / b; });
    case FREM_32: return float32([](float a, float b) { return std::fmod(a, b); });
    case FREM_64: return float64([](double a, double b) { return std::fmod(a, b); });
    default: break;
  }

  // Signed integer arithmetic. Compute width index from opcode groups of 4.
  auto si = [&](OpCode base) -> unsigned {
    return static_cast<unsigned>(op) - static_cast<unsigned>(base);
  };

  int64_t l = AsInt(lhs);
  int64_t r = AsInt(rhs);
  uint64_t ul = AsUint(lhs);
  uint64_t ur = AsUint(rhs);

  // ADD
  if (op >= ADD_8 && op <= ADD_64)
    return SignedIntBinOp(l, r, si(ADD_8),
        [](auto a, auto b) { return static_cast<decltype(a)>(a + b); });
  if (op >= ATOMIC_ADD_8 && op <= ATOMIC_ADD_64)
    return SignedIntBinOp(l, r,
        static_cast<unsigned>(op) - static_cast<unsigned>(ATOMIC_ADD_8),
        [](auto a, auto b) { return static_cast<decltype(a)>(a + b); });

  // SUB
  if (op >= SUB_8 && op <= SUB_64)
    return SignedIntBinOp(l, r, si(SUB_8),
        [](auto a, auto b) { return static_cast<decltype(a)>(a - b); });
  if (op >= ATOMIC_SUB_8 && op <= ATOMIC_SUB_64)
    return SignedIntBinOp(l, r,
        static_cast<unsigned>(op) - static_cast<unsigned>(ATOMIC_SUB_8),
        [](auto a, auto b) { return static_cast<decltype(a)>(a - b); });

  // MUL
  if (op >= MUL_8 && op <= MUL_64)
    return SignedIntBinOp(l, r, si(MUL_8),
        [](auto a, auto b) { return static_cast<decltype(a)>(a * b); });

  // DIV (signed, div-by-zero returns 0)
  if (op >= DIV_8 && op <= DIV_64)
    return SignedIntBinOp(l, r, si(DIV_8),
        [](auto a, auto b) -> decltype(a) { return b == 0 ? 0 : a / b; });

  // REM (signed, div-by-zero returns 0)
  if (op >= REM_8 && op <= REM_64)
    return SignedIntBinOp(l, r, si(REM_8),
        [](auto a, auto b) -> decltype(a) { return b == 0 ? 0 : a % b; });

  // UDIV (unsigned, div-by-zero returns 0)
  if (op >= UDIV_8 && op <= UDIV_64)
    return UnsignedIntBinOp(ul, ur, si(UDIV_8),
        [](auto a, auto b) -> decltype(a) { return b == 0 ? 0 : a / b; });

  // UREM (unsigned, div-by-zero returns 0)
  if (op >= UREM_8 && op <= UREM_64)
    return UnsignedIntBinOp(ul, ur, si(UREM_8),
        [](auto a, auto b) -> decltype(a) { return b == 0 ? 0 : a % b; });

  // BIT_AND
  if (op >= BIT_AND_8 && op <= BIT_AND_64)
    return SignedIntBinOp(l, r, si(BIT_AND_8),
        [](auto a, auto b) { return static_cast<decltype(a)>(a & b); });
  if (op >= ATOMIC_AND_8 && op <= ATOMIC_AND_64)
    return SignedIntBinOp(l, r,
        static_cast<unsigned>(op) - static_cast<unsigned>(ATOMIC_AND_8),
        [](auto a, auto b) { return static_cast<decltype(a)>(a & b); });

  // BIT_OR
  if (op >= BIT_OR_8 && op <= BIT_OR_64)
    return SignedIntBinOp(l, r, si(BIT_OR_8),
        [](auto a, auto b) { return static_cast<decltype(a)>(a | b); });
  if (op >= ATOMIC_OR_8 && op <= ATOMIC_OR_64)
    return SignedIntBinOp(l, r,
        static_cast<unsigned>(op) - static_cast<unsigned>(ATOMIC_OR_8),
        [](auto a, auto b) { return static_cast<decltype(a)>(a | b); });

  // BIT_XOR
  if (op >= BIT_XOR_8 && op <= BIT_XOR_64)
    return SignedIntBinOp(l, r, si(BIT_XOR_8),
        [](auto a, auto b) { return static_cast<decltype(a)>(a ^ b); });
  if (op >= ATOMIC_XOR_8 && op <= ATOMIC_XOR_64)
    return SignedIntBinOp(l, r,
        static_cast<unsigned>(op) - static_cast<unsigned>(ATOMIC_XOR_8),
        [](auto a, auto b) { return static_cast<decltype(a)>(a ^ b); });

  // ATOMIC_NAND
  if (op >= ATOMIC_NAND_8 && op <= ATOMIC_NAND_64)
    return SignedIntBinOp(l, r,
        static_cast<unsigned>(op) - static_cast<unsigned>(ATOMIC_NAND_8),
        [](auto a, auto b) { return static_cast<decltype(a)>(~(a & b)); });

  // ATOMIC_EXCHANGE (just returns rhs)
  if (op >= ATOMIC_EXCHANGE_8 && op <= ATOMIC_EXCHANGE_64)
    return rhs;

  // SHL (mask shift amount)
  if (op >= SHL_8 && op <= SHL_64) {
    unsigned wi = si(SHL_8);
    unsigned mask = ShiftMask(wi);
    return SignedIntBinOp(l, r & mask, wi,
        [](auto a, auto b) { return static_cast<decltype(a)>(a << b); });
  }

  // SHR (arithmetic shift right, mask amount)
  if (op >= SHR_8 && op <= SHR_64) {
    unsigned wi = si(SHR_8);
    unsigned mask = ShiftMask(wi);
    return SignedIntBinOp(l, r & mask, wi,
        [](auto a, auto b) { return static_cast<decltype(a)>(a >> b); });
  }

  // USHR (logical shift right, mask amount)
  if (op >= USHR_8 && op <= USHR_64) {
    unsigned wi = si(USHR_8);
    unsigned mask = ShiftMask(wi);
    return UnsignedIntBinOp(ul, ur & mask, wi,
        [](auto a, auto b) { return static_cast<decltype(a)>(a >> b); });
  }

  assert(false && "Unhandled BinaryOp opcode");
  return MakeUndef();
}

// ---------------------------------------------------------------------------
// UnaryOp
// ---------------------------------------------------------------------------

Value ConcreteValueFactory::UnaryOp(OpCode op, const Value &operand) {
  using enum OpCode;

  if (op == LOGICAL_NOT) return MakeInt(!IsTruthy(operand) ? 1 : 0);

  // Float negate.
  if (op == FNEG_32) return MakeFloat32(-AsFloat32(operand));
  if (op == FNEG_64) return MakeFloat(-AsFloat(operand));

  int64_t v = AsInt(operand);
  uint64_t uv = AsUint(operand);

  auto wi = [&](OpCode base) -> unsigned {
    return static_cast<unsigned>(op) - static_cast<unsigned>(base);
  };

  // NEG
  if (op >= NEG_8 && op <= NEG_64)
    return SignedIntUnaryOp(v, wi(NEG_8),
        [](auto a) { return static_cast<decltype(a)>(-a); });

  // BIT_NOT
  if (op >= BIT_NOT_8 && op <= BIT_NOT_64)
    return UnsignedIntUnaryOp(uv, wi(BIT_NOT_8),
        [](auto a) { return static_cast<decltype(a)>(~a); });

  // ABS
  if (op >= ABS_8 && op <= ABS_64)
    return SignedIntUnaryOp(v, wi(ABS_8),
        [](auto a) { return a < 0 ? static_cast<decltype(a)>(-a) : a; });

  assert(false && "Unhandled UnaryOp opcode");
  return MakeUndef();
}

// ---------------------------------------------------------------------------
// Compare
// ---------------------------------------------------------------------------

Value ConcreteValueFactory::Compare(OpCode op, const Value &lhs,
                                    const Value &rhs) {
  using enum OpCode;

  // Pointer comparisons: if either side is a pointer, compare addresses.
  auto *lp = AsPointer(lhs);
  auto *rp = AsPointer(rhs);
  if (lp || rp) {
    uint64_t la = lp ? ConcreteAddress(*lp) : AsUint(lhs);
    uint64_t ra = rp ? ConcreteAddress(*rp) : AsUint(rhs);

    switch (op) {
      case CMP_EQ_8:  case CMP_EQ_16: case CMP_EQ_32: case CMP_EQ_64:
        return MakeInt(la == ra ? 1 : 0);
      case CMP_NE_8:  case CMP_NE_16: case CMP_NE_32: case CMP_NE_64:
        return MakeInt(la != ra ? 1 : 0);
      case CMP_LT_8:  case CMP_LT_16: case CMP_LT_32: case CMP_LT_64:
      case UCMP_LT_8: case UCMP_LT_16: case UCMP_LT_32: case UCMP_LT_64:
        return MakeInt(la < ra ? 1 : 0);
      case CMP_LE_8:  case CMP_LE_16: case CMP_LE_32: case CMP_LE_64:
      case UCMP_LE_8: case UCMP_LE_16: case UCMP_LE_32: case UCMP_LE_64:
        return MakeInt(la <= ra ? 1 : 0);
      case CMP_GT_8:  case CMP_GT_16: case CMP_GT_32: case CMP_GT_64:
      case UCMP_GT_8: case UCMP_GT_16: case UCMP_GT_32: case UCMP_GT_64:
        return MakeInt(la > ra ? 1 : 0);
      case CMP_GE_8:  case CMP_GE_16: case CMP_GE_32: case CMP_GE_64:
      case UCMP_GE_8: case UCMP_GE_16: case UCMP_GE_32: case UCMP_GE_64:
        return MakeInt(la >= ra ? 1 : 0);
      default: break;
    }
  }

  // Float comparisons.
  auto fcmp64 = [&](auto fn) -> Value {
    return MakeInt(fn(AsFloat(lhs), AsFloat(rhs)) ? 1 : 0);
  };
  auto fcmp32 = [&](auto fn) -> Value {
    return MakeInt(fn(AsFloat32(lhs), AsFloat32(rhs)) ? 1 : 0);
  };

  switch (op) {
    case FCMP_EQ_32: return fcmp32([](float a, float b) { return a == b; });
    case FCMP_EQ_64: return fcmp64([](double a, double b) { return a == b; });
    case FCMP_NE_32: return fcmp32([](float a, float b) { return a != b; });
    case FCMP_NE_64: return fcmp64([](double a, double b) { return a != b; });
    case FCMP_LT_32: return fcmp32([](float a, float b) { return a < b; });
    case FCMP_LT_64: return fcmp64([](double a, double b) { return a < b; });
    case FCMP_LE_32: return fcmp32([](float a, float b) { return a <= b; });
    case FCMP_LE_64: return fcmp64([](double a, double b) { return a <= b; });
    case FCMP_GT_32: return fcmp32([](float a, float b) { return a > b; });
    case FCMP_GT_64: return fcmp64([](double a, double b) { return a > b; });
    case FCMP_GE_32: return fcmp32([](float a, float b) { return a >= b; });
    case FCMP_GE_64: return fcmp64([](double a, double b) { return a >= b; });
    default: break;
  }

  // Signed integer comparisons.
  int64_t l = AsInt(lhs);
  int64_t r = AsInt(rhs);
  uint64_t ul = AsUint(lhs);
  uint64_t ur = AsUint(rhs);

  auto si = [&](OpCode base) -> unsigned {
    return static_cast<unsigned>(op) - static_cast<unsigned>(base);
  };

  // CMP_EQ
  if (op >= CMP_EQ_8 && op <= CMP_EQ_64)
    return SignedIntBinOp(l, r, si(CMP_EQ_8),
        [](auto a, auto b) -> int64_t { return a == b ? 1 : 0; });

  // CMP_NE
  if (op >= CMP_NE_8 && op <= CMP_NE_64)
    return SignedIntBinOp(l, r, si(CMP_NE_8),
        [](auto a, auto b) -> int64_t { return a != b ? 1 : 0; });

  // CMP_LT (signed)
  if (op >= CMP_LT_8 && op <= CMP_LT_64)
    return SignedIntBinOp(l, r, si(CMP_LT_8),
        [](auto a, auto b) -> int64_t { return a < b ? 1 : 0; });

  // CMP_LE (signed)
  if (op >= CMP_LE_8 && op <= CMP_LE_64)
    return SignedIntBinOp(l, r, si(CMP_LE_8),
        [](auto a, auto b) -> int64_t { return a <= b ? 1 : 0; });

  // CMP_GT (signed)
  if (op >= CMP_GT_8 && op <= CMP_GT_64)
    return SignedIntBinOp(l, r, si(CMP_GT_8),
        [](auto a, auto b) -> int64_t { return a > b ? 1 : 0; });

  // CMP_GE (signed)
  if (op >= CMP_GE_8 && op <= CMP_GE_64)
    return SignedIntBinOp(l, r, si(CMP_GE_8),
        [](auto a, auto b) -> int64_t { return a >= b ? 1 : 0; });

  // UCMP_LT (unsigned)
  if (op >= UCMP_LT_8 && op <= UCMP_LT_64)
    return UnsignedIntBinOp(ul, ur, si(UCMP_LT_8),
        [](auto a, auto b) -> int64_t { return a < b ? 1 : 0; });

  // UCMP_LE (unsigned)
  if (op >= UCMP_LE_8 && op <= UCMP_LE_64)
    return UnsignedIntBinOp(ul, ur, si(UCMP_LE_8),
        [](auto a, auto b) -> int64_t { return a <= b ? 1 : 0; });

  // UCMP_GT (unsigned)
  if (op >= UCMP_GT_8 && op <= UCMP_GT_64)
    return UnsignedIntBinOp(ul, ur, si(UCMP_GT_8),
        [](auto a, auto b) -> int64_t { return a > b ? 1 : 0; });

  // UCMP_GE (unsigned)
  if (op >= UCMP_GE_8 && op <= UCMP_GE_64)
    return UnsignedIntBinOp(ul, ur, si(UCMP_GE_8),
        [](auto a, auto b) -> int64_t { return a >= b ? 1 : 0; });

  assert(false && "Unhandled Compare opcode");
  return MakeInt(0);
}

// ---------------------------------------------------------------------------
// Cast
// ---------------------------------------------------------------------------

Value ConcreteValueFactory::Cast(CastOp op, const Value &operand) {
  using enum CastOp;

  switch (op) {
    case IDENTITY:
      return operand;

    case BITCAST:
      return operand;

    // Pointer conversions.
    case PTR_TO_I64: {
      auto *p = AsPointer(operand);
      return MakeInt(static_cast<int64_t>(p ? ConcreteAddress(*p)
                                            : AsUint(operand)));
    }
    case PTR_TO_I32: {
      auto *p = AsPointer(operand);
      uint64_t addr = p ? ConcreteAddress(*p) : AsUint(operand);
      return MakeInt(static_cast<int64_t>(static_cast<uint32_t>(addr)));
    }
    case I64_TO_PTR:
      return MakePtr(AsUint(operand));
    case I32_TO_PTR:
      return MakePtr(static_cast<uint64_t>(static_cast<uint32_t>(AsUint(operand))));

    // Sign-extend.
    case SEXT_I8_I16:
      return MakeInt(static_cast<int64_t>(static_cast<int16_t>(
          static_cast<int8_t>(AsInt(operand)))));
    case SEXT_I8_I32:
      return MakeInt(static_cast<int64_t>(static_cast<int32_t>(
          static_cast<int8_t>(AsInt(operand)))));
    case SEXT_I8_I64:
      return MakeInt(static_cast<int64_t>(
          static_cast<int8_t>(AsInt(operand))));
    case SEXT_I16_I32:
      return MakeInt(static_cast<int64_t>(static_cast<int32_t>(
          static_cast<int16_t>(AsInt(operand)))));
    case SEXT_I16_I64:
      return MakeInt(static_cast<int64_t>(
          static_cast<int16_t>(AsInt(operand))));
    case SEXT_I32_I64:
      return MakeInt(static_cast<int64_t>(
          static_cast<int32_t>(AsInt(operand))));

    // Zero-extend.
    case ZEXT_I8_I16:
      return MakeInt(static_cast<int64_t>(
          static_cast<uint16_t>(static_cast<uint8_t>(AsUint(operand)))));
    case ZEXT_I8_I32:
      return MakeInt(static_cast<int64_t>(
          static_cast<uint32_t>(static_cast<uint8_t>(AsUint(operand)))));
    case ZEXT_I8_I64:
      return MakeInt(static_cast<int64_t>(
          static_cast<uint8_t>(AsUint(operand))));
    case ZEXT_I16_I32:
      return MakeInt(static_cast<int64_t>(
          static_cast<uint32_t>(static_cast<uint16_t>(AsUint(operand)))));
    case ZEXT_I16_I64:
      return MakeInt(static_cast<int64_t>(
          static_cast<uint16_t>(AsUint(operand))));
    case ZEXT_I32_I64:
      return MakeInt(static_cast<int64_t>(
          static_cast<uint32_t>(AsUint(operand))));

    // Truncate.
    case TRUNC_I16_I8:
      return MakeInt(static_cast<int64_t>(
          static_cast<int8_t>(static_cast<int16_t>(AsInt(operand)))));
    case TRUNC_I32_I8:
      return MakeInt(static_cast<int64_t>(
          static_cast<int8_t>(static_cast<int32_t>(AsInt(operand)))));
    case TRUNC_I64_I8:
      return MakeInt(static_cast<int64_t>(
          static_cast<int8_t>(AsInt(operand))));
    case TRUNC_I32_I16:
      return MakeInt(static_cast<int64_t>(
          static_cast<int16_t>(static_cast<int32_t>(AsInt(operand)))));
    case TRUNC_I64_I16:
      return MakeInt(static_cast<int64_t>(
          static_cast<int16_t>(AsInt(operand))));
    case TRUNC_I64_I32:
      return MakeInt(static_cast<int64_t>(
          static_cast<int32_t>(AsInt(operand))));

    // Float widening/narrowing.
    case F32_TO_F64:
      return MakeFloat(static_cast<double>(AsFloat32(operand)));
    case F64_TO_F32:
      return MakeFloat32(static_cast<float>(AsFloat(operand)));

    // Signed int to float.
    case SI8_TO_F32:
      return MakeFloat32(static_cast<float>(
          static_cast<int8_t>(AsInt(operand))));
    case SI8_TO_F64:
      return MakeFloat(static_cast<double>(
          static_cast<int8_t>(AsInt(operand))));
    case SI16_TO_F32:
      return MakeFloat32(static_cast<float>(
          static_cast<int16_t>(AsInt(operand))));
    case SI16_TO_F64:
      return MakeFloat(static_cast<double>(
          static_cast<int16_t>(AsInt(operand))));
    case SI32_TO_F32:
      return MakeFloat32(static_cast<float>(
          static_cast<int32_t>(AsInt(operand))));
    case SI32_TO_F64:
      return MakeFloat(static_cast<double>(
          static_cast<int32_t>(AsInt(operand))));
    case SI64_TO_F32:
      return MakeFloat32(static_cast<float>(AsInt(operand)));
    case SI64_TO_F64:
      return MakeFloat(static_cast<double>(AsInt(operand)));

    // Unsigned int to float.
    case UI8_TO_F32:
      return MakeFloat32(static_cast<float>(
          static_cast<uint8_t>(AsUint(operand))));
    case UI8_TO_F64:
      return MakeFloat(static_cast<double>(
          static_cast<uint8_t>(AsUint(operand))));
    case UI16_TO_F32:
      return MakeFloat32(static_cast<float>(
          static_cast<uint16_t>(AsUint(operand))));
    case UI16_TO_F64:
      return MakeFloat(static_cast<double>(
          static_cast<uint16_t>(AsUint(operand))));
    case UI32_TO_F32:
      return MakeFloat32(static_cast<float>(
          static_cast<uint32_t>(AsUint(operand))));
    case UI32_TO_F64:
      return MakeFloat(static_cast<double>(
          static_cast<uint32_t>(AsUint(operand))));
    case UI64_TO_F32:
      return MakeFloat32(static_cast<float>(AsUint(operand)));
    case UI64_TO_F64:
      return MakeFloat(static_cast<double>(AsUint(operand)));

    // Float to signed int.
    case F32_TO_SI8:
      return MakeInt(static_cast<int64_t>(
          static_cast<int8_t>(static_cast<float>(AsFloat32(operand)))));
    case F32_TO_SI16:
      return MakeInt(static_cast<int64_t>(
          static_cast<int16_t>(static_cast<float>(AsFloat32(operand)))));
    case F32_TO_SI32:
      return MakeInt(static_cast<int64_t>(
          static_cast<int32_t>(static_cast<float>(AsFloat32(operand)))));
    case F32_TO_SI64:
      return MakeInt(static_cast<int64_t>(
          static_cast<float>(AsFloat32(operand))));
    case F64_TO_SI8:
      return MakeInt(static_cast<int64_t>(
          static_cast<int8_t>(AsFloat(operand))));
    case F64_TO_SI16:
      return MakeInt(static_cast<int64_t>(
          static_cast<int16_t>(AsFloat(operand))));
    case F64_TO_SI32:
      return MakeInt(static_cast<int64_t>(
          static_cast<int32_t>(AsFloat(operand))));
    case F64_TO_SI64:
      return MakeInt(static_cast<int64_t>(AsFloat(operand)));

    // Float to unsigned int.
    case F32_TO_UI8:
      return MakeInt(static_cast<int64_t>(
          static_cast<uint8_t>(static_cast<float>(AsFloat32(operand)))));
    case F32_TO_UI16:
      return MakeInt(static_cast<int64_t>(
          static_cast<uint16_t>(static_cast<float>(AsFloat32(operand)))));
    case F32_TO_UI32:
      return MakeInt(static_cast<int64_t>(
          static_cast<uint32_t>(static_cast<float>(AsFloat32(operand)))));
    case F32_TO_UI64:
      return MakeInt(static_cast<int64_t>(
          static_cast<uint64_t>(static_cast<float>(AsFloat32(operand)))));
    case F64_TO_UI8:
      return MakeInt(static_cast<int64_t>(
          static_cast<uint8_t>(AsFloat(operand))));
    case F64_TO_UI16:
      return MakeInt(static_cast<int64_t>(
          static_cast<uint16_t>(AsFloat(operand))));
    case F64_TO_UI32:
      return MakeInt(static_cast<int64_t>(
          static_cast<uint32_t>(AsFloat(operand))));
    case F64_TO_UI64:
      return MakeInt(static_cast<int64_t>(
          static_cast<uint64_t>(AsFloat(operand))));
  }

  assert(false && "Unhandled CastOp");
  return MakeUndef();
}

// ---------------------------------------------------------------------------
// MakeConst
// ---------------------------------------------------------------------------

Value ConcreteValueFactory::MakeConst(ConstOp op, int64_t signed_val,
                                      uint64_t unsigned_val) {
  using enum ConstOp;

  switch (op) {
    case NULL_PTR:
      return MakeNull();

    case FLOAT16: {
      // float16 is stored as float in the constant pool.
      float f;
      std::memcpy(&f, &signed_val, sizeof(f));
      return MakeFloat32(f);
    }
    case FLOAT32: {
      float f;
      std::memcpy(&f, &signed_val, sizeof(f));
      return MakeFloat32(f);
    }
    case FLOAT64: {
      double d;
      std::memcpy(&d, &signed_val, sizeof(d));
      return MakeFloat(d);
    }

    case INF32:
      return MakeFloat32(std::numeric_limits<float>::infinity());
    case INF64:
      return MakeFloat(std::numeric_limits<double>::infinity());
    case NAN32:
      return MakeFloat32(std::numeric_limits<float>::quiet_NaN());
    case NAN64:
      return MakeFloat(std::numeric_limits<double>::quiet_NaN());

    case UINT64:
      return MakeInt(static_cast<int64_t>(unsigned_val));

    case UINT32:
      return MakeInt(static_cast<int64_t>(
          static_cast<int32_t>(static_cast<uint32_t>(unsigned_val))));
    case UINT16:
    case WCHAR16:
      return MakeInt(static_cast<int64_t>(
          static_cast<int16_t>(static_cast<uint16_t>(unsigned_val))));
    case UINT8:
      return MakeInt(static_cast<int64_t>(
          static_cast<int8_t>(static_cast<uint8_t>(unsigned_val))));

    case INT8:
    case INT16:
    case INT32:
    case INT64:
    case BOOL:
    case WCHAR32:
      return MakeInt(signed_val);
  }

  assert(false && "Unhandled ConstOp");
  return MakeUndef();
}

// ---------------------------------------------------------------------------
// MakeNullPtr
// ---------------------------------------------------------------------------

Value ConcreteValueFactory::MakeNullPtr(void) {
  return MakeNull();
}

// ---------------------------------------------------------------------------
// PtrAdd
// ---------------------------------------------------------------------------

Value ConcreteValueFactory::PtrAdd(const Value &base, const Value &index,
                                   int64_t element_size) {
  int64_t offset = AsInt(index) * element_size;
  if (auto *p = AsPointer(base)) {
    return MakePtr(ConcreteAddress(*p) + static_cast<uint64_t>(offset));
  }
  return MakeInt(AsInt(base) + offset);
}

// ---------------------------------------------------------------------------
// PtrDiff
// ---------------------------------------------------------------------------

Value ConcreteValueFactory::PtrDiff(const Value &lhs, const Value &rhs,
                                    int64_t element_size) {
  auto *lp = AsPointer(lhs);
  auto *rp = AsPointer(rhs);
  int64_t la = lp ? static_cast<int64_t>(ConcreteAddress(*lp)) : AsInt(lhs);
  int64_t ra = rp ? static_cast<int64_t>(ConcreteAddress(*rp)) : AsInt(rhs);
  int64_t divisor = std::max(element_size, static_cast<int64_t>(1));
  return MakeInt((la - ra) / divisor);
}

// ---------------------------------------------------------------------------
// IsTrue
// ---------------------------------------------------------------------------

std::optional<bool> ConcreteValueFactory::IsTrue(const Value &val) {
  return IsTruthy(val);
}

// ---------------------------------------------------------------------------
// Select
// ---------------------------------------------------------------------------

Value ConcreteValueFactory::Select(const Value &cond, const Value &if_true,
                                   const Value &if_false) {
  return IsTruthy(cond) ? if_true : if_false;
}

// ---------------------------------------------------------------------------
// BitwiseIntrinsic
// ---------------------------------------------------------------------------

Value ConcreteValueFactory::BitwiseIntrinsic(OpCode width_op, BitwiseOp sub,
                                             const Value &val,
                                             const Value &val2) {
  using enum BitwiseOp;
  using enum OpCode;

  uint64_t v = AsUint(val);
  uint64_t v2 = AsUint(val2);

  // Determine the width from the parent opcode.
  unsigned width_bits;
  switch (width_op) {
    case BITWISE_8:  width_bits = 8; break;
    case BITWISE_16: width_bits = 16; break;
    case BITWISE_32: width_bits = 32; break;
    case BITWISE_64: width_bits = 64; break;
    default: assert(false); return MakeUndef();
  }

  switch (sub) {
    case BSWAP_16:
      return MakeInt(static_cast<int64_t>(__builtin_bswap16(
          static_cast<uint16_t>(v))));
    case BSWAP_32:
      return MakeInt(static_cast<int64_t>(__builtin_bswap32(
          static_cast<uint32_t>(v))));
    case BSWAP_64:
      return MakeInt(static_cast<int64_t>(__builtin_bswap64(v)));

    case POPCOUNT:
      if (width_bits <= 32)
        return MakeInt(static_cast<int64_t>(
            __builtin_popcount(static_cast<unsigned>(
                static_cast<uint32_t>(v)))));
      return MakeInt(static_cast<int64_t>(
          __builtin_popcountll(static_cast<unsigned long long>(v))));

    case CLZ:
      switch (width_bits) {
        case 8:
          return MakeInt(static_cast<int64_t>(
              __builtin_clz(static_cast<unsigned>(
                  static_cast<uint8_t>(v))) - 24));
        case 16:
          return MakeInt(static_cast<int64_t>(
              __builtin_clz(static_cast<unsigned>(
                  static_cast<uint16_t>(v))) - 16));
        case 32:
          return MakeInt(static_cast<int64_t>(
              __builtin_clz(static_cast<unsigned>(
                  static_cast<uint32_t>(v)))));
        case 64:
          return MakeInt(static_cast<int64_t>(
              __builtin_clzll(static_cast<unsigned long long>(v))));
        default: break;
      }
      break;

    case CTZ:
      if (width_bits <= 32)
        return MakeInt(static_cast<int64_t>(
            __builtin_ctz(static_cast<unsigned>(
                static_cast<uint32_t>(v)))));
      return MakeInt(static_cast<int64_t>(
          __builtin_ctzll(static_cast<unsigned long long>(v))));

    case FFS:
      if (width_bits <= 32)
        return MakeInt(static_cast<int64_t>(
            __builtin_ffs(static_cast<int>(static_cast<int32_t>(v)))));
      return MakeInt(static_cast<int64_t>(
          __builtin_ffsll(static_cast<long long>(
              static_cast<int64_t>(v)))));

    case PARITY:
      if (width_bits <= 32)
        return MakeInt(static_cast<int64_t>(
            __builtin_parity(static_cast<unsigned>(
                static_cast<uint32_t>(v)))));
      return MakeInt(static_cast<int64_t>(
          __builtin_parityll(static_cast<unsigned long long>(v))));

    case ROTL: {
      unsigned amt = static_cast<unsigned>(v2) % width_bits;
      if (amt == 0) return MakeInt(static_cast<int64_t>(v));
      switch (width_bits) {
        case 8: {
          auto x = static_cast<uint8_t>(v);
          return MakeInt(static_cast<int64_t>(
              static_cast<uint8_t>((x << amt) | (x >> (8 - amt)))));
        }
        case 16: {
          auto x = static_cast<uint16_t>(v);
          return MakeInt(static_cast<int64_t>(
              static_cast<uint16_t>((x << amt) | (x >> (16 - amt)))));
        }
        case 32: {
          auto x = static_cast<uint32_t>(v);
          return MakeInt(static_cast<int64_t>((x << amt) | (x >> (32 - amt))));
        }
        case 64:
          return MakeInt(static_cast<int64_t>(
              (v << amt) | (v >> (64 - amt))));
        default: break;
      }
      break;
    }

    case ROTR: {
      unsigned amt = static_cast<unsigned>(v2) % width_bits;
      if (amt == 0) return MakeInt(static_cast<int64_t>(v));
      switch (width_bits) {
        case 8: {
          auto x = static_cast<uint8_t>(v);
          return MakeInt(static_cast<int64_t>(
              static_cast<uint8_t>((x >> amt) | (x << (8 - amt)))));
        }
        case 16: {
          auto x = static_cast<uint16_t>(v);
          return MakeInt(static_cast<int64_t>(
              static_cast<uint16_t>((x >> amt) | (x << (16 - amt)))));
        }
        case 32: {
          auto x = static_cast<uint32_t>(v);
          return MakeInt(static_cast<int64_t>((x >> amt) | (x << (32 - amt))));
        }
        case 64:
          return MakeInt(static_cast<int64_t>(
              (v >> amt) | (v << (64 - amt))));
        default: break;
      }
      break;
    }
  }

  assert(false && "Unhandled BitwiseOp");
  return MakeUndef();
}

// ---------------------------------------------------------------------------
// FloatIntrinsic
// ---------------------------------------------------------------------------

Value ConcreteValueFactory::FloatIntrinsic(FloatOp sub,
                                           const std::vector<Value> &operands) {
  using enum FloatOp;

  // Helper to get operand as double/float.
  auto d = [&](size_t i) -> double {
    return i < operands.size() ? AsFloat(operands[i]) : 0.0;
  };
  auto f = [&](size_t i) -> float {
    return i < operands.size() ? AsFloat32(operands[i]) : 0.0f;
  };

  switch (sub) {
    // Classification (return int).
    case ISNAN_32:    return MakeInt(std::isnan(f(0)) ? 1 : 0);
    case ISNAN_64:    return MakeInt(std::isnan(d(0)) ? 1 : 0);
    case ISINF_32:    return MakeInt(std::isinf(f(0)) ? 1 : 0);
    case ISINF_64:    return MakeInt(std::isinf(d(0)) ? 1 : 0);
    case ISFINITE_32: return MakeInt(std::isfinite(f(0)) ? 1 : 0);
    case ISFINITE_64: return MakeInt(std::isfinite(d(0)) ? 1 : 0);
    case SIGNBIT_32:  return MakeInt(std::signbit(f(0)) ? 1 : 0);
    case SIGNBIT_64:  return MakeInt(std::signbit(d(0)) ? 1 : 0);

    // Constants (no operands).
    case INF_32:  return MakeFloat32(std::numeric_limits<float>::infinity());
    case INF_64:  return MakeFloat(std::numeric_limits<double>::infinity());
    case NAN_32:  return MakeFloat32(std::numeric_limits<float>::quiet_NaN());
    case NAN_64:  return MakeFloat(std::numeric_limits<double>::quiet_NaN());
    case HUGE_32: return MakeFloat32(HUGE_VALF);
    case HUGE_64: return MakeFloat(HUGE_VAL);

    // Unary float ops.
    case FABS_32:      return MakeFloat32(std::fabs(f(0)));
    case FABS_64:      return MakeFloat(std::fabs(d(0)));
    case CEIL_32:      return MakeFloat32(std::ceil(f(0)));
    case CEIL_64:      return MakeFloat(std::ceil(d(0)));
    case FLOOR_32:     return MakeFloat32(std::floor(f(0)));
    case FLOOR_64:     return MakeFloat(std::floor(d(0)));
    case ROUND_32:     return MakeFloat32(std::round(f(0)));
    case ROUND_64:     return MakeFloat(std::round(d(0)));
    case TRUNC_32:     return MakeFloat32(std::trunc(f(0)));
    case TRUNC_64:     return MakeFloat(std::trunc(d(0)));
    case SQRT_32:      return MakeFloat32(std::sqrt(f(0)));
    case SQRT_64:      return MakeFloat(std::sqrt(d(0)));
    case SIN_32:       return MakeFloat32(std::sin(f(0)));
    case SIN_64:       return MakeFloat(std::sin(d(0)));
    case COS_32:       return MakeFloat32(std::cos(f(0)));
    case COS_64:       return MakeFloat(std::cos(d(0)));
    case TAN_32:       return MakeFloat32(std::tan(f(0)));
    case TAN_64:       return MakeFloat(std::tan(d(0)));
    case ASIN_32:      return MakeFloat32(std::asin(f(0)));
    case ASIN_64:      return MakeFloat(std::asin(d(0)));
    case ACOS_32:      return MakeFloat32(std::acos(f(0)));
    case ACOS_64:      return MakeFloat(std::acos(d(0)));
    case ATAN_32:      return MakeFloat32(std::atan(f(0)));
    case ATAN_64:      return MakeFloat(std::atan(d(0)));
    case EXP_32:       return MakeFloat32(std::exp(f(0)));
    case EXP_64:       return MakeFloat(std::exp(d(0)));
    case EXP2_32:      return MakeFloat32(std::exp2(f(0)));
    case EXP2_64:      return MakeFloat(std::exp2(d(0)));
    case LOG_32:       return MakeFloat32(std::log(f(0)));
    case LOG_64:       return MakeFloat(std::log(d(0)));
    case LOG2_32:      return MakeFloat32(std::log2(f(0)));
    case LOG2_64:      return MakeFloat(std::log2(d(0)));
    case LOG10_32:     return MakeFloat32(std::log10(f(0)));
    case LOG10_64:     return MakeFloat(std::log10(d(0)));
    case SINH_32:      return MakeFloat32(std::sinh(f(0)));
    case SINH_64:      return MakeFloat(std::sinh(d(0)));
    case COSH_32:      return MakeFloat32(std::cosh(f(0)));
    case COSH_64:      return MakeFloat(std::cosh(d(0)));
    case TANH_32:      return MakeFloat32(std::tanh(f(0)));
    case TANH_64:      return MakeFloat(std::tanh(d(0)));
    case ERF_32:       return MakeFloat32(std::erf(f(0)));
    case ERF_64:       return MakeFloat(std::erf(d(0)));
    case ERFC_32:      return MakeFloat32(std::erfc(f(0)));
    case ERFC_64:      return MakeFloat(std::erfc(d(0)));
    case TGAMMA_32:    return MakeFloat32(std::tgamma(f(0)));
    case TGAMMA_64:    return MakeFloat(std::tgamma(d(0)));
    case LGAMMA_32:    return MakeFloat32(std::lgamma(f(0)));
    case LGAMMA_64:    return MakeFloat(std::lgamma(d(0)));

    // Binary float ops.
    case COPYSIGN_32:  return MakeFloat32(std::copysign(f(0), f(1)));
    case COPYSIGN_64:  return MakeFloat(std::copysign(d(0), d(1)));
    case FMIN_32:      return MakeFloat32(std::fmin(f(0), f(1)));
    case FMIN_64:      return MakeFloat(std::fmin(d(0), d(1)));
    case FMAX_32:      return MakeFloat32(std::fmax(f(0), f(1)));
    case FMAX_64:      return MakeFloat(std::fmax(d(0), d(1)));
    case ATAN2_32:     return MakeFloat32(std::atan2(f(0), f(1)));
    case ATAN2_64:     return MakeFloat(std::atan2(d(0), d(1)));
    case POW_32:       return MakeFloat32(std::pow(f(0), f(1)));
    case POW_64:       return MakeFloat(std::pow(d(0), d(1)));
    case FMOD_32:      return MakeFloat32(std::fmod(f(0), f(1)));
    case FMOD_64:      return MakeFloat(std::fmod(d(0), d(1)));
    case REMAINDER_32: return MakeFloat32(std::remainder(f(0), f(1)));
    case REMAINDER_64: return MakeFloat(std::remainder(d(0), d(1)));
    case HYPOT_32:     return MakeFloat32(std::hypot(f(0), f(1)));
    case HYPOT_64:     return MakeFloat(std::hypot(d(0), d(1)));
    case FDIM_32:      return MakeFloat32(std::fdim(f(0), f(1)));
    case FDIM_64:      return MakeFloat(std::fdim(d(0), d(1)));

    // Ternary float ops.
    case FMA_32:       return MakeFloat32(std::fma(f(0), f(1), f(2)));
    case FMA_64:       return MakeFloat(std::fma(d(0), d(1), d(2)));
  }

  assert(false && "Unhandled FloatOp");
  return MakeUndef();
}

}  // namespace mx::ir::interpret
