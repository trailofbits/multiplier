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
class HLSLAnnotationAttr;
class HLSLSV_DispatchThreadIDAttr;
class HLSLSV_GroupIndexAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class HLSLAnnotationAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<HLSLAnnotationAttr> in(const Fragment &frag);
  static gap::generator<HLSLAnnotationAttr> in(const File &file);
  static gap::generator<HLSLAnnotationAttr> in(const Index &index);
  static gap::generator<HLSLAnnotationAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<HLSLAnnotationAttr> by_id(const Index &, EntityId);

  static std::optional<HLSLAnnotationAttr> from(const Attr &parent);

  inline static std::optional<HLSLAnnotationAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return HLSLAnnotationAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<HLSLAnnotationAttr> from(const Reference &r);
  static std::optional<HLSLAnnotationAttr> from(const TokenContext &t);

};

static_assert(sizeof(HLSLAnnotationAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
