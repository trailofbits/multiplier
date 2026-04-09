// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include "../Compiler.h"

namespace mx::ir {

// Structural role of a basic block in the control flow graph.
enum class BlockKind : uint8_t {
  // Function prologue/entry.
  FRAME = 0,            // Contains all ALLOCAs (parameters + locals).
  ENTRY = 1,            // Logical entry: ENTER_SCOPE, PARAM_READs, body start.

  // If-statement.
  IF_THEN = 2,
  IF_ELSE = 3,
  IF_MERGE = 4,

  // Loops (while, do-while, for).
  LOOP_PREHEADER = 5,   // Single-entry block before loop condition.
  LOOP_CONDITION = 6,
  LOOP_BODY = 7,
  LOOP_EXIT = 8,
  LOOP_INCREMENT = 9,   // For-loop increment.

  // Switch-statement.
  SWITCH_CASE = 10,
  SWITCH_DEFAULT = 11,
  SWITCH_EXIT = 12,

  // Labels and control flow.
  LABEL = 13,           // User-defined goto target.
  COMPENSATION = 14,    // Scope transition block on goto edges.

  // Other.
  UNREACHABLE = 15,     // Dead code after a terminator.
  GENERIC = 16,         // Unclassified.
};

inline static const char *EnumerationName(BlockKind) {
  return "BlockKind";
}

MX_EXPORT const char *EnumeratorName(BlockKind kind) noexcept;

inline static constexpr unsigned NumEnumerators(BlockKind) {
  return 17u;
}

}  // namespace mx::ir
