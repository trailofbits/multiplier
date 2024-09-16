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
class Attr;
class File;
class InheritableAttr;
class PtGuardedVarAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT PtGuardedVarAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<PtGuardedVarAttr> in(const Index &index);
  static gap::generator<PtGuardedVarAttr> in(const Fragment &frag);
  static gap::generator<PtGuardedVarAttr> in(const File &file);
  static gap::generator<PtGuardedVarAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PT_GUARDED_VAR;
  }

  static std::optional<PtGuardedVarAttr> by_id(const Index &, EntityId);

  static std::optional<PtGuardedVarAttr> from_base(const Attr &parent);
  inline static std::optional<PtGuardedVarAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<PtGuardedVarAttr> from(const std::optional<Attr> &parent);
  static std::optional<PtGuardedVarAttr> from(const Reference &r);
  static std::optional<PtGuardedVarAttr> from(const VariantEntity &e);
  static std::optional<PtGuardedVarAttr> from(const TokenContext &t);

};

static_assert(sizeof(PtGuardedVarAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
