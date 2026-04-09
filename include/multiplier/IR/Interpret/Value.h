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

// A pointer into the interpreter's address space.
struct Pointer {
  uint32_t object_id{0};
  int64_t offset{0};
};

// The value type the interpreter passes around.
// Concrete implementation. A symbolic layer would extend/wrap this.
using Value = std::variant<ScalarValue, Pointer, NullPtr, Undefined>;

}  // namespace mx::ir::interpret
