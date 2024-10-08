// Copyright (c) 2022-present, Trail of Bits, Inc.
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
class InheritableAttr;
class Token;
class WebAssemblyImportNameAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT WebAssemblyImportNameAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<WebAssemblyImportNameAttr> in(const Index &index);
  static gap::generator<WebAssemblyImportNameAttr> in(const Fragment &frag);
  static gap::generator<WebAssemblyImportNameAttr> in(const File &file);
  static gap::generator<WebAssemblyImportNameAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::WEB_ASSEMBLY_IMPORT_NAME;
  }

  static std::optional<WebAssemblyImportNameAttr> by_id(const Index &, EntityId);

  static std::optional<WebAssemblyImportNameAttr> from_base(const Attr &parent);
  inline static std::optional<WebAssemblyImportNameAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<WebAssemblyImportNameAttr> from(const std::optional<Attr> &parent);
  static std::optional<WebAssemblyImportNameAttr> from(const Reference &r);
  static std::optional<WebAssemblyImportNameAttr> from(const VariantEntity &e);
  static std::optional<WebAssemblyImportNameAttr> from(const TokenContext &t);

  std::string_view import_name(void) const;
  uint32_t import_name_length(void) const;
};

static_assert(sizeof(WebAssemblyImportNameAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
