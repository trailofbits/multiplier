// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/StructureKinds.h>

#include "Impl.h"
#include "../Fragment.h"

namespace mx {
namespace {

// Helper: find a child structure of a given kind.
static std::optional<IRStructure> FindChild(
    const IRStructure &parent, ir::StructureKind kind) {
  for (auto child : parent.child_structures()) {
    if (child.kind() == kind) return child;
  }
  return std::nullopt;
}

}  // namespace

// ---------------------------------------------------------------------------
// from() implementations
// ---------------------------------------------------------------------------

std::optional<IRScopeStructure> IRScopeStructure::from(const IRStructure &s) {
  if (s.is_scope()) return IRScopeStructure(s.impl_ptr());
  return std::nullopt;
}

std::optional<IRIfStructure> IRIfStructure::from(const IRStructure &s) {
  if (s.kind() == ir::StructureKind::IF) return IRIfStructure(s.impl_ptr());
  return std::nullopt;
}

std::optional<IRIfThenStructure> IRIfThenStructure::from(const IRStructure &s) {
  if (s.kind() == ir::StructureKind::IF_THEN)
    return IRIfThenStructure(s.impl_ptr());
  return std::nullopt;
}

std::optional<IRIfElseStructure> IRIfElseStructure::from(const IRStructure &s) {
  if (s.kind() == ir::StructureKind::IF_ELSE)
    return IRIfElseStructure(s.impl_ptr());
  return std::nullopt;
}

std::optional<IRForStructure> IRForStructure::from(const IRStructure &s) {
  if (s.kind() == ir::StructureKind::FOR) return IRForStructure(s.impl_ptr());
  return std::nullopt;
}

std::optional<IRWhileStructure> IRWhileStructure::from(const IRStructure &s) {
  if (s.kind() == ir::StructureKind::WHILE)
    return IRWhileStructure(s.impl_ptr());
  return std::nullopt;
}

std::optional<IRDoWhileStructure> IRDoWhileStructure::from(
    const IRStructure &s) {
  if (s.kind() == ir::StructureKind::DO_WHILE)
    return IRDoWhileStructure(s.impl_ptr());
  return std::nullopt;
}

std::optional<IRSwitchStructure> IRSwitchStructure::from(
    const IRStructure &s) {
  if (s.kind() == ir::StructureKind::SWITCH)
    return IRSwitchStructure(s.impl_ptr());
  return std::nullopt;
}

std::optional<IRSwitchCaseStructure> IRSwitchCaseStructure::from(
    const IRStructure &s) {
  if (s.kind() == ir::StructureKind::SWITCH_CASE)
    return IRSwitchCaseStructure(s.impl_ptr());
  return std::nullopt;
}

// ---------------------------------------------------------------------------
// IRIfStructure
// ---------------------------------------------------------------------------

std::optional<IRStructure> IRIfStructure::then_branch(void) const {
  return FindChild(*this, ir::StructureKind::IF_THEN);
}

std::optional<IRStructure> IRIfStructure::else_branch(void) const {
  return FindChild(*this, ir::StructureKind::IF_ELSE);
}

// ---------------------------------------------------------------------------
// IRForStructure
// ---------------------------------------------------------------------------

std::optional<IRStructure> IRForStructure::init(void) const {
  return FindChild(*this, ir::StructureKind::FOR_INIT);
}

std::optional<IRStructure> IRForStructure::condition(void) const {
  return FindChild(*this, ir::StructureKind::FOR_CONDITION);
}

std::optional<IRStructure> IRForStructure::body(void) const {
  return FindChild(*this, ir::StructureKind::FOR_BODY);
}

std::optional<IRStructure> IRForStructure::increment(void) const {
  return FindChild(*this, ir::StructureKind::FOR_INCREMENT);
}

// ---------------------------------------------------------------------------
// IRWhileStructure
// ---------------------------------------------------------------------------

std::optional<IRStructure> IRWhileStructure::condition(void) const {
  return FindChild(*this, ir::StructureKind::WHILE_CONDITION);
}

std::optional<IRStructure> IRWhileStructure::body(void) const {
  return FindChild(*this, ir::StructureKind::WHILE_BODY);
}

// ---------------------------------------------------------------------------
// IRDoWhileStructure
// ---------------------------------------------------------------------------

std::optional<IRStructure> IRDoWhileStructure::body(void) const {
  return FindChild(*this, ir::StructureKind::DO_WHILE_BODY);
}

std::optional<IRStructure> IRDoWhileStructure::condition(void) const {
  return FindChild(*this, ir::StructureKind::DO_WHILE_CONDITION);
}

// ---------------------------------------------------------------------------
// IRSwitchStructure
// ---------------------------------------------------------------------------

gap::generator<IRSwitchCaseStructure>
IRSwitchStructure::cases(void) const & {
  for (auto child : child_structures()) {
    if (child.kind() == ir::StructureKind::SWITCH_CASE) {
      co_yield IRSwitchCaseStructure(child.impl_ptr());
    }
  }
}

std::optional<IRSwitchCaseStructure>
IRSwitchStructure::default_case(void) const {
  for (auto child : child_structures()) {
    if (child.kind() == ir::StructureKind::SWITCH_CASE) {
      IRSwitchCaseStructure sc(child.impl_ptr());
      if (sc.is_default()) return sc;
    }
  }
  return std::nullopt;
}

// ---------------------------------------------------------------------------
// IRSwitchCaseStructure
// ---------------------------------------------------------------------------

int64_t IRSwitchCaseStructure::low(void) const {
  if (!impl_ptr()) return 0;
  return impl_ptr()->reader().getCaseLow();
}

int64_t IRSwitchCaseStructure::high(void) const {
  if (!impl_ptr()) return 0;
  return impl_ptr()->reader().getCaseHigh();
}

bool IRSwitchCaseStructure::is_range(void) const {
  return low() != high();
}

bool IRSwitchCaseStructure::is_default(void) const {
  if (!impl_ptr()) return false;
  return impl_ptr()->reader().getIsDefault();
}

}  // namespace mx
