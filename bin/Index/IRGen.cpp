// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "IRGen.h"
#include "EntityMapper.h"

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

// We use raw Clang AST accessors for things PASTA doesn't expose
// (literal values, type sizes, etc.)
#include <clang/AST/ASTContext.h>
#include <clang/AST/Decl.h>
#include <clang/AST/Expr.h>
#include <clang/AST/RecordLayout.h>
#include <clang/AST/Type.h>

#include <cassert>
#include <functional>
#include <glog/logging.h>

namespace indexer {
namespace ir {

using mx::RawEntityId;
using mx::kInvalidEntityId;
// PASTA enums for dispatch. These are converted to our unified OpCode.

// ---------------------------------------------------------------------------
// IRGenerator
// ---------------------------------------------------------------------------

IRGenerator::IRGenerator(const pasta::AST &ast, const EntityMapper &em)
    : ast_(ast),
      em_(em),
      ctx_(const_cast<clang::ASTContext &>(ast.UnderlyingAST())) {}

std::optional<FunctionIR> IRGenerator::Generate(
    const pasta::FunctionDecl &func) {

  auto body = func.Body();
  if (!body) return std::nullopt;

  try {
    func_ = FunctionIR{};
    func_.func_decl_entity_id = EntityIdOf(func);
    current_block_index_ = 0;
    current_structure_index_ = UINT32_MAX;
    next_obj_index_ = 0;
    entity_to_object_.clear();
    address_taken_.clear();
    loop_stack_.clear();
    label_blocks_.clear();
    case_blocks_.clear();
    structure_stack_.clear();

    // Pre-scan for address-taken variables.
    ScanAddressTaken(*body);

    // Create parameters as objects.
    auto params = func.Parameters();
    for (const auto &param : params) {
      auto eid = EntityIdOf(param);
      bool addr_taken = address_taken_.count(eid);
      auto kind = addr_taken ? mx::ir::ObjectKind::PARAMETER
                             : mx::ir::ObjectKind::PARAMETER_VALUE;
      MakeObject(kind, &param);
    }

    // Return slot if non-void.
    auto rt = func.ReturnType();
    auto rt_size = TypeSizeBytes(rt);
    if (rt_size && *rt_size > 0) {
      ObjectIR obj;
      obj.kind = mx::ir::ObjectKind::RETURN_SLOT;
      obj.type_entity_id = TypeEntityIdOf(rt);
      if (auto sz = TypeSizeBytes(rt)) obj.size_bytes = *sz;
      if (auto al = TypeAlignBytes(rt)) obj.align_bytes = *al;
      func_.objects.push_back(std::move(obj));
      next_obj_index_++;
    }

    // --- Frame block: all ALLOCAs (parameters + locals) ---
    uint32_t frame = NewBlock(mx::ir::BlockKind::FRAME);
    func_.entry_block_index = frame;
    SwitchToBlock(frame);

    // Emit parameter ALLOCAs in the frame block.
    for (const auto &param : params) {
      uint32_t obj_idx = GetOrMakeObject(param);
      InstructionIR alloca_inst;
      alloca_inst.opcode = mx::ir::OpCode::ALLOCA;
      alloca_inst.source_entity_id = EntityIdOf(param);
      alloca_inst.object_index = obj_idx;
      alloca_inst.type_entity_id = TypeEntityIdOf(param.Type());
      EmitTopLevel(std::move(alloca_inst));
    }

    // Emit local variable ALLOCAs in the frame block.
    EmitEntryBlockAllocas(*body);

    // --- Entry block: logical start of the function body ---
    uint32_t entry = NewBlock(mx::ir::BlockKind::ENTRY);
    EmitBranch(entry);
    SwitchToBlock(entry);

    // Push the function-level scope structure.
    uint32_t func_scope = PushStructure(
        mx::ir::StructureKind::FUNCTION_SCOPE, EntityIdOf(*body));
    func_.body_scope_index = func_scope;
    AssociateBlockWithStructure(entry);

    // ENTER_SCOPE for the function body.
    {
      InstructionIR enter;
      enter.opcode = mx::ir::OpCode::ENTER_SCOPE;
      enter.source_entity_id = EntityIdOf(*body);
      enter.structure_index = func_scope;
      EmitTopLevel(std::move(enter));
    }

    // Read each parameter into its alloca.
    for (uint32_t pi = 0; pi < params.size(); ++pi) {
      const auto &param = params[pi];
      uint32_t obj_idx = GetOrMakeObject(param);

      // Associate parameter objects with the function scope.
      func_.structures[func_scope].object_indices.push_back(obj_idx);

      // PARAM_READ: reads the Nth parameter value.
      InstructionIR pr;
      pr.opcode = mx::ir::OpCode::PARAM_READ;
      pr.source_entity_id = EntityIdOf(param);
      pr.object_index = obj_idx;
      pr.type_entity_id = TypeEntityIdOf(param.Type());
      pr.int_value = static_cast<int64_t>(pi);  // parameter index
      uint32_t pr_idx = EmitInstruction(std::move(pr));

      // ADDRESS_OF the parameter's alloca.
      InstructionIR addr;
      addr.opcode = mx::ir::OpCode::ADDRESS_OF;
      addr.source_entity_id = EntityIdOf(param);
      addr.object_index = obj_idx;
      uint32_t addr_idx = EmitInstruction(std::move(addr));

      // STORE the parameter value into its alloca.
      InstructionIR store;
      store.opcode = mx::ir::OpCode::STORE;
      store.source_entity_id = EntityIdOf(param);
      store.operand_indices = {addr_idx, pr_idx};
      EmitTopLevel(std::move(store));
    }

    EmitBody(*body);

    // If the current block has no terminator, add an implicit void return.
    {
      auto &blk = func_.blocks[current_block_index_];
      bool needs_ret = blk.instruction_indices.empty();
      if (!needs_ret) {
        auto last_op = func_.instructions[blk.instruction_indices.back()].opcode;
        needs_ret = !mx::ir::IsTerminator(last_op);
      }
      if (needs_ret) {
        // EXIT_SCOPE for the function scope before implicit return.
        InstructionIR exit_inst;
        exit_inst.opcode = mx::ir::OpCode::EXIT_SCOPE;
        exit_inst.source_entity_id = EntityIdOf(*body);
        exit_inst.structure_index = func_scope;
        EmitTopLevel(std::move(exit_inst));

        InstructionIR ret;
        ret.opcode = mx::ir::OpCode::RET;
        EmitTopLevel(std::move(ret));
      }
    }

    // Pop the function-level scope.
    PopStructure();

    // Patch empty blocks before computing dominators.
    // Empty blocks arise when all paths into a merge/exit block already
    // terminated (e.g., both if-branches return), or from empty switch cases.
    for (uint32_t bi = 0; bi < func_.blocks.size(); ++bi) {
      auto &block = func_.blocks[bi];
      if (!block.instruction_indices.empty()) continue;
      InstructionIR term;
      term.parent_block_index = bi;
      if (!block.successor_indices.empty()) {
        term.opcode = mx::ir::OpCode::IMPLICIT_GOTO;
        BranchTargetIR target;
        target.block_index = block.successor_indices.front();
        term.branch_targets = {target};
      } else {
        term.opcode = mx::ir::OpCode::IMPLICIT_UNREACHABLE;
      }
      uint32_t idx = static_cast<uint32_t>(func_.instructions.size());
      func_.instructions.push_back(std::move(term));
      block.instruction_indices.push_back(idx);
    }

    // Compute dominators and RPO.
    ComputeDominators();
    ComputeRPO();

    // Verify block structure.
    VerifyBlocks();

    LOG(INFO) << "Generated IR for function entity "
              << func_.func_decl_entity_id
              << ": " << func_.blocks.size() << " blocks, "
              << func_.instructions.size() << " instructions, "
              << func_.objects.size() << " objects";

    return std::move(func_);

  } catch (...) {
    DCHECK(false) << "Exception during IR generation for function";
    return std::nullopt;
  }
}

std::optional<FunctionIR> IRGenerator::GenerateGlobalInit(
    const pasta::VarDecl &var) {

  auto init = var.Initializer();
  if (!init) return std::nullopt;

  try {
    func_ = FunctionIR{};
    func_.func_decl_entity_id = EntityIdOf(var);
    func_.kind = mx::ir::FunctionKind::GLOBAL_INITIALIZER;
    current_block_index_ = 0;
    current_structure_index_ = UINT32_MAX;
    next_obj_index_ = 0;
    entity_to_object_.clear();
    address_taken_.clear();
    loop_stack_.clear();
    label_blocks_.clear();
    case_blocks_.clear();
    structure_stack_.clear();

    // Create entry block.
    uint32_t entry = NewBlock(mx::ir::BlockKind::ENTRY);
    func_.entry_block_index = entry;
    SwitchToBlock(entry);

    // Push FUNCTION_SCOPE.
    uint32_t func_scope = PushStructure(
        mx::ir::StructureKind::FUNCTION_SCOPE, EntityIdOf(var));
    func_.body_scope_index = func_scope;
    AssociateBlockWithStructure(entry);

    // Create the global object.
    uint32_t obj_idx = MakeObject(mx::ir::ObjectKind::GLOBAL, &var);

    // Emit ADDRESS_OF for the global.
    InstructionIR addr_inst;
    addr_inst.opcode = mx::ir::OpCode::ADDRESS_OF;
    addr_inst.source_entity_id = EntityIdOf(var);
    addr_inst.object_index = obj_idx;
    uint32_t addr_idx = EmitInstruction(std::move(addr_inst));

    // Emit the initializer expression.
    uint32_t val_idx = EmitRValue(*init);

    // Emit STORE.
    InstructionIR store_inst;
    store_inst.opcode = mx::ir::OpCode::STORE;
    store_inst.source_entity_id = EntityIdOf(var);
    store_inst.operand_indices = {addr_idx, val_idx};
    EmitTopLevel(std::move(store_inst));

    // Emit RET.
    InstructionIR ret;
    ret.opcode = mx::ir::OpCode::RET;
    EmitTopLevel(std::move(ret));

    // Pop FUNCTION_SCOPE.
    PopStructure();

    // Patch empty blocks.
    for (uint32_t bi = 0; bi < func_.blocks.size(); ++bi) {
      auto &block = func_.blocks[bi];
      if (!block.instruction_indices.empty()) continue;
      InstructionIR term;
      term.parent_block_index = bi;
      if (!block.successor_indices.empty()) {
        term.opcode = mx::ir::OpCode::IMPLICIT_GOTO;
        BranchTargetIR target;
        target.block_index = block.successor_indices.front();
        term.branch_targets = {target};
      } else {
        term.opcode = mx::ir::OpCode::IMPLICIT_UNREACHABLE;
      }
      uint32_t idx = static_cast<uint32_t>(func_.instructions.size());
      func_.instructions.push_back(std::move(term));
      block.instruction_indices.push_back(idx);
    }

    ComputeDominators();
    ComputeRPO();
    VerifyBlocks();

    LOG(INFO) << "Generated global init IR for var entity "
              << func_.func_decl_entity_id
              << ": " << func_.instructions.size() << " instructions";

    return std::move(func_);

  } catch (...) {
    DCHECK(false) << "Exception during IR generation for global initializer";
    return std::nullopt;
  }
}

// ---------------------------------------------------------------------------
// Structure management
// ---------------------------------------------------------------------------

uint32_t IRGenerator::PushStructure(mx::ir::StructureKind kind,
                                     mx::RawEntityId source_eid) {
  uint32_t idx = static_cast<uint32_t>(func_.structures.size());
  StructureIR s;
  s.kind = kind;
  s.source_entity_id = source_eid;
  s.parent_structure_index = current_structure_index_;
  func_.structures.push_back(std::move(s));

  // Register as child of parent.
  if (current_structure_index_ != UINT32_MAX) {
    StructureIR::ChildRef ref;
    ref.index = idx;
    ref.is_structure = true;
    func_.structures[current_structure_index_].children.push_back(ref);
  }

  structure_stack_.push_back(current_structure_index_);
  current_structure_index_ = idx;
  return idx;
}

void IRGenerator::PopStructure() {
  assert(!structure_stack_.empty());
  current_structure_index_ = structure_stack_.back();
  structure_stack_.pop_back();
}

void IRGenerator::AssociateBlockWithStructure(uint32_t block_idx) {
  if (current_structure_index_ == UINT32_MAX) return;
  func_.blocks[block_idx].parent_structure_index = current_structure_index_;
  StructureIR::ChildRef ref;
  ref.index = block_idx;
  ref.is_structure = false;
  func_.structures[current_structure_index_].children.push_back(ref);
}

void IRGenerator::AssociateObjectWithScope(uint32_t obj_idx) {
  // Walk up the structure stack to find the nearest scope.
  uint32_t si = current_structure_index_;
  while (si != UINT32_MAX) {
    if (mx::ir::IsScope(func_.structures[si].kind)) {
      func_.structures[si].object_indices.push_back(obj_idx);
      return;
    }
    si = func_.structures[si].parent_structure_index;
  }
}

void IRGenerator::EmitScopeExits(uint32_t stop_structure_index) {
  // Walk from current structure up to (but not including) stop, emitting
  // EXIT_SCOPE for each SCOPE we pass through.
  uint32_t si = current_structure_index_;
  while (si != UINT32_MAX && si != stop_structure_index) {
    if (mx::ir::IsScope(func_.structures[si].kind)) {
      InstructionIR exit_inst;
      exit_inst.opcode = mx::ir::OpCode::EXIT_SCOPE;
      exit_inst.source_entity_id = func_.structures[si].source_entity_id;
      exit_inst.structure_index = si;
      EmitTopLevel(std::move(exit_inst));
    }
    si = func_.structures[si].parent_structure_index;
  }
}

// ---------------------------------------------------------------------------
// Block management
// ---------------------------------------------------------------------------

uint32_t IRGenerator::NewBlock(mx::ir::BlockKind kind) {
  uint32_t idx = static_cast<uint32_t>(func_.blocks.size());
  BlockIR block;
  block.kind = kind;
  func_.blocks.push_back(std::move(block));
  return idx;
}

void IRGenerator::SwitchToBlock(uint32_t block_idx) {
  current_block_index_ = block_idx;
}

void IRGenerator::AddEdge(uint32_t from, uint32_t to) {
  func_.blocks[from].successor_indices.push_back(to);
  func_.blocks[to].predecessor_indices.push_back(from);
}

uint32_t IRGenerator::EmitBranch(uint32_t target_block,
                                  mx::RawEntityId source_eid) {
  // Default: implicit goto (structural CFG edge).
  return EmitBranchWithOpCode(mx::ir::OpCode::IMPLICIT_GOTO, target_block,
                               source_eid);
}

uint32_t IRGenerator::EmitBranchWithOpCode(mx::ir::OpCode opcode,
                                            uint32_t target_block,
                                            mx::RawEntityId source_eid) {
  // Don't emit a branch if the current block is already terminated.
  auto &blk = func_.blocks[current_block_index_];
  if (!blk.instruction_indices.empty()) {
    auto last_op = func_.instructions[blk.instruction_indices.back()].opcode;
    if (mx::ir::IsTerminator(last_op)) {
      return UINT32_MAX;
    }
  }

  InstructionIR br;
  br.opcode = opcode;
  br.source_entity_id = source_eid;
  BranchTargetIR target;
  target.block_index = target_block;
  br.branch_targets = {target};
  uint32_t idx = EmitTopLevel(std::move(br));
  AddEdge(current_block_index_, target_block);
  return idx;
}

uint32_t IRGenerator::EmitCondBranch(uint32_t cond_idx, uint32_t true_block,
                                      uint32_t false_block,
                                      mx::RawEntityId source_eid) {
  InstructionIR term;
  term.opcode = mx::ir::OpCode::COND_BRANCH;
  term.source_entity_id = source_eid;
  term.operand_indices = {cond_idx};
  BranchTargetIR true_t, false_t;
  true_t.block_index = true_block;
  false_t.block_index = false_block;
  term.branch_targets = {true_t, false_t};
  uint32_t idx = EmitTopLevel(std::move(term));
  AddEdge(current_block_index_, true_block);
  AddEdge(current_block_index_, false_block);
  return idx;
}

uint32_t IRGenerator::EmitLoadFromLValue(const pasta::Expr &e) {
  auto eid = EntityIdOf(e);
  uint32_t addr_idx = EmitLValue(e);
  InstructionIR inst;
  inst.opcode = mx::ir::OpCode::LOAD;
  inst.source_entity_id = eid;
  if (auto t = e.Type()) inst.type_entity_id = TypeEntityIdOf(*t);
  inst.operand_indices = {addr_idx};
  return EmitInstruction(std::move(inst));
}

void IRGenerator::MarkConditionallyExecuted(uint32_t inst_idx) {
  auto &inst = func_.instructions[inst_idx];
  inst.flags |= 0x4;  // bit 2 = isConditionallyExecuted
  // Recursively mark all operands (children in the expression tree).
  for (auto op_idx : inst.operand_indices) {
    MarkConditionallyExecuted(op_idx);
  }
}

// ---------------------------------------------------------------------------
// Address-taken pre-scan
// ---------------------------------------------------------------------------

void IRGenerator::ScanAddressTaken(const pasta::Stmt &s) {
  if (auto uo = pasta::UnaryOperator::From(s)) {
    if (uo->Opcode() == pasta::UnaryOperatorKind::kAddressOf) {
      auto sub = uo->SubExpression();
      while (true) {
        if (auto pe = pasta::ParenExpr::From(sub)) {
          sub = pe->SubExpression();
          continue;
        }
        if (auto ice = pasta::ImplicitCastExpr::From(sub)) {
          sub = ice->SubExpression();
          continue;
        }
        break;
      }
      if (auto dre = pasta::DeclRefExpr::From(sub)) {
        address_taken_.insert(EntityIdOf(dre->Declaration()));
      }
    }
  }

  for (const auto &child : s.Children()) {
    ScanAddressTaken(child);
  }
}

void IRGenerator::EmitEntryBlockAllocas(const pasta::Stmt &body) {
  // Walk the body to find all VarDecls and emit allocas in the entry block.
  std::function<void(const pasta::Stmt &)> walk;
  walk = [&](const pasta::Stmt &s) {
    if (auto ds = pasta::DeclStmt::From(s)) {
      for (const auto &decl : ds->Declarations()) {
        auto vd = pasta::VarDecl::From(decl);
        if (!vd) continue;
        if (pasta::ParmVarDecl::From(decl)) continue;

        uint32_t obj_idx = GetOrMakeObject(decl);

        InstructionIR alloca_inst;
        alloca_inst.opcode = mx::ir::OpCode::ALLOCA;
        alloca_inst.source_entity_id = EntityIdOf(decl);
        alloca_inst.object_index = obj_idx;
        alloca_inst.type_entity_id = TypeEntityIdOf(vd->Type());
        EmitTopLevel(std::move(alloca_inst));
      }
    }
    for (const auto &child : s.Children()) {
      walk(child);
    }
  };
  walk(body);
}

// ---------------------------------------------------------------------------
// Object management
// ---------------------------------------------------------------------------

uint32_t IRGenerator::MakeObject(mx::ir::ObjectKind kind,
                                  const pasta::Decl *decl) {
  ObjectIR obj;
  obj.kind = kind;

  if (decl) {
    obj.source_decl_id = EntityIdOf(*decl);
    // Name is accessible via source_decl_id -> NamedDecl::Name()
    if (auto vd = pasta::VarDecl::From(*decl)) {
      {
        auto vt = vd->Type();
        obj.type_entity_id = TypeEntityIdOf(vt);
        // type_str removed -- use Multiplier Type APIs to render
        if (auto sz = TypeSizeBytes(vt)) obj.size_bytes = *sz;
        if (auto al = TypeAlignBytes(vt)) obj.align_bytes = *al;
      }
    }
  }

  uint32_t idx = next_obj_index_++;
  func_.objects.push_back(std::move(obj));

  if (decl) {
    auto eid = EntityIdOf(*decl);
    if (eid != kInvalidEntityId) {
      entity_to_object_[eid] = idx;
    }
  }

  return idx;
}

uint32_t IRGenerator::GetOrMakeObject(const pasta::Decl &decl) {
  auto eid = EntityIdOf(decl);
  if (eid != kInvalidEntityId) {
    auto it = entity_to_object_.find(eid);
    if (it != entity_to_object_.end()) return it->second;
  }

  mx::ir::ObjectKind kind = mx::ir::ObjectKind::LOCAL;
  if (auto vd = pasta::VarDecl::From(decl)) {
    bool addr_taken = address_taken_.count(eid);
    if (vd->HasGlobalStorage() || vd->IsStaticLocal()) {
      kind = mx::ir::ObjectKind::GLOBAL;
    } else if (vd->TSCSpec() != pasta::ThreadStorageClassSpecifier::kUnspecified) {
      kind = mx::ir::ObjectKind::THREAD_LOCAL;
    } else {
      kind = addr_taken ? mx::ir::ObjectKind::LOCAL
                        : mx::ir::ObjectKind::LOCAL_VALUE;
    }
  }

  return MakeObject(kind, &decl);
}

// ---------------------------------------------------------------------------
// Instruction emission
// ---------------------------------------------------------------------------

uint32_t IRGenerator::EmitInstruction(InstructionIR inst) {
  inst.parent_block_index = current_block_index_;
  uint32_t idx = static_cast<uint32_t>(func_.instructions.size());
  func_.instructions.push_back(std::move(inst));
  return idx;
}

uint32_t IRGenerator::EmitTopLevel(InstructionIR inst) {
  uint32_t idx = EmitInstruction(std::move(inst));
  func_.blocks[current_block_index_].instruction_indices.push_back(idx);
  // Root: parent instruction is none, parent block is the current block.
  func_.instructions[idx].parent_instruction_index = UINT32_MAX;
  SetOperandParents(idx);
  return idx;
}

void IRGenerator::SetOperandParents(uint32_t inst_idx) {
  auto &inst = func_.instructions[inst_idx];
  for (auto op_idx : inst.operand_indices) {
    func_.instructions[op_idx].parent_instruction_index = inst_idx;
  }
}

// ---------------------------------------------------------------------------
// Statement emission (builds the CFG)
// ---------------------------------------------------------------------------

void IRGenerator::EmitBody(const pasta::Stmt &body) {
  if (auto cs = pasta::CompoundStmt::From(body)) {
    // Push a SCOPE structure for compound statements that are NOT the
    // function body (which already has FUNCTION_SCOPE).
    bool is_function_body = (current_structure_index_ != UINT32_MAX &&
        func_.structures[current_structure_index_].kind ==
            mx::ir::StructureKind::FUNCTION_SCOPE);
    if (!is_function_body) {
      PushStructure(mx::ir::StructureKind::SCOPE, EntityIdOf(body));

      // Emit ENTER_SCOPE instruction.
      InstructionIR enter;
      enter.opcode = mx::ir::OpCode::ENTER_SCOPE;
      enter.source_entity_id = EntityIdOf(body);
      enter.structure_index = current_structure_index_;
      EmitTopLevel(std::move(enter));
    }

    for (const auto &child : cs->Children()) {
      EmitStmt(child);
    }

    if (!is_function_body) {
      // Emit EXIT_SCOPE instruction.
      InstructionIR exit_inst;
      exit_inst.opcode = mx::ir::OpCode::EXIT_SCOPE;
      exit_inst.source_entity_id = EntityIdOf(body);
      exit_inst.structure_index = current_structure_index_;
      EmitTopLevel(std::move(exit_inst));

      PopStructure();
    }
  } else {
    EmitStmt(body);
  }
}

void IRGenerator::EmitStmt(const pasta::Stmt &s) {
  // Inline assembly -- emit as UNKNOWN with operands for inputs/outputs.
  if (pasta::GCCAsmStmt::From(s) || pasta::MSAsmStmt::From(s)) {
    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::UNKNOWN;
    inst.source_entity_id = EntityIdOf(s);
    // Emit children (input/output operands) so data flow is tracked.
    for (const auto &child : s.Children()) {
      if (auto expr = pasta::Expr::From(child)) {
        inst.operand_indices.push_back(EmitRValue(*expr));
      }
    }
    EmitTopLevel(std::move(inst));
    return;
  }

  if (pasta::IfStmt::From(s)) { EmitIfStmt(s); return; }
  if (pasta::WhileStmt::From(s)) { EmitWhileStmt(s); return; }
  if (pasta::DoStmt::From(s)) { EmitDoStmt(s); return; }
  if (pasta::ForStmt::From(s)) { EmitForStmt(s); return; }
  if (pasta::SwitchStmt::From(s)) { EmitSwitchStmt(s); return; }
  if (pasta::ReturnStmt::From(s)) { EmitReturnStmt(s); return; }
  if (pasta::DeclStmt::From(s)) { EmitDeclStmt(s); return; }
  if (pasta::BreakStmt::From(s)) { EmitBreakStmt(s); return; }
  if (pasta::ContinueStmt::From(s)) { EmitContinueStmt(s); return; }
  if (pasta::GotoStmt::From(s)) { EmitGotoStmt(s); return; }
  if (pasta::LabelStmt::From(s)) { EmitLabelStmt(s); return; }

  // Case/default encountered during body emission (fallthrough).
  // If the current block's last instruction is an explicit FALLTHROUGH,
  // patch its branch target. Otherwise emit a branch.
  if (pasta::CaseStmt::From(s) || pasta::DefaultStmt::From(s)) {
    auto it = case_blocks_.find(EntityIdOf(s));
    if (it != case_blocks_.end()) {
      uint32_t target_block = it->second;

      // Check if the last instruction is an explicit FALLTHROUGH to patch.
      auto &blk = func_.blocks[current_block_index_];
      bool patched = false;
      if (!blk.instruction_indices.empty()) {
        auto &last = func_.instructions[blk.instruction_indices.back()];
        if (last.opcode == mx::ir::OpCode::FALLTHROUGH &&
            last.branch_targets.empty()) {
          BranchTargetIR bt;
          bt.block_index = target_block;
          last.branch_targets = {bt};
          AddEdge(current_block_index_, target_block);
          patched = true;
        }
      }
      if (!patched) {
        EmitBranch(target_block, EntityIdOf(s));
      }
      SwitchToBlock(target_block);
    }

    if (auto cs = pasta::CaseStmt::From(s)) {
      EmitBody(cs->SubStatement());
    } else if (auto ds = pasta::DefaultStmt::From(s)) {
      EmitBody(ds->SubStatement());
    }
    return;
  }

  // AttributedStmt (wraps [[fallthrough]], [[likely]], etc.)
  if (auto as = pasta::AttributedStmt::From(s)) {
    bool is_fallthrough = false;
    for (const auto &attr : as->Attributes()) {
      if (pasta::FallThroughAttr::From(attr)) {
        is_fallthrough = true;
        break;
      }
    }
    if (is_fallthrough) {
      // Emit a FALLTHROUGH terminator. The branch target will be filled in
      // when the next case/default is encountered (see case/default handler).
      InstructionIR inst;
      inst.opcode = mx::ir::OpCode::FALLTHROUGH;
      inst.source_entity_id = EntityIdOf(s);
      // Branch target left empty -- will be patched by the case/default handler.
      EmitTopLevel(std::move(inst));
    }
    EmitStmt(as->SubStatement());
    return;
  }

  // NullStmt (empty statement, e.g. lone ';')
  if (pasta::NullStmt::From(s)) {
    return;
  }

  // Compound statement (nested block).
  if (auto cs = pasta::CompoundStmt::From(s)) {
    for (const auto &child : cs->Children()) {
      EmitStmt(child);
    }
    return;
  }

  // Expression statement.
  if (auto expr = pasta::Expr::From(s)) {
    uint32_t val_idx = EmitRValue(*expr);
    func_.blocks[current_block_index_].instruction_indices.push_back(val_idx);
    SetOperandParents(val_idx);
    return;
  }

  // Unhandled statement kind.
  DCHECK(false) << "Unhandled statement kind in IR generation";
}

void IRGenerator::EmitIfStmt(const pasta::Stmt &s) {
  auto ifs = pasta::IfStmt::From(s);
  if (!ifs) return;

  PushStructure(mx::ir::StructureKind::IF, EntityIdOf(s));

  uint32_t cond_idx = EmitRValue(ifs->Condition());
  uint32_t then_block = NewBlock(mx::ir::BlockKind::IF_THEN);
  uint32_t else_block = NewBlock(mx::ir::BlockKind::IF_ELSE);
  uint32_t merge_block = NewBlock(mx::ir::BlockKind::IF_MERGE);

  EmitCondBranch(cond_idx, then_block, else_block, EntityIdOf(s));

  PushStructure(mx::ir::StructureKind::IF_THEN, EntityIdOf(ifs->Then()));
  SwitchToBlock(then_block);
  AssociateBlockWithStructure(then_block);
  EmitBody(ifs->Then());
  EmitBranch(merge_block);
  PopStructure();  // IF_THEN

  PushStructure(mx::ir::StructureKind::IF_ELSE);
  SwitchToBlock(else_block);
  AssociateBlockWithStructure(else_block);
  if (auto else_body = ifs->Else()) {
    EmitBody(*else_body);
  }
  EmitBranch(merge_block);
  PopStructure();  // IF_ELSE

  AssociateBlockWithStructure(merge_block);
  SwitchToBlock(merge_block);

  PopStructure();  // IF
}

void IRGenerator::EmitWhileStmt(const pasta::Stmt &s) {
  auto ws = pasta::WhileStmt::From(s);
  if (!ws) return;

  PushStructure(mx::ir::StructureKind::WHILE, EntityIdOf(s));

  uint32_t cond_block = NewBlock(mx::ir::BlockKind::LOOP_CONDITION);
  uint32_t body_block = NewBlock(mx::ir::BlockKind::LOOP_BODY);
  uint32_t exit_block = NewBlock(mx::ir::BlockKind::LOOP_EXIT);

  EmitBranch(cond_block);

  PushStructure(mx::ir::StructureKind::WHILE_CONDITION, EntityIdOf(ws->Condition()));
  SwitchToBlock(cond_block);
  AssociateBlockWithStructure(cond_block);
  uint32_t cond_idx = EmitRValue(ws->Condition());
  EmitCondBranch(cond_idx, body_block, exit_block, EntityIdOf(s));
  PopStructure();  // WHILE_CONDITION

  loop_stack_.push_back({exit_block, cond_block, current_structure_index_, false});
  PushStructure(mx::ir::StructureKind::WHILE_BODY, EntityIdOf(ws->Body()));
  SwitchToBlock(body_block);
  AssociateBlockWithStructure(body_block);
  EmitBody(ws->Body());
  EmitBranch(cond_block);
  PopStructure();  // WHILE_BODY
  loop_stack_.pop_back();

  AssociateBlockWithStructure(exit_block);
  SwitchToBlock(exit_block);

  PopStructure();  // WHILE
}

void IRGenerator::EmitDoStmt(const pasta::Stmt &s) {
  auto ds = pasta::DoStmt::From(s);
  if (!ds) return;

  PushStructure(mx::ir::StructureKind::DO_WHILE, EntityIdOf(s));

  uint32_t body_block = NewBlock(mx::ir::BlockKind::LOOP_BODY);
  uint32_t cond_block = NewBlock(mx::ir::BlockKind::LOOP_CONDITION);
  uint32_t exit_block = NewBlock(mx::ir::BlockKind::LOOP_EXIT);

  EmitBranch(body_block);

  loop_stack_.push_back({exit_block, cond_block, current_structure_index_, false});
  PushStructure(mx::ir::StructureKind::DO_WHILE_BODY, EntityIdOf(ds->Body()));
  SwitchToBlock(body_block);
  AssociateBlockWithStructure(body_block);
  EmitBody(ds->Body());
  EmitBranch(cond_block);
  PopStructure();  // DO_WHILE_BODY
  loop_stack_.pop_back();

  PushStructure(mx::ir::StructureKind::DO_WHILE_CONDITION, EntityIdOf(ds->Condition()));
  SwitchToBlock(cond_block);
  AssociateBlockWithStructure(cond_block);
  uint32_t cond_idx = EmitRValue(ds->Condition());
  EmitCondBranch(cond_idx, body_block, exit_block, EntityIdOf(s));
  PopStructure();  // DO_WHILE_CONDITION

  AssociateBlockWithStructure(exit_block);
  SwitchToBlock(exit_block);

  PopStructure();  // DO_WHILE
}

void IRGenerator::EmitForStmt(const pasta::Stmt &s) {
  auto fs = pasta::ForStmt::From(s);
  if (!fs) return;

  // If the for-init declares variables, wrap the entire for loop in an
  // implicit SCOPE so those variables have correct lifetimes.
  auto init = fs->Initializer();
  bool has_init_decl = init && pasta::DeclStmt::From(*init);
  if (has_init_decl) {
    PushStructure(mx::ir::StructureKind::SCOPE, EntityIdOf(s));
    InstructionIR enter;
    enter.opcode = mx::ir::OpCode::ENTER_SCOPE;
    enter.source_entity_id = EntityIdOf(s);
    enter.structure_index = current_structure_index_;
    EmitTopLevel(std::move(enter));
  }

  PushStructure(mx::ir::StructureKind::FOR, EntityIdOf(s));

  if (init) {
    PushStructure(mx::ir::StructureKind::FOR_INIT, EntityIdOf(*init));
    EmitStmt(*init);
    PopStructure();  // FOR_INIT
  }

  uint32_t cond_block = NewBlock(mx::ir::BlockKind::LOOP_CONDITION);
  uint32_t body_block = NewBlock(mx::ir::BlockKind::LOOP_BODY);
  uint32_t inc_block = NewBlock(mx::ir::BlockKind::LOOP_INCREMENT);
  uint32_t exit_block = NewBlock(mx::ir::BlockKind::LOOP_EXIT);

  EmitBranch(cond_block);

  PushStructure(mx::ir::StructureKind::FOR_CONDITION);
  SwitchToBlock(cond_block);
  AssociateBlockWithStructure(cond_block);
  if (auto cond = fs->Condition()) {
    uint32_t cond_idx = EmitRValue(*cond);
    EmitCondBranch(cond_idx, body_block, exit_block, EntityIdOf(s));
  } else {
    EmitBranch(body_block);
  }
  PopStructure();  // FOR_CONDITION

  loop_stack_.push_back({exit_block, inc_block, current_structure_index_, false});
  PushStructure(mx::ir::StructureKind::FOR_BODY, EntityIdOf(fs->Body()));
  SwitchToBlock(body_block);
  AssociateBlockWithStructure(body_block);
  EmitBody(fs->Body());
  EmitBranch(inc_block);
  PopStructure();  // FOR_BODY
  loop_stack_.pop_back();

  PushStructure(mx::ir::StructureKind::FOR_INCREMENT);
  SwitchToBlock(inc_block);
  AssociateBlockWithStructure(inc_block);
  if (auto inc = fs->Increment()) {
    uint32_t inc_idx = EmitRValue(*inc);
    func_.blocks[current_block_index_].instruction_indices.push_back(inc_idx);
    SetOperandParents(inc_idx);
  }
  EmitBranch(cond_block);
  PopStructure();  // FOR_INCREMENT

  AssociateBlockWithStructure(exit_block);
  SwitchToBlock(exit_block);

  PopStructure();  // FOR

  if (has_init_decl) {
    // current_structure_index_ is now the implicit SCOPE since FOR was popped.
    InstructionIR exit_inst;
    exit_inst.opcode = mx::ir::OpCode::EXIT_SCOPE;
    exit_inst.source_entity_id = EntityIdOf(s);
    exit_inst.structure_index = current_structure_index_;
    EmitTopLevel(std::move(exit_inst));
    PopStructure();  // implicit SCOPE
  }
}

void IRGenerator::EmitSwitchStmt(const pasta::Stmt &s) {
  auto sw = pasta::SwitchStmt::From(s);
  if (!sw) return;

  PushStructure(mx::ir::StructureKind::SWITCH, EntityIdOf(s));

  uint32_t cond_idx = EmitRValue(sw->Condition());
  uint32_t exit_block = NewBlock(mx::ir::BlockKind::SWITCH_EXIT);

  // Collect case/default statements and create a block for each.
  struct CaseInfo {
    int64_t low{0};
    int64_t high{0};
    bool is_default{false};
    uint32_t block_index;
    mx::RawEntityId source_entity_id{mx::kInvalidEntityId};
  };
  std::vector<CaseInfo> cases;

  auto body = sw->Body();
  std::function<void(const pasta::Stmt &)> collect_cases;
  collect_cases = [&](const pasta::Stmt &stmt) {
    if (auto cs = pasta::CaseStmt::From(stmt)) {
      int64_t low = 0, high = 0;
      auto *raw_lhs = reinterpret_cast<const clang::Expr *>(
          cs->LHS().RawStmt());
      if (raw_lhs) {
        clang::Expr::EvalResult result;
        if (raw_lhs->EvaluateAsInt(result, ctx_)) {
          low = result.Val.getInt().getSExtValue();
          high = low;
        }
      }
      // GNU range case: case low ... high:
      if (cs->CaseStatementIsGNURange()) {
        if (auto rhs = cs->RHS()) {
          auto *raw_rhs = reinterpret_cast<const clang::Expr *>(
              rhs->RawStmt());
          if (raw_rhs) {
            clang::Expr::EvalResult result;
            if (raw_rhs->EvaluateAsInt(result, ctx_)) {
              high = result.Val.getInt().getSExtValue();
            }
          }
        }
      }
      uint32_t block = NewBlock(mx::ir::BlockKind::SWITCH_CASE);
      cases.push_back({low, high, false, block, EntityIdOf(stmt)});
      case_blocks_[EntityIdOf(stmt)] = block;
      return;
    }
    if (auto ds = pasta::DefaultStmt::From(stmt)) {
      uint32_t block = NewBlock(mx::ir::BlockKind::SWITCH_DEFAULT);
      cases.push_back({0, 0, true, block, EntityIdOf(stmt)});
      case_blocks_[EntityIdOf(stmt)] = block;
      return;
    }
    for (const auto &child : stmt.Children()) {
      collect_cases(child);
    }
  };
  collect_cases(body);

  // Build switch terminator.
  // Branch targets: case blocks first, then default block last.
  // switch_cases: one SwitchCase per non-default case.
  InstructionIR term;
  term.opcode = mx::ir::OpCode::SWITCH;
  term.source_entity_id = EntityIdOf(s);
  term.operand_indices = {cond_idx};

  // Store the case type from the selector expression.
  auto cond_type = sw->Condition().Type();
  if (cond_type) term.type_entity_id = TypeEntityIdOf(*cond_type);

  // Build switch cases with full provenance.
  for (const auto &ci : cases) {
    InstructionIR::SwitchCaseIR sc;
    sc.low = ci.low;
    sc.high = ci.high;
    sc.block_index = ci.block_index;
    sc.source_entity_id = ci.source_entity_id;
    sc.is_default = ci.is_default;
    term.switch_cases.push_back(sc);
    AddEdge(current_block_index_, ci.block_index);
  }

  EmitTopLevel(std::move(term));

  // Push switch context so break statements work.
  // continue_block = 0 is unused (continue skips switch contexts).
  loop_stack_.push_back({exit_block, 0, current_structure_index_, true});

  // Emit case bodies.
  // Emit case bodies. Before switching to each new case block, check if
  // the current block has been terminated. If not, it's implicit fallthrough.
  size_t ci = 0;
  auto maybe_emit_implicit_fallthrough = [&](uint32_t next_block) {
    auto &blk = func_.blocks[current_block_index_];
    if (blk.instruction_indices.empty()) return;
    auto &last = func_.instructions[blk.instruction_indices.back()];
    if (mx::ir::IsTerminator(last.opcode)) return;
    // Current block has no terminator -- implicit fallthrough.
    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::IMPLICIT_FALLTHROUGH;
    BranchTargetIR target;
    target.block_index = next_block;
    inst.branch_targets = {target};
    EmitTopLevel(std::move(inst));
    AddEdge(current_block_index_, next_block);
  };

  std::function<void(const pasta::Stmt &)> emit_case_bodies;
  emit_case_bodies = [&](const pasta::Stmt &stmt) {
    if (auto cs = pasta::CaseStmt::From(stmt)) {
      if (ci < cases.size()) {
        maybe_emit_implicit_fallthrough(cases[ci].block_index);
        PushStructure(mx::ir::StructureKind::SWITCH_CASE,
                      cases[ci].source_entity_id);
        // Store case value data in the structure.
        auto &sc_struct = func_.structures[current_structure_index_];
        sc_struct.case_low = cases[ci].low;
        sc_struct.case_high = cases[ci].high;
        sc_struct.is_default = false;
        SwitchToBlock(cases[ci].block_index);
        AssociateBlockWithStructure(cases[ci].block_index);
        ci++;
        EmitBody(cs->SubStatement());
        PopStructure();  // SWITCH_CASE
      }
      return;
    }
    if (auto ds = pasta::DefaultStmt::From(stmt)) {
      if (ci < cases.size()) {
        maybe_emit_implicit_fallthrough(cases[ci].block_index);
        PushStructure(mx::ir::StructureKind::SWITCH_CASE,
                      cases[ci].source_entity_id);
        auto &sc_struct = func_.structures[current_structure_index_];
        sc_struct.is_default = true;
        SwitchToBlock(cases[ci].block_index);
        AssociateBlockWithStructure(cases[ci].block_index);
        ci++;
        EmitBody(ds->SubStatement());
        PopStructure();  // SWITCH_CASE (default)
      }
      return;
    }
    for (const auto &child : stmt.Children()) {
      emit_case_bodies(child);
    }
  };
  emit_case_bodies(body);

  // After all cases, if the last case didn't terminate, branch to exit.
  maybe_emit_implicit_fallthrough(exit_block);
  EmitBranch(exit_block);

  loop_stack_.pop_back();
  AssociateBlockWithStructure(exit_block);
  SwitchToBlock(exit_block);

  PopStructure();  // SWITCH
}

void IRGenerator::EmitReturnStmt(const pasta::Stmt &s) {
  auto rs = pasta::ReturnStmt::From(s);
  if (!rs) return;

  // Emit the return value first (before scope exits).
  InstructionIR inst;
  inst.opcode = mx::ir::OpCode::RET;
  inst.source_entity_id = EntityIdOf(s);

  auto rv = rs->ReturnValue();
  if (rv) {
    uint32_t val_idx = EmitRValue(*rv);
    inst.operand_indices = {val_idx};
  }

  // Exit all scopes up to and including the function scope.
  EmitScopeExits(func_.body_scope_index);
  {
    InstructionIR exit_inst;
    exit_inst.opcode = mx::ir::OpCode::EXIT_SCOPE;
    exit_inst.source_entity_id = func_.structures[func_.body_scope_index].source_entity_id;
    exit_inst.structure_index = func_.body_scope_index;
    EmitTopLevel(std::move(exit_inst));
  }

  EmitTopLevel(std::move(inst));
}

void IRGenerator::EmitDeclStmt(const pasta::Stmt &s) {
  auto ds = pasta::DeclStmt::From(s);
  if (!ds) return;

  // Allocas were already emitted in the entry block by EmitEntryBlockAllocas.
  // Here we only emit the initialization store.
  for (const auto &decl : ds->Declarations()) {
    auto vd = pasta::VarDecl::From(decl);
    if (!vd) continue;
    if (pasta::ParmVarDecl::From(decl)) continue;

    uint32_t obj_idx = GetOrMakeObject(decl);
    AssociateObjectWithScope(obj_idx);

    if (auto init = vd->Initializer()) {
      InstructionIR addr_inst;
      addr_inst.opcode = mx::ir::OpCode::ADDRESS_OF;
      addr_inst.source_entity_id = EntityIdOf(decl);
      addr_inst.object_index = obj_idx;
      uint32_t addr_idx = EmitInstruction(std::move(addr_inst));

      uint32_t val_idx = EmitRValue(*init);

      InstructionIR store_inst;
      store_inst.opcode = mx::ir::OpCode::STORE;
      store_inst.source_entity_id = EntityIdOf(decl);
      store_inst.operand_indices = {addr_idx, val_idx};
      EmitTopLevel(std::move(store_inst));
    }
  }
}

void IRGenerator::EmitBreakStmt(const pasta::Stmt &s) {
  for (auto it = loop_stack_.rbegin(); it != loop_stack_.rend(); ++it) {
    EmitScopeExits(it->structure_index);
    EmitBranchWithOpCode(mx::ir::OpCode::BREAK, it->break_block,
                          EntityIdOf(s));
    SwitchToBlock(NewBlock(mx::ir::BlockKind::UNREACHABLE));
    return;
  }
  DCHECK(false) << "break statement outside of loop/switch";
}

void IRGenerator::EmitContinueStmt(const pasta::Stmt &s) {
  for (auto it = loop_stack_.rbegin(); it != loop_stack_.rend(); ++it) {
    if (!it->is_switch) {
      EmitScopeExits(it->structure_index);
      EmitBranchWithOpCode(mx::ir::OpCode::CONTINUE, it->continue_block,
                            EntityIdOf(s));
      SwitchToBlock(NewBlock(mx::ir::BlockKind::UNREACHABLE));
      return;
    }
  }
  DCHECK(false) << "continue statement outside of loop";
}

void IRGenerator::EmitGotoStmt(const pasta::Stmt &s) {
  auto gs = pasta::GotoStmt::From(s);
  if (!gs) return;

  auto label = gs->Label();
  std::string label_name = label.Name();

  auto it = label_blocks_.find(label_name);
  uint32_t target;
  if (it != label_blocks_.end()) {
    target = it->second;
  } else {
    target = NewBlock(mx::ir::BlockKind::LABEL);
    label_blocks_[label_name] = target;
  }

  // Conservatively exit all scopes up to function scope.
  // A more precise analysis would determine the target label's scope.
  EmitScopeExits(func_.body_scope_index);

  EmitBranchWithOpCode(mx::ir::OpCode::GOTO, target, EntityIdOf(s));
  SwitchToBlock(NewBlock(mx::ir::BlockKind::UNREACHABLE));
}

void IRGenerator::EmitLabelStmt(const pasta::Stmt &s) {
  auto ls = pasta::LabelStmt::From(s);
  if (!ls) return;

  std::string label_name(ls->Name());

  auto it = label_blocks_.find(label_name);
  uint32_t label_block;
  if (it != label_blocks_.end()) {
    label_block = it->second;
  } else {
    label_block = NewBlock(mx::ir::BlockKind::LABEL);
    label_blocks_[label_name] = label_block;
  }

  // Reaching a label sequentially is an implicit goto.
  EmitBranchWithOpCode(mx::ir::OpCode::IMPLICIT_GOTO, label_block,
                        EntityIdOf(s));
  SwitchToBlock(label_block);

  EmitStmt(ls->SubStatement());
}

// ---------------------------------------------------------------------------
// Expression emission (nested instruction trees)
// ---------------------------------------------------------------------------

uint32_t IRGenerator::EmitRValue(const pasta::Expr &e) {
  auto eid = EntityIdOf(e);

  // Helper: emit instruction with result type from expression e.
  auto expr_type = e.Type();
  auto emit_typed = [&](InstructionIR inst) -> uint32_t {
    if (expr_type && inst.type_entity_id == kInvalidEntityId) {
      inst.type_entity_id = TypeEntityIdOf(*expr_type);
    }
    return EmitInstruction(std::move(inst));
  };

  // Integer literal -- use Clang's evaluated value.
  if (auto il = pasta::IntegerLiteral::From(e)) {
    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::CONST_INT;
    inst.source_entity_id = eid;
    auto *raw = reinterpret_cast<const clang::IntegerLiteral *>(il->RawStmt());
    if (raw) {
      auto val = raw->getValue();
      inst.int_value = val.getSExtValue();
      inst.uint_value = val.getZExtValue();
      inst.width = static_cast<uint8_t>(val.getBitWidth());
      {
        auto ty = e.Type();
        if (ty) inst.type_entity_id = TypeEntityIdOf(*ty);
      }
    }
    return emit_typed(std::move(inst));
  }

  // Floating literal -- use Clang's evaluated value.
  if (auto fl = pasta::FloatingLiteral::From(e)) {
    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::CONST_FLOAT;
    inst.source_entity_id = eid;
    auto *raw = reinterpret_cast<const clang::FloatingLiteral *>(fl->RawStmt());
    if (raw) {
      bool losesInfo = false;
      llvm::APFloat val = raw->getValue();
      val.convert(llvm::APFloat::IEEEdouble(),
                  llvm::APFloat::rmNearestTiesToEven, &losesInfo);
      inst.float_value = val.convertToDouble();
      inst.width = static_cast<uint8_t>(
          ctx_.getTypeSize(raw->getType()));
    }
    return emit_typed(std::move(inst));
  }

  // Character literal -- use Clang's value.
  if (auto cl = pasta::CharacterLiteral::From(e)) {
    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::CONST_INT;
    inst.source_entity_id = eid;
    auto *raw = reinterpret_cast<const clang::CharacterLiteral *>(cl->RawStmt());
    if (raw) {
      inst.int_value = raw->getValue();
    }
    inst.width = 8;
    return emit_typed(std::move(inst));
  }

  // String literal.
  if (auto sl = pasta::StringLiteral::From(e)) {
    ObjectIR obj;
    obj.kind = mx::ir::ObjectKind::STRING_LITERAL;
    obj.size_bytes = static_cast<uint32_t>(sl->Tokens().Data().size());
    uint32_t obj_idx = next_obj_index_++;
    func_.objects.push_back(std::move(obj));

    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::ADDRESS_OF;
    inst.source_entity_id = eid;
    inst.object_index = obj_idx;
    return emit_typed(std::move(inst));
  }

  // Paren expr -- unwrap.
  if (auto pe = pasta::ParenExpr::From(e)) {
    return EmitRValue(pe->SubExpression());
  }

  // ExprWithCleanups, FullExpr -- unwrap.
  if (auto ewc = pasta::ExprWithCleanups::From(e)) {
    return EmitRValue(ewc->SubExpression());
  }

  // Lvalue expressions -- load from their address.
  if (pasta::DeclRefExpr::From(e) ||
      pasta::MemberExpr::From(e) ||
      pasta::ArraySubscriptExpr::From(e)) {
    return EmitLoadFromLValue(e);
  }

  // Implicit cast.
  if (auto ice = pasta::ImplicitCastExpr::From(e)) {
    auto ck = ice->CastKind();
    auto sub = ice->SubExpression();
    auto maybe_type = e.Type();

    if (ck == pasta::CastKind::kLValueToRValue) {
      uint32_t addr_idx = EmitLValue(sub);
      InstructionIR inst;
      inst.opcode = mx::ir::OpCode::LOAD;
      inst.source_entity_id = eid;
      if (maybe_type) inst.type_entity_id = TypeEntityIdOf(*maybe_type);
      inst.operand_indices = {addr_idx};
      return emit_typed(std::move(inst));
    }
    if (ck == pasta::CastKind::kArrayToPointerDecay ||
        ck == pasta::CastKind::kNoOperation) {
      return EmitRValue(sub);
    }
    if (ck == pasta::CastKind::kFunctionToPointerDecay) {
      return EmitLValue(sub);
    }
    if (ck == pasta::CastKind::kNullToPointer) {
      InstructionIR inst;
      inst.opcode = mx::ir::OpCode::CONST_NULL;
      inst.source_entity_id = eid;
      return emit_typed(std::move(inst));
    }
    if (ck == pasta::CastKind::kIntegralToBoolean) {
      uint32_t sub_idx = EmitRValue(sub);
      InstructionIR zero;
      zero.opcode = mx::ir::OpCode::CONST_INT;
      zero.int_value = 0; zero.width = 32;
      uint32_t zero_idx = EmitInstruction(std::move(zero));
      InstructionIR inst;
      inst.opcode = mx::ir::OpCode::CMP_NE;
      inst.source_entity_id = eid;
      inst.operand_indices = {sub_idx, zero_idx};
      return emit_typed(std::move(inst));
    }

    // Map cast kinds to IR opcodes.
    mx::ir::OpCode cast_op = mx::ir::OpCode::CAST_BITCAST;
    switch (ck) {
      case pasta::CastKind::kBitCast: cast_op = mx::ir::OpCode::CAST_BITCAST; break;
      case pasta::CastKind::kIntegralCast: cast_op = mx::ir::OpCode::CAST_INT_CAST; break;
      case pasta::CastKind::kPointerToIntegral: cast_op = mx::ir::OpCode::CAST_PTR_TO_INT; break;
      case pasta::CastKind::kIntegralToPointer: cast_op = mx::ir::OpCode::CAST_INT_TO_PTR; break;
      case pasta::CastKind::kIntegralToFloating: cast_op = mx::ir::OpCode::CAST_SI_TO_FP; break;
      case pasta::CastKind::kFloatingToIntegral: cast_op = mx::ir::OpCode::CAST_FP_TO_SI; break;
      case pasta::CastKind::kFloatingCast: cast_op = mx::ir::OpCode::CAST_FP_CAST; break;
      default: return EmitRValue(sub);
    }
    uint32_t sub_idx = EmitRValue(sub);
    InstructionIR inst;
    inst.opcode = cast_op;
    inst.source_entity_id = eid;
    if (maybe_type) inst.type_entity_id = TypeEntityIdOf(*maybe_type);
    inst.operand_indices = {sub_idx};
    return emit_typed(std::move(inst));
  }

  // Explicit cast -- use same CastKind dispatch as implicit casts.
  if (auto ece = pasta::ExplicitCastExpr::From(e)) {
    auto ck = ece->CastKind();
    if (ck == pasta::CastKind::kNoOperation) {
      return EmitRValue(ece->SubExpression());
    }
    if (ck == pasta::CastKind::kLValueToRValue) {
      return EmitLoadFromLValue(ece->SubExpression());
    }
    mx::ir::OpCode cast_op = mx::ir::OpCode::CAST_BITCAST;
    switch (ck) {
      case pasta::CastKind::kBitCast: cast_op = mx::ir::OpCode::CAST_BITCAST; break;
      case pasta::CastKind::kIntegralCast: cast_op = mx::ir::OpCode::CAST_INT_CAST; break;
      case pasta::CastKind::kPointerToIntegral: cast_op = mx::ir::OpCode::CAST_PTR_TO_INT; break;
      case pasta::CastKind::kIntegralToPointer: cast_op = mx::ir::OpCode::CAST_INT_TO_PTR; break;
      case pasta::CastKind::kIntegralToFloating: cast_op = mx::ir::OpCode::CAST_SI_TO_FP; break;
      case pasta::CastKind::kFloatingToIntegral: cast_op = mx::ir::OpCode::CAST_FP_TO_SI; break;
      case pasta::CastKind::kFloatingCast: cast_op = mx::ir::OpCode::CAST_FP_CAST; break;
      default: cast_op = mx::ir::OpCode::CAST_BITCAST; break;
    }
    uint32_t sub_idx = EmitRValue(ece->SubExpression());
    InstructionIR inst;
    inst.opcode = cast_op;
    inst.source_entity_id = eid;
    if (auto t = e.Type()) inst.type_entity_id = TypeEntityIdOf(*t);
    inst.operand_indices = {sub_idx};
    return emit_typed(std::move(inst));
  }

  // Other CastExpr -- pass through.
  if (auto ce = pasta::CastExpr::From(e)) {
    return EmitRValue(ce->SubExpression());
  }

  // Unary operator.
  if (auto uo = pasta::UnaryOperator::From(e)) {
    {
      auto oc = uo->Opcode();
      auto sub = uo->SubExpression();

      if (oc == pasta::UnaryOperatorKind::kAddressOf) return EmitLValue(sub);
      if (oc == pasta::UnaryOperatorKind::kDeref) {
        uint32_t ptr_idx = EmitRValue(sub);
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::LOAD;
        inst.source_entity_id = eid;
        if (auto t__ = e.Type()) inst.type_entity_id = TypeEntityIdOf(*t__);
        inst.operand_indices = {ptr_idx};
        return emit_typed(std::move(inst));
      }
      if (oc == pasta::UnaryOperatorKind::kPreIncrement ||
          oc == pasta::UnaryOperatorKind::kPreDecrement ||
          oc == pasta::UnaryOperatorKind::kPostIncrement ||
          oc == pasta::UnaryOperatorKind::kPostDecrement) {
        uint32_t addr_idx = EmitLValue(sub);
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::INC_DEC;
        inst.source_entity_id = eid;
        inst.operand_indices = {addr_idx};
        uint8_t f = 0;
        if (oc == pasta::UnaryOperatorKind::kPreIncrement ||
            oc == pasta::UnaryOperatorKind::kPostIncrement) f |= 1;
        if (oc == pasta::UnaryOperatorKind::kPreIncrement ||
            oc == pasta::UnaryOperatorKind::kPreDecrement) f |= 2;
        inst.flags = f;
        return emit_typed(std::move(inst));
      }
      if (oc == pasta::UnaryOperatorKind::kMinus) {
        uint32_t sub_idx = EmitRValue(sub);
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::NEG;
        inst.source_entity_id = eid;
        inst.operand_indices = {sub_idx};
        return emit_typed(std::move(inst));
      }
      if (oc == pasta::UnaryOperatorKind::kPlus) return EmitRValue(sub);
      if (oc == pasta::UnaryOperatorKind::kLNot) {
        uint32_t sub_idx = EmitRValue(sub);
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::LOGICAL_NOT;
        inst.source_entity_id = eid;
        inst.operand_indices = {sub_idx};
        return emit_typed(std::move(inst));
      }
      if (oc == pasta::UnaryOperatorKind::kNot) {
        uint32_t sub_idx = EmitRValue(sub);
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::BIT_NOT;
        inst.source_entity_id = eid;
        inst.operand_indices = {sub_idx};
        return emit_typed(std::move(inst));
      }
      return EmitRValue(sub);
    }
  }

  // Binary operator.
  if (auto bo = pasta::BinaryOperator::From(e)) {
    {
      auto oc = bo->Opcode();

      // Assignment.
      if (oc == pasta::BinaryOperatorKind::kAssign) {
        uint32_t addr_idx = EmitLValue(bo->LHS());
        uint32_t val_idx = EmitRValue(bo->RHS());
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::STORE;
        inst.source_entity_id = eid;
        inst.operand_indices = {addr_idx, val_idx};
        return emit_typed(std::move(inst));
      }

      // Compound assignment.
      if (pasta::CompoundAssignOperator::From(e)) {
        uint32_t addr_idx = EmitLValue(bo->LHS());
        uint32_t val_idx = EmitRValue(bo->RHS());
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::COMPOUND_ASSIGN;
        inst.source_entity_id = eid;
        inst.operand_indices = {addr_idx, val_idx};
        switch (oc) {
          case pasta::BinaryOperatorKind::kAddAssign: inst.compound_op = mx::ir::OpCode::ADD; break;
          case pasta::BinaryOperatorKind::kSubAssign: inst.compound_op = mx::ir::OpCode::SUB; break;
          case pasta::BinaryOperatorKind::kMulAssign: inst.compound_op = mx::ir::OpCode::MUL; break;
          case pasta::BinaryOperatorKind::kDivAssign: inst.compound_op = mx::ir::OpCode::DIV; break;
          case pasta::BinaryOperatorKind::kRemAssign: inst.compound_op = mx::ir::OpCode::REM; break;
          case pasta::BinaryOperatorKind::kAndAssign: inst.compound_op = mx::ir::OpCode::BIT_AND; break;
          case pasta::BinaryOperatorKind::kOrAssign: inst.compound_op = mx::ir::OpCode::BIT_OR; break;
          case pasta::BinaryOperatorKind::kXorAssign: inst.compound_op = mx::ir::OpCode::BIT_XOR; break;
          case pasta::BinaryOperatorKind::kShlAssign: inst.compound_op = mx::ir::OpCode::SHL; break;
          case pasta::BinaryOperatorKind::kShrAssign: inst.compound_op = mx::ir::OpCode::SHR; break;
          default: inst.compound_op = mx::ir::OpCode::ADD; break;
        }
        return emit_typed(std::move(inst));
      }

      // Comma.
      if (oc == pasta::BinaryOperatorKind::kComma) {
        EmitRValue(bo->LHS());
        return EmitRValue(bo->RHS());
      }

      // Logical AND/OR -- kept as instructions, NOT control flow splits.
      // RHS is conditionally executed.
      if (oc == pasta::BinaryOperatorKind::kLAnd ||
          oc == pasta::BinaryOperatorKind::kLOr) {
        uint32_t lhs_idx = EmitRValue(bo->LHS());
        uint32_t rhs_idx = EmitRValue(bo->RHS());
        MarkConditionallyExecuted(rhs_idx);
        InstructionIR inst;
        inst.opcode = (oc == pasta::BinaryOperatorKind::kLAnd)
                          ? mx::ir::OpCode::LOGICAL_AND
                          : mx::ir::OpCode::LOGICAL_OR;
        inst.source_entity_id = eid;
        inst.operand_indices = {lhs_idx, rhs_idx};
        return emit_typed(std::move(inst));
      }

      // Comparison.
      mx::ir::OpCode cmp_op;
      bool is_cmp = true;
      switch (oc) {
        case pasta::BinaryOperatorKind::kEQ: cmp_op = mx::ir::OpCode::CMP_EQ; break;
        case pasta::BinaryOperatorKind::kNE: cmp_op = mx::ir::OpCode::CMP_NE; break;
        case pasta::BinaryOperatorKind::kLT: cmp_op = mx::ir::OpCode::CMP_LT; break;
        case pasta::BinaryOperatorKind::kGT: cmp_op = mx::ir::OpCode::CMP_GT; break;
        case pasta::BinaryOperatorKind::kLE: cmp_op = mx::ir::OpCode::CMP_LE; break;
        case pasta::BinaryOperatorKind::kGE: cmp_op = mx::ir::OpCode::CMP_GE; break;
        default: is_cmp = false; cmp_op = mx::ir::OpCode::CMP_EQ; break;
      }
      if (is_cmp) {
        uint32_t lhs_idx = EmitRValue(bo->LHS());
        uint32_t rhs_idx = EmitRValue(bo->RHS());
        InstructionIR inst;
        inst.opcode = cmp_op;
        inst.source_entity_id = eid;
        inst.operand_indices = {lhs_idx, rhs_idx};
        return emit_typed(std::move(inst));
      }

      // Arithmetic / logic.
      mx::ir::OpCode arith_op = mx::ir::OpCode::ADD;
      switch (oc) {
        case pasta::BinaryOperatorKind::kAdd: arith_op = mx::ir::OpCode::ADD; break;
        case pasta::BinaryOperatorKind::kSub: arith_op = mx::ir::OpCode::SUB; break;
        case pasta::BinaryOperatorKind::kMul: arith_op = mx::ir::OpCode::MUL; break;
        case pasta::BinaryOperatorKind::kDiv: arith_op = mx::ir::OpCode::DIV; break;
        case pasta::BinaryOperatorKind::kRem: arith_op = mx::ir::OpCode::REM; break;
        case pasta::BinaryOperatorKind::kAnd: arith_op = mx::ir::OpCode::BIT_AND; break;
        case pasta::BinaryOperatorKind::kOr: arith_op = mx::ir::OpCode::BIT_OR; break;
        case pasta::BinaryOperatorKind::kXor: arith_op = mx::ir::OpCode::BIT_XOR; break;
        case pasta::BinaryOperatorKind::kShl: arith_op = mx::ir::OpCode::SHL; break;
        case pasta::BinaryOperatorKind::kShr: arith_op = mx::ir::OpCode::SHR; break;
        default: break;
      }

      // Check for pointer arithmetic.
      auto lhs_type = bo->LHS().Type();
      auto rhs_type = bo->RHS().Type();
      bool lhs_ptr = lhs_type && pasta::PointerType::From(*lhs_type);
      bool rhs_ptr = rhs_type && pasta::PointerType::From(*rhs_type);

      if (arith_op == mx::ir::OpCode::ADD && (lhs_ptr || rhs_ptr)) {
        auto base_expr = lhs_ptr ? bo->LHS() : bo->RHS();
        auto idx_expr = lhs_ptr ? bo->RHS() : bo->LHS();
        auto &ptr_type = lhs_ptr ? lhs_type : rhs_type;
        uint32_t base_idx = EmitRValue(base_expr);
        uint32_t idx_idx = EmitRValue(idx_expr);
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::PTR_ADD;
        inst.source_entity_id = eid;
        inst.operand_indices = {base_idx, idx_idx};
        if (auto pt = pasta::PointerType::From(*ptr_type)) {
          auto pointee = pt->PointeeType();
          inst.type_entity_id = TypeEntityIdOf(pointee);
          if (auto sz = TypeSizeBytes(pointee)) inst.size_bytes = *sz;
        }
        return emit_typed(std::move(inst));
      }

      if (arith_op == mx::ir::OpCode::SUB && lhs_ptr && rhs_ptr) {
        // ptr - ptr → PTR_DIFF
        uint32_t lhs_idx = EmitRValue(bo->LHS());
        uint32_t rhs_idx = EmitRValue(bo->RHS());
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::PTR_DIFF;
        inst.source_entity_id = eid;
        inst.operand_indices = {lhs_idx, rhs_idx};
        return emit_typed(std::move(inst));
      }

      if (arith_op == mx::ir::OpCode::SUB && lhs_ptr) {
        uint32_t base_idx = EmitRValue(bo->LHS());
        uint32_t idx_idx = EmitRValue(bo->RHS());
        InstructionIR neg;
        neg.opcode = mx::ir::OpCode::NEG;
        neg.operand_indices = {idx_idx};
        uint32_t neg_idx = EmitInstruction(std::move(neg));
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::PTR_ADD;
        inst.source_entity_id = eid;
        inst.operand_indices = {base_idx, neg_idx};
        if (auto pt = pasta::PointerType::From(*lhs_type)) {
          auto pointee = pt->PointeeType();
          inst.type_entity_id = TypeEntityIdOf(pointee);
          if (auto sz = TypeSizeBytes(pointee)) inst.size_bytes = *sz;
        }
        return emit_typed(std::move(inst));
      }

      uint32_t lhs_idx = EmitRValue(bo->LHS());
      uint32_t rhs_idx = EmitRValue(bo->RHS());
      InstructionIR inst;
      inst.opcode = arith_op;
      inst.source_entity_id = eid;
      inst.operand_indices = {lhs_idx, rhs_idx};
      return emit_typed(std::move(inst));
    }
  }


  // Call expression (including member calls).
  if (auto ce = pasta::CallExpr::From(e)) {
    auto direct_callee = ce->DirectCallee();

    // Handle va_start/va_end/va_copy builtins.
    if (direct_callee) {
      auto callee_name = direct_callee->Name();
      auto args = ce->Arguments();

      if (callee_name == "__builtin_va_start" || callee_name == "va_start") {
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::VA_START;
        inst.source_entity_id = eid;
        if (!args.empty()) inst.operand_indices.push_back(EmitRValue(args[0]));
        return emit_typed(std::move(inst));
      }
      if (callee_name == "__builtin_va_end" || callee_name == "va_end") {
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::VA_END;
        inst.source_entity_id = eid;
        if (!args.empty()) inst.operand_indices.push_back(EmitRValue(args[0]));
        return emit_typed(std::move(inst));
      }
      if (callee_name == "__builtin_va_copy" || callee_name == "va_copy") {
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::VA_COPY;
        inst.source_entity_id = eid;
        if (args.size() >= 2) {
          inst.operand_indices.push_back(EmitRValue(args[0]));
          inst.operand_indices.push_back(EmitRValue(args[1]));
        }
        return emit_typed(std::move(inst));
      }

      // Recognize memset/memcpy/memmove and lower to MEMSET/MEMCPY.
      if (callee_name == "memset" || callee_name == "__builtin_memset" ||
          callee_name == "__builtin_memset_chk" ||
          callee_name == "__builtin___memset_chk") {
        if (args.size() >= 3) {
          InstructionIR inst;
          inst.opcode = mx::ir::OpCode::MEMSET;
          inst.source_entity_id = eid;
          inst.operand_indices.push_back(EmitRValue(args[0]));
          inst.operand_indices.push_back(EmitRValue(args[1]));
          inst.operand_indices.push_back(EmitRValue(args[2]));
          return emit_typed(std::move(inst));
        }
      }
      if (callee_name == "memcpy" || callee_name == "memmove" ||
          callee_name == "__builtin_memcpy" || callee_name == "__builtin_memmove" ||
          callee_name == "__builtin_memcpy_chk" || callee_name == "__builtin_memmove_chk" ||
          callee_name == "__builtin___memcpy_chk" || callee_name == "__builtin___memmove_chk") {
        if (args.size() >= 3) {
          InstructionIR inst;
          inst.opcode = mx::ir::OpCode::MEMCPY;
          inst.source_entity_id = eid;
          inst.operand_indices.push_back(EmitRValue(args[0]));
          inst.operand_indices.push_back(EmitRValue(args[1]));
          inst.operand_indices.push_back(EmitRValue(args[2]));
          return emit_typed(std::move(inst));
        }
      }
    }

    InstructionIR inst;
    inst.source_entity_id = eid;

    inst.opcode = mx::ir::OpCode::CALL;

    if (direct_callee) {
      auto canon = direct_callee->CanonicalDeclaration();
      inst.target_entity_id = EntityIdOf(canon);

      auto args = ce->Arguments();
      uint32_t num_params = direct_callee->NumParameters();
      bool is_variadic = direct_callee->IsVariadic();

      for (uint32_t i = 0; i < args.size(); ++i) {
        if (is_variadic && i >= num_params) {
          InstructionIR pack;
          pack.opcode = mx::ir::OpCode::VA_PACK;
          pack.source_entity_id = eid;
          for (uint32_t j = i; j < args.size(); ++j) {
            pack.operand_indices.push_back(EmitRValue(args[j]));
          }
          inst.operand_indices.push_back(EmitInstruction(std::move(pack)));
          break;
        }
        inst.operand_indices.push_back(EmitRValue(args[i]));
      }
    } else {
      inst.target_entity_id = kInvalidEntityId;
      inst.operand_indices.push_back(EmitRValue(ce->Callee()));
      for (const auto &arg : ce->Arguments()) {
        inst.operand_indices.push_back(EmitRValue(arg));
      }
    }
    return emit_typed(std::move(inst));
  }

  // Conditional operator (ternary) -- kept as SELECT, not control flow.
  // Both true and false branches are conditionally executed.
  if (auto co = pasta::ConditionalOperator::From(e)) {
    uint32_t cond_idx = EmitRValue(co->Condition());
    uint32_t true_idx = EmitRValue(co->TrueExpression());
    uint32_t false_idx = EmitRValue(co->FalseExpression());
    MarkConditionallyExecuted(true_idx);
    MarkConditionallyExecuted(false_idx);
    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::SELECT;
    inst.source_entity_id = eid;
    inst.operand_indices = {cond_idx, true_idx, false_idx};
    return emit_typed(std::move(inst));
  }

  // sizeof / alignof.
  if (auto tte = pasta::UnaryExprOrTypeTraitExpr::From(e)) {
    if (tte->KeywordKind() == pasta::UnaryExprOrTypeTrait::kSizeOf) {
      InstructionIR inst;
      inst.opcode = mx::ir::OpCode::SIZE_OF;
      inst.source_entity_id = eid;
      {
        auto arg_type = tte->TypeOfArgument();
        inst.type_entity_id = TypeEntityIdOf(arg_type);
        if (auto sz = TypeSizeBytes(arg_type)) inst.size_bytes = *sz;
      }
      return emit_typed(std::move(inst));
    }
    // Other traits (alignof, etc.) -- treat as constant if we can evaluate.
    {
      auto arg_type = tte->TypeOfArgument();
      if (auto sz = TypeSizeBytes(arg_type)) {
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::CONST_INT;
        inst.source_entity_id = eid;
        inst.int_value = static_cast<int64_t>(*sz);
        inst.uint_value = static_cast<uint64_t>(*sz);
        inst.width = 64;
        return emit_typed(std::move(inst));
      }
    }
  }

  // InitListExpr -- aggregate initialization. Operands are the initializer values.
  if (auto ile = pasta::InitListExpr::From(e)) {
    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::INIT_LIST;
    inst.source_entity_id = eid;
    if (auto t = e.Type()) inst.type_entity_id = TypeEntityIdOf(*t);
    for (const auto &child : ile->Children()) {
      if (auto child_expr = pasta::Expr::From(child)) {
        inst.operand_indices.push_back(EmitRValue(*child_expr));
      }
    }
    return emit_typed(std::move(inst));
  }

  // CompoundLiteralExpr -- emit the initializer.
  if (auto cle = pasta::CompoundLiteralExpr::From(e)) {
    return EmitRValue(cle->Initializer());
  }

  // StmtExpr -- GNU ({ ... }) expression. Emit children, return last expr.
  if (auto se = pasta::StmtExpr::From(e)) {
    auto sub = se->SubStatement();
    if (auto cs = pasta::CompoundStmt::From(sub)) {
      uint32_t last_idx = 0;
      bool first = true;
      for (const auto &child : cs->Children()) {
        if (auto child_expr = pasta::Expr::From(child)) {
          last_idx = EmitRValue(*child_expr);
          first = false;
        } else {
          EmitStmt(child);
        }
      }
      if (!first) return last_idx;
    }
    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::CONST_INT;
    inst.source_entity_id = eid;
    inst.int_value = 0;
    inst.width = 32;
    return emit_typed(std::move(inst));
  }

  // VAArgExpr -- va_arg(ap, type).
  if (auto va = pasta::VAArgExpr::From(e)) {
    uint32_t sub_idx = EmitRValue(va->SubExpression());
    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::VA_ARG;
    inst.source_entity_id = eid;
    if (auto t = e.Type()) inst.type_entity_id = TypeEntityIdOf(*t);
    inst.operand_indices = {sub_idx};
    return emit_typed(std::move(inst));
  }


  // PredefinedExpr (__func__, __FUNCTION__, __PRETTY_FUNCTION__) -- unwrap to the StringLiteral.
  if (auto pe = pasta::PredefinedExpr::From(e)) {
    if (auto fn = pe->FunctionName()) {
      return EmitRValue(*fn);
    }
  }

  // CXXNullPtrLiteralExpr -- nullptr.
  if (pasta::CXXNullPtrLiteralExpr::From(e)) {
    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::CONST_NULL;
    inst.source_entity_id = eid;
    return emit_typed(std::move(inst));
  }

  // CXXBoolLiteralExpr -- true/false.
  if (auto bl = pasta::CXXBoolLiteralExpr::From(e)) {
    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::CONST_INT;
    inst.source_entity_id = eid;
    inst.int_value = bl->Value() ? 1 : 0;
    inst.uint_value = bl->Value() ? 1 : 0;
    inst.width = 1;
    if (auto t = e.Type()) inst.type_entity_id = TypeEntityIdOf(*t);
    return emit_typed(std::move(inst));
  }

  // Emit UNKNOWN for anything we haven't explicitly handled.
  // The source_entity_id lets the user inspect the original AST node.
  InstructionIR inst;
  inst.opcode = mx::ir::OpCode::UNKNOWN;
  inst.source_entity_id = eid;
  return emit_typed(std::move(inst));
}

uint32_t IRGenerator::EmitLValue(const pasta::Expr &e) {
  auto eid = EntityIdOf(e);

  // Paren -- unwrap.
  if (auto pe = pasta::ParenExpr::From(e)) {
    return EmitLValue(pe->SubExpression());
  }

  // DeclRefExpr -> addressOf.
  if (auto dre = pasta::DeclRefExpr::From(e)) {
    auto decl = dre->Declaration();
    uint32_t obj_idx = GetOrMakeObject(decl);
    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::ADDRESS_OF;
    inst.source_entity_id = eid;
    inst.object_index = obj_idx;
    return EmitInstruction(std::move(inst));
  }

  // MemberExpr.
  if (auto me = pasta::MemberExpr::From(e)) {
    uint32_t base_idx;
    if (me->IsArrow()) {
      base_idx = EmitRValue(me->Base());
    } else {
      base_idx = EmitLValue(me->Base());
    }

    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::GEP_FIELD;
    inst.source_entity_id = eid;
    inst.operand_indices = {base_idx};

    auto member = me->MemberDeclaration();
    inst.target_entity_id = EntityIdOf(member);
    // Field name accessible via target_entity_id -> FieldDecl::Name()
    if (auto fd = pasta::FieldDecl::From(member)) {
      auto bits = fd->OffsetInBits();
      if (bits) inst.size_bytes = static_cast<uint32_t>(*bits / 8);
    }
    return EmitInstruction(std::move(inst));
  }

  // ArraySubscriptExpr -- pointer + index.
  if (auto ase = pasta::ArraySubscriptExpr::From(e)) {
    uint32_t base_idx = EmitRValue(ase->Base());
    uint32_t idx_idx = EmitRValue(ase->Index());
    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::PTR_ADD;
    inst.source_entity_id = eid;
    inst.operand_indices = {base_idx, idx_idx};
    // Element type from the base pointer/array type.
    auto base_type = ase->Base().Type();
    if (base_type) {
      if (auto pt = pasta::PointerType::From(*base_type)) {
        auto pointee = pt->PointeeType();
        inst.type_entity_id = TypeEntityIdOf(pointee);
        if (auto sz = TypeSizeBytes(pointee)) inst.size_bytes = *sz;
      } else if (auto at = base_type->PointeeOrArrayElementType()) {
        inst.type_entity_id = TypeEntityIdOf(*at);
        if (auto sz = TypeSizeBytes(*at)) inst.size_bytes = *sz;
      }
    }
    return EmitInstruction(std::move(inst));
  }

  // UnaryOperator(Deref) -> the pointer IS the address.
  if (auto uo = pasta::UnaryOperator::From(e)) {
    {
      if (uo->Opcode() == pasta::UnaryOperatorKind::kDeref) {
        return EmitRValue(uo->SubExpression());
      }
    }
  }

  // ImplicitCastExpr passthrough.
  if (auto ice = pasta::ImplicitCastExpr::From(e)) {
    {
      auto ck = ice->CastKind();
      if (ck == pasta::CastKind::kLValueToRValue ||
          ck == pasta::CastKind::kArrayToPointerDecay ||
          ck == pasta::CastKind::kNoOperation) {
        return EmitLValue(ice->SubExpression());
      }
    }
    return EmitLValue(ice->SubExpression());
  }

  // Fallback: treat as rvalue.
  return EmitRValue(e);
}

// ---------------------------------------------------------------------------
// Entity ID helpers
// ---------------------------------------------------------------------------

RawEntityId IRGenerator::EntityIdOf(const pasta::Stmt &s) {
  return em_.EntityId(s);
}

RawEntityId IRGenerator::EntityIdOf(const pasta::Decl &d) {
  return em_.EntityId(d);
}

RawEntityId IRGenerator::TypeEntityIdOf(const pasta::Type &t) {
  return em_.EntityId(t);
}

// ---------------------------------------------------------------------------
// Type helpers
// ---------------------------------------------------------------------------

std::optional<uint32_t> IRGenerator::TypeSizeBytes(const pasta::Type &t) {
  {
    auto bits = t.SizeInBits();
    if (bits && *bits > 0) return static_cast<uint32_t>((*bits + 7) / 8);
  }
  return std::nullopt;
}

std::optional<uint32_t> IRGenerator::TypeAlignBytes(const pasta::Type &t) {
  {
    auto a = t.Alignment();
    if (a && *a > 0) return static_cast<uint32_t>((*a + 7) / 8);
  }
  return std::nullopt;
}

// ---------------------------------------------------------------------------
// Dominator computation (Cooper-Harvey-Kennedy)
// ---------------------------------------------------------------------------

void IRGenerator::ComputeDominators() {
  auto &blocks = func_.blocks;
  if (blocks.empty()) return;

  uint32_t entry = func_.entry_block_index;
  uint32_t num_blocks = static_cast<uint32_t>(blocks.size());

  std::vector<std::vector<uint32_t>> succs(num_blocks);
  std::vector<std::vector<uint32_t>> preds(num_blocks);
  for (uint32_t i = 0; i < num_blocks; ++i) {
    succs[i] = blocks[i].successor_indices;
    preds[i] = blocks[i].predecessor_indices;
  }

  // RPO.
  std::vector<uint32_t> rpo;
  {
    std::vector<bool> visited(num_blocks, false);
    std::function<void(uint32_t)> dfs = [&](uint32_t n) {
      if (visited[n]) return;
      visited[n] = true;
      for (auto s : succs[n]) dfs(s);
      rpo.push_back(n);
    };
    dfs(entry);
    std::reverse(rpo.begin(), rpo.end());
  }

  std::unordered_map<uint32_t, uint32_t> rpo_num;
  for (uint32_t i = 0; i < rpo.size(); ++i) rpo_num[rpo[i]] = i;

  // Immediate dominators.
  std::vector<uint32_t> idom(num_blocks, UINT32_MAX);
  idom[entry] = entry;

  auto intersect = [&](uint32_t b1, uint32_t b2) -> uint32_t {
    while (b1 != b2) {
      while (rpo_num.count(b1) && rpo_num.count(b2) && rpo_num[b1] > rpo_num[b2]) b1 = idom[b1];
      while (rpo_num.count(b1) && rpo_num.count(b2) && rpo_num[b2] > rpo_num[b1]) b2 = idom[b2];
    }
    return b1;
  };

  bool changed = true;
  while (changed) {
    changed = false;
    for (auto b : rpo) {
      if (b == entry) continue;
      uint32_t new_idom = UINT32_MAX;
      for (auto p : preds[b]) {
        if (idom[p] == UINT32_MAX) continue;
        new_idom = (new_idom == UINT32_MAX) ? p : intersect(new_idom, p);
      }
      if (new_idom != UINT32_MAX && idom[b] != new_idom) {
        idom[b] = new_idom;
        changed = true;
      }
    }
  }

  for (uint32_t i = 0; i < num_blocks; ++i) {
    if (idom[i] != UINT32_MAX && idom[i] != i)
      blocks[i].immediate_dominator = idom[i];

    uint32_t cur = i;
    while (cur != UINT32_MAX && cur != idom[cur]) {
      blocks[i].dominator_indices.push_back(cur);
      cur = idom[cur];
    }
    if (cur != UINT32_MAX) blocks[i].dominator_indices.push_back(cur);
  }

  // Post-dominators (reverse CFG).
  std::vector<uint32_t> exits;
  for (uint32_t i = 0; i < num_blocks; ++i)
    if (succs[i].empty()) exits.push_back(i);
  if (exits.empty()) exits.push_back(num_blocks - 1);

  uint32_t virt_exit = num_blocks;
  std::vector<std::vector<uint32_t>> rev_succs(num_blocks + 1);
  std::vector<std::vector<uint32_t>> rev_preds(num_blocks + 1);
  for (uint32_t i = 0; i < num_blocks; ++i) {
    rev_succs[i] = preds[i];
    rev_preds[i] = succs[i];
  }
  for (auto ex : exits) {
    rev_succs[virt_exit].push_back(ex);
    rev_preds[ex].push_back(virt_exit);
  }

  std::vector<uint32_t> rev_rpo;
  {
    std::vector<bool> visited(num_blocks + 1, false);
    std::function<void(uint32_t)> dfs = [&](uint32_t n) {
      if (visited[n]) return;
      visited[n] = true;
      for (auto s : rev_succs[n]) dfs(s);
      rev_rpo.push_back(n);
    };
    dfs(virt_exit);
    std::reverse(rev_rpo.begin(), rev_rpo.end());
  }

  std::unordered_map<uint32_t, uint32_t> rev_rpo_num;
  for (uint32_t i = 0; i < rev_rpo.size(); ++i) rev_rpo_num[rev_rpo[i]] = i;

  std::vector<uint32_t> ipdom(num_blocks + 1, UINT32_MAX);
  ipdom[virt_exit] = virt_exit;

  auto rev_intersect = [&](uint32_t b1, uint32_t b2) -> uint32_t {
    while (b1 != b2) {
      while (rev_rpo_num.count(b1) && rev_rpo_num.count(b2) && rev_rpo_num[b1] > rev_rpo_num[b2]) b1 = ipdom[b1];
      while (rev_rpo_num.count(b1) && rev_rpo_num.count(b2) && rev_rpo_num[b2] > rev_rpo_num[b1]) b2 = ipdom[b2];
    }
    return b1;
  };

  changed = true;
  while (changed) {
    changed = false;
    for (auto b : rev_rpo) {
      if (b == virt_exit) continue;
      uint32_t new_ipdom = UINT32_MAX;
      for (auto p : rev_preds[b]) {
        if (ipdom[p] == UINT32_MAX) continue;
        new_ipdom = (new_ipdom == UINT32_MAX) ? p : rev_intersect(new_ipdom, p);
      }
      if (new_ipdom != UINT32_MAX && ipdom[b] != new_ipdom) {
        ipdom[b] = new_ipdom;
        changed = true;
      }
    }
  }

  for (uint32_t i = 0; i < num_blocks; ++i) {
    if (ipdom[i] != UINT32_MAX && ipdom[i] != virt_exit && ipdom[i] != i)
      blocks[i].immediate_post_dominator = ipdom[i];

    uint32_t cur = i;
    while (cur != UINT32_MAX && cur != virt_exit && cur != ipdom[cur]) {
      blocks[i].post_dominator_indices.push_back(cur);
      cur = ipdom[cur];
    }
    if (cur != UINT32_MAX && cur != virt_exit)
      blocks[i].post_dominator_indices.push_back(cur);
  }
}

void IRGenerator::ComputeRPO() {
  auto &blocks = func_.blocks;
  if (blocks.empty()) return;

  uint32_t num_blocks = static_cast<uint32_t>(blocks.size());
  std::vector<bool> visited(num_blocks, false);
  func_.rpo_block_order.clear();

  std::function<void(uint32_t)> dfs = [&](uint32_t n) {
    if (visited[n]) return;
    visited[n] = true;
    for (auto s : blocks[n].successor_indices) dfs(s);
    func_.rpo_block_order.push_back(n);
  };
  dfs(func_.entry_block_index);
  std::reverse(func_.rpo_block_order.begin(), func_.rpo_block_order.end());
}

void IRGenerator::VerifyBlocks() {
  auto &blocks = func_.blocks;
  auto &instructions = func_.instructions;

  // Entry block must exist.
  DCHECK(func_.entry_block_index < blocks.size())
      << "Entry block index out of range";

  for (uint32_t bi = 0; bi < blocks.size(); ++bi) {
    auto &block = blocks[bi];

    // All blocks should have been patched before ComputeDominators.
    DCHECK(!block.instruction_indices.empty())
        << "Block " << bi << " has no instructions";

    // The last top-level instruction must be a terminator.
    {
      auto last_idx = block.instruction_indices.back();
      DCHECK(last_idx < instructions.size())
          << "Block " << bi << " last instruction index out of range";
      auto last_op = instructions[last_idx].opcode;
      DCHECK(mx::ir::IsTerminator(last_op))
          << "Block " << bi << " last instruction is not a terminator (opcode="
          << static_cast<int>(last_op) << ")";
    }

    // Successor/predecessor edges must be symmetric.
    for (auto succ_idx : block.successor_indices) {
      DCHECK(succ_idx < blocks.size())
          << "Block " << bi << " successor " << succ_idx << " out of range";
      auto &succ = blocks[succ_idx];
      bool found = false;
      for (auto pred_idx : succ.predecessor_indices) {
        if (pred_idx == bi) { found = true; break; }
      }
      DCHECK(found)
          << "Block " << bi << " -> " << succ_idx
          << " successor edge has no matching predecessor";
    }

    for (auto pred_idx : block.predecessor_indices) {
      DCHECK(pred_idx < blocks.size())
          << "Block " << bi << " predecessor " << pred_idx << " out of range";
      auto &pred = blocks[pred_idx];
      bool found = false;
      for (auto succ_idx : pred.successor_indices) {
        if (succ_idx == bi) { found = true; break; }
      }
      DCHECK(found)
          << "Block " << bi << " <- " << pred_idx
          << " predecessor edge has no matching successor";
    }
  }
}

}  // namespace ir
}  // namespace indexer
