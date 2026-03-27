// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>

namespace mx::ir {

// Classification of IR memory objects.
enum class ObjectKind : uint8_t {
  LOCAL = 0,              // address-taken local variable (needs alloca/load/store)
  LOCAL_VALUE = 1,        // non-address-taken local (pure value, can be SSA)
  PARAMETER = 2,          // address-taken function parameter
  PARAMETER_VALUE = 3,    // non-address-taken parameter (pure value)
  GLOBAL = 4,             // global variable
  THREAD_LOCAL = 5,       // thread-local variable
  STRING_LITERAL = 6,     // string literal storage
  COMPOUND_LITERAL = 7,   // compound literal storage
  RETURN_SLOT = 8,        // implicit return value storage
  ALLOCA = 9,             // dynamic alloca (VLA, etc.)
  HEAP = 10,              // dynamically allocated (malloc, etc.)
};

inline static const char *EnumerationName(ObjectKind) {
  return "ObjectKind";
}

const char *EnumeratorName(ObjectKind kind) noexcept;

inline static constexpr unsigned NumEnumerators(ObjectKind) {
  return 11u;
}

// Is this an address-taken object that needs memory operations?
inline bool NeedsMemory(ObjectKind kind) {
  switch (kind) {
    case ObjectKind::LOCAL:
    case ObjectKind::PARAMETER:
    case ObjectKind::GLOBAL:
    case ObjectKind::THREAD_LOCAL:
    case ObjectKind::STRING_LITERAL:
    case ObjectKind::COMPOUND_LITERAL:
    case ObjectKind::RETURN_SLOT:
    case ObjectKind::ALLOCA:
    case ObjectKind::HEAP:
      return true;
    case ObjectKind::LOCAL_VALUE:
    case ObjectKind::PARAMETER_VALUE:
      return false;
  }
  return true;
}

}  // namespace mx::ir
