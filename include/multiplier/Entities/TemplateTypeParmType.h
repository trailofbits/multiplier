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

#include "DeclUseSelector.h"
#include "Type.h"
#include "TypeKind.h"

namespace mx {
class TemplateTypeParmDecl;
class TemplateTypeParmType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using TemplateTypeParmTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, TemplateTypeParmType>;
class TemplateTypeParmType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static gap::generator<TemplateTypeParmType> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static TemplateTypeParmTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : TemplateTypeParmType::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::TEMPLATE_TYPE_PARM;
  }

  static std::optional<TemplateTypeParmType> from(const TokenContext &c);
  static std::optional<TemplateTypeParmType> from(const Type &parent);

  inline static std::optional<TemplateTypeParmType> from(const std::optional<Type> &parent) {
    if (parent) {
      return TemplateTypeParmType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  std::optional<TemplateTypeParmDecl> declaration(void) const;
  bool is_parameter_pack(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(TemplateTypeParmType) == sizeof(Type));

#endif
} // namespace mx
