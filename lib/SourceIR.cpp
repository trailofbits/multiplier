// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "SourceIR.h"

#include <iostream>
#include <unordered_map>

#include <multiplier/SourceIR.h>
#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Designator.h>
#include <multiplier/Entities/Macro.h>
#include <multiplier/Entities/PseudoKind.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Type.h>

#include "Fragment.h"

#ifdef MX_ENABLE_SOURCEIR
#include <llvm/Support/SourceMgr.h>
#include <mlir/Parser/Parser.h>

#include <vast/Dialect/Dialects.hpp>
#include <vast/Translation/CodeGenContext.hpp>
#include <vast/Translation/CodeGenBuilder.hpp>
#include <vast/Dialect/Meta/MetaTypes.hpp>
#include <vast/Dialect/Dialects.hpp>


namespace mx {
namespace {

// Get the entity id from the location. It is embedded as `meta.id<>`
static RawEntityId MetaIdFromLocation(mlir::Location &loc) {
  if (loc.isa<mlir::FusedLoc>()) {
    auto fused = loc.cast<mlir::FusedLoc>();
    auto meta = fused.getMetadata().cast<vast::meta::IdentifierAttr>();
    return meta.getValue();
  }
  return kInvalidEntityId;
}

// Function traverse through the child operation and deserialize the module scope
// to an entity to operation map.
static OperationMap Deserialize(mlir::Operation *scope) {
  OperationMap entities;
  auto result = scope->walk<mlir::WalkOrder::PreOrder>([&] (mlir::Operation *child) {
    auto loc = child->getLoc();
    auto id = MetaIdFromLocation(loc);
    entities[id].emplace(const_cast<const mlir::Operation*>(child));
    return mlir::WalkResult::advance();
  });

  if (result == mlir::WalkResult::interrupt()) {
    std::cerr << "WARNING: SourceIR deserialization got interrupted" << std::endl;
  }

  return entities;
}

}

#define MX_DEFINE_ENTITY_FUNCTION(type_name, lower_name, e, v) \
  OperationRange SourceIR::for_##lower_name(const mx::type_name &lower_name) const { \
    auto ops = impl->For##type_name(lower_name); \
    return OperationRange(std::shared_ptr<const OperationRange::Set>(impl, ops)); \
  }

  MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_DEFINE_ENTITY_FUNCTION,
                              MX_DEFINE_ENTITY_FUNCTION)
#undef MX_DEFINE_ENTITY_FUNCTION


VariantEntity
SourceIR::entity_for(const mlir::Operation *op) const {
  auto loc = const_cast<mlir::Operation*>(op)->getLoc();
  auto id = MetaIdFromLocation(loc);
  return impl->EntityFor(id);
}

VariantEntity
SourceIR::entity_for(const std::shared_ptr<const mlir::Operation> &op) const {
  return entity_for(op.get());
}

#define MX_DEFINE_ENTITY_FUNCTION(type_name, lower_name, enum_name, val) \
    std::optional<mx::type_name> SourceIR::lower_name ##_for(const mlir::Operation *op) const { \
      auto ent = entity_for(op); \
      if (std::holds_alternative<type_name>(ent)) { \
         return std::move(std::get<type_name>(ent)); \
      } \
      return std::nullopt; \
    } \
  std::optional<mx::type_name> SourceIR::lower_name ##_for \
    (const std::shared_ptr<const mlir::Operation> &op) const { \
    return lower_name ##_for(op.get()); \
  }

MX_FOR_EACH_ENTITY_CATEGORY(MX_DEFINE_ENTITY_FUNCTION,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DEFINE_ENTITY_FUNCTION,
                            MX_DEFINE_ENTITY_FUNCTION,
                            MX_DEFINE_ENTITY_FUNCTION)

#undef MX_DEFINE_ENTITY_FUNCTION

void SourceIR::print(std::ostream &os) const {
  impl->print(os);
}

mlir::DialectRegistry SourceIRImpl::registry;

SourceIRImpl::SourceIRImpl(std::shared_ptr<const FragmentImpl> frag_,
                           std::string_view &mlir)
    : mctx(Registry()), frag(frag_) {
  llvm::SourceMgr sm;
  auto buffer = llvm::MemoryBuffer::getMemBuffer(mlir);
  sm.AddNewSourceBuffer(std::move(buffer), llvm::SMLoc());
  mod = mlir::parseSourceFile<mlir::ModuleOp>(sm, &mctx);
  if (mod) {
    deserialized_ops = Deserialize(mod.get());
  }
}

SourceIRImpl::~SourceIRImpl(void) {}

const mlir::DialectRegistry&
SourceIRImpl::Registry(void) {
  struct RegistryInitializer {
    RegistryInitializer() {
       vast::registerAllDialects(registry);
       mlir::registerAllDialects(registry);
     }
  };
  static RegistryInitializer init_guard;
  return registry;
}

mlir::Operation* SourceIRImpl::scope(void) const {
  return mod.get();
}

const OperationRange::Set*
SourceIRImpl::ForDecl(const Decl &decl) const {
  auto id = decl.id().Pack();
  // Note: A decl can have multiple redeclaration. If the
  //       entity id of the decl is not available in the
  //       source ir, it will fallback to checking for the
  //       entity ids of redeclarations.
  auto found_item = deserialized_ops.find(id);
  if (found_item != deserialized_ops.end()) {
    return &found_item->second;
  }

  for (auto &raw_id : frag->ep->Redeclarations(frag->ep, id)) {
    auto item = deserialized_ops.find(raw_id);
    if (item != deserialized_ops.end()) {
      return &item->second;
    }
  }

  return {};
}

const OperationRange::Set*
SourceIRImpl::ForStmt(const Stmt &stmt) const {
  auto id = stmt.id().Pack();
  auto found_item = deserialized_ops.find(id);
  if (found_item != deserialized_ops.end()) {
    return &found_item->second;
  }
  return {};
}

const OperationRange::Set*
SourceIRImpl::ForType(const Type &) const {
  return {};
}

const OperationRange::Set*
SourceIRImpl::ForAttr(const Attr &) const {
  return {};
}

const OperationRange::Set*
SourceIRImpl::ForMacro(const Macro &) const {
  return {};
}

#define MX_DEFINE_ENTITY_FUNCTION(type_name, lower_name, e, v) \
	const OperationRange::Set* \
	SourceIRImpl::For##type_name(const type_name &lower_name) const { \
    return {}; \
  }

MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DEFINE_ENTITY_FUNCTION)

#undef MX_DEFINE_ENTITY_FUNCTION


VariantEntity SourceIRImpl::EntityFor(EntityId eid) const {
  auto index = Index::containing(frag);
  return index.entity(eid);
}

void SourceIRImpl::print(std::ostream &os) const {
  std::string result;
  auto flags = mlir::OpPrintingFlags();
  flags.enableDebugInfo(false);
  llvm::raw_string_ostream ss(result);
  mod.get()->print(ss, flags);
  os << result;
}

}
#else

namespace mx {

#define MX_DEFINE_ENTITY_FUNCTION(type_name, lower_name, e, v) \
	OperationRange SourceIR::for_##lower_name(const mx::type_name &) const { \
    return {}; \
  }

  MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_DEFINE_ENTITY_FUNCTION,
                              MX_DEFINE_ENTITY_FUNCTION)
#undef MX_DEFINE_ENTITY_FUNCTION


VariantEntity
SourceIR::entity_for(const mlir::Operation *) const {
  return {};
}

VariantEntity
SourceIR::entity_for(const std::shared_ptr<const mlir::Operation> &) const {
  return {};
}

#define MX_DEFINE_ENTITY_FUNCTION(type_name, lower_name, e, v) \
  std::optional<mx::type_name> SourceIR::lower_name ##_for \
    (const mlir::Operation *) const { \
      return {}; \
    } \
  std::optional<mx::type_name> SourceIR::lower_name ##_for \
    (const std::shared_ptr<const mlir::Operation> &) const { \
    return {}; \
  }

MX_FOR_EACH_ENTITY_CATEGORY(MX_DEFINE_ENTITY_FUNCTION,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DEFINE_ENTITY_FUNCTION,
                            MX_DEFINE_ENTITY_FUNCTION,
                            MX_DEFINE_ENTITY_FUNCTION)

#undef MX_DEFINE_ENTITY_FUNCTION

void SourceIR::print(std::ostream &) const {}

}

#endif
