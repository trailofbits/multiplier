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
class InheritableAttr;
class SwiftImportAsNonGenericAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT SwiftImportAsNonGenericAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftImportAsNonGenericAttr> in(const Index &index);
  static gap::generator<SwiftImportAsNonGenericAttr> in(const Fragment &frag);
  static gap::generator<SwiftImportAsNonGenericAttr> in(const File &file);
  static gap::generator<SwiftImportAsNonGenericAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_IMPORT_AS_NON_GENERIC;
  }

  static std::optional<SwiftImportAsNonGenericAttr> by_id(const Index &, EntityId);

  static std::optional<SwiftImportAsNonGenericAttr> from_base(const Attr &parent);
  inline static std::optional<SwiftImportAsNonGenericAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<SwiftImportAsNonGenericAttr> from(const std::optional<Attr> &parent);
  static std::optional<SwiftImportAsNonGenericAttr> from(const Reference &r);
  static std::optional<SwiftImportAsNonGenericAttr> from(const VariantEntity &e);
  static std::optional<SwiftImportAsNonGenericAttr> from(const TokenContext &t);

};

static_assert(sizeof(SwiftImportAsNonGenericAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
