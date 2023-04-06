// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "HLSLAnnotationAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class HLSLAnnotationAttr;
class HLSLSV_DispatchThreadIDAttr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class HLSLSV_DispatchThreadIDAttr : public HLSLAnnotationAttr {
 private:
  friend class FragmentImpl;
  friend class HLSLAnnotationAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<HLSLSV_DispatchThreadIDAttr> in(const Fragment &frag);
  static gap::generator<HLSLSV_DispatchThreadIDAttr> in(const File &file);
  static gap::generator<HLSLSV_DispatchThreadIDAttr> in(const Index &index);
  static gap::generator<HLSLSV_DispatchThreadIDAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<HLSLSV_DispatchThreadIDAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::HLSLSV__DISPATCH_THREAD_ID;
  }

  static std::optional<HLSLSV_DispatchThreadIDAttr> from(const Attr &parent);

  inline static std::optional<HLSLSV_DispatchThreadIDAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return HLSLSV_DispatchThreadIDAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<HLSLSV_DispatchThreadIDAttr> from(const Reference &r);
  static std::optional<HLSLSV_DispatchThreadIDAttr> from(const TokenContext &t);

};

static_assert(sizeof(HLSLSV_DispatchThreadIDAttr) == sizeof(HLSLAnnotationAttr));

#endif
} // namespace mx
