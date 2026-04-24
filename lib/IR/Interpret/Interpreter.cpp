// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.
//
// Concrete interpreter: delegates to the templatized loop in InterpreterLoop.h.
// Also contains Continuation factory methods and pump() (concrete-only).

#include <multiplier/IR/Interpret/Interpreter.h>
#include <multiplier/IR/Interpret/InterpreterLoop.h>
#include <multiplier/IR/Interpret/ConcretePolicy.h>
#include <multiplier/IR/Interpret/Policy.h>

namespace mx::ir::interpret {

// ===========================================================================
// ConcretePolicy methods — delegate to free template functions
// ===========================================================================

void ConcretePolicy::init_state(InterpreterState<Value> &state,
                                const IRFunction &func,
                                const std::vector<Value> &args) {
  NoOpScheduler sched;
  interp_init_state<ConcretePolicy, NoOpScheduler, Value>(
      *this, sched, state, func, args);
}

bool ConcretePolicy::step(InterpreterState<Value> &state, NoOpScheduler &sched,
                          uint64_t max_steps) {
  return interp_step<ConcretePolicy, NoOpScheduler, Value>(
      *this, sched, state, max_steps);
}

// ===========================================================================
// Continuation factory methods + pump
// ===========================================================================

Continuation Continuation::branch(std::shared_ptr<InterpreterState<Value>> snapshot,
                                  NeedBranchDecision info) {
  Continuation c(BRANCH, std::move(snapshot));
  c.data_ = BranchData{std::move(info)};
  return c;
}

Continuation Continuation::call(std::shared_ptr<InterpreterState<Value>> snapshot,
                                NeedCallResolution info,
                                RawEntityId instruction_id) {
  Continuation c(CALL, std::move(snapshot));
  c.data_ = CallData{std::move(info), instruction_id};
  return c;
}

Continuation Continuation::global(std::shared_ptr<InterpreterState<Value>> snapshot,
                                  NeedGlobalResolution info,
                                  RawEntityId instruction_id) {
  Continuation c(GLOBAL, std::move(snapshot));
  c.data_ = GlobalData{std::move(info), instruction_id};
  return c;
}

Continuation Continuation::completed(Value return_value,
                                     std::shared_ptr<InterpreterState<Value>> snapshot) {
  Continuation c(COMPLETED, std::move(snapshot));
  c.data_ = CompletedData{std::move(return_value)};
  return c;
}

Continuation Continuation::errored(ErrorKind kind,
                                   std::shared_ptr<InterpreterState<Value>> snapshot) {
  Continuation c(ERRORED, std::move(snapshot));
  c.data_ = ErroredData{kind};
  return c;
}

const NeedBranchDecision &Continuation::as_branch(void) const {
  return std::get<BranchData>(data_).info;
}

const NeedCallResolution &Continuation::as_call(void) const {
  return std::get<CallData>(data_).info;
}

const NeedGlobalResolution &Continuation::as_global(void) const {
  return std::get<GlobalData>(data_).info;
}

const Value &Continuation::return_value(void) const {
  return std::get<CompletedData>(data_).return_value;
}

ErrorKind Continuation::error(void) const {
  return std::get<ErroredData>(data_).kind;
}

InterpreterState<Value> Continuation::pump(ConcretePolicy &policy,
                                    const Resolution &resolution) const {
  auto state = *snapshot_;

  switch (kind_) {
    case BRANCH: {
      auto *bd = std::get_if<BranchDecision>(&resolution);
      if (!bd) break;
      auto &info = std::get<BranchData>(data_).info;
      auto target = bd->take_true ? info.true_block : info.false_block;
      enter_block<Value>(state, target);
      break;
    }
    case CALL: {
      auto *cr = std::get_if<CallResolution>(&resolution);
      if (!cr) break;
      auto &cd = std::get<CallData>(data_);
      switch (cr->action) {
        case CallAction::SKIP:
        case CallAction::MODEL:
          state.call_stack.top().values[cd.instruction_id] = cr->return_value;
          break;
        case CallAction::INLINE:
          // TODO: push callee frame + ENTER_BLOCK
          break;
      }
      break;
    }
    case GLOBAL: {
      auto *gr = std::get_if<GlobalResolution>(&resolution);
      if (!gr || gr->info.size == 0) break;
      auto &gd = std::get<GlobalData>(data_);
      auto &info = gr->info;
      auto key = (info.canonical_eid != kInvalidEntityId)
                     ? info.canonical_eid : gd.info.entity_id;
      NoOpScheduler sched;
      Value addr = policy.mem_allocate(sched, info.size,
                                       info.align ? info.align : 8);
      if (auto *p = as_pointer(addr)) {
        uint64_t a = concrete_address(*p);
        state.global_addresses[key] = a;
        if (key != gd.info.entity_id)
          state.global_addresses[gd.info.entity_id] = a;
        state.call_stack.top().values[gd.instruction_id] = addr;
      }
      break;
    }
    case COMPLETED:
    case ERRORED:
      break;
  }

  return state;
}

}  // namespace mx::ir::interpret
