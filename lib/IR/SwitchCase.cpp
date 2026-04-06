// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/SwitchCase.h>
#include <multiplier/IR/Block.h>

#include "Impl.h"
#include "../Fragment.h"
#include "../EntityProvider.h"

namespace mx {

EntityId IRSwitchCase::id(void) const {
  if (!impl) return {};
  IRSwitchCaseId scid;
  scid.fragment_id = impl->fragment_id;
  scid.offset = impl->offset;
  return EntityId(scid);
}

int64_t IRSwitchCase::low(void) const {
  if (!impl) return 0;
  return impl->reader().getLow();
}

int64_t IRSwitchCase::high(void) const {
  if (!impl) return 0;
  return impl->reader().getHigh();
}

bool IRSwitchCase::is_range(void) const {
  return low() != high();
}

bool IRSwitchCase::is_default(void) const {
  if (!impl) return false;
  return impl->reader().getIsDefault();
}

IRBlock IRSwitchCase::target_block(void) const {
  if (!impl) return {};
  auto eid = impl->reader().getTargetBlockId();
  auto vid = EntityId(eid).Unpack();
  if (auto *bid = std::get_if<IRBlockId>(&vid)) {
    return IRBlock(std::make_shared<IRBlockImpl>(
        impl->frag, bid->offset, impl->fragment_id));
  }
  return {};
}

std::optional<Type> IRSwitchCase::value_type(void) const {
  if (!impl) return std::nullopt;
  auto eid = impl->reader().getValueTypeId();
  if (eid == kInvalidEntityId) return std::nullopt;
  if (auto ptr = impl->frag->ep->TypeFor(impl->frag->ep, eid)) {
    return Type(std::move(ptr));
  }
  return std::nullopt;
}

std::optional<Stmt> IRSwitchCase::source_statement(void) const {
  if (!impl) return std::nullopt;
  auto eid = impl->reader().getSourceEntityId();
  if (eid == kInvalidEntityId) return std::nullopt;
  if (auto ptr = impl->frag->ep->StmtFor(impl->frag->ep, eid)) {
    return Stmt(std::move(ptr));
  }
  return std::nullopt;
}

}  // namespace mx
