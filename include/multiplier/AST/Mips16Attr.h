// Copyright (c) 2022-present, Trail of Bits, Inc.
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
class Mips16Attr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT Mips16Attr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<Mips16Attr> in(const Index &index);
  static gap::generator<Mips16Attr> in(const Fragment &frag);
  static gap::generator<Mips16Attr> in(const File &file);
  static gap::generator<Mips16Attr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MIPS16;
  }

  static std::optional<Mips16Attr> by_id(const Index &, EntityId);

  static std::optional<Mips16Attr> from_base(const Attr &parent);
  inline static std::optional<Mips16Attr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<Mips16Attr> from(const std::optional<Attr> &parent);
  static std::optional<Mips16Attr> from(const Reference &r);
  static std::optional<Mips16Attr> from(const VariantEntity &e);
  static std::optional<Mips16Attr> from(const TokenContext &t);

};

static_assert(sizeof(Mips16Attr) == sizeof(InheritableAttr));

#endif
} // namespace mx
