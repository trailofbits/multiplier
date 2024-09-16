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
class PragmaClangTextSectionAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT PragmaClangTextSectionAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<PragmaClangTextSectionAttr> in(const Index &index);
  static gap::generator<PragmaClangTextSectionAttr> in(const Fragment &frag);
  static gap::generator<PragmaClangTextSectionAttr> in(const File &file);
  static gap::generator<PragmaClangTextSectionAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PRAGMA_CLANG_TEXT_SECTION;
  }

  static std::optional<PragmaClangTextSectionAttr> by_id(const Index &, EntityId);

  static std::optional<PragmaClangTextSectionAttr> from_base(const Attr &parent);
  inline static std::optional<PragmaClangTextSectionAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<PragmaClangTextSectionAttr> from(const std::optional<Attr> &parent);
  static std::optional<PragmaClangTextSectionAttr> from(const Reference &r);
  static std::optional<PragmaClangTextSectionAttr> from(const VariantEntity &e);
  static std::optional<PragmaClangTextSectionAttr> from(const TokenContext &t);

  std::string_view name(void) const;
  uint32_t name_length(void) const;
};

static_assert(sizeof(PragmaClangTextSectionAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
