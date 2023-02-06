// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Type.h"
#include "TypeKind.h"

namespace mx {
class CXXRecordDecl;
class MemberPointerType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MemberPointerType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<MemberPointerType> in(const Fragment &frag);
  static gap::generator<MemberPointerType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::MEMBER_POINTER;
  }

  inline static std::optional<MemberPointerType> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<MemberPointerType> from(const TokenContext &t) {
    return from(t.as_type());
  }

  static std::optional<MemberPointerType> from(const Type &parent);

  inline static std::optional<MemberPointerType> from(const std::optional<Type> &parent) {
    if (parent) {
      return MemberPointerType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  Type class_(void) const;
  CXXRecordDecl most_recent_cxx_record_declaration(void) const;
  bool is_member_data_pointer(void) const;
  bool is_member_function_pointer(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(MemberPointerType) == sizeof(Type));

#endif
} // namespace mx
