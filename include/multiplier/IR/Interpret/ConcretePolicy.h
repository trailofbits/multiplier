// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../../Compiler.h"
#include "ConcreteMemory.h"
#include "ConcreteOps.h"
#include "Policy.h"

#include <multiplier/IR/Function.h>
#include <multiplier/IR/Instruction.h>
#include <multiplier/Types.h>

#include <functional>
#include <optional>

namespace mx::ir::interpret {

// Function resolver: given an entity ID, return its IRFunction.
using FunctionResolver =
    std::function<std::optional<IRFunction>(RawEntityId)>;

// Global resolver: given a global variable's entity ID, return its info.
using GlobalResolver =
    std::function<std::optional<GlobalInfo>(RawEntityId)>;

// Concrete policy: all operations are direct computation, no symbolic
// reasoning, no forking. Uses NoOpScheduler (compiles to nothing).
//
// Takes a ConcreteMemory by reference (not owned). The memory is separate
// because it has forkable state and is reusable across policies.
//
// Value factory methods (arithmetic, casts, comparisons, intrinsics)
// are implemented directly here — they are stateless pure functions
// and don't need a separate class.
class MX_EXPORT ConcretePolicy
    : public Policy<ConcretePolicy> {
 public:
  explicit ConcretePolicy(ConcreteMemory &memory,
                          FunctionResolver func_resolver = {},
                          GlobalResolver global_resolver = {});

  ConcreteMemory &memory(void) { return memory_; }
  const ConcreteMemory &memory(void) const { return memory_; }

  // --- 0. Value extraction / construction (interpreter bookkeeping) ---
  std::optional<uint64_t> extract_address(const Value &val);
  int64_t extract_int(const Value &val);
  uint64_t extract_uint(const Value &val);
  Value make_literal_int(int64_t v, uint8_t width = 8);
  Value make_literal_ptr(uint64_t addr);
  Value make_default();
  bool has_address(const Value &val);

  // --- 1. Value construction ---
  Value make_const(ConstOp op, int64_t signed_val, uint64_t unsigned_val);
  Value make_null_ptr(void);

  // --- 2. Arithmetic / logic ---
  Value binary_op(OpCode op, const Value &lhs, const Value &rhs);
  Value unary_op(OpCode op, const Value &operand);
  Value compare(OpCode op, const Value &lhs, const Value &rhs);
  Value cast(CastOp op, const Value &operand);
  Value ptr_add(const Value &base, const Value &index,
                int64_t element_size);
  Value ptr_diff(const Value &lhs, const Value &rhs,
                 int64_t element_size);
  Value ptr_offset(const Value &base, int64_t byte_offset);
  Value select(const Value &cond, const Value &if_true,
               const Value &if_false);
  Value bitwise_intrinsic(OpCode width_op, BitwiseOp sub,
                          const Value &val, const Value &val2);
  Value float_intrinsic(FloatOp sub,
                        const std::vector<Value> &operands);

  // --- 3. Truth test ---
  std::optional<bool> is_true(const Value &val);

  // --- 4. Memory ---
  //
  // Memory operations are scheduler-agnostic: ConcretePolicy never emits
  // continuations from these calls (concrete addresses are always
  // resolvable inline). The `Sched` parameter is templated so the same
  // policy works under any scheduler the loop instantiates against.
  template <typename Sched>
  Value mem_allocate(Sched &, uint64_t size_bytes, uint64_t align_bytes) {
    return make_ptr(memory_.allocate(size_bytes, align_bytes));
  }

  template <typename Sched>
  void mem_free(Sched &, const Value &address) {
    if (address.u64 != 0) {
      memory_.free(address.u64);
    }
  }

  template <typename Sched>
  bool mem_read(Sched &, const Value &addr, const MemAccessHint &hint,
                Value &result) {
    if (addr.u64 == 0) {
      result = make_undef();
      return true;
    }
    result = concrete_read_from_mem(memory_, addr.u64,
                                    hint.size_bytes, hint.is_float);
    return true;
  }

  template <typename Sched>
  bool mem_write(Sched &, const Value &addr, const Value &val,
                 const MemAccessHint &hint) {
    if (addr.u64 == 0) return true;
    concrete_write_to_mem(memory_, addr.u64, val,
                          hint.size_bytes, hint.is_float);
    return true;
  }

  template <typename Sched>
  bool mem_bulk_op(Sched &, MemOp sub,
                   const std::vector<Value> &ops,
                   const MemoryInst &mi, Value &result) {
    return concrete_mem_bulk_op(memory_, sub, ops, mi, result);
  }

  void mem_poison(const Value &addr);
  void mem_unpoison(const Value &addr);
  bool is_undefined(const Value &val);

  // --- 4b. Block entry notification ---
  // Phase 8d: invoked at the top of every block entry. The default is
  // a no-op; the symbolic interpreter overrides this to fan a
  // BLOCK_ENTER event out to Python observers / the path's event log.
  template <typename StateT>
  void on_enter_block(StateT &, const IRBlock &) {}

  // --- 5. Resolution ---
  template <typename Sched>
  bool resolve_branch(Sched &, const Value &,
                      IRBlock true_block, IRBlock /*false_block*/,
                      IRBlock &chosen_block) {
    chosen_block = true_block;
    return true;
  }

  template <typename Sched>
  bool resolve_call(Sched &, const IRInstruction &,
                    RawEntityId target_eid,
                    RawEntityId indirect_target_eid,
                    const std::vector<Value> &,
                    bool, CallResolution<Value> &resolution) {
    if (func_resolver_) {
      for (auto eid : {target_eid, indirect_target_eid}) {
        if (eid != kInvalidEntityId) {
          if (auto ir = func_resolver_(eid)) {
            resolution.action = CallAction::INLINE;
            resolution.return_value = make_undef();
            resolution.callee_ir = *std::move(ir);
            return true;
          }
        }
      }
    }
    resolution.action = CallAction::SKIP;
    resolution.return_value = make_undef();
    return true;
  }

  template <typename Sched>
  bool resolve_global(Sched &, RawEntityId entity_id,
                      GlobalResolution &resolution) {
    if (global_resolver_) {
      if (auto info = global_resolver_(entity_id)) {
        resolution = GlobalResolution{.info = *std::move(info)};
        return true;
      }
    }
    resolution = GlobalResolution{};
    return true;
  }

 private:
  ConcreteMemory &memory_;
  FunctionResolver func_resolver_;
  GlobalResolver global_resolver_;
};

}  // namespace mx::ir::interpret
