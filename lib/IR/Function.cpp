// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/Function.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Object.h>

#include "Impl.h"
#include "../Fragment.h"

namespace mx {

EntityId IRFunction::id(void) const {
  if (!impl) return {};
  IRFunctionId fid;
  fid.fragment_id = impl->fragment_id;
  fid.offset = impl->offset;
  return EntityId(fid);
}

IRBlock IRFunction::entry_block(void) const {
  if (!impl) return {};
  auto eid = impl->reader().getEntryBlockId();
  auto vid = EntityId(eid).Unpack();
  if (auto *bid = std::get_if<IRBlockId>(&vid)) {
    return IRBlock(std::make_shared<IRBlockImpl>(
        impl->frag, bid->offset, impl->fragment_id));
  }
  return {};
}

gap::generator<IRBlock> IRFunction::blocks(void) const & {
  if (!impl) co_return;
  for (auto eid : impl->reader().getBlocks()) {
    auto vid = EntityId(eid).Unpack();
    if (auto *bid = std::get_if<IRBlockId>(&vid)) {
      co_yield IRBlock(std::make_shared<IRBlockImpl>(
          impl->frag, bid->offset, impl->fragment_id));
    }
  }
}

gap::generator<IRObject> IRFunction::objects(void) const & {
  if (!impl) co_return;
  for (auto eid : impl->reader().getObjects()) {
    auto vid = EntityId(eid).Unpack();
    if (auto *oid = std::get_if<IRObjectId>(&vid)) {
      co_yield IRObject(std::make_shared<IRObjectImpl>(
          impl->frag, oid->offset, impl->fragment_id));
    }
  }
}

}  // namespace mx
