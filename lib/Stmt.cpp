// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Stmt.h"

#include <multiplier/Index.h>

#include "Fragment.h"
#include "Types.h"

namespace mx {

StmtImpl::StmtImpl(std::shared_ptr<EntityProvider> ep_, std::string data_,
                   RawEntityId id_)
    : EntityImpl<ast::Stmt>(std::move(ep_), std::move(data_)),
      fragment_id(FragmentIdFromEntityId(id_).value()),
      offset(FragmentOffsetFromEntityId(id_).value()) {}

SpecificEntityId<StmtId> Stmt::id(void) const {
  StmtId eid;
  eid.fragment_id = impl->fragment_id.Unpack().fragment_id;
  eid.kind = kind();
  eid.offset = impl->offset;
  return eid;
}

gap::generator<Stmt> Stmt::in_internal(const Fragment &fragment) {
  FragmentId fid(fragment.impl->fragment_id);
  auto &ep = fragment.impl->ep;
  for (StmtImplPtr reader : ep->StmtsFor(ep, fid)) {
    co_yield Stmt(std::move(reader));
  }
}

}  // namespace mx
