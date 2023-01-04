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
#include "ParameterABIAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class InheritableParamAttr;
class ParameterABIAttr;
class SwiftErrorResultAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using SwiftErrorResultAttrRange = DerivedEntityRange<AttrIterator, SwiftErrorResultAttr>;
using SwiftErrorResultAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, SwiftErrorResultAttr>;
class SwiftErrorResultAttr : public ParameterABIAttr {
 private:
  friend class FragmentImpl;
  friend class ParameterABIAttr;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static SwiftErrorResultAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SwiftErrorResultAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : SwiftErrorResultAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_ERROR_RESULT;
  }

  static std::optional<SwiftErrorResultAttr> from(const TokenContext &c);
  static std::optional<SwiftErrorResultAttr> from(const ParameterABIAttr &parent);

  inline static std::optional<SwiftErrorResultAttr> from(const std::optional<ParameterABIAttr> &parent) {
    if (parent) {
      return SwiftErrorResultAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SwiftErrorResultAttr> from(const InheritableParamAttr &parent);

  inline static std::optional<SwiftErrorResultAttr> from(const std::optional<InheritableParamAttr> &parent) {
    if (parent) {
      return SwiftErrorResultAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SwiftErrorResultAttr> from(const InheritableAttr &parent);

  inline static std::optional<SwiftErrorResultAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return SwiftErrorResultAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SwiftErrorResultAttr> from(const Attr &parent);

  inline static std::optional<SwiftErrorResultAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SwiftErrorResultAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(SwiftErrorResultAttr) == sizeof(ParameterABIAttr));

#endif
} // namespace mx
