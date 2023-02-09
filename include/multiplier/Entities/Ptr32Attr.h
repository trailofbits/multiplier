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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "AttrKind.h"
#include "TypeAttr.h"

namespace mx {
class Attr;
class Ptr32Attr;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class Ptr32Attr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<Ptr32Attr> in(const Fragment &frag);
  static gap::generator<Ptr32Attr> in(const Index &index);
  static gap::generator<Ptr32Attr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<Ptr32Attr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PTR32;
  }

  inline static std::optional<Ptr32Attr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<Ptr32Attr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<Ptr32Attr> from(const TypeAttr &parent);

  inline static std::optional<Ptr32Attr> from(const std::optional<TypeAttr> &parent) {
    if (parent) {
      return Ptr32Attr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<Ptr32Attr> from(const Attr &parent);

  inline static std::optional<Ptr32Attr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return Ptr32Attr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(Ptr32Attr) == sizeof(TypeAttr));

#endif
} // namespace mx
