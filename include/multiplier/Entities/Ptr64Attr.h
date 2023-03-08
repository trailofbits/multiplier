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

#include "TypeAttr.h"

namespace mx {
class Attr;
class Ptr64Attr;
class Token;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class Ptr64Attr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<Ptr64Attr> in(const Fragment &frag);
  static gap::generator<Ptr64Attr> in(const File &file);
  static gap::generator<Ptr64Attr> in(const Index &index);
  static gap::generator<Ptr64Attr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<Ptr64Attr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PTR64;
  }

  static std::optional<Ptr64Attr> from(const Attr &parent);

  inline static std::optional<Ptr64Attr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return Ptr64Attr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<Ptr64Attr> from(const Reference &r) {
    return Ptr64Attr::from(r.as_attribute());
  }

  inline static std::optional<Ptr64Attr> from(const TokenContext &t) {
    return Ptr64Attr::from(t.as_attribute());
  }

};

static_assert(sizeof(Ptr64Attr) == sizeof(TypeAttr));

#endif
} // namespace mx
