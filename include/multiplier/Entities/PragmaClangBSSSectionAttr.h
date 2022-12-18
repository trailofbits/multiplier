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
class PragmaClangBSSSectionAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using PragmaClangBSSSectionAttrRange = DerivedEntityRange<AttrIterator, PragmaClangBSSSectionAttr>;
using PragmaClangBSSSectionAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, PragmaClangBSSSectionAttr>;
class PragmaClangBSSSectionAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static PragmaClangBSSSectionAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static PragmaClangBSSSectionAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : PragmaClangBSSSectionAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PRAGMA_CLANG_BSS_SECTION;
  }

  static std::optional<PragmaClangBSSSectionAttr> from(const TokenContext &c);
  static std::optional<PragmaClangBSSSectionAttr> from(const InheritableAttr &parent);

  inline static std::optional<PragmaClangBSSSectionAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return PragmaClangBSSSectionAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<PragmaClangBSSSectionAttr> from(const Attr &parent);

  inline static std::optional<PragmaClangBSSSectionAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return PragmaClangBSSSectionAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view name(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(PragmaClangBSSSectionAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
