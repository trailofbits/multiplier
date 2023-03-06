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

#include "ConstInitAttrSpelling.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class ConstInitAttr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ConstInitAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ConstInitAttr> in(const Fragment &frag);
  static gap::generator<ConstInitAttr> in(const File &file);
  static gap::generator<ConstInitAttr> in(const Index &index);
  static gap::generator<ConstInitAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ConstInitAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CONST_INIT;
  }

  static std::optional<ConstInitAttr> from(const Attr &parent);

  inline static std::optional<ConstInitAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ConstInitAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ConstInitAttr> from(const Reference &r) {
    return ConstInitAttr::from(r.as_attribute());
  }

  inline static std::optional<ConstInitAttr> from(const TokenContext &t) {
    return ConstInitAttr::from(t.as_attribute());
  }

  ConstInitAttrSpelling semantic_spelling(void) const;
  bool is_constinit(void) const;
};

static_assert(sizeof(ConstInitAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
