// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/HLSLParamModifierAttrSpelling.h>
#include <multiplier/AST/TypeAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class HLSLParamModifierAttr;
class Token;
class TypeAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT HLSLParamModifierAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<HLSLParamModifierAttr> in(const Index &index);
  static gap::generator<HLSLParamModifierAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<HLSLParamModifierAttr> by_id(const Index &, EntityId);
  static gap::generator<HLSLParamModifierAttr> in(const Fragment &frag);
  static gap::generator<HLSLParamModifierAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::HLSL_PARAM_MODIFIER;
  }

  static std::optional<HLSLParamModifierAttr> from_base(const Attr &parent);
  inline static std::optional<HLSLParamModifierAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<HLSLParamModifierAttr> from(const std::optional<Attr> &parent);
  static std::optional<HLSLParamModifierAttr> from(const Reference &r);
  static std::optional<HLSLParamModifierAttr> from(const VariantEntity &e);
  static std::optional<HLSLParamModifierAttr> from(const TokenContext &t);

  bool merged_spelling(void) const;
  HLSLParamModifierAttrSpelling semantic_spelling(void) const;
  bool is_any_in(void) const;
  bool is_any_out(void) const;
  bool is_in(void) const;
  bool is_in_out(void) const;
  bool is_out(void) const;
};

static_assert(sizeof(HLSLParamModifierAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
