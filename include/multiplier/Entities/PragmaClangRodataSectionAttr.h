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
class InheritableAttr;
class PragmaClangRodataSectionAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class PragmaClangRodataSectionAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<PragmaClangRodataSectionAttr> in(const Fragment &frag);
  static gap::generator<PragmaClangRodataSectionAttr> in(const File &file);
  static gap::generator<PragmaClangRodataSectionAttr> in(const Index &index);
  static gap::generator<PragmaClangRodataSectionAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PragmaClangRodataSectionAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PRAGMA_CLANG_RODATA_SECTION;
  }

  static std::optional<PragmaClangRodataSectionAttr> from(const Attr &parent);

  inline static std::optional<PragmaClangRodataSectionAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return PragmaClangRodataSectionAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<PragmaClangRodataSectionAttr> from(const Reference &r);
  static std::optional<PragmaClangRodataSectionAttr> from(const TokenContext &t);

  std::string_view name(void) const;
};

static_assert(sizeof(PragmaClangRodataSectionAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
