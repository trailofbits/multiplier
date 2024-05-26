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
class DLLImportStaticLocalAttr;
class File;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT DLLImportStaticLocalAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<DLLImportStaticLocalAttr> in(const Index &index);
  static gap::generator<DLLImportStaticLocalAttr> in(const Fragment &frag);
  static gap::generator<DLLImportStaticLocalAttr> in(const File &file);
  static gap::generator<DLLImportStaticLocalAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::DLL_IMPORT_STATIC_LOCAL;
  }

  static std::optional<DLLImportStaticLocalAttr> by_id(const Index &, EntityId);

  static std::optional<DLLImportStaticLocalAttr> from_base(const Attr &parent);
  inline static std::optional<DLLImportStaticLocalAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<DLLImportStaticLocalAttr> from(const std::optional<Attr> &parent);
  static std::optional<DLLImportStaticLocalAttr> from(const Reference &r);
  static std::optional<DLLImportStaticLocalAttr> from(const VariantEntity &e);
  static std::optional<DLLImportStaticLocalAttr> from(const TokenContext &t);

};

static_assert(sizeof(DLLImportStaticLocalAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
