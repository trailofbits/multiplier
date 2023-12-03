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
class PascalAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT PascalAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<PascalAttr> in(const Index &index);
  static gap::generator<PascalAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PascalAttr> by_id(const Index &, EntityId);
  static gap::generator<PascalAttr> in(const Fragment &frag);
  static gap::generator<PascalAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PASCAL;
  }

  static std::optional<PascalAttr> from_base(const Attr &parent);
  inline static std::optional<PascalAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<PascalAttr> from(const std::optional<Attr> &parent);
  static std::optional<PascalAttr> from(const Reference &r);
  static std::optional<PascalAttr> from(const VariantEntity &e);
  static std::optional<PascalAttr> from(const TokenContext &t);

};

static_assert(sizeof(PascalAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
