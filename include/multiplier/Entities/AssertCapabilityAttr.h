// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "AssertCapabilityAttrSpelling.h"
#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class AssertCapabilityAttr;
class Attr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AssertCapabilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AssertCapabilityAttr> in(const Fragment &frag);
  static gap::generator<AssertCapabilityAttr> in(const File &file);
  static gap::generator<AssertCapabilityAttr> in(const Index &index);
  static gap::generator<AssertCapabilityAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AssertCapabilityAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ASSERT_CAPABILITY;
  }

  static std::optional<AssertCapabilityAttr> from(const Attr &parent);

  inline static std::optional<AssertCapabilityAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AssertCapabilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AssertCapabilityAttr> from(const Reference &r);
  static std::optional<AssertCapabilityAttr> from(const TokenContext &t);

  AssertCapabilityAttrSpelling semantic_spelling(void) const;
  bool is_shared(void) const;
};

static_assert(sizeof(AssertCapabilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
