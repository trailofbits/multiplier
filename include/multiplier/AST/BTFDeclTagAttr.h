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
class BTFDeclTagAttr;
class File;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT BTFDeclTagAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<BTFDeclTagAttr> in(const Index &index);
  static gap::generator<BTFDeclTagAttr> in(const Fragment &frag);
  static gap::generator<BTFDeclTagAttr> in(const File &file);
  static gap::generator<BTFDeclTagAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::BTF_DECL_TAG;
  }

  static std::optional<BTFDeclTagAttr> by_id(const Index &, EntityId);

  static std::optional<BTFDeclTagAttr> from_base(const Attr &parent);
  inline static std::optional<BTFDeclTagAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<BTFDeclTagAttr> from(const std::optional<Attr> &parent);
  static std::optional<BTFDeclTagAttr> from(const Reference &r);
  static std::optional<BTFDeclTagAttr> from(const VariantEntity &e);
  static std::optional<BTFDeclTagAttr> from(const TokenContext &t);

  std::string_view btf_decl_tag(void) const;
};

static_assert(sizeof(BTFDeclTagAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
