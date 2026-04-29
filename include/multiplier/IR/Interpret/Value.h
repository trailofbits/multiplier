// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>

namespace mx::ir::interpret {

// A concrete value: 8 bytes, type-punnable via union. The instruction
// determines interpretation — no variant tag, no width, no is_float.
// Pointers, integers, floats, and "undefined" are all just bit patterns.
struct Value {
  union {
    uint64_t u64;
    int64_t  i64;
    double   f64;
    struct { float    val; uint32_t _pad; } f32;
    struct { uint32_t val; uint32_t _pad; } u32;
    struct { int32_t  val; uint32_t _pad; } i32;
    struct { uint16_t val; uint16_t _pad[3]; } u16;
    struct { int16_t  val; uint16_t _pad[3]; } i16;
    struct { uint8_t  val; uint8_t  _pad[7]; } u8;
    struct { int8_t   val; uint8_t  _pad[7]; } i8;
  };
};

static_assert(sizeof(Value) == 8,
    "Value must be exactly 8 bytes — check struct packing");
static_assert(alignof(Value) == alignof(uint64_t),
    "Value must be naturally aligned to 8 bytes");

// ---------------------------------------------------------------------------
// Accessors — direct union reads, no dispatch
// ---------------------------------------------------------------------------

inline int64_t  as_int(const Value &v)     { return v.i64; }
inline uint64_t as_uint(const Value &v)    { return v.u64; }
inline double   as_float(const Value &v)   { return v.f64; }
inline float    as_float32(const Value &v) { return v.f32.val; }
inline bool     is_truthy(const Value &v)  { return v.u64 != 0; }

// ---------------------------------------------------------------------------
// Construction helpers — every path writes all 8 bytes
// ---------------------------------------------------------------------------

inline Value make_int(int64_t v, uint8_t = 8) {
  Value r;
  r.i64 = v;
  return r;
}

inline Value make_uint(uint64_t v, uint8_t = 8) {
  Value r;
  r.u64 = v;
  return r;
}

inline Value make_float(double v) {
  Value r;
  r.f64 = v;
  return r;
}

inline Value make_float32(float v) {
  Value r;
  r.u64 = 0;
  r.f32.val = v;
  return r;
}

inline Value make_ptr(uint64_t addr) {
  Value r;
  r.u64 = addr;
  return r;
}

inline Value make_undef(void) {
  Value r;
  r.u64 = 0;
  return r;
}

inline Value make_null(void) {
  Value r;
  r.u64 = 0;
  return r;
}

// ---------------------------------------------------------------------------
// ValueTraits — value lifecycle for templatized interpreter state.
// ---------------------------------------------------------------------------

template <typename ValueT>
struct ValueTraits {
  static ValueT default_value() { return ValueT{}; }
};

template <>
struct ValueTraits<Value> {
  static Value default_value() {
    Value v;
    v.u64 = 0;
    return v;
  }
};

}  // namespace mx::ir::interpret
