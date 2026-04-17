// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../Compiler.h"
#include "../Types.h"
#include "ObjectKind.h"
#include <memory>
#include <optional>

namespace mx {

class VarDecl;
class Type;
class IRObjectImpl;
using IRObjectImplPtr = std::shared_ptr<const IRObjectImpl>;

class MX_EXPORT IRObject {
 private:
  friend class EntityProvider;
  friend class Index;
  friend class IRFunction;
  friend class IRInstruction;
  IRObjectImplPtr impl;

 public:
  IRObject(void) = default;
  explicit IRObject(IRObjectImplPtr impl_)
      : impl(std::move(impl_)) {}

  EntityId id(void) const;
  ir::ObjectKind kind(void) const;

  std::optional<VarDecl> source_declaration(void) const;
  std::optional<Type> type(void) const;
  uint32_t size_bytes(void) const;
  uint32_t align_bytes(void) const;
  uint32_t frame_offset(void) const;  // Offset within the function's stack frame.
  bool needs_memory(void) const;

};

}  // namespace mx
