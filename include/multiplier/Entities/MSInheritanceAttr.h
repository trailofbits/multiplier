// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"
#include "MSInheritanceAttrSpelling.h"
#include "MSInheritanceModel.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class MSInheritanceAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MSInheritanceAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<MSInheritanceAttr> in(const Index &index);
  static gap::generator<MSInheritanceAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MSInheritanceAttr> by_id(const Index &, EntityId);
  static gap::generator<MSInheritanceAttr> in(const Fragment &frag);
  static gap::generator<MSInheritanceAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MS_INHERITANCE;
  }

  static std::optional<MSInheritanceAttr> from_base(const Attr &parent);
  inline static std::optional<MSInheritanceAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<MSInheritanceAttr> from(const std::optional<Attr> &parent);
  static std::optional<MSInheritanceAttr> from(const Reference &r);
  static std::optional<MSInheritanceAttr> from(const VariantEntity &e);
  static std::optional<MSInheritanceAttr> from(const TokenContext &t);

  bool best_case(void) const;
  MSInheritanceModel inheritance_model(void) const;
  MSInheritanceAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(MSInheritanceAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
