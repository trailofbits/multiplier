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
#include "TypeUseSelector.h"

namespace mx {
class DeducedType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DeducedTypeRange = DerivedEntityRange<TypeIterator, DeducedType>;
using DeducedTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, DeducedType>;
class DeducedType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static DeducedTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DeducedTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : DeducedType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  static std::optional<DeducedType> from(const TokenContext &c);
  static std::optional<DeducedType> from(const Type &parent);

  inline static std::optional<DeducedType> from(const std::optional<Type> &parent) {
    if (parent) {
      return DeducedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  std::optional<Type> resolved_type(void) const;
  bool is_deduced(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(DeducedType) == sizeof(Type));

#endif
} // namespace mx
