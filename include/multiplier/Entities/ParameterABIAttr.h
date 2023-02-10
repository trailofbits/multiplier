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
  static gap::generator<ParameterABIAttr> in(const Fragment &frag);
  static gap::generator<ParameterABIAttr> in(const File &file);
  static gap::generator<ParameterABIAttr> in(const Index &index);
  static gap::generator<ParameterABIAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ParameterABIAttr> by_id(const Index &, EntityId);

  static std::optional<ParameterABIAttr> from(const Attr &parent);

  inline static std::optional<ParameterABIAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ParameterABIAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ParameterABIAttr> from(const Reference &r) {
    return ParameterABIAttr::from(r.as_attribute());
  }

  inline static std::optional<ParameterABIAttr> from(const TokenContext &t) {
    return ParameterABIAttr::from(t.as_attribute());
  }

  ParameterABI abi(void) const;
};

static_assert(sizeof(ParameterABIAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
