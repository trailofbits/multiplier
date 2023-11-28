// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class InheritableAttr;
class NoUniqueAddressAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NoUniqueAddressAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NoUniqueAddressAttr> in(const Index &index);
  static gap::generator<NoUniqueAddressAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NoUniqueAddressAttr> by_id(const Index &, EntityId);
  static gap::generator<NoUniqueAddressAttr> in(const Fragment &frag);
  static gap::generator<NoUniqueAddressAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_UNIQUE_ADDRESS;
  }

  static std::optional<NoUniqueAddressAttr> from_base(const Attr &parent);
  inline static std::optional<NoUniqueAddressAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<NoUniqueAddressAttr> from(const std::optional<Attr> &parent);
  static std::optional<NoUniqueAddressAttr> from(const Reference &r);
  static std::optional<NoUniqueAddressAttr> from(const VariantEntity &e);
  static std::optional<NoUniqueAddressAttr> from(const TokenContext &t);

};

static_assert(sizeof(NoUniqueAddressAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
