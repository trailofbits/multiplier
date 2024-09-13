// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Attr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class SwiftVersionedAdditionAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT SwiftVersionedAdditionAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<SwiftVersionedAdditionAttr> in(const Index &index);
  static gap::generator<SwiftVersionedAdditionAttr> in(const Fragment &frag);
  static gap::generator<SwiftVersionedAdditionAttr> in(const File &file);
  static gap::generator<SwiftVersionedAdditionAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_VERSIONED_ADDITION;
  }

  static std::optional<SwiftVersionedAdditionAttr> by_id(const Index &, EntityId);

  static std::optional<SwiftVersionedAdditionAttr> from_base(const Attr &parent);
  inline static std::optional<SwiftVersionedAdditionAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<SwiftVersionedAdditionAttr> from(const std::optional<Attr> &parent);
  static std::optional<SwiftVersionedAdditionAttr> from(const Reference &r);
  static std::optional<SwiftVersionedAdditionAttr> from(const VariantEntity &e);
  static std::optional<SwiftVersionedAdditionAttr> from(const TokenContext &t);

  Attr additional_attribute(void) const;
  bool is_replaced_by_active(void) const;
};

static_assert(sizeof(SwiftVersionedAdditionAttr) == sizeof(Attr));

#endif
} // namespace mx
