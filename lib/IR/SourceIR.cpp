// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "SourceIR.h"

#include <cassert>
#include <iostream>
#include <unordered_map>

#include <multiplier/AST/Attr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Designator.h>
#include <multiplier/AST/Macro.h>
#include <multiplier/AST/PseudoKind.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/Type.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Operation.h>
#include <multiplier/IR/Type.h>

#include <llvm/ADT/DenseMap.h>
#include <llvm/ADT/StringRef.h>
#include <llvm/Support/SourceMgr.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/MemRef/IR/MemRef.h>
#include <mlir/InitAllDialects.h>
#include <mlir/IR/AttributeSupport.h>
#include <mlir/IR/BuiltinOps.h>
#include <mlir/IR/BuiltinTypes.h>
#include <mlir/IR/BuiltinAttributes.h>
#include <mlir/IR/DialectRegistry.h>
#include <mlir/IR/TypeSupport.h>
#include <mlir/IR/Visitors.h>
#include <mlir/Parser/Parser.h>
#include <mlir/Support/TypeID.h>

#include <vast/Dialect/Core/CoreOps.hpp>
#include <vast/Dialect/Core/CoreTypes.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/ABI/ABIOps.hpp>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/HighLevel/HighLevelTypes.hpp>
#include <vast/Dialect/LowLevel/LowLevelOps.hpp>
#include <vast/Dialect/Meta/MetaAttributes.hpp>
#include <vast/Dialect/Meta/MetaTypes.hpp>
#include <vast/Dialect/Unsupported/UnsupportedOps.hpp>
#include <vast/Dialect/Unsupported/UnsupportedTypes.hpp>
#include <vast/CodeGen/CodeGenContext.hpp>
#include <vast/CodeGen/CodeGenBuilder.hpp>

#include "../Fragment.h"
#include "Attribute.h"
#include "Operation.h"
#include "Type.h"

namespace mx {
namespace ir {
namespace {

// Get the entity id from the location. It is embedded as `meta.id<>`
static EntityId MetaIdFromLocation(mlir::Location loc) {
  if (loc.isa<mlir::FusedLoc>()) {
    mlir::Attribute meta = loc.cast<mlir::FusedLoc>().getMetadata();
    if (meta.isa<vast::meta::IdentifierAttr>()) {
      return EntityId(meta.cast<const vast::meta::IdentifierAttr>().getValue());
    }
  }
  return {};
}

// Register all dialects.
class MLIRRegistryInitializer {
 public:
  explicit MLIRRegistryInitializer(mlir::DialectRegistry &registry) {
    ::vast::registerAllDialects(registry);
    ::mlir::registerAllDialects(registry);
  }
};

class MLIRInitializer {
 private:
  MLIRInitializer(void) = delete;

  mlir::DialectRegistry registry;
  MLIRRegistryInitializer registry_initializer;
  mutable mlir::MLIRContext context;

 public:

  llvm::DenseMap<llvm::StringRef, OperationKind> op_name_to_kind;
  llvm::DenseMap<mlir::TypeID, OperationKind> op_type_to_kind;
  llvm::DenseMap<mlir::TypeID, AttributeKind> attr_type_to_kind;
  llvm::DenseMap<mlir::TypeID, TypeKind> type_type_to_kind;

  explicit MLIRInitializer(int);

  inline mlir::MLIRContext &Context(void) const noexcept {
    return context;
  }
};

MLIRInitializer::MLIRInitializer(int)
    : registry(),
      registry_initializer(registry),
      context(registry, mlir::MLIRContext::Threading::DISABLED),
      op_name_to_kind(MX_IR_NUM_MLIR_OPS),
      op_type_to_kind(MX_IR_NUM_MLIR_OPS) {

  context.loadAllAvailableDialects();
  context.enableMultithreading();

  // Map all operation types.
#define MAP_OP_NAME(name, kind, type) \
    op_name_to_kind.try_emplace(name, kind);

#define MAP_OP_TYPE(name, kind, type) \
    op_type_to_kind.try_emplace(mlir::TypeID::get<type>(), kind);

#define MAP_ATTR_TYPE(name, kind, type) \
    attr_type_to_kind.try_emplace(mlir::TypeID::get<type>(), kind);

#define MAP_TYPE_TYPE(name, kind, type) \
    type_type_to_kind.try_emplace(mlir::TypeID::get<type>(), kind);

  MX_IR_FOR_EACH_MLIR_OP(MAP_OP_NAME, MAP_OP_NAME, MAP_OP_NAME, MAP_OP_NAME,
                         MAP_OP_NAME, MAP_OP_NAME, MAP_OP_NAME, MAP_OP_NAME,
                         MAP_OP_NAME)

  MX_IR_FOR_EACH_MLIR_OP(MAP_OP_TYPE, MAP_OP_TYPE, MAP_OP_TYPE, MAP_OP_TYPE,
                         MAP_OP_TYPE, MAP_OP_TYPE, MAP_OP_TYPE, MAP_OP_TYPE,
                         MAP_OP_TYPE)

  MX_IR_FOR_EACH_MLIR_ATTRIBUTE(MAP_ATTR_TYPE, MAP_ATTR_TYPE, MAP_ATTR_TYPE,
                                MAP_ATTR_TYPE, MAP_ATTR_TYPE, MAP_ATTR_TYPE,
                                MAP_ATTR_TYPE, MAP_ATTR_TYPE, MAP_ATTR_TYPE)

  MX_IR_FOR_EACH_MLIR_TYPE(MAP_TYPE_TYPE, MAP_TYPE_TYPE, MAP_TYPE_TYPE,
                           MAP_TYPE_TYPE, MAP_TYPE_TYPE, MAP_TYPE_TYPE,
                           MAP_TYPE_TYPE, MAP_TYPE_TYPE, MAP_TYPE_TYPE)

#undef MAP_OP_NAME
#undef MAP_OP_TYPE
#undef MAP_ATTR_TYPE
#undef MAP_TYPE_TYPE
}

static const MLIRInitializer kMLIR(0);

}  // namespace

OperationKind Operation::classify(::mlir::Operation *opaque) {
  mlir::TypeID tid = opaque->getName().getTypeID();
  if (auto it = kMLIR.op_type_to_kind.find(tid);
      it != kMLIR.op_type_to_kind.end()) {
    return it->second;
  } else {
    return OperationKind::UNKNOWN;
  }
}

OperationKind Operation::classify(std::string_view name_) {
  llvm::StringRef name(name_);
  if (auto it = kMLIR.op_name_to_kind.find(name);
      it != kMLIR.op_name_to_kind.end()) {
    return it->second;
  } else {
    return OperationKind::UNKNOWN;
  }
}

AttributeKind Attribute::classify(::mlir::AttributeStorage *opaque) {
  mlir::TypeID tid = opaque->getAbstractAttribute().getTypeID();
  if (auto it = kMLIR.attr_type_to_kind.find(tid);
      it != kMLIR.attr_type_to_kind.end()) {
    return it->second;
  } else {
    return AttributeKind::UNKNOWN;
  }
}

TypeKind Type::classify(::mlir::TypeStorage *opaque) {
  mlir::TypeID tid = opaque->getAbstractType().getTypeID();
  if (auto it = kMLIR.type_type_to_kind.find(tid);
      it != kMLIR.type_type_to_kind.end()) {
    return it->second;
  } else {
    return TypeKind::UNKNOWN;
  }
}

SourceIRImpl::SourceIRImpl(PackedCompilationId compilation_id_,
                           EntityProviderPtr ep_, std::string_view mlir)
    : compilation_id(compilation_id_),
      ep(std::move(ep_)) {

  llvm::SourceMgr sm;
  sm.AddNewSourceBuffer(llvm::MemoryBuffer::getMemBuffer(mlir), llvm::SMLoc());

  mlir::MLIRContext &context = ir::kMLIR.Context();
  context.enterMultiThreadedExecution();
  mod = mlir::parseSourceFile<mlir::ModuleOp>(sm, &context);
  context.exitMultiThreadedExecution();

  if (!mod) {
    return;
  }

  // Index the entities / operations in the module.
  auto result = mod->walk<mlir::WalkOrder::PreOrder>(
      [this] (mlir::Operation *child) {
        operations[ir::Operation::classify(child)].push_back(child);

        EntityId eid = ir::MetaIdFromLocation(child->getLoc());
        VariantId vid = eid.Unpack();
        if (std::holds_alternative<InvalidId>(vid)) {
          return mlir::WalkResult::advance();
        }

        if (std::holds_alternative<DeclId>(vid)) {
          declarations[std::get<DeclId>(vid).kind].push_back(child);

        } else if (std::holds_alternative<StmtId>(vid)) {
          statements[std::get<StmtId>(vid).kind].push_back(child);

        } else if (std::holds_alternative<TypeId>(vid)) {
          types[std::get<TypeId>(vid).kind].push_back(child);
        }

        entities[eid.Pack()].push_back(child);

        return mlir::WalkResult::advance();
      });

  assert(result != mlir::WalkResult::interrupt());
  (void) result;
}

SourceIRImpl::~SourceIRImpl(void) {}

mlir::Operation *SourceIRImpl::scope(void) const {
  if (mod) {
    return reinterpret_cast<mlir::Operation *>(
        const_cast<void *>(mod.get().getAsOpaquePointer()));
  } else {
    return nullptr;
  }
}

//const OperationRange::OpVec *
//SourceIRImpl::ForDecl(const Decl &decl) const {
//  auto id = decl.id().Pack();
//  // NOTE(kumarak): A decl can have multiple redeclaration. If the entity id of
//  //                the decl is not available in the source ir, it will fall
//  //                back to checking for the entity ids of redeclarations.
//  auto found_item = deserialized_ops.find(id);
//  if (found_item != deserialized_ops.end()) {
//    return &found_item->second;
//  }
//
//  for (auto raw_id : frag->ep->Redeclarations(frag->ep, id)) {
//    auto item = deserialized_ops.find(raw_id);
//    if (item != deserialized_ops.end()) {
//      return &item->second;
//    }
//  }
//
//  return {};
//}
//
//const OperationRange::OpVec *
//SourceIRImpl::ForStmt(const Stmt &stmt) const {
//  auto id = stmt.id().Pack();
//  auto found_item = deserialized_ops.find(id);
//  if (found_item != deserialized_ops.end()) {
//    return &found_item->second;
//  }
//  return {};
//}
//
//const OperationRange::OpVec *
//SourceIRImpl::ForType(const Type &) const {
//  return {};
//}
//
//const OperationRange::OpVec *
//SourceIRImpl::ForAttr(const Attr &) const {
//  return {};
//}
//
//const OperationRange::OpVec *
//SourceIRImpl::ForMacro(const Macro &) const {
//  return {};
//}
//
//#define MX_DEFINE_ENTITY_FUNCTION(type_name, lower_name, e, v) \
//	const OperationRange::OpVec * \
//	SourceIRImpl::For##type_name(const type_name &lower_name) const { \
//    return {}; \
//  }
//
//MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
//                            MX_IGNORE_ENTITY_CATEGORY,
//                            MX_IGNORE_ENTITY_CATEGORY,
//                            MX_IGNORE_ENTITY_CATEGORY,
//                            MX_IGNORE_ENTITY_CATEGORY,
//                            MX_DEFINE_ENTITY_FUNCTION)
//
//#undef MX_DEFINE_ENTITY_FUNCTION
//
//
//VariantEntity SourceIRImpl::EntityFor(EntityId eid) const {
//  Fragment f(frag);
//  return Index::containing(f).entity(eid);
//}

}  // namespace ir
}  // namespace mx
