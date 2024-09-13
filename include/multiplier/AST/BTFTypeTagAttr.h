// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/TypeAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class BTFTypeTagAttr;
class File;
class Token;
class TypeAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT BTFTypeTagAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<BTFTypeTagAttr> in(const Index &index);
  static gap::generator<BTFTypeTagAttr> in(const Fragment &frag);
  static gap::generator<BTFTypeTagAttr> in(const File &file);
  static gap::generator<BTFTypeTagAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::BTF_TYPE_TAG;
  }

  static std::optional<BTFTypeTagAttr> by_id(const Index &, EntityId);

  static std::optional<BTFTypeTagAttr> from_base(const Attr &parent);
  inline static std::optional<BTFTypeTagAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<BTFTypeTagAttr> from(const std::optional<Attr> &parent);
  static std::optional<BTFTypeTagAttr> from(const Reference &r);
  static std::optional<BTFTypeTagAttr> from(const VariantEntity &e);
  static std::optional<BTFTypeTagAttr> from(const TokenContext &t);

  std::string_view btf_type_tag(void) const;
  uint32_t btf_type_tag_length(void) const;
};

static_assert(sizeof(BTFTypeTagAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
