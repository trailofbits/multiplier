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
class AnyX86NoCallerSavedRegistersAttr;
class Attr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AnyX86NoCallerSavedRegistersAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AnyX86NoCallerSavedRegistersAttr> in(const Fragment &frag);
  static gap::generator<AnyX86NoCallerSavedRegistersAttr> in(const File &file);
  static gap::generator<AnyX86NoCallerSavedRegistersAttr> in(const Index &index);
  static gap::generator<AnyX86NoCallerSavedRegistersAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AnyX86NoCallerSavedRegistersAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ANY_X86_NO_CALLER_SAVED_REGISTERS;
  }

  static std::optional<AnyX86NoCallerSavedRegistersAttr> from(const Attr &parent);

  inline static std::optional<AnyX86NoCallerSavedRegistersAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AnyX86NoCallerSavedRegistersAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AnyX86NoCallerSavedRegistersAttr> from(const Reference &r);
  static std::optional<AnyX86NoCallerSavedRegistersAttr> from(const TokenContext &t);

};

static_assert(sizeof(AnyX86NoCallerSavedRegistersAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
