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
class File;
class InheritableAttr;
class TargetVersionAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT TargetVersionAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<TargetVersionAttr> in(const Index &index);
  static gap::generator<TargetVersionAttr> in(const Fragment &frag);
  static gap::generator<TargetVersionAttr> in(const File &file);
  static gap::generator<TargetVersionAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::TARGET_VERSION;
  }

  static std::optional<TargetVersionAttr> by_id(const Index &, EntityId);

  static std::optional<TargetVersionAttr> from_base(const Attr &parent);
  inline static std::optional<TargetVersionAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<TargetVersionAttr> from(const std::optional<Attr> &parent);
  static std::optional<TargetVersionAttr> from(const Reference &r);
  static std::optional<TargetVersionAttr> from(const VariantEntity &e);
  static std::optional<TargetVersionAttr> from(const TokenContext &t);

  std::string_view name(void) const;
  std::string_view names_string(void) const;
  bool is_default_version(void) const;
};

static_assert(sizeof(TargetVersionAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
