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
class File;
class HLSLAnnotationAttr;
class HLSLSV_GroupIndexAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT HLSLSV_GroupIndexAttr : public HLSLAnnotationAttr {
 private:
  friend class FragmentImpl;
  friend class HLSLAnnotationAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<HLSLSV_GroupIndexAttr> in(const Index &index);
  static gap::generator<HLSLSV_GroupIndexAttr> in(const Fragment &frag);
  static gap::generator<HLSLSV_GroupIndexAttr> in(const File &file);
  static gap::generator<HLSLSV_GroupIndexAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::HLSLSV__GROUP_INDEX;
  }

  static std::optional<HLSLSV_GroupIndexAttr> by_id(const Index &, EntityId);

  static std::optional<HLSLSV_GroupIndexAttr> from_base(const Attr &parent);
  inline static std::optional<HLSLSV_GroupIndexAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<HLSLSV_GroupIndexAttr> from(const std::optional<Attr> &parent);
  static std::optional<HLSLSV_GroupIndexAttr> from(const Reference &r);
  static std::optional<HLSLSV_GroupIndexAttr> from(const VariantEntity &e);
  static std::optional<HLSLSV_GroupIndexAttr> from(const TokenContext &t);

};

static_assert(sizeof(HLSLSV_GroupIndexAttr) == sizeof(HLSLAnnotationAttr));

#endif
} // namespace mx
