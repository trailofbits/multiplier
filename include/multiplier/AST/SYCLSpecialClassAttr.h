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
class InheritableAttr;
class SYCLSpecialClassAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SYCLSpecialClassAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SYCLSpecialClassAttr> in(const Index &index);
  static gap::generator<SYCLSpecialClassAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SYCLSpecialClassAttr> by_id(const Index &, EntityId);
  static gap::generator<SYCLSpecialClassAttr> in(const Fragment &frag);
  static gap::generator<SYCLSpecialClassAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SYCL_SPECIAL_CLASS;
  }

  static std::optional<SYCLSpecialClassAttr> from_base(const Attr &parent);
  inline static std::optional<SYCLSpecialClassAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<SYCLSpecialClassAttr> from(const std::optional<Attr> &parent);
  static std::optional<SYCLSpecialClassAttr> from(const Reference &r);
  static std::optional<SYCLSpecialClassAttr> from(const VariantEntity &e);
  static std::optional<SYCLSpecialClassAttr> from(const TokenContext &t);

};

static_assert(sizeof(SYCLSpecialClassAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
