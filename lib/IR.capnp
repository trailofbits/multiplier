@0xa5321e2fb1267b91;

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("mx::rpc::ir");

struct Object @0xa7625c6bfddc036b {
  sourceDeclId @0 :UInt64;
  typeEntityId @1 :UInt64;
  sizeBytes @2 :UInt32;
  alignBytes @3 :UInt32;
  kind @4 :UInt8;
}

struct Instruction @0xc6bb311936d9962b {
  entityOffset @0 :UInt32;   # Start index into fragment's irEntityPool
  constOffset @1 :UInt32;    # Start index into fragment's irIntPool
  parentOffset @2 :UInt16;   # Distance to parent instruction (0 = root)
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
}

struct Function @0xe6be31a259218610 {
  funcDeclEntityId @0 :UInt64;
  entryBlockId @1 :UInt64;
  numBlocks @2 :UInt16;      # Number of block IDs in this function's entityPool run
  numObjects @3 :UInt16;     # Number of object IDs in this function's entityPool run
  entityOffset @4 :UInt32;   # Start index into fragment's irEntityPool for block/object lists
}
