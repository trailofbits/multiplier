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
class AArch64VectorPcsAttr;
class Attr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AArch64VectorPcsAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AArch64VectorPcsAttr> in(const Fragment &frag);
  static gap::generator<AArch64VectorPcsAttr> in(const File &file);
  static gap::generator<AArch64VectorPcsAttr> in(const Index &index);
  static gap::generator<AArch64VectorPcsAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AArch64VectorPcsAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::A_ARCH64_VECTOR_PCS;
  }

  static std::optional<AArch64VectorPcsAttr> from(const Attr &parent);

  inline static std::optional<AArch64VectorPcsAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AArch64VectorPcsAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AArch64VectorPcsAttr> from(const Reference &r);
  static std::optional<AArch64VectorPcsAttr> from(const TokenContext &t);

};

static_assert(sizeof(AArch64VectorPcsAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
