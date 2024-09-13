// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/AST/RequiresCapabilityAttrSpelling.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class InheritableAttr;
class RequiresCapabilityAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT RequiresCapabilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<RequiresCapabilityAttr> in(const Index &index);
  static gap::generator<RequiresCapabilityAttr> in(const Fragment &frag);
  static gap::generator<RequiresCapabilityAttr> in(const File &file);
  static gap::generator<RequiresCapabilityAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::REQUIRES_CAPABILITY;
  }

  static std::optional<RequiresCapabilityAttr> by_id(const Index &, EntityId);

  static std::optional<RequiresCapabilityAttr> from_base(const Attr &parent);
  inline static std::optional<RequiresCapabilityAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<RequiresCapabilityAttr> from(const std::optional<Attr> &parent);
  static std::optional<RequiresCapabilityAttr> from(const Reference &r);
  static std::optional<RequiresCapabilityAttr> from(const VariantEntity &e);
  static std::optional<RequiresCapabilityAttr> from(const TokenContext &t);

  RequiresCapabilityAttrSpelling semantic_spelling(void) const;
  bool is_shared(void) const;
};

static_assert(sizeof(RequiresCapabilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
