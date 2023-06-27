// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"
#include "SectionAttrSpelling.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class SectionAttr;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SectionAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SectionAttr> in(const Fragment &frag);
  static gap::generator<SectionAttr> in(const File &file);
  static gap::generator<SectionAttr> in(const Index &index);
  static gap::generator<SectionAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SectionAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SECTION;
  }

  static std::optional<SectionAttr> from(const Attr &parent);

  inline static std::optional<SectionAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SectionAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SectionAttr> from(const Reference &r);
  static std::optional<SectionAttr> from(const TokenContext &t);

  std::string_view name(void) const;
  SectionAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(SectionAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
