// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Structure.h"
#include "StructureKind.h"
#include "Block.h"

namespace mx {

class Type;

// Helper macro for derived structure classes.
#define MX_DECLARE_IR_STRUCTURE(ClassName) \
  explicit ClassName(IRStructureImplPtr impl_) \
      : IRStructure(std::move(impl_)) {} \
  static std::optional<ClassName> from(const IRStructure &s);

// ---------------------------------------------------------------------------
// Scopes
// ---------------------------------------------------------------------------

// FUNCTION_SCOPE or SCOPE. Tracks variable lifetimes.
class MX_EXPORT IRScopeStructure : public IRStructure {
 public:
  MX_DECLARE_IR_STRUCTURE(IRScopeStructure)
  // objects() is inherited from IRStructure.
};

// ---------------------------------------------------------------------------
// If statement
// ---------------------------------------------------------------------------

class MX_EXPORT IRIfStructure : public IRStructure {
 public:
  MX_DECLARE_IR_STRUCTURE(IRIfStructure)
  std::optional<IRStructure> then_branch(void) const;
  std::optional<IRStructure> else_branch(void) const;
};

class MX_EXPORT IRIfThenStructure : public IRStructure {
 public:
  MX_DECLARE_IR_STRUCTURE(IRIfThenStructure)
};

class MX_EXPORT IRIfElseStructure : public IRStructure {
 public:
  MX_DECLARE_IR_STRUCTURE(IRIfElseStructure)
};

// ---------------------------------------------------------------------------
// For loop
// ---------------------------------------------------------------------------

class MX_EXPORT IRForStructure : public IRStructure {
 public:
  MX_DECLARE_IR_STRUCTURE(IRForStructure)
  std::optional<IRStructure> init(void) const;
  std::optional<IRStructure> condition(void) const;
  std::optional<IRStructure> body(void) const;
  std::optional<IRStructure> increment(void) const;
};

// ---------------------------------------------------------------------------
// While loop
// ---------------------------------------------------------------------------

class MX_EXPORT IRWhileStructure : public IRStructure {
 public:
  MX_DECLARE_IR_STRUCTURE(IRWhileStructure)
  std::optional<IRStructure> condition(void) const;
  std::optional<IRStructure> body(void) const;
};

// ---------------------------------------------------------------------------
// Do-while loop
// ---------------------------------------------------------------------------

class MX_EXPORT IRDoWhileStructure : public IRStructure {
 public:
  MX_DECLARE_IR_STRUCTURE(IRDoWhileStructure)
  std::optional<IRStructure> body(void) const;
  std::optional<IRStructure> condition(void) const;
};

// ---------------------------------------------------------------------------
// Switch statement
// ---------------------------------------------------------------------------

class IRSwitchCaseStructure;

class MX_EXPORT IRSwitchStructure : public IRStructure {
 public:
  MX_DECLARE_IR_STRUCTURE(IRSwitchStructure)
  gap::generator<IRSwitchCaseStructure> cases(void) const &;
  std::optional<IRSwitchCaseStructure> default_case(void) const;
};

class MX_EXPORT IRSwitchCaseStructure : public IRStructure {
 public:
  MX_DECLARE_IR_STRUCTURE(IRSwitchCaseStructure)
  int64_t low(void) const;
  int64_t high(void) const;
  bool is_range(void) const;
  bool is_default(void) const;

  // The target block for this case (first child block).
  IRBlock target_block(void) const;
};

}  // namespace mx
