// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "TypeAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class ObjCInertUnsafeUnretainedAttr;
class Token;
class TypeAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCInertUnsafeUnretainedAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<ObjCInertUnsafeUnretainedAttr> in(const Index &index);
  static gap::generator<ObjCInertUnsafeUnretainedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCInertUnsafeUnretainedAttr> by_id(const Index &, EntityId);
  static gap::generator<ObjCInertUnsafeUnretainedAttr> in(const Fragment &frag);
  static gap::generator<ObjCInertUnsafeUnretainedAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_INERT_UNSAFE_UNRETAINED;
  }

  static std::optional<ObjCInertUnsafeUnretainedAttr> from_base(const Attr &parent);
  inline static std::optional<ObjCInertUnsafeUnretainedAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCInertUnsafeUnretainedAttr> from(const std::optional<Attr> &parent);
  static std::optional<ObjCInertUnsafeUnretainedAttr> from(const Reference &r);
  static std::optional<ObjCInertUnsafeUnretainedAttr> from(const VariantEntity &e);
  static std::optional<ObjCInertUnsafeUnretainedAttr> from(const TokenContext &t);

};

static_assert(sizeof(ObjCInertUnsafeUnretainedAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
