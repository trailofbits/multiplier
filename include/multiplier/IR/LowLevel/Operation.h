// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Operation.h"

namespace vast::ll {
class Alloca;
class ArgAlloca;
class Br;
class Concat;
class CondBr;
class CondScopeRet;
class Extract;
class InitializeVar;
class InlineScope;
class Load;
class FuncOp;
class StructGEPOp;
class ReturnOp;
class Scope;
class ScopeRecurse;
class ScopeRet;
class Store;
class Subscript;
class UninitializedVar;
}  // namespace vast::ll
namespace mx::ir::ll {

class MX_EXPORT Operation : public ::mx::ir::Operation {
 public:
  static std::optional<Operation> from(const ::mx::ir::Operation &);
};
static_assert(sizeof(Operation) == sizeof(::mx::ir::Operation));

class MX_EXPORT AllocaOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::LL_ALLOCA;
  }

  static std::optional<AllocaOp> from(const ::mx::ir::Operation &that);
  static std::optional<AllocaOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::Alloca underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(AllocaOp) == sizeof(Operation));

class MX_EXPORT ArgAllocaOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::LL_ARG_ALLOCA;
  }

  static std::optional<ArgAllocaOp> from(const ::mx::ir::Operation &that);
  static std::optional<ArgAllocaOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::ArgAlloca underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value fn_arg(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(ArgAllocaOp) == sizeof(Operation));

class MX_EXPORT BrOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::LL_BR;
  }

  static std::optional<BrOp> from(const ::mx::ir::Operation &that);
  static std::optional<BrOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::Br underlying_repr(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> operands(void) const &;
  //::mlir::Block * dest(void) const;
};
static_assert(sizeof(BrOp) == sizeof(Operation));

class MX_EXPORT ConcatOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::LL_CONCAT;
  }

  static std::optional<ConcatOp> from(const ::mx::ir::Operation &that);
  static std::optional<ConcatOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::Concat underlying_repr(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> args(void) const &;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(ConcatOp) == sizeof(Operation));

class MX_EXPORT CondBrOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::LL_COND_BR;
  }

  static std::optional<CondBrOp> from(const ::mx::ir::Operation &that);
  static std::optional<CondBrOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::CondBr underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value cond(void) const;
  gap::generator<::mx::ir::Operand> true_operands(void) const &;
  gap::generator<::mx::ir::Operand> false_operands(void) const &;
  //::mlir::Block * true_dest(void) const;
  //::mlir::Block * false_dest(void) const;
};
static_assert(sizeof(CondBrOp) == sizeof(Operation));

class MX_EXPORT CondScopeRetOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::LL_COND_SCOPE_RET;
  }

  static std::optional<CondScopeRetOp> from(const ::mx::ir::Operation &that);
  static std::optional<CondScopeRetOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::CondScopeRet underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value cond(void) const;
  gap::generator<::mx::ir::Operand> dest_operands(void) const &;
  //::mlir::Block * dest(void) const;
};
static_assert(sizeof(CondScopeRetOp) == sizeof(Operation));

class MX_EXPORT ExtractOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::LL_EXTRACT;
  }

  static std::optional<ExtractOp> from(const ::mx::ir::Operation &that);
  static std::optional<ExtractOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::Extract underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value result(void) const;
  //::mlir::TypedAttr from(void) const;
  //::mlir::TypedAttr to(void) const;
  std::size_t size(void) const;
};
static_assert(sizeof(ExtractOp) == sizeof(Operation));

class MX_EXPORT InitializeVarOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::LL_INITIALIZE;
  }

  static std::optional<InitializeVarOp> from(const ::mx::ir::Operation &that);
  static std::optional<InitializeVarOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::InitializeVar underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value var(void) const;
  gap::generator<::mx::ir::Operand> elements(void) const &;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(InitializeVarOp) == sizeof(Operation));

class MX_EXPORT InlineScopeOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::LL_INLINE_SCOPE;
  }

  static std::optional<InlineScopeOp> from(const ::mx::ir::Operation &that);
  static std::optional<InlineScopeOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::InlineScope underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body(void) const;
};
static_assert(sizeof(InlineScopeOp) == sizeof(Operation));

class MX_EXPORT LoadOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::LL_LOAD;
  }

  static std::optional<LoadOp> from(const ::mx::ir::Operation &that);
  static std::optional<LoadOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::Load underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<ElementTypeInterface> ptr(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(LoadOp) == sizeof(Operation));

class MX_EXPORT FuncOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::LL_FUNC;
  }

  static std::optional<FuncOp> from(const ::mx::ir::Operation &that);
  static std::optional<FuncOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::FuncOp underlying_repr(void) const noexcept;

  // Imported methods:
  std::optional<::mx::ir::Region> body(void) const;
  std::string_view sym_name(void) const;
  //::vast::core::FunctionType function_type(void) const;
  //::std::optional<GlobalLinkageKind> linkage(void) const;
  std::optional<std::string_view> sym_visibility(void) const;
  //::std::optional<ArrayAttr> arg_attrs(void) const;
  //::std::optional<ArrayAttr> res_attrs(void) const;
  bool is_var_arg(void) const;
  //::mlir::Region * callable_region(void) const;
  gap::generator<::mx::ir::Type> callable_results(void) const &;
  //::mlir::ArrayAttr callable_arg_attrs(void) const;
  //::mlir::ArrayAttr callable_res_attrs(void) const;
  gap::generator<::mx::ir::Type> argument_types(void) const &;
  gap::generator<::mx::ir::Type> result_types(void) const &;
  bool is_declaration(void) const;
};
static_assert(sizeof(FuncOp) == sizeof(Operation));

class MX_EXPORT StructGEPOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::LL_GEP;
  }

  static std::optional<StructGEPOp> from(const ::mx::ir::Operation &that);
  static std::optional<StructGEPOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::StructGEPOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value record(void) const;
  ::mx::ir::Value element(void) const;
  uint32_t idx(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(StructGEPOp) == sizeof(Operation));

class MX_EXPORT ReturnOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::LL_RETURN;
  }

  static std::optional<ReturnOp> from(const ::mx::ir::Operation &that);
  static std::optional<ReturnOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::ReturnOp underlying_repr(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> result(void) const &;
};
static_assert(sizeof(ReturnOp) == sizeof(Operation));

class MX_EXPORT ScopeOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::LL_SCOPE;
  }

  static std::optional<ScopeOp> from(const ::mx::ir::Operation &that);
  static std::optional<ScopeOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::Scope underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body(void) const;
  //mlir::Block * start__block(void) const;
};
static_assert(sizeof(ScopeOp) == sizeof(Operation));

class MX_EXPORT ScopeRecurseOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::LL_SCOPE_RECURSE;
  }

  static std::optional<ScopeRecurseOp> from(const ::mx::ir::Operation &that);
  static std::optional<ScopeRecurseOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::ScopeRecurse underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(ScopeRecurseOp) == sizeof(Operation));

class MX_EXPORT ScopeRetOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::LL_SCOPE_RET;
  }

  static std::optional<ScopeRetOp> from(const ::mx::ir::Operation &that);
  static std::optional<ScopeRetOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::ScopeRet underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(ScopeRetOp) == sizeof(Operation));

class MX_EXPORT StoreOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::LL_STORE;
  }

  static std::optional<StoreOp> from(const ::mx::ir::Operation &that);
  static std::optional<StoreOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::Store underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value val(void) const;
  //::mlir::TypedValue<ElementTypeInterface> ptr(void) const;
};
static_assert(sizeof(StoreOp) == sizeof(Operation));

class MX_EXPORT SubscriptOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::LL_SUBSCRIPT;
  }

  static std::optional<SubscriptOp> from(const ::mx::ir::Operation &that);
  static std::optional<SubscriptOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::Subscript underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value array(void) const;
  ::mx::ir::Value index(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(SubscriptOp) == sizeof(Operation));

class MX_EXPORT UninitializedVarOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::LL_UNINITIALIZED_VAR;
  }

  static std::optional<UninitializedVarOp> from(const ::mx::ir::Operation &that);
  static std::optional<UninitializedVarOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::UninitializedVar underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(UninitializedVarOp) == sizeof(Operation));

}  // namespace mx::ir::ll
