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
class AArch64VectorPcsAttr;
class Attr;
class File;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT AArch64VectorPcsAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AArch64VectorPcsAttr> in(const Index &index);
  static gap::generator<AArch64VectorPcsAttr> in(const Fragment &frag);
  static gap::generator<AArch64VectorPcsAttr> in(const File &file);
  static gap::generator<AArch64VectorPcsAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::A_ARCH64_VECTOR_PCS;
  }

  static std::optional<AArch64VectorPcsAttr> by_id(const Index &, EntityId);

  static std::optional<AArch64VectorPcsAttr> from_base(const Attr &parent);
  inline static std::optional<AArch64VectorPcsAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<AArch64VectorPcsAttr> from(const std::optional<Attr> &parent);
  static std::optional<AArch64VectorPcsAttr> from(const Reference &r);
  static std::optional<AArch64VectorPcsAttr> from(const VariantEntity &e);
  static std::optional<AArch64VectorPcsAttr> from(const TokenContext &t);

};

static_assert(sizeof(AArch64VectorPcsAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
