// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Attr.h>
#include <multiplier/AST/AttrKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class SwiftVersionedRemovalAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT SwiftVersionedRemovalAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<SwiftVersionedRemovalAttr> in(const Index &index);
  static gap::generator<SwiftVersionedRemovalAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SwiftVersionedRemovalAttr> by_id(const Index &, EntityId);
  static gap::generator<SwiftVersionedRemovalAttr> in(const Fragment &frag);
  static gap::generator<SwiftVersionedRemovalAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_VERSIONED_REMOVAL;
  }

  static std::optional<SwiftVersionedRemovalAttr> from_base(const Attr &parent);
  inline static std::optional<SwiftVersionedRemovalAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<SwiftVersionedRemovalAttr> from(const std::optional<Attr> &parent);
  static std::optional<SwiftVersionedRemovalAttr> from(const Reference &r);
  static std::optional<SwiftVersionedRemovalAttr> from(const VariantEntity &e);
  static std::optional<SwiftVersionedRemovalAttr> from(const TokenContext &t);

  AttrKind attribute_kind_to_remove(void) const;
  bool is_replaced_by_active(void) const;
};

static_assert(sizeof(SwiftVersionedRemovalAttr) == sizeof(Attr));

#endif
} // namespace mx
