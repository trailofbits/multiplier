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

#include "InheritableParamAttr.h"

namespace mx {
class Attr;
class CFConsumedAttr;
class InheritableAttr;
class InheritableParamAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CFConsumedAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CFConsumedAttr> in(const Fragment &frag);
  static gap::generator<CFConsumedAttr> in(const File &file);
  static gap::generator<CFConsumedAttr> in(const Index &index);
  static gap::generator<CFConsumedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CFConsumedAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CF_CONSUMED;
  }

  static std::optional<CFConsumedAttr> from(const Attr &parent);

  inline static std::optional<CFConsumedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CFConsumedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<CFConsumedAttr> from(const Reference &r) {
    return CFConsumedAttr::from(r.as_attribute());
  }

  inline static std::optional<CFConsumedAttr> from(const TokenContext &t) {
    return CFConsumedAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(CFConsumedAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
