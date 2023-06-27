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
class ThisCallAttr;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ThisCallAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ThisCallAttr> in(const Fragment &frag);
  static gap::generator<ThisCallAttr> in(const File &file);
  static gap::generator<ThisCallAttr> in(const Index &index);
  static gap::generator<ThisCallAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ThisCallAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::THIS_CALL;
  }

  static std::optional<ThisCallAttr> from(const Attr &parent);

  inline static std::optional<ThisCallAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ThisCallAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ThisCallAttr> from(const Reference &r);
  static std::optional<ThisCallAttr> from(const TokenContext &t);

};

static_assert(sizeof(ThisCallAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
