// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/Builtin/ModuleOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>

namespace mx::ir::builtin {
std::optional<ModuleOp> ModuleOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::BUILTIN_MODULE) {
    return reinterpret_cast<const ModuleOp &>(that);
  }
  return std::nullopt;
}

std::optional<ModuleOp> ModuleOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::ModuleOp ModuleOp::underlying_op(void) const noexcept {
  return ::mlir::ModuleOp(this->Operation::op_);
}

::mx::ir::Region ModuleOp::body_region(void) const {
  auto &val = underlying_op().getBodyRegion();
  return ::mx::ir::Region(module_, val);
}

std::optional<std::string_view> ModuleOp::sym_name(void) const {
  auto opt_val = underlying_op().getSymName();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<std::string_view> ModuleOp::sym_visibility(void) const {
  auto opt_val = underlying_op().getSymVisibility();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<std::string_view> ModuleOp::name(void) const {
  auto opt_val = underlying_op().getName();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

bool ModuleOp::is_optional_symbol(void) const {
  auto val = underlying_op().isOptionalSymbol();
  return val;
}

std::string_view ModuleOp::default_dialect(void) const {
  auto val = underlying_op().getDefaultDialect();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

}  // namespace mx::ir::builtin
