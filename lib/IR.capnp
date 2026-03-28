@0xa5321e2fb1267b91;

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("mx::rpc::ir");

# Intermediate Representation for per-function analysis.
#
# All IR entities (functions, blocks, instructions, objects) live as flat lists
# in the containing Fragment, mirroring how decls/stmts work. Each entity
# references others by Multiplier entity ID (RawEntityId / UInt64).

# ---------------------------------------------------------------------------
# Enumerations
# ---------------------------------------------------------------------------

# ObjectKind, OpCode, and BlockKind are stored as plain integers.
# See include/multiplier/IR/ for the C++ enum definitions.

# ---------------------------------------------------------------------------
# Objects (memory regions)
# ---------------------------------------------------------------------------

struct Object @0xa7625c6bfddc036b {
  # RawEntityId of the originating VarDecl/ParmVarDecl. 0 = synthetic object.
  # Name accessible via sourceDeclId -> NamedDecl::Name().
  sourceDeclId @0 :UInt64;

  # RawEntityId of the Multiplier Type entity. Use Multiplier APIs to render.
  typeEntityId @1 :UInt64;

  sizeBytes @2 :UInt32;
  alignBytes @3 :UInt32;
  kind @4 :UInt8;  # ObjectKind
}

# ---------------------------------------------------------------------------
# Instructions (flat in fragment, reference operands by entity ID)
# ---------------------------------------------------------------------------

struct Instruction @0xc6bb311936d9962b {
  # Determines the instruction class and C++ subclass.
  opcode @0 :UInt8;  # OpCode

  # RawEntityId of the originating AST Stmt/Expr. 0 = no source mapping.
  sourceEntityId @1 :UInt64;

  # IRInstructionId entity IDs of operand values.
  operands @2 :List(UInt64);

  # ---------- OpCode-specific fields ----------
  # Which fields are meaningful depends on the opcode:
  #
  #   constInt:       intValue, uintValue, width
  #   constFloat:     floatValue, width
  #   alloca:         objectId
  #   load:           typeEntityId (loaded type); op[0]=address
  #   store:          op[0]=address, op[1]=value
  #   addressOf:      objectId
  #   gepField:       targetEntityId (FieldDecl), sizeBytes (byte offset)
  #   gepIndex:       sizeBytes (element size); op[0]=base, op[1]=index
  #   ptrAdd:         op[0]=base, op[1]=offset
  #   add..ptrDiff:   op[0]=lhs, op[1]=rhs
  #   cmpEq..cmpGe:   op[0]=lhs, op[1]=rhs
  #   neg..logicalNot: op[0]=operand
  #   castSext..castFpCast: op[0]=operand; typeEntityId (result type)
  #   sizeOf:         typeEntityId, sizeBytes (static size, 0 = dynamic)
  #   call:           targetEntityId (callee FunctionDecl, 0=indirect)
  #                   op[0]=callee_ptr (if indirect), op[1..]=args
  #   incDec:         flags (bit 0=isIncrement, bit 1=isPrefix),
  #                   sizeBytes (ptr element size); op[0]=address
  #   compoundAssign: compoundOp (underlying arithmetic opcode),
  #                   sizeBytes (ptr element size); op[0]=address, op[1]=value
  #   select:         op[0]=cond, op[1]=true_val, op[2]=false_val
  #   copy:           op[0]=source
  #   branch:         branchTargets[0]
  #   condBranch:     branchTargets[0]=true, branchTargets[1]=false; op[0]=condition
  #   switch:         branchTargets[0..N-1]=cases, branchTargets[N]=default;
  #                   switchValues parallel to case targets; op[0]=selector
  #   ret:            op[0]=return value (absent for void return)
  #   unreachable:    (no fields)

  # IRObjectId entity ID (alloca, addressOf).
  objectId @3 :UInt64;

  # Type entity ID (load result type, sizeOf target, blockArgDef type, cast result).
  typeEntityId @4 :UInt64;

  # Target entity ID: callee DeclId (call), field DeclId (gepField).
  # Names accessible via targetEntityId -> NamedDecl::Name().
  targetEntityId @5 :UInt64;

  # Integer constant (constInt). Both representations stored.
  intValue @6 :Int64;            # sign-extended value (signed_value() in API)
  uintValue @7 :UInt64;          # zero-extended value (value() in API)

  # Float constant value (constFloat).
  floatValue @8 :Float64;

  # Bit width (constInt, constFloat).
  width @9 :UInt8;

  # Multi-purpose size field: element size (gepIndex), byte offset (gepField),
  # static size (sizeOf), pointer element size (incDec, compoundAssign).
  sizeBytes @10 :UInt32;

  # Flags:
  #   bit 0 = isIncrement (incDec)
  #   bit 1 = isPrefix (incDec)
  #   bit 2 = isConditionallyExecuted (true if this instruction may not
  #           execute depending on a parent short-circuit or ternary, e.g.
  #           B in `A || B`, or b/c in `a ? b : c`)
  flags @11 :UInt8;

  # Underlying arithmetic opcode for compoundAssign.
  compoundOp @12 :UInt8;  # OpCode

  # IRBlockId of the containing block (for parent_block() navigation).
  parentBlockId @13 :UInt64;

  # Branch targets for terminator instructions.
  # branch: [target], condBranch: [true, false],
  # switch: [case0, case1, ..., default].
  branchTargets @14 :List(BranchTarget);

  # Switch case values, parallel to branchTargets (last entry is the default
  # and has no corresponding value here).
  switchValues @15 :List(Int64);

  # Non-negative offset to the parent instruction in the fragment's flat
  # instruction list. Instructions are laid out children-before-parents
  # (post-order), so the parent is always at a higher index.
  #
  #   0 = this is a top-level (statement-level root) instruction
  #   N = parent is at (this_instruction's_index + N) in the flat list
  #
  # This encoding enables efficient bottom-up iteration (just scan forward)
  # and top-down reconstruction (follow operand indices). To iterate
  # top-level instructions in a block: read each instruction's parentOffset;
  # if 0, it's a root.
  parentOffset @16 :UInt32;
}

# A branch target: block entity ID + values passed to block arguments.
struct BranchTarget @0x8fcdc16a959ce793 {
  # IRBlockId entity ID of the target block.
  blockId @0 :UInt64;
}

# ---------------------------------------------------------------------------
# Blocks (flat in fragment)
# ---------------------------------------------------------------------------

struct Block @0xb1141386bcc94b26 {
  # BlockKind enum value (see include/multiplier/IR/BlockKind.h).
  kind @0 :UInt8;

  # IRInstructionId entity IDs. These are ALL instructions belonging to this
  # block (including sub-expressions), laid out children-before-parents.
  # Top-level (statement-root) instructions have parentOffset == 0.
  instructions @1 :List(UInt64);

  # IRBlockId entity IDs.
  successors @2 :List(UInt64);
  predecessors @3 :List(UInt64);

  # Dominator tree information (IRBlockId entity IDs).
  dominators @4 :List(UInt64);
  postDominators @5 :List(UInt64);
  immediateDominator @6 :UInt64;      # 0 = none (entry block)
  immediatePostDominator @7 :UInt64;  # 0 = none (exit blocks)
}

# ---------------------------------------------------------------------------
# Functions (flat in fragment)
# ---------------------------------------------------------------------------

struct Function @0xe6be31a259218610 {
  # RawEntityId of the source FunctionDecl.
  # Name accessible via funcDeclEntityId -> FunctionDecl::Name().
  funcDeclEntityId @0 :UInt64;

  # IRBlockId entity IDs, in reverse post-order.
  blocks @1 :List(UInt64);

  # IRObjectId entity IDs.
  objects @2 :List(UInt64);

  # IRBlockId entity ID of the entry block.
  entryBlockId @3 :UInt64;
}
