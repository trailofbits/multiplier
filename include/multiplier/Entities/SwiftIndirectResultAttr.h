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
class SwiftIndirectResultAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SwiftIndirectResultAttr : public ParameterABIAttr {
 private:
  friend class FragmentImpl;
  friend class ParameterABIAttr;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftIndirectResultAttr> in(const Index &index);
  static gap::generator<SwiftIndirectResultAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SwiftIndirectResultAttr> by_id(const Index &, EntityId);
  static gap::generator<SwiftIndirectResultAttr> in(const Fragment &frag);
  static gap::generator<SwiftIndirectResultAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_INDIRECT_RESULT;
  }

  static std::optional<SwiftIndirectResultAttr> from_base(const Attr &parent);
  inline static std::optional<SwiftIndirectResultAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<SwiftIndirectResultAttr> from(const std::optional<Attr> &parent);
  static std::optional<SwiftIndirectResultAttr> from(const Reference &r);
  static std::optional<SwiftIndirectResultAttr> from(const VariantEntity &e);
  static std::optional<SwiftIndirectResultAttr> from(const TokenContext &t);

};

static_assert(sizeof(SwiftIndirectResultAttr) == sizeof(ParameterABIAttr));

#endif
} // namespace mx
