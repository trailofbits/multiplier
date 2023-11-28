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
class ColdAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ColdAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ColdAttr> in(const Index &index);
  static gap::generator<ColdAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ColdAttr> by_id(const Index &, EntityId);
  static gap::generator<ColdAttr> in(const Fragment &frag);
  static gap::generator<ColdAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::COLD;
  }

  static std::optional<ColdAttr> from_base(const Attr &parent);
  inline static std::optional<ColdAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<ColdAttr> from(const std::optional<Attr> &parent);
  static std::optional<ColdAttr> from(const Reference &r);
  static std::optional<ColdAttr> from(const VariantEntity &e);
  static std::optional<ColdAttr> from(const TokenContext &t);

};

static_assert(sizeof(ColdAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
