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
  opcode @0 :UInt8;
  sourceEntityId @1 :UInt64;
  operands @2 :List(UInt64);
  objectId @3 :UInt64;
  typeEntityId @4 :UInt64;
  targetEntityId @5 :UInt64;
  intValue @6 :Int64;
  uintValue @7 :UInt64;
  floatValue @8 :Float64;
  width @9 :UInt8;
  sizeBytes @10 :UInt32;
  flags @11 :UInt8;
  compoundOp @12 :UInt8;
  parentBlockId @13 :UInt64;
  branchTargets @14 :List(BranchTarget);
  switchValues @15 :List(Int64);
  parentOffset @16 :UInt32;
}

struct BranchTarget @0x8fcdc16a959ce793 {
  blockId @0 :UInt64;
}

struct Block @0xb1141386bcc94b26 {
  kind @0 :UInt8;
  instructions @1 :List(UInt64);
  successors @2 :List(UInt64);
  predecessors @3 :List(UInt64);
  dominators @4 :List(UInt64);
  postDominators @5 :List(UInt64);
  immediateDominator @6 :UInt64;
  immediatePostDominator @7 :UInt64;
}

struct Function @0xe6be31a259218610 {
  funcDeclEntityId @0 :UInt64;
  blocks @1 :List(UInt64);
  objects @2 :List(UInt64);
  entryBlockId @3 :UInt64;
}
