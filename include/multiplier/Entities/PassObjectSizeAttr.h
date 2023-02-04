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
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "AttrKind.h"
#include "InheritableParamAttr.h"
#include "PassObjectSizeAttrSpelling.h"

namespace mx {
class Attr;
class InheritableAttr;
class InheritableParamAttr;
class PassObjectSizeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class PassObjectSizeAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<PassObjectSizeAttr> in(const Fragment &frag);
  static gap::generator<PassObjectSizeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PASS_OBJECT_SIZE;
  }

  inline static std::optional<PassObjectSizeAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<PassObjectSizeAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<PassObjectSizeAttr> from(const InheritableParamAttr &parent);

  inline static std::optional<PassObjectSizeAttr> from(const std::optional<InheritableParamAttr> &parent) {
    if (parent) {
      return PassObjectSizeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<PassObjectSizeAttr> from(const InheritableAttr &parent);

  inline static std::optional<PassObjectSizeAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return PassObjectSizeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<PassObjectSizeAttr> from(const Attr &parent);

  inline static std::optional<PassObjectSizeAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return PassObjectSizeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  PassObjectSizeAttrSpelling semantic_spelling(void) const;
  bool is_dynamic(void) const;
};

static_assert(sizeof(PassObjectSizeAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
