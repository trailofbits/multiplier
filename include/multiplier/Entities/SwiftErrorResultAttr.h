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

#include "ParameterABIAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class InheritableParamAttr;
class ParameterABIAttr;
class SwiftErrorResultAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SwiftErrorResultAttr : public ParameterABIAttr {
 private:
  friend class FragmentImpl;
  friend class ParameterABIAttr;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftErrorResultAttr> in(const Fragment &frag);
  static gap::generator<SwiftErrorResultAttr> in(const File &file);
  static gap::generator<SwiftErrorResultAttr> in(const Index &index);
  static gap::generator<SwiftErrorResultAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SwiftErrorResultAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_ERROR_RESULT;
  }

  static std::optional<SwiftErrorResultAttr> from(const Attr &parent);

  inline static std::optional<SwiftErrorResultAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SwiftErrorResultAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<SwiftErrorResultAttr> from(const Reference &r) {
    return SwiftErrorResultAttr::from(r.as_attribute());
  }

  inline static std::optional<SwiftErrorResultAttr> from(const TokenContext &t) {
    return SwiftErrorResultAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(SwiftErrorResultAttr) == sizeof(ParameterABIAttr));

#endif
} // namespace mx
