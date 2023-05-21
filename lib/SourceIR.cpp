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
#include <mlir/InitAllDialects.h>
#include <mlir/Parser/Parser.h>

#include <vast/Dialect/Dialects.hpp>
#include <vast/Translation/CodeGenContext.hpp>
#include <vast/Translation/CodeGenBuilder.hpp>
#include <vast/Dialect/Meta/MetaTypes.hpp>
#include <vast/Dialect/Dialects.hpp>

namespace mx {
namespace {

// Get the entity id from the location. It is embedded as `meta.id<>`
static RawEntityId MetaIdFromLocation(mlir::Location loc) {
  if (loc.isa<mlir::FusedLoc>()) {
    auto fused = loc.cast<mlir::FusedLoc>();
    auto meta = fused.getMetadata();
    if (meta.isa<vast::meta::IdentifierAttr>()) {
      auto identifier = meta.cast<const vast::meta::IdentifierAttr>();
      return identifier.getValue();
    }
  }
  return kInvalidEntityId;
}

// Function traverse through the child operation and deserialize the module scope
// to an entity to operation map.
static OperationMap Deserialize(mlir::Operation *scope) {
  OperationMap entities;
  auto result = scope->walk<mlir::WalkOrder::PreOrder>(
      [&] (mlir::Operation *child) {
        auto loc = child->getLoc();
        auto id = MetaIdFromLocation(loc);
        if (id != kInvalidEntityId) {
          entities[id].emplace_back(const_cast<RawMLIROperationPtr>(child));
        }
        return mlir::WalkResult::advance();
      });

  // Add assert to check if it gets hit at anytime?
  assert(result != mlir::WalkResult::interrupt());
  (void) result;
  return entities;
}

} // namespace

#define MX_DEFINE_ENTITY_FUNCTION(type_name, lower_name, e, v) \
  OperationRange SourceIR::for_##lower_name(\
      const type_name &lower_name) const { \
    if (auto ops = impl->For##type_name(lower_name); ops) { \
      return OperationRange(OperationRange::OpVecPtr(impl, ops)); \
    } \
    return {}; \
  }

  MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_DEFINE_ENTITY_FUNCTION,
                              MX_DEFINE_ENTITY_FUNCTION)
#undef MX_DEFINE_ENTITY_FUNCTION

MLIRModulePtr SourceIR::module(void) const {
  return MLIRModulePtr(impl, impl->mod.get().getOperation());
}

VariantEntity SourceIR::entity_for(RawMLIROperationPtr op) const {
  auto loc = const_cast<mlir::Operation *>(op)->getLoc();
  return impl->EntityFor(MetaIdFromLocation(loc));
}

VariantEntity SourceIR::entity_for(const MLIROperationPtr &op) const {
  return entity_for(op.get());
}

OperationRange SourceIR::for_entity(const VariantEntity &entity) const {
  if (false) {
#define MX_DEFINE_FOR_ENTRITY(type_name, lower_name, enum_name, val) \
    } else if (std::holds_alternative<type_name>(entity)) { \
      auto lower_name = std::get<type_name>(entity); \
      return for_##lower_name(lower_name);

  MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_DEFINE_FOR_ENTRITY,
                              MX_DEFINE_FOR_ENTRITY)
#undef MX_DEFINE_FOR_ENTRITY
  } else {
    return {};
  }
}

#define MX_DEFINE_ENTITY_FUNCTION(type_name, lower_name, enum_name, val) \
  std::optional<mx::type_name> SourceIR::lower_name ##_for( \
      RawMLIROperationPtr op) const { \
    auto ent = entity_for(op); \
    if (std::holds_alternative<type_name>(ent)) { \
      return std::move(std::get<type_name>(ent)); \
    } \
    return std::nullopt; \
  } \
  std::optional<mx::type_name> SourceIR::lower_name ##_for( \
      const MLIROperationPtr &op) const { \
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

namespace {

class RegistryInitializer {
 public:
  mlir::DialectRegistry registry;

  RegistryInitializer(void) {
    vast::registerAllDialects(registry);
    mlir::registerAllDialects(registry);
  }
};

static RegistryInitializer gMLIR;

} // namespace

SourceIRImpl::SourceIRImpl(std::shared_ptr<const FragmentImpl> frag_,
                           std::string_view mlir)
    : mctx(gMLIR.registry),
      frag(std::move(frag_)) {
  llvm::SourceMgr sm;
  auto buffer = llvm::MemoryBuffer::getMemBuffer(mlir);
  sm.AddNewSourceBuffer(std::move(buffer), llvm::SMLoc());
  mod = mlir::parseSourceFile<mlir::ModuleOp>(sm, &mctx);
  if (mod) {
    deserialized_ops = Deserialize(mod.get());
  } else {
    std::cerr << "Failed to lower: " << frag->fragment_id << "\n" << mlir << std::endl;
  }
}

SourceIRImpl::~SourceIRImpl(void) {}

RawMLIROperationPtr SourceIRImpl::scope(void) const {
  return mod.get();
}

const OperationRange::OpVec *
SourceIRImpl::ForDecl(const Decl &decl) const {
  auto id = decl.id().Pack();
  // NOTE(kumarak): A decl can have multiple redeclaration. If the entity id of
  //                the decl is not available in the source ir, it will fall
  //                back to checking for the entity ids of redeclarations.
  auto found_item = deserialized_ops.find(id);
  if (found_item != deserialized_ops.end()) {
    return &found_item->second;
  }

  for (auto raw_id : frag->ep->Redeclarations(frag->ep, id)) {
    auto item = deserialized_ops.find(raw_id);
    if (item != deserialized_ops.end()) {
      return &item->second;
    }
  }

  return {};
}

const OperationRange::OpVec *
SourceIRImpl::ForStmt(const Stmt &stmt) const {
  auto id = stmt.id().Pack();
  auto found_item = deserialized_ops.find(id);
  if (found_item != deserialized_ops.end()) {
    return &found_item->second;
  }
  return {};
}

const OperationRange::OpVec *
SourceIRImpl::ForType(const Type &) const {
  return {};
}

const OperationRange::OpVec *
SourceIRImpl::ForAttr(const Attr &) const {
  return {};
}

const OperationRange::OpVec *
SourceIRImpl::ForMacro(const Macro &) const {
  return {};
}

#define MX_DEFINE_ENTITY_FUNCTION(type_name, lower_name, e, v) \
	const OperationRange::OpVec * \
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
  Fragment f(frag);
  return Index::containing(f).entity(eid);
}

void SourceIRImpl::print(std::ostream &os) const {
  std::string result;
  auto flags = mlir::OpPrintingFlags();
  flags.enableDebugInfo(false);
  llvm::raw_string_ostream ss(result);
  mod.get()->print(ss, flags);
  os << result;
}

} // namespace mx
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

OperationRange SourceIR::for_entity(const VariantEntity &) const {
  return {};
}

MLIRModulePtr SourceIR::module(void) const {
  return {};
}

VariantEntity SourceIR::entity_for(RawMLIROperationPtr) const {
  return {};
}

VariantEntity SourceIR::entity_for(const MLIROperationPtr &) const {
  return {};
}

#define MX_DEFINE_ENTITY_FUNCTION(type_name, lower_name, e, v) \
    std::optional<mx::type_name> SourceIR::lower_name ##_for( \
        RawMLIROperationPtr) const { \
      return {}; \
    } \
    std::optional<mx::type_name> SourceIR::lower_name ##_for( \
        const MLIROperationPtr &) const { \
      return {}; \
    }

MX_FOR_EACH_ENTITY_CATEGORY(MX_DEFINE_ENTITY_FUNCTION,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DEFINE_ENTITY_FUNCTION,
                            MX_DEFINE_ENTITY_FUNCTION,
                            MX_DEFINE_ENTITY_FUNCTION)

#undef MX_DEFINE_ENTITY_FUNCTION

void SourceIR::print(std::ostream &) const {}

} // namespace mx

#endif
