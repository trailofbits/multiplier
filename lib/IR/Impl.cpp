// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Impl.h"
#include "../Fragment.h"

namespace mx {

rpc::ir::Function::Reader IRFunctionImpl::reader() const {
  return frag->reader.getIrFunctions()[offset];
}

rpc::ir::Block::Reader IRBlockImpl::reader() const {
  return frag->reader.getIrBlocks()[offset];
}

rpc::ir::Instruction::Reader IRInstructionImpl::reader() const {
  return frag->reader.getIrInstructions()[offset];
}

rpc::ir::SwitchCase::Reader IRSwitchCaseImpl::reader() const {
  return frag->reader.getIrSwitchCases()[offset];
}

rpc::ir::Object::Reader IRObjectImpl::reader() const {
  return frag->reader.getIrObjects()[offset];
}

rpc::ir::Structure::Reader IRStructureImpl::reader() const {
  return frag->reader.getIrStructures()[offset];
}

}  // namespace mx
