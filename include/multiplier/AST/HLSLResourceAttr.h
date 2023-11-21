// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "HLSLResourceAttrResourceClass.h"
#include "HLSLResourceAttrResourceKind.h"
#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class HLSLResourceAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class HLSLResourceAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<HLSLResourceAttr> in(const Index &index);
  static gap::generator<HLSLResourceAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<HLSLResourceAttr> by_id(const Index &, EntityId);
  static gap::generator<HLSLResourceAttr> in(const Fragment &frag);
  static gap::generator<HLSLResourceAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::HLSL_RESOURCE;
  }

  static std::optional<HLSLResourceAttr> from_base(const Attr &parent);
  inline static std::optional<HLSLResourceAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<HLSLResourceAttr> from(const std::optional<Attr> &parent);
  static std::optional<HLSLResourceAttr> from(const Reference &r);
  static std::optional<HLSLResourceAttr> from(const VariantEntity &e);
  static std::optional<HLSLResourceAttr> from(const TokenContext &t);

  HLSLResourceAttrResourceKind resource_shape(void) const;
  HLSLResourceAttrResourceClass resource_type(void) const;
};

static_assert(sizeof(HLSLResourceAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
