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
#include "HLSLShaderAttrShaderType.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class HLSLShaderAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using HLSLShaderAttrRange = DerivedEntityRange<AttrIterator, HLSLShaderAttr>;
using HLSLShaderAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, HLSLShaderAttr>;
class HLSLShaderAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static HLSLShaderAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static HLSLShaderAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : HLSLShaderAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::HLSL_SHADER;
  }

  static std::optional<HLSLShaderAttr> from(const TokenContext &c);
  static std::optional<HLSLShaderAttr> from(const InheritableAttr &parent);

  inline static std::optional<HLSLShaderAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return HLSLShaderAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<HLSLShaderAttr> from(const Attr &parent);

  inline static std::optional<HLSLShaderAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return HLSLShaderAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
  HLSLShaderAttrShaderType type(void) const;
};

static_assert(sizeof(HLSLShaderAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
