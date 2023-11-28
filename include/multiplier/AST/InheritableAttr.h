// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Attr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class InheritableAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<InheritableAttr> in(const Index &index);
  static gap::generator<InheritableAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<InheritableAttr> by_id(const Index &, EntityId);
  static gap::generator<InheritableAttr> in(const Fragment &frag);
  static gap::generator<InheritableAttr> in(const File &file);

  static std::optional<InheritableAttr> from_base(const Attr &parent);
  inline static std::optional<InheritableAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<InheritableAttr> from(const std::optional<Attr> &parent);
  static std::optional<InheritableAttr> from(const Reference &r);
  static std::optional<InheritableAttr> from(const VariantEntity &e);
  static std::optional<InheritableAttr> from(const TokenContext &t);

  bool should_inherit_even_if_already_present(void) const;
};

static_assert(sizeof(InheritableAttr) == sizeof(Attr));

#endif
} // namespace mx
