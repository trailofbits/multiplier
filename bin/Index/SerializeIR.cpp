// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "SerializeIR.h"
#include "IRGen.h"
#include "EntityMapper.h"
#include "PendingFragment.h"
#include "ProgressBar.h"

#include <multiplier/IR.capnp.h>
#include <multiplier/RPC.capnp.h>
#include <pasta/AST/Decl.h>

#include <glog/logging.h>

namespace indexer {
namespace {

using mx::RawEntityId;
using mx::kInvalidEntityId;

// Helpers to construct entity IDs with embedded kind/opcode.
static RawEntityId MakeBlockEid(
    const ir::FunctionIR &func, RawEntityId fragment_id,
    uint32_t ir_block_base_offset, uint32_t local_block_idx) {
  auto bk = static_cast<uint8_t>(func.blocks[local_block_idx].kind);
  mx::IRBlockId bid{fragment_id, ir_block_base_offset + local_block_idx, bk};
  return mx::EntityId(bid).Pack();
}

static RawEntityId MakeInstEid(
    const ir::FunctionIR &func, RawEntityId fragment_id,
    uint32_t ir_inst_base_offset, uint32_t local_inst_idx) {
  auto op = static_cast<uint8_t>(func.instructions[local_inst_idx].opcode);
  mx::IRInstructionId iid{fragment_id, ir_inst_base_offset + local_inst_idx, op};
  return mx::EntityId(iid).Pack();
}

static RawEntityId MakeObjEid(RawEntityId fragment_id,
                               uint32_t ir_obj_base_offset,
                               uint32_t local_obj_idx) {
  mx::IRObjectId oid{fragment_id, ir_obj_base_offset + local_obj_idx};
  return mx::EntityId(oid).Pack();
}

// Pool builder: accumulates entity IDs and int values, returns offsets.
struct PoolBuilder {
  std::vector<uint64_t> entities;
  std::vector<int64_t> ints;

  uint32_t AddEntity(uint64_t eid) {
    uint32_t offset = static_cast<uint32_t>(entities.size());
    entities.push_back(eid);
    return offset;
  }

  uint32_t EntitySize() const {
    return static_cast<uint32_t>(entities.size());
  }

  uint32_t AddInt(int64_t val) {
    uint32_t offset = static_cast<uint32_t>(ints.size());
    ints.push_back(val);
    return offset;
  }

  uint32_t IntSize() const {
    return static_cast<uint32_t>(ints.size());
  }
};

// Determine number of extra entity pool entries after operands, based on opcode.
static void EmitInstructionExtras(
    PoolBuilder &pool,
    const ir::InstructionIR &inst,
    const ir::FunctionIR &func,
    RawEntityId fragment_id,
    uint32_t obj_base, uint32_t block_base, uint32_t inst_base) {

  using OC = mx::ir::OpCode;

  switch (inst.opcode) {
    case OC::CALL:
      pool.AddEntity(inst.target_entity_id);
      break;

    case OC::GEP_FIELD:
      pool.AddEntity(inst.target_entity_id);
      pool.AddEntity(inst.type_entity_id);
      break;

    case OC::PTR_ADD:
      pool.AddEntity(inst.type_entity_id);
      break;

    case OC::LOAD:
    case OC::CAST_SEXT: case OC::CAST_ZEXT: case OC::CAST_TRUNC:
    case OC::CAST_BITCAST: case OC::CAST_PTR_TO_INT: case OC::CAST_INT_TO_PTR:
    case OC::CAST_FP_TO_SI: case OC::CAST_SI_TO_FP: case OC::CAST_FP_TRUNC:
    case OC::CAST_FP_EXT: case OC::CAST_INT_CAST: case OC::CAST_FP_CAST:
    case OC::VA_ARG:
      pool.AddEntity(inst.type_entity_id);
      break;

    case OC::ALLOCA:
    case OC::ADDRESS_OF:
      pool.AddEntity(MakeObjEid(fragment_id, obj_base, inst.object_index));
      break;

    case OC::SIZE_OF:
      pool.AddEntity(inst.type_entity_id);
      break;

    case OC::COND_BRANCH:
      for (auto &bt : inst.branch_targets) {
        pool.AddEntity(MakeBlockEid(func, fragment_id, block_base,
                                     bt.block_index));
      }
      break;

    case OC::GOTO: case OC::IMPLICIT_GOTO:
    case OC::BREAK: case OC::CONTINUE:
    case OC::FALLTHROUGH: case OC::IMPLICIT_FALLTHROUGH:
      for (auto &bt : inst.branch_targets) {
        pool.AddEntity(MakeBlockEid(func, fragment_id, block_base,
                                     bt.block_index));
      }
      break;

    case OC::SWITCH:
      for (auto &bt : inst.branch_targets) {
        pool.AddEntity(MakeBlockEid(func, fragment_id, block_base,
                                     bt.block_index));
      }
      break;

    default:
      break;
  }
}

static uint32_t EmitInstructionConsts(
    PoolBuilder &pool,
    const ir::InstructionIR &inst) {

  using OC = mx::ir::OpCode;
  uint32_t offset = pool.IntSize();

  switch (inst.opcode) {
    case OC::CONST_INT:
      pool.AddInt(inst.int_value);
      pool.AddInt(static_cast<int64_t>(inst.uint_value));
      break;

    case OC::CONST_FLOAT: {
      int64_t bits;
      static_assert(sizeof(double) == sizeof(int64_t));
      memcpy(&bits, &inst.float_value, sizeof(bits));
      pool.AddInt(bits);
      break;
    }

    case OC::SWITCH:
      for (auto v : inst.switch_values) {
        pool.AddInt(v);
      }
      break;

    case OC::GEP_FIELD:
      pool.AddInt(static_cast<int64_t>(inst.size_bytes));  // byte offset
      break;

    case OC::PTR_ADD:
      pool.AddInt(static_cast<int64_t>(inst.size_bytes));  // element size
      break;

    case OC::COMPOUND_ASSIGN:
      pool.AddInt(static_cast<int64_t>(inst.compound_op));
      break;

    case OC::INC_DEC:
      pool.AddInt(static_cast<int64_t>(inst.size_bytes));  // ptr element size
      break;

    default:
      return offset;  // no constants
  }

  return offset;
}

}  // namespace

std::vector<ir::FunctionIR> GenerateIR(
    const pasta::AST &ast,
    const PendingFragment &pf,
    EntityMapper &em,
    const std::unique_ptr<ProgressBar> &progress) {

  std::vector<ir::FunctionIR> ir_functions;
  RawEntityId fragment_id = pf.fragment_id.Unpack().fragment_id;

  uint32_t inst_offset = 0;

  for (const auto &decl : pf.top_level_decls) {
    auto func = pasta::FunctionDecl::From(decl);
    if (!func || !func->Body()) continue;

    ProgressBarWork ir_tracker(progress);
    ir::IRGenerator gen(ast, em);
    auto ir = gen.Generate(*func);
    if (!ir) {
      DCHECK(false) << "IR generation returned nullopt for function with body";
      continue;
    }

    for (uint32_t i = 0; i < ir->instructions.size(); ++i) {
      auto &inst = ir->instructions[i];
      if (inst.source_entity_id != mx::kInvalidEntityId) {
        auto ir_eid = mx::EntityId(mx::IRInstructionId{
            fragment_id, inst_offset + i,
            static_cast<uint8_t>(inst.opcode)}).Pack();
        em.ir_for_entity[inst.source_entity_id] = ir_eid;
      }
    }

    inst_offset += static_cast<uint32_t>(ir->instructions.size());
    ir_functions.push_back(std::move(*ir));
  }

  return ir_functions;
}

void SerializeIR(
    const std::vector<ir::FunctionIR> &ir_functions,
    const PendingFragment &pf,
    mx::rpc::Fragment::Builder &fb) {

  if (ir_functions.empty()) return;

  RawEntityId fragment_id = pf.fragment_id.Unpack().fragment_id;

  // Count totals.
  uint32_t total_blocks = 0;
  uint32_t total_instructions = 0;
  uint32_t total_objects = 0;
  for (const auto &func : ir_functions) {
    total_blocks += static_cast<uint32_t>(func.blocks.size());
    total_instructions += static_cast<uint32_t>(func.instructions.size());
    total_objects += static_cast<uint32_t>(func.objects.size());
  }

  // Build the pools.
  PoolBuilder pool;

  // Pre-allocate output lists.
  auto frag_funcs = fb.initIrFunctions(ir_functions.size());
  auto frag_blocks = fb.initIrBlocks(total_blocks);
  auto frag_insts = fb.initIrInstructions(total_instructions);
  auto frag_objs = fb.initIrObjects(total_objects);

  uint32_t block_offset = 0;
  uint32_t inst_offset = 0;
  uint32_t obj_offset = 0;

  for (size_t fi = 0; fi < ir_functions.size(); ++fi) {
    const auto &func = ir_functions[fi];

    // Serialize objects.
    for (size_t oi = 0; oi < func.objects.size(); ++oi) {
      auto &src = func.objects[oi];
      auto ob = frag_objs[obj_offset + oi];
      ob.setSourceDeclId(src.source_decl_id);
      ob.setTypeEntityId(src.type_entity_id);
      ob.setSizeBytes(src.size_bytes);
      ob.setAlignBytes(src.align_bytes);
      ob.setKind(static_cast<uint8_t>(src.kind));
    }

    // Serialize instructions.
    for (size_t ii = 0; ii < func.instructions.size(); ++ii) {
      const auto &src = func.instructions[ii];
      auto ib = frag_insts[inst_offset + ii];

      // Entity pool: [parentBlockId, sourceEntityId, op0..opN, ...extras]
      uint32_t ent_start = pool.EntitySize();
      pool.AddEntity(MakeBlockEid(func, fragment_id, block_offset,
                                   src.parent_block_index));
      pool.AddEntity(src.source_entity_id);
      for (auto op_idx : src.operand_indices) {
        pool.AddEntity(MakeInstEid(func, fragment_id, inst_offset, op_idx));
      }
      EmitInstructionExtras(pool, src, func, fragment_id,
                            obj_offset, block_offset, inst_offset);

      // Int pool.
      uint32_t const_start = EmitInstructionConsts(pool, src);

      ib.setEntityOffset(ent_start);
      ib.setConstOffset(const_start);
      ib.setParentOffset(static_cast<uint16_t>(src.parent_offset));
      ib.setNumOperands(static_cast<uint8_t>(src.operand_indices.size()));
      ib.setOpcode(static_cast<uint8_t>(src.opcode));
      ib.setConstWidth(src.width);
      ib.setFlags(src.flags);
    }

    // Serialize blocks.
    for (size_t bi = 0; bi < func.blocks.size(); ++bi) {
      const auto &src = func.blocks[bi];
      auto bb = frag_blocks[block_offset + bi];

      uint32_t ent_start = pool.EntitySize();

      // Instructions.
      for (auto idx : src.instruction_indices) {
        pool.AddEntity(MakeInstEid(func, fragment_id, inst_offset, idx));
      }

      // Successors.
      for (auto idx : src.successor_indices) {
        pool.AddEntity(MakeBlockEid(func, fragment_id, block_offset, idx));
      }

      // Predecessors.
      for (auto idx : src.predecessor_indices) {
        pool.AddEntity(MakeBlockEid(func, fragment_id, block_offset, idx));
      }

      // Dominators (first = immediate dominator).
      if (src.immediate_dominator != UINT32_MAX) {
        pool.AddEntity(MakeBlockEid(func, fragment_id, block_offset,
                                     src.immediate_dominator));
      }
      for (auto idx : src.dominator_indices) {
        if (idx != src.immediate_dominator) {
          pool.AddEntity(MakeBlockEid(func, fragment_id, block_offset, idx));
        }
      }

      // Post-dominators (first = immediate post-dominator).
      if (src.immediate_post_dominator != UINT32_MAX) {
        pool.AddEntity(MakeBlockEid(func, fragment_id, block_offset,
                                     src.immediate_post_dominator));
      }
      for (auto idx : src.post_dominator_indices) {
        if (idx != src.immediate_post_dominator) {
          pool.AddEntity(MakeBlockEid(func, fragment_id, block_offset, idx));
        }
      }

      uint16_t num_doms = (src.immediate_dominator != UINT32_MAX ? 1 : 0)
          + static_cast<uint16_t>(src.dominator_indices.size()
              - (src.immediate_dominator != UINT32_MAX ? 1 : 0));
      uint16_t num_pdoms = (src.immediate_post_dominator != UINT32_MAX ? 1 : 0)
          + static_cast<uint16_t>(src.post_dominator_indices.size()
              - (src.immediate_post_dominator != UINT32_MAX ? 1 : 0));

      bb.setEntityOffset(ent_start);
      bb.setNumInstructions(static_cast<uint16_t>(src.instruction_indices.size()));
      bb.setNumSuccessors(static_cast<uint16_t>(src.successor_indices.size()));
      bb.setNumPredecessors(static_cast<uint16_t>(src.predecessor_indices.size()));
      bb.setNumDominators(num_doms);
      bb.setNumPostDominators(num_pdoms);
      bb.setKind(static_cast<uint8_t>(src.kind));
    }

    // Serialize function.
    {
      auto ffb = frag_funcs[fi];
      ffb.setFuncDeclEntityId(func.func_decl_entity_id);
      ffb.setEntryBlockId(MakeBlockEid(func, fragment_id, block_offset,
                                        func.entry_block_index));

      // Function's block and object lists go into the entity pool.
      uint32_t func_ent_start = pool.EntitySize();
      for (auto idx : func.rpo_block_order) {
        pool.AddEntity(MakeBlockEid(func, fragment_id, block_offset, idx));
      }
      for (uint32_t oi = 0; oi < func.objects.size(); ++oi) {
        pool.AddEntity(MakeObjEid(fragment_id, obj_offset, oi));
      }
      ffb.setEntityOffset(func_ent_start);
      ffb.setNumBlocks(static_cast<uint16_t>(func.rpo_block_order.size()));
      ffb.setNumObjects(static_cast<uint16_t>(func.objects.size()));
    }

    block_offset += static_cast<uint32_t>(func.blocks.size());
    inst_offset += static_cast<uint32_t>(func.instructions.size());
    obj_offset += static_cast<uint32_t>(func.objects.size());
  }

  // Write the pools into the fragment.
  auto ep = fb.initIrEntityPool(pool.entities.size());
  for (size_t i = 0; i < pool.entities.size(); ++i) {
    ep.set(i, pool.entities[i]);
  }

  auto ip = fb.initIrIntPool(pool.ints.size());
  for (size_t i = 0; i < pool.ints.size(); ++i) {
    ip.set(i, pool.ints[i]);
  }
}

}  // namespace indexer
