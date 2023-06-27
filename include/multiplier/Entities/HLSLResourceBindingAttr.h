// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class HLSLResourceBindingAttr;
class InheritableAttr;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class HLSLResourceBindingAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<HLSLResourceBindingAttr> in(const Fragment &frag);
  static gap::generator<HLSLResourceBindingAttr> in(const File &file);
  static gap::generator<HLSLResourceBindingAttr> in(const Index &index);
  static gap::generator<HLSLResourceBindingAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<HLSLResourceBindingAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::HLSL_RESOURCE_BINDING;
  }

  static std::optional<HLSLResourceBindingAttr> from(const Attr &parent);

  inline static std::optional<HLSLResourceBindingAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return HLSLResourceBindingAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<HLSLResourceBindingAttr> from(const Reference &r);
  static std::optional<HLSLResourceBindingAttr> from(const TokenContext &t);

  std::string_view slot(void) const;
  std::string_view space(void) const;
};

static_assert(sizeof(HLSLResourceBindingAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
