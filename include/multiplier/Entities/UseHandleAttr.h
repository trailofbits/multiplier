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
class InheritableAttr;
class InheritableParamAttr;
class UseHandleAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using UseHandleAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, UseHandleAttr>;
class UseHandleAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static gap::generator<UseHandleAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static UseHandleAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : UseHandleAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::USE_HANDLE;
  }

  static std::optional<UseHandleAttr> from(const TokenContext &c);
  static std::optional<UseHandleAttr> from(const InheritableParamAttr &parent);

  inline static std::optional<UseHandleAttr> from(const std::optional<InheritableParamAttr> &parent) {
    if (parent) {
      return UseHandleAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UseHandleAttr> from(const InheritableAttr &parent);

  inline static std::optional<UseHandleAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return UseHandleAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UseHandleAttr> from(const Attr &parent);

  inline static std::optional<UseHandleAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return UseHandleAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view handle_type(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(UseHandleAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
