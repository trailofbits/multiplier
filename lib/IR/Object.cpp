// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/Object.h>
#include <multiplier/IR/ObjectKind.h>

#include "Impl.h"
#include "../Fragment.h"

namespace mx {

EntityId IRObject::id(void) const {
  if (!impl) return {};
  IRObjectId oid;
  oid.fragment_id = impl->fragment_id;
  oid.offset = impl->offset;
  return EntityId(oid);
}

ir::ObjectKind IRObject::kind(void) const {
  if (!impl) return ir::ObjectKind::LOCAL;
  return static_cast<ir::ObjectKind>(impl->reader().getKind());
}

uint32_t IRObject::size_bytes(void) const {
  if (!impl) return 0;
  return impl->reader().getSizeBytes();
}

uint32_t IRObject::align_bytes(void) const {
  if (!impl) return 0;
  return impl->reader().getAlignBytes();
}

bool IRObject::needs_memory(void) const {
  return ir::NeedsMemory(kind());
}

}  // namespace mx
