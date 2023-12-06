// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/HLSLAnnotationAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class HLSLAnnotationAttr;
class HLSLSV_DispatchThreadIDAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT HLSLSV_DispatchThreadIDAttr : public HLSLAnnotationAttr {
 private:
  friend class FragmentImpl;
  friend class HLSLAnnotationAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<HLSLSV_DispatchThreadIDAttr> in(const Index &index);
  static gap::generator<HLSLSV_DispatchThreadIDAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<HLSLSV_DispatchThreadIDAttr> by_id(const Index &, EntityId);
  static gap::generator<HLSLSV_DispatchThreadIDAttr> in(const Fragment &frag);
  static gap::generator<HLSLSV_DispatchThreadIDAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::HLSLSV__DISPATCH_THREAD_ID;
  }

  static std::optional<HLSLSV_DispatchThreadIDAttr> from_base(const Attr &parent);
  inline static std::optional<HLSLSV_DispatchThreadIDAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<HLSLSV_DispatchThreadIDAttr> from(const std::optional<Attr> &parent);
  static std::optional<HLSLSV_DispatchThreadIDAttr> from(const Reference &r);
  static std::optional<HLSLSV_DispatchThreadIDAttr> from(const VariantEntity &e);
  static std::optional<HLSLSV_DispatchThreadIDAttr> from(const TokenContext &t);

};

static_assert(sizeof(HLSLSV_DispatchThreadIDAttr) == sizeof(HLSLAnnotationAttr));

#endif
} // namespace mx
