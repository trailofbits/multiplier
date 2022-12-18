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
class InheritableAttr;
class InheritableParamAttr;
class ReleaseHandleAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ReleaseHandleAttrRange = DerivedEntityRange<AttrIterator, ReleaseHandleAttr>;
using ReleaseHandleAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, ReleaseHandleAttr>;
class ReleaseHandleAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static ReleaseHandleAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ReleaseHandleAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ReleaseHandleAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::RELEASE_HANDLE;
  }

  static std::optional<ReleaseHandleAttr> from(const TokenContext &c);
  static std::optional<ReleaseHandleAttr> from(const InheritableParamAttr &parent);

  inline static std::optional<ReleaseHandleAttr> from(const std::optional<InheritableParamAttr> &parent) {
    if (parent) {
      return ReleaseHandleAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ReleaseHandleAttr> from(const InheritableAttr &parent);

  inline static std::optional<ReleaseHandleAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return ReleaseHandleAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ReleaseHandleAttr> from(const Attr &parent);

  inline static std::optional<ReleaseHandleAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ReleaseHandleAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view handle_type(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(ReleaseHandleAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
