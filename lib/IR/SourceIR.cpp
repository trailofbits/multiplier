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
#include <multiplier/AST/PseudoKind.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/Type.h>
#include <multiplier/Frontend/Macro.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/HighLevel/Operation.h>
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

#include "../Compilation.h"
#include "../Fragment.h"
#include "Attribute.h"
#include "Operation.h"
#include "Type.h"

namespace mx {
namespace ir {
namespace {

// Get the entity id from the location. It is embedded as `meta.id<>`
static RawEntityId MetaIdFromLocation(mlir::Location loc) {
  if (loc.isa<mlir::FusedLoc>()) {
    mlir::Attribute meta = loc.cast<mlir::FusedLoc>().getMetadata();
    if (meta.isa<vast::meta::IdentifierAttr>()) {
      return meta.cast<const vast::meta::IdentifierAttr>().getValue();
    }
  }
  return kInvalidEntityId;
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

  ~MLIRInitializer(void);
};

MLIRInitializer::MLIRInitializer(int)
    : registry(),
      registry_initializer(registry),
      context(registry, mlir::MLIRContext::Threading::ENABLED),
      op_name_to_kind(MX_IR_NUM_MLIR_OPS),
      op_type_to_kind(MX_IR_NUM_MLIR_OPS) {

  context.disableMultithreading();
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

MLIRInitializer::~MLIRInitializer(void) {
  context.disableMultithreading();
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
        auto op_kind = ir::Operation::classify(child);
        operations[op_kind].push_back(child);

        if (!IsHighLevelOperationKind(op_kind)) {
          return mlir::WalkResult::advance();
        }

        RawEntityId eid = MetaIdFromLocation(child->getLoc());
        VariantId vid = EntityId(eid).Unpack();

        if (std::holds_alternative<InvalidId>(vid)) {
          return mlir::WalkResult::advance();
        }

        if (std::holds_alternative<DeclId>(vid)) {
          declarations[std::get<DeclId>(vid).kind].emplace_back(eid, child);

        } else if (std::holds_alternative<StmtId>(vid)) {
          statements[std::get<StmtId>(vid).kind].emplace_back(eid, child);
        }

        entities[eid].emplace_back(op_kind, child);

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

}  // namespace ir

std::optional<Decl> Decl::from(const ir::hl::Operation &op) {
  RawEntityId eid = ir::MetaIdFromLocation(op.op_->getLoc());
  VariantId vid = EntityId(eid).Unpack();
  if (!std::holds_alternative<DeclId>(vid)) {
    return std::nullopt;
  }

  const auto &ep = op.module_->ep;
  auto eptr = ep->DeclFor(ep, eid);
  if (!eptr) {
    return std::nullopt;
  }

  return Decl(std::move(eptr));
}

gap::generator<std::pair<Decl, ir::hl::Operation>>
Decl::in(const Compilation &tu) {
  auto source_ir = tu.impl->SourceIRPtr(tu.id());
  if (!source_ir) {
    co_return;
  }

  const auto &ep = source_ir->ep;
  for (auto &[kind, eid_ops_pairs] : source_ir->declarations) {
    for (auto [eid, op_ptr] : eid_ops_pairs) {
      if (auto eptr = ep->DeclFor(ep, eid)) {
        ir::Operation op(source_ir, op_ptr);
        co_yield std::pair<Decl, ir::hl::Operation>(
            Decl(std::move(eptr)),
            std::move(reinterpret_cast<ir::hl::Operation &>(op)));
      }
    }
  }
}

gap::generator<std::pair<Decl, ir::hl::Operation>> Decl::in(
  const Compilation &tu, std::span<const DeclKind> kinds) {
  if (kinds.empty()) {
    co_return;
  }

  auto source_ir = tu.impl->SourceIRPtr(tu.id());
  if (!source_ir) {
    co_return;
  }

  const auto &ep = source_ir->ep;
  const auto it_end = source_ir->declarations.end();
  for (auto kind : kinds) {
    auto it = source_ir->declarations.find(kind);
    if (it == it_end) {
      continue;
    }

    for (auto [eid, op_ptr] : it->second) {
      if (auto eptr = ep->DeclFor(ep, eid)) {
        ir::Operation op(source_ir, op_ptr);
        co_yield std::pair<Decl, ir::hl::Operation>(
            Decl(std::move(eptr)),
            std::move(reinterpret_cast<ir::hl::Operation &>(op)));
      }
    }
  }
}

std::optional<Stmt> Stmt::from(const ir::hl::Operation &op) {
  RawEntityId eid = ir::MetaIdFromLocation(op.op_->getLoc());
  VariantId vid = EntityId(eid).Unpack();
  if (!std::holds_alternative<StmtId>(vid)) {
    return std::nullopt;
  }

  const auto &ep = op.module_->ep;
  auto eptr = ep->StmtFor(ep, eid);
  if (!eptr) {
    return std::nullopt;
  }

  return Stmt(std::move(eptr));
}

gap::generator<std::pair<Stmt, ir::hl::Operation>>
Stmt::in(const Compilation &tu) {
  auto source_ir = tu.impl->SourceIRPtr(tu.id());
  if (!source_ir) {
    co_return;
  }

  const auto &ep = source_ir->ep;
  for (auto &[kind, eid_ops_pairs] : source_ir->statements) {
    for (auto [eid, op_ptr] : eid_ops_pairs) {
      if (auto eptr = ep->StmtFor(ep, eid)) {
        ir::Operation op(source_ir, op_ptr);
        co_yield std::pair<Stmt, ir::hl::Operation>(
            Stmt(std::move(eptr)),
            std::move(reinterpret_cast<ir::hl::Operation &>(op)));
      }
    }
  }
}

gap::generator<std::pair<Stmt, ir::hl::Operation>> Stmt::in(
  const Compilation &tu, std::span<const StmtKind> kinds) {
    if (kinds.empty()) {
    co_return;
  }

  auto source_ir = tu.impl->SourceIRPtr(tu.id());
  if (!source_ir) {
    co_return;
  }

  const auto &ep = source_ir->ep;
  const auto it_end = source_ir->statements.end();
  for (auto kind : kinds) {
    auto it = source_ir->statements.find(kind);
    if (it == it_end) {
      continue;
    }

    for (auto [eid, op_ptr] : it->second) {
      if (auto eptr = ep->StmtFor(ep, eid)) {
        ir::Operation op(source_ir, op_ptr);
        co_yield std::pair<Stmt, ir::hl::Operation>(
            Stmt(std::move(eptr)),
            std::move(reinterpret_cast<ir::hl::Operation &>(op)));
      }
    }
  }
}

namespace ir {
namespace hl {
namespace {

static std::optional<Operation> FirstFrom(
    std::shared_ptr<const SourceIRImpl> source_ir, RawEntityId eid) {

  if (!source_ir) {
    return std::nullopt;
  }

  auto it = source_ir->entities.find(eid);
  if (it == source_ir->entities.end()) {
    return std::nullopt;
  }

  for (auto [op_kind, op_ptr] : it->second) {
    ::mx::ir::Operation op(std::move(source_ir), op_ptr, op_kind);
    return reinterpret_cast<Operation &&>(op);
  }

  return std::nullopt;
}

static std::optional<Operation> FirstFromOfKind(
    std::shared_ptr<const SourceIRImpl> source_ir, RawEntityId eid,
    OperationKind kind) {

  if (!source_ir) {
    return std::nullopt;
  }

  auto it = source_ir->entities.find(eid);
  if (it == source_ir->entities.end()) {
    return std::nullopt;
  }

  for (auto [op_kind, op_ptr] : it->second) {
    if (op_kind != kind) {
      continue;
    }

    ::mx::ir::Operation op(std::move(source_ir), op_ptr, op_kind);
    return reinterpret_cast<Operation &&>(op);
  }

  return std::nullopt;
}

static gap::generator<Operation> AllFrom(
    std::shared_ptr<const SourceIRImpl> source_ir, RawEntityId eid) {

  if (!source_ir) {
    co_return;
  }

  auto it = source_ir->entities.find(eid);
  if (it == source_ir->entities.end()) {
    co_return;
  }

  for (auto [op_kind, op_ptr] : it->second) {
    ::mx::ir::Operation op(std::move(source_ir), op_ptr, op_kind);
    co_yield reinterpret_cast<Operation &&>(op);
  }
}

}  // namespace

std::optional<Operation> Operation::first_from(const ::mx::Decl &that) {
  auto compilation = Compilation::containing(that);
  return FirstFrom(
      compilation.impl->SourceIRPtr(compilation.id()),
      that.id().Pack());
}

std::optional<Operation> Operation::first_from(const ::mx::Decl &that,
                                               OperationKind op_kind) {
  auto compilation = Compilation::containing(that);
  return FirstFromOfKind(
      compilation.impl->SourceIRPtr(compilation.id()),
      that.id().Pack(),
      op_kind);
}

gap::generator<Operation> Operation::all_from(const ::mx::Decl &that) {
  auto compilation = Compilation::containing(that);
  return AllFrom(
      compilation.impl->SourceIRPtr(compilation.id()),
      that.id().Pack());
}

std::optional<Operation> Operation::first_from(const ::mx::Stmt &that) {
  auto compilation = Compilation::containing(that);
  return FirstFrom(
      compilation.impl->SourceIRPtr(compilation.id()),
      that.id().Pack());
}

std::optional<Operation> Operation::first_from(const ::mx::Stmt &that,
                                               OperationKind op_kind) {
  auto compilation = Compilation::containing(that);
  return FirstFromOfKind(
      compilation.impl->SourceIRPtr(compilation.id()),
      that.id().Pack(),
      op_kind);
}

gap::generator<Operation> Operation::all_from(const ::mx::Stmt &that) {
  auto compilation = Compilation::containing(that);
  return AllFrom(
      compilation.impl->SourceIRPtr(compilation.id()),
      that.id().Pack());
}

}  // namespace hl
}  // namespace ir

}  // namespace mx
