// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class Expr;
class InheritableAttr;
class LockReturnedAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class LockReturnedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<LockReturnedAttr> in(const Index &index);
  static gap::generator<LockReturnedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<LockReturnedAttr> by_id(const Index &, EntityId);
  static gap::generator<LockReturnedAttr> in(const Fragment &frag);
  static gap::generator<LockReturnedAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::LOCK_RETURNED;
  }

  static std::optional<LockReturnedAttr> from_base(const Attr &parent);
  inline static std::optional<LockReturnedAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<LockReturnedAttr> from(const std::optional<Attr> &parent);
  static std::optional<LockReturnedAttr> from(const Reference &r);
  static std::optional<LockReturnedAttr> from(const VariantEntity &e);
  static std::optional<LockReturnedAttr> from(const TokenContext &t);

  Expr argument(void) const;
};

static_assert(sizeof(LockReturnedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
