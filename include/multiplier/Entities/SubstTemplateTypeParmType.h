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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Type.h"
#include "TypeKind.h"

namespace mx {
class SubstTemplateTypeParmType;
class TemplateTypeParmType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using SubstTemplateTypeParmTypeRange = DerivedEntityRange<TypeIterator, SubstTemplateTypeParmType>;
using SubstTemplateTypeParmTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, SubstTemplateTypeParmType>;
class SubstTemplateTypeParmType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static SubstTemplateTypeParmTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SubstTemplateTypeParmTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : SubstTemplateTypeParmType::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::SUBST_TEMPLATE_TYPE_PARM;
  }

  static std::optional<SubstTemplateTypeParmType> from(const TokenContext &c);
  static std::optional<SubstTemplateTypeParmType> from(const Type &parent);

  inline static std::optional<SubstTemplateTypeParmType> from(const std::optional<Type> &parent) {
    if (parent) {
      return SubstTemplateTypeParmType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  TemplateTypeParmType replaced_parameter(void) const;
  Type replacement_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(SubstTemplateTypeParmType) == sizeof(Type));

#endif
} // namespace mx
