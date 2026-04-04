// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/Function.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Object.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/FunctionDecl.h>
#include <multiplier/Fragment.h>

#include "Impl.h"
#include "../Fragment.h"
#include "../EntityProvider.h"

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
  auto r = impl->reader();
  auto pool = impl->frag->reader.getIrEntityPool();
  uint32_t base = r.getEntityOffset();
  uint16_t n = r.getNumBlocks();
  for (uint16_t i = 0; i < n; ++i) {
    auto eid = pool[base + i];
    auto vid = EntityId(eid).Unpack();
    if (auto *bid = std::get_if<IRBlockId>(&vid)) {
      co_yield IRBlock(std::make_shared<IRBlockImpl>(
          impl->frag, bid->offset, impl->fragment_id));
    }
  }
}

gap::generator<IRObject> IRFunction::objects(void) const & {
  if (!impl) co_return;
  auto r = impl->reader();
  auto pool = impl->frag->reader.getIrEntityPool();
  uint32_t base = r.getEntityOffset() + r.getNumBlocks();
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

std::optional<FunctionDecl> IRFunction::declaration(void) const {
  if (!impl) return std::nullopt;
  auto eid = impl->reader().getFuncDeclEntityId();
  if (eid == kInvalidEntityId) return std::nullopt;
  if (auto ptr = impl->frag->ep->DeclFor(impl->frag->ep, eid)) {
    auto decl = Decl(std::move(ptr));
    return FunctionDecl::from(decl);
  }
  return std::nullopt;
}

std::optional<IRFunction> IRFunction::from(const FunctionDecl &decl) {
  auto frag = Fragment::containing(decl);
  if (!frag.impl) return std::nullopt;

  auto decl_eid = decl.id().Pack();
  auto ir_funcs = frag.impl->reader.getIrFunctions();
  auto frag_id = frag.impl->fragment_id;

  for (unsigned i = 0; i < ir_funcs.size(); ++i) {
    if (ir_funcs[i].getFuncDeclEntityId() == decl_eid) {
      return IRFunction(std::make_shared<IRFunctionImpl>(
          frag.impl, i, frag_id));
    }
  }
  return std::nullopt;
}

}  // namespace mx
