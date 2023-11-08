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
class PtGuardedByAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class PtGuardedByAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<PtGuardedByAttr> in(const Index &index);
  static gap::generator<PtGuardedByAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PtGuardedByAttr> by_id(const Index &, EntityId);
  static gap::generator<PtGuardedByAttr> in(const Fragment &frag);
  static gap::generator<PtGuardedByAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PT_GUARDED_BY;
  }

  static std::optional<PtGuardedByAttr> from(const Attr &parent);

  inline static std::optional<PtGuardedByAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return PtGuardedByAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<PtGuardedByAttr> from(const Reference &r);
  static std::optional<PtGuardedByAttr> from(const TokenContext &t);

  Expr argument(void) const;
};

static_assert(sizeof(PtGuardedByAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
