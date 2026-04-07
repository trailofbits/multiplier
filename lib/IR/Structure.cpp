// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/Structure.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Function.h>
#include <multiplier/IR/Object.h>

#include "Impl.h"
#include "../Fragment.h"

namespace mx {

// Entity pool layout per structure (starting at entityOffset):
//   [child0..childN, obj0..objM]
// where children are IRStructureId or IRBlockId,
// and objects are IRObjectId (only for scope kinds).

static capnp::List<uint64_t, capnp::Kind::PRIMITIVE>::Reader
GetEntityPool(const IRStructureImpl &impl) {
  return impl.frag->reader.getIrEntityPool();
}

EntityId IRStructure::id(void) const {
  if (!impl) return {};
  IRStructureId sid;
  sid.fragment_id = impl->fragment_id;
  sid.offset = impl->offset;
  sid.structure_kind = static_cast<uint8_t>(kind());
  return EntityId(sid);
}

ir::StructureKind IRStructure::kind(void) const {
  if (!impl) return ir::StructureKind::SCOPE;
  return static_cast<ir::StructureKind>(impl->reader().getKind());
}

std::optional<Stmt> IRStructure::source_statement(void) const {
  if (!impl) return std::nullopt;
  auto eid = impl->reader().getSourceEntityId();
  if (eid == kInvalidEntityId) return std::nullopt;
  if (auto ptr = impl->frag->ep->StmtFor(impl->frag->ep, eid)) {
    return Stmt(std::move(ptr));
  }
  return std::nullopt;
}

std::optional<IRStructure> IRStructure::parent_structure(void) const {
  if (!impl) return std::nullopt;
  auto eid = impl->reader().getParentId();
  auto vid = EntityId(eid).Unpack();
  if (auto *sid = std::get_if<IRStructureId>(&vid)) {
    return IRStructure(std::make_shared<IRStructureImpl>(
        impl->frag, sid->offset, impl->fragment_id));
  }
  return std::nullopt;
}

std::optional<IRFunction> IRStructure::parent_function(void) const {
  if (!impl) return std::nullopt;
  auto eid = impl->reader().getParentId();
  auto vid = EntityId(eid).Unpack();
  if (auto *fid = std::get_if<IRFunctionId>(&vid)) {
    return IRFunction(std::make_shared<IRFunctionImpl>(
        impl->frag, fid->offset, impl->fragment_id));
  }
  return std::nullopt;
}

gap::generator<IRStructure> IRStructure::child_structures(void) const & {
  if (!impl) co_return;
  auto r = impl->reader();
  auto pool = GetEntityPool(*impl);
  uint32_t base = r.getEntityOffset();
  uint16_t n = r.getNumChildren();
  for (uint16_t i = 0; i < n; ++i) {
    auto eid = pool[base + i];
    auto vid = EntityId(eid).Unpack();
    if (auto *sid = std::get_if<IRStructureId>(&vid)) {
      co_yield IRStructure(std::make_shared<IRStructureImpl>(
          impl->frag, sid->offset, impl->fragment_id));
    }
  }
}

gap::generator<IRBlock> IRStructure::child_blocks(void) const & {
  if (!impl) co_return;
  auto r = impl->reader();
  auto pool = GetEntityPool(*impl);
  uint32_t base = r.getEntityOffset();
  uint16_t n = r.getNumChildren();
  for (uint16_t i = 0; i < n; ++i) {
    auto eid = pool[base + i];
    auto vid = EntityId(eid).Unpack();
    if (auto *bid = std::get_if<IRBlockId>(&vid)) {
      co_yield IRBlock(std::make_shared<IRBlockImpl>(
          impl->frag, bid->offset, impl->fragment_id));
    }
  }
}

gap::generator<IRObject> IRStructure::objects(void) const & {
  if (!impl) co_return;
  auto r = impl->reader();
  auto pool = GetEntityPool(*impl);
  uint32_t base = r.getEntityOffset() + r.getNumChildren();
  uint16_t n = r.getNumObjects();
  for (uint16_t i = 0; i < n; ++i) {
    auto eid = pool[base + i];
    auto vid = EntityId(eid).Unpack();
    if (auto *oid = std::get_if<IRObjectId>(&vid)) {
      co_yield IRObject(std::make_shared<IRObjectImpl>(
          impl->frag, oid->offset, impl->fragment_id));
    }
  }
}

bool IRStructure::is_scope(void) const {
  return ir::IsScope(kind());
}

}  // namespace mx
