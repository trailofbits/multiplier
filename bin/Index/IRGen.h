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
#include <multiplier/IR/FunctionKind.h>
#include <multiplier/IR/StructureKind.h>

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
  std::vector<uint32_t> operand_indices;

  // Parent instruction index (UINT32_MAX for top-level roots).
  // Roots have their parent block determined by which BlockIR contains them.
  uint32_t parent_instruction_index{UINT32_MAX};

  // Block this instruction was emitted into (set by EmitInstruction).
  uint32_t parent_block_index{UINT32_MAX};

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
  uint8_t const_op{0};    // ConstOp sub-opcode for CONST instructions
  uint8_t cast_op{0};     // CastOp sub-opcode for CAST instructions
  uint8_t bitwise_op{0};  // BitwiseOp sub-opcode for BITWISE instructions
  uint8_t mem_op{0};      // MemOp sub-opcode for MEMORY instructions
  uint8_t float_op{0};    // FloatOp sub-opcode for FLOAT instructions
  uint32_t bit_offset{0}; // BIT_READ/BIT_WRITE: bit offset into the object
  uint32_t bit_width{0};  // BIT_READ/BIT_WRITE: number of bits

  // Structure index for ENTER_SCOPE/EXIT_SCOPE (into FunctionIR::structures).
  uint32_t structure_index{UINT32_MAX};

  // Terminator data.
  std::vector<BranchTargetIR> branch_targets;

  // Switch cases: one per case/default in a switch statement.
  // Each maps to an IRSwitchCase entity in the serialized output.
  struct SwitchCaseIR {
    int64_t low{0};
    int64_t high{0};
    uint32_t block_index{0};
    mx::RawEntityId source_entity_id{mx::kInvalidEntityId};  // CaseStmt/DefaultStmt
    bool is_default{false};
  };
  std::vector<SwitchCaseIR> switch_cases;
};

struct BlockIR {
  mx::ir::BlockKind kind{mx::ir::BlockKind::GENERIC};
  uint32_t parent_structure_index{UINT32_MAX};

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

struct StructureIR {
  mx::ir::StructureKind kind{mx::ir::StructureKind::SCOPE};
  mx::RawEntityId source_entity_id{mx::kInvalidEntityId};
  uint32_t parent_structure_index{UINT32_MAX};  // index into FunctionIR::structures

  // Children: interleaved structure and block indices (in source order).
  // Each entry is either a structure index (with is_structure=true) or block index.
  struct ChildRef {
    uint32_t index;
    bool is_structure;
  };
  std::vector<ChildRef> children;

  // Object indices for scope kinds (ALLOCAs declared in this scope).
  std::vector<uint32_t> object_indices;

  // Switch case data (for SWITCH_CASE kind).
  int64_t case_low{0};
  int64_t case_high{0};
  bool is_default{false};
};

struct FunctionIR {
  mx::RawEntityId func_decl_entity_id{mx::kInvalidEntityId};
  mx::ir::FunctionKind kind{mx::ir::FunctionKind::NORMAL};

  std::vector<InstructionIR> instructions;
  std::vector<BlockIR> blocks;
  std::vector<ObjectIR> objects;
  std::vector<StructureIR> structures;

  uint32_t entry_block_index{0};
  uint32_t body_scope_index{UINT32_MAX};  // FUNCTION_SCOPE structure
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
  std::optional<FunctionIR> GenerateGlobalInit(const pasta::VarDecl &var);

 private:
  const pasta::AST &ast_;
  const EntityMapper &em_;
  clang::ASTContext &ctx_;  // from ast_.UnderlyingAST(), for type sizes etc.

  FunctionIR func_;
  uint32_t current_block_index_{0};
  uint32_t next_obj_index_{0};
  std::unordered_map<mx::RawEntityId, uint32_t> entity_to_object_;
  std::unordered_map<uint32_t, uint32_t> object_to_alloca_;  // obj_idx → alloca inst idx
  std::unordered_set<mx::RawEntityId> address_taken_;

  // Break/continue targets: maps source entity ID of the enclosing
  // loop/switch to its exit (break) and continue-target blocks.
  struct LoopContext {
    uint32_t break_block;     // where break goes
    uint32_t continue_block;  // where continue goes (loops only)
    uint32_t structure_index; // structure index of the loop/switch
    bool is_switch;           // true = switch (break goes here, continue goes to enclosing loop)
  };
  std::vector<LoopContext> loop_stack_;

  // Structure stack for nesting.
  uint32_t current_structure_index_{UINT32_MAX};
  std::vector<uint32_t> structure_stack_;

  // Goto label targets: maps label name to block index.
  // Forward gotos create the block on first reference.
  std::unordered_map<std::string, uint32_t> label_blocks_;

  // Maps case/default statement entity IDs to their block indices,
  // so fallthrough can branch to the right block.
  std::unordered_map<mx::RawEntityId, uint32_t> case_blocks_;

  // Goto compensation: records pending gotos that need scope transitions.
  struct PendingGoto {
    uint32_t goto_inst_idx;        // index of the GOTO instruction
    uint32_t source_block_idx;     // block containing the goto
    uint32_t target_block_idx;     // label block
    uint32_t source_structure_idx; // structure at goto site
  };
  std::vector<PendingGoto> pending_gotos_;

  // Maps label block index to the structure index active when label was emitted.
  std::unordered_map<uint32_t, uint32_t> label_structure_;

  // --- Structure management ---
  uint32_t PushStructure(mx::ir::StructureKind kind,
                         mx::RawEntityId source_eid = mx::kInvalidEntityId);
  void PopStructure();
  void AssociateBlockWithStructure(uint32_t block_idx);
  void AssociateObjectWithScope(uint32_t obj_idx);

  // Emit EXIT_SCOPE for all enclosing scopes up to (but not including)
  // the scope at stop_structure_index. Used by break/continue/return/goto.
  void EmitScopeExits(uint32_t stop_structure_index);

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

  // --- Initializer emission (decomposes aggregates into element stores) ---
  void EmitInitializer(uint32_t dest_addr_idx, const pasta::Expr &init,
                       mx::RawEntityId source_eid);

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
  mx::ir::MemOp DetermineMemOp(bool is_store, bool is_atomic,
                                unsigned size_bytes);

  // --- Pre-scan ---
  void ScanAddressTaken(const pasta::Stmt &s);
  void EmitEntryBlockAllocas(const pasta::Stmt &body);

  // --- Post-processing ---
  void InsertGotoCompensationBlocks();
  void ComputeDominators();
  void ComputeRPO();
  void VerifyBlocks();
};

}  // namespace ir
}  // namespace indexer
