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
#include "TypeAttr.h"

namespace mx {
class Attr;
class CmseNSCallAttr;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CmseNSCallAttrRange = DerivedEntityRange<AttrIterator, CmseNSCallAttr>;
using CmseNSCallAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, CmseNSCallAttr>;
class CmseNSCallAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  inline static CmseNSCallAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CmseNSCallAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CmseNSCallAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CMSE_NS_CALL;
  }

  static std::optional<CmseNSCallAttr> from(const TokenContext &c);
  static std::optional<CmseNSCallAttr> from(const TypeAttr &parent);

  inline static std::optional<CmseNSCallAttr> from(const std::optional<TypeAttr> &parent) {
    if (parent) {
      return CmseNSCallAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CmseNSCallAttr> from(const Attr &parent);

  inline static std::optional<CmseNSCallAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CmseNSCallAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(CmseNSCallAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
