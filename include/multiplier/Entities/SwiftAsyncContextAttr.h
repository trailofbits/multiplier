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
#include "ParameterABIAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class InheritableParamAttr;
class ParameterABIAttr;
class SwiftAsyncContextAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SwiftAsyncContextAttr : public ParameterABIAttr {
 private:
  friend class FragmentImpl;
  friend class ParameterABIAttr;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftAsyncContextAttr> in(const Fragment &frag);
  static gap::generator<SwiftAsyncContextAttr> in(const File &file);
  static gap::generator<SwiftAsyncContextAttr> in(const Index &index);
  static gap::generator<SwiftAsyncContextAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SwiftAsyncContextAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_ASYNC_CONTEXT;
  }

  static std::optional<SwiftAsyncContextAttr> from(const Attr &parent);

  inline static std::optional<SwiftAsyncContextAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SwiftAsyncContextAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<SwiftAsyncContextAttr> from(const Reference &r) {
    return SwiftAsyncContextAttr::from(r.as_attribute());
  }

  inline static std::optional<SwiftAsyncContextAttr> from(const TokenContext &t) {
    return SwiftAsyncContextAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(SwiftAsyncContextAttr) == sizeof(ParameterABIAttr));

#endif
} // namespace mx
