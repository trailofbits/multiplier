@0xa5321e2fb1267b91;

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("mx::rpc::ir");

struct Object @0xa7625c6bfddc036b {
  sourceDeclId @0 :UInt64;
  typeEntityId @1 :UInt64;
  sizeBytes @2 :UInt32;
  alignBytes @3 :UInt32;
  kind @4 :UInt8;
  frameOffset @5 :UInt32;     # Offset within the function's stack frame.
                               # Only meaningful for stack-allocated objects.
}

struct Instruction @0xc6bb311936d9962b {
  entityOffset @0 :UInt32;   # Start index into fragment's irEntityPool
  constOffset @1 :UInt32;    # Start index into fragment's irIntPool
  users @2 :List(UInt64);    # IRInstructionId entity IDs of instructions using this value
  numOperands @3 :UInt8;     # Number of data-flow operand entity IDs
  opcode @4 :UInt8;          # OpCode enum
  constWidth @5 :UInt8;      # Bit width for constants
  flags @6 :UInt8;           # Bit flags
}

struct Block @0xb1141386bcc94b26 {
  entityOffset @0 :UInt32;
  numInstructions @1 :UInt16;
  numSuccessors @2 :UInt16;
  numPredecessors @3 :UInt16;
  numDominators @4 :UInt16;
  numPostDominators @5 :UInt16;
  kind @6 :UInt8;
  parentStructureId @7 :UInt64;   # IRStructureId of enclosing structure
}

struct Structure @0xd4a8b7c2e9f31056 {
  sourceEntityId @0 :UInt64;    # AST Stmt/Decl entity ID
  parentId @1 :UInt64;          # IRStructureId of parent (or IRFunctionId)
  kind @2 :UInt8;               # StructureKind
  entityOffset @3 :UInt32;      # into irEntityPool for children
  numChildren @4 :UInt16;       # child structure/block entity IDs
  numObjects @5 :UInt16;        # ALLOCAs declared in this scope (scopes only)
  caseLow @6 :Int64;            # SWITCH_CASE: case value lower bound
  caseHigh @7 :Int64;           # SWITCH_CASE: case value upper bound
  isDefault @8 :Bool;           # SWITCH_CASE: true for default case
}

struct Function @0xe6be31a259218610 {
  sourceDeclEntityId @0 :UInt64;  # FunctionDecl for NORMAL, VarDecl for GLOBAL_INITIALIZER
  entryBlockId @1 :UInt64;
  numBlocks @2 :UInt16;
  numObjects @3 :UInt16;
  entityOffset @4 :UInt32;
  kind @5 :UInt8;             # FunctionKind enum (0 = NORMAL)
  bodyScopeId @6 :UInt64;    # IRStructureId of FUNCTION_SCOPE (root of structure tree)
  frameSizeBytes @7 :UInt32;  # Total size of the fixed stack frame (non-dynamic allocas).
  hasDynamicAllocas @8 :Bool; # True if the function has VLAs or alloca().
}
