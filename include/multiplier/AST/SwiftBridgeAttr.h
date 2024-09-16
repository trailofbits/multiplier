// Copyright (c) 2022-present, Trail of Bits, Inc.
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
class File;
class InheritableAttr;
class SwiftBridgeAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT SwiftBridgeAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftBridgeAttr> in(const Index &index);
  static gap::generator<SwiftBridgeAttr> in(const Fragment &frag);
  static gap::generator<SwiftBridgeAttr> in(const File &file);
  static gap::generator<SwiftBridgeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_BRIDGE;
  }

  static std::optional<SwiftBridgeAttr> by_id(const Index &, EntityId);

  static std::optional<SwiftBridgeAttr> from_base(const Attr &parent);
  inline static std::optional<SwiftBridgeAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<SwiftBridgeAttr> from(const std::optional<Attr> &parent);
  static std::optional<SwiftBridgeAttr> from(const Reference &r);
  static std::optional<SwiftBridgeAttr> from(const VariantEntity &e);
  static std::optional<SwiftBridgeAttr> from(const TokenContext &t);

  std::string_view swift_type(void) const;
  uint32_t swift_type_length(void) const;
};

static_assert(sizeof(SwiftBridgeAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
