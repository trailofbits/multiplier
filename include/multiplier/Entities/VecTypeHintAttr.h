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
#include "InheritableAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class Type;
class VecTypeHintAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class VecTypeHintAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<VecTypeHintAttr> in(const Fragment &frag);
  static gap::generator<VecTypeHintAttr> in(const File &file);
  static gap::generator<VecTypeHintAttr> in(const Index &index);
  static gap::generator<VecTypeHintAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<VecTypeHintAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::VEC_TYPE_HINT;
  }

  static std::optional<VecTypeHintAttr> from(const Attr &parent);

  inline static std::optional<VecTypeHintAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return VecTypeHintAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<VecTypeHintAttr> from(const Reference &r) {
    return VecTypeHintAttr::from(r.as_attribute());
  }

  inline static std::optional<VecTypeHintAttr> from(const TokenContext &t) {
    return VecTypeHintAttr::from(t.as_attribute());
  }

  Type type_hint(void) const;
  Type type_hint_token(void) const;
};

static_assert(sizeof(VecTypeHintAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
