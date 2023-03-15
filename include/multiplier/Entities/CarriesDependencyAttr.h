// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableParamAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class CarriesDependencyAttr;
class InheritableAttr;
class InheritableParamAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CarriesDependencyAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CarriesDependencyAttr> in(const Fragment &frag);
  static gap::generator<CarriesDependencyAttr> in(const File &file);
  static gap::generator<CarriesDependencyAttr> in(const Index &index);
  static gap::generator<CarriesDependencyAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CarriesDependencyAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CARRIES_DEPENDENCY;
  }

  static std::optional<CarriesDependencyAttr> from(const Attr &parent);

  inline static std::optional<CarriesDependencyAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CarriesDependencyAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CarriesDependencyAttr> from(const Reference &r);
  static std::optional<CarriesDependencyAttr> from(const TokenContext &t);

};

static_assert(sizeof(CarriesDependencyAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
