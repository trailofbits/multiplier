// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class HLSLResourceBindingAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT HLSLResourceBindingAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<HLSLResourceBindingAttr> in(const Index &index);
  static gap::generator<HLSLResourceBindingAttr> in(const Fragment &frag);
  static gap::generator<HLSLResourceBindingAttr> in(const File &file);
  static gap::generator<HLSLResourceBindingAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::HLSL_RESOURCE_BINDING;
  }

  static std::optional<HLSLResourceBindingAttr> by_id(const Index &, EntityId);

  static std::optional<HLSLResourceBindingAttr> from_base(const Attr &parent);
  inline static std::optional<HLSLResourceBindingAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<HLSLResourceBindingAttr> from(const std::optional<Attr> &parent);
  static std::optional<HLSLResourceBindingAttr> from(const Reference &r);
  static std::optional<HLSLResourceBindingAttr> from(const VariantEntity &e);
  static std::optional<HLSLResourceBindingAttr> from(const TokenContext &t);

  std::string_view slot(void) const;
  std::string_view space(void) const;
};

static_assert(sizeof(HLSLResourceBindingAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
