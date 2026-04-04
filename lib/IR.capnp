@0xa5321e2fb1267b91;

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("mx::rpc::ir");

struct Object @0xa7625c6bfddc036b {
  sourceDeclId @0 :UInt64;   # VarDecl/ParmVarDecl entity ID (0 = synthetic)
  typeEntityId @1 :UInt64;   # Multiplier Type entity ID
  sizeBytes @2 :UInt32;      # Size in bytes
  alignBytes @3 :UInt32;     # Alignment in bytes
  kind @4 :UInt8;            # ObjectKind enum
}

struct Instruction @0xc6bb311936d9962b {
  opcode @0 :UInt8;          # OpCode enum -- determines instruction class
  sourceEntityId @1 :UInt64; # Originating AST Stmt/Expr entity ID
  operands @2 :List(UInt64); # Data-flow children (IRInstructionId entity IDs)
  objectId @3 :UInt64;       # IRObjectId for alloca/addressOf
  typeEntityId @4 :UInt64;   # Result/element type (load, cast, sizeOf, ptrAdd)
  targetEntityId @5 :UInt64; # Call target FunctionDecl / field FieldDecl
  intValue @6 :Int64;        # Signed integer constant (constInt)
  uintValue @7 :UInt64;      # Unsigned integer constant (constInt)
  floatValue @8 :Float64;    # Float constant (constFloat)
  width @9 :UInt8;           # Bit width of constant
  sizeBytes @10 :UInt32;     # Element size (ptrAdd), byte offset (gepField), static size (sizeOf)
  flags @11 :UInt8;          # Bit flags (incDec: 0=isInc, 1=isPrefix; 2=isCondExec)
  compoundOp @12 :UInt8;     # Underlying arithmetic OpCode for compoundAssign
  parentBlockId @13 :UInt64; # Containing IRBlockId
  branchTargets @14 :List(BranchTarget); # Terminator targets
  switchValues @15 :List(Int64);         # Switch case values (parallel to branchTargets)
  parentOffset @16 :UInt32;  # Distance to parent instruction (0 = top-level root)
}

struct BranchTarget @0x8fcdc16a959ce793 {
  blockId @0 :UInt64;        # Target IRBlockId
}

struct Block @0xb1141386bcc94b26 {
  kind @0 :UInt8;            # BlockKind enum
  instructions @1 :List(UInt64); # All instructions (post-order, children before parents)
  successors @2 :List(UInt64);   # CFG successor IRBlockIds
  predecessors @3 :List(UInt64); # CFG predecessor IRBlockIds
  dominators @4 :List(UInt64);          # Dominator IRBlockIds
  postDominators @5 :List(UInt64);      # Post-dominator IRBlockIds
  immediateDominator @6 :UInt64;        # Immediate dominator (0 = none)
  immediatePostDominator @7 :UInt64;    # Immediate post-dominator (0 = none)
}

struct Function @0xe6be31a259218610 {
  funcDeclEntityId @0 :UInt64;    # Source FunctionDecl entity ID
  blocks @1 :List(UInt64);       # IRBlockIds in reverse post-order
  objects @2 :List(UInt64);      # IRObjectIds
  entryBlockId @3 :UInt64;       # Entry block IRBlockId
}
