// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/AST/SwiftErrorAttrConventionKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class InheritableAttr;
class SwiftErrorAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT SwiftErrorAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftErrorAttr> in(const Index &index);
  static gap::generator<SwiftErrorAttr> in(const Fragment &frag);
  static gap::generator<SwiftErrorAttr> in(const File &file);
  static gap::generator<SwiftErrorAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_ERROR;
  }

  static std::optional<SwiftErrorAttr> by_id(const Index &, EntityId);

  static std::optional<SwiftErrorAttr> from_base(const Attr &parent);
  inline static std::optional<SwiftErrorAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<SwiftErrorAttr> from(const std::optional<Attr> &parent);
  static std::optional<SwiftErrorAttr> from(const Reference &r);
  static std::optional<SwiftErrorAttr> from(const VariantEntity &e);
  static std::optional<SwiftErrorAttr> from(const TokenContext &t);

  SwiftErrorAttrConventionKind convention(void) const;
};

static_assert(sizeof(SwiftErrorAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
