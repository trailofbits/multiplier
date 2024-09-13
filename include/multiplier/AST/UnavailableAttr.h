// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/AST/UnavailableAttrImplicitReason.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class InheritableAttr;
class Token;
class UnavailableAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT UnavailableAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<UnavailableAttr> in(const Index &index);
  static gap::generator<UnavailableAttr> in(const Fragment &frag);
  static gap::generator<UnavailableAttr> in(const File &file);
  static gap::generator<UnavailableAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::UNAVAILABLE;
  }

  static std::optional<UnavailableAttr> by_id(const Index &, EntityId);

  static std::optional<UnavailableAttr> from_base(const Attr &parent);
  inline static std::optional<UnavailableAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<UnavailableAttr> from(const std::optional<Attr> &parent);
  static std::optional<UnavailableAttr> from(const Reference &r);
  static std::optional<UnavailableAttr> from(const VariantEntity &e);
  static std::optional<UnavailableAttr> from(const TokenContext &t);

  UnavailableAttrImplicitReason implicit_reason(void) const;
  std::string_view message(void) const;
  uint32_t message_length(void) const;
};

static_assert(sizeof(UnavailableAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
