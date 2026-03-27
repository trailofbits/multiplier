// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../Compiler.h"
#include "../Types.h"
#include <memory>

namespace mx {

class IRObjectImpl;
using IRObjectImplPtr = std::shared_ptr<const IRObjectImpl>;

class MX_EXPORT IRObject {
 private:
  friend class EntityProvider;
  friend class Index;
  IRObjectImplPtr impl;

 public:
  IRObject(void) = default;
  explicit IRObject(IRObjectImplPtr impl_)
      : impl(std::move(impl_)) {}

  EntityId id(void) const { return EntityId(); }  // TODO
};

}  // namespace mx
