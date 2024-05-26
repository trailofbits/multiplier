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
class EnforceTCBLeafAttr;
class File;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT EnforceTCBLeafAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<EnforceTCBLeafAttr> in(const Index &index);
  static gap::generator<EnforceTCBLeafAttr> in(const Fragment &frag);
  static gap::generator<EnforceTCBLeafAttr> in(const File &file);
  static gap::generator<EnforceTCBLeafAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ENFORCE_TCB_LEAF;
  }

  static std::optional<EnforceTCBLeafAttr> by_id(const Index &, EntityId);

  static std::optional<EnforceTCBLeafAttr> from_base(const Attr &parent);
  inline static std::optional<EnforceTCBLeafAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<EnforceTCBLeafAttr> from(const std::optional<Attr> &parent);
  static std::optional<EnforceTCBLeafAttr> from(const Reference &r);
  static std::optional<EnforceTCBLeafAttr> from(const VariantEntity &e);
  static std::optional<EnforceTCBLeafAttr> from(const TokenContext &t);

  std::string_view tcb_name(void) const;
};

static_assert(sizeof(EnforceTCBLeafAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
