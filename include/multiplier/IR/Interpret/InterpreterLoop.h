// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.
//
// Template interpreter loop. Parameterized on PolicyT, SchedT, and ValueT
// so that the same dispatch logic works for both the concrete C++ interpreter
// and a future Python-subclassable policy path.

#pragma once

#include "Interpreter.h"
#include "Policy.h"
#include "Value.h"
#include "Suspension.h"
#include "ConcreteMemory.h"

#include <multiplier/IR/Block.h>
#include <multiplier/IR/Function.h>
#include <multiplier/IR/Instruction.h>
#include <multiplier/IR/InstructionKinds.h>
#include <multiplier/IR/Object.h>
#include <multiplier/AST/BuiltinType.h>
#include <multiplier/IR/OpCode.h>
#include <multiplier/IR/StructureKinds.h>
#include <multiplier/AST.h>
#include <multiplier/Entity.h>
#include <multiplier/Fragment.h>
#include <multiplier/Frontend.h>

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace mx::ir::interpret {

// ===========================================================================
// Non-template helpers
// ===========================================================================

inline RawEntityId eid(const IRInstruction &inst) {
  return EntityId(inst.id()).Pack();
}

inline size_t underlying_op_access_size(ir::OpCode op) {
  using enum ir::OpCode;
  if (ir::IsFloatArithmetic(op)) {
    unsigned v = static_cast<unsigned>(op);
    return (v % 2 == 1) ? 4 : 8;
  }
  if (op >= ADD_8 && op <= SHR_64) {
    static constexpr size_t widths[] = {1, 2, 4, 8};
    unsigned base;
    if (op >= SHR_8) base = static_cast<unsigned>(SHR_8);
    else if (op >= SHL_8) base = static_cast<unsigned>(SHL_8);
    else if (op >= BIT_XOR_8) base = static_cast<unsigned>(BIT_XOR_8);
    else if (op >= BIT_OR_8) base = static_cast<unsigned>(BIT_OR_8);
    else if (op >= BIT_AND_8) base = static_cast<unsigned>(BIT_AND_8);
    else if (op >= USHR_8) base = static_cast<unsigned>(USHR_8);
    else if (op >= UREM_8) base = static_cast<unsigned>(UREM_8);
    else if (op >= UDIV_8) base = static_cast<unsigned>(UDIV_8);
    else if (op >= REM_8) base = static_cast<unsigned>(REM_8);
    else if (op >= DIV_8) base = static_cast<unsigned>(DIV_8);
    else if (op >= MUL_8) base = static_cast<unsigned>(MUL_8);
    else if (op >= SUB_8) base = static_cast<unsigned>(SUB_8);
    else base = static_cast<unsigned>(ADD_8);
    unsigned idx = static_cast<unsigned>(op) - base;
    return (idx < 4) ? widths[idx] : 8;
  }
  if (op >= ATOMIC_ADD_8 && op <= ATOMIC_EXCHANGE_64) {
    static constexpr size_t widths[] = {1, 2, 4, 8};
    unsigned v = static_cast<unsigned>(op) -
                 static_cast<unsigned>(ATOMIC_ADD_8);
    return widths[v % 4];
  }
  if (op >= ADD_OVERFLOW_8 && op <= MUL_OVERFLOW_64) {
    static constexpr size_t widths[] = {1, 2, 4, 8};
    unsigned v = static_cast<unsigned>(op) -
                 static_cast<unsigned>(ADD_OVERFLOW_8);
    return widths[v % 4];
  }
  return 8;
}

// ===========================================================================
// val() — value lookup from instruction cache
// ===========================================================================

template <typename ValueT>
inline ValueT val(const CallFrame<ValueT> &frame, const IRInstruction &inst) {
  auto it = frame.values.find(EntityId(inst.id()).Pack());
  return (it != frame.values.end()) ? it->second
                                    : ValueTraits<ValueT>::default_value();
}

// ===========================================================================
// resolve_va_list_val — dereference load addresses for va_list operands
// ===========================================================================

template <typename ValueT>
inline ValueT resolve_va_list_val(const CallFrame<ValueT> &frame,
                                  const IRInstruction &operand) {
  auto load_mi = MemoryInst::from(operand);
  if (load_mi) return val<ValueT>(frame, load_mi->address());
  return val<ValueT>(frame, operand);
}

// ===========================================================================
// ENTER_BLOCK — push a block's root instructions onto the work stack
// ===========================================================================

// Walk a block's instructions and push them onto the work stack.
// Does NOT clear frame.values; safe to call after pre-seeding live-in
// values for mid-block entry (see interp_init_state_at).
template <typename ValueT>
inline void push_block_work_items(auto &state, const IRBlock &block) {
  // Collect root instructions. Find the terminator.
  std::vector<IRInstruction> roots;
  IRInstruction terminator_inst;
  bool has_terminator = false;

  uint32_t inst_count = 0;
  for (auto inst : block.all_instructions()) {
    ++inst_count;
    if (inst_count > 10000) {
      (void) fprintf(stderr, "ENTER_BLOCK: too many instructions (%u), aborting\n", inst_count);
      return;
    }
    if (ir::IsTerminator(inst.opcode())) {
      terminator_inst = inst;
      has_terminator = true;
    } else {
      roots.push_back(inst);
    }
  }
  // Push terminator (processed last = pushed first).
  if (has_terminator) {
    auto op = terminator_inst.opcode();
    WorkKind wk;
    if (op == OpCode::COND_BRANCH) wk = WorkKind::DECIDE_COND_BRANCH;
    else if (op == OpCode::SWITCH) wk = WorkKind::DECIDE_SWITCH;
    else if (op == OpCode::RET) wk = WorkKind::EXEC_RET;
    else if (op == OpCode::UNREACHABLE || op == OpCode::IMPLICIT_UNREACHABLE)
      wk = WorkKind::EXEC_UNREACHABLE;
    else wk = WorkKind::EXEC_GOTO;  // GOTO/IMPLICIT_GOTO/BREAK/CONTINUE/etc.

    state.work_stack.push_back({wk, terminator_inst, block});
  }

  // Push non-terminator roots in reverse (first instruction on top).
  for (auto it = roots.rbegin(); it != roots.rend(); ++it) {
    state.work_stack.push_back({WorkKind::ANALYZE, *it, {}});
  }
}

template <typename PolicyT, typename ValueT>
inline void enter_block(auto &state, PolicyT &policy, const IRBlock &block) {
  // Phase 8d: notify the policy of the block entry so analysts can
  // observe every block visit (not only branch transitions).
  policy.on_enter_block(state, block);
  // Clear transient values cache, then push roots.
  state.call_stack.top().values.clear();
  push_block_work_items<ValueT>(state, block);
}

// ===========================================================================
// ANALYZE — dispatch on opcode, push specific items + operand ANALYZEs
// ===========================================================================

template <typename ValueT>
inline void analyze(auto &state,
                    const IRInstruction &inst) {
  auto &frame = state.call_stack.top();
  auto id = eid(inst);

  // Already cached -> skip.
  if (frame.values.count(id)) return;

  auto op = inst.opcode();
  auto push = [&](WorkKind wk) {
    state.work_stack.push_back({wk, inst, {}});
  };
  auto push_operand = [&](const IRInstruction &operand) {
    state.work_stack.push_back({WorkKind::ANALYZE, operand, {}});
  };

  switch (op) {
    case OpCode::CONST:
      push(WorkKind::COMPUTE_CONST);
      break;

    case OpCode::ALLOCA:
      push(WorkKind::COMPUTE_ALLOCA);
      // Dynamic alloca needs size operand.
      if (auto da = DynamicAllocaInst::from(inst)) {
        push_operand(da->size());
      }
      break;

    case OpCode::STRING_PTR_32: case OpCode::STRING_PTR_64:
      push(WorkKind::COMPUTE_STRING_PTR);
      break;

    case OpCode::MEMORY: {
      auto mi = MemoryInst::from(inst);
      if (!mi) break;
      auto sub = mi->sub_opcode();
      if (sub == ir::MemOp::CONSUME_VA_PARAM) {
        push(WorkKind::EXEC_CONSUME_VA_PARAM);
        if (auto cvp = ConsumeVAParamInst::from(inst)) {
          push_operand(cvp->va_list_operand());
        }
      } else if (ir::IsDirectLoadStore(sub)) {
        if (ir::IsAnyLoad(sub)) {
          push(WorkKind::EXEC_LOAD);
          push_operand(mi->address());
        } else {
          push(WorkKind::EXEC_STORE);
          push_operand(mi->stored_value());
          push_operand(mi->address());
        }
      } else {
        push(WorkKind::EXEC_BULK_MEM);
        for (auto operand : inst.operands()) {
          push_operand(operand);
        }
      }
      break;
    }

    case OpCode::GEP_FIELD_32: case OpCode::GEP_FIELD_64:
      if (auto gep = GEPFieldInst::from(inst)) {
        push(WorkKind::COMPUTE_GEP_FIELD);
        push_operand(gep->base());
      }
      break;

    case OpCode::PTR_ADD_32: case OpCode::PTR_ADD_64:
      if (auto pa = PtrAddInst::from(inst)) {
        push(WorkKind::COMPUTE_PTR_ADD);
        push_operand(pa->index());
        push_operand(pa->base());
      }
      break;

    case OpCode::PTR_DIFF_32: case OpCode::PTR_DIFF_64:
      if (auto pd = PtrDiffInst::from(inst)) {
        push(WorkKind::COMPUTE_PTR_DIFF);
        push_operand(pd->rhs());
        push_operand(pd->lhs());
      }
      break;

    // Binary arithmetic (all widths).
    case OpCode::ADD_8: case OpCode::ADD_16:
    case OpCode::ADD_32: case OpCode::ADD_64:
    case OpCode::SUB_8: case OpCode::SUB_16:
    case OpCode::SUB_32: case OpCode::SUB_64:
    case OpCode::MUL_8: case OpCode::MUL_16:
    case OpCode::MUL_32: case OpCode::MUL_64:
    case OpCode::DIV_8: case OpCode::DIV_16:
    case OpCode::DIV_32: case OpCode::DIV_64:
    case OpCode::REM_8: case OpCode::REM_16:
    case OpCode::REM_32: case OpCode::REM_64:
    case OpCode::UDIV_8: case OpCode::UDIV_16:
    case OpCode::UDIV_32: case OpCode::UDIV_64:
    case OpCode::UREM_8: case OpCode::UREM_16:
    case OpCode::UREM_32: case OpCode::UREM_64:
    case OpCode::USHR_8: case OpCode::USHR_16:
    case OpCode::USHR_32: case OpCode::USHR_64:
    case OpCode::BIT_AND_8: case OpCode::BIT_AND_16:
    case OpCode::BIT_AND_32: case OpCode::BIT_AND_64:
    case OpCode::BIT_OR_8: case OpCode::BIT_OR_16:
    case OpCode::BIT_OR_32: case OpCode::BIT_OR_64:
    case OpCode::BIT_XOR_8: case OpCode::BIT_XOR_16:
    case OpCode::BIT_XOR_32: case OpCode::BIT_XOR_64:
    case OpCode::SHL_8: case OpCode::SHL_16:
    case OpCode::SHL_32: case OpCode::SHL_64:
    case OpCode::SHR_8: case OpCode::SHR_16:
    case OpCode::SHR_32: case OpCode::SHR_64:
    case OpCode::FADD_32: case OpCode::FADD_64:
    case OpCode::FSUB_32: case OpCode::FSUB_64:
    case OpCode::FMUL_32: case OpCode::FMUL_64:
    case OpCode::FDIV_32: case OpCode::FDIV_64:
    case OpCode::FREM_32: case OpCode::FREM_64:
    case OpCode::LOGICAL_AND: case OpCode::LOGICAL_OR:
      if (auto bin = BinaryInst::from(inst)) {
        push(WorkKind::COMPUTE_BINARY);
        push_operand(bin->rhs());
        push_operand(bin->lhs());
      }
      break;

    // Comparisons (all widths).
    case OpCode::CMP_EQ_8: case OpCode::CMP_EQ_16:
    case OpCode::CMP_EQ_32: case OpCode::CMP_EQ_64:
    case OpCode::CMP_NE_8: case OpCode::CMP_NE_16:
    case OpCode::CMP_NE_32: case OpCode::CMP_NE_64:
    case OpCode::CMP_LT_8: case OpCode::CMP_LT_16:
    case OpCode::CMP_LT_32: case OpCode::CMP_LT_64:
    case OpCode::CMP_LE_8: case OpCode::CMP_LE_16:
    case OpCode::CMP_LE_32: case OpCode::CMP_LE_64:
    case OpCode::CMP_GT_8: case OpCode::CMP_GT_16:
    case OpCode::CMP_GT_32: case OpCode::CMP_GT_64:
    case OpCode::CMP_GE_8: case OpCode::CMP_GE_16:
    case OpCode::CMP_GE_32: case OpCode::CMP_GE_64:
    case OpCode::UCMP_LT_8: case OpCode::UCMP_LT_16:
    case OpCode::UCMP_LT_32: case OpCode::UCMP_LT_64:
    case OpCode::UCMP_LE_8: case OpCode::UCMP_LE_16:
    case OpCode::UCMP_LE_32: case OpCode::UCMP_LE_64:
    case OpCode::UCMP_GT_8: case OpCode::UCMP_GT_16:
    case OpCode::UCMP_GT_32: case OpCode::UCMP_GT_64:
    case OpCode::UCMP_GE_8: case OpCode::UCMP_GE_16:
    case OpCode::UCMP_GE_32: case OpCode::UCMP_GE_64:
    case OpCode::FCMP_EQ_32: case OpCode::FCMP_EQ_64:
    case OpCode::FCMP_NE_32: case OpCode::FCMP_NE_64:
    case OpCode::FCMP_LT_32: case OpCode::FCMP_LT_64:
    case OpCode::FCMP_LE_32: case OpCode::FCMP_LE_64:
    case OpCode::FCMP_GT_32: case OpCode::FCMP_GT_64:
    case OpCode::FCMP_GE_32: case OpCode::FCMP_GE_64:
      if (auto cmp = ComparisonInst::from(inst)) {
        push(WorkKind::COMPUTE_COMPARE);
        push_operand(cmp->rhs());
        push_operand(cmp->lhs());
      }
      break;

    // Unary.
    case OpCode::NEG_8: case OpCode::NEG_16:
    case OpCode::NEG_32: case OpCode::NEG_64:
    case OpCode::FNEG_32: case OpCode::FNEG_64:
    case OpCode::BIT_NOT_8: case OpCode::BIT_NOT_16:
    case OpCode::BIT_NOT_32: case OpCode::BIT_NOT_64:
    case OpCode::LOGICAL_NOT:
    case OpCode::ABS_8: case OpCode::ABS_16:
    case OpCode::ABS_32: case OpCode::ABS_64:
      if (auto u = UnaryInst::from(inst)) {
        push(WorkKind::COMPUTE_UNARY);
        push_operand(u->operand());
      }
      break;

    case OpCode::CAST:
      if (auto c = CastInst::from(inst)) {
        push(WorkKind::COMPUTE_CAST);
        push_operand(c->operand());
      }
      break;

    case OpCode::READ_MODIFY_WRITE:
      if (auto rmw = ReadModifyWriteInst::from(inst)) {
        push(WorkKind::EXEC_RMW);
        for (auto rhs_op : rmw->rhs_operands()) {
          push_operand(rhs_op);
        }
        push_operand(rmw->address());
      }
      break;

    case OpCode::CALL: {
      // Check if this CALL already has a cached result (from a previous
      // block -- the callee already returned).
      auto crit = frame.call_results.find(id);
      if (crit != frame.call_results.end()) {
        frame.values[id] = crit->second;
        return;
      }
      if (auto ci = CallInst::from(inst)) {
        push(WorkKind::EXEC_CALL);
        // Analyze arguments.
        for (auto arg : ci->arguments()) {
          push_operand(arg);
        }
        // For indirect calls, also analyze the callee operand (operand 0)
        // so the function pointer value is cached before EXEC_CALL.
        if (ci->is_indirect()) {
          push_operand(inst.nth_operand(0));
        }
      }
      break;
    }

    case OpCode::SELECT:
      if (auto sel = SelectInst::from(inst)) {
        push(WorkKind::COMPUTE_SELECT);
        push_operand(sel->false_value());
        push_operand(sel->true_value());
        push_operand(sel->condition());
      }
      break;

    case OpCode::LAST_VALUE:
      if (auto lv = LastValueInst::from(inst)) {
        push(WorkKind::COMPUTE_LAST_VALUE);
        push_operand(lv->last());
      }
      break;

    case OpCode::PARAM_PTR_32: case OpCode::PARAM_PTR_64:
      push(WorkKind::COMPUTE_PARAM_PTR);
      break;

    case OpCode::BITWISE_8: case OpCode::BITWISE_16:
    case OpCode::BITWISE_32: case OpCode::BITWISE_64:
      push(WorkKind::COMPUTE_BITWISE);
      for (auto operand : inst.operands()) {
        push_operand(operand);
      }
      break;

    case OpCode::FLOAT:
      push(WorkKind::COMPUTE_FLOAT_OP);
      for (auto operand : inst.operands()) {
        push_operand(operand);
      }
      break;

    case OpCode::GLOBAL_PTR_32: case OpCode::GLOBAL_PTR_64:
    case OpCode::THREAD_LOCAL_PTR_32: case OpCode::THREAD_LOCAL_PTR_64:
      push(WorkKind::COMPUTE_GLOBAL_PTR);
      break;

    case OpCode::FUNC_PTR_32: case OpCode::FUNC_PTR_64:
      push(WorkKind::COMPUTE_FUNC_PTR);
      break;

    case OpCode::RETURN_PTR_32: case OpCode::RETURN_PTR_64:
      push(WorkKind::COMPUTE_RETURN_PTR);
      break;

    case OpCode::ENTER_SCOPE:
      push(WorkKind::EXEC_ENTER_SCOPE);
      break;

    case OpCode::EXIT_SCOPE:
      push(WorkKind::EXEC_EXIT_SCOPE);
      break;

    case OpCode::UNDEFINED:
      push(WorkKind::COMPUTE_UNDEFINED);
      break;

    case OpCode::FRAME_PTR_32: case OpCode::FRAME_PTR_64:
    case OpCode::RETURN_ADDRESS_32: case OpCode::RETURN_ADDRESS_64:
      frame.values[id] = ValueTraits<ValueT>::default_value();
      break;

    case OpCode::VA_START:
      push(WorkKind::EXEC_VA_START);
      if (auto vai = VAStartInst::from(inst)) {
        push_operand(vai->va_list_operand());
      }
      break;

    case OpCode::VA_END:
      push(WorkKind::EXEC_VA_END);
      if (auto vei = VAEndInst::from(inst)) {
        push_operand(vei->va_list_operand());
      }
      break;

    case OpCode::VA_COPY:
      push(WorkKind::EXEC_VA_COPY);
      if (auto vci = VACopyInst::from(inst)) {
        push_operand(vci->dest());
        push_operand(vci->src());
      }
      break;

    // Overflow/atomic opcodes only valid as RMW underlying ops.
    default:
      frame.values[id] = ValueTraits<ValueT>::default_value();
      break;
  }
}

// ===========================================================================
// exec_goto — unconditional branch
// ===========================================================================

template <typename PolicyT, typename ValueT>
inline void exec_goto(auto &state, PolicyT &policy,
                      const IRInstruction &inst) {
  auto br = BranchInst::from(inst);
  if (br) {
    enter_block<PolicyT, ValueT>(state, policy, br->target_block());
  }
}

// ===========================================================================
// compute_last_value — reads cached value only
// ===========================================================================

template <typename ValueT>
inline void compute_last_value(CallFrame<ValueT> &frame,
                               const IRInstruction &inst) {
  auto lv = LastValueInst::from(inst);
  frame.values[eid(inst)] = lv ? val<ValueT>(frame, lv->last())
                               : ValueTraits<ValueT>::default_value();
}

// ===========================================================================
// compute_param_ptr — reads cached value only
// ===========================================================================

template <typename ValueT>
inline void compute_param_ptr(CallFrame<ValueT> &frame,
                              const IRInstruction &inst) {
  auto pr = ParamPtrInst::from(inst);
  if (pr) {
    uint32_t idx = pr->parameter_index();
    if (idx < frame.param_ptrs.size()) {
      frame.values[eid(inst)] = frame.param_ptrs[idx];
      return;
    }
  }
  frame.values[eid(inst)] = ValueTraits<ValueT>::default_value();
}

// ===========================================================================
// COMPUTE_* handlers — operands guaranteed cached
// ===========================================================================

template <typename PolicyT, typename SchedT, typename ValueT>
inline void compute_const(CallFrame<ValueT> &frame, PolicyT &policy,
                          const IRInstruction &inst) {
  auto ci = ConstInst::from(inst);
  if (!ci) {
    frame.values[eid(inst)] = ValueTraits<ValueT>::default_value();
    return;
  }
  frame.values[eid(inst)] = policy.make_const(
      ci->sub_opcode(), ci->signed_value(), ci->unsigned_value());
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void compute_alloca(auto &state, PolicyT &policy,
                           SchedT &sched, const IRInstruction &inst) {
  auto &frame = state.call_stack.top();
  auto ai = AllocaInst::from(inst);
  if (!ai) return;
  auto obj = ai->object();
  auto obj_eid = EntityId(obj.id()).Pack();
  if (frame.locals.find(obj_eid) == frame.locals.end()) {
    if (auto da = DynamicAllocaInst::from(inst)) {
      ValueT sz_val = val<ValueT>(frame, da->size());
      int64_t runtime_sz = policy.extract_int(sz_val);
      if (runtime_sz > 0) {
        ValueT addr = policy.mem_allocate(sched,
            static_cast<uint64_t>(runtime_sz), ai->align_bytes());
        if (auto a = policy.extract_address(addr))
          frame.locals[obj_eid] = *a;
      } else {
        goto static_alloc;
      }
    } else {
      static_alloc:
      uint32_t size = obj.size_bytes();
      if (size == 0) size = 8;
      uint32_t align = obj.align_bytes();
      if (align == 0) align = 8;
      ValueT addr = policy.mem_allocate(sched, size, align);
      if (auto a = policy.extract_address(addr))
        frame.locals[obj_eid] = *a;
    }
  }
  frame.values[eid(inst)] = policy.make_literal_ptr(frame.locals[obj_eid]);
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void compute_string_ptr(auto &state, PolicyT &policy,
                               SchedT &sched, const IRInstruction &inst) {
  auto &frame = state.call_stack.top();
  auto inst_eid = eid(inst);
  if (frame.locals.find(inst_eid) == frame.locals.end()) {
    if (auto src = inst.source_statement()) {
      if (auto sl = StringLiteral::from(*src)) {
        auto bytes = sl->bytes();
        uint32_t char_width = sl->character_byte_width();
        uint32_t total = sl->byte_length() + char_width;
        ValueT addr = policy.mem_allocate(sched, total, 1);
        if (auto a = policy.extract_address(addr)) {
          frame.locals[inst_eid] = *a;
          policy.memory().write(*a, bytes.data(),
              std::min<uint32_t>(static_cast<uint32_t>(bytes.size()), total));
        }
      }
    }
  }
  auto it = frame.locals.find(inst_eid);
  frame.values[inst_eid] = (it != frame.locals.end())
      ? policy.make_literal_ptr(it->second) : policy.make_default();
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void compute_binary(CallFrame<ValueT> &frame, PolicyT &policy,
                           const IRInstruction &inst) {
  auto bin = BinaryInst::from(inst);
  if (!bin) {
    frame.values[eid(inst)] = ValueTraits<ValueT>::default_value();
    return;
  }
  frame.values[eid(inst)] = policy.binary_op(
      inst.opcode(), val<ValueT>(frame, bin->lhs()),
      val<ValueT>(frame, bin->rhs()));
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void compute_compare(CallFrame<ValueT> &frame, PolicyT &policy,
                            const IRInstruction &inst) {
  auto cmp = ComparisonInst::from(inst);
  if (!cmp) {
    frame.values[eid(inst)] = ValueTraits<ValueT>::default_value();
    return;
  }
  frame.values[eid(inst)] = policy.compare(
      inst.opcode(), val<ValueT>(frame, cmp->lhs()),
      val<ValueT>(frame, cmp->rhs()));
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void compute_unary(CallFrame<ValueT> &frame, PolicyT &policy,
                          const IRInstruction &inst) {
  auto u = UnaryInst::from(inst);
  if (!u) {
    frame.values[eid(inst)] = ValueTraits<ValueT>::default_value();
    return;
  }
  frame.values[eid(inst)] = policy.unary_op(
      inst.opcode(), val<ValueT>(frame, u->operand()));
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void compute_cast(CallFrame<ValueT> &frame, PolicyT &policy,
                         const IRInstruction &inst) {
  auto c = CastInst::from(inst);
  if (!c) {
    frame.values[eid(inst)] = ValueTraits<ValueT>::default_value();
    return;
  }
  frame.values[eid(inst)] = policy.cast(
      c->sub_opcode(), val<ValueT>(frame, c->operand()));
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void compute_gep_field(CallFrame<ValueT> &frame, PolicyT &policy,
                              const IRInstruction &inst) {
  auto gep = GEPFieldInst::from(inst);
  if (!gep) {
    frame.values[eid(inst)] = ValueTraits<ValueT>::default_value();
    return;
  }
  frame.values[eid(inst)] = policy.ptr_offset(
      val<ValueT>(frame, gep->base()), gep->byte_offset());
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void compute_ptr_add(CallFrame<ValueT> &frame, PolicyT &policy,
                            const IRInstruction &inst) {
  auto pa = PtrAddInst::from(inst);
  if (!pa) {
    frame.values[eid(inst)] = ValueTraits<ValueT>::default_value();
    return;
  }
  frame.values[eid(inst)] = policy.ptr_add(
      val<ValueT>(frame, pa->base()), val<ValueT>(frame, pa->index()),
      pa->element_size());
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void compute_ptr_diff(CallFrame<ValueT> &frame, PolicyT &policy,
                             const IRInstruction &inst) {
  auto pd = PtrDiffInst::from(inst);
  if (!pd) {
    frame.values[eid(inst)] = ValueTraits<ValueT>::default_value();
    return;
  }
  frame.values[eid(inst)] = policy.ptr_diff(
      val<ValueT>(frame, pd->lhs()), val<ValueT>(frame, pd->rhs()),
      pd->element_size());
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void compute_select(CallFrame<ValueT> &frame, PolicyT &policy,
                           const IRInstruction &inst) {
  auto sel = SelectInst::from(inst);
  if (!sel) {
    frame.values[eid(inst)] = ValueTraits<ValueT>::default_value();
    return;
  }
  frame.values[eid(inst)] = policy.select(
      val<ValueT>(frame, sel->condition()),
      val<ValueT>(frame, sel->true_value()),
      val<ValueT>(frame, sel->false_value()));
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void compute_bitwise(CallFrame<ValueT> &frame, PolicyT &policy,
                            const IRInstruction &inst) {
  auto bw = BitwiseOpInst::from(inst);
  if (!bw) {
    frame.values[eid(inst)] = ValueTraits<ValueT>::default_value();
    return;
  }
  ValueT v1 = ValueTraits<ValueT>::default_value();
  ValueT v2 = ValueTraits<ValueT>::default_value();
  int count = 0;
  for (auto op_inst : inst.operands()) {
    if (count == 0) v1 = val<ValueT>(frame, op_inst);
    else if (count == 1) v2 = val<ValueT>(frame, op_inst);
    ++count;
  }
  frame.values[eid(inst)] = policy.bitwise_intrinsic(
      inst.opcode(), bw->sub_opcode(), v1, v2);
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void compute_float_op(CallFrame<ValueT> &frame, PolicyT &policy,
                             const IRInstruction &inst) {
  auto fo = FloatOpInst::from(inst);
  if (!fo) {
    frame.values[eid(inst)] = ValueTraits<ValueT>::default_value();
    return;
  }
  std::vector<ValueT> ops;
  for (auto op_inst : inst.operands()) {
    ops.push_back(val<ValueT>(frame, op_inst));
  }
  frame.values[eid(inst)] = policy.float_intrinsic(fo->sub_opcode(), ops);
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void compute_global_ptr(auto &state, PolicyT &policy,
                               SchedT &sched, const IRInstruction &inst) {
  auto &frame = state.call_stack.top();
  auto src_eid = inst.source_entity_id();
  auto id = eid(inst);

  auto git = state.global_addresses.find(src_eid);
  if (git != state.global_addresses.end()) {
    frame.values[id] = policy.make_literal_ptr(git->second);
    return;
  }

  GlobalResolution gr;
  if (!policy.resolve_global(sched, src_eid, gr) || gr.info.size == 0) {
    frame.values[id] = policy.make_default();
    return;
  }

  auto &info = gr.info;
  auto key = (info.canonical_eid != kInvalidEntityId)
                 ? info.canonical_eid : src_eid;

  git = state.global_addresses.find(key);
  if (git != state.global_addresses.end()) {
    if (key != src_eid) state.global_addresses[src_eid] = git->second;
    frame.values[id] = policy.make_literal_ptr(git->second);
    return;
  }

  uint32_t align = info.align;
  if (align == 0) align = 8;

  // Phase 9: an `address_hint` from the resolver pre-empts the bump
  // allocator. `place_at` returns true on first reference and false
  // when the address is already live (e.g. Layout.place_global ran
  // earlier) — both cases honor the hint. Only a misalignment / true
  // overlap (place_at false AND the existing region's base differs)
  // falls back to mem_allocate.
  ValueT addr;
  bool placed_via_hint = false;
  if (info.address_hint) {
    auto hint_addr = *info.address_hint;
    if (policy.memory().place_at(hint_addr, info.size, align)) {
      addr = policy.make_literal_ptr(hint_addr);
      placed_via_hint = true;
    } else {
      // Already-live region at this address counts as a hit.
      uint8_t probe = 0;
      if (policy.memory().read(hint_addr, &probe, 1)) {
        addr = policy.make_literal_ptr(hint_addr);
        placed_via_hint = true;
      }
    }
  }
  if (!placed_via_hint) {
    addr = policy.mem_allocate(sched, info.size, align);
  }
  if (auto a = policy.extract_address(addr)) {
    state.global_addresses[key] = *a;
    if (key != src_eid) state.global_addresses[src_eid] = *a;

    // Store the result BEFORE pushing the initializer frame, because
    // the push may reallocate the segment's vector and invalidate `frame`.
    frame.values[id] = addr;

    if (info.initializer && !placed_via_hint) {
      CallFrame<ValueT> init_frame;
      init_frame.func = *info.initializer;
      init_frame.params = {addr};
      init_frame.call_site = kInvalidEntityId;
      for (auto obj : info.initializer->objects()) {
        auto k = obj.kind();
        if (k == ir::ObjectKind::PARAMETER ||
            k == ir::ObjectKind::PARAMETER_VALUE) {
          init_frame.param_ptrs.push_back(addr);
        }
      }
      if (info.initializer->kind() == ir::FunctionKind::GLOBAL_INITIALIZER) {
        init_frame.param_ptrs.push_back(addr);
      }
      state.call_stack.push(std::move(init_frame));
      state.work_stack.push_back({WorkKind::ENTER_BLOCK,
                                  {}, info.initializer->entry_block()});
    }
  }
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void compute_func_ptr(auto &state, PolicyT &policy,
                             SchedT &sched, const IRInstruction &inst) {
  auto &frame = state.call_stack.top();
  auto src_eid = inst.source_entity_id();
  auto id = eid(inst);

  // Phase 9: state-level cache so repeat references to the same
  // function — even from different frames — see one address.
  uint64_t slot_addr;
  auto sit = state.function_addresses.find(src_eid);
  if (sit != state.function_addresses.end()) {
    slot_addr = sit->second;
  } else {
    bool placed_via_hint = false;
    if (auto hint = policy.address_for_function(sched, src_eid)) {
      if (policy.memory().place_at(*hint, 8, 8)) {
        slot_addr = *hint;
        placed_via_hint = true;
      } else {
        // Already-live region at this address: reuse the slot.
        uint8_t probe = 0;
        if (policy.memory().read(*hint, &probe, 1)) {
          slot_addr = *hint;
          placed_via_hint = true;
        }
      }
    }
    if (!placed_via_hint) {
      ValueT addr = policy.mem_allocate(sched, 8, 8);
      auto a = policy.extract_address(addr);
      if (!a) {
        frame.values[id] = ValueTraits<ValueT>::default_value();
        return;
      }
      slot_addr = *a;
    }
    policy.memory().write(slot_addr, &src_eid, 8);
    state.function_addresses[src_eid] = slot_addr;
  }
  frame.locals[src_eid] = slot_addr;
  frame.values[id] = policy.make_literal_ptr(slot_addr);
}

// ===========================================================================
// EXEC_* handlers — side effects
// ===========================================================================

template <typename PolicyT, typename SchedT, typename ValueT>
inline void exec_load(auto &state, PolicyT &policy,
                      SchedT &sched, const IRInstruction &inst) {
  auto mi = MemoryInst::from(inst);
  if (!mi) return;
  auto sub = mi->sub_opcode();
  MemAccessHint hint{ir::AccessSize(sub), ir::IsFloatLoad(sub), false};
  auto &frame = state.call_stack.top();
  ValueT addr = val<ValueT>(frame, mi->address());
  auto inst_eid = eid(inst);
  auto addr_eid = eid(mi->address());

  // Phase 8a: when the address didn't extract concretely but does carry
  // an operand eid, give the policy a chance to resolve the load
  // symbolically (e.g. via a region-overlay z3 Select). Returning false
  // falls through to `with_address`, preserving the existing suspension
  // behavior for policies that don't override the hook.
  if (!policy.extract_address(addr) && addr_eid != kInvalidEntityId) {
    ValueT result;
    if (policy.exec_symbolic_load(sched, addr, hint, result)) {
      frame.values[inst_eid] = result;
      return;
    }
  }

  policy.with_address(addr, policy.memory(), hint, addr_eid, state, sched,
      [&](auto &p, ConcreteMemory & /*mem*/, uint64_t a) {
        ValueT result;
        ValueT addr_val = p.make_literal_ptr(a);
        p.mem_read(sched, addr_val, hint, result);
        frame.values[inst_eid] = result;
      });
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void exec_store(auto &state, PolicyT &policy,
                       SchedT &sched, const IRInstruction &inst) {
  auto mi = MemoryInst::from(inst);
  if (!mi) return;
  auto sub = mi->sub_opcode();
  MemAccessHint hint{ir::AccessSize(sub), ir::IsFloatStore(sub), true};
  auto &frame = state.call_stack.top();
  ValueT addr = val<ValueT>(frame, mi->address());
  ValueT stored = val<ValueT>(frame, mi->stored_value());
  auto addr_eid = eid(mi->address());

  // Phase 8a: symmetric symbolic-STORE short-circuit (see exec_load).
  if (!policy.extract_address(addr) && addr_eid != kInvalidEntityId) {
    if (policy.exec_symbolic_store(sched, addr, stored, hint)) {
      return;
    }
  }

  policy.with_address(addr, policy.memory(), hint, addr_eid, state, sched,
      [&](auto &p, ConcreteMemory & /*mem*/, uint64_t a) {
        ValueT addr_val = p.make_literal_ptr(a);
        p.mem_write(sched, addr_val, stored, hint);
      });
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void exec_bulk_mem(CallFrame<ValueT> &frame, PolicyT &policy,
                          SchedT &sched, const IRInstruction &inst) {
  auto mi = MemoryInst::from(inst);
  if (!mi) return;
  auto sub = mi->sub_opcode();
  std::vector<ValueT> ops;
  for (auto op_inst : inst.operands()) {
    ops.push_back(val<ValueT>(frame, op_inst));
  }
  ValueT result;
  policy.mem_bulk_op(sched, sub, ops, *mi, result);
  frame.values[eid(inst)] = result;
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void exec_rmw(auto &state, PolicyT &policy,
                     SchedT &sched, const IRInstruction &inst) {
  auto rmw = ReadModifyWriteInst::from(inst);
  if (!rmw) return;
  auto &frame = state.call_stack.top();
  ValueT addr = val<ValueT>(frame, rmw->address());

  auto underlying = rmw->underlying_op();
  size_t access_sz = underlying_op_access_size(underlying);
  bool rmw_is_float = ir::IsFloatArithmetic(underlying);
  MemAccessHint rhint{static_cast<uint32_t>(access_sz), rmw_is_float, false};
  auto inst_eid = eid(inst);
  auto addr_eid = eid(rmw->address());

  policy.with_address(addr, policy.memory(), rhint, addr_eid, state, sched,
      [&](auto &p, ConcreteMemory & /*mem*/, uint64_t addr_u64) {
    ValueT addr_val = p.make_literal_ptr(addr_u64);
    ValueT old_val;
    p.mem_read(sched, addr_val, rhint, old_val);

    ValueT rhs = p.make_literal_int(0);
    for (auto rhs_op : rmw->rhs_operands()) {
      rhs = val<ValueT>(frame, rhs_op);
      break;
    }

    // Overflow-checked arithmetic.
    if (underlying >= OpCode::ADD_OVERFLOW_8 &&
        underlying <= OpCode::MUL_OVERFLOW_64) {
      ValueT a = p.make_literal_int(0), b = p.make_literal_int(0);
      int rhs_i = 0;
      for (auto rhs_op : rmw->rhs_operands()) {
        if (rhs_i == 0) a = val<ValueT>(frame, rhs_op);
        else if (rhs_i == 1) b = val<ValueT>(frame, rhs_op);
        ++rhs_i;
      }
      __int128 wide;
      if (underlying >= OpCode::ADD_OVERFLOW_8 &&
          underlying <= OpCode::ADD_OVERFLOW_64)
        wide = static_cast<__int128>(p.extract_int(a)) +
               static_cast<__int128>(p.extract_int(b));
      else if (underlying >= OpCode::SUB_OVERFLOW_8 &&
               underlying <= OpCode::SUB_OVERFLOW_64)
        wide = static_cast<__int128>(p.extract_int(a)) -
               static_cast<__int128>(p.extract_int(b));
      else
        wide = static_cast<__int128>(p.extract_int(a)) *
               static_cast<__int128>(p.extract_int(b));

      int64_t truncated = static_cast<int64_t>(wide);
      switch (access_sz) {
        case 1: truncated = static_cast<int64_t>(static_cast<int8_t>(truncated)); break;
        case 2: truncated = static_cast<int64_t>(static_cast<int16_t>(truncated)); break;
        case 4: truncated = static_cast<int64_t>(static_cast<int32_t>(truncated)); break;
        default: break;
      }
      ValueT new_val = p.make_literal_int(truncated);
      bool overflow = (wide != static_cast<__int128>(truncated));
      MemAccessHint whint{static_cast<uint32_t>(access_sz), rmw_is_float, true};
      p.mem_write(sched, addr_val, new_val, whint);
      frame.values[inst_eid] = p.make_literal_int(overflow ? 1 : 0);
      return;
    }

    // PTR_ADD in RMW.
    if (underlying == OpCode::PTR_ADD_32 || underlying == OpCode::PTR_ADD_64) {
      int64_t elem_sz = rmw->element_size();
      if (elem_sz <= 0) elem_sz = 1;
      ValueT new_val = p.ptr_add(old_val, rhs, elem_sz);
      MemAccessHint whint{static_cast<uint32_t>(access_sz), false, true};
      p.mem_write(sched, addr_val, new_val, whint);
      frame.values[inst_eid] = rmw->returns_new_value() ? new_val : old_val;
      return;
    }

    // Atomic exchange.
    if (underlying >= OpCode::ATOMIC_EXCHANGE_8 &&
        underlying <= OpCode::ATOMIC_EXCHANGE_64) {
      MemAccessHint whint{static_cast<uint32_t>(access_sz), rmw_is_float, true};
      p.mem_write(sched, addr_val, rhs, whint);
      frame.values[inst_eid] = rmw->returns_new_value() ? rhs : old_val;
      return;
    }

    // General case.
    ValueT new_val = p.binary_op(underlying, old_val, rhs);
    MemAccessHint whint{static_cast<uint32_t>(access_sz), rmw_is_float, true};
    p.mem_write(sched, addr_val, new_val, whint);
    frame.values[inst_eid] = rmw->returns_new_value() ? new_val : old_val;
  });
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void exec_call(auto &state, PolicyT &policy,
                      SchedT &sched, const IRInstruction &inst) {
  auto ci = CallInst::from(inst);
  if (!ci) return;
  auto &frame = state.call_stack.top();
  auto id = eid(inst);

  // Collect arguments: dereference ALLOCA pointers.
  std::vector<ValueT> call_args;
  for (auto arg : ci->arguments()) {
    ValueT v = val<ValueT>(frame, arg);
    auto ai = AllocaInst::from(arg);
    if (ai) {
      uint32_t sz = ai->size_bytes();
      if (sz == 0) sz = 8;
      if (sz <= 8) {
        MemAccessHint hint{sz, false, false};
        bool dereffed = false;
        ValueT loaded;
        policy.with_address(v, policy.memory(), hint, eid(arg),
            state, sched,
            [&](auto &p, ConcreteMemory & /*mem*/, uint64_t a) {
              ValueT addr_val = p.make_literal_ptr(a);
              p.mem_read(sched, addr_val, hint, loaded);
              dereffed = true;
            });
        if (dereffed) {
          call_args.push_back(loaded);
          continue;
        }
      }
    }
    call_args.push_back(v);
  }

  // Resolve callee.
  std::optional<IRFunction> callee_ir;
  auto target_decl = ci->target();
  RawEntityId indirect_eid = kInvalidEntityId;

  if (ci->is_indirect()) {
    auto callee_op = inst.nth_operand(0);
    ValueT callee_val = val<ValueT>(frame, callee_op);
    MemAccessHint hint{8, false, false};
    // Phase 9: mark the next suspension as a call-target so the Python
    // driver can route it through intercept.indirect_call(target_kind=
    // "symbolic") instead of the generic address strategy.
    if (!policy.extract_address(callee_val)) {
      policy.mark_next_suspension_as_call_target();
    }
    policy.with_address(callee_val, policy.memory(), hint, eid(callee_op),
        state, sched,
        [&](auto &p, ConcreteMemory & /*mem*/, uint64_t a) {
          ValueT addr_val = p.make_literal_ptr(a);
          ValueT eid_val;
          p.mem_read(sched, addr_val, hint, eid_val);
          indirect_eid = static_cast<RawEntityId>(p.extract_uint(eid_val));
        });
  }

  // Always consult the policy. Default policies fall through to
  // `func_resolver_` so direct-call inlining is preserved; symex
  // analysts can intercept any call site via `intercept.call(name=…)`.
  {
    RawEntityId target_eid = target_decl
        ? target_decl->id().Pack() : kInvalidEntityId;
    CallResolution<ValueT> resolution;
    bool alive = policy.resolve_call(
        sched, inst, target_eid, indirect_eid,
        call_args, ci->is_indirect(), resolution);
    if (!alive) {
      frame.values[id] = policy.make_default();
      return;
    }
    switch (resolution.action) {
      case CallAction::INLINE:
        callee_ir = resolution.callee_ir;
        break;
      case CallAction::MODEL:
      case CallAction::SKIP:
        frame.values[id] = resolution.return_value;
        return;
    }
  }

  if (!callee_ir) {
    frame.values[id] = policy.make_default();
    return;
  }

  // Get return pointer before pushing (frame ref invalidated by push).
  ValueT return_ptr = policy.make_default();
  auto ret_alloca = ci->return_alloca();
  if (ret_alloca) {
    return_ptr = val<ValueT>(frame, *ret_alloca);
  }

  // Push callee frame.
  CallFrame<ValueT> callee_frame;
  callee_frame.func = *callee_ir;
  callee_frame.params = call_args;
  callee_frame.call_site = id;
  if (!policy.is_undefined(return_ptr)) {
    callee_frame.return_ptr = return_ptr;
  }

  // Allocate parameter storage.
  uint32_t param_idx = 0;
  for (auto obj : callee_ir->objects()) {
    auto k = obj.kind();
    if (k == ir::ObjectKind::PARAMETER ||
        k == ir::ObjectKind::PARAMETER_VALUE) {
      uint32_t size = obj.size_bytes();
      if (size == 0) size = 8;
      uint32_t align = obj.align_bytes();
      if (align == 0) align = 8;
      ValueT addr = policy.mem_allocate(sched, size, align);
      // mem_allocate-derived addresses are concrete by construction.
      if (auto a = policy.extract_address(addr)) {
        callee_frame.locals[EntityId(obj.id()).Pack()] = *a;
        if (param_idx < call_args.size()) {
          auto &arg = call_args[param_idx];
          MemAccessHint w_hint{size, false, true};
          bool memcpyed = false;
          if (size > 8) {
            // Init-time bulk copy: cannot meaningfully resume from a
            // symbolic source pointer here, so suppress suspension by
            // passing kInvalidEntityId.
            policy.with_address(arg, policy.memory(), w_hint,
                kInvalidEntityId, state, sched,
                [&](auto &p, ConcreteMemory &mem, uint64_t arg_addr) {
                  mem.memcpy(*a, arg_addr, size);
                  memcpyed = true;
                  (void)p;
                });
          }
          if (!memcpyed) {
            policy.mem_write(sched, addr, arg, w_hint);
          }
        }
      }
      callee_frame.param_ptrs.push_back(addr);
      ++param_idx;
    }
  }

  if (callee_ir->kind() == ir::FunctionKind::GLOBAL_INITIALIZER) {
    for (auto &a : call_args) {
      callee_frame.param_ptrs.push_back(a);
    }
    param_idx = static_cast<uint32_t>(call_args.size());
  }

  callee_frame.variadic_start_index = param_idx;
  for (uint32_t i = param_idx; i < call_args.size(); ++i) {
    ValueT addr = policy.mem_allocate(sched, 8, 8);
    MemAccessHint hint{8, false, true};
    policy.mem_write(sched, addr, call_args[i], hint);
    callee_frame.param_ptrs.push_back(addr);
  }

  // Allocate return storage if not already set.
  if (policy.is_undefined(callee_frame.return_ptr)) {
    if (auto fd = callee_ir->declaration()) {
      auto rt = fd->return_type();
      if (auto bits = rt.size_in_bits()) {
        uint32_t sz = static_cast<uint32_t>((*bits + 7) / 8);
        if (sz > 0) {
          callee_frame.return_ptr = policy.mem_allocate(sched, sz, 8);
        }
      }
    }
  }

  state.call_stack.push(std::move(callee_frame));
  state.work_stack.push_back({WorkKind::ENTER_BLOCK, {},
                              callee_ir->entry_block()});
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void exec_enter_scope(CallFrame<ValueT> &frame, PolicyT &policy,
                             const IRInstruction &inst) {
  auto esi = EnterScopeInst::from(inst);
  if (!esi) return;
  for (auto obj : esi->scope().objects()) {
    auto oid = EntityId(obj.id()).Pack();
    auto it = frame.locals.find(oid);
    if (it != frame.locals.end()) {
      policy.mem_unpoison(policy.make_literal_ptr(it->second));
    }
  }
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void exec_exit_scope(CallFrame<ValueT> &frame, PolicyT &policy,
                            const IRInstruction &inst) {
  auto esi = ExitScopeInst::from(inst);
  if (!esi) return;
  for (auto obj : esi->scope().objects()) {
    auto oid = EntityId(obj.id()).Pack();
    auto it = frame.locals.find(oid);
    if (it != frame.locals.end()) {
      policy.mem_poison(policy.make_literal_ptr(it->second));
    }
  }
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void exec_va_start(CallFrame<ValueT> &frame, PolicyT &policy,
                          SchedT &sched, const IRInstruction &inst) {
  auto vai = VAStartInst::from(inst);
  if (!vai) return;
  ValueT va_addr = resolve_va_list_val<ValueT>(frame, vai->va_list_operand());
  if (policy.has_address(va_addr)) {
    ValueT idx = policy.make_literal_int(static_cast<int64_t>(frame.variadic_start_index), 4);
    MemAccessHint hint{4, false, true};
    policy.mem_write(sched, va_addr, idx, hint);
  }
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void exec_va_end(CallFrame<ValueT> &frame, PolicyT &policy,
                        SchedT &sched, const IRInstruction &inst) {
  auto vei = VAEndInst::from(inst);
  if (!vei) return;
  ValueT va_addr = resolve_va_list_val<ValueT>(frame, vei->va_list_operand());
  if (policy.has_address(va_addr)) {
    ValueT sentinel = policy.make_literal_int(static_cast<int64_t>(~0u), 4);
    MemAccessHint hint{4, false, true};
    policy.mem_write(sched, va_addr, sentinel, hint);
  }
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void exec_va_copy(CallFrame<ValueT> &frame, PolicyT &policy,
                         SchedT &sched, const IRInstruction &inst) {
  auto vci = VACopyInst::from(inst);
  if (!vci) return;
  ValueT src_addr = resolve_va_list_val<ValueT>(frame, vci->src());
  ValueT dst_addr = resolve_va_list_val<ValueT>(frame, vci->dest());
  if (policy.has_address(src_addr) && policy.has_address(dst_addr)) {
    ValueT idx_val;
    MemAccessHint rhint{4, false, false};
    policy.mem_read(sched, src_addr, rhint, idx_val);
    MemAccessHint whint{4, false, true};
    policy.mem_write(sched, dst_addr, idx_val, whint);
  }
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void exec_consume_va_param(CallFrame<ValueT> &frame, PolicyT &policy,
                                  SchedT &sched, const IRInstruction &inst) {
  auto cvp = ConsumeVAParamInst::from(inst);
  if (!cvp) return;
  ValueT va_addr = resolve_va_list_val<ValueT>(frame, cvp->va_list_operand());
  if (policy.has_address(va_addr)) {
    ValueT idx_val;
    MemAccessHint hint{4, false, false};
    policy.mem_read(sched, va_addr, hint, idx_val);
    uint32_t idx = static_cast<uint32_t>(policy.extract_uint(idx_val));
    if (idx < frame.param_ptrs.size()) {
      frame.values[eid(inst)] = frame.param_ptrs[idx];
      ++idx;
      ValueT new_idx = policy.make_literal_int(static_cast<int64_t>(idx), 4);
      MemAccessHint whint{4, false, true};
      policy.mem_write(sched, va_addr, new_idx, whint);
      return;
    }
  }
  frame.values[eid(inst)] = policy.make_default();
}

// ===========================================================================
// Terminator handlers
// ===========================================================================

template <typename PolicyT, typename SchedT, typename ValueT>
inline ValueT read_return_value(auto &state,
                                PolicyT &policy,
                                const CallFrame<ValueT> &frame,
                                const ValueT &ret_from_inst,
                                SchedT &sched) {
  if (policy.is_undefined(frame.return_ptr)) return ret_from_inst;

  uint32_t sz = 0;
  bool ret_is_float = false;
  if (auto fd = frame.func.declaration()) {
    auto rt = fd->return_type();
    if (auto bits = rt.size_in_bits()) {
      sz = static_cast<uint32_t>((*bits + 7) / 8);
    }
    if (auto bt = BuiltinType::from(rt)) {
      ret_is_float = bt->is_floating_point();
    }
  }

  if (sz > 0 && sz <= 8) {
    MemAccessHint hint{sz, ret_is_float, false};
    ValueT result = ret_from_inst;
    // The return pointer is a Value held in the callee frame, not an IR
    // operand of the RET; pass kInvalidEntityId to suppress suspension.
    policy.with_address(frame.return_ptr, policy.memory(), hint,
        kInvalidEntityId, state, sched,
        [&](auto &p, ConcreteMemory & /*mem*/, uint64_t a) {
          ValueT addr_val = p.make_literal_ptr(a);
          p.mem_read(sched, addr_val, hint, result);
        });
    return result;
  }
  if (sz > 8) return frame.return_ptr;
  return ret_from_inst;
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void exec_ret(auto &state, PolicyT &policy,
                     SchedT &sched, const IRInstruction &inst) {
  auto &frame = state.call_stack.top();
  // RET is a pure terminator — the return value (if any) lives in
  // the slot at `frame.return_ptr` where the IR's preceding
  // RETURN_PTR + MEMORY/STORE wrote it. The substrate's "default
  // value" sentinel stands in for the SSA-operand path the loop
  // used to take; `read_return_value` reads through the slot when
  // it is defined.
  ValueT ret_from_inst = ValueTraits<ValueT>::default_value();

  if (state.call_stack.depth() > 1) {
    ValueT callee_result = read_return_value<PolicyT, SchedT, ValueT>(
        state, policy, frame, ret_from_inst, sched);
    auto call_site = frame.call_site;
    state.call_stack.pop();
    if (call_site != kInvalidEntityId) {
      // Store in both caches: values (for within-block use) and
      // call_results (persistent across block transitions).
      state.call_stack.top().values[call_site] = callee_result;
      state.call_stack.top().call_results[call_site] = callee_result;
    }
    return;
  }

  // Top-level return.
  ValueT final_result = read_return_value<PolicyT, SchedT, ValueT>(
      state, policy, frame, ret_from_inst, sched);
  sched.on_completed(final_result,
                     state.clone());
  state.work_stack.clear();
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline void decide_cond_branch(auto &state, PolicyT &policy,
                               SchedT &sched, const IRInstruction &inst) {
  auto cb = CondBranchInst::from(inst);
  if (!cb) {
    sched.on_errored(ErrorKind::NO_TERMINATOR,
                     state.clone());
    state.work_stack.clear();
    return;
  }
  auto &frame = state.call_stack.top();
  ValueT cond = val<ValueT>(frame, cb->condition());

  // If condition operand isn't cached, push ANALYZE for it and retry.
  auto cond_eid = eid(cb->condition());
  if (!frame.values.count(cond_eid)) {
    state.work_stack.push_back({WorkKind::DECIDE_COND_BRANCH, inst, {}});
    state.work_stack.push_back({WorkKind::ANALYZE, cb->condition(), {}});
    return;
  }

  auto truth = policy.is_true(cond);
  if (truth.has_value()) {
    auto target = *truth ? cb->true_block() : cb->false_block();
    enter_block<PolicyT, ValueT>(state, policy, target);
    return;
  }

  // Unresolvable branch -> suspension continuation.
  IRBlock chosen;
  if (policy.resolve_branch(sched, inst, cond, cb->true_block(),
                            cb->false_block(), chosen)) {
    enter_block<PolicyT, ValueT>(state, policy, chosen);
    return;
  }

  // Bind-and-redispatch protocol (mirrors `with_address`):
  //   (1) re-push DECIDE_COND_BRANCH so the resumed state retries the
  //       same op with cond_eid now cached;
  //   (2) snapshot;
  //   (3) emit BranchContinuation;
  //   (4) clear the live work_stack so the current step halts.
  state.work_stack.push_back({WorkKind::DECIDE_COND_BRANCH, inst, {}});
  ValueT false_val = policy.make_literal_int(0, 1);
  ValueT true_val = policy.make_literal_int(1, 1);
  sched.on_branch(cond, cond_eid, cb->true_block(), cb->false_block(),
                  std::move(false_val), std::move(true_val),
                  state.clone());
  state.work_stack.clear();
}

template <typename PolicyT, typename ValueT>
inline void decide_switch(auto &state, PolicyT &policy,
                          const IRInstruction &inst) {
  auto sw = SwitchInst::from(inst);
  if (!sw) return;
  auto &frame = state.call_stack.top();

  // Ensure selector is cached.
  auto sel_eid = eid(sw->selector());
  if (!frame.values.count(sel_eid)) {
    state.work_stack.push_back({WorkKind::DECIDE_SWITCH, inst, {}});
    state.work_stack.push_back({WorkKind::ANALYZE, sw->selector(), {}});
    return;
  }

  ValueT sel = frame.values[sel_eid];
  int64_t sel_val = policy.extract_int(sel);
  IRBlock default_block{};
  for (auto sc : sw->cases()) {
    if (sc.is_default()) {
      default_block = sc.target_block();
      continue;
    }
    if (sel_val >= sc.low() && sel_val <= sc.high()) {
      enter_block<PolicyT, ValueT>(state, policy, sc.target_block());
      return;
    }
  }
  if (EntityId(default_block.id()).Pack()) {
    enter_block<PolicyT, ValueT>(state, policy, default_block);
  }
}

// ===========================================================================
// Main dispatch loop
// ===========================================================================

template <typename PolicyT, typename SchedT, typename ValueT>
inline void dispatch(auto &state, PolicyT &policy,
                     SchedT &sched, const WorkItem &item) {
  auto &frame = state.call_stack.top();

  // Fire the per-instruction observe hook for every work item that
  // represents a real instruction execution (not scheduling helpers).
  if (item.kind != WorkKind::ENTER_BLOCK &&
      item.kind != WorkKind::ANALYZE) {
    policy.on_instruction(state, sched, item.inst);
    if (policy.abort_requested()) {
      state.work_stack.clear();
      return;
    }
  }

  switch (item.kind) {
    case WorkKind::ENTER_BLOCK:
      enter_block<PolicyT, ValueT>(state, policy, item.block);
      break;

    case WorkKind::ANALYZE:
      analyze<ValueT>(state, item.inst);
      break;

    // --- Value computation ---
    case WorkKind::COMPUTE_CONST:
      ++state.steps;
      compute_const<PolicyT, SchedT, ValueT>(frame, policy, item.inst);
      break;
    case WorkKind::COMPUTE_ALLOCA:
      ++state.steps;
      compute_alloca<PolicyT, SchedT, ValueT>(state, policy, sched, item.inst);
      break;
    case WorkKind::COMPUTE_STRING_PTR:
      ++state.steps;
      compute_string_ptr<PolicyT, SchedT, ValueT>(state, policy, sched, item.inst);
      break;
    case WorkKind::COMPUTE_BINARY:
      ++state.steps;
      compute_binary<PolicyT, SchedT, ValueT>(frame, policy, item.inst);
      break;
    case WorkKind::COMPUTE_COMPARE:
      ++state.steps;
      compute_compare<PolicyT, SchedT, ValueT>(frame, policy, item.inst);
      break;
    case WorkKind::COMPUTE_UNARY:
      ++state.steps;
      compute_unary<PolicyT, SchedT, ValueT>(frame, policy, item.inst);
      break;
    case WorkKind::COMPUTE_CAST:
      ++state.steps;
      compute_cast<PolicyT, SchedT, ValueT>(frame, policy, item.inst);
      break;
    case WorkKind::COMPUTE_GEP_FIELD:
      ++state.steps;
      compute_gep_field<PolicyT, SchedT, ValueT>(frame, policy, item.inst);
      break;
    case WorkKind::COMPUTE_PTR_ADD:
      ++state.steps;
      compute_ptr_add<PolicyT, SchedT, ValueT>(frame, policy, item.inst);
      break;
    case WorkKind::COMPUTE_PTR_DIFF:
      ++state.steps;
      compute_ptr_diff<PolicyT, SchedT, ValueT>(frame, policy, item.inst);
      break;
    case WorkKind::COMPUTE_SELECT:
      ++state.steps;
      compute_select<PolicyT, SchedT, ValueT>(frame, policy, item.inst);
      break;
    case WorkKind::COMPUTE_LAST_VALUE:
      ++state.steps;
      compute_last_value<ValueT>(frame, item.inst);
      break;
    case WorkKind::COMPUTE_PARAM_PTR:
      ++state.steps;
      compute_param_ptr<ValueT>(frame, item.inst);
      break;
    case WorkKind::COMPUTE_BITWISE:
      ++state.steps;
      compute_bitwise<PolicyT, SchedT, ValueT>(frame, policy, item.inst);
      break;
    case WorkKind::COMPUTE_FLOAT_OP:
      ++state.steps;
      compute_float_op<PolicyT, SchedT, ValueT>(frame, policy, item.inst);
      break;
    case WorkKind::COMPUTE_GLOBAL_PTR:
      ++state.steps;
      compute_global_ptr<PolicyT, SchedT, ValueT>(state, policy, sched, item.inst);
      break;
    case WorkKind::COMPUTE_FUNC_PTR:
      ++state.steps;
      compute_func_ptr<PolicyT, SchedT, ValueT>(state, policy, sched, item.inst);
      break;
    case WorkKind::COMPUTE_RETURN_PTR:
      ++state.steps;
      frame.values[eid(item.inst)] = frame.return_ptr;
      break;
    case WorkKind::COMPUTE_UNDEFINED:
      ++state.steps;
      frame.values[eid(item.inst)] = ValueTraits<ValueT>::default_value();
      break;

    // --- Side effects ---
    case WorkKind::EXEC_LOAD:
      ++state.steps;
      exec_load<PolicyT, SchedT, ValueT>(state, policy, sched, item.inst);
      break;
    case WorkKind::EXEC_STORE:
      ++state.steps;
      exec_store<PolicyT, SchedT, ValueT>(state, policy, sched, item.inst);
      break;
    case WorkKind::EXEC_BULK_MEM:
      ++state.steps;
      exec_bulk_mem<PolicyT, SchedT, ValueT>(frame, policy, sched, item.inst);
      break;
    case WorkKind::EXEC_RMW:
      ++state.steps;
      exec_rmw<PolicyT, SchedT, ValueT>(state, policy, sched, item.inst);
      break;
    case WorkKind::EXEC_CALL:
      ++state.steps;
      exec_call<PolicyT, SchedT, ValueT>(state, policy, sched, item.inst);
      break;
    case WorkKind::EXEC_ENTER_SCOPE:
      ++state.steps;
      exec_enter_scope<PolicyT, SchedT, ValueT>(frame, policy, item.inst);
      break;
    case WorkKind::EXEC_EXIT_SCOPE:
      ++state.steps;
      exec_exit_scope<PolicyT, SchedT, ValueT>(frame, policy, item.inst);
      break;
    case WorkKind::EXEC_VA_START:
      ++state.steps;
      exec_va_start<PolicyT, SchedT, ValueT>(frame, policy, sched, item.inst);
      break;
    case WorkKind::EXEC_VA_END:
      ++state.steps;
      exec_va_end<PolicyT, SchedT, ValueT>(frame, policy, sched, item.inst);
      break;
    case WorkKind::EXEC_VA_COPY:
      ++state.steps;
      exec_va_copy<PolicyT, SchedT, ValueT>(frame, policy, sched, item.inst);
      break;
    case WorkKind::EXEC_CONSUME_VA_PARAM:
      ++state.steps;
      exec_consume_va_param<PolicyT, SchedT, ValueT>(frame, policy, sched, item.inst);
      break;

    // --- Control flow ---
    case WorkKind::DECIDE_COND_BRANCH:
      ++state.steps;
      decide_cond_branch<PolicyT, SchedT, ValueT>(state, policy, sched, item.inst);
      break;
    case WorkKind::DECIDE_SWITCH:
      ++state.steps;
      decide_switch<PolicyT, ValueT>(state, policy, item.inst);
      break;
    case WorkKind::EXEC_RET:
      ++state.steps;
      exec_ret<PolicyT, SchedT, ValueT>(state, policy, sched, item.inst);
      break;
    case WorkKind::EXEC_GOTO:
      ++state.steps;
      exec_goto<PolicyT, ValueT>(state, policy, item.inst);
      break;
    case WorkKind::EXEC_UNREACHABLE:
      ++state.steps;
      sched.on_errored(ErrorKind::UNREACHABLE,
                       state.clone());
      state.work_stack.clear();
      break;
  }
}

// ===========================================================================
// Top-level entry points — free template functions matching the
// ConcretePolicy::init_state() and ConcretePolicy::step() signatures.
// ===========================================================================

template <typename PolicyT, typename SchedT, typename ValueT>
inline void interp_init_state(PolicyT &policy, SchedT &sched,
                              auto &state,
                              const IRFunction &func,
                              const std::vector<ValueT> &args) {
  state.call_stack = CallStack<ValueT>();
  state.global_addresses.clear();
  state.function_addresses.clear();
  state.steps = 0;
  state.work_stack.clear();

  CallFrame<ValueT> frame;
  frame.func = func;
  frame.params = args;

  // Allocate parameter storage.
  uint32_t param_idx = 0;
  for (auto obj : func.objects()) {
    auto k = obj.kind();
    if (k == ir::ObjectKind::PARAMETER ||
        k == ir::ObjectKind::PARAMETER_VALUE) {
      uint32_t size = obj.size_bytes();
      if (size == 0) size = 8;
      uint32_t align = obj.align_bytes();
      if (align == 0) align = 8;
      ValueT addr = policy.mem_allocate(sched, size, align);
      // mem_allocate-derived addresses are concrete by construction.
      if (auto a = policy.extract_address(addr)) {
        frame.locals[EntityId(obj.id()).Pack()] = *a;
        if (param_idx < args.size()) {
          bool param_is_float = false;
          if (auto obj_type = obj.type()) {
            if (auto bt = BuiltinType::from(*obj_type)) {
              param_is_float = bt->is_floating_point();
            }
          }
          MemAccessHint w_hint{size, param_is_float, true};
          bool memcpyed = false;
          if (size > 8) {
            // Init-time bulk copy: cannot resume from a symbolic source
            // pointer here, so suppress suspension via kInvalidEntityId.
            policy.with_address(args[param_idx], policy.memory(), w_hint,
                kInvalidEntityId, state, sched,
                [&](auto &p, ConcreteMemory &mem, uint64_t arg_addr) {
                  mem.memcpy(*a, arg_addr, size);
                  memcpyed = true;
                  (void)p;
                });
          }
          if (!memcpyed) {
            policy.mem_write(sched, addr, args[param_idx], w_hint);
          }
        }
      }
      frame.param_ptrs.push_back(addr);
      ++param_idx;
    }
  }

  if (func.kind() == ir::FunctionKind::GLOBAL_INITIALIZER) {
    for (auto &a : args) frame.param_ptrs.push_back(a);
    param_idx = static_cast<uint32_t>(args.size());
  }

  frame.variadic_start_index = param_idx;
  for (uint32_t i = param_idx; i < args.size(); ++i) {
    ValueT addr = policy.mem_allocate(sched, 8, 8);
    MemAccessHint hint{8, false, true};
    policy.mem_write(sched, addr, args[i], hint);
    frame.param_ptrs.push_back(addr);
  }

  if (policy.is_undefined(frame.return_ptr)) {
    if (auto fd = func.declaration()) {
      auto rt = fd->return_type();
      if (auto bits = rt.size_in_bits()) {
        uint32_t sz = static_cast<uint32_t>((*bits + 7) / 8);
        if (sz > 0) frame.return_ptr = policy.mem_allocate(sched, sz, 8);
      }
    }
  }

  state.call_stack.push(std::move(frame));
  state.work_stack.push_back({WorkKind::ENTER_BLOCK, {},
                              func.entry_block()});
}

// Variant that uses pre-allocated parameter/return addresses.
// Values must already be written into memory at those addresses.
template <typename PolicyT, typename SchedT, typename ValueT>
inline void interp_init_state_prealloc(
    PolicyT &policy, SchedT &sched,
    auto &state,
    const IRFunction &func,
    const std::vector<uint64_t> &param_addrs,
    std::optional<uint64_t> return_addr) {

  state.call_stack = CallStack<ValueT>();
  state.global_addresses.clear();
  state.function_addresses.clear();
  state.steps = 0;
  state.work_stack.clear();

  CallFrame<ValueT> frame;
  frame.func = func;

  // Map IR objects to pre-allocated addresses.
  uint32_t param_idx = 0;
  for (auto obj : func.objects()) {
    auto k = obj.kind();
    if (k == ir::ObjectKind::PARAMETER ||
        k == ir::ObjectKind::PARAMETER_VALUE) {
      if (param_idx < param_addrs.size()) {
        uint64_t addr = param_addrs[param_idx];
        frame.locals[EntityId(obj.id()).Pack()] = addr;
        frame.param_ptrs.push_back(policy.make_literal_ptr(addr));
      } else {
        frame.param_ptrs.push_back(
            ValueTraits<ValueT>::default_value());
      }
      ++param_idx;
    }
  }

  frame.variadic_start_index = param_idx;

  if (return_addr) {
    frame.return_ptr = policy.make_literal_ptr(*return_addr);
  } else {
    if (auto fd = func.declaration()) {
      auto rt = fd->return_type();
      if (auto bits = rt.size_in_bits()) {
        uint32_t sz = static_cast<uint32_t>((*bits + 7) / 8);
        if (sz > 0) frame.return_ptr = policy.mem_allocate(sched, sz, 8);
      }
    }
  }

  state.call_stack.push(std::move(frame));
  state.work_stack.push_back({WorkKind::ENTER_BLOCK, {},
                              func.entry_block()});
}

// Variant for mid-block (under-constrained) entry. Like _prealloc, but
// starts execution at a chosen block with a caller-supplied seed of
// live-in values (eid -> ValueT). The seed survives ENTER_BLOCK because
// we push the block's work items directly via push_block_work_items
// after seeding frame.values, bypassing the cache-clearing path that
// the work-stack ENTER_BLOCK handler would take.
template <typename PolicyT, typename SchedT, typename ValueT>
inline void interp_init_state_at(
    PolicyT &policy, SchedT &sched,
    auto &state,
    const IRFunction &func,
    const IRBlock &block,
    const std::vector<uint64_t> &param_addrs,
    std::optional<uint64_t> return_addr,
    const std::unordered_map<RawEntityId, ValueT> &value_seed) {

  state.call_stack = CallStack<ValueT>();
  state.global_addresses.clear();
  state.function_addresses.clear();
  state.steps = 0;
  state.work_stack.clear();

  CallFrame<ValueT> frame;
  frame.func = func;

  uint32_t param_idx = 0;
  for (auto obj : func.objects()) {
    auto k = obj.kind();
    if (k == ir::ObjectKind::PARAMETER ||
        k == ir::ObjectKind::PARAMETER_VALUE) {
      if (param_idx < param_addrs.size()) {
        uint64_t addr = param_addrs[param_idx];
        frame.locals[EntityId(obj.id()).Pack()] = addr;
        frame.param_ptrs.push_back(policy.make_literal_ptr(addr));
      } else {
        frame.param_ptrs.push_back(
            ValueTraits<ValueT>::default_value());
      }
      ++param_idx;
    }
  }

  frame.variadic_start_index = param_idx;

  if (return_addr) {
    frame.return_ptr = policy.make_literal_ptr(*return_addr);
  } else {
    if (auto fd = func.declaration()) {
      auto rt = fd->return_type();
      if (auto bits = rt.size_in_bits()) {
        uint32_t sz = static_cast<uint32_t>((*bits + 7) / 8);
        if (sz > 0) frame.return_ptr = policy.mem_allocate(sched, sz, 8);
      }
    }
  }

  // Pre-seed the instruction-result cache for live-in values of the
  // chosen block. These represent values that, in normal flow, would
  // have been computed by predecessor blocks; we materialize them
  // directly so analyze() short-circuits when it sees them cached.
  for (const auto &kv : value_seed) {
    frame.values[kv.first] = kv.second;
  }

  state.call_stack.push(std::move(frame));

  // Push the block's work items directly, skipping the work-stack
  // ENTER_BLOCK handler that would clear frame.values.
  push_block_work_items<ValueT>(state, block);
}

template <typename PolicyT, typename SchedT, typename ValueT>
inline bool interp_step(PolicyT &policy, SchedT &sched,
                        auto &state,
                        uint64_t max_steps) {
  uint64_t target = state.steps + max_steps;
  uint64_t iters = 0;
  while (!state.work_stack.empty() && state.steps < target) {
    if (state.work_stack.size() > 100000) {
      (void) fprintf(stderr, "ABORT: work stack overflow (%zu items)\n",
                     state.work_stack.size());
      sched.on_errored(ErrorKind::NO_TERMINATOR,
                       state.clone());
      state.work_stack.clear();
      return false;
    }
    auto item = state.work_stack.back();
    state.work_stack.pop_back();
    state.current_item = item;
    dispatch<PolicyT, SchedT, ValueT>(state, policy, sched, item);
    if (policy.abort_requested()) {
      state.work_stack.clear();
      break;
    }
    if (++iters > max_steps * 100) {
      // Safety: abort if the work stack is churning without stepping.
      sched.on_errored(ErrorKind::NO_TERMINATOR,
                       state.clone());
      state.work_stack.clear();
      return false;
    }
  }
  return !state.work_stack.empty();
}

}  // namespace mx::ir::interpret
