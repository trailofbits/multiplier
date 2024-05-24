// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/AST/NoStackProtectorAttrSpelling.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class InheritableAttr;
class NoStackProtectorAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT NoStackProtectorAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NoStackProtectorAttr> in(const Index &index);
  static gap::generator<NoStackProtectorAttr> in(const Fragment &frag);
  static gap::generator<NoStackProtectorAttr> in(const File &file);
  static gap::generator<NoStackProtectorAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_STACK_PROTECTOR;
  }

  static std::optional<NoStackProtectorAttr> by_id(const Index &, EntityId);

  static std::optional<NoStackProtectorAttr> from_base(const Attr &parent);
  inline static std::optional<NoStackProtectorAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<NoStackProtectorAttr> from(const std::optional<Attr> &parent);
  static std::optional<NoStackProtectorAttr> from(const Reference &r);
  static std::optional<NoStackProtectorAttr> from(const VariantEntity &e);
  static std::optional<NoStackProtectorAttr> from(const TokenContext &t);

  NoStackProtectorAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(NoStackProtectorAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
