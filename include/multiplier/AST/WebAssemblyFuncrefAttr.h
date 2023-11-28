// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/TypeAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class Token;
class TypeAttr;
class WebAssemblyFuncrefAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class WebAssemblyFuncrefAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<WebAssemblyFuncrefAttr> in(const Index &index);
  static gap::generator<WebAssemblyFuncrefAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<WebAssemblyFuncrefAttr> by_id(const Index &, EntityId);
  static gap::generator<WebAssemblyFuncrefAttr> in(const Fragment &frag);
  static gap::generator<WebAssemblyFuncrefAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::WEB_ASSEMBLY_FUNCREF;
  }

  static std::optional<WebAssemblyFuncrefAttr> from_base(const Attr &parent);
  inline static std::optional<WebAssemblyFuncrefAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<WebAssemblyFuncrefAttr> from(const std::optional<Attr> &parent);
  static std::optional<WebAssemblyFuncrefAttr> from(const Reference &r);
  static std::optional<WebAssemblyFuncrefAttr> from(const VariantEntity &e);
  static std::optional<WebAssemblyFuncrefAttr> from(const TokenContext &t);

};

static_assert(sizeof(WebAssemblyFuncrefAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
