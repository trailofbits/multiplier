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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class InheritableParamAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using InheritableParamAttrRange = DerivedEntityRange<AttrIterator, InheritableParamAttr>;
using InheritableParamAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, InheritableParamAttr>;
class InheritableParamAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static InheritableParamAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static InheritableParamAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : InheritableParamAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  static std::optional<InheritableParamAttr> from(const TokenContext &c);
  static std::optional<InheritableParamAttr> from(const InheritableAttr &parent);

  inline static std::optional<InheritableParamAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return InheritableParamAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<InheritableParamAttr> from(const Attr &parent);

  inline static std::optional<InheritableParamAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return InheritableParamAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(InheritableParamAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
