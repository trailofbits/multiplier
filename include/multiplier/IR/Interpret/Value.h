// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <cstring>
#include <variant>

namespace mx::ir::interpret {

// A concrete scalar value: up to 8 bytes, type-punnable.
// The interpreter moves bytes around; the ValueFactory gives them meaning.
struct ScalarValue {
  uint64_t bits{0};
  uint8_t width{0};    // 1, 2, 4, or 8 bytes
  bool is_float{false}; // true if this holds a float/double

  static ScalarValue from_u64(uint64_t v, uint8_t w = 8) {
    return {v, w, false};
  }

  static ScalarValue from_i64(int64_t v, uint8_t w = 8) {
    uint64_t bits;
    std::memcpy(&bits, &v, sizeof(bits));
    return {bits, w, false};
  }

  static ScalarValue from_f64(double v) {
    uint64_t bits;
    std::memcpy(&bits, &v, sizeof(bits));
    return {bits, 8, true};
  }

  static ScalarValue from_f32(float v) {
    uint32_t bits;
    std::memcpy(&bits, &v, sizeof(bits));
    return {bits, 4, true};
  }

  int64_t as_i64(void) const {
    int64_t v;
    std::memcpy(&v, &bits, sizeof(v));
    return v;
  }

  uint64_t as_u64(void) const {
    return bits;
  }

  double as_f64(void) const {
    double v;
    std::memcpy(&v, &bits, sizeof(v));
    return v;
  }

  float as_f32(void) const {
    uint32_t lo = static_cast<uint32_t>(bits);
    float v;
    std::memcpy(&v, &lo, sizeof(v));
    return v;
  }
};

// Sentinel for undefined/poison values.
struct Undefined {};

// An opaque pointer into the interpreter's virtual address space.
// Pointer(0) is the null pointer.
struct Pointer {
 private:
  uint64_t address_{0};

 public:
  Pointer(void) = default;
  explicit Pointer(uint64_t addr) : address_(addr) {}

  bool operator==(const Pointer &o) const { return address_ == o.address_; }
  bool operator!=(const Pointer &o) const { return address_ != o.address_; }

  friend bool is_concrete(const Pointer &p);
  friend uint64_t concrete_address(const Pointer &p);
};

inline bool is_concrete(const Pointer &) { return true; }
inline uint64_t concrete_address(const Pointer &p) { return p.address_; }

// The value type the concrete interpreter passes around.
using Value = std::variant<ScalarValue, Pointer, Undefined>;

// ---------------------------------------------------------------------------
// Inline helper functions
// ---------------------------------------------------------------------------

inline int64_t as_int(const Value &v) {
  if (auto *s = std::get_if<ScalarValue>(&v)) return s->as_i64();
  return 0;
}

inline uint64_t as_uint(const Value &v) {
  if (auto *s = std::get_if<ScalarValue>(&v)) return s->as_u64();
  return 0;
}

inline double as_float(const Value &v) {
  if (auto *s = std::get_if<ScalarValue>(&v)) {
    if (s->width == 4) return static_cast<double>(s->as_f32());
    return s->as_f64();
  }
  return 0.0;
}

inline float as_float32(const Value &v) {
  if (auto *s = std::get_if<ScalarValue>(&v)) {
    // If the value is an f64 holding a double, narrow through double→float
    // instead of reading the wrong low-32 bits of the f64 representation.
    if (s->is_float && s->width == 8)
      return static_cast<float>(s->as_f64());
    return s->as_f32();
  }
  return 0.0f;
}

inline const Pointer *as_pointer(const Value &v) {
  return std::get_if<Pointer>(&v);
}

inline bool is_truthy(const Value &v) {
  if (auto *s = std::get_if<ScalarValue>(&v)) return s->bits != 0;
  if (auto *p = std::get_if<Pointer>(&v)) return concrete_address(*p) != 0;
  return false;  // Undefined
}

inline bool is_undefined(const Value &v) {
  return std::holds_alternative<Undefined>(v);
}

inline bool is_null(const Value &v) {
  if (auto *p = std::get_if<Pointer>(&v)) return concrete_address(*p) == 0;
  return false;
}

// --- Construction helpers ---

inline Value make_int(int64_t v, uint8_t w = 8) {
  return ScalarValue::from_i64(v, w);
}

inline Value make_uint(uint64_t v, uint8_t w = 8) {
  return ScalarValue::from_u64(v, w);
}

inline Value make_float(double v) {
  return ScalarValue::from_f64(v);
}

inline Value make_float32(float v) {
  return ScalarValue::from_f32(v);
}

inline Value make_ptr(uint64_t addr) {
  return Pointer(addr);
}

inline Value make_undef(void) {
  return Undefined{};
}

inline Value make_null(void) {
  return Pointer(0);
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
  static Value default_value() { return Undefined{}; }
};

}  // namespace mx::ir::interpret
