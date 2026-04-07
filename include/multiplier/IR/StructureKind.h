// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>

namespace mx::ir {

// Structural entities in the IR hierarchy. These represent the nesting
// structure of the program: scopes, control flow regions, etc.
// Every block has a parent structure, and structures form a tree rooted
// at the function's FUNCTION_SCOPE.
enum class StructureKind : uint8_t {
  // Scopes (lexical blocks with variable lifetimes).
  FUNCTION_SCOPE = 0,    // function body CompoundStmt
  SCOPE = 1,             // nested CompoundStmt

  // If statement parts.
  IF = 2,                // the whole if statement
  IF_THEN = 3,           // then branch
  IF_ELSE = 4,           // else branch

  // For loop parts.
  FOR = 5,               // the whole for loop
  FOR_INIT = 6,          // for(init; ...)
  FOR_CONDITION = 7,     // for(...; cond; ...)
  FOR_BODY = 8,          // loop body
  FOR_INCREMENT = 9,     // for(...; ...; inc)

  // While loop parts.
  WHILE = 10,            // the whole while loop
  WHILE_CONDITION = 11,
  WHILE_BODY = 12,

  // Do-while loop parts.
  DO_WHILE = 13,         // the whole do-while
  DO_WHILE_BODY = 14,
  DO_WHILE_CONDITION = 15,

  // Switch statement parts.
  SWITCH = 16,           // the whole switch
  SWITCH_CASE = 17,      // individual case/default
};

inline static const char *EnumerationName(StructureKind) {
  return "StructureKind";
}

const char *EnumeratorName(StructureKind kind) noexcept;

inline static constexpr unsigned NumEnumerators(StructureKind) {
  return 18u;
}

// Classification helpers.
inline bool IsScope(StructureKind kind) {
  return kind == StructureKind::FUNCTION_SCOPE ||
         kind == StructureKind::SCOPE;
}

}  // namespace mx::ir
