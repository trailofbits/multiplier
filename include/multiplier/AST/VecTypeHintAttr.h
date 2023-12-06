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
class Token;
class Type;
class VecTypeHintAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT VecTypeHintAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<VecTypeHintAttr> in(const Index &index);
  static gap::generator<VecTypeHintAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<VecTypeHintAttr> by_id(const Index &, EntityId);
  static gap::generator<VecTypeHintAttr> in(const Fragment &frag);
  static gap::generator<VecTypeHintAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::VEC_TYPE_HINT;
  }

  static std::optional<VecTypeHintAttr> from_base(const Attr &parent);
  inline static std::optional<VecTypeHintAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<VecTypeHintAttr> from(const std::optional<Attr> &parent);
  static std::optional<VecTypeHintAttr> from(const Reference &r);
  static std::optional<VecTypeHintAttr> from(const VariantEntity &e);
  static std::optional<VecTypeHintAttr> from(const TokenContext &t);

  Type type_hint(void) const;
  Type type_hint_token(void) const;
};

static_assert(sizeof(VecTypeHintAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
