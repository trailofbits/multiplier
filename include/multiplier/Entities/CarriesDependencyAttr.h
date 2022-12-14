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

#include "AttrKind.h"
#include "InheritableParamAttr.h"

namespace mx {
class Attr;
class CarriesDependencyAttr;
class InheritableAttr;
class InheritableParamAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CarriesDependencyAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, CarriesDependencyAttr>;
class CarriesDependencyAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static gap::generator<CarriesDependencyAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static CarriesDependencyAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CarriesDependencyAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CARRIES_DEPENDENCY;
  }

  static std::optional<CarriesDependencyAttr> from(const TokenContext &c);
  static std::optional<CarriesDependencyAttr> from(const InheritableParamAttr &parent);

  inline static std::optional<CarriesDependencyAttr> from(const std::optional<InheritableParamAttr> &parent) {
    if (parent) {
      return CarriesDependencyAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CarriesDependencyAttr> from(const InheritableAttr &parent);

  inline static std::optional<CarriesDependencyAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return CarriesDependencyAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CarriesDependencyAttr> from(const Attr &parent);

  inline static std::optional<CarriesDependencyAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CarriesDependencyAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(CarriesDependencyAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
