// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <multiplier/IR.capnp.h>
#include <multiplier/RPC.capnp.h>

namespace pasta {
class AST;
}  // namespace pasta

namespace indexer {

class EntityMapper;
class PendingFragment;
class ProgressBar;

void GenerateAndSerializeIR(
    const pasta::AST &ast,
    const PendingFragment &pf,
    const EntityMapper &em,
    mx::rpc::Fragment::Builder &fb,
    const std::unique_ptr<ProgressBar> &progress);

}  // namespace indexer
