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
  uint8_t width{0};  // 1, 2, 4, or 8 bytes

  static ScalarValue FromU64(uint64_t v, uint8_t w = 8) {
    return {v, w};
  }

  static ScalarValue FromI64(int64_t v, uint8_t w = 8) {
    uint64_t bits;
    std::memcpy(&bits, &v, sizeof(bits));
    return {bits, w};
  }

  static ScalarValue FromF64(double v) {
    uint64_t bits;
    std::memcpy(&bits, &v, sizeof(bits));
    return {bits, 8};
  }

  static ScalarValue FromF32(float v) {
    uint32_t bits;
    std::memcpy(&bits, &v, sizeof(bits));
    return {bits, 4};
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

// Sentinel for a null pointer.
struct NullPtr {};

// An opaque pointer into the interpreter's virtual address space.
// Address width (4 or 8 bytes) is a session property on Memory, not per-pointer.
// Policies access the concrete address via the free functions below.
struct Pointer {
 private:
  uint64_t address_{0};

 public:
  Pointer(void) = default;
  explicit Pointer(uint64_t addr) : address_(addr) {}

  bool operator==(const Pointer &o) const { return address_ == o.address_; }
  bool operator!=(const Pointer &o) const { return address_ != o.address_; }

  friend bool IsConcrete(const Pointer &p);
  friend uint64_t ConcreteAddress(const Pointer &p);
};

// For the concrete interpreter, all pointers are concrete.
// A future symbolic pointer variant would make this non-trivial.
inline bool IsConcrete(const Pointer &) { return true; }

// Extract the concrete integral address. Only valid when IsConcrete() is true.
inline uint64_t ConcreteAddress(const Pointer &p) { return p.address_; }

// The value type the interpreter passes around.
// Concrete implementation. A symbolic layer would extend/wrap this.
using Value = std::variant<ScalarValue, Pointer, NullPtr, Undefined>;

// ---------------------------------------------------------------------------
// Inline helper functions
// ---------------------------------------------------------------------------

// Extract as signed integer. Returns 0 for non-scalar values.
inline int64_t AsInt(const Value &v) {
  if (auto *s = std::get_if<ScalarValue>(&v)) return s->as_i64();
  return 0;
}

// Extract as unsigned integer. Returns 0 for non-scalar values.
inline uint64_t AsUint(const Value &v) {
  if (auto *s = std::get_if<ScalarValue>(&v)) return s->as_u64();
  return 0;
}

// Extract as double. Returns 0.0 for non-scalar values.
inline double AsFloat(const Value &v) {
  if (auto *s = std::get_if<ScalarValue>(&v)) return s->as_f64();
  return 0.0;
}

// Extract as float. Returns 0.0f for non-scalar values.
inline float AsFloat32(const Value &v) {
  if (auto *s = std::get_if<ScalarValue>(&v)) return s->as_f32();
  return 0.0f;
}

// Returns pointer if the value holds one, nullptr otherwise.
inline const Pointer *AsPointer(const Value &v) {
  return std::get_if<Pointer>(&v);
}

// Truth test for concrete values.
inline bool IsTruthy(const Value &v) {
  if (auto *s = std::get_if<ScalarValue>(&v)) return s->bits != 0;
  if (std::holds_alternative<Pointer>(v)) return true;
  if (std::holds_alternative<NullPtr>(v)) return false;
  return false;  // Undefined
}

// Check if the value is undefined/poison.
inline bool IsUndefined(const Value &v) {
  return std::holds_alternative<Undefined>(v);
}

// Check if the value is a null pointer.
inline bool IsNull(const Value &v) {
  return std::holds_alternative<NullPtr>(v);
}

// --- Construction helpers ---

inline Value MakeInt(int64_t v, uint8_t w = 8) {
  return ScalarValue::FromI64(v, w);
}

inline Value MakeUint(uint64_t v, uint8_t w = 8) {
  return ScalarValue::FromU64(v, w);
}

inline Value MakeFloat(double v) {
  return ScalarValue::FromF64(v);
}

inline Value MakeFloat32(float v) {
  return ScalarValue::FromF32(v);
}

inline Value MakePtr(uint64_t addr) {
  return Pointer(addr);
}

inline Value MakeUndef(void) {
  return Undefined{};
}

inline Value MakeNull(void) {
  return NullPtr{};
}

}  // namespace mx::ir::interpret
