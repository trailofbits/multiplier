// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Stmt.h"

#include <multiplier/Index.h>

#include "Fragment.h"
#include "Reference.h"
#include "Types.h"

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

// References to this statement.
gap::generator<Reference> Stmt::references(void) const & {
  EntityProviderPtr ep = impl->ep;
  for (auto ref : ep->References(ep, id().Pack())) {
    if (auto [eptr, category] = ReferencedEntity(ep, std::get<0>(ref)); eptr) {
      auto context = std::make_shared<ReferenceContextImpl>(ep, std::get<1>(ref));
      co_yield Reference(std::move(eptr), std::move(context),
                         std::get<0>(ref), category, std::get<2>(ref));
    }
  }
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

}  // namespace mx
