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
static mx::RawEntityId MakeBlockEid(
    const ir::FunctionIR &func, RawEntityId fragment_id,
    uint32_t ir_block_base_offset, uint32_t local_block_idx) {
  auto bk = static_cast<uint8_t>(func.blocks[local_block_idx].kind);
  mx::IRBlockId bid{fragment_id, ir_block_base_offset + local_block_idx, bk};
  return mx::EntityId(bid).Pack();
}

static mx::RawEntityId MakeInstEid(
    const ir::FunctionIR &func, RawEntityId fragment_id,
    uint32_t ir_inst_base_offset, uint32_t local_inst_idx) {
  auto op = static_cast<uint8_t>(func.instructions[local_inst_idx].opcode);
  mx::IRInstructionId iid{fragment_id, ir_inst_base_offset + local_inst_idx, op};
  return mx::EntityId(iid).Pack();
}

static void SerializeBranchTarget(
    mx::rpc::ir::BranchTarget::Builder bt,
    const ir::BranchTargetIR &src,
    const ir::FunctionIR &func,
    RawEntityId fragment_id,
    uint32_t ir_block_base_offset,
    uint32_t ir_inst_base_offset) {

  bt.setBlockId(MakeBlockEid(func, fragment_id, ir_block_base_offset,
                              src.block_index));

  auto args = bt.initArgs(src.arg_indices.size());
  for (size_t i = 0; i < src.arg_indices.size(); ++i) {
    args.set(i, MakeInstEid(func, fragment_id, ir_inst_base_offset,
                             src.arg_indices[i]));
  }
}

static void SerializeInstruction(
    mx::rpc::ir::Instruction::Builder ib,
    const ir::InstructionIR &src,
    const ir::FunctionIR &func,
    RawEntityId fragment_id,
    uint32_t ir_obj_base_offset,
    uint32_t ir_block_base_offset,
    uint32_t ir_inst_base_offset) {

  ib.setOpcode(static_cast<uint8_t>(src.opcode));
  ib.setSourceEntityId(src.source_entity_id);

  auto ops = ib.initOperands(src.operand_indices.size());
  for (size_t i = 0; i < src.operand_indices.size(); ++i) {
    ops.set(i, MakeInstEid(func, fragment_id, ir_inst_base_offset,
                            src.operand_indices[i]));
  }

  if (src.opcode == mx::ir::OpCode::ALLOCA ||
      src.opcode == mx::ir::OpCode::ADDRESS_OF) {
    mx::IRObjectId oid{fragment_id, ir_obj_base_offset + src.object_index};
    ib.setObjectId(mx::EntityId(oid).Pack());
  }

  ib.setTypeEntityId(src.type_entity_id);
  ib.setTargetEntityId(src.target_entity_id);
  ib.setIntValue(src.int_value);
  ib.setUintValue(src.uint_value);
  ib.setFloatValue(src.float_value);
  ib.setWidth(src.width);
  ib.setSizeBytes(src.size_bytes);
  ib.setFlags(src.flags);
  ib.setCompoundOp(static_cast<uint8_t>(src.compound_op));
  ib.setParentOffset(src.parent_offset);

  ib.setParentBlockId(MakeBlockEid(func, fragment_id, ir_block_base_offset,
                                    src.parent_block_index));

  if (!src.branch_targets.empty()) {
    auto bts = ib.initBranchTargets(src.branch_targets.size());
    for (size_t i = 0; i < src.branch_targets.size(); ++i) {
      SerializeBranchTarget(bts[i], src.branch_targets[i], func, fragment_id,
                            ir_block_base_offset, ir_inst_base_offset);
    }
  }

  if (!src.switch_values.empty()) {
    auto svs = ib.initSwitchValues(src.switch_values.size());
    for (size_t i = 0; i < src.switch_values.size(); ++i) {
      svs.set(i, src.switch_values[i]);
    }
  }
}

static void SerializeBlock(
    mx::rpc::ir::Block::Builder bb,
    const ir::BlockIR &src,
    const ir::FunctionIR &func,
    RawEntityId fragment_id,
    uint32_t ir_block_base_offset,
    uint32_t ir_inst_base_offset) {

  bb.setKind(static_cast<uint8_t>(src.kind));

  auto insts = bb.initInstructions(src.instruction_indices.size());
  for (size_t i = 0; i < src.instruction_indices.size(); ++i) {
    insts.set(i, MakeInstEid(func, fragment_id, ir_inst_base_offset,
                              src.instruction_indices[i]));
  }
  bb.setNumArguments(src.num_arguments);

  auto succs = bb.initSuccessors(src.successor_indices.size());
  for (size_t i = 0; i < src.successor_indices.size(); ++i) {
    succs.set(i, MakeBlockEid(func, fragment_id, ir_block_base_offset,
                               src.successor_indices[i]));
  }

  auto preds = bb.initPredecessors(src.predecessor_indices.size());
  for (size_t i = 0; i < src.predecessor_indices.size(); ++i) {
    preds.set(i, MakeBlockEid(func, fragment_id, ir_block_base_offset,
                               src.predecessor_indices[i]));
  }

  auto doms = bb.initDominators(src.dominator_indices.size());
  for (size_t i = 0; i < src.dominator_indices.size(); ++i) {
    doms.set(i, MakeBlockEid(func, fragment_id, ir_block_base_offset,
                              src.dominator_indices[i]));
  }

  auto pdoms = bb.initPostDominators(src.post_dominator_indices.size());
  for (size_t i = 0; i < src.post_dominator_indices.size(); ++i) {
    pdoms.set(i, MakeBlockEid(func, fragment_id, ir_block_base_offset,
                               src.post_dominator_indices[i]));
  }

  if (src.immediate_dominator != UINT32_MAX) {
    bb.setImmediateDominator(MakeBlockEid(func, fragment_id,
                                           ir_block_base_offset,
                                           src.immediate_dominator));
  }

  if (src.immediate_post_dominator != UINT32_MAX) {
    bb.setImmediatePostDominator(MakeBlockEid(func, fragment_id,
                                               ir_block_base_offset,
                                               src.immediate_post_dominator));
  }
}

static void SerializeFunction(
    mx::rpc::ir::Function::Builder fb,
    const ir::FunctionIR &src,
    RawEntityId fragment_id,
    uint32_t ir_block_base_offset,
    uint32_t ir_obj_base_offset) {

  fb.setFuncDeclEntityId(src.func_decl_entity_id);

  auto blocks = fb.initBlocks(src.rpo_block_order.size());
  for (size_t i = 0; i < src.rpo_block_order.size(); ++i) {
    blocks.set(i, MakeBlockEid(src, fragment_id, ir_block_base_offset,
                                src.rpo_block_order[i]));
  }

  auto objs = fb.initObjects(src.objects.size());
  for (size_t i = 0; i < src.objects.size(); ++i) {
    mx::IRObjectId oid{fragment_id,
                        ir_obj_base_offset + static_cast<uint32_t>(i)};
    objs.set(i, mx::EntityId(oid).Pack());
  }

  fb.setEntryBlockId(MakeBlockEid(src, fragment_id, ir_block_base_offset,
                                   src.entry_block_index));
}

// Serialize an ObjectIR into a capnp Object builder.
static void SerializeObject(
    mx::rpc::ir::Object::Builder ob,
    const ir::ObjectIR &src) {

  ob.setSourceDeclId(src.source_decl_id);
  // Name accessible via sourceDeclId -> NamedDecl::Name()
  ob.setTypeEntityId(src.type_entity_id);
  ob.setSizeBytes(src.size_bytes);
  ob.setAlignBytes(src.align_bytes);
  ob.setKind(static_cast<uint8_t>(src.kind));
}

}  // namespace

void GenerateAndSerializeIR(
    const pasta::AST &ast,
    const PendingFragment &pf,
    const EntityMapper &em,
    mx::rpc::Fragment::Builder &fb,
    const std::unique_ptr<ProgressBar> &progress) {

  std::vector<ir::FunctionIR> ir_functions;

  for (const auto &decl : pf.top_level_decls) {
    auto func = pasta::FunctionDecl::From(decl);
    if (!func || !func->Body()) continue;

    ProgressBarWork ir_tracker(progress);
    ir::IRGenerator gen(ast, em);
    auto ir = gen.Generate(*func);
    if (ir) {
      ir_functions.push_back(std::move(*ir));
    } else {
      DCHECK(false) << "IR generation returned nullopt for function with body";
    }
  }

  if (ir_functions.empty()) return;

  // Count total IR entities across all functions.
  uint32_t total_blocks = 0;
  uint32_t total_instructions = 0;
  uint32_t total_objects = 0;
  for (const auto &func : ir_functions) {
    total_blocks += static_cast<uint32_t>(func.blocks.size());
    total_instructions += static_cast<uint32_t>(func.instructions.size());
    total_objects += static_cast<uint32_t>(func.objects.size());
  }

  // Initialize the flat lists in the fragment.
  auto frag_funcs = fb.initIrFunctions(ir_functions.size());
  auto frag_blocks = fb.initIrBlocks(total_blocks);
  auto frag_insts = fb.initIrInstructions(total_instructions);
  auto frag_objs = fb.initIrObjects(total_objects);

  RawEntityId fragment_id = pf.fragment_id.Unpack().fragment_id;

  uint32_t block_offset = 0;
  uint32_t inst_offset = 0;
  uint32_t obj_offset = 0;

  for (size_t fi = 0; fi < ir_functions.size(); ++fi) {
    const auto &func = ir_functions[fi];

    // Serialize objects.
    for (size_t oi = 0; oi < func.objects.size(); ++oi) {
      SerializeObject(frag_objs[obj_offset + oi], func.objects[oi]);
    }

    // Serialize instructions.
    for (size_t ii = 0; ii < func.instructions.size(); ++ii) {
      SerializeInstruction(frag_insts[inst_offset + ii],
                           func.instructions[ii], func,
                           fragment_id, obj_offset,
                           block_offset, inst_offset);
    }

    // Serialize blocks.
    for (size_t bi = 0; bi < func.blocks.size(); ++bi) {
      SerializeBlock(frag_blocks[block_offset + bi],
                     func.blocks[bi], func,
                     fragment_id, block_offset, inst_offset);
    }

    // Serialize function.
    SerializeFunction(frag_funcs[fi], func,
                      fragment_id, block_offset, obj_offset);

    block_offset += static_cast<uint32_t>(func.blocks.size());
    inst_offset += static_cast<uint32_t>(func.instructions.size());
    obj_offset += static_cast<uint32_t>(func.objects.size());
  }
}

}  // namespace indexer
