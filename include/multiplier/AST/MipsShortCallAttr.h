// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/AST/MipsShortCallAttrSpelling.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class InheritableAttr;
class MipsShortCallAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MipsShortCallAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<MipsShortCallAttr> in(const Index &index);
  static gap::generator<MipsShortCallAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MipsShortCallAttr> by_id(const Index &, EntityId);
  static gap::generator<MipsShortCallAttr> in(const Fragment &frag);
  static gap::generator<MipsShortCallAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MIPS_SHORT_CALL;
  }

  static std::optional<MipsShortCallAttr> from_base(const Attr &parent);
  inline static std::optional<MipsShortCallAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<MipsShortCallAttr> from(const std::optional<Attr> &parent);
  static std::optional<MipsShortCallAttr> from(const Reference &r);
  static std::optional<MipsShortCallAttr> from(const VariantEntity &e);
  static std::optional<MipsShortCallAttr> from(const TokenContext &t);

  MipsShortCallAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(MipsShortCallAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
