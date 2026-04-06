// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../Compiler.h"
#include "../Types.h"
#include <memory>
#include <optional>

namespace mx {

class IRBlock;
class IRSwitchCaseImpl;
class Stmt;
class Type;
using IRSwitchCaseImplPtr = std::shared_ptr<const IRSwitchCaseImpl>;

class MX_EXPORT IRSwitchCase {
 protected:
  friend class EntityProvider;
  friend class Index;
  friend class IRInstruction;
  IRSwitchCaseImplPtr impl;

 public:
  IRSwitchCase(void) = default;
  explicit IRSwitchCase(IRSwitchCaseImplPtr impl_)
      : impl(std::move(impl_)) {}

  EntityId id(void) const;

  // Case value range. For normal cases, low() == high().
  // For GNU range cases (case 1...5), low() < high().
  int64_t low(void) const;
  int64_t high(void) const;
  bool is_range(void) const;
  bool is_default(void) const;

  // The target block for this case.
  IRBlock target_block(void) const;

  // The integral type of the case values.
  std::optional<Type> value_type(void) const;

  // AST provenance: the CaseStmt or DefaultStmt.
  std::optional<Stmt> source_statement(void) const;
};

}  // namespace mx
