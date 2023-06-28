// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class DLLImportStaticLocalAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DLLImportStaticLocalAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<DLLImportStaticLocalAttr> in(const Fragment &frag);
  static gap::generator<DLLImportStaticLocalAttr> in(const File &file);
  static gap::generator<DLLImportStaticLocalAttr> in(const Index &index);
  static gap::generator<DLLImportStaticLocalAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DLLImportStaticLocalAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::DLL_IMPORT_STATIC_LOCAL;
  }

  static std::optional<DLLImportStaticLocalAttr> from(const Attr &parent);

  inline static std::optional<DLLImportStaticLocalAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return DLLImportStaticLocalAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DLLImportStaticLocalAttr> from(const Reference &r);
  static std::optional<DLLImportStaticLocalAttr> from(const TokenContext &t);

};

static_assert(sizeof(DLLImportStaticLocalAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
