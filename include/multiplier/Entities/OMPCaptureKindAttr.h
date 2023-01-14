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

#include "Attr.h"
#include "AttrKind.h"

namespace mx {
class Attr;
class OMPCaptureKindAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPCaptureKindAttrRange = DerivedEntityRange<AttrIterator, OMPCaptureKindAttr>;
using OMPCaptureKindAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPCaptureKindAttr>;
class OMPCaptureKindAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static OMPCaptureKindAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPCaptureKindAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPCaptureKindAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OMP_CAPTURE_KIND;
  }

  static std::optional<OMPCaptureKindAttr> from(const TokenContext &c);
  static std::optional<OMPCaptureKindAttr> from(const Attr &parent);

  inline static std::optional<OMPCaptureKindAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OMPCaptureKindAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPCaptureKindAttr) == sizeof(Attr));

#endif
} // namespace mx
