// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ConstInitAttrSpelling.h>
#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class ConstInitAttr;
class File;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ConstInitAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ConstInitAttr> in(const Index &index);
  static gap::generator<ConstInitAttr> in(const Fragment &frag);
  static gap::generator<ConstInitAttr> in(const File &file);
  static gap::generator<ConstInitAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CONST_INIT;
  }

  static std::optional<ConstInitAttr> by_id(const Index &, EntityId);

  static std::optional<ConstInitAttr> from_base(const Attr &parent);
  inline static std::optional<ConstInitAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<ConstInitAttr> from(const std::optional<Attr> &parent);
  static std::optional<ConstInitAttr> from(const Reference &r);
  static std::optional<ConstInitAttr> from(const VariantEntity &e);
  static std::optional<ConstInitAttr> from(const TokenContext &t);

  ConstInitAttrSpelling semantic_spelling(void) const;
  bool is_constinit(void) const;
};

static_assert(sizeof(ConstInitAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
