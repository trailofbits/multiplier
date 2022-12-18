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

#include "AttrKind.h"
#include "NullabilityKind.h"
#include "Type.h"
#include "TypeKind.h"

namespace mx {
class AttributedType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using AttributedTypeRange = DerivedEntityRange<TypeIterator, AttributedType>;
using AttributedTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, AttributedType>;
class AttributedType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static AttributedTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AttributedTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : AttributedType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::ATTRIBUTED;
  }

  static std::optional<AttributedType> from(const TokenContext &c);
  static std::optional<AttributedType> from(const Type &parent);

  inline static std::optional<AttributedType> from(const std::optional<Type> &parent) {
    if (parent) {
      return AttributedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  AttrKind attribute_kind(void) const;
  Type equivalent_type(void) const;
  std::optional<NullabilityKind> immediate_nullability(void) const;
  Type modified_type(void) const;
  bool is_calling_conv(void) const;
  bool is_ms_type_spec(void) const;
  bool is_qualifier(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(AttributedType) == sizeof(Type));

#endif
} // namespace mx
