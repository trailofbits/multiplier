// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>

namespace mx::ir {

// Structural role of a basic block in the control flow graph.
enum class BlockKind : uint8_t {
  // Function entry point.
  ENTRY = 0,

  // If-statement related.
  IF_THEN = 1,
  IF_ELSE = 2,
  IF_MERGE = 3,

  // Loop condition/body/exit (while, do-while, for).
  LOOP_CONDITION = 4,
  LOOP_BODY = 5,
  LOOP_EXIT = 6,
  LOOP_INCREMENT = 7,   // for-loop increment

  // Switch-statement related.
  SWITCH_CASE = 8,
  SWITCH_DEFAULT = 9,
  SWITCH_EXIT = 10,

  // User-defined label (goto target).
  LABEL = 11,

  // Dead code after a terminator (break/continue/goto/return).
  UNREACHABLE = 12,

  // Generic / unclassified.
  GENERIC = 13,
};

const char *EnumeratorName(BlockKind kind) noexcept;

inline static constexpr unsigned NumEnumerators(BlockKind) {
  return 14u;
}

}  // namespace mx::ir
