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
class AArch64SVEPcsAttr;
class Attr;
class InheritableAttr;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AArch64SVEPcsAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AArch64SVEPcsAttr> in(const Fragment &frag);
  static gap::generator<AArch64SVEPcsAttr> in(const File &file);
  static gap::generator<AArch64SVEPcsAttr> in(const Index &index);
  static gap::generator<AArch64SVEPcsAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AArch64SVEPcsAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::A_ARCH64_SVE_PCS;
  }

  static std::optional<AArch64SVEPcsAttr> from(const Attr &parent);

  inline static std::optional<AArch64SVEPcsAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AArch64SVEPcsAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AArch64SVEPcsAttr> from(const Reference &r);
  static std::optional<AArch64SVEPcsAttr> from(const TokenContext &t);

};

static_assert(sizeof(AArch64SVEPcsAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
