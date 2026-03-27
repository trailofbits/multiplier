// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

namespace mx {

// Stub Impl classes for IR entities. These will be fleshed out when
// the read-side API is implemented.

class IRFunctionImpl {
 public:
  virtual ~IRFunctionImpl(void) = default;
};

class IRBlockImpl {
 public:
  virtual ~IRBlockImpl(void) = default;
};

class IRInstructionImpl {
 public:
  virtual ~IRInstructionImpl(void) = default;
};

class IRObjectImpl {
 public:
  virtual ~IRObjectImpl(void) = default;
};

}  // namespace mx
