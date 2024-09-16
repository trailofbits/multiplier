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
class AcquiredAfterAttr;
class Attr;
class File;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT AcquiredAfterAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AcquiredAfterAttr> in(const Index &index);
  static gap::generator<AcquiredAfterAttr> in(const Fragment &frag);
  static gap::generator<AcquiredAfterAttr> in(const File &file);
  static gap::generator<AcquiredAfterAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ACQUIRED_AFTER;
  }

  static std::optional<AcquiredAfterAttr> by_id(const Index &, EntityId);

  static std::optional<AcquiredAfterAttr> from_base(const Attr &parent);
  inline static std::optional<AcquiredAfterAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<AcquiredAfterAttr> from(const std::optional<Attr> &parent);
  static std::optional<AcquiredAfterAttr> from(const Reference &r);
  static std::optional<AcquiredAfterAttr> from(const VariantEntity &e);
  static std::optional<AcquiredAfterAttr> from(const TokenContext &t);

};

static_assert(sizeof(AcquiredAfterAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
