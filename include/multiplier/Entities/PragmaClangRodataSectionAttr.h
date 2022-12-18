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
class PragmaClangRodataSectionAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using PragmaClangRodataSectionAttrRange = DerivedEntityRange<AttrIterator, PragmaClangRodataSectionAttr>;
using PragmaClangRodataSectionAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, PragmaClangRodataSectionAttr>;
class PragmaClangRodataSectionAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static PragmaClangRodataSectionAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static PragmaClangRodataSectionAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : PragmaClangRodataSectionAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PRAGMA_CLANG_RODATA_SECTION;
  }

  static std::optional<PragmaClangRodataSectionAttr> from(const TokenContext &c);
  static std::optional<PragmaClangRodataSectionAttr> from(const InheritableAttr &parent);

  inline static std::optional<PragmaClangRodataSectionAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return PragmaClangRodataSectionAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<PragmaClangRodataSectionAttr> from(const Attr &parent);

  inline static std::optional<PragmaClangRodataSectionAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return PragmaClangRodataSectionAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view name(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(PragmaClangRodataSectionAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
