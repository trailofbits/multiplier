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
class InheritableAttr;
class Token;
class WebAssemblyImportModuleAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT WebAssemblyImportModuleAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<WebAssemblyImportModuleAttr> in(const Index &index);
  static gap::generator<WebAssemblyImportModuleAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<WebAssemblyImportModuleAttr> by_id(const Index &, EntityId);
  static gap::generator<WebAssemblyImportModuleAttr> in(const Fragment &frag);
  static gap::generator<WebAssemblyImportModuleAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::WEB_ASSEMBLY_IMPORT_MODULE;
  }

  static std::optional<WebAssemblyImportModuleAttr> from_base(const Attr &parent);
  inline static std::optional<WebAssemblyImportModuleAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<WebAssemblyImportModuleAttr> from(const std::optional<Attr> &parent);
  static std::optional<WebAssemblyImportModuleAttr> from(const Reference &r);
  static std::optional<WebAssemblyImportModuleAttr> from(const VariantEntity &e);
  static std::optional<WebAssemblyImportModuleAttr> from(const TokenContext &t);

  std::string_view import_module(void) const;
};

static_assert(sizeof(WebAssemblyImportModuleAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
