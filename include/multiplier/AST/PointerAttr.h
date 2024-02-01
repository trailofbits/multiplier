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
class PointerAttr;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT PointerAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<PointerAttr> in(const Index &index);
  static gap::generator<PointerAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PointerAttr> by_id(const Index &, EntityId);
  static gap::generator<PointerAttr> in(const Fragment &frag);
  static gap::generator<PointerAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::POINTER;
  }

  static std::optional<PointerAttr> from_base(const Attr &parent);
  inline static std::optional<PointerAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<PointerAttr> from(const std::optional<Attr> &parent);
  static std::optional<PointerAttr> from(const Reference &r);
  static std::optional<PointerAttr> from(const VariantEntity &e);
  static std::optional<PointerAttr> from(const TokenContext &t);

  std::optional<Type> dereferenced_type(void) const;
  std::optional<Type> dereferenced_type_token(void) const;
};

static_assert(sizeof(PointerAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
