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
class RetainAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class RetainAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<RetainAttr> in(const Fragment &frag);
  static gap::generator<RetainAttr> in(const File &file);
  static gap::generator<RetainAttr> in(const Index &index);
  static gap::generator<RetainAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<RetainAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::RETAIN;
  }

  static std::optional<RetainAttr> from(const Attr &parent);

  inline static std::optional<RetainAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return RetainAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<RetainAttr> from(const Reference &r);
  static std::optional<RetainAttr> from(const TokenContext &t);

};

static_assert(sizeof(RetainAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
