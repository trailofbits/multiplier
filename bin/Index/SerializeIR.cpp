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
  CHECK(local_block_idx < func.blocks.size())
      << "MakeBlockEid: local_block_idx=" << local_block_idx
      << " >= blocks.size()=" << func.blocks.size();
  auto bk = func.blocks[local_block_idx].kind;
  mx::IRBlockId bid{fragment_id, ir_block_base_offset + local_block_idx, bk};
  return mx::EntityId(bid).Pack();
}

static RawEntityId MakeInstEid(
    const ir::FunctionIR &func, RawEntityId fragment_id,
    uint32_t ir_inst_base_offset, uint32_t local_inst_idx) {
  auto op = func.instructions[local_inst_idx].opcode;
  mx::IRInstructionId iid{fragment_id, ir_inst_base_offset + local_inst_idx, op};
  return mx::EntityId(iid).Pack();
}

static RawEntityId MakeObjEid(RawEntityId fragment_id,
                               uint32_t ir_obj_base_offset,
                               uint32_t local_obj_idx) {
  mx::IRObjectId oid{fragment_id, ir_obj_base_offset + local_obj_idx};
  return mx::EntityId(oid).Pack();
}

static RawEntityId MakeStructureEid(
    const ir::FunctionIR &func, RawEntityId fragment_id,
    uint32_t ir_struct_base_offset, uint32_t local_struct_idx) {
  auto sk = func.structures[local_struct_idx].kind;
  mx::IRStructureId sid{fragment_id, ir_struct_base_offset + local_struct_idx, sk};
  return mx::EntityId(sid).Pack();
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
    uint32_t obj_base, uint32_t block_base, uint32_t inst_base,
    uint32_t struct_base) {

  using OC = mx::ir::OpCode;

  switch (inst.opcode) {
    case OC::CALL:
      pool.AddEntity(inst.target_entity_id);
      // Return alloca instruction ID (kInvalidEntityId for void calls).
      if (inst.return_alloca_index != UINT32_MAX) {
        pool.AddEntity(MakeInstEid(func, fragment_id, inst_base,
                                    inst.return_alloca_index));
      } else {
        pool.AddEntity(mx::kInvalidEntityId);
      }
      break;

    case OC::GEP_FIELD_32: case OC::GEP_FIELD_64:
      pool.AddEntity(inst.target_entity_id);
      pool.AddEntity(inst.type_entity_id);
      break;

    case OC::PTR_ADD_32: case OC::PTR_ADD_64:
      pool.AddEntity(inst.type_entity_id);
      break;

    case OC::CAST:
      pool.AddEntity(inst.type_entity_id);
      break;

    case OC::ALLOCA:
      pool.AddEntity(MakeObjEid(fragment_id, obj_base, inst.object_index));
      break;

    case OC::PARAM_PTR_32: case OC::PARAM_PTR_64:
      break;

    case OC::GLOBAL_PTR_32: case OC::GLOBAL_PTR_64:
    case OC::THREAD_LOCAL_PTR_32: case OC::THREAD_LOCAL_PTR_64:
    case OC::FUNC_PTR_32: case OC::FUNC_PTR_64:
      pool.AddEntity(inst.target_entity_id);
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
      // Extras: [caseType, switchCase0_eid, switchCase1_eid, ...]
      // Placeholders for case entity IDs -- filled in second pass.
      pool.AddEntity(inst.type_entity_id);  // case integral type
      for (size_t i = 0; i < inst.switch_cases.size(); ++i) {
        pool.AddEntity(0);  // placeholder
      }
      break;

    case OC::ENTER_SCOPE:
    case OC::EXIT_SCOPE:
      if (inst.structure_index != UINT32_MAX) {
        pool.AddEntity(MakeStructureEid(func, fragment_id, struct_base,
                                         inst.structure_index));
      } else {
        pool.AddEntity(0);
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
    case OC::CONST: {
      pool.AddInt(static_cast<int64_t>(inst.const_op));  // ConstOp sub-opcode
      auto cop = static_cast<mx::ir::ConstOp>(inst.const_op);
      if (cop == mx::ir::ConstOp::FLOAT32 || cop == mx::ir::ConstOp::FLOAT64 ||
          cop == mx::ir::ConstOp::FLOAT16) {
        int64_t bits;
        static_assert(sizeof(double) == sizeof(int64_t));
        memcpy(&bits, &inst.float_value, sizeof(bits));
        pool.AddInt(bits);
        pool.AddInt(0);  // placeholder for unsigned_value slot
      } else {
        pool.AddInt(inst.int_value);
        pool.AddInt(static_cast<int64_t>(inst.uint_value));
      }
      break;
    }

    case OC::ALLOCA:
      pool.AddInt(static_cast<int64_t>(inst.alloca_kind));  // AllocaKind sub-opcode
      break;

    case OC::CAST:
      pool.AddInt(static_cast<int64_t>(inst.cast_op));  // CastOp sub-opcode
      break;

    case OC::SWITCH:
      // Case values are now in SwitchCase entities, not the int pool.
      break;

    case OC::GEP_FIELD_32: case OC::GEP_FIELD_64:
      pool.AddInt(static_cast<int64_t>(inst.size_bytes));  // byte offset
      break;

    case OC::PTR_ADD_32: case OC::PTR_ADD_64:
    case OC::PTR_DIFF_32: case OC::PTR_DIFF_64:
      pool.AddInt(static_cast<int64_t>(inst.size_bytes));  // element size
      break;

    case OC::READ_MODIFY_WRITE:
      pool.AddInt(static_cast<int64_t>(inst.compound_op));  // underlying opcode
      pool.AddInt(static_cast<int64_t>(inst.size_bytes));    // element size
      pool.AddInt(static_cast<int64_t>(inst.is_big_endian ? 1 : 0));  // endianness
      break;

    case OC::PARAM_PTR_32: case OC::PARAM_PTR_64:
      pool.AddInt(inst.int_value);  // parameter index
      break;

    case OC::BITWISE_8: case OC::BITWISE_16:
    case OC::BITWISE_32: case OC::BITWISE_64:
      pool.AddInt(static_cast<int64_t>(inst.bitwise_op));  // BitwiseOp sub-opcode
      break;

    case OC::MEMORY:
      pool.AddInt(static_cast<int64_t>(inst.mem_op));  // MemOp sub-opcode
      // BIT_READ/BIT_WRITE store bit_offset and bit_width in int pool.
      if (inst.mem_op == static_cast<uint8_t>(mx::ir::MemOp::BIT_READ_LE) ||
          inst.mem_op == static_cast<uint8_t>(mx::ir::MemOp::BIT_READ_BE) ||
          inst.mem_op == static_cast<uint8_t>(mx::ir::MemOp::BIT_WRITE_LE) ||
          inst.mem_op == static_cast<uint8_t>(mx::ir::MemOp::BIT_WRITE_BE)) {
        pool.AddInt(static_cast<int64_t>(inst.bit_offset));
        pool.AddInt(static_cast<int64_t>(inst.bit_width));
      }
      break;

    case OC::FLOAT:
      pool.AddInt(static_cast<int64_t>(inst.float_op));  // FloatOp sub-opcode
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

    // Map FunctionDecl → IRFunction.
    auto func_eid = em.EntityId(RawEntity(*func));
    if (func_eid != mx::kInvalidEntityId) {
      auto ir_func_eid = mx::EntityId(mx::IRFunctionId{
          fragment_id,
          static_cast<uint32_t>(ir_functions.size())}).Pack();
      em.ir_for_entity[func_eid] = ir_func_eid;
    }

    for (uint32_t i = 0; i < ir->instructions.size(); ++i) {
      auto &inst = ir->instructions[i];
      if (inst.source_entity_id != mx::kInvalidEntityId) {
        auto ir_eid = mx::EntityId(mx::IRInstructionId{
            fragment_id, inst_offset + i,
            inst.opcode}).Pack();
        em.ir_for_entity[inst.source_entity_id] = ir_eid;
      }
    }

    inst_offset += static_cast<uint32_t>(ir->instructions.size());
    ir_functions.push_back(std::move(*ir));
  }

  // Generate IR for global variables with initializers, including static locals.
  // Collect all global-storage VarDecls: top-level globals + static locals.
  std::vector<pasta::VarDecl> global_vars;
  for (const auto &decl : pf.top_level_decls) {
    auto var = pasta::VarDecl::From(decl);
    if (var && var->Initializer() && var->HasGlobalStorage()) {
      global_vars.push_back(*var);
    }
    // Scan function bodies for static locals.
    if (auto func = pasta::FunctionDecl::From(decl)) {
      if (auto body = func->Body()) {
        std::function<void(const pasta::Stmt &)> find_statics;
        find_statics = [&](const pasta::Stmt &s) {
          if (auto ds = pasta::DeclStmt::From(s)) {
            for (const auto &d : ds->Declarations()) {
              auto vd = pasta::VarDecl::From(d);
              if (vd && vd->Initializer() && vd->HasGlobalStorage()) {
                global_vars.push_back(*vd);
              }
            }
          }
          for (const auto &child : s.Children()) {
            find_statics(child);
          }
        };
        find_statics(*body);
      }
    }
  }

  for (const auto &var : global_vars) {

    ProgressBarWork ir_tracker(progress);
    ir::IRGenerator gen(ast, em);
    auto ir = gen.GenerateGlobalInit(var);
    if (!ir) continue;

    // Map VarDecl → IRFunction (GLOBAL_INITIALIZER).
    auto var_eid = em.EntityId(RawEntity(var));
    if (var_eid != mx::kInvalidEntityId) {
      auto ir_func_eid = mx::EntityId(mx::IRFunctionId{
          fragment_id,
          static_cast<uint32_t>(ir_functions.size())}).Pack();
      em.ir_for_entity[var_eid] = ir_func_eid;
    }

    for (uint32_t i = 0; i < ir->instructions.size(); ++i) {
      auto &inst = ir->instructions[i];
      if (inst.source_entity_id != mx::kInvalidEntityId) {
        auto ir_eid = mx::EntityId(mx::IRInstructionId{
            fragment_id, inst_offset + i,
            inst.opcode}).Pack();
        // Don't overwrite existing mappings (the VarDecl already maps
        // to its IRFunction).
        em.ir_for_entity.emplace(inst.source_entity_id, ir_eid);
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
    EntityMapper &em,
    mx::rpc::Fragment::Builder &fb) {

  if (ir_functions.empty()) return;

  RawEntityId fragment_id = pf.fragment_id.Unpack().fragment_id;

  // Count totals.
  uint32_t total_blocks = 0;
  uint32_t total_instructions = 0;
  uint32_t total_objects = 0;
  uint32_t total_structures = 0;
  for (const auto &func : ir_functions) {
    total_blocks += static_cast<uint32_t>(func.blocks.size());
    total_instructions += static_cast<uint32_t>(func.instructions.size());
    total_objects += static_cast<uint32_t>(func.objects.size());
    total_structures += static_cast<uint32_t>(func.structures.size());
  }

  // Build the pools.
  PoolBuilder pool;

  // Pre-allocate output lists.
  auto frag_funcs = fb.initIrFunctions(ir_functions.size());
  auto frag_blocks = fb.initIrBlocks(total_blocks);
  auto frag_insts = fb.initIrInstructions(total_instructions);
  auto frag_objs = fb.initIrObjects(total_objects);
  auto frag_structs = fb.initIrStructures(total_structures);

  uint32_t block_offset = 0;
  uint32_t inst_offset = 0;
  uint32_t obj_offset = 0;
  uint32_t struct_offset = 0;

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

    // No reverse map needed: each instruction stores parent_block_index.

    // Serialize instructions.
    for (size_t ii = 0; ii < func.instructions.size(); ++ii) {
      const auto &src = func.instructions[ii];
      auto ib = frag_insts[inst_offset + ii];

      // Entity pool: [parentBlockOrInst, sourceEntityId, (type?), op0..opN, ...extras]
      uint32_t ent_start = pool.EntitySize();

      // Position 0: parent (block for roots, instruction for sub-exprs).
      if (src.parent_instruction_index == UINT32_MAX) {
        pool.AddEntity(MakeBlockEid(func, fragment_id, block_offset,
                                     src.parent_block_index));
      } else {
        pool.AddEntity(MakeInstEid(func, fragment_id, inst_offset,
                                    src.parent_instruction_index));
      }

      // Position 1: source entity ID.
      pool.AddEntity(src.source_entity_id);

      // Position 2 (value-producing only): result type.
      {
        bool has_type = !mx::ir::IsTerminator(src.opcode) &&
            src.opcode != mx::ir::OpCode::VA_START &&
            src.opcode != mx::ir::OpCode::VA_END &&
            src.opcode != mx::ir::OpCode::VA_COPY &&
            src.opcode != mx::ir::OpCode::UNKNOWN;
        // MEMORY direct stores don't produce a value.
        if (has_type && src.opcode == mx::ir::OpCode::MEMORY) {
          auto mop = static_cast<mx::ir::MemOp>(src.mem_op);
          if (mx::ir::IsDirectLoadStore(mop) && mx::ir::IsAnyStore(mop))
            has_type = false;
        }
        if (has_type) pool.AddEntity(src.type_entity_id);
      }

      // Operands.
      for (auto op_idx : src.operand_indices) {
        pool.AddEntity(MakeInstEid(func, fragment_id, inst_offset, op_idx));
      }

      // Opcode-specific extras.
      EmitInstructionExtras(pool, src, func, fragment_id,
                            obj_offset, block_offset, inst_offset,
                            struct_offset);

      // Int pool.
      uint32_t const_start = EmitInstructionConsts(pool, src);

      ib.setEntityOffset(ent_start);
      ib.setConstOffset(const_start);
      // Operand count fits in uint8_t: most instructions have 0-3 operands.
      // CALL has one per argument; 255 args is the practical limit. Variadic
      // calls with more would need a wider field in the capnp schema.
      DCHECK(src.operand_indices.size() <= 255)
          << "Instruction has " << src.operand_indices.size()
          << " operands, exceeding uint8_t capacity";
      ib.setNumOperands(static_cast<uint8_t>(src.operand_indices.size()));
      // OpCode is uint8_t (max value 250 = ATOMIC_EXCHANGE_64). If we
      // ever exceed 255 opcodes, the capnp schema and this cast must
      // be widened to UInt16.
      DCHECK(static_cast<unsigned>(src.opcode) <= 255)
          << "OpCode " << static_cast<unsigned>(src.opcode)
          << " exceeds uint8_t capacity";
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

      // Set parent structure ID.
      if (src.parent_structure_index != UINT32_MAX) {
        bb.setParentStructureId(MakeStructureEid(func, fragment_id,
                                                  struct_offset,
                                                  src.parent_structure_index));
      }
    }

    // Serialize function.
    {
      auto ffb = frag_funcs[fi];
      ffb.setSourceDeclEntityId(func.func_decl_entity_id);
      ffb.setKind(static_cast<uint8_t>(func.kind));
      ffb.setEntryBlockId(MakeBlockEid(func, fragment_id, block_offset,
                                        func.entry_block_index));
      if (func.body_scope_index != UINT32_MAX) {
        ffb.setBodyScopeId(MakeStructureEid(func, fragment_id, struct_offset,
                                             func.body_scope_index));
      }

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

    // Serialize structures.
    for (uint32_t si = 0; si < func.structures.size(); ++si) {
      const auto &src = func.structures[si];
      auto sb = frag_structs[struct_offset + si];

      sb.setKind(static_cast<uint8_t>(src.kind));
      sb.setSourceEntityId(src.source_entity_id);

      // Parent: structure or function.
      if (src.parent_structure_index != UINT32_MAX) {
        sb.setParentId(MakeStructureEid(func, fragment_id, struct_offset,
                                         src.parent_structure_index));
      } else {
        // Parent is the function itself.
        mx::IRFunctionId fid{fragment_id, static_cast<uint32_t>(fi)};
        sb.setParentId(mx::EntityId(fid).Pack());
      }

      // Children: structures and blocks interleaved.
      uint32_t ent_start = pool.EntitySize();
      for (const auto &child : src.children) {
        if (child.is_structure) {
          pool.AddEntity(MakeStructureEid(func, fragment_id, struct_offset,
                                           child.index));
        } else {
          pool.AddEntity(MakeBlockEid(func, fragment_id, block_offset,
                                       child.index));
        }
      }
      // Objects (for scope kinds).
      for (auto oi : src.object_indices) {
        pool.AddEntity(MakeObjEid(fragment_id, obj_offset, oi));
      }

      sb.setEntityOffset(ent_start);
      sb.setNumChildren(static_cast<uint16_t>(src.children.size()));
      sb.setNumObjects(static_cast<uint16_t>(src.object_indices.size()));

      // SWITCH_CASE data.
      if (src.kind == mx::ir::StructureKind::SWITCH_CASE) {
        sb.setCaseLow(src.case_low);
        sb.setCaseHigh(src.case_high);
        sb.setIsDefault(src.is_default);
      }
    }

    block_offset += static_cast<uint32_t>(func.blocks.size());
    inst_offset += static_cast<uint32_t>(func.instructions.size());
    obj_offset += static_cast<uint32_t>(func.objects.size());
    struct_offset += static_cast<uint32_t>(func.structures.size());
  }

  // Fill in switch instruction placeholder pool entries with IRStructureId
  // references to the SWITCH_CASE structures.
  {
    uint32_t func_inst_base = 0;
    uint32_t func_struct_base = 0;

    for (const auto &func : ir_functions) {
      for (uint32_t ii = 0; ii < func.instructions.size(); ++ii) {
        const auto &inst = func.instructions[ii];
        if (inst.opcode != mx::ir::OpCode::SWITCH) continue;

        // Find the placeholder offset: extras start at
        // entityOffset + 2(parent+source) + numOperands
        // SWITCH is a terminator so has no type slot.
        // extras[0] = caseType, extras[1..] = case entity IDs.
        auto r = frag_insts[func_inst_base + ii];
        uint32_t placeholder_base = r.getEntityOffset() + 2 +
            r.getNumOperands() + 1;  // +1 for caseType at extras[0]

        for (size_t sci = 0; sci < inst.switch_cases.size(); ++sci) {
          const auto &sc = inst.switch_cases[sci];

          // Overwrite the placeholder with an IRStructureId for the
          // SWITCH_CASE structure.
          CHECK(sc.structure_index != UINT32_MAX)
              << "Switch case " << sci << " has no structure_index";
          auto sc_eid = MakeStructureEid(func, fragment_id,
                                          func_struct_base,
                                          sc.structure_index);
          pool.entities[placeholder_base + sci] = sc_eid;

          // Map CaseStmt/DefaultStmt -> IRStructure (SWITCH_CASE).
          if (sc.source_entity_id != mx::kInvalidEntityId) {
            em.ir_for_entity[sc.source_entity_id] = sc_eid;
          }
        }
      }
      func_inst_base += static_cast<uint32_t>(func.instructions.size());
      func_struct_base += static_cast<uint32_t>(func.structures.size());
    }
  }

  // Compute use-def chains and write per-instruction users lists.
  {
    std::vector<uint8_t> opcodes(total_instructions);
    std::vector<std::vector<uint32_t>> users(total_instructions);
    {
      uint32_t gi = 0;
      for (const auto &func : ir_functions) {
        for (uint32_t ii = 0; ii < func.instructions.size(); ++ii) {
          opcodes[gi + ii] = static_cast<uint8_t>(func.instructions[ii].opcode);
          for (auto op_idx : func.instructions[ii].operand_indices) {
            users[gi + op_idx].push_back(gi + ii);
          }
        }
        gi += static_cast<uint32_t>(func.instructions.size());
      }
    }

    for (uint32_t gi = 0; gi < total_instructions; ++gi) {
      auto &u = users[gi];
      auto user_list = frag_insts[gi].initUsers(u.size());
      for (size_t j = 0; j < u.size(); ++j) {
        mx::IRInstructionId iid{fragment_id, u[j], static_cast<mx::ir::OpCode>(opcodes[u[j]])};
        user_list.set(j, mx::EntityId(iid).Pack());
      }
    }
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
