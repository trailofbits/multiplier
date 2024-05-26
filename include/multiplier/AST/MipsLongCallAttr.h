// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/AST/MipsLongCallAttrSpelling.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class InheritableAttr;
class MipsLongCallAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT MipsLongCallAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<MipsLongCallAttr> in(const Index &index);
  static gap::generator<MipsLongCallAttr> in(const Fragment &frag);
  static gap::generator<MipsLongCallAttr> in(const File &file);
  static gap::generator<MipsLongCallAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MIPS_LONG_CALL;
  }

  static std::optional<MipsLongCallAttr> by_id(const Index &, EntityId);

  static std::optional<MipsLongCallAttr> from_base(const Attr &parent);
  inline static std::optional<MipsLongCallAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<MipsLongCallAttr> from(const std::optional<Attr> &parent);
  static std::optional<MipsLongCallAttr> from(const Reference &r);
  static std::optional<MipsLongCallAttr> from(const VariantEntity &e);
  static std::optional<MipsLongCallAttr> from(const TokenContext &t);

  MipsLongCallAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(MipsLongCallAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
