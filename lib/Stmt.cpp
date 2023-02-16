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

StmtImpl::StmtImpl(std::shared_ptr<EntityProvider> ep_,
                   kj::Array<capnp::word> data_,
                   RawEntityId id_)
    : EntityImpl<ast::Stmt>(std::move(ep_), kj::mv(data_)),
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
  const EntityProvider::Ptr &ep = impl->ep;
  for (auto [ref_id, ref_kind] : ep->References(ep, id().Pack())) {
    if (auto [eptr, category] = ReferencedEntity(ep, ref_id); eptr) {
      co_yield Reference(std::move(eptr), ref_id, category, ref_kind);
    }
  }
}

// Public methods for derived classes

// Included to make sure to distinguish from `call_return_type`
std::optional<Type> CallExpr::casted_return_type(void) const {
  for (CastExpr cast_expr : CastExpr::containing(*this)) {
    if (cast_expr.sub_expression().id() == id())
      return cast_expr.type();
  }
  return std::nullopt;
}

// Grabs the actual parent CastExpr if needed for further inspection
std::optional<CastExpr> CallExpr::casted_return_value(void) const {
  for (CastExpr cast_expr : CastExpr::containing(*this)) {
    if (cast_expr.sub_expression().id() == id())
      return cast_expr;
  }
  return std::nullopt;
}

}  // namespace mx
