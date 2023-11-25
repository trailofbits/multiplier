// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../../Operation.h"

namespace vast::abi {
class CallArgsOp;
class CallExecutionOp;
class CallOp;
class CallRetsOp;
class DirectOp;
class EpilogueOp;
class FuncOp;
class PrologueOp;
class RetDirectOp;
class TodoOp;
class WrapFuncOp;
class YieldOp;
}  // namespace vast::abi
namespace mx::ir::abi {

class Operation : public ::mx::ir::Operation {
 public:
  static std::optional<Operation> from(const ::mx::ir::Operation &);
};
static_assert(sizeof(Operation) == sizeof(::mx::ir::Operation));

class CallArgsOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::ABI_CALL_ARGS;
  }

  static std::optional<CallArgsOp> from(const ::mx::ir::Operation &that);
  static std::optional<CallArgsOp> producing(const ::mx::ir::Value &val);

  ::vast::abi::CallArgsOp underlying_repr(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Result> results(void) const;
  ::mx::ir::Region body(void) const;
};
static_assert(sizeof(CallArgsOp) == sizeof(Operation));

class CallExecutionOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::ABI_CALL_EXEC;
  }

  static std::optional<CallExecutionOp> from(const ::mx::ir::Operation &that);
  static std::optional<CallExecutionOp> producing(const ::mx::ir::Value &val);

  ::vast::abi::CallExecutionOp underlying_repr(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> args(void) const;
  ::mx::ir::Value result(void) const;
  ::mx::ir::Region body(void) const;
  std::string_view callee(void) const;
  //::mlir::CallInterfaceCallable callable_for_callee(void) const;
  gap::generator<::mx::ir::Operand> arg_operands(void) const;
};
static_assert(sizeof(CallExecutionOp) == sizeof(Operation));

class CallOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::ABI_CALL;
  }

  static std::optional<CallOp> from(const ::mx::ir::Operation &that);
  static std::optional<CallOp> producing(const ::mx::ir::Value &val);

  ::vast::abi::CallOp underlying_repr(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> args(void) const;
  gap::generator<::mx::ir::Result> results(void) const;
  std::string_view callee(void) const;
  //::mlir::CallInterfaceCallable callable_for_callee(void) const;
  gap::generator<::mx::ir::Operand> arg_operands(void) const;
};
static_assert(sizeof(CallOp) == sizeof(Operation));

class CallRetsOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::ABI_CALL_RETS;
  }

  static std::optional<CallRetsOp> from(const ::mx::ir::Operation &that);
  static std::optional<CallRetsOp> producing(const ::mx::ir::Value &val);

  ::vast::abi::CallRetsOp underlying_repr(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Result> results(void) const;
  ::mx::ir::Region body(void) const;
};
static_assert(sizeof(CallRetsOp) == sizeof(Operation));

class DirectOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::ABI_DIRECT;
  }

  static std::optional<DirectOp> from(const ::mx::ir::Operation &that);
  static std::optional<DirectOp> producing(const ::mx::ir::Value &val);

  ::vast::abi::DirectOp underlying_repr(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> value(void) const;
  gap::generator<::mx::ir::Result> result(void) const;
};
static_assert(sizeof(DirectOp) == sizeof(Operation));

class EpilogueOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::ABI_EPILOGUE;
  }

  static std::optional<EpilogueOp> from(const ::mx::ir::Operation &that);
  static std::optional<EpilogueOp> producing(const ::mx::ir::Value &val);

  ::vast::abi::EpilogueOp underlying_repr(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Result> results(void) const;
  ::mx::ir::Region body(void) const;
};
static_assert(sizeof(EpilogueOp) == sizeof(Operation));

class FuncOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::ABI_FUNC;
  }

  static std::optional<FuncOp> from(const ::mx::ir::Operation &that);
  static std::optional<FuncOp> producing(const ::mx::ir::Value &val);

  ::vast::abi::FuncOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body(void) const;
  std::string_view sym_name(void) const;
  //::vast::core::FunctionType function_type(void) const;
  //::vast::core::GlobalLinkageKind linkage(void) const;
  std::optional<std::string_view> sym_visibility(void) const;
  //::std::optional<::mlir::ArrayAttr> arg_attrs(void) const;
  //::std::optional<::mlir::ArrayAttr> res_attrs(void) const;
  bool is_var_arg(void) const;
  //::mlir::Region* callable_region(void) const;
  //llvm::ArrayRef<Type> callable_results(void) const;
  //::mlir::ArrayAttr callable_arg_attrs(void) const;
  //::mlir::ArrayAttr callable_res_attrs(void) const;
  //llvm::ArrayRef<Type> argument_types(void) const;
  //llvm::ArrayRef<Type> result_types(void) const;
  bool is_declaration(void) const;
};
static_assert(sizeof(FuncOp) == sizeof(Operation));

class PrologueOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::ABI_PROLOGUE;
  }

  static std::optional<PrologueOp> from(const ::mx::ir::Operation &that);
  static std::optional<PrologueOp> producing(const ::mx::ir::Value &val);

  ::vast::abi::PrologueOp underlying_repr(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Result> results(void) const;
  ::mx::ir::Region body(void) const;
};
static_assert(sizeof(PrologueOp) == sizeof(Operation));

class RetDirectOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::ABI_RET_DIRECT;
  }

  static std::optional<RetDirectOp> from(const ::mx::ir::Operation &that);
  static std::optional<RetDirectOp> producing(const ::mx::ir::Value &val);

  ::vast::abi::RetDirectOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  gap::generator<::mx::ir::Result> result(void) const;
};
static_assert(sizeof(RetDirectOp) == sizeof(Operation));

class TodoOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::ABI_TODO;
  }

  static std::optional<TodoOp> from(const ::mx::ir::Operation &that);
  static std::optional<TodoOp> producing(const ::mx::ir::Value &val);

  ::vast::abi::TodoOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  gap::generator<::mx::ir::Result> result(void) const;
};
static_assert(sizeof(TodoOp) == sizeof(Operation));

class WrapFuncOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::ABI_WRAP_FN;
  }

  static std::optional<WrapFuncOp> from(const ::mx::ir::Operation &that);
  static std::optional<WrapFuncOp> producing(const ::mx::ir::Value &val);

  ::vast::abi::WrapFuncOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body(void) const;
  std::string_view sym_name(void) const;
  //::vast::core::FunctionType function_type(void) const;
  //::vast::core::GlobalLinkageKind linkage(void) const;
  std::optional<std::string_view> sym_visibility(void) const;
  //::std::optional<::mlir::ArrayAttr> arg_attrs(void) const;
  //::std::optional<::mlir::ArrayAttr> res_attrs(void) const;
  bool is_var_arg(void) const;
  //::mlir::Region* callable_region(void) const;
  //llvm::ArrayRef<Type> callable_results(void) const;
  //::mlir::ArrayAttr callable_arg_attrs(void) const;
  //::mlir::ArrayAttr callable_res_attrs(void) const;
  //llvm::ArrayRef<Type> argument_types(void) const;
  //llvm::ArrayRef<Type> result_types(void) const;
  bool is_declaration(void) const;
};
static_assert(sizeof(WrapFuncOp) == sizeof(Operation));

class YieldOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::ABI_YIELD;
  }

  static std::optional<YieldOp> from(const ::mx::ir::Operation &that);
  static std::optional<YieldOp> producing(const ::mx::ir::Value &val);

  ::vast::abi::YieldOp underlying_repr(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> values(void) const;
  gap::generator<::mx::ir::Result> result(void) const;
};
static_assert(sizeof(YieldOp) == sizeof(Operation));

}  // namespace mx::ir::abi
