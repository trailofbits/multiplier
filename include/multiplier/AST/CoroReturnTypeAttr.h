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
class CoroReturnTypeAttr;
class File;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CoroReturnTypeAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CoroReturnTypeAttr> in(const Index &index);
  static gap::generator<CoroReturnTypeAttr> in(const Fragment &frag);
  static gap::generator<CoroReturnTypeAttr> in(const File &file);
  static gap::generator<CoroReturnTypeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CORO_RETURN_TYPE;
  }

  static std::optional<CoroReturnTypeAttr> by_id(const Index &, EntityId);

  static std::optional<CoroReturnTypeAttr> from_base(const Attr &parent);
  inline static std::optional<CoroReturnTypeAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<CoroReturnTypeAttr> from(const std::optional<Attr> &parent);
  static std::optional<CoroReturnTypeAttr> from(const Reference &r);
  static std::optional<CoroReturnTypeAttr> from(const VariantEntity &e);
  static std::optional<CoroReturnTypeAttr> from(const TokenContext &t);

};

static_assert(sizeof(CoroReturnTypeAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
