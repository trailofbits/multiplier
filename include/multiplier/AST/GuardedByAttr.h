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
class Expr;
class File;
class GuardedByAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT GuardedByAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<GuardedByAttr> in(const Index &index);
  static gap::generator<GuardedByAttr> in(const Fragment &frag);
  static gap::generator<GuardedByAttr> in(const File &file);
  static gap::generator<GuardedByAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::GUARDED_BY;
  }

  static std::optional<GuardedByAttr> by_id(const Index &, EntityId);

  static std::optional<GuardedByAttr> from_base(const Attr &parent);
  inline static std::optional<GuardedByAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<GuardedByAttr> from(const std::optional<Attr> &parent);
  static std::optional<GuardedByAttr> from(const Reference &r);
  static std::optional<GuardedByAttr> from(const VariantEntity &e);
  static std::optional<GuardedByAttr> from(const TokenContext &t);

  Expr argument(void) const;
};

static_assert(sizeof(GuardedByAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
