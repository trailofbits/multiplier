// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "CFGuardAttrGuardArg.h"
#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class CFGuardAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CFGuardAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CFGuardAttr> in(const Fragment &frag);
  static gap::generator<CFGuardAttr> in(const File &file);
  static gap::generator<CFGuardAttr> in(const Index &index);
  static gap::generator<CFGuardAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CFGuardAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CF_GUARD;
  }

  static std::optional<CFGuardAttr> from(const Attr &parent);

  inline static std::optional<CFGuardAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CFGuardAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CFGuardAttr> from(const Reference &r);
  static std::optional<CFGuardAttr> from(const TokenContext &t);

  CFGuardAttrGuardArg guard(void) const;
};

static_assert(sizeof(CFGuardAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
