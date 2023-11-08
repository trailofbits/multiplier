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
class InheritableAttr;
class NoUwtableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NoUwtableAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NoUwtableAttr> in(const Index &index);
  static gap::generator<NoUwtableAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NoUwtableAttr> by_id(const Index &, EntityId);
  static gap::generator<NoUwtableAttr> in(const Fragment &frag);
  static gap::generator<NoUwtableAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_UWTABLE;
  }

  static std::optional<NoUwtableAttr> from(const Attr &parent);

  inline static std::optional<NoUwtableAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NoUwtableAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NoUwtableAttr> from(const Reference &r);
  static std::optional<NoUwtableAttr> from(const TokenContext &t);

};

static_assert(sizeof(NoUwtableAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
