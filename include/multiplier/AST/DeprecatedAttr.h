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
class DeprecatedAttr;
class File;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT DeprecatedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<DeprecatedAttr> in(const Index &index);
  static gap::generator<DeprecatedAttr> in(const Fragment &frag);
  static gap::generator<DeprecatedAttr> in(const File &file);
  static gap::generator<DeprecatedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::DEPRECATED;
  }

  static std::optional<DeprecatedAttr> by_id(const Index &, EntityId);

  static std::optional<DeprecatedAttr> from_base(const Attr &parent);
  inline static std::optional<DeprecatedAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<DeprecatedAttr> from(const std::optional<Attr> &parent);
  static std::optional<DeprecatedAttr> from(const Reference &r);
  static std::optional<DeprecatedAttr> from(const VariantEntity &e);
  static std::optional<DeprecatedAttr> from(const TokenContext &t);

  std::string_view message(void) const;
  uint32_t message_length(void) const;
  std::string_view replacement(void) const;
  uint32_t replacement_length(void) const;
};

static_assert(sizeof(DeprecatedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
