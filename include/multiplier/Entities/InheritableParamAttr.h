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
class InheritableParamAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class InheritableParamAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<InheritableParamAttr> in(const Fragment &frag);
  static gap::generator<InheritableParamAttr> in(const File &file);
  static gap::generator<InheritableParamAttr> in(const Index &index);
  static gap::generator<InheritableParamAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<InheritableParamAttr> by_id(const Index &, EntityId);

  static std::optional<InheritableParamAttr> from(const Attr &parent);

  inline static std::optional<InheritableParamAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return InheritableParamAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<InheritableParamAttr> from(const Reference &r) {
    return InheritableParamAttr::from(r.as_attribute());
  }

  inline static std::optional<InheritableParamAttr> from(const TokenContext &t) {
    return InheritableParamAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(InheritableParamAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
