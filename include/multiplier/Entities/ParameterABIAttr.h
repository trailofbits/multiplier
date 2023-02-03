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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"

#include "AttrKind.h"
#include "InheritableParamAttr.h"
#include "ParameterABI.h"

namespace mx {
class Attr;
class InheritableAttr;
class InheritableParamAttr;
class ParameterABIAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ParameterABIAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static gap::generator<ParameterABIAttr> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<ParameterABIAttr> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ParameterABIAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  static std::optional<ParameterABIAttr> from(const TokenContext &c);
  static std::optional<ParameterABIAttr> from(const InheritableParamAttr &parent);

  inline static std::optional<ParameterABIAttr> from(const std::optional<InheritableParamAttr> &parent) {
    if (parent) {
      return ParameterABIAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ParameterABIAttr> from(const InheritableAttr &parent);

  inline static std::optional<ParameterABIAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return ParameterABIAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ParameterABIAttr> from(const Attr &parent);

  inline static std::optional<ParameterABIAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ParameterABIAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  ParameterABI abi(void) const;
};

static_assert(sizeof(ParameterABIAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
