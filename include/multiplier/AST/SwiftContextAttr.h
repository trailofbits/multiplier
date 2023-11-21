// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ParameterABIAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class InheritableParamAttr;
class ParameterABIAttr;
class SwiftContextAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SwiftContextAttr : public ParameterABIAttr {
 private:
  friend class FragmentImpl;
  friend class ParameterABIAttr;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftContextAttr> in(const Index &index);
  static gap::generator<SwiftContextAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SwiftContextAttr> by_id(const Index &, EntityId);
  static gap::generator<SwiftContextAttr> in(const Fragment &frag);
  static gap::generator<SwiftContextAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_CONTEXT;
  }

  static std::optional<SwiftContextAttr> from_base(const Attr &parent);
  inline static std::optional<SwiftContextAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<SwiftContextAttr> from(const std::optional<Attr> &parent);
  static std::optional<SwiftContextAttr> from(const Reference &r);
  static std::optional<SwiftContextAttr> from(const VariantEntity &e);
  static std::optional<SwiftContextAttr> from(const TokenContext &t);

};

static_assert(sizeof(SwiftContextAttr) == sizeof(ParameterABIAttr));

#endif
} // namespace mx
