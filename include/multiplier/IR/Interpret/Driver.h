// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Suspension.h"
#include "Value.h"

namespace mx::ir::interpret {

// The Driver resolves suspensions from the interpreter.
// Subclass to implement analysis-specific policies.
//
// ConcreteDriver: resolves everything concretely, aborts on symbolic.
// TaintDriver: tracks provenance, surfaces decisions to an agent.
// GuidedDriver: target-directed exploration with coverage coordination.
class Driver {
 public:
  virtual ~Driver(void) = default;

  // Resolve a conditional branch with unknown condition.
  virtual BranchResolution ResolveBranch(const BranchSuspension &s) = 0;

  // Resolve a function call.
  virtual CallResolution ResolveCall(const CallSuspension &s) = 0;

  // Resolve a load from a symbolic/unknown address.
  virtual LoadResolution ResolveLoad(const LoadSuspension &s) = 0;

  // Resolve a store to a symbolic/unknown address.
  virtual StoreResolution ResolveStore(const StoreSuspension &s) = 0;

  // Concretize a symbolic value.
  virtual ConcretizeResolution ResolveConcretize(
      const ConcretizeSuspension &s) = 0;
};

// Checker interface: plugged into the interpreter for memory safety checks.
// Multiple checkers can be registered; all fire on each relevant event.
class Checker {
 public:
  virtual ~Checker(void) = default;

  // Called before every memory access.
  virtual void OnMemoryAccess(const Pointer &addr, uint32_t size,
                              bool is_write) {}

  // Called after pointer arithmetic.
  virtual void OnPointerArithmetic(const Pointer &base, int64_t offset_bytes,
                                   const Pointer &result) {}

  // Called on function entry.
  virtual void OnCallEntry(const CallSuspension &call) {}

  // Called on function return.
  virtual void OnCallReturn(const Value &return_value) {}
};

}  // namespace mx::ir::interpret
