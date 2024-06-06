// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Stmt.h"

#include <multiplier/Index.h>
#include <multiplier/Frontend/MacroSubstitution.h>

#include "Fragment.h"
#include "Reference.h"
#include "Types.h"
#include "DeclStmtUtil.h"

namespace mx {

StmtImpl::StmtImpl(FragmentImplPtr frag_,
                   ast::Stmt::Reader reader_,
                   RawEntityId id_)
    : FragmentEntityImpl<ast::Stmt>(std::move(frag_), kj::mv(reader_)),
      fragment_id(FragmentIdFromEntityId(id_).value()),
      offset(FragmentOffsetFromEntityId(id_).value()) {}

SpecificEntityId<StmtId> Stmt::id(void) const {
  StmtId eid;
  eid.fragment_id = impl->fragment_id.Unpack().fragment_id;
  eid.kind = kind();
  eid.offset = impl->offset;
  return eid;
}

// Public methods for derived classes

// Included to make sure to distinguish from `call_return_type`
std::optional<Type> CallExpr::casted_return_type(void) const {
  for (CastExpr cast_expr : CastExpr::containing(*this)) {
    if (cast_expr.sub_expression().id() == id()) {
      return cast_expr.type();
    }
  }
  return std::nullopt;
}

// Grabs the actual parent CastExpr if needed for further inspection
std::optional<CastExpr> CallExpr::casted_return_value(void) const {
  for (CastExpr cast_expr : CastExpr::containing(*this)) {
    if (cast_expr.sub_expression().id() == id()) {
      return cast_expr;
    }
  }
  return std::nullopt;
}

gap::generator<Stmt> Stmt::overlapping(const MacroSubstitution &sub) {
  return EntityOverlapping<Stmt>(sub);
}

gap::generator<Stmt> Stmt::overlapping(const std::optional<MacroSubstitution> &sub) {
  if (sub.has_value()) {
    auto overlapping_stmts = overlapping(sub.value());
    for (auto stmt : overlapping_stmts) {
      co_yield stmt;
    }
  }
}

std::optional<Stmt> Stmt::covering(const MacroSubstitution &sub) {
  return EntityCovering<Stmt>(sub);
}

std::optional<Stmt> Stmt::covering(const std::optional<MacroSubstitution> &macro) {
  if (macro.has_value()) {
    return covering(macro.value());
  }
  return std::nullopt;
}

}  // namespace mx
