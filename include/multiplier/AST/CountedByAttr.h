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
class CountedByAttr;
class InheritableAttr;
class Token;
class TokenRange;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CountedByAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CountedByAttr> in(const Index &index);
  static gap::generator<CountedByAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CountedByAttr> by_id(const Index &, EntityId);
  static gap::generator<CountedByAttr> in(const Fragment &frag);
  static gap::generator<CountedByAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::COUNTED_BY;
  }

  static std::optional<CountedByAttr> from_base(const Attr &parent);
  inline static std::optional<CountedByAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<CountedByAttr> from(const std::optional<Attr> &parent);
  static std::optional<CountedByAttr> from(const Reference &r);
  static std::optional<CountedByAttr> from(const VariantEntity &e);
  static std::optional<CountedByAttr> from(const TokenContext &t);

  TokenRange counted_by_field_token(void) const;
};

static_assert(sizeof(CountedByAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx