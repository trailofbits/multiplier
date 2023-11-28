// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/AssertCapabilityAttrSpelling.h>
#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
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
  static gap::generator<AssertCapabilityAttr> in(const Index &index);
  static gap::generator<AssertCapabilityAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AssertCapabilityAttr> by_id(const Index &, EntityId);
  static gap::generator<AssertCapabilityAttr> in(const Fragment &frag);
  static gap::generator<AssertCapabilityAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ASSERT_CAPABILITY;
  }

  static std::optional<AssertCapabilityAttr> from_base(const Attr &parent);
  inline static std::optional<AssertCapabilityAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<AssertCapabilityAttr> from(const std::optional<Attr> &parent);
  static std::optional<AssertCapabilityAttr> from(const Reference &r);
  static std::optional<AssertCapabilityAttr> from(const VariantEntity &e);
  static std::optional<AssertCapabilityAttr> from(const TokenContext &t);

  AssertCapabilityAttrSpelling semantic_spelling(void) const;
  bool is_shared(void) const;
};

static_assert(sizeof(AssertCapabilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
