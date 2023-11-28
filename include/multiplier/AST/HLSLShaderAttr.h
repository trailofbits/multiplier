// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/HLSLShaderAttrShaderType.h>
#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class HLSLShaderAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class HLSLShaderAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<HLSLShaderAttr> in(const Index &index);
  static gap::generator<HLSLShaderAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<HLSLShaderAttr> by_id(const Index &, EntityId);
  static gap::generator<HLSLShaderAttr> in(const Fragment &frag);
  static gap::generator<HLSLShaderAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::HLSL_SHADER;
  }

  static std::optional<HLSLShaderAttr> from_base(const Attr &parent);
  inline static std::optional<HLSLShaderAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<HLSLShaderAttr> from(const std::optional<Attr> &parent);
  static std::optional<HLSLShaderAttr> from(const Reference &r);
  static std::optional<HLSLShaderAttr> from(const VariantEntity &e);
  static std::optional<HLSLShaderAttr> from(const TokenContext &t);

  HLSLShaderAttrShaderType type(void) const;
};

static_assert(sizeof(HLSLShaderAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
