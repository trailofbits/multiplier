// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/AST/ZeroCallUsedRegsAttrZeroCallUsedRegsKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class InheritableAttr;
class Token;
class ZeroCallUsedRegsAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ZeroCallUsedRegsAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ZeroCallUsedRegsAttr> in(const Index &index);
  static gap::generator<ZeroCallUsedRegsAttr> in(const Fragment &frag);
  static gap::generator<ZeroCallUsedRegsAttr> in(const File &file);
  static gap::generator<ZeroCallUsedRegsAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ZERO_CALL_USED_REGS;
  }

  static std::optional<ZeroCallUsedRegsAttr> by_id(const Index &, EntityId);

  static std::optional<ZeroCallUsedRegsAttr> from_base(const Attr &parent);
  inline static std::optional<ZeroCallUsedRegsAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<ZeroCallUsedRegsAttr> from(const std::optional<Attr> &parent);
  static std::optional<ZeroCallUsedRegsAttr> from(const Reference &r);
  static std::optional<ZeroCallUsedRegsAttr> from(const VariantEntity &e);
  static std::optional<ZeroCallUsedRegsAttr> from(const TokenContext &t);

  ZeroCallUsedRegsAttrZeroCallUsedRegsKind zero_call_used_regs(void) const;
};

static_assert(sizeof(ZeroCallUsedRegsAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
