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
#include <clang/Basic/TargetInfo.h>

#include <cassert>
#include <functional>
#include <glog/logging.h>

namespace indexer {
namespace ir {

using mx::RawEntityId;
using mx::kInvalidEntityId;
// PASTA enums for dispatch. These are converted to our unified OpCode.

// Returns true if size_bytes is a valid scalar access size (1, 2, 4, or 8).
static bool IsScalarSize(unsigned size_bytes) {
  return size_bytes == 1 || size_bytes == 2 ||
         size_bytes == 4 || size_bytes == 8;
}

// Helper: determine ConstOp from width and signedness for integer constants.
static mx::ir::ConstOp IntConstOp(uint8_t width, bool is_signed = true) {
  if (width <= 1) return mx::ir::ConstOp::BOOL;
  if (width <= 8) return is_signed ? mx::ir::ConstOp::INT8 : mx::ir::ConstOp::UINT8;
  if (width <= 16) return is_signed ? mx::ir::ConstOp::INT16 : mx::ir::ConstOp::UINT16;
  if (width <= 32) return is_signed ? mx::ir::ConstOp::INT32 : mx::ir::ConstOp::UINT32;
  return is_signed ? mx::ir::ConstOp::INT64 : mx::ir::ConstOp::UINT64;
}

// Helper: determine ConstOp for float constants.
static mx::ir::ConstOp FloatConstOp(uint8_t width) {
  if (width <= 16) return mx::ir::ConstOp::FLOAT16;
  if (width <= 32) return mx::ir::ConstOp::FLOAT32;
  return mx::ir::ConstOp::FLOAT64;
}

// Helper: determine CastOp from Clang CastKind and type info.
// src_signed: whether the source integer type is signed.
// dst_signed: whether the destination integer type is signed.
static mx::ir::CastOp DetermineCastOp(
    pasta::CastKind ck, unsigned src_bits, unsigned dst_bits,
    bool src_signed, bool dst_signed, bool src_float, bool dst_float) {
  switch (ck) {
    case pasta::CastKind::kBitCast:
      return mx::ir::CastOp::BITCAST;

    case pasta::CastKind::kIntegralCast: {
      if (dst_bits > src_bits) {
        // Widening.
        if (src_signed) {
          // Sign-extend.
          if (src_bits <= 8 && dst_bits <= 16) return mx::ir::CastOp::SEXT_I8_I16;
          if (src_bits <= 8 && dst_bits <= 32) return mx::ir::CastOp::SEXT_I8_I32;
          if (src_bits <= 8) return mx::ir::CastOp::SEXT_I8_I64;
          if (src_bits <= 16 && dst_bits <= 32) return mx::ir::CastOp::SEXT_I16_I32;
          if (src_bits <= 16) return mx::ir::CastOp::SEXT_I16_I64;
          return mx::ir::CastOp::SEXT_I32_I64;
        } else {
          // Zero-extend.
          if (src_bits <= 8 && dst_bits <= 16) return mx::ir::CastOp::ZEXT_I8_I16;
          if (src_bits <= 8 && dst_bits <= 32) return mx::ir::CastOp::ZEXT_I8_I32;
          if (src_bits <= 8) return mx::ir::CastOp::ZEXT_I8_I64;
          if (src_bits <= 16 && dst_bits <= 32) return mx::ir::CastOp::ZEXT_I16_I32;
          if (src_bits <= 16) return mx::ir::CastOp::ZEXT_I16_I64;
          return mx::ir::CastOp::ZEXT_I32_I64;
        }
      } else if (dst_bits < src_bits) {
        // Narrowing (truncate).
        if (dst_bits <= 8 && src_bits <= 16) return mx::ir::CastOp::TRUNC_I16_I8;
        if (dst_bits <= 8 && src_bits <= 32) return mx::ir::CastOp::TRUNC_I32_I8;
        if (dst_bits <= 8) return mx::ir::CastOp::TRUNC_I64_I8;
        if (dst_bits <= 16 && src_bits <= 32) return mx::ir::CastOp::TRUNC_I32_I16;
        if (dst_bits <= 16) return mx::ir::CastOp::TRUNC_I64_I16;
        return mx::ir::CastOp::TRUNC_I64_I32;
      }
      return mx::ir::CastOp::IDENTITY;
    }

    case pasta::CastKind::kPointerToIntegral:
      return dst_bits <= 32 ? mx::ir::CastOp::PTR_TO_I32 : mx::ir::CastOp::PTR_TO_I64;

    case pasta::CastKind::kIntegralToPointer:
      return src_bits <= 32 ? mx::ir::CastOp::I32_TO_PTR : mx::ir::CastOp::I64_TO_PTR;

    case pasta::CastKind::kIntegralToFloating: {
      if (src_signed) {
        if (src_bits <= 8 && dst_bits <= 32) return mx::ir::CastOp::SI8_TO_F32;
        if (src_bits <= 8) return mx::ir::CastOp::SI8_TO_F64;
        if (src_bits <= 16 && dst_bits <= 32) return mx::ir::CastOp::SI16_TO_F32;
        if (src_bits <= 16) return mx::ir::CastOp::SI16_TO_F64;
        if (src_bits <= 32 && dst_bits <= 32) return mx::ir::CastOp::SI32_TO_F32;
        if (src_bits <= 32) return mx::ir::CastOp::SI32_TO_F64;
        if (dst_bits <= 32) return mx::ir::CastOp::SI64_TO_F32;
        return mx::ir::CastOp::SI64_TO_F64;
      } else {
        if (src_bits <= 8 && dst_bits <= 32) return mx::ir::CastOp::UI8_TO_F32;
        if (src_bits <= 8) return mx::ir::CastOp::UI8_TO_F64;
        if (src_bits <= 16 && dst_bits <= 32) return mx::ir::CastOp::UI16_TO_F32;
        if (src_bits <= 16) return mx::ir::CastOp::UI16_TO_F64;
        if (src_bits <= 32 && dst_bits <= 32) return mx::ir::CastOp::UI32_TO_F32;
        if (src_bits <= 32) return mx::ir::CastOp::UI32_TO_F64;
        if (dst_bits <= 32) return mx::ir::CastOp::UI64_TO_F32;
        return mx::ir::CastOp::UI64_TO_F64;
      }
    }

    case pasta::CastKind::kFloatingToIntegral: {
      if (src_bits <= 32) {
        if (dst_bits <= 8) return dst_signed ? mx::ir::CastOp::F32_TO_SI8 : mx::ir::CastOp::F32_TO_UI8;
        if (dst_bits <= 16) return dst_signed ? mx::ir::CastOp::F32_TO_SI16 : mx::ir::CastOp::F32_TO_UI16;
        if (dst_bits <= 32) return dst_signed ? mx::ir::CastOp::F32_TO_SI32 : mx::ir::CastOp::F32_TO_UI32;
        return dst_signed ? mx::ir::CastOp::F32_TO_SI64 : mx::ir::CastOp::F32_TO_UI64;
      } else {
        if (dst_bits <= 8) return dst_signed ? mx::ir::CastOp::F64_TO_SI8 : mx::ir::CastOp::F64_TO_UI8;
        if (dst_bits <= 16) return dst_signed ? mx::ir::CastOp::F64_TO_SI16 : mx::ir::CastOp::F64_TO_UI16;
        if (dst_bits <= 32) return dst_signed ? mx::ir::CastOp::F64_TO_SI32 : mx::ir::CastOp::F64_TO_UI32;
        return dst_signed ? mx::ir::CastOp::F64_TO_SI64 : mx::ir::CastOp::F64_TO_UI64;
      }
    }

    case pasta::CastKind::kFloatingCast:
      if (src_bits <= 32 && dst_bits > 32) return mx::ir::CastOp::F32_TO_F64;
      if (src_bits > 32 && dst_bits <= 32) return mx::ir::CastOp::F64_TO_F32;
      return mx::ir::CastOp::IDENTITY;

    default:
      return mx::ir::CastOp::BITCAST;
  }
}

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
    object_to_alloca_.clear();
    address_taken_.clear();
    loop_stack_.clear();
    label_blocks_.clear();
    case_blocks_.clear();
    structure_stack_.clear();
    pending_gotos_.clear();
    label_structure_.clear();

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
      uint32_t alloca_idx = EmitTopLevel(std::move(alloca_inst));
      object_to_alloca_[obj_idx] = alloca_idx;
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

    // Emit PARAM_PTR for each parameter. PARAM_PTR gives a direct pointer
    // to the caller's ARG alloca — no local copy. The parameter's "alloca"
    // in DeclRefExpr resolution maps to this PARAM_PTR instruction.
    for (uint32_t pi = 0; pi < params.size(); ++pi) {
      const auto &param = params[pi];
      uint32_t obj_idx = GetOrMakeObject(param);

      InstructionIR pr;
      pr.opcode = mx::ir::OpCode::PARAM_PTR;
      pr.source_entity_id = EntityIdOf(param);
      pr.type_entity_id = TypeEntityIdOf(param.Type());
      pr.int_value = static_cast<int64_t>(pi);  // parameter index
      uint32_t pr_idx = EmitInstruction(std::move(pr));

      // Map the parameter object's alloca to the PARAM_PTR instruction,
      // so DeclRefExpr for the param resolves to this pointer.
      object_to_alloca_[obj_idx] = pr_idx;
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

    // Insert compensation blocks for gotos that cross scope boundaries.
    InsertGotoCompensationBlocks();

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
    func_.kind = (var.TLSKind() != pasta::VarDeclTLSKind::kNone)
        ? mx::ir::FunctionKind::THREAD_LOCAL_INITIALIZER
        : mx::ir::FunctionKind::GLOBAL_INITIALIZER;
    current_block_index_ = 0;
    current_structure_index_ = UINT32_MAX;
    next_obj_index_ = 0;
    entity_to_object_.clear();
    object_to_alloca_.clear();
    address_taken_.clear();
    loop_stack_.clear();
    label_blocks_.clear();
    case_blocks_.clear();
    structure_stack_.clear();

    // --- Frame block (empty: address comes via parameter) ---
    uint32_t frame = NewBlock(mx::ir::BlockKind::FRAME);
    func_.entry_block_index = frame;
    SwitchToBlock(frame);

    // --- Entry block: scope entry + initialization ---
    uint32_t entry = NewBlock(mx::ir::BlockKind::ENTRY);
    EmitBranch(entry);
    SwitchToBlock(entry);

    // Push FUNCTION_SCOPE.
    uint32_t func_scope = PushStructure(
        mx::ir::StructureKind::FUNCTION_SCOPE, EntityIdOf(var));
    func_.body_scope_index = func_scope;
    AssociateBlockWithStructure(entry);

    // ENTER_SCOPE for the function body.
    {
      InstructionIR enter;
      enter.opcode = mx::ir::OpCode::ENTER_SCOPE;
      enter.source_entity_id = EntityIdOf(var);
      enter.structure_index = func_scope;
      EmitTopLevel(std::move(enter));
    }

    // PARAM_PTR 0: the pointer to the global (passed by the caller).
    InstructionIR pr;
    pr.opcode = mx::ir::OpCode::PARAM_PTR;
    pr.source_entity_id = EntityIdOf(var);
    pr.type_entity_id = TypeEntityIdOf(var.Type());
    pr.int_value = 0;  // parameter index 0
    uint32_t addr_idx = EmitInstruction(std::move(pr));

    // Emit initialization (decomposes aggregates into element stores).
    EmitInitializer(addr_idx, *init, EntityIdOf(var));

    // EXIT_SCOPE + RET.
    {
      InstructionIR exit_inst;
      exit_inst.opcode = mx::ir::OpCode::EXIT_SCOPE;
      exit_inst.source_entity_id = EntityIdOf(var);
      exit_inst.structure_index = func_scope;
      EmitTopLevel(std::move(exit_inst));
    }
    {
      InstructionIR ret;
      ret.opcode = mx::ir::OpCode::RET;
      EmitTopLevel(std::move(ret));
    }

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

  // Bit-field read: emit BIT_READ instead of GEP_FIELD + LOAD.
  if (auto me = pasta::MemberExpr::From(e)) {
    auto member = me->MemberDeclaration();
    if (auto fd = pasta::FieldDecl::From(member)) {
      if (fd->IsBitField()) {
        // Emit base address (not through the MemberExpr itself).
        uint32_t base_idx;
        if (me->IsArrow()) {
          base_idx = EmitRValue(me->Base());
        } else {
          base_idx = EmitLValue(me->Base());
        }

        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::MEMORY;
        inst.source_entity_id = eid;
        if (auto t = e.Type()) {
          inst.type_entity_id = TypeEntityIdOf(*t);
        }
        inst.operand_indices = {base_idx};
        inst.target_entity_id = EntityIdOf(member);

        // Determine bit offset and width.
        if (auto bits = fd->OffsetInBits()) {
          inst.bit_offset = static_cast<uint32_t>(*bits);
        }
        if (auto bw = fd->BitWidth()) {
          auto *raw_bw = reinterpret_cast<const clang::Expr *>(bw->RawStmt());
          if (raw_bw) {
            clang::Expr::EvalResult result;
            if (raw_bw->EvaluateAsInt(result, ctx_)) {
              inst.bit_width = static_cast<uint32_t>(
                  result.Val.getInt().getZExtValue());
            }
          }
        }

        bool big_endian = ctx_.getTargetInfo().isBigEndian();
        inst.mem_op = static_cast<uint8_t>(
            big_endian ? mx::ir::MemOp::BIT_READ_BE
                       : mx::ir::MemOp::BIT_READ_LE);
        return EmitInstruction(std::move(inst));
      }
    }
  }

  uint32_t addr_idx = EmitLValue(e);

  // Check if this is a large object that can't be scalar-loaded.
  // For types > 8 bytes (structs, arrays, etc.), return the address directly —
  // the "value" of a large object is its pointer. Callers that need to copy
  // the object should use MEMCPY explicitly.
  if (auto t = e.Type()) {
    if (auto sz = TypeSizeBytes(*t)) {
      if (!IsScalarSize(*sz)) {
        return addr_idx;
      }
    }
  }

  InstructionIR inst;
  inst.opcode = mx::ir::OpCode::MEMORY;
  inst.source_entity_id = eid;
  if (auto t = e.Type()) {
    inst.type_entity_id = TypeEntityIdOf(*t);
    unsigned sz = 8;
    if (auto s = TypeSizeBytes(*t)) sz = *s;
    bool is_atomic = t->IsAtomicType();
    bool is_float = t->IsFloatingType();
    inst.mem_op = static_cast<uint8_t>(
        DetermineMemOp(false, is_atomic, sz, is_float));
  } else {
    inst.mem_op = static_cast<uint8_t>(
        DetermineMemOp(false, false, 8));
  }
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

        // Static/global-storage variables don't get local ALLOCAs.
        // They're accessed via GLOBAL_PTR and initialized by
        // GLOBAL_INITIALIZER functions.
        if (vd->HasGlobalStorage()) continue;

        uint32_t obj_idx = GetOrMakeObject(decl);

        InstructionIR alloca_inst;
        alloca_inst.opcode = mx::ir::OpCode::ALLOCA;
        alloca_inst.source_entity_id = EntityIdOf(decl);
        alloca_inst.object_index = obj_idx;
        alloca_inst.type_entity_id = TypeEntityIdOf(vd->Type());
        // Detect VLAs: VariableArrayType has runtime size.
        if (pasta::VariableArrayType::From(vd->Type())) {
          alloca_inst.alloca_kind = static_cast<uint8_t>(
              mx::ir::AllocaKind::DYNAMIC);
        }
        uint32_t alloca_idx = EmitTopLevel(std::move(alloca_inst));
        object_to_alloca_[obj_idx] = alloca_idx;
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
    SetOperandParents(op_idx);
  }
}

// ---------------------------------------------------------------------------
// Expression scope for calls
// ---------------------------------------------------------------------------

bool IRGenerator::ContainsCall(const pasta::Expr &e) {
  if (pasta::CallExpr::From(e)) return true;
  for (auto child : e.Children()) {
    if (auto child_expr = pasta::Expr::From(child)) {
      if (ContainsCall(*child_expr)) return true;
    }
  }
  return false;
}

uint32_t IRGenerator::EnsureExpressionScope(mx::RawEntityId source_eid) {
  if (expression_scope_index_ != UINT32_MAX) {
    return expression_scope_index_;
  }
  expression_scope_index_ = PushStructure(
      mx::ir::StructureKind::EXPRESSION_SCOPE, source_eid);
  InstructionIR enter;
  enter.opcode = mx::ir::OpCode::ENTER_SCOPE;
  enter.source_entity_id = source_eid;
  enter.structure_index = expression_scope_index_;
  EmitTopLevel(std::move(enter));
  return expression_scope_index_;
}

void IRGenerator::PopExpressionScope() {
  if (expression_scope_index_ == UINT32_MAX) return;
  InstructionIR exit_inst;
  exit_inst.opcode = mx::ir::OpCode::EXIT_SCOPE;
  exit_inst.structure_index = expression_scope_index_;
  EmitTopLevel(std::move(exit_inst));
  PopStructure();
  expression_scope_index_ = UINT32_MAX;
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

  // Compound statement (nested block) -- push/pop a SCOPE.
  if (auto cs = pasta::CompoundStmt::From(s)) {
    auto scope_eid = EntityIdOf(s);
    uint32_t scope_idx = PushStructure(mx::ir::StructureKind::SCOPE, scope_eid);
    AssociateBlockWithStructure(current_block_index_);
    {
      InstructionIR enter;
      enter.opcode = mx::ir::OpCode::ENTER_SCOPE;
      enter.source_entity_id = scope_eid;
      enter.structure_index = scope_idx;
      EmitTopLevel(std::move(enter));
    }
    for (const auto &child : cs->Children()) {
      EmitStmt(child);
    }
    {
      InstructionIR exit_inst;
      exit_inst.opcode = mx::ir::OpCode::EXIT_SCOPE;
      exit_inst.source_entity_id = scope_eid;
      exit_inst.structure_index = scope_idx;
      EmitTopLevel(std::move(exit_inst));
    }
    PopStructure();
    return;
  }

  // Expression statement.
  if (auto expr = pasta::Expr::From(s)) {
    uint32_t val_idx = EmitRValue(*expr);
    func_.blocks[current_block_index_].instruction_indices.push_back(val_idx);
    SetOperandParents(val_idx);
    // Pop expression scope at the full-expression boundary (the `;`).
    PopExpressionScope();
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
  PopExpressionScope();
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

  uint32_t preheader = NewBlock(mx::ir::BlockKind::LOOP_PREHEADER);
  uint32_t cond_block = NewBlock(mx::ir::BlockKind::LOOP_CONDITION);
  uint32_t body_block = NewBlock(mx::ir::BlockKind::LOOP_BODY);
  uint32_t exit_block = NewBlock(mx::ir::BlockKind::LOOP_EXIT);

  EmitBranch(preheader);
  SwitchToBlock(preheader);
  AssociateBlockWithStructure(preheader);
  EmitBranch(cond_block);

  PushStructure(mx::ir::StructureKind::WHILE_CONDITION, EntityIdOf(ws->Condition()));
  SwitchToBlock(cond_block);
  AssociateBlockWithStructure(cond_block);
  uint32_t cond_idx = EmitRValue(ws->Condition());
  PopExpressionScope();
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

  uint32_t preheader = NewBlock(mx::ir::BlockKind::LOOP_PREHEADER);
  uint32_t body_block = NewBlock(mx::ir::BlockKind::LOOP_BODY);
  uint32_t cond_block = NewBlock(mx::ir::BlockKind::LOOP_CONDITION);
  uint32_t exit_block = NewBlock(mx::ir::BlockKind::LOOP_EXIT);

  EmitBranch(preheader);
  SwitchToBlock(preheader);
  AssociateBlockWithStructure(preheader);
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
  PopExpressionScope();
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

  uint32_t preheader = NewBlock(mx::ir::BlockKind::LOOP_PREHEADER);
  uint32_t cond_block = NewBlock(mx::ir::BlockKind::LOOP_CONDITION);
  uint32_t body_block = NewBlock(mx::ir::BlockKind::LOOP_BODY);
  uint32_t inc_block = NewBlock(mx::ir::BlockKind::LOOP_INCREMENT);
  uint32_t exit_block = NewBlock(mx::ir::BlockKind::LOOP_EXIT);

  EmitBranch(preheader);
  SwitchToBlock(preheader);
  AssociateBlockWithStructure(preheader);

  // For-init lives in the preheader.
  if (init) {
    PushStructure(mx::ir::StructureKind::FOR_INIT, EntityIdOf(*init));
    EmitStmt(*init);
    PopStructure();  // FOR_INIT
  }

  EmitBranch(cond_block);

  PushStructure(mx::ir::StructureKind::FOR_CONDITION);
  SwitchToBlock(cond_block);
  AssociateBlockWithStructure(cond_block);
  if (auto cond = fs->Condition()) {
    uint32_t cond_idx = EmitRValue(*cond);
    PopExpressionScope();
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
    PopExpressionScope();
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
  PopExpressionScope();
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
      // Recurse into SubStatement to find nested cases (case 1: case 2: ...).
      auto sub = cs->SubStatement();
      if (pasta::CaseStmt::From(sub) || pasta::DefaultStmt::From(sub)) {
        collect_cases(sub);
      }
      return;
    }
    if (auto ds = pasta::DefaultStmt::From(stmt)) {
      uint32_t block = NewBlock(mx::ir::BlockKind::SWITCH_DEFAULT);
      cases.push_back({0, 0, true, block, EntityIdOf(stmt)});
      case_blocks_[EntityIdOf(stmt)] = block;
      auto sub = ds->SubStatement();
      if (pasta::CaseStmt::From(sub) || pasta::DefaultStmt::From(sub)) {
        collect_cases(sub);
      }
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

  uint32_t switch_block_idx = current_block_index_;
  uint32_t switch_structure_idx = current_structure_index_;
  uint32_t term_idx = EmitTopLevel(std::move(term));

  // Push switch context so break statements work.
  // continue_block = 0 is unused (continue skips switch contexts).
  loop_stack_.push_back({exit_block, 0, current_structure_index_, true});

  // Emit case bodies.
  // Emit case bodies. Before switching to each new case block, check if
  // the current block has been terminated. If not, it's implicit fallthrough.
  size_t ci = 0;
  auto maybe_emit_implicit_fallthrough = [&](uint32_t next_block) {
    auto &blk = func_.blocks[current_block_index_];
    // If the block already has a terminator, skip.
    if (!blk.instruction_indices.empty()) {
      auto &last = func_.instructions[blk.instruction_indices.back()];
      if (mx::ir::IsTerminator(last.opcode)) return;
    }
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
        // Record structure index back into the switch instruction.
        func_.instructions[term_idx].switch_cases[ci].structure_index =
            current_structure_index_;
        SwitchToBlock(cases[ci].block_index);
        AssociateBlockWithStructure(cases[ci].block_index);
        // Record case block structure for Duff's device compensation.
        label_structure_[cases[ci].block_index] = current_structure_index_;
        pending_gotos_.push_back({term_idx, switch_block_idx,
                                  cases[ci].block_index,
                                  switch_structure_idx});
        ci++;
        // If SubStatement is another case/default, handle it via recursion
        // (empty case fallthrough: case 1: case 2: case 3: body).
        auto sub = cs->SubStatement();
        if (pasta::CaseStmt::From(sub) || pasta::DefaultStmt::From(sub)) {
          emit_case_bodies(sub);
        } else {
          EmitBody(sub);
        }
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
        func_.instructions[term_idx].switch_cases[ci].structure_index =
            current_structure_index_;
        SwitchToBlock(cases[ci].block_index);
        AssociateBlockWithStructure(cases[ci].block_index);
        label_structure_[cases[ci].block_index] = current_structure_index_;
        pending_gotos_.push_back({term_idx, switch_block_idx,
                                  cases[ci].block_index,
                                  switch_structure_idx});
        ci++;
        auto sub = ds->SubStatement();
        if (pasta::CaseStmt::From(sub) || pasta::DefaultStmt::From(sub)) {
          emit_case_bodies(sub);
        } else {
          EmitBody(sub);
        }
        PopStructure();  // SWITCH_CASE (default)
      }
      return;
    }
    // For CompoundStmt or other container, process children.
    // Non-case/default statements (like break, assignments between cases)
    // are emitted directly.
    if (pasta::CompoundStmt::From(stmt)) {
      for (const auto &child : stmt.Children()) {
        emit_case_bodies(child);
      }
    } else {
      // Regular statement between cases (e.g., break, goto, assignment).
      EmitStmt(stmt);
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
    PopExpressionScope();

    // RET carries the value as operand for backward compat
    // (RetInst::return_value() reads it).
    inst.operand_indices = {val_idx};

    // Emit RETURN_PTR to get pointer to caller's return storage.
    InstructionIR ret_ptr;
    ret_ptr.opcode = mx::ir::OpCode::RETURN_PTR;
    ret_ptr.source_entity_id = EntityIdOf(s);
    if (auto t = rv->Type()) ret_ptr.type_entity_id = TypeEntityIdOf(*t);
    uint32_t ret_ptr_idx = EmitInstruction(std::move(ret_ptr));

    // Store the return value into RETURN_PTR.
    unsigned sz = 8;
    if (auto t = rv->Type()) {
      if (auto s = TypeSizeBytes(*t)) sz = *s;
    }
    InstructionIR store;
    store.opcode = mx::ir::OpCode::MEMORY;
    store.source_entity_id = EntityIdOf(s);
    if (!IsScalarSize(sz) || rv->IsLValue()) {
      // Large or lvalue: MEMCPY.
      InstructionIR size_inst;
      size_inst.opcode = mx::ir::OpCode::CONST;
      size_inst.const_op = static_cast<uint8_t>(mx::ir::ConstOp::UINT64);
      size_inst.uint_value = sz;
      size_inst.width = 64;
      uint32_t size_idx = EmitInstruction(std::move(size_inst));
      uint32_t src_idx = rv->IsLValue() ? EmitLValue(*rv) : val_idx;
      store.operand_indices = {ret_ptr_idx, src_idx, size_idx};
      store.mem_op = static_cast<uint8_t>(mx::ir::MemOp::MEMCPY);
    } else {
      store.operand_indices = {ret_ptr_idx, val_idx};
      store.mem_op = static_cast<uint8_t>(
          DetermineMemOp(true, false, sz));
    }
    EmitTopLevel(std::move(store));
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

  // Allocas were already emitted in the frame block by EmitEntryBlockAllocas.
  // Here we only emit the initialization store for non-static locals.
  // Static locals are initialized by their GLOBAL_INITIALIZER functions.
  for (const auto &decl : ds->Declarations()) {
    auto vd = pasta::VarDecl::From(decl);
    if (!vd) continue;
    if (pasta::ParmVarDecl::From(decl)) continue;

    // Static/global-storage variables: initialization is handled by
    // GLOBAL_INITIALIZER. Don't emit local init code.
    if (vd->HasGlobalStorage()) continue;

    uint32_t obj_idx = GetOrMakeObject(decl);
    AssociateObjectWithScope(obj_idx);

    if (auto init = vd->Initializer()) {
      uint32_t addr_idx = object_to_alloca_[obj_idx];
      EmitInitializer(addr_idx, *init, EntityIdOf(decl));
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

  // Don't emit scope exits here — compensation blocks handle it.
  // Record the goto for post-processing.
  uint32_t goto_idx = EmitBranchWithOpCode(mx::ir::OpCode::GOTO, target,
                                            EntityIdOf(s));
  if (goto_idx != UINT32_MAX) {
    pending_gotos_.push_back({goto_idx, current_block_index_, target,
                              current_structure_index_});
  }
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

  // Record which structure this label is in (for goto compensation).
  label_structure_[label_block] = current_structure_index_;

  // Reaching a label sequentially is an implicit goto.
  EmitBranchWithOpCode(mx::ir::OpCode::IMPLICIT_GOTO, label_block,
                        EntityIdOf(s));
  SwitchToBlock(label_block);
  AssociateBlockWithStructure(label_block);

  EmitStmt(ls->SubStatement());
}

// ---------------------------------------------------------------------------
// Initializer emission (decomposes aggregates into element stores)
// ---------------------------------------------------------------------------

void IRGenerator::EmitInitializer(uint32_t dest_addr_idx,
                                   const pasta::Expr &init,
                                   mx::RawEntityId source_eid) {
  // If the initializer is an InitListExpr, decompose it into element stores.
  if (auto ile = pasta::InitListExpr::From(init)) {
    auto inits = ile->Initializers();
    auto maybe_type = init.Type();
    if (!maybe_type) goto scalar_fallback;

    auto type = *maybe_type;

    // Zero-initialize the whole object before element-wise stores.
    // The compiler emits a memset for aggregate initialization.
    // ENTER_SCOPE only marks memory as allocated-but-uninitialized;
    // this MEMSET is what actually makes the memory defined.
    auto total_size = TypeSizeBytes(type);
    if (total_size && *total_size > 0) {
      InstructionIR zero;
      zero.opcode = mx::ir::OpCode::CONST;
      zero.const_op = static_cast<uint8_t>(mx::ir::ConstOp::UINT8);
      zero.source_entity_id = source_eid;
      zero.int_value = 0;
      zero.uint_value = 0;
      zero.width = 8;
      uint32_t zero_idx = EmitInstruction(std::move(zero));

      InstructionIR sz;
      sz.opcode = mx::ir::OpCode::CONST;
      sz.const_op = static_cast<uint8_t>(mx::ir::ConstOp::UINT64);
      sz.source_entity_id = source_eid;
      sz.int_value = static_cast<int64_t>(*total_size);
      sz.uint_value = static_cast<uint64_t>(*total_size);
      sz.width = 64;
      uint32_t sz_idx = EmitInstruction(std::move(sz));

      InstructionIR memset_inst;
      memset_inst.opcode = mx::ir::OpCode::MEMORY;
      memset_inst.mem_op = static_cast<uint8_t>(mx::ir::MemOp::MEMSET);
      memset_inst.source_entity_id = source_eid;
      memset_inst.operand_indices = {dest_addr_idx, zero_idx, sz_idx};
      EmitTopLevel(std::move(memset_inst));
    }

    // Strip qualifiers/sugar to get the underlying type.
    auto canon = type.CanonicalType();

    // Array initialization: PTR_ADD for each element.
    if (auto arr_type = pasta::ConstantArrayType::From(canon)) {
      auto elem_type = arr_type->ElementType();
      auto elem_size = TypeSizeBytes(elem_type);
      if (!elem_size || *elem_size == 0) goto scalar_fallback;

      for (uint32_t i = 0; i < inits.size(); ++i) {
        uint32_t elem_addr;
        if (i == 0) {
          elem_addr = dest_addr_idx;
        } else {
          // PTR_ADD base, i.
          InstructionIR ci;
          ci.opcode = mx::ir::OpCode::CONST;
          ci.const_op = static_cast<uint8_t>(mx::ir::ConstOp::INT64);
          ci.source_entity_id = source_eid;
          ci.int_value = static_cast<int64_t>(i);
          ci.uint_value = static_cast<uint64_t>(i);
          ci.width = 64;
          uint32_t idx_val = EmitInstruction(std::move(ci));

          InstructionIR pa;
          pa.opcode = mx::ir::OpCode::PTR_ADD;
          pa.source_entity_id = source_eid;
          pa.operand_indices = {dest_addr_idx, idx_val};
          pa.type_entity_id = TypeEntityIdOf(elem_type);
          pa.size_bytes = *elem_size;
          elem_addr = EmitInstruction(std::move(pa));
        }
        // Recurse for nested aggregates.
        EmitInitializer(elem_addr, inits[i], source_eid);
      }

      return;
    }

    // Struct/union initialization: GEP_FIELD for each field.
    if (auto rec_type = pasta::RecordType::From(canon)) {
      auto rec_decl = rec_type->Declaration();
      auto fields = rec_decl.Fields();

      uint32_t init_idx = 0;
      for (const auto &field : fields) {
        if (init_idx >= inits.size()) break;

        // Bit-fields: use BIT_WRITE to set individual bit ranges.
        if (field.IsBitField()) {
          auto offset_bits = field.OffsetInBits();
          auto bw = field.BitWidth();
          if (offset_bits && bw) {
            // Get bit width from the BitWidth expression.
            auto *raw_bw = reinterpret_cast<const clang::Expr *>(bw->RawStmt());
            clang::Expr::EvalResult eval_result;
            unsigned bit_width = 0;
            if (raw_bw && raw_bw->EvaluateAsInt(eval_result, ctx_)) {
              bit_width = static_cast<unsigned>(
                  eval_result.Val.getInt().getZExtValue());
            }
            if (bit_width > 0) {
              // MEMORY(BIT_WRITE): op[0]=addr, op[1]=value.
              // bit_offset and bit_width stored in int pool (not as operands).
              uint32_t val_idx = EmitRValue(inits[init_idx]);

              InstructionIR bw_inst;
              bw_inst.opcode = mx::ir::OpCode::MEMORY;
              bw_inst.mem_op = static_cast<uint8_t>(
                  ctx_.getTargetInfo().isBigEndian()
                      ? mx::ir::MemOp::BIT_WRITE_BE
                      : mx::ir::MemOp::BIT_WRITE_LE);
              bw_inst.source_entity_id = source_eid;
              bw_inst.bit_offset = static_cast<uint32_t>(*offset_bits);
              bw_inst.bit_width = bit_width;
              bw_inst.operand_indices = {dest_addr_idx, val_idx};
              EmitTopLevel(std::move(bw_inst));
            }
          }
          ++init_idx;
          continue;
        }

        auto offset_bits = field.OffsetInBits();
        if (!offset_bits) continue;
        uint32_t byte_offset = static_cast<uint32_t>(*offset_bits / 8);

        InstructionIR gep;
        gep.opcode = mx::ir::OpCode::GEP_FIELD;
        gep.source_entity_id = source_eid;
        gep.operand_indices = {dest_addr_idx};
        gep.target_entity_id = EntityIdOf(field);
        gep.size_bytes = byte_offset;
        gep.type_entity_id = TypeEntityIdOf(field.Type());
        uint32_t field_addr = EmitInstruction(std::move(gep));

        EmitInitializer(field_addr, inits[init_idx], source_eid);
        ++init_idx;
      }
      return;
    }

    // Single-element init list for scalars: { expr }.
    if (inits.size() == 1) {
      EmitInitializer(dest_addr_idx, inits[0], source_eid);
      return;
    }
  }

scalar_fallback:
  // Emit the value and store/copy it into the destination.
  {
    unsigned sz = 8;
    if (auto t = init.Type()) {
      if (auto s = TypeSizeBytes(*t)) sz = *s;
    }

    uint32_t val_idx = EmitRValue(init);
    InstructionIR store;
    store.opcode = mx::ir::OpCode::MEMORY;
    store.source_entity_id = source_eid;

    if (!IsScalarSize(sz)) {
      // Non-scalar size (e.g., string literal char[6]): MEMCPY.
      // val_idx is a pointer for non-scalar types.
      InstructionIR size_inst;
      size_inst.opcode = mx::ir::OpCode::CONST;
      size_inst.const_op = static_cast<uint8_t>(mx::ir::ConstOp::UINT64);
      size_inst.uint_value = sz;
      size_inst.width = 64;
      uint32_t size_idx = EmitInstruction(std::move(size_inst));
      store.operand_indices = {dest_addr_idx, val_idx, size_idx};
      store.mem_op = static_cast<uint8_t>(mx::ir::MemOp::MEMCPY);
    } else {
      store.operand_indices = {dest_addr_idx, val_idx};
      store.mem_op = static_cast<uint8_t>(
          DetermineMemOp(true, false, sz));
    }
    EmitTopLevel(std::move(store));
  }
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
    inst.opcode = mx::ir::OpCode::CONST;
    inst.source_entity_id = eid;
    auto *raw = reinterpret_cast<const clang::IntegerLiteral *>(il->RawStmt());
    if (raw) {
      auto val = raw->getValue();
      inst.int_value = val.getSExtValue();
      inst.uint_value = val.getZExtValue();
      inst.width = static_cast<uint8_t>(val.getBitWidth());
      bool is_signed = raw->getType()->isSignedIntegerOrEnumerationType();
      inst.const_op = static_cast<uint8_t>(IntConstOp(inst.width, is_signed));
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
    inst.opcode = mx::ir::OpCode::CONST;
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
      inst.const_op = static_cast<uint8_t>(FloatConstOp(inst.width));
    }
    return emit_typed(std::move(inst));
  }

  // Character literal -- use Clang's value.
  if (auto cl = pasta::CharacterLiteral::From(e)) {
    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::CONST;
    inst.source_entity_id = eid;
    auto *raw = reinterpret_cast<const clang::CharacterLiteral *>(cl->RawStmt());
    if (raw) {
      inst.int_value = raw->getValue();
      // Determine char width from Clang's CharacterKind.
      switch (raw->getKind()) {
        case clang::CharacterLiteralKind::Wide:
          inst.width = static_cast<uint8_t>(ctx_.getTargetInfo().getWCharWidth());
          inst.const_op = static_cast<uint8_t>(
              inst.width <= 16 ? mx::ir::ConstOp::WCHAR16 : mx::ir::ConstOp::WCHAR32);
          break;
        case clang::CharacterLiteralKind::UTF16:
          inst.width = 16;
          inst.const_op = static_cast<uint8_t>(mx::ir::ConstOp::WCHAR16);
          break;
        case clang::CharacterLiteralKind::UTF32:
          inst.width = 32;
          inst.const_op = static_cast<uint8_t>(mx::ir::ConstOp::WCHAR32);
          break;
        default:
          inst.width = 8;
          inst.const_op = static_cast<uint8_t>(mx::ir::ConstOp::UINT8);
          break;
      }
    } else {
      inst.width = 8;
      inst.const_op = static_cast<uint8_t>(mx::ir::ConstOp::UINT8);
    }
    return emit_typed(std::move(inst));
  }

  // String literal.
  if (auto sl = pasta::StringLiteral::From(e)) {
    ObjectIR obj;
    obj.kind = mx::ir::ObjectKind::STRING_LITERAL;
    obj.size_bytes = static_cast<uint32_t>(sl->Tokens().Data().size());
    uint32_t obj_idx = next_obj_index_++;
    func_.objects.push_back(std::move(obj));

    InstructionIR alloca_inst;
    alloca_inst.opcode = mx::ir::OpCode::ALLOCA;
    alloca_inst.source_entity_id = eid;
    alloca_inst.object_index = obj_idx;
    if (auto t = e.Type()) alloca_inst.type_entity_id = TypeEntityIdOf(*t);
    uint32_t alloca_idx = emit_typed(std::move(alloca_inst));
    object_to_alloca_[obj_idx] = alloca_idx;
    return alloca_idx;
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
      // Bit-field read: emit BIT_READ instead of normal LOAD.
      if (auto me = pasta::MemberExpr::From(sub)) {
        auto member = me->MemberDeclaration();
        if (auto fd = pasta::FieldDecl::From(member)) {
          if (fd->IsBitField()) {
            uint32_t base_idx;
            if (me->IsArrow()) {
              base_idx = EmitRValue(me->Base());
            } else {
              base_idx = EmitLValue(me->Base());
            }

            InstructionIR inst;
            inst.opcode = mx::ir::OpCode::MEMORY;
            inst.source_entity_id = eid;
            if (maybe_type) {
              inst.type_entity_id = TypeEntityIdOf(*maybe_type);
            }
            inst.operand_indices = {base_idx};
            inst.target_entity_id = EntityIdOf(member);

            if (auto bits = fd->OffsetInBits()) {
              inst.bit_offset = static_cast<uint32_t>(*bits);
            }
            if (auto bw = fd->BitWidth()) {
              auto *raw_bw = reinterpret_cast<const clang::Expr *>(
                  bw->RawStmt());
              if (raw_bw) {
                clang::Expr::EvalResult result;
                if (raw_bw->EvaluateAsInt(result, ctx_)) {
                  inst.bit_width = static_cast<uint32_t>(
                      result.Val.getInt().getZExtValue());
                }
              }
            }

            bool big_endian = ctx_.getTargetInfo().isBigEndian();
            inst.mem_op = static_cast<uint8_t>(
                big_endian ? mx::ir::MemOp::BIT_READ_BE
                           : mx::ir::MemOp::BIT_READ_LE);
            return emit_typed(std::move(inst));
          }
        }
      }

      uint32_t addr_idx = EmitLValue(sub);

      // For large objects, LValueToRValue returns the address —
      // the "value" is the pointer to the object.
      if (maybe_type) {
        if (auto sz = TypeSizeBytes(*maybe_type)) {
          if (!IsScalarSize(*sz)) {
            return addr_idx;
          }
        }
      }

      InstructionIR inst;
      inst.opcode = mx::ir::OpCode::MEMORY;
      inst.source_entity_id = eid;
      if (maybe_type) {
        inst.type_entity_id = TypeEntityIdOf(*maybe_type);
        unsigned sz = 8;
        if (auto s = TypeSizeBytes(*maybe_type)) sz = *s;
        bool is_atomic = maybe_type->IsAtomicType();
        bool is_float = maybe_type->IsFloatingType();
        inst.mem_op = static_cast<uint8_t>(
            DetermineMemOp(false, is_atomic, sz, is_float));
      } else {
        inst.mem_op = static_cast<uint8_t>(
            DetermineMemOp(false, false, 8));
      }
      inst.operand_indices = {addr_idx};
      return emit_typed(std::move(inst));
    }
    if (ck == pasta::CastKind::kArrayToPointerDecay) {
      // Array decays to pointer: the address of the array IS the pointer.
      return EmitLValue(sub);
    }
    if (ck == pasta::CastKind::kNoOperation) {
      return EmitRValue(sub);
    }
    if (ck == pasta::CastKind::kFunctionToPointerDecay) {
      return EmitLValue(sub);
    }
    if (ck == pasta::CastKind::kNullToPointer) {
      InstructionIR inst;
      inst.opcode = mx::ir::OpCode::CONST;
      inst.const_op = static_cast<uint8_t>(mx::ir::ConstOp::NULL_PTR);
      inst.source_entity_id = eid;
      return emit_typed(std::move(inst));
    }
    if (ck == pasta::CastKind::kIntegralToBoolean) {
      uint32_t sub_idx = EmitRValue(sub);
      InstructionIR zero;
      zero.opcode = mx::ir::OpCode::CONST;
      zero.const_op = static_cast<uint8_t>(mx::ir::ConstOp::INT32);
      zero.int_value = 0; zero.width = 32;
      uint32_t zero_idx = EmitInstruction(std::move(zero));
      InstructionIR inst;
      inst.opcode = mx::ir::OpCode::CMP_NE;
      inst.source_entity_id = eid;
      inst.operand_indices = {sub_idx, zero_idx};
      return emit_typed(std::move(inst));
    }

    // Map cast kinds to unified CAST opcode with CastOp sub-opcode.
    {
      // Determine source/dest type info for CastOp selection.
      auto sub_type = sub.Type();
      unsigned src_bits = 64, dst_bits = 64;
      bool src_signed = true, dst_signed = true;
      bool src_float = false, dst_float = false;
      if (sub_type) {
        auto *raw_sub_type = reinterpret_cast<const clang::Expr *>(sub.RawStmt());
        if (raw_sub_type) {
          src_bits = static_cast<unsigned>(ctx_.getTypeSize(raw_sub_type->getType()));
          src_signed = raw_sub_type->getType()->isSignedIntegerOrEnumerationType();
          src_float = raw_sub_type->getType()->isFloatingType();
        }
      }
      if (maybe_type) {
        auto *raw_e = reinterpret_cast<const clang::Expr *>(e.RawStmt());
        if (raw_e) {
          dst_bits = static_cast<unsigned>(ctx_.getTypeSize(raw_e->getType()));
          dst_signed = raw_e->getType()->isSignedIntegerOrEnumerationType();
          dst_float = raw_e->getType()->isFloatingType();
        }
      }

      auto cast_sub = DetermineCastOp(ck, src_bits, dst_bits,
                                       src_signed, dst_signed, src_float, dst_float);
      uint32_t sub_idx = EmitRValue(sub);
      InstructionIR inst;
      inst.opcode = mx::ir::OpCode::CAST;
      inst.cast_op = static_cast<uint8_t>(cast_sub);
      inst.source_entity_id = eid;
      if (maybe_type) inst.type_entity_id = TypeEntityIdOf(*maybe_type);
      inst.operand_indices = {sub_idx};
      return emit_typed(std::move(inst));
    }
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
    {
      auto sub_expr = ece->SubExpression();
      unsigned src_bits = 64, dst_bits = 64;
      bool src_signed = true, dst_signed = true;
      bool src_float = false, dst_float = false;
      auto *raw_sub = reinterpret_cast<const clang::Expr *>(sub_expr.RawStmt());
      if (raw_sub) {
        src_bits = static_cast<unsigned>(ctx_.getTypeSize(raw_sub->getType()));
        src_signed = raw_sub->getType()->isSignedIntegerOrEnumerationType();
        src_float = raw_sub->getType()->isFloatingType();
      }
      auto *raw_e = reinterpret_cast<const clang::Expr *>(e.RawStmt());
      if (raw_e) {
        dst_bits = static_cast<unsigned>(ctx_.getTypeSize(raw_e->getType()));
        dst_signed = raw_e->getType()->isSignedIntegerOrEnumerationType();
        dst_float = raw_e->getType()->isFloatingType();
      }
      auto cast_sub = DetermineCastOp(ck, src_bits, dst_bits,
                                       src_signed, dst_signed, src_float, dst_float);
      uint32_t sub_idx = EmitRValue(sub_expr);
      InstructionIR inst;
      inst.opcode = mx::ir::OpCode::CAST;
      inst.cast_op = static_cast<uint8_t>(cast_sub);
      inst.source_entity_id = eid;
      if (auto t = e.Type()) inst.type_entity_id = TypeEntityIdOf(*t);
      inst.operand_indices = {sub_idx};
      return emit_typed(std::move(inst));
    }
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
        inst.opcode = mx::ir::OpCode::MEMORY;
        inst.source_entity_id = eid;
        if (auto t__ = e.Type()) {
          inst.type_entity_id = TypeEntityIdOf(*t__);
          unsigned sz = 8;
          if (auto s = TypeSizeBytes(*t__)) sz = *s;
          inst.mem_op = static_cast<uint8_t>(
              DetermineMemOp(false, false, sz));
        } else {
          inst.mem_op = static_cast<uint8_t>(
              DetermineMemOp(false, false, 8));
        }
        inst.operand_indices = {ptr_idx};
        return emit_typed(std::move(inst));
      }
      if (oc == pasta::UnaryOperatorKind::kPreIncrement ||
          oc == pasta::UnaryOperatorKind::kPreDecrement ||
          oc == pasta::UnaryOperatorKind::kPostIncrement ||
          oc == pasta::UnaryOperatorKind::kPostDecrement) {
        uint32_t addr_idx = EmitLValue(sub);
        bool is_inc = (oc == pasta::UnaryOperatorKind::kPreIncrement ||
                       oc == pasta::UnaryOperatorKind::kPostIncrement);
        bool is_pre = (oc == pasta::UnaryOperatorKind::kPreIncrement ||
                       oc == pasta::UnaryOperatorKind::kPreDecrement);

        // Determine underlying op and element size for pointers.
        auto sub_type = sub.Type();
        bool is_ptr = sub_type && sub_type->IsAnyPointerType();
        mx::ir::OpCode underlying = is_inc ? mx::ir::OpCode::ADD
                                           : mx::ir::OpCode::SUB;
        uint32_t elem_sz = 0;
        // Delta: +1 for integers (ADD/SUB handles direction).
        // For pointers: +1 (increment) or -1 (decrement) with PTR_ADD.
        int64_t delta = 1;
        if (is_ptr) {
          underlying = mx::ir::OpCode::PTR_ADD;
          if (!is_inc) delta = -1;
          if (auto pt = sub_type->PointeeType()) {
            if (auto sz = TypeSizeBytes(*pt)) elem_sz = *sz;
          }
        }

        // Emit the delta CONST now that we know the final value.
        InstructionIR delta_inst;
        delta_inst.opcode = mx::ir::OpCode::CONST;
        delta_inst.const_op = static_cast<uint8_t>(mx::ir::ConstOp::INT64);
        delta_inst.source_entity_id = eid;
        delta_inst.int_value = delta;
        delta_inst.uint_value = static_cast<uint64_t>(delta);
        delta_inst.width = 64;
        if (expr_type) delta_inst.type_entity_id = TypeEntityIdOf(*expr_type);
        uint32_t delta_idx = EmitInstruction(std::move(delta_inst));

        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::READ_MODIFY_WRITE;
        inst.source_entity_id = eid;
        inst.operand_indices = {addr_idx, delta_idx};
        inst.compound_op = underlying;
        inst.size_bytes = elem_sz;
        inst.is_big_endian = ctx_.getTargetInfo().isBigEndian();
        // flags bit0 = returns_new_value: pre returns new, post returns old.
        inst.flags = is_pre ? 1 : 0;
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

      // Assignment: always MEMCPY when RHS is an lvalue (has an address).
      // For computed scalars (arithmetic results), use STORE.
      if (oc == pasta::BinaryOperatorKind::kAssign) {
        // Bit-field assignment: use BIT_WRITE instead of GEP_FIELD + STORE.
        if (auto me = pasta::MemberExpr::From(bo->LHS())) {
          auto member = me->MemberDeclaration();
          if (auto fd = pasta::FieldDecl::From(member)) {
            if (fd->IsBitField()) {
              uint32_t base_idx;
              if (me->IsArrow()) {
                base_idx = EmitRValue(me->Base());
              } else {
                base_idx = EmitLValue(me->Base());
              }
              uint32_t val_idx = EmitRValue(bo->RHS());
              InstructionIR inst;
              inst.opcode = mx::ir::OpCode::MEMORY;
              inst.source_entity_id = eid;
              inst.operand_indices = {base_idx, val_idx};
              inst.target_entity_id = EntityIdOf(member);
              if (auto bits = fd->OffsetInBits()) {
                inst.bit_offset = static_cast<uint32_t>(*bits);
              }
              if (auto bw = fd->BitWidth()) {
                auto *raw_bw = reinterpret_cast<const clang::Expr *>(
                    bw->RawStmt());
                if (raw_bw) {
                  clang::Expr::EvalResult result;
                  if (raw_bw->EvaluateAsInt(result, ctx_)) {
                    inst.bit_width = static_cast<uint32_t>(
                        result.Val.getInt().getZExtValue());
                  }
                }
              }
              bool big_endian = ctx_.getTargetInfo().isBigEndian();
              inst.mem_op = static_cast<uint8_t>(
                  big_endian ? mx::ir::MemOp::BIT_WRITE_BE
                             : mx::ir::MemOp::BIT_WRITE_LE);
              return emit_typed(std::move(inst));
            }
          }
        }

        uint32_t addr_idx = EmitLValue(bo->LHS());
        auto rhs = bo->RHS();
        unsigned sz = 8;
        if (auto t = rhs.Type()) {
          if (auto s = TypeSizeBytes(*t)) sz = *s;
        }

        // If RHS is an lvalue or the type is large, use MEMCPY.
        bool rhs_is_lvalue = rhs.IsLValue();
        bool is_large = (!IsScalarSize(sz));
        if (rhs_is_lvalue || is_large) {
          // Get the address of the RHS.
          uint32_t src_idx = rhs_is_lvalue ? EmitLValue(rhs) : EmitRValue(rhs);
          InstructionIR size_inst;
          size_inst.opcode = mx::ir::OpCode::CONST;
          size_inst.const_op = static_cast<uint8_t>(mx::ir::ConstOp::UINT64);
          size_inst.uint_value = sz;
          size_inst.width = 64;
          uint32_t size_idx = EmitInstruction(std::move(size_inst));
          InstructionIR inst;
          inst.opcode = mx::ir::OpCode::MEMORY;
          inst.source_entity_id = eid;
          inst.operand_indices = {addr_idx, src_idx, size_idx};
          inst.mem_op = static_cast<uint8_t>(mx::ir::MemOp::MEMCPY);
          return emit_typed(std::move(inst));
        }

        // RHS is a computed scalar value — use STORE.
        uint32_t val_idx = EmitRValue(rhs);
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::MEMORY;
        inst.source_entity_id = eid;
        inst.operand_indices = {addr_idx, val_idx};
        auto lhs_type = bo->LHS().Type();
        bool is_atomic = lhs_type && lhs_type->IsAtomicType();
        bool is_float = lhs_type && lhs_type->IsFloatingType();
        inst.mem_op = static_cast<uint8_t>(
            DetermineMemOp(true, is_atomic, sz, is_float));
        return emit_typed(std::move(inst));
      }

      // Compound assignment -> READ_MODIFY_WRITE.
      if (pasta::CompoundAssignOperator::From(e)) {
        uint32_t addr_idx = EmitLValue(bo->LHS());
        uint32_t val_idx = EmitRValue(bo->RHS());
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::READ_MODIFY_WRITE;
        inst.source_entity_id = eid;
        inst.operand_indices = {addr_idx, val_idx};

        // Check if LHS is a pointer type for += and -=.
        // Check if LHS is _Atomic for atomic compound assignment.
        auto lhs_type = bo->LHS().Type();
        bool lhs_is_ptr = lhs_type && lhs_type->IsAnyPointerType();
        bool lhs_is_atomic = lhs_type && lhs_type->IsAtomicType();

        switch (oc) {
          case pasta::BinaryOperatorKind::kAddAssign:
            if (lhs_is_ptr) {
              inst.compound_op = mx::ir::OpCode::PTR_ADD;
              if (auto pt = lhs_type->PointeeType()) {
                if (auto sz = TypeSizeBytes(*pt)) inst.size_bytes = *sz;
              }
            } else {
              inst.compound_op = lhs_is_atomic ? mx::ir::OpCode::ATOMIC_ADD
                                               : mx::ir::OpCode::ADD;
            }
            break;
          case pasta::BinaryOperatorKind::kSubAssign:
            if (lhs_is_ptr) {
              InstructionIR neg;
              neg.opcode = mx::ir::OpCode::NEG;
              neg.source_entity_id = eid;
              neg.operand_indices = {val_idx};
              val_idx = EmitInstruction(std::move(neg));
              inst.operand_indices = {addr_idx, val_idx};
              inst.compound_op = mx::ir::OpCode::PTR_ADD;
              if (auto pt = lhs_type->PointeeType()) {
                if (auto sz = TypeSizeBytes(*pt)) inst.size_bytes = *sz;
              }
            } else {
              inst.compound_op = lhs_is_atomic ? mx::ir::OpCode::ATOMIC_SUB
                                               : mx::ir::OpCode::SUB;
            }
            break;
          case pasta::BinaryOperatorKind::kMulAssign: inst.compound_op = mx::ir::OpCode::MUL; break;
          case pasta::BinaryOperatorKind::kDivAssign: inst.compound_op = mx::ir::OpCode::DIV; break;
          case pasta::BinaryOperatorKind::kRemAssign: inst.compound_op = mx::ir::OpCode::REM; break;
          case pasta::BinaryOperatorKind::kAndAssign:
            inst.compound_op = lhs_is_atomic ? mx::ir::OpCode::ATOMIC_AND
                                             : mx::ir::OpCode::BIT_AND;
            break;
          case pasta::BinaryOperatorKind::kOrAssign:
            inst.compound_op = lhs_is_atomic ? mx::ir::OpCode::ATOMIC_OR
                                             : mx::ir::OpCode::BIT_OR;
            break;
          case pasta::BinaryOperatorKind::kXorAssign:
            inst.compound_op = lhs_is_atomic ? mx::ir::OpCode::ATOMIC_XOR
                                             : mx::ir::OpCode::BIT_XOR;
            break;
          case pasta::BinaryOperatorKind::kShlAssign: inst.compound_op = mx::ir::OpCode::SHL; break;
          case pasta::BinaryOperatorKind::kShrAssign: inst.compound_op = mx::ir::OpCode::SHR; break;
          default: inst.compound_op = mx::ir::OpCode::ADD; break;
        }
        // Compound assign always returns the new value.
        inst.flags = 1;
        inst.is_big_endian = ctx_.getTargetInfo().isBigEndian();
        return emit_typed(std::move(inst));
      }

      // Comma operator: evaluate both sides, return the last value.
      if (oc == pasta::BinaryOperatorKind::kComma) {
        uint32_t lhs_idx = EmitRValue(bo->LHS());
        uint32_t rhs_idx = EmitRValue(bo->RHS());
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::LAST_VALUE;
        inst.source_entity_id = eid;
        inst.operand_indices = {lhs_idx, rhs_idx};
        return emit_typed(std::move(inst));
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

      // Use unsigned opcodes for unsigned operands.
      {
        auto op_type = e.Type();
        bool is_unsigned = op_type && op_type->IsUnsignedIntegerType();
        if (is_unsigned) {
          if (arith_op == mx::ir::OpCode::DIV) arith_op = mx::ir::OpCode::UDIV;
          else if (arith_op == mx::ir::OpCode::REM) arith_op = mx::ir::OpCode::UREM;
          else if (arith_op == mx::ir::OpCode::SHR) arith_op = mx::ir::OpCode::USHR;
        }
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
        // ptr - ptr → PTR_DIFF (result in elements, not bytes)
        uint32_t lhs_idx = EmitRValue(bo->LHS());
        uint32_t rhs_idx = EmitRValue(bo->RHS());
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::PTR_DIFF;
        inst.source_entity_id = eid;
        inst.operand_indices = {lhs_idx, rhs_idx};
        // Element size needed to convert byte difference to element count.
        if (auto pt = pasta::PointerType::From(*lhs_type)) {
          auto pointee = pt->PointeeType();
          if (auto sz = TypeSizeBytes(pointee)) inst.size_bytes = *sz;
        }
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
      // For unsigned ops, store the operand width so the interpreter
      // can mask to the correct bit width before operating.
      if (arith_op >= mx::ir::OpCode::UDIV &&
          arith_op <= mx::ir::OpCode::USHR) {
        if (auto t = e.Type()) {
          if (auto sz = TypeSizeBytes(*t)) inst.size_bytes = *sz;
        }
      }
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

      // Recognize memory/string operations and lower to MEMORY.
      {
        using MO = mx::ir::MemOp;
        struct MemBuiltin {
          const char *name;
          MO op;
          unsigned min_args;
        };
        static const MemBuiltin mem_builtins[] = {
          {"memset", MO::MEMSET, 3},
          {"__builtin_memset", MO::MEMSET, 3},
          {"__builtin_memset_chk", MO::MEMSET, 3},
          {"__builtin___memset_chk", MO::MEMSET, 3},
          {"memcpy", MO::MEMCPY, 3},
          {"__builtin_memcpy", MO::MEMCPY, 3},
          {"__builtin_memcpy_chk", MO::MEMCPY, 3},
          {"__builtin___memcpy_chk", MO::MEMCPY, 3},
          {"memmove", MO::MEMMOVE, 3},
          {"__builtin_memmove", MO::MEMMOVE, 3},
          {"__builtin_memmove_chk", MO::MEMMOVE, 3},
          {"__builtin___memmove_chk", MO::MEMMOVE, 3},
          {"memcmp", MO::MEMCMP, 3},
          {"__builtin_memcmp", MO::MEMCMP, 3},
          {"memchr", MO::MEMCHR, 3},
          {"__builtin_memchr", MO::MEMCHR, 3},
          {"bzero", MO::BZERO, 2},
          {"__builtin_bzero", MO::BZERO, 2},
          {"strlen", MO::STRLEN, 1},
          {"__builtin_strlen", MO::STRLEN, 1},
          {"strnlen", MO::STRNLEN, 2},
          {"__builtin_strnlen", MO::STRNLEN, 2},
          {"strcmp", MO::STRCMP, 2},
          {"__builtin_strcmp", MO::STRCMP, 2},
          {"strncmp", MO::STRNCMP, 3},
          {"__builtin_strncmp", MO::STRNCMP, 3},
          {"strchr", MO::STRCHR, 2},
          {"__builtin_strchr", MO::STRCHR, 2},
          {"strrchr", MO::STRRCHR, 2},
          {"__builtin_strrchr", MO::STRRCHR, 2},
          {"strstr", MO::STRSTR, 2},
          {"__builtin_strstr", MO::STRSTR, 2},
          {"strcpy", MO::STRCPY, 2},
          {"__builtin_strcpy", MO::STRCPY, 2},
          {"__builtin___strcpy_chk", MO::STRCPY, 2},
          {"strncpy", MO::STRNCPY, 3},
          {"__builtin_strncpy", MO::STRNCPY, 3},
          {"__builtin___strncpy_chk", MO::STRNCPY, 3},
          {"strcat", MO::STRCAT, 2},
          {"__builtin_strcat", MO::STRCAT, 2},
          {"__builtin___strcat_chk", MO::STRCAT, 2},
          {"strncat", MO::STRNCAT, 3},
          {"__builtin_strncat", MO::STRNCAT, 3},
          {"__builtin___strncat_chk", MO::STRNCAT, 3},
          {"stpcpy", MO::STPCPY, 2},
          {"__builtin_stpcpy", MO::STPCPY, 2},
          {"stpncpy", MO::STPNCPY, 3},
          {"__builtin_stpncpy", MO::STPNCPY, 3},
          // String-to-number (fixed size).
          {"atoi", MO::STRTOI32, 1},    // int is always 32-bit
          {"atoll", MO::STRTOI64, 1},
          {"atof", MO::STRTOF64, 1},
          {"strtoll", MO::STRTOI64, 3},
          {"strtoull", MO::STRTOU64, 3},
          {"strtod", MO::STRTOF64, 2},
          {"strtof", MO::STRTOF32, 2},
          // _chk variants map to the base operation (extra dest_size arg ignored).
          {"__memcpy_chk", MO::MEMCPY, 3},
          {"__memset_chk", MO::MEMSET, 3},
          {"__memmove_chk", MO::MEMMOVE, 3},
          {"__strcpy_chk", MO::STRCPY, 2},
          {"__strncpy_chk", MO::STRNCPY, 3},
          {"__strcat_chk", MO::STRCAT, 2},
          {"__strncat_chk", MO::STRNCAT, 3},
        };
        for (const auto &mb : mem_builtins) {
          if (callee_name == mb.name && args.size() >= mb.min_args) {
            InstructionIR inst;
            inst.opcode = mx::ir::OpCode::MEMORY;
            inst.mem_op = static_cast<uint8_t>(mb.op);
            inst.source_entity_id = eid;
            for (unsigned i = 0; i < mb.min_args; ++i) {
              inst.operand_indices.push_back(EmitRValue(args[i]));
            }
            return emit_typed(std::move(inst));
          }
        }
      }

      // Size-dependent string-to-number: atol/strtol/strtoul depend on
      // sizeof(long), which varies by platform.
      if (callee_name == "atol" || callee_name == "strtol" ||
          callee_name == "strtoul") {
        using MO = mx::ir::MemOp;
        bool is_long64 = (ctx_.getTargetInfo().getLongWidth() == 64);
        MO op;
        unsigned min_args;
        if (callee_name == "atol") {
          op = is_long64 ? MO::STRTOI64 : MO::STRTOI32;
          min_args = 1;
        } else if (callee_name == "strtol") {
          op = is_long64 ? MO::STRTOI64 : MO::STRTOI32;
          min_args = 3;
        } else {
          op = is_long64 ? MO::STRTOU64 : MO::STRTOU32;
          min_args = 3;
        }
        if (args.size() >= min_args) {
          InstructionIR inst;
          inst.opcode = mx::ir::OpCode::MEMORY;
          inst.mem_op = static_cast<uint8_t>(op);
          inst.source_entity_id = eid;
          for (unsigned i = 0; i < min_args; ++i) {
            inst.operand_indices.push_back(EmitRValue(args[i]));
          }
          return emit_typed(std::move(inst));
        }
      }

      // __builtin_unreachable() → UNREACHABLE.
      if (callee_name == "__builtin_unreachable") {
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::UNREACHABLE;
        inst.source_entity_id = eid;
        return emit_typed(std::move(inst));
      }

      // __builtin_expect(x, v) / __builtin_expect_with_probability → just x.
      if (callee_name == "__builtin_expect" ||
          callee_name == "__builtin_expect_with_probability") {
        if (!args.empty()) return EmitRValue(args[0]);
      }

      // __builtin_assume(x) → BITWISE(ASSUME, x).
      if (callee_name == "__builtin_assume") {
        if (!args.empty()) {
          InstructionIR inst;
          inst.opcode = mx::ir::OpCode::BITWISE;
          inst.source_entity_id = eid;
          inst.bitwise_op = static_cast<uint8_t>(mx::ir::BitwiseOp::ASSUME);
          inst.operand_indices.push_back(EmitRValue(args[0]));
          return emit_typed(std::move(inst));
        }
      }

      // Overflow-checked arithmetic builtins →
      //   STORE &result, UNDEFINED
      //   overflow = RMW(&result, ADD_OVERFLOW, a, b)
      if (callee_name == "__builtin_add_overflow" ||
          callee_name == "__builtin_sub_overflow" ||
          callee_name == "__builtin_mul_overflow") {
        if (args.size() >= 3) {
          mx::ir::OpCode overflow_op = mx::ir::OpCode::ADD_OVERFLOW;
          if (callee_name == "__builtin_sub_overflow")
            overflow_op = mx::ir::OpCode::SUB_OVERFLOW;
          else if (callee_name == "__builtin_mul_overflow")
            overflow_op = mx::ir::OpCode::MUL_OVERFLOW;

          uint32_t a_idx = EmitRValue(args[0]);
          uint32_t b_idx = EmitRValue(args[1]);
          uint32_t dest_idx = EmitRValue(args[2]);

          // Store UNDEFINED to dest to mark it as initialized-but-unknown.
          InstructionIR undef;
          undef.opcode = mx::ir::OpCode::UNDEFINED;
          undef.source_entity_id = eid;
          uint32_t undef_idx = EmitInstruction(std::move(undef));

          InstructionIR store;
          store.opcode = mx::ir::OpCode::MEMORY;
          store.source_entity_id = eid;
          store.operand_indices = {dest_idx, undef_idx};
          store.mem_op = static_cast<uint8_t>(
              DetermineMemOp(true, false, 8));
          EmitTopLevel(std::move(store));

          // RMW(&result, overflow_op, a, b) → returns bool (overflow flag).
          InstructionIR rmw;
          rmw.opcode = mx::ir::OpCode::READ_MODIFY_WRITE;
          rmw.source_entity_id = eid;
          rmw.compound_op = overflow_op;
          rmw.flags = 1;  // returns new value (the overflow flag)
          rmw.is_big_endian = ctx_.getTargetInfo().isBigEndian();
          rmw.operand_indices = {dest_idx, a_idx, b_idx};
          return emit_typed(std::move(rmw));
        }
      }

      // Bitwise/intrinsic builtins → BITWISE with sub-opcode.
      {
        using BO = mx::ir::BitwiseOp;
        struct BitwiseBuiltin {
          const char *name;
          BO op;
          bool undef_for_zero;  // CLZ/CTZ are undefined for input == 0
        };
        static const BitwiseBuiltin bitwise_builtins[] = {
          {"__builtin_bswap16", BO::BSWAP16, false},
          {"__builtin_bswap32", BO::BSWAP32, false},
          {"__builtin_bswap64", BO::BSWAP64, false},
          {"__builtin_popcount", BO::POPCOUNT, false},
          {"__builtin_popcountl", BO::POPCOUNT, false},
          {"__builtin_popcountll", BO::POPCOUNT, false},
          {"__builtin_clz", BO::CLZ, true},
          {"__builtin_clzl", BO::CLZ, true},
          {"__builtin_clzll", BO::CLZ, true},
          {"__builtin_ctz", BO::CTZ, true},
          {"__builtin_ctzl", BO::CTZ, true},
          {"__builtin_ctzll", BO::CTZ, true},
          {"__builtin_ffs", BO::FFS, false},
          {"__builtin_ffsl", BO::FFS, false},
          {"__builtin_ffsll", BO::FFS, false},
          {"__builtin_parity", BO::PARITY, false},
          {"__builtin_parityl", BO::PARITY, false},
          {"__builtin_parityll", BO::PARITY, false},
          {"__builtin_abs", BO::ABS, false},
        };
        for (const auto &bb : bitwise_builtins) {
          if (callee_name == bb.name && !args.empty()) {
            uint32_t val_idx = EmitRValue(args[0]);

            InstructionIR bw;
            bw.opcode = mx::ir::OpCode::BITWISE;
            bw.source_entity_id = eid;
            bw.bitwise_op = static_cast<uint8_t>(bb.op);
            bw.operand_indices.push_back(val_idx);
            uint32_t bw_idx = EmitInstruction(std::move(bw));

            if (bb.undef_for_zero) {
              // result = SELECT(val == 0, UNDEFINED, bw_result)
              InstructionIR zero;
              zero.opcode = mx::ir::OpCode::CONST;
              zero.const_op = static_cast<uint8_t>(mx::ir::ConstOp::INT64);
              zero.source_entity_id = eid;
              zero.int_value = 0;
              zero.uint_value = 0;
              zero.width = 64;
              uint32_t zero_idx = EmitInstruction(std::move(zero));

              InstructionIR cmp;
              cmp.opcode = mx::ir::OpCode::CMP_EQ;
              cmp.source_entity_id = eid;
              cmp.operand_indices = {val_idx, zero_idx};
              uint32_t cmp_idx = EmitInstruction(std::move(cmp));

              InstructionIR undef;
              undef.opcode = mx::ir::OpCode::UNDEFINED;
              undef.source_entity_id = eid;
              uint32_t undef_idx = EmitInstruction(std::move(undef));

              InstructionIR sel;
              sel.opcode = mx::ir::OpCode::SELECT;
              sel.source_entity_id = eid;
              sel.operand_indices = {cmp_idx, undef_idx, bw_idx};
              return emit_typed(std::move(sel));
            }

            // For defined-for-all-inputs builtins, just return the BITWISE.
            // Re-wrap as top-level since we already called EmitInstruction.
            auto &bw_ref = func_.instructions[bw_idx];
            if (auto t = e.Type()) bw_ref.type_entity_id = TypeEntityIdOf(*t);
            return bw_idx;
          }
        }
      }

      // Float builtins → FLOAT with sub-opcode.
      {
        using FO = mx::ir::FloatOp;
        struct FloatBuiltin {
          const char *name;
          FO op;
          unsigned num_args;
        };
        static const FloatBuiltin float_builtins[] = {
          {"__builtin_isnan", FO::ISNAN, 1},
          {"__builtin_isinf", FO::ISINF, 1},
          {"__builtin_isfinite", FO::ISFINITE, 1},
          {"__builtin_fabs", FO::FABS, 1},
          {"__builtin_fabsf", FO::FABS, 1},
          {"__builtin_fabsl", FO::FABS, 1},
          {"fabs", FO::FABS, 1},
          {"fabsf", FO::FABS, 1},
          {"fabsl", FO::FABS, 1},
          {"__builtin_copysign", FO::COPYSIGN, 2},
          {"__builtin_copysignf", FO::COPYSIGN, 2},
          {"__builtin_copysignl", FO::COPYSIGN, 2},
          {"copysign", FO::COPYSIGN, 2},
          {"copysignf", FO::COPYSIGN, 2},
          {"__builtin_fmin", FO::FMIN, 2},
          {"__builtin_fminf", FO::FMIN, 2},
          {"fmin", FO::FMIN, 2},
          {"fminf", FO::FMIN, 2},
          {"__builtin_fmax", FO::FMAX, 2},
          {"__builtin_fmaxf", FO::FMAX, 2},
          {"fmax", FO::FMAX, 2},
          {"fmaxf", FO::FMAX, 2},
          {"__builtin_ceil", FO::CEIL, 1},
          {"__builtin_ceilf", FO::CEIL, 1},
          {"ceil", FO::CEIL, 1},
          {"ceilf", FO::CEIL, 1},
          {"__builtin_floor", FO::FLOOR, 1},
          {"__builtin_floorf", FO::FLOOR, 1},
          {"floor", FO::FLOOR, 1},
          {"floorf", FO::FLOOR, 1},
          {"__builtin_round", FO::ROUND, 1},
          {"__builtin_roundf", FO::ROUND, 1},
          {"round", FO::ROUND, 1},
          {"roundf", FO::ROUND, 1},
          {"__builtin_trunc", FO::TRUNC, 1},
          {"__builtin_truncf", FO::TRUNC, 1},
          {"trunc", FO::TRUNC, 1},
          {"truncf", FO::TRUNC, 1},
          {"__builtin_sqrt", FO::SQRT, 1},
          {"__builtin_sqrtf", FO::SQRT, 1},
          {"sqrt", FO::SQRT, 1},
          {"sqrtf", FO::SQRT, 1},
          // Trigonometric.
          {"sin", FO::SIN, 1}, {"sinf", FO::SIN, 1},
          {"__builtin_sin", FO::SIN, 1}, {"__builtin_sinf", FO::SIN, 1},
          {"cos", FO::COS, 1}, {"cosf", FO::COS, 1},
          {"__builtin_cos", FO::COS, 1}, {"__builtin_cosf", FO::COS, 1},
          {"tan", FO::TAN, 1}, {"tanf", FO::TAN, 1},
          {"__builtin_tan", FO::TAN, 1}, {"__builtin_tanf", FO::TAN, 1},
          {"asin", FO::ASIN, 1}, {"asinf", FO::ASIN, 1},
          {"__builtin_asin", FO::ASIN, 1}, {"__builtin_asinf", FO::ASIN, 1},
          {"acos", FO::ACOS, 1}, {"acosf", FO::ACOS, 1},
          {"__builtin_acos", FO::ACOS, 1}, {"__builtin_acosf", FO::ACOS, 1},
          {"atan", FO::ATAN, 1}, {"atanf", FO::ATAN, 1},
          {"__builtin_atan", FO::ATAN, 1}, {"__builtin_atanf", FO::ATAN, 1},
          {"atan2", FO::ATAN2, 2}, {"atan2f", FO::ATAN2, 2},
          {"__builtin_atan2", FO::ATAN2, 2}, {"__builtin_atan2f", FO::ATAN2, 2},
          // Exponential/logarithmic.
          {"exp", FO::EXP, 1}, {"expf", FO::EXP, 1},
          {"__builtin_exp", FO::EXP, 1}, {"__builtin_expf", FO::EXP, 1},
          {"exp2", FO::EXP2, 1}, {"exp2f", FO::EXP2, 1},
          {"__builtin_exp2", FO::EXP2, 1}, {"__builtin_exp2f", FO::EXP2, 1},
          {"log", FO::LOG, 1}, {"logf", FO::LOG, 1},
          {"__builtin_log", FO::LOG, 1}, {"__builtin_logf", FO::LOG, 1},
          {"log2", FO::LOG2, 1}, {"log2f", FO::LOG2, 1},
          {"__builtin_log2", FO::LOG2, 1}, {"__builtin_log2f", FO::LOG2, 1},
          {"log10", FO::LOG10, 1}, {"log10f", FO::LOG10, 1},
          {"__builtin_log10", FO::LOG10, 1}, {"__builtin_log10f", FO::LOG10, 1},
          // Power/modular.
          {"pow", FO::POW, 2}, {"powf", FO::POW, 2},
          {"__builtin_pow", FO::POW, 2}, {"__builtin_powf", FO::POW, 2},
          {"fmod", FO::FMOD, 2}, {"fmodf", FO::FMOD, 2},
          {"__builtin_fmod", FO::FMOD, 2}, {"__builtin_fmodf", FO::FMOD, 2},
          {"remainder", FO::REMAINDER, 2}, {"remainderf", FO::REMAINDER, 2},
          {"__builtin_remainder", FO::REMAINDER, 2},
          {"fma", FO::FMA, 3}, {"fmaf", FO::FMA, 3},
          {"__builtin_fma", FO::FMA, 3}, {"__builtin_fmaf", FO::FMA, 3},
          // Hyperbolic.
          {"sinh", FO::SINH, 1}, {"sinhf", FO::SINH, 1},
          {"__builtin_sinh", FO::SINH, 1},
          {"cosh", FO::COSH, 1}, {"coshf", FO::COSH, 1},
          {"__builtin_cosh", FO::COSH, 1},
          {"tanh", FO::TANH, 1}, {"tanhf", FO::TANH, 1},
          {"__builtin_tanh", FO::TANH, 1},
          // Other.
          {"hypot", FO::HYPOT, 2}, {"hypotf", FO::HYPOT, 2},
          {"__builtin_hypot", FO::HYPOT, 2},
          {"erf", FO::ERF, 1}, {"erff", FO::ERF, 1},
          {"__builtin_erf", FO::ERF, 1},
          {"erfc", FO::ERFC, 1}, {"erfcf", FO::ERFC, 1},
          {"__builtin_erfc", FO::ERFC, 1},
          {"tgamma", FO::TGAMMA, 1}, {"tgammaf", FO::TGAMMA, 1},
          {"__builtin_tgamma", FO::TGAMMA, 1},
          {"lgamma", FO::LGAMMA, 1}, {"lgammaf", FO::LGAMMA, 1},
          {"__builtin_lgamma", FO::LGAMMA, 1},
          {"fdim", FO::FDIM, 2}, {"fdimf", FO::FDIM, 2},
          {"__builtin_fdim", FO::FDIM, 2},
          {"__builtin_signbit", FO::SIGNBIT, 1},
          {"signbit", FO::SIGNBIT, 1},
        };
        for (const auto &fb : float_builtins) {
          if (callee_name == fb.name && args.size() >= fb.num_args) {
            InstructionIR inst;
            inst.opcode = mx::ir::OpCode::FLOAT;
            inst.float_op = static_cast<uint8_t>(fb.op);
            inst.source_entity_id = eid;
            for (unsigned i = 0; i < fb.num_args; ++i) {
              inst.operand_indices.push_back(EmitRValue(args[i]));
            }
            return emit_typed(std::move(inst));
          }
        }

        // Zero-argument float constants.
        if (callee_name == "__builtin_inf" || callee_name == "__builtin_inff" ||
            callee_name == "__builtin_infl") {
          InstructionIR inst;
          inst.opcode = mx::ir::OpCode::FLOAT;
          inst.float_op = static_cast<uint8_t>(FO::INF);
          inst.source_entity_id = eid;
          return emit_typed(std::move(inst));
        }
        if (callee_name == "__builtin_nan" || callee_name == "__builtin_nanf" ||
            callee_name == "__builtin_nanl") {
          InstructionIR inst;
          inst.opcode = mx::ir::OpCode::FLOAT;
          inst.float_op = static_cast<uint8_t>(FO::NAN_VAL);
          inst.source_entity_id = eid;
          return emit_typed(std::move(inst));
        }
        if (callee_name == "__builtin_huge_val" ||
            callee_name == "__builtin_huge_valf" ||
            callee_name == "__builtin_huge_vall") {
          InstructionIR inst;
          inst.opcode = mx::ir::OpCode::FLOAT;
          inst.float_op = static_cast<uint8_t>(FO::FLOAT_HUGE);
          inst.source_entity_id = eid;
          return emit_typed(std::move(inst));
        }
      }

      // Dynamic alloca → ALLOCA/DYNAMIC with scope-tracked object.
      if (callee_name == "__builtin_alloca" || callee_name == "alloca") {
        if (!args.empty()) {
          // Create an ALLOCA object so the scope can track this allocation.
          // On scope exit, the interpreter frees objects of kind ALLOCA.
          ObjectIR obj;
          obj.kind = mx::ir::ObjectKind::ALLOCA;
          obj.source_decl_id = eid;
          uint32_t obj_idx = next_obj_index_++;
          func_.objects.push_back(std::move(obj));
          AssociateObjectWithScope(obj_idx);

          InstructionIR inst;
          inst.opcode = mx::ir::OpCode::ALLOCA;
          inst.alloca_kind = static_cast<uint8_t>(mx::ir::AllocaKind::DYNAMIC);
          inst.source_entity_id = eid;
          inst.object_index = obj_idx;
          inst.operand_indices.push_back(EmitRValue(args[0]));
          return emit_typed(std::move(inst));
        }
      }

      // Frame/return address intrinsics.
      if (callee_name == "__builtin_frame_address") {
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::FRAME_PTR;
        inst.source_entity_id = eid;
        if (!args.empty()) {
          inst.operand_indices.push_back(EmitRValue(args[0]));
        } else {
          // Default level 0.
          InstructionIR zero;
          zero.opcode = mx::ir::OpCode::CONST;
          zero.const_op = static_cast<uint8_t>(mx::ir::ConstOp::INT32);
          zero.source_entity_id = eid;
          zero.int_value = 0;
          zero.uint_value = 0;
          zero.width = 32;
          inst.operand_indices.push_back(EmitInstruction(std::move(zero)));
        }
        return emit_typed(std::move(inst));
      }
      if (callee_name == "__builtin_return_address") {
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::RETURN_ADDRESS;
        inst.source_entity_id = eid;
        if (!args.empty()) {
          inst.operand_indices.push_back(EmitRValue(args[0]));
        } else {
          InstructionIR zero;
          zero.opcode = mx::ir::OpCode::CONST;
          zero.const_op = static_cast<uint8_t>(mx::ir::ConstOp::INT32);
          zero.source_entity_id = eid;
          zero.int_value = 0;
          zero.uint_value = 0;
          zero.width = 32;
          inst.operand_indices.push_back(EmitInstruction(std::move(zero)));
        }
        return emit_typed(std::move(inst));
      }

      // Atomic load/store/cmpxchg builtins.
      if (callee_name == "__atomic_load_n" || callee_name == "__c11_atomic_load") {
        if (!args.empty()) {
          InstructionIR inst;
          inst.opcode = mx::ir::OpCode::MEMORY;
          inst.source_entity_id = eid;
          inst.operand_indices.push_back(EmitRValue(args[0]));
          {
            unsigned sz = 8;
            if (auto t = e.Type()) {
              if (auto s = TypeSizeBytes(*t)) sz = *s;
            }
            inst.mem_op = static_cast<uint8_t>(
                DetermineMemOp(false, true, sz));
          }
          return emit_typed(std::move(inst));
        }
      }
      if (callee_name == "__atomic_store_n" || callee_name == "__c11_atomic_store") {
        if (args.size() >= 2) {
          InstructionIR inst;
          inst.opcode = mx::ir::OpCode::MEMORY;
          inst.source_entity_id = eid;
          inst.operand_indices.push_back(EmitRValue(args[0]));
          inst.operand_indices.push_back(EmitRValue(args[1]));
          {
            unsigned sz = 8;
            if (auto t = args[1].Type()) {
              if (auto s = TypeSizeBytes(*t)) sz = *s;
            }
            inst.mem_op = static_cast<uint8_t>(
                DetermineMemOp(true, true, sz));
          }
          return emit_typed(std::move(inst));
        }
      }
      if (callee_name == "__atomic_compare_exchange_n" ||
          callee_name == "__c11_atomic_compare_exchange_strong" ||
          callee_name == "__c11_atomic_compare_exchange_weak" ||
          callee_name == "__sync_bool_compare_and_swap" ||
          callee_name == "__sync_val_compare_and_swap") {
        if (args.size() >= 3) {
          InstructionIR inst;
          inst.opcode = mx::ir::OpCode::MEMORY;
          inst.source_entity_id = eid;
          inst.operand_indices.push_back(EmitRValue(args[0]));
          inst.operand_indices.push_back(EmitRValue(args[1]));
          inst.operand_indices.push_back(EmitRValue(args[2]));
          {
            unsigned sz = 8;
            if (auto t = args[2].Type()) {
              if (auto s = TypeSizeBytes(*t)) sz = *s;
            }
            bool big = ctx_.getTargetInfo().isBigEndian();
            unsigned size_idx;
            switch (sz) {
              case 1: size_idx = 0; break;
              case 2: size_idx = 1; break;
              case 4: size_idx = 2; break;
              case 8: default: size_idx = 3; break;
            }
            unsigned base = big ? static_cast<unsigned>(mx::ir::MemOp::CMPXCHG_BE_8)
                                : static_cast<unsigned>(mx::ir::MemOp::CMPXCHG_LE_8);
            inst.mem_op = static_cast<uint8_t>(base + size_idx);
          }
          return emit_typed(std::move(inst));
        }
      }

      // Atomic fetch-and-modify → RMW with atomic underlying opcodes.
      {
        struct AtomicRMWBuiltin {
          const char *name;
          mx::ir::OpCode underlying;
          bool returns_new;  // true = returns new value, false = returns old
        };
        static const AtomicRMWBuiltin atomic_rmw_builtins[] = {
          {"__atomic_fetch_add", mx::ir::OpCode::ATOMIC_ADD, false},
          {"__atomic_add_fetch", mx::ir::OpCode::ATOMIC_ADD, true},
          {"__sync_fetch_and_add", mx::ir::OpCode::ATOMIC_ADD, false},
          {"__atomic_fetch_sub", mx::ir::OpCode::ATOMIC_SUB, false},
          {"__atomic_sub_fetch", mx::ir::OpCode::ATOMIC_SUB, true},
          {"__sync_fetch_and_sub", mx::ir::OpCode::ATOMIC_SUB, false},
          {"__atomic_fetch_and", mx::ir::OpCode::ATOMIC_AND, false},
          {"__atomic_and_fetch", mx::ir::OpCode::ATOMIC_AND, true},
          {"__sync_fetch_and_and", mx::ir::OpCode::ATOMIC_AND, false},
          {"__atomic_fetch_or", mx::ir::OpCode::ATOMIC_OR, false},
          {"__atomic_or_fetch", mx::ir::OpCode::ATOMIC_OR, true},
          {"__sync_fetch_and_or", mx::ir::OpCode::ATOMIC_OR, false},
          {"__atomic_fetch_xor", mx::ir::OpCode::ATOMIC_XOR, false},
          {"__atomic_xor_fetch", mx::ir::OpCode::ATOMIC_XOR, true},
          {"__sync_fetch_and_xor", mx::ir::OpCode::ATOMIC_XOR, false},
          {"__atomic_fetch_nand", mx::ir::OpCode::ATOMIC_NAND, false},
          {"__atomic_nand_fetch", mx::ir::OpCode::ATOMIC_NAND, true},
          {"__sync_fetch_and_nand", mx::ir::OpCode::ATOMIC_NAND, false},
          {"__atomic_exchange_n", mx::ir::OpCode::ATOMIC_EXCHANGE, false},
          {"__sync_lock_test_and_set", mx::ir::OpCode::ATOMIC_EXCHANGE, false},
        };
        for (const auto &ab : atomic_rmw_builtins) {
          if (callee_name == ab.name && args.size() >= 2) {
            InstructionIR rmw;
            rmw.opcode = mx::ir::OpCode::READ_MODIFY_WRITE;
            rmw.source_entity_id = eid;
            rmw.compound_op = ab.underlying;
            rmw.flags = ab.returns_new ? 1u : 0u;
            rmw.operand_indices.push_back(EmitRValue(args[0]));
            rmw.operand_indices.push_back(EmitRValue(args[1]));
            rmw.is_big_endian = ctx_.getTargetInfo().isBigEndian();
            // Set element size from the pointee type (args[0] is a pointer).
            if (auto arg_type = args[0].Type()) {
              if (auto pt = arg_type->PointeeType()) {
                if (auto sz = TypeSizeBytes(*pt)) rmw.size_bytes = *sz;
              }
            }
            return emit_typed(std::move(rmw));
          }
        }
      }

      // Type query builtins → CONST.
      if (callee_name == "__builtin_constant_p") {
        // In our IR everything is "not a constant" from the optimizer's view.
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::CONST;
        inst.const_op = static_cast<uint8_t>(mx::ir::ConstOp::INT32);
        inst.source_entity_id = eid;
        inst.int_value = 0;
        inst.uint_value = 0;
        inst.width = 32;
        return emit_typed(std::move(inst));
      }
      if (callee_name == "__builtin_types_compatible_p" ||
          callee_name == "__builtin_classify_type" ||
          callee_name == "__builtin_object_size") {
        auto *raw = reinterpret_cast<const clang::Expr *>(e.RawStmt());
        if (raw) {
          clang::Expr::EvalResult eval_result;
          if (raw->EvaluateAsInt(eval_result, ctx_)) {
            auto ap_val = eval_result.Val.getInt();
            InstructionIR inst;
            inst.opcode = mx::ir::OpCode::CONST;
            inst.const_op = static_cast<uint8_t>(IntConstOp(
                static_cast<uint8_t>(std::min<unsigned>(ap_val.getBitWidth(), 64u)),
                true));
            inst.source_entity_id = eid;
            inst.int_value = ap_val.getSExtValue();
            inst.uint_value = ap_val.getZExtValue();
            inst.width = static_cast<uint8_t>(
                std::min<unsigned>(ap_val.getBitWidth(), 64u));
            return emit_typed(std::move(inst));
          }
        }
        // Fallback for __builtin_object_size: return -1 (unknown).
        if (callee_name == "__builtin_object_size") {
          InstructionIR inst;
          inst.opcode = mx::ir::OpCode::CONST;
          inst.const_op = static_cast<uint8_t>(mx::ir::ConstOp::INT64);
          inst.source_entity_id = eid;
          inst.int_value = -1;
          inst.uint_value = static_cast<uint64_t>(-1);
          inst.width = 64;
          return emit_typed(std::move(inst));
        }
      }
    }

    // Ensure we have an EXPRESSION_SCOPE for the argument allocas.
    EnsureExpressionScope(eid);

    InstructionIR inst;
    inst.source_entity_id = eid;
    inst.opcode = mx::ir::OpCode::CALL;

    auto args = ce->Arguments();

    if (direct_callee) {
      auto canon = direct_callee->CanonicalDeclaration();
      inst.target_entity_id = EntityIdOf(canon);
    } else {
      inst.target_entity_id = kInvalidEntityId;
      // For indirect calls, first operand is the callee pointer.
      inst.operand_indices.push_back(EmitRValue(ce->Callee()));
    }

    // Create ARG allocas for each argument.
    for (uint32_t i = 0; i < args.size(); ++i) {
      auto arg_expr = args[i];
      uint32_t val_idx = EmitRValue(arg_expr);

      // Create ALLOCA/ARG for this argument.
      ObjectIR obj;
      obj.kind = mx::ir::ObjectKind::PARAMETER;
      obj.source_decl_id = EntityIdOf(arg_expr);
      if (auto t = arg_expr.Type()) {
        obj.type_entity_id = TypeEntityIdOf(*t);
        if (auto sz = TypeSizeBytes(*t)) obj.size_bytes = *sz;
        if (auto al = TypeAlignBytes(*t)) obj.align_bytes = *al;
      }
      uint32_t obj_idx = next_obj_index_++;
      func_.objects.push_back(std::move(obj));
      AssociateObjectWithScope(obj_idx);

      InstructionIR alloca_inst;
      alloca_inst.opcode = mx::ir::OpCode::ALLOCA;
      alloca_inst.alloca_kind = static_cast<uint8_t>(mx::ir::AllocaKind::ARG);
      alloca_inst.source_entity_id = EntityIdOf(arg_expr);
      alloca_inst.object_index = obj_idx;
      if (auto t = arg_expr.Type()) {
        alloca_inst.type_entity_id = TypeEntityIdOf(*t);
      }
      uint32_t alloca_idx = EmitInstruction(std::move(alloca_inst));

      // Copy value into the ARG alloca.
      unsigned sz = 8;
      if (auto t = arg_expr.Type()) {
        if (auto s = TypeSizeBytes(*t)) sz = *s;
      }

      InstructionIR store;
      store.opcode = mx::ir::OpCode::MEMORY;
      store.source_entity_id = EntityIdOf(arg_expr);
      if (!IsScalarSize(sz)) {
        // Large argument: MEMCPY.
        InstructionIR size_inst;
        size_inst.opcode = mx::ir::OpCode::CONST;
        size_inst.const_op = static_cast<uint8_t>(mx::ir::ConstOp::UINT64);
        size_inst.uint_value = sz;
        size_inst.width = 64;
        uint32_t size_idx = EmitInstruction(std::move(size_inst));
        store.operand_indices = {alloca_idx, val_idx, size_idx};
        store.mem_op = static_cast<uint8_t>(mx::ir::MemOp::MEMCPY);
      } else if (arg_expr.IsLValue()) {
        // Lvalue arg: MEMCPY from source address.
        uint32_t src_idx = EmitLValue(arg_expr);
        InstructionIR size_inst;
        size_inst.opcode = mx::ir::OpCode::CONST;
        size_inst.const_op = static_cast<uint8_t>(mx::ir::ConstOp::UINT64);
        size_inst.uint_value = sz;
        size_inst.width = 64;
        uint32_t size_idx = EmitInstruction(std::move(size_inst));
        store.operand_indices = {alloca_idx, src_idx, size_idx};
        store.mem_op = static_cast<uint8_t>(mx::ir::MemOp::MEMCPY);
      } else {
        // Scalar rvalue: STORE.
        store.operand_indices = {alloca_idx, val_idx};
        store.mem_op = static_cast<uint8_t>(
            DetermineMemOp(true, false, sz));
      }
      EmitTopLevel(std::move(store));

      // CALL operand is the ARG alloca (pointer to argument storage).
      inst.operand_indices.push_back(alloca_idx);
    }

    // Create ALLOCA/RETURN for the return value (if non-void).
    auto ret_type = ce->Type();
    bool has_return = ret_type && !ret_type->IsVoidType();
    uint32_t return_alloca_idx = UINT32_MAX;
    if (has_return) {
      ObjectIR ret_obj;
      ret_obj.kind = mx::ir::ObjectKind::RETURN_SLOT;
      if (ret_type) {
        ret_obj.type_entity_id = TypeEntityIdOf(*ret_type);
        if (auto sz = TypeSizeBytes(*ret_type)) ret_obj.size_bytes = *sz;
        if (auto al = TypeAlignBytes(*ret_type)) ret_obj.align_bytes = *al;
      }
      uint32_t ret_obj_idx = next_obj_index_++;
      func_.objects.push_back(std::move(ret_obj));
      AssociateObjectWithScope(ret_obj_idx);

      InstructionIR ret_alloca;
      ret_alloca.opcode = mx::ir::OpCode::ALLOCA;
      ret_alloca.alloca_kind = static_cast<uint8_t>(mx::ir::AllocaKind::RETURN);
      ret_alloca.source_entity_id = eid;
      ret_alloca.object_index = ret_obj_idx;
      if (ret_type) ret_alloca.type_entity_id = TypeEntityIdOf(*ret_type);
      return_alloca_idx = EmitInstruction(std::move(ret_alloca));
    }

    inst.return_alloca_index = return_alloca_idx;
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

  // sizeof / alignof / other type traits -- emit as CONST.
  if (auto tte = pasta::UnaryExprOrTypeTraitExpr::From(e)) {
    auto arg_type = tte->TypeOfArgument();
    std::optional<uint32_t> val;
    if (tte->KeywordKind() == pasta::UnaryExprOrTypeTrait::kSizeOf) {
      val = TypeSizeBytes(arg_type);
    } else if (tte->KeywordKind() == pasta::UnaryExprOrTypeTrait::kAlignOf ||
               tte->KeywordKind() == pasta::UnaryExprOrTypeTrait::kPreferredAlignOf) {
      val = TypeAlignBytes(arg_type);
    } else {
      val = TypeSizeBytes(arg_type);  // fallback
    }
    if (val) {
      InstructionIR inst;
      inst.opcode = mx::ir::OpCode::CONST;
      inst.const_op = static_cast<uint8_t>(mx::ir::ConstOp::UINT64);
      inst.source_entity_id = eid;
      inst.int_value = static_cast<int64_t>(*val);
      inst.uint_value = static_cast<uint64_t>(*val);
      inst.width = 64;
      return emit_typed(std::move(inst));
    }
  }

  // InitListExpr -- allocate a COMPOUND_LITERAL temp, fill via EmitInitializer,
  // return ALLOCA. This makes aggregate init consistent with compound literals.
  if (auto ile = pasta::InitListExpr::From(e)) {
    ObjectIR obj;
    obj.kind = mx::ir::ObjectKind::COMPOUND_LITERAL;
    obj.source_decl_id = eid;
    if (auto t = e.Type()) {
      obj.type_entity_id = TypeEntityIdOf(*t);
      if (auto sz = TypeSizeBytes(*t)) obj.size_bytes = *sz;
      if (auto al = TypeAlignBytes(*t)) obj.align_bytes = *al;
    }
    uint32_t obj_idx = next_obj_index_++;
    func_.objects.push_back(std::move(obj));
    AssociateObjectWithScope(obj_idx);

    // ALLOCA for the temp object.
    InstructionIR alloca_inst;
    alloca_inst.opcode = mx::ir::OpCode::ALLOCA;
    alloca_inst.source_entity_id = eid;
    alloca_inst.object_index = obj_idx;
    if (auto t = e.Type()) alloca_inst.type_entity_id = TypeEntityIdOf(*t);
    uint32_t alloca_idx = EmitInstruction(std::move(alloca_inst));
    object_to_alloca_[obj_idx] = alloca_idx;

    // Fill the temp via EmitInitializer.
    EmitInitializer(alloca_idx, *ile, eid);

    return alloca_idx;
  }

  // CompoundLiteralExpr -- allocate temp, fill via EmitInitializer.
  if (auto cle = pasta::CompoundLiteralExpr::From(e)) {
    ObjectIR obj;
    obj.kind = mx::ir::ObjectKind::COMPOUND_LITERAL;
    obj.source_decl_id = eid;
    if (auto t = e.Type()) {
      obj.type_entity_id = TypeEntityIdOf(*t);
      if (auto sz = TypeSizeBytes(*t)) obj.size_bytes = *sz;
      if (auto al = TypeAlignBytes(*t)) obj.align_bytes = *al;
    }
    uint32_t obj_idx = next_obj_index_++;
    func_.objects.push_back(std::move(obj));
    AssociateObjectWithScope(obj_idx);

    InstructionIR alloca_inst;
    alloca_inst.opcode = mx::ir::OpCode::ALLOCA;
    alloca_inst.source_entity_id = eid;
    alloca_inst.object_index = obj_idx;
    if (auto t = e.Type()) alloca_inst.type_entity_id = TypeEntityIdOf(*t);
    uint32_t alloca_idx = EmitInstruction(std::move(alloca_inst));
    object_to_alloca_[obj_idx] = alloca_idx;

    EmitInitializer(alloca_idx, cle->Initializer(), eid);

    return alloca_idx;
  }

  // StmtExpr -- GNU ({ ... }) expression. Emit all statements in a scope,
  // return the value of the last expression.
  if (auto se = pasta::StmtExpr::From(e)) {
    auto sub = se->SubStatement();
    if (auto cs = pasta::CompoundStmt::From(sub)) {
      // Push a scope for the block expression's locals.
      PushStructure(mx::ir::StructureKind::SCOPE, EntityIdOf(sub));
      {
        InstructionIR enter;
        enter.opcode = mx::ir::OpCode::ENTER_SCOPE;
        enter.source_entity_id = EntityIdOf(sub);
        enter.structure_index = current_structure_index_;
        EmitTopLevel(std::move(enter));
      }

      // Emit all children. The last expression child is the value.
      auto children = cs->Children();
      std::vector<pasta::Stmt> child_vec(children.begin(), children.end());
      uint32_t last_idx = UINT32_MAX;

      for (size_t i = 0; i < child_vec.size(); ++i) {
        bool is_last = (i == child_vec.size() - 1);
        auto child_expr = pasta::Expr::From(child_vec[i]);
        if (is_last && child_expr) {
          // Last child is an expression — its value is the block result.
          last_idx = EmitRValue(*child_expr);
        } else {
          // Non-last children: emit as statements (side effects only).
          EmitStmt(child_vec[i]);
        }
      }

      {
        InstructionIR exit_inst;
        exit_inst.opcode = mx::ir::OpCode::EXIT_SCOPE;
        exit_inst.source_entity_id = EntityIdOf(sub);
        exit_inst.structure_index = current_structure_index_;
        EmitTopLevel(std::move(exit_inst));
      }
      PopStructure();

      if (last_idx != UINT32_MAX) return last_idx;
    }
    // No expression result — return undefined.
    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::UNDEFINED;
    inst.source_entity_id = eid;
    return emit_typed(std::move(inst));
  }

  // VAArgExpr -- va_arg(ap, type).
  if (auto va = pasta::VAArgExpr::From(e)) {
    uint32_t sub_idx = EmitRValue(va->SubExpression());
    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::MEMORY;
    inst.mem_op = static_cast<uint8_t>(mx::ir::MemOp::CONSUME_VA_PARAM);
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
    inst.opcode = mx::ir::OpCode::CONST;
    inst.const_op = static_cast<uint8_t>(mx::ir::ConstOp::NULL_PTR);
    inst.source_entity_id = eid;
    return emit_typed(std::move(inst));
  }

  // CXXBoolLiteralExpr -- true/false.
  if (auto bl = pasta::CXXBoolLiteralExpr::From(e)) {
    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::CONST;
    inst.const_op = static_cast<uint8_t>(mx::ir::ConstOp::BOOL);
    inst.source_entity_id = eid;
    inst.int_value = bl->Value() ? 1 : 0;
    inst.uint_value = bl->Value() ? 1 : 0;
    inst.width = 1;
    if (auto t = e.Type()) inst.type_entity_id = TypeEntityIdOf(*t);
    return emit_typed(std::move(inst));
  }

  // DesignatedInitExpr -- unwrap to the actual initializer value.
  if (auto die = pasta::DesignatedInitExpr::From(e)) {
    return EmitRValue(die->Initializer());
  }

  // ImplicitValueInitExpr -- zero-initialization of a value.
  if (pasta::ImplicitValueInitExpr::From(e)) {
    InstructionIR inst;
    inst.opcode = mx::ir::OpCode::CONST;
    inst.const_op = static_cast<uint8_t>(mx::ir::ConstOp::INT64);
    inst.source_entity_id = eid;
    inst.int_value = 0;
    inst.uint_value = 0;
    inst.width = 64;
    return emit_typed(std::move(inst));
  }

  // ChooseExpr (__builtin_choose_expr) -- emit the chosen sub-expression.
  if (auto ce = pasta::ChooseExpr::From(e)) {
    return EmitRValue(ce->ChosenSubExpression());
  }

  // GenericSelectionExpr (_Generic) -- emit the result expression.
  if (auto gse = pasta::GenericSelectionExpr::From(e)) {
    if (auto re = gse->ResultExpression()) {
      return EmitRValue(*re);
    }
  }

  // OffsetOfExpr (__builtin_offsetof) -- try to evaluate as constant.
  if (auto ofe = pasta::OffsetOfExpr::From(e)) {
    auto *raw = reinterpret_cast<const clang::OffsetOfExpr *>(ofe->RawStmt());
    if (raw) {
      clang::Expr::EvalResult eval_result;
      if (raw->EvaluateAsInt(eval_result, ctx_)) {
        auto ap_val = eval_result.Val.getInt();
        InstructionIR inst;
        inst.opcode = mx::ir::OpCode::CONST;
        inst.const_op = static_cast<uint8_t>(mx::ir::ConstOp::UINT64);
        inst.source_entity_id = eid;
        inst.int_value = ap_val.getSExtValue();
        inst.uint_value = ap_val.getZExtValue();
        inst.width = 64;
        return emit_typed(std::move(inst));
      }
    }
  }

  // Emit UNKNOWN for anything we haven't explicitly handled.
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

  // DeclRefExpr -> addressOf / globalAddr / funcAddr.
  if (auto dre = pasta::DeclRefExpr::From(e)) {
    auto decl = dre->Declaration();

    // Function reference → FUNC_PTR.
    if (auto fd = pasta::FunctionDecl::From(decl)) {
      InstructionIR inst;
      inst.opcode = mx::ir::OpCode::FUNC_PTR;
      inst.source_entity_id = eid;
      inst.target_entity_id = EntityIdOf(fd->CanonicalDeclaration());
      return EmitInstruction(std::move(inst));
    }

    // Global/static/thread-local variable → GLOBAL_PTR or THREAD_LOCAL_PTR.
    if (auto vd = pasta::VarDecl::From(decl)) {
      if (vd->HasGlobalStorage()) {
        InstructionIR inst;
        inst.source_entity_id = eid;
        inst.target_entity_id = EntityIdOf(decl);
        // Distinguish thread-local from regular global.
        if (vd->TLSKind() != pasta::VarDeclTLSKind::kNone) {
          inst.opcode = mx::ir::OpCode::THREAD_LOCAL_PTR;
        } else {
          inst.opcode = mx::ir::OpCode::GLOBAL_PTR;
        }
        return EmitInstruction(std::move(inst));
      }
    }

    // Local/parameter → reference the ALLOCA directly.
    uint32_t obj_idx = GetOrMakeObject(decl);
    return object_to_alloca_[obj_idx];
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

mx::ir::MemOp IRGenerator::DetermineMemOp(
    bool is_store, bool is_atomic, unsigned size_bytes, bool is_float) {
  // Float load/store: separate sub-opcodes for 32-bit and 64-bit.
  if (is_float && !is_atomic && (size_bytes == 4 || size_bytes == 8)) {
    bool big_endian = ctx_.getTargetInfo().isBigEndian();
    if (!is_store) {
      if (size_bytes == 4) return big_endian ? mx::ir::MemOp::LOAD_F32_BE : mx::ir::MemOp::LOAD_F32_LE;
      return big_endian ? mx::ir::MemOp::LOAD_F64_BE : mx::ir::MemOp::LOAD_F64_LE;
    } else {
      if (size_bytes == 4) return big_endian ? mx::ir::MemOp::STORE_F32_BE : mx::ir::MemOp::STORE_F32_LE;
      return big_endian ? mx::ir::MemOp::STORE_F64_BE : mx::ir::MemOp::STORE_F64_LE;
    }
  }
  assert(IsScalarSize(size_bytes) &&
         "DetermineMemOp called with non-scalar size; use MEMCPY instead");
  unsigned size_idx;
  switch (size_bytes) {
    case 1: size_idx = 0; break;
    case 2: size_idx = 1; break;
    case 4: size_idx = 2; break;
    case 8: size_idx = 3; break;
    default: __builtin_unreachable();
  }
  bool big_endian = ctx_.getTargetInfo().isBigEndian();
  unsigned base = 0;
  if (is_store && !is_atomic) base = 8;
  else if (!is_store && is_atomic) base = 16;
  else if (is_store && is_atomic) base = 24;
  if (big_endian) base += 4;
  return static_cast<mx::ir::MemOp>(base + size_idx);
}

// ---------------------------------------------------------------------------
// Goto compensation blocks
// ---------------------------------------------------------------------------

void IRGenerator::InsertGotoCompensationBlocks() {
  if (pending_gotos_.empty()) return;

  // Helper: get the scope chain from a structure index up to (and including)
  // FUNCTION_SCOPE. Returns scopes in order from innermost to outermost.
  auto get_scope_chain = [&](uint32_t si) -> std::vector<uint32_t> {
    std::vector<uint32_t> chain;
    while (si != UINT32_MAX) {
      if (mx::ir::IsScope(func_.structures[si].kind)) {
        chain.push_back(si);
      }
      si = func_.structures[si].parent_structure_index;
    }
    return chain;  // innermost first
  };

  for (auto &pg : pending_gotos_) {
    // Find the target label's structure.
    auto label_it = label_structure_.find(pg.target_block_idx);
    if (label_it == label_structure_.end()) {
      // Forward reference to label we never saw — leave as-is.
      continue;
    }
    uint32_t target_struct = label_it->second;
    uint32_t source_struct = pg.source_structure_idx;

    // Get scope chains for source and target.
    auto source_chain = get_scope_chain(source_struct);
    auto target_chain = get_scope_chain(target_struct);

    // Find common ancestor scope by converting one chain to a set.
    std::unordered_set<uint32_t> source_set(source_chain.begin(),
                                             source_chain.end());
    uint32_t common_ancestor = UINT32_MAX;
    // Walk target chain (innermost→outermost) to find first match.
    for (auto ts : target_chain) {
      if (source_set.count(ts)) {
        common_ancestor = ts;
        break;
      }
    }

    // Scopes to exit: source scopes above common ancestor.
    std::vector<uint32_t> scopes_to_exit;
    for (auto ss : source_chain) {
      if (ss == common_ancestor) break;
      scopes_to_exit.push_back(ss);
    }

    // Scopes to enter: target scopes below common ancestor (reversed:
    // we need outermost→innermost order for ENTER_SCOPE).
    std::vector<uint32_t> scopes_to_enter;
    for (auto ts : target_chain) {
      if (ts == common_ancestor) break;
      scopes_to_enter.push_back(ts);
    }
    std::reverse(scopes_to_enter.begin(), scopes_to_enter.end());

    // If no transitions needed, skip.
    if (scopes_to_exit.empty() && scopes_to_enter.empty()) continue;

    // Compensation block needed.

    // Create a compensation block.
    uint32_t comp_block = NewBlock(mx::ir::BlockKind::COMPENSATION);

    // Redirect the source instruction → comp_block instead of → target.
    auto &goto_inst = func_.instructions[pg.goto_inst_idx];

    // Update successor: source_block → comp_block (was → target).
    auto &src_block = func_.blocks[pg.source_block_idx];
    for (auto &succ : src_block.successor_indices) {
      if (succ == pg.target_block_idx) {
        succ = comp_block;
        break;
      }
    }

    // Redirect the branch target in the instruction itself.
    // For SWITCH instructions, update the matching switch_cases entry.
    // For gotos/branches, update branch_targets[0].
    if (goto_inst.opcode == mx::ir::OpCode::SWITCH) {
      for (auto &sc : goto_inst.switch_cases) {
        if (sc.block_index == pg.target_block_idx) {
          sc.block_index = comp_block;
          break;
        }
      }
    } else if (!goto_inst.branch_targets.empty()) {
      for (auto &bt : goto_inst.branch_targets) {
        if (bt.block_index == pg.target_block_idx) {
          bt.block_index = comp_block;
          break;
        }
      }
    }

    // Remove old predecessor: target no longer has source as predecessor.
    auto &target_preds = func_.blocks[pg.target_block_idx].predecessor_indices;
    for (auto it = target_preds.begin(); it != target_preds.end(); ++it) {
      if (*it == pg.source_block_idx) {
        target_preds.erase(it);
        break;
      }
    }

    // Add new predecessor: comp_block has source as predecessor.
    func_.blocks[comp_block].predecessor_indices.push_back(pg.source_block_idx);

    // Emit scope transitions in the compensation block.
    uint32_t saved_block = current_block_index_;
    SwitchToBlock(comp_block);

    // EXIT_SCOPE for each source scope above common ancestor.
    for (auto si : scopes_to_exit) {
      InstructionIR exit_inst;
      exit_inst.opcode = mx::ir::OpCode::EXIT_SCOPE;
      exit_inst.source_entity_id = func_.structures[si].source_entity_id;
      exit_inst.structure_index = si;
      EmitTopLevel(std::move(exit_inst));
    }

    // ENTER_SCOPE for each target scope below common ancestor.
    for (auto si : scopes_to_enter) {
      InstructionIR enter_inst;
      enter_inst.opcode = mx::ir::OpCode::ENTER_SCOPE;
      enter_inst.source_entity_id = func_.structures[si].source_entity_id;
      enter_inst.structure_index = si;
      EmitTopLevel(std::move(enter_inst));
    }

    // Branch from compensation block to the original target.
    EmitBranch(pg.target_block_idx);

    SwitchToBlock(saved_block);
  }

  pending_gotos_.clear();
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
