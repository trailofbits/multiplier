// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../../Compiler.h"
#include "Value.h"

#include <multiplier/IR/OpCode.h>
#include <multiplier/IR/InstructionKinds.h>

#include <optional>
#include <vector>

namespace mx::ir::interpret {

// ===========================================================================
// Width-dispatch helpers for integer arithmetic.
//
// These are pure-computation templates used by concrete_binary_op, etc.
// Inline so that both ConcretePolicy.cpp and the Python specialization
// can call them without ODR issues.
// ===========================================================================

template <typename Op>
inline Value SignedIntBinOp(int64_t l, int64_t r, unsigned wi, Op fn) {
  switch (wi) {
    case 0: return make_int(static_cast<int64_t>(static_cast<int8_t>(fn(static_cast<int8_t>(l), static_cast<int8_t>(r)))));
    case 1: return make_int(static_cast<int64_t>(static_cast<int16_t>(fn(static_cast<int16_t>(l), static_cast<int16_t>(r)))));
    case 2: return make_int(static_cast<int64_t>(static_cast<int32_t>(fn(static_cast<int32_t>(l), static_cast<int32_t>(r)))));
    case 3: return make_int(fn(l, r));
    default: return Undefined{};
  }
}

template <typename Op>
inline Value UnsignedIntBinOp(uint64_t l, uint64_t r, unsigned wi, Op fn) {
  switch (wi) {
    case 0: return make_int(static_cast<int64_t>(fn(static_cast<uint8_t>(l), static_cast<uint8_t>(r))));
    case 1: return make_int(static_cast<int64_t>(fn(static_cast<uint16_t>(l), static_cast<uint16_t>(r))));
    case 2: return make_int(static_cast<int64_t>(fn(static_cast<uint32_t>(l), static_cast<uint32_t>(r))));
    case 3: return make_int(static_cast<int64_t>(fn(static_cast<uint64_t>(l), static_cast<uint64_t>(r))));
    default: return Undefined{};
  }
}

template <typename Op>
inline Value SignedIntUnaryOp(int64_t v, unsigned wi, Op fn) {
  switch (wi) {
    case 0: return make_int(static_cast<int64_t>(static_cast<int8_t>(fn(static_cast<int8_t>(v)))));
    case 1: return make_int(static_cast<int64_t>(static_cast<int16_t>(fn(static_cast<int16_t>(v)))));
    case 2: return make_int(static_cast<int64_t>(static_cast<int32_t>(fn(static_cast<int32_t>(v)))));
    case 3: return make_int(fn(v));
    default: return Undefined{};
  }
}

template <typename Op>
inline Value UnsignedIntUnaryOp(uint64_t v, unsigned wi, Op fn) {
  switch (wi) {
    case 0: return make_int(static_cast<int64_t>(fn(static_cast<uint8_t>(v))));
    case 1: return make_int(static_cast<int64_t>(fn(static_cast<uint16_t>(v))));
    case 2: return make_int(static_cast<int64_t>(fn(static_cast<uint32_t>(v))));
    case 3: return make_int(static_cast<int64_t>(fn(v)));
    default: return Undefined{};
  }
}

inline unsigned ShiftMask(unsigned wi) {
  static constexpr unsigned masks[] = {7u, 15u, 31u, 63u};
  return masks[wi & 3u];
}

// ===========================================================================
// Free functions: stateless concrete value operations.
//
// Callable from any translation unit — both ConcretePolicy (the concrete
// interpreter) and the Python-policy specialization's concrete fast-path.
// ===========================================================================

MX_EXPORT Value concrete_binary_op(OpCode op, const Value &lhs,
                                   const Value &rhs);
MX_EXPORT Value concrete_unary_op(OpCode op, const Value &operand);
MX_EXPORT Value concrete_compare(OpCode op, const Value &lhs,
                                 const Value &rhs);
MX_EXPORT Value concrete_cast(CastOp op, const Value &operand);
MX_EXPORT Value concrete_make_const(ConstOp op, int64_t signed_val,
                                    uint64_t unsigned_val);
MX_EXPORT Value concrete_ptr_add(const Value &base, const Value &index,
                                 int64_t element_size);
MX_EXPORT Value concrete_ptr_diff(const Value &lhs, const Value &rhs,
                                  int64_t element_size);
MX_EXPORT Value concrete_ptr_offset(const Value &base, int64_t byte_offset);
MX_EXPORT Value concrete_select(const Value &cond, const Value &if_true,
                                const Value &if_false);
MX_EXPORT Value concrete_bitwise_intrinsic(OpCode width_op, BitwiseOp sub,
                                           const Value &val,
                                           const Value &val2);
MX_EXPORT Value concrete_float_intrinsic(FloatOp sub,
                                         const std::vector<Value> &operands);
MX_EXPORT std::optional<bool> concrete_is_true(const Value &val);

// ===========================================================================
// Memory address helpers (pure value operations, no memory needed).
// ===========================================================================

MX_EXPORT uint64_t concrete_extract_address(const Value &val);
MX_EXPORT bool concrete_has_address(const Value &val);

// ===========================================================================
// Memory read/write and bulk operations.
// ===========================================================================

class ConcreteMemory;

MX_EXPORT void concrete_write_to_mem(ConcreteMemory &memory, uint64_t address,
                                     const Value &val, size_t size,
                                     bool is_float = false);
MX_EXPORT Value concrete_read_from_mem(ConcreteMemory &memory, uint64_t address,
                                       size_t size, bool is_float);
MX_EXPORT bool concrete_mem_bulk_op(ConcreteMemory &memory, MemOp sub,
                                    const std::vector<Value> &ops,
                                    const MemoryInst &mi, Value &result);

}  // namespace mx::ir::interpret
