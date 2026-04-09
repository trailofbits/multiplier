// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <vector>
#include <multiplier/IR.capnp.h>
#include <multiplier/RPC.capnp.h>

#include "IRGen.h"

namespace pasta {
class AST;
}  // namespace pasta

namespace indexer {

class EntityMapper;
class PendingFragment;
class ProgressBar;

// Step 1: Generate IR for all function bodies in the fragment.
// Returns the generated IR functions. Also populates the reverse map
// on the EntityMapper (AST entity ID → IR instruction entity ID).
std::vector<ir::FunctionIR> GenerateIR(
    const pasta::AST &ast,
    const PendingFragment &pf,
    EntityMapper &em,
    const std::unique_ptr<ProgressBar> &progress);

// Step 2: Serialize previously-generated IR into the fragment proto.
// Also populates remaining reverse mappings (e.g. CaseStmt -> IRStructure).
void SerializeIR(
    const std::vector<ir::FunctionIR> &ir_functions,
    const PendingFragment &pf,
    EntityMapper &em,
    mx::rpc::Fragment::Builder &fb);

}  // namespace indexer
