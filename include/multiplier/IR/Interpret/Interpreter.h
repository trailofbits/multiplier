// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../../Compiler.h"
#include "Value.h"
#include "Suspension.h"
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Function.h>
#include <multiplier/IR/Instruction.h>
#include <multiplier/Types.h>
#include <memory>
#include <unordered_map>
#include <vector>

namespace mx {
class IRObject;
class MemoryInst;
}  // namespace mx

namespace mx::ir::interpret {

class Driver;
class Memory;
class ValueFactory;

// ---------------------------------------------------------------------------
// StepResult — what Step() returns
// ---------------------------------------------------------------------------

enum class StepStatus {
  CONTINUE,    // More instructions to execute.
  SUSPENDED,   // Needs external resolution before resuming.
  COMPLETED,   // Top-level function returned normally.
  ERROR,       // Unrecoverable error (unreachable, etc.).
};

struct StepResult {
  StepStatus status{StepStatus::ERROR};
  Suspension suspension;  // Valid when status == SUSPENDED.
  Value return_value;     // Valid when status == COMPLETED.
};

// ---------------------------------------------------------------------------
// CallFrame — per-function-invocation state
// ---------------------------------------------------------------------------

struct CallFrame {
  IRFunction func;
  std::vector<Value> params;
  std::vector<Value> param_ptrs;
  Value return_ptr{Undefined{}};

  // Index into param_ptrs where variadic arguments begin.
  uint32_t variadic_start_index{0};

  // Instruction ID → computed value.
  std::unordered_map<RawEntityId, Value> values;

  // Entity ID → allocated address in Memory.
  std::unordered_map<RawEntityId, uint64_t> entity_to_address;

  // Block ID → IRBlock (for CFG navigation).
  std::unordered_map<RawEntityId, IRBlock> block_map;

  // Current execution position.
  IRBlock current_block;

  // When a CALL pushes a callee frame, this records the CALL instruction's
  // entity ID so that after the callee returns, we can resume from the
  // instruction after the CALL and store the return value.
  RawEntityId resume_after_inst{kInvalidEntityId};
};

// ---------------------------------------------------------------------------
// InterpreterState — everything needed to resume execution
// ---------------------------------------------------------------------------

struct MX_EXPORT InterpreterState {
  std::vector<CallFrame> call_stack;

  // Global variable addresses: entity ID → allocated address.
  std::unordered_map<RawEntityId, uint64_t> global_addresses;

  // Instruction step counter.
  uint64_t steps{0};

  // Current frame (convenience).
  CallFrame &Frame(void) { return call_stack.back(); }
  const CallFrame &Frame(void) const { return call_stack.back(); }
  bool Empty(void) const { return call_stack.empty(); }
};

// ---------------------------------------------------------------------------
// Free functions — the interpreter is a state transition function
// ---------------------------------------------------------------------------

// Initialize state for executing a function with the given arguments.
MX_EXPORT void InitState(InterpreterState &state, Memory &memory,
                         const IRFunction &func, const std::vector<Value> &args);

// Execute one block. Advances state in place.
// The caller (driver) owns the loop and handles suspensions.
MX_EXPORT StepResult Step(InterpreterState &state, Memory &memory,
                          ValueFactory &factory, Driver &driver);

}  // namespace mx::ir::interpret
