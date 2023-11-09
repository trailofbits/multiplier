// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/VarDeclOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<VarDeclOp> VarDeclOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_VAR) {
    return reinterpret_cast<const VarDeclOp &>(that);
  }
  return std::nullopt;
}

std::optional<VarDeclOp> VarDeclOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::VarDeclOp VarDeclOp::underlying_op(void) const noexcept {
  return ::vast::hl::VarDeclOp(this->Operation::op_);
}

::mx::ir::Value VarDeclOp::result(void) const {
  auto val = underlying_op().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region VarDeclOp::initializer(void) const {
  auto &val = underlying_op().getInitializer();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region VarDeclOp::allocation_size(void) const {
  auto &val = underlying_op().getAllocationSize();
  return ::mx::ir::Region(module_, val);
}

std::string_view VarDeclOp::name(void) const {
  auto val = underlying_op().getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

bool VarDeclOp::has_local_storage(void) const {
  auto val = underlying_op().hasLocalStorage();
  return val;
}

bool VarDeclOp::is_local_var_decl(void) const {
  auto val = underlying_op().isLocalVarDecl();
  return val;
}

bool VarDeclOp::is_static_local(void) const {
  auto val = underlying_op().isStaticLocal();
  return val;
}

bool VarDeclOp::has_external_storage(void) const {
  auto val = underlying_op().hasExternalStorage();
  return val;
}

bool VarDeclOp::has_global_storage(void) const {
  auto val = underlying_op().hasGlobalStorage();
  return val;
}

bool VarDeclOp::is_static_data_member(void) const {
  auto val = underlying_op().isStaticDataMember();
  return val;
}

bool VarDeclOp::is_in_file_context(void) const {
  auto val = underlying_op().isInFileContext();
  return val;
}

bool VarDeclOp::is_in_function_or_method_context(void) const {
  auto val = underlying_op().isInFunctionOrMethodContext();
  return val;
}

bool VarDeclOp::is_in_record_context(void) const {
  auto val = underlying_op().isInRecordContext();
  return val;
}

bool VarDeclOp::is_file_var_decl(void) const {
  auto val = underlying_op().isFileVarDecl();
  return val;
}

}  // namespace mx::ir::hl
