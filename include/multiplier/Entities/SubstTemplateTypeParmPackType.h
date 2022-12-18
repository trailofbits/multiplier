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
class SubstTemplateTypeParmPackType;
class TemplateTypeParmType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using SubstTemplateTypeParmPackTypeRange = DerivedEntityRange<TypeIterator, SubstTemplateTypeParmPackType>;
using SubstTemplateTypeParmPackTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, SubstTemplateTypeParmPackType>;
class SubstTemplateTypeParmPackType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static SubstTemplateTypeParmPackTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SubstTemplateTypeParmPackTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : SubstTemplateTypeParmPackType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::SUBST_TEMPLATE_TYPE_PARM_PACK;
  }

  static std::optional<SubstTemplateTypeParmPackType> from(const TokenContext &c);
  static std::optional<SubstTemplateTypeParmPackType> from(const Type &parent);

  inline static std::optional<SubstTemplateTypeParmPackType> from(const std::optional<Type> &parent) {
    if (parent) {
      return SubstTemplateTypeParmPackType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  TemplateTypeParmType replaced_parameter(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(SubstTemplateTypeParmPackType) == sizeof(Type));

#endif
} // namespace mx
