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

#include "HLSLShaderAttrShaderType.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class HLSLShaderAttr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class HLSLShaderAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<HLSLShaderAttr> in(const Fragment &frag);
  static gap::generator<HLSLShaderAttr> in(const File &file);
  static gap::generator<HLSLShaderAttr> in(const Index &index);
  static gap::generator<HLSLShaderAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<HLSLShaderAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::HLSL_SHADER;
  }

  static std::optional<HLSLShaderAttr> from(const Attr &parent);

  inline static std::optional<HLSLShaderAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return HLSLShaderAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<HLSLShaderAttr> from(const Reference &r) {
    return HLSLShaderAttr::from(r.as_attribute());
  }

  inline static std::optional<HLSLShaderAttr> from(const TokenContext &t) {
    return HLSLShaderAttr::from(t.as_attribute());
  }

  HLSLShaderAttrShaderType type(void) const;
};

static_assert(sizeof(HLSLShaderAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
