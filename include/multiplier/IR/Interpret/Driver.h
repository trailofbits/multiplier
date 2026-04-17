// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Suspension.h"

namespace mx::ir::interpret {

// The Driver resolves suspensions from the interpreter.
//
// In the new architecture, the driver CALLS Step() in a loop and handles
// suspensions. This base class provides a convenient Resolve() dispatch
// that maps each suspension type to a resolution. Subclass to implement
// analysis-specific policies.
class Driver {
 public:
  virtual ~Driver(void) = default;

  // Resolve a suspension. Returns the resolution to resume with.
  virtual Resolution Resolve(const Suspension &s) = 0;
};

}  // namespace mx::ir::interpret
