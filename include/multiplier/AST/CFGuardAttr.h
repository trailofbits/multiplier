// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/CFGuardAttrGuardArg.h>
#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class CFGuardAttr;
class File;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CFGuardAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CFGuardAttr> in(const Index &index);
  static gap::generator<CFGuardAttr> in(const Fragment &frag);
  static gap::generator<CFGuardAttr> in(const File &file);
  static gap::generator<CFGuardAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CF_GUARD;
  }

  static std::optional<CFGuardAttr> by_id(const Index &, EntityId);

  static std::optional<CFGuardAttr> from_base(const Attr &parent);
  inline static std::optional<CFGuardAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<CFGuardAttr> from(const std::optional<Attr> &parent);
  static std::optional<CFGuardAttr> from(const Reference &r);
  static std::optional<CFGuardAttr> from(const VariantEntity &e);
  static std::optional<CFGuardAttr> from(const TokenContext &t);

  CFGuardAttrGuardArg guard(void) const;
};

static_assert(sizeof(CFGuardAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
