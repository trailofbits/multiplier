// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/Function.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Object.h>
#include <multiplier/IR/Structure.h>
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

ir::FunctionKind IRFunction::kind(void) const {
  if (!impl) return ir::FunctionKind::NORMAL;
  return static_cast<ir::FunctionKind>(impl->reader().getKind());
}

std::optional<FunctionDecl> IRFunction::declaration(void) const {
  if (!impl) return std::nullopt;
  if (kind() != ir::FunctionKind::NORMAL) return std::nullopt;
  auto eid = impl->reader().getSourceDeclEntityId();
  if (eid == kInvalidEntityId) return std::nullopt;
  if (auto ptr = impl->frag->ep->DeclFor(impl->frag->ep, eid)) {
    return FunctionDecl::from(Decl(std::move(ptr)));
  }
  return std::nullopt;
}

std::optional<Decl> IRFunction::source_declaration(void) const {
  if (!impl) return std::nullopt;
  auto eid = impl->reader().getSourceDeclEntityId();
  if (eid == kInvalidEntityId) return std::nullopt;
  if (auto ptr = impl->frag->ep->DeclFor(impl->frag->ep, eid)) {
    return Decl(std::move(ptr));
  }
  return std::nullopt;
}

std::optional<IRStructure> IRFunction::body_scope(void) const {
  if (!impl) return std::nullopt;
  auto eid = impl->reader().getBodyScopeId();
  if (eid == kInvalidEntityId) return std::nullopt;
  auto vid = EntityId(eid).Unpack();
  if (auto *sid = std::get_if<IRStructureId>(&vid)) {
    return IRStructure(std::make_shared<IRStructureImpl>(
        impl->frag, sid->offset, impl->fragment_id));
  }
  return std::nullopt;
}

std::optional<IRFunction> IRFunction::from(const FunctionDecl &decl) {
  // Try this specific declaration first.
  auto try_decl = [](const FunctionDecl &d) -> std::optional<IRFunction> {
    auto frag = Fragment::containing(d);
    if (!frag.impl) return std::nullopt;

    auto decl_eid = d.id().Pack();
    auto ir_funcs = frag.impl->reader.getIrFunctions();
    auto frag_id = frag.impl->fragment_id;

    for (unsigned i = 0; i < ir_funcs.size(); ++i) {
      if (ir_funcs[i].getSourceDeclEntityId() == decl_eid) {
        return IRFunction(std::make_shared<IRFunctionImpl>(
            frag.impl, i, frag_id));
      }
    }
    return std::nullopt;
  };

  if (auto ir = try_decl(decl)) return ir;

  // If this declaration has no IR, try the definition.
  // IR is generated from the definition, so a forward declaration
  // won't have IR mapped directly.
  if (!decl.is_definition()) {
    for (auto redecl : decl.redeclarations()) {
      if (auto fd = FunctionDecl::from(redecl)) {
        if (fd->is_definition()) {
          if (auto ir = try_decl(*fd)) return ir;
        }
      }
    }
  }

  return std::nullopt;
}

}  // namespace mx
