// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class VarDeclOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class VarDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_VAR;
  }

  static std::optional<VarDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<VarDeclOp> producing(const ::mx::ir::Value &val);

  vast::hl::VarDeclOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  ::mx::ir::Region initializer(void) const;
  ::mx::ir::Region allocation_size(void) const;
  std::string_view name(void) const;
  //::std::optional<::vast::hl::StorageClass> storage_class(void) const;
  //::std::optional<::vast::hl::TSClass> thread_storage_class(void) const;
  bool has_local_storage(void) const;
  bool is_local_var_decl(void) const;
  bool is_static_local(void) const;
  bool has_external_storage(void) const;
  bool has_global_storage(void) const;
  //StorageDuration storage_duration(void) const;
  //DeclContextKind decl_context_kind(void) const;
  bool is_static_data_member(void) const;
  bool is_in_file_context(void) const;
  bool is_in_function_or_method_context(void) const;
  bool is_in_record_context(void) const;
  bool is_file_var_decl(void) const;
};
static_assert(sizeof(VarDeclOp) == sizeof(Operation));

}  // namespace mx::ir::hl
