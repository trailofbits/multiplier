// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/AST/UnusedAttrSpelling.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class InheritableAttr;
class Token;
class UnusedAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UnusedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<UnusedAttr> in(const Index &index);
  static gap::generator<UnusedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UnusedAttr> by_id(const Index &, EntityId);
  static gap::generator<UnusedAttr> in(const Fragment &frag);
  static gap::generator<UnusedAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::UNUSED;
  }

  static std::optional<UnusedAttr> from_base(const Attr &parent);
  inline static std::optional<UnusedAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<UnusedAttr> from(const std::optional<Attr> &parent);
  static std::optional<UnusedAttr> from(const Reference &r);
  static std::optional<UnusedAttr> from(const VariantEntity &e);
  static std::optional<UnusedAttr> from(const TokenContext &t);

  UnusedAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(UnusedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
