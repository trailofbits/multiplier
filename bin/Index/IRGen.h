// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <multiplier/Types.h>
#include <multiplier/IR/OpCode.h>
#include <multiplier/IR/BlockKind.h>
#include <multiplier/IR/ObjectKind.h>

namespace clang {
class ASTContext;
}  // namespace clang

namespace pasta {
class AST;
class Decl;
class Expr;
class FunctionDecl;
class Stmt;
class Type;
class VarDecl;
}  // namespace pasta

namespace indexer {

class EntityMapper;

namespace ir {

// ---------------------------------------------------------------------------
// In-memory IR data structures (populated during generation, then serialized)
// ---------------------------------------------------------------------------

struct BranchTargetIR {
  uint32_t block_index{0};
};

struct InstructionIR {
  mx::ir::OpCode opcode{mx::ir::OpCode::UNREACHABLE};
  mx::RawEntityId source_entity_id{mx::kInvalidEntityId};

  // Operand instruction indices (into FunctionIR::instructions).
  // These are the children in the expression tree.
  std::vector<uint32_t> operand_indices;

  // Offset to parent instruction in the flat list. 0 = top-level root.
  // parent is at (my_index + parent_offset) in the flat instruction list.
  uint32_t parent_offset{0};

  // Parent block index.
  uint32_t parent_block_index{0};

  // OpCode-specific fields.
  uint32_t object_index{0};
  mx::RawEntityId type_entity_id{mx::kInvalidEntityId};
  mx::RawEntityId target_entity_id{mx::kInvalidEntityId};
  int64_t int_value{0};      // sign-extended
  uint64_t uint_value{0};    // zero-extended
  double float_value{0.0};
  uint8_t width{0};
  uint32_t size_bytes{0};
  uint8_t flags{0};
  mx::ir::OpCode compound_op{mx::ir::OpCode::ADD};

  // Terminator data.
  std::vector<BranchTargetIR> branch_targets;
  std::vector<int64_t> switch_values;
};

struct BlockIR {
  mx::ir::BlockKind kind{mx::ir::BlockKind::GENERIC};

  // Top-level instruction indices (roots of expression trees).
  std::vector<uint32_t> instruction_indices;

  // Block indices.
  std::vector<uint32_t> successor_indices;
  std::vector<uint32_t> predecessor_indices;

  // Dominator tree.
  std::vector<uint32_t> dominator_indices;
  std::vector<uint32_t> post_dominator_indices;
  uint32_t immediate_dominator{UINT32_MAX};
  uint32_t immediate_post_dominator{UINT32_MAX};
};

struct ObjectIR {
  mx::RawEntityId source_decl_id{mx::kInvalidEntityId};
  mx::RawEntityId type_entity_id{mx::kInvalidEntityId};
  uint32_t size_bytes{0};
  uint32_t align_bytes{1};
  mx::ir::ObjectKind kind{mx::ir::ObjectKind::LOCAL};
};

struct FunctionIR {
  mx::RawEntityId func_decl_entity_id{mx::kInvalidEntityId};

  std::vector<InstructionIR> instructions;
  std::vector<BlockIR> blocks;
  std::vector<ObjectIR> objects;

  uint32_t entry_block_index{0};
  std::vector<uint32_t> rpo_block_order;
};

// ---------------------------------------------------------------------------
// IRGenerator: builds IR from a pasta::FunctionDecl by walking the PASTA AST
// directly. Builds a statement-level CFG (no Clang CFG dependency).
// Expressions are kept as nested instruction trees within blocks.
// ---------------------------------------------------------------------------

class IRGenerator {
 public:
  IRGenerator(const pasta::AST &ast, const EntityMapper &em);

  std::optional<FunctionIR> Generate(const pasta::FunctionDecl &func);

 private:
  const pasta::AST &ast_;
  const EntityMapper &em_;
  clang::ASTContext &ctx_;  // from ast_.UnderlyingAST(), for type sizes etc.

  FunctionIR func_;
  uint32_t current_block_index_{0};
  uint32_t next_obj_index_{0};
  std::unordered_map<mx::RawEntityId, uint32_t> entity_to_object_;
  std::unordered_set<mx::RawEntityId> address_taken_;

  // Index of the 'this' parameter object for C++ methods, or UINT32_MAX.
  uint32_t this_object_index_{UINT32_MAX};

  // Break/continue targets: maps source entity ID of the enclosing
  // loop/switch to its exit (break) and continue-target blocks.
  struct LoopContext {
    uint32_t break_block;     // where break goes
    uint32_t continue_block;  // where continue goes (loops only)
    bool is_switch;           // true = switch (break goes here, continue goes to enclosing loop)
  };
  std::vector<LoopContext> loop_stack_;

  // Goto label targets: maps label name to block index.
  // Forward gotos create the block on first reference.
  std::unordered_map<std::string, uint32_t> label_blocks_;

  // Maps case/default statement entity IDs to their block indices,
  // so fallthrough can branch to the right block.
  std::unordered_map<mx::RawEntityId, uint32_t> case_blocks_;

  // --- Block management ---
  uint32_t NewBlock(mx::ir::BlockKind kind = mx::ir::BlockKind::GENERIC);
  void SwitchToBlock(uint32_t block_idx);
  void AddEdge(uint32_t from, uint32_t to);

  // --- Branch helpers (reduce boilerplate) ---
  // EmitBranch emits an IMPLICIT_GOTO (structural edge).
  uint32_t EmitBranch(uint32_t target_block,
                      mx::RawEntityId source_eid = mx::kInvalidEntityId);
  uint32_t EmitBranchWithOpCode(mx::ir::OpCode opcode, uint32_t target_block,
                                mx::RawEntityId source_eid = mx::kInvalidEntityId);
  uint32_t EmitCondBranch(uint32_t cond_idx, uint32_t true_block,
                          uint32_t false_block,
                          mx::RawEntityId source_eid = mx::kInvalidEntityId);

  // --- Load from lvalue helper ---
  uint32_t EmitLoadFromLValue(const pasta::Expr &e);

  // --- Object management ---
  uint32_t MakeObject(mx::ir::ObjectKind kind,
                      const pasta::Decl *decl = nullptr);
  uint32_t GetOrMakeObject(const pasta::Decl &decl);

  // --- Instruction emission ---
  // Emits an instruction into the flat list. Does NOT add it as a top-level
  // instruction in the current block -- that happens only for statement-level
  // roots. Sub-expressions are linked via operand_indices and
  // parent_instruction_index.
  uint32_t EmitInstruction(InstructionIR inst);

  // Emit a top-level instruction (added to the current block's root list).
  uint32_t EmitTopLevel(InstructionIR inst);

  // Set parent_instruction_index on all operands of inst at `inst_idx`.
  void SetOperandParents(uint32_t inst_idx);

  // --- Statement emission (builds the CFG) ---
  void EmitBody(const pasta::Stmt &body);
  void EmitStmt(const pasta::Stmt &s);
  void EmitIfStmt(const pasta::Stmt &s);
  void EmitWhileStmt(const pasta::Stmt &s);
  void EmitDoStmt(const pasta::Stmt &s);
  void EmitForStmt(const pasta::Stmt &s);
  void EmitSwitchStmt(const pasta::Stmt &s);
  void EmitReturnStmt(const pasta::Stmt &s);
  void EmitDeclStmt(const pasta::Stmt &s);
  void EmitBreakStmt(const pasta::Stmt &s);
  void EmitContinueStmt(const pasta::Stmt &s);
  void EmitGotoStmt(const pasta::Stmt &s);
  void EmitLabelStmt(const pasta::Stmt &s);

  // --- Expression emission (builds nested instruction trees) ---
  uint32_t EmitRValue(const pasta::Expr &e);
  uint32_t EmitLValue(const pasta::Expr &e);

  // --- Conditionally-executed flag propagation ---
  void MarkConditionallyExecuted(uint32_t inst_idx);

  // --- Entity ID helpers ---
  mx::RawEntityId EntityIdOf(const pasta::Stmt &s);
  mx::RawEntityId EntityIdOf(const pasta::Decl &d);
  mx::RawEntityId TypeEntityIdOf(const pasta::Type &t);

  // --- Type helpers ---
  std::optional<uint32_t> TypeSizeBytes(const pasta::Type &t);
  std::optional<uint32_t> TypeAlignBytes(const pasta::Type &t);

  // --- Pre-scan ---
  void ScanAddressTaken(const pasta::Stmt &s);

  // --- Post-processing ---
  void ComputeDominators();
  void ComputeRPO();
};

}  // namespace ir
}  // namespace indexer
