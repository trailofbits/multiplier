// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/AST.capnp.h>
#include <multiplier/AST/CastExpr.h>
#include <multiplier/AST/CallExpr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/Type.h>

#include "FragmentEntity.h"

#pragma GCC visibility push(hidden)
namespace mx {

// Interface for accessing a statement.
class StmtImpl final : public FragmentEntityImpl<ast::Stmt> {
 public:
  const PackedFragmentId fragment_id;
  const EntityOffset offset;

  explicit StmtImpl(FragmentImplPtr frag_,
                    ast::Stmt::Reader reader_,
                    RawEntityId id_);
};

}  // namespace mx
#pragma GCC visibility pop
