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
class AArch64VectorPcsAttr;
class Attr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using AArch64VectorPcsAttrRange = DerivedEntityRange<AttrIterator, AArch64VectorPcsAttr>;
using AArch64VectorPcsAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, AArch64VectorPcsAttr>;
class AArch64VectorPcsAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static AArch64VectorPcsAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AArch64VectorPcsAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : AArch64VectorPcsAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::A_ARCH64_VECTOR_PCS;
  }

  static std::optional<AArch64VectorPcsAttr> from(const TokenContext &c);
  static std::optional<AArch64VectorPcsAttr> from(const InheritableAttr &parent);

  inline static std::optional<AArch64VectorPcsAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return AArch64VectorPcsAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AArch64VectorPcsAttr> from(const Attr &parent);

  inline static std::optional<AArch64VectorPcsAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AArch64VectorPcsAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(AArch64VectorPcsAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
