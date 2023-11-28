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
class InheritableAttr;
class InternalLinkageAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class InternalLinkageAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<InternalLinkageAttr> in(const Index &index);
  static gap::generator<InternalLinkageAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<InternalLinkageAttr> by_id(const Index &, EntityId);
  static gap::generator<InternalLinkageAttr> in(const Fragment &frag);
  static gap::generator<InternalLinkageAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::INTERNAL_LINKAGE;
  }

  static std::optional<InternalLinkageAttr> from_base(const Attr &parent);
  inline static std::optional<InternalLinkageAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<InternalLinkageAttr> from(const std::optional<Attr> &parent);
  static std::optional<InternalLinkageAttr> from(const Reference &r);
  static std::optional<InternalLinkageAttr> from(const VariantEntity &e);
  static std::optional<InternalLinkageAttr> from(const TokenContext &t);

};

static_assert(sizeof(InternalLinkageAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
