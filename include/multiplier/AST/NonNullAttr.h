// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableParamAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class InheritableAttr;
class InheritableParamAttr;
class NonNullAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NonNullAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NonNullAttr> in(const Index &index);
  static gap::generator<NonNullAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NonNullAttr> by_id(const Index &, EntityId);
  static gap::generator<NonNullAttr> in(const Fragment &frag);
  static gap::generator<NonNullAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NON_NULL;
  }

  static std::optional<NonNullAttr> from_base(const Attr &parent);
  inline static std::optional<NonNullAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<NonNullAttr> from(const std::optional<Attr> &parent);
  static std::optional<NonNullAttr> from(const Reference &r);
  static std::optional<NonNullAttr> from(const VariantEntity &e);
  static std::optional<NonNullAttr> from(const TokenContext &t);

};

static_assert(sizeof(NonNullAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
