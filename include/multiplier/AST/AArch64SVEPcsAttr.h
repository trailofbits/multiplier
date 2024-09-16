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
class AArch64SVEPcsAttr;
class Attr;
class File;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT AArch64SVEPcsAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AArch64SVEPcsAttr> in(const Index &index);
  static gap::generator<AArch64SVEPcsAttr> in(const Fragment &frag);
  static gap::generator<AArch64SVEPcsAttr> in(const File &file);
  static gap::generator<AArch64SVEPcsAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::A_ARCH64_SVE_PCS;
  }

  static std::optional<AArch64SVEPcsAttr> by_id(const Index &, EntityId);

  static std::optional<AArch64SVEPcsAttr> from_base(const Attr &parent);
  inline static std::optional<AArch64SVEPcsAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<AArch64SVEPcsAttr> from(const std::optional<Attr> &parent);
  static std::optional<AArch64SVEPcsAttr> from(const Reference &r);
  static std::optional<AArch64SVEPcsAttr> from(const VariantEntity &e);
  static std::optional<AArch64SVEPcsAttr> from(const TokenContext &t);

};

static_assert(sizeof(AArch64SVEPcsAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
