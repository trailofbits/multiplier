// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableParamAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class InheritableAttr;
class InheritableParamAttr;
class OSConsumedAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OSConsumedAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<OSConsumedAttr> in(const Index &index);
  static gap::generator<OSConsumedAttr> in(const Fragment &frag);
  static gap::generator<OSConsumedAttr> in(const File &file);
  static gap::generator<OSConsumedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OS_CONSUMED;
  }

  static std::optional<OSConsumedAttr> by_id(const Index &, EntityId);

  static std::optional<OSConsumedAttr> from_base(const Attr &parent);
  inline static std::optional<OSConsumedAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<OSConsumedAttr> from(const std::optional<Attr> &parent);
  static std::optional<OSConsumedAttr> from(const Reference &r);
  static std::optional<OSConsumedAttr> from(const VariantEntity &e);
  static std::optional<OSConsumedAttr> from(const TokenContext &t);

};

static_assert(sizeof(OSConsumedAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
