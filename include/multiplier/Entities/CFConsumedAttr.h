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
#include "InheritableParamAttr.h"

namespace mx {
class Attr;
class CFConsumedAttr;
class InheritableAttr;
class InheritableParamAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CFConsumedAttrRange = DerivedEntityRange<AttrIterator, CFConsumedAttr>;
using CFConsumedAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, CFConsumedAttr>;
class CFConsumedAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static CFConsumedAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CFConsumedAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : CFConsumedAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CF_CONSUMED;
  }

  static std::optional<CFConsumedAttr> from(const TokenContext &c);
  static std::optional<CFConsumedAttr> from(const InheritableParamAttr &parent);

  inline static std::optional<CFConsumedAttr> from(const std::optional<InheritableParamAttr> &parent) {
    if (parent) {
      return CFConsumedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CFConsumedAttr> from(const InheritableAttr &parent);

  inline static std::optional<CFConsumedAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return CFConsumedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CFConsumedAttr> from(const Attr &parent);

  inline static std::optional<CFConsumedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CFConsumedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(CFConsumedAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
