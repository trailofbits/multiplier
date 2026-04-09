// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/Object.h>
#include <multiplier/IR/ObjectKind.h>
#include <multiplier/AST/VarDecl.h>
#include <multiplier/AST/Type.h>

#include "Impl.h"
#include "../Fragment.h"
#include "../EntityProvider.h"

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

std::optional<VarDecl> IRObject::source_declaration(void) const {
  if (!impl) return std::nullopt;
  auto eid = impl->reader().getSourceDeclId();
  if (eid == kInvalidEntityId) return std::nullopt;
  auto vid = EntityId(eid).Unpack();
  if (!std::holds_alternative<DeclId>(vid)) return std::nullopt;
  if (auto ptr = impl->frag->ep->DeclFor(impl->frag->ep, eid)) {
    return VarDecl::from(Decl(std::move(ptr)));
  }
  return std::nullopt;
}

std::optional<Type> IRObject::type(void) const {
  if (!impl) return std::nullopt;
  auto eid = impl->reader().getTypeEntityId();
  if (eid == kInvalidEntityId) return std::nullopt;
  if (auto ptr = impl->frag->ep->TypeFor(impl->frag->ep, eid)) {
    return Type(std::move(ptr));
  }
  return std::nullopt;
}

bool IRObject::needs_memory(void) const {
  return ir::NeedsMemory(kind());
}

}  // namespace mx
