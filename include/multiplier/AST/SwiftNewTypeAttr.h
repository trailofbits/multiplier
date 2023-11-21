// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"
#include "SwiftNewTypeAttrNewtypeKind.h"
#include "SwiftNewTypeAttrSpelling.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class SwiftNewTypeAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SwiftNewTypeAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftNewTypeAttr> in(const Index &index);
  static gap::generator<SwiftNewTypeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SwiftNewTypeAttr> by_id(const Index &, EntityId);
  static gap::generator<SwiftNewTypeAttr> in(const Fragment &frag);
  static gap::generator<SwiftNewTypeAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_NEW_TYPE;
  }

  static std::optional<SwiftNewTypeAttr> from_base(const Attr &parent);
  inline static std::optional<SwiftNewTypeAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<SwiftNewTypeAttr> from(const std::optional<Attr> &parent);
  static std::optional<SwiftNewTypeAttr> from(const Reference &r);
  static std::optional<SwiftNewTypeAttr> from(const VariantEntity &e);
  static std::optional<SwiftNewTypeAttr> from(const TokenContext &t);

  SwiftNewTypeAttrNewtypeKind newtype_kind(void) const;
  SwiftNewTypeAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(SwiftNewTypeAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
