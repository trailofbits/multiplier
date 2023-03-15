// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Attr.h"

namespace mx {
class EntityProvider;
class Index;
class AbiTagAttr;
class Attr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AbiTagAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<AbiTagAttr> in(const Fragment &frag);
  static gap::generator<AbiTagAttr> in(const File &file);
  static gap::generator<AbiTagAttr> in(const Index &index);
  static gap::generator<AbiTagAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AbiTagAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ABI_TAG;
  }

  static std::optional<AbiTagAttr> from(const Attr &parent);

  inline static std::optional<AbiTagAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AbiTagAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AbiTagAttr> from(const Reference &r);
  static std::optional<AbiTagAttr> from(const TokenContext &t);

};

static_assert(sizeof(AbiTagAttr) == sizeof(Attr));

#endif
} // namespace mx
