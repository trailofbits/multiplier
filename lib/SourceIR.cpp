// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "SourceIR.h"
#include "Fragment.h"

#include <iostream>
#include <unordered_map>

#include <multiplier/SourceIR.h>

#ifdef MX_ENABLE_SOURCEIR
#include <llvm/Support/SourceMgr.h>
#include <mlir/Parser/Parser.h>

#include <vast/Dialect/Dialects.hpp>
#include <vast/Translation/CodeGenContext.hpp>
#include <vast/Translation/CodeGenBuilder.hpp>
#include <vast/Dialect/Meta/MetaTypes.hpp>


namespace mx {
namespace {

using OperationMap = std::unordered_map<uint64_t, mlir::Operation*>;

const RawEntityId invalid_id = (uint64_t)(-1);

std::shared_ptr<MLIRContext> create_mcontext(void) {
  mlir::DialectRegistry registry;
  vast::registerAllDialects(registry);
  mlir::registerAllDialects(registry);
  return std::make_shared<MLIRContext>(registry);
}

// Get the entity id from the location. It is embedded as `meta.id<>`
RawEntityId metaid_from_location(mlir::Location &loc) {
  if(loc.isa<mlir::FusedLoc>()) {
    auto fused = loc.cast<mlir::FusedLoc>();
    auto meta = fused.getMetadata().cast<vast::meta::IdentifierAttr>();
    return meta.getValue();
  }
  return invalid_id;
}

// Function traverse through the child operation and deserialize the module scope
// to an entity to operation map.
void deserialize(mlir::Operation *scope, OperationMap &entities) {
  scope->walk<mlir::WalkOrder::PreOrder>([&] (mlir::Operation *child) {
    auto loc = child->getLoc();
    auto id = metaid_from_location(loc);
    if (entities.find(id) == entities.end()) {
      entities.emplace(std::pair(id, child));
    }
    return mlir::WalkResult::advance();
  });
}

}

std::shared_ptr<const mlir::Operation>
SourceIR::for_decl(const mx::Decl &decl) const {
  OperationMap deserialized_ops;

  // deserialize the scope to Operation maps
  deserialize(impl->scope(), deserialized_ops);

  // Note: A decl can have multiple redeclaration. If the
  //       entity id of the decl is not available in the
  //       source ir, it will fallback to checking for the
  //       entity ids of redeclarations.
  auto id = decl.id().Pack();
  if (deserialized_ops.find(id) != deserialized_ops.end()) {
    return std::shared_ptr<mlir::Operation>(impl, deserialized_ops[id]);
  }

  for (auto &redecl : decl.redeclarations()) {
    auto raw_id = redecl.id().Pack();
    if (deserialized_ops.find(raw_id) != deserialized_ops.end()) {
      return std::shared_ptr<mlir::Operation>(impl, deserialized_ops[raw_id]);
    }
  }
  return {};
}

std::shared_ptr<const mlir::Operation>
SourceIR::for_stmt(const mx::Stmt &stmt) const {
  auto id = stmt.id().Pack();
  OperationMap deserialized_ops;

  // deserialize the scope to Operation maps
  deserialize(impl->scope(), deserialized_ops);
  if (deserialized_ops.find(id) != deserialized_ops.end()) {
    return std::shared_ptr<mlir::Operation>(impl, deserialized_ops[id]);
  }
  return {};
}

VariantEntity
SourceIR::entity_for(const mlir::Operation *op) const {
  auto loc = const_cast<mlir::Operation*>(op)->getLoc();
  auto id = metaid_from_location(loc);
  return impl->entity_for(id);
}

VariantEntity
SourceIR::entity_for(const std::shared_ptr<const mlir::Operation> op) const {
  return entity_for(op.get());
}

std::optional<mx::Decl>
SourceIR::decl_for(const mlir::Operation *op) const {
  auto ent = entity_for(op);
  if (std::holds_alternative<Decl>(ent)) {
    return std::move(std::get<Decl>(ent));
  }
  return std::nullopt;
}

std::optional<mx::Stmt>
SourceIR::stmt_for(const mlir::Operation *op) const {
  auto ent = entity_for(op);
  if (std::holds_alternative<Stmt>(ent)) {
    return std::move(std::get<Stmt>(ent));
  }
  return std::nullopt;
}

std::string SourceIR::operator*(void) const {
  std::string result;
  impl->print(result);
  return result;
}

void SourceIR::print(std::string &str) const {
  impl->print(str);
}

SourceIRImpl::SourceIRImpl(std::shared_ptr<const FragmentImpl> frag_,
                           std::string_view &mlir)
  : mctx(create_mcontext()), frag(frag_)
{
  llvm::SourceMgr sm;
  auto buffer = llvm::MemoryBuffer::getMemBuffer(mlir);
  sm.AddNewSourceBuffer(std::move(buffer), llvm::SMLoc());
  mod = mlir::parseSourceFile<mlir::ModuleOp>(sm, mctx.get());
}

SourceIRImpl::~SourceIRImpl(void) {}

mlir::Operation* SourceIRImpl::scope(void) const {
  return mod.get();
}

VariantEntity SourceIRImpl::entity_for(EntityId eid) {
  auto index = Index::containing(frag);
  return index.entity(eid);
}

void SourceIRImpl::print(std::string &str) const {
  auto flags = mlir::OpPrintingFlags();
  flags.enableDebugInfo(false);
  llvm::raw_string_ostream os(str);
  mod.get()->print(os, flags);
}

}
#else

namespace mx {

std::shared_ptr<const mlir::Operation>
SourceIR::for_decl(const mx::Decl&) const {
  return {};
}

std::shared_ptr<const mlir::Operation>
SourceIR::for_stmt(const mx::Stmt&) const {
  return {};
}

VariantEntity
SourceIR::entity_for(const mlir::Operation*) const {
  return {};
}

VariantEntity
SourceIR::entity_for(const std::shared_ptr<const mlir::Operation>) const {
  return {};
}

std::optional<mx::Decl>
SourceIR::decl_for(const mlir::Operation*) const {
  return {};
}

std::optional<mx::Stmt>
SourceIR::stmt_for(const mlir::Operation*) const {
  return {};
}

std::string SourceIR::operator*(void) const {
  return {};
}

void SourceIR::print(std::string&) const {}

}

#endif
