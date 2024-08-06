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
class File;
class InheritableAttr;
class MaxFieldAlignmentAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT MaxFieldAlignmentAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<MaxFieldAlignmentAttr> in(const Index &index);
  static gap::generator<MaxFieldAlignmentAttr> in(const Fragment &frag);
  static gap::generator<MaxFieldAlignmentAttr> in(const File &file);
  static gap::generator<MaxFieldAlignmentAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MAX_FIELD_ALIGNMENT;
  }

  static std::optional<MaxFieldAlignmentAttr> by_id(const Index &, EntityId);

  static std::optional<MaxFieldAlignmentAttr> from_base(const Attr &parent);
  inline static std::optional<MaxFieldAlignmentAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<MaxFieldAlignmentAttr> from(const std::optional<Attr> &parent);
  static std::optional<MaxFieldAlignmentAttr> from(const Reference &r);
  static std::optional<MaxFieldAlignmentAttr> from(const VariantEntity &e);
  static std::optional<MaxFieldAlignmentAttr> from(const TokenContext &t);

  uint32_t alignment(void) const;
};

static_assert(sizeof(MaxFieldAlignmentAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
