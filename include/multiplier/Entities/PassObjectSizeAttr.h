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
#include "PassObjectSizeAttrSpelling.h"

namespace mx {
class Attr;
class InheritableAttr;
class InheritableParamAttr;
class PassObjectSizeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using PassObjectSizeAttrRange = DerivedEntityRange<AttrIterator, PassObjectSizeAttr>;
using PassObjectSizeAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, PassObjectSizeAttr>;
class PassObjectSizeAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static PassObjectSizeAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static PassObjectSizeAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : PassObjectSizeAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PASS_OBJECT_SIZE;
  }

  static std::optional<PassObjectSizeAttr> from(const TokenContext &c);
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
  std::string_view spelling(void) const;
  bool is_dynamic(void) const;
};

static_assert(sizeof(PassObjectSizeAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
