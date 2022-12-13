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
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Type.h"
#include "TypeKind.h"

namespace mx {
class CXXRecordDecl;
class InjectedClassNameType;
class TemplateSpecializationType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using InjectedClassNameTypeRange = DerivedEntityRange<TypeIterator, InjectedClassNameType>;
using InjectedClassNameTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, InjectedClassNameType>;
class InjectedClassNameType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static InjectedClassNameTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static InjectedClassNameTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : InjectedClassNameType::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::INJECTED_CLASS_NAME;
  }

  static std::optional<InjectedClassNameType> from(const TokenContext &c);
  static std::optional<InjectedClassNameType> from(const Type &parent);

  inline static std::optional<InjectedClassNameType> from(const std::optional<Type> &parent) {
    if (parent) {
      return InjectedClassNameType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  CXXRecordDecl declaration(void) const;
  Type injected_specialization_type(void) const;
  TemplateSpecializationType injected_tst(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(InjectedClassNameType) == sizeof(Type));

#endif
} // namespace mx
