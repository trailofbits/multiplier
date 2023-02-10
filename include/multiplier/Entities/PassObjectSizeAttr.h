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
  static gap::generator<PassObjectSizeAttr> in(const File &file);
  static gap::generator<PassObjectSizeAttr> in(const Index &index);
  static gap::generator<PassObjectSizeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PassObjectSizeAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PASS_OBJECT_SIZE;
  }

  static std::optional<PassObjectSizeAttr> from(const Attr &parent);

  inline static std::optional<PassObjectSizeAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return PassObjectSizeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<PassObjectSizeAttr> from(const Reference &r) {
    return PassObjectSizeAttr::from(r.as_attribute());
  }

  inline static std::optional<PassObjectSizeAttr> from(const TokenContext &t) {
    return PassObjectSizeAttr::from(t.as_attribute());
  }

  PassObjectSizeAttrSpelling semantic_spelling(void) const;
  bool is_dynamic(void) const;
};

static_assert(sizeof(PassObjectSizeAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
